// All the original content belonged to the US Army

#include "AA29/Object/Actor/AI_Primitive/SoldierRole/FTMemberRole.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/Object/Actor/AI_Primitive/SoldierRole/SoldierRole.h"

AFTMemberRole::AFTMemberRole()
{

}

FVector AFTMemberRole::GetDestination(AAGP_Pawn* Leader)
{
	FVector Destination = FVector(0,0,0);
	Destination = Leader->GetActorLocation();
	Destination.Y -= 150;
	return Destination;
}

ASoldierRole* AFTMemberRole::spawnNewRole()
{
	//return Spawn('FTMemberRole');
	return nullptr;    //FAKE   /EliZ
}

int32 AFTMemberRole::getUnitSize()
{
	return 1;
}

AAGP_Pawn* AFTMemberRole::getUnitLeader()
{
	return my_AGP_Pawn->Leader->Leader;
}

ESoldierRole AFTMemberRole::getRole()
{
	return ESoldierRole::ROLE_FTMember;
}

AActor* AFTMemberRole::GetTeamClass()
{
	//return class<Actor>(DynamicLoadObject("AGP_Characters.ClassGrenadier", Class'Class'));
	return nullptr;    //FAKE   /EliZ
}
