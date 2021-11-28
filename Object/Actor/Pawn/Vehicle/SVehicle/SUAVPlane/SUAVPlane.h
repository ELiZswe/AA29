// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/SVehicle.h"
#include "SUAVPlane.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ASUAVPlane : public ASVehicle
{
	GENERATED_BODY()
public:
	ASUAVPlane();

	/*
	replication
	{
		reliable if ((Role == ROLE_Authority))
			uavsUAVState;
	}
	*/

	UPROPERTY(EditAnywhere)				float					UprightStiffness;			//var() float UprightStiffness;
	UPROPERTY(EditAnywhere)				float					UprightDamping;				//var() float UprightDamping;
	UPROPERTY(EditAnywhere)				float					LongDamping;				//var() float LongDamping;
	UPROPERTY(EditAnywhere)				float					LatDamping;					//var() float LatDamping;
	UPROPERTY(EditAnywhere)				float					UpDamping;					//var() float UpDamping;
	UPROPERTY(EditAnywhere)				float					TurnTorqueFactor;			//var() float TurnTorqueFactor;
	UPROPERTY(EditAnywhere)				float					TurnTorqueMax;				//var() float TurnTorqueMax;
	UPROPERTY(EditAnywhere)				float					TurnDamping;				//var() float TurnDamping;
	UPROPERTY(EditAnywhere)				float					MaxYawRate;					//var() float MaxYawRate;
	UPROPERTY(EditAnywhere)				float					PitchTorqueMax;				//var() float PitchTorqueMax;
	UPROPERTY(EditAnywhere)				float					PitchDamping;				//var() float PitchDamping;
	UPROPERTY(EditAnywhere)				float					RollTorqueMax;				//var() float RollTorqueMax;
	UPROPERTY(EditAnywhere)				float					RollDamping;				//var() float RollDamping;
	UPROPERTY(EditAnywhere)				float					RotorSpeedAccelRateMax;		//var() float RotorSpeedAccelRateMax;
	UPROPERTY(EditAnywhere)				float					RoterSpeedDecelRate;		//var() float RoterSpeedDecelRate;
	UPROPERTY(EditAnywhere)				float					RotorSpeedForceFactor;		//var() float RotorSpeedForceFactor;
	UPROPERTY(EditAnywhere)				float					RotorSpeedIdle;				//var() float RotorSpeedIdle;
	UPROPERTY(EditAnywhere)				float					RotorSpeedMax;				//var() float RotorSpeedMax;
	UPROPERTY(EditAnywhere)				FName					TailRotorBoneName;			//var() FName TailRotorBoneName;
	UPROPERTY(EditAnywhere)				EAA2_Axis				TailRotorBoneAxis;			//var() Object.EAxis TailRotorBoneAxis;
	UPROPERTY(EditAnywhere)				FName					RotorBoneName;				//var() FName RotorBoneName;
	UPROPERTY(EditAnywhere)				EAA2_Axis				RotorBoneAxis;				//var() Object.EAxis RotorBoneAxis;
	UPROPERTY(EditAnywhere)				float					RotorBoneSpeedScale;		//var() float RotorBoneSpeedScale;
	UPROPERTY(EditAnywhere)				float					RotorBoneSpeedMax;			//var() float RotorBoneSpeedMax;
	UPROPERTY(EditAnywhere)				float					RotorBoneRotation;			//var float RotorBoneRotation;
	UPROPERTY(EditAnywhere)				UMaterialInstance*		MPHMeterMaterial;			//var Material MPHMeterMaterial;
	UPROPERTY(EditAnywhere)				float					MPHMeterPosX;				//var() float MPHMeterPosX;
	UPROPERTY(EditAnywhere)				float					MPHMeterPosY;				//var() float MPHMeterPosY;
	UPROPERTY(EditAnywhere)				float					MPHMeterScale;				//var() float MPHMeterScale;
	UPROPERTY(EditAnywhere)				float					MPHMeterSizeY;				//var() float MPHMeterSizeY;
	UPROPERTY()							float					RotorSpeed;					//var float RotorSpeed;
	UPROPERTY()							float					CopterMPH;					//var float CopterMPH;
	UPROPERTY()							float					TargetHeading;				//var float TargetHeading;
	UPROPERTY()							float					TargetPitch;				//var float TargetPitch;
	UPROPERTY()							float					OutputThrust;				//var float OutputThrust;
	UPROPERTY()							float					OutputStrafe;				//var float OutputStrafe;
	UPROPERTY()							float					OutputRise;					//var float OutputRise;
	//UPROPERTY()							float					bFollowLookDir;				//var bool bFollowLookDir;
	UPROPERTY()							FUAVState				uavsUAVState;				//var UAVState uavsUAVState;
	UPROPERTY()							FKRigidBodyState		ChassisState;				//var Actor.KRigidBodyState ChassisState;
	UPROPERTY()							float					bNewUAVState;				//var bool bNewUAVState;
};
