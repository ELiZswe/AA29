// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/RocketWeapon/RocketWeapon.h"
#include "Javelin_Tube.generated.h"

class ABaseAmmoRound;
class AInvContainer;
class ALevelInfo;
class APickup;
UCLASS()
class AJavelin_Tube : public ARocketWeapon
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
	ABaseAmmoRound* SpawnSingleAmmoRound(bool bAux, int32 ammo_id, bool bSpecial);
	void StaticPrecache(ALevelInfo* L);
	bool CanLean();
	bool CanUseWeapon(int32 DesiredAction);
	AInvContainer* GetSwapContainer();
	void GiveTo(APawn* Other, APickup* Pickup);
	APickup* DropFrom(FVector StartLocation, bool bAttach);
	virtual bool CanSprint() override;
	EUpperBodyAnim GetUpperBodyLowerAnim();
	EUpperBodyAnim GetUpperBodyRaiseAnim();
	EUpperBodyAnim GetUpperBodyReadyAnim();
	void RunAnimation(FName Sequence, float Rate, float TweenTime, bool bLoop);
	virtual void PlaySelect() override;
	virtual void TweenDown() override;
};
