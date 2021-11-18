// All the original content belonged to the US Army


#include "WeaponMod_M68_AimPoint.h"
#include "AA29/BaseWeaponMod/WeaponMod_Compact_AimPoint/WeaponMod_Compact_AimPoint.h"
#include "AA29/BaseWeaponMod/WeaponMod_Reflex/WeaponMod_Reflex.h"
#include "AA29/BaseScope/ScopeW_M68_Aimpoint.h"

AWeaponMod_M68_AimPoint::AWeaponMod_M68_AimPoint()
{
	ScopeClass			= AScopeW_M68_Aimpoint::StaticClass();
	ModImage			= LoadObject<UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_UI/Menu/mod_m68_black.mod_m68_black"), NULL, LOAD_None, NULL);
	ModImageOverlay		= LoadObject<UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_UI/m4mod/m4mod_m68.m4mod_m68"), NULL, LOAD_None, NULL);
	ExclusiveModsList	= {
							AWeaponMod_Reflex::StaticClass()
						};
		//ValidSlot = 1;
	EnemyModClass		= AWeaponMod_Compact_AimPoint::StaticClass();
	modname				= "M68 Aimpoint";
	DrawType			= EDrawType::DT_Mesh;
	Mesh				= LoadObject<USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_ModsUS/m68_aimpoint.m68_aimpoint"), NULL, LOAD_None, NULL);
}