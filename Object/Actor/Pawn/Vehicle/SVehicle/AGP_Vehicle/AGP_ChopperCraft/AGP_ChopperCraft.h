// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/AGP_Vehicle/AGP_Vehicle.h"
#include "AA29/AA29.h"
#include "AGP_ChopperCraft.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AAGP_ChopperCraft : public AAGP_Vehicle
{
	GENERATED_BODY()
public:
	AAGP_ChopperCraft();


	UPROPERTY()									float LastJumpOutCheck;								//var float LastJumpOutCheck;
	UPROPERTY()									float PushForce;									//var float PushForce;
	UPROPERTY()									bool bNewCopterState;								//var bool bNewCopterState;
	UPROPERTY()									FKRigidBodyState ChassisState;						//var Actor.KRigidBodyState ChassisState;
	UPROPERTY()									FCopterState OldCopState;							//var AGP_ChopperCraft.CopterState OldCopState;
	UPROPERTY()									FCopterState CopState;								//var AGP_ChopperCraft.CopterState CopState;
	UPROPERTY()									float AccumulatedTime;								//var float AccumulatedTime;
	UPROPERTY()									FVector RandTorque;									//var Object.Vector RandTorque;
	UPROPERTY()									FVector RandForce;									//var Object.Vector RandForce;
	UPROPERTY()									float OutputRise;									//var float OutputRise;
	UPROPERTY()									float OutputStrafe;									//var float OutputStrafe;
	UPROPERTY()									float OutputThrust;									//var float OutputThrust;
	UPROPERTY()									bool bHeadingInitialized;							//var bool bHeadingInitialized;
	UPROPERTY()									float TargetPitch;									//var float TargetPitch;
	UPROPERTY()									float TargetHeading;								//var float TargetHeading;
	UPROPERTY()									float CopterMPH;									//var float CopterMPH;
	UPROPERTY(EditAnywhere)						float RandForceInterval;							//var() float RandForceInterval;
	UPROPERTY(EditAnywhere)						float MaxRandForce;									//var() float MaxRandForce;
	UPROPERTY(EditAnywhere)						float StopThreshold;								//var() float StopThreshold;
	UPROPERTY(EditAnywhere)						float RollDamping;									//var() float RollDamping;
	UPROPERTY(EditAnywhere)						float RollTorqueMax;								//var() float RollTorqueMax;
	UPROPERTY(EditAnywhere)						float RollTorqueStrafeFactor;						//var() float RollTorqueStrafeFactor;
	UPROPERTY(EditAnywhere)						float RollTorqueTurnFactor;							//var() float RollTorqueTurnFactor;
	UPROPERTY(EditAnywhere)						float PitchDamping;									//var() float PitchDamping;
	UPROPERTY(EditAnywhere)						float PitchTorqueMax;								//var() float PitchTorqueMax;
	UPROPERTY(EditAnywhere)						float PitchTorqueFactor;							//var() float PitchTorqueFactor;
	UPROPERTY(EditAnywhere)						float MaxYawRate;									//var() float MaxYawRate;
	UPROPERTY(EditAnywhere)						float TurnDamping;									//var() float TurnDamping;
	UPROPERTY(EditAnywhere)						float TurnTorqueMax;								//var() float TurnTorqueMax;
	UPROPERTY(EditAnywhere)						float TurnTorqueFactor;								//var() float TurnTorqueFactor;
	UPROPERTY(EditAnywhere)						float UpDamping;									//var() float UpDamping;
	UPROPERTY(EditAnywhere)						float MaxRiseForce;									//var() float MaxRiseForce;
	UPROPERTY(EditAnywhere)						float LatDamping;									//var() float LatDamping;
	UPROPERTY(EditAnywhere)						float MaxStrafeForce;								//var() float MaxStrafeForce;
	UPROPERTY(EditAnywhere)						float LongDamping;									//var() float LongDamping;
	UPROPERTY(EditAnywhere)						float MaxThrustForce;								//var() float MaxThrustForce;
	UPROPERTY(EditAnywhere)						float UprightDamping;								//var() float UprightDamping;
	UPROPERTY(EditAnywhere)						float UprightStiffness;								//var() float UprightStiffness;

	bool KUpdateState(FKRigidBodyState NewState);
	void SVehicleUpdateParams();
	void SpecialCalcFirstPersonView(APlayerController* PC, AActor*& ViewActor, FVector& CameraLocation, FRotator& CameraRotation);
	void JumpOutCheck();
};
