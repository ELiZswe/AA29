// All the original content belonged to the US Army

#include "AA29/Object/Actor/AntiPortalActor/AntiPortalActor.h"
#include "AA29/Object/Actor/Triggers/Trigger/Trigger.h"

// Sets default values
AAntiPortalActor::AAntiPortalActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//DrawType = 11;
	//bNoDelete = true;
	//RemoteRole = 0;
	//bEdShouldSnap = true;
}

/*
State TriggerControl
{
	simulated Event Cast<ATrigger>(AActor* Other, APawn* EventInstigator)
	{
		SetDrawType(DT_None);
	}
	simulated Event UnTrigger(AActor* Other, APawn* EventInstigator)
	{
		SetDrawType(DT_AntiPortal);
	}
}
*/

/*
State TriggerToggle
{
	simulated Event Cast<ATrigger>(AActor* Other, APawn* EventInstigator)
	{
		if (DrawType == 11)
		{
			SetDrawType(DT_None);
		}
		else
		{
			if (DrawType == 0)
			{
				SetDrawType(DT_AntiPortal);
			}
		}
	}
}
*/


void AAntiPortalActor::BeginPlay()
{
	Super::BeginPlay();
	
}


void AAntiPortalActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

