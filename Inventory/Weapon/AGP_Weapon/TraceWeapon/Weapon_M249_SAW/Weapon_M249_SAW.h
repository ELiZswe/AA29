// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/TraceWeapon/TraceWeapon.h"
#include "Weapon_M249_SAW.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AWeapon_M249_SAW : public ATraceWeapon
{
	GENERATED_BODY()
public:
	AWeapon_M249_SAW();
	
	UPROPERTY()		TArray<FName> SupportedStillLowAmmo;			//var name SupportedStillLowAmmo;
	UPROPERTY()		TArray<FName> SupportedFireAnimsLowAmmo;		//var name SupportedFireAnimsLowAmmo;
	UPROPERTY()		TArray<FName> StillLowAmmo;						//var name StillLowAmmo;
	UPROPERTY()		TArray<FName> FireAnimsLowAmmo;					//var name FireAnimsLowAmmo;

	virtual void DoChangeFireMode() override;
	virtual void ChangeFireMode() override;
	virtual void PlayReloading() override;
	void GetSpecialFireAnim(FName SpecialAnimName);
	virtual void PlayIdleAnim() override;
	virtual void PlaySelect() override;
	virtual void TweenDown() override;
	void PlaySupporting();
	void PlayHighCrawlIn();
	void PlayCrawl();
	void PlayHighCrawlOut();
	void HandleMisFire();
	virtual void FixJam() override;
	int32 GetPendingShots();

};
