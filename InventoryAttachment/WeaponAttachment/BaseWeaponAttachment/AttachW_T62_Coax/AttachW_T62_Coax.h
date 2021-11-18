// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/BaseWeaponAttachment.h"
#include "AttachW_T62_Coax.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AAttachW_T62_Coax : public ABaseWeaponAttachment
{
	GENERATED_BODY()
public:
	AAttachW_T62_Coax();



	void SpawnMILESAttachments();
	void AttachToMe(AInventoryAttachment* att);
	void AdjustAttachmentFor(AInventory* Inv);
	void PostBeginPlay();
	void SpawnMuzzleFlashEmitters();

};
