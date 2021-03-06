// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/BaseWeaponAttachment.h"
#include "AttachW_T62_Coax.generated.h"

class AInventory;
class AInventoryAttachment;
UCLASS()
class AAttachW_T62_Coax : public ABaseWeaponAttachment
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
