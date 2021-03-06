// All the original content belonged to the US Army

#include "AA29/Object/Actor/Triggers/SVehicleTrigger/SVehicleTrigger.h"
#include "AA29/Object/Actor/NavigationPoint/NavigationPoint.h"

ASVehicleTrigger::ASVehicleTrigger()
{
	bEnabled = true;
	//bOnlyAffectPawns = true;
	//bHardAttach = true;
	CollisionRadius = 80;
	CollisionHeight = 400;
	bCollideActors = false;
}

void ASVehicleTrigger::PostBeginPlay()
{
	//Super::PostBeginPlay();
	BACKUP_bEnabled = bEnabled;
}

void ASVehicleTrigger::Trigger(AActor* Other, APawn* EventInstigator)
{
	bEnabled = (!bEnabled);
}

bool ASVehicleTrigger::UsedBy(APawn* User)
{
	if (!bEnabled)
	{
		return false;
	}
	//Vehicle(GetOwner())->TryToDrive(User);
	return true;
}

void ASVehicleTrigger::Reset()
{
	Super::Reset();
	bEnabled = BACKUP_bEnabled;
}
