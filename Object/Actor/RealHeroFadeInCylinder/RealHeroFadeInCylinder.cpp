// All the original content belonged to the US Army

#include "AA29/Object/Actor/RealHeroFadeInCylinder/RealHeroFadeInCylinder.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCRecruiterController/NPCRealHeroController/NPCRealHeroController.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"

// Sets default values
ARealHeroFadeInCylinder::ARealHeroFadeInCylinder()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//bHidden = true;
	//CollisionRadius = 256;
	//CollisionHeight = 72;
	//bCollideActors = true;
	//bUseCylinderCollision = true;
}


void ARealHeroFadeInCylinder::BeginPlay()
{
	Super::BeginPlay();
	
}


void ARealHeroFadeInCylinder::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ARealHeroFadeInCylinder::Touch(AActor* Other)
{
	/*
	Super::Touch(Other);
	if (Cast<AAGP_Pawn>(Other) != nullptr)
	{
		if (Cast<AAGP_Pawn>(Other).IsHumanControlled())
		{
			RHController.BrightenAlpha();
		}
	}
	*/
}

void ARealHeroFadeInCylinder::UnTouch(AActor* Other)
{
	/*
	Super::UnTouch(Other);
	if (Cast<AAGP_Pawn>(Other) != nullptr)
	{
		if (Cast<AAGP_Pawn>(Other).IsHumanControlled())
		{
			RHController.DimAlpha();
		}
	}
	*/
}
