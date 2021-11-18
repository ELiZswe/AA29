// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AA29/MyStructs.h"
#include "AA29/AA29.h"
#include "VehicleDamageZone.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UVehicleDamageZone : public UObject
{
	GENERATED_BODY()
public:
	UVehicleDamageZone();

	UPROPERTY(EditAnywhere)							float PenetrationPercent;					//var() float PenetrationPercent;
	UPROPERTY(EditAnywhere)							bool bAttachedToRightTread;					//var() bool bAttachedToRightTread;
	UPROPERTY(EditAnywhere)							bool bAttachedToLeftTread;					//var() bool bAttachedToLeftTread;
	UPROPERTY()										AActor* MeshOwner;							//var Actor MeshOwner;
	UPROPERTY(EditAnywhere)							EMeshOwnerType MeshOwnerType;				//var() EMeshOwnerType MeshOwnerType;
	UPROPERTY(EditAnywhere)							uint8 VehiclePositionOwnerIndex;			//var() byte VehiclePositionOwnerIndex;
	UPROPERTY(EditAnywhere)							bool bControlsExternalMesh;					//var() bool bControlsExternalMesh;
	UPROPERTY(EditAnywhere)							bool bInitialSyncToVehicleHealth;			//var() bool bInitialSyncToVehicleHealth;
	UPROPERTY(EditAnywhere)							bool bNoPassDamageToVehicle;				//var() bool bNoPassDamageToVehicle;
	UPROPERTY()										uint8 CurrentDamageState;					//var byte CurrentDamageState;
	UPROPERTY(EditAnywhere)							TArray<FDamageStateStruct> DamageStates;	//var() array<DamageStateStruct> DamageStates;
	UPROPERTY(EditAnywhere)							TArray<uint8> WindowDamageZones;			//var() array<byte> WindowDamageZones;
	UPROPERTY(EditAnywhere)							TArray<uint8> ChildDamageZones;				//var() array<byte> ChildDamageZones;
	UPROPERTY(EditAnywhere)							uint8 WheelNum;								//var() byte WheelNum;
	UPROPERTY(EditAnywhere)							bool bWheelZone;							//var() bool bWheelZone;
	UPROPERTY()										int32 HitPoints;							//var int HitPoints;
	UPROPERTY(EditAnywhere)							int32 MaxHitPoints;							//var() int MaxHitPoints;
	UPROPERTY(EditAnywhere)							float DamageModifier;						//var() float DamageModifier;
	UPROPERTY(EditAnywhere)							int32 ArmorThreshold;						//var() int ArmorThreshold;

	void CopyDamageZones(UVehicleDamageZone* DefaultZone);
	void Destroyed();

};
