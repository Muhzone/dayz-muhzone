/**
 * Represents the login queue when a player is waiting for a server slot to free up.
 */
modded class LoginQueueBase extends UIScriptedMenu
{
    ImageWidget m_ImageBackground;

    /**
     * Initializes the hot UI mess.
     */
    override Widget Init()
    {
        // Returns widget container from "gui/layouts/dialog_queue_position.layout".
        layoutRoot = super.Init();

        // Replace background image with our own.
        Class.CastTo(m_ImageBackground, layoutRoot.FindAnyWidget("Background"));
        m_ImageBackground.LoadMaskTexture("");
        m_ImageBackground.LoadImageFile( 0, "Muhzone/gui/textures/loading_screens/loading_screen_1_co.edds" );
        m_ImageBackground.Show(true);

        return layoutRoot;
    }
};