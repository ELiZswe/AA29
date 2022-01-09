// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AA29/AA29.h"
#include "AA29/MyEnums.h"
#include "SVehicleWheel.generated.h"

UCLASS()
class USVehicleWheel : public UObject
{
	GENERATED_BODY()
public:
	USVehicleWheel();

	UPROPERTY()									Fpointer KContact;							//var const transient pointer KContact;
	UPROPERTY()									float CurrentRotation;						//var float CurrentRotation;
	UPROPERTY()									float SuspensionPosition;					//var float SuspensionPosition;
	UPROPERTY()									float SlipVel;								//var float SlipVel;
	UPROPERTY()									float SlipAngle;							//var float SlipAngle;
	UPROPERTY()									float TrackVel;								//var float TrackVel;
	UPROPERTY()									float SpinVel;								//var float SpinVel;
	UPROPERTY()									FVector WheelAxle;							//var Object.Vector WheelAxle;
	UPROPERTY()									FVector WheelDir;							//var Object.Vector WheelDir;
	UPROPERTY()									float TireLoad;								//var float TireLoad;
	UPROPERTY()									bool bWheelOnGround;						//var bool bWheelOnGround;
	UPROPERTY()									float SupportPivotDistance;					//var float SupportPivotDistance;
	UPROPERTY()									FVector WheelPosition;						//var Object.Vector WheelPosition;
	UPROPERTY()									FAA2_InterpCurve LatSlipFunc;					//var() Object.InterpCurve LatSlipFunc;
	UPROPERTY(EditAnywhere)						FAA2_InterpCurve LongFrictionFunc;				//var() Object.InterpCurve LongFrictionFunc;
	UPROPERTY(EditAnywhere)						EAA2_Axis SupportBoneAxis;						//var() Object.EAxis SupportBoneAxis;
	UPROPERTY(EditAnywhere)						FName SupportBoneName;						//var() name SupportBoneName;
	UPROPERTY(EditAnywhere)						float SuspensionMaxRenderTravel;			//var() float SuspensionMaxRenderTravel;
	UPROPERTY(EditAnywhere)						float HandbrakeFrictionFactor;				//var() float HandbrakeFrictionFactor;
	UPROPERTY(EditAnywhere)						float HandbrakeSlipFactor;					//var() float HandbrakeSlipFactor;
	UPROPERTY(EditAnywhere)						float SuspensionOffset;						//var() float SuspensionOffset;
	UPROPERTY(EditAnywhere)						float SuspensionTravel;						//var() float SuspensionTravel;
	UPROPERTY(EditAnywhere)						float WheelInertia;							//var() float WheelInertia;
	UPROPERTY(EditAnywhere)						float Adhesion;								//var() float Adhesion;
	UPROPERTY(EditAnywhere)						float Restitution;							//var() float Restitution;
	UPROPERTY(EditAnywhere)						float PenOffset;							//var() float PenOffset;
	UPROPERTY(EditAnywhere)						float PenScale;								//var() float PenScale;
	UPROPERTY(EditAnywhere)						float Softness;								//var() float Softness;
	UPROPERTY(EditAnywhere)						float RimWheelRadius;						//var() float RimWheelRadius;
	UPROPERTY(EditAnywhere)						float FlatWheelRadius;						//var() float FlatWheelRadius;
	UPROPERTY(EditAnywhere)						float WheelRadius;							//var() float WheelRadius;
	UPROPERTY(EditAnywhere)						FVector WheelBoneOffset;					//var() Object.Vector WheelBoneOffset;
	UPROPERTY(EditAnywhere)						EAA2_Axis BoneSteerAxis;						//var() Object.EAxis BoneSteerAxis;
	UPROPERTY(EditAnywhere)						EAA2_Axis BoneRollAxis;							//var() Object.EAxis BoneRollAxis;
	UPROPERTY(EditAnywhere)						FName BoneName;								//var() name BoneName;
	UPROPERTY(EditAnywhere)						EVehicleSteerType SteerType;				//var() EVehicleSteerType SteerType;
	UPROPERTY(EditAnywhere)						bool bLeftTrack;							//var() bool bLeftTrack;
	UPROPERTY(EditAnywhere)						bool bTrackWheel;							//var() bool bTrackWheel;
	UPROPERTY(EditAnywhere)						bool bHandbrakeWheel;						//var() bool bHandbrakeWheel;
	UPROPERTY(EditAnywhere)						bool bPoweredWheel;							//var() bool bPoweredWheel;
	UPROPERTY(EditAnywhere)						float ChassisTorque;						//var() float ChassisTorque;
	UPROPERTY(EditAnywhere)						float LatSlip;								//var() float LatSlip;
	UPROPERTY(EditAnywhere)						float LongSlip;								//var() float LongSlip;
	UPROPERTY(EditAnywhere)						float LatFriction;							//var() float LatFriction;
	UPROPERTY(EditAnywhere)						float LongFriction;							//var() float LongFriction;
	UPROPERTY(EditAnywhere)						float DriveForce;							//var() float DriveForce;
	UPROPERTY(EditAnywhere)						float Steer;								//var() float Steer;
};
