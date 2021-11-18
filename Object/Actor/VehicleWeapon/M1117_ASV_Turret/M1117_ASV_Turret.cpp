// All the original content belonged to the US Army


#include "AA29/Object/Actor/VehicleWeapon/M1117_ASV_Turret/M1117_ASV_Turret.h"

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
	//FireSoundClass = Sound'S_AA2_WeaponsUS.M249.WeaponsUS_M249_Outdoorfire';
	//AltFireSoundClass = Sound'S_AA2_WeaponsUS.M249.WeaponsUS_M249_Outdoorfire';
	//DamageType = Class'AGP_Inventory.ProjectileDamageUS50cal';
	DamageMin = 200;
	DamageMax = 200;
	TraceRange = 16000;
	//ProjectileClass = Class'AGP_Inventory.Proj_MK19Gren';
	ShakeRotMag = FVector(250, 0, 0);
	ShakeRotRate = FVector(2500, 0, 0);
	ShakeRotTime = 0.1;
	//	\\AIInfo = ;
	//Mesh = SkeletalMesh'A_AGP_Vehicles.M1117_ASV_Turret';
}

/*
State ProjectileFireMode
{
	simulated Function SpawnHitEffects(Actor HitActor, Object.Vector HitLocation, Object.Vector HitNormal, optional Material HitMaterial)
	{
		local PlayerController PC;
		local Emitter EM;
		local class<Emitter>  EMClass;
		if (Level.NetMode == 1)
		{
			Return;
		}
		PC = Level.GetLocalPlayerController();
		if (HitMaterial != None)
		{
			EMClass = HitMaterial.GetBulletImpactEmitterClass();
			if (EMClass == None)
			{
				EMClass = Class'em_bt_dirt';
			}
			EM = Spawn(EMClass,None,,HitLocation,HitNormal);
		}
		if (EM != None)
		{
			EM.InitEmitters(HitLocation,HitNormal);
			EM.LifeSpan = 5;
		}
		if (PC != None && Instigator != None && Instigator.Controller == PC || VSize(PC.ViewTarget.Location - HitLocation) < 5000)
	}
	{
	}
	simulated Event ClientSpawnHitEffects()
	{
		local Object.Vector HitLocation;
		local Object.Vector HitNormal;
		local Object.Vector offset;
		local Actor HitActor;
		local Material HitMaterial;
		if (Level.NetMode == 0)
		{
			Return;
		}
		offset = 20 * Normal(WeaponFireLocation - LastHitLocation);
		HitActor = Trace(HitLocation,HitNormal,LastHitLocation - offset,LastHitLocation + offset,True,,HitMaterial);
		SpawnHitEffects(HitActor,LastHitLocation,HitNormal,HitMaterial);
	}
	Function AltFire(Controller C)
	{
		FlashAltMuzzleFlash();
		if (bAmbientFireSound)
		{
			AmbientSound = AltFireSoundClass;
		}
		else
		{
			PlayOwnedSound(AltFireSoundClass,0,AltFireSoundVolume / 255,,AltFireSoundRadius,FireSoundPitch,False);
		}
		TraceFire(WeaponFireLocation,WeaponFireRotation);
	}
	Function Fire(Controller C)
	{
		SpawnProjectile(ProjectileClass,False);
	}
}
*/


void AM1117_ASV_Turret::InitEffects()
{
	/*
	InitEffects();
	if (Level.NetMode == 1)
	{
		Return;
	}
	if (AltFlashEmitterClass != None && AltFlashEmitter == None || AltFlashEmitter.bDeleteMe)
	{
		AltFlashEmitter = Spawn(AltFlashEmitterClass, Self);
		if (AltFlashEmitter != None)
		{
			AltFlashEmitter.SetDrawScale(DrawScale);
			if (AltWeaponFireAttachmentBone == 'None')
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
	if (AltFlashEmitter != None)
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
	/*
	local int i;
	if (AltFlashEmitter != None)
	{
		for (i = 0; i < AltFlashEmitter.EmitterCount(); i++)
		{
			AltFlashEmitter.Emitters[i].SpawnParticle(AltFlashEmitter.Emitters[i].iFlashSpawnCount);
		}
		if (BaseMuzzleFlashEmitter(AltFlashEmitter) != None)
		{
			BaseMuzzleFlashEmitter(AltFlashEmitter).DynamicFlash();
		}
	}
	*/
}
void AM1117_ASV_Turret::CeaseFire(AController* C)
{
	/*
	AltFlashCount = 0;
	CeaseFire(C);
	*/
}

void AM1117_ASV_Turret::DestroyEffects()
{
	/*
	if (AltFlashEmitter != None)
	{
		AltFlashEmitter.Destroy();
	}
	DestroyEffects();
	*/
}

void AM1117_ASV_Turret::PostNetReceive()
{
	/*
	if (OldAltFlashCount != AltFlashCount)
	{
		FlashAltMuzzleFlash();
		OldAltFlashCount = AltFlashCount;
	}
	PostNetReceive();
	*/
}