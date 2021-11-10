/**
 * Represents the weird countdown before loading / spawning.
 */
modded class LoginTimeBase extends UIScriptedMenu
{
    ImageWidget m_ImageBackground;

    /**
     * Initializes the hot UI mess.
     */
    override Widget Init()
    {
        // Returns widget container from "gui/layouts/dialog_login_time.layout".
        layoutRoot = super.Init();

        // Replace background image with our own.
        Class.CastTo(m_ImageBackground, layoutRoot.FindAnyWidget("Background"));
        m_ImageBackground.LoadMaskTexture("");
        m_ImageBackground.LoadImageFile( 0, "Muhzone/gui/textures/loading_screens/loading_screen_1_co.edds" );
        m_ImageBackground.Show(true);

        return layoutRoot;
    }
};