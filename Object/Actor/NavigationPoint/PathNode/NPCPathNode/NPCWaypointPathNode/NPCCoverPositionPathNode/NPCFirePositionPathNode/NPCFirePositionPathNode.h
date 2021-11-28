// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/NavigationPoint/PathNode/NPCPathNode/NPCWaypointPathNode/NPCCoverPositionPathNode/NPCCoverPositionPathNode.h"
#include "NPCFirePositionPathNode.generated.h"

class ANPCDuckAndCoverPathNode;

UCLASS()
class AA29_API ANPCFirePositionPathNode : public ANPCCoverPositionPathNode
{
	GENERATED_BODY()
public:
	ANPCFirePositionPathNode();

	UPROPERTY(EditAnywhere)												TArray<ANPCDuckAndCoverPathNode*> anpcdacpnDuckAndCoverNode;	//var array<NPCDuckAndCoverPathNode> anpcdacpnDuckAndCoverNode;
	UPROPERTY(EditAnywhere, Category = "NPCFiringPosition")				TArray<FName> anameDuckAndCoverNodes;							//var(NPCFiringPosition) array<name> anameDuckAndCoverNodes;
	UPROPERTY(EditAnywhere, Category = "NPCFiringPosition")				bool bPopAndShoot;												//var(NPCFiringPosition) bool bPopAndShoot;
	UPROPERTY(EditAnywhere, Category = "NPCFiringPosition")				bool bIsFiringBlindlyOverHead;									//var(NPCFiringPosition) bool bIsFiringBlindlyOverHead;
	UPROPERTY(EditAnywhere, Category = "NPCFiringPosition")				bool bBlindFireRight;											//var(NPCFiringPosition) bool bBlindFireRight;
	UPROPERTY(EditAnywhere, Category = "NPCFiringPosition")				bool bBlindFireLeft;											//var(NPCFiringPosition) bool bBlindFireLeft;
	UPROPERTY(EditAnywhere, Category = "NPCFiringPosition")				bool bShouldLeanLeftToShoot;									//var(NPCFiringPosition) bool bShouldLeanLeftToShoot;
	UPROPERTY(EditAnywhere, Category = "NPCFiringPosition")				bool bShouldLeanRightToShoot;									//var(NPCFiringPosition) bool bShouldLeanRightToShoot;
	UPROPERTY(EditAnywhere, Category = "NPCFiringPosition")				bool bCanUseGrenades;											//var(NPCFiringPosition) bool bCanUseGrenades;
	UPROPERTY(EditAnywhere, Category = "NPCFiringPosition")				bool bUsePrimaryWeapon;											//var(NPCFiringPosition) bool bUsePrimaryWeapon;
	UPROPERTY(EditAnywhere, Category = "NPCFiringPosition")				bool bIsCover;													//var(NPCFiringPosition) bool bIsCover;
	UPROPERTY(EditAnywhere, Category = "NPCFiringPosition")				bool bShootWhileProne;											//var(NPCFiringPosition) bool bShootWhileProne;
	UPROPERTY(EditAnywhere, Category = "NPCFiringPosition")				bool bShootWhileCrouched;										//var(NPCFiringPosition) bool bShootWhileCrouched;
	UPROPERTY(EditAnywhere, Category = "NPCFiringPosition")				bool bProneHere;												//var(NPCFiringPosition) bool bProneHere;
	UPROPERTY(EditAnywhere, Category = "NPCFiringPosition")				bool bCrouchHere;												//var(NPCFiringPosition) bool bCrouchHere;
};
