// All the original content belonged to the US Army

#include "GroupLeaderRole.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"

AGroupLeaderRole::AGroupLeaderRole()
{

}

void AGroupLeaderRole::spawnNewRole()
{
	/*
	return Spawn('GroupLeaderRole');
	*/
}
void AGroupLeaderRole::spawnSubordinateRole()
{
	/*
	return Spawn('GroupFollowerRole');
	*/
}
void AGroupLeaderRole::getUnitSize()
{
	/*
	return my_AGP_Pawn.nSubordinates + 1;
	*/
}
void AGroupLeaderRole::getUnitLeader()
{
	/*
	if (my_AGP_Pawn.nSubordinates == 0)
	{
		return my_AGP_Pawn;
	}
	else
	{
		return my_AGP_Pawn.Subordinate[0].Leader;
	}
	*/
}
ESoldierRole AGroupLeaderRole::getRole()
{
	return ESoldierRole::ROLE_GroupLeader;
}
bool AGroupLeaderRole::squadBasedRole()
{
	return false;
}
