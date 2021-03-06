// All the original content belonged to the US Army

#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/ThrowWeapon/Throw_M83_Smoke/Throw_M83_GreenSmoke/Throw_M83_GreenSmoke.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/ThrowWeaponPickup/PickupT_M83_Smoke/PickupT_M83_GreenSmoke/PickupT_M83_GreenSmoke.h"
#include "AA29/Object/Actor/Emitter/BaseSmokeEmitter/M83GreenSmokeEmitter/M83GreenSmokeEmitter.h"

AThrow_M83_GreenSmoke::AThrow_M83_GreenSmoke()
{
	//cSmokeEmitter = AM83GreenSmokeEmitter::StaticClass();
	InvGrenadeIndex  = 6;
	PickupClass      = APickupT_M83_GreenSmoke::StaticClass();
	ItemName         = "M83 Green Smoke Grenade";
}
