// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIHorzList/GUIHorzList.h"

UGUIHorzList::UGUIHorzList()
{
	bRequiresStyle = true;
	//__OnClick__Delegate = "GUIHorzList.InternalOnClick";
}

int32 UGUIHorzList::CalculateIndex(bool bRequireValidIndex)
{
	/*
	local int i;
	local int NewIndex;
	i = Top + Controller.MouseX - ClientBounds[0] / ItemWidth;
	if (i >= ItemCount && bRequireValidIndex)
	{
		i = -1;
	}
	NewIndex = Min(i, ItemCount - 1);
	return NewIndex;
	*/
	return 0;     //FAKE  /ELiZ
}

bool UGUIHorzList::InternalOnClick(UGUIComponent* Sender)
{
	/*
	local int NewIndex;
	if (!IsInClientBounds() || ItemsPerPage == 0)
	{
		return false;
	}
	NewIndex = CalculateIndex();
	SetIndex(NewIndex);
	*/
	return true;
}

bool UGUIHorzList::InternalOnKeyType(uint8 &Key, FString Unicode)
{
	return false;
}

void UGUIHorzList::WheelUp()
{
	/*
	if (MyScrollBar != None)
	{
		GUIHorzScrollBar(MyScrollBar).WheelUp();
	}
	else
	{
		if (!Controller.CtrlPressed)
		{
			ScrollLeft();
		}
		else
		{
			PgUp();
		}
	}
	*/
}
void UGUIHorzList::WheelDown()
{
	/*
	if (MyScrollBar != None)
	{
		GUIHorzScrollBar(MyScrollBar).WheelDown();
	}
	else
	{
		if (!Controller.CtrlPressed)
		{
			ScrollRight();
		}
		else
		{
			PgDn();
		}
	}
	*/
}
bool UGUIHorzList::MoveLeft()
{
	/*
	if (ItemCount < 2 || Index == 0)
	{
		return true;
	}
	Index = Max(0, Index - 1);
	if (Index < Top || Index > Top + ItemsPerPage)
	{
		Top = Index;
		MyScrollBar.AlignThumb();
	}
	*/
	return true;
}
bool UGUIHorzList::MoveRight()
{
	/*
	if (ItemCount < 2 || Index == ItemCount - 1)
	{
		return true;
	}
	Index = Min(Index + 1, ItemCount - 1);
	if (Index < Top)
	{
		Top = Index;
		MyScrollBar.AlignThumb();
	}
	else
	{
		if (Index >= Top + ItemsPerPage)
		{
			Top = Index - ItemsPerPage + 1;
			MyScrollBar.AlignThumb();
		}
	}
	*/
	return true;
}
void UGUIHorzList::ScrollLeft()
{
	MoveLeft();
}
void UGUIHorzList::ScrollRight()
{
	MoveRight();
}
void UGUIHorzList::home()
{
	/*
	if (ItemCount < 2)
	{
		Return;
	}
	SetIndex(0);
	Top = 0;
	MyScrollBar.AlignThumb();
	*/
}
void UGUIHorzList::End()
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
	MyScrollBar.AlignThumb();
	*/
}
void UGUIHorzList::PgUp()
{
	/*
	if (ItemCount < 2)
	{
		Return;
	}
	Index -= ItemsPerPage;
	if (Index < 0)
	{
		Index = 0;
	}
	if (Top + ItemsPerPage <= Index)
	{
		Top = Index;
	}
	else
	{
		if (Index + ItemsPerPage < Top)
		{
			Top = Index;
		}
		else
		{
			if (Index < Top)
			{
				SetTopItem(Top - ItemsPerPage);
			}
		}
	}
	SetIndex(Index);
	MyScrollBar.AlignThumb();
	*/
}
void UGUIHorzList::PgDn()
{
	/*
	if (ItemCount < 2)
	{
		Return;
	}
	Index += ItemsPerPage;
	if (Index >= ItemCount)
	{
		Index = ItemCount - 1;
	}
	if (Index < Top)
	{
		Top = Index;
	}
	else
	{
		if (Index - Top - ItemsPerPage >= ItemsPerPage)
		{
			SetTopItem(Index);
		}
		else
		{
			if (Index - Top >= ItemsPerPage)
			{
				SetTopItem(Top + ItemsPerPage);
			}
		}
	}
	SetIndex(Index);
	MyScrollBar.AlignThumb();
	*/
}
