// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIScrollZoneBase/GUIHorzScrollZone/GUIHorzScrollZone.h"

UGUIHorzScrollZone::UGUIHorzScrollZone()
{

}

bool UGUIHorzScrollZone::InternalOnClick(UGUIComponent* Sender)
{
	/*
	float Perc = 0;
	if (!IsInBounds())
	{
		return false;
	}
	Perc = ((Controller.MouseX - ActualLeft()) / ActualWidth());
	OnScrollZoneClick(Perc);
	*/
	return true;
}