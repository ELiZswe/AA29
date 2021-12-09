// All the original content belonged to the US Army


#include "FTMemberRole.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"

AFTMemberRole::AFTMemberRole()
{

}


void AFTMemberRole::GetDestination(AAGP_Pawn* Leader)
{
	/*
	local FVector Destination;
	Destination = Leader.Location;
	Destination.Y -= 150;
	Return Destination;
	*/
}
void AFTMemberRole::spawnNewRole()
{
	/*
	Return Spawn('FTMemberRole');
	*/
}

int32 AFTMemberRole::getUnitSize()
{
	return 1;
}
void AFTMemberRole::getUnitLeader()
{
	/*
	Return my_AGP_Pawn.Leader.Leader;
	*/
}
ESoldierRole AFTMemberRole::getRole()
{
	return ESoldierRole::ROLE_FTMember;
}
void AFTMemberRole::GetTeamClass()
{
	/*
	Return class<Actor>(DynamicLoadObject("AGP_Characters.ClassGrenadier", Class'Class'));
	*/
}
