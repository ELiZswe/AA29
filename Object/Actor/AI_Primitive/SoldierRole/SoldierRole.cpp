// All the original content belonged to the US Army


#include "SoldierRole.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"

ASoldierRole::ASoldierRole()
{
	TeamClassName = "AGP_Characters.ClassGrenadier";
}



void ASoldierRole::GetDestination(AAGP_Pawn* Leader)
{
	//Return my_AGP_Pawn.Location;
}

void ASoldierRole::spawnNewRole()
{
	/*
	Return Spawn(Self.Class);
	*/
}
void ASoldierRole::spawnSubordinateRole()
{
}
void ASoldierRole::getUnitSize()
{
	/*
	local int i;
	local int unit_size;
	unit_size = 1;
	for (i = 0; i < my_AGP_Pawn.nSubordinates; i++)
	{
		unit_size += my_AGP_Pawn.Subordinate[i].TeamRole.getUnitSize();
	}
	Return unit_size;
	*/
}
void ASoldierRole::getMentalModel()
{
	/*
	Return my_AGP_Pawn.getMentalModel();
	*/
}
void ASoldierRole::getUnitLeader()
{
}
ESoldierRole ASoldierRole::getRole()
{
	return ESoldierRole::ROLE_Error;	//this function should always be overridden
}
bool ASoldierRole::squadBasedRole()
{
	return true;
}
void ASoldierRole::GetTeamClass()
{
}
