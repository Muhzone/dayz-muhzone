/**
 * Extend Community-Online-Tools mod with additional features.
 */
modded class JMPlayerModule: JMRenderableModuleBase
{
    /**
     * Extend heal function to also remove active "agents" (e.g. infections) from a player.
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

            /*
             * player.RemoveAllAgents() appears to remove the "source" of (negative) effects. The
             * rest of the game scripts seem to be written so that symptoms and everything else is
             * automatically removed once the agent is gone.
             *
             * This process is not instant though and "symptoms" (e.g. caught) which have already
             * been queued up might still get executed.
             */
            player.RemoveAllAgents();

            // todo: Not sure if this call is required as the super class also calls this
            players[i].Update();
        }

        // let the original function handle the rest
        super.Exec_Heal(guids, ident, instance);
    }
}