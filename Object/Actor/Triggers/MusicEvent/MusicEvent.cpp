// All the original content belonged to the US Army

#include "AA29/Object/Actor/Triggers/MusicEvent/MusicEvent.h"

AMusicEvent::AMusicEvent()
{
	Transition = EMusicTransition::MTRAN_Fade;
	bAffectAllPlayers = true;
	//bObsolete = true;
}

void AMusicEvent::BeginPlay()
{
	if (Song == "")
	{
		//Song = Level.Song;
	}
	if (bSilence)
	{
	}
}

void AMusicEvent::Trigger(AActor* Other, APawn* EventInstigator)
{
	APlayerController* p = nullptr;
	AController* A = nullptr;
	/*
	if (bAffectAllPlayers)
	{
		for (A=Level.ControllerList; A!=nullptr; A=A.nextController)
		{
			if (A.IsA("PlayerController"))
			{
				PlayerController(A).ClientSetMusic(Song,Transition);
			}
		}
	}
	else
	{
		p=Cast<APlayerController>(EventInstigator.Controller);
		if (p == nullptr)
		{
			return;
		}
		p.ClientSetMusic(Song,Transition);
	}
	if (bOnceOnly)
	{
		SetCollision(false,false,false);
		Disable("Trigger");
	}
	*/
}