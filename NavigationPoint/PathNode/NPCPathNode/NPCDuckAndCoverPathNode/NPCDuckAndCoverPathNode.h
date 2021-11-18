// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/NavigationPoint/PathNode/NPCPathNode/NPCPathNode.h"
#include "NPCDuckAndCoverPathNode.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ANPCDuckAndCoverPathNode : public ANPCPathNode
{
	GENERATED_BODY()
public:
	ANPCDuckAndCoverPathNode();

	UPROPERTY()																ANPCPathNode* npcpnPrimaryFiringPosition;			//var NPCPathNode npcpnPrimaryFiringPosition;
	UPROPERTY(EditAnywhere, Category = "NPCDuckAndCover")					FName nameFiringNode;								//var(NPCDuckAndCover) name nameFiringNode;
	UPROPERTY(EditAnywhere, Category = "NPCDuckAndCover")					bool bCombatRollRightToShoot;						//var(NPCDuckAndCover) bool bCombatRollRightToShoot;
	UPROPERTY(EditAnywhere, Category = "NPCDuckAndCover")					bool bCombatRollLeftToShoot;						//var(NPCDuckAndCover) bool bCombatRollLeftToShoot;
	UPROPERTY(EditAnywhere, Category = "NPCDuckAndCover")					bool bProneForCover;								//var(NPCDuckAndCover) bool bProneForCover;
	UPROPERTY(EditAnywhere, Category = "NPCDuckAndCover")					bool bCrouchForCover;								//var(NPCDuckAndCover) bool bCrouchForCover;
	UPROPERTY(EditAnywhere, Category = "NPCDuckAndCover")					bool bStepRightToShoot;								//var(NPCDuckAndCover) bool bStepRightToShoot;
	UPROPERTY(EditAnywhere, Category = "NPCDuckAndCover")					bool bStepLeftToShoot;								//var(NPCDuckAndCover) bool bStepLeftToShoot;
};
