// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIList/GUIList.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIScrollBarBase/GUIScrollBarBase.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"

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
	Super::Sort();
	SortList();
}

void UGUIList::CompareItem(FGUIListElem ElemA, FGUIListElem ElemB)
{
	//return StrCmp(ElemA.Item, ElemB.Item);
}

void UGUIList::Add(FString NewItem, UObject* obj, FString str, bool bSection)
{
	int32 NewIndex = 0;
	FGUIListElem E = FGUIListElem({});
	if (!bAllowEmptyItems && NewItem == "" && obj == nullptr && str == "")
	{
		return;
	}
	E.Item = NewItem;
	E.ExtraData = obj;
	E.ExtraStrData = str;
	E.bSection = bSection;
	if (bSorted && Elements.Num() > 0)
	{
		/*
		if (NewIndex < Elements.Num() && CompareItem(Elements[NewIndex], E) < 0)
		{
			NewIndex++;
		}
		*/
	}
	else
	{
		NewIndex = Elements.Num();
	}
	//Elements.insert(NewIndex, 1);
	Elements[NewIndex] = E;
	ItemCount = Elements.Num();
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
	if (MyScrollBar != nullptr)
	{
		MyScrollBar->AlignThumb();
	}
}

void UGUIList::AddElement(FGUIListElem NewElem)
{
	Add(NewElem.Item, NewElem.ExtraData, NewElem.ExtraStrData,false);
}

void UGUIList::Replace(int32 i, FString NewItem, UObject* obj, FString str, bool bNoSort)
{
	if (!IsValidIndex(i))
	{
		Add(NewItem, obj, str,false);
	}
	else
	{
		if (!bAllowEmptyItems && NewItem == "" && obj == nullptr && str == "")
		{
			return;
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
}

void UGUIList::Insert(int32 i, FString NewItem, UObject* obj, FString str, bool bNoSort, bool bSection)
{
	if (!IsValidIndex(i))
	{
		Add(NewItem, obj, str, bSection);
	}
	else
	{
		if (!bAllowEmptyItems && NewItem == "" && obj == nullptr && str == "")
		{
			return;
		}
		Elements.Insert(FGUIListElem({ NewItem,obj,str,bSection }),i);
		ItemCount = Elements.Num();
		if (bSorted && !bNoSort)
		{
			Sort();
		}
		SetIndex(Index);
		if (MyScrollBar != nullptr)
		{
			MyScrollBar->AlignThumb();
		}
	}
}

void UGUIList::InsertElement(int32 i, FGUIListElem NewElem, bool bNoSort)
{
	Insert(i, NewElem.Item, NewElem.ExtraData, NewElem.ExtraStrData, bNoSort,false);
}

void UGUIList::Swap(int32 IndexA, int32 IndexB)
{
	FGUIListElem elem = FGUIListElem({});
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
			CheckLinkedObjects(this);
		}
	}
}

void UGUIList::LoadFrom(UGUIList* Source, bool bClearFirst)
{
	FString t1 = "";
	FString t2 = "";
	UObject* t = nullptr;
	int32 i = 0;
	if (bClearFirst)
	{
		Clear();
	}
	for (i = 0; i < Source->Elements.Num(); i++)
	{
		Source->GetAtIndex(i, t1, t, t2);
		Add(t1, t, t2,false);
	}
}

int32 UGUIList::Remove(int32 i, int32 Count, bool bNoSort)
{
	Count = FMath::Max(Count, 1);
	if (!IsValidIndex(i))
	{
		return Index;
	}
	Elements.RemoveAt(i, FMath::Min(Count, Elements.Num() - i));
	ItemCount = Elements.Num();
	if (bSorted && !bNoSort)
	{
		Sort();
	}
	SetIndex(Index);
	if (MyScrollBar != nullptr)
	{
		MyScrollBar->AlignThumb();
	}
	return Index;
}

int32 UGUIList::RemoveSilent(int32 i, int32 Count)
{
	bNotify = false;
	i = Remove(i, Count, true);
	bNotify = true;
	return i;
}

int32 UGUIList::RemoveElement(FGUIListElem elem, int32 Count, bool bNoSort)
{
	int32 i = 0;
	Count = FMath::Max(Count, 1);
	i = 0;
	if (i < Elements.Num())
	{
		
		if (Elements[i] == elem)
		{
			Elements.RemoveAt(i, FMath::Min(Count, Elements.Num() - i));
		}
		else
		{
			i++;
		}
	}
	ItemCount = Elements.Num();
	if (bSorted && !bNoSort)
	{
		Sort();
	}
	SetIndex(Index);
	if (MyScrollBar != nullptr)
	{
		MyScrollBar->AlignThumb();
	}
	return Index;
}

void UGUIList::Clear()
{
	if (Elements.Num() == 0)
	{
		return;
	}
	Elements.RemoveAt(0, Elements.Num());
	ItemCount = 0;
	Super::Clear();
}

FString UGUIList::SelectedText()
{
	return Get(false);
}

FString UGUIList::Get(bool bGuarantee)
{
	if (!IsValid())
	{
		if (bGuarantee && Elements.Num() > 0)
		{
			return Elements[0].Item;
		}
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
	if (!IsValidIndex(i))
	{
		return;
	}
	ItemStr = Elements[i].Item;
	ExtraObj = Elements[i].ExtraData;
	ExtraStr = Elements[i].ExtraStrData;
}

void UGUIList::SetItemAtIndex(int32 i, FString NewItem)
{
	if (!IsValidIndex(i))
	{
		return;
	}
	Elements[i].Item = NewItem;
	if (bNotify)
	{
		CheckLinkedObjects(this);
	}
}

void UGUIList::SetObjectAtIndex(int32 i, UObject* NewObject)
{
	if (!IsValidIndex(i))
	{
		return;
	}
	Elements[i].ExtraData = NewObject;
	if (bNotify)
	{
		CheckLinkedObjects(this);
	}
}

void UGUIList::SetExtraAtIndex(int32 i, FString NewExtra)
{
	if (!IsValidIndex(i))
	{
		return;
	}
	Elements[i].ExtraStrData = NewExtra;
	if (bNotify)
	{
		CheckLinkedObjects(this);
	}
}

void UGUIList::RemoveItem(FString Item)
{
	int32 i = 0;
	if (i < Elements.Num())
	{
		if (Item.Compare(Elements[i].Item, ESearchCase::IgnoreCase))
		{
			Elements.RemoveAt(i, 1);
		}
		else
		{
			i++;
		}
	}
	ItemCount = Elements.Num();
	SetIndex(-1);
	if (MyScrollBar != nullptr)
	{
		MyScrollBar->AlignThumb();
	}
}

void UGUIList::RemoveObject(UObject* obj)
{
	int32 i = 0;
	if (i < Elements.Num())
	{
		if (obj == Elements[i].ExtraData)
		{
			Elements.RemoveAt(i, 1);
		}
		else
		{
			i++;
		}
	}
	ItemCount = Elements.Num();
	SetIndex(-1);
	if (MyScrollBar != nullptr)
	{
		MyScrollBar->AlignThumb();
	}
}

void UGUIList::RemoveExtra(FString str)
{
	int32 i = 0;
	if (i < Elements.Num())
	{
		if (str.Compare(Elements[i].ExtraStrData,ESearchCase::IgnoreCase))
		{
			Elements.RemoveAt(i, 1);
		}
		else
		{
			i++;
		}
	}
	ItemCount = Elements.Num();
	SetIndex(-1);
	if (MyScrollBar != nullptr)
	{
		MyScrollBar->AlignThumb();
	}
}

FString UGUIList::Find(FString Text, bool bExact, bool bExtra)
{
	int32 i = 0;
	i = FindIndex(Text, bExact, bExtra,nullptr);
	if (i != -1)
	{
		SetIndex(i);
		return Elements[i].Item;
	}
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
	int32 i = 0;
	if (TestObject != nullptr)
	{
		for (i = 0; i < Elements.Num(); i++)
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
				for (i = 0; i < Elements.Num(); i++)
				{
					if (bExact&& Elements[i].ExtraStrData == Test || !bExact && Elements[i].ExtraStrData.Compare(Test,ESearchCase::IgnoreCase))
					{
						return i;
					}
				}
			}
			else
			{
				for (i = 0; i < Elements.Num(); i++)
				{
					if (bExact&& Elements[i].Item == Test || !bExact && Elements[i].Item.Compare(Test,ESearchCase::IgnoreCase))
					{
						return i;
					}
				}
			}
		}
	}
	return -1;
}

void UGUIList::InternalOnEndDrag(UGUIComponent* Accepting, bool bAccepted)
{
	int32 i = 0;
	if (bAccepted && Accepting != nullptr)
	{
		GetPendingElements(false);
		if (Accepting != this)
		{
			for (i = 0; i < SelectedElements.Num(); i++)
			{
				RemoveElement(SelectedElements[i],0,false);
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

bool UGUIList::InternalOnDragDrop(UGUIComponent* Sender)
{
	TArray<FGUIListElem> NewItem;
	int32 i = 0;
	if (Controller->DropTarget == this)
	{
		if (Controller->DropSource != nullptr && Cast<UGUIList>(Controller->DropSource) != nullptr)
		{
			NewItem = Cast<UGUIList>(Controller->DropSource)->GetPendingElements(false);
			if (Controller->DropSource == this)
			{
				for (i = NewItem.Num() - 1; i >= 0; i--)
				{
					RemoveElement(NewItem[i], 0, true);
				}
			}
			if (!IsValidIndex(DropIndex))
			{
				DropIndex = ItemCount;
			}
			for (i = NewItem.Num() - 1; i >= 0; i--)
			{
				Insert(DropIndex, NewItem[i].Item, NewItem[i].ExtraData, NewItem[i].ExtraStrData,false,false);
			}
			SetIndex(DropIndex);
			return true;
		}
	}
	return false;
}

void UGUIList::ClearPendingElements()
{
	/*
	ClearPendingElements();
	if (SelectedItems.Num() == 0)
	{
		SelectedElements.RemoveAt(0, SelectedElements.Num());
	}
	*/
}

TArray<FGUIListElem> UGUIList::GetPendingElements(bool bGuarantee)
{
	/*
	int32 i = 0;
	if (DropState == EDropState::DRP_Source && Controller->DropSource == this || bGuarantee)
	{
		if (SelectedElements.Num() == 0)
		{
			for (i = 0; i < SelectedItems.Num(); i++)
			{
				if (IsValidIndex(SelectedItems[i]))
				{
					SelectedElements[SelectedElements.Num()] = Elements[SelectedItems[i]];
				}
			}
			if (SelectedElements.Num() == 0 && IsValid())
			{
				SelectedElements.Num() = SelectedElements.Num() + 1;
				GetAtIndex(Index, SelectedElements[0].Item, SelectedElements[0].ExtraData, SelectedElements[0].ExtraStrData);
			}
		}
		return SelectedElements;
	}
	*/
	return {};    //FAKE   /EliZ
}
