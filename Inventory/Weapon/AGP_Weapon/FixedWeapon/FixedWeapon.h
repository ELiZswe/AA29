// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/AGP_Weapon.h"
#include "FixedWeapon.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AFixedWeapon : public AAGP_Weapon
{
	GENERATED_BODY()
public:
	AFixedWeapon();

	
	UPROPERTY()		int32 iLastPercent;						//var int iLastPercent;
	UPROPERTY()		float fReloadTime;						//var float fReloadTime;
	UPROPERTY()		UMaterialInstance* tTurretOverlay;		//var Material tTurretOverlay;


	void DetachFromPawn(APawn* p, bool bPreserveWeapon);
	void AttachToPawn(APawn* p);
	void MatchStarting();
	void Destroyed();
	void RemoveTurret();
	void SetTurret(AActor* A);
	void MatchEnding();
	void GetFireStart(FVector X, FVector Y, FVector Z);
	void GetFireRot();
	void GetAnimActor();
	void GetSoundActor();
	virtual void TweenDown() override;
	virtual void PlayIdleAnim() override;
	virtual void Fire(float Value) override;
	void ServerFire(bool bNoAdjustAim, bool bRapid, bool bBreatheBonus);
	void Tick(float DeltaTime);
	void FixedWeaponReload();
	void InitFor(AInventory* Inv);
	void RenderOverlays(UCanvas* Canvas, bool bWeaponAndAttachmentsOnly);

};
