// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIMultiComponentList/GUIMultiComponentList.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"

UGUIMultiComponentList::UGUIMultiComponentList()
{
	ItemScaling = 0.045;
	ItemPadding = 0.1;
	ColumnWidth = 1;
	NumColumns = 1;
	//__OnAdjustTop__Delegate = "GUIMultiComponentList.InternalOnAdjustTop";
}

void UGUIMultiComponentList::OnCreateComponent(UGUIComponent* NewComp, UGUIMultiComponentList* Sender)
{
}

void UGUIMultiComponentList::InitComponent(UGUIController* InController, UGUIComponent* InOwner)
{
	Super::InitComponent(InController, InOwner);
	//MyScrollBar.__AlignThumb__Delegate = ScrollAlignThumb;
}

int32 UGUIMultiComponentList::CalculateIndex(bool bRequireValidIndex)
{
	int32 NewIndex = 0;
	int32 i = 0;
	float X = 0;
	float Y = 0;
	NewIndex = -1;
	/*
	if (IsInClientBounds())
	{
		X = ClientBounds[0];
		Y = ClientBounds[1];
		NewIndex = Top;
		if (bVerticalLayout)
		{
			i = 1;
		}
		if (NewIndex < ItemCount)
		{
			if (!ElementVisible(NewIndex))
			{
				NewIndex++;
			}
			else
			{
				if (Controller.MouseX >= X && Controller.MouseX <= X + ItemWidth && Controller.MouseY >= Y && Controller.MouseY <= Y + ItemHeight)
				{
				}
				if (bVerticalLayout)
				{
					NewIndex += ItemsPerColumn;
					X += ItemWidth;
					if (NewIndex >= ItemCount)
					{
						X = ClientBounds[0];
						Y += ItemHeight;
						NewIndex = Top + i++;
						if (NewIndex >= Top + FMath::Min(ItemsPerPage, ItemCount) / NumColumns)
						{
							if (bRequireValidIndex)
							{
								NewIndex = -1;
							}
						}
					}
					else
					{
					}
				else
				{
					X += ItemWidth;
					if (++i >= NumColumns)
					{
						i = 0;
						X = ClientBounds[0];
						Y += ItemHeight;
					}
				}
				NewIndex++;
				}
				else
				{
				}
			}
		}
	}
	if (NewIndex >= ItemCount && bRequireValidIndex)
	{
		NewIndex = -1;
	}
	return FMath::Min(NewIndex, ItemCount - 1);
	*/
	return 0;    //FAKE    /ELiZ
}

bool UGUIMultiComponentList::ElementVisible(int32 idx)
{
	/*
	int32 i = 0;
	if (bVerticalLayout)
	{
		i = idx - ItemsPerColumn * idx / ItemsPerColumn;
		return i >= Top && i < FMath::Min(Top + ItemsPerPage / NumColumns, ItemCount - 1);
	}
	else
	{
		return idx >= Top && idx < Top + ItemsPerPage;
	}
	*/
	return false;   //FAKE   /ELiZ
}

bool UGUIMultiComponentList::InternalOnClick(UGUIComponent* Sender)
{
	/*
	int32 NewIndex = 0;
	if (ItemsPerPage == 0)
	{
		return false;
	}
	NewIndex = CalculateIndex();
	if (!IsValidIndex(NewIndex))
	{
		return false;
	}
	SilentSetIndex(NewIndex);
	if (Sender != nullptr && Sender.OnClick(Sender))
	{
		return true;
	}
	if (Sender != Self)
	{
		OnClick(this);
	}
	*/
	return true;
}

void UGUIMultiComponentList::GenerateComponent(FString &NewComponentClass, UGUIComponent* &NewComp, FString &Caption)
{
	UGUIComponent* ComponentClass = nullptr;
	/*
	if (NewComponentClass == "" && NewComp == nullptr)
	{
		Warn("Must specify a component class to add item to list!");
		return;
	}
	else
	{
		if (NewComp == nullptr)
		{
			ComponentClass = Controller.AddComponentClass(NewComponentClass);
			if (ComponentClass == nullptr)
			{
				Warn("Could not create new component for list:" @ NewComponentClass);
				return;
			}
			NewComp = new (None) classComponentClass;
		}
		else
		{
			NewComponentClass = NewComp.Class;
		}
	}
	NewComp.__OnChange__Delegate = InternalOnChange;
	OnCreateComponent(NewComp, this);
	NewComp.InitComponent(Controller, this);
	NewComp.__OnClick__Delegate = InternalOnClick;
	*/
}

UGUIComponent* UGUIMultiComponentList::addItem(FString NewComponentClass, UGUIComponent* &NewComp, FString Caption, bool bUnique)
{
	/*
	if (NewComp != nullptr && bUnique)
	{
		if (FindComp(NewComp) == -1)
		{
			return nullptr;
		}
	}
	GenerateComponent(NewComponentClass, NewComp, Caption);
	if (NewComp != nullptr)
	{
		Elements[Elements.Num()] = NewComp;
		NewComp.Opened(this);
		if (MyScrollBar != nullptr)
		{
			MyScrollBar.AlignThumb();
		}
	}
	ItemCount = Elements.Num();
	CheckLinkedObjects(this);
	*/
	return NewComp;
}

UGUIComponent* UGUIMultiComponentList::ReplaceItem(int32 idx, FString NewComponentClass, UGUIComponent* NewComp, FString Caption, bool bUnique)
{
	/*
	if (!ValidIndex(idx))
	{
		return addItem(NewComponentClass, NewComp, Caption, bUnique);
	}
	if (NewComp != nullptr && bUnique)
	{
		if (FindComp(NewComp) == -1)
		{
			return nullptr;
		}
	}
	GenerateComponent(NewComponentClass, NewComp, Caption);
	if (NewComp != nullptr)
	{
		if (NewComp != Elements[Index])
		{
			NewComp.TabOrder = Elements[Index].TabOrder;
			Elements[Index].Free();
			Elements[Index] = NewComp;
			NewComp.Opened(this);
			if (Controller.bCurMenuInitialized)
			{
				OnChange(this);
			}
		}
	}
	*/
	return NewComp;
}

UGUIComponent* UGUIMultiComponentList::InsertItem(int32 idx, FString NewComponentClass, UGUIComponent* NewComp, FString Caption, bool bUnique)
{
	/*
	if (!ValidIndex(idx))
	{
		return addItem(NewComponentClass, NewComp, Caption, bUnique);
	}
	if (NewComp != nullptr && bUnique)
	{
		if (FindComp(NewComp) == -1)
		{
			return nullptr;
		}
	}
	GenerateComponent(NewComponentClass, NewComp, Caption);
	if (NewComp != nullptr)
	{
		NewComp.TabOrder = idx;
		Elements.insert(idx, 1);
		Elements[idx] = NewComp;
		NewComp.Opened(this);
		if (++idx < Elements.Num())
		{
			Elements[idx].TabOrder = idx;
		}
		if (MyScrollBar != nullptr)
		{
			MyScrollBar.AlignThumb();
		}
		if (Controller.bCurMenuInitialized)
		{
			OnChange(this);
		}
	}
	ItemCount = Elements.Num();
	*/
	return NewComp;
}

void UGUIMultiComponentList::RemoveItem(int32 idx)
{
	/*
	if (ValidIndex(idx))
	{
		Elements[idx].Free();
		for (Elements.RemoveAt(idx, 1); idx < Elements.Num(); Elements[idx].TabOrder = idx++)
		{
		}
		SetIndex(-1);
		if (MyScrollBar != nullptr)
		{
			MyScrollBar.AlignThumb();
		}
	}
	ItemCount = Elements.Num();
	*/
}

void UGUIMultiComponentList::Clear()
{
	/*
	int32 i = 0;
	for (i = 0; i < Elements.Num(); i++)
	{
		Elements[i].Free();
	}
	Elements.RemoveAt(0, Elements.Num());
	Super::Clear();
	*/
}

bool UGUIMultiComponentList::ValidIndex(int32 idx)
{
	if (idx < 0 || idx >= Elements.Num())
	{
		return false;
	}
	return true;
}

UGUIComponent* UGUIMultiComponentList::Get()
{
	if (ValidIndex(Index))
	{
		return Elements[Index];
	}
	return nullptr;
}

UGUIComponent* UGUIMultiComponentList::GetItem(int32 idx)
{
	if (ValidIndex(idx))
	{
		return Elements[idx];
	}
	return nullptr;
}

int32 UGUIMultiComponentList::Find(FString Caption)
{
	return -1;
}

int32 UGUIMultiComponentList::FindComp(UGUIComponent* Comp)
{
	int32 i = 0;
	for (i = 0; i < Elements.Num(); i++)
	{
		if (Elements[i] == Comp)
		{
			return i;
		}
	}
	return -1;
}

void UGUIMultiComponentList::InternalOnChange(UGUIComponent* Sender)
{
	/*
	if (Controller.bCurMenuInitialized)
	{
		if (Sender != nullptr)
		{
			SilentSetIndex(FindComp(Sender));
		}
		OnChange(this);
	}
	*/
}

void UGUIMultiComponentList::ShowList()
{
	int32 i = 0;
	for (i = 0; i < Elements.Num(); i++)
	{
		Elements[i]->Show();
	}
}

void UGUIMultiComponentList::HideList()
{
	int32 i = 0;
	for (i = 0; i < Elements.Num(); i++)
	{
		Elements[i]->Hide();
	}
}

int32 UGUIMultiComponentList::SetIndex(int32 NewIndex)
{
	/*
	if (NewIndex == Index)
	{
		if (ValidIndex(NewIndex) && CanFocusElement(Elements[NewIndex]))
		{
			Elements[NewIndex].SetFocus(nullptr);
		}
		return NewIndex;
	}
	if (NewIndex < 0 || NewIndex >= ItemCount)
	{
		Index = -1;
	}
	else
	{
		Index = NewIndex;
	}
	if (Index >= 0 && ItemsPerPage > 0 && !ElementVisible(Index))
	{
		SetTopItem(Index);
	}
	IndexChanged(this);
	bNotify = true;
	if (ElementVisible(Index) && Index < ItemCount && CanFocusElement(Elements[NewIndex]))
	{
		Elements[Index].SetFocus(nullptr);
	}
	return Index;
	*/
	return -1;    //FAKE    /ELiZ
}

void UGUIMultiComponentList::SetFocus(UGUIComponent* Who)
{
	if (Who == nullptr)
	{
		SetFocus(nullptr);
		return;
	}
	MenuStateChange(EMenuState::MSAT_Focused);
	FocusInstead = Who;
	Index = FindComp(Who);
	if (MenuOwner != nullptr)
	{
		MenuOwner->SetFocus(this);
	}
}

void UGUIMultiComponentList::LoseFocus(UGUIComponent* Sender)
{
	if (bHotTrack)
	{
		FocusInstead = nullptr;
	}
	Super::LoseFocus(Sender);
}

void UGUIMultiComponentList::ScrollAlignThumb()
{
	float NewPos = 0;
	/*
	if (ItemCount == 0)
	{
		NewPos = 0;
	}
	else
	{
		if (bVerticalLayout)
		{
			NewPos = Top / ItemsPerColumn - ItemsPerPage / NumColumns;
		}
		else
		{
			NewPos = Top / ItemCount - ItemsPerPage;
		}
	}
	MyScrollBar.GripPos =FMath::Clamp(NewPos, 0, 1);
	*/
}

void UGUIMultiComponentList::MakeVisible(float Perc)
{
	float MaxTop = 0;
	float ModResult = 0;
	int32 NewTop = 0;
	int32 Change = 0;
	/*
	if (!bVerticalLayout)
	{
		MaxTop = ItemCount - ItemsPerPage;
		ModResult = MaxTop % NumColumns;
		if (ModResult > 0)
		{
			MaxTop = MaxTop - ModResult + NumColumns;
		}
		NewTop =FMath::RoundHalfFromZero(MaxTop * Perc);
		Change = Abs(Top - NewTop);
		if (Change < NumColumns && Perc < 1)
		{
			return;
		}
	}
	else
	{
		MaxTop = ItemsPerColumn - ItemsPerPage / NumColumns;
		NewTop =FMath::RoundHalfFromZero(MaxTop * Perc);
	}
	SetTopItem(NewTop);
	*/
}

void UGUIMultiComponentList::SetTopItem(int32 Item)
{
	/*
	int32 ModResult;
	if (bVerticalLayout)
	{
		if (Item > ItemsPerColumn)
		{
			Item -= ItemsPerColumn;
		}
		Item = Clamp(Item, 0, ItemsPerColumn - ItemsPerPage / NumColumns);
	}
	else
	{
		Item = Clamp(Item, 0, ItemCount - 1);
		ModResult = Item % NumColumns;
		if (ModResult > 0)
		{
			if (Item > Top)
			{
				Item += NumColumns;
			}
			Item -= ModResult;
		}
		if (Item + ItemsPerPage > ItemCount + NumColumns && Item >= 0)
		{
			Item -= NumColumns;
		}
	}
	Top = FMath::Max(0, Item);
	OnAdjustTop(this);
	*/
}

void UGUIMultiComponentList::InternalOnAdjustTop(UGUIComponent* Sender)
{
	/*
	if (!bHotTrack && !ElementVisible(Index))
	{
		FocusInstead = nullptr;
	}
	else
	{
		if (bHotTrack && ElementVisible(Index) && Index < Elements.Num() && CanFocusElement(Elements[Index]))
		{
			FocusInstead = Elements[Index];
		}
	}
	*/
}

void UGUIMultiComponentList::WheelDown()
{
	/*
	if (MyScrollBar != nullptr)
	{
		if (Controller.CtrlPressed)
		{
			MyScrollBar.MoveGripBy(ItemsPerPage);
		}
		else
		{
			MyScrollBar.MoveGripBy(NumColumns);
		}
	}
	else
	{
		if (!Controller.CtrlPressed)
		{
			Down();
		}
		else
		{
			PgDn();
		}
	}
	*/
}

void UGUIMultiComponentList::PgUp()
{
	/*
	if (ItemCount < 2)
	{
		return;
	}
	if (bVerticalLayout)
	{
		SetIndex(Max(0, Index - ItemsPerPage / NumColumns));
	}
	else
	{
		PgUp();
	}
	*/
}

void UGUIMultiComponentList::PgDn()
{
	/*
	if (ItemCount < 2)
	{
		return;
	}
	if (bVerticalLayout)
	{
		SetIndex(Min(Index + ItemsPerPage / NumColumns, ItemCount - 1));
	}
	else
	{
		PgDn();
	}
	*/
}

bool UGUIMultiComponentList::Up()
{
	/*
	int32 NewIndex = 0;
	if (bVerticalLayout)
	{
		if (Index > 0 && Index % ItemsPerColumn > 0)
		{
			NewIndex = Index - 1;
			if (NewIndex > 0 && !CanFocusElement(Elements[NewIndex]) && NewIndex % ItemsPerColumn > 0)
			{
				NewIndex--;
			}
			NewIndex = FMath::Max(0, NewIndex);
			if (CanFocusElement(Elements[NewIndex]))
			{
				SetIndex(NewIndex);
			}
		}
		if (MyScrollBar != nullptr)
		{
			MyScrollBar.AlignThumb();
		}
		return true;
	}
	if (Index - NumColumns >= 0)
	{
		NewIndex = Index - NumColumns;
		if (NewIndex - NumColumns >= 0 && !CanFocusElement(Elements[NewIndex]))
		{
			NewIndex -= NumColumns;
		}
		NewIndex = FMath::Max(0, NewIndex);
		if (CanFocusElement(Elements[NewIndex]))
		{
			SetIndex(NewIndex);
		}
	}
	if (MyScrollBar != nullptr)
	{
		MyScrollBar.AlignThumb();
	}
	*/
	return true;
}

bool UGUIMultiComponentList::Down()
{
	/*
	int32 NewIndex = 0;
	if (bVerticalLayout)
	{
		NewIndex = Index + 1;
		if (NewIndex % ItemsPerColumn > 0 && NewIndex < ItemCount)
		{
			if (NewIndex < ItemCount && NewIndex % ItemsPerColumn > 0 && !CanFocusElement(Elements[NewIndex]))
			{
				NewIndex++;
			}
			NewIndex = FMath::Min(NewIndex, ItemCount - 1);
			if (CanFocusElement(Elements[NewIndex]))
			{
				SetIndex(NewIndex);
			}
		}
		if (MyScrollBar != nullptr)
		{
			MyScrollBar.AlignThumb();
		}
		return true;
	}
	if (Index + NumColumns < ItemCount)
	{
		NewIndex = Index + NumColumns;
		if (NewIndex + NumColumns < ItemCount && !CanFocusElement(Elements[NewIndex]))
		{
			NewIndex += NumColumns;
		}
		NewIndex = FMath::Min(NewIndex, ItemCount - 1);
		if (CanFocusElement(Elements[NewIndex]))
		{
			SetIndex(NewIndex);
		}
	}
	if (MyScrollBar != nullptr)
	{
		MyScrollBar.AlignThumb();
	}
	*/
	return true;
}

bool UGUIMultiComponentList::MoveRight()
{
	/*
	int32 NewIndex = 0;
	int32 Avail;
	if (bVerticalLayout)
	{
		NewIndex = Index + ItemsPerColumn;
		if (Index + ItemsPerColumn >= ItemCount)
		{
			return true;
		}
		if (NewIndex + ItemsPerColumn < ItemCount && !CanFocusElement(Elements[NewIndex]))
		{
			NewIndex += ItemsPerColumn;
		}
		NewIndex = FMath::Min(NewIndex, ItemCount - 1);
		if (CanFocusElement(Elements[NewIndex]))
		{
			SetIndex(NewIndex);
		}
		return true;
	}
	Avail = NumColumns - Index % NumColumns - 1;
	NewIndex = Index + 1;
	if (Avail > 0 && NewIndex < ItemCount && ItemCount > 0)
	{
		if (NewIndex - Index <= Avail && NewIndex < ItemCount && !CanFocusElement(Elements[NewIndex]))
		{
			NewIndex++;
		}
		NewIndex = FMath::Min(NewIndex, ItemCount - 1);
		if (CanFocusElement(Elements[NewIndex]))
		{
			SetIndex(NewIndex);
		}
		return true;
	}
	*/
	return true;
}

bool UGUIMultiComponentList::MoveLeft()
{
	/*
	int32 NewIndex = 0;
	int32 Avail;
	if (bVerticalLayout)
	{
		NewIndex = Index - ItemsPerColumn;
		if (NewIndex < 0)
		{
			return true;
		}
		if (NewIndex - ItemsPerColumn >= 0 && !CanFocusElement(Elements[NewIndex]))
		{
			NewIndex -= ItemsPerColumn;
		}
		NewIndex = FMath::Max(0, NewIndex);
		if (CanFocusElement(Elements[NewIndex]))
		{
			SetIndex(NewIndex);
		}
		return true;
	}
	Avail = Index % NumColumns;
	if (Avail > 0 && Index > 0 && ItemCount > 0)
	{
		NewIndex = Index - 1;
		if (Index - NewIndex <= Avail && NewIndex > 0 && !CanFocusElement(Elements[NewIndex]))
		{
			NewIndex--;
		}
		NewIndex = FMath::Max(0, NewIndex);
		if (CanFocusElement(Elements[NewIndex]))
		{
			SetIndex(NewIndex);
		}
		return true;
	}
	*/
	return true;
}

bool UGUIMultiComponentList::NextControl(UGUIComponent* Sender)
{
	/*
	if (Controller.CtrlPressed || Controller.AltPressed || Controller.ShiftPressed || ItemCount > 1 && Index == ItemCount - 1)
	{
		if (MenuOwner != nullptr)
		{
			return MenuOwner.NextControl(this);
		}
	}
	if (bVerticalLayout)
	{
		return Down();
	}
	*/
	return MoveRight();
}

bool UGUIMultiComponentList::PrevControl(UGUIComponent* Sender)
{
	/*
	if (Controller.CtrlPressed || Controller.AltPressed || Controller.ShiftPressed || ItemCount > 1 && Index <= 0)
	{
		if (MenuOwner != nullptr)
		{
			return MenuOwner.PrevControl(this);
		}
	}
	if (bVerticalLayout)
	{
		return Up();
	}
	else
	{
		return MoveLeft();
	}
	*/
	return false;     //FAKE    /ELiZ
}

bool UGUIMultiComponentList::CanFocusElement(UGUIComponent* elem)
{
	//return elem != nullptr && elem.MenuState != 4 && GUIListSpacer(elem) == nullptr;
	return false;     //FAKE    /ELiZ
}

void UGUIMultiComponentList::CenterMouse()
{
	UGUIComponent* mo = nullptr;
	mo = Get();
	if (CanFocusElement(mo))
	{
		mo->CenterMouse();
		return;
	}
	Super::CenterMouse();
}
