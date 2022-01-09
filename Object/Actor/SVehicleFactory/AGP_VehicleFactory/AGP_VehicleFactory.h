// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/SVehicleFactory/SVehicleFactory.h"
#include "AGP_VehicleFactory.generated.h"

class AVehicle;

UCLASS()
class AAGP_VehicleFactory : public ASVehicleFactory
{
	GENERATED_BODY()
public:
	AAGP_VehicleFactory();

	UPROPERTY(EditAnywhere)				float RespawnTime;					//var() float RespawnTime;
	UPROPERTY(EditAnywhere)				float PreSpawnEffectTime;			//var() float PreSpawnEffectTime;
	UPROPERTY(EditAnywhere)				bool bReverseBlueTeamDirection;		//var() bool bReverseBlueTeamDirection;
	UPROPERTY()							bool bActive;						//var bool bActive;
	UPROPERTY(EditAnywhere)				bool bNeverActivate;				//var() bool bNeverActivate;
	UPROPERTY()							bool bPreSpawn;						//var bool bPreSpawn;
	UPROPERTY(EditAnywhere)				int32 TeamNum;						//var() int TeamNum;
	UPROPERTY()							AVehicle* LastSpawned;				//var Vehicle LastSpawned;
	UPROPERTY(EditAnywhere)				FName SpawnedVehicleTag;			//var() name SpawnedVehicleTag;

	void BeginPlay();

	void PostBeginPlay();
	void UpdatePrecacheMaterials();
	void PostNetBeginPlay();
	void Activate(uint8 t);
	void Deactivate();
	void VehicleDestroyed(AVehicle* V);
	void SpawnVehicle();
	bool ValidateSpawnLocation(float Radius);
	void SpawnBuildEffect();
	void Timer();
	void Trigger(AActor* Other, APawn* EventInstigator);
};
