// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/UT2ServerInfo/UT2ServerInfo.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUITabControl/GUITabControl.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIBorder/GUITitleBar/GUITitleBar.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIBorder/GUIFooter/GUIFooter.h"

UUT2ServerInfo::UUT2ServerInfo()
{
	UGUITabControl* ServerInfoTabs = NewObject<UGUITabControl>(UGUITabControl::StaticClass());
	ServerInfoTabs->bFillSpace = true;
	ServerInfoTabs->bDockPanels = true;
	ServerInfoTabs->TabHeight = 0.045;
	ServerInfoTabs->WinTop = 0.083333;
	ServerInfoTabs->WinLeft = 0.0125;
	ServerInfoTabs->WinWidth = 0.974999;
	ServerInfoTabs->WinHeight = 0.06;
	ServerInfoTabs->bBoundToParent = true;
	ServerInfoTabs->bScaleToParent = true;
	ServerInfoTabs->bAcceptsInput = true;
	//ServerInfoTabs->OnActivate=ServerInfoTabs.InternalOnActivate;
	UGUIButton* ServerBackButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	ServerBackButton->Caption = "Close";
	ServerBackButton->Hint = "Close this menu";
	ServerBackButton->WinTop = 0.934167;
	ServerBackButton->WinLeft = 0.84875;
	ServerBackButton->WinWidth = 0.12;
	ServerBackButton->WinHeight = 0.055;
	ServerBackButton->bBoundToParent = true;
	ServerBackButton->bScaleToParent = true;
	//ServerBackButton->OnClick=UT2ServerInfo.ButtonClicked;
	//ServerBackButton->OnKeyEvent=ServerBackButton.InternalOnKeyEvent;
	UGUIImage* ServerInfoBackground = NewObject<UGUIImage>(UGUIImage::StaticClass());
	ServerInfoBackground->ImageStyle = EImgStyle::ISTY_Stretched;
	ServerInfoBackground->WinHeight = 1;
	ServerInfoBackground->bBoundToParent = true;
	ServerInfoBackground->bScaleToParent = true;
	ServerInfoBackground->bNeverFocus = true;
	UGUITitleBar* ServerInfoHeader = NewObject<UGUITitleBar>(UGUITitleBar::StaticClass());
	ServerInfoHeader->StyleName = "Header";
	ServerInfoHeader->WinHeight = 0.1;
	ServerInfoHeader->bBoundToParent = true;
	ServerInfoHeader->bScaleToParent = true;
	UGUIFooter* ServerInfoFooter = NewObject<UGUIFooter>(UGUIFooter::StaticClass());
	ServerInfoFooter->WinTop = 0.925;
	ServerInfoFooter->WinHeight = 0.075;
	PanelClass = { "XInterface.Tab_ServerMOTD","XInterface.Tab_ServerInfo", "XInterface.Tab_ServerMapList" };
	PanelCaption = { "MOTD","Rules","Maps" };
	PanelHint = { "Message of the Day","Game Rules","Map Rotation" };
	bRequire640x480 = false;
	bAllowedAsLast = true;
	Controls = {ServerInfoBackground, ServerInfoHeader, ServerInfoFooter, ServerBackButton, ServerInfoTabs};
	WinTop = 0.1;
	WinLeft = 0.2;
	WinWidth = 0.6;
	WinHeight = 0.8;
}

void UUT2ServerInfo::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	int32 i = 0;
	Super::InitComponent(MyController, MyOwner);
	if ((PlayerOwner() != None) && (PlayerOwner().GameReplicationInfo != None))
	{
		SetTitle();
	}
	TabC = GUITabControl(Controls[4]);
	TabC.MyFooter = GUIFooter(Controls[2]);
	i = 0;
	if (((i < PanelClass.Length) && (i < PanelCaption.Length)) && (i < PanelHint.Length))
	{
		TabC.AddTab(PanelCaption[i], PanelClass[i], , PanelHint[i]);
		i++;
	}
	if (!bOldStyleMenus)
	{
		Controls[3].Style = Controller.GetStyle("SquareButton", Controls[3].FontScale);
	}
	*/
}

bool UUT2ServerInfo::ButtonClicked(UGUIComponent* Sender)
{
	//Controller.CloseMenu(true);
	return true;
}

void UUT2ServerInfo::ChangeHint(FString NewHint)
{
	//GUITitleBar(Controls[2]).SetCaption(NewHint);
}

void UUT2ServerInfo::SetTitle()
{
	//GUITitleBar(Controls[1]).SetCaption(PlayerOwner().GameReplicationInfo.ServerName);
}

bool UUT2ServerInfo::NotifyLevelChange()
{
	bPersistent = false;
	return true;
}