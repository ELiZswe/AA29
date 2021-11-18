// All the original content belonged to the US Army


#include "AA29/AA2_Emitter/BaseSmokeEmitter/BaseSmokeEmitter.h"
#include "AA29/AA2_WorldSettings.h"
ABaseSmokeEmitter::ABaseSmokeEmitter()
{
	Duration = { 25,50 };
//	bNoDelete = false;
}


void ABaseSmokeEmitter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (_EffectDuration > 0 && !_bKilled)
	{
		_EffectCounter += DeltaTime;
		if (Cast<AAA2_WorldSettings>(GetWorldSettings())->debugGrenade)
		{
			UE_LOG(LogTemp, Log, TEXT("Counter %d Time %d"), _EffectCounter, _EffectDuration);
		}
		if (_EffectCounter > _EffectDuration)
		{
			//Kill();
			_bKilled = true;
		}
	}
}
void ABaseSmokeEmitter::MatchStarting()
{
	//Super::MatchStarting();
	Destroy();
}
void ABaseSmokeEmitter::Destroyed()
{
	Super::Destroyed();
	if (WeaponPtr != nullptr)
	{
		//WeaponPtr.GotoState('DestroyWeapon');
	}
	if (PickupPtr != nullptr)
	{
		//PickupPtr->Destroy();
	}
}