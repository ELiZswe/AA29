// All the original content belonged to the US Army

#include "AA29/Object/Actor/HudOverlay/HudOverlay.h"

// Sets default values
AHudOverlay::AHudOverlay()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//bHidden = true;
	//RemoteRole = ROLE_None;
}


void AHudOverlay::BeginPlay()
{
	Super::BeginPlay();
	
}


void AHudOverlay::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AHudOverlay::Render(UCanvas* C)
{
}

void AHudOverlay::Destroyed()
{
	/*
	if (HUD(Owner) != nullptr)
	{
		HUD(Owner).RemoveHudOverlay(this);
	}
	*/
	Super::Destroyed();
}
