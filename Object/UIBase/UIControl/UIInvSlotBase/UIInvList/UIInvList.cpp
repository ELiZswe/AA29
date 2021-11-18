// All the original content belonged to the US Army


#include "AA29/Object/UIBase/UIControl/UIInvSlotBase/UIInvList/UIInvList.h"

UUIInvList::UUIInvList()
{

}


void UUIInvList::Create(UUIFrame* frame, UUIScreen* screen, int32 pUIID, int32 pUIEvent, int32 pParams)
{
	//Super::Create(frame, screen, pUIID, pUIEvent, pParams);
	iScaledSlotWidth = iSlotWidth;
	iScaledSlotHeight = iSlotHeight;
}
void UUIInvList::GetNumItems()
{
	//return 0;
}
void UUIInvList::Draw(UCanvas* Canvas)
{
}
void UUIInvList::DrawItem(UCanvas* Canvas, int32 Position, int32 x_pos, int32 y_pos)
{
}
void UUIInvList::GetWidth(int32 Index)
{
	//return iScaledSlotWidth;
}
void UUIInvList::GetHeight(int32 Index)
{
	//return iScaledSlotHeight;
}
void UUIInvList::GetItemsWidth()
{
	//return iItemsWidth;
}
void UUIInvList::GetItemsHeight()
{
	//return iItemsHeight;
}
void UUIInvList::ScaleControl(UCanvas* Canvas)
{
	/*
	if (_bAllowScaling)
	{
		iScaledSlotWidth = iSlotWidth * cFrame.fScaleX;
		iScaledSlotHeight = iSlotHeight * cFrame.fScaleY;
	}
	*/
}
