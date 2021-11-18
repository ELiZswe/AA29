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

//native final Function GetListIndex(int YourArrayIndex);
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

//native final Function UpdatedItem(int YourArrayIndex);
void UGUIMultiColumnList::UpdatedItem(int32 YourArrayIndex)
{
}

//native final Function RemovedItem(int YourArrayIndex);
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
		Return - 1;
	}
	Return SortData[Index].SortItem;
	*/
	return 0;
}

int32 UGUIMultiColumnList::OnSortChanged()
{
	/*
	if (SortData.Length <= 0)
	{
		Return;
	}
	ChangeSortOrder();
	SortList();
	if (IsValid())
	{
		Index = InvSortData[Index];
	}
	*/
	return -1;    //FAKE   /ELiZ
}

void UGUIMultiColumnList::Clear()
{
	/*
	SortData.remove(0, SortData.Length);
	InvSortData.remove(0, InvSortData.Length);
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
		bInit = True;
	}
	Super::ResolutionChanged(ResX, ResY);
	*/
}

void UGUIMultiColumnList::InitializeColumns(UCanvas* C)
{
	/*
	local int i;
	local float AW;
	if (bDebugging)
	{
		Log(Name @ "#### InitializeColumns ActualWidth() = " @ ActualWidth() @ "WinWidth:" $ WinWidth);
	}
	AW = ActualWidth();
	for (i = 0; i < InitColumnPerc.Length; i++)
	{
		if (bDebugging)
		{
			Log(Name @ "#### InitColumnPerc[" $ i $ "]:" $ InitColumnPerc[i]);
		}
		ColumnWidths[i] = AW * InitColumnPerc[i];
	}
	*/
	bInit = false;
}

bool UGUIMultiColumnList::InternalOnPreDraw(UCanvas* C)
{
	/*
	local float X;
	local int i;
	if (bInit)
	{
		Return False;
	}
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
		if (i < ColumnWidths.Length - 1)
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
	/*
	local int i;
	Left = ClientBounds[0];
	i = 0;
	if (i < Column && i < ColumnWidths.Length)
	{
		Left += ColumnWidths[i];
		i++;
	}
	if (i < ColumnWidths.Length)
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

void UGUIMultiColumnList::UGUIMultiColumnList::Sort()
{
	SortList();
}

void UGUIMultiColumnList::UGUIMultiColumnList::Dump()
{
	/*
	local int i;
	Log("Dumping multicolumn list contents  '" $ Name $ "'");
	for (i = 0; i < SortData.Length; i++)
	{
		if (i < InvSortData.Length)
		{
			Log(" " $ i $ ")" @ "'" $ SortData[i].SortString $ "'" @ SortData[i].SortItem @ "InvSortData:" $ InvSortData[i]);
		}
		else
		{
			Log(" " $ i $ ")" @ "'" $ SortData[i].SortString $ "'" @ SortData[i].SortItem @ "InvSortData: Invalid");
		}
	}
	*/
}