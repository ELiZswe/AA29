// All the original content belonged to the US Army

#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/WarpZoneMarker/WarpZoneMarker.h"
#include "AA29/Object/Actor/Info/ZoneInfo/WarpZoneInfo/WarpZoneInfo.h"
#include "AA29/Object/Actor/Triggers/Trigger/ZoneTrigger/ZoneTrigger.h"

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
	AZoneTrigger* Z = nullptr;
	/*
	ForEach AllActors(AZoneTrigger::StaticClass(), Z)
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
