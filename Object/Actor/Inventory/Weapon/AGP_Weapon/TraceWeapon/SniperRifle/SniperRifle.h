// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/TraceWeapon/TraceWeapon.h"
#include "SniperRifle.generated.h"

UCLASS()
class ASniperRifle : public ATraceWeapon
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
	FRotator AdjustAim(bool bBreatheBonus);
};
