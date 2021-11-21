// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIScrollZoneBase/GUIScrollZoneBase.h"

UGUIScrollZoneBase::UGUIScrollZoneBase()
{
	StyleName = "ScrollZone";
	RenderWeight = 0.25;
	bAcceptsInput = true;
	bCaptureMouse = true;
	bNeverFocus = true;
	bRepeatClick = true;
	bRequiresStyle = true;
	//OnClick = GUIScrollZoneBase.InternalOnClick;
}


void UGUIScrollZoneBase::OnScrollZoneClick(float Delta)
{
}

bool UGUIScrollZoneBase::InternalOnClick(UGUIComponent* Sender)
{
	return false;
}