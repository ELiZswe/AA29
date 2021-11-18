// All the original content belonged to the US Army


#include "Base3pAmmoRound.h"

// Sets default values
ABase3pAmmoRound::ABase3pAmmoRound()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	DrawType = EDrawType::DT_StaticMesh;
}

// Called when the game starts or when spawned
void ABase3pAmmoRound::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABase3pAmmoRound::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABase3pAmmoRound::ShowRound(bool bShouldShowRound)
{
	if (bShouldShowRound)
	{
	//	SetDrawType(EDrawType::DT_StaticMesh);
	}
	else
	{
	//	SetDrawType(EDrawType::DT_None);
	}
}