// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCRecruiterController/NPCRecruiterController.h"
#include "NPCACUSoldierController.generated.h"

UCLASS()
class ANPCACUSoldierController : public ANPCRecruiterController
{
	GENERATED_BODY()
public:
	ANPCACUSoldierController();

	void InitializePawn();
	void ShoulderWeapon();
	void Start();
	bool UsedBy(APawn* User);
};
