// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCBaseSoldierController/NPCBaseSoldierController.h"
#include "NPCNCOController.generated.h"

class ANPCBaseSoldierController;
UCLASS()
class ANPCNCOController : public ANPCBaseSoldierController
{
	GENERATED_BODY()
public:
	ANPCNCOController();

	UPROPERTY()		int32		iTotalSquadMates;			//var int32 iTotalSquadMates;

	void PostBeginPlay();
	void SquadMateHit(ANPCBaseSoldierController* npcbscHitNPC, APawn* pawnInstigator);
	void CalculateLeadershipBonus();
	int32 GetLeadershipBonus(ANPCBaseSoldierController* npcbscRequestingBonus);
};
