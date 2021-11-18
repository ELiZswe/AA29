// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/TraceWeapon/Weapon_M16A2_Rifle/Weapon_M16A2_Rifle.h"
#include "Weapon_M16A2_Trainer.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AWeapon_M16A2_Trainer : public AWeapon_M16A2_Rifle
{
	GENERATED_BODY()
public:
	AWeapon_M16A2_Trainer();

	UPROPERTY()		bool bInitializeWeaponDown;			//var bool bInitializeWeaponDown;
	UPROPERTY()		bool bCanSetSupported;				//var bool bCanSetSupported;

	void AddClip(AAmmunition* AmmoClass);
	virtual void FixJam() override;
	void SetSupported(bool newSupported);
	void PlayChangeFireMode();
	virtual void TweenDown() override;
	void SetupClientWeapon();

};
