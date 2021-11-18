// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUITreeList/GUITreeList.h"

UGUITreeList::UGUITreeList()
{
	bAllowDuplicateCaption = true;
	bGroupItems = true;
}

//native final Function UpdateVisibleCount();
void UGUITreeList::UpdateVisibleCount()
{
}

//native final Function SortList();
void UGUITreeList::SortList()
{
}

void UGUITreeList::CompareItem(FGUITreeNode ElemA, FGUITreeNode ElemB)
{
	//Return StrCmp(ElemA.Caption, ElemB.Caption);
}

int32 UGUITreeList::addItem(FString Caption, FString Value, FString ParentCaption, bool bEnabled, FString ExtraInfo)
{
	int32 idx=0;
	int32 i=0;
	/*
	if (!bAllowEmptyItems && Caption == "" && ParentCaption == "")
	{
		return -1;
	}
	if (!bAllowDuplicateCaption && FindIndex(Caption) != -1)
	{
		return -1;
	}
	if (ParentCaption == "")
	{
		idx = HardInsert(Elements.Length, Caption, Value, "", 0, True, ExtraInfo);
	}
	else
	{
		if (bGroupItems)
		{
			i = FindIndex(ParentCaption, True);
			if (i == -1)
			{
				i = FindIndex(ParentCaption);
			}
			if (i == -1)
			{
				i = HardInsert(Elements.Length, ParentCaption, "", "", 0, True);
			}
		}
		else
		{
			if (ParentCaption != "")
			{
				i = HardInsert(Elements.Length, ParentCaption, Value, "", 0, True, ExtraInfo);
			}
		}
		idx = HardInsert(i + 1, Caption, Value, ParentCaption, Elements[i].Level + 1, bEnabled, ExtraInfo);
	}
	if (Elements.Length == 1 && bInitializeList)
	{
		SetIndex(0);
	}
	else
	{
		if (bNotify)
		{
			CheckLinkedObjects(Self);
		}
	}
	UpdateVisibleCount();
	if (MyScrollBar != None)
	{
		MyScrollBar.AlignThumb();
	}
	*/
	return idx;
}

void UGUITreeList::AddElement(FGUITreeNode Node)
{
	//Return addItem(Node.Caption, Node.Value, Node.ParentCaption, Node.bEnabled, Node.ExtraInfo);
}

void UGUITreeList::Replace(int32 i, FString NewItem, FString NewValue, FString ParentCaption, bool bNoSort, FString ExtraInfo)
{
	/*
	if (!IsValidIndex(i))
	{
		addItem(NewItem, NewValue, ParentCaption);
	}
	else
	{
		if (!bAllowEmptyItems && NewItem == "" && NewValue == "" && ParentCaption == "")
		{
			Return;
		}
		Elements[i].Caption = NewItem;
		Elements[i].Value = NewValue;
		Elements[i].ExtraInfo = ExtraInfo;
		if (bSorted && !bNoSort)
		{
			Sort();
		}
		SetIndex(Index);
	}
	*/
}

void UGUITreeList::InsertItem(int32 idx, FString Caption, FString Value, FString ParentCaption, int32 Level, bool bEnabled, FString ExtraInfo)
{
	/*
	local int32 ParentIndex;
	local int32 ChildIndex;
	if (!IsValidIndex(idx))
	{
		Return addItem(Caption, Value, ParentCaption, bEnabled, ExtraInfo);
	}
	if (bGroupItems)
	{
		ParentIndex = FindParentIndex(idx);
		if (IsValidIndex(ParentIndex) && Elements[ParentIndex].Caption == ParentCaption)
		{
			ChildIndex = FindAvailableChildIndex(ParentIndex);
			if (idx > ParentIndex && idx <= ChildIndex)
			{
				Return HardInsert(idx, Caption, Value, ParentCaption, Elements[ParentIndex].Level + 1, bEnabled, ExtraInfo);
			}
			else
			{
				Return HardInsert(ChildIndex, Caption, Value, ParentCaption, Elements[ParentIndex].Level + 1, bEnabled, ExtraInfo);
			}
		}
		else
		{
			if (ParentCaption == "")
			{
				idx = FindNextAvailableRootIndex(idx);
				Return HardInsert(idx, Caption, Value, ParentCaption, Level, True, ExtraInfo);
			}
		}
	}
	else
	{
		ParentIndex = FindNextAvailableRootIndex(idx);
		if (ParentCaption != "")
		{
			idx = HardInsert(idx, ParentCaption, Value, "", Level++, True, ExtraInfo);
		}
		Return HardInsert(idx + 1, Caption, Value, ParentCaption, Level, True, ExtraInfo);
	}
	Return addItem(Caption, Value, ParentCaption, bEnabled);
	*/
}

int32 UGUITreeList::HardInsert(int32 idx, FString Caption, FString Value, FString ParentCaption, int32 Level, bool bEnabled, FString ExtraInfo)
{
	/*
	Elements.insert(idx, 1);
	Elements[idx].Caption = Caption;
	Elements[idx].Value = Value;
	Elements[idx].ParentCaption = ParentCaption;
	Elements[idx].ExtraInfo = ExtraInfo;
	Elements[idx].Level = Level;
	Elements[idx].bEnabled = bEnabled;
	ItemCount = Elements.Length;
	*/
	return idx;
}

void UGUITreeList::LoadFrom(UGUITreeList* Source, bool bClearFirst)
{
	/*
	local int32 i;
	local int32 Level;
	local byte bEnabled;
	local FString Caption;
	local FString Value;
	local FString ParentCaption;
	local FString ExtraInfo;
	if (bClearFirst)
	{
		Clear();
	}
	for (i = 0; i < Source.ItemCount; i++)
	{
		if (Source.ValidSelectionAt(i))
		{
			Source.GetAtIndex(i, Caption, Value, ParentCaption, Level, bEnabled, ExtraInfo);
			addItem(Caption, Value, ParentCaption, bEnabled, ExtraInfo);
		}
	}
	*/
}

int32 UGUITreeList::RemoveSilent(FString Caption)
{
	int32 i=0;
	/*
	bNotify = False;
	i = RemoveItem(Caption);
	bNotify = True;
	*/
	return i;
}

int32 UGUITreeList::RemoveItem(FString Caption)
{
	int32 i=0;
	/*
	i = FindIndex(Caption, True);
	if (i == -1)
	{
		i = FindIndex(Caption);
	}
	*/
	return RemoveItemAt(i,false,false);

}

int32 UGUITreeList::RemoveItemAt(int32 idx, bool bNoSort, bool bSkipCleanup)
{
	/*
	local int32 Level;
	local int32 ParentIndex;
	if (IsValidIndex(idx))
	{
		Level = Elements[idx].Level + 1;
		ParentIndex = FindParentIndex(idx);
		Elements.remove(idx, 1);
		ItemCount--;
		if (idx < ItemCount && Elements[idx].Level == Level)
		{
			if (RemoveItemAt(idx, True, True) == -2)
			{
			}
		}
		if (!bAllowParentSelection && !bSkipCleanup && IsValidIndex(ParentIndex) && !HasChildren(ParentIndex))
		{
			RemoveItemAt(ParentIndex, True);
		}
		UpdateVisibleCount();
		if (bSorted && !bNoSort)
		{
			Sort();
		}
		SetIndex(Index);
		if (MyScrollBar != None)
		{
			MyScrollBar.AlignThumb();
		}
		Return Index;
	}
	*/
	return -2;
}

int32 UGUITreeList::RemoveElement(FGUITreeNode Node, int32 Count, bool bNoSort)
{
	/*
	local int32 i;
	Count = Max(Count, 1);
	for (i = 0; i < Elements.Length; i++)
	{
		if (Elements[i] == Node)
		{
			Return RemoveItemAt(i, bNoSort);
		}
	}
	*/
	return -1;
}

void UGUITreeList::Clear()
{
	/*
	if (Elements.Length == 0)
	{
		Return;
	}
	Elements.remove(0, Elements.Length);
	ItemCount = 0;
	UpdateVisibleCount();
	Super::Clear();
	*/
}

bool UGUITreeList::Swap(int32 IndexA, int32 IndexB)
{
	/*
	local int32 ParentIndexA;
	local int32 ParentIndexB;
	ParentIndexA = FindParentIndex(IndexA);
	ParentIndexB = FindParentIndex(IndexB);
	if (bGroupItems)
	{
		if (IsValidIndex(ParentIndexA))
		{
			if (IsValidIndex(ParentIndexB))
			{
				if (ParentIndexA != ParentIndexB)
				{
					return false;
				}
			}
			else
			{
				return false;
			}
		}
		else
		{
			if (IsValidIndex(ParentIndexB))
			{
				return false;
			}
		}
	}
	if (IsValidIndex(IndexA) && IsValidIndex(IndexB))
	{
		if (!bGroupItems)
		{
			if (IndexA > IndexB)
			{
				if (Elements[IndexA].Level > 0)
				{
					IndexA = ParentIndexA;
				}
				if (Elements[IndexB].Level > 0)
				{
					IndexB = ParentIndexB;
				}
				if (IndexA == IndexB)
				{
					IndexA = FindNextAvailableRootIndex(IndexB - 1);
					if (!IsValidIndex(IndexA))
					{
						return false;
					}
				}
			}
			else
			{
				if (Elements[IndexA].Level > 0)
				{
					IndexA = ParentIndexA;
				}
				if (Elements[IndexB].Level > 0)
				{
					IndexB = ParentIndexB;
				}
				if (IndexA == IndexB)
				{
					IndexB = FindAvailableChildIndex(IndexA);
				}
				if (!IsValidIndex(IndexB))
				{
					return false;
				}
			}
		}
		HardSwap(IndexA, IndexB);
		return true;
	}
	*/
	return false;
}

void UGUITreeList::HardSwap(int32 IndexA, int32 IndexB)
{
	/*
	local array<int> chIdxA;
	local array<int> chIdxB;
	local int32 i;
	local array<GUITreeNode> NodesA;
	local array<GUITreeNode> NodesB;
	NodesA[NodesA.Length] = Elements[IndexA];
	NodesB[NodesB.Length] = Elements[IndexB];
	if (HasChildren(IndexA))
	{
		chIdxA = GetChildIndexList(IndexA);
		for (i = 0; i < chIdxA.Length; i++)
		{
			NodesA[NodesA.Length] = Elements[chIdxA[i]];
		}
	}
	if (HasChildren(IndexB))
	{
		chIdxB = GetChildIndexList(IndexB);
		for (i = 0; i < chIdxB.Length; i++)
		{
			NodesB[NodesB.Length] = Elements[chIdxB[i]];
		}
	}
	if (IndexA > IndexB)
	{
		Elements.remove(IndexA, NodesA.Length);
		Elements.insert(IndexA, NodesB.Length);
		for (i = 0; i < NodesB.Length; i++)
		{
			Elements[IndexA + i] = NodesB[i];
		}
		Elements.remove(IndexB, NodesB.Length);
		Elements.insert(IndexB, NodesA.Length);
		for (i = 0; i < NodesB.Length; i++)
		{
			Elements[IndexB + i] = NodesA[i];
		}
	}
	else
	{
		Elements.remove(IndexB, NodesB.Length);
		Elements.insert(IndexB, NodesA.Length);
		for (i = 0; i < NodesA.Length; i++)
		{
			Elements[IndexB + i] = NodesA[i];
		}
		Elements.remove(IndexA, NodesA.Length);
		Elements.insert(IndexA, NodesB.Length);
		for (i = 0; i < NodesB.Length; i++)
		{
			Elements[IndexA + i] = NodesB[i];
		}
	}
	if (bNotify)
	{
		CheckLinkedObjects(Self);
	}
	if (bSorted)
	{
		Sort();
	}
	*/
}

void UGUITreeList::GetCaption()
{
	//Return GetCaptionAtIndex(Index);
}

void UGUITreeList::GetParentCaption()
{
	//Return GetParentCaptionAtIndex(Index);
}

void UGUITreeList::GetValue()
{
	//Return GetValueAtIndex(Index);
}

void UGUITreeList::GetLevel()
{
	//Return GetLevelAtIndex(Index);
}

void UGUITreeList::GetExtra()
{
	//Return GetExtraAtIndex(Index);
}

void UGUITreeList::GetCaptionAtIndex(int32 i)
{
	/*
	if (!IsValidIndex(i))
	{
		Return "";
	}
	Return Elements[i].Caption;
	*/
}

void UGUITreeList::GetParentCaptionAtIndex(int32 idx)
{
	/*
	if (!IsValidIndex(idx))
	{
		Return "";
	}
	if (Elements[idx].ParentCaption == "")
	{
		Return Elements[idx].Caption;
	}
	Return Elements[idx].ParentCaption;
	*/
}

void UGUITreeList::GetValueAtIndex(int32 i)
{
	/*
	if (!IsValidIndex(i))
	{
		Return "";
	}
	Return Elements[i].Value;
	*/
}

void UGUITreeList::GetLevelAtIndex(int32 i)
{
	/*
	if (!IsValidIndex(i))
	{
		return -1;
	}
	Return Elements[i].Level;
	*/
}

void UGUITreeList::GetExtraAtIndex(int32 idx)
{
	/*
	if (!IsValidIndex(idx))
	{
		Return "";
	}
	Return Elements[idx].ExtraInfo;
	*/
}

bool UGUITreeList::GetElementAtIndex(int32 i, FGUITreeNode &Node)
{
	/*
	if (!IsValidIndex(i))
	{
		return false;
	}
	Node = Elements[i];
	*/
	return true;
}

bool UGUITreeList::GetAtIndex(int32 i, FString &Caption, FString &Value, FString &ParentCaption, int32 &Level, uint8 &bEnabled, FString &ExtraInfo)
{
	/*
	if (!IsValidIndex(i))
	{
		return false;
	}
	Caption = Elements[i].Caption;
	Value = Elements[i].Value;
	Level = Elements[i].Level;
	ParentCaption = Elements[i].ParentCaption;
	bEnabled = Elements[i].bEnabled;
	ExtraInfo = Elements[i].ExtraInfo;
	*/
	return true;
}

TArray<int32> UGUITreeList::GetIndexList()
{
	TArray<int32> Indexes = { };
	/*
	local int32 i;
	for (i = 0; i < ItemCount; i++)
	{
		if (ValidSelectionAt(i))
		{
			Indexes[Indexes.Length] = i;
		}
	}
	*/
	return Indexes;
}

TArray<int32> UGUITreeList::GetChildIndexList(int32 idx, bool bNoRecurse)
{
	TArray<int32> Indexes = { };
	/*
	local int32 Level;
	if (IsValidIndex(idx))
	{
		Level = Elements[idx].Level + 1;
		if (++idx < ItemCount)
		{
			if (Elements[idx].Level < Level)
			{
			}
			if (bNoRecurse && Elements[idx].Level > Level)
			{
			}
			Indexes[Indexes.Length] = idx;
		}
	}
	*/
	return Indexes;
}

bool UGUITreeList::ValidSelection()
{
	return ValidSelectionAt(Index);
}

bool UGUITreeList::ValidSelectionAt(int32 idx)
{
	if (!IsValidIndex(idx))
	{
		return false;
	}
	return bAllowParentSelection || !HasChildren(idx);
}

bool UGUITreeList::HasChildren(int32 ParentIndex)
{
	/*
	if (!IsValidIndex(ParentIndex))
	{
		return false;
	}
	if (ParentIndex < ItemCount - 1)
	{
		Return Elements[ParentIndex + 1].Level > Elements[ParentIndex].Level;
	}
	*/
	return false;
}

bool UGUITreeList::IsExpanded(int32 ParentIndex)
{
	/*
	if (!HasChildren(ParentIndex))
	{
		return true;
	}
	Return Elements[ParentIndex + 1].bEnabled;
	*/
	return true;    //FAKE    /ELiZ
}

void UGUITreeList::SetCaptionAtIndex(int32 i, FString NewCaption)
{
	/*
	if (!IsValidIndex(i))
	{
		Return;
	}
	Elements[i].Caption = NewCaption;
	*/
}

void UGUITreeList::SetValueAtIndex(int32 i, FString NewValue)
{
	/*
	if (!IsValidIndex(i))
	{
		Return;
	}
	Elements[i].Value = NewValue;
	*/
}

void UGUITreeList::SetLevelAtIndex(int32 i, int32 NewLevel)
{
	/*
	if (!IsValidIndex(i))
	{
		Return;
	}
	Elements[i].Level = NewLevel;
	*/
}

bool UGUITreeList::Expand(int32 idx, bool bRecursive)
{
	/*
	local int32 i;
	local array<int> Indexes;
	if (!IsValidIndex(idx))
	{
		return false;
	}
	Expand(FindParentIndex(idx));
	Indexes = GetChildIndexList(idx, !bRecursive);
	for (i = 0; i < Indexes.Length; i++)
	{
		Elements[Indexes[i]].bEnabled = True;
	}
	*/
	return true;
}

bool UGUITreeList::Collapse(int32 idx)
{
	/*
	local int32 i;
	local array<int> Indexes;
	if (!IsValidIndex(idx))
	{
		return false;
	}
	Indexes = GetChildIndexList(idx);
	for (i = 0; i < Indexes.Length; i++)
	{
		Elements[Indexes[i]].bEnabled = False;
	}
	*/
	return true;
}

void UGUITreeList::ToggleExpand(int32 idx, bool bRecursive)
{
	/*
	if (!IsValidIndex(idx))
	{
		Return;
	}
	if (IsExpanded(idx))
	{
		Collapse(idx);
	}
	else
	{
		Expand(idx, bRecursive);
	}
	*/
}

bool UGUITreeList::IsToggleClick(int32 idx)
{
	/*
	local float PrefixOffset;
	local float CaptionOffset;
	if (!IsValidIndex(idx))
	{
		return false;
	}
	if (!HasChildren(idx))
	{
		return false;
	}
	PrefixOffset = ClientBounds[0] + SelectedPrefixWidth * GetLevelAtIndex(idx);
	CaptionOffset = PrefixOffset + SelectedPrefixWidth;
	if (Controller.MouseX >= PrefixOffset && Controller.MouseX <= CaptionOffset)
	{
		return true;
	}
	*/
	return false;
}

bool UGUITreeList::InternalOnClick(UGUIComponent* Sender)
{
	bool bResult=false;
	/*
	bResult = InternalOnClick(Sender);
	if (bResult && IsToggleClick(Index))
	{
		ToggleExpand(Index);
	}
	*/
	return bResult;
}

bool UGUITreeList::InternalDblClick(UGUIComponent* Sender)
{
	//ToggleExpand(Index);
	return true;
}

int32 UGUITreeList::FindIndex(FString Caption, bool bExact)
{
	/*
	local int32 i;
	for (i = 0; i < Elements.Length; i++)
	{
		if (bExact&& Elements[i].Caption == Caption || !bExact && Elements[i].Caption ~= Caption)
		{
			Return i;
		}
	}
	*/
	return -1;
}

int32 UGUITreeList::FindFullIndex(FString Caption, FString Value, FString ParentCaption)
{
	/*
	local int32 i;
	for (i = 0; i < Elements.Length; i++)
	{
		if (Elements[i].Caption == Caption && Elements[i].Value == Value && Elements[i].ParentCaption == ParentCaption)
		{
			Return i;
		}
	}
	*/
	return -1;
}

int32 UGUITreeList::FindParentIndex(int32 ChildIndex)
{
	/*
	local int32 Level;
	if (!IsValidIndex(ChildIndex))
	{
		return -1;
	}
	if (Elements[ChildIndex].Level == 0)
	{
		return -1;
	}
	Level = Elements[ChildIndex].Level - 1;
JL004B:
	if (--ChildIndex >= 0 && Elements[ChildIndex].Level > Level)
	{
		GOTO JL004B;
	}
	*/
	return ChildIndex;
}

int32 UGUITreeList::FindNextAvailableRootIndex(int32 Target)
{
	/*
	if (!IsValidIndex(Target))
	{
		Return Elements.Length;
	}
	if (Elements[Target].Level == 0)
	{
		Return Target;
	JL0033:
	}
	if (--Target > 0 && Elements[Target].Level > 0)
	{
		GOTO JL0033;
	}
	*/
	return Target;
}

int32 UGUITreeList::FindAvailableChildIndex(int32 ParentIndex)
{
	/*
	local int32 ParentLevel;
	if (IsValidIndex(ParentIndex))
	{
		ParentLevel = Elements[ParentIndex].Level + 1;
		if (++ParentIndex < ItemCount && Elements[ParentIndex].Level >= ParentLevel)
		{
		}
		Return ParentIndex;
	}
	*/
	return -1;
}

int32 UGUITreeList::FindIndexByValue(FString Value, bool bExact)
{
	/*
	local int32 i;
	for (i = 0; i < Elements.Length; i++)
	{
		if (bExact&& Elements[i].Value == Value || !bExact && Elements[i].Value ~= Value)
		{
			Return i;
		}
	}
	*/
	return -1;
}

int32 UGUITreeList::FindElement(FString Caption, FString Value, int32 Level, bool bCaseSensitive)
{
	/*
	local int32 i;
	if (bCaseSensitive)
	{
		for (i = 0; i < Elements.Length; i++)
		{
			if (Elements[i].Caption == Caption && Elements[i].Value == Value && Elements[i].Level == Level)
			{
				Return i;
			}
			else
			{
				for (i = 0; i < Elements.Length; i++)
				{
					if (Elements[i].Caption ~= Caption && Elements[i].Value ~= Value && Elements[i].Level == Level)
					{
						Return i;
					}
				}
			}
		}
	}
	*/
	return -1;
}

int32 UGUITreeList::FindVisibleIndex(int32 idx, int32 Distance)
{
	int32 Count=0;
	int32 i=0;
	int32 increment=0;
	/*
	if (Distance == 0)
	{
		Return idx;
	}
	else
	{
		if (Distance < 0)
		{
			increment = -1;
		}
		else
		{
			increment = 1;
		}
	}
	i = idx;
	if (IsValidIndex(i))
	{
		if (Elements[i].bEnabled)
		{
			Count++;
		}
		if (Count >= Abs(Distance))
		{
		}
		i += increment;
	}
	*/
	return i;
}

int32 UGUITreeList::CalculateIndex(bool bRequireValidIndex)
{
	/*
	local int32 row;
	local int32 NewIndex;
	row = Ceil(Controller.MouseY - ClientBounds[1] / ItemHeight);
	NewIndex = FindVisibleIndex(Top, row);
	Return Min(NewIndex, ItemCount - 1);
	*/
	return -1;     //FAKE    /ELiZ
}

void UGUITreeList::Sort()
{
	SortList();
}

int32 UGUITreeList::SetIndex(int32 NewIndex)
{
	/*
	if (IsValidIndex(NewIndex) && !Elements[NewIndex].bEnabled)
	{
		Expand(NewIndex);
		UpdateVisibleCount();
	}
	return Super::SetIndex(NewIndex);
	*/
	return -1;     //FAKE    /ELiZ
}

void UGUITreeList::SetTopItem(int32 Item)
{
	/*
	Top = Item;
	if (Top < 0)
	{
		Top = 0;
	}
	else
	{
		if (FindVisibleIndex(Top, ItemsPerPage) >= ItemCount)
		{
			Top = FindVisibleIndex(ItemCount - 1, -ItemsPerPage);
		}
	}
	if (ItemCount <= 0)
	{
		Top = 0;
	}
	else
	{
		Top = Clamp(Top, 0, ItemCount - 1);
	}
	if (bNotify)
	{
		CheckLinkedObjects(Self);
	}
	OnAdjustTop(Self);
	if (MyScrollBar != None)
	{
		MyScrollBar.AlignThumb();
	}
	*/
}

bool UGUITreeList::Up()
{
	/*
	local int32 NewIndex;
	if (ItemCount < 2 || Index == 0)
	{
		return true;
	}
	NewIndex = Index;
JL0026:
	if (--NewIndex >= 0 && !Elements[NewIndex].bEnabled)
	{
		GOTO JL0026;
	}
	SetIndex(Max(0, NewIndex));
	if (MyScrollBar != None)
	{
		MyScrollBar.AlignThumb();
	}
	*/
	return true;
}

bool UGUITreeList::Down()
{
	/*
	local int32 NewIndex;
	if (ItemCount < 2 || Index == ItemCount - 1)
	{
		return true;
	}
	NewIndex = Index;
JL002D:
	if (++NewIndex < ItemCount && !Elements[NewIndex].bEnabled)
	{
		GOTO JL002D;
	}
	SetIndex(Min(NewIndex, ItemCount - 1));
	if (MyScrollBar != None)
	{
		MyScrollBar.AlignThumb();
	}
	*/
	return true;
}

void UGUITreeList::End()
{
	/*
	local int32 NewIndex;
	if (ItemCount < 2)
	{
		Return;
	}
	NewIndex = FindVisibleIndex(ItemCount - 1, 1);
	if (IsValidIndex(NewIndex))
	{
		SetIndex(NewIndex);
		if (MyScrollBar != None)
		{
			MyScrollBar.AlignThumb();
		}
	}
	*/
}

void UGUITreeList::PgUp()
{
	/*
	if (ItemCount < 2)
	{
		Return;
	}
	UpdateVisibleCount();
	PgUp();
	*/
}

void UGUITreeList::PgDn()
{
	/*
	if (ItemCount < 2)
	{
		Return;
	}
	UpdateVisibleCount();
	PgDn();
	*/
}

void UGUITreeList::InternalOnEndDrag(UGUIComponent* Accepting, bool bAccepted)
{
	/*
	local int32 i;
	if (bAccepted && Accepting != None)
	{
		GetPendingElements();
		if (Accepting != Self)
		{
			for (i = 0; i < SelectedElements.Length; i++)
			{
				RemoveElement(SelectedElements[i]);
			}
		}
		bRepeatClick = False;
	}
	if (Accepting == None)
	{
		bRepeatClick = True;
	}
	SetOutlineAlpha(255);
	if (bNotify)
	{
		CheckLinkedObjects(Self);
	}
	*/
}

bool UGUITreeList::InternalOnDragDrop(UGUIComponent* Sender)
{
	/*
	local array<GUITreeNode> NewItem;
	local GUITreeList SourceTree;
	local int32 i;
	if (Controller.DropTarget == Self)
	{
		if (Controller.DropSource != None && GUITreeList(Controller.DropSource) != None)
		{
			SourceTree = GUITreeList(Controller.DropSource);
			NewItem = SourceTree.GetPendingElements();
			if (Controller.DropSource == Self)
			{
				for (i = NewItem.Length - 1; i >= 0; i--)
				{
					RemoveElement(NewItem[i], , True);
				}
			}
			if (!IsValidIndex(DropIndex))
			{
				DropIndex = ItemCount;
			}
			for (i = NewItem.Length - 1; i >= 0; i--)
			{
				InsertItem(DropIndex, NewItem[i].Caption, NewItem[i].Value, NewItem[i].ParentCaption, NewItem[i].Level, NewItem[i].bEnabled, NewItem[i].ExtraInfo);
			}
			SetIndex(DropIndex);
			return true;
		}
	}
	*/
	return false;
}

void UGUITreeList::ClearPendingElements()
{
	/*
	ClearPendingElements();
	if (SelectedItems.Length == 0)
	{
		SelectedElements.remove(0, SelectedElements.Length);
	}
	*/
}

void UGUITreeList::GetPendingElements(bool bGuarantee)
{
	/*
	local int32 i;
	if (DropState == 1 && Controller.DropSource == Self || bGuarantee)
	{
		if (SelectedElements.Length == 0)
		{
			for (i = 0; i < SelectedItems.Length; i++)
			{
				if (IsValidIndex(SelectedItems[i]) && ValidSelectionAt(SelectedItems[i]))
				{
					SelectedElements[SelectedElements.Length] = Elements[SelectedItems[i]];
				}
			}
			if (SelectedElements.Length == 0 && IsValid() && ValidSelection())
			{
				SelectedElements.Length = SelectedElements.Length + 1;
				GetElementAtIndex(Index, SelectedElements[0]);
			}
		}
		Return SelectedElements;
	}
	*/
}