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
	/*
	local PlayerController p;
	local Controller A;
	if (bAffectAllPlayers)
	{
		A = Level.ControllerList;
		if (A != None)
		{
			if (A.IsA("PlayerController"))
			{
				PlayerController(A).ClientSetMusic(Song, Transition);
			}
			A = A.nextController;
		}
	}
	else
	{
		p = PlayerController(EventInstigator.Controller);
		if (p == None)
		{
			return;
		}
		p.ClientSetMusic(Song, Transition);
	}
	if (bOnceOnly)
	{
		SetCollision(false, false, false);
		Disable("Trigger");
	}
	*/
}