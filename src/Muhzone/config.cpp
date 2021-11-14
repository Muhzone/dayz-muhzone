/**
 * Apparently, this is where we are supposed to define non script- or input-related dependencies.
 *
 * The difference between CfgPatches and CfgMods doesn't make sense to me yet and the examples
 * from the wiki are not useful either.
 *
 * So we just roll with it, I guess?
 */
class CfgPatches {
    class Muhzone {
        units[] = {
            "Drink_MuhzoneMilkBottle"
        };
        requiredVersion = 0.1;
        requiredAddons[] = {
            "DZ_Data",
            "DZ_Structures_Signs",
            "DZ_Gear_Drinks",
            "DZ_Scripts",
            "JM_COT_Scripts"
        };
    };
};

/**
 * According to BI, this is required in PBO's which add/modify scripts or inputs.
 */
class CfgMods {
    class Muhzone {
        type = "mod";

        // mod directory
        dir = "Muhzone";

        // required modules
        dependencies[] = { "Game", "World", "Mission" };

        // mod name
        name = "Muhzone";

        // mod logo in various resolutions
        picture = "Muhzone/images/muhzone.paa";
        logo = "Muhzone/images/muhzone.paa";
        logoOver = "Muhzone/images/muhzone.paa";
        logoSmall = "Muhzone/images/muhzone.paa";

        // icon hover text
        tooltip="$STR_MUHZONE_MOD_TOOLTIP";
        tooltipOwned="$STR_MUHZONE_MOD_TOOLTIP";

        // mod description
        overview = "$STR_MUHZONE_MOD_OVERVIEW";

        // author information
        author = "$STR_MUHZONE_MOD_AUTHOR";
        action = "https://muhzone.de/";

        // mod version
        version = "0.6";

        // flags
        hideName = 1;
        hidePicture = 1;
        extra = 0;

        // modules to modify and where to find the modified scripts
        class defs {
            class gameScriptModule {
                value = "";
                files[] = { "Muhzone\scripts\3_Game" };
            };
            class worldScriptModule
            {
                value="";
                files[]= { "Muhzone\scripts\4_World" };
            };
            class missionScriptModule {
                value = "";
                files[] = { "Muhzone\scripts\5_Mission" };
            };
        };
    };
};

/**
 * Someone at BI decided back in the days of "Operation Flashpoint" that buildings are "Vehicles".
 *
 * Err... right. Why not.
 */
class CfgVehicles
{
    class HouseNoDestruct;
    class Bottle_Base;

    /**
     * Custom Muhzone billboard model
     */
    class land_billboard_muhzone_1: HouseNoDestruct
    {
        scope=2;
        model="\Muhzone\structures\signs\billboards\billboard_muhzone_1.p3d";
    };
    /**
     * Custom Muhzone milk bottle.
     *
     * Milk bottle uses the same model and textures (except color) as the water bottle, so we
     * can re-use the water bottle damage stages.
     */
    class MuhzoneMilkBottle: Bottle_Base
    {
        scope=2;
        displayName="$STR_MUHZONE_BOTTLE_MILK_NAME";
        descriptionShort="$STR_MUHZONE_BOTTLE_MILK_DESCRIPTION";
        model="\dz\gear\drinks\WaterBottle.p3d";
        weight=25;
        itemSize[]={1,3};
        destroyOnEmpty=0;
        varQuantityDestroyOnMin=0;
        varLiquidTypeInit=524288;
        liquidContainerType="1 + 2 + 4 + 8 + 16 + 32 + 64 + 128 + 256 + 512 + 1024 + 2048 + 4096 + 8192 + 16384 + 32768 + 65536 + 524288 - (1 + 2 + 4 + 8 + 16 + 32 + 64 + 128 + 256) -32768";
        varQuantityInit=1000;
        varQuantityMin=0;
        varQuantityMax=1000;
        isMeleeWeapon=1;
        hiddenSelections[]=
        {
            "zbytek"
        };
        hiddenSelectionsTextures[]=
        {
            "Muhzone\gear\drinks\data\loot_muhzone_milkbottle_ca.paa"
        };
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints=50;
                    healthLevels[]=
                    {
                        {
                            1,
                            {
                                    "DZ\gear\drinks\data\Loot_WaterBottle.rvmat"
                            }
                        },
                        {
                            0.69999999,
                            {
                                    "DZ\gear\drinks\data\Loot_WaterBottle.rvmat"
                            }
                        },
                        {
                            0.5,
                            {
                                    "DZ\gear\drinks\data\Loot_WaterBottle_damage.rvmat"
                            }
                        },
                        {
                            0.30000001,
                            {
                                    "DZ\gear\drinks\data\Loot_WaterBottle_damage.rvmat"
                            }
                        },

                        {
                            0,
                            {
                                    "DZ\gear\drinks\data\Loot_WaterBottle_destruct.rvmat"
                            }
                        }
                    };
                };
            };
        };
        class AnimEvents
        {
            class SoundWeapon
            {
                class WaterBottle_in_B
                {
                    soundSet="WaterBottle_in_B_SoundSet";
                    id=202;
                };
                class WaterBottle_in_C
                {
                    soundSet="WaterBottle_in_C_SoundSet";
                    id=203;
                };
                class WaterBottle_in_C1
                {
                    soundSet="WaterBottle_in_C1_SoundSet";
                    id=204;
                };
                class WaterBottle_out_A
                {
                    soundSet="WaterBottle_out_A_SoundSet";
                    id=205;
                };
                class WaterBottle_out_B
                {
                    soundSet="WaterBottle_out_B_SoundSet";
                    id=206;
                };
                class WellPond_loop
                {
                    soundSet="WellPond_loop_SoundSet";
                    id=209;
                };
                class WellBottle_loop
                {
                    soundSet="WellBottle_loop_SoundSet";
                    id=210;
                };
                class pickup
                {
                    soundSet="WaterBottle_pickup_SoundSet";
                    id=797;
                };
            };
        };
    };
};

/**
 * Add "milk" liquid type.
 *
 * This definition uses the same ID which "Liquid_Framework" lists on their Steam workshop page.
 * We did not decide whether we want to add an entire framework just to add one type of liquid yet.
 * Therefore, we are trying to be "forwards compatible" in case we decide to use it later.
 */
class cfgLiquidDefinitions {
    class Milk {
        type = 524288;
        displayName = "$STR_MUHZONE_LIQUID_TYPE_MILK_NAME";
        flammability = -10;

        class Nutrition {
            fullnessIndex = 1;
            energy = 50;
            water = 80;
            nutritionalIndex = 75;
            toxicity = -0.0099999998;
            digestibility = 2;
        };
    };
};
