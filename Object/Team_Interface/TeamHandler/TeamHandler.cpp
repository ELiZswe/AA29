// All the original content belonged to the US Army


#include "TeamHandler.h"

UTeamHandler::UTeamHandler()
{

}

void UTeamHandler::getMentalModel()
{
	/*
		Return _teamMentalModel;
	*/
}
void UTeamHandler::getTeamSize()
{
	/*
		local int i;
		local int TEAM_SIZE;
		TEAM_SIZE=0;
		for (i=0; i<nSubordinates; i++)
		{
			TEAM_SIZE += Subordinate[i].TeamRole.getUnitSize();
		}
		Return TEAM_SIZE;
	*/
}
void UTeamHandler::printTeam()
{
	/*
		local int i;
		local int j;
		for (i=0; i<nSubordinates; i++)
		{
			for (j=0; j<Subordinate[i].nSubordinates; j++)
			{
			}
		}
	*/
}
void UTeamHandler::replaceSubordinate(AAGP_Pawn* old_sub, AAGP_Pawn* new_sub)
{
	/*
		local int i;
		for (i=0; i<nSubordinates; i++)
		{
			if (Subordinate[i] == old_sub)
			{
				Subordinate[i]=new_sub;
				Return True;
			}
		}
		Return False;
	*/
}
void UTeamHandler::addPawn(AAGP_Pawn* Add)
{
	/*
		local int i;
		local int unit_number;
		local AGP.AGP_Pawn Leader;
		local bool bNewTeam;
		unit_number=Add.idUnitNumber;
		Add.DebugLog(8,"dnback:: TeamHandler.addPawn(); adding " $ Add.Name $ " to the team");
		if (bTeamReady == false)
		{
			Leader=Subordinate[unit_number];
			if (Leader == None)
			{
				Subordinate[unit_number]=Add;
			}
			else
			{
				if (replaceLeader(Leader,Add) == false)
				{
					if (Add.idRole == 1)
					{
						Log("WARNING TeamHandler::addPawn()	Group already has a leader. Leader pawn becoming follower");
					}
					Leader.addSubordinate(Add);
				}
				else
				{
					for (i=0; i<Leader.nSubordinates; i++)
					{
						Add.addSubordinate(Leader.Subordinate[i]);
					}
					Add.addSubordinate(Leader);
					Leader.nSubordinates=0;
					Subordinate[unit_number]=Add;
				}
			}
		}
		else
		{
			bNewTeam=True;
			i=0;
			if (i < nSubordinates)
			{
				if (Subordinate[i].idUnitNumber == unit_number)
				{
					bNewTeam=False;
					unit_number=i;
				}
				else
				{
					i ++;
				}
			}
			if (bNewTeam == false)
			{
			}
			unit_number=nSubordinates;
			nSubordinates ++;
			Add.idUnitNumber=unit_number;
		}
	*/
}
void UTeamHandler::replaceLeader(AAGP_Pawn* Leader, AAGP_Pawn* Replace)
{
	/*
		if (Leader.idRole == 1)
		{
			if (Replace.idRole == 1 && Replace.rank > Leader.rank)
			{
				Return True;
			}
			Return False;
		}
		else
		{
			if (Replace.idRole == 1 || Replace.rank > Leader.rank)
			{
				Return True;
			}
			Return False;
		}
	*/
}
void UTeamHandler::Init()
{
	/*
		local int i;
		local int j;
		nSubordinates=16;
		for (i=0; i<nSubordinates; i++)
		{
			if (Subordinate[i] == None)
			{
				j=i;
				if (j < nSubordinates - 1)
				{
					Subordinate[j]=Subordinate[j + 1];
					j ++;
				}
				nSubordinates --;
				i --;
			}
			else
			{
				Subordinate[i].idUnitNumber=i;
				initLeader(Subordinate[i]);
			}
		}
		printTeam();
		bTeamReady=True;
	*/
}
void UTeamHandler::initLeader(AAGP_Pawn* Leader)
{
	/*
		local int i;
		local AGP.AGP_Pawn Follower;
		Leader.TeamRole=Leader.Spawn('GroupLeaderRole');
		Leader.TeamRole.my_AGP_Pawn=Leader;
		Leader.idRole=1;
		if (Leader.idRank == 0)
		{
			Leader.idRank=7;
		}
		Leader.fLeadership=Range(0.5,1);
		Leader.createMentalModel();
		Leader.Team=Self;
		for (i=0; i<Leader.nSubordinates; i++)
		{
			Follower=Leader.Subordinate[i];
			Follower.TeamRole=Follower.Spawn('GroupFollowerRole');
			Follower.TeamRole.my_AGP_Pawn=Follower;
			Follower.idRole=0;
			if (Follower.idRank == 0)
			{
				Follower.idRank=3;
			}
			Follower.fLeadership=Range(0.2,0.9);
			Follower.Leader=Leader;
			Follower.resetMentalModel();
			Follower.idUnitNumber=Leader.idUnitNumber;
			Follower.Team=Leader.Team;
		}
	*/
}
void UTeamHandler::Range(float val1, float val2)
{
	/*
		if (val1 < val2)
		{
			Return val1 + val2 - val1 * FRand();
		}
		else
		{
			Return val2 + val1 - val2 * FRand();
		}
	*/
}
