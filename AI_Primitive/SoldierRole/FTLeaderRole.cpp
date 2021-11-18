// All the original content belonged to the US Army


#include "FTLeaderRole.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"

AFTLeaderRole::AFTLeaderRole()
{
	TeamClassName = "AGP_Characters.ClassRifleman";
}



void AFTLeaderRole::GetDestination(AAGP_Pawn* Leader)
{
	/*
	local FVector Destination;
	Destination = Leader.Location;
	Destination.Y -= 500;
	Return Destination;
	*/
}

void AFTLeaderRole::spawnNewRole()
{
	/*
	Return Spawn('FTLeaderRole');
	*/
}
void AFTLeaderRole::spawnSubordinateRole()
{
	/*
	Return Spawn('FTMemberRole');
	*/
}
void AFTLeaderRole::getUnitSize()
{
	/*
	Return my_AGP_Pawn.nSubordinates + 1;
	*/
}
void AFTLeaderRole::getUnitLeader()
{
	/*
	Return my_AGP_Pawn.Leader;
	*/
}
ESoldierRole AFTLeaderRole::getRole()
{
	return ESoldierRole::ROLE_FTLeader;
}
void AFTLeaderRole::GetTeamClass()
{
	/*
	Return class<Actor>(DynamicLoadObject("AGP_Characters.ClassRifleman", Class'Class'));
	*/
}
