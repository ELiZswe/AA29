// All the original content belonged to the US Army

#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCBaseSoldierController/NPCCommandoController/NPCCommandoController.h"

ANPCCommandoController::ANPCCommandoController()
{

}

void ANPCCommandoController::PostBeginPlay()
{
	Super::PostBeginPlay();
}

bool ANPCCommandoController::IsConcerned()
{
	return false;
}


