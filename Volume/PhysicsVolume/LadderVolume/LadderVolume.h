// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PhysicsVolume.h"
#include "AA29/MyStructs.h"
#include "LadderVolume.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ALadderVolume : public APhysicsVolume
{
	GENERATED_BODY()
public:
	ALadderVolume();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)		ELadderClimbSound ClimbSound;		//var() ELadderClimbSound ClimbSound;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		bool bDoTriggerLadder;				//var() bool bDoTriggerLadder;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		bool bStartOn;						//var() bool bStartOn;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		bool bLadderIsOn;					//var bool bLadderIsOn;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		APawn* PendingClimber;				//var Pawn PendingClimber;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		bool bAllowLadderStrafing;			//var() bool bAllowLadderStrafing;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		bool bAutoPath;						//var() bool bAutoPath;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		bool bNoPhysicalLadder;				//var() bool bNoPhysicalLadder;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite)		ALadder* LadderList;			//var const Ladder LadderList;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		FVector ClimbDir;					//var FVector ClimbDir;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		FVector LookDir;					//var FVector LookDir;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		FRotator WallDir;					//var() Object.Rotator WallDir;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		FName TopAnimation;					//var() name TopAnimation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		FName ClimbingAnimation;			//var() name ClimbingAnimation;
};
