// All the original content belonged to the US Army

#include "AA29/Object/Actor/AI_Primitive/SoldierRole/GroupFollowerRole.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/Object/Actor/AI_Primitive/SoldierRole/SoldierRole.h"

AGroupFollowerRole::AGroupFollowerRole()
{

}

ASoldierRole* AGroupFollowerRole::spawnNewRole()
{
	//return Spawn('GroupFollowerRole');
	return nullptr;   //FAKE   /EliZ
}

int32 AGroupFollowerRole::getUnitSize()
{
	return 1;
}

AAGP_Pawn* AGroupFollowerRole::getUnitLeader()
{
	return my_AGP_Pawn->Leader;
}

ESoldierRole AGroupFollowerRole::getRole()
{
	return ESoldierRole::ROLE_GroupFollower;
}

bool AGroupFollowerRole::squadBasedRole()
{
	return false;
}
