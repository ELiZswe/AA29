// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/RocketWeapon/RocketWeapon.h"
#include "Javelin_Tube.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AJavelin_Tube : public ARocketWeapon
{
	GENERATED_BODY()
public:
	AJavelin_Tube();

	virtual void Fire(float Value) override;
	virtual void Reload() override;
	virtual void FixJam() override;
	void ChangeFireMode();
	void SpawnAndAttachMILESGear();
	virtual void AltFire(float Value) override;
	void SpawnAndAttachAmmoRounds();
	void SpawnSingleAmmoRound(bool bAux, int32 ammo_id, bool bSpecial);
	//void StaticPrecache(LevelInfo L);
	void CanLean();
	bool CanUseWeapon(int32 DesiredAction);
	void GetSwapContainer();
	void GiveTo(APawn* Other, APickup* Pickup);
	void DropFrom(FVector StartLocation, bool bAttach);
	virtual bool CanSprint() override;
	EUpperBodyAnim GetUpperBodyLowerAnim();
	EUpperBodyAnim GetUpperBodyRaiseAnim();
	EUpperBodyAnim GetUpperBodyReadyAnim();
	void RunAnimation(FName Sequence, float Rate, float TweenTime, bool bLoop);
	virtual void PlaySelect() override;
	virtual void TweenDown() override;

};
