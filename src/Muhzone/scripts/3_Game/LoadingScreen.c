/**
 * Represents the loading screen when the game is actually loading stuff in the background.
 */
modded class LoadingScreen
{
    ref Widget m_WidgetRoot;
    TextWidget m_TextWidgetTitle;
    TextWidget m_TextWidgetStatus;
    TextWidget m_ModdedWarning;
    ImageWidget m_ImageWidgetBackground;
    DayZGame m_DayZGame;
    float m_LastProgressUpdate;

    ImageWidget m_ImageLogoMid;
    ImageWidget m_ImageLogoCorner;
    ImageWidget m_ImageLoadingIcon;
    ImageWidget m_ImageBackground;
    ProgressBarWidget m_ProgressLoading;
    float m_ImageLoadingIconRotation;
    TextWidget m_ProgressText;

    int m_Counter;
    ref Timer m_Timer;

    /**
     * Loading screen constructor which does way too many things.
     *
     * Since BI decided to shove must of the loading screen logic into the constructor and they
     * apparently forgot to allow constructors to be modded, we have to copy paste a large portion
     * of their original code and then add our logic wherever it fits.
     *
     * We took the liberty of removing tons of commented out dead code lines from BI's original code
     * though.
     *
     * @param DayZGame game
     */
    void LoadingScreen(DayZGame game)
    {
        // -------------------- BEGIN BI CODE --------------------
        m_DayZGame = game;

        m_WidgetRoot = game.GetLoadingWorkspace().CreateWidgets("gui/layouts/loading.layout");
        Class.CastTo(m_ImageLogoMid, m_WidgetRoot.FindAnyWidget("ImageLogoMid"));
        Class.CastTo(m_ImageLogoCorner, m_WidgetRoot.FindAnyWidget("ImageLogoCorner"));

        Class.CastTo(m_TextWidgetTitle, m_WidgetRoot.FindAnyWidget("TextWidget"));
        Class.CastTo(m_TextWidgetStatus, m_WidgetRoot.FindAnyWidget("StatusText"));
        Class.CastTo(m_ImageWidgetBackground, m_WidgetRoot.FindAnyWidget("ImageBackground"));
        Class.CastTo(m_ImageLoadingIcon, m_WidgetRoot.FindAnyWidget("ImageLoadingIcon"));
        Class.CastTo(m_ModdedWarning, m_WidgetRoot.FindAnyWidget("ModdedWarning"));

        m_ImageBackground = ImageWidget.Cast( m_WidgetRoot.FindAnyWidget("ImageBackground") );
        m_ProgressLoading = ProgressBarWidget.Cast( m_WidgetRoot.FindAnyWidget("LoadingBar") );

        string tmp;
        m_ProgressText = TextWidget.Cast(m_WidgetRoot.FindAnyWidget("ProgressText"));
        if (GetGame())
        {
            m_ProgressText.Show( GetGame().CommandlineGetParam("loadingTest", tmp) );
        }
        m_WidgetRoot.FindAnyWidget("notification_root").Show(false);

        #ifdef PLATFORM_CONSOLE
        #ifdef PLATFORM_XBOX
		#ifdef BUILD_EXPERIMENTAL
			Widget exp_notifiaction = m_WidgetRoot.FindAnyWidget("notification_root");
			if (exp_notifiaction)
			{
				exp_notifiaction.Show(true);
			}
		#endif
		#endif
        #endif

        m_ModdedWarning.Show( g_Game.ReportModded() );
        m_ImageLogoMid.Show(true);
        m_ImageLogoCorner.Show(false);
        m_ImageWidgetBackground.Show( true );
        m_Counter = 0;

        game.GetBacklit().LoadingAnim();

        ProgressAsync.SetProgressData(m_ProgressLoading);
        ProgressAsync.SetUserData(m_ImageBackground);
        // -------------------- END BI CODE --------------------

        // -------------------- BEGIN MUHZONE CODE --------------------
        Print("Executing custom loading queue screen");

        // Replace background image with our own.
        m_ImageWidgetBackground.LoadMaskTexture("");
        m_ImageWidgetBackground.LoadImageFile( 0, "Muhzone/gui/textures/loading_screens/loading_screen_1_co.edds" );
        m_ImageWidgetBackground.Show(true);

        // Hide DayZ logo as it clashes with our logo. We don't want to modify layout files either.
        m_ImageLogoMid.Show(false);
        m_ImageLogoCorner.Show(false);

        // Hide "playing a modded version" widget. The launcher had us actively confirm the mods.
        m_ModdedWarning.Show(false);
        // -------------------- END MUHZONE CODE --------------------
    }

    /**
     * Shows the loading screen and is called multiple times, apparently.
     */
    override void Show()
    {
        super.Show();

        // Hide DayZ logo again.
        m_ImageLogoMid.Show(false);
        m_ImageLogoCorner.Show(false);
    }
};