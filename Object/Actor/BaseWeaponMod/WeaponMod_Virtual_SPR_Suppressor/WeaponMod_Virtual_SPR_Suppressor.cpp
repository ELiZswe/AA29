// All the original content belonged to the US Army

#include "AA29/Object/Actor/BaseWeaponMod/WeaponMod_Virtual_SPR_Suppressor/WeaponMod_Virtual_SPR_Suppressor.h"
#include "AA29/Object/Actor/BaseWeaponMod/WeaponMod_SPR_Suppressor/WeaponMod_SPR_Suppressor.h"

AWeaponMod_Virtual_SPR_Suppressor::AWeaponMod_Virtual_SPR_Suppressor()
{
	//ValidSlot(5) = 1
	EnemyModClass   = AWeaponMod_SPR_Suppressor::StaticClass();
	modname         = "None";
	DrawType        = EDrawType::DT_None;
}
