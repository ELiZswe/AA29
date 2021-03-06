// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUIGridLayout/GUIGridLayout.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"

UGUIGridLayout::UGUIGridLayout()
{
	NumColumns = 1;
	ColumnSpacing = 0.01;
	RowSpacing = 0.01;
	bInitialPredraw = true;
}

UGUIComponent* UGUIGridLayout::CreateItem(FString NewClass, EeCellAlign A, int32 row, int32 col)
{
	UGUIComponent* NewComp = nullptr;
	/*
	NewComp = AddComponent(NewClass, true);
	addItem(NewComp, A, row, col);
	*/
	return NewComp;
}

void UGUIGridLayout::addItem(UGUIComponent* NewComp, EeCellAlign A, int32 row, int32 col)
{
	/*
	int32 i = 0;
	if (NewComp == nullptr)
	{
		Log("GUIGridLayout: Attempted to add non-existent component to grid");
		return;
	}
	AppendComponent(NewComp, true);
	NewComp.bBoundToParent = false;
	NewComp.bScaleToParent = false;
	if (row < 1 || col < 1)
	{
		i = Elements.Num();
		Elements.Num() = i + 1;
	}
	else
	{
		i = NumColumns * row - 1 + col - 1;
		if (i >= Elements.Num())
		{
			Elements.Num() = i + 1;
		}
		else
		{
			if (Elements[i].Component != nullptr)
			{
				RemoveComponent(Elements[i].Component, true);
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
	int32 i = 0;
	int32 Num = 0;
	int32 LastIndex = 0;
	int32 NumAfter = 0;
	/*
	if (Comp == nullptr)
	{
		Log("GUIGridLayout: Attempted to remove non-existent component from grid");
		return;
	}
	Num = -1;
	i = 0;
	if (i < Elements.Num())
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
		return;
	}
	if (RemoveComponent(Comp, True))
	{
		if (bAdjustTrailingItems)
		{
			Elements.RemoveAt(Num, 1);
			OriginalComponentWidths.RemoveAt(Num, 1);
		}
		else
		{
			Elements[Num].Component = nullptr;
			OriginalComponentWidths[Num] = 0;
		}
		for (i = 0; i < Elements.Num(); i++)
		{
			if (Elements[i].Component != nullptr)
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
			Elements.RemoveAt(LastIndex + 1, NumAfter);
			OriginalComponentWidths.RemoveAt(LastIndex + 1, NumAfter);
		}
	}
	*/
}

void UGUIGridLayout::AddColumnWidth(float Width)
{
	//ColumnWidths[ColumnWidths.Num()] = Width;
}
