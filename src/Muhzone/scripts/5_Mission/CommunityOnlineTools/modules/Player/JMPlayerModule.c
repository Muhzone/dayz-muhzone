/**
 * Extend Community-Online-Tools mod with additional features.
 */
modded class JMPlayerModule: JMRenderableModuleBase
{
    /**
     * Extend heal function to "heal" a lot more things.
     *
     * @param guids    Player GUIDs to heal.
     * @param ident    PlayerIdentity of the player executing the heal command.
     * @param instance JMPlayerInstance of the player executing the heal command.
     */
    override private void Exec_Heal(array <string> guids, PlayerIdentity ident, JMPlayerInstance instance = NULL)
    {
        array <JMPlayerInstance> players = GetPermissionsManager().GetPlayers(guids);

        // iterate over all selected players
        for (int i = 0; i < players.Count(); i++) {
            PlayerBase player = PlayerBase.Cast(players[i].PlayerObject);

            // no player, nothing to do
            if (player == NULL)
            {
                continue;
            }

            this.muhzoneExtendedHeal(player);
        }

        // let the original function handle the rest
        super.Exec_Heal(guids, ident, instance);
    }

    /**
     * Resets a ton of negative health related stats.
     *
     * @param player PlayerBase instance.
     */
    private void muhzoneExtendedHeal(PlayerBase player)
    {
        /*
         * player.RemoveAllAgents() appears to remove the "source" of (negative) effects. The
         * rest of the game scripts seem to be written so that symptoms and everything else is
         * automatically removed once the agent is gone.
         *
         * This process is not instant though and "symptoms" (e.g. caught) which have already
         * been queued up might still get executed.
         */
        player.RemoveAllAgents();

        // stop freezing
        player.GetStatHeatBuffer().Set(player.GetStatHeatBuffer().GetMax());

        // stop shaking hands
        player.GetStatTremor().Set(0);

        // fill stomach
        player.GetStatDiet().Set(player.GetStatDiet().GetMax());

        // remove toxins
        player.GetStatToxicity().Set(0);

        // dry player
        player.GetStatWet().Set(0);

        // dry inventory items
        this.muhzoneDryInventory(player.GetInventory());
    }

    /**
     * Dries all inventory items so they can't make the player wet anymore.
     *
     * @param inventory Player inventory.
     */
    private void muhzoneDryInventory(GameInventory inventory)
    {
        array<EntityAI> items = new array<EntityAI>;
        inventory.EnumerateInventory(InventoryTraversalType.LEVELORDER, items);
        for (int i = 0; i < items.Count(); i++){
            ItemBase item = ItemBase.Cast(items.Get(i));
            if ( item && item.GetWet() > 0){
                item.SetWet(0);
            }
        }
    }
}