// All the original content belonged to the US Army

#include "AA29/Object/Actor/RealHeroFadeInCylinder/RealHeroFadeInCylinder.h"

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

// Called when the game starts or when spawned
void ARealHeroFadeInCylinder::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARealHeroFadeInCylinder::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ARealHeroFadeInCylinder::Touch(AActor* Other)
{
	/*
	Super::Touch(Other);
	if (AGP_Pawn(Other) != None)
	{
		if (AGP_Pawn(Other).IsHumanControlled())
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
	if (AGP_Pawn(Other) != None)
	{
		if (AGP_Pawn(Other).IsHumanControlled())
		{
			RHController.DimAlpha();
		}
	}
	*/
}
