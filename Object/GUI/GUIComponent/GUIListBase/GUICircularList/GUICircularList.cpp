// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUICircularList/GUICircularList.h"

UGUICircularList::UGUICircularList()
{
	bCenterInBounds = true;
	bIgnoreBackClick = true;
	bAllowSelectEmpty = true;
	bWrapItems = true;
	bRequiresStyle = true;
	//__OnClick__Delegate = "GUICircularList.InternalOnClick";
}

void UGUICircularList::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	InitComponent(MyController, MyOwner);
	if (bFillBounds)
	{
		bCenterInBounds = False;
	}
	if (!bAllowSelectEmpty && ItemCount == 0)
	{
		Index = -1;
	}
	*/
}
void UGUICircularList::CalculateOffset(float MouseX)
{
	/*
	local float X;
	local float X1;
	local float X2;
	local float Width;
	local float xMod;
	local int i;
	X1 = ClientBounds[0];
	X2 = ClientBounds[2];
	if (MouseX < X1 || MouseX > X2)
	{
		Return - 1;
	}
	Width = X2 - X1;
	if (bCenterInBounds && ItemsPerPage * ItemWidth < Width)
	{
		xMod = Width - ItemsPerPage * ItemWidth / 2;
		X1 += xMod;
		X2 -= xMod;
		if (MouseX >= X1 && MouseX <= X2)
		{
			Return MouseX - X1 / ItemWidth;
		}
		else
		{
			Return - 1;
		}
	}
	if (bFillBounds && ItemsPerPage * ItemWidth < Width)
	{
		xMod = Width - ItemsPerPage * ItemWidth / ItemsPerPage;
		i = 0;
		X = X1;
		if (X <= X2)
		{
			if (MouseX >= X && MouseX <= X + ItemWidth)
			{
				Return i;
			}
			i++;
			X += ItemWidth + xMod;
		}
		Return - 1;
	}
	Return MouseX - X1 / ItemWidth;
	*/
}
int32 UGUICircularList::CalculateIndex(bool bRequireValidIndex)
{
	/*
	local int i;
	local int NewIndex;
	i = Top + CalculateOffset(Controller.MouseX) % ItemCount;
	if (bRequireValidIndex && !IsValidIndex(i))
	{
		i = -1;
	}
	NewIndex = Min(i, ItemCount - 1);
	Return NewIndex;
	*/
	return 0;    //FAKE  /ELiZ
}
void UGUICircularList::InternalOnClick(UGUIComponent* Sender)
{
	/*
	local int NewIndex;
	if (!IsInClientBounds() || ItemsPerPage == 0)
	{
		Return False;
	}
	NewIndex = CalculateIndex(True);
	if (NewIndex < 0 && bIgnoreBackClick)
	{
		Return False;
	}
	if (!bAllowSelectEmpty && !IsValidIndex(NewIndex))
	{
		Return False;
	}
	SetIndex(NewIndex);
	Return True;
	*/
}
void UGUICircularList::WheelUp()
{
	MoveLeft();
}
void UGUICircularList::WheelDown()
{
	MoveRight();
}
void UGUICircularList::MoveLeft()
{
	/*
	local int Last;
	if (ItemCount < 2)
	{
		Return True;
	}
	Last = Index;
	if (Index == 0)
	{
		Index = ItemCount - 1;
	}
	else
	{
		Index--;
	}
	if (Last == Top)
	{
		Top = Index;
	}
	OnChange(Self);
	Return True;
	*/
}
void UGUICircularList::MoveRight()
{
	/*
	local int Last;
	if (ItemCount < 2)
	{
		Return True;
	}
	Last = Index;
	Index++;
	if (Index == ItemCount)
	{
		Index = 0;
	}
	if (Last == Top + ItemsPerPage - 1 % ItemCount)
	{
		Top++;
		if (Top == ItemCount)
		{
			Top = 0;
		}
	}
	OnChange(Self);
	Return True;
	*/
}
void UGUICircularList::home()
{
	/*
	if (ItemCount < 2)
	{
		Return;
	}
	SetIndex(0);
	Top = 0;
	OnChange(Self);
	*/
}
void UGUICircularList::End()
{
	/*
	if (ItemCount < 2)
	{
		Return;
	}
	Top = ItemCount - ItemsPerPage;
	if (Top < 0)
	{
		Top = 0;
	}
	SetIndex(ItemCount - 1);
	*/
}
void UGUICircularList::PgUp()
{
	/*
	local int moveCount;
	local int Last;
	if (ItemCount < 2)
	{
		Return;
	}
	moveCount = 0;
	if (moveCount < ItemsPerPage - 1)
	{
		Last = Index;
		if (Index == 0)
		{
			Index = ItemCount - 1;
		}
		else
		{
			Index--;
		}
		if (Last == Top)
		{
			Top = Index;
		}
		moveCount++;
	}
	OnChange(Self);
	*/
}
void UGUICircularList::PgDown()
{
	/*
	local int moveCount;
	local int Last;
	if (ItemCount < 2)
	{
		Return;
	}
	moveCount = 0;
	if (moveCount < ItemsPerPage - 1)
	{
		Last = Index;
		Index++;
		if (Index == ItemCount)
		{
			Index = 0;
		}
		if (Last == Top + ItemsPerPage - 1 % ItemCount)
		{
			Top++;
			if (Top == ItemCount)
			{
				Top = 0;
			}
		}
		moveCount++;
	}
	OnChange(Self);
	*/
}
bool UGUICircularList::IsValid()
{
	return Index != -1;
}
void UGUICircularList::InternalOnMousePressed(UGUIComponent* Sender, bool IsRepeat)
{
	/*
	local int NewIndex;
	local int i;
	local int j;
	local int k;
	if (!IsInClientBounds() || ItemsPerPage == 0)
	{
		Return;
	}
	if (!IsRepeat && ItemCount > 0)
	{
		NewIndex = CalculateIndex(True);
		if (NewIndex == -1 && bIgnoreBackClick)
		{
			Return;
		}
		LastPressX = Controller.MouseX;
		LastPressY = Controller.MouseY;
		if (NewIndex >= ItemCount)
		{
			NewIndex = ItemCount - 1;
		}
		if (Controller.CtrlPressed && bMultiSelect && SelectedItems.Length == 0 && NewIndex != Index)
		{
			SelectedItems[SelectedItems.Length] = Index;
		}
		if (Controller.ShiftPressed && IsMultiSelect())
		{
			if (LastSelected == -1)
			{
				LastSelected = 0;
			}
			if (!Controller.CtrlPressed)
			{
				for (j = SelectedItems.Length - 1; j >= 0; j--)
				{
					if (SelectedItems[j] != Index)
					{
						SelectedItems.remove(j, 1);
					}
				}
			}
			for (j = Min(LastSelected, NewIndex); j <= Max(LastSelected, NewIndex); j++)
			{
				for (k = 0; k < SelectedItems.Length; k++)
				{
					if (SelectedItems[k] == j)
					{
					}
				}
				if (k == SelectedItems.Length)
				{
					SelectedItems[k] = j;
				}
			}
			Return;
		}
		else
		{
			LastSelected = NewIndex;
			if (IsMultiSelect())
			{
				Index = NewIndex;
			}
		}
		for (i = 0; i < SelectedItems.Length; i++)
		{
			if (SelectedItems[i] == NewIndex)
			{
			}
		}
		if (i < SelectedItems.Length)
		{
			MightRemove = i;
		}
		else
		{
			if (Controller.CtrlPressed && bMultiSelect)
			{
				SelectedItems[i] = NewIndex;
			}
			else
			{
				if (SelectedItems.Length > 0 && MightRemove == -1)
				{
					SelectedItems.remove(0, SelectedItems.Length);
				}
			}
		}
	}
	*/
}
void UGUICircularList::CheckDragSelect()
{
	/*
	local int i;
	i = CalculateIndex(True);
	if (i < 0 && bIgnoreBackClick)
	{
		Return;
	}
	if (i >= ItemCount)
	{
		i = ItemCount - 1;
	}
	SetIndex(i);
	SelectedItems[SelectedItems.Length] = i;
	*/
}
void UGUICircularList::InternalOnDragOver(UGUIComponent* Sender)
{
	/*
	local int NewIndex;
	if (Controller.DropTarget == Self)
	{
		NewIndex = CalculateIndex(True);
		if (NewIndex == -1 && bIgnoreBackClick)
		{
			Return;
		}
		if (NewIndex >= ItemCount)
		{
			DropIndex = -1;
			Return;
		}
		if (Controller.DropSource != Self && SelectedItems.Length > 0)
		{
			SelectedItems.remove(0, SelectedItems.Length);
		}
		DropIndex = NewIndex;
	}
	*/
}