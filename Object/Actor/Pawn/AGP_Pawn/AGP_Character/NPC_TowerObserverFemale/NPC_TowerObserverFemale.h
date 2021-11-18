// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/AGP_Character.h"
#include "NPC_TowerObserverFemale.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ANPC_TowerObserverFemale : public AAGP_Character
{
	GENERATED_BODY()
public:
	ANPC_TowerObserverFemale();


	void PossessedBy(AController* C);
	void BeginPlay();
};
