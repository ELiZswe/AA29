// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCBaseSoldierController/NPCNCOController/NPCNCOController.h"
#include "NPCOfficerController.generated.h"

class ANPCBaseSoldierController;
UCLASS()
class ANPCOfficerController : public ANPCNCOController
{
	GENERATED_BODY()
public:
	ANPCOfficerController();

	void CalculateLeadershipBonus();
	int32 GetLeadershipBonus(ANPCBaseSoldierController* npcbscRequestingBonus);
	void PostBeginPlay();
	void SquadMateHit(ANPCBaseSoldierController* npcbscHitNPC, APawn* pawnInstigator);
};
