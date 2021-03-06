// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/InventoryAttachment/InventoryAttachment.h"
#include "ItemAttachment.generated.h"

class AInventory;
UCLASS()
class AItemAttachment : public AInventoryAttachment
{
	GENERATED_BODY()

public:
	AItemAttachment();
	
	UPROPERTY()		TArray<FName> DisableOtherAttachment;				//var array<name> DisableOtherAttachment;
	UPROPERTY()		FName AttachBone;									//var name AttachBone;
	UPROPERTY()		FRotator Rotation;

	FName GetAttachBoneFor(AInventory* Inv);
	void SetMesh();
	void Destroyed();
	void RemoveFromList();
	void CheckOtherAttachments(bool bEnable);
	void EnableItem(bool bEnable, AItemAttachment* Item);
};
