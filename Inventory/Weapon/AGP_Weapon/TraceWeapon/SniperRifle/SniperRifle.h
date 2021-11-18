// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/TraceWeapon/TraceWeapon.h"
#include "SniperRifle.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ASniperRifle : public ATraceWeapon
{
	GENERATED_BODY()
public:
	ASniperRifle();


	virtual void DoChangeFireMode() override;
	virtual void ChangeFireMode() override;
	bool IsSniperRifle();
	bool ShouldDrawCrosshair();
	virtual void AltFire(float Value) override;
	float GetSoundDampening();
	void AdjustAim(bool bBreatheBonus);
};
