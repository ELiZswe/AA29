// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/BaseWeaponAttachment.h"
#include "AttachW_Javelin_Tube.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AAttachW_Javelin_Tube : public ABaseWeaponAttachment
{
	GENERATED_BODY()
public:
	AAttachW_Javelin_Tube();

	
	UPROPERTY()		FVector SlungWeaponLocationOffset;				//var FVector SlungWeaponLocationOffset;
	UPROPERTY()		UStaticMesh* TubeInHands;						//var StaticMesh TubeInHands;
};
