// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/BaseWeaponAttachment.h"
#include "AttachW_MP5_Rifle.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AAttachW_MP5_Rifle : public ABaseWeaponAttachment
{
	GENERATED_BODY()
public:
	AAttachW_MP5_Rifle();

	void AttachmentAnimation();
};
