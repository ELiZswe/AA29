// All the original content belonged to the US Army

#include "AA29/Object/Actor/BaseWeaponMod/WeaponMod_Virtual_Harris_Bipod/WeaponMod_Virtual_Harris_Bipod.h"
#include "AA29/Object/Actor/BaseWeaponMod/WeaponMod_Harris_Bipod/WeaponMod_Harris_Bipod.h"

AWeaponMod_Virtual_Harris_Bipod::AWeaponMod_Virtual_Harris_Bipod()
{
	WeaponBone     = "Bipod";
	//ValidSlot(4) = 1
	EnemyModClass  = AWeaponMod_Harris_Bipod::StaticClass();
	DrawType       = EDrawType::DT_None;
}
