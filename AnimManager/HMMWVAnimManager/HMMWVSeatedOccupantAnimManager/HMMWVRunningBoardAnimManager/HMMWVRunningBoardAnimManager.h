// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/AnimManager/HMMWVAnimManager/HMMWVSeatedOccupantAnimManager/HMMWVSeatedOccupantAnimManager.h"
#include "HMMWVRunningBoardAnimManager.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AHMMWVRunningBoardAnimManager : public AHMMWVSeatedOccupantAnimManager
{
	GENERATED_BODY()
public:
	AHMMWVRunningBoardAnimManager();

	UPROPERTY()										APlayerController* OldController;				//var PlayerController OldController;
	UPROPERTY()										APawn* BackupPawn;								//var Pawn BackupPawn;
	UPROPERTY()										APlayerController* BackupController;			//var PlayerController BackupController;
	UPROPERTY()										bool bLockLeavingState;							//var bool bLockLeavingState;
	UPROPERTY()										FRotator ExitRotation;							//var Object.Rotator ExitRotation;
	UPROPERTY()										float LastTime;									//var float LastTime;
	UPROPERTY()										FVector LastPawnLocation;						//var Object.Vector LastPawnLocation;
	UPROPERTY()										float JumpOut;									//var float JumpOut;
	UPROPERTY()										FName TransitionToRunningBoard;					//var name TransitionToRunningBoard;
	UPROPERTY()										FName TransitionFromRunningBoard;				//var name TransitionFromRunningBoard;
	UPROPERTY()										FName RunningBoardExitFinal;					//var name RunningBoardExitFinal;
	UPROPERTY()										FName RunningBoardExit;							//var name RunningBoardExit;
	UPROPERTY()										FName RunningBoardEnter;						//var name RunningBoardEnter;
	UPROPERTY()										FName VehicleDoorExit;							//var name VehicleDoorExit;
	UPROPERTY()										FName VehicleDoorEnter;							//var name VehicleDoorEnter;
	UPROPERTY()										int32 VehicleDoorAnimChannel;					//var int VehicleDoorAnimChannel;
	UPROPERTY()										FName DoorBoneName;								//var name DoorBoneName;
	UPROPERTY()										bool bDestGetOff;								//var bool bDestGetOff;


	void ReleasePawn();
	void PlayVehicleEnterAnim();
	void PlayIdleAnim();
	void FinishVehicleTransition();
	void DoTransitionToRunningBoardAnim();
	//void ClientBeginEnterVehicle(APawn* User, AVehicle* BaseVehicle);
	//void ServerBeginEnterVehicle(APawn* User, AVehicle* EntryVehicle, AVehicle* EntryBoard);
	void FinishPawnLeave();
	void Timer();
	void SetExitRotation();
	void ServerSetExitRotation(FRotator Rotation);

};
