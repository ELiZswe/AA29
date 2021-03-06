// All the original content belonged to the US Army

#include "AA29/Object/Actor/BaseWeaponMod/WeaponMod_M68_AimPoint/WeaponMod_M68_AimPoint.h"
#include "AA29/Object/Actor/BaseWeaponMod/WeaponMod_Compact_AimPoint/WeaponMod_Compact_AimPoint.h"
#include "AA29/Object/Actor/BaseWeaponMod/WeaponMod_Reflex/WeaponMod_Reflex.h"
#include "AA29/Object/Actor/BaseScope/ScopeW_M68_Aimpoint/ScopeW_M68_Aimpoint.h"

AWeaponMod_M68_AimPoint::AWeaponMod_M68_AimPoint()
{
	ScopeClass			= AScopeW_M68_Aimpoint::StaticClass();
	ModImage = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/mod_m68_black_Mat.mod_m68_black_Mat'"), NULL, LOAD_None, NULL);
	ModImageOverlay = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/m4mod/m4mod_m68_Mat.m4mod_m68_Mat'"), NULL, LOAD_None, NULL);
	ExclusiveModsList	= {
							AWeaponMod_Reflex::StaticClass()
						};
		//ValidSlot = 1;
	EnemyModClass		= AWeaponMod_Compact_AimPoint::StaticClass();
	modname				= "M68 Aimpoint";
	DrawType			= EDrawType::DT_Mesh;
	//Mesh				= LoadObject<USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_ModsUS/m68_aimpoint.m68_aimpoint"), NULL, LOAD_None, NULL);
}
