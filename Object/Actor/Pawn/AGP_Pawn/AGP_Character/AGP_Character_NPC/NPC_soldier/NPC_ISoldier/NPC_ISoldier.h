// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/AGP_Character_NPC/NPC_soldier/NPC_soldier.h"
#include "NPC_ISoldier.generated.h"

UCLASS()
class AA29_API ANPC_ISoldier : public ANPC_soldier
{
	GENERATED_BODY()
public:
	ANPC_ISoldier();
};
