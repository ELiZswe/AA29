// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/AAIntroMoviePage/AAIntroMoviePage.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImageButton/GUIImageButton.h"

UAAIntroMoviePage::UAAIntroMoviePage()
{
	
	UGUIImageButton* IntroMovie = NewObject<UGUIImageButton>(UGUIImageButton::StaticClass());
	IntroMovie->ImageStyle = EImgStyle::ISTY_Scaled;
	IntroMovie->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	IntroMovie->WinHeight=1;
	IntroMovie->RenderWeight=1;
	//IntroMovie->OnClick=AAIntroMoviePage.InternalOnClick;
	//IntroMovie->OnKeyEvent=IntroMovie.InternalOnKeyEvent;
	
	iIntroMovie = IntroMovie;
	EntryPage = "AGP_Interface.AASplashPage";
	bAllowedAsLast = true;
	//OnOpen = AAIntroMoviePage.InternalOnOpen;
	//OnClose = AAIntroMoviePage.InternalOnClose;
	//OnCanClose = AAIntroMoviePage.CanClose;
	WinHeight = 1;
	//OnClick = AAIntroMoviePage.InternalOnClick;
	//OnKeyEvent = AAIntroMoviePage.internalKeyEvent;

}

void UAAIntroMoviePage::InternalOnOpen()
{
	/*
	local AAGUIController AAGC;
	OnOpen();
	AAGC = AAGUIController(Controller);
	if (AAGC == None)
	{
		InternalOnClose(true);
	}
	if ((!AAGC.bPlayedSplashMovieOnce) && PlayerOwner().Level.IsEntry())
	{
		AAGC.bHideMouseCursor = true;
		iIntroMovie.SetFocus(Self);
		AAGC.GlobalNMLQueue.PauseDownloads();
		MovieToPlay = MovieTexture(DynamicLoadObject("T_AAO_Movies.GUI.m_bink_aasf_intro", Class'MovieTexture'));
		if (MovieToPlay != None)
		{
			AAGC.bPlayedSplashMovieOnce = true;
			iIntroMovie.Image = MovieToPlay;
			MovieToPlay.InitializeMovie();
			MovieToPlay.Movie.Play(MovieToPlay.MovieFilename, true, false, 30);
			MovieToPlay.Movie.SetVolume(0.5);
			SetTimer(0.1, true);
		}
	}
	else
	{
		PlayerOwner().bPauseMusic = false;
		if ((PlayerOwner().Level.Song != "") && (PlayerOwner().Level.Song != "None"))
		{
			PlayerOwner().ClientSetInitialMusic(PlayerOwner().Level.Song, 3);
		}
		bAllowClose = true;
		AAGC.bHideMouseCursor = false;
		AAGC.OpenMenu(EntryPage);
	}
	*/
}

bool UAAIntroMoviePage::internalKeyEvent(uint8& Key, uint8& State, float Delta)
{
	/*
	bForceClose = true;
	SetTimer(0, false);
	Timer();
	*/
	return false;
}

bool UAAIntroMoviePage::InternalOnClick(UGUIComponent* Sender)
{
	/*
	bForceClose = true;
	SetTimer(0, false);
	Timer();
	*/
	return false;
}

bool UAAIntroMoviePage::CanClose(bool bCancelled)
{
	return bAllowClose;
}

void UAAIntroMoviePage::InternalOnClose(bool bCanceled)
{
	/*
	bForceClose = true;
	Timer();
	OnClose(bCanceled);
	*/
}

void UAAIntroMoviePage::Timer()
{
	/*
	if ((!MovieToPlay.Movie.IsPlaying()) || bForceClose)
	{
		MovieCleanup();
		AAGUIController(Controller).GlobalNMLQueue.ResumeDownloads();
		AAGUIController(Controller).bHideMouseCursor = false;
		if (PlayerOwner().Level.IsEntry())
		{
			if ((PlayerOwner().Level.Song != "") && (PlayerOwner().Level.Song != "None"))
			{
				PlayerOwner().ClientSetInitialMusic(PlayerOwner().Level.Song, 3);
			}
			if (AAGUIController(Controller).bLoggedIn)
			{
				EntryPage = "AGP_Interface.AAMainMenu";
			}
			Controller.OpenMenu(EntryPage);
		}
	}
	*/
}

void UAAIntroMoviePage::MovieCleanup()
{
	/*
	PlayerOwner().bPauseMusic = false;
	bAllowClose = true;
	MovieToPlay.Movie.StopNow();
	*/
}