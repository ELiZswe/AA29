// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIListBox/MapListBox/MapListBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIContextMenu/GUIContextMenu.h"

UMapListBox::UMapListBox()
{
	UGUIContextMenu* RCMenu = NewObject<UGUIContextMenu>(UGUIContextMenu::StaticClass());
	RCMenu->ContextItems = { "Play This Map","Spectate This Map","-","Add To Maplist","Remove From Maplist","Filter Maplist" };
	RCMenu->StyleName = "ServerListContextMenu";
	ContextMenu = RCMenu;
}

void UMapListBox::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	InitComponent(MyController, MyOwner);
	ContextMenu.__OnOpen__Delegate = MyOpen;
	ContextMenu.__OnClose__Delegate = MyClose;
	ContextMenu.__OnSelect__Delegate = ContextClick;
	*/
}

void UMapListBox::ContextClick(UGUIContextMenu* Sender, int32 Index)
{
	//NotifyContextSelect(Sender, Index);
}

bool UMapListBox::MyRealOpen(UGUIComponent* aMenuOwner)
{
	return false;
}

void UMapListBox::MyOpen(UGUIContextMenu* Menu)
{
	//Return HandleContextMenuOpen(List, Menu, Menu.MenuOwner);
}

void UMapListBox::MyClose(UGUIContextMenu* Sender)
{
	//Return HandleContextMenuClose(Sender);
}
