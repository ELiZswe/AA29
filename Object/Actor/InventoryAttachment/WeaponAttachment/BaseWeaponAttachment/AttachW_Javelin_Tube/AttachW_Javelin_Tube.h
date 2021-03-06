// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/BaseWeaponAttachment.h"
#include "AttachW_Javelin_Tube.generated.h"

UCLASS()
class AAttachW_Javelin_Tube : public ABaseWeaponAttachment
{
	GENERATED_BODY()
public:
	AAttachW_Javelin_Tube();
	
	UPROPERTY()		UStaticMesh*	TubeInHands;						//var StaticMesh TubeInHands;
	UPROPERTY()		FVector			SlungWeaponLocationOffset;			//var FVector SlungWeaponLocationOffset;

	UStaticMesh* GetStaticMesh(bool bFriendly);
	void AttachmentAnimation();
};
