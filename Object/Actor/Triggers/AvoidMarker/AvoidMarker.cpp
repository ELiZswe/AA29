// All the original content belonged to the US Army

#include "AA29/Object/Actor/Triggers/AvoidMarker/AvoidMarker.h"

AAvoidMarker::AAvoidMarker()
{
	TeamNum = 255;
	CollisionRadius = 100;
}

void AAvoidMarker::Touch(AActor* Other)
{
	/*
	if ((Cast<APawn>(Other) != nullptr) && RelevantTo(Cast<APawn>(Other)))
	{
		Cast<APawn>(Other).Controller.FearThisSpot(this);
	}
	*/
}

bool AAvoidMarker::RelevantTo(APawn* p)
{
	//return ((Cast<AAIController>(p.Controller) != nullptr) && (((p.Controller.PlayerReplicationInfo == nullptr) || (p.Controller.PlayerReplicationInfo.Team == nullptr)) || (p.Controller.PlayerReplicationInfo.Team.TeamIndex != TeamNum)));
	return false;    //FAKE   /EliZ
}

void AAvoidMarker::StartleBots()
{
	APawn* p = nullptr;
	/*
	ForEach CollidingActors(Class'Pawn', p, CollisionRadius)
	{
		if (RelevantTo(p))
		{
			Cast<AaAIController>(p.Controller).Startle(this);
		}
	}
	*/
}
