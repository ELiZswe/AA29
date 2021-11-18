// All the original content belonged to the US Army


#include "AA29/AntiPortalActor/AntiPortalActor.h"

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

// Called when the game starts or when spawned
void AAntiPortalActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAntiPortalActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

/*
State TriggerControl
{
	simulated Event UnTrigger (Actor Other, Pawn EventInstigator)
	{
		SetDrawType(11);
	}
	simulated Event Trigger (Actor Other, Pawn EventInstigator)
	{
		SetDrawType(0);
	}
}
State TriggerToggle
{
	simulated Event Trigger (Actor Other, Pawn EventInstigator)
	{
		if (DrawType == 11)
		{
			SetDrawType(0);
		}
		else
		{
			if (DrawType == 0)
			{
				SetDrawType(11);
			}
		}
	}
}
*/