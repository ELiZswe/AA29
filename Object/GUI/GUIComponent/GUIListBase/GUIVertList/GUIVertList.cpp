// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIVertList.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"

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
	APlayerController* PC = nullptr;
	float X = 0;
	local float Y;
	if (IsValid())
	{
		PC = PlayerOwner();
		if (PC != nullptr)
		{
			SetTopItem(Index);
			X = ActualLeft() + ActualWidth() / 2;
			Y = Index - Top * ItemHeight;
			PC.ConsoleCommand("SETMOUSE" @ X @ Y);
		}
		return;
	}
	CenterMouse();
	*/
}
int32 UGUIVertList::CalculateIndex(bool bRequireValidIndex)
{
	/*
	int32 i;
	int32 NewIndex;
	i = Top + Controller.MouseY - ClientBounds[1] / ItemHeight;
	if (i >= ItemCount && bRequireValidIndex)
	{
		i = -1;
	}
	NewIndex = Min(i, ItemCount - 1);
	return NewIndex;
	*/
	return 0;   //FAKE /EliZ
}

bool UGUIVertList::InternalOnClick(UGUIComponent* Sender)
{
	/*
	int32 NewIndex;
	if (!IsInClientBounds() || ItemsPerPage == 0)
	{
		return false;
	}
	NewIndex = CalculateIndex();
	SetIndex(NewIndex);
	*/
	return true;
}
bool UGUIVertList::InternalOnKeyType(uint8 &Key, FString Unicode)
{
	return false;
}
void UGUIVertList::WheelUp()
{
	/*
	if (MyScrollBar != nullptr)
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
	if (MyScrollBar != nullptr)
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
bool UGUIVertList::Up()
{
	/*
	if (ItemCount < 2 || Index == 0)
	{
		return true;
	}
	SetIndex(Max(0, Index - 1));
	if (MyScrollBar != nullptr)
	{
		MyScrollBar.AlignThumb();
	}
	*/
	return true;
}
bool UGUIVertList::Down()
{
	/*
	if (ItemCount < 2 || Index == ItemCount - 1)
	{
		return true;
	}
	SetIndex(Min(Index + 1, ItemCount - 1));
	if (MyScrollBar != nullptr)
	{
		MyScrollBar.AlignThumb();
	}
	*/
	return true;
}
void UGUIVertList::home()
{
	/*
	if (ItemCount < 2)
	{
		return;
	}
	SetIndex(0);
	if (MyScrollBar != nullptr)
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
		return;
	}
	SetIndex(ItemCount - 1);
	if (MyScrollBar != nullptr)
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
		return;
	}
	SetIndex(Max(0, Index - ItemsPerPage));
	if (MyScrollBar != nullptr)
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
		return;
	}
	SetIndex(Min(Index + ItemsPerPage, ItemCount - 1));
	if (MyScrollBar != nullptr)
	{
		MyScrollBar.AlignThumb();
	}
	*/
}
