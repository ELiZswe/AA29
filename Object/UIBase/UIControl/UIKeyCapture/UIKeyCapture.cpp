// All the original content belonged to the US Army


#include "AA29/Object/UIBase/UIControl/UIKeyCapture/UIKeyCapture.h"

UUIKeyCapture::UUIKeyCapture()
{

}

bool UUIKeyCapture::ProcessKeyEvent(int32 Key, int32 Action, float Delta)
{
	if (!_bEnabled)
	{
		return false;
	}
	if (Key == 9 || Key == 38 || Key == 40)
	{
		return false;
	}
	return true;
}