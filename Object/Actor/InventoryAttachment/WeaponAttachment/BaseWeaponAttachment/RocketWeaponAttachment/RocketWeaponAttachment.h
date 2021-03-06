// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/BaseWeaponAttachment.h"
#include "AA29/Object/Actor/InventoryAttachment/ItemAttachment/ItemAttachment.h"
#include "RocketWeaponAttachment.generated.h"
class AInventory;
UCLASS()
class ARocketWeaponAttachment : public ABaseWeaponAttachment
{
	GENERATED_BODY()
public:
	ARocketWeaponAttachment();

	UPROPERTY()		TSubclassOf<class AItemAttachment> RPGBackpack;						//var ItemAttachment RPGBackpack;
	UPROPERTY()	 	TSubclassOf<class ABase3pAmmoRound> ThirdPersonAmmoRoundClass;		//var class<Base3pAmmoRound> ThirdPersonAmmoRoundClass;
	UPROPERTY()		TSubclassOf<class AItemAttachment> BackpackAttachmentClass;			//var class<ItemAttachment> BackpackAttachmentClass;

	void PlayAttachmentReload(int32 SpecialReload);
	void ThirdPersonEffects();
	void Destroyed();
	uint8 AdjustForThirdPersonRounds(uint8 NewAnimState, AInventory* Inv);
	void AttachmentAnimation();
};
