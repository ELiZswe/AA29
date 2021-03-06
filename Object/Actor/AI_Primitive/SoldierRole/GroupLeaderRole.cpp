// All the original content belonged to the US Army

#include "AA29/Object/Actor/AI_Primitive/SoldierRole/GroupLeaderRole.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/Object/Actor/AI_Primitive/SoldierRole/SoldierRole.h"

AGroupLeaderRole::AGroupLeaderRole()
{

}

ASoldierRole* AGroupLeaderRole::spawnNewRole()
{
	//return Spawn('GroupLeaderRole');
	return nullptr;     //FAKE   /ELiZ
}

ASoldierRole* AGroupLeaderRole::spawnSubordinateRole()
{
	//return Spawn('GroupFollowerRole');
	return nullptr;     //FAKE   /ELiZ
}

int32 AGroupLeaderRole::getUnitSize()
{
	return my_AGP_Pawn->nSubordinates + 1;
}

AAGP_Pawn* AGroupLeaderRole::getUnitLeader()
{
	if (my_AGP_Pawn->nSubordinates == 0)
	{
		return my_AGP_Pawn;
	}
	else
	{
		return my_AGP_Pawn->Subordinate[0]->Leader;
	}
}

ESoldierRole AGroupLeaderRole::getRole()
{
	return ESoldierRole::ROLE_GroupLeader;
}

bool AGroupLeaderRole::squadBasedRole()
{
	return false;
}
