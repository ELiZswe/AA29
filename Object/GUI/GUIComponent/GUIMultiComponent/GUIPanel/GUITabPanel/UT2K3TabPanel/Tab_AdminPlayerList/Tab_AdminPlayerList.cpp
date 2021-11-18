// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/Tab_AdminPlayerList/Tab_AdminPlayerList.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIMultiColumnList/AdminPlayerList/AdminPlayerList.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIMultiColumnListBox/GUIMultiColumnListBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"

UTab_AdminPlayerList::UTab_AdminPlayerList()
{
	UAdminPlayerList* AdminList = NewObject<UAdminPlayerList>(UAdminPlayerList::StaticClass());
	//AdminList->OnPreDraw=AdminList.InternalOnPreDraw;
	//AdminList->OnClick=AdminList.InternalOnClick;
	//AdminList->OnRightClick=AdminList.InternalOnRightClick;
	//AdminList->OnMousePressed=AdminList.InternalOnMousePressed;
	//AdminList->OnMouseRelease=AdminList.InternalOnMouseRelease;
	//AdminList->OnKeyEvent=AdminList.InternalOnKeyEvent;
	//AdminList->OnBeginDrag=AdminList.InternalOnBeginDrag;
	//AdminList->OnEndDrag=AdminList.InternalOnEndDrag;
	//AdminList->OnDragDrop=AdminList.InternalOnDragDrop;
	//AdminList->OnDragEnter=AdminList.InternalOnDragEnter;
	//AdminList->OnDragLeave=AdminList.InternalOnDragLeave;
	//AdminList->OnDragOver=AdminList.InternalOnDragOver;
	UGUIButton* AdminPlayerBan = NewObject<UGUIButton>(UGUIButton::StaticClass());
	AdminPlayerBan->Caption="Ban";
	AdminPlayerBan->StyleName="SquareMenuButton";
	AdminPlayerBan->Hint="Ban this player";
	AdminPlayerBan->WinTop=0.9;
	AdminPlayerBan->WinLeft=0.86875;
	AdminPlayerBan->WinWidth=0.12;
	AdminPlayerBan->WinHeight=0.070625;
	//AdminPlayerBan->OnClick=Tab_AdminPlayerList.BanClicked;
	//AdminPlayerBan->OnKeyEvent=AdminPlayerBan.InternalOnKeyEvent;
	UGUIButton* AdminPlayerKick = NewObject<UGUIButton>(UGUIButton::StaticClass());
	AdminPlayerKick->Caption="Kick";
	AdminPlayerKick->StyleName="SquareMenuButton";
	AdminPlayerKick->Hint="Kick this Player";
	AdminPlayerKick->WinTop=0.9;
	AdminPlayerKick->WinLeft=0.74375;
	AdminPlayerKick->WinWidth=0.12;
	AdminPlayerKick->WinHeight=0.070625;
	//AdminPlayerKick->OnClick=Tab_AdminPlayerList.KickClicked;
	//AdminPlayerKick->OnKeyEvent=AdminPlayerKick.InternalOnKeyEvent;
	UGUIMultiColumnListBox* AdminPlayersListBox = NewObject<UGUIMultiColumnListBox>(UGUIMultiColumnListBox::StaticClass());
	AdminPlayersListBox->bVisibleWhenEmpty=true;
	AdminPlayersListBox->Controls = { AdminList };
	//AdminPlayersListBox->OnCreateComponent=AdminPlayersListBox.InternalOnCreateComponent;
	AdminPlayersListBox->StyleName="ServerBrowserGrid";
	AdminPlayersListBox->WinHeight=0.878127;
	UGUIImage* AdminBackground = NewObject<UGUIImage>(UGUIImage::StaticClass());
	//AdminBackground->Image=Texture'InterfaceContent.Menu.SquareBoxA';
	AdminBackground->ImageStyle = EImgStyle::ISTY_Stretched;
	AdminBackground->WinHeight=1;
	AdminBackground->bNeverFocus=true;

	Controls = { AdminBackground,AdminPlayersListBox,AdminPlayerKick,AdminPlayerBan };
	WinHeight = 0.625003;
}

void UTab_AdminPlayerList::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	Super::InitComponent(MyController, MyOwner);
	MyListBox = GUIMultiColumnListBox(Controls[1]);
	MyPlayerList = AdminPlayerList(MyListBox.Controls[0]);
	MyPlayerList.InitComponent(MyController, Self);
	WinWidth = Controller.ActivePage.WinWidth;
	WinLeft = Controller.ActivePage.WinLeft;
	*/
}

void UTab_AdminPlayerList::ProcessRule(FString NewRule)
{
}

void UTab_AdminPlayerList::ReloadList()
{
	//MyPlayerList.Clear();
}

bool UTab_AdminPlayerList::KickClicked(UGUIComponent* Sender)
{
	/*
	PlayerOwner().ConsoleCommand("Admin Kick" @ MyPlayerList.MyPlayers[MyPlayerList.Index].PlayerName);
	ReloadList();
	*/
	return true;
}

bool UTab_AdminPlayerList::BanClicked(UGUIComponent* Sender)
{
	/*
	if (bAdvancedAdmin)
	{
		PlayerOwner().ConsoleCommand("Admin Kick Ban" @ MyPlayerList.MyPlayers[MyPlayerList.Index].PlayerName);
	}
	else
	{
		PlayerOwner().ConsoleCommand("Admin KickBan" @ MyPlayerList.MyPlayers[MyPlayerList.Index].PlayerName);
	}
	ReloadList();
	*/
	return true;
}