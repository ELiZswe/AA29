// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/AGP_Weapon.h"
#include "item_headphones.generated.h"

UCLASS()
class Aitem_headphones : public AAGP_Weapon
{
	GENERATED_BODY()
public:
	Aitem_headphones();


	virtual void Fire(float Value) override;
	virtual void Reload() override;
	virtual void FixJam() override;
	void ChangeFireMode();
	void SpawnAndAttachMILESGear();
	void NotifyBaseChange();
	void SetMesh();
	UStaticMesh* GetStaticMesh(bool bFriendly);
	virtual void AltFire(float Value) override;
	bool ShouldDrawCrosshair();
	bool ShouldBreatheCycle();
	EUpperBodyAnim GetUpperBodyLowerAnim();
	EUpperBodyAnim GetUpperBodyRaiseAnim();
	EUpperBodyAnim GetUpperBodyReadyAnim();
	virtual void PlayIdleAnim() override;
	virtual void TweenDown() override;

};
