// All the original content belonged to the US Army

#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCBaseSoldierController/NPCNCOController/NPCOfficerController/NPCOfficerController.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCBaseSoldierController/NPCBaseSoldierController.h"

ANPCOfficerController::ANPCOfficerController()
{
	fpMortarRequestSkill = 70;
}

void ANPCOfficerController::CalculateLeadershipBonus()
{
}

int32 ANPCOfficerController::GetLeadershipBonus(ANPCBaseSoldierController* npcbscRequestingBonus)
{
	/*
	if (npcbscRequestingBonus->Pawn != nullptr)
	{
		if (VSize((npcbscRequestingBonus->PawnDied>Pawn-Location - Pawn->Location)) < float(iNPCLeadershipMentalStateRange))
		{
			return iNPCLeadershipMentalStateBonus;
		}
	}
	*/
	return 0;
}

void ANPCOfficerController::PostBeginPlay()
{
	ANPCBaseSoldierController* npcbscIterator = nullptr;
	Super::PostBeginPlay();
	/*
	NPCLog("NPCBaseController.PostBeginPlay() entered");
	iTotalSquadMates = 0;
	ForEach AllActors(ANPCBaseSoldierController::StaticClass(), npcbscIterator)
	{
		if (float(iSquadID) ~= float(npcbscIterator.iSquadID))
		{
			iTotalSquadMates++;
		}
	}
	NPCLog("Total squad mates for squad \"" + FString::FromInt(iSquadID) + "\": " + FString::FromInt(iTotalSquadMates));
	*/
}

void ANPCOfficerController::SquadMateHit(ANPCBaseSoldierController* npcbscHitNPC, APawn* pawnInstigator)
{
	ANPCBaseSoldierController* npcbscIterator = nullptr;
	int32 iLiveSquadMates = 0;
	/*
	ForEach AllActors(ANPCBaseSoldierController::StaticClass(), npcbscIterator)
	{
		if (float(iSquadID) ~= float(npcbscIterator.iSquadID))
		{
			iLiveSquadMates++;
		}
	}
	*/
}
