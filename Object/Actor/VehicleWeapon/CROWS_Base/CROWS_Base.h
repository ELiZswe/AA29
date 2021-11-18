// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/VehicleWeapon/VehicleWeapon.h"
#include "CROWS_Base.generated.h"

class ABodyPanel;
/**
 * 
 */
UCLASS()
class AA29_API ACROWS_Base : public AVehicleWeapon
{
	GENERATED_BODY()
public:
	ACROWS_Base();


	/*
	const RadianToURot = 10430.3783505;
	const CROWS_SYSSTATUS_CAMERA = 1;
	const CROWS_SYSSTATUS_CAMERALENS = 2;
	const CROWS_SYSSTATUS_LASER = 4;
	const CROWS_SYSSTATUS_PITCHSERVO = 8;
	const CROWS_SYSSTATUS_YAWSERVO = 0x10;
	const CROWS_SYSSTATUS_M2WEAPON = 0x20;
	const CROWS_SYSSTATUS_MK19WEAPON = 0x40;
	*/

	UPROPERTY()							int32						WeaponAimAdjust;							//var int WeaponAimAdjust;
	UPROPERTY()							FRotator					NewCurrentAim;								//var Object.Rotator NewCurrentAim;
	UPROPERTY()							int32						iSystemStatus;								//var int iSystemStatus;
	UPROPERTY()							FRotator						rotRotationAtServoFailure;				//var Object.Rotator rotRotationAtServoFailure;
	UPROPERTY()							int32						LastDamageIndex;							//var int LastDamageIndex;
	UPROPERTY()							int32						DamageIndex;								//var int DamageIndex;
	UPROPERTY()							TArray<UMaterialInstance*>	DamagedTexture;								//var array<Texture> DamagedTexture;
	UPROPERTY()							TArray<int32>				DamageThreshholds;							//var array<int> DamageThreshholds;
	UPROPERTY()							int32						iTotalDamage;								//var int iTotalDamage;
	UPROPERTY()							int32						iWeaponHealth;								//var int iWeaponHealth;
	UPROPERTY()							int32						iPitchServoHealth;							//var int iPitchServoHealth;
	UPROPERTY()							int32						iYawServoHealth;							//var int iYawServoHealth;
	UPROPERTY()							int32						iLaserHealth;								//var int iLaserHealth;
	UPROPERTY()							int32						iCameraLensHealth;							//var int iCameraLensHealth;
	UPROPERTY()							int32						iCameraHealth;								//var int iCameraHealth;
	UPROPERTY()							FName						RootBone;									//var name RootBone;
	UPROPERTY()							FName						CameraBaseBone;								//var name CameraBaseBone;
	UPROPERTY()							FName						CameraViewBone;								//var name CameraViewBone;
	UPROPERTY()							FName						WeaponFireBaseBone;							//var name WeaponFireBaseBone;
	UPROPERTY()							FName						WeaponFireBone;								//var name WeaponFireBone;
	UPROPERTY()							ABodyPanel*					BodyPanels;									//var AGP.BodyPanel BodyPanels;
	UPROPERTY()							TArray<FName>				StartBodyPanelBones;						//var() array<name> StartBodyPanelBones;
	UPROPERTY()							TArray<UStaticMesh*>		StartBodyPanelMeshes;						//var() array<StaticMesh> StartBodyPanelMeshes;
	UPROPERTY()							TArray<FString>				asBodyPanelClasses;							//var array<String> asBodyPanelClasses;
	UPROPERTY()							UMaterialInstance*			HUDAmmoIcon;								//var Texture HUDAmmoIcon;
	UPROPERTY()							float						ServoSoundRadius;							//var float ServoSoundRadius;
	UPROPERTY()							float						SustainUDDuration;							//var float SustainUDDuration;
	UPROPERTY()							float						ServoAtkUDDurationLeft;						//var float ServoAtkUDDurationLeft;
	UPROPERTY()							float						ServoVolumeUD;								//var float ServoVolumeUD;
	UPROPERTY()							USoundBase*					ServoSusUD;									//var Sound ServoSusUD;
	UPROPERTY()							USoundBase*					ServoRelUD;									//var Sound ServoRelUD;
	UPROPERTY()							USoundBase*					ServoAtkUD;									//var Sound ServoAtkUD;
	UPROPERTY()							USoundBase*					PlayingServoUD;								//var Sound PlayingServoUD;
	UPROPERTY()							int32						GunFailureClicks;							//var int GunFailureClicks;
	UPROPERTY()							float						HissTriggerCount;							//var float HissTriggerCount;
	UPROPERTY()							float						HissCount;									//var float HissCount;
	UPROPERTY()							float						HissDecrementDelay;							//var float HissDecrementDelay;
	UPROPERTY()							USoundBase*					BarrelHiss;									//var Sound BarrelHiss;
	UPROPERTY()							USoundBase*					GunFailureSound;							//var Sound GunFailureSound;
	UPROPERTY()							bool						bCasingQueued;								//var bool bCasingQueued;
	UPROPERTY()							USoundBase*					BulletCasingRing;							//var Sound BulletCasingRing;
	UPROPERTY()							USoundBase*					CameraFailureSound;							//var Sound CameraFailureSound;
	UPROPERTY()							USoundBase*					DryFireSound;								//var Sound DryFireSound;
	UPROPERTY()							USoundBase*					ServoDamagedSus;							//var Sound ServoDamagedSus;
	UPROPERTY()							float						CasingDelayDeviation;						//var float CasingDelayDeviation;
	UPROPERTY()							float						CasingSoundMinDelay;						//var float CasingSoundMinDelay;
	UPROPERTY()							float						SustainLRDuration;							//var float SustainLRDuration;
	UPROPERTY()							float						ServoAtkLRDurationLeft;						//var float ServoAtkLRDurationLeft;
	UPROPERTY()							float						ServoVolumeLR;								//var float ServoVolumeLR;
	UPROPERTY()							USoundBase*					ServoSusLR;									//var Sound ServoSusLR;
	UPROPERTY()							USoundBase*					ServoRelLR;									//var Sound ServoRelLR;
	UPROPERTY()							USoundBase*					ServoAtkLR;									//var Sound ServoAtkLR;
	UPROPERTY()							USoundBase*					PlayingServoLR;								//var Sound PlayingServoLR;
	UPROPERTY()							float						MinSustain;									//var float MinSustain;
	UPROPERTY()							FName						CameraPitchBone;							//var name CameraPitchBone;
	UPROPERTY()							FVector						ClientWeaponFireLocation;					//var Object.Vector ClientWeaponFireLocation;
	UPROPERTY()							float						ChargeTime;									//var float ChargeTime;
	UPROPERTY()							USoundBase*					ChargeSound;								//var Sound ChargeSound;
	UPROPERTY()							FName						ChargeTimerName;							//var name ChargeTimerName;
	UPROPERTY()							int32						InitialVehicleYaw;							//var int InitialVehicleYaw;
	UPROPERTY()							FRotator					LaseOffset;									//var Object.Rotator LaseOffset;
	UPROPERTY()							int32						RangePitchOffset;							//var int RangePitchOffset;
	UPROPERTY()							float						BulletVelocity;								//var float BulletVelocity;
	UPROPERTY()							float						GunPitchOffset;								//var float GunPitchOffset;
	UPROPERTY()							float						LasePitchOffset;							//var float LasePitchOffset;
	UPROPERTY()							float						OldLaseDistance;							//var float OldLaseDistance;
	UPROPERTY()							float						LaseDistance;								//var float LaseDistance;
	UPROPERTY()							FRotator					RotateCamera;								//var Object.Rotator RotateCamera;
	UPROPERTY()							bool						bHideGun;									//var bool bHideGun;
	UPROPERTY()							bool						bCharged;									//var bool bCharged;
	UPROPERTY()							FString						AmmoType;									//var string AmmoType;
	UPROPERTY()							int32						Ammo;										//var int Ammo;

	void WeaponFailureSounds();
	void SpawnProjectile(AProjectile* ProjClass, bool bAltFire);
	void DecrementHiss();
	void PlayHiss();
	void FinishHiss();
	void OwnerEffects();
	void ShakeView();
	void ChargeWeapon();
	void SetLaseDistance(float inLaseDistance);
	void HideGun(bool bHide);
	void ChargeTimer();
	void Tick(float DeltaTime);
	void SetLaseOffset(FRotator newOffset);
	void CalcWeaponFire();
	void PlayCasingRing();
	void PostNetBeginPlay();
	void PostBeginPlay();
	void Destroyed();
	void AttachBodyPanels();
	bool IsPitchServoFunctional();
	bool IsYawServoFunctional();
	void GetFailedServoPitch();
	void GetFailedServoYaw();
	void TakeProjectileImpactDamage(int32 Damage, APawn* instigatedBy, FVector HitLocation, FVector Momentum, UaDamageType* InDamageType, FBoneInfo Bone, AController* KillerController, AActor* ResponsibleActor, UMaterialInstance* HitMaterial);
	//void TakeDamage(int Damage, Pawn instigatedBy, Object.Vector HitLocation, Object.Vector Momentum, class<DamageType>  DamageType, optional Actor.BoneInfo Bone, optional Controller KillerController, optional Actor ResponsibleActor, optional Material HitMaterial);
	
};
