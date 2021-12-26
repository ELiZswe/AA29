// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/SUAVPlane/SUAVPlane.h"
#include "RavenUAV.generated.h"

class AHelicopterDustCloudEffect;
class AAGP_Objective;
class ABaseSmokeEmitter;

UCLASS()
class AA29_API ARavenUAV : public ASUAVPlane
{
	GENERATED_BODY()
public:
	ARavenUAV();

	UPROPERTY(EditAnywhere)								USoundBase*						sndCruising;					//var Sound sndCruising;
	UPROPERTY(EditAnywhere)								USoundBase*						sndHover;						//var Sound sndHover;
	UPROPERTY(EditAnywhere)								AHelicopterDustCloudEffect*		emitDust;						//var HelicopterDustCloudEffect emitDust[16];
	UPROPERTY(EditAnywhere, Category = "LinkDamage")	FName							DamageEvent;					//var(LinkDamage) FName DamageEvent;
	UPROPERTY(EditAnywhere, Category = "LinkDamage")	FName							DamageTag;						//var(LinkDamage) FName DamageTag;
	UPROPERTY(EditAnywhere, Category = "LinkDamage")	FName							KillEvent;						//var(LinkDamage) FName KillEvent;
	UPROPERTY(EditAnywhere, Category = "LinkDamage")	int32							KillHealth;						//var(LinkDamage) int32 KillHealth;
	UPROPERTY()											AAGP_Objective*					DamageObjective;				//var AGP_Objective DamageObjective;
	UPROPERTY()											int32							InitialKillHealth;				//var int32 InitialKillHealth;
	UPROPERTY()											ABaseSmokeEmitter*				SmokeGenerator;					//var AGP_Effects.BaseSmokeEmitter SmokeGenerator;
	UPROPERTY()											bool							bSmokeGeneratorOn;				//var bool bSmokeGeneratorOn;
	UPROPERTY()											float							fpSmokeEndTime;					//var float fpSmokeEndTime;
	UPROPERTY()											float							fpOriginalMaxRotorSpeed;		//var float fpOriginalMaxRotorSpeed;
	UPROPERTY()											FName							SmokeGeneratorAttachmentBone;	//var FName SmokeGeneratorAttachmentBone;
	UPROPERTY()											float							fpElevatorPercent;				//var float fpElevatorPercent;

	/*
	replication
	{
		reliable if ((bNetDirty && (Role == ROLE_Authority)))
			bSmokeGeneratorOn;
	}
	*/

	
	void DisplayDebug(UCanvas* Canvas, const class FDebugDisplayInfo& DebugDisplay, float& YL, float& YPos);
	void Tick(float DeltaTime);
	void PostBeginPlay();
	void UAVTakeOff();
	void UAVTurnLeft();
	void UAVTurnRight();
	void UAVSetThrottle(float fpThrottle);
	void UAVSetAileron(float fpAngle);
	void UAVMoveElevator(float fpDelta);
	void UAVSetElevator(float fpAngle);
	void UAVSetVerticalVelocity(float fpVelocity);
	void UAVSetHorizontalVelocity(float fpVelocity);
	void UAVMoveRudder(float fpRudderIncrement);
	void UAVSetRudder(float fpRudderSetting);
	void UAVGear(bool bGearUp);
	void UAVLand();
	void UAVEnableAutoPilot(bool bEnable);
	float UAVGetRadioStrength();
	void Destroyed();
	void Timer();
	bool UsedBy(APawn* User);
	bool TryToDrive(APawn* p);
	void KDriverEnter(APawn* p);
	bool KDriverLeave(bool bForceLeave);
	//void TakeDamage(int32 Damage, Pawn instigatedBy, Vector HitLocation, Vector Momentum, class<DamageType>  dtDamageType, Actor.BoneInfo Bone, Controller KillerController, Actor ResponsibleActor, Material HitMaterial);
	void HelicopterEngineSmoke(bool bEnable);
	void HelicopterRotorSmoke(bool bEnable);
	void HelicopterCockpitSmoke(bool bEnable);
	void CheckSmokeGenerator();
	void SpawnSmokeGenerator(float fpSmokeLengthSeconds);
	void StartSmokeGenerator();
	void SpawnDestructionEffects();
	void Landed(FVector HitNormal);
	void HelicopterForceRotorMaxToIdleSpeed();
	void HelicopterRestoreRotorMaxSpeed();

};
