// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Pickup/Pickup.h"
#include "WeaponPickup.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AWeaponPickup : public APickup
{
	GENERATED_BODY()
public:
	AWeaponPickup();

	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		int32 AmmoAmount;			//var() int AmmoAmount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		bool bThrown;				//var() bool bThrown;
	UPROPERTY()										bool bWeaponStay;			//var bool bWeaponStay;



	void PostBeginPlay();
	void SetWeaponStay();
	//void UpdateHUD(AHUD* H);
	void StartSleeping();
	bool AllowRepeatPickup();
	void GetRespawnTime();
};
