// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/NavigationPoint/NavigationPoint.h"
#include "JumpDest.generated.h"

class UReachSpec;

UCLASS()
class AJumpDest : public ANavigationPoint
{
	GENERATED_BODY()
public:
	AJumpDest();

	UPROPERTY()							float					CalculatedGravityZ;				//var float CalculatedGravityZ;
	UPROPERTY()							FVector					NeededJump;						//var Object.Vector NeededJump;
	UPROPERTY()							TArray<UReachSpec*>		UpstreamPaths;					//var ReachSpec UpstreamPaths[8];
	UPROPERTY()							int32					NumUpstreamPaths;				//var int NumUpstreamPaths;
	UPROPERTY(EditAnywhere)				bool					bForceDoubleJump;				//var() bool bForceDoubleJump;
	UPROPERTY()							bool					bOptionalJumpDest;				//var bool bOptionalJumpDest;

	int32 GetPathIndex(UReachSpec* Path);
	int32 SpecialCost(APawn* Other, UReachSpec* Path);
	void DoJump(APawn* Other);
	bool SuggestMovePreparation(APawn* Other);
};
