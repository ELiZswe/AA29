// All the original content belonged to the US Army


#include "AA29/Object/Actor/VehicleWeapon/BTR80_Turret/BTR80_Turret.h"

ABTR80_Turret::ABTR80_Turret()
{
	YawBone = "Yaw_Master_bone";
	PitchBone = "Pitch_bone";
	PitchUpLimit = 8000;
	PitchDownLimit = -1820;
	WeaponFireAttachmentBone = "Muzzle_Bone";
	RotationsPerSecond = 0.25;
	bInstantFire = true;
	Spread = 350;
	FireInterval = 0.2;
	//DestroyedModelClass = class'AGP_Vehicles.BTR60_DestroyedTurret';
	//FlashEmitterClass = class'AGP_Vehicles.M2MuzzleFlash';
	//EffectEmitterClass = class'AGP_Vehicles.M2MuzzleFlash';
	//TracerClass = Class'AGP.GreenTracer';
	//FireSoundClass = Sound'S_AA2_WeaponsUS.M249.WeaponsUS_M249_Outdoorfire';
	//DamageType = Class'AGP_Inventory.ProjectileDamageBTR60127mm';
	DamageMin = 85;
	DamageMax = 85;
	TraceRange = 20000;
	//	\\AIInfo = ;
	WeaponBoneHack = true;
	//Mesh = SkeletalMesh'A_AAO_Vehicles.BTR80_Turret';
}

void ABTR80_Turret::InitEffects()
{
	/*
	if (Level.NetMode == 1)
	{
		Return;
	}
	if (FlashEmitterClass != None && FlashEmitter == None || FlashEmitter.bDeleteMe)
	{
		FlashEmitter = Spawn(FlashEmitterClass, Self);
		if (FlashEmitter != None)
		{
			FlashEmitter.SetDrawScale(DrawScale);
			if (WeaponFireAttachmentBone == 'None')
			{
				FlashEmitter.SetBase(Owner);
			}
			else
			{
				AttachToBone(FlashEmitter, WeaponFireAttachmentBone);
				FlashEmitter.SetRelativeRotation(rot(0 0 0));
			}
		}
	}
	if (ShellEjectionEmitterClass != None && ShellEjectionEmitter == None || ShellEjectionEmitter.bDeleteMe && ShellEjectionBone != 'None')
	{
		ShellEjectionEmitter = Spawn(ShellEjectionEmitterClass, Self);
		ShellEjectionEmitter.Initialize(ShellEjectionRandomizer, Shell1p, shell3p);
		ShellEjectionEmitter.SetLocation(Self.Location + vect(0 0 30));
		AttachToBone(ShellEjectionEmitter, ShellEjectionBone);
	}
	*/
}