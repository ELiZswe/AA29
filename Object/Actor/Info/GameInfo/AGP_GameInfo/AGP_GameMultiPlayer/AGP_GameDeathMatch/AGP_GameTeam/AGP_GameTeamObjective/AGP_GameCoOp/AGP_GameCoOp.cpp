// All the original content belonged to the US Army

#include "AA29/Object/Actor/Info/GameInfo/AGP_GameInfo/AGP_GameMultiPlayer/AGP_GameDeathMatch/AGP_GameTeam/AGP_GameTeamObjective/AGP_GameCoOp/AGP_GameCoOp.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/TeamInfo/AGP_TeamInfo/AGP_TeamInfo.h"
#include "AA29/Object/Actor/Keypoint/BaseObjective/AGP_Objective/AGP_Objective.h"
#include "AA29/Object/Actor/Keypoint/BaseObjective/AGP_Objective/AGP_TriggeredObjective/AGP_TriggeredObjective.h"

AAGP_GameCoOp::AAGP_GameCoOp()
{

}

void AAGP_GameCoOp::MaybeAutoBalanceTeams()
{
}

uint8 AAGP_GameCoOp::PickTeam(uint8 Num, AController* C)
{
	if (Num == 255)
	{
		return 255;
	}
	return Teams[0]->TeamIndex;
}

void AAGP_GameCoOp::CheckScore(AAA2_PlayerState* Scorer)
{
	AAGP_Objective* obj = nullptr;
	AAGP_TriggeredObjective* trigObj = nullptr;
	AController* C = nullptr;
	bool bFoundSomeone = false;
	/*
	if (!IsInState('MatchInProgress'))
	{
		return;
	}
	obj = firstObjective;
	if (obj != nullptr)
	{
		if (!obj.IsRequired() || !obj.IsEnabled())
		{
		}
		trigObj = AGP_TriggeredObjective(obj);
		if (trigObj == nullptr || trigObj.MustBeClass == nullptr)
		{
		}
		bFoundSomeone = false;
		C = Level.ControllerList;
		if (C != nullptr)
		{
			if (!C.bIsPlayer || C.PlayerReplicationInfo == nullptr || C.Pawn == nullptr)
			{
			}
			if (trigObj.CanAccomplish(C.Pawn))
			{
				bFoundSomeone = true;
			}
			else
			{
				C = C.nextController;
			}
		}
		if (!bFoundSomeone)
		{
			switch(trigObj.AttackTeam)
			{
					case 0:
						PendingEndGame(Teams[1].GetSquadLeader(None), "ObjectiveImpossible");
						return;
					case 1:
						PendingEndGame(Teams[0].GetSquadLeader(None), "ObjectiveImpossible");
						return;
					default:
						PendingEndGame(None, "ObjectiveImpossible");
						return;
			}
			obj = obj.nextObjective;
			break;
		}
		if (Teams[0].TeamDead())
		{
			PendingEndGame(None, "TeamDead");
		}
		CheckScore(Scorer);
	
	}
	*/
}
