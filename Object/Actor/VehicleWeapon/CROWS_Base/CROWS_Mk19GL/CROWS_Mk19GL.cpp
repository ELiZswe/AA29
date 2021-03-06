// All the original content belonged to the US Army

#include "AA29/Object/Actor/VehicleWeapon/CROWS_Base/CROWS_Mk19GL/CROWS_Mk19GL.h"
#include "AA29/Object/Actor/Emitter/BaseMuzzleFlashEmitter/M2MuzzleFlash/M2MuzzleFlash.h"
#include "AA29/Object/Actor/Projectile/BaseProjectile/BaseExplodingProjectile/BallisticProjectile/Proj_Mk19G.h"
#include "AA29/Object/DamageType/AGP_DamageType/ProjectileDamage/ProjectileDamage556mm.h"

ACROWS_Mk19GL::ACROWS_Mk19GL()
{
	Ammo = 50;
	AmmoType = "MK19 40MM";
	//HUDAmmoIcon = Texture'T_AAO_UI.HUD.t_ui_hud_crows_40mm_icon';
	//StartBodyPanelMeshes(0) = StaticMesh'M_AAO_Weapons.weapons_3p.m_weap_weapons3p_CROWS_main';
	//StartBodyPanelMeshes(1) = StaticMesh'M_AAO_Weapons.weapons_3p.m_weap_weapons3p_CROWS_camera';
	//StartBodyPanelMeshes(2) = StaticMesh'M_AAO_Weapons.weapons_3p.m_weap_weapons3p_CROWS_weaponmount';
	//StartBodyPanelMeshes(3) = StaticMesh'M_AAO_Weapons.weapons_3p.m_weap_weapons3p_CROWS_mk19';
	WeaponFireBone = "B_Muzzle_MK19";
	CameraBaseBone = "B_WeaponCamera_mk19_Vector";
	WeaponFireAttachmentBone = "B_Muzzle_MK19";
	FireInterval = 0.2;
	//FlashEmitterClass = AM2MuzzleFlash::StaticClass();
	//FireSoundClass = Sound'S_AAO_Armory.MK19.s_arm_mk19_single_fire';
	FireSoundRadius = 300;
	//DamageType = AProjectileDamage556mm::StaticClass();
	DamageMin = 200;
	DamageMax = 200;
	TraceRange = 16000;
	//ProjectileClass = AProj_Mk19G::StaticClass();
}

/*
State ProjectileFireMode
{
	Function Fire(AController* C)
	{
		APlayerController* PC = nullptr;
		Super::Fire(C);
		if ((Ammo > 0) && bCharged)
		{
			PC=Cast<APlayerController>(C);
			if (((Level.Game.Stats != nullptr) && (PC != nullptr)) && (PC.PlayerStatsIndex >= 0))
			{
				Level.Game.Stats.PlayerStats[PC.PlayerStatsIndex].StatEvent_ShotFiredGrenade();
			}
		}
	}
}
*/

/*

State ProjectileFireMode
{
	Function Fire(Controller C)
	{
		APlayerController* PC = nullptr;
		Fire(C);
		if (Ammo > 0 && bCharged)
		{
			PC = Cast<APlayerController>(C);
			if (Level.Game.Stats != nullptr && PC != nullptr && PC.PlayerStatsIndex >= 0)
			{
				Level.Game.Stats.PlayerStats[PC.PlayerStatsIndex].StatEvent_ShotFiredGrenade();
			}
		}
	}
}
*/

void ACROWS_Mk19GL::OwnerEffects()
{
	/*
	if (Ammo > 0 && bCharged)
	{
		ShakeView();
		OwnerEffects();
	}
	*/
}
