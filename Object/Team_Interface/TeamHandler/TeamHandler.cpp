// All the original content belonged to the US Army

#include "AA29/Object/Team_Interface/TeamHandler/TeamHandler.h"
#include "AA29/Object/Actor/AI_Primitive/SoldierRole/SoldierRole.h"
#include "AA29/Object/Actor/AI_Primitive/MentalModel/MentalModel.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"

UTeamHandler::UTeamHandler()
{

}

AMentalModel* UTeamHandler::getMentalModel()
{
	return _teamMentalModel;
}

int32 UTeamHandler::getTeamSize()
{
	int32 i = 0;
	int32 TEAM_SIZE = 0;
	TEAM_SIZE=0;

	for (i=0; i<nSubordinates; i++)
	{
		TEAM_SIZE += Subordinate[i]->TeamRole->getUnitSize();
	}
	return TEAM_SIZE;
}

void UTeamHandler::printTeam()
{
	int32 i = 0;
	int32 j = 0;
	for (i=0; i<nSubordinates; i++)
	{
		for (j=0; j<Subordinate[i]->nSubordinates; j++)
		{

		}
	}
}

bool UTeamHandler::replaceSubordinate(AAGP_Pawn* old_sub, AAGP_Pawn* new_sub)
{
	int32 i = 0;
	for (i=0; i<nSubordinates; i++)
	{
		if (Subordinate[i] == old_sub)
		{
			Subordinate[i]=new_sub;
			return true;
		}
	}
	return false;
}

void UTeamHandler::addPawn(AAGP_Pawn* Add)
{
	int32 i = 0;
	int32 unit_number = 0;
	AAGP_Pawn* Leader = nullptr;
	bool bNewTeam = false;
	/*
	unit_number=Add.idUnitNumber;
	Add.DebugLog(8,"dnback:: TeamHandler.addPawn(); adding " + Add.Name + " to the team");
	if (bTeamReady == false)
	{
		Leader=Subordinate[unit_number];
		if (Leader == nullptr)
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
		bNewTeam=true;
		i=0;
		if (i < nSubordinates)
		{
			if (Subordinate[i].idUnitNumber == unit_number)
			{
				bNewTeam=false;
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

bool UTeamHandler::replaceLeader(AAGP_Pawn* Leader, AAGP_Pawn* Replace)
{
	if (Leader->idRole == ERole::STARTROLE_UnitLeader)
	{
		if (Replace->idRole == ERole::STARTROLE_UnitLeader && Replace->rank > Leader->rank)
		{
			return true;
		}
		return false;
	}
	else
	{
		if (Replace->idRole == ERole::STARTROLE_UnitLeader || Replace->rank > Leader->rank)
		{
			return true;
		}
		return false;
	}
}

void UTeamHandler::Init()
{
	int32 i = 0;
	int32 j = 0;
	nSubordinates=16;
	for (i=0; i<nSubordinates; i++)
	{
		if (Subordinate[i] == nullptr)
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
			Subordinate[i]->idUnitNumber=i;
			initLeader(Subordinate[i]);
		}
	}
	printTeam();
	bTeamReady=true;
}

void UTeamHandler::initLeader(AAGP_Pawn* Leader)
{
	int32 i = 0;
	AAGP_Pawn* Follower = nullptr;
	//Leader->TeamRole=Leader.Spawn('GroupLeaderRole');
	Leader->TeamRole->my_AGP_Pawn=Leader;
	Leader->idRole = ERole::STARTROLE_UnitLeader;
	if (Leader->idRank == ERank::RANK_UnAssigned)
	{
		Leader->idRank= ERank::RANK_E6_SSG;
	}
	Leader->fLeadership = Range( 0.5,1 );
	Leader->createMentalModel();
	Leader->Team=this;
	for (i=0; i<Leader->nSubordinates; i++)
	{
		Follower=Leader->Subordinate[i];
		//Follower->TeamRole=Follower.Spawn('GroupFollowerRole');
		Follower->TeamRole->my_AGP_Pawn=Follower;
		Follower->idRole = ERole::STARTROLE_UnitFollower;
		if (Follower->idRank == ERank::RANK_UnAssigned)
		{
			Follower->idRank = ERank::RANK_E3_PFC;
		}
		Follower->fLeadership = Range(0.2,0.9);
		Follower->Leader=Leader;
		Follower->resetMentalModel();
		Follower->idUnitNumber=Leader->idUnitNumber;
		Follower->Team=Leader->Team;
	}
}

float UTeamHandler::Range(float val1, float val2)
{
	if (val1 < val2)
	{
		return (val1 + ((val2 - val1) * FMath::FRand()));
	}
	else
	{
		return (val2 + ((val1 - val2) * FMath::FRand()));
	}
	return 0;    //FAKE   /EliZ
}
