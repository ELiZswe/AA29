// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/TraceWeapon/SniperRifle/SniperRifle.h"
#include "Weapon_Vintorez_Sniper.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AWeapon_Vintorez_Sniper : public ASniperRifle
{
	GENERATED_BODY()
public:
	AWeapon_Vintorez_Sniper();

	
	UPROPERTY()		float FireAdjustRapid;				//var float FireAdjustRapid;

	bool IsSuppressed();
	virtual void DoChangeFireMode() override;
	virtual void ChangeFireMode() override;
	virtual void AltFire(float Value) override;
	virtual void PlayFiring() override;

};
