// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUITreeList/GUITreeList.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"

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
	//return StrCmp(ElemA.Caption, ElemB.Caption);
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
		idx = HardInsert(Elements.Num(), Caption, Value, "", 0, true, ExtraInfo);
	}
	else
	{
		if (bGroupItems)
		{
			i = FindIndex(ParentCaption, true);
			if (i == -1)
			{
				i = FindIndex(ParentCaption);
			}
			if (i == -1)
			{
				i = HardInsert(Elements.Num(), ParentCaption, "", "", 0, true);
			}
		}
		else
		{
			if (ParentCaption != "")
			{
				i = HardInsert(Elements.Num(), ParentCaption, Value, "", 0, true, ExtraInfo);
			}
		}
		idx = HardInsert(i + 1, Caption, Value, ParentCaption, Elements[i].Level + 1, bEnabled, ExtraInfo);
	}
	if (Elements.Num() == 1 && bInitializeList)
	{
		SetIndex(0);
	}
	else
	{
		if (bNotify)
		{
			CheckLinkedObjects(this);
		}
	}
	UpdateVisibleCount();
	if (MyScrollBar != nullptr)
	{
		MyScrollBar.AlignThumb();
	}
	*/
	return idx;
}

int32 UGUITreeList::AddElement(FGUITreeNode Node)
{
	//return addItem(Node.Caption, Node.Value, Node.ParentCaption, Node.bEnabled, Node.ExtraInfo);
	return 0;    //FAKE   /ELiZ
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
			return;
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

int32 UGUITreeList::InsertItem(int32 idx, FString Caption, FString Value, FString ParentCaption, int32 Level, bool bEnabled, FString ExtraInfo)
{
	int32 ParentIndex = 0;
	int32 ChildIndex = 0;
	/*
	if (!IsValidIndex(idx))
	{
		return addItem(Caption, Value, ParentCaption, bEnabled, ExtraInfo);
	}
	if (bGroupItems)
	{
		ParentIndex = FindParentIndex(idx);
		if (IsValidIndex(ParentIndex) && Elements[ParentIndex].Caption == ParentCaption)
		{
			ChildIndex = FindAvailableChildIndex(ParentIndex);
			if (idx > ParentIndex && idx <= ChildIndex)
			{
				return HardInsert(idx, Caption, Value, ParentCaption, Elements[ParentIndex].Level + 1, bEnabled, ExtraInfo);
			}
			else
			{
				return HardInsert(ChildIndex, Caption, Value, ParentCaption, Elements[ParentIndex].Level + 1, bEnabled, ExtraInfo);
			}
		}
		else
		{
			if (ParentCaption == "")
			{
				idx = FindNextAvailableRootIndex(idx);
				return HardInsert(idx, Caption, Value, ParentCaption, Level, true, ExtraInfo);
			}
		}
	}
	else
	{
		ParentIndex = FindNextAvailableRootIndex(idx);
		if (ParentCaption != "")
		{
			idx = HardInsert(idx, ParentCaption, Value, "", Level++, true, ExtraInfo);
		}
		return HardInsert(idx + 1, Caption, Value, ParentCaption, Level, true, ExtraInfo);
	}
	return addItem(Caption, Value, ParentCaption, bEnabled);
	*/
	return 0;    //FAKE   /ELiZ
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
	ItemCount = Elements.Num();
	*/
	return idx;
}

void UGUITreeList::LoadFrom(UGUITreeList* Source, bool bClearFirst)
{
	int32 i = 0;
	int32 Level = 0;
	uint8 bEnabled = 0;
	FString Caption = "";
	FString Value = "";
	FString ParentCaption = "";
	FString ExtraInfo = "";
	if (bClearFirst)
	{
		Clear();
	}
	/*
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
	bNotify = false;
	i = RemoveItem(Caption);
	bNotify = true;
	return i;
}

int32 UGUITreeList::RemoveItem(FString Caption)
{
	int32 i=0;
	i = FindIndex(Caption, true);
	if (i == -1)
	{
		i = FindIndex(Caption,false);
	}
	return RemoveItemAt(i,false,false);

}

int32 UGUITreeList::RemoveItemAt(int32 idx, bool bNoSort, bool bSkipCleanup)
{
	int32 Level = 0;
	int32 ParentIndex = 0;
	/*
	if (IsValidIndex(idx))
	{
		Level = Elements[idx].Level + 1;
		ParentIndex = FindParentIndex(idx);
		Elements.RemoveAt(idx, 1);
		ItemCount--;
		if (idx < ItemCount && Elements[idx].Level == Level)
		{
			if (RemoveItemAt(idx, true, True) == -2)
			{
			}
		}
		if (!bAllowParentSelection && !bSkipCleanup && IsValidIndex(ParentIndex) && !HasChildren(ParentIndex))
		{
			RemoveItemAt(ParentIndex, true);
		}
		UpdateVisibleCount();
		if (bSorted && !bNoSort)
		{
			Sort();
		}
		SetIndex(Index);
		if (MyScrollBar != nullptr)
		{
			MyScrollBar.AlignThumb();
		}
		return Index;
	}
	*/
	return -2;
}

int32 UGUITreeList::RemoveElement(FGUITreeNode Node, int32 Count, bool bNoSort)
{
	/*
	int32 i = 0;
	Count = FMath::Max(Count, 1);
	for (i = 0; i < Elements.Num(); i++)
	{
		if (Elements[i] == Node)
		{
			return RemoveItemAt(i, bNoSort);
		}
	}
	*/
	return -1;
}

void UGUITreeList::Clear()
{
	/*
	if (Elements.Num() == 0)
	{
		return;
	}
	Elements.RemoveAt(0, Elements.Num());
	ItemCount = 0;
	UpdateVisibleCount();
	Super::Clear();
	*/
}

bool UGUITreeList::Swap(int32 IndexA, int32 IndexB)
{
	int32 ParentIndexA = 0;
	int32 ParentIndexB = 0;
	/*
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
	TArray<int32> chIdxA = {};
	TArray<int32> chIdxB = {};
	int32 i = 0;
	TArray<UGUITreeNode*> NodesA = {};
	TArray<UGUITreeNode*> NodesB = {};
	/*
	NodesA[NodesA.Num()] = Elements[IndexA];
	NodesB[NodesB.Num()] = Elements[IndexB];
	if (HasChildren(IndexA))
	{
		chIdxA = GetChildIndexList(IndexA);
		for (i = 0; i < chIdxA.Num(); i++)
		{
			NodesA[NodesA.Num()] = Elements[chIdxA[i]];
		}
	}
	if (HasChildren(IndexB))
	{
		chIdxB = GetChildIndexList(IndexB);
		for (i = 0; i < chIdxB.Num(); i++)
		{
			NodesB[NodesB.Num()] = Elements[chIdxB[i]];
		}
	}
	if (IndexA > IndexB)
	{
		Elements.RemoveAt(IndexA, NodesA.Num());
		Elements.insert(IndexA, NodesB.Num());
		for (i = 0; i < NodesB.Num(); i++)
		{
			Elements[IndexA + i] = NodesB[i];
		}
		Elements.RemoveAt(IndexB, NodesB.Num());
		Elements.insert(IndexB, NodesA.Num());
		for (i = 0; i < NodesB.Num(); i++)
		{
			Elements[IndexB + i] = NodesA[i];
		}
	}
	else
	{
		Elements.RemoveAt(IndexB, NodesB.Num());
		Elements.insert(IndexB, NodesA.Num());
		for (i = 0; i < NodesA.Num(); i++)
		{
			Elements[IndexB + i] = NodesA[i];
		}
		Elements.RemoveAt(IndexA, NodesA.Num());
		Elements.insert(IndexA, NodesB.Num());
		for (i = 0; i < NodesB.Num(); i++)
		{
			Elements[IndexA + i] = NodesB[i];
		}
	}
	if (bNotify)
	{
		CheckLinkedObjects(this);
	}
	if (bSorted)
	{
		Sort();
	}
	*/
}

FString UGUITreeList::GetCaption()
{
	return GetCaptionAtIndex(Index);
}

FString UGUITreeList::GetParentCaption()
{
	return GetParentCaptionAtIndex(Index);
}

FString UGUITreeList::GetValue()
{
	return GetValueAtIndex(Index);
}

int32 UGUITreeList::GetLevel()
{
	return GetLevelAtIndex(Index);
}

FString UGUITreeList::GetExtra()
{
	return GetExtraAtIndex(Index);
}

FString UGUITreeList::GetCaptionAtIndex(int32 i)
{
	if (!IsValidIndex(i))
	{
		return "";
	}
	return Elements[i].Caption;
}

FString UGUITreeList::GetParentCaptionAtIndex(int32 idx)
{
	if (!IsValidIndex(idx))
	{
		return "";
	}
	if (Elements[idx].ParentCaption == "")
	{
		return Elements[idx].Caption;
	}
	return Elements[idx].ParentCaption;
}

FString UGUITreeList::GetValueAtIndex(int32 i)
{
	if (!IsValidIndex(i))
	{
		return "";
	}
	return Elements[i].Value;
}

int32 UGUITreeList::GetLevelAtIndex(int32 i)
{
	if (!IsValidIndex(i))
	{
		return -1;
	}
	return Elements[i].Level;
}

FString UGUITreeList::GetExtraAtIndex(int32 idx)
{
	
	if (!IsValidIndex(idx))
	{
		return "";
	}
	return Elements[idx].ExtraInfo;
}

bool UGUITreeList::GetElementAtIndex(int32 i, FGUITreeNode &Node)
{
	if (!IsValidIndex(i))
	{
		return false;
	}
	Node = Elements[i];
	return true;
}

bool UGUITreeList::GetAtIndex(int32 i, FString &Caption, FString &Value, FString &ParentCaption, int32 &Level, uint8 &bEnabled, FString &ExtraInfo)
{
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
	return true;
}

TArray<int32> UGUITreeList::GetIndexList()
{
	TArray<int32> Indexes = { };
	int32 i = 0;
	for (i = 0; i < ItemCount; i++)
	{
		if (ValidSelectionAt(i))
		{
			Indexes[Indexes.Num()] = i;
		}
	}
	return Indexes;
}

TArray<int32> UGUITreeList::GetChildIndexList(int32 idx, bool bNoRecurse)
{
	TArray<int32> Indexes = { };
	int32 Level = 0;
	/*
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
			Indexes[Indexes.Num()] = idx;
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
		return Elements[ParentIndex + 1].Level > Elements[ParentIndex].Level;
	}
	*/
	return false;
}

bool UGUITreeList::IsExpanded(int32 ParentIndex)
{
	if (!HasChildren(ParentIndex))
	{
		return true;
	}
	return Elements[ParentIndex + 1].bEnabled;
	return true;    //FAKE    /ELiZ
}

void UGUITreeList::SetCaptionAtIndex(int32 i, FString NewCaption)
{
	if (!IsValidIndex(i))
	{
		return;
	}
	Elements[i].Caption = NewCaption;
}

void UGUITreeList::SetValueAtIndex(int32 i, FString NewValue)
{
	if (!IsValidIndex(i))
	{
		return;
	}
	Elements[i].Value = NewValue;
}

void UGUITreeList::SetLevelAtIndex(int32 i, int32 NewLevel)
{
	if (!IsValidIndex(i))
	{
		return;
	}
	Elements[i].Level = NewLevel;
}

bool UGUITreeList::Expand(int32 idx, bool bRecursive)
{
	int32 i = 0;
	TArray<int32> Indexes = {};
	if (!IsValidIndex(idx))
	{
		return false;
	}
	Expand(FindParentIndex(idx),false);
	Indexes = GetChildIndexList(idx, !bRecursive);
	for (i = 0; i < Indexes.Num(); i++)
	{
		Elements[Indexes[i]].bEnabled = true;
	}
	return true;
}

bool UGUITreeList::Collapse(int32 idx)
{
	int32 i = 0;
	TArray<int32> Indexes;
	if (!IsValidIndex(idx))
	{
		return false;
	}
	Indexes = GetChildIndexList(idx,false);
	for (i = 0; i < Indexes.Num(); i++)
	{
		Elements[Indexes[i]].bEnabled = false;
	}
	return true;
}

void UGUITreeList::ToggleExpand(int32 idx, bool bRecursive)
{
	if (!IsValidIndex(idx))
	{
		return;
	}
	if (IsExpanded(idx))
	{
		Collapse(idx);
	}
	else
	{
		Expand(idx, bRecursive);
	}
}

bool UGUITreeList::IsToggleClick(int32 idx)
{
	float PrefixOffset = 0;
	float CaptionOffset = 0;
	/*
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
	int32 i = 0;
	/*
	for (i = 0; i < Elements.Num(); i++)
	{
		if (bExact&& Elements[i].Caption == Caption || !bExact && Elements[i].Caption ~= Caption)
		{
			return i;
		}
	}
	*/
	return -1;
}

int32 UGUITreeList::FindFullIndex(FString Caption, FString Value, FString ParentCaption)
{
	int32 i = 0;
	/*
	for (i = 0; i < Elements.Num(); i++)
	{
		if (Elements[i].Caption == Caption && Elements[i].Value == Value && Elements[i].ParentCaption == ParentCaption)
		{
			return i;
		}
	}
	*/
	return -1;
}

int32 UGUITreeList::FindParentIndex(int32 ChildIndex)
{
	int32 Level = 0;
	/*
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
		return Elements.Num();
	}
	if (Elements[Target].Level == 0)
	{
		return Target;
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
	int32 ParentLevel = 0;
	/*
	if (IsValidIndex(ParentIndex))
	{
		ParentLevel = Elements[ParentIndex].Level + 1;
		if (++ParentIndex < ItemCount && Elements[ParentIndex].Level >= ParentLevel)
		{
		}
		return ParentIndex;
	}
	*/
	return -1;
}

int32 UGUITreeList::FindIndexByValue(FString Value, bool bExact)
{
	int32 i = 0;
	/*
	for (i = 0; i < Elements.Num(); i++)
	{
		if (bExact&& Elements[i].Value == Value || !bExact && Elements[i].Value ~= Value)
		{
			return i;
		}
	}
	*/
	return -1;
}

int32 UGUITreeList::FindElement(FString Caption, FString Value, int32 Level, bool bCaseSensitive)
{
	int32 i = 0;
	/*
	if (bCaseSensitive)
	{
		for (i = 0; i < Elements.Num(); i++)
		{
			if (Elements[i].Caption == Caption && Elements[i].Value == Value && Elements[i].Level == Level)
			{
				return i;
			}
			else
			{
				for (i = 0; i < Elements.Num(); i++)
				{
					if (Elements[i].Caption ~= Caption && Elements[i].Value ~= Value && Elements[i].Level == Level)
					{
						return i;
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
	if (Distance == 0)
	{
		return idx;
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
	/*
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
	int32 row = 0;
	int32 NewIndex = 0;
	/*
	row = Ceil(Controller.MouseY - ClientBounds[1] / ItemHeight);
	NewIndex = FindVisibleIndex(Top, row);
	return FMath::Min(NewIndex, ItemCount - 1);
	*/
	return -1;     //FAKE    /ELiZ
}

void UGUITreeList::Sort()
{
	SortList();
}

int32 UGUITreeList::SetIndex(int32 NewIndex)
{
	if (IsValidIndex(NewIndex) && !Elements[NewIndex].bEnabled)
	{
		Expand(NewIndex,false);
		UpdateVisibleCount();
	}
	return Super::SetIndex(NewIndex);
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
		CheckLinkedObjects(this);
	}
	OnAdjustTop(this);
	if (MyScrollBar != nullptr)
	{
		MyScrollBar.AlignThumb();
	}
	*/
}

bool UGUITreeList::Up()
{
	int32 NewIndex = 0;
	/*
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
	if (MyScrollBar != nullptr)
	{
		MyScrollBar.AlignThumb();
	}
	*/
	return true;
}

bool UGUITreeList::Down()
{
	int32 NewIndex = 0;
	/*
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
	if (MyScrollBar != nullptr)
	{
		MyScrollBar.AlignThumb();
	}
	*/
	return true;
}

void UGUITreeList::End()
{
	int32 NewIndex = 0;
	/*
	if (ItemCount < 2)
	{
		return;
	}
	NewIndex = FindVisibleIndex(ItemCount - 1, 1);
	if (IsValidIndex(NewIndex))
	{
		SetIndex(NewIndex);
		if (MyScrollBar != nullptr)
		{
			MyScrollBar.AlignThumb();
		}
	}
	*/
}

void UGUITreeList::PgUp()
{
	if (ItemCount < 2)
	{
		return;
	}
	UpdateVisibleCount();
	Super::PgUp();
}

void UGUITreeList::PgDn()
{
	if (ItemCount < 2)
	{
		return;
	}
	UpdateVisibleCount();
	Super::PgDn();
}

void UGUITreeList::InternalOnEndDrag(UGUIComponent* Accepting, bool bAccepted)
{
	int32 i = 0;
	if (bAccepted && Accepting != nullptr)
	{
		GetPendingElements(false);
		if (Accepting != this)
		{
			for (i = 0; i < SelectedElements.Num(); i++)
			{
				RemoveElement(SelectedElements[i],false,false);
			}
		}
		bRepeatClick = false;
	}
	if (Accepting == nullptr)
	{
		bRepeatClick = true;
	}
	SetOutlineAlpha(255);
	if (bNotify)
	{
		CheckLinkedObjects(this);
	}
}

bool UGUITreeList::InternalOnDragDrop(UGUIComponent* Sender)
{
	TArray<UGUITreeNode*> NewItem = {};
	UGUITreeList* SourceTree = nullptr;
	int32 i = 0;
	/*
	if (Controller->DropTarget == this)
	{
		if (Controller->DropSource != nullptr && GUITreeList(Controller->DropSource) != nullptr)
		{
			SourceTree = GUITreeList(Controller->DropSource);
			NewItem = SourceTree.GetPendingElements();
			if (Controller->DropSource == this)
			{
				for (i = NewItem.Num() - 1; i >= 0; i--)
				{
					RemoveElement(NewItem[i], , true);
				}
			}
			if (!IsValidIndex(DropIndex))
			{
				DropIndex = ItemCount;
			}
			for (i = NewItem.Num() - 1; i >= 0; i--)
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
	if (SelectedItems.Num() == 0)
	{
		SelectedElements.RemoveAt(0, SelectedElements.Num());
	}
	*/
}

TArray<UGUITreeNode*> UGUITreeList::GetPendingElements(bool bGuarantee)
{
	int32 i = 0 ;
	/*
	if (DropState == EDropState::DRP_Source && Controller->DropSource == this || bGuarantee)
	{
		if (SelectedElements.Num() == 0)
		{
			for (i = 0; i < SelectedItems.Num(); i++)
			{
				if (IsValidIndex(SelectedItems[i]) && ValidSelectionAt(SelectedItems[i]))
				{
					SelectedElements[SelectedElements.Num()] = Elements[SelectedItems[i]];
				}
			}
			if (SelectedElements.Num() == 0 && IsValid() && ValidSelection())
			{
				SelectedElements.Num() = SelectedElements.Num() + 1;
				GetElementAtIndex(Index, SelectedElements[0]);
			}
		}
		return SelectedElements;
	}
	*/
	return {};    //FAKE   /EliZ
}
