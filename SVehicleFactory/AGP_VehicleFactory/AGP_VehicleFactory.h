// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/SVehicleFactory/SVehicleFactory.h"
#include "AGP_VehicleFactory.generated.h"



UCLASS()
class AA29_API AAGP_VehicleFactory : public ASVehicleFactory
{
	GENERATED_BODY()
public:
	AAGP_VehicleFactory();

	UPROPERTY(EditAnywhere)											FName SpawnedVehicleTag;							//var() name SpawnedVehicleTag;
	//UPROPERTY()														AVehicle* LastSpawned;								//var Vehicle LastSpawned;
	UPROPERTY(EditAnywhere)											int32 TeamNum;										//var() int TeamNum;
	UPROPERTY()														bool bPreSpawn;										//var bool bPreSpawn;
	UPROPERTY(EditAnywhere)											bool bNeverActivate;								//var() bool bNeverActivate;
	UPROPERTY()														bool bActive;										//var bool bActive;
	UPROPERTY(EditAnywhere)											bool bReverseBlueTeamDirection;						//var() bool bReverseBlueTeamDirection;
	UPROPERTY(EditAnywhere)											float PreSpawnEffectTime;							//var() float PreSpawnEffectTime;
	UPROPERTY(EditAnywhere)											float RespawnTime;									//var() float RespawnTime;
};
