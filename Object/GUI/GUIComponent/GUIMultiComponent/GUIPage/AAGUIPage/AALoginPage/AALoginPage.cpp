// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/AALoginPage/AALoginPage.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/BackgroundImage/BackgroundImage.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIBorder/GUIBorder.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"

UAALoginPage::UAALoginPage()
{
	
	UGUIButton* QuitButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	QuitButton->Caption="EXIT";
	QuitButton->FontScale = EFontScale::FNS_Small;
	QuitButton->Hint="Exit America's Army.";
	QuitButton->WinTop=0.8;
	QuitButton->WinLeft=0.6775;
	QuitButton->WinWidth=0.125;
	QuitButton->WinHeight=0.036;
	QuitButton->TabOrder=5;
	//QuitButton->OnClick=AALoginPage.ButtonClick;
	//QuitButton->OnKeyEvent=QuitButton.InternalOnKeyEvent;
	UBackgroundImage* PageBackground = NewObject<UBackgroundImage>(UBackgroundImage::StaticClass());
	//PageBackground->Image=Texture'T_AAO_UI.GUI.t_ui_gui_background';
	PageBackground->ImageColor=FColor(255, 255, 255, 32);
	PageBackground->ImageStyle = EImgStyle::ISTY_Scaled;
	UGUIBorder* PageHeader = NewObject<UGUIBorder>(UGUIBorder::StaticClass());
	PageHeader->WinTop=0.1;
	PageHeader->WinLeft=0.1;
	PageHeader->WinWidth=0.8;
	PageHeader->WinHeight=0.05;
	PageHeader->RenderWeight=0.1;
	PageHeader->bBoundToParent=true;
	PageHeader->bScaleToParent=true;
	UGUIImage* PageBG = NewObject<UGUIImage>(UGUIImage::StaticClass());
	//PageBG->Image=Texture'T_AAO_UI.GUI.t_ui_gui_background_fill';
	PageBG->ImageStyle = EImgStyle::ISTY_Stretched;
	PageBG->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	PageBG->WinTop=0.16;
	PageBG->WinLeft=0.1;
	PageBG->WinWidth=0.8;
	PageBG->WinHeight=0.74;
	PageBG->bBoundToParent=true;
	PageBG->bScaleToParent=true;
	UGUILabel* VersionLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	VersionLabel->Caption="Game Client v%major%.%minor%.%tiny%";
	VersionLabel->TextAlign = ETextAlign::TXTA_Right;
	VersionLabel->TextColor=FColor(204, 255, 255, 255);
	VersionLabel->TextFont="AAFontSmall";
	VersionLabel->VertAlign = ETextAlign::TXTA_Center;
	VersionLabel->WinTop=0.17;
	VersionLabel->WinLeft=0.63;
	VersionLabel->WinWidth=0.25;
	VersionLabel->WinHeight=0.05;
	VersionLabel->bScaleToParent=true;
	
	i_Background = PageBackground;
	h_PageHeader = PageHeader;
	i_PageBackground = PageBG;
	b_Quit = QuitButton;
	l_Version = VersionLabel;
	LoginSuccessMsg = "Login Success!";
	LoginFailureMsg = "Login Error.";
	PageCaption = "Welcome to America's Army";
	GreenColor = FColor(156, 201, 168, 255);
	RedColor = FColor(50, 30, 150, 255);
	GoldColor = FColor(52, 180, 217, 255);
	BlueColor = FColor(159, 82, 82, 255);
	bPersistent = true;
	//OnOpen = AALoginPage.InternalOnOpen;
	//OnReOpen = AALoginPage.Reopened;
	//OnCanClose = AALoginPage.CanClose;
	WinHeight = 1;
	bDebugging = true;
	WhiteColor = FColor(229, 248, 251, 255);
	//OnKeyEvent = AALoginPage.internalKeyEvent;
}

void UAALoginPage::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	FString sSubTinyVersion = "";
	Super::InitComponent(MyController, MyOwner);
	l_Version.Caption = Repl(l_Version.Caption, "%major%", string(GetVersionAGPMajor()));
	l_Version.Caption = Repl(l_Version.Caption, "%minor%", string(GetVersionAGPMinor()));
	sSubTinyVersion = string(GetVersionAGPTiny());
	if (GetVersionAGPSubTiny() > 0)
	{
		sSubTinyVersion = sSubTinyVersion $ ".";
		if (GetVersionAGPSubTiny() < 10)
		{
			sSubTinyVersion = sSubTinyVersion $ "0";
		}
		sSubTinyVersion = sSubTinyVersion $ string(GetVersionAGPSubTiny());
	}
	l_Version.Caption = Repl(l_Version.Caption, "%tiny%", sSubTinyVersion);
	h_PageHeader.SetCaption(PageCaption);
	*/
}

void UAALoginPage::Reopened()
{
	/*
	if (!PlayerOwner().Level.IsPendingConnection())
	{
		Opened(None);
	}
	*/
}

void UAALoginPage::Opened(UGUIComponent* Sender)
{
	/*
	if (bDebugging)
	{
		Log(string(Name) $ ".Opened()   Sender:" $ string(Sender), 'Debug');
	}
	Super::Opened(Sender);
	selected = nullptr;
	*/
}

void UAALoginPage::InternalOnOpen()
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

void UAALoginPage::OnClose(bool bCancelled)
{
}

bool UAALoginPage::internalKeyEvent(uint8& Key, uint8& State, float Delta)
{
	/*
	if ((Key == 27) && (State == 1))
	{
		bAllowClose = true;
	}
	*/
	return false;
}

bool UAALoginPage::CanClose(bool bCancelled)
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

bool UAALoginPage::ButtonClick(UGUIComponent* Sender)
{
	/*
	if ((GUIButton(Sender) != None) || (GUIImageButton(Sender) != None))
	{
		selected = Sender;
	}
	if (selected == nullptr)
	{
		return false;
	}
	switch (selected)
	{
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

bool UAALoginPage::NotifyLevelChange()
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
