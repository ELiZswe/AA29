// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/FloatingWindow/LargeWindow/AAGameMenu_RHModal/AAGameMenu_RHModal.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIBorder/GUITitleBar/GUIHeader/GUIHeader.h"

UAAGameMenu_RHModal::UAAGameMenu_RHModal()
{
	UGUIButton* PlayNowButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	PlayNowButton->Caption = "Play Now!";
	PlayNowButton->FontScale = EFontScale::FNS_Small;
	PlayNowButton->Hint = "Jump into 10 of our most popular maps for some Instant Action!";
	PlayNowButton->WinTop = 0.75;
	PlayNowButton->WinLeft = 0.05;
	PlayNowButton->WinWidth = 0.18;
	PlayNowButton->WinHeight = 0.044;
	PlayNowButton->RenderWeight = 0.9;
	PlayNowButton->bBoundToParent = true;
	PlayNowButton->bScaleToParent = true;
	//PlayNowButton->OnClick=AAGameMenu_RHModal.ButtonClick;
	//PlayNowButton->OnKeyEvent=PlayNowButton.InternalOnKeyEvent;
	UGUIButton* WatchInterviewButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	WatchInterviewButton->Caption = "Real Hero Video";
	WatchInterviewButton->FontScale = EFontScale::FNS_Small;
	WatchInterviewButton->Hint = "Watch a full-motion video interview with this Real Hero.";
	WatchInterviewButton->WinTop = 0.75;
	WatchInterviewButton->WinLeft = 0.29;
	WatchInterviewButton->WinWidth = 0.18;
	WatchInterviewButton->WinHeight = 0.044;
	WatchInterviewButton->RenderWeight = 0.9;
	WatchInterviewButton->bBoundToParent = true;
	WatchInterviewButton->bScaleToParent = true;
	//WatchInterviewButton->OnClick=AAGameMenu_RHModal.ButtonClick;
	//WatchInterviewButton->OnKeyEvent=WatchInterviewButton.InternalOnKeyEvent;
	UGUIButton* WatchMOSButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	WatchMOSButton->Caption = "MOS Video";
	WatchMOSButton->FontScale = EFontScale::FNS_Small;
	WatchMOSButton->Hint = "Watch a full-motion video sequence about this Real Hero's Army MOS.";
	WatchMOSButton->WinTop = 0.75;
	WatchMOSButton->WinLeft = 0.53;
	WatchMOSButton->WinWidth = 0.18;
	WatchMOSButton->WinHeight = 0.044;
	WatchMOSButton->RenderWeight = 0.9;
	WatchMOSButton->bBoundToParent = true;
	WatchMOSButton->bScaleToParent = true;
	//WatchMOSButton->OnClick=AAGameMenu_RHModal.ButtonClick;
	//WatchMOSButton->OnKeyEvent=WatchMOSButton.InternalOnKeyEvent;
	UGUIButton* CloseButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	CloseButton->Caption = "Close";
	CloseButton->FontScale = EFontScale::FNS_Small;
	CloseButton->Hint = "Close this window and continue exploring the Virtual Recruiting Station.";
	CloseButton->WinTop = 0.75;
	CloseButton->WinLeft = 0.77;
	CloseButton->WinWidth = 0.18;
	CloseButton->WinHeight = 0.044;
	CloseButton->RenderWeight = 0.9;
	CloseButton->bBoundToParent = true;
	CloseButton->bScaleToParent = true;
	//CloseButton->OnClick=AAGameMenu_RHModal.ButtonClick;
	//CloseButton->OnKeyEvent=CloseButton.InternalOnKeyEvent;
	UGUILabel* HeaderLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	HeaderLabel->Caption = "America's Army Real Heroes Videos";
	HeaderLabel->TextAlign = ETextAlign::TXTA_Center;
	HeaderLabel->TextColor = FColor(200, 200, 200, 255);
	HeaderLabel->TextFont = "AAFontLarge";
	HeaderLabel->bMultiLine = true;
	HeaderLabel->WinTop = 0.1;
	HeaderLabel->WinLeft = 0.03;
	HeaderLabel->WinWidth = 0.94;
	HeaderLabel->WinHeight = 0.25;
	HeaderLabel->RenderWeight = 0.5;
	HeaderLabel->bBoundToParent = true;
	HeaderLabel->bScaleToParent = true;
	UGUILabel* MyNameLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	MyNameLabel->Caption = "My name is {rank last name}, I served in Iraq as an {mos} with the {assigned unit].  My name is {rank last name}, I served in Iraq as an {mos} with the {assigned unit].  My name is {rank last name}, I served in Iraq as an {mos} with the {assigned unit].  ";
	MyNameLabel->TextAlign = ETextAlign::TXTA_Center;
	MyNameLabel->TextColor = FColor(175, 175, 175, 255);
	MyNameLabel->TextFont = "AAFontMedium";
	MyNameLabel->bMultiLine = true;
	MyNameLabel->WinTop = 0.3;
	MyNameLabel->WinLeft = 0.03;
	MyNameLabel->WinWidth = 0.94;
	MyNameLabel->WinHeight = 0.3;
	MyNameLabel->RenderWeight = 0.5;
	MyNameLabel->bBoundToParent = true;
	MyNameLabel->bScaleToParent = true;
	UGUILabel* ChooseOptionLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	ChooseOptionLabel->Caption = "Choose one of the options below:";
	ChooseOptionLabel->TextAlign = ETextAlign::TXTA_Center;
	ChooseOptionLabel->TextColor = FColor(175, 175, 175, 255);
	ChooseOptionLabel->TextFont = "AAFontMedium";
	ChooseOptionLabel->bMultiLine = true;
	ChooseOptionLabel->WinTop = 0.65;
	ChooseOptionLabel->WinLeft = 0.03;
	ChooseOptionLabel->WinWidth = 0.94;
	ChooseOptionLabel->WinHeight = 0.3;
	ChooseOptionLabel->RenderWeight = 0.5;
	ChooseOptionLabel->bBoundToParent = true;
	ChooseOptionLabel->bScaleToParent = true;
	UGUIImage* MyBackground = NewObject<UGUIImage>(UGUIImage::StaticClass());
	MyBackground->Image = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/field_tabwindo_Mat.field_tabwindo_Mat'"), NULL, LOAD_None, NULL);
	MyBackground->ImageStyle = EImgStyle::ISTY_Stretched;
	MyBackground->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	MyBackground->WinHeight = 1;
	MyBackground->RenderWeight = 1E-05;
	MyBackground->bBoundToParent = true;
	MyBackground->bScaleToParent = true;
	UGUIHeader* TitleBar = NewObject<UGUIHeader>(UGUIHeader::StaticClass());
	TitleBar->bUseTextHeight = true;
	TitleBar->FontScale = EFontScale::FNS_Medium;
	TitleBar->WinHeight = 0.065;
	TitleBar->RenderWeight = 0.1;
	TitleBar->bBoundToParent = true;
	TitleBar->bScaleToParent = true;
	TitleBar->bAcceptsInput = true;
	TitleBar->bNeverFocus = false;
	TitleBar->ScalingType = EParentScaleType::SCALE_X;
	//TitleBar->OnMousePressed=AAGameMenu_RHModal.FloatingMousePressed;
	//TitleBar->OnMouseRelease=AAGameMenu_RHModal.FloatingMouseRelease;
	guibtnPlayNow = PlayNowButton;
	guibtnWatchInterview = WatchInterviewButton;
	guibtnWatchMOS = WatchMOSButton;
	guibtnClose = CloseButton;
	guilblHeader = HeaderLabel;
	guilblMyName = MyNameLabel;
	guilblChooseOption = ChooseOptionLabel;
	guiimgBackground = MyBackground;
	t_WindowTitle = TitleBar;
	WindowName = "Welcome to Instant Action";
	bRestorable = true;
	WinLeft = 0.125;
	WinWidth = 0.75;
}

void UAAGameMenu_RHModal::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	//Super::InitComponent(MyController, MyOwner);
}

void UAAGameMenu_RHModal::OnOpen()
{
	/*
	local AGP_HUD HUD;
	Super::OnOpen();
	HUD = AGP_HUD(PlayerOwner().myHUD);
	guilblMyName.Caption = HUD.sRHModalText;
	bPlayerHUD = HUD.bShowHUD;
	HUD.bShowVersion = true;
	HUD.bShowSpectatorInfo = false;
	HUD.bShowHUD = false;
	PlayerOwner().LockPlayer(true, true);
	PlayerOwner().DoFade(false, true, 0.5, 0.75);
	*/
}

void UAAGameMenu_RHModal::OnClose(bool bCanceled)
{
	/*
	local AGP_HUD HUD;
	local PlayerController PC;
	PC = PlayerOwner();
	Super::OnClose(bCanceled);
	HUD = AGP_HUD(PlayerOwner().myHUD);
	HUD.bShowVersion = false;
	HUD.bShowSpectatorInfo = true;
	HUD.bShowHUD = bPlayerHUD;
	PlayerOwner().LockPlayer(false, false);
	PlayerOwner().DoFade(true, true, 0.5, 0.75);
	*/
}

bool UAAGameMenu_RHModal::OnCanClose(bool bCancelled)
{
	return true;
}

bool UAAGameMenu_RHModal::ButtonClick(UGUIComponent* Sender)
{
	/*
	FString LinkToken = "";
	switch (Sender)
	{
	case guibtnClose:
		HumanController(PlayerOwner()).ClientCloseMenu(true);
		break;
	case guibtnPlayNow:
		HumanController(PlayerOwner()).ClientOpenMenu("AGP_Interface.AAMainMenu", false, "INSTANT ACTION");
		break;
	case guibtnWatchInterview:
		Divide(InterviewMovie, ":", LinkToken, InterviewMovie);
		if (StrCmp(LinkToken, "movie") == 0)
		{
			AGP_HUD(HumanController(PlayerOwner()).myHUD).mtMovieToPlay = MovieTexture(DynamicLoadObject(InterviewMovie, Class'MovieTexture'));
			HumanController(PlayerOwner()).ClientOpenMenu("AGP_Interface.AAGameMenu_MoviePlayer", , "true");
		}
		else
		{
			if (StrCmp(LinkToken, "http") == 0)
			{
				InterviewMovie = "http:" $ InterviewMovie;
			}
			HumanController(PlayerOwner()).ClientOpenMenu("AGP_Interface.AARHLinkPage", , "Congratulations, for visiting the Real Heroes web site you'll earn an XP Bonus: +3%|This is a one-time bonus and you must be logged in with a valid, active account", InterviewMovie);
		}
		SilenceRealHeroes();
		bVisible = false;
		GOTO JL0323;
	case guibtnWatchMOS:
		AGP_HUD(HumanController(PlayerOwner()).myHUD).mtMovieToPlay = MovieTexture(DynamicLoadObject(MOSMovie, Class'MovieTexture'));
		AGP_HUD(HumanController(PlayerOwner()).myHUD).sMovieTitle = AGP_HUD(PlayerOwner().myHUD).sMOSMovieTitle;
		AGP_HUD(HumanController(PlayerOwner()).myHUD).sMovieCaption = AGP_HUD(PlayerOwner().myHUD).sMOSMovieCaption;
		HumanController(PlayerOwner()).ClientOpenMenu("AGP_Interface.AAGameMenu_MoviePlayer", );
		SilenceRealHeroes();
		bVisible = false;
		GOTO JL0323;
	default:
	JL0323:
	}
	*/
	return true;
}

void UAAGameMenu_RHModal::HandleParameters(FString Param1, FString Param2)
{
	/*
	InterviewMovie = Param1;
	MOSMovie = Param2;
	Super::HandleParameters(Param1, Param2);
	*/
}

void UAAGameMenu_RHModal::SilenceRealHeroes()
{
	/*
	local NPCRealHeroController RHC;
	ForEach AllObjects(Class'AGP.NPCRealHeroController', RHC)
	{
		if (RHC.Pawn.IsPlayingLIPSincAnim())
		{
			RHC.Pawn.StopLIPSincAnim();
		}
	}
	*/
}

void UAAGameMenu_RHModal::AddSystemMenu()
{
	/*
	local GUI.eFontScale tFontScale;
	b_ExitButton = GUIButton(t_WindowTitle.AddComponent("XInterface.GUIButton"));
	b_ExitButton.Style = Controller.GetStyle("CloseButton", tFontScale);
	b_ExitButton.__OnClick__Delegate = XButtonClicked;
	b_ExitButton.bNeverFocus = true;
	b_ExitButton.FocusInstead = t_WindowTitle;
	b_ExitButton.RenderWeight = 1;
	b_ExitButton.bScaleToParent = false;
	b_ExitButton.__OnPreDraw__Delegate = SystemMenuPreDraw;
	b_ExitButton.bRepeatClick = false;
	*/
}

bool UAAGameMenu_RHModal::SystemMenuPreDraw(UCanvas* Canvas)
{
	//b_ExitButton.SetPosition((t_WindowTitle.ActualLeft() + (t_WindowTitle.ActualWidth() - (0.875 * t_WindowTitle.ActualHeight()))), (t_WindowTitle.ActualTop() + (0.025 * t_WindowTitle.ActualHeight())), (0.9 * t_WindowTitle.ActualHeight()), (0.95 * t_WindowTitle.ActualHeight()), true);
	return true;
}

bool UAAGameMenu_RHModal::XButtonClicked(UGUIComponent* Sender)
{
	//HumanController(PlayerOwner()).ClientCloseMenu(true);
	return true;
}