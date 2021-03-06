// All the original content belonged to the US Army

#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCBaseSoldierController/NPCSquadLeaderController/NPCSquadLeaderController.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCBaseSoldierController/NPCBaseSoldierController.h"

ANPCSquadLeaderController::ANPCSquadLeaderController()
{

}

void ANPCSquadLeaderController::PostBeginPlay()
{
	ANPCBaseSoldierController* npcbscIterator = nullptr;
	Super::PostBeginPlay();
	/*
	Log("NPCBaseController.PostBeginPlay() entered");
	iTotalSquadMates = 0;
	ForEach AllActors(ANPCBaseSoldierController::StaticClass(), npcbscIterator)
	{
		if (float(iSquadID) ~= float(npcbscIterator.iSquadID))
		{
			iTotalSquadMates++;
		}
	}
	Log("Total squad mates for squad \"" + FString::FromInt(iSquadID) + "\": " + FString::FromInt(iTotalSquadMates));
	*/
}

void ANPCSquadLeaderController::SquadMateHit(ANPCBaseSoldierController* npcbscHitNPC, APawn* pawnInstigator)
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


