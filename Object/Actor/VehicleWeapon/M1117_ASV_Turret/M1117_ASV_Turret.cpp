// All the original content belonged to the US Army

#include "AA29/Object/Actor/VehicleWeapon/M1117_ASV_Turret/M1117_ASV_Turret.h"
#include "Particles/Emitter.h"

AM1117_ASV_Turret::AM1117_ASV_Turret()
{
	AltWeaponFireAttachmentBone = "FiftyCal_Muzzle_bone";
	//AltFlashEmitterClass = class'AGP_Vehicles.M2MuzzleFlash';
	YawBone = "Yaw_bone";
	PitchBone = "Pitch_bone";
	PitchUpLimit = 8000;
	PitchDownLimit = -500;
	WeaponFireAttachmentBone = "MK19_Muzzle_bone";
	WeaponFireOffset = 500;
	RotationsPerSecond = 0.18;
	FireInterval = 0.2;
	AltFireInterval = 0.1;
	//FlashEmitterClass = class'AGP_Vehicles.M2MuzzleFlash';
	FireSoundClass = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/M249/WeaponsUS_M249_Outdoorfire_Cue.WeaponsUS_M249_Outdoorfire_Cue'"), NULL, LOAD_None, NULL);
	AltFireSoundClass = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/M249/WeaponsUS_M249_Outdoorfire_Cue.WeaponsUS_M249_Outdoorfire_Cue'"), NULL, LOAD_None, NULL);
	//DamageType = Class'AGP_Inventory.ProjectileDamageUS50cal';
	DamageMin = 200;
	DamageMax = 200;
	TraceRange = 16000;
	//ProjectileClass = Class'AGP_Inventory.Proj_MK19Gren';
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
		if (Level.NetMode == NM_Standalone)
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
		local class<Emitter>  EMClass;
		if (Level.NetMode == NM_DedicatedServer)
		{
			return;
		}
		PC=Level.GetLocalPlayerController();
		if (HitMaterial != nullptr)
		{
			EMClass=HitMaterial.GetBulletImpactEmitterClass();
			if (EMClass == nullptr)
			{
				EMClass=Class'AGP_Effects.em_bt_dirt';
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
	/*
	InitEffects();
	if (Level.NetMode == 1)
	{
		return;
	}
	if (AltFlashEmitterClass != nullptr && AltFlashEmitter == nullptr || AltFlashEmitter.bDeleteMe)
	{
		AltFlashEmitter = Spawn(AltFlashEmitterClass, Self);
		if (AltFlashEmitter != nullptr)
		{
			AltFlashEmitter.SetDrawScale(DrawScale);
			if (AltWeaponFireAttachmentBone == "None")
			{
				AltFlashEmitter.SetBase(Owner);
			}
			else
			{
				AttachToBone(AltFlashEmitter, AltWeaponFireAttachmentBone);
				AltFlashEmitter.SetRelativeRotation(rot(0 - 16384 0));
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
		AimLockReleaseTime = Level.TimeSeconds + FireCountdown * FireIntervalAimLock;
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
				PlaySound(AltFireSoundClass, 0, AltFireSoundVolume / 255, , AltFireSoundRadius, , False);
			}
			else
			{
				PlaySound(FireSoundClass, 0, FireSoundVolume / 255, , FireSoundRadius, , False);
			}
		}
	}
	*/
}

void AM1117_ASV_Turret::FlashAltMuzzleFlash()
{
	/*
	if (Role == 4)
	{
		AltFlashCount++;
		NetUpdateTime = Level.TimeSeconds - 1;
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
	/*
	local Object.Coords WeaponBoneCoords;
	local Object.Vector CurrentFireOffset;
	WeaponBoneCoords = GetBoneCoords(AltWeaponFireAttachmentBone);
	CurrentFireOffset = WeaponFireOffset * vect(1 0 0) + DualFireOffset * vect(0 1 0);
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
		if (BaseMuzzleFlashEmitter(AltFlashEmitter) != nullptr)
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
