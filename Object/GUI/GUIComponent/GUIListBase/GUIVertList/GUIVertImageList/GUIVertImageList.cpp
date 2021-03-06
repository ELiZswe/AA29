// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIVertImageList/GUIVertImageList.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"

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
	int32 HitCol = 0;
	int32 HitRow = 0;
	/*
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
	int32 NewIndex = 0;
	/*
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

int32 UGUIVertImageList::SetIndex(int32 NewIndex)
{
	/*
	if (Elements[NewIndex].Locked == 1)
	{
		return Index;
	}
	return SetIndex(NewIndex);
	*/
	return 0;    //FAKE   /EliZ
}

bool UGUIVertImageList::Up()
{
	int32 TargetIndex = 0;
	/*
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
	if (MyScrollBar != nullptr)
	{
		MyScrollBar.AlignThumb();
	}
	*/
	return true;
}

bool UGUIVertImageList::Down()
{
	int32 TargetIndex = 0;
	/*
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
	if (MyScrollBar != nullptr)
	{
		MyScrollBar.AlignThumb();
	}
	*/
	return true;
}

bool UGUIVertImageList::MoveRight()
{
	int32 TargetIndex = 0;
	TargetIndex = Index + 1;
	/*
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
	int32 TargetIndex = 0;
	/*
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
	int32 i = 0;
	if (ItemCount < 2)
	{
		return;
	}
	for (i = 0; i < Index; i++)
	{
		if (Elements[i].Locked != 1)
		{
			SetIndex(i);
			if (MyScrollBar != nullptr)
			{
				MyScrollBar.AlignThumb();
			}
			return;
		}
	}
	*/
}

void UGUIVertImageList::End()
{
	/*
	int32 i = 0;
	if (ItemCount < 2)
	{
		return;
	}
	for (i = ItemCount - 1; i > 0; i--)
	{
		if (Elements[i].Locked != 1)
		{
			SetIndex(i);
			if (MyScrollBar != nullptr)
			{
				MyScrollBar.AlignThumb();
			}
			return;
		}
	}
	*/
}

void UGUIVertImageList::PgUp()
{
	int32 NewTop = 0;
	/*
	if (Top > 0)
	{
		NewTop = FMath::Max(0, Top - NoVisibleRows);
		SetTopItem(NewTop);
		if (MyScrollBar != nullptr)
		{
			MyScrollBar.AlignThumb();
		}
	}
	return;
	*/
}

void UGUIVertImageList::PgDn()
{
	int32 NewTop = 0;
	/*
	if (Top < ItemCount / NoVisibleCols - NoVisibleRows)
	{
		NewTop = FMath::Max(0, Top + NoVisibleRows);
		SetTopItem(NewTop);
		if (MyScrollBar != nullptr)
		{
			MyScrollBar.AlignThumb();
		}
	}
	return;
	*/
}

void UGUIVertImageList::MakeVisible(float Perc)
{
	float MaxTop = 0;
	float ModResult = 0;
	int32 NewTop = 0;
	int32 Change = 0;
	/*
	MaxTop = ItemCount - ItemsPerPage;
	ModResult = MaxTop % NoVisibleCols;
	if (ModResult > 0)
	{
		MaxTop = MaxTop - ModResult + NoVisibleCols;
	}
	NewTop =FMath::RoundHalfFromZero(MaxTop * Perc);
	Change = Abs(Top - NewTop);
	if (Change < NoVisibleCols && Perc < 1)
	{
		return;
	}
	SetTopItem(NewTop);
	*/
}

void UGUIVertImageList::SetTopItem(int32 Item)
{
	int32 ModResult = 0;
	/*
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
	Top = FMath::Max(0, Item);
	OnAdjustTop(this);
	*/
}

void UGUIVertImageList::Add(UMaterialInstance* Image, int32 Item, int32 Locked)
{
	/*
	int32 i = 0;
	if (Image == nullptr && !bAllowEmptyItems)
	{
		return;
	}
	i = Elements.Num();
	Elements.Num() = i + 1;
	Elements[i].Image = Image;
	Elements[i].Item = Item;
	Elements[i].Locked = Locked;
	ItemCount = Elements.Num();
	if (ItemCount == 1 && bInitializeList)
	{
		SetIndex(0);
	}
	else
	{
		CheckLinkedObjects(this);
	}
	if (MyScrollBar != nullptr)
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
		if (!bAllowEmptyItems && NewImage == nullptr)
		{
			return;
		}
		Elements[i].Item = NewItem;
		Elements[i].Image = NewImage;
		Elements[i].Locked = Locked;
		SetIndex(Index);
		if (MyScrollBar != nullptr)
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
		if (!bAllowEmptyItems && NewImage == nullptr)
		{
			return;
		}
		Elements.insert(i, 1);
		Elements[i].Item = NewItem;
		Elements[i].Image = NewImage;
		Elements[i].Locked = Locked;
		ItemCount = Elements.Num();
		SetIndex(Index);
		if (MyScrollBar != nullptr)
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
	FImageListElem elem = FImageListElem({});
	/*
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
	int32 i = 0;
	int32 Item = 0;
	UMaterialInstance* mat = nullptr;
	int32 L = 0;
	if (bClearFirst)
	{
		Clear();
	}
	/*
	for (i = 0; i < Source.ItemCount; i++)
	{
		Source.GetAtIndex(i, mat, Item, L);
		Add(mat, Item, L);
	}
	*/
}

int32 UGUIVertImageList::Remove(int32 i,int32 Count)
{
	/*
	Count = FMath::Max(Count, 1);
	if (!IsValidIndex(i))
	{
		return Index;
	}
	Elements.RemoveAt(i, FMath::Min(Count, Elements.Num() - i));
	ItemCount = Elements.Num();
	SetIndex(Index);
	if (MyScrollBar != nullptr)
	{
		MyScrollBar.AlignThumb();
	}
	*/
	return Index;
}

int32 UGUIVertImageList::RemoveSilent(int32 i,int32 Count)
{
	/*
	bNotify = false;
	i = Remove(i, Count);
	bNotify = true;
	*/
	return i;
}

int32 UGUIVertImageList::RemoveElement(FImageListElem elem,int32 Count)
{
	/*
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
	SetIndex(Index);
	if (MyScrollBar != nullptr)
	{
		MyScrollBar.AlignThumb();
	}
	*/
	return Index;
}

void UGUIVertImageList::Clear()
{
	/*
	if (ItemCount == 0)
	{
		return;
	}
	Elements.RemoveAt(0, Elements.Num());
	Clear();
	*/
}

UMaterialInstance* UGUIVertImageList::Get(bool bGuarantee)
{
	if (!IsValid())
	{
		if (bGuarantee && ItemCount > 0)
		{
			return Elements[0].Image;
		}
		return nullptr;
	}
	return Elements[Index].Image;
}

int32 UGUIVertImageList::GetItem()
{
	if (!IsValid())
	{
		return -1;
	}
	return Elements[Index].Item;
}

UMaterialInstance* UGUIVertImageList::GetImageAtIndex(int32 i)
{
	if (!IsValidIndex(i))
	{
		return nullptr;
	}
	return Elements[i].Image;
}

FString UGUIVertImageList::getItemAtIndex(int32 i)
{
	return FString::FromInt(GetItemIntAtIndex(i));
}

int32 UGUIVertImageList::GetItemIntAtIndex(int32 i)
{
	if (!IsValidIndex(i))
	{
		return -1;
	}
	return Elements[i].Item;
}

void UGUIVertImageList::GetAtIndex(int32 i, UMaterialInstance* &Image, int32 &Item, int32 &Locked)
{
	/*
	if (!IsValidIndex(i))
	{
		return;
	}
	Image = Elements[i].Image;
	Item = Elements[i].Item;
	Locked = Elements[i].Locked;
	*/
}

bool UGUIVertImageList::IndexLocked(int32 i)
{
	//return Elements[i].Locked == 1;
	return false;    //FAKE   /ELiZ
}

bool UGUIVertImageList::IsLocked()
{
	//return Elements[Index].Locked == 1;
	return false;    //FAKE   /ELiZ
}

void UGUIVertImageList::ClearPendingElements()
{
	/*
	ClearPendingElements();
	SelectedElements.RemoveAt(0, SelectedElements.Num());
	*/
}

TArray<UImageListElem*> UGUIVertImageList::GetPendingElements(bool bGuarantee)
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
				GetAtIndex(Index, SelectedElements[0].Image, SelectedElements[0].Item, SelectedElements[0].Locked);
			}
		}
		return SelectedElements;
	}
	*/
	return {};    //FAKE   /EliZ
}

void UGUIVertImageList::SetImageAtIndex(int32 i, UMaterialInstance* NewImage)
{
	if (!IsValidIndex(i))
	{
		return;
	}
	Elements[i].Image = NewImage;
}

void UGUIVertImageList::SetItemAtIndex(int32 i, int32 NewItem)
{
	if (!IsValidIndex(i))
	{
		return;
	}
	Elements[i].Item = NewItem;
}

void UGUIVertImageList::RemoveImage(UMaterialInstance* Image)
{
	/*
	int32 i = 0;
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
	int32 i = 0;
	for (i = Elements.Num() - 1; i >= 0; i--)
	{
		if (Elements[i].Item == Item)
		{
			Remove(i);
		}
	}
	ItemCount = Elements.Num();
	SetIndex(Index);
	if (MyScrollBar != nullptr)
	{
		MyScrollBar.AlignThumb();
	}
	*/
}

int32 UGUIVertImageList::FindImage(UMaterialInstance* Image)
{
	/*
	int32 i = 0;
	if (Image == nullptr && !bAllowEmptyItems)
	{
		return -1;
	}
	for (i = 0; i < Elements.Num(); i++)
	{
		if (Elements[i].Image == Image)
		{
			return i;
		}
	}
	*/
	return -1;
}

int32 UGUIVertImageList::FindItem(int32 Item)
{
	/*
	int32 i = 0;
	for (i = 0; i < Elements.Num(); i++)
	{
		if (Elements[i].Item == Item)
		{
			return i;
		}
	}
	*/
	return -1;
}

void UGUIVertImageList::InternalOnEndDrag(UGUIComponent* Accepting, bool bAccepted)
{
	/*
	int32 i = 0;
	if (bAccepted && Accepting != nullptr)
	{
		GetPendingElements();
		if (Accepting != Self)
		{
			for (i = 0; i < SelectedElements.Num(); i++)
			{
				RemoveElement(SelectedElements[i]);
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
	*/
}

bool UGUIVertImageList::InternalOnDragDrop(UGUIComponent* Sender)
{
	FImageListElem NewItem = FImageListElem({});
	int32 i = 0;
	/*
	if (Controller->DropTarget == this)
	{
		if (Controller->DropSource != nullptr && GUIVertImageList(Controller->DropSource) != nullptr)
		{
			NewItem = GUIVertImageList(Controller->DropSource).GetPendingElements();
			if (Controller->DropSource == this)
			{
				for (i = NewItem.Num() - 1; i >= 0; i--)
				{
					RemoveElement(NewItem[i]);
				}
			}
			if (!IsValidIndex(DropIndex))
			{
				DropIndex = ItemCount;
			}
			for (i = NewItem.Num() - 1; i >= 0; i--)
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
