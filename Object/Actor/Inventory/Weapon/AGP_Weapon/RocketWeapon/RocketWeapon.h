// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/AGP_Weapon.h"
#include "RocketWeapon.generated.h"

class APickup;
UCLASS()
class ARocketWeapon : public AAGP_Weapon
{
	GENERATED_BODY()
public:
	ARocketWeapon();

	UPROPERTY()		bool	bSafe;					//var bool bSafe;
	UPROPERTY()		bool	bSingleShot;			//var bool bSingleShot;

	bool GetSpecialFireAnim(FName& SpecialAnimName);
	virtual void Fire(float Value) override;
	bool IsSafe();
	void Tick(float DeltaTime);
	void SetSafety(bool new_safety);
	virtual void PlayIdleAnim() override;
	void PlayToggleSafety();
	void StartCrawling();
	bool CanCombatRoll(bool bActual);
	void TestWeaponProne();
	void PlayCrawl();
	virtual bool PutDown() override;
	void UpdateCurrentAmmoRounds(bool bRoundInBreech);
	void GiveTo(APawn* Other, APickup* Pickup);
	bool CanUseWeapon(int32 DesiredAction);
	virtual bool CheckForNoReload() override;
	virtual bool SingleShotWeapon() override;
	virtual bool CanSprint() override;
	bool ShouldDrawCrosshair();
	virtual void DoChangeFireMode() override;
	virtual void ChangeFireMode() override;
};
