// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AA29/MyEnums.h"
#include "AA29/AA29.h"
#include "VehicleDamageZone.generated.h"

UCLASS()
class UVehicleDamageZone : public UObject
{
	GENERATED_BODY()
public:
	UVehicleDamageZone();

	UPROPERTY(EditAnywhere)			float						PenetrationPercent;
	UPROPERTY(EditAnywhere)			bool						bAttachedToRightTread;
	UPROPERTY(EditAnywhere)			bool						bAttachedToLeftTread;
	UPROPERTY()						AActor*						MeshOwner;
	UPROPERTY(EditAnywhere)			EMeshOwnerType				MeshOwnerType;
	UPROPERTY(EditAnywhere)			uint8						VehiclePositionOwnerIndex;
	UPROPERTY(EditAnywhere)			bool						bControlsExternalMesh;
	UPROPERTY(EditAnywhere)			bool						bInitialSyncToVehicleHealth;
	UPROPERTY(EditAnywhere)			bool						bNoPassDamageToVehicle;
	UPROPERTY()						uint8						CurrentDamageState;
	UPROPERTY(EditAnywhere)			TArray<FDamageStateStruct>	DamageStates;
	UPROPERTY(EditAnywhere)			TArray<uint8>				WindowDamageZones;
	UPROPERTY(EditAnywhere)			TArray<uint8>				ChildDamageZones;
	UPROPERTY(EditAnywhere)			uint8						WheelNum;
	UPROPERTY(EditAnywhere)			bool						bWheelZone;
	UPROPERTY()						int32						HitPoints;
	UPROPERTY(EditAnywhere)			int32						MaxHitPoints;
	UPROPERTY(EditAnywhere)			float						DamageModifier;
	UPROPERTY(EditAnywhere)			int32						ArmorThreshold;

	void CopyDamageZones(UVehicleDamageZone* DefaultZone);
	void Destroyed();
};
