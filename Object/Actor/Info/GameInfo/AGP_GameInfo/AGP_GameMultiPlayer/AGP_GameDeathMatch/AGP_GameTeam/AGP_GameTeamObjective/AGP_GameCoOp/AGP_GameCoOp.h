// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/GameInfo/AGP_GameInfo/AGP_GameMultiPlayer/AGP_GameDeathMatch/AGP_GameTeam/AGP_GameTeamObjective/AGP_GameTeamObjective.h"
#include "AGP_GameCoOp.generated.h"

class AAA2_PlayerState;

UCLASS()
class AAGP_GameCoOp : public AAGP_GameTeamObjective
{
	GENERATED_BODY()
public:

	AAGP_GameCoOp();

	void MaybeAutoBalanceTeams();
	uint8 PickTeam(uint8 Num, AController* C);
	void CheckScore(AAA2_PlayerState* Scorer);
};
