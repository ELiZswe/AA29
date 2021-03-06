// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIMultiColumnList/GUIMultiColumnList.h"

UGUIMultiColumnList::UGUIMultiColumnList()
{
	CellSpacing = 1;
	//__OnPreDraw__Delegate = "GUIMultiColumnList.InternalOnPreDraw";
}

void UGUIMultiColumnList::OnColumnSized(int32 Column)
{
}

//native final Function GetListIndex(int32 YourArrayIndex);
void UGUIMultiColumnList::GetListIndex(int32 YourArrayIndex)
{
}

//native final Function ChangeSortOrder();
void UGUIMultiColumnList::ChangeSortOrder()
{
}

//native final Function SortList();
void UGUIMultiColumnList::SortList()
{
}

//native final Function UpdatedItem(int32 YourArrayIndex);
void UGUIMultiColumnList::UpdatedItem(int32 YourArrayIndex)
{
}

//native final Function RemovedItem(int32 YourArrayIndex);
void UGUIMultiColumnList::RemovedItem(int32 YourArrayIndex)
{
}

//native final Function AddedItem(optional int YourArrayIndex);
void UGUIMultiColumnList::AddedItem(int32 YourArrayIndex)
{
}

void UGUIMultiColumnList::GetSortString(int32 YourArrayIndex)
{
}

int32 UGUIMultiColumnList::CurrentListId()
{
	/*
	if (Index < 0)
	{
		return - 1;
	}
	return SortData[Index].SortItem;
	*/
	return 0;
}

void UGUIMultiColumnList::OnSortChanged()
{
	/*
	if (SortData.Num() <= 0)
	{
		return;
	}
	ChangeSortOrder();
	SortList();
	if (IsValid())
	{
		Index = InvSortData[Index];
	}
	*/
}

void UGUIMultiColumnList::Clear()
{
	/*
	SortData.RemoveAt(0, SortData.Num());
	InvSortData.RemoveAt(0, InvSortData.Num());
	*/
	Super::Clear();
}

void UGUIMultiColumnList::RemovedCurrent()
{
	/*
	if (IsValid())
	{
		RemovedItem(CurrentListId());
		SetIndex(Index);
	}
	*/
}

void UGUIMultiColumnList::ResolutionChanged(int32 ResX, int32 ResY)
{
	/*
	if (!bInit)
	{
		bInit = true;
	}
	Super::ResolutionChanged(ResX, ResY);
	*/
}

void UGUIMultiColumnList::InitializeColumns(UCanvas* C)
{
	int32 i = 0;
	float AW = 0;
	/*
	if (bDebugging)
	{
		Log(Name @ "#### InitializeColumns ActualWidth() = " @ ActualWidth() @ "WinWidth:" + WinWidth);
	}
	AW = ActualWidth();
	for (i = 0; i < InitColumnPerc.Num(); i++)
	{
		if (bDebugging)
		{
			Log(Name @ "#### InitColumnPerc[" + i + "]:" + InitColumnPerc[i]);
		}
		ColumnWidths[i] = AW * InitColumnPerc[i];
	}
	*/
	bInit = false;
}

bool UGUIMultiColumnList::InternalOnPreDraw(UCanvas* C)
{
	float X = 0;
	int32 i = 0;
	if (bInit)
	{
		return false;
	}
	/*
	if (NeedsSorting)
	{
		SortList();
		if (IsValid())
		{
			Index = InvSortData[Index];
		}
	}
	if (ExpandLastColumn)
	{
		i = 0;
		if (i < ColumnWidths.Num() - 1)
		{
			X += ColumnWidths[i];
			i++;
		}
		ColumnWidths[i] = ActualWidth() - X;
	}
	*/
	return false;
}

void UGUIMultiColumnList::GetCellLeftWidth(int32 Column, float &Left, float &Width)
{
	int32 i = 0;
	/*
	Left = ClientBounds[0];
	i = 0;
	if (i < Column && i < ColumnWidths.Num())
	{
		Left += ColumnWidths[i];
		i++;
	}
	if (i < ColumnWidths.Num())
	{
		Width = ColumnWidths[i];
	}
	else
	{
		Width = 0;
	}
	Left += CellSpacing;
	Width -= 2 * CellSpacing;
	if (Left >= Bounds[2])
	{
		Width = 0;
	}
	if (Left + Width >= Bounds[2])
	{
		Width = Bounds[2] - Left;
	}
	if (Width < 0)
	{
		Width = 0;
	}
	*/
}

void UGUIMultiColumnList::Sort()
{
	SortList();
}

void UGUIMultiColumnList::Dump()
{
	int32 i = 0;
	/*
	Log("Dumping multicolumn list contents  '" + Name + "'");
	for (i = 0; i < SortData.Num(); i++)
	{
		if (i < InvSortData.Num())
		{
			Log(" " + i + ")" @ "'" + SortData[i].SortString + "'" @ SortData[i].SortItem @ "InvSortData:" + InvSortData[i]);
		}
		else
		{
			Log(" " + i + ")" @ "'" + SortData[i].SortString + "'" @ SortData[i].SortItem @ "InvSortData: Invalid");
		}
	}
	*/
}
