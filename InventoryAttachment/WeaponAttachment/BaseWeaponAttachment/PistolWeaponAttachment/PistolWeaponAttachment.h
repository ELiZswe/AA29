// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/BaseWeaponAttachment.h"
#include "PistolWeaponAttachment.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API APistolWeaponAttachment : public ABaseWeaponAttachment
{
	GENERATED_BODY()
public:
	APistolWeaponAttachment();
	
	UPROPERTY()		FName HolsterBone;				//var name HolsterBone;
	UPROPERTY()		FName HandBone;					//var name HandBone;

	void PostBeginPlay();
	void AdjustAttachmentFor(AInventory* Inv);
	void AttachmentAnimation();
	void PlayThirdPersonFiring();
	void PlayAttachmentReload(int32 SpecialReload);
	void ThirdPersonEffects();

};
