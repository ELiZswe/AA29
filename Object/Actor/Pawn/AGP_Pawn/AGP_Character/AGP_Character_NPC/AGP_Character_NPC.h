// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/AGP_Character.h"
#include "AGP_Character_NPC.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AAGP_Character_NPC : public AAGP_Character
{
	GENERATED_BODY()
public:
	AAGP_Character_NPC();

	void PossessedBy(AController* C);
	void BeginPlay();

};

