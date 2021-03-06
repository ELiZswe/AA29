// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIContextMenu/GUIContextMenu.h"
#include "AA29/Object/GUI/GUIStyles/GUIStyles.h"

UGUIContextMenu::UGUIContextMenu()
{
	SelectionStyleName = "ListSelection";
	FontScale = EeFontScale::FNS_Small;
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

int32 UGUIContextMenu::addItem(FString NewItem)
{
	int32 Index = 0;
	Index = ContextItems.Num();
	ContextItems[Index] = NewItem;
	return Index;
}

int32 UGUIContextMenu::InsertItem(FString NewItem, int32 Index)
{
	if (Index >= ContextItems.Num())
	{
		return addItem(NewItem);
	}
	if (Index < 0)
	{
		return - 1;
	}
	//ContextItems.insert(Index, 1);
	ContextItems[Index] = NewItem;
	return Index;
}

bool UGUIContextMenu::RemoveItemByName(FString ItemName)
{
	int32 Index = 0;
	for (Index = 0; Index < ContextItems.Num(); Index++)
	{
		if (ContextItems[Index].Compare(ItemName,ESearchCase::IgnoreCase))
		{
			ContextItems.RemoveAt(Index, 1);
			return true;
		}
	}
	return false;
}

bool UGUIContextMenu::RemoveItemByIndex(int32 Index)
{
	if (Index >= 0 && Index < ContextItems.Num())
	{
		ContextItems.RemoveAt(Index, 1);
		return true;
	}
	return false;
}

bool UGUIContextMenu::ReplaceItem(int32 Index, FString NewItem)
{
	if (RemoveItemByIndex(Index))
	{
		return InsertItem(NewItem, Index) > 0;
	}
	return false;
}
