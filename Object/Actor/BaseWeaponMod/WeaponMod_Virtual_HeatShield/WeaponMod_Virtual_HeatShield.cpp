// All the original content belonged to the US Army


#include "WeaponMod_Virtual_HeatShield.h"
#include "AA29/Object/Actor/BaseWeaponMod/WeaponMod_HeatShield/WeaponMod_HeatShield.h"

AWeaponMod_Virtual_HeatShield::AWeaponMod_Virtual_HeatShield()
{
	//ValidSlot(1) = 1
	//ValidSlot(2) = 1
	//ValidSlot(3) = 1
	//ValidSlot(4) = 1
	EnemyModClass  = AWeaponMod_HeatShield::StaticClass();
	DrawType       = EDrawType::DT_None;
}