// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Pickup/Pickup.h"
#include "WeaponPickup.generated.h"

class AAA2_HUD;

UCLASS()
class AWeaponPickup : public APickup
{
	GENERATED_BODY()
public:
	AWeaponPickup();
	
	UPROPERTY(EditAnywhere)		TArray<int32>	AmmoAmount;			//var() int AmmoAmount;
	UPROPERTY(EditAnywhere)		bool			bThrown;			//var() bool bThrown;
	UPROPERTY()					bool			bWeaponStay;		//var bool bWeaponStay;

	void PostBeginPlay();
	void SetWeaponStay();
	void UpdateHUD(AAA2_HUD* H);
	void StartSleeping();
	bool AllowRepeatPickup();
	float GetRespawnTime();
};
