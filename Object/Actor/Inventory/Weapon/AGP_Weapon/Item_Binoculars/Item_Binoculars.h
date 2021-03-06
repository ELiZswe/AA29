// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/AGP_Weapon.h"
#include "Item_Binoculars.generated.h"

UCLASS()
class AItem_Binoculars : public AAGP_Weapon
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
	UStaticMesh* GetStaticMesh(bool bFriendly);
	bool ShouldDrawCrosshair();
	bool ShouldBreatheCycle();
	virtual void AltFire(float Value) override;
	EUpperBodyAnim GetUpperBodyLowerAnim();
	EUpperBodyAnim GetUpperBodyRaiseAnim();
	EUpperBodyAnim GetUpperBodyReadyAnim();
};
