// All the original content belonged to the US Army

#include "AA29/Object/Actor/AI_Primitive/SoldierRole/SquadLeaderRole.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/Object/Actor/AI_Primitive/SoldierRole/SoldierRole.h"

ASquadLeaderRole::ASquadLeaderRole()
{

}

FVector ASquadLeaderRole::GetDestination(AAGP_Pawn* Leader)
{
	return my_AGP_Pawn->GetActorLocation();
}

ASoldierRole* ASquadLeaderRole::spawnNewRole()
{
	//return Spawn('SquadLeaderRole');
	return nullptr;    //FAKE  /ELiZ
}

ASoldierRole* ASquadLeaderRole::spawnSubordinateRole()
{
	//return Spawn('FTLeaderRole');
	return nullptr;    //FAKE  /ELiZ
}

AAGP_Pawn* ASquadLeaderRole::getUnitLeader()
{
	if (my_AGP_Pawn->nSubordinates == 0)
	{
		return my_AGP_Pawn;
	}
	return my_AGP_Pawn->Subordinate[0]->Leader;
}

ESoldierRole ASquadLeaderRole::getRole()
{
	return ESoldierRole::ROLE_SquadLeader;
}

AActor* ASquadLeaderRole::GetTeamClass()
{
	//return class<Actor>(DynamicLoadObject("AGP_Characters.Sniper", Class'Class'));
	return nullptr;    //FAKE  /ELiZ
}
