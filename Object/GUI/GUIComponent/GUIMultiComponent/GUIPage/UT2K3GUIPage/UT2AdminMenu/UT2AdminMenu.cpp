// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/UT2K3GUIPage/UT2AdminMenu/UT2AdminMenu.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUITabControl/GUITabControl.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIBorder/GUITitleBar/GUITitleBar.h"

UUT2AdminMenu::UUT2AdminMenu()
{
	UGUITabControl* AdminInfoTabs = NewObject<UGUITabControl>(UGUITabControl::StaticClass());
	AdminInfoTabs->bDockPanels = true;
	AdminInfoTabs->TabHeight = 0.04;
	AdminInfoTabs->WinTop = 0.1;
	AdminInfoTabs->WinHeight = 0.06;
	AdminInfoTabs->bBoundToParent = true;
	AdminInfoTabs->bScaleToParent = true;
	AdminInfoTabs->bAcceptsInput = true;
	//AdminInfoTabs->OnActivate=AdminInfoTabs.InternalOnActivate;
	UGUIButton* AdminBackButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	AdminBackButton->Caption = "Close";
	AdminBackButton->StyleName = "SquareMenuButton";
	AdminBackButton->Hint = "Close this menu";
	AdminBackButton->WinTop = 0.934167;
	AdminBackButton->WinLeft = 0.86875;
	AdminBackButton->WinWidth = 0.12;
	AdminBackButton->WinHeight = 0.055;
	AdminBackButton->bBoundToParent = true;
	AdminBackButton->bScaleToParent = true;
	//AdminBackButton->OnClick=UT2AdminMenu.ButtonClicked;
	//AdminBackButton->OnKeyEvent=AdminBackButton.InternalOnKeyEvent;
	UGUIImage* AdminInfoBackground = NewObject<UGUIImage>(UGUIImage::StaticClass());
	AdminInfoBackground->ImageStyle = EImgStyle::ISTY_Stretched;
	AdminInfoBackground->WinHeight = 1;
	AdminInfoBackground->bBoundToParent = true;
	AdminInfoBackground->bScaleToParent = true;
	AdminInfoBackground->bNeverFocus = true;
	UGUIImage* AdminInfoBackground2 = NewObject<UGUIImage>(UGUIImage::StaticClass());
	AdminInfoBackground2->ImageStyle = EImgStyle::ISTY_Stretched;
	AdminInfoBackground2->WinHeight = 1;
	AdminInfoBackground2->bBoundToParent = true;
	AdminInfoBackground2->bScaleToParent = true;
	AdminInfoBackground2->bNeverFocus = true;
	UGUITitleBar* AdminInfoHeader = NewObject<UGUITitleBar>(UGUITitleBar::StaticClass());
	AdminInfoHeader->Caption = "Admin In-Game Menu";
	AdminInfoHeader->StyleName = "Header";
	AdminInfoHeader->WinHeight = 0.1;
	AdminInfoHeader->bBoundToParent = true;
	AdminInfoHeader->bScaleToParent = true;
	UGUITitleBar* AdminInfoFooter = NewObject<UGUITitleBar>(UGUITitleBar::StaticClass());
	AdminInfoFooter->bUseTextHeight = false;
	AdminInfoFooter->StyleName = "Footer";
	AdminInfoFooter->WinTop = 0.925;
	AdminInfoFooter->WinHeight = 0.075;
	AdminInfoFooter->bBoundToParent = true;
	AdminInfoFooter->bScaleToParent = true;
	bRequire640x480 = false;
	bAllowedAsLast = true;
	Controls = { AdminInfoBackground,AdminInfoBackground2,AdminInfoHeader,AdminInfoFooter,AdminBackButton,AdminInfoTabs };
	WinTop = 0.1;
	WinLeft = 0.02;
	WinWidth = 0.96;
	WinHeight = 0.8;
}

void UUT2AdminMenu::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	Super::InitComponent(MyController, MyOwner);
	TabC = GUITabControl(Controls[5]);
	PlayerList = Tab_AdminPlayerList(TabC.AddTab("Players", "xinterface.Tab_AdminPlayerList", , "Player Mgt.", true));
	if (PlayerList != None)
	{
		PlayerList.ReloadList();
	}
	*/
}

void UUT2AdminMenu::HandleParameters(FString Param1, FString Param2)
{
	//PlayerList.bAdvancedAdmin = bool(Param1);
}

bool UUT2AdminMenu::ButtonClicked(UGUIComponent* Sender)
{
	//Controller.CloseMenu(true);
	return true;
}