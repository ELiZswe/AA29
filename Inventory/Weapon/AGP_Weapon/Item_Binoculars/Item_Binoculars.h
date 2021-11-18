// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/AGP_Weapon.h"
#include "Item_Binoculars.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AItem_Binoculars : public AAGP_Weapon
{
	GENERATED_BODY()
public:
	AItem_Binoculars();

	UPROPERTY()		uint8 InvBinocularsIndex;
	

	virtual void Fire(float Value) override;
	virtual void Reload() override;
	virtual void FixJam() override;
	void ChangeFireMode();
	void SpawnAndAttachMILESGear();
	void NotifyBaseChange();
	void SetMesh();
	void GetStaticMesh(bool bFriendly);
	void ShouldDrawCrosshair();
	bool ShouldBreatheCycle();
	virtual void AltFire(float Value) override;
	void GetUpperBodyLowerAnim();
	void GetUpperBodyRaiseAnim();
	void GetUpperBodyReadyAnim();

};
