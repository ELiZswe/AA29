// All the original content belonged to the US Army


#include "AA29/Keypoint/AmbientSound/EventSound/EventSound.h"

AEventSound::AEventSound()
{

}


void AEventSound::Trigger(AActor* Other, APawn* EventInstigator)
{
	/*
	_timer = GetSoundDuration(MySound);
	if (bPlayLocal)
	{
		PlaySound(MySound);
	}
	else
	{
		if (EventInstigator != nullptr)
		{
			EventInstigator.PlaySound(MySound);
		}
	}
	if (_Target != nullptr && !bInstantNotify)
	{
		SetTimer(_timer, false);
	}
	else
	{
		Timer();
	}
	*/
}
void AEventSound::Timer()
{
	/*
	if (_Target != nullptr)
	{
		_Target.Notify();
	}
	*/
}