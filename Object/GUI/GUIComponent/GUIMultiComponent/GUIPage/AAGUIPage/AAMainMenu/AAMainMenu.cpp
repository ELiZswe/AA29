// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/AAMainMenu/AAMainMenu.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUITabControl/GUIVertTabControl/GUIVertTabControl.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImageButton/GUIImageButton.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"
#include "AA29/Object/Actor/Info/InternetInfo/InternetLink/UdpLink/UdpBeacon/ClientBeaconReceiver/ClientBeaconReceiver.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainPanel/AAMainPanel.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUITabButton/GUITabButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/GUITabPanel.h"
#include "AA29/Object/Actor/HUD/AGP_HUD/AGP_HUD.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"

UAAMainMenu::UAAMainMenu()
{
	PanelHints.SetNum(9);
	PanelCaptions.SetNum(9);
	PanelClasses.SetNum(9);
	UGUIVertTabControl* MyTabC = NewObject<UGUIVertTabControl>(UGUIVertTabControl::StaticClass());
	MyTabC->TabWidth=0.22;
	MyTabC->TabSpacing=0.01;
	MyTabC->ButtonStyleName="VertTabButton";
	MyTabC->TabHeight=0.05;
	MyTabC->WinTop=0.22;
	MyTabC->WinLeft=0.005;
	MyTabC->WinWidth=0.22;
	MyTabC->WinHeight=0.5;
	MyTabC->TabOrder=0;
	//MyTabC->OnActivate=MyTabC.InternalOnActivate;
	UGUIButton* MyQuitButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	MyQuitButton->Caption="SIGNOUT";
	MyQuitButton->StyleName="VertTabButton";
	MyQuitButton->Hint="Sign on with a different account, or exit the game.";
	MyQuitButton->WinTop=0.76;
	MyQuitButton->WinLeft=0.005;
	MyQuitButton->WinWidth=0.22;
	MyQuitButton->WinHeight=0.05;
	MyQuitButton->TabOrder=1;
	//MyQuitButton->OnClick=AAMainMenu.ButtonClick;
	//MyQuitButton->OnKeyEvent=MyQuitButton.InternalOnKeyEvent;
	UGUIImageButton* AALogoImageButton = NewObject<UGUIImageButton>(UGUIImageButton::StaticClass());
	AALogoImageButton->Caption="http://www.americasarmy.com/";
	AALogoImageButton->link="http://www.americasarmy.com/redir.php?r=0";
	//AALogoImageButton->Image=Texture'T_AAO_UI.Logo.t_ui_logo_aa';
	AALogoImageButton->ImageStyle = EImgStyle::ISTY_Justified;
	AALogoImageButton->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	AALogoImageButton->ImageAlign = EImgAlign::IMGA_Center;
	AALogoImageButton->WinTop=0.0475;
	AALogoImageButton->WinLeft=0.0275;
	AALogoImageButton->WinWidth=0.175;
	AALogoImageButton->WinHeight=0.125;
	AALogoImageButton->TabOrder=2;
	//AALogoImageButton->OnClick=AAMainMenu.ButtonClick;
	//AALogoImageButton->OnKeyEvent=AALogoImageButton.InternalOnKeyEvent;
	UGUIImageButton* USArmyImageButton = NewObject<UGUIImageButton>(UGUIImageButton::StaticClass());
	USArmyImageButton->Caption="http://www.goarmy.com/";
	USArmyImageButton->link="http://www.americasarmy.com/redir.php?r=2";
	//USArmyImageButton->Image=Texture'T_AAO_UI.Logo.t_ui_logo_goarmy';
	USArmyImageButton->ImageStyle = EImgStyle::ISTY_Justified;
	USArmyImageButton->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	USArmyImageButton->ImageAlign = EImgAlign::IMGA_Center;
	USArmyImageButton->WinTop=0.8575;
	USArmyImageButton->WinLeft=0.04;
	USArmyImageButton->WinWidth=0.15;
	USArmyImageButton->WinHeight=0.1;
	USArmyImageButton->TabOrder=3;
	//USArmyImageButton->OnClick=AAMainMenu.ButtonClick;
	//USArmyImageButton->OnKeyEvent=USArmyImageButton.InternalOnKeyEvent;
	UGUIImage* MyBackground = NewObject<UGUIImage>(UGUIImage::StaticClass());
	//MyBackground->Image=Texture'T_AAO_UI.GUI.t_ui_gui_background';
	MyBackground->ImageStyle = EImgStyle::ISTY_Scaled;
	MyBackground->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	MyBackground->WinHeight=1;
	MyBackground->RenderWeight=0;
	UGUIImage* MyTabBackground = NewObject<UGUIImage>(UGUIImage::StaticClass());
	//MyTabBackground->Image=Texture'T_AA2_UI.Menu.Side';
	MyTabBackground->ImageStyle = EImgStyle::ISTY_Stretched;
	MyTabBackground->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	MyTabBackground->WinWidth=0.22;
	MyTabBackground->WinHeight=1;
	MyTabBackground->RenderWeight=0;
	MyTabBackground->bVisible=false;
	UGUILabel* VersionLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	VersionLabel->TextAlign = ETextAlign::TXTA_Right;
	VersionLabel->TextColor=FColor(204, 255, 255, 255);
	VersionLabel->FontScale = EeFontScale::FNS_Small;
	VersionLabel->StyleName="LightTextLabel";
	VersionLabel->WinTop=0.955;
	VersionLabel->WinLeft=0.74;
	VersionLabel->WinWidth=0.25;
	VersionLabel->WinHeight=0.053476;
	VersionLabel->RenderWeight=0.5;
	VersionLabel->bNeverFocus=true;
	
	i_Background = MyBackground;
	i_TabBackground = MyTabBackground;
	c_Tab = MyTabC;
	b_Quit = MyQuitButton;
	ib_AALogo = AALogoImageButton;
	ib_USArmyLogo = USArmyImageButton;
	l_Version = VersionLabel;

	PanelClasses = { "AGP_Interface.AARecordBriefPanel","AGP_Interface.AATrainingPanel","AGP_Interface.AADeploymentPanel","AGP_Interface.AARealHeroesPanel","AGP_Interface.AAExplorePanel","AGP_Interface.AABrowserPanel","AGP_Interface.AASettingsPanel","AGP_Interface.AASupportPanel","AGP_Interface.AACreditsPanel" };
	PanelCaptions = { "RECORD BRIEF","TRAINING","DEPLOYMENT","REAL HEROES","INSTANT ACTION","AA BROWSER","SETTINGS","SUPPORT","CREDITS" };
	PanelHints = { "Create and maintain soldier information.","Finish basic and other training missions.","Find Internet and LAN games.","Visit the Real Heroes and learn about their stories.","Instant Action - play online now!","Find Internet and LAN games.","Configure your video, audio and other settings.","Support information and links.","View credits." };
	bPersistent = true;
	bAllowedAsLast = true;
	//OnCanClose = AAMainMenu.InternalOnCanClose;
	WinHeight = 1;
	//OnKeyEvent = AAMainMenu.InternalOnKeyEvent;
}

void UAAMainMenu::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	UGUITabPanel* MyPanel = nullptr;
	int32 i = 0;
	FString sSubTinyVersion = "";
	Super::InitComponent(MyController, MyOwner);
	/*
	for (i = 0; i < 9; i++)
	{
		MyPanel = c_Tab.AddTab(PanelCaptions[i], PanelClasses[i], , PanelHints[i]);
	}
	sSubTinyVersion = FString::FromInt(GetVersionAGPTiny());
	if (GetVersionAGPSubTiny() > 0)
	{
		sSubTinyVersion = sSubTinyVersion + ".";
		if (GetVersionAGPSubTiny() < 10)
		{
			sSubTinyVersion = sSubTinyVersion + "0";
		}
		sSubTinyVersion = sSubTinyVersion + FString::FromInt(GetVersionAGPSubTiny());
	}
	l_Version.Caption = "Game Client v" + FString::FromInt(GetVersionAGPMajor()) + "." + FString::FromInt(GetVersionAGPMinor()) + "." + sSubTinyVersion;
	*/
}

void UAAMainMenu::Opened(UGUIComponent* Sender)
{
	if (bDebugging)
	{
		//Log(string(Name) + ".Opened()   Sender:" + FString::FromInt(Sender), 'Debug');
	}
	Super::Opened(Sender);
}

void UAAMainMenu::HandleParameters(FString Param1, FString Param2)
{
	int32 i = 0;
	UGUITabButton* TabButton = nullptr;
	UAAMainPanel* MainPanel = nullptr;
	Super::HandleParameters(Param1, Param2);
	c_Tab->ActivateTabByName(Param1, true);
	/*
	if (Param2 != "")
	{
		i = c_Tab.TabIndex(Param1);
		if ((i >= 0) && (i < c_Tab.TabStack.Num()))
		{
			TabButton = c_Tab.TabStack[i];
			if (TabButton != nullptr)
			{
				MainPanel = AAMainPanel(TabButton.MyPanel);
				if (MainPanel != nullptr)
				{
					MainPanel.c_Tabs.ActivateTabByName(Param2, true);
				}
			}
		}
	}
	*/
}

void UAAMainMenu::OnClose(bool bCanceled)
{
	FRotator newRot = FRotator(0, 0, 0);
	AClientBeaconReceiver* ClientBeacon = nullptr;
	if (PlayerOwner() != nullptr)
	{
		ClientBeacon = Cast<AAGP_HUD>(Cast<AHumanController>(PlayerOwner())->MyHUD)->ClientBeacon;
		ClientBeacon->StopBeacon();
	}
	//newRot = PlayerOwner()->GetActorRotation();
	newRot.Pitch = int(SavedPitch);
	//PlayerOwner().SetRotation(newRot);
}

bool UAAMainMenu::InternalOnKeyEvent(uint8& Key, uint8& State, float Delta)
{
	if ((Key == 27) && (State == 1))
	{
		bAllowClose = true;
	}
	return false;
}

bool UAAMainMenu::InternalOnCanClose(bool bCanceled)
{
	FString L = "";
	if (bAllowClose)
	{
		/*
		L = PlayerOwner().Level.GetLevelName();
		if ((L ~= "entry") || (L ~= "entry2"))
		{
			Controller.OpenMenu("AGP_Interface.AALogoutPage");
		}
		else
		{
			return true;
		}
		*/
	}
	bAllowClose = false;
	//return PlayerOwner().Level.IsPendingConnection();
	return false;    //FAKE   /ELiZ
}

bool UAAMainMenu::ButtonClick(UGUIComponent* Sender)
{
	if (Sender == b_Quit)
	{
		Controller->OpenMenu("AGP_Interface.AALogoutPage","","");
	}
	else
	{
		if (Sender == ib_AALogo)
		{
			Controller->OpenMenu("AGP_Interface.AAExternalLinkPage", ib_AALogo->Caption, ib_AALogo->link);
		}
		else
		{
			if (Sender == ib_USArmyLogo)
			{
				Controller->OpenMenu("AGP_Interface.AAExternalLinkPage", ib_USArmyLogo->Caption, ib_USArmyLogo->link);
			}
		}
	}
	return true;
}

bool UAAMainMenu::NotifyLevelChange()
{
	if (bDebugging)
	{
		//Log(string(Name) @ "NotifyLevelChange  PendingConnection:" + FString::FromInt(PlayerOwner().Level.IsPendingConnection()));
	}
	//return PlayerOwner().Level.IsPendingConnection();
	return false;    //FAKE   /ELiZ
}
