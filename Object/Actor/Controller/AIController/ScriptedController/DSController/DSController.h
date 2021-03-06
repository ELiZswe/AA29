// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Controller/AIController/ScriptedController/ScriptedController.h"
#include "DSController.generated.h"

class AScriptedSequence;
class UAction_WAITFORANIMEND;
class UAction_SETVIEWTARGET;
class UAction_PLAYANIM;
class UAction_MOVETOPOINT;

UCLASS()
class ADSController : public AScriptedController
{
	GENERATED_BODY()
public:
	ADSController();

	UPROPERTY()										int32 piprod;										//var const int piprod;
	UPROPERTY()										float ElapsedTime;									//var float ElapsedTime;
	UPROPERTY()										float tickAccumulator;								//var float tickAccumulator;
	UPROPERTY()										int32 tickCount;									//var int tickCount;
	UPROPERTY()										AActor* assignedPosition;							//var Actor assignedPosition;
	UPROPERTY()										TArray<FString> PendingFSTSParm3;							//var string PendingFSTSParm3;
	UPROPERTY()										TArray<FString> PendingFSTSParm2;							//var string PendingFSTSParm2;
	UPROPERTY()										TArray<FString> PendingFSTSParm1;							//var string PendingFSTSParm1;
	UPROPERTY()										TArray<FString> PendingFSTSActions;							//var string PendingFSTSActions;
	UPROPERTY()										int32 numPendingFSTSActions;						//var int numPendingFSTSActions;
	UPROPERTY()										UAction_WAITFORANIMEND* FSTSWaitForAnimEnd;			//var Gameplay.Action_WAITFORANIMEND FSTSWaitForAnimEnd;
	UPROPERTY()										UAction_SETVIEWTARGET* FSTSSetViewTarget;			//var Gameplay.Action_SETVIEWTARGET FSTSSetViewTarget;
	UPROPERTY()										UAction_PLAYANIM* FSTSPlayAnimationAction;			//var Gameplay.Action_PLAYANIM FSTSPlayAnimationAction;
	UPROPERTY()										UAction_MOVETOPOINT* FSTSMoveToAction;				//var Gameplay.Action_MOVETOPOINT FSTSMoveToAction;
	UPROPERTY()										AScriptedSequence* DynamicScript;					//var Gameplay.ScriptedSequence DynamicScript;
	UPROPERTY()										AScriptedSequence* OriginalScript;					//var Gameplay.ScriptedSequence OriginalScript;
	UPROPERTY()										bool bReadyForScripting;							//var bool bReadyForScripting;
	UPROPERTY()										bool bReadyToBuild;									//var bool bReadyToBuild;

	void PostBeginPlay();
	void InitPlayerReplicationInfo();
	void InitializeFor(AScriptedSequence* t);
	void TakeControlOf(APawn* aPawn);
	void ClearScript();
	void SetNewScript(AScriptedSequence* NewScript);
	bool CheckForNewCommand();
	void MoveToPoint(FName DestinationTag);
	void PlayAnimation(FName BaseAnimation);
	void WaitForAnimEnd(int32 Channel);
	void PlayLipSinc(FName AnimName);
	void WaitForLipSincAnimEnd(int32 Channel);
	void SetViewTarget(FName ViewTargetTag);
	void TurnTowardPlayer();
	void Crouch();
	void Stand();
	void Walk();
	void Run();
	void WaitForTimer(float PauseTime);
	void WaitForEvent(FName ExternalEvent);
	void BuildDynamicScriptFromFSTS();
	void DestinationOccupied();
	void EndCurrentScript();
	void ClearAnimation();
	void Tick(float Delta);
	void PawnDied(APawn* p);
	void Destroyed();

};
