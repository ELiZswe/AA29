// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIScrollZoneBase/GUIVertScrollZone/GUIVertScrollZone.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"

UGUIVertScrollZone::UGUIVertScrollZone()
{

}

bool UGUIVertScrollZone::InternalOnClick(UGUIComponent* Sender)
{
	/*
	float Perc = 0;
	if (!IsInBounds())
	{
		return false;
	}
	Perc = ((Controller.MouseY - ActualTop()) / ActualHeight());
	OnScrollZoneClick(Perc);
	*/
	return true;
}
