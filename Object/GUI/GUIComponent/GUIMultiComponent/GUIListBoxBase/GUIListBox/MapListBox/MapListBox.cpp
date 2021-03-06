// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIListBox/MapListBox/MapListBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIContextMenu/GUIContextMenu.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIList/GUIList.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"

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
	Super::InitComponent(MyController, MyOwner);
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

bool UMapListBox::MyOpen(UGUIContextMenu* Menu)
{
	return HandleContextMenuOpen(List, Menu, Menu->MenuOwner);
}

bool UMapListBox::MyClose(UGUIContextMenu* Sender)
{
	return HandleContextMenuClose(Sender);
}
