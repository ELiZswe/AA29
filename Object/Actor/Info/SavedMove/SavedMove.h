// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/AA2_Info.h"
#include "AA29/MyEnums.h"
#include "SavedMove.generated.h"

UCLASS()
class ASavedMove : public AAA2_Info
{
	GENERATED_BODY()
public:
	ASavedMove();

	UPROPERTY()			ASavedMove*		NextMove;					//var SavedMove NextMove;
	UPROPERTY()			float			TimeStamp;					//var float TimeStamp;
	UPROPERTY()			float			Delta;						//var float Delta;
	UPROPERTY()			bool			bRun;						//var bool bRun;
	UPROPERTY()			bool			bDuck;						//var bool bDuck;
	UPROPERTY()			bool			bPressedJump;				//var bool bPressedJump;
	UPROPERTY()			bool			bDoubleJump;				//var bool bDoubleJump;
	UPROPERTY()			bool			bIsWalking;					//var bool bIsWalking;
	UPROPERTY()			bool			bProne;						//var bool bProne;
	UPROPERTY()			bool			bWantsToCrouch;				//var bool bWantsToCrouch;
	UPROPERTY()			bool			bWantsToProne;				//var bool bWantsToProne;
	UPROPERTY()			FVector			StartLocation;				//var Vector StartLocation;
	UPROPERTY()			FVector			StartRelativeLocation;		//var Vector StartRelativeLocation;
	UPROPERTY()			FVector			StartVelocity;				//var Vector StartVelocity;
	UPROPERTY()			FVector			StartFloor;					//var Vector StartFloor;
	UPROPERTY()			FVector			SavedLocation;				//var Vector SavedLocation;
	UPROPERTY()			FVector			SavedVelocity;				//var Vector SavedVelocity;
	UPROPERTY()			FVector			SavedRelativeLocation;		//var Vector SavedRelativeLocation;
	UPROPERTY()			AActor*			StartBase;					//var Actor StartBase;
	UPROPERTY()			AActor*			EndBase;					//var Actor EndBase;

	void Clear();
	void PostUpdate(APlayerController* p);
	bool IsJumpMove();
	FVector GetStartLocation();
	void SetInitialPosition(APawn* p);
	void SetMoveFor(APlayerController* p, float DeltaTime, FVector NewAccel, EDoubleClickDir InDoubleClick);
};
