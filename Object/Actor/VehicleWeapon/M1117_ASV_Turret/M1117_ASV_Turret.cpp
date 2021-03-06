// All the original content belonged to the US Army

#include "AA29/Object/Actor/VehicleWeapon/M1117_ASV_Turret/M1117_ASV_Turret.h"
#include "Particles/Emitter.h"
#include "AA29/Object/Actor/Emitter/BaseContactEmitter/em_bt_dirt/em_bt_dirt.h"
#include "AA29/Object/Actor/Emitter/BaseMuzzleFlashEmitter/M2MuzzleFlash/M2MuzzleFlash.h"
#include "AA29/Object/Actor/Projectile/BaseProjectile/BaseExplodingProjectile/Proj_MK19Gren/Proj_MK19Gren.h"
#include "AA29/Object/DamageType/AGP_DamageType/ProjectileDamage/ProjectileDamageUS50cal.h"
#include "AA29/Object/Actor/Emitter/BaseMuzzleFlashEmitter/BaseMuzzleFlashEmitter.h"

AM1117_ASV_Turret::AM1117_ASV_Turret()
{
	AltWeaponFireAttachmentBone = "FiftyCal_Muzzle_bone";
	//AltFlashEmitterClass = AM2MuzzleFlash::StaticClass();
	YawBone = "Yaw_bone";
	PitchBone = "Pitch_bone";
	PitchUpLimit = 8000;
	PitchDownLimit = -500;
	WeaponFireAttachmentBone = "MK19_Muzzle_bone";
	WeaponFireOffset = 500;
	RotationsPerSecond = 0.18;
	FireInterval = 0.2;
	AltFireInterval = 0.1;
	//FlashEmitterClass = AM2MuzzleFlash::StaticClass();
	FireSoundClass = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/M249/WeaponsUS_M249_Outdoorfire_Cue.WeaponsUS_M249_Outdoorfire_Cue'"), NULL, LOAD_None, NULL);
	AltFireSoundClass = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/M249/WeaponsUS_M249_Outdoorfire_Cue.WeaponsUS_M249_Outdoorfire_Cue'"), NULL, LOAD_None, NULL);
	//DamageType = AProjectileDamageUS50cal::StaticClass();
	DamageMin = 200;
	DamageMax = 200;
	TraceRange = 16000;
	//ProjectileClass = AProj_MK19Gren::StaticClass();
	ShakeRotMag = FVector(250, 0, 0);
	ShakeRotRate = FVector(2500, 0, 0);
	ShakeRotTime = 0.1;
	//ZeroSizeSize;
	//Mesh = LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AGP_Vehicles/M1117_ASV_Turret.M1117_ASV_Turret'"), NULL, LOAD_None, NULL);
}

/*
State ProjectileFireMode
{
	Function Fire(AController* C)
	{
		SpawnProjectile(ProjectileClass,false);
	}
	Function AltFire(AController* C)
	{
		FlashAltMuzzleFlash();
		if (bAmbientFireSound)
		{
			AmbientSound=AltFireSoundClass;
		}
		else
		{
			PlayOwnedSound(AltFireSoundClass,0,(AltFireSoundVolume / 255),,AltFireSoundRadius,FireSoundPitch,false);
		}
		TraceFire(WeaponFireLocation,WeaponFireRotation);
	}
	simulated Event ClientSpawnHitEffects()
	{
		FVector HitLocation = FVector(0,0,0);
		FVector HitNormal = FVector(0,0,0);
		FVector offset = FVector(0,0,0);
		AActor* HitActor = nullptr;
		UMaterialInstance* HitMaterial = nullptr;
		if (GetWorld()->GetNetMode() == NM_Standalone)
		{
			return;
		}
		offset=(float(20) * Normal((WeaponFireLocation - LastHitLocation)));
		HitActor=Trace(HitLocation,HitNormal,(LastHitLocation - offset),(LastHitLocation + offset),true,,HitMaterial);
		SpawnHitEffects(HitActor,LastHitLocation,HitNormal,HitMaterial);
	}
	simulated Function SpawnHitEffects(AActor* HitActor, Vector HitLocation, Vector HitNormal, UMaterialInstance* HitMaterial)
	{
		APlayerController* PC = nullptr;
		AEmitter* EM = nullptr;
		AEmitter* EMClass = nullptr;
		if (GetWorld()->GetNetMode() == NM_DedicatedServer)
		{
			return;
		}
		PC=Level.GetLocalPlayerController();
		if (HitMaterial != nullptr)
		{
			EMClass=HitMaterial.GetBulletImpactEmitterClass();
			if (EMClass == nullptr)
			{
				EMClass=Aem_bt_dirt::StaticClass();
			}
			EM=Spawn(EMClass,nullptr,,HitLocation,rotator(HitNormal));
		}
		if (EM != nullptr)
		{
			EM.InitEmitters(HitLocation,HitNormal);
			EM.LifeSpan=5;
		}
		if ((PC != nullptr) && (((Instigator != nullptr) && (Instigator.Controller == PC)) || (VSize((PC.ViewTarget.Location - HitLocation)) < float(5000))))
		{
		}
	}
}
*/

void AM1117_ASV_Turret::InitEffects()
{
	Super::InitEffects();
	/*
	if (GetWorld()->GetNetMode() == 1)
	{
		return;
	}
	if (AltFlashEmitterClass != nullptr && AltFlashEmitter == nullptr || AltFlashEmitter.bDeleteMe)
	{
		AltFlashEmitter = Spawn(AltFlashEmitterClass, this);
		if (AltFlashEmitter != nullptr)
		{
			AltFlashEmitter.SetDrawScale(DrawScale);
			if (AltWeaponFireAttachmentBone == "None")
			{
				AltFlashEmitter.SetBase(GetOwner());
			}
			else
			{
				AttachToBone(AltFlashEmitter, AltWeaponFireAttachmentBone);
				AltFlashEmitter.SetRelativeRotation(FRotator(0 - 16384 0));
			}
		}
	}
	*/
}

void AM1117_ASV_Turret::OwnerEffects()
{
	/*
	if (!bIsRepeatingFF)
	{
		if (bIsAltFire)
		{
			ClientPlayForceFeedback(AltFireForce);
		}
		else
		{
			ClientPlayForceFeedback(FireForce);
		}
	}
	ShakeView();
	if (Role < 4)
	{
		if (bIsAltFire)
		{
			FireCountdown = AltFireInterval;
		}
		else
		{
			FireCountdown = FireInterval;
		}
		AimLockReleaseTime = GetWorld()->GetTimeSeconds() + FireCountdown * FireIntervalAimLock;
		if (!bIsAltFire)
		{
			FlashMuzzleFlash();
		}
		else
		{
			FlashAltMuzzleFlash();
		}
		if (!bAmbientFireSound)
		{
			if (bIsAltFire)
			{
				PlaySound(AltFireSoundClass, 0, AltFireSoundVolume / 255, , AltFireSoundRadius, , false);
			}
			else
			{
				PlaySound(FireSoundClass, 0, FireSoundVolume / 255, , FireSoundRadius, , false);
			}
		}
	}
	*/
}

void AM1117_ASV_Turret::FlashAltMuzzleFlash()
{
	/*
	if (GetRemoteRole() == ENetRole::ROLE_MAX)
	{
		AltFlashCount++;
		NetUpdateTime = GetWorld()->GetTimeSeconds() - 1;
	}
	else
	{
		CalcAltWeaponFire();
	}
	if (AltFlashEmitter != nullptr)
	{
		AltMuzzleFlash();
	}
	*/
}

void AM1117_ASV_Turret::CalcAltWeaponFire()
{
	FCoords WeaponBoneCoords = FCoords({});
	FVector CurrentFireOffset = FVector(0,0,0);
	/*
	WeaponBoneCoords = GetBoneCoords(AltWeaponFireAttachmentBone);
	CurrentFireOffset = WeaponFireOffset * FVector(1 0 0) + DualFireOffset * FVector(0 1 0);
	WeaponFireRotation = Vector(CurrentAim) >> Rotation;
	WeaponFireLocation = WeaponBoneCoords.Origin + CurrentFireOffset >> WeaponFireRotation;
	if (bDualIndependantTargeting)
	{
		WeaponFireRotation = CurrentHitLocation - WeaponFireLocation;
	}
	*/
}

void AM1117_ASV_Turret::AltMuzzleFlash()
{
	int32 i = 0;
	if (AltFlashEmitter != nullptr)
	{
		/*
		for (i = 0; i < AltFlashEmitter->EmitterCount(); i++)
		{
			AltFlashEmitter->Emitters[i]->SpawnParticle(AltFlashEmitter->Emitters[i]->iFlashSpawnCount);
		}
		if (Cast<ABaseMuzzleFlashEmitter>(AltFlashEmitter) != nullptr)
		{
			BaseMuzzleFlashEmitter(AltFlashEmitter)->DynamicFlash();
		}
		*/
	}
}
void AM1117_ASV_Turret::CeaseFire(AController* C)
{
	AltFlashCount = 0;
	Super::CeaseFire(C);
}

void AM1117_ASV_Turret::DestroyEffects()
{
	if (AltFlashEmitter != nullptr)
	{
		AltFlashEmitter->Destroy();
	}
	Super::DestroyEffects();
}

void AM1117_ASV_Turret::PostNetReceive()
{
	if (OldAltFlashCount != AltFlashCount)
	{
		FlashAltMuzzleFlash();
		OldAltFlashCount = AltFlashCount;
	}
	Super::PostNetReceive();
}
