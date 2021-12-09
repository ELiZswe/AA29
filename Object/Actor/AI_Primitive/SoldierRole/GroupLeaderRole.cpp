// All the original content belonged to the US Army


#include "GroupLeaderRole.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"

AGroupLeaderRole::AGroupLeaderRole()
{

}

void AGroupLeaderRole::spawnNewRole()
{
	/*
	Return Spawn('GroupLeaderRole');
	*/
}
void AGroupLeaderRole::spawnSubordinateRole()
{
	/*
	Return Spawn('GroupFollowerRole');
	*/
}
void AGroupLeaderRole::getUnitSize()
{
	/*
	Return my_AGP_Pawn.nSubordinates + 1;
	*/
}
void AGroupLeaderRole::getUnitLeader()
{
	/*
	if (my_AGP_Pawn.nSubordinates == 0)
	{
		Return my_AGP_Pawn;
	}
	else
	{
		Return my_AGP_Pawn.Subordinate[0].Leader;
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
