// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIVertList.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIScrollBarBase/GUIVertScrollBar/GUIVertScrollBar.h"
#include "Engine/Canvas.h"

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
	APlayerController* PC = nullptr;
	float X = 0;
	float Y = 0;
	if (IsValid())
	{
		PC = PlayerOwner();
		if (PC != nullptr)
		{
			SetTopItem(Index);
			X = ActualLeft(0,false) + ActualWidth(0,false) / 2;
			Y = Index - Top * ItemHeight;
			//PC->ConsoleCommand("SETMOUSE" + X + Y);
		}
		return;
	}
	Super::CenterMouse();
}

int32 UGUIVertList::CalculateIndex(bool bRequireValidIndex)
{
	int32 i = 0;
	int32 NewIndex = 0;
	i = Top + Controller->MouseY - ClientBounds[1] / ItemHeight;
	if (i >= ItemCount && bRequireValidIndex)
	{
		i = -1;
	}
	NewIndex = FMath::Min(i, ItemCount - 1);
	return NewIndex;
}

bool UGUIVertList::InternalOnClick(UGUIComponent* Sender)
{
	int32 NewIndex = 0;
	if (!IsInClientBounds() || ItemsPerPage == 0)
	{
		return false;
	}
	NewIndex = CalculateIndex(false);
	SetIndex(NewIndex);
	return true;
}

bool UGUIVertList::InternalOnKeyType(uint8 &Key, FString Unicode)
{
	return false;
}

void UGUIVertList::WheelUp()
{
	if (MyScrollBar != nullptr)
	{
		Cast<UGUIVertScrollBar>(MyScrollBar)->WheelUp();
	}
	else
	{
		if (!Controller->CtrlPressed)
		{
			Up();
		}
		else
		{
			PgUp();
		}
	}
}

void UGUIVertList::WheelDown()
{
	if (MyScrollBar != nullptr)
	{
		Cast<UGUIVertScrollBar>(MyScrollBar)->WheelDown();
	}
	else
	{
		if (!Controller->CtrlPressed)
		{
			Down();
		}
		else
		{
			PgDn();
		}
	}
}

bool UGUIVertList::Up()
{
	if (ItemCount < 2 || Index == 0)
	{
		return true;
	}
	SetIndex(FMath::Max(0, Index - 1));
	if (MyScrollBar != nullptr)
	{
		MyScrollBar->AlignThumb();
	}
	return true;
}

bool UGUIVertList::Down()
{
	if (ItemCount < 2 || Index == ItemCount - 1)
	{
		return true;
	}
	SetIndex(FMath::Min(Index + 1, ItemCount - 1));
	if (MyScrollBar != nullptr)
	{
		MyScrollBar->AlignThumb();
	}
	return true;
}

void UGUIVertList::home()
{
	if (ItemCount < 2)
	{
		return;
	}
	SetIndex(0);
	if (MyScrollBar != nullptr)
	{
		MyScrollBar->AlignThumb();
	}
}

void UGUIVertList::End()
{
	if (ItemCount < 2)
	{
		return;
	}
	SetIndex(ItemCount - 1);
	if (MyScrollBar != nullptr)
	{
		MyScrollBar->AlignThumb();
	}
}

void UGUIVertList::PgUp()
{
	if (ItemCount < 2)
	{
		return;
	}
	SetIndex(FMath::Max(0, Index - ItemsPerPage));
	if (MyScrollBar != nullptr)
	{
		MyScrollBar->AlignThumb();
	}
}

void UGUIVertList::PgDn()
{
	if (ItemCount < 2)
	{
		return;
	}
	SetIndex(FMath::Min(Index + ItemsPerPage, ItemCount - 1));
	if (MyScrollBar != nullptr)
	{
		MyScrollBar->AlignThumb();
	}
}
