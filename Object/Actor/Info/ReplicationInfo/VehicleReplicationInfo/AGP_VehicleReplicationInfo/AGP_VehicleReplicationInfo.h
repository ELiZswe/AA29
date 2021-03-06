// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/VehicleReplicationInfo/VehicleReplicationInfo.h"
#include "AGP_VehicleReplicationInfo.generated.h"

class AAA2_PlayerState;

UCLASS()
class AAGP_VehicleReplicationInfo : public AVehicleReplicationInfo
{
	GENERATED_BODY()
public:
	AAGP_VehicleReplicationInfo();

	UPROPERTY()		float						StatusUpdateFrequency;		//var float StatusUpdateFrequency;
	UPROPERTY()		int32						DriverIndex;				//var int32 DriverIndex;
	UPROPERTY()		int32						GunnerIndex;				//var int32 GunnerIndex;
	UPROPERTY()		bool						bVehicleDisabled;			//var bool bVehicleDisabled;
	UPROPERTY()		bool						bIsPlayerDriveable;			//var bool bIsPlayerDriveable;
	UPROPERTY()		TArray<AAA2_PlayerState*>	Passengers;					//var AAA2_PlayerState* Passengers[8];

	void PostNetBeginPlay();
	void UpdateStatus();
	void Destroyed();
	void PlayerEntered(APlayerController* PC, int32 PositionIndex);
	void PlayerLeft(APlayerController* PC);
	bool IsPlayerDriveable();
	bool IsVehicleDisabled();
	int32 GetPassengerCount();
	AAA2_PlayerState* GetDriver();
	AAA2_PlayerState* GetGunner();
	TArray<AAA2_PlayerState*> GetPassengers();
};
