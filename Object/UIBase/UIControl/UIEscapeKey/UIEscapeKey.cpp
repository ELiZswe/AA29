// All the original content belonged to the US Army

#include "AA29/Object/UIBase/UIControl/UIEscapeKey/UIEscapeKey.h"
#include "AA29/Object/UIBase/UIFrame/UIFrame.h"

UUIEscapeKey::UUIEscapeKey()
{

}

bool UUIEscapeKey::ProcessKeyEvent(int32 Key, int32 Action, float Delta)
{
	if (!_bEnabled)
	{
		return false;
	}
	if (Key == 27)
	{
		if (Action == 1)
		{
			bKeyDown = true;
		}
		if (Action == 3 && bKeyDown)
		{
			bKeyDown = false;
			cFrame->Notify(_iUIEvent);
		}
		return true;
	}
	return false;
}
