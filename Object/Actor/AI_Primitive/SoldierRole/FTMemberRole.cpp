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
	return Destination;
	*/
}
void AFTMemberRole::spawnNewRole()
{
	/*
	return Spawn('FTMemberRole');
	*/
}

int32 AFTMemberRole::getUnitSize()
{
	return 1;
}
void AFTMemberRole::getUnitLeader()
{
	/*
	return my_AGP_Pawn.Leader.Leader;
	*/
}
ESoldierRole AFTMemberRole::getRole()
{
	return ESoldierRole::ROLE_FTMember;
}
void AFTMemberRole::GetTeamClass()
{
	/*
	return class<Actor>(DynamicLoadObject("AGP_Characters.ClassGrenadier", Class'Class'));
	*/
}
