// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUICircularList/GUICircularImageList/GUICircularImageList.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIList/GUIList.h"

UGUICircularImageList::UGUICircularImageList()
{

}

void UGUICircularImageList::Add(UMaterialInstance* img, FString str)
{
	int32 NewIndex = 0;
	if (((!bAllowEmptyItems) && (img == nullptr)) && (str == ""))
	{
		return;
	}
	if (bSorted && (Elements.Num() > 0))
	{
		if ((NewIndex < Elements.Num()) && (Elements[NewIndex].Item < str))
		{
			NewIndex++;
		}
	}
	else
	{
		NewIndex = Elements.Num();
	}
	//Elements.insert(NewIndex, 1);
	Elements[NewIndex].Item = str;
	Elements[NewIndex].ExtraData = img;
	ItemCount = Elements.Num();
	if ((Elements.Num() == 1) && bInitializeList)
	{
		SetIndex(0);
	}
	else
	{
		CheckLinkedObjects(this);
	}
}

void UGUICircularImageList::Replace(int32 i, UMaterialInstance* img, FString str)
{
	if (!IsValidIndex(i))
	{
		Add(img, str);
	}
	else
	{
		if (((!bAllowEmptyItems) && (img == nullptr)) && (str == ""))
		{
			return;
		}
		Elements[i].Item = str;
		Elements[i].ExtraData = img;
		if (bNotify)
		{
			OnChange(this);
		}
	}
}

void UGUICircularImageList::Insert(int32 i, UMaterialInstance* img, FString str)
{
	if (!IsValidIndex(i))
	{
		Add(img, str);
	}
	else
	{
		if (((!bAllowEmptyItems) && (img == nullptr)) && (str == ""))
		{
			return;
		}
		Elements.Insert(FGUIListElem({ str, img }),i);
		ItemCount = Elements.Num();
		if (bNotify)
		{
			OnChange(this);
		}
	}
}

void UGUICircularImageList::Swap(int32 IndexA, int32 IndexB)
{
	FGUIListElem elem;
	if (IsValidIndex(IndexA) && IsValidIndex(IndexB))
	{
		elem = Elements[IndexA];
		Elements[IndexA] = Elements[IndexB];
		Elements[IndexB] = elem;
	}
}

void UGUICircularImageList::LoadFrom(UGUICircularImageList* Source, bool bClearFirst)
{
	FString t1 = "";
	FString t2 = "";
	UObject* obj = nullptr;
	int32 i = 0;
	if (bClearFirst)
	{
		Clear();
	}
	for (i = 0; i < Source->Elements.Num(); i++)
	{
		Source->GetAtIndex(i, t1, obj, t2);
		Add(Cast<UMaterialInstance>(obj), t1);
	}
}

int32 UGUICircularImageList::RemoveSilent(int32 i, int32 Count)
{
	bNotify = false;
	i = Remove(i, Count);
	bNotify = true;
	return i;
}

int32 UGUICircularImageList::Remove(int32 i, int32 Count)
{
	Count = FMath::Max(Count, 1);
	if (!IsValidIndex(i))
	{
		return Index;
	}
	Elements.RemoveAt(i, FMath::Min(Count, (Elements.Num() - i)));
	ItemCount = Elements.Num();
	SetIndex(Index);
	return Index;
}

int32 UGUICircularImageList::RemoveElement(FGUIListElem elem, int32 Count)
{
	int32 i = 0;
	Count = FMath::Max(Count, 1);
	i = 0;
	if (i < Elements.Num())
	{
		if (Elements[i] == elem)
		{
			Elements.RemoveAt(i, FMath::Min(Count, (Elements.Num() - i)));
		}
		else
		{
			i++;
		}
	}
	ItemCount = Elements.Num();
	SetIndex(Index);
	return Index;
}

void UGUICircularImageList::Clear()
{
	if (Elements.Num() == 0)
	{
		return;
	}
	Elements.Empty();
	ItemCount = 0;
	Super::Clear();
}

FString UGUICircularImageList::Get(bool bGuarantee)
{
	if (!IsValid())
	{
		if (bGuarantee && (Elements.Num() > 0))
		{
			return Elements[0].Item;
		}
		return "";
	}
	return Elements[Index].Item;
}

UMaterialInstance* UGUICircularImageList::GetImage(bool bGuarantee)
{
	if (!IsValid())
	{
		if (bGuarantee && (Elements.Num() > 0))
		{
			return Cast<UMaterialInstance>(Elements[0].ExtraData);
		}
		return nullptr;
	}
	return Cast<UMaterialInstance>(Elements[Index].ExtraData);
}

FString UGUICircularImageList::getItemAtIndex(int32 i)
{
	if (!IsValidIndex(i))
	{
		return "";
	}
	return Elements[i].Item;
}

UMaterialInstance* UGUICircularImageList::GetImageAtIndex(int32 i)
{
	if (!IsValidIndex(i))
	{
		return nullptr;
	}
	return Cast<UMaterialInstance>(Elements[i].ExtraData);
}

void UGUICircularImageList::GetAtIndex(int32 i, FString& ItemStr, UObject*& img, FString& ExtraStr)
{
	if (!IsValidIndex(i))
	{
		return;
	}
	ItemStr = Elements[i].Item;
	img = Elements[i].ExtraData;
	ExtraStr = Elements[i].ExtraStrData;
}

TArray<FString> UGUICircularImageList::GetPendingItems(bool bGuarantee)
{
	int32 i = 0;
	TArray<FString> items = {};
	if (((DropState == EDropState::DRP_Source) && (Controller->DropSource == this)) || bGuarantee)
	{
		for (i = 0; i < SelectedItems.Num(); i++)
		{
			if (IsValidIndex(SelectedItems[i]))
			{
				items[items.Num()] = Elements[SelectedItems[i]].Item;
			}
		}
		if ((items.Num() == 0) && IsValid())
		{
			items[0] = Get(false);
		}
	}
	return items;
}

TArray<FGUIListElem> UGUICircularImageList::GetPendingElements(bool bGuarantee)
{
	int32 i = 0;
	TArray<FGUIListElem> PendingItem = {};
	if (((DropState == EDropState::DRP_Source) && (Controller->DropSource == this)) || bGuarantee)
	{
		for (i = 0; i < SelectedItems.Num(); i++)
		{
			if (IsValidIndex(SelectedItems[i]))
			{
				PendingItem[PendingItem.Num()] = Elements[SelectedItems[i]];
			}
		}
		if ((PendingItem.Num() == 0) && IsValid())
		{
			PendingItem.SetNum(PendingItem.Num() + 1);
			GetAtIndex(Index, PendingItem[0].Item, PendingItem[0].ExtraData, PendingItem[0].ExtraStrData);
		}
	}
	return PendingItem;
}

void UGUICircularImageList::SetItemAtIndex(int32 i, FString NewItem)
{
	if (!IsValidIndex(i))
	{
		return;
	}
	Elements[i].Item = NewItem;
}

void UGUICircularImageList::SetImageAtIndex(int32 i, UMaterialInstance* img)
{
	if (!IsValidIndex(i))
	{
		return;
	}
	Elements[i].ExtraData = img;
}

void UGUICircularImageList::RemoveItem(FString Item)
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
}

void UGUICircularImageList::RemoveImage(UMaterialInstance* img)
{
	int32 i = 0;
	if (i < Elements.Num())
	{
		if (img == Elements[i].ExtraData)
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
}

int32 UGUICircularImageList::FindIndex(UMaterialInstance* img, FString Test)
{
	int32 i = 0;
	if (img != nullptr)
	{
		for (i = 0; i < Elements.Num(); i++)
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
			for (i = 0; i < Elements.Num(); i++)
			{
				if (Elements[i].Item.Compare(Test, ESearchCase::IgnoreCase))
				{
					return i;
				}
			}
		}
	}
	return -1;
}

void UGUICircularImageList::InternalOnEndDrag(UGUIComponent* Accepting, bool bAccepted)
{
	int32 i = 0;
	TArray<FGUIListElem> TempElem = {};
	if (bAccepted && (Accepting != nullptr))
	{
		for (i = 0; i < SelectedItems.Num(); i++)
		{
			TempElem[TempElem.Num()] = Elements[SelectedItems[i]];
		}
		for (i = 0; i < TempElem.Num(); i++)
		{
			RemoveElement(TempElem[i],0);
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

bool UGUICircularImageList::InternalOnDragDrop(UGUIComponent* Sender)
{
	TArray<FGUIListElem> NewItem = {};
	int32 i = 0;
	if (Controller->DropTarget == this)
	{
		if ((Controller->DropSource != nullptr) && (Cast<UGUIList>(Controller->DropSource) != nullptr))
		{
			NewItem = Cast<UGUIList>(Controller->DropSource)->GetPendingElements(false);
			if ((DropIndex >= 0) && (DropIndex < ItemCount))
			{
				for (i = NewItem.Num() - 1; i >= 0; i--)
				{
					Insert(DropIndex, Cast<UMaterialInstance>(NewItem[i].ExtraData), NewItem[i].Item);
				}
			}
			else
			{
				DropIndex = ItemCount;
				for (i = 0; i < NewItem.Num(); i++)
				{
					Add(Cast<UMaterialInstance>(NewItem[i].ExtraData), NewItem[i].Item);
				}
			}
			SetIndex(DropIndex);
			return true;
		}
	}
	return false;
}
