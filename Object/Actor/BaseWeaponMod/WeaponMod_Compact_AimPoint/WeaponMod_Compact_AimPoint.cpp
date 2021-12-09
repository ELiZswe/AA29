// All the original content belonged to the US Army


#include "WeaponMod_Compact_AimPoint.h"
#include "AA29/Object/Actor/BaseScope/ScopeW_M68_Aimpoint/ScopeW_M68_Aimpoint.h"
#include "AA29/Object/Actor/BaseWeaponMod/WeaponMod_Kobra_Reflex/WeaponMod_Kobra_Reflex.h"
#include "AA29/Object/Actor/BaseWeaponMod/WeaponMod_M68_AimPoint/WeaponMod_M68_AimPoint.h"

AWeaponMod_Compact_AimPoint::AWeaponMod_Compact_AimPoint()
{
	ScopeClass			= AScopeW_M68_Aimpoint::StaticClass();
	ExclusiveModsList	= {
							AWeaponMod_Kobra_Reflex::StaticClass()
						};
	//ValidSlot = 1;
	EnemyModClass		= AWeaponMod_M68_AimPoint::StaticClass();
	DrawType			= EDrawType::DT_Mesh;
	Mesh				= LoadObject<USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_ModsOpfor/compact.compact"), NULL, LOAD_None, NULL);
}