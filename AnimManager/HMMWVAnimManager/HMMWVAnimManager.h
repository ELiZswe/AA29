// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/AnimManager/AnimManager.h"
#include "HMMWVAnimManager.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AHMMWVAnimManager : public AAnimManager
{
	GENERATED_BODY()
public:
	AHMMWVAnimManager();

	UPROPERTY()										float DeathFadeOutTime;						//var float DeathFadeOutTime;
	UPROPERTY()										float DeathFadeStartTime;					//var float DeathFadeStartTime;
	UPROPERTY()										bool bBusyAnimating;						//var bool bBusyAnimating;
	UPROPERTY()										FRotator OldPCRotation;						//var Object.Rotator OldPCRotation;
	UPROPERTY()										FName CameraBone;							//var name CameraBone;
	UPROPERTY()										APlayerController* TempPC;					//var PlayerController TempPC;
	UPROPERTY()										APawn* TempPawn;							//var Pawn TempPawn;
	UPROPERTY()										FName ActionIdle;							//var name ActionIdle;
	UPROPERTY()										FName ActionTransitionReverse;				//var name ActionTransitionReverse;
	UPROPERTY()										FName ActionTransition;						//var name ActionTransition;
	UPROPERTY()										FName DriverDead;							//var name DriverDead;
	UPROPERTY()										FName DriverDie;							//var name DriverDie;
	UPROPERTY()										FName DrivingIdle;							//var name DrivingIdle;
	UPROPERTY()										bool bLeaving;								//var bool bLeaving;
	UPROPERTY()										bool bForceExit;							//var bool bForceExit;
	//UPROPERTY()										AVehicle* DestVehicle;						//var Vehicle DestVehicle;
	//UPROPERTY()										AVehicle* Vehicle;							//var Vehicle Vehicle;
	void BindToPawn(APawn* p);
	void ReleasePawn();
	//bool DoTransition(AVehicle* EntryVehicle);
	bool CanPlayDeathAnim();
	void PlayIdleAnim();
	void PlayActionAnim();
	void PlayDeathAnim();

};
