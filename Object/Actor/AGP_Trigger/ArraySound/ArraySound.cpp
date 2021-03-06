// All the original content belonged to the US Army

#include "AA29/Object/Actor/AGP_Trigger/ArraySound/ArraySound.h"

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
	if (Sounds.Num() == 0)
	{
		return;
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
	uint8 Num = 0;
	/*
	Num = Rand(Sounds.Num());
	if (Sounds[Num] == nullptr)
	{
		return;
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
		Level.GetClientPawn().PlaySound(MySound, SoundSlot, SoundVolume, false, SoundRadius);
	}
	else
	{
		PlaySound(MySound, SoundSlot, SoundVolume, false, SoundRadius);
	}
	*/
}

void AArraySound::SetSoundIndex()
{
	SoundIndex++;
	if (SoundIndex >= Sounds.Num())
	{
		SoundIndex = 0;
	}
}
