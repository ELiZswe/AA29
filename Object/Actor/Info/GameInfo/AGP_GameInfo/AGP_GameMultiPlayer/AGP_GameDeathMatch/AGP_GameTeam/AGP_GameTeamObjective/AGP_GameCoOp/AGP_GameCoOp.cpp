// All the original content belonged to the US Army

#include "AA29/Object/Actor/Info/GameInfo/AGP_GameInfo/AGP_GameMultiPlayer/AGP_GameDeathMatch/AGP_GameTeam/AGP_GameTeamObjective/AGP_GameCoOp/AGP_GameCoOp.h"

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
	//return Teams[0]->TeamIndex;

	return 0;	//Fake   /ELiZ

}
void AAGP_GameCoOp::CheckScore(AAA2_PlayerState* Scorer)
{
	/*
	local AGP.AGP_Objective obj;
	local AGP_TriggeredObjective trigObj;
	local Controller C;
	local bool bFoundSomeone;
	if (!IsInState('MatchInProgress'))
	{
		Return;
	}
	obj = firstObjective;
	if (obj != None)
	{
		if (!obj.IsRequired() || !obj.IsEnabled())
		{
		}
		trigObj = AGP_TriggeredObjective(obj);
		if (trigObj == nullptr || trigObj.MustBeClass == nullptr)
		{
		}
		bFoundSomeone = False;
		C = Level.ControllerList;
		if (C != None)
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
			Switch(trigObj.AttackTeam)
			{
					case 0:
						PendingEndGame(Teams[1].GetSquadLeader(None), "ObjectiveImpossible");
						Return;
					case 1:
						PendingEndGame(Teams[0].GetSquadLeader(None), "ObjectiveImpossible");
						Return;
					default:
						PendingEndGame(None, "ObjectiveImpossible");
						Return;
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
