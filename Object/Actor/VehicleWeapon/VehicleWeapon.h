// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AA29/AA29.h"
#include "AA29/MyEnums.h"
#include "VehicleWeapon.generated.h"

class AProjectile;
class UaDamageType;
class AGameReplicationInfo;

UCLASS()
class AA29_API AVehicleWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AVehicleWeapon();

	UPROPERTY()							bool							WeaponBoneHack;									//var bool WeaponBoneHack;
	UPROPERTY()							FString							DebugInfo;										//var string DebugInfo;
	//UPROPERTY()							AFireProperties*				SavedFireProperties;							//var Actor.FireProperties SavedFireProperties;
	//UPROPERTY()							AVehicleWeaponAIInfo*			AIInfo;											//var VehicleWeapon.VehicleWeaponAIInfo AIInfo;
	UPROPERTY()							bool							bUseAimErrorTime;								//var bool bUseAimErrorTime;
	UPROPERTY()							bool							bAdjustAfterFire;								//var bool bAdjustAfterFire;
	UPROPERTY()							float							AimErrorTime;									//var float AimErrorTime;
	UPROPERTY()							FVector							NewAimError;									//var Object.Vector NewAimError;
	UPROPERTY()							int32							ScanOffset_Pitch;								//var int ScanOffset_Pitch;
	UPROPERTY()							int32							ScanOffset_Yaw;									//var int ScanOffset_Yaw;
	UPROPERTY()							int32							YawAnimScale;									//var int YawAnimScale;
	UPROPERTY()							int32							YawAnimOffset;									//var int YawAnimOffset;
	UPROPERTY()							int32							PitchAnimScale;									//var int PitchAnimScale;
	UPROPERTY()							int32							PitchAnimOffset;								//var int PitchAnimOffset;
	UPROPERTY()							int32							numWeaponAimAnims;								//var int numWeaponAimAnims;
	UPROPERTY()							FName							WeaponAimAnims;									//var name WeaponAimAnims;
	UPROPERTY(EditAnywhere)				float							ShakeOffsetTime;								//var() float ShakeOffsetTime;
	UPROPERTY(EditAnywhere)				FVector							ShakeOffsetRate;								//var() Object.Vector ShakeOffsetRate;
	UPROPERTY(EditAnywhere)				FVector							ShakeOffsetMag;									//var() Object.Vector ShakeOffsetMag;
	UPROPERTY(EditAnywhere)				float							ShakeRotTime;									//var() float ShakeRotTime;
	UPROPERTY(EditAnywhere)				FVector							ShakeRotRate;									//var() Object.Vector ShakeRotRate;
	UPROPERTY(EditAnywhere)				FVector							ShakeRotMag;									//var() Object.Vector ShakeRotMag;
	UPROPERTY()							AProjectile*					Projectiles;									//var array<Projectile> Projectiles;
	UPROPERTY(EditAnywhere)				AProjectile*					AltFireProjectileClass;							//var() class<Projectile> AltFireProjectileClass;
	UPROPERTY(EditAnywhere)				AProjectile*					ProjectileClass;								//var() class<Projectile> ProjectileClass;
	UPROPERTY()							float							Momentum;										//var float Momentum;
	UPROPERTY()							float							TraceRange;										//var float TraceRange;
	UPROPERTY()							int32							DamageMax;										//var int DamageMax;
	UPROPERTY()							int32							DamageMin;										//var int DamageMin;
	UPROPERTY()							UaDamageType*					DamageType;										//var class<DamageType> DamageType;
	UPROPERTY(EditAnywhere)				FString							AltFireForce;									//var() string AltFireForce;
	UPROPERTY(EditAnywhere)				FString							FireForce;										//var() string FireForce;
	UPROPERTY(EditAnywhere)				USoundBase*						RotatingSound;									//var() Sound RotatingSound;
	UPROPERTY(EditAnywhere)				float							AmbientSoundScaling;							//var() float AmbientSoundScaling;
	UPROPERTY(EditAnywhere)				float							AltFireSoundRadius;								//var() float AltFireSoundRadius;
	UPROPERTY(EditAnywhere)				float							AltFireSoundVolume;								//var() float AltFireSoundVolume;
	UPROPERTY(EditAnywhere)				USoundBase*						AltFireSoundClass;								//var() Sound AltFireSoundClass;
	UPROPERTY(EditAnywhere)				float							FireSoundPitch;									//var() float FireSoundPitch;
	UPROPERTY(EditAnywhere)				float							FireSoundRadius;								//var() float FireSoundRadius;
	UPROPERTY(EditAnywhere)				float							FireSoundVolume;								//var() float FireSoundVolume;
	UPROPERTY(EditAnywhere)				USoundBase*						FireSoundClass;									//var() Sound FireSoundClass;
	UPROPERTY()							uint8							TracerCounter;									//var byte TracerCounter;
	UPROPERTY(EditAnywhere)				uint8							ShotsPerTracer;									//var() byte ShotsPerTracer;
	UPROPERTY()							AProjectile*					TracerClass;									//var class<Projectile> TracerClass;
	//UPROPERTY()							FBoneOffset						shell3p;										//var Object.BoneOffset shell3p;
	//UPROPERTY()							FBoneOffset						Shell1p;										//var Object.BoneOffset Shell1p;
	//UPROPERTY()							FRotationRandomizer				ShellEjectionRandomizer;						//var Object.RotationRandomizer ShellEjectionRandomizer;
	//UPROPERTY()							ABaseShellEmitter*				ShellEjectionEmitter;							//var AGP_Effects.BaseShellEmitter ShellEjectionEmitter;
	//UPROPERTY(EditAnywhere)				ABaseShellEmitter*				ShellEjectionEmitterClass;						//var() class<AGP_Effects.BaseShellEmitter> ShellEjectionEmitterClass;
	//UPROPERTY()							AEmitter*						EffectEmitter;									//var Emitter EffectEmitter;
	//UPROPERTY(EditAnywhere)				AEmitter*						EffectEmitterClass;								//var() class<Emitter> EffectEmitterClass;
	//UPROPERTY()							AEmitter*						FlashEmitter;									//var Emitter FlashEmitter;
	//UPROPERTY(EditAnywhere)				AEmitter*						FlashEmitterClass;								//var() class<Emitter> FlashEmitterClass;
	UPROPERTY(EditAnywhere)				UStaticMesh*					DestroyedWeaponStaticMesh;						//var() StaticMesh DestroyedWeaponStaticMesh;
	//UPROPERTY(EditAnywhere)				AAGP_DestroyedVehicleModels*	DestroyedModelClass;							//var() class<AGP_DestroyedVehicleModels> DestroyedModelClass;
	UPROPERTY()							float							FireCountdown;									//var float FireCountdown;
	UPROPERTY(EditAnywhere)				float							AltFireInterval;								//var() float AltFireInterval;
	UPROPERTY(EditAnywhere)				float							FireInterval;									//var() float FireInterval;
	UPROPERTY()							uint8							Team;											//var byte Team;
	UPROPERTY()							uint8							OldHitCount;									//var byte OldHitCount;
	UPROPERTY()							uint8							HitCount;										//var byte HitCount;
	UPROPERTY()							uint8							OldFlashCount;									//var byte OldFlashCount;
	UPROPERTY()							uint8							FlashCount;										//var byte FlashCount;
	UPROPERTY()							FVector							LastHitLocation;								//var Object.Vector LastHitLocation;
	UPROPERTY()							float							AimTraceRange;									//var float AimTraceRange;
	UPROPERTY()							float							Spread;											//var float Spread;
	UPROPERTY()							FVector							CurrentHitLocation;								//var Object.Vector CurrentHitLocation;
	UPROPERTY()							float							AimLockReleaseTime;								//var float AimLockReleaseTime;
	UPROPERTY(EditAnywhere)				float							FireIntervalAimLock;							//var() float FireIntervalAimLock;
	UPROPERTY()							bool							bCorrectAim;									//var const bool bCorrectAim;
	UPROPERTY(EditAnywhere)				bool							bReflective;									//var() bool bReflective;
	UPROPERTY()							bool							bIsRepeatingFF;									//var bool bIsRepeatingFF;
	UPROPERTY()							bool							bIsAltFire;										//var bool bIsAltFire;
	UPROPERTY(EditAnywhere)				bool							bInheritVelocity;								//var() bool bInheritVelocity;
	UPROPERTY(EditAnywhere)				bool							bAmbientAltFireSound;							//var() bool bAmbientAltFireSound;
	UPROPERTY(EditAnywhere)				bool							bAmbientFireSound;								//var() bool bAmbientFireSound;
	UPROPERTY()							bool							bDoOffsetTrace;									//var bool bDoOffsetTrace;
	UPROPERTY(EditAnywhere)				bool							bAimable;										//var() bool bAimable;
	UPROPERTY()							bool							bForceCenterAim;								//var bool bForceCenterAim;
	UPROPERTY()							bool							bCallInstigatorPostRender;						//var bool bCallInstigatorPostRender;
	UPROPERTY()							bool							bShowChargingBar;								//var bool bShowChargingBar;
	UPROPERTY(EditAnywhere)				bool							bDualIndependantTargeting;						//var() bool bDualIndependantTargeting;
	UPROPERTY()							bool							bOldInstantFire;								//var bool bOldInstantFire;
	UPROPERTY(EditAnywhere)				bool							bInstantFire;									//var() bool bInstantFire;
	UPROPERTY()							bool							bActive;										//var bool bActive;
	UPROPERTY()							bool							bInstantRotation;								//var bool bInstantRotation;
	UPROPERTY()							float							RotationsPerSecond;								//var float RotationsPerSecond;
	UPROPERTY()							FRotator						LastRotation;									//var Object.Rotator LastRotation;
	UPROPERTY()							FVector							WeaponOffset;									//var Object.Vector WeaponOffset;
	UPROPERTY(EditAnywhere)				float							DualFireOffset;									//var() float DualFireOffset;
	UPROPERTY(EditAnywhere)				float							WeaponFireOffset;								//var() float WeaponFireOffset;
	UPROPERTY(EditAnywhere)				FName							ShellEjectionBone;								//var() name ShellEjectionBone;
	UPROPERTY(EditAnywhere)				FName							GunnerAttachmentBone;							//var() name GunnerAttachmentBone;
	UPROPERTY(EditAnywhere)				FName							WeaponFireAttachmentBone;						//var() name WeaponFireAttachmentBone;
	UPROPERTY()							FRotator						WeaponFireRotation;								//var Object.Rotator WeaponFireRotation;
	UPROPERTY()							FVector							WeaponFireLocation;								//var Object.Vector WeaponFireLocation;
	UPROPERTY()							FRotator						CurrentAim;										//var Object.Rotator CurrentAim;
	UPROPERTY(EditAnywhere)				int32							PitchDownLimit;									//var() int PitchDownLimit;
	UPROPERTY(EditAnywhere)				int32							PitchUpLimit;									//var() int PitchUpLimit;
	UPROPERTY(EditAnywhere)				FName							PitchBone;										//var() name PitchBone;
	UPROPERTY()							float							YawConstraintDelta;								//var float YawConstraintDelta;
	UPROPERTY(EditAnywhere)				float							YawEndConstraint;								//var() float YawEndConstraint;
	UPROPERTY(EditAnywhere)				float							YawStartConstraint;								//var() float YawStartConstraint;
	UPROPERTY(EditAnywhere)				FName							YawBone;										//var() name YawBone;

	void LimitPitch(int32 Pitch, FRotator ForwardRotation, int32 WeaponYaw);
	void DisplayDebug(UCanvas* Canvas, const class FDebugDisplayInfo& DebugDisplay, float& YL, float& YPos);
	void SetInstantFire(bool bInstant);
	void SetInstantFireMode(bool bSetInstantFire);
	void ClientToggleFireMode();
	void VerifyVehicleSystemBones(bool bFoundBadBones);
	void PostBeginPlay();
	void PostNetBeginPlay();
	void MatchEnding();
	void ToggleZoom();
	void InitEffects();
	void SetGRI(AGameReplicationInfo* GRI);
	void SetFireRateModifier(float Modifier);
	void SpawnHitEffects(AActor* HitActor, FVector HitLocation, FVector HitNormal, UMaterialInstance* HitMaterial);
	void ClientSpawnHitEffects();
	void ShakeView();
	void ClientStartFire(AController* C, bool bAltFire);
	void ClientStopFire(AController* C, bool bWasAltFire);
	void ClientPlayForceFeedback(FString EffectName);
	void StopForceFeedback(FString EffectName);
	void TakeProjectileImpactDamage(int32 Damage, APawn* instigatedBy, FVector HitLocation, FVector Momentum, UaDamageType* InDamageType, FBoneInfo Bone, AController* KillerController, AActor* ResponsibleActor, UMaterialInstance* HitMaterial);
	void OwnerEffects();
	bool AttemptFire(AController* C, bool bAltFire);
	void AdjustAim(bool bAltFire);
	void BestMode();
	void Fire(AController* C);
	void AltFire(AController* C);
	bool CanAttack(AActor* Other);
	void MaxRange();
	bool ShouldSpawnTracer();
	void SpawnTracer(FVector Start, FRotator Dir);
	void GetSource();
	void DoBulletEffect(AActor* HitActor, UMaterialInstance* HitMaterial, FVector HitLocation, FVector HitNormal, EBulletImpactType BType);
	void SpawnProjectile(AProjectile* ProjClass, bool bAltFire);
	void CeaseFire(AController* C);
	void FlashMuzzleFlash();
	void MuzzleFlash();
	void EjectShell();
	void Destroyed();
	void DestroyEffects();
	void SetTeam(uint8 t);
	void SimulateTraceFire(FVector& Start, FRotator& Dir, FVector& HitLocation, FVector& HitNormal);
	void TraceFire(FVector Start, FRotator Dir);
	void SpawnBeamEffect(FVector Start, FRotator Dir, FVector HitLocation, FVector HitNormal, int32 ReflectNum);
	void CalcWeaponFire();
	void PostNetReceive();
	//void StaticPrecache(LevelInfo L);
	void UpdatePrecacheStaticMeshes();
	void UpdatePrecacheMaterials();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
