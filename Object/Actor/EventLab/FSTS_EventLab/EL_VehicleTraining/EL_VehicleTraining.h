// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/EventLab/FSTS_EventLab/FSTS_EventLab.h"
#include "EL_VehicleTraining.generated.h"

class AVehicleWeapon;
class AAGP_VehicleFactory;
class AAGP_Vehicle; 
class AAGP_VehicleBot;

UCLASS()
class AEL_VehicleTraining : public AFSTS_EventLab
{
	GENERATED_BODY()
public:
	AEL_VehicleTraining();

	UPROPERTY()						FName					InitialStateName;				//var FName InitialStateName;
	UPROPERTY()						AAGP_VehicleBot*		Sgt;							//var AAGP_Vehicle*Bot Sgt;
	UPROPERTY()						AAGP_Vehicle*			Vehicle;						//var AAGP_Vehicle* Vehicle;
	UPROPERTY()						int32					DriverPosition;					//var int32 DriverPosition;
	UPROPERTY()						int32					PassengerPosition;				//var int32 PassengerPosition;
	UPROPERTY()						int32					GunnerPosition;					//var int32 GunnerPosition;
	UPROPERTY()						FString					ActionHintString1;				//var localized FString ActionHintString1;
	UPROPERTY()						FString					ActionHintString2;				//var localized FString ActionHintString2;
	UPROPERTY()						FString					ActionHintString3;				//var localized FString ActionHintString3;
	UPROPERTY()						FString					ActionHintString4;				//var localized FString ActionHintString4;
	UPROPERTY()						TArray<Flipsync>		LipSyncs;						//var TArray<lipsync> LipSyncs;
	UPROPERTY()						TArray<FLipSyncDebug>	LipSyncDebugs;					//var TArray<LipSyncDebug> LipSyncDebugs;
	UPROPERTY()						TArray<AActor*>			TargetIDs;						//var TArray<Actor> TargetIDs;

	void PlayLSMessage(int32 Slot);
	void PostInit();
	void PostPostInit();
	void AssignSgt();
	void AssignVehicle();
	bool AGP_Vehicle_Spawned(AAGP_VehicleFactory* SpawningFactory, AAGP_Vehicle* NewVehicle, FString Parms);
	bool AGP_Vehicle_Entered(AAGP_Vehicle* EntryVehicle, AActor* Controller, FString Parms);
	bool AGP_Vehicle_Exited(AAGP_Vehicle* ExitVehicle, AActor* Controller, FString Parms);
	bool VehiclePosition_Entered(AVehiclePosition* Position, AActor* Controller, FString Parms);
	bool VehiclePosition_Exited(AVehiclePosition* Position, AActor* Controller, FString Parms);
	bool VehicleWeapon_Fire(AVehicleWeapon* NotifyActor, AActor* Instigator, FString Parms);
};
