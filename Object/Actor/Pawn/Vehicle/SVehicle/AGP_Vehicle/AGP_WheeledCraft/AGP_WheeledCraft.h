// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/AGP_Vehicle/AGP_Vehicle.h"
#include "AA29/AA29.h"
#include "AGP_WheeledCraft.generated.h"

class AAnnouncerVoice;
class ABrakelightCorona;
class ADieselSmoke;
class ADustCloudEffect;

UCLASS()
class AAGP_WheeledCraft : public AAGP_Vehicle
{
	GENERATED_BODY()
public:
	AAGP_WheeledCraft();

	UPROPERTY()									float StopwatchTime;							//var float StopwatchTime;
	UPROPERTY()									float StopwatchStopSpeed;						//var float StopwatchStopSpeed;
	UPROPERTY()									float StopwatchStartSpeed;						//var float StopwatchStartSpeed;
	UPROPERTY()									bool bStopwatchPending;							//var bool bStopwatchPending;
	UPROPERTY()									bool bStopwatchRunning;							//var bool bStopwatchRunning;
	UPROPERTY(EditAnywhere)						float COMAdjustScale;							//var() float COMAdjustScale;
	UPROPERTY(EditAnywhere)						float MaxCOMOffset;								//var() float MaxCOMOffset;
	UPROPERTY(EditAnywhere)						bool bAllowCOMAdjust;							//var() bool bAllowCOMAdjust;
	UPROPERTY(EditAnywhere)						float MinAirControlDamping;						//var() float MinAirControlDamping;
	UPROPERTY(EditAnywhere)						float AirRollDamping;							//var() float AirRollDamping;
	UPROPERTY(EditAnywhere)						float AirRollTorque;							//var() float AirRollTorque;
	UPROPERTY(EditAnywhere)						float AirPitchDamping;							//var() float AirPitchDamping;
	UPROPERTY(EditAnywhere)						float AirPitchTorque;							//var() float AirPitchTorque;
	UPROPERTY(EditAnywhere)						float AirTurnTorque;							//var() float AirTurnTorque;
	UPROPERTY()									float OutputPitch;								//var float OutputPitch;
	UPROPERTY()									bool bPushDown;									//var bool bPushDown;
	UPROPERTY(EditAnywhere)						bool bAllowAirControl;							//var() bool bAllowAirControl;
	UPROPERTY()									bool bOldVehicleOnGround;						//var bool bOldVehicleOnGround;
	UPROPERTY()									bool bNewCarState;								//var bool bNewCarState;
	UPROPERTY()									FKRigidBodyState ChassisState;					//var Actor.KRigidBodyState ChassisState;
	UPROPERTY()									FSCarState OldCarState;							//var AGP_WheeledCraft.SCarState OldCarState;
	UPROPERTY()									FSCarState CarState;							//var AGP_WheeledCraft.SCarState CarState;
	UPROPERTY(EditAnywhere)						UMaterialInstance* BrakeLightMaterial;			//var() Material BrakeLightMaterial;
	UPROPERTY()									TArray<ABrakelightCorona*> BrakeLight;			//var BrakelightCorona BrakeLight;
	UPROPERTY(EditAnywhere)						TArray<FVector> BrakeLightOffset;				//var() Object.Vector BrakeLightOffset;
	UPROPERTY(EditAnywhere)						bool bMakeBrakeLights;							//var() bool bMakeBrakeLights;
	UPROPERTY(EditAnywhere)						float RevMeterSizeY;							//var() float RevMeterSizeY;
	UPROPERTY(EditAnywhere)						float RevMeterScale;							//var() float RevMeterScale;
	UPROPERTY(EditAnywhere)						float RevMeterPosY;								//var() float RevMeterPosY;
	UPROPERTY(EditAnywhere)						float RevMeterPosX;								//var() float RevMeterPosX;
	UPROPERTY()									UMaterialInstance* RevMeterMaterial;			//var Material RevMeterMaterial;
	UPROPERTY()									float ActualSteering;							//var float ActualSteering;
	UPROPERTY()									float CarMPH;									//var float CarMPH;
	UPROPERTY()									float EngineRPM;								//var float EngineRPM;
	UPROPERTY()									float TotalSpinVel;								//var float TotalSpinVel;
	UPROPERTY()									float NumPoweredWheels;							//var float NumPoweredWheels;
	UPROPERTY()									bool bIsDriving;								//var bool bIsDriving;
	UPROPERTY()									bool bIsInverted;								//var bool bIsInverted;
	UPROPERTY()									float ForwardVel;								//var float ForwardVel;
	UPROPERTY()									int32 Gear;										//var int Gear;
	UPROPERTY()									bool OutputHandbrake;							//var bool OutputHandbrake;
	UPROPERTY()									float OutputGas;								//var float OutputGas;
	UPROPERTY()									float OutputBrake;								//var float OutputBrake;
	UPROPERTY()									TArray<ADustCloudEffect*> Dust;					//var array<DustCloudEffect> Dust;
	UPROPERTY(EditAnywhere)						float SteerBoneMaxAngle;						//var() float SteerBoneMaxAngle;
	UPROPERTY(EditAnywhere)						EAA2_Axis SteerBoneAxis;						//var() Object.EAxis SteerBoneAxis;
	UPROPERTY(EditAnywhere)						FName SteerBoneName;							//var() name SteerBoneName;
	UPROPERTY(EditAnywhere)						float EngineRPMSoundRange;						//var() float EngineRPMSoundRange;
	UPROPERTY(EditAnywhere)						float IdleRPM;									//var() float IdleRPM;
	UPROPERTY(EditAnywhere)						float EngineInertia;							//var() float EngineInertia;
	UPROPERTY(EditAnywhere)						float HandbrakeThresh;							//var() float HandbrakeThresh;
	UPROPERTY(EditAnywhere)						float StopThreshold;							//var() float StopThreshold;
	UPROPERTY(EditAnywhere)						float TurnDamping;								//var() float TurnDamping;
	UPROPERTY(EditAnywhere)						float SteerSpeed;								//var() float SteerSpeed;
	UPROPERTY(EditAnywhere)						float MaxBrakeTorque;							//var() float MaxBrakeTorque;
	UPROPERTY(EditAnywhere)						float EngineBrakeRPMScale;						//var() float EngineBrakeRPMScale;
	UPROPERTY(EditAnywhere)						float EngineBrakeFactor;						//var() float EngineBrakeFactor;
	UPROPERTY(EditAnywhere)						float LSDFactor;								//var() float LSDFactor;
	UPROPERTY(EditAnywhere)						float ChangeDownPoint;							//var() float ChangeDownPoint;
	UPROPERTY(EditAnywhere)						float ChangeUpPoint;							//var() float ChangeUpPoint;
	UPROPERTY(EditAnywhere)						float TransRatio;								//var() float TransRatio;
	UPROPERTY(EditAnywhere)						int32 NumForwardGears;							//var() int NumForwardGears;
	UPROPERTY(EditAnywhere)						TArray<float> GearRatios;						//var() float GearRatios;
	UPROPERTY(EditAnywhere)						FAA2_InterpCurve TorqueCurve;					//var() Object.InterpCurve TorqueCurve;
	UPROPERTY(EditAnywhere)						FAA2_InterpCurve MaxSteerAngleCurve;			//var() Object.InterpCurve MaxSteerAngleCurve;
	UPROPERTY(EditAnywhere)						float MinBrakeFriction;							//var() float MinBrakeFriction;
	UPROPERTY(EditAnywhere)						float ChassisTorqueScale;						//var() float ChassisTorqueScale;
	UPROPERTY(EditAnywhere)						float FTScale;									//var() float FTScale;
	UPROPERTY(EditAnywhere)						bool bHasExhaust;								//var() bool bHasExhaust;
	UPROPERTY(EditAnywhere)						FName ExhaustBone;								//var() name ExhaustBone;
	UPROPERTY()									TArray<float> dieselCoeffs;						//var array<float> dieselCoeffs;
	UPROPERTY()									ADieselSmoke* dieselPuff;					//var DieselSmoke dieselPuff;
	UPROPERTY()									float puffStateStartTime;						//var float puffStateStartTime;
	UPROPERTY()									EDieselPuffState puffState;						//var DieselPuffState puffState;
	UPROPERTY(EditAnywhere)						float WheelSuspensionMaxRenderTravel;			//var() float WheelSuspensionMaxRenderTravel;
	UPROPERTY(EditAnywhere)						float WheelSuspensionOffset;					//var() float WheelSuspensionOffset;
	UPROPERTY(EditAnywhere)						float WheelSuspensionTravel;					//var() float WheelSuspensionTravel;
	UPROPERTY(EditAnywhere)						float WheelHandbrakeFriction;					//var() float WheelHandbrakeFriction;
	UPROPERTY(EditAnywhere)						float WheelHandbrakeSlip;						//var() float WheelHandbrakeSlip;
	UPROPERTY(EditAnywhere)						float WheelLatFrictionScale;					//var() float WheelLatFrictionScale;
	UPROPERTY(EditAnywhere)						float WheelLongFrictionScale;					//var() float WheelLongFrictionScale;
	UPROPERTY(EditAnywhere)						FAA2_InterpCurve WheelLatSlipFunc;				//var() Object.InterpCurve WheelLatSlipFunc;
	UPROPERTY(EditAnywhere)						float WheelLongSlip;							//var() float WheelLongSlip;
	UPROPERTY(EditAnywhere)						FAA2_InterpCurve WheelLongFrictionFunc;			//var() Object.InterpCurve WheelLongFrictionFunc;
	UPROPERTY(EditAnywhere)						float WheelInertia;								//var() float WheelInertia;
	UPROPERTY(EditAnywhere)						float WheelAdhesion;							//var() float WheelAdhesion;
	UPROPERTY(EditAnywhere)						float WheelRestitution;							//var() float WheelRestitution;
	UPROPERTY(EditAnywhere)						float WheelPenOffset;							//var() float WheelPenOffset;
	UPROPERTY(EditAnywhere)						float WheelPenScale;							//var() float WheelPenScale;
	UPROPERTY(EditAnywhere)						float WheelSoftness;							//var() float WheelSoftness;

	void StopwatchStart();
	void StopwatchReset();
	void StopwatchSet(float EndSpeed, float StartSpeed);
	void DisplayVehicleDebug(UCanvas* Canvas, float& YL, float& YPos);
	void PostNetBeginPlay();
	void PrecacheAnnouncer(AAnnouncerVoice* V, bool bRewardSounds);
	void Destroyed();
	bool KUpdateState(FKRigidBodyState& NewState);
	void updatePuff();
	void SVehicleUpdateParams();
	void DrivingStatusChanged();
	void Tick(float dt);
	float ImpactDamageModifier();
	int32 LimitPitch(int32 Pitch);
};
