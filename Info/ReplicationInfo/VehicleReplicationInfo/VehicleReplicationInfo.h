// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Info/ReplicationInfo/ReplicationInfo.h"
#include "VehicleReplicationInfo.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AVehicleReplicationInfo : public AReplicationInfo
{
	GENERATED_BODY()
public:
	AVehicleReplicationInfo();


	UPROPERTY(Replicated)									float LocationUpdateFrequency;					//var float LocationUpdateFrequency;
	UPROPERTY(Replicated)									float RotationUpdateFrequency;					//var float RotationUpdateFrequency;
	UPROPERTY(Replicated)									float LocationX;								//var float LocationX;
	UPROPERTY(Replicated)									float LocationY;								//var float LocationY;
	UPROPERTY(Replicated)									float LocationZ;								//var float LocationZ;
	UPROPERTY(Replicated)									float RotationPitch;							//var float RotationPitch;
	UPROPERTY(Replicated)									float RotationYaw;								//var float RotationYaw;
	UPROPERTY(Replicated)									float RotationRoll;								//var float RotationRoll;
	UPROPERTY(Replicated)									int32 MyVehicle;								//var Vehicle MyVehicle;
	UPROPERTY(Replicated)									int32 MyVehicleNumber;							//var int MyVehicleNumber;

	//void SetVehicle(Vehicle V);
	void SetVehicleNumber(int32 VehicleNumber);
	void PostNetBeginPlay();
	void Destroyed();
	void UpdateLocation();
	void UpdateRotation();
	void IsVehicleDisabled();
	void GetVehiclePosition();
	void GetVehicleRotation();
	int32 GetVehicleNumber();
	void PlayerEntered(APlayerController* PC, int32 PositionIndex);
	void PlayerLeft(APlayerController* PC);

};

