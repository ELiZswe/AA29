// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCBaseController.h"
#include "NPCBaseVehicleController.generated.h"

class ANPCRoadPathNode;

UCLASS()
class ANPCBaseVehicleController : public ANPCBaseController
{
	GENERATED_BODY()
public:
	ANPCBaseVehicleController();

	void Start();
	//void Possess(APawn* aPawn);
	void PreloadPathNodeList();
	ANPCRoadPathNode* FindNextDrivingPatrolPathNode();
	//void UnPossess();
	float PlayCustomAnimation(FName nameAnimation, bool bLoop, float fpRate);
	void NPCLog(FString sLogText);
};
