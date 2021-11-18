// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/AAEntryPage/AAEntryPage.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImageButton/GUIImageButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/BackgroundImage/BackgroundImage.h"
UAAEntryPage::UAAEntryPage()
{
	UGUIButton* PersonnelJacketButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	PersonnelJacketButton->Caption = "PERSONNEL JACKET";
	PersonnelJacketButton->bUseCaptionHeight = true;
	PersonnelJacketButton->FontScale = EFontScale::FNS_Small;
	PersonnelJacketButton->StyleName = "EntryButton";
	PersonnelJacketButton->Hint = "Create and maintain soldier information";
	PersonnelJacketButton->WinTop = 0.25;
	PersonnelJacketButton->WinLeft = 0.35;
	PersonnelJacketButton->WinWidth = 0.3;
	PersonnelJacketButton->WinHeight = 0.075;
	PersonnelJacketButton->TabOrder = 1;
	PersonnelJacketButton->bFocusOnWatch = true;
	//PersonnelJacketButton->OnClick=AAEntryPage.ButtonClick;
	//PersonnelJacketButton->OnKeyEvent=PersonnelJacketButton.InternalOnKeyEvent;
	UGUIButton* TrainingButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	TrainingButton->Caption = "TRAINING";
	TrainingButton->bUseCaptionHeight = true;
	TrainingButton->FontScale = EFontScale::FNS_Small;
	TrainingButton->StyleName = "EntryButton";
	TrainingButton->Hint = "Finish basic and other training missions";
	TrainingButton->WinTop = 0.3;
	TrainingButton->WinLeft = 0.35;
	TrainingButton->WinWidth = 0.3;
	TrainingButton->WinHeight = 0.075;
	TrainingButton->TabOrder = 2;
	TrainingButton->bFocusOnWatch = true;
	//TrainingButton->OnClick=AAEntryPage.ButtonClick;
	//TrainingButton->OnKeyEvent=TrainingButton.InternalOnKeyEvent;
	UGUIButton* DeploymentButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	DeploymentButton->Caption = "DEPLOYMENT";
	DeploymentButton->bUseCaptionHeight = true;
	DeploymentButton->FontScale = EFontScale::FNS_Small;
	DeploymentButton->StyleName = "EntryButton";
	DeploymentButton->Hint = "Find Internet and LAN games";
	DeploymentButton->WinTop = 0.35;
	DeploymentButton->WinLeft = 0.35;
	DeploymentButton->WinWidth = 0.3;
	DeploymentButton->WinHeight = 0.075;
	DeploymentButton->TabOrder = 3;
	DeploymentButton->bFocusOnWatch = true;
	//DeploymentButton->OnClick=AAEntryPage.ButtonClick;
	//DeploymentButton->OnKeyEvent=DeploymentButton.InternalOnKeyEvent;
	UGUIButton* SettingsButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	SettingsButton->Caption = "SETTINGS";
	SettingsButton->bUseCaptionHeight = true;
	SettingsButton->FontScale = EFontScale::FNS_Small;
	SettingsButton->StyleName = "EntryButton";
	SettingsButton->Hint = "Configure your video, audio and other settings";
	SettingsButton->WinTop = 0.4;
	SettingsButton->WinLeft = 0.35;
	SettingsButton->WinWidth = 0.3;
	SettingsButton->WinHeight = 0.075;
	SettingsButton->TabOrder = 4;
	SettingsButton->bFocusOnWatch = true;
	//SettingsButton->OnClick=AAEntryPage.ButtonClick;
	//SettingsButton->OnKeyEvent=SettingsButton.InternalOnKeyEvent;
	UGUIButton* SupportButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	SupportButton->Caption = "SUPPORT";
	SupportButton->bUseCaptionHeight = true;
	SupportButton->FontScale = EFontScale::FNS_Small;
	SupportButton->StyleName = "EntryButton";
	SupportButton->Hint = "Support information and links";
	SupportButton->WinTop = 0.45;
	SupportButton->WinLeft = 0.35;
	SupportButton->WinWidth = 0.3;
	SupportButton->WinHeight = 0.075;
	SupportButton->TabOrder = 5;
	SupportButton->bFocusOnWatch = true;
	//SupportButton->OnClick=AAEntryPage.ButtonClick;
	//SupportButton->OnKeyEvent=SupportButton.InternalOnKeyEvent;
	UGUIButton* ParentalControlButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	ParentalControlButton->Caption = "PARENTAL CONTROL";
	ParentalControlButton->bUseCaptionHeight = true;
	ParentalControlButton->FontScale = EFontScale::FNS_Small;
	ParentalControlButton->StyleName = "EntryButton";
	ParentalControlButton->Hint = "Set content control and password";
	ParentalControlButton->WinTop = 0.5;
	ParentalControlButton->WinLeft = 0.35;
	ParentalControlButton->WinWidth = 0.3;
	ParentalControlButton->WinHeight = 0.075;
	ParentalControlButton->TabOrder = 6;
	ParentalControlButton->bFocusOnWatch = true;
	//ParentalControlButton->OnClick=AAEntryPage.ButtonClick;
	//ParentalControlButton->OnKeyEvent=ParentalControlButton.InternalOnKeyEvent;
	UGUIButton* CreditsButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	CreditsButton->Caption = "CREDITS";
	CreditsButton->bUseCaptionHeight = true;
	CreditsButton->FontScale = EFontScale::FNS_Small;
	CreditsButton->StyleName = "EntryButton";
	CreditsButton->Hint = "Credits";
	CreditsButton->WinTop = 0.55;
	CreditsButton->WinLeft = 0.35;
	CreditsButton->WinWidth = 0.3;
	CreditsButton->WinHeight = 0.075;
	CreditsButton->TabOrder = 7;
	CreditsButton->bFocusOnWatch = true;
	//CreditsButton->OnClick=AAEntryPage.ButtonClick;
	//CreditsButton->OnKeyEvent=CreditsButton.InternalOnKeyEvent;
	UGUIButton* QuitButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	QuitButton->Caption = "EXIT";
	QuitButton->bUseCaptionHeight = true;
	QuitButton->FontScale = EFontScale::FNS_Small;
	QuitButton->StyleName = "EntryButton";
	QuitButton->Hint = "Exit America's Army";
	QuitButton->WinTop = 0.6;
	QuitButton->WinLeft = 0.35;
	QuitButton->WinWidth = 0.3;
	QuitButton->WinHeight = 0.075;
	QuitButton->TabOrder = 8;
	QuitButton->bFocusOnWatch = true;
	//QuitButton->OnClick=AAEntryPage.ButtonClick;
	//QuitButton->OnKeyEvent=QuitButton.InternalOnKeyEvent;
	UGUIImageButton* AALogoImageButton = NewObject<UGUIImageButton>(UGUIImageButton::StaticClass());
	AALogoImageButton->Caption = "http://www.americasarmy.com/";
	AALogoImageButton->link = "http://www.americasarmy.com/redir.php?r=0";
	AALogoImageButton->Image = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/Logo_AA_hori_Mat.Logo_AA_hori_Mat'"), NULL, LOAD_None, NULL);
	AALogoImageButton->ImageStyle = EImgStyle::ISTY_Scaled;
	AALogoImageButton->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	AALogoImageButton->WinTop = 0.05;
	AALogoImageButton->WinLeft = 0.075;
	AALogoImageButton->WinWidth = 0.85;
	AALogoImageButton->WinHeight = 0.15;
	AALogoImageButton->TabOrder = 9;
	//AALogoImageButton->OnClick=AAEntryPage.ButtonClick;
	//AALogoImageButton->OnKeyEvent=AALogoImageButton.InternalOnKeyEvent;
	UGUIImageButton* USArmyImageButton = NewObject<UGUIImageButton>(UGUIImageButton::StaticClass());
	USArmyImageButton->Caption = "http://www.goarmy.com/";
	USArmyImageButton->link = "http://www.americasarmy.com/redir.php?r=2";
	USArmyImageButton->Image = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/Logo_USArm_Mat.Logo_USArm_Mat'"), NULL, LOAD_None, NULL);
	USArmyImageButton->ImageStyle = EImgStyle::ISTY_Justified;
	USArmyImageButton->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	USArmyImageButton->WinTop = 0.8;
	USArmyImageButton->WinLeft = 0.025;
	USArmyImageButton->WinWidth = 0.15;
	USArmyImageButton->WinHeight = 0.15;
	USArmyImageButton->TabOrder = 10;
	//USArmyImageButton->OnClick=AAEntryPage.ButtonClick;
	//USArmyImageButton->OnKeyEvent=USArmyImageButton.InternalOnKeyEvent;
	UGUIImageButton* ESRBLogoImageButton = NewObject<UGUIImageButton>(UGUIImageButton::StaticClass());
	ESRBLogoImageButton->Caption = "http://www.esrb.com/";
	ESRBLogoImageButton->link = "http://www.americasarmy.com/redir.php?r=17";
	ESRBLogoImageButton->Image = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/Logo_esr_Mat.Logo_esr_Mat'"), NULL, LOAD_None, NULL);
	ESRBLogoImageButton->ImageStyle = EImgStyle::ISTY_Justified;
	ESRBLogoImageButton->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	ESRBLogoImageButton->WinTop = 0.8;
	ESRBLogoImageButton->WinLeft = 0.875;
	ESRBLogoImageButton->WinWidth = 0.15;
	ESRBLogoImageButton->WinHeight = 0.15;
	ESRBLogoImageButton->TabOrder = 11;
	//ESRBLogoImageButton->OnClick=AAEntryPage.ButtonClick;
	//ESRBLogoImageButton->OnKeyEvent=ESRBLogoImageButton.InternalOnKeyEvent;
	UBackgroundImage* PageBackground = NewObject<UBackgroundImage>(UBackgroundImage::StaticClass());
	PageBackground->Image = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Background/Main_BKG1__Mat.Main_BKG1__Mat'"), NULL, LOAD_None, NULL);
	PageBackground->ImageColor = FColor(255, 255, 255, 32);
	PageBackground->ImageStyle = EImgStyle::ISTY_Scaled;
	UGUILabel* VersionLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	VersionLabel->Caption = "Version %major%.%minor%.%tiny%";
	VersionLabel->TextAlign = ETextAlign::TXTA_Center;
	VersionLabel->TextColor = FColor(156, 201, 168, 255);
	VersionLabel->TextFont = "AAFontSmall";
	VersionLabel->TextAlign = ETextAlign::TXTA_Center;
	VersionLabel->WinTop = 0.15;
	VersionLabel->WinLeft = 0.65;
	VersionLabel->WinWidth = 0.411;
	VersionLabel->WinHeight = 0.15;
	VersionLabel->bScaleToParent = true;
	UGUILabel* DisclaimerLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	DisclaimerLabel->Caption = "The presence of logos, URLs or other information identifying private companies or other non-federal entities does not constitute endorsement by the Department of the Army or the Department of Defense";
	DisclaimerLabel->TextAlign = ETextAlign::TXTA_Center;
	DisclaimerLabel->TextColor = FColor(156, 201, 168, 255);
	DisclaimerLabel->TextFont = "AAFontSmall";
	DisclaimerLabel->bMultiLine = true;
	DisclaimerLabel->TextAlign = ETextAlign::TXTA_Center;
	DisclaimerLabel->WinTop = 0.8;
	DisclaimerLabel->WinLeft = 0.2;
	DisclaimerLabel->WinWidth = 0.6;
	DisclaimerLabel->WinHeight = 0.1;
	DisclaimerLabel->bScaleToParent = true;
	UGUILabel* NoticeLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	NoticeLabel->Caption = "ESRB Notice: Game Experience May Change During Online Play";
	NoticeLabel->TextAlign = ETextAlign::TXTA_Center;
	NoticeLabel->TextColor = FColor(156, 201, 168, 255);
	NoticeLabel->TextFont = "AAFontSmall";
	NoticeLabel->bMultiLine = true;
	NoticeLabel->TextAlign = ETextAlign::TXTA_Center;
	NoticeLabel->WinTop = 0.875;
	NoticeLabel->WinLeft = 0.2;
	NoticeLabel->WinWidth = 0.6;
	NoticeLabel->WinHeight = 0.1;
	NoticeLabel->bScaleToParent = true;

	
	i_Background = PageBackground;
	b_PersonnelJacket = PersonnelJacketButton;
	b_Training = TrainingButton;
	b_Deployment = DeploymentButton;
	b_Settings = SettingsButton;
	b_Support = SupportButton;
	b_ParentalControl = ParentalControlButton;
	b_Credits = CreditsButton;
	b_Quit = QuitButton;
	ib_AALogo = AALogoImageButton;
	ib_USArmyLogo = USArmyImageButton;
	ib_ESRBLogo = ESRBLogoImageButton;
	l_Version = VersionLabel;
	l_Disclaimer = DisclaimerLabel;
	l_Notice = NoticeLabel;
	bAllowedAsLast = true;

	//OnOpen = AAEntryPage.InternalOnOpen;
	//OnReOpen = AAEntryPage.Reopened;
	//OnCanClose = AAEntryPage.CanClose;
	WinHeight = 1;
	bDebugging = true;
	//OnKeyEvent = AAEntryPage.internalKeyEvent;
}

//const ADJUST_LATER = 0.0;
//const HINT_HEIGHT = 34;
//const TXT_VER = 14;
//const TXT_DISC = 13;
//const ESRB = 12;
//const LOGO_ARMY = 11;
//const logo_AA = 10;
//const BUTTN_QUIT = 9;
//const BUTTN_CRDT = 8;
//const BUTTN_PRNT = 7;
//const BUTTN_SUPP = 6;
//const BUTTN_SETT = 5;
//const BUTTN_DEPL = 4;
//const BUTTN_TRNG = 3;
//const BUTTN_PERS = 2;
//const HINT_BOX = 1;
//const BACKGRND = 0;

void UAAEntryPage::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	Super::InitComponent(MyController, MyOwner);
	l_Version.Caption = Repl(l_Version.Caption, "%major%", string(GetVersionAGPMajor()));
	l_Version.Caption = Repl(l_Version.Caption, "%minor%", string(GetVersionAGPMinor()));
	l_Version.Caption = Repl(l_Version.Caption, "%tiny%", string(GetVersionAGPTiny()) $ "." $ string(GetVersionAGPSubTiny()));
	*/
}

void UAAEntryPage::Reopened()
{
	/*
	if (!PlayerOwner().Level.IsPendingConnection())
	{
		Opened(None);
	}
	*/
}

void UAAEntryPage::Opened(UGUIComponent* Sender)
{
	/*
	if (bDebugging)
	{
		Log(string(Name) $ ".Opened()   Sender:" $ string(Sender), 'Debug');
	}
	Super::Opened(Sender);
	selected = None;
	*/
}

void UAAEntryPage::InternalOnOpen()
{
	/*
	local DBAuth.KeyGenerator KeyGenerator;
	if (Class'DBAuth.KeyGenerator'.DoesKeyNeedGeneration())
	{
		KeyGenerator = new () classClass'DBAuth.KeyGenerator';
		KeyGenerator.BeginKeyGeneration();
		Assert(KeyGenerator.IsKeyGenerationComplete());
	}
	*/
}

void UAAEntryPage::OnClose(bool bCancelled)
{
}

bool UAAEntryPage::internalKeyEvent(uint8& Key, uint8& State, float Delta)
{
	/*
	if ((Key == 27) && (State == 1))
	{
		bAllowClose = true;
	}
	*/
	return false;
}

bool UAAEntryPage::CanClose(bool bCancelled)
{
	/*
	if (bAllowClose)
	{
		ButtonClick(b_Quit);
	}
	bAllowClose = false;
	return PlayerOwner().Level.IsPendingConnection();
	*/
	return false;   //FAKE   /ELiZ
}

bool UAAEntryPage::ButtonClick(UGUIComponent* Sender)
{
	/*
	if ((GUIButton(Sender) != None) || (GUIImageButton(Sender) != None))
	{
		selected = Sender;
	}
	if (selected == None)
	{
		return false;
	}
	switch (selected)
	{
	case b_PersonnelJacket:
		Profile("PersonnelJacket");
		Controller.ReplaceMenu(Controller.GetMainMenuClass(), "PERSONNEL JACKET");
		Profile("PersonnelJacket");
		return true;
	case b_Training:
		Profile("Training");
		Controller.ReplaceMenu(Controller.GetMainMenuClass(), "TRAINING");
		Profile("Training");
		return true;
	case b_Deployment:
		Profile("Deployment");
		Controller.ReplaceMenu(Controller.GetMainMenuClass(), "DEPLOYMENT");
		Profile("Deployment");
		return true;
	case b_Settings:
		Profile("Settings");
		Controller.ReplaceMenu(Controller.GetMainMenuClass(), "SETTINGS");
		Profile("Settings");
		return true;
	case b_Support:
		Profile("Support");
		Controller.ReplaceMenu(Controller.GetMainMenuClass(), "SUPPORT");
		Profile("Support");
		return true;
	case b_ParentalControl:
		Profile("ParentalControl");
		Controller.ReplaceMenu(Controller.GetMainMenuClass(), "PARENTAL CONTROL");
		Profile("ParentalControl");
		return true;
	case b_Credits:
		Profile("Credits");
		Controller.ReplaceMenu(Controller.GetMainMenuClass(), "CREDITS");
		Profile("Credits");
		return true;
	case b_Quit:
		Profile("Quit");
		Controller.OpenMenu("AGP_Interface.AAQuitPage");
		Profile("Quit");
		return true;
	case ib_AALogo:
		Profile("AALogo");
		Controller.OpenMenu("AGP_Interface.AAExternalLinkPage", ib_AALogo.Caption, ib_AALogo.link);
		Profile("AALogo");
		return true;
	case ib_USArmyLogo:
		Profile("USArmyLogo");
		Controller.OpenMenu("AGP_Interface.AAExternalLinkPage", ib_USArmyLogo.Caption, ib_USArmyLogo.link);
		Profile("USArmyLogo");
		return true;
	case ib_ESRBLogo:
		Profile("ESRBLogo");
		Controller.OpenMenu("AGP_Interface.AAExternalLinkPage", ib_ESRBLogo.Caption, ib_ESRBLogo.link);
		Profile("ESRBLogo");
		return true;
	default:
		StopWatch(true);
		return true;
	}
	*/
	return false;   //FAKE   /ELiZ
}

bool UAAEntryPage::NotifyLevelChange()
{
	/*
	if (bDebugging)
	{
		Log(string(Name) @ "NotifyLevelChange  PendingConnection:" $ string(PlayerOwner().Level.IsPendingConnection()));
	}
	return PlayerOwner().Level.IsPendingConnection();
	*/
	return false;   //FAKE   /ELiZ
}