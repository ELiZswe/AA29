// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Emitter/AA2_Emitter.h"
#include "BaseSmokeEmitter.generated.h"

/**
 * 
 */
class APickup;
class AWeapon;

UCLASS()
class AA29_API ABaseSmokeEmitter : public AAA2_Emitter
{
	GENERATED_BODY()
public:
	ABaseSmokeEmitter();

	UPROPERTY()															bool _bKilled;									//var bool _bKilled;
	UPROPERTY()															float _EffectCounter;							//var float _EffectCounter;
	UPROPERTY()															float _EffectDuration;							//var float _EffectDuration;
	UPROPERTY()															APickup* PickupPtr;								//var Pickup PickupPtr;
	UPROPERTY()															AWeapon* WeaponPtr;								//var Weapon WeaponPtr;
	UPROPERTY()															FRange Duration;								//var Object.Range Duration;

	void Tick(float DeltaTime);
	void MatchStarting();
	void Destroyed();

};
