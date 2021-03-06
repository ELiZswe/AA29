// All the original content belonged to the US Army

#include "AA29/Object/UIBase/UIControl/UIInvSlotBase/UIInvList/UIInvList.h"
#include "AA29/Object/UIBase/UIFrame/UIFrame.h"
#include "AA29/Object/UIBase/UIScreen/UIScreen.h"
#include "Engine/Canvas.h"

UUIInvList::UUIInvList()
{

}

void UUIInvList::Create(UUIFrame* frame, UUIScreen* screen, int32 pUIID, int32 pUIEvent, int32 pParams)
{
	//Super::Create(frame, screen, pUIID, pUIEvent, pParams);
	iScaledSlotWidth = iSlotWidth;
	iScaledSlotHeight = iSlotHeight;
}

int32 UUIInvList::GetNumItems()
{
	return 0;
}

void UUIInvList::Draw(UCanvas* Canvas)
{
}
void UUIInvList::DrawItem(UCanvas* Canvas, int32 Position, int32 x_pos, int32 y_pos)
{
}

int32 UUIInvList::GetWidth(int32 Index)
{
	return iScaledSlotWidth;
}

int32 UUIInvList::GetHeight(int32 Index)
{
	return iScaledSlotHeight;
}

int32 UUIInvList::GetItemsWidth()
{
	return iItemsWidth;
}

int32 UUIInvList::GetItemsHeight()
{
	return iItemsHeight;
}
void UUIInvList::ScaleControl(UCanvas* Canvas)
{
	if (_bAllowScaling)
	{
		iScaledSlotWidth = iSlotWidth * cFrame->fScaleX;
		iScaledSlotHeight = iSlotHeight * cFrame->fScaleY;
	}
}
