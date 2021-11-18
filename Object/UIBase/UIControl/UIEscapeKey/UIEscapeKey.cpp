// All the original content belonged to the US Army


#include "AA29/Object/UIBase/UIControl/UIEscapeKey/UIEscapeKey.h"

UUIEscapeKey::UUIEscapeKey()
{

}

bool UUIEscapeKey::ProcessKeyEvent(int32 Key, int32 Action, float Delta)
{
	/*
	if (!_bEnabled)
	{
		Return False;
	}
	if (Key == 27)
	{
		if (Action == 1)
		{
			bKeyDown = true;
		}
		if (Action == 3 && bKeyDown)
		{
			bKeyDown = False;
			cFrame.Notify(_iUIEvent);
		}
		Return True;
	}
	*/
	return false;
}