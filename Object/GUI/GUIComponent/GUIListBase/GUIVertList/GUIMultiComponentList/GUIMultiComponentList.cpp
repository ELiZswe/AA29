// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIMultiComponentList/GUIMultiComponentList.h"

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
	//InitComponent(InController, InOwner);
	//MyScrollBar.__AlignThumb__Delegate = ScrollAlignThumb;
}

int32 UGUIMultiComponentList::CalculateIndex(bool bRequireValidIndex)
{
	/*
	local int NewIndex;
	local int i;
	local float X;
	local float Y;
	NewIndex = -1;
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
						if (NewIndex >= Top + Min(ItemsPerPage, ItemCount) / NumColumns)
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
	Return Min(NewIndex, ItemCount - 1);
	*/
	return 0;    //FAKE    /ELiZ
}

bool UGUIMultiComponentList::ElementVisible(int32 idx)
{
	/*
	local int i;
	if (bVerticalLayout)
	{
		i = idx - ItemsPerColumn * idx / ItemsPerColumn;
		Return i >= Top && i < Min(Top + ItemsPerPage / NumColumns, ItemCount - 1);
	}
	else
	{
		Return idx >= Top && idx < Top + ItemsPerPage;
	}
	*/
	return false;   //FAKE   /ELiZ
}

bool UGUIMultiComponentList::InternalOnClick(UGUIComponent* Sender)
{
	/*
	local int NewIndex;
	if (ItemsPerPage == 0)
	{
		Return False;
	}
	NewIndex = CalculateIndex();
	if (!IsValidIndex(NewIndex))
	{
		Return False;
	}
	SilentSetIndex(NewIndex);
	if (Sender != None && Sender.OnClick(Sender))
	{
		Return True;
	}
	if (Sender != Self)
	{
		OnClick(Self);
	}
	*/
	return true;
}

void UGUIMultiComponentList::GenerateComponent(FString &NewComponentClass, UGUIComponent* &NewComp, FString &Caption)
{
	/*
	local class<UGUIComponent*>  ComponentClass;
	if (NewComponentClass == "" && NewComp == None)
	{
		Warn("Must specify a component class to add item to list!");
		Return;
	}
	else
	{
		if (NewComp == None)
		{
			ComponentClass = Controller.AddComponentClass(NewComponentClass);
			if (ComponentClass == None)
			{
				Warn("Could not create new component for list:" @ NewComponentClass);
				Return;
			}
			NewComp = new (None) classComponentClass;
		}
		else
		{
			NewComponentClass = NewComp.Class;
		}
	}
	NewComp.__OnChange__Delegate = InternalOnChange;
	OnCreateComponent(NewComp, Self);
	NewComp.InitComponent(Controller, Self);
	NewComp.__OnClick__Delegate = InternalOnClick;
	*/
}

UGUIComponent* UGUIMultiComponentList::addItem(FString NewComponentClass, UGUIComponent* &NewComp, FString Caption, bool bUnique)
{
	/*
	if (NewComp != None && bUnique)
	{
		if (FindComp(NewComp) == -1)
		{
			Return None;
		}
	}
	GenerateComponent(NewComponentClass, NewComp, Caption);
	if (NewComp != None)
	{
		Elements[Elements.Length] = NewComp;
		NewComp.Opened(Self);
		if (MyScrollBar != None)
		{
			MyScrollBar.AlignThumb();
		}
	}
	ItemCount = Elements.Length;
	CheckLinkedObjects(Self);
	*/
	return NewComp;
}

UGUIComponent* UGUIMultiComponentList::ReplaceItem(int32 idx, FString NewComponentClass, UGUIComponent* NewComp, FString Caption, bool bUnique)
{
	/*
	if (!ValidIndex(idx))
	{
		Return addItem(NewComponentClass, NewComp, Caption, bUnique);
	}
	if (NewComp != None && bUnique)
	{
		if (FindComp(NewComp) == -1)
		{
			Return None;
		}
	}
	GenerateComponent(NewComponentClass, NewComp, Caption);
	if (NewComp != None)
	{
		if (NewComp != Elements[Index])
		{
			NewComp.TabOrder = Elements[Index].TabOrder;
			Elements[Index].Free();
			Elements[Index] = NewComp;
			NewComp.Opened(Self);
			if (Controller.bCurMenuInitialized)
			{
				OnChange(Self);
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
		Return addItem(NewComponentClass, NewComp, Caption, bUnique);
	}
	if (NewComp != None && bUnique)
	{
		if (FindComp(NewComp) == -1)
		{
			Return None;
		}
	}
	GenerateComponent(NewComponentClass, NewComp, Caption);
	if (NewComp != None)
	{
		NewComp.TabOrder = idx;
		Elements.insert(idx, 1);
		Elements[idx] = NewComp;
		NewComp.Opened(Self);
		if (++idx < Elements.Length)
		{
			Elements[idx].TabOrder = idx;
		}
		if (MyScrollBar != None)
		{
			MyScrollBar.AlignThumb();
		}
		if (Controller.bCurMenuInitialized)
		{
			OnChange(Self);
		}
	}
	ItemCount = Elements.Length;
	*/
	return NewComp;
}

void UGUIMultiComponentList::RemoveItem(int32 idx)
{
	/*
	if (ValidIndex(idx))
	{
		Elements[idx].Free();
		for (Elements.remove(idx, 1); idx < Elements.Length; Elements[idx].TabOrder = idx++)
		{
		}
		SetIndex(-1);
		if (MyScrollBar != None)
		{
			MyScrollBar.AlignThumb();
		}
	}
	ItemCount = Elements.Length;
	*/
}

void UGUIMultiComponentList::Clear()
{
	/*
	local int i;
	for (i = 0; i < Elements.Length; i++)
	{
		Elements[i].Free();
	}
	Elements.remove(0, Elements.Length);
	Super::Clear();
	*/
}

bool UGUIMultiComponentList::ValidIndex(int32 idx)
{
	/*
	if (idx < 0 || idx >= Elements.Length)
	{
		Return False;
	}
	*/
	return true;
}

void UGUIMultiComponentList::Get()
{
	/*
	if (ValidIndex(Index))
	{
		Return Elements[Index];
	}
	Return None;
	*/
}

void UGUIMultiComponentList::GetItem(int32 idx)
{
	/*
	if (ValidIndex(idx))
	{
		Return Elements[idx];
	}
	Return None;
	*/
}

int32 UGUIMultiComponentList::Find(FString Caption)
{
	return -1;
}

int32 UGUIMultiComponentList::FindComp(UGUIComponent* Comp)
{
	/*
	local int i;
	for (i = 0; i < Elements.Length; i++)
	{
		if (Elements[i] == Comp)
		{
			Return i;
		}
	}
	*/
	return -1;
}

void UGUIMultiComponentList::InternalOnChange(UGUIComponent* Sender)
{
	/*
	if (Controller.bCurMenuInitialized)
	{
		if (Sender != None)
		{
			SilentSetIndex(FindComp(Sender));
		}
		OnChange(Self);
	}
	*/
}

void UGUIMultiComponentList::ShowList()
{
	/*
	local int i;
	for (i = 0; i < Elements.Length; i++)
	{
		Elements[i].Show();
	}
	*/
}

void UGUIMultiComponentList::HideList()
{
	/*
	local int i;
	for (i = 0; i < Elements.Length; i++)
	{
		Elements[i].Hide();
	}
	*/
}

int32 UGUIMultiComponentList::SetIndex(int32 NewIndex)
{
	/*
	if (NewIndex == Index)
	{
		if (ValidIndex(NewIndex) && CanFocusElement(Elements[NewIndex]))
		{
			Elements[NewIndex].SetFocus(None);
		}
		Return NewIndex;
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
	IndexChanged(Self);
	bNotify = True;
	if (ElementVisible(Index) && Index < ItemCount && CanFocusElement(Elements[NewIndex]))
	{
		Elements[Index].SetFocus(None);
	}
	Return Index;
	*/
	return -1;    //FAKE    /ELiZ
}

void UGUIMultiComponentList::SetFocus(UGUIComponent* Who)
{
	/*
	if (Who == None)
	{
		SetFocus(None);
		Return;
	}
	MenuStateChange(2);
	FocusInstead = Who;
	Index = FindComp(Who);
	if (MenuOwner != None)
	{
		MenuOwner.SetFocus(Self);
	}
	*/
}

void UGUIMultiComponentList::LoseFocus(UGUIComponent* Sender)
{
	/*
	if (bHotTrack)
	{
		FocusInstead = None;
	}
	LoseFocus(Sender);
	*/
}

void UGUIMultiComponentList::ScrollAlignThumb()
{
	/*
	local float NewPos;
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
	MyScrollBar.GripPos = FClamp(NewPos, 0, 1);
	*/
}

void UGUIMultiComponentList::MakeVisible(float Perc)
{
	/*
	local float MaxTop;
	local float ModResult;
	local int NewTop;
	local int Change;
	if (!bVerticalLayout)
	{
		MaxTop = ItemCount - ItemsPerPage;
		ModResult = MaxTop % NumColumns;
		if (ModResult > 0)
		{
			MaxTop = MaxTop - ModResult + NumColumns;
		}
		NewTop = Round(MaxTop * Perc);
		Change = Abs(Top - NewTop);
		if (Change < NumColumns && Perc < 1)
		{
			Return;
		}
	}
	else
	{
		MaxTop = ItemsPerColumn - ItemsPerPage / NumColumns;
		NewTop = Round(MaxTop * Perc);
	}
	SetTopItem(NewTop);
	*/
}

void UGUIMultiComponentList::SetTopItem(int32 Item)
{
	/*
	local int ModResult;
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
	Top = Max(0, Item);
	OnAdjustTop(Self);
	*/
}

void UGUIMultiComponentList::InternalOnAdjustTop(UGUIComponent* Sender)
{
	/*
	if (!bHotTrack && !ElementVisible(Index))
	{
		FocusInstead = None;
	}
	else
	{
		if (bHotTrack && ElementVisible(Index) && Index < Elements.Length && CanFocusElement(Elements[Index]))
		{
			FocusInstead = Elements[Index];
		}
	}
	*/
}

void UGUIMultiComponentList::WheelDown()
{
	/*
	if (MyScrollBar != None)
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
		Return;
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
		Return;
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
	local int NewIndex;
	if (bVerticalLayout)
	{
		if (Index > 0 && Index % ItemsPerColumn > 0)
		{
			NewIndex = Index - 1;
			if (NewIndex > 0 && !CanFocusElement(Elements[NewIndex]) && NewIndex % ItemsPerColumn > 0)
			{
				NewIndex--;
			}
			NewIndex = Max(0, NewIndex);
			if (CanFocusElement(Elements[NewIndex]))
			{
				SetIndex(NewIndex);
			}
		}
		if (MyScrollBar != None)
		{
			MyScrollBar.AlignThumb();
		}
		Return True;
	}
	if (Index - NumColumns >= 0)
	{
		NewIndex = Index - NumColumns;
		if (NewIndex - NumColumns >= 0 && !CanFocusElement(Elements[NewIndex]))
		{
			NewIndex -= NumColumns;
		}
		NewIndex = Max(0, NewIndex);
		if (CanFocusElement(Elements[NewIndex]))
		{
			SetIndex(NewIndex);
		}
	}
	if (MyScrollBar != None)
	{
		MyScrollBar.AlignThumb();
	}
	*/
	return true;
}

bool UGUIMultiComponentList::Down()
{
	/*
	local int NewIndex;
	if (bVerticalLayout)
	{
		NewIndex = Index + 1;
		if (NewIndex % ItemsPerColumn > 0 && NewIndex < ItemCount)
		{
			if (NewIndex < ItemCount && NewIndex % ItemsPerColumn > 0 && !CanFocusElement(Elements[NewIndex]))
			{
				NewIndex++;
			}
			NewIndex = Min(NewIndex, ItemCount - 1);
			if (CanFocusElement(Elements[NewIndex]))
			{
				SetIndex(NewIndex);
			}
		}
		if (MyScrollBar != None)
		{
			MyScrollBar.AlignThumb();
		}
		Return True;
	}
	if (Index + NumColumns < ItemCount)
	{
		NewIndex = Index + NumColumns;
		if (NewIndex + NumColumns < ItemCount && !CanFocusElement(Elements[NewIndex]))
		{
			NewIndex += NumColumns;
		}
		NewIndex = Min(NewIndex, ItemCount - 1);
		if (CanFocusElement(Elements[NewIndex]))
		{
			SetIndex(NewIndex);
		}
	}
	if (MyScrollBar != None)
	{
		MyScrollBar.AlignThumb();
	}
	*/
	return true;
}

bool UGUIMultiComponentList::MoveRight()
{
	/*
	local int NewIndex;
	local int Avail;
	if (bVerticalLayout)
	{
		NewIndex = Index + ItemsPerColumn;
		if (Index + ItemsPerColumn >= ItemCount)
		{
			Return True;
		}
		if (NewIndex + ItemsPerColumn < ItemCount && !CanFocusElement(Elements[NewIndex]))
		{
			NewIndex += ItemsPerColumn;
		}
		NewIndex = Min(NewIndex, ItemCount - 1);
		if (CanFocusElement(Elements[NewIndex]))
		{
			SetIndex(NewIndex);
		}
		Return True;
	}
	Avail = NumColumns - Index % NumColumns - 1;
	NewIndex = Index + 1;
	if (Avail > 0 && NewIndex < ItemCount && ItemCount > 0)
	{
		if (NewIndex - Index <= Avail && NewIndex < ItemCount && !CanFocusElement(Elements[NewIndex]))
		{
			NewIndex++;
		}
		NewIndex = Min(NewIndex, ItemCount - 1);
		if (CanFocusElement(Elements[NewIndex]))
		{
			SetIndex(NewIndex);
		}
		Return True;
	}
	*/
	return true;
}

bool UGUIMultiComponentList::MoveLeft()
{
	/*
	local int NewIndex;
	local int Avail;
	if (bVerticalLayout)
	{
		NewIndex = Index - ItemsPerColumn;
		if (NewIndex < 0)
		{
			Return True;
		}
		if (NewIndex - ItemsPerColumn >= 0 && !CanFocusElement(Elements[NewIndex]))
		{
			NewIndex -= ItemsPerColumn;
		}
		NewIndex = Max(0, NewIndex);
		if (CanFocusElement(Elements[NewIndex]))
		{
			SetIndex(NewIndex);
		}
		Return True;
	}
	Avail = Index % NumColumns;
	if (Avail > 0 && Index > 0 && ItemCount > 0)
	{
		NewIndex = Index - 1;
		if (Index - NewIndex <= Avail && NewIndex > 0 && !CanFocusElement(Elements[NewIndex]))
		{
			NewIndex--;
		}
		NewIndex = Max(0, NewIndex);
		if (CanFocusElement(Elements[NewIndex]))
		{
			SetIndex(NewIndex);
		}
		Return True;
	}
	*/
	return true;
}

bool UGUIMultiComponentList::NextControl(UGUIComponent* Sender)
{
	/*
	if (Controller.CtrlPressed || Controller.AltPressed || Controller.ShiftPressed || ItemCount > 1 && Index == ItemCount - 1)
	{
		if (MenuOwner != None)
		{
			Return MenuOwner.NextControl(Self);
		}
	}
	if (bVerticalLayout)
	{
		Return Down();
	}
	*/
	return MoveRight();
}

bool UGUIMultiComponentList::PrevControl(UGUIComponent* Sender)
{
	/*
	if (Controller.CtrlPressed || Controller.AltPressed || Controller.ShiftPressed || ItemCount > 1 && Index <= 0)
	{
		if (MenuOwner != None)
		{
			Return MenuOwner.PrevControl(Self);
		}
	}
	if (bVerticalLayout)
	{
		Return Up();
	}
	else
	{
		Return MoveLeft();
	}
	*/
	return false;     //FAKE    /ELiZ
}

bool UGUIMultiComponentList::CanFocusElement(UGUIComponent* elem)
{
	//Return elem != None && elem.MenuState != 4 && GUIListSpacer(elem) == None;
	return false;     //FAKE    /ELiZ
}

void UGUIMultiComponentList::CenterMouse()
{
	/*
	local UGUIComponent* mo;
	mo = Get();
	if (CanFocusElement(mo))
	{
		mo.CenterMouse();
		Return;
	}
	Super::CenterMouse();
	*/
}