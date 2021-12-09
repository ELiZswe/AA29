// All the original content belonged to the US Army


#include "AA29/Object/Actor/AGP_DestroyedVehicleModels/AGP_DestroyedVehicleModels.h"

// Sets default values
AAGP_DestroyedVehicleModels::AAGP_DestroyedVehicleModels()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//DrawType = 8;
	//bCollideActors = true;
	//bBlockActors = true;
	//bBlockKarma = true;
}

// Called when the game starts or when spawned
void AAGP_DestroyedVehicleModels::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAGP_DestroyedVehicleModels::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AAGP_DestroyedVehicleModels::MatchEnding()
{
	//Super::MatchEnding();
	//Destroy();
}
