// All the original content belonged to the US Army

#include "AA29/Object/Actor/Brush/Volume/BlockingVolume/PlayerBlockingVolume/TriggeredPlayerBlockingVolume/TriggeredPlayerBlockingVolume.h"

ATriggeredPlayerBlockingVolume::ATriggeredPlayerBlockingVolume()
{
	//bStatic = false;
	//bWorldGeometry = false;
	//bProjTarget = true;
}

void ATriggeredPlayerBlockingVolume::PostBeginPlay()
{
	/*
	Super::PostBeginPlay();
	if (bBlockOnStart)
	{
		ActivatePlayerBlocking();
	}
	else
	{
		DeactivatePlayerBlocking();
	}
	*/
}

void ATriggeredPlayerBlockingVolume::DeactivatePlayerBlocking()
{
	//bBlockActors = false;
	//bBlockPlayers = false;
}

void ATriggeredPlayerBlockingVolume::ActivatePlayerBlocking()
{
	//bBlockActors = true;
	//bBlockPlayers = true;
}

void ATriggeredPlayerBlockingVolume::Touch(AActor* Other)
{
	/*
	if ((Pawn(Other) != nullptr) && Pawn(Other).Controller.IsA("HumanController"))
	{
		if (EventLab != nullptr)
		{
			EventLab.ActorNotify(Self, ET_Exit, Other);
		}
	}
	*/
}

void ATriggeredPlayerBlockingVolume::UnTouch(AActor* Other)
{
	/*
	if ((Pawn(Other) != nullptr) && Pawn(Other).Controller.IsA("HumanController"))
	{
		if (EventLab != nullptr)
		{
			EventLab.ActorNotify(Self, ET_Damaged, Other);
		}
	}
	*/
}

void ATriggeredPlayerBlockingVolume::Bump(AActor* Other)
{
	/*
	if (((AGP_Pawn(Other) == nullptr) || (!AGP_Pawn(Other).IsHumanControlled())) || ((!bBlockPlayers) && (!bBlockActors)))
	{
		return;
	}
	*/
}
