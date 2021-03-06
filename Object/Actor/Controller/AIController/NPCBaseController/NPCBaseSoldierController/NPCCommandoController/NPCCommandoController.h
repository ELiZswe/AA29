// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCBaseSoldierController/NPCBaseSoldierController.h"
#include "NPCCommandoController.generated.h"

UCLASS()
class ANPCCommandoController : public ANPCBaseSoldierController
{
	GENERATED_BODY()
public:
	ANPCCommandoController();

	void PostBeginPlay();
	bool IsConcerned();
};
