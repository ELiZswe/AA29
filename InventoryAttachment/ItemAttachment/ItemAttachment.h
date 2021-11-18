// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/InventoryAttachment/InventoryAttachment.h"
#include "ItemAttachment.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AItemAttachment : public AInventoryAttachment
{
	GENERATED_BODY()

public:
	AItemAttachment();

	
	UPROPERTY()		TArray<FName> DisableOtherAttachment;				//var array<name> DisableOtherAttachment;
	UPROPERTY()		FName AttachBone;									//var name AttachBone;
	UPROPERTY()		FRotator Rotation;



};
