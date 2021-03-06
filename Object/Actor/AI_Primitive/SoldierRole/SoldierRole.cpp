// All the original content belonged to the US Army

#include "AA29/Object/Actor/AI_Primitive/SoldierRole/SoldierRole.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/Object/Actor/AI_Primitive/MentalModel/MentalModel.h"

ASoldierRole::ASoldierRole()
{
	TeamClassName = "AGP_Characters.ClassGrenadier";
}

FVector ASoldierRole::GetDestination(AAGP_Pawn* Leader)
{
	return my_AGP_Pawn->GetActorLocation();
}

ASoldierRole* ASoldierRole::spawnNewRole()
{
	//return Spawn(Self.Class);
	return nullptr;    //FAKE   /ELiZ
}

ASoldierRole* ASoldierRole::spawnSubordinateRole()
{
	return nullptr;    //FAKE   /ELiZ
}

int32 ASoldierRole::getUnitSize()
{
	int32 i = 0;
	int32 unit_size = 0;
	unit_size = 1;
	for (i = 0; i < my_AGP_Pawn->nSubordinates; i++)
	{
		unit_size += my_AGP_Pawn->Subordinate[i]->TeamRole->getUnitSize();
	}
	return unit_size;
}

AMentalModel* ASoldierRole::getMentalModel()
{
	return my_AGP_Pawn->getMentalModel();
}

AAGP_Pawn* ASoldierRole::getUnitLeader()
{
	return nullptr;    //FAKE   /ELiZ
}

ESoldierRole ASoldierRole::getRole()
{
	return ESoldierRole::ROLE_Error;	//this function should always be overridden
}

bool ASoldierRole::squadBasedRole()
{
	return true;
}

AActor* ASoldierRole::GetTeamClass()
{
	return nullptr;    //FAKE   /ELiZ
}
