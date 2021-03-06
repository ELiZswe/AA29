// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUICircularList/GUICircularList.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"

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
	Super::InitComponent(MyController, MyOwner);
	if (bFillBounds)
	{
		bCenterInBounds = false;
	}
	if (!bAllowSelectEmpty && ItemCount == 0)
	{
		Index = -1;
	}
}

float UGUICircularList::CalculateOffset(float MouseX)
{
	float X = 0;
	float X1 = 0;
	float X2 = 0;
	float Width = 0;
	float xMod = 0;
	int32 i = 0;
	X1 = ClientBounds[0];
	X2 = ClientBounds[2];
	if (MouseX < X1 || MouseX > X2)
	{
		return - 1;
	}
	Width = X2 - X1;
	if (bCenterInBounds && ((float(ItemsPerPage) * ItemWidth) < Width))
	{
		xMod = Width - ItemsPerPage * ItemWidth / 2;
		X1 += xMod;
		X2 -= xMod;
		if (MouseX >= X1 && MouseX <= X2)
		{
			return MouseX - X1 / ItemWidth;
		}
		else
		{
			return - 1;
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
				return i;
			}
			i++;
			X += ItemWidth + xMod;
		}
		return - 1;
	}
	return MouseX - X1 / ItemWidth;
}

int32 UGUICircularList::CalculateIndex(bool bRequireValidIndex)
{
	int32 i = 0;
	int32 NewIndex = 0;
	//i = Top + CalculateOffset(Controller.MouseX) % ItemCount;
	if (bRequireValidIndex && !IsValidIndex(i))
	{
		i = -1;
	}
	NewIndex = FMath::Min(i, ItemCount - 1);
	return NewIndex;
}

bool UGUICircularList::InternalOnClick(UGUIComponent* Sender)
{
	int32 NewIndex = 0;
	if (!IsInClientBounds() || ItemsPerPage == 0)
	{
		return false;
	}
	NewIndex = CalculateIndex(true);
	if (NewIndex < 0 && bIgnoreBackClick)
	{
		return false;
	}
	if (!bAllowSelectEmpty && !IsValidIndex(NewIndex))
	{
		return false;
	}
	SetIndex(NewIndex);
	return true;
}

void UGUICircularList::WheelUp()
{
	MoveLeft();
}

void UGUICircularList::WheelDown()
{
	MoveRight();
}

bool UGUICircularList::MoveLeft()
{
	int32 Last;
	if (ItemCount < 2)
	{
		return true;
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
	OnChange(this);
	return true;
}

bool UGUICircularList::MoveRight()
{
	int32 Last = 0;
	if (ItemCount < 2)
	{
		return true;
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
	OnChange(this);
	return true;
}

void UGUICircularList::home()
{
	if (ItemCount < 2)
	{
		return;
	}
	SetIndex(0);
	Top = 0;
	OnChange(this);
}

void UGUICircularList::End()
{
	if (ItemCount < 2)
	{
		return;
	}
	Top = ItemCount - ItemsPerPage;
	if (Top < 0)
	{
		Top = 0;
	}
	SetIndex(ItemCount - 1);
}

void UGUICircularList::PgUp()
{
	int32 moveCount = 0;
	int32 Last = 0;
	if (ItemCount < 2)
	{
		return;
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
	OnChange(this);
}

void UGUICircularList::PgDown()
{
	int32 moveCount = 0;
	int32 Last = 0;
	if (ItemCount < 2)
	{
		return;
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
		if (float(Last) == (((Top + ItemsPerPage) - 1) % ItemCount))
		{
			Top++;
			if (Top == ItemCount)
			{
				Top = 0;
			}
		}
		moveCount++;
	}
	OnChange(this);
}

bool UGUICircularList::IsValid()
{
	return Index != -1;
}

void UGUICircularList::InternalOnMousePressed(UGUIComponent* Sender, bool IsRepeat)
{
	int32 NewIndex = 0;
	int32 i = 0;
	int32 j = 0;
	int32 k = 0;
	if (!IsInClientBounds() || ItemsPerPage == 0)
	{
		return;
	}
	if (!IsRepeat && ItemCount > 0)
	{
		NewIndex = CalculateIndex(true);
		if (NewIndex == -1 && bIgnoreBackClick)
		{
			return;
		}
		LastPressX = Controller->MouseX;
		LastPressY = Controller->MouseY;
		if (NewIndex >= ItemCount)
		{
			NewIndex = ItemCount - 1;
		}
		if (Controller->CtrlPressed && bMultiSelect && SelectedItems.Num() == 0 && NewIndex != Index)
		{
			SelectedItems[SelectedItems.Num()] = Index;
		}
		if (Controller->ShiftPressed && IsMultiSelect())
		{
			if (LastSelected == -1)
			{
				LastSelected = 0;
			}
			if (!Controller->CtrlPressed)
			{
				for (j = SelectedItems.Num() - 1; j >= 0; j--)
				{
					if (SelectedItems[j] != Index)
					{
						SelectedItems.RemoveAt(j, 1);
					}
				}
			}
			for (j = FMath::Min(LastSelected, NewIndex); j <= FMath::Max(LastSelected, NewIndex); j++)
			{
				for (k = 0; k < SelectedItems.Num(); k++)
				{
					if (SelectedItems[k] == j)
					{
					}
				}
				if (k == SelectedItems.Num())
				{
					SelectedItems[k] = j;
				}
			}
			return;
		}
		else
		{
			LastSelected = NewIndex;
			if (IsMultiSelect())
			{
				Index = NewIndex;
			}
		}
		for (i = 0; i < SelectedItems.Num(); i++)
		{
			if (SelectedItems[i] == NewIndex)
			{
			}
		}
		if (i < SelectedItems.Num())
		{
			MightRemove = i;
		}
		else
		{
			if (Controller->CtrlPressed && bMultiSelect)
			{
				SelectedItems[i] = NewIndex;
			}
			else
			{
				if (SelectedItems.Num() > 0 && MightRemove == -1)
				{
					SelectedItems.RemoveAt(0, SelectedItems.Num());
				}
			}
		}
	}
}

void UGUICircularList::CheckDragSelect()
{
	int32 i = 0;
	i = CalculateIndex(true);
	if (i < 0 && bIgnoreBackClick)
	{
		return;
	}
	if (i >= ItemCount)
	{
		i = ItemCount - 1;
	}
	SetIndex(i);
	SelectedItems[SelectedItems.Num()] = i;
}

void UGUICircularList::InternalOnDragOver(UGUIComponent* Sender)
{
	int32 NewIndex = 0;
	if (Controller->DropTarget == this)
	{
		NewIndex = CalculateIndex(true);
		if (NewIndex == -1 && bIgnoreBackClick)
		{
			return;
		}
		if (NewIndex >= ItemCount)
		{
			DropIndex = -1;
			return;
		}
		if (Controller->DropSource != this && SelectedItems.Num() > 0)
		{
			SelectedItems.RemoveAt(0, SelectedItems.Num());
		}
		DropIndex = NewIndex;
	}
}
