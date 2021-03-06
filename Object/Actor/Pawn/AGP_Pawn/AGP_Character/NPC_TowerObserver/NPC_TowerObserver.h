// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/AGP_Character.h"
#include "NPC_TowerObserver.generated.h"

UCLASS()
class ANPC_TowerObserver : public AAGP_Character
{
	GENERATED_BODY()
public:
	ANPC_TowerObserver();

	bool IsFriend(APawn* Other);
	void MatchStarting();
};
