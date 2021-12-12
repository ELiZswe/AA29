// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PhysicsVolume.h"
#include "AA29/MyEnums.h"
#include "LadderVolume.generated.h"

class ALadder;

UCLASS()
class AA29_API ALadderVolume : public APhysicsVolume
{
	GENERATED_BODY()
public:
	ALadderVolume();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)		ELadderClimbSound ClimbSound;		//var() ELadderClimbSound ClimbSound;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		bool bDoTriggerLadder;				//var() bool bDoTriggerLadder;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		bool bStartOn;						//var() bool bStartOn;
	UPROPERTY()										bool bLadderIsOn;					//var bool bLadderIsOn;
	UPROPERTY()										APawn* PendingClimber;				//var Pawn PendingClimber;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		bool bAllowLadderStrafing;			//var() bool bAllowLadderStrafing;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		bool bAutoPath;						//var() bool bAutoPath;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		bool bNoPhysicalLadder;				//var() bool bNoPhysicalLadder;
	UPROPERTY()										ALadder* LadderList;				//var const Ladder LadderList;
	UPROPERTY()										FVector ClimbDir;					//var FVector ClimbDir;
	UPROPERTY()										FVector LookDir;					//var FVector LookDir;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		FRotator WallDir;					//var() Object.Rotator WallDir;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		FName TopAnimation;					//var() name TopAnimation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		FName ClimbingAnimation;			//var() name ClimbingAnimation;

	void PostBeginPlay();
	bool InUse(APawn* Ignored);
	void PawnEnteredVolume(APawn* p);
	void PawnLeavingVolume(APawn* p);
	void PhysicsChangedFor(AActor* Other);
	void MatchStarting();
	void SetLadderState(bool bOn);
	void Trigger(AActor* Other, APawn* EventInstigator);
	USoundBase* GetLadderClimbSound();
};
