// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Pawn/SVehicle/AGP_Vehicle/AGP_Vehicle.h"
#include "AGP_TrackedCraft.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AAGP_TrackedCraft : public AAGP_Vehicle
{
	GENERATED_BODY()
public:
	AAGP_TrackedCraft();

	UPROPERTY(EditAnywhere)						FName RightTreadDamageBone;							//var() name RightTreadDamageBone;
	UPROPERTY(EditAnywhere)						FName RightTreadBone;								//var() name RightTreadBone;
	UPROPERTY(EditAnywhere)						FName LeftTreadDamageBone;							//var() name LeftTreadDamageBone;
	UPROPERTY(EditAnywhere)						FName LeftTreadBone;								//var() name LeftTreadBone;
	UPROPERTY(EditAnywhere)						int32 RightTreadSkinNum;							//var() int RightTreadSkinNum;
	UPROPERTY(EditAnywhere)						int32 LeftTreadSkinNum;								//var() int LeftTreadSkinNum;
	UPROPERTY(EditAnywhere)						FRotator TreadPannerRotation;						//var() Object.Rotator TreadPannerRotation;
	UPROPERTY()									UMaterialInstance* RightTreadPanner;				//var VariableTexPanner RightTreadPanner;
	UPROPERTY()									UMaterialInstance* LeftTreadPanner;					//var VariableTexPanner LeftTreadPanner;
	UPROPERTY(EditAnywhere)						TArray<FName> RightTreadWheels;						//var() array<name> RightTreadWheels;
	UPROPERTY(EditAnywhere)						TArray<FName> LeftTreadWheels;						//var() array<name> LeftTreadWheels;
	UPROPERTY()									float MaxAirSpeed;									//var float MaxAirSpeed;
	UPROPERTY()									float MaxGroundSpeed;								//var float MaxGroundSpeed;
	UPROPERTY()									float RightTreadWheelRoll;							//var float RightTreadWheelRoll;
	UPROPERTY()									float LeftTreadWheelRoll;							//var float LeftTreadWheelRoll;
	UPROPERTY()									float WheelVelocityScale;							//var float WheelVelocityScale;
	UPROPERTY()									float TreadVelocityScale;							//var float TreadVelocityScale;
	UPROPERTY(EditAnywhere)						float MaxPitchSpeed;								//var() float MaxPitchSpeed;
	UPROPERTY()									bool bNewTrackedState;								//var bool bNewTrackedState;
	UPROPERTY()									FKRigidBodyState ChassisState;						//var Actor.KRigidBodyState ChassisState;
	UPROPERTY()									FTrackedCraftState OldTrackedState;					//var AGP_TrackedCraft.TrackedCraftState OldTrackedState;
	UPROPERTY()									FTrackedCraftState TrackedState;					//var AGP_TrackedCraft.TrackedCraftState TrackedState;
	UPROPERTY()									float OutputTurn;									//var float OutputTurn;
	UPROPERTY()									float OutputThrust;									//var float OutputThrust;
	UPROPERTY(EditAnywhere)						float InvertSteeringThrottleThreshold;				//var() float InvertSteeringThrottleThreshold;
	UPROPERTY(EditAnywhere)						float BankDampFactor;								//var() float BankDampFactor;
	UPROPERTY(EditAnywhere)						float BankTorqueFactor;								//var() float BankTorqueFactor;
	UPROPERTY(EditAnywhere)						float PitchDampFactor;								//var() float PitchDampFactor;
	UPROPERTY(EditAnywhere)						float PitchTorqueFactor;							//var() float PitchTorqueFactor;
	UPROPERTY(EditAnywhere)						float SteerDampFactor;								//var() float SteerDampFactor;
	UPROPERTY(EditAnywhere)						float ParkingDampFactor;							//var() float ParkingDampFactor;
	UPROPERTY(EditAnywhere)						float LateralDampFactor;							//var() float LateralDampFactor;
	UPROPERTY(EditAnywhere)						float TurnDampFactor;								//var() float TurnDampFactor;
	UPROPERTY(EditAnywhere)						float ForwardDampFactor;							//var() float ForwardDampFactor;
	UPROPERTY(EditAnywhere)						float MaxSteerTorque;								//var() float MaxSteerTorque;
	UPROPERTY(EditAnywhere)						float MaxThrust;									//var() float MaxThrust;
	UPROPERTY(EditAnywhere)						float UprightDamping;								//var() float UprightDamping;
	UPROPERTY(EditAnywhere)						float UprightStiffness;								//var() float UprightStiffness;
	UPROPERTY(EditAnywhere)						float HoverCheckDist;								//var() float HoverCheckDist;
	UPROPERTY(EditAnywhere)						float HoverPenScale;								//var() float HoverPenScale;
	UPROPERTY(EditAnywhere)						float HoverSoftness;								//var() float HoverSoftness;
	UPROPERTY()									TArray<FVector> ThrusterOffsets;					//var array<Vector> ThrusterOffsets;


	bool KUpdateState(FKRigidBodyState& NewState);
	void PostBeginPlay();
	void PostNetBeginPlay();
	void Destroyed();
	void SVehicleUpdateParams();
	void DamageTread(bool bRightTread);
	void SetupTreads();
	void DestroyTreads();
	void DrivingStatusChanged();
	void Tick(float DeltaTime);
	void KDriverEnter(APawn* p);
	void DriverLeft();
	void ChangeDamageState(uint8 ZoneNum, uint8 NewStateNum);
};
