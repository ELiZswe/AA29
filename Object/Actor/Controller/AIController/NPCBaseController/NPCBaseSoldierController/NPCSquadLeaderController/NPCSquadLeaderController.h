// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCBaseSoldierController/NPCBaseSoldierController.h"
#include "NPCSquadLeaderController.generated.h"

class ANPCBaseSoldierController;
UCLASS()
class ANPCSquadLeaderController : public ANPCBaseSoldierController
{
	GENERATED_BODY()
public:
	ANPCSquadLeaderController();

	UPROPERTY()				int32 iTotalSquadMates;							//	var int32 iTotalSquadMates;

	void PostBeginPlay();
	void SquadMateHit(ANPCBaseSoldierController* npcbscHitNPC, APawn* pawnInstigator);
};
