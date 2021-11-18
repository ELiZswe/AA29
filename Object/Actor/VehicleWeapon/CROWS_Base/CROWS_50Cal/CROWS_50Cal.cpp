// All the original content belonged to the US Army


#include "AA29/Object/Actor/VehicleWeapon/CROWS_Base/CROWS_50Cal/CROWS_50Cal.h"

ACROWS_50Cal::ACROWS_50Cal()
{
	Ammo = 500;
	AmmoType = "M2 .50 CAL";
	CasingSoundMinDelay = 0.2;
	CasingDelayDeviation = 0.2;
	//BulletCasingRing(0) = Sound'S_AAO_Armory.M2.s_arm_m2_case_1';
	//BulletCasingRing(1) = Sound'S_AAO_Armory.M2.s_arm_m2_case_2';
	//BulletCasingRing(2) = Sound'S_AAO_Armory.M2.s_arm_m2_case_3';
	//BulletCasingRing(3) = Sound'S_AAO_Armory.M2.s_arm_m2_case_4';
	//BarrelHiss = Sound'S_AAO_Armory.M2.s_arm_m2_barrel_hiss';
	HissDecrementDelay = 1;
	HissTriggerCount = 20;
	//HUDAmmoIcon = Texture'T_AAO_UI.HUD.t_ui_hud_crows_50cal_icon';
	WeaponFireBone = "B_Muzzle_MK19";
	CameraBaseBone = "B_WeaponCamera_mk19_Vector";
	WeaponFireAttachmentBone = "B_Muzzle_MK19";
	FireInterval = 0.12;
	//FlashEmitterClass = Class'AGP_Effects.M249MuzzleFlash';
	//EffectEmitterClass = Class'AGP_Effects.M249MuzzleFlash';
	//DamageType = Class'AGP_Inventory.ProjectileDamage556mm';
	DamageMin = 100;
	DamageMax = 150;
	TraceRange = 100000;
	//ProjectileClass = class'AGP_Vehicles.Proj_50Cal';
}

/*
State ProjectileFireMode
{
	Function Fire(Controller C)
	{
		local PlayerController PC;
		Fire(C);
		if (Ammo > 0 && bCharged)
		{
			PC = PlayerController(C);
			if (Level.Game.Stats != None && PC != None && PC.PlayerStatsIndex >= 0)
			{
				Level.Game.Stats.PlayerStats[PC.PlayerStatsIndex].StatEvent_ShotFiredMachineGun();
			}
		}
	}
}
*/

void ACROWS_50Cal::OwnerEffects()
{
	/*
	if (Ammo > 0 && bCharged)
	{
		ShakeView();
		OwnerEffects();
	}
	*/
}

void ACROWS_50Cal::InitEffects()
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
			AttachToBone(FlashEmitter, 'B_Muzzle');
			FlashEmitter.SetRelativeRotation(rot(0 0 32768));
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