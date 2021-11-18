// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIVertImageList/GUIVertImageList.h"

UGUIVertImageList::UGUIVertImageList()
{
	ImageScale = 1;
	NoVisibleRows = 4;
	NoVisibleCols = 3;
	HorzBorder = 5;
	VertBorder = 5;
	StyleName = "";
	//__OnClick__Delegate = "GUIVertImageList.InternalOnClick"
}


int32 UGUIVertImageList::CalculateIndex(bool bRequireValidIndex)
{
	int32 i=0;
	/*
	local int32 HitCol;
	local int32 HitRow;
	HitCol = Controller.MouseX - ClientBounds[0] / ItemWidth;
	HitRow = Controller.MouseY - ClientBounds[1] / ItemHeight;
	i = Top + HitCol + HitRow * NoVisibleCols;
	if (i < 0 || i >= ItemCount && bRequireValidIndex)
	{
		return -1;
	}
	*/
	return i;
}

bool UGUIVertImageList::InternalOnClick(UGUIComponent* Sender)
{
	/*
	local int32 NewIndex;
	if (!IsInClientBounds() || ItemsPerPage == 0)
	{
		return false;
	}
	NewIndex = CalculateIndex();
	if (!IsValidIndex(NewIndex))
	{
		return false;
	}
	SetIndex(NewIndex);
	*/
	return true;
}

void UGUIVertImageList::SetIndex(int32 NewIndex)
{
	/*
	if (Elements[NewIndex].Locked == 1)
	{
		Return Index;
	}
	Return SetIndex(NewIndex);
	*/
}

bool UGUIVertImageList::Up()
{
	/*
	local int32 TargetIndex;
	if (Index - NoVisibleCols < 0)
	{
		return true;
	}
	TargetIndex = Index - NoVisibleCols;
	if (Elements[TargetIndex].Locked == 1)
	{
		TargetIndex = TargetIndex - NoVisibleCols;
		if (TargetIndex < 0 || Elements[TargetIndex].Locked == 1)
		{
			return true;
		}
	}
	SetIndex(TargetIndex);
	if (MyScrollBar != None)
	{
		MyScrollBar.AlignThumb();
	}
	*/
	return true;
}

bool UGUIVertImageList::Down()
{
	/*
	local int32 TargetIndex;
	if (Index + NoVisibleCols >= ItemCount)
	{
		return true;
	}
	TargetIndex = Index + NoVisibleCols;
	if (Elements[TargetIndex].Locked == 1)
	{
		TargetIndex = TargetIndex + NoVisibleCols;
		if (TargetIndex >= ItemCount || Elements[TargetIndex].Locked == 1)
		{
			return true;
		}
	}
	SetIndex(TargetIndex);
	if (MyScrollBar != None)
	{
		MyScrollBar.AlignThumb();
	}
	*/
	return true;
}

bool UGUIVertImageList::MoveRight()
{
	/*
	local int32 TargetIndex;
	TargetIndex = Index + 1;
	if (TargetIndex % NoVisibleCols == 0)
	{
		return true;
	}
	if (Elements[TargetIndex].Locked == 1)
	{
		TargetIndex++;
		if (TargetIndex % NoVisibleCols == 0 || Elements[TargetIndex].Locked == 1)
		{
			return true;
		}
	}
	if (TargetIndex < ItemCount)
	{
		SetIndex(TargetIndex);
	}
	*/
	return true;
}

bool UGUIVertImageList::MoveLeft()
{
	/*
	local int32 TargetIndex;
	if (Index % NoVisibleCols == 0)
	{
		return true;
	}
	TargetIndex = Index - 1;
	if (Elements[TargetIndex].Locked == 1)
	{
		TargetIndex--;
		if (TargetIndex < 0 || TargetIndex % NoVisibleCols == NoVisibleCols - 1 || Elements[TargetIndex].Locked == 1)
		{
			return true;
		}
	}
	if (Index > 0)
	{
		SetIndex(TargetIndex);
	}
	*/
	return true;
}

void UGUIVertImageList::home()
{
	/*
	local int32 i;
	if (ItemCount < 2)
	{
		Return;
	}
	for (i = 0; i < Index; i++)
	{
		if (Elements[i].Locked != 1)
		{
			SetIndex(i);
			if (MyScrollBar != None)
			{
				MyScrollBar.AlignThumb();
			}
			Return;
		}
	}
	*/
}

void UGUIVertImageList::End()
{
	/*
	local int32 i;
	if (ItemCount < 2)
	{
		Return;
	}
	for (i = ItemCount - 1; i > 0; i--)
	{
		if (Elements[i].Locked != 1)
		{
			SetIndex(i);
			if (MyScrollBar != None)
			{
				MyScrollBar.AlignThumb();
			}
			Return;
		}
	}
	*/
}

void UGUIVertImageList::PgUp()
{
	/*
	local int32 NewTop;
	if (Top > 0)
	{
		NewTop = Max(0, Top - NoVisibleRows);
		SetTopItem(NewTop);
		if (MyScrollBar != None)
		{
			MyScrollBar.AlignThumb();
		}
	}
	Return;
	*/
}

void UGUIVertImageList::PgDn()
{
	/*
	local int32 NewTop;
	if (Top < ItemCount / NoVisibleCols - NoVisibleRows)
	{
		NewTop = Max(0, Top + NoVisibleRows);
		SetTopItem(NewTop);
		if (MyScrollBar != None)
		{
			MyScrollBar.AlignThumb();
		}
	}
	Return;
	*/
}

void UGUIVertImageList::MakeVisible(float Perc)
{
	/*
	local float MaxTop;
	local float ModResult;
	local int32 NewTop;
	local int32 Change;
	MaxTop = ItemCount - ItemsPerPage;
	ModResult = MaxTop % NoVisibleCols;
	if (ModResult > 0)
	{
		MaxTop = MaxTop - ModResult + NoVisibleCols;
	}
	NewTop = Round(MaxTop * Perc);
	Change = Abs(Top - NewTop);
	if (Change < NoVisibleCols && Perc < 1)
	{
		Return;
	}
	SetTopItem(NewTop);
	*/
}

void UGUIVertImageList::SetTopItem(int32 Item)
{
	/*
	local int32 ModResult;
	Item = Clamp(Item, 0, ItemCount - 1);
	ModResult = Item % NoVisibleCols;
	if (ModResult > 0)
	{
		if (Item > Top)
		{
			Item += NoVisibleCols;
		}
		Item -= ModResult;
	}
	if (Item + ItemsPerPage > ItemCount + NoVisibleCols && Item >= 0)
	{
		Item -= NoVisibleCols;
	}
	Top = Max(0, Item);
	OnAdjustTop(Self);
	*/
}

void UGUIVertImageList::Add(UMaterialInstance* Image, int32 Item, int32 Locked)
{
	/*
	local int32 i;
	if (Image == None && !bAllowEmptyItems)
	{
		Return;
	}
	i = Elements.Length;
	Elements.Length = i + 1;
	Elements[i].Image = Image;
	Elements[i].Item = Item;
	Elements[i].Locked = Locked;
	ItemCount = Elements.Length;
	if (ItemCount == 1 && bInitializeList)
	{
		SetIndex(0);
	}
	else
	{
		CheckLinkedObjects(Self);
	}
	if (MyScrollBar != None)
	{
		MyScrollBar.AlignThumb();
	}
	*/
}

void UGUIVertImageList::AddImage(FImageListElem NewElem, int32 Locked)
{
	//Add(NewElem.Image, NewElem.Item, Locked);
}

void UGUIVertImageList::Replace(int32 i, UMaterialInstance* NewImage, int32 NewItem, int32 Locked)
{
	/*
	if (!IsValidIndex(i))
	{
		Add(NewImage, NewItem);
	}
	else
	{
		if (!bAllowEmptyItems && NewImage == None)
		{
			Return;
		}
		Elements[i].Item = NewItem;
		Elements[i].Image = NewImage;
		Elements[i].Locked = Locked;
		SetIndex(Index);
		if (MyScrollBar != None)
		{
			MyScrollBar.AlignThumb();
		}
	}
	*/
}

void UGUIVertImageList::Insert(int32 i, UMaterialInstance* NewImage,int32 NewItem,int32 Locked)
{
	/*
	if (!IsValidIndex(i))
	{
		Add(NewImage, NewItem);
	}
	else
	{
		if (!bAllowEmptyItems && NewImage == None)
		{
			Return;
		}
		Elements.insert(i, 1);
		Elements[i].Item = NewItem;
		Elements[i].Image = NewImage;
		Elements[i].Locked = Locked;
		ItemCount = Elements.Length;
		SetIndex(Index);
		if (MyScrollBar != None)
		{
			MyScrollBar.AlignThumb();
		}
	}
	*/
}

void UGUIVertImageList::InsertElement(int32 i, FImageListElem NewElem,int32 Locked)
{
	//Insert(i, NewElem.Image, NewElem.Item, Locked);
}

void UGUIVertImageList::Swap(int32 IndexA, int32 IndexB)
{
	/*
	local FImageListElem elem;
	if (IsValidIndex(IndexA) && IsValidIndex(IndexB))
	{
		elem = Elements[IndexA];
		Elements[IndexA] = Elements[IndexB];
		Elements[IndexB] = elem;
	}
	*/
}

void UGUIVertImageList::LoadFrom(UGUIVertImageList* Source,bool bClearFirst)
{
	/*
	local int32 i;
	local int32 Item;
	local UMaterialInstance* mat;
	local int32 L;
	if (bClearFirst)
	{
		Clear();
	}
	for (i = 0; i < Source.ItemCount; i++)
	{
		Source.GetAtIndex(i, mat, Item, L);
		Add(mat, Item, L);
	}
	*/
}

void UGUIVertImageList::Remove(int32 i,int32 Count)
{
	/*
	Count = Max(Count, 1);
	if (!IsValidIndex(i))
	{
		Return Index;
	}
	Elements.remove(i, Min(Count, Elements.Length - i));
	ItemCount = Elements.Length;
	SetIndex(Index);
	if (MyScrollBar != None)
	{
		MyScrollBar.AlignThumb();
	}
	Return Index;
	*/
}

int32 UGUIVertImageList::RemoveSilent(int32 i,int32 Count)
{
	/*
	bNotify = False;
	i = Remove(i, Count);
	bNotify = True;
	*/
	return i;
}

void UGUIVertImageList::RemoveElement(FImageListElem elem,int32 Count)
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
	SetIndex(Index);
	if (MyScrollBar != None)
	{
		MyScrollBar.AlignThumb();
	}
	Return Index;
	*/
}

void UGUIVertImageList::Clear()
{
	/*
	if (ItemCount == 0)
	{
		Return;
	}
	Elements.remove(0, Elements.Length);
	Clear();
	*/
}

void UGUIVertImageList::Get(bool bGuarantee)
{
	/*
	if (!IsValid())
	{
		if (bGuarantee && ItemCount > 0)
		{
			Return Elements[0].Image;
		}
		Return None;
	}
	Return Elements[Index].Image;
	*/
}

int32 UGUIVertImageList::GetItem()
{
	/*
	if (!IsValid())
	{
		return -1;
	}
	Return Elements[Index].Item;
	*/
	return -1;    //FAKE   /ELiZ
}

void UGUIVertImageList::GetImageAtIndex(int32 i)
{
	/*
	if (!IsValidIndex(i))
	{
		Return None;
	}
	Return Elements[i].Image;
	*/
}

void UGUIVertImageList::getItemAtIndex(int32 i)
{
	//Return GetItemIntAtIndex(i);
}

int32 UGUIVertImageList::GetItemIntAtIndex(int32 i)
{
	/*
	if (!IsValidIndex(i))
	{
		return -1;
	}
	Return Elements[i].Item;
	*/
	return -1;    //FAKE   /ELiZ
}

void UGUIVertImageList::GetAtIndex(int32 i, UMaterialInstance* &Image, int32 &Item, int32 &Locked)
{
	/*
	if (!IsValidIndex(i))
	{
		Return;
	}
	Image = Elements[i].Image;
	Item = Elements[i].Item;
	Locked = Elements[i].Locked;
	*/
}

bool UGUIVertImageList::IndexLocked(int32 i)
{
	//Return Elements[i].Locked == 1;
	return false;    //FAKE   /ELiZ
}

bool UGUIVertImageList::IsLocked()
{
	//Return Elements[Index].Locked == 1;
	return false;    //FAKE   /ELiZ
}

void UGUIVertImageList::ClearPendingElements()
{
	/*
	ClearPendingElements();
	SelectedElements.remove(0, SelectedElements.Length);
	*/
}

void UGUIVertImageList::GetPendingElements(bool bGuarantee)
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
				GetAtIndex(Index, SelectedElements[0].Image, SelectedElements[0].Item, SelectedElements[0].Locked);
			}
		}
		Return SelectedElements;
	}
	*/
}

void UGUIVertImageList::SetImageAtIndex(int32 i, UMaterialInstance* NewImage)
{
	/*
	if (!IsValidIndex(i))
	{
		Return;
	}
	Elements[i].Image = NewImage;
	*/
}

void UGUIVertImageList::SetItemAtIndex(int32 i, int32 NewItem)
{
	/*
	if (!IsValidIndex(i))
	{
		Return;
	}
	Elements[i].Item = NewItem;
	*/
}

void UGUIVertImageList::RemoveImage(UMaterialInstance* Image)
{
	/*
	local int32 i;
	i = FindImage(Image);
	if (IsValidIndex(i))
	{
		Remove(i);
	}
	*/
}

void UGUIVertImageList::RemoveItem(int32 Item)
{
	/*
	local int32 i;
	for (i = Elements.Length - 1; i >= 0; i--)
	{
		if (Elements[i].Item == Item)
		{
			Remove(i);
		}
	}
	ItemCount = Elements.Length;
	SetIndex(Index);
	if (MyScrollBar != None)
	{
		MyScrollBar.AlignThumb();
	}
	*/
}

int32 UGUIVertImageList::FindImage(UMaterialInstance* Image)
{
	/*
	local int32 i;
	if (Image == None && !bAllowEmptyItems)
	{
		return -1;
	}
	for (i = 0; i < Elements.Length; i++)
	{
		if (Elements[i].Image == Image)
		{
			Return i;
		}
	}
	*/
	return -1;
}

int32 UGUIVertImageList::FindItem(int32 Item)
{
	/*
	local int32 i;
	for (i = 0; i < Elements.Length; i++)
	{
		if (Elements[i].Item == Item)
		{
			Return i;
		}
	}
	*/
	return -1;
}

void UGUIVertImageList::InternalOnEndDrag(UGUIComponent* Accepting, bool bAccepted)
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

bool UGUIVertImageList::InternalOnDragDrop(UGUIComponent* Sender)
{
	/*
	local array<ImageListElem> NewItem;
	local int32 i;
	if (Controller.DropTarget == Self)
	{
		if (Controller.DropSource != None && GUIVertImageList(Controller.DropSource) != None)
		{
			NewItem = GUIVertImageList(Controller.DropSource).GetPendingElements();
			if (Controller.DropSource == Self)
			{
				for (i = NewItem.Length - 1; i >= 0; i--)
				{
					RemoveElement(NewItem[i]);
				}
			}
			if (!IsValidIndex(DropIndex))
			{
				DropIndex = ItemCount;
			}
			for (i = NewItem.Length - 1; i >= 0; i--)
			{
				Insert(DropIndex, NewItem[i].Image, NewItem[i].Item);
			}
			SetIndex(DropIndex);
			return true;
		}
	}
	*/
	return false;
}
