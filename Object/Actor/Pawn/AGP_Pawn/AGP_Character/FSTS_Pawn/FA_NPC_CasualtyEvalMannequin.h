// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/FSTS_Pawn/FSTS_NPC_Mannequin.h"
#include "FA_NPC_CasualtyEvalMannequin.generated.h"

UCLASS()
class AFA_NPC_CasualtyEvalMannequin : public AFSTS_NPC_Mannequin
{
	GENERATED_BODY()
public:
	AFA_NPC_CasualtyEvalMannequin();

	void AnimateStanding();
};
