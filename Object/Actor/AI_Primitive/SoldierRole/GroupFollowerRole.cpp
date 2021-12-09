// All the original content belonged to the US Army


#include "GroupFollowerRole.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"

AGroupFollowerRole::AGroupFollowerRole()
{

}


void AGroupFollowerRole::spawnNewRole()
{
	/*
	Return Spawn('GroupFollowerRole');
	*/
}
int32 AGroupFollowerRole::getUnitSize()
{
	return 1;
}
void AGroupFollowerRole::getUnitLeader()
{
	/*
	Return my_AGP_Pawn.Leader;
	*/
}
ESoldierRole AGroupFollowerRole::getRole()
{
	return ESoldierRole::ROLE_GroupFollower;
}
bool AGroupFollowerRole::squadBasedRole()
{
	return false;
}
