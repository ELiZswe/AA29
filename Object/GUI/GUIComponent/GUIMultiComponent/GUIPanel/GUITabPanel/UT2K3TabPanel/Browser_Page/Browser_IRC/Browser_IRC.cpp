// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/Browser_Page/Browser_IRC/Browser_IRC.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUITabControl/GUITabControl.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUIPanel.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/IRC_Page/IRC_System/IRC_System.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUITabButton/GUITabButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/UT2K3GUIPage/IRC_NewNick/IRC_NewNick.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/IRC_Page/IRC_Channel/IRC_Channel.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/IRC_Page/IRC_Channel/IRC_Private/IRC_Private.h"

UBrowser_IRC::UBrowser_IRC()
{
	UGUIButton* MyBackButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	MyBackButton->Caption="BACK";
	MyBackButton->StyleName="SquareMenuButton";
	MyBackButton->WinWidth=0.2;
	MyBackButton->WinHeight=1;
	//MyBackButton->OnKeyEvent=MyBackButton.InternalOnKeyEvent;
	UGUIButton* MyLeaveButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	MyLeaveButton->StyleName="SquareMenuButton";
	MyLeaveButton->WinLeft=0.4;
	MyLeaveButton->WinWidth=0.2;
	MyLeaveButton->WinHeight=1;
	//MyLeaveButton->OnKeyEvent=MyLeaveButton.InternalOnKeyEvent;
	UGUIButton* MyChangeNickButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	MyChangeNickButton->Caption="CHANGE NICK";
	MyChangeNickButton->StyleName="SquareMenuButton";
	MyChangeNickButton->WinLeft=0.2;
	MyChangeNickButton->WinWidth=0.2;
	MyChangeNickButton->WinHeight=1;
	//MyChangeNickButton->OnKeyEvent=MyChangeNickButton.InternalOnKeyEvent;
	UGUITabControl* ChannelTabControl = NewObject<UGUITabControl>(UGUITabControl::StaticClass());
	ChannelTabControl->bDockPanels=true;
	ChannelTabControl->TabHeight=0.04;
	ChannelTabControl->WinHeight=48;
	ChannelTabControl->bAcceptsInput=true;
	//ChannelTabControl->OnActivate=ChannelTabControl.InternalOnActivate;
	UGUIPanel* FooterPanel = NewObject<UGUIPanel>(UGUIPanel::StaticClass());
	FooterPanel->Controls = {MyBackButton,MyLeaveButton,MyChangeNickButton};
	FooterPanel->WinTop=0.95;
	FooterPanel->WinHeight=0.05;
	
	SystemLabel = "System";
	LeaveChannelCaption = "LEAVE CHANNEL";
	LeavePrivateCaptionHead = "CLOSE ";
	ChooseNewNickText = "Choose A New Chat Nickname";
	Controls = { FooterPanel,ChannelTabControl };
}

void UBrowser_IRC::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	Super::InitComponent(MyController, MyOwner);
	if (!bIrcIsInitialised)
	{
		ChannelTabs = Cast<UGUITabControl>(Controls[1]);
		SystemPage = IRC_System(ChannelTabs.AddTab(SystemLabel, "xinterface.IRC_System", , , true));
		SystemPage.IRCPage = this;
		ChannelTabs.__OnChange__Delegate = TabChange;
		SystemPage.SetCurrentChannel(-1);
		BackButton = Cast<UGUIButton>(Cast<UGUIPanel>(Controls[0]).Controls[0]);
		BackButton.__OnClick__Delegate = BackClick;
		LeaveButton = Cast<UGUIButton>(Cast<UGUIPanel>(Controls[0]).Controls[1]);
		LeaveButton.bVisible = false;
		LeaveButton.__OnClick__Delegate = LeaveChannelClick;
		ChangeNickButton = Cast<UGUIButton>(Cast<UGUIPanel>(Controls[0]).Controls[2]);
		ChangeNickButton.__OnClick__Delegate = ChangeNickClick;
		bIrcIsInitialised = true;
	}
	*/
}

bool UBrowser_IRC::BackClick(UGUIComponent* Sender)
{
	//Controller.CloseMenu(true);
	return true;
}

bool UBrowser_IRC::ChangeNickClick(UGUIComponent* Sender)
{
	UIRC_NewNick* NewNickDialog = nullptr;
	/*
	if (SystemPage.Controller.OpenMenu("xinterface.IRC_NewNick"))
	{
		NewNickDialog = IRC_NewNick(SystemPage.Controller.TopPage());
		NewNickDialog.NewNickPrompt.Caption = ChooseNewNickText;
		NewNickDialog.SystemPage = SystemPage;
	}
	*/
	return true;
}

void UBrowser_IRC::TabChange(UGUIComponent* Sender)
{
	UGUITabButton* TabButton = nullptr;
	TabButton = Cast<UGUITabButton>(Sender);
	/*
	if (TabButton == nullptr)
	{
		return;
	}
	if (SystemPage == TabButton.MyPanel)
	{
		SystemPage.SetCurrentChannel(-1);
		LeaveButton.bVisible = false;
	}
	else
	{
		SystemPage.SetCurrentChannelPage(Cast<UIRC_Channel>(TabButton.MyPanel));
		if (Cast<UIRC_Private>(TabButton.MyPanel) != nullptr)
		{
			LeaveButton.Caption = LeavePrivateCaptionHead + Caps(TabButton.Caption) + LeavePrivateCaptionTail;
		}
		else
		{
			LeaveButton.Caption = LeaveChannelCaption;
		}
		LeaveButton.bVisible = true;
	}
	TabButton.bForceFlash = false;
	*/
}

bool UBrowser_IRC::LeaveChannelClick(UGUIComponent* Sender)
{
	/*
	SystemPage.PartCurrentChannel();
	*/
	return true;
}
