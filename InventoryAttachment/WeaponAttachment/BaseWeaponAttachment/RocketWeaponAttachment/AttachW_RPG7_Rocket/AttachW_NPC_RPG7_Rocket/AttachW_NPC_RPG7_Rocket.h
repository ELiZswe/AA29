// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/RocketWeaponAttachment/AttachW_RPG7_Rocket/AttachW_RPG7_Rocket.h"
#include "AttachW_NPC_RPG7_Rocket.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AAttachW_NPC_RPG7_Rocket : public AAttachW_RPG7_Rocket
{
	GENERATED_BODY()
public:
	AAttachW_NPC_RPG7_Rocket();


	void PreBeginPlay();
	void AttachmentAnimation();

};
