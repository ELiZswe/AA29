// All the original content belonged to the US Army

#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/WarpZoneMarker/WarpZoneMarker.h"

AWarpZoneMarker::AWarpZoneMarker()
{
	bCollideWhenPlacing = false;
	bHiddenEd = true;
}

void AWarpZoneMarker::PostBeginPlay()
{
	/*
	if (markedWarpZone.numDestinations > 1)
	{
		FindTriggerActor();
	}
	Super::PostBeginPlay();
	*/
}

void AWarpZoneMarker::FindTriggerActor()
{
	/*
	local ZoneTrigger Z;
	ForEach AllActors(Class'ZoneTrigger', Z)
	{
		if (Z.Event == markedWarpZone.ZoneTag)
		{
			TriggerActor = Z;
			return;
		}
	}
	*/
}

AActor* AWarpZoneMarker::SpecialHandling(APawn* Other)
{
	/*
	if (Other.Region.Zone == markedWarpZone)
	{
		markedWarpZone.ActorEntered(Other);
	}
	*/
	return this;
}