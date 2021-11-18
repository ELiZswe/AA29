// All the original content belonged to the US Army


#include "AA29/Object/Actor/VehicleWeapon/CROWS_Base/CROWS_Mk19GL/CROWS_Mk19GL.h"

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
	//FlashEmitterClass = class'AGP_Vehicles.M2MuzzleFlash';
	//FireSoundClass = Sound'S_AAO_Armory.MK19.s_arm_mk19_single_fire';
	FireSoundRadius = 300;
	//DamageType = Class'AGP_Inventory.ProjectileDamage556mm';
	DamageMin = 200;
	DamageMax = 200;
	TraceRange = 16000;
	//ProjectileClass = class'AGP_Vehicles.Proj_Mk19G';
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