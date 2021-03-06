// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/BaseWeaponAttachment.h"
#include "PistolWeaponAttachment.generated.h"

class AInventory;
UCLASS()
class APistolWeaponAttachment : public ABaseWeaponAttachment
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
