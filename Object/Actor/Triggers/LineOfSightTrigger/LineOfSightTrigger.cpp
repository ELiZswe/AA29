// All the original content belonged to the US Army

#include "AA29/Object/Actor/Triggers/LineOfSightTrigger/LineOfSightTrigger.h"

ALineOfSightTrigger::ALineOfSightTrigger()
{
	MaxViewDist = 3000;
	bEnabled = true;
	MaxViewAngle = 15;
	bCollideActors = false;
}

void ALineOfSightTrigger::PostBeginPlay()
{
	//Super::PostBeginPlay();
	//RequiredViewDir = Cos(((float(MaxViewAngle) * 3.141593) / float(180)));
	if (SeenActorTag != "None")
	{
		//ForEach AllActors(Class'Actor', SeenActor, SeenActorTag)
		//{
		//}
	}
}

void ALineOfSightTrigger::PlayerSeesMe(APlayerController* p)
{
	//TriggerEvent(Event, this, p.Pawn);
	bTriggered = true;
}

void ALineOfSightTrigger::Trigger(AActor* Other, APawn* EventInstigator)
{
	bEnabled = true;
}
