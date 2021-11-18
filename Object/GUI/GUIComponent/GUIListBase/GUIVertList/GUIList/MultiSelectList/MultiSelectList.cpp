// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIList/MultiSelectList/MultiSelectList.h"

UMultiSelectList::UMultiSelectList()
{

}


void UMultiSelectList::Add(FString NewItem, UObject* obj, FString str, bool bSection)
{
	/*
	local int NewIndex;
	if (!bAllowEmptyItems && NewItem == "" && obj == None && str == "")
	{
		Return;
	}
	if (bSorted && MElements.Length > 0)
	{
		if (NewIndex < MElements.Length && MElements[NewIndex].Item < NewItem)
		{
			NewIndex++;
		}
	}
	else
	{
		NewIndex = MElements.Length;
	}
	MElements.insert(NewIndex, 1);
	MElements[NewIndex].Item = NewItem;
	MElements[NewIndex].ExtraData = obj;
	MElements[NewIndex].ExtraStrData = str;
	MElements[NewIndex].bSelected = False;
	MElements[NewIndex].bSection = bSection;
	ItemCount = MElements.Length;
	if (MyScrollBar != None)
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
		if (!bAllowEmptyItems && NewItem == "" && obj == None && str == "")
		{
			Return;
		}
		MElements[aIndex].Item = NewItem;
		MElements[aIndex].ExtraData = obj;
		MElements[aIndex].ExtraStrData = str;
		MElements[aIndex].bSelected = False;
		if (bSorted)
		{
			Sort();
		}
		OnChange(Self);
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
		if (!bAllowEmptyItems && NewItem == "" && obj == None && str == "")
		{
			Return;
		}
		MElements.insert(aIndex, 1);
		MElements[aIndex].Item = NewItem;
		MElements[aIndex].ExtraData = obj;
		MElements[aIndex].ExtraStrData = str;
		MElements[aIndex].bSection = bSection;
		MElements[aIndex].bSelected = False;
		ItemCount = MElements.Length;
		if (bSorted)
		{
			Sort();
		}
		OnChange(Self);
		if (MyScrollBar != None)
		{
			MyScrollBar.AlignThumb();
		}
	}
	*/
}

void UMultiSelectList::Swap(int32 IndexA, int32 IndexB)
{
	/*
	local GUI.MultiSelectListElem elem;
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
	/*
	local string t1;
	local string t2;
	local Object t;
	local int i;
	if (MultiSelectList(Source) == None)
	{
		Return;
	}
	if (bClearFirst)
	{
		Clear();
	}
	for (i = 0; i < MultiSelectList(Source).MElements.Length; i++)
	{
		MultiSelectList(Source).GetAtIndex(i, t1, t, t2);
		Add(t1, t, t2);
	}
	*/
}

void UMultiSelectList::Remove(int32 i, int32 Count, bool bNoSort)
{
	/*
	if (Count == 0)
	{
		Count = 1;
	}
	if (!IsValidIndex(i))
	{
		Return Index;
	}
	MElements.remove(i, Count);
	ItemCount = MElements.Length;
	if (bSorted)
	{
		Sort();
	}
	SetIndex(-1);
	if (MyScrollBar != None)
	{
		MyScrollBar.AlignThumb();
	}
	Return Index;
	*/
}

void UMultiSelectList::Clear()
{
	/*
	if (MElements.Length == 0)
	{
		Return;
	}
	MElements.remove(0, MElements.Length);
	ItemCount = 0;
	Clear();
	*/
}

FString UMultiSelectList::Get(bool bGuarantee)
{
	FString CSVString="";
	/*
	local int i;
	for (i = 0; i < MElements.Length; i++)
	{
		if (MElements[i].bSelected)
		{
			if (CSVString == "")
			{
				CSVString = MElements[i].Item;
			}
			else
			{
				CSVString = CSVString $ "," $ MElements[i].Item;
			}
		}
	}
	*/
	return CSVString;
}

void UMultiSelectList::GetObject()
{
	/*
	if (!IsValid())
	{
		Return None;
	}
	else
	{
		Return MElements[Index].ExtraData;
	}
	*/
}

bool UMultiSelectList::IsSection()
{
	/*
	if (!IsValid())
	{
		Return False;
	}
	else
	{
		Return MElements[Index].bSection;
	}
	*/
	return false;    //FAKE   /ELiZ

}

FString UMultiSelectList::GetExtra()
{
	FString CSVString="";
	/*
	local int i;
	for (i = 0; i < MElements.Length; i++)
	{
		if (MElements[i].bSelected)
		{
			if (CSVString == "")
			{
				CSVString = MElements[i].ExtraStrData;
			}
			else
			{
				CSVString = CSVString $ "," $ MElements[i].ExtraStrData;
			}
		}
	}
	*/
	return CSVString;
}

void UMultiSelectList::getItemAtIndex(int32 i)
{
	/*
	if (!IsValidIndex(i))
	{
		Return "";
	}
	Return MElements[i].Item;
	*/
}

void UMultiSelectList::GetObjectAtIndex(int32 i)
{
	/*
	if (!IsValidIndex(i))
	{
		Return None;
	}
	Return MElements[i].ExtraData;
	*/
}

void UMultiSelectList::GetExtraAtIndex(int32 i)
{
	/*
	if (!IsValidIndex(i))
	{
		Return "";
	}
	Return MElements[i].ExtraStrData;
	*/
}

void UMultiSelectList::GetAtIndex(int32 i, FString &ItemStr, UObject* &ExtraObj, FString &ExtraStr)
{
	/*
	if (!IsValidIndex(i))
	{
		Return;
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
		Return;
	}
	MElements[i].Item = NewItem;
	*/
}

void UMultiSelectList::SetObjectAtIndex(int32 i, UObject* NewObject)
{
	/*
	if (!IsValidIndex(i))
	{
		Return;
	}
	MElements[i].ExtraData = NewObject;
	*/
}

void UMultiSelectList::SetExtraAtIndex(int32 i, FString NewExtra)
{
	/*
	if (!IsValidIndex(i))
	{
		Return;
	}
	MElements[i].ExtraStrData = NewExtra;
	*/
}

void UMultiSelectList::RemoveItem(FString Item)
{
	/*
	local int i;
	if (i < MElements.Length)
	{
		if (Item ~= MElements[i].Item)
		{
			MElements.remove(i, 1);
		}
		else
		{
			i++;
		}
	}
	ItemCount = MElements.Length;
	SetIndex(-1);
	if (MyScrollBar != None)
	{
		MyScrollBar.AlignThumb();
	}
	*/
}

void UMultiSelectList::RemoveObject(UObject* obj)
{
	/*
	local int i;
	if (i < MElements.Length)
	{
		if (obj == MElements[i].ExtraData)
		{
			MElements.remove(i, 1);
		}
		else
		{
			i++;
		}
	}
	ItemCount = MElements.Length;
	SetIndex(-1);
	if (MyScrollBar != None)
	{
		MyScrollBar.AlignThumb();
	}
	*/
}

void UMultiSelectList::RemoveExtra(FString str)
{
	/*
	local int i;
	if (i < MElements.Length)
	{
		if (str ~= MElements[i].ExtraStrData)
		{
			MElements.remove(i, 1);
		}
		else
		{
			i++;
		}
	}
	ItemCount = MElements.Length;
	SetIndex(-1);
	if (MyScrollBar != None)
	{
		MyScrollBar.AlignThumb();
	}
	*/
}

FString UMultiSelectList::Find(FString Text, bool bExact, bool bExtra)
{
	/*
	local int i;
	i = FindIndex(Text, bExact, bExtra);
	if (i != -1)
	{
		SetIndex(i);
		Return MElements[i].Item;
	}
	*/
	return "";
}

int32 UMultiSelectList::FindIndex(FString Test, bool bExact, bool bExtra, UObject* TestObject)
{
	/*
	local int i;
	if (TestObject != None)
	{
		for (i = 0; i < MElements.Length; i++)
		{
			if (TestObject == MElements[i].ExtraData)
			{
				Return i;
			}
		}
	}
	else
	{
		if (Test != "")
		{
			if (bExtra)
			{
				for (i = 0; i < MElements.Length; i++)
				{
					if (bExact&& MElements[i].ExtraStrData == Test || !bExact && MElements[i].ExtraStrData ~= Test)
					{
						Return i;
					}
				}
			}
			else
			{
				for (i = 0; i < MElements.Length; i++)
				{
					if (bExact&& MElements[i].Item == Test || !bExact && MElements[i].Item ~= Test)
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
	OnChange(Self);
	*/
	return Index;
}