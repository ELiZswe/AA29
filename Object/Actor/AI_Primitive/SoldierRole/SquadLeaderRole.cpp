// All the original content belonged to the US Army

#include "SquadLeaderRole.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"

ASquadLeaderRole::ASquadLeaderRole()
{

}

void ASquadLeaderRole::GetDestination(AAGP_Pawn* Leader)
{
	/*
	return my_AGP_Pawn.Location;
	*/
}
void ASquadLeaderRole::spawnNewRole()
{
	/*
	return Spawn('SquadLeaderRole');
	*/
}
void ASquadLeaderRole::spawnSubordinateRole()
{
	/*
	return Spawn('FTLeaderRole');
	*/
}
void ASquadLeaderRole::getUnitLeader()
{
	/*
	if (my_AGP_Pawn.nSubordinates == 0)
	{
		return my_AGP_Pawn;
	}
	return my_AGP_Pawn.Subordinate[0].Leader;
	*/
}
ESoldierRole ASquadLeaderRole::getRole()
{
	return ESoldierRole::ROLE_SquadLeader;
}
void ASquadLeaderRole::GetTeamClass()
{
	/*
	return class<Actor>(DynamicLoadObject("AGP_Characters.Sniper", Class'Class'));
	*/
}
