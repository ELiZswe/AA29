// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIContextMenu/GUIContextMenu.h"

UGUIContextMenu::UGUIContextMenu()
{
	SelectionStyleName = "ListSelection";
	FontScale = EFontScale::FNS_Small;
	StyleName = "ContextMenu";
	bRequiresStyle = true;
}

void UGUIContextMenu::OnOpen(UGUIContextMenu* Sender)
{
}
void UGUIContextMenu::OnClose(UGUIContextMenu* Sender)
{
}
void UGUIContextMenu::OnSelect(UGUIContextMenu* Sender, int32 ClickIndex)
{
}
void UGUIContextMenu::OnContextHitTest(float MouseX, float MouseY)
{
}
void UGUIContextMenu::addItem(FString NewItem)
{
	/*
	local int Index;
	Index = ContextItems.Length;
	ContextItems[Index] = NewItem;
	Return Index;
	*/
}
void UGUIContextMenu::InsertItem(FString NewItem, int32 Index)
{
	/*
	if (Index >= ContextItems.Length)
	{
		Return addItem(NewItem);
	}
	if (Index < 0)
	{
		Return - 1;
	}
	ContextItems.insert(Index, 1);
	ContextItems[Index] = NewItem;
	Return Index;
	*/
}
void UGUIContextMenu::RemoveItemByName(FString ItemName)
{
	/*
	local int Index;
	for (Index = 0; Index < ContextItems.Length; Index++)
	{
		if (ContextItems[Index] ~= ItemName)
		{
			ContextItems.remove(Index, 1);
			Return True;
		}
	}
	Return False;
	*/
}
void UGUIContextMenu::RemoveItemByIndex(int32 Index)
{
	/*
	if (Index >= 0 && Index < ContextItems.Length)
	{
		ContextItems.remove(Index, 1);
		Return True;
	}
	Return False;
	*/
}
void UGUIContextMenu::ReplaceItem(int32 Index, FString NewItem)
{
	/*
	if (RemoveItemByIndex(Index))
	{
		Return InsertItem(NewItem, Index) > 0;
	}
	Return False;
	*/
}
