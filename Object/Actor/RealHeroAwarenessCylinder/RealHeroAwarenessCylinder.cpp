// All the original content belonged to the US Army

#include "AA29/Object/Actor/RealHeroAwarenessCylinder/RealHeroAwarenessCylinder.h"

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

// Called when the game starts or when spawned
void ARealHeroAwarenessCylinder::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARealHeroAwarenessCylinder::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ARealHeroAwarenessCylinder::Touch(AActor* Other)
{
	/*
	local NPCRealHeroController RHC;
	Super::Touch(Other);
	if (AGP_Pawn(Other) != None)
	{
		if (AGP_Pawn(Other).IsHumanControlled() && (RHController != None))
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
	if (AGP_Pawn(Other) != None)
	{
		if (AGP_Pawn(Other).IsHumanControlled() && (RHController != None))
		{
			RHController.BrightenAlpha();
		}
	}
	*/
}
