// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/AGP_Character_NPC/AGP_Character_NPC.h"
#include "NPC_civilian.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ANPC_civilian : public AAGP_Character_NPC
{
	GENERATED_BODY()
public:
	ANPC_civilian();
	UPROPERTY(EditAnywhere)													bool NPC_DamageOn;								//var() bool NPC_DamageOn;
};
