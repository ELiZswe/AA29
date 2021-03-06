// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIList/MultiSelectList/MultiSelectList.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIList/GUIList.h"

UMultiSelectList::UMultiSelectList()
{

}

void UMultiSelectList::Add(FString NewItem, UObject* obj, FString str, bool bSection)
{
	/*
	int32 NewIndex = 0;
	if (!bAllowEmptyItems && NewItem == "" && obj == nullptr && str == "")
	{
		return;
	}
	if (bSorted && MElements.Num() > 0)
	{
		if (NewIndex < MElements.Num() && MElements[NewIndex].Item < NewItem)
		{
			NewIndex++;
		}
	}
	else
	{
		NewIndex = MElements.Num();
	}
	MElements.insert(NewIndex, 1);
	MElements[NewIndex].Item = NewItem;
	MElements[NewIndex].ExtraData = obj;
	MElements[NewIndex].ExtraStrData = str;
	MElements[NewIndex].bSelected = false;
	MElements[NewIndex].bSection = bSection;
	ItemCount = MElements.Num();
	if (MyScrollBar != nullptr)
	{
		MyScrollBar.AlignThumb();
	}
	*/
}

void UMultiSelectList::Replace(int32 aIndex, FString NewItem, UObject* obj, FString str, bool bNoSort)
{
	/*
	if (!IsValidIndex(aIndex))
	{
		Add(NewItem, obj, str);
	}
	else
	{
		if (!bAllowEmptyItems && NewItem == "" && obj == nullptr && str == "")
		{
			return;
		}
		MElements[aIndex].Item = NewItem;
		MElements[aIndex].ExtraData = obj;
		MElements[aIndex].ExtraStrData = str;
		MElements[aIndex].bSelected = false;
		if (bSorted)
		{
			Sort();
		}
		OnChange(this);
	}
	*/
}

void UMultiSelectList::Insert(int32 aIndex, FString NewItem, UObject* obj, FString str, bool bNoSort, bool bSection)
{
	/*
	if (!IsValidIndex(aIndex))
	{
		Add(NewItem, obj, str);
	}
	else
	{
		if (!bAllowEmptyItems && NewItem == "" && obj == nullptr && str == "")
		{
			return;
		}
		MElements.insert(aIndex, 1);
		MElements[aIndex].Item = NewItem;
		MElements[aIndex].ExtraData = obj;
		MElements[aIndex].ExtraStrData = str;
		MElements[aIndex].bSection = bSection;
		MElements[aIndex].bSelected = false;
		ItemCount = MElements.Num();
		if (bSorted)
		{
			Sort();
		}
		OnChange(this);
		if (MyScrollBar != nullptr)
		{
			MyScrollBar.AlignThumb();
		}
	}
	*/
}

void UMultiSelectList::Swap(int32 IndexA, int32 IndexB)
{
	FMultiSelectListElem elem = FMultiSelectListElem({});
	/*
	if (IsValidIndex(IndexA) && IsValidIndex(IndexB))
	{
		elem = MElements[IndexA];
		MElements[IndexA] = MElements[IndexB];
		MElements[IndexB] = elem;
		if (bSorted)
		{
			Sort();
		}
	}
	*/
}

void UMultiSelectList::LoadFrom(UGUIList* Source, bool bClearFirst)
{
	FString t1 = "";
	FString t2 = "";
	UObject* t = nullptr;
	int32 i = 0;
	/*
	if (Cast<UMultiSelectList>(Source) == nullptr)
	{
		return;
	}
	if (bClearFirst)
	{
		Clear();
	}
	for (i = 0; i < MultiSelectList(Source).MElements.Num(); i++)
	{
		MultiSelectList(Source).GetAtIndex(i, t1, t, t2);
		Add(t1, t, t2);
	}
	*/
}

int32 UMultiSelectList::Remove(int32 i, int32 Count, bool bNoSort)
{
	/*
	if (Count == 0)
	{
		Count = 1;
	}
	if (!IsValidIndex(i))
	{
		return Index;
	}
	MElements.RemoveAt(i, Count);
	ItemCount = MElements.Num();
	if (bSorted)
	{
		Sort();
	}
	SetIndex(-1);
	if (MyScrollBar != nullptr)
	{
		MyScrollBar.AlignThumb();
	}
	*/
	return Index;
}

void UMultiSelectList::Clear()
{
	/*
	if (MElements.Num() == 0)
	{
		return;
	}
	MElements.RemoveAt(0, MElements.Num());
	ItemCount = 0;
	Clear();
	*/
}

FString UMultiSelectList::Get(bool bGuarantee)
{
	FString CSVString="";
	/*
	int32 i = 0;
	for (i = 0; i < MElements.Num(); i++)
	{
		if (MElements[i].bSelected)
		{
			if (CSVString == "")
			{
				CSVString = MElements[i].Item;
			}
			else
			{
				CSVString = CSVString + "," + MElements[i].Item;
			}
		}
	}
	*/
	return CSVString;
}

UObject* UMultiSelectList::GetObject()
{
	/*
	if (!IsValid())
	{
		return nullptr;
	}
	else
	{
		return MElements[Index].ExtraData;
	}
	*/
	return nullptr;    //FAKE   /EliZ
}

bool UMultiSelectList::IsSection()
{
	/*
	if (!IsValid())
	{
		return false;
	}
	else
	{
		return MElements[Index].bSection;
	}
	*/
	return false;    //FAKE   /ELiZ

}

FString UMultiSelectList::GetExtra()
{
	FString CSVString="";
	/*
	int32 i = 0;
	for (i = 0; i < MElements.Num(); i++)
	{
		if (MElements[i].bSelected)
		{
			if (CSVString == "")
			{
				CSVString = MElements[i].ExtraStrData;
			}
			else
			{
				CSVString = CSVString + "," + MElements[i].ExtraStrData;
			}
		}
	}
	*/
	return CSVString;
}

FString UMultiSelectList::getItemAtIndex(int32 i)
{
	/*
	if (!IsValidIndex(i))
	{
		return "";
	}
	return MElements[i].Item;
	*/
	return "FAKE";   //FAKE  /EliZ
}

UObject* UMultiSelectList::GetObjectAtIndex(int32 i)
{
	/*
	if (!IsValidIndex(i))
	{
		return nullptr;
	}
	return MElements[i].ExtraData;
	*/
	return nullptr;   //FAKE  /EliZ
}

FString UMultiSelectList::GetExtraAtIndex(int32 i)
{
	/*
	if (!IsValidIndex(i))
	{
		return "";
	}
	return MElements[i].ExtraStrData;
	*/
	return "FAKE";   //FAKE  /EliZ
}

void UMultiSelectList::GetAtIndex(int32 i, FString &ItemStr, UObject* &ExtraObj, FString &ExtraStr)
{
	/*
	if (!IsValidIndex(i))
	{
		return;
	}
	ItemStr = MElements[i].Item;
	ExtraObj = MElements[i].ExtraData;
	ExtraStr = MElements[i].ExtraStrData;
	*/
}

TArray<FString> UMultiSelectList::GetPendingItems(bool bGuarantee)
{
	TArray<FString> items = {};
	return items;
}

TArray<FGUIListElem> UMultiSelectList::GetPendingElements(bool bGuarantee)
{
	TArray<FGUIListElem> PendingItem = {};
	return PendingItem;
}

void UMultiSelectList::SetItemAtIndex(int32 i, FString NewItem)
{
	/*
	if (!IsValidIndex(i))
	{
		return;
	}
	MElements[i].Item = NewItem;
	*/
}

void UMultiSelectList::SetObjectAtIndex(int32 i, UObject* NewObject)
{
	/*
	if (!IsValidIndex(i))
	{
		return;
	}
	MElements[i].ExtraData = NewObject;
	*/
}

void UMultiSelectList::SetExtraAtIndex(int32 i, FString NewExtra)
{
	/*
	if (!IsValidIndex(i))
	{
		return;
	}
	MElements[i].ExtraStrData = NewExtra;
	*/
}

void UMultiSelectList::RemoveItem(FString Item)
{
	/*
	int32 i = 0;
	if (i < MElements.Num())
	{
		if (Item ~= MElements[i].Item)
		{
			MElements.RemoveAt(i, 1);
		}
		else
		{
			i++;
		}
	}
	ItemCount = MElements.Num();
	SetIndex(-1);
	if (MyScrollBar != nullptr)
	{
		MyScrollBar.AlignThumb();
	}
	*/
}

void UMultiSelectList::RemoveObject(UObject* obj)
{
	/*
	int32 i = 0;
	if (i < MElements.Num())
	{
		if (obj == MElements[i].ExtraData)
		{
			MElements.RemoveAt(i, 1);
		}
		else
		{
			i++;
		}
	}
	ItemCount = MElements.Num();
	SetIndex(-1);
	if (MyScrollBar != nullptr)
	{
		MyScrollBar.AlignThumb();
	}
	*/
}

void UMultiSelectList::RemoveExtra(FString str)
{
	/*
	int32 i = 0;
	if (i < MElements.Num())
	{
		if (str ~= MElements[i].ExtraStrData)
		{
			MElements.RemoveAt(i, 1);
		}
		else
		{
			i++;
		}
	}
	ItemCount = MElements.Num();
	SetIndex(-1);
	if (MyScrollBar != nullptr)
	{
		MyScrollBar.AlignThumb();
	}
	*/
}

FString UMultiSelectList::Find(FString Text, bool bExact, bool bExtra)
{
	/*
	int32 i = 0;
	i = FindIndex(Text, bExact, bExtra);
	if (i != -1)
	{
		SetIndex(i);
		return MElements[i].Item;
	}
	*/
	return "";
}

int32 UMultiSelectList::FindIndex(FString Test, bool bExact, bool bExtra, UObject* TestObject)
{
	/*
	int32 i = 0;
	if (TestObject != nullptr)
	{
		for (i = 0; i < MElements.Num(); i++)
		{
			if (TestObject == MElements[i].ExtraData)
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
				for (i = 0; i < MElements.Num(); i++)
				{
					if (bExact&& MElements[i].ExtraStrData == Test || !bExact && MElements[i].ExtraStrData ~= Test)
					{
						return i;
					}
				}
			}
			else
			{
				for (i = 0; i < MElements.Num(); i++)
				{
					if (bExact&& MElements[i].Item == Test || !bExact && MElements[i].Item ~= Test)
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

int32 UMultiSelectList::SetIndex(int32 NewIndex)
{
	/*
	if (NewIndex < 0 || NewIndex >= ItemCount)
	{
		Index = -1;
	}
	else
	{
		Index = NewIndex;
		MElements[Index].bSelected = !MElements[Index].bSelected;
	}
	if (Index >= 0 && ItemsPerPage > 0)
	{
		if (Index < Top)
		{
			SetTopItem(Index);
		}
		if (ItemsPerPage != 0 && Index == Top + ItemsPerPage)
		{
			SetTopItem(Index - ItemsPerPage + 1);
		}
	}
	OnChange(this);
	*/
	return Index;
}
