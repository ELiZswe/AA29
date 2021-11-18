// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUIGridLayout/GUIGridLayout.h"

UGUIGridLayout::UGUIGridLayout()
{
	NumColumns = 1;
	ColumnSpacing = 0.01;
	RowSpacing = 0.01;
	bInitialPredraw = true;
}

void UGUIGridLayout::CreateItem(FString NewClass, EeCellAlign A, int32 row, int32 col)
{
	/*
	local UGUIComponent* NewComp;
	NewComp = AddComponent(NewClass, True);
	addItem(NewComp, A, row, col);
	Return NewComp;
	*/
}

void UGUIGridLayout::addItem(UGUIComponent* NewComp, EeCellAlign A, int32 row, int32 col)
{
	/*
	local int32 i;
	if (NewComp == None)
	{
		Log("GUIGridLayout: Attempted to add non-existent component to grid");
		Return;
	}
	AppendComponent(NewComp, True);
	NewComp.bBoundToParent = False;
	NewComp.bScaleToParent = False;
	if (row < 1 || col < 1)
	{
		i = Elements.Length;
		Elements.Length = i + 1;
	}
	else
	{
		i = NumColumns * row - 1 + col - 1;
		if (i >= Elements.Length)
		{
			Elements.Length = i + 1;
		}
		else
		{
			if (Elements[i].Component != None)
			{
				RemoveComponent(Elements[i].Component, True);
			}
		}
	}
	Elements[i].Component = NewComp;
	Elements[i].Alignment = A;
	OriginalComponentWidths.insert(i, 1);
	OriginalComponentWidths[i] = NewComp.WinWidth;
	*/
}

void UGUIGridLayout::RemoveItem(UGUIComponent* Comp, bool bAdjustTrailingItems)
{
	/*
	local int32 i;
	local int32 Num;
	local int32 LastIndex;
	local int32 NumAfter;
	if (Comp == None)
	{
		Log("GUIGridLayout: Attempted to remove non-existent component from grid");
		Return;
	}
	Num = -1;
	i = 0;
	if (i < Elements.Length)
	{
		if (Elements[i].Component == Comp)
		{
			Num = i;
		}
		else
		{
			i++;
		}
	}
	if (Num < 0)
	{
		Return;
	}
	if (RemoveComponent(Comp, True))
	{
		if (bAdjustTrailingItems)
		{
			Elements.remove(Num, 1);
			OriginalComponentWidths.remove(Num, 1);
		}
		else
		{
			Elements[Num].Component = None;
			OriginalComponentWidths[Num] = 0;
		}
		for (i = 0; i < Elements.Length; i++)
		{
			if (Elements[i].Component != None)
			{
				LastIndex = i;
				NumAfter = 0;
			}
			else
			{
				NumAfter++;
			}
		}
		if (NumAfter > 0)
		{
			Elements.remove(LastIndex + 1, NumAfter);
			OriginalComponentWidths.remove(LastIndex + 1, NumAfter);
		}
	}
	*/
}

void UGUIGridLayout::AddColumnWidth(float Width)
{
	//ColumnWidths[ColumnWidths.Length] = Width;
}