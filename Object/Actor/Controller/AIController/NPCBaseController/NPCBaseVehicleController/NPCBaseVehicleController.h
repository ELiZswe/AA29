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

	UPROPERTY()		AVehicle*					agpvVehicle;						//var AVehicle* agpvVehicle;
	UPROPERTY()		AAA2_PlayerState*			priFromNPCPawn;						//var AAA2_PlayerState* priFromNPCPawn;
	UPROPERTY()		ANPCRoadPathNode*			pnCurrentRoadPathNode;				//var ANPCRoadPathNode* pnCurrentRoadPathNode;
	UPROPERTY()		TArray<ANPCRoadPathNode*>	apnDrivingPathNodesForPatrol;		//var TArray<NPCRoadPathNode> apnDrivingPathNodesForPatrol;
	UPROPERTY()		int32						iCurrentDrivingPathNodeIndex;		//var int32 iCurrentDrivingPathNodeIndex;

	void Start();
	//void Possess(APawn* aPawn);
	void PreloadPathNodeList();
	ANPCRoadPathNode* FindNextDrivingPatrolPathNode();
	//void UnPossess();
	float PlayCustomAnimation(FName nameAnimation, bool bLoop, float fpRate);
	void NPCLog(FString sLogText);
};
