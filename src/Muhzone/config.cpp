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
        requiredVersion = 0.1;
        requiredAddons[] = {
            "DZ_Data",
            "DZ_Structures_Signs",
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
        dependencies[] = { "Game", "Mission" };

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
                files[] = { "Muhzone/scripts/3_Game" };
            };
            class missionScriptModule {
                value = "";
                files[] = { "Muhzone/scripts/5_Mission" };
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

    /**
     * Custom Muhzone billboard model
     */
    class land_billboard_muhzone_1: HouseNoDestruct
    {
        scope=2;
        model="\Muhzone\structures\signs\billboards\billboard_muhzone_1.p3d";
    };
};
