// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/NavigationPoint/PathNode/PathNode.h"
#include "NPCPathNode.generated.h"

class ANPCBaseController;
class ANPCPathNode;

UCLASS()
class ANPCPathNode : public APathNode
{
	GENERATED_BODY()
public:
	ANPCPathNode();

	UPROPERTY()																ANPCBaseController* npcbcUsingHallway;					//var NPCBaseController npcbcUsingHallway;
	UPROPERTY()																ANPCPathNode* npcpnHallwayOtherEnd;						//var NPCPathNode npcpnHallwayOtherEnd;
	UPROPERTY(EditAnywhere, Category = "NPCNodeOptions")					FName nameHallway;										//var(NPCNodeOptions) name nameHallway;
	UPROPERTY()																int32 iNPCOrderTableWaypointIndex;						//var int iNPCOrderTableWaypointIndex;
	UPROPERTY(EditAnywhere, Category = "NPCNodeOptions")					bool bNarrowPassageway;									//var(NPCNodeOptions) bool bNarrowPassageway;
	UPROPERTY(EditAnywhere, Category = "NPCNodeOptions")					float fpMentalStateRecoveryModifier;					//var(NPCNodeBonuses) float fpMentalStateRecoveryModifier;
	UPROPERTY(EditAnywhere, Category = "NPCNodeOptions")					float fpHearingRangeModifier;							//var(NPCNodeBonuses) float fpHearingRangeModifier;
	UPROPERTY(EditAnywhere, Category = "NPCNodeOptions")					float fpVisionConeAngle;								//var(NPCNodeBonuses) float fpVisionConeAngle;
	UPROPERTY(EditAnywhere, Category = "NPCNodeOptions")					float fpVisionRangeModifier;							//var(NPCNodeBonuses) float fpVisionRangeModifier;
	UPROPERTY(EditAnywhere, Category = "NPCNodeOptions")					float fpMentalStateChangeModifier;						//var(NPCNodeBonuses) float fpMentalStateChangeModifier;
	UPROPERTY(EditAnywhere, Category = "NPCNodeOptions")					float fpWeaponAccuracyBonus;							//var(NPCNodeBonuses) float fpWeaponAccuracyBonus;
	UPROPERTY(EditAnywhere, Category = "NPCNodeOptions")					float fpMentalStateBonus;								//var(NPCNodeBonuses) float fpMentalStateBonus;
	UPROPERTY(EditAnywhere, Category = "NPCNodeOptions")					bool bKeepWeaponPosition;								//var(NPCNodeOptions) bool bKeepWeaponPosition;
	UPROPERTY(EditAnywhere, Category = "NPCNodeOptions")					bool bStopHere;											//var(NPCNodeOptions) bool bStopHere;
	UPROPERTY(EditAnywhere, Category = "NPCNodeOptions")					bool bMustWalk;											//var(NPCNodeOptions) bool bMustWalk;
	UPROPERTY(EditAnywhere, Category = "NPCNodeOptions")					bool bMustSprint;										//var(NPCNodeOptions) bool bMustSprint;
	UPROPERTY(EditAnywhere, Category = "NPCNodeOptions")					bool bMustRun;											//var(NPCNodeOptions) bool bMustRun;
	UPROPERTY(EditAnywhere, Category = "NPCNodeOptions")					bool bMustStand;										//var(NPCNodeOptions) bool bMustStand;
	UPROPERTY(EditAnywhere, Category = "NPCNodeOptions")					bool bMustProne;										//var(NPCNodeOptions) bool bMustProne;
	UPROPERTY(EditAnywhere, Category = "NPCNodeOptions")					bool bMustCrouch;										//var(NPCNodeOptions) bool bMustCrouch;
	UPROPERTY()																ANPCBaseController* npcbcUsingNode;						//var NPCBaseController npcbcUsingNode;
	UPROPERTY(EditAnywhere, Category = "NPCNodeOptions")					bool bPathBranchDesc;									//var(NPCNodeOptions) bool bPathBranchDesc;
	UPROPERTY(EditAnywhere, Category = "NPCNodeOptions")					bool bPathBranchAsc;									//var(NPCNodeOptions) bool bPathBranchAsc;
	UPROPERTY(EditAnywhere, Category = "NPCNodeOptions")					int32 iBranchIndex;										//var(NPCNodeOptions) int iBranchIndex;
	UPROPERTY()																ENodeType bInUse;										//var bool bInUse;

	void BeginPlay();
	bool IsHallwayEntry();
	bool RequestHallway(ANPCBaseController* npcbc);
	void ReleaseHallway(ANPCBaseController* npcbc);
};
