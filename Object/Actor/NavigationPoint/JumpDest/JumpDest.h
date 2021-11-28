// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/NavigationPoint/NavigationPoint.h"
#include "JumpDest.generated.h"

//class AReachSpec;

UCLASS()
class AA29_API AJumpDest : public ANavigationPoint
{
	GENERATED_BODY()
public:
	AJumpDest();


	UPROPERTY()													float CalculatedGravityZ;							//var float CalculatedGravityZ;
	UPROPERTY()													FVector NeededJump;									//var Object.Vector NeededJump;
	//UPROPERTY()													AReachSpec* UpstreamPaths;							//var ReachSpec UpstreamPaths;
	UPROPERTY()													int32 NumUpstreamPaths;								//var int NumUpstreamPaths;
	UPROPERTY(EditAnywhere)										bool bForceDoubleJump;								//var() bool bForceDoubleJump;
	UPROPERTY()													bool bOptionalJumpDest;								//var bool bOptionalJumpDest;


	//void GetPathIndex(AReachSpec* Path);
	//int32 SpecialCost(APawn* Other, AReachSpec* Path);
	void DoJump(APawn* Other);
	bool SuggestMovePreparation(APawn* Other);
};
