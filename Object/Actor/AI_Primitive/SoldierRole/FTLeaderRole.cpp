// All the original content belonged to the US Army

#include "AA29/Object/Actor/AI_Primitive/SoldierRole/FTLeaderRole.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/Object/Actor/AI_Primitive/SoldierRole/SoldierRole.h"

AFTLeaderRole::AFTLeaderRole()
{
	TeamClassName = "AGP_Characters.ClassRifleman";
}

FVector AFTLeaderRole::GetDestination(AAGP_Pawn* Leader)
{
	FVector Destination = FVector(0,0,0);
	/*
	Destination = Leader.Location;
	Destination.Y -= 500;
	*/
	return Destination;
}

ASoldierRole* AFTLeaderRole::spawnNewRole()
{
	//return Spawn('FTLeaderRole');
	return nullptr;  //FAKE   /EliZ
}

ASoldierRole* AFTLeaderRole::spawnSubordinateRole()
{
	//return Spawn('FTMemberRole');
	return nullptr;  //FAKE   /EliZ
}

int32 AFTLeaderRole::getUnitSize()
{
	return my_AGP_Pawn->nSubordinates + 1;
}

AAGP_Pawn* AFTLeaderRole::getUnitLeader()
{
	return my_AGP_Pawn->Leader;
}

ESoldierRole AFTLeaderRole::getRole()
{
	return ESoldierRole::ROLE_FTLeader;
}

AActor* AFTLeaderRole::GetTeamClass()
{
	//return class<Actor>(DynamicLoadObject("AGP_Characters.ClassRifleman", Class'Class'));
	return nullptr;  //FAKE   /EliZ
}
