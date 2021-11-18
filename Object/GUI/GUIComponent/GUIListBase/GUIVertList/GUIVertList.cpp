// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIVertList.h"

UGUIVertList::UGUIVertList()
{
	bRequiresStyle = true;
	//__OnClick__Delegate = "GUIVertList.InternalOnClick";
}




void UGUIVertList::GetItemHeight(UCanvas* C)
{
}
void UGUIVertList::CenterMouse()
{
	/*
	local PlayerController PC;
	local float X;
	local float Y;
	if (IsValid())
	{
		PC = PlayerOwner();
		if (PC != None)
		{
			SetTopItem(Index);
			X = ActualLeft() + ActualWidth() / 2;
			Y = Index - Top * ItemHeight;
			PC.ConsoleCommand("SETMOUSE" @ X @ Y);
		}
		Return;
	}
	CenterMouse();
	*/
}
int32 UGUIVertList::CalculateIndex(bool bRequireValidIndex)
{
	/*
	local int i;
	local int NewIndex;
	i = Top + Controller.MouseY - ClientBounds[1] / ItemHeight;
	if (i >= ItemCount && bRequireValidIndex)
	{
		i = -1;
	}
	NewIndex = Min(i, ItemCount - 1);
	Return NewIndex;
	*/
	return 0;   //FAKE /EliZ
}
void UGUIVertList::InternalOnClick(UGUIComponent* Sender)
{
	/*
	local int NewIndex;
	if (!IsInClientBounds() || ItemsPerPage == 0)
	{
		Return False;
	}
	NewIndex = CalculateIndex();
	SetIndex(NewIndex);
	Return True;
	*/
}
bool UGUIVertList::InternalOnKeyType(uint8 &Key, FString Unicode)
{
	return false;
}
void UGUIVertList::WheelUp()
{
	/*
	if (MyScrollBar != None)
	{
		GUIVertScrollBar(MyScrollBar).WheelUp();
	}
	else
	{
		if (!Controller.CtrlPressed)
		{
			Up();
		}
		else
		{
			PgUp();
		}
	}
	*/
}
void UGUIVertList::WheelDown()
{
	/*
	if (MyScrollBar != None)
	{
		GUIVertScrollBar(MyScrollBar).WheelDown();
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
void UGUIVertList::Up()
{
	/*
	if (ItemCount < 2 || Index == 0)
	{
		Return True;
	}
	SetIndex(Max(0, Index - 1));
	if (MyScrollBar != None)
	{
		MyScrollBar.AlignThumb();
	}
	Return True;
	*/
}
void UGUIVertList::Down()
{
	/*
	if (ItemCount < 2 || Index == ItemCount - 1)
	{
		Return True;
	}
	SetIndex(Min(Index + 1, ItemCount - 1));
	if (MyScrollBar != None)
	{
		MyScrollBar.AlignThumb();
	}
	Return True;
	*/
}
void UGUIVertList::home()
{
	/*
	if (ItemCount < 2)
	{
		Return;
	}
	SetIndex(0);
	if (MyScrollBar != None)
	{
		MyScrollBar.AlignThumb();
	}
	*/
}
void UGUIVertList::End()
{
	/*
	if (ItemCount < 2)
	{
		Return;
	}
	SetIndex(ItemCount - 1);
	if (MyScrollBar != None)
	{
		MyScrollBar.AlignThumb();
	}
	*/
}
void UGUIVertList::PgUp()
{
	/*
	if (ItemCount < 2)
	{
		Return;
	}
	SetIndex(Max(0, Index - ItemsPerPage));
	if (MyScrollBar != None)
	{
		MyScrollBar.AlignThumb();
	}
	*/
}
void UGUIVertList::PgDn()
{
	/*
	if (ItemCount < 2)
	{
		Return;
	}
	SetIndex(Min(Index + ItemsPerPage, ItemCount - 1));
	if (MyScrollBar != None)
	{
		MyScrollBar.AlignThumb();
	}
	*/
}
