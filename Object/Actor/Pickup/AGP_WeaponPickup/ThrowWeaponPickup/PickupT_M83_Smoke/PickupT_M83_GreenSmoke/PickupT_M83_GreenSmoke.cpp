// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/ThrowWeaponPickup/PickupT_M83_Smoke/PickupT_M83_GreenSmoke/PickupT_M83_GreenSmoke.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/ThrowWeapon/Throw_M83_Smoke/Throw_M83_GreenSmoke/Throw_M83_GreenSmoke.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/ThrowWeapon/ThrowWeapon.h"
#include "AA29/Object/Actor/Emitter/BaseSmokeEmitter/BaseSmokeEmitter.h"

APickupT_M83_GreenSmoke::APickupT_M83_GreenSmoke()
{
	InventoryType		= AThrow_M83_GreenSmoke::StaticClass();
	EnemyPickupClass	= APickupT_M83_GreenSmoke::StaticClass();
}

void APickupT_M83_GreenSmoke::SpawnSmokeEmitter(AThrowWeapon* W)
{
	ABaseSmokeEmitter* SmokeGenerator = nullptr;
	/*
	if (W.Default.cSmokeEmitter != nullptr)
	{
		SmokeGenerator = Spawn(W.Default.cSmokeEmitter, this, , Location, FRotator(16384 0 0));
		SmokeGenerator.SetBase(this);
		SmokeGenerator.PickupPtr = this;
		SmokeGenerator._EffectDuration = _EffectDuration;
	}
	SignalBlackhawkToLand();
	*/
}
