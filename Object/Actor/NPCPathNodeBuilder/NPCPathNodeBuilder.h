// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NPCPathNodeBuilder.generated.h"

class ANavigationPoint;
class ANPCRoadPathNode;
class ANPCPlayerStart;
class AStudentController;

UCLASS()
class ANPCPathNodeBuilder : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANPCPathNodeBuilder();


	UPROPERTY()						TArray<ANavigationPoint*>		anpcpnPathNodes;							//var TArray<NavigationPoint> anpcpnPathNodes;
	UPROPERTY()						TArray<ANPCRoadPathNode*>		anpcpnRoadPathNodes;						//var TArray<NPCRoadPathNode> anpcpnRoadPathNodes;
	UPROPERTY()						ANavigationPoint*				npcpnLastDroppedPathNode;					//var NavigationPoint npcpnLastDroppedPathNode;
	UPROPERTY()						ANavigationPoint*				npcpnNodeBeingEdited;						//var NavigationPoint npcpnNodeBeingEdited;
	UPROPERTY()						ANavigationPoint*				npcpnNodeBeingDeleted;						//var NavigationPoint npcpnNodeBeingDeleted;
	UPROPERTY()						ANavigationPoint*				npcpnNodeLastEdited;						//var NavigationPoint npcpnNodeLastEdited;
	UPROPERTY()						TArray<ANPCPlayerStart*>		anpcpsPlayerStarts;							//var TArray<NPCPlayerStart> anpcpsPlayerStarts;
	UPROPERTY()						ANPCPlayerStart*				npcpsBeingEdited;							//var NPCPlayerStart npcpsBeingEdited;
	UPROPERTY()						ANPCPlayerStart*				npcpsBeingDeleted;							//var NPCPlayerStart npcpsBeingDeleted;
	UPROPERTY()						float							fpTimeSinceDeleteRequest;					//var float fpTimeSinceDeleteRequest;
	UPROPERTY()						float							fpTimeSinceLastMenuActivationButton;		//var float fpTimeSinceLastMenuActivationButton;
	UPROPERTY()						float							fpTimeSinceLastMenuIconClicked;				//var float fpTimeSinceLastMenuIconClicked;
	UPROPERTY()						FVector							vLastTestedAutoDropLocation;				//var Vector vLastTestedAutoDropLocation;
	UPROPERTY()						FVector							vLastLocationTestedForAutoDrop;				//var Vector vLastLocationTestedForAutoDrop;
	UPROPERTY()						FRotator						vLastTestedAutoDropRotation;				//var Rotator vLastTestedAutoDropRotation;
	UPROPERTY()						bool							bEnabledPathBuilding;						//var bool bEnabledPathBuilding;
	UPROPERTY()						bool							bPathNodingPaused;							//var bool bPathNodingPaused;
	UPROPERTY()						AStudentController*				scOwner;									//var StudentController scOwner;
	UPROPERTY()						FString							sWaypointNavTag;							//var FString sWaypointNavTag;
	UPROPERTY()						int32							iWaypointIndex;								//var int32 iWaypointIndex;
	UPROPERTY()						float							fpTimeSinceLastNodeCheck;					//var float fpTimeSinceLastNodeCheck;
	UPROPERTY()						bool							bInAutoDropMode;							//var bool bInAutoDropMode;
	UPROPERTY()						float							fpTimeSinceResetPathsRequest;				//var float fpTimeSinceResetPathsRequest;
	UPROPERTY()						bool							bBusyLoading;								//var bool bBusyLoading;
	UPROPERTY()						bool							bOnLadder;									//var bool bOnLadder;
	UPROPERTY()						FString							sCurrentPNBFileName;						//var FString sCurrentPNBFileName;
	UPROPERTY()						TArray<FString>					asPNBFileList;								//var TArray<FString> asPNBFileList;

	bool SavePathNodes(FString sFileName);
	bool LoadPathNodes(FString sFileName);
	int32 GetMouseX();
	int32 GetMouseY();
	void SetCurrentWaypointNodeTag(FString sNewTag);
	void EnableTransientNaming(bool bUseTransient);
	void BuildAndTestPaths();
	void BuildFinalPaths(FString sMapNameToSave);
	void GetPathNodeFileList();
	void SetPathBuilderOwner(AStudentController* SC);
	void TestPathNodes();
	void SaveFinalMapPaths(FString sFinalMapName);
	FString GetPNBFileName();
	void SavePathNodesToFile(FString sFileName);
	void LoadPathNodesFromFile(FString sFileName);
	void EnablePathBuilding(bool bEnable);
	void RequestResetPaths();
	void ResetPathBuilding();
	void PausePathBuilding(bool bPause);
	bool CanDropNode(bool bAutoDropTest);
	ANPCPlayerStart* DropNPCPlayerStart(FString sType);
	bool DropCustomNode(FString sType);
	void ManNodePosition();
	void SetFireWeaponPosture();
	void SetValidGrenadePosture();
	void DropNode(bool bIsAutoDrop);
	void DropRoadNode(bool bIsAutoDrop);
	bool CanDropNodeAtLocation(FVector vDesiredLocation);
	void AutoDropNodeLastGoodLocation();
	void StartNewPatrolPathSetupPage();
	void StartNewPatrolPath(FString sWaypointTag);
	void EndPatrolPath();
	void DropWaypointNode();
	void ClientMessage(FString sMsg);
	void StartAutoDropMode();
	void EndAutoDropMode();
	void EnteringLadderVolume();
	void ExitingLadderVolume();
	void MoverUsed();
	void Action();
	void ForceConnection();
	void RequestDeleteNode();
	void EditRotationAndPosture();
	void SetCurrentNodeTag(FString sNewTag);
	void SetNPCName(FString sNewName);
	bool IsLocationInFrontOfOwner(FVector vLocation);
	float GetAngleFromOwner(FVector vLocation);
	void ProcessMenuIconClick();
	void Tick(float DeltaTime);
	bool CanSeeFullPathToLastNode();
	void ImportPaths();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
