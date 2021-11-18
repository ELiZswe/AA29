// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/AALoginPage/AAPostLoginPage/AAPostLoginPage.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIContentBox/GUIContentBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"

UAAPostLoginPage::UAAPostLoginPage()
{
	
	UGUIButton* DownloadsButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	DownloadsButton->Caption="DOWNLOADS";
	DownloadsButton->FontScale = EFontScale::FNS_Small;
	DownloadsButton->Hint="Download new content for America's Army.";
	DownloadsButton->WinTop=0.8;
	DownloadsButton->WinLeft=0.1975;
	DownloadsButton->WinWidth=0.126;
	DownloadsButton->WinHeight=0.035;
	DownloadsButton->TabOrder=2;
	//DownloadsButton->OnClick=AAPostLoginPage.ButtonClick;
	//DownloadsButton->OnKeyEvent=DownloadsButton.InternalOnKeyEvent;
	UGUIButton* ServerBrowserButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	ServerBrowserButton->Caption="AA BROWSER";
	ServerBrowserButton->FontScale = EFontScale::FNS_Small;
	ServerBrowserButton->Hint="Go to the America's Army server browser.";
	ServerBrowserButton->WinTop=0.8;
	ServerBrowserButton->WinLeft=0.3575;
	ServerBrowserButton->WinWidth=0.126;
	ServerBrowserButton->WinHeight=0.035;
	ServerBrowserButton->TabOrder=3;
	//ServerBrowserButton->OnClick=AAPostLoginPage.ButtonClick;
	//ServerBrowserButton->OnKeyEvent=ServerBrowserButton.InternalOnKeyEvent;
	UGUIButton* MainMenuButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	MainMenuButton->Caption="MAIN MENU";
	MainMenuButton->FontScale = EFontScale::FNS_Small;
	MainMenuButton->Hint="Go to the America's Army main menu.";
	MainMenuButton->WinTop=0.8;
	MainMenuButton->WinLeft=0.5175;
	MainMenuButton->WinWidth=0.126;
	MainMenuButton->WinHeight=0.035;
	MainMenuButton->TabOrder=4;
	//MainMenuButton->OnClick=AAPostLoginPage.ButtonClick;
	//MainMenuButton->OnKeyEvent=MainMenuButton.InternalOnKeyEvent;
	UGUIContentBox* MyPanel = NewObject<UGUIContentBox>(UGUIContentBox::StaticClass());
	MyPanel->ItemSpacing=0.02;
	MyPanel->bScaleItemsToWidth=true;
	MyPanel->WinTop=0.18;
	MyPanel->WinLeft=0.1;
	MyPanel->WinWidth=0.8;
	MyPanel->WinHeight=0.6;
	MyPanel->RenderWeight=0.6;
	MyPanel->bBoundToParent=true;
	MyPanel->bScaleToParent=true;
	UGUIImage* NMLStatusIcon = NewObject<UGUIImage>(UGUIImage::StaticClass());
	NMLStatusIcon->ImageStyle = EImgStyle::ISTY_Scaled;
	NMLStatusIcon->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	NMLStatusIcon->WinTop=0.9075;
	NMLStatusIcon->WinLeft=0.1;
	NMLStatusIcon->WinWidth=0.025;
	NMLStatusIcon->WinHeight=0.025;
	NMLStatusIcon->RenderWeight=0.5;
	NMLStatusIcon->bVisible=false;
	UGUILabel* NMLStatusText = NewObject<UGUILabel>(UGUILabel::StaticClass());
	NMLStatusText->TextColor=FColor(204, 255, 255, 255);
	NMLStatusText->FontScale = EFontScale::FNS_Small;
	NMLStatusText->StyleName="LightTextLabel";
	NMLStatusText->WinTop=0.895;
	NMLStatusText->WinLeft=0.135;
	NMLStatusText->WinWidth=0.4;
	NMLStatusText->WinHeight=0.053476;
	NMLStatusText->RenderWeight=0.5;
	NMLStatusText->bNeverFocus=true;
	
	b_Downloads = DownloadsButton;
	b_ServerBrowser = ServerBrowserButton;
	b_MainMenu = MainMenuButton;
	guicbPanel = MyPanel;
	i_NMLStatusIcon = NMLStatusIcon;
	l_NMLStatusText = NMLStatusText;
	asInstantActionPlayerMessage = { "You can unlock more combat roles by completing Basic Combat Training.  Select the 'Training' menu option to get started.","You can play on even more maps if you complete Basic Combat Training.  Select the 'Training' menu option to get started.","Want to improve your game?  Click on the 'Training' menu option and complete Basic Combat Training.","Complete Basic Combat Training and take a shot at getting your name in the 'Shoot House' record books!  Click on the 'Training' menu option and complete Basic Combat Training.","Want to play a Special Forces soldier role?  Complete Basic Combat Training and then complete SF Training  to get all the cool SF gear!","Ready to raise your honor level beyond 20?  Complete Basic Combat Training and all of the additional experience you have gained will be instantly applied towards additional honor levels!","Want to take advanced marksmanship training and gain access to the M-24 and M-82?  Complete Basic Combat Training and all of the Advanced Infantry Training will become available!","Want to learn to the medic role and even learn first aid technniques that may apply in your life?  Complete Basic Combat Training and all of the Medic Training will become available!" };
	asInstantActionWelcomeMessage = { "Welcome to America's Army Special Forces: OverMatch!||You can get started either by completing basic training or jumping on any of the thousands of America's Army game servers available!  Once you get to the Main Menu just click on 'Instant Action' to start playing right away or click on 'Training' to learn more about playing America's Army!||Don't forget to customize your settings to get the best experience possible using the 'Settings' option." };
	//OnPreDraw = AAPostLoginPage.InternalOnPreDraw;

}



void UAAPostLoginPage::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	local NMLContent MyNML;
	Super::InitComponent(MyController, MyOwner);
	MyNML = new (None) class'AGP_Interface.NMLContent';
	if (MyNML != None)
	{
		if (MyNML.Controller == None)
		{
			MyNML.InitComponent(MyController, MyOwner);
		}
		MyNML.ParseNMLFromServer("/x_login_post.nml", "dms1.americasarmy.com", 80, guicbPanel, i_NMLStatusIcon, l_NMLStatusText);
	}
	*/
}

bool UAAPostLoginPage::InternalOnPreDraw(UCanvas* C)
{
	/*
	if (((HumanController(PlayerOwner()) != None) && (HumanController(PlayerOwner()).iCompleted[1] != 15)) && (!bOneTimeDisplay))
	{
		bOneTimeDisplay = true;
		if (HumanController(PlayerOwner()).PlayerReplicationInfo.GetExperience() != 5000)
		{
			Controller.OpenMenu("AGP_Interface.AAGenericMessageBox", "Do More By Completing Basic Combat Training", asInstantActionPlayerMessage[Rand(asInstantActionPlayerMessage.Length)]);
		}
		else
		{
			Controller.OpenMenu("AGP_Interface.AAGenericMessageBox", "Welcome To America's Army!", asInstantActionWelcomeMessage[Rand(asInstantActionWelcomeMessage.Length)]);
		}
	}
	*/
	return false;
}

void UAAPostLoginPage::Opened(UGUIComponent* Sender)
{
	/*
	local AARecordBrief_PlayerStats SubPanel;
	HumanController HC = nullptr;
	local DBAuth.DCDS initDCDS;
	ForEach AllObjects(class'AGP_Interface.AARecordBrief_PlayerStats', SubPanel)
	{
		SubPanel.UpdateHeaderWithUserName();
		SubPanel.RequestRecordBrief();
		GOTO JL0031;
	JL0031:
	}
	ForEach AllObjects(Class'DBAuth.DCDS', initDCDS)
	{
		GOTO JL0045;
	JL0045:
	}
	if (initDCDS != None)
	{
		HC = HumanController(PlayerOwner());
		if (HC != None)
		{
			initDCDS.DownloadFileManifest(HC.UserName, HC.UserPassword);
		}
	}
	Super::Opened(Sender);
	*/
}

void UAAPostLoginPage::SetNonExploreTheArmyMode()
{
}

bool UAAPostLoginPage::ButtonClick(UGUIComponent* Sender)
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
	case b_Downloads:
		Profile("Downloads");
		Controller.OpenMenu("AGP_Interface.AAExternalLinkPage", "http://www.americasarmy.com/", "http://www.americasarmy.com/downloads/");
		Profile("Downloads");
		bOneTimeDisplay = false;
		return true;
	case b_ServerBrowser:
		Profile("ServerBrowser");
		class'AGP_Interface.AADeploy_Internet'.SetExploreTheArmyMode(false);
		Controller.ReplaceMenu("AGP_Interface.AAMainMenu", "AA BROWSER");
		Profile("ServerBrowser");
		bOneTimeDisplay = false;
		return true;
	case b_MainMenu:
		Profile("MainMenu");
		class'AGP_Interface.AADeploy_Internet'.SetExploreTheArmyMode(false);
		Controller.ReplaceMenu("AGP_Interface.AAMainMenu");
		Profile("MainMenu");
		bOneTimeDisplay = false;
		return true;
	case b_Quit:
		Profile("Quit");
		Controller.OpenMenu("AGP_Interface.AALogoutPage");
		Profile("Quit");
		return true;
	default:
		StopWatch(true);
		return true;
	}
	*/
	return false;    //FAKE   /ELiZ
}
