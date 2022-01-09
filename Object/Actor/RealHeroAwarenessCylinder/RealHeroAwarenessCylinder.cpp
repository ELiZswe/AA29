// All the original content belonged to the US Army

#include "AA29/Object/Actor/RealHeroAwarenessCylinder/RealHeroAwarenessCylinder.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCRecruiterController/NPCRealHeroController/NPCRealHeroController.h"

// Sets default values
ARealHeroAwarenessCylinder::ARealHeroAwarenessCylinder()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//bHidden = true;
	//CollisionRadius = 64;
	//CollisionHeight = 72;
	//bCollideActors = true;
	//bUseCylinderCollision = true;
}


void ARealHeroAwarenessCylinder::BeginPlay()
{
	Super::BeginPlay();
	
}


void ARealHeroAwarenessCylinder::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ARealHeroAwarenessCylinder::Touch(AActor* Other)
{
	/*
	local NPCRealHeroController RHC;
	Super::Touch(Other);
	if (AGP_Pawn(Other) != nullptr)
	{
		if (AGP_Pawn(Other).IsHumanControlled() && (RHController != nullptr))
		{
			RHController.DimAlpha();
			ForEach AllObjects(class'AGP.NPCRealHeroController', RHC)
			{
				if (RHC.Pawn.IsPlayingLIPSincAnim() && (RHC != RHController))
				{
					RHC.Pawn.StopLIPSincAnim();
				}
			}
			RHController.NotifyPlayerPawnSeen(AGP_Pawn(Other));
		}
	}
	*/
}

void ARealHeroAwarenessCylinder::UnTouch(AActor* Other)
{
	/*
	Super::UnTouch(Other);
	if (AGP_Pawn(Other) != nullptr)
	{
		if (AGP_Pawn(Other).IsHumanControlled() && (RHController != nullptr))
		{
			RHController.BrightenAlpha();
		}
	}
	*/
}
