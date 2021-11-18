// All the original content belonged to the US Army


#include "AA29/Object/Actor/Light/TriggerCorona/TriggerCorona.h"

ATriggerCorona::ATriggerCorona()
{
	bCoronaStartsOn = true;
	//bStatic = false;
	//bAlwaysRelevant = true;
	//bOnlyDirtyReplication = true;
	//bMovable = true;
}

void ATriggerCorona::PreBeginPlay()
{
	bCorona = bCoronaStartsOn;
}

void ATriggerCorona::Trigger(AActor* Other, APawn* EventInstigator)
{
	ToggleCorona();
}

void ATriggerCorona::ToggleCorona()
{
	bCorona = !bCorona;
}

void ATriggerCorona::MatchStarting()
{
	bCorona = bCoronaStartsOn;
}