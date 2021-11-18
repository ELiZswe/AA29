// All the original content belonged to the US Army


#include "AA29/AGP_Trigger/ArraySound/ArraySound.h"

AArraySound::AArraySound()
{
	bPlayRandom = true;
	//SoundVolume = 1;
	//SoundRadius = 256;
}


void AArraySound::Trigger(AActor* Other, APawn* EventInstigator)
{
	/*
	TriggerEvent(Event, Other, EventInstigator);
	if (Sounds.Length == 0)
	{
		Return;
	}
	if (bPlayRandom)
	{
		PlayRandomSound();
	}
	else
	{
		PlaySequentialSound();
	}
	*/
}
void AArraySound::UnTrigger(AActor* Other, APawn* EventInstigator)
{
	//Trigger(Other, EventInstigator);
}
void AArraySound::PlayRandomSound()
{
	/*
	local byte Num;
	Num = Rand(Sounds.Length);
	if (Sounds[Num] == None)
	{
		Return;
	}
	PlayMySound(Sounds[Num]);
	*/
}
void AArraySound::PlaySequentialSound()
{
	PlayMySound(Sounds[SoundIndex]);
	SetSoundIndex();
}
void AArraySound::PlayMySound(USoundBase* MySound)
{
	/*
	if (bPlayerSource)
	{
		Level.GetClientPawn().PlaySound(MySound, SoundSlot, SoundVolume, False, SoundRadius);
	}
	else
	{
		PlaySound(MySound, SoundSlot, SoundVolume, False, SoundRadius);
	}
	*/
}
void AArraySound::SetSoundIndex()
{
	/*
	SoundIndex++;
	if (SoundIndex >= Sounds.Length)
	{
		SoundIndex = 0;
	}
	*/
}
