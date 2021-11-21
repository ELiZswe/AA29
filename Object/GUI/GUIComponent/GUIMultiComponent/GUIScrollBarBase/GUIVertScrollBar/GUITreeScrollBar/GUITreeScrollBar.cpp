// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIScrollBarBase/GUIVertScrollBar/GUITreeScrollBar/GUITreeScrollBar.h"

UGUITreeScrollBar::UGUITreeScrollBar()
{

}

void UGUITreeScrollBar::SetList(UGUIListBase* InList)
{
	/*
	Super::SetList(InList);
	List = GUITreeList(InList);
	if (List != None)
	{
		ItemCount = List.VisibleCount;
	}
	*/
}

void UGUITreeScrollBar::UpdateGripPosition(float NewPos)
{
	/*
	if (List != None)
	{
		List.MakeVisible(NewPos);
		ItemCount = List.VisibleCount;
	}
	GripPos = NewPos;
	CurPos = int((float((ItemCount - ItemsPerPage)) * GripPos));
	PositionChanged(CurPos);
	*/
}

void UGUITreeScrollBar::MoveGripBy(int32 items)
{
	/*
	int32 NewItem = 0;
	if (List != None)
	{
		NewItem = (List.Top + items);
		ItemCount = List.VisibleCount;
		if (ItemCount > 0)
		{
			List.SetTopItem(NewItem);
		}
	}
	(CurPos += items);
	if (CurPos < 0)
	{
		CurPos = 0;
	}
	if (CurPos > (ItemCount - ItemsPerPage))
	{
		CurPos = (ItemCount - ItemsPerPage);
	}
	if ((List == None) && (ItemCount > 0))
	{
		AlignThumb();
	}
	PositionChanged(CurPos);
	*/
}

void UGUITreeScrollBar::AlignThumb()
{
	/*
	float NewPos = 0;
	if (List != None)
	{
		BigStep = (List.ItemsPerPage * Step);
		if (List.ItemCount == 0)
		{
			NewPos = 0;
		}
		else
		{
			NewPos = (float(List.Top) / float((List.VisibleCount - List.ItemsPerPage)));
		}
	}
	else
	{
		if (ItemCount == 0)
		{
			NewPos = 0;
		}
		else
		{
			NewPos = (float(CurPos) / float((ItemCount - ItemsPerPage)));
		}
	}
	GripPos = FClamp(NewPos, 0, 1);
	*/
}
