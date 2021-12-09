// All the original content belonged to the US Army


#include "AA29/Object/Actor/Keypoint/AmbientSound/TriggerSound/TriggerSound.h"

ATriggerSound::ATriggerSound()
{
	bToggle = true;
	nNumLoops = 1;
	bAlwaysRelevant = true;
	//RemoteRole = 1;
}


void ATriggerSound::PreBeginPlay()
{
	/*
	SoundTemp = Sound;
	Sound = nullptr;
	//SoundDuration = nNumLoops * GetSoundDuration(SoundTemp);
	*/
}
void ATriggerSound::BeginPlay()
{
	if (GetNetMode() == ENetMode::NM_Standalone)
	{
		MatchStarting();
	}
}
void ATriggerSound::MatchStarting()
{
	/*
	if (bStartOn)
	{
		Sound = SoundTemp;
	}
	else
	{
		Sound = nullptr;
	}
	if (!bLoopInfinite && Sound != nullptr)
	{
		//SetTimer(SoundDuration, false);
	}
	*/
}
void ATriggerSound::Trigger(AActor* Other, APawn* EventInstigator)
{
	/*
	if (bToggle)
	{
		if (Sound == nullptr)
		{
			Sound = SoundTemp;
		}
		else
		{
			Sound = nullptr;
		}
		if (!bLoopInfinite && Sound != nullptr)
		{
			//SetTimer(SoundDuration, false);
		}
	}
	else
	{
		if (Sound == nullptr)
		{
			Sound = SoundTemp;
			if (!bLoopInfinite)
			{
				//SetTimer(SoundDuration, false);
			}
		}
	}
	*/
}
void ATriggerSound::Timer()
{
	//Sound = nullptr;
}
