// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Inventory/Weapon\AGP_Weapon\ThrowWeapon\ThrowWeapon.h"
#include "Demo_DoorBreacher.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ADemo_DoorBreacher : public AThrowWeapon
{
	GENERATED_BODY()
public:
	ADemo_DoorBreacher();
	
	UPROPERTY()										FVector BlastDir;							//var FVector BlastDir;
	UPROPERTY()										float DirectionalBlastDamage;				//var float DirectionalBlastDamage;
	UPROPERTY()										float DirectionalBlastCone;					//var float DirectionalBlastCone;
	UPROPERTY()										float DirectionalBlastRadius;				//var float DirectionalBlastRadius;
	UPROPERTY()										AActor* SavedHitactor;						//var Actor SavedHitactor;
	UPROPERTY()										FVector SavedHitLocation;					//var FVector SavedHitLocation;
	UPROPERTY()										FVector SavedPlacementNormal;				//var FVector SavedPlacementNormal;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float fPlacementTraceDistance;				//var() float fPlacementTraceDistance;


	void Tick(float DeltaTime);
	void PipeBombAnim();
	virtual void Fire(float Value) override;
	void ServerFire(bool bNoAdjustAim, bool bRapid, bool bBreatheBonus);
	void CanPlaceDemolition();
	bool IsTossNotThrow();
	void SetAltFireNotified(bool bNotify);
	bool IsAltFireNotified();
	virtual void PlayFiring() override;
	virtual void PlayIdleAnim() override;
	virtual void PlaySelect() override;
	virtual void TweenDown() override;
	void SpawnPickup(bool bDrop, AThrowWeaponPickup* SetPickupPtr);
	void BlowUp();
	void DirectionalBlast(FVector BlastDirection);
};
