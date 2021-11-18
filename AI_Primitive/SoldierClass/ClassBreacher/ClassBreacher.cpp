// All the original content belonged to the US Army


#include "ClassBreacher.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/TraceWeapon/Weapon_M870_Shotgun/Weapon_M870_Shotgun.h"
#include "AA29/Inventory/Ammunition/AGP_Ammunition/Ammo_12gauge_7_Rounds/Ammo_12gauge_7_Rounds.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/ThrowWeapon/Throw_M67_Frag/Throw_M67_Frag.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/ThrowWeapon/Throw_M83_Smoke/Throw_M83_Smoke.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/ThrowWeapon/Throw_M84_Stun/Throw_M84_Stun.h"

AClassBreacher::AClassBreacher()
{
	ClassEquipment  = {
		AWeapon_M870_Shotgun::StaticClass(),
		AAmmo_12gauge_7_Rounds::StaticClass(),
		AAmmo_12gauge_7_Rounds::StaticClass(),
		AAmmo_12gauge_7_Rounds::StaticClass(),
		AAmmo_12gauge_7_Rounds::StaticClass(),
		AThrow_M67_Frag::StaticClass(),
		AThrow_M67_Frag::StaticClass(),
		AThrow_M83_Smoke::StaticClass(),
		AThrow_M83_Smoke::StaticClass(),
		AThrow_M84_Stun::StaticClass(),
		AThrow_M84_Stun::StaticClass()
	};
	_ShortName    = "B";
}