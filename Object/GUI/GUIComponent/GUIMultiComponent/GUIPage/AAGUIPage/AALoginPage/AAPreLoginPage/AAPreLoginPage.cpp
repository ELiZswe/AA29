// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/AALoginPage/AAPreLoginPage/AAPreLoginPage.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moEditBox/moEditBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moCheckBox/moCheckBox.h"

UAAPreLoginPage::UAAPreLoginPage()
{
	UGUIButton* LoginButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	LoginButton->Caption="LOGIN";
	LoginButton->FontScale = EFontScale::FNS_Small;
	LoginButton->Hint="Login to your America's Army Player Account.";
	LoginButton->WinTop=0.43;
	LoginButton->WinLeft=0.755;
	LoginButton->WinWidth=0.126;
	LoginButton->WinHeight=0.035;
	LoginButton->TabOrder=5;
	//LoginButton->OnClick=AAPreLoginPage.ButtonClick;
	//LoginButton->OnKeyEvent=LoginButton.InternalOnKeyEvent;
	UGUIButton* LanPlayButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	LanPlayButton->Caption="LAN PLAY";
	LanPlayButton->FontScale = EFontScale::FNS_Small;
	LanPlayButton->Hint="Play a LAN game of America's Army on your home network!  Use this to play without logging into your America's Army account.";
	LanPlayButton->WinTop=0.43;
	LanPlayButton->WinLeft=0.63;
	LanPlayButton->WinWidth=0.126;
	LanPlayButton->WinHeight=0.035;
	LanPlayButton->TabOrder=5;
	//LanPlayButton->OnClick=AAPreLoginPage.ButtonClick;
	//LanPlayButton->OnKeyEvent=LanPlayButton.InternalOnKeyEvent;
	UGUIButton* ExploreButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	ExploreButton->Caption="EXPLORE";
	ExploreButton->FontScale = EFontScale::FNS_Small;
	ExploreButton->Hint="Get started playing right away with Instant Action and see what America's Army is all about!";
	ExploreButton->WinTop=0.8;
	ExploreButton->WinLeft=0.1975;
	ExploreButton->WinWidth=0.126;
	ExploreButton->WinHeight=0.035;
	ExploreButton->TabOrder=6;
	//ExploreButton->OnClick=AAPreLoginPage.ButtonClick;
	//ExploreButton->OnKeyEvent=ExploreButton.InternalOnKeyEvent;
	UGUIButton* SupportButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	SupportButton->Caption="HELP";
	SupportButton->FontScale = EFontScale::FNS_Small;
	SupportButton->Hint="Get Help with America's Army.";
	SupportButton->WinTop=0.8;
	SupportButton->WinLeft=0.3575;
	SupportButton->WinWidth=0.126;
	SupportButton->WinHeight=0.035;
	SupportButton->TabOrder=7;
	//SupportButton->OnClick=AAPreLoginPage.ButtonClick;
	//SupportButton->OnKeyEvent=SupportButton.InternalOnKeyEvent;
	UGUIButton* NewAccountButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	NewAccountButton->Caption="NEW ACCOUNT";
	NewAccountButton->FontScale = EFontScale::FNS_Small;
	NewAccountButton->Hint="Create a new America's Army player account.";
	NewAccountButton->WinTop=0.8;
	NewAccountButton->WinLeft=0.5175;
	NewAccountButton->WinWidth=0.125;
	NewAccountButton->WinHeight=0.035;
	NewAccountButton->TabOrder=8;
	//NewAccountButton->OnClick=AAPreLoginPage.ButtonClick;
	//NewAccountButton->OnKeyEvent=NewAccountButton.InternalOnKeyEvent;
	UmoEditBox* UserNameBox = NewObject<UmoEditBox>(UmoEditBox::StaticClass());
	UserNameBox->CaptionWidth=0;
	//UserNameBox->OnCreateComponent=UserNameBox.InternalOnCreateComponent;
	UserNameBox->IniOption="@Internal";
	UserNameBox->Hint="Enter your user name here.";
	UserNameBox->WinTop=0.3;
	UserNameBox->WinLeft=0.63;
	UserNameBox->WinWidth=0.25;
	UserNameBox->WinHeight=0.04;
	UserNameBox->TabOrder=2;
	UserNameBox->bStandardized=false;
	//UserNameBox->OnLoadINI=AAPreLoginPage.InternalOnLoadINI;
	UmoEditBox* PasswordBox = NewObject<UmoEditBox>(UmoEditBox::StaticClass());
	PasswordBox->bMaskText=true;
	PasswordBox->CaptionWidth=0;
	//PasswordBox->OnCreateComponent=PasswordBox.InternalOnCreateComponent;
	PasswordBox->IniOption="@Internal";
	PasswordBox->Hint="Enter your password here.";
	PasswordBox->WinTop=0.365;
	PasswordBox->WinLeft=0.63;
	PasswordBox->WinWidth=0.25;
	PasswordBox->WinHeight=0.04;
	PasswordBox->TabOrder=3;
	PasswordBox->bStandardized=false;
	//PasswordBox->OnLoadINI=AAPreLoginPage.InternalOnLoadINI;
	UmoCheckBox* RememberUserCheckBox = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	RememberUserCheckBox->CaptionWidth=0.9;
	RememberUserCheckBox->Caption="Remember Login";
	//RememberUserCheckBox->OnCreateComponent=RememberUserCheckBox.InternalOnCreateComponent;
	RememberUserCheckBox->IniOption="@Internal";
	RememberUserCheckBox->Hint="Check this box to remember the username and password for the next session.";
	RememberUserCheckBox->WinTop=0.5;
	RememberUserCheckBox->WinLeft=0.63;
	RememberUserCheckBox->WinWidth=0.25;
	RememberUserCheckBox->WinHeight=0.035;
	RememberUserCheckBox->TabOrder=1;
	RememberUserCheckBox->bStandardized=false;
	//RememberUserCheckBox->OnChange=AAPreLoginPage.InternalOnChange;
	//RememberUserCheckBox->OnLoadINI=AAPreLoginPage.InternalOnLoadINI;
	UmoCheckBox* AutoLoadCheckBox = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	AutoLoadCheckBox->CaptionWidth=0.9;
	AutoLoadCheckBox->Caption="Automatically Log in";
	//AutoLoadCheckBox->OnCreateComponent=AutoLoadCheckBox.InternalOnCreateComponent;
	AutoLoadCheckBox->IniOption="@Internal";
	AutoLoadCheckBox->Hint="Check this box to automatically log in.";
	AutoLoadCheckBox->WinTop=0.56;
	AutoLoadCheckBox->WinLeft=0.63;
	AutoLoadCheckBox->WinWidth=0.25;
	AutoLoadCheckBox->WinHeight=0.035;
	AutoLoadCheckBox->TabOrder=4;
	AutoLoadCheckBox->bStandardized=false;
	//AutoLoadCheckBox->OnChange=AAPreLoginPage.InternalOnChange;
	//AutoLoadCheckBox->OnLoadINI=AAPreLoginPage.InternalOnLoadINI;
	UGUILabel* StatusLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	StatusLabel->TextAlign = ETextAlign::TXTA_Right;
	StatusLabel->TextColor=FColor(156, 201, 168, 255);
	StatusLabel->TextFont="AAFontMedium";
	StatusLabel->WinTop=0.65;
	StatusLabel->WinLeft=0.58;
	StatusLabel->WinWidth=0.3;
	StatusLabel->WinHeight=0.05;
	UGUILabel* AuthMessageLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	AuthMessageLabel->Caption="Error.||Login Unsuccessful.||Please try again, or press the SUPPORT button for instructions on submitting a Help Ticket via the America's Army Support Web Site.";
	AuthMessageLabel->TextColor=FColor(50, 30, 150, 255);
	AuthMessageLabel->TextFont="AAFontMedium";
	AuthMessageLabel->bMultiLine=true;
	AuthMessageLabel->WinTop=0.2;
	AuthMessageLabel->WinLeft=0.14;
	AuthMessageLabel->WinWidth=0.36;
	AuthMessageLabel->WinHeight=0.4;
	AuthMessageLabel->bVisible=false;
	UGUILabel* LoginLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	LoginLabel->Caption="If you already have an America's Army player account, enter your User Name and Password in the fields provided.";
	LoginLabel->TextColor=FColor(156, 201, 168, 255);
	LoginLabel->TextFont="AAFontMedium";
	LoginLabel->bMultiLine=true;
	LoginLabel->VertAlign = ETextAlign::TXTA_Center;
	LoginLabel->WinTop=0.2;
	LoginLabel->WinLeft=0.12;
	LoginLabel->WinWidth=0.4;
	LoginLabel->WinHeight=0.1;
	UGUILabel* OptionsLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	OptionsLabel->Caption="Or choose from an option below:";
	OptionsLabel->TextColor=FColor(156, 201, 168, 255);
	OptionsLabel->TextFont="AAFontMedium";
	OptionsLabel->bMultiLine=true;
	OptionsLabel->VertAlign = ETextAlign::TXTA_Center;
	OptionsLabel->WinTop=0.3;
	OptionsLabel->WinLeft=0.12;
	OptionsLabel->WinWidth=0.4;
	OptionsLabel->WinHeight=0.05;
	UGUILabel* ExploreLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	ExploreLabel->Caption="- Instant Action";
	ExploreLabel->TextColor=FColor(204, 255, 255, 255);
	ExploreLabel->TextFont="AAFontMedium";
	ExploreLabel->VertAlign = ETextAlign::TXTA_Center;
	ExploreLabel->WinTop=0.365;
	ExploreLabel->WinLeft=0.12;
	ExploreLabel->WinWidth=0.4;
	ExploreLabel->WinHeight=0.05;
	UGUILabel* ExploreDescriptionLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	ExploreDescriptionLabel->Caption="Get started playing right away with Instant Action!  Then to gain access to more roles and gear complete your training and unlock everything America's Army has to offer!";
	ExploreDescriptionLabel->TextColor=FColor(156, 201, 168, 255);
	ExploreDescriptionLabel->TextFont="AAFontSmall";
	ExploreDescriptionLabel->bMultiLine=true;
	ExploreDescriptionLabel->WinTop=0.405;
	ExploreDescriptionLabel->WinLeft=0.13;
	ExploreDescriptionLabel->WinWidth=0.35;
	ExploreDescriptionLabel->WinHeight=0.15;
	UGUILabel* SupportLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	SupportLabel->Caption="- Get Help From our Support Page";
	SupportLabel->TextColor=FColor(204, 255, 255, 255);
	SupportLabel->TextFont="AAFontMedium";
	SupportLabel->VertAlign = ETextAlign::TXTA_Center;
	SupportLabel->WinTop=0.5;
	SupportLabel->WinLeft=0.12;
	SupportLabel->WinWidth=0.4;
	SupportLabel->WinHeight=0.05;
	UGUILabel* SupportDescriptionLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	SupportDescriptionLabel->Caption="If you need help with America's Army, press the 'Help' button to view the support options available on the America's Army Web Site.";
	SupportDescriptionLabel->TextColor=FColor(156, 201, 168, 255);
	SupportDescriptionLabel->TextFont="AAFontSmall";
	SupportDescriptionLabel->bMultiLine=true;
	SupportDescriptionLabel->WinTop=0.54;
	SupportDescriptionLabel->WinLeft=0.13;
	SupportDescriptionLabel->WinWidth=0.35;
	SupportDescriptionLabel->WinHeight=0.15;
	UGUILabel* NewAccountLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	NewAccountLabel->Caption="- Create a New Account";
	NewAccountLabel->TextColor=FColor(204, 255, 255, 255);
	NewAccountLabel->TextFont="AAFontMedium";
	NewAccountLabel->VertAlign = ETextAlign::TXTA_Center;
	NewAccountLabel->WinTop=0.64;
	NewAccountLabel->WinLeft=0.12;
	NewAccountLabel->WinWidth=0.4;
	NewAccountLabel->WinHeight=0.05;
	UGUILabel* NewAccountDescriptionLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	NewAccountDescriptionLabel->Caption="If you would like to create a player account for America's Army, press the NEW ACCOUNT button to minimize the game and visit the America's Army Web Site.";
	NewAccountDescriptionLabel->TextColor=FColor(156, 201, 168, 255);
	NewAccountDescriptionLabel->TextFont="AAFontSmall";
	NewAccountDescriptionLabel->bMultiLine=true;
	NewAccountDescriptionLabel->WinTop=0.68;
	NewAccountDescriptionLabel->WinLeft=0.13;
	NewAccountDescriptionLabel->WinWidth=0.35;
	NewAccountDescriptionLabel->WinHeight=0.15;
	
	b_LogIn = LoginButton;
	b_Explore = ExploreButton;
	b_Support = SupportButton;
	b_NewAccount = NewAccountButton;
	btnLANPlay = LanPlayButton;
	ch_RememberUser = RememberUserCheckBox;
	ch_AutoLoad = AutoLoadCheckBox;
	l_Status = StatusLabel;
	l_AuthMessage = AuthMessageLabel;
	l_Login = LoginLabel;
	l_Options = OptionsLabel;
	l_OptionExplore = ExploreLabel;
	l_OptionExploreDescription = ExploreDescriptionLabel;
	l_OptionSupport = SupportLabel;
	l_OptionSupportDescription = SupportDescriptionLabel;
	l_OptionNewAccount = NewAccountLabel;
	l_OptionNewAccountDescription = NewAccountDescriptionLabel;
	ed_Username = UserNameBox;
	ed_Password = PasswordBox;
	sStatus = "Cannot load profile now.";
	sReady = "Ready.";
	sError = "Login Error.";
	sUserName = "Invalid User Name.";
	sUserNameDescription = "Please enter a valid user name in the \"User Name\" field.";
	sPassword = "Invalid Password.";
	sPasswordDescription = "Please enter a valid password in the \"Password\" field.";
}

void UAAPreLoginPage::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	//Super::InitComponent(MyController, MyOwner);
}

void UAAPreLoginPage::Opened(UGUIComponent* Sender)
{
	/*
	local DBAuth.KeyGenerator KeyGenerator;
	Super::Opened(Sender);
	l_Status.Caption = "";
	if (AAGUIController(Controller) != None)
	{
		AAGUIController(Controller).bLoggedIn = false;
	}
	if (Class'DBAuth.KeyGenerator'.DoesKeyNeedGeneration())
	{
		KeyGenerator = new () classClass'DBAuth.KeyGenerator';
		KeyGenerator.BeginKeyGeneration();
		Assert(KeyGenerator.IsKeyGenerationComplete());
	}
	*/
}

bool UAAPreLoginPage::ButtonClick(UGUIComponent* Sender)
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
	case btnLANPlay:
		Controller.ReplaceMenu("AGP_Interface.AAMainMenu", "AA BROWSER");
		Profile("Explore");
		return true;
	case b_LogIn:
		Profile("Login");
		if (HumanController(PlayerOwner()) != None)
		{
			HumanController(PlayerOwner()).SetAutoLoggedInRunOnce();
		}
		Login(b_LogIn);
		SaveSettings();
		Profile("Login");
		return true;
	case b_Explore:
		Profile("Explore");
		Controller.OpenMenu("AGP_Interface.AAGenericMessageBox", "Instant Action", "Start playing right away with Instant Action on any server not running a Special Forces Exclusive maps in three simple steps!||1. Create an account if you don't already have one.|2. Enter your account name and password and log in here.|3. From the main America's Army menu, click on 'Explore the Army' to start playing immediately!");
		return true;
	case b_Support:
		Profile("Support");
		Controller.ReplaceMenu("AGP_Interface.AAMainMenu", "SUPPORT");
		Profile("Support");
		return true;
	case b_NewAccount:
		Profile("NewAccount");
		Controller.OpenMenu("AGP_Interface.AAExternalLinkPage", "http://www.americasarmy.com/", "http://login.americasarmy.com/views/index.php");
		Profile("NewAccount");
		return true;
	case b_Quit:
		Profile("Quit");
		Controller.OpenMenu("AGP_Interface.AAExitPage");
		Profile("Quit");
		return true;
	default:
		StopWatch(true);
		return true;
	}
	*/
	return false;    //FAKE   /ELiZ
}

void UAAPreLoginPage::InternalOnLoadINI(UGUIComponent* Sender, FString S)
{
	/*
	if (HumanController(PlayerOwner()) != None)
	{
		HumanController(PlayerOwner()).RestoreSavedUserNameAndPassword();
	}
	switch (Sender)
	{
	case ch_RememberUser:
		bSaveProfile = (!Class'AGP.HumanController'.Default.bDontRememberUsernameAndPassword);
		ch_RememberUser.Checked(bSaveProfile);
		break;
	case ch_AutoLoad:
		bAutoLoad = Class'AGP.HumanController'.Default.bAutoLoad;
		ch_AutoLoad.Checked(bAutoLoad);
		if (bAutoLoad && (!HumanController(PlayerOwner()).HasAutoLoggedInRunOnce()))
		{
			HumanController(PlayerOwner()).SetAutoLoggedInRunOnce();
			Login(ch_AutoLoad);
		}
		break;
	case ed_Username:
		if (!Class'AGP.HumanController'.Default.bDontRememberUsernameAndPassword)
		{
			ed_Username.SetText(Class'AGP.HumanController'.Default.UserName);
		}
		else
		{
			ed_Username.SetText("UserName");
		}
		GOTO JL018B;
	case ed_Password:
		if (!Class'AGP.HumanController'.Default.bDontRememberUsernameAndPassword)
		{
			ed_Password.SetText(Class'AGP.HumanController'.Default.UserPassword);
		}
		else
		{
			ed_Password.SetText("UserPassword");
		}
		GOTO JL018B;
	default:
	JL018B:
	}
	*/
}

void UAAPreLoginPage::InternalOnChange(UGUIComponent* Sender)
{
	/*
	switch (Sender)
	{
	case ch_RememberUser:
		bSaveProfile = ch_RememberUser.IsChecked();
		SaveSettings();
		break;
	case ch_AutoLoad:
		bAutoLoad = ch_AutoLoad.IsChecked();
		SaveSettings();
		break;
	case ed_Username:
		break;
	case ed_Password:
		break;
	default:
	}
	*/
}

void UAAPreLoginPage::InternalSetLoginStatus(int32 iStatus, FString asStatus, FString sNavMsg)
{
	/*
	HumanController HC = nullptr;
	HC = HumanController(PlayerOwner());
	if (HC == None)
	{
		l_Status.Caption = "";
		EnableComponent(b_LogIn);
		EnableComponent(b_Explore);
		EnableComponent(b_Support);
		EnableComponent(b_NewAccount);
		_iLoginStatus = 0;
		return;
	}
	_iLoginStatus = iStatus;
	l_Status.Caption = asStatus;
	if ((iStatus == 0) && (Len(sNavMsg) > 0))
	{
		Controller.OpenMenu("AGP_Interface.AAGenericMessageBox", sError, sNavMsg);
	}
	if (_iLoginStatus == 2)
	{
		if (AAGUIController(Controller) != None)
		{
			AAGUIController(Controller).bLoggedIn = true;
		}
		if (AGP_HUD(PlayerOwner().myHUD).GetCurrentServerBrowser(false).IsSupportsFavorites())
		{
			class'AGP_Interface.AABrowser_FavoritesPanel'.Default.Favorites.RefreshFavoritesFromServer(HC.UserName, HC.UserPassword, PlayerOwner());
		}
		_iLoginStatus = 0;
		EnableComponent(b_LogIn);
		EnableComponent(b_Explore);
		EnableComponent(b_Support);
		EnableComponent(b_NewAccount);
		Controller.ReplaceMenu("AGP_Interface.AAPostLoginPage");
	}
	else
	{
		if (_iLoginStatus != 1)
		{
			EnableComponent(b_LogIn);
			EnableComponent(b_Explore);
			EnableComponent(b_Support);
			EnableComponent(b_NewAccount);
		}
	}
	*/
}

void UAAPreLoginPage::SaveSettings()
{
	/*
	Class'AGP.HumanController'.Default.UserName = ed_Username.GetText();
	Class'AGP.HumanController'.Default.sSavedUserName = ed_Username.GetText();
	HumanController(PlayerOwner()).UserName = ed_Username.GetText();
	HumanController(PlayerOwner()).sSavedUserName = ed_Username.GetText();
	Class'AGP.HumanController'.Default.bDontRememberUsernameAndPassword = (!bSaveProfile);
	Class'AGP.HumanController'.Default.bAutoLoad = bAutoLoad;
	Log("Recording user name \"" $ HumanController(PlayerOwner()).UserName $ "\" for server logins.");
	Class'AGP.HumanController'.StaticSaveConfig();
	HumanController(PlayerOwner()).ObfuscatePassword(ed_Password.GetText());
	bSaveProfile = ch_RememberUser.IsChecked();
	*/
}

bool UAAPreLoginPage::Login(UGUIComponent* Sender)
{
	/*
	HumanController HC = nullptr;
	HC = HumanController(PlayerOwner());
	if (HC == None)
	{
		return false;
	}
	AGP_HUD(HumanController(PlayerOwner()).myHUD).__OnSetLoginStatus__Delegate = InternalSetLoginStatus;
	if ((ed_Username.GetText() == "") || (ed_Username.GetText() == "UserName"))
	{
		Controller.OpenMenu("AGP_Interface.AAGenericMessageBox", sUserName, sUserNameDescription);
		return false;
	}
	DisableComponent(b_LogIn);
	DisableComponent(b_Explore);
	DisableComponent(b_Support);
	DisableComponent(b_NewAccount);
	if ((_iLoginStatus == 0) || (_iLoginStatus == -1))
	{
		SaveSettings();
		HC.UserName = ed_Username.GetText();
		HC.UserPassword = ed_Password.GetText();
		if (!HC.LoadUserProfileAndNews())
		{
			l_Status.Caption = sStatus;
		}
	}
	*/
	return true;
}
