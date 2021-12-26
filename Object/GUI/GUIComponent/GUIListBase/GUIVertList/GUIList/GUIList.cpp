// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIList/GUIList.h"

UGUIList::UGUIList()
{
	TextAlign = EeTextAlign::TXTA_Center;
}

//native final Function SortList();
void UGUIList::SortList()
{

}

void UGUIList::Sort()
{
	/*
	Super::Sort();
	SortList();
	*/
}

void UGUIList::CompareItem(FGUIListElem ElemA, FGUIListElem ElemB)
{
	//Return StrCmp(ElemA.Item, ElemB.Item);
}

void UGUIList::Add(FString NewItem, UObject* obj, FString str, bool bSection)
{
	/*
	local int32 NewIndex;
	local GUI.GUIListElem E;
	if (!bAllowEmptyItems && NewItem == "" && obj == nullptr && str == "")
	{
		Return;
	}
	E.Item = NewItem;
	E.ExtraData = obj;
	E.ExtraStrData = str;
	E.bSection = bSection;
	if (bSorted && Elements.Length > 0)
	{
		if (NewIndex < Elements.Length && CompareItem(Elements[NewIndex], E) < 0)
		{
			NewIndex++;
		}
	}
	else
	{
		NewIndex = Elements.Length;
	}
	Elements.insert(NewIndex, 1);
	Elements[NewIndex] = E;
	ItemCount = Elements.Length;
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
	if (MyScrollBar != None)
	{
		MyScrollBar.AlignThumb();
	}
	*/
}
void UGUIList::AddElement(FGUIListElem NewElem)
{
	//Add(NewElem.Item, NewElem.ExtraData, NewElem.ExtraStrData);
}

void UGUIList::Replace(int32 i, FString NewItem, UObject* obj, FString str, bool bNoSort)
{
	/*
	if (!IsValidIndex(i))
	{
		Add(NewItem, obj, str);
	}
	else
	{
		if (!bAllowEmptyItems && NewItem == "" && obj == nullptr && str == "")
		{
			Return;
		}
		Elements[i].Item = NewItem;
		Elements[i].ExtraData = obj;
		Elements[i].ExtraStrData = str;
		if (bSorted && !bNoSort)
		{
			Sort();
		}
		SetIndex(Index);
	}
	*/
}

void UGUIList::Insert(int32 i, FString NewItem, UObject* obj, FString str, bool bNoSort, bool bSection)
{
	/*
	if (!IsValidIndex(i))
	{
		Add(NewItem, obj, str, bSection);
	}
	else
	{
		if (!bAllowEmptyItems && NewItem == "" && obj == nullptr && str == "")
		{
			Return;
		}
		Elements.insert(i, 1);
		Elements[i].Item = NewItem;
		Elements[i].ExtraData = obj;
		Elements[i].ExtraStrData = str;
		Elements[i].bSection = bSection;
		ItemCount = Elements.Length;
		if (bSorted && !bNoSort)
		{
			Sort();
		}
		SetIndex(Index);
		if (MyScrollBar != None)
		{
			MyScrollBar.AlignThumb();
		}
	}
	*/
}

void UGUIList::InsertElement(int32 i, FGUIListElem NewElem, bool bNoSort)
{
	//Insert(i, NewElem.Item, NewElem.ExtraData, NewElem.ExtraStrData, bNoSort);
}

void UGUIList::Swap(int32 IndexA, int32 IndexB)
{
	/*
	local GUI.GUIListElem elem;
	if (IsValidIndex(IndexA) && IsValidIndex(IndexB))
	{
		elem = Elements[IndexA];
		Elements[IndexA] = Elements[IndexB];
		Elements[IndexB] = elem;
		if (bSorted)
		{
			Sort();
		}
		if (bNotify)
		{
			CheckLinkedObjects(Self);
		}
	}
	*/
}

void UGUIList::LoadFrom(UGUIList* Source, bool bClearFirst)
{
	/*
	local FString t1;
	local FString t2;
	local Object t;
	local int32 i;
	if (bClearFirst)
	{
		Clear();
	}
	for (i = 0; i < Source.Elements.Length; i++)
	{
		Source.GetAtIndex(i, t1, t, t2);
		Add(t1, t, t2);
	}
	*/
}

int32 UGUIList::Remove(int32 i, int32 Count, bool bNoSort)
{
	/*
	Count = Max(Count, 1);
	if (!IsValidIndex(i))
	{
		return Index;
	}
	Elements.remove(i, Min(Count, Elements.Length - i));
	ItemCount = Elements.Length;
	if (bSorted && !bNoSort)
	{
		Sort();
	}
	SetIndex(Index);
	if (MyScrollBar != None)
	{
		MyScrollBar.AlignThumb();
	}
	*/
	return Index;
}

int32 UGUIList::RemoveSilent(int32 i, int32 Count)
{
	/*
	bNotify = False;
	i = Remove(i, Count, True);
	bNotify = True;
	*/
	return i;
}

int32 UGUIList::RemoveElement(FGUIListElem elem, int32 Count, bool bNoSort)
{
	/*
	local int32 i;
	Count = Max(Count, 1);
	i = 0;
	if (i < Elements.Length)
	{
		if (Elements[i] == elem)
		{
			Elements.remove(i, Min(Count, Elements.Length - i));
		}
		else
		{
			i++;
		}
	}
	ItemCount = Elements.Length;
	if (bSorted && !bNoSort)
	{
		Sort();
	}
	SetIndex(Index);
	if (MyScrollBar != None)
	{
		MyScrollBar.AlignThumb();
	}
	*/
	return Index;
}

void UGUIList::Clear()
{
	/*
	if (Elements.Length == 0)
	{
		Return;
	}
	Elements.remove(0, Elements.Length);
	ItemCount = 0;
	Super::Clear();
	*/
}

FString UGUIList::SelectedText()
{
	return Get(false);
}

FString UGUIList::Get(bool bGuarantee)
{
	if (!IsValid())
	{
		/*
		if (bGuarantee && Elements.Length > 0)
		{
			return Elements[0].Item;
		}
		*/
		return "";
	}
	return Elements[Index].Item;
}

UObject* UGUIList::GetObject()
{
	if (!IsValid())
	{
		return nullptr;
	}
	return Elements[Index].ExtraData;
}

FString UGUIList::GetExtra()
{
	if (!IsValid())
	{
		return "";
	}
	return Elements[Index].ExtraStrData;
}

bool UGUIList::IsSection()
{
	if (!IsValid())
	{
		return false;
	}
	return Elements[Index].bSection;
}

FString UGUIList::getItemAtIndex(int32 i)
{
	if (!IsValidIndex(i))
	{
		return "";
	}
	return Elements[i].Item;
}

UObject* UGUIList::GetObjectAtIndex(int32 i)
{
	if (!IsValidIndex(i))
	{
		return nullptr;
	}
	return Elements[i].ExtraData;
}

FString UGUIList::GetExtraAtIndex(int32 i)
{
	if (!IsValidIndex(i))
	{
		return "";
	}
	return Elements[i].ExtraStrData;
}

void UGUIList::GetAtIndex(int32 i, FString &ItemStr, UObject* &ExtraObj, FString &ExtraStr)
{
	/*
	if (!IsValidIndex(i))
	{
		Return;
	}
	ItemStr = Elements[i].Item;
	ExtraObj = Elements[i].ExtraData;
	ExtraStr = Elements[i].ExtraStrData;
	*/
}

void UGUIList::SetItemAtIndex(int32 i, FString NewItem)
{
	/*
	if (!IsValidIndex(i))
	{
		Return;
	}
	Elements[i].Item = NewItem;
	if (bNotify)
	{
		CheckLinkedObjects(Self);
	}
	*/
}

void UGUIList::SetObjectAtIndex(int32 i, UObject* NewObject)
{
	/*
	if (!IsValidIndex(i))
	{
		Return;
	}
	Elements[i].ExtraData = NewObject;
	if (bNotify)
	{
		CheckLinkedObjects(Self);
	}
	*/
}

void UGUIList::SetExtraAtIndex(int32 i, FString NewExtra)
{
	/*
	if (!IsValidIndex(i))
	{
		Return;
	}
	Elements[i].ExtraStrData = NewExtra;
	if (bNotify)
	{
		CheckLinkedObjects(Self);
	}
	*/
}

void UGUIList::RemoveItem(FString Item)
{
	/*
	local int32 i;
	if (i < Elements.Length)
	{
		if (Item ~= Elements[i].Item)
		{
			Elements.remove(i, 1);
		}
		else
		{
			i++;
		}
	}
	ItemCount = Elements.Length;
	SetIndex(-1);
	if (MyScrollBar != None)
	{
		MyScrollBar.AlignThumb();
	}
	*/
}

void UGUIList::RemoveObject(UObject* obj)
{
	/*
	local int32 i;
	if (i < Elements.Length)
	{
		if (obj == Elements[i].ExtraData)
		{
			Elements.remove(i, 1);
		}
		else
		{
			i++;
		}
	}
	ItemCount = Elements.Length;
	SetIndex(-1);
	if (MyScrollBar != None)
	{
		MyScrollBar.AlignThumb();
	}
	*/
}

void UGUIList::RemoveExtra(FString str)
{
	/*
	local int32 i;
	if (i < Elements.Length)
	{
		if (str ~= Elements[i].ExtraStrData)
		{
			Elements.remove(i, 1);
		}
		else
		{
			i++;
		}
	}
	ItemCount = Elements.Length;
	SetIndex(-1);
	if (MyScrollBar != None)
	{
		MyScrollBar.AlignThumb();
	}
	*/
}

FString UGUIList::Find(FString Text, bool bExact, bool bExtra)
{
	/*
	local int32 i;
	i = FindIndex(Text, bExact, bExtra);
	if (i != -1)
	{
		SetIndex(i);
		return Elements[i].Item;
	}
	*/
	return "";
}

int32 UGUIList::FindExtra(FString Text, bool bExact)
{
	return FindIndex(Text, bExact, true, nullptr);
}

int32 UGUIList::FindItemObject(UObject* obj)
{
	return FindIndex("", false, false, obj);
}

int32 UGUIList::FindIndex(FString Test, bool bExact, bool bExtra, UObject* TestObject)
{
	/*
	local int32 i;
	if (TestObject != None)
	{
		for (i = 0; i < Elements.Length; i++)
		{
			if (TestObject == Elements[i].ExtraData)
			{
				return i;
			}
		}
	}
	else
	{
		if (Test != "")
		{
			if (bExtra)
			{
				for (i = 0; i < Elements.Length; i++)
				{
					if (bExact&& Elements[i].ExtraStrData == Test || !bExact && Elements[i].ExtraStrData ~= Test)
					{
						return i;
					}
				}
			}
			else
			{
				for (i = 0; i < Elements.Length; i++)
				{
					if (bExact&& Elements[i].Item == Test || !bExact && Elements[i].Item ~= Test)
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

void UGUIList::InternalOnEndDrag(UGUIComponent* Accepting, bool bAccepted)
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
	if (Accepting == nullptr)
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

bool UGUIList::InternalOnDragDrop(UGUIComponent* Sender)
{
	/*
	local array<GUIListElem> NewItem;
	local int32 i;
	if (Controller.DropTarget == Self)
	{
		if (Controller.DropSource != None && GUIList(Controller.DropSource) != None)
		{
			NewItem = GUIList(Controller.DropSource).GetPendingElements();
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
				Insert(DropIndex, NewItem[i].Item, NewItem[i].ExtraData, NewItem[i].ExtraStrData);
			}
			SetIndex(DropIndex);
			return true;
		}
	}
	*/
	return false;
}

void UGUIList::ClearPendingElements()
{
	/*
	ClearPendingElements();
	if (SelectedItems.Length == 0)
	{
		SelectedElements.remove(0, SelectedElements.Length);
	}
	*/
}

TArray<FGUIListElem> UGUIList::GetPendingElements(bool bGuarantee)
{
	/*
	local int32 i;
	if (DropState == 1 && Controller.DropSource == Self || bGuarantee)
	{
		if (SelectedElements.Length == 0)
		{
			for (i = 0; i < SelectedItems.Length; i++)
			{
				if (IsValidIndex(SelectedItems[i]))
				{
					SelectedElements[SelectedElements.Length] = Elements[SelectedItems[i]];
				}
			}
			if (SelectedElements.Length == 0 && IsValid())
			{
				SelectedElements.Length = SelectedElements.Length + 1;
				GetAtIndex(Index, SelectedElements[0].Item, SelectedElements[0].ExtraData, SelectedElements[0].ExtraStrData);
			}
		}
		return SelectedElements;
	}
	*/
	return {};    //FAKE   /EliZ
}
