// All the original content belonged to the US Army

#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCBaseSoldierController/NPCNCOController/NPCNCOController.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCBaseSoldierController/NPCNCOController/NPCOfficerController/NPCOfficerController.h"

ANPCNCOController::ANPCNCOController()
{
	fpNPCWeaponAccuracy = 80;
	fNPCExperience = 75;
	fpMortarRequestSkill = 25;
}

void ANPCNCOController::PostBeginPlay()
{
	ANPCBaseSoldierController* npcbscIterator = nullptr;
	/*
	Super::PostBeginPlay();
	NPCLog("NPCNCOController.PostBeginPlay() entered");
	iTotalSquadMates = 0;
	ForEach AllActors(class'AGP.NPCBaseSoldierController', npcbscIterator)
	{
		if (float(iSquadID) ~= float(npcbscIterator.iSquadID))
		{
			iTotalSquadMates++;
		}
	}
	NPCLog("NPCNCOController - Total squad mates for squad \"" $ string(iSquadID) $ "\": " $ string(iTotalSquadMates));
	*/
}

void ANPCNCOController::SquadMateHit(ANPCBaseSoldierController* npcbscHitNPC, APawn* pawnInstigator)
{
	ANPCBaseSoldierController* npcbscIterator = nullptr;
	int32 iLiveSquadMates = 0;
	/*
	ForEach AllActors(class'AGP.NPCBaseSoldierController', npcbscIterator)
	{
		if (float(iSquadID) ~= float(npcbscIterator.iSquadID))
		{
			iLiveSquadMates++;
		}
	}
	*/
}

void ANPCNCOController::CalculateLeadershipBonus()
{
	ANPCOfficerController* npcbscIterator = nullptr;
	/*
	fpCurrentLeadershipBonus = 0;
	ForEach AllActors(class'AGP.NPCOfficerController', npcbscIterator)
	{
		if (npcbscIterator != Self)
		{
			fpCurrentLeadershipBonus = float(npcbscIterator.GetLeadershipBonus(Self));
		}
		else
		{
		}
	}
	*/
}

int32 ANPCNCOController::GetLeadershipBonus(ANPCBaseSoldierController* npcbscRequestingBonus)
{
	/*
	if (npcbscRequestingBonus->Pawn != nullptr)
	{
		if (VSize((npcbscRequestingBonus->Pawn->Location - Pawn->Location)) < float(iNPCLeadershipMentalStateRange))
		{
			return iNPCLeadershipMentalStateBonus;
		}
	}
	*/
	return 0;
}