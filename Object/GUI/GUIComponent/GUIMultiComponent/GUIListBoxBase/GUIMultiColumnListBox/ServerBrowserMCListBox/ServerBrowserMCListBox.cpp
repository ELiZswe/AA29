// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIMultiColumnListBox/ServerBrowserMCListBox/ServerBrowserMCListBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiColumnListHeader/GUIMultiColumnListHeader.h"

UServerBrowserMCListBox::UServerBrowserMCListBox()
{
	UGUIMultiColumnListHeader* MyHeader = NewObject<UGUIMultiColumnListHeader>(UGUIMultiColumnListHeader::StaticClass());
	MyHeader->FontScale = EFontScale::FNS_Small;
	MyHeader->StyleName = "ServerBrowserGridHeader";
	Header = MyHeader;
	bVisibleWhenEmpty = true;
	IniOption = "@Internal";
	StyleName = "ServerBrowserGrid";
}

void UServerBrowserMCListBox::InternalOnOpen(UGUIContextMenu* Menu)
{
	//Return HandleContextMenuOpen(List, Menu, Menu.MenuOwner);
}

void UServerBrowserMCListBox::InternalOnClose(UGUIContextMenu* Sender)
{
	//Return HandleContextMenuClose(Sender);
}