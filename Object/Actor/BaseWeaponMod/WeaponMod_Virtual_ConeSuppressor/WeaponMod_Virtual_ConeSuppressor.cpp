// All the original content belonged to the US Army


#include "WeaponMod_Virtual_ConeSuppressor.h"
#include "AA29/Object/Actor/BaseWeaponMod/WeaponMod_Cone_Suppressor/WeaponMod_Cone_Suppressor.h"

AWeaponMod_Virtual_ConeSuppressor::AWeaponMod_Virtual_ConeSuppressor()
{
	//ValidSlot(5) = 1
	EnemyModClass  = AWeaponMod_Cone_Suppressor::StaticClass();
	modname        = "None";
	DrawType       = EDrawType::DT_None;
}