// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/AAGameMenu_MoviePlayer/AAGameMenu_MoviePlayer.h"
#include "AA29/Object/GUI/GUIComponent/GUISlider/GUISlider.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImageButton/GUIImageButton.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"

UAAGameMenu_MoviePlayer::UAAGameMenu_MoviePlayer()
{
	
	UGUISlider* VolumeControlSlider = NewObject<UGUISlider>(UGUISlider::StaticClass());
	VolumeControlSlider->bIntSlider=true;
	VolumeControlSlider->bDrawPercentSign=true;
	VolumeControlSlider->BarStyleName="MoviePlayer_Volume";
	VolumeControlSlider->StyleName="MoviePlayer_VolumeKnob";
	VolumeControlSlider->Hint="Use the slider to adjust the volume.";
	VolumeControlSlider->WinTop=0.83;
	VolumeControlSlider->WinLeft=0.78;
	VolumeControlSlider->WinWidth=0.2;
	VolumeControlSlider->WinHeight=0.06;
	VolumeControlSlider->bBoundToParent=true;
	VolumeControlSlider->bScaleToParent=true;
	//VolumeControlSlider->OnClick=VolumeControlSlider.InternalOnClick;
	//VolumeControlSlider->OnMousePressed=VolumeControlSlider.InternalOnMousePressed;
	//VolumeControlSlider->OnMouseRelease=VolumeControlSlider.InternalOnMouseRelease;
	//VolumeControlSlider->OnChange=AAGameMenu_MoviePlayer.InternalOnChange;
	//VolumeControlSlider->OnKeyEvent=VolumeControlSlider.InternalOnKeyEvent;
	//VolumeControlSlider->OnCapturedMouseMove=VolumeControlSlider.InternalCapturedMouseMove;
	UGUISlider* ScrubControlSlider = NewObject<UGUISlider>(UGUISlider::StaticClass());
	//ScrubControlSlider->FillImage=Texture'T_AAO_UI.MoviePlayer.t_ui_movieplayer_video_progress_filled';
	ScrubControlSlider->BarStyleName="MoviePlayer_Scrubber";
	ScrubControlSlider->StyleName="MoviePlayer_ScrubberKnob";
	ScrubControlSlider->Hint="Scrubber";
	ScrubControlSlider->WinTop=0.805;
	ScrubControlSlider->WinLeft=0.025;
	ScrubControlSlider->WinWidth=0.95;
	ScrubControlSlider->RenderWeight=0.9;
	ScrubControlSlider->bBoundToParent=true;
	ScrubControlSlider->bScaleToParent=true;
	//ScrubControlSlider->OnClick=ScrubControlSlider.InternalOnClick;
	//ScrubControlSlider->OnMousePressed=AAGameMenu_MoviePlayer.ScrubberOnMousePressed;
	//ScrubControlSlider->OnMouseRelease=AAGameMenu_MoviePlayer.ScrubberOnMouseReleased;
	//ScrubControlSlider->OnChange=AAGameMenu_MoviePlayer.InternalOnChange;
	//ScrubControlSlider->OnKeyEvent=ScrubControlSlider.InternalOnKeyEvent;
	//ScrubControlSlider->OnCapturedMouseMove=ScrubControlSlider.InternalCapturedMouseMove;
	UGUIButton* PlayMovieButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	PlayMovieButton->StyleName="MoviePlayerButtonPlay";
	PlayMovieButton->Hint="Click here to play the movie.";
	PlayMovieButton->WinTop=0.84;
	PlayMovieButton->WinLeft=0.0125;
	PlayMovieButton->WinWidth=0.05;
	PlayMovieButton->WinHeight=0.05;
	PlayMovieButton->bBoundToParent=true;
	PlayMovieButton->bScaleToParent=true;
	//PlayMovieButton->OnClick=AAGameMenu_MoviePlayer.ButtonClick;
	//PlayMovieButton->OnKeyEvent=PlayMovieButton.InternalOnKeyEvent;
	UGUIButton* PauseMovieButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	PauseMovieButton->StyleName="MoviePlayerButtonPause";
	PauseMovieButton->Hint="Click here to pause/unpause the movie.";
	PauseMovieButton->WinTop=0.84;
	PauseMovieButton->WinLeft=0.065;
	PauseMovieButton->WinWidth=0.05;
	PauseMovieButton->WinHeight=0.05;
	PauseMovieButton->bBoundToParent=true;
	PauseMovieButton->bScaleToParent=true;
	//PauseMovieButton->OnClick=AAGameMenu_MoviePlayer.ButtonClick;
	//PauseMovieButton->OnKeyEvent=PauseMovieButton.InternalOnKeyEvent;
	UGUIButton* StopMovieButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	StopMovieButton->StyleName="MoviePlayerButtonStop";
	StopMovieButton->Hint="Click here to stop the movie.";
	StopMovieButton->WinTop=0.84;
	StopMovieButton->WinLeft=0.12;
	StopMovieButton->WinWidth=0.05;
	StopMovieButton->WinHeight=0.05;
	StopMovieButton->bBoundToParent=true;
	StopMovieButton->bScaleToParent=true;
	//StopMovieButton->OnClick=AAGameMenu_MoviePlayer.ButtonClick;
	//StopMovieButton->OnKeyEvent=StopMovieButton.InternalOnKeyEvent;
	UGUIButton* RewindMovieButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	RewindMovieButton->StyleName="MoviePlayerButtonRewind";
	RewindMovieButton->Hint="Click here to rewind movie.";
	RewindMovieButton->WinTop=0.84;
	RewindMovieButton->WinLeft=0.165;
	RewindMovieButton->WinWidth=0.05;
	RewindMovieButton->WinHeight=0.05;
	RewindMovieButton->bBoundToParent=true;
	RewindMovieButton->bScaleToParent=true;
	RewindMovieButton->bRepeatClick=true;
	//RewindMovieButton->OnClick=AAGameMenu_MoviePlayer.ButtonClick;
	//RewindMovieButton->OnKeyEvent=RewindMovieButton.InternalOnKeyEvent;
	UGUIButton* FastForwardMovieButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	FastForwardMovieButton->StyleName="MoviePlayerButtonForward";
	FastForwardMovieButton->Hint="Click here to fast forward movie.";
	FastForwardMovieButton->WinTop=0.84;
	FastForwardMovieButton->WinLeft=0.22;
	FastForwardMovieButton->WinWidth=0.05;
	FastForwardMovieButton->WinHeight=0.05;
	FastForwardMovieButton->bBoundToParent=true;
	FastForwardMovieButton->bScaleToParent=true;
	FastForwardMovieButton->bRepeatClick=true;
	//FastForwardMovieButton->OnClick=AAGameMenu_MoviePlayer.ButtonClick;
	//FastForwardMovieButton->OnKeyEvent=FastForwardMovieButton.InternalOnKeyEvent;
	UGUIButton* ClosePlayerButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	ClosePlayerButton->StyleName="MoviePlayerButtonClose";
	ClosePlayerButton->Hint="Click here to close the movie player.";
	ClosePlayerButton->WinTop=0.00346;
	ClosePlayerButton->WinLeft=0.962;
	ClosePlayerButton->WinWidth=0.031;
	ClosePlayerButton->WinHeight=0.0357;
	ClosePlayerButton->bBoundToParent=true;
	ClosePlayerButton->bScaleToParent=true;
	//ClosePlayerButton->OnClick=AAGameMenu_MoviePlayer.ButtonClick;
	//ClosePlayerButton->OnKeyEvent=ClosePlayerButton.InternalOnKeyEvent;
	UGUIImageButton* VolumeIcon = NewObject<UGUIImageButton>(UGUIImageButton::StaticClass());
	//VolumeIcon->Image=Texture'T_AAO_UI.MoviePlayer.t_ui_movieplayer_volume_button_up';
	VolumeIcon->ImageStyle = EImgStyle::ISTY_Scaled;
	VolumeIcon->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	VolumeIcon->Hint="Toggle Mute";
	VolumeIcon->WinTop=0.84;
	VolumeIcon->WinLeft=0.69;
	VolumeIcon->WinWidth=0.1;
	VolumeIcon->WinHeight=0.05;
	VolumeIcon->bBoundToParent=true;
	VolumeIcon->bScaleToParent=true;
	//VolumeIcon->OnClick=AAGameMenu_MoviePlayer.ButtonClick;
	//VolumeIcon->OnKeyEvent=VolumeIcon.InternalOnKeyEvent;
	UGUIImage* MyBackground = NewObject<UGUIImage>(UGUIImage::StaticClass());
	//MyBackground->Image=Texture'T_AAO_UI.MoviePlayer.t_ui_movieplayer_bg_videobox_color1';
	MyBackground->ImageStyle = EImgStyle::ISTY_Stretched;
	MyBackground->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	MyBackground->WinHeight=1;
	MyBackground->RenderWeight=1E-05;
	MyBackground->bBoundToParent=true;
	MyBackground->bScaleToParent=true;
	UGUIImage* TitleBar = NewObject<UGUIImage>(UGUIImage::StaticClass());
	//TitleBar->Image=Texture'T_AAO_UI.MoviePlayer.t_ui_movieplayer_title_bar';
	TitleBar->ImageStyle = EImgStyle::ISTY_Scaled;
	TitleBar->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	TitleBar->WinHeight=0.072;
	TitleBar->bBoundToParent=true;
	TitleBar->bScaleToParent=true;
	UGUILabel* MoviePlayerTitle = NewObject<UGUILabel>(UGUILabel::StaticClass());
	MoviePlayerTitle->Caption="Movie Player";
	MoviePlayerTitle->TextColor=FColor(175, 175, 175, 255);
	MoviePlayerTitle->TextFont="AAFontSmall";
	MoviePlayerTitle->WinTop=-0.01157;
	MoviePlayerTitle->WinLeft=0.009;
	MoviePlayerTitle->WinWidth=0.85;
	MoviePlayerTitle->WinHeight=0.07198;
	MoviePlayerTitle->RenderWeight=0.9999;
	MoviePlayerTitle->bBoundToParent=true;
	MoviePlayerTitle->bScaleToParent=true;
	UGUIImage* MoviePlayerTexture = NewObject<UGUIImage>(UGUIImage::StaticClass());
	MoviePlayerTexture->ImageStyle = EImgStyle::ISTY_Scaled;
	MoviePlayerTexture->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	MoviePlayerTexture->WinTop=0.0432;
	MoviePlayerTexture->WinLeft=0.01;
	MoviePlayerTexture->WinWidth=0.98;
	MoviePlayerTexture->WinHeight=0.7524;
	MoviePlayerTexture->RenderWeight=0.8;
	MoviePlayerTexture->bBoundToParent=true;
	MoviePlayerTexture->bScaleToParent=true;
	UGUILabel* MoviePlayerCaption = NewObject<UGUILabel>(UGUILabel::StaticClass());
	MoviePlayerCaption->TextColor=FColor(153, 153, 153, 255);
	MoviePlayerCaption->TextFont="AAFontSmall";
	MoviePlayerCaption->bMultiLine=true;
	MoviePlayerCaption->WinTop=0.905;
	MoviePlayerCaption->WinLeft=0.04;
	MoviePlayerCaption->WinWidth=0.935;
	MoviePlayerCaption->WinHeight=0.08;
	MoviePlayerCaption->RenderWeight=0.9999;
	MoviePlayerCaption->bBoundToParent=true;
	MoviePlayerCaption->bScaleToParent=true;
	UGUIImage* CaptionBackground = NewObject<UGUIImage>(UGUIImage::StaticClass());
	//CaptionBackground->Image=Texture'T_AAO_UI.MoviePlayer.t_ui_movieplayer_caption_area';
	CaptionBackground->ImageStyle = EImgStyle::ISTY_Stretched;
	CaptionBackground->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	CaptionBackground->WinTop=0.895;
	CaptionBackground->WinLeft=0.025;
	CaptionBackground->WinWidth=0.95;
	CaptionBackground->WinHeight=0.09;
	CaptionBackground->RenderWeight=2E-05;
	CaptionBackground->bBoundToParent=true;
	CaptionBackground->bScaleToParent=true;
	UGUILabel* MoviePlayerCounter = NewObject<UGUILabel>(UGUILabel::StaticClass());
	MoviePlayerCounter->TextAlign = ETextAlign::TXTA_Center;
	MoviePlayerCounter->TextColor=FColor(175, 175, 175, 255);
	MoviePlayerCounter->TextFont="AAFontSmall";
	MoviePlayerCounter->WinTop=0.83;
	MoviePlayerCounter->WinLeft=0.325;
	MoviePlayerCounter->WinWidth=0.3;
	MoviePlayerCounter->WinHeight=0.07;
	MoviePlayerCounter->RenderWeight=0.9999;
	MoviePlayerCounter->bBoundToParent=true;
	MoviePlayerCounter->bScaleToParent=true;
	UGUIImage* BorderTop = NewObject<UGUIImage>(UGUIImage::StaticClass());
	//BorderTop->Image=Texture'T_AAO_UI.MoviePlayer.t_ui_movieplayer_gray_square';
	BorderTop->ImageStyle = EImgStyle::ISTY_Scaled;
	BorderTop->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	BorderTop->WinHeight=0.0025;
	BorderTop->RenderWeight=0.9;
	BorderTop->bBoundToParent=true;
	BorderTop->bScaleToParent=true;
	UGUIImage* BorderBottom = NewObject<UGUIImage>(UGUIImage::StaticClass());
	//BorderBottom->Image=Texture'T_AAO_UI.MoviePlayer.t_ui_movieplayer_gray_square';
	BorderBottom->ImageStyle = EImgStyle::ISTY_Scaled;
	BorderBottom->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	BorderBottom->WinTop=0.9975;
	BorderBottom->WinHeight=0.0025;
	BorderBottom->RenderWeight=0.9;
	BorderBottom->bBoundToParent=true;
	BorderBottom->bScaleToParent=true;
	UGUIImage* BorderLeft = NewObject<UGUIImage>(UGUIImage::StaticClass());
	//BorderLeft->Image=Texture'T_AAO_UI.MoviePlayer.t_ui_movieplayer_gray_square';
	BorderLeft->ImageStyle = EImgStyle::ISTY_Scaled;
	BorderLeft->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	BorderLeft->WinWidth=0.0025;
	BorderLeft->WinHeight=1;
	BorderLeft->RenderWeight=0.9;
	BorderLeft->bBoundToParent=true;
	BorderLeft->bScaleToParent=true;
	UGUIImage* BorderRight = NewObject<UGUIImage>(UGUIImage::StaticClass());
	//BorderRight->Image=Texture'T_AAO_UI.MoviePlayer.t_ui_movieplayer_gray_square';
	BorderRight->ImageStyle = EImgStyle::ISTY_Scaled;
	BorderRight->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	BorderRight->WinLeft=0.9975;
	BorderRight->WinWidth=0.0025;
	BorderRight->WinHeight=1;
	BorderRight->RenderWeight=0.9;
	BorderRight->bBoundToParent=true;
	BorderRight->bScaleToParent=true;

	guiimgMoviePlayerTexture = MoviePlayerTexture;
	guibtnClose = ClosePlayerButton;
	guibtnRewindMovie = RewindMovieButton;
	guibtnFastForwardMovie = FastForwardMovieButton;
	guibtnPlayMovie = PlayMovieButton;
	guibtnStopMovie = StopMovieButton;
	guibtnPauseMovie = PauseMovieButton;
	guibtnVolumeIcon = VolumeIcon;
	guilTitle = MoviePlayerTitle;
	guilCaption = MoviePlayerCaption;
	guilCounter = MoviePlayerCounter;
	guiimgTitleBar = TitleBar;
	guiimgBackground = MyBackground;
	guiimgCaptionBackground = CaptionBackground;
	guiimgBorderTop = BorderTop;
	guiimgBorderBottom = BorderBottom;
	guiimgBorderLeft = BorderLeft;
	guiimgBorderRight = BorderRight;
	fpMovieVolume = 1;
	//texVolumeIcon = Texture'T_AAO_UI.MoviePlayer.t_ui_movieplayer_volume_button_up';
	//texVolumeIconMute = Texture'T_AAO_UI.MoviePlayer.t_ui_movieplayer_volume_button_down';
	guisVolume = VolumeControlSlider;
	guisScrubber = ScrubControlSlider;
	bRenderWorld = true;
	WinTop = 0.20828;
	WinLeft = 0.26;
	WinWidth = 0.48;
	WinHeight = 0.58344;

}


//const NextButtonPressTime = 0.1;

void UAAGameMenu_MoviePlayer::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	local AGP_HUD HUD;
	Super::InitComponent(MyController, MyOwner);
	HUD = AGP_HUD(PlayerOwner().myHUD);
	guilTitle.Caption = HUD.sMovieTitle;
	guilCaption.Caption = HUD.sMovieCaption;
	*/
}

void UAAGameMenu_MoviePlayer::OnOpen()
{
	/*
	local StudentController SC;
	local AGP_HUD HUD;
	Super::OnOpen();
	HUD = AGP_HUD(PlayerOwner().myHUD);
	SetTimer(0.1, true);
	bPlayerHUD = HUD.bShowHUD;
	HUD.bShowVersion = true;
	HUD.bShowSpectatorInfo = false;
	HUD.bShowHUD = false;
	SC = StudentController(PlayerOwner());
	if ((SC != None) && bIsInterview)
	{
		if (!((int((2 * *float(SC.iLastRealHeroVisited))) & SC.iCompleted[15]) > 0))
		{
			guibtnRewindMovie.DisableMe();
			guibtnFastForwardMovie.DisableMe();
			guisScrubber.DisableMe();
		}
	}
	guiimgMoviePlayerTexture.Image = HUD.mtMovieToPlay;
	fpMovieVolume = FClamp(HUD.fpVolumeMovieToPlayOnUse, 0, 1);
	fpSavedMovieVolume = fpMovieVolume;
	if (fpMovieVolume == 0)
	{
		fpMovieVolume = 0.5;
	}
	guisVolume.SetValue((fpMovieVolume * 100));
	HUD.PlayMovieScaled(HUD.mtMovieToPlay, 0.5, 0.5, 0.5, 0.5, false, false, false, AGP_HUD(PlayerOwner().myHUD).iMovieFrameRate);
	PlayerOwner().myHUD.TextureMovie.Movie.SetVolume(fpMovieVolume);
	bHasBeenPlayedOnce = true;
	fMovieTime = HUD.TextureMovie.Movie.GetMovieDuration();
	guilCounter.Caption = SecondsToString(fMovieTime);
	*/
}

void UAAGameMenu_MoviePlayer::OnClose(bool bCanceled)
{
	/*
	local AGP_HUD HUD;
	local PlayerController PC;
	PlayerOwner().myHUD.StopMovie();
	PC = PlayerOwner();
	Super::OnClose(bCanceled);
	HUD = AGP_HUD(PlayerOwner().myHUD);
	SetTimer(0, false);
	HUD.bShowVersion = false;
	HUD.bShowSpectatorInfo = true;
	HUD.bShowHUD = bPlayerHUD;
	ParentPage.bVisible = true;
	*/
}

bool UAAGameMenu_MoviePlayer::OnCanClose(bool bCancelled)
{
	return true;
}

bool UAAGameMenu_MoviePlayer::ButtonClick(UGUIComponent* Sender)
{
	/*
	switch (Sender)
	{
	case guibtnClose:
		if (AGP_HUD(PlayerOwner().myHUD).sndMovieSoundToPlay != None)
		{
			HumanController(PlayerOwner()).ViewTarget.StopSound(AGP_HUD(PlayerOwner().myHUD).sndMovieSoundToPlay);
		}
		HumanController(PlayerOwner()).ClientCloseMenu(false);
		break;
	case guibtnPauseMovie:
		if (!PlayerOwner().myHUD.IsMoviePaused())
		{
			PlayerOwner().myHUD.PauseMovie(true);
			guibtnPlayMovie.EnableMe();
			bPauseButtonPressed = true;
		}
		else
		{
			PlayerOwner().myHUD.PauseMovie(false);
			guibtnPlayMovie.DisableMe();
			SetTimer(0.1, true);
			bPauseButtonPressed = false;
		}
		GOTO JL0532;
	case guibtnStopMovie:
		guibtnStopMovie.DisableMe();
		guibtnPlayMovie.EnableMe();
		guibtnPauseMovie.DisableMe();
		bPauseButtonPressed = false;
		PlayerOwner().myHUD.StopMovie();
		if (Len(string(AGP_HUD(PlayerOwner().myHUD).sndMovieSoundToPlay)) > 0)
		{
			HumanController(PlayerOwner()).ViewTarget.StopSound(AGP_HUD(PlayerOwner().myHUD).sndMovieSoundToPlay);
		}
		guilCounter.Caption = SecondsToString(0) $ " / " $ SecondsToString(fMovieTime);
		guisScrubber.SetValue(0);
		SetTimer(0, false);
		GOTO JL0532;
	case guibtnPlayMovie:
		if (bPauseButtonPressed == true)
		{
			PlayerOwner().myHUD.PauseMovie(false);
			guibtnPlayMovie.DisableMe();
			bPauseButtonPressed = false;
		}
		else
		{
			guibtnStopMovie.EnableMe();
			guibtnPlayMovie.DisableMe();
			PlayerOwner().myHUD.PlayMovieScaled(AGP_HUD(PlayerOwner().myHUD).mtMovieToPlay, 0.0025, 0.0015, 0.0075, 0.0065, false, false, false, AGP_HUD(PlayerOwner().myHUD).iMovieFrameRate);
			PlayerOwner().myHUD.TextureMovie.Movie.SetVolume(fpMovieVolume);
			if (Len(string(AGP_HUD(PlayerOwner().myHUD).sndMovieSoundToPlay)) > 0)
			{
				HumanController(PlayerOwner()).ViewTarget.PlaySound(AGP_HUD(PlayerOwner().myHUD).sndMovieSoundToPlay, 0, 1, , , , false);
			}
		}
		guibtnPauseMovie.EnableMe();
		bHasBeenPlayedOnce = true;
		SetTimer(0.1, true);
		GOTO JL0532;
	case guibtnRewindMovie:
		PlayerOwner().myHUD.RewindMovie(5);
		GOTO JL0532;
	case guibtnFastForwardMovie:
		if (PlayerOwner().Level != None)
		{
			if (PlayerOwner().Level.TimeSeconds >= (iLastTimeFFPressed + 0.1))
			{
				PlayerOwner().myHUD.FastForwardMovie(5);
			}
			iLastTimeFFPressed = PlayerOwner().Level.TimeSeconds;
		}
		GOTO JL0532;
	case guibtnVolumeIcon:
		if (!bIsMuted)
		{
			fpSavedMovieVolume = fpMovieVolume;
			fpMovieVolume = 0;
			guisVolume.SetValue(fpMovieVolume);
			PlayerOwner().myHUD.TextureMovie.Movie.SetVolume(fpMovieVolume);
			guibtnVolumeIcon.Image = texVolumeIconMute;
			guisVolume.DisableMe();
			bIsMuted = true;
		}
		else
		{
			fpMovieVolume = fpSavedMovieVolume;
			guisVolume.SetValue((fpMovieVolume * 100));
			PlayerOwner().myHUD.TextureMovie.Movie.SetVolume(fpMovieVolume);
			guibtnVolumeIcon.Image = texVolumeIcon;
			guisVolume.EnableMe();
			bIsMuted = false;
		}
		GOTO JL0532;
	default:
	JL0532:
	}
	*/
	return true;
}

void UAAGameMenu_MoviePlayer::InternalOnChange(UGUIComponent* Sender)
{
	/*
	switch (Sender)
	{
	case guisVolume:
		fpMovieVolume = (guisVolume.Value / 100);
		PlayerOwner().myHUD.TextureMovie.Movie.SetVolume(fpMovieVolume);
		break;
	case guisScrubber:
		PlayerOwner().myHUD.TextureMovie.Movie.JumpToPercent((guisScrubber.Value / 100));
		PlayerOwner().myHUD.PauseMovie(true);
		break;
	default:
	}
	*/
}

void UAAGameMenu_MoviePlayer::ScrubberOnMousePressed(UGUIComponent* Sender, bool bRepeat)
{
	/*
	PlayerOwner().myHUD.PauseMovie(true);
	SetTimer(0, false);
	*/
}

void UAAGameMenu_MoviePlayer::ScrubberOnMouseReleased(UGUIComponent* Sender)
{
	/*
	if (!bPauseButtonPressed)
	{
		PlayerOwner().myHUD.PauseMovie(false);
	}
	SetTimer(0.1, true);
	*/
}

FString UAAGameMenu_MoviePlayer::SecondsToString(float Seconds)
{
	FString Time="";
	/*
	local int32 locMinutes;
	local int32 locSeconds;
	locMinutes = int((Seconds / float(60)));
	locSeconds = int((Seconds % float(60)));
	if (locMinutes < 10)
	{
		Time = "0" $ string(locMinutes);
	}
	else
	{
		Time = string(locMinutes);
	}
	(Time $ = ":");
	if (locSeconds < 10)
	{
		(Time $ = "0" $ string(locSeconds));
	}
	else
	{
		(Time $ = string(locSeconds));
	}
	*/
	return Time;
}

void UAAGameMenu_MoviePlayer::Timer()
{
	/*
	local float PercentComplete;
	local StudentController SC;
	PercentComplete = PlayerOwner().myHUD.TextureMovie.Movie.GetPercentageComplete();
	guisScrubber.SetValue((PercentComplete * 100));
	guilCounter.Caption = SecondsToString((PercentComplete * fMovieTime)) $ " / " $ SecondsToString(fMovieTime);
	if (!PlayerOwner().myHUD.TextureMovie.Movie.IsPlaying())
	{
		guibtnStopMovie.DisableMe();
		guibtnPlayMovie.EnableMe();
		guibtnPauseMovie.DisableMe();
		bPauseButtonPressed = false;
		guisScrubber.SetValue(0);
		if (bHasBeenPlayedOnce)
		{
			HumanController(PlayerOwner()).bRealHeroesVisited = true;
			PlayerOwner().SaveConfig();
			SetTimer(0, false);
			if (bIsInterview && AAGUIController(Controller).bLoggedIn)
			{
				Log("Logged in, and it's an interview...");
				SC = StudentController(PlayerOwner());
				if (SC != None)
				{
					if (!((int((2 * *float(SC.iLastRealHeroVisited))) & SC.iCompleted[15]) > 0))
					{
						Log("Sending Mission Complete Data!  Tour:  14, Mission:  " $ string(SC.iLastRealHeroVisited));
						SC.bDontLockAfterMisionComplete = true;
						SC.SetAuthMissionPassFlag(true);
						SC.SendMissionComplete(14, SC.iLastRealHeroVisited);
						SC.iCompleted[15] = (int((2 * *float(SC.iLastRealHeroVisited))) | SC.iCompleted[15]);
					}
				}
			}
			Log("Player has watched video...enabling scrubber.");
			guibtnRewindMovie.EnableMe();
			guibtnFastForwardMovie.EnableMe();
			guisScrubber.EnableMe();
		}
	}
	*/
}

void UAAGameMenu_MoviePlayer::HandleParameters(FString Param1, FString Param2)
{
	/*
	if (Param1 == "true")
	{
		bIsInterview = true;
	}
	else
	{
		bIsInterview = false;
	}
	Super::HandleParameters(Param1, Param2);
	*/
}
