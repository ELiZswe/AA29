// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUICircularList/GUICircularImageList/GUICircularImageList.h"

UGUICircularImageList::UGUICircularImageList()
{

}

void UGUICircularImageList::Add(UMaterialInstance* img, FString str)
{
	/*
	int32 NewIndex = 0;
	if (((!bAllowEmptyItems) && (img == None)) && (str == ""))
	{
		return;
	}
	if (bSorted && (Elements.Length > 0))
	{
		if ((NewIndex < Elements.Length) && (Elements[NewIndex].Item < str))
		{
			NewIndex++;
		}
	}
	else
	{
		NewIndex = Elements.Length;
	}
	Elements.insert(NewIndex, 1);
	Elements[NewIndex].Item = str;
	Elements[NewIndex].ExtraData = img;
	ItemCount = Elements.Length;
	if ((Elements.Length == 1) && bInitializeList)
	{
		SetIndex(0);
	}
	else
	{
		CheckLinkedObjects(Self);
	}
	*/
}

void UGUICircularImageList::Replace(int32 i, UMaterialInstance* img, FString str)
{
	/*
	if (!IsValidIndex(i))
	{
		Add(img, str);
	}
	else
	{
		if (((!bAllowEmptyItems) && (img == None)) && (str == ""))
		{
			return;
		}
		Elements[i].Item = str;
		Elements[i].ExtraData = img;
		if (bNotify)
		{
			OnChange(Self);
		}
	}
	*/
}

void UGUICircularImageList::Insert(int32 i, UMaterialInstance* img, FString str)
{
	/*
	if (!IsValidIndex(i))
	{
		Add(img, str);
	}
	else
	{
		if (((!bAllowEmptyItems) && (img == None)) && (str == ""))
		{
			return;
		}
		Elements.insert(i, 1);
		Elements[i].Item = str;
		Elements[i].ExtraData = img;
		ItemCount = Elements.Length;
		if (bNotify)
		{
			OnChange(Self);
		}
	}
	*/
}

void UGUICircularImageList::Swap(int32 IndexA, int32 IndexB)
{
	/*
	local FGUIListElem elem;
	if (IsValidIndex(IndexA) && IsValidIndex(IndexB))
	{
		elem = Elements[IndexA];
		Elements[IndexA] = Elements[IndexB];
		Elements[IndexB] = elem;
	}
	*/
}

void UGUICircularImageList::LoadFrom(UGUICircularImageList* Source, bool bClearFirst)
{
	/*
	FString t1 = "";
	FString t2 = "";
	local Object obj;
	int32 i = 0;
	if (bClearFirst)
	{
		Clear();
	}
	for (i = 0; i < Source.Elements.Length; i++)
	{
		Source.GetAtIndex(i, t1, obj, t2);
		Add(Material(obj), t1);
	}
	*/
}

int32 UGUICircularImageList::RemoveSilent(int32 i, int32 Count)
{
	/*
	bNotify = false;
	i = Remove(i, Count);
	bNotify = true;
	*/
	return i;
}

int32 UGUICircularImageList::Remove(int32 i, int32 Count)
{
	/*
	Count = Max(Count, 1);
	if (!IsValidIndex(i))
	{
		return Index;
	}
	Elements.remove(i, Min(Count, (Elements.Length - i)));
	ItemCount = Elements.Length;
	SetIndex(Index);
	*/
	return Index;
}

int32 UGUICircularImageList::RemoveElement(FGUIListElem elem, int32 Count)
{
	/*
	int32 i = 0;
	Count = Max(Count, 1);
	i = 0;
	if (i < Elements.Length)
	{
		if (Elements[i] == elem)
		{
			Elements.remove(i, Min(Count, (Elements.Length - i)));
		}
		else
		{
			i++;
		}
	}
	ItemCount = Elements.Length;
	SetIndex(Index);
	*/
	return Index;
}

void UGUICircularImageList::Clear()
{
	/*
	if (Elements.Length == 0)
	{
		return;
	}
	Elements.remove(0, Elements.Length);
	ItemCount = 0;
	Super::Clear();
	*/
}

FString UGUICircularImageList::Get(bool bGuarantee)
{
	/*
	if (!IsValid())
	{
		if (bGuarantee && (Elements.Length > 0))
		{
			return Elements[0].Item;
		}
		return "";
	}
	return Elements[Index].Item;
	*/
	return "FAKE";   //FAKE   /ELiZ
}

UMaterialInstance* UGUICircularImageList::GetImage(bool bGuarantee)
{
	/*
	if (!IsValid())
	{
		if (bGuarantee && (Elements.Length > 0))
		{
			return Material(Elements[0].ExtraData);
		}
		return None;
	}
	return Material(Elements[Index].ExtraData);
	*/
	return nullptr;    //FAKE   /ELiZ
}

FString UGUICircularImageList::getItemAtIndex(int32 i)
{
	/*
	if (!IsValidIndex(i))
	{
		return "";
	}
	return Elements[i].Item;
	*/
	return "FAKE";   //FAKE   /ELiZ

}

UMaterialInstance* UGUICircularImageList::GetImageAtIndex(int32 i)
{
	/*
	if (!IsValidIndex(i))
	{
		return None;
	}
	return Material(Elements[i].ExtraData);
	*/
	return nullptr;    //FAKE   /ELiZ
}

void UGUICircularImageList::GetAtIndex(int32 i, FString& ItemStr, UObject*& img, FString& ExtraStr)
{
	/*
	if (!IsValidIndex(i))
	{
		return;
	}
	ItemStr = Elements[i].Item;
	img = Elements[i].ExtraData;
	ExtraStr = Elements[i].ExtraStrData;
	*/
}

TArray<FString> UGUICircularImageList::GetPendingItems(bool bGuarantee)
{
	int32 i = 0;
	TArray<FString> items = {};
	/*
	if (((DropState == 1) && (Controller.DropSource == Self)) || bGuarantee)
	{
		for (i = 0; i < SelectedItems.Length; i++)
		{
			if (IsValidIndex(SelectedItems[i]))
			{
				items[items.Length] = Elements[SelectedItems[i]].Item;
			}
		}
		if ((items.Length == 0) && IsValid())
		{
			items[0] = Get();
		}
	}
	*/
	return items;
}

TArray<FGUIListElem> UGUICircularImageList::GetPendingElements(bool bGuarantee)
{
	int32 i = 0;
	TArray<FGUIListElem> PendingItem = {};
	/*
	if (((DropState == 1) && (Controller.DropSource == Self)) || bGuarantee)
	{
		for (i = 0; i < SelectedItems.Length; i++)
		{
			if (IsValidIndex(SelectedItems[i]))
			{
				PendingItem[PendingItem.Length] = Elements[SelectedItems[i]];
			}
		}
		if ((PendingItem.Length == 0) && IsValid())
		{
			PendingItem.Length = (PendingItem.Length + 1);
			GetAtIndex(Index, PendingItem[0].Item, PendingItem[0].ExtraData, PendingItem[0].ExtraStrData);
		}
	}
	*/
	return PendingItem;
}

void UGUICircularImageList::SetItemAtIndex(int32 i, FString NewItem)
{
	/*
	if (!IsValidIndex(i))
	{
		return;
	}
	Elements[i].Item = NewItem;
	*/
}

void UGUICircularImageList::SetImageAtIndex(int32 i, UMaterialInstance* img)
{
	/*
	if (!IsValidIndex(i))
	{
		return;
	}
	Elements[i].ExtraData = img;
	*/
}

void UGUICircularImageList::RemoveItem(FString Item)
{
	/*
	int32 i = 0;
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
	*/
}

void UGUICircularImageList::RemoveImage(UMaterialInstance* img)
{
	/*
	int32 i = 0;
	if (i < Elements.Length)
	{
		if (img == Elements[i].ExtraData)
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
	*/
}

int32 UGUICircularImageList::FindIndex(UMaterialInstance* img, FString Test)
{
	/*
	int32 i = 0;
	if (img != None)
	{
		for (i = 0; i < Elements.Length; i++)
		{
			if (img == Elements[i].ExtraData)
			{
				return i;
			}
		}
	}
	else
	{
		if (Test != "")
		{
			for (i = 0; i < Elements.Length; i++)
			{
				if (Elements[i].Item ~= Test)
				{
					return i;
				}
			}
		}
	}
	*/
	return -1;
}

void UGUICircularImageList::InternalOnEndDrag(UGUIComponent* Accepting, bool bAccepted)
{
	/*
	int32 i = 0;
	local TArray<GUIListElem> TempElem;
	if (bAccepted && (Accepting != None))
	{
		for (i = 0; i < SelectedItems.Length; i++)
		{
			TempElem[TempElem.Length] = Elements[SelectedItems[i]];
		}
		for (i = 0; i < TempElem.Length; i++)
		{
			RemoveElement(TempElem[i]);
		}
		bRepeatClick = false;
	}
	if (Accepting == None)
	{
		bRepeatClick = true;
	}
	SetOutlineAlpha(255);
	if (bNotify)
	{
		CheckLinkedObjects(Self);
	}
	*/
}

bool UGUICircularImageList::InternalOnDragDrop(UGUIComponent* Sender)
{
	/*
	local TArray<GUIListElem> NewItem;
	int32 i = 0;
	if (Controller.DropTarget == Self)
	{
		if ((Controller.DropSource != None) && (GUIList(Controller.DropSource) != None))
		{
			NewItem = GUIList(Controller.DropSource).GetPendingElements();
			if ((DropIndex >= 0) && (DropIndex < ItemCount))
			{
				i = (NewItem.Length - 1);
				if (i >= 0)
				{
					Insert(DropIndex, Material(NewItem[i].ExtraData), NewItem[i].Item);
					i;
				}
			}
			else
			{
				DropIndex = ItemCount;
				for (i = 0; i < NewItem.Length; i++)
				{
					Add(Material(NewItem[i].ExtraData), NewItem[i].Item);
				}
			}
			SetIndex(DropIndex);
			return true;
		}
	}
	*/
	return false;
}
