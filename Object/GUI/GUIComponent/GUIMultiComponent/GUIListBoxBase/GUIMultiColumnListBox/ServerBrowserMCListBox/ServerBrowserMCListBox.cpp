// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIMultiColumnListBox/ServerBrowserMCListBox/ServerBrowserMCListBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiColumnListHeader/GUIMultiColumnListHeader.h"
#include "AA29/Object/GUI/GUIComponent/GUIContextMenu/GUIContextMenu.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIMultiColumnList/GUIMultiColumnList.h"

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

bool UServerBrowserMCListBox::InternalOnOpen(UGUIContextMenu* Menu)
{
	return HandleContextMenuOpen(List, Menu, Menu->MenuOwner);
}

bool UServerBrowserMCListBox::InternalOnClose(UGUIContextMenu* Sender)
{
	return HandleContextMenuClose(Sender);
}