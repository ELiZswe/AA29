// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIMultiColumnListBox/AAWeaponClass_WaitingListBox/AAWeaponClass_WaitingListBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiColumnListHeader/GUIMultiColumnListHeader.h"

UAAWeaponClass_WaitingListBox::UAAWeaponClass_WaitingListBox()
{
	UGUIMultiColumnListHeader* MyHeader = NewObject<UGUIMultiColumnListHeader>(UGUIMultiColumnListHeader::StaticClass());
	MyHeader->StyleName = "ScoreboardHeader";
	MyHeader->bAcceptsInput = false;
	Header = MyHeader;
	//DefaultListClass = "AGP_Interface.AAWeaponClass_WaitingList";
	StyleName = "AAUnitBox";
}