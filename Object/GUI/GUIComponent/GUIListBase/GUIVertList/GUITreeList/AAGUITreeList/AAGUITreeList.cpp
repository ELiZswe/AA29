// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUITreeList/AAGUITreeList/AAGUITreeList.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"
#include "AA29/Object/GUI/GUIStyles/GUIStyles.h"
#include "Engine/Canvas.h"

UAAGUITreeList::UAAGUITreeList()
{
	//CollapsedIcon = Texture'T_AAO_UI.Menu.t_ui_treelist_category_collapsed';
	//ExpandedIcon = Texture'T_AAO_UI.Menu.t_ui_treelist_category_expanded';
	CategoryStyleName = "AAGUITreeListCategory";
	ItemStyleName = "AAGUITreeListItem";
	//__GetItemHeight__Delegate = "AAGUITreeList.MyGetItemHeight";
	//SelectedStyleName = "AAGUITreeListSelected";
	//__OnDrawItem__Delegate = "AAGUITreeList.MyOnDrawItem";
}

void UAAGUITreeList::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	InitComponent(MyController, MyOwner);
	if (CategoryStyleName != "" && CategoryStyle == nullptr)
	{
		CategoryStyle = MyController.GetStyle(CategoryStyleName, FontScale);
	}
	if (ItemStyleName != "" && ItemStyle == nullptr)
	{
		ItemStyle = MyController.GetStyle(ItemStyleName, FontScale);
	}
	*/
}

bool UAAGUITreeList::IsToggleClick(int32 idx)
{
	/*
	if (!IsValidIndex(idx))
	{
		return false;
	}
	if (!HasChildren(idx))
	{
		return false;
	}
	if (Controller.MouseX >= ClientBounds[0] && Controller.MouseX <= ClientBounds[2])
	{
		return true;
	}
	*/
	return false;
}

float UAAGUITreeList::MyGetItemHeight(UCanvas* C)
{
	float XL = 0;
	float YL = 0;
	/*
	Style.TextSize(C, MenuState, "WQ", XL, YL, FontScale);
	return YL * 1.5;
	*/
	return 0;     //FAKE   /ELiZ
}

void UAAGUITreeList::MyOnDrawItem(UCanvas* Canvas, int32 Item, float X, float Y, float W, float HT, bool bSelected, bool bPending)
{
	FString Text;
	UMaterialInstance* Icon = nullptr;
	UGUIStyles* MyItemStyle = nullptr;
	MyItemStyle = ItemStyle;
	/*
	if (HasChildren(Item))
	{
		if (IsExpanded(Item))
		{
			Icon = ExpandedIcon;
		}
		else
		{
			Icon = CollapsedIcon;
		}
		MyItemStyle = CategoryStyle;
	}
	else
	{
		if (Item == Index)
		{
			MyItemStyle = SelectedStyle;
		}
	}
	Text = GetCaptionAtIndex(Item);
	MyItemStyle.Draw(Canvas, MenuState, X, Y, W, HT);
	Y += HT / 6;
	MyItemStyle.DrawText(Canvas, MenuState, X, Y, W, HT, 1, Text, FontScale);
	if (None != Icon)
	{
		Canvas.SetPos(X + 4, Y);
		Canvas.Style = 6;
		Canvas.DrawTile(Icon, 16, 16, 0, 0, 16, 16);
	}
	*/
}
