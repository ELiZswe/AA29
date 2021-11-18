// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AASoldierSubPanel/AAPersonnelJacket_SoldierLogin.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moCheckBox/moCheckBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moEditBox/moEditBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIScrollTextBox/GUIScrollTextBox.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"

UAAPersonnelJacket_SoldierLogin::UAAPersonnelJacket_SoldierLogin()
{
	UGUIButton* CreateAccountButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	CreateAccountButton->Caption="Create Account";
	CreateAccountButton->StyleName="SquareMenuButton";
	CreateAccountButton->Hint="Click here to create an account.";
	CreateAccountButton->WinTop=0.115;
	CreateAccountButton->WinLeft=0.05;
	CreateAccountButton->WinWidth=0.25;
	CreateAccountButton->WinHeight=0.053476;
	CreateAccountButton->TabOrder=5;
	//CreateAccountButton->OnClick=AAPersonnelJacket_SoldierLogin.ButtonClick;
	//CreateAccountButton->OnKeyEvent=CreateAccountButton.InternalOnKeyEvent;
	UGUIScrollTextBox* NewsBox = NewObject<UGUIScrollTextBox>(UGUIScrollTextBox::StaticClass());
	NewsBox->bNoTeletype=true;
	//NewsBox->OnCreateComponent=NewsBox.InternalOnCreateComponent;
	NewsBox->StyleName="AASmallText";
	NewsBox->WinTop=0.1723;
	NewsBox->WinLeft=0.02;
	NewsBox->WinWidth=0.96;
	NewsBox->WinHeight=0.2;
	UmoEditBox* UserNameBox = NewObject<UmoEditBox>(UmoEditBox::StaticClass());
	UserNameBox->CaptionWidth=0.25;
	UserNameBox->Caption="User Name";
	//UserNameBox->OnCreateComponent=UserNameBox.InternalOnCreateComponent;
	UserNameBox->IniOption="@Internal";
	UserNameBox->Hint="Enter your user name here.";
	UserNameBox->WinTop=0.5;
	UserNameBox->WinLeft=0.05;
	UserNameBox->WinWidth=0.65;
	UserNameBox->WinHeight=0.053476;
	UserNameBox->TabOrder=0;
	UserNameBox->bStandardized=false;
	//UserNameBox->OnLoadINI=AAPersonnelJacket_SoldierLogin.InternalOnLoadINI;
	UmoEditBox* PasswordBox = NewObject<UmoEditBox>(UmoEditBox::StaticClass());
	PasswordBox->bMaskText=true;
	PasswordBox->CaptionWidth=0.25;
	PasswordBox->Caption="Password";
	//PasswordBox->OnCreateComponent=PasswordBox.InternalOnCreateComponent;
	PasswordBox->IniOption="@Internal";
	PasswordBox->Hint="Enter your password here.";
	PasswordBox->WinTop=0.565;
	PasswordBox->WinLeft=0.05;
	PasswordBox->WinWidth=0.65;
	PasswordBox->WinHeight=0.053476;
	PasswordBox->TabOrder=1;
	PasswordBox->bStandardized=false;
	//PasswordBox->OnLoadINI=AAPersonnelJacket_SoldierLogin.InternalOnLoadINI;
	UGUIButton* LoginButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	LoginButton->Caption="LOG IN";
	LoginButton->StyleName="SquareMenuButton";
	LoginButton->Hint="Enter your user name and password, then click here to log in.";
	LoginButton->WinTop=0.65;
	LoginButton->WinLeft=0.2125;
	LoginButton->WinWidth=0.2;
	LoginButton->WinHeight=0.053476;
	LoginButton->TabOrder=2;
	//LoginButton->OnClick=AAPersonnelJacket_SoldierLogin.ButtonClick;
	//LoginButton->OnKeyEvent=LoginButton.InternalOnKeyEvent;
	UGUIButton* LogoutButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	LogoutButton->Caption="LOG OUT";
	LogoutButton->StyleName="SquareMenuButton";
	LogoutButton->Hint="Click here to log out.";
	LogoutButton->WinTop=0.65;
	LogoutButton->WinLeft=0.5;
	LogoutButton->WinWidth=0.2;
	LogoutButton->WinHeight=0.053476;
	LogoutButton->TabOrder=3;
	//LogoutButton->OnClick=AAPersonnelJacket_SoldierLogin.ButtonClick;
	//LogoutButton->OnKeyEvent=LogoutButton.InternalOnKeyEvent;
	UmoCheckBox* RememberUserCheckBox = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	RememberUserCheckBox->CaptionWidth=0.9;
	RememberUserCheckBox->Caption="Remember User Name/Password";
	//RememberUserCheckBox->OnCreateComponent=RememberUserCheckBox.InternalOnCreateComponent;
	RememberUserCheckBox->IniOption="@Internal";
	RememberUserCheckBox->Hint="Check this box to remember your username and password.";
	RememberUserCheckBox->WinTop=0.9;
	RememberUserCheckBox->WinLeft=0.35;
	RememberUserCheckBox->WinWidth=0.6;
	RememberUserCheckBox->WinHeight=0.053476;
	RememberUserCheckBox->TabOrder=4;
	RememberUserCheckBox->bStandardized=false;
	//RememberUserCheckBox->OnChange=AAPersonnelJacket_SoldierLogin.InternalOnChange;
	//RememberUserCheckBox->OnLoadINI=AAPersonnelJacket_SoldierLogin.InternalOnLoadINI;
	UGUIButton* GetNewsButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	GetNewsButton->Caption="Get News";
	GetNewsButton->StyleName="SquareMenuButton";
	GetNewsButton->Hint="Click here to get the latest news.";
	GetNewsButton->WinTop=0.115;
	GetNewsButton->WinLeft=0.7;
	GetNewsButton->WinWidth=0.25;
	GetNewsButton->WinHeight=0.06;
	GetNewsButton->TabOrder=6;
	//GetNewsButton->OnClick=AAPersonnelJacket_SoldierLogin.ButtonClick;
	//GetNewsButton->OnKeyEvent=GetNewsButton.InternalOnKeyEvent;
	UGUIImage* FieldBackground = NewObject<UGUIImage>(UGUIImage::StaticClass());
	//FieldBackground->Image=Texture'T_AA2_UI.Menu.field_translucent';
	FieldBackground->ImageStyle = EImgStyle::ISTY_Stretched;
	FieldBackground->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	FieldBackground->WinTop=0.07;
	FieldBackground->WinLeft=0.01;
	FieldBackground->WinWidth=0.98;
	FieldBackground->WinHeight=0.92;
	FieldBackground->RenderWeight=0.2;
	UGUILabel* StatusLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	StatusLabel->Caption="Not Connected...";
	StatusLabel->StyleName="TextLabel";
	StatusLabel->WinTop=0.8;
	StatusLabel->WinLeft=0.05;
	StatusLabel->WinWidth=0.5;
	
	i_FieldBackground = FieldBackground;
	b_CreateAccount = CreateAccountButton;
	b_GetNews = GetNewsButton;
	b_LogIn = LoginButton;
	b_LogOut = LogoutButton;
	ed_Username = UserNameBox;
	ed_Password = PasswordBox;
	ch_RememberUser = RememberUserCheckBox;
	l_Status = StatusLabel;
	stb_News = NewsBox;
	NotConnectedText = "Not Connected...";
	CreateAccountText = "Create an Account";
	PanelCaption = "Login";

}

void UAAPersonnelJacket_SoldierLogin::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	Super::InitComponent(MyController, MyOwner);
	RefreshLoginScreen();
	AGP_HUD(HumanController(PlayerOwner()).myHUD).__OnSetLoginStatus__Delegate = MySetLoginStatus;
	*/
}

bool UAAPersonnelJacket_SoldierLogin::ButtonClick(UGUIComponent* Sender)
{
	/*
	switch (Sender)
	{
	case b_CreateAccount:
		Controller.OpenMenu("AGP_Interface.AAExternalLinkPage", "http://login.americasarmy.com", "http://www.americasarmy.com/redir.php?r=100");
		return true;
	case b_LogIn:
		SelectLogin();
		return true;
	case b_GetNews:
		GetNews();
		return true;
	case b_LogOut:
		Logout();
		return true;
	default:
		return true;
	}
	*/
	return false;    //FAKE   /ELiZ
}

void UAAPersonnelJacket_SoldierLogin::InternalOnLoadINI(UGUIComponent* Sender, FString S)
{
	/*
	bool bRemember = false;
	switch (Sender)
	{
	case ch_RememberUser:
		bRemember = (!HumanController(PlayerOwner()).bDontRememberUsernameAndPassword);
		ch_RememberUser.Checked(bRemember);
		break;
	case ed_Username:
		ed_Username.SetText(Class'AGP.HumanController'.Default.UserName);
		break;
	case ed_Password:
		ed_Password.SetText(Class'AGP.HumanController'.Default.UserPassword);
		break;
	default:
	}
	*/
}

void UAAPersonnelJacket_SoldierLogin::GetNews()
{
	/*
	local HumanController HC;
	HC = HumanController(PlayerOwner());
	if (HC != None)
	{
		HC.UserName = ed_Username.GetText();
		HC.UserPassword = ed_Password.GetText();
		_iLoginStatus = 1;
		stb_News.SetContent(HC.sNewsLine1 $ "|" $ HC.sNewsLine2 $ "|" $ HC.sNewsLine3 $ "|" $ HC.sNewsLine4);
	}
	*/
}

void UAAPersonnelJacket_SoldierLogin::SelectLogin()
{
	/*
	local HumanController HC;
	HC = HumanController(PlayerOwner());
	if ((_iLoginStatus == 0) || (_iLoginStatus == -1))
	{
		SaveSettings();
		HC.UserName = ed_Username.GetText();
		HC.UserPassword = ed_Password.GetText();
		if (HC.Level.Game.bBinaryAuthProtocol)
		{
		}
		_iLoginStatus = 1;
	}
	if (_iLoginStatus == 2)
	{
	}
	*/
}

void UAAPersonnelJacket_SoldierLogin::Logout()
{
	/*
	SaveSettings();
	if (!ch_RememberUser.IsChecked())
	{
		ed_Username.SetText("");
		ed_Password.SetText("");
	}
	AAGUIController(Controller).bLoggedIn = false;
	RefreshLoginScreen();
	*/
}

void UAAPersonnelJacket_SoldierLogin::RefreshLoginScreen()
{
	/*
	FString sTemp = "";
	local HumanController HC;
	HC = HumanController(PlayerOwner());
	if (AAGUIController(Controller).bLoggedIn)
	{
		sTemp = HC.UserName;
		ed_Username.SetText(sTemp);
		sTemp = HC.UserPassword;
		ed_Password.SetText(sTemp);
	}
	stb_News.SetContent(HC.sNewsLine1 $ "|" $ HC.sNewsLine2 $ "|" $ HC.sNewsLine3 $ "|" $ HC.sNewsLine4);
	if ((HC.Level.iTour == -1) && (HC.Level.iMission == -1))
	{
		l_Status.Caption = NotConnectedText;
		l_Status.bVisible = true;
	}
	else
	{
		l_Status.Caption = "";
		l_Status.bVisible = false;
	}
	*/
}

void UAAPersonnelJacket_SoldierLogin::MySetLoginStatus(int32 iStatus, FString sStatus, FString sNavMsg)
{
	/*
	local HumanController HC;
	HC = HumanController(PlayerOwner());
	_iLoginStatus = iStatus;
	l_Status.Caption = sStatus;
	if (_iLoginStatus == 2)
	{
		AAGUIController(Controller).bLoggedIn = true;
		_iLoginStatus = 0;
		stb_News.SetContent(HC.sNewsLine1 $ "|" $ HC.sNewsLine2 $ "|" $ HC.sNewsLine3 $ "|" $ HC.sNewsLine4);
	}
	*/
}

void UAAPersonnelJacket_SoldierLogin::SaveSettings()
{
	/*
	bool bSave = false;
	bool bRemember = false;
	bRemember = ch_RememberUser.IsChecked();
	if (Class'AGP.HumanController'.Default.bDontRememberUsernameAndPassword != (!bRemember))
	{
		Class'AGP.HumanController'.Default.bDontRememberUsernameAndPassword = (!bRemember);
		bSave = true;
	}
	if (bRemember)
	{
		if (Class'AGP.HumanController'.Default.UserName != ed_Username.GetText())
		{
			Class'AGP.HumanController'.Default.UserName = ed_Username.GetText();
			bSave = true;
		}
		if (Class'AGP.HumanController'.Default.UserPassword != ed_Password.GetText())
		{
			Class'AGP.HumanController'.Default.UserPassword = ed_Password.GetText();
			bSave = true;
		}
	}
	else
	{
		Class'AGP.HumanController'.Default.UserName = "";
		Class'AGP.HumanController'.Default.UserPassword = "";
		bSave = true;
	}
	if (bSave)
	{
		Class'AGP.HumanController'.StaticSaveConfig();
	}
	*/
}

void UAAPersonnelJacket_SoldierLogin::InternalOnChange(UGUIComponent* Sender)
{
	/*
	if (Sender == ch_RememberUser)
	{
		SaveSettings();
	}
	*/
}
