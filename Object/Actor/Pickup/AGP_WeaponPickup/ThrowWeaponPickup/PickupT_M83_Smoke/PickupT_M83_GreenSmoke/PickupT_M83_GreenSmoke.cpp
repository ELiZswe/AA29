// All the original content belonged to the US Army


#include "PickupT_M83_GreenSmoke.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/ThrowWeapon/Throw_M83_Smoke/Throw_M83_GreenSmoke/Throw_M83_GreenSmoke.h"

APickupT_M83_GreenSmoke::APickupT_M83_GreenSmoke()
{
	InventoryType		= AThrow_M83_GreenSmoke::StaticClass();
	EnemyPickupClass	= APickupT_M83_GreenSmoke::StaticClass();
}

void APickupT_M83_GreenSmoke::SpawnSmokeEmitter(AThrowWeapon* W)
{
	/*
	local AGP_Effects.BaseSmokeEmitter SmokeGenerator;
	if (W.Default.cSmokeEmitter != None)
	{
		SmokeGenerator = Spawn(W.Default.cSmokeEmitter, Self, , Location, rot(16384 0 0));
		SmokeGenerator.SetBase(Self);
		SmokeGenerator.PickupPtr = Self;
		SmokeGenerator._EffectDuration = _EffectDuration;
	}
	SignalBlackhawkToLand();
	*/
}