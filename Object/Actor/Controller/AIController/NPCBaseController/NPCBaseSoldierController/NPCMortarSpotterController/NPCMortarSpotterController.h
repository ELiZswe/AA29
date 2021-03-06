// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCBaseSoldierController/NPCBaseSoldierController.h"
#include "NPCMortarSpotterController.generated.h"

UCLASS()
class ANPCMortarSpotterController : public ANPCBaseSoldierController
{
	GENERATED_BODY()
public:
	ANPCMortarSpotterController();

	UPROPERTY()					int32							iTotalSquadMates;				//var int32 iTotalSquadMates;
	UPROPERTY()					FVector							vLastValidNoiseHeard;			//var FVector vLastValidNoiseHeard;
	UPROPERTY()					bool							bWatchingFireMission;			//var bool bWatchingFireMission;
	UPROPERTY()					FVector							vCurrentFireMissionLocation;	//var FVector vCurrentFireMissionLocation;
	UPROPERTY()					APawn*							pawnLastConsidered;				//var APawn* pawnLastConsidered;
	UPROPERTY()					APawn*							pawnLastTargeted;				//var APawn* pawnLastTargeted;
	UPROPERTY()					float							fpTimeLastFireMission;			//var float fpTimeLastFireMission;
	UPROPERTY()					bool							bSmokeAssaultLocation;			//var bool bSmokeAssaultLocation;
	UPROPERTY()					TArray<FFireMissionRequests>	afmrFireMissions;				//var TArray<FireMissionRequests> afmrFireMissions;

	void PostBeginPlay();
	void Start();
	void FireMissionComplete(FVector vLocation);
	void FireMissionInProgress(FVector vLocation);
	void AddFireMissionRequest(FVector vLocation, APawn* pawnTarget);
	bool IsValidFireMissionRequest(FVector vLocation, APawn* pawnSeen);
	bool CallInFireMission(APawn* pawnSeen, bool bSmokeMission, bool bHEAssaultLocation);
};
