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
	if ((Pawn(Other) != None) && RelevantTo(Pawn(Other)))
	{
		Pawn(Other).Controller.FearThisSpot(Self);
	}
	*/
}

bool AAvoidMarker::RelevantTo(APawn* p)
{
	//return ((AIController(p.Controller) != None) && (((p.Controller.PlayerReplicationInfo == None) || (p.Controller.PlayerReplicationInfo.Team == None)) || (p.Controller.PlayerReplicationInfo.Team.TeamIndex != TeamNum)));
	return false;    //FAKE   /EliZ
}

void AAvoidMarker::StartleBots()
{
	/*
	local Pawn p;
	ForEach CollidingActors(Class'Pawn', p, CollisionRadius)
	{
		if (RelevantTo(p))
		{
			AIController(p.Controller).Startle(Self);
		}
	}
	*/
}