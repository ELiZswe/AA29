// All the original content belonged to the US Army


#include "AA29/AGP_USMortarTeam/AGP_USMortarTeam.h"

// Sets default values
AAGP_USMortarTeam::AAGP_USMortarTeam()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAGP_USMortarTeam::BeginPlay()
{
	Super::BeginPlay();
	iMaxVehicleRoundsPerMission = 12;
	iMaxHERoundsPerMission = 12;
	iMaxSmokeRoundsPerMission = 2;
	iMaxVehicleRoundsAvailable = 64;
	iMaxHERoundsAvailable = 96;
	iMaxSmokeRoundsAvailable = 16;
	iCurrentHERoundsAvailable = 96;
	iCurrentSmokeRoundsAvailable = 16;
	iCurrentVehicleRoundsAvailable = 64;
	iNumberOfTubes = 2;
	fpSkillLevel = 80;
	//bProp = true;
	//bHidden = true;
}

// Called every frame
void AAGP_USMortarTeam::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void AAGP_USMortarTeam::Reset()
{
	UE_LOG(LogTemp, Log, TEXT("Resetting mortar team"));
	iCurrentHERoundsAvailable = iMaxHERoundsPerMission;
	iCurrentSmokeRoundsAvailable = iMaxSmokeRoundsPerMission;
	iCurrentVehicleRoundsAvailable = iMaxVehicleRoundsAvailable;
}
