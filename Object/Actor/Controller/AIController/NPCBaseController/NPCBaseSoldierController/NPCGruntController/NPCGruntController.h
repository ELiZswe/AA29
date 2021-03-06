// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCBaseSoldierController/NPCBaseSoldierController.h"
#include "NPCGruntController.generated.h"

UCLASS()
class ANPCGruntController : public ANPCBaseSoldierController
{
	GENERATED_BODY()
public:
	ANPCGruntController();

	UPROPERTY()		int32	iTotalSquadMates;		//var int32 iTotalSquadMates;

	void PostBeginPlay();
};
