// All the original content belonged to the US Army

#include "AA29/Object/Actor/RealHeroAwarenessCylinder/RealHeroAwarenessCylinder.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCRecruiterController/NPCRealHeroController/NPCRealHeroController.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"

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
	ANPCRealHeroController* RHC = nullptr;
	//Super::Touch(Other);
	/*
	if (Cast<AAGP_Pawn>(Other) != nullptr)
	{
		if (Cast<AAGP_Pawn>(Other).IsHumanControlled() && (RHController != nullptr))
		{
			RHController.DimAlpha();
			ForEach AllObjects(ANPCRealHeroController::StaticClass(), RHC)
			{
				if (RHC.Pawn.IsPlayingLIPSincAnim() && (RHC != RHController))
				{
					RHC.Pawn->StopLIPSincAnim();
				}
			}
			RHController.NotifyPlayerPawnSeen(Cast<AAGP_Pawn>(Other));
		}
	}
	*/
}

void ARealHeroAwarenessCylinder::UnTouch(AActor* Other)
{
	//Super::UnTouch(Other);
	if (Cast<AAGP_Pawn>(Other) != nullptr)
	{
		if (Cast<AAGP_Pawn>(Other)->IsHumanControlled() && (RHController != nullptr))
		{
			RHController->BrightenAlpha();
		}
	}
}
