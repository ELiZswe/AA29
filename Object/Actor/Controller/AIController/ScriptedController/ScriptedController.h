// All the original content belonged to the US Army

// ScriptedController
// AI controller which is controlling the pawn through a scripted sequence specified by
// an AIScript

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Controller/AIController/aAIController.h"
#include "ScriptedController.generated.h"

class ULatentScriptedAction;
class UAction_PLAYANIM;
class AScriptedSequence;

class AAmmunition;
UCLASS()
class AScriptedController : public AaAIController
{
	GENERATED_BODY()
public:
	AScriptedController();

	UPROPERTY()										AController* PendingController;				//var Controller PendingController;						// controller which will get this pawn after scripted sequence is complete
	UPROPERTY()										int32 ActionNum;							//var int ActionNum;
	UPROPERTY()										int32 AnimsRemaining;						//var int AnimsRemaining;
	UPROPERTY()										AScriptedSequence* SequenceScript;			//var ScriptedSequence SequenceScript;
	UPROPERTY()										ULatentScriptedAction* CurrentAction;		//var LatentScriptedAction CurrentAction;
	UPROPERTY()										UAction_PLAYANIM* CurrentAnimation;			//var Action_PLAYANIM CurrentAnimation;
	UPROPERTY()										bool bBroken;								//var bool bBroken;
	UPROPERTY()										bool bShootTarget;							//var bool bShootTarget;
	UPROPERTY()										bool bShootSpray;							//var bool bShootSpray;
	UPROPERTY()										bool bPendingShoot;							//var bool bPendingShoot;
	UPROPERTY()										bool bFakeShot;								//var bool bFakeShot;									// FIXME - this is currently a hack
	UPROPERTY()										bool bUseScriptFacing;						//var bool bUseScriptFacing;
	UPROPERTY()										bool bPendingDoubleJump;					//var bool bPendingDoubleJump;
	UPROPERTY()										bool bFineWeaponControl;					//var bool bFineWeaponControl;
	UPROPERTY()										bool bChangingPawns;						//var bool bChangingPawns;
	UPROPERTY()										AActor* ScriptedFocus;						//var Actor ScriptedFocus;
	UPROPERTY()										APlayerController* MyPlayerController;		//var PlayerController MyPlayerController;
	UPROPERTY()										int32 NumShots;								//var int NumShots;
	UPROPERTY()										FName FiringMode;							//var name FiringMode;
	UPROPERTY()										int32 IterationCounter;						//var int IterationCounter;
	UPROPERTY()										int32 IterationSectionStart;				//var int IterationSectionStart;

	bool WeaponFireAgain(float RefireRate, bool bFinishedFire);
	void Init();
	void SetDoubleJump();
	void NotifyJumpApex();
	void TakeControlOf(APawn* aPawn);
	void SetEnemyReaction(int32 AlertnessLevel);
	void DestroyPawn();
	APawn* GetMyPlayer();
	APawn* GetInstigator();
	AActor* GetSoundSource();

	bool CheckIfNearPlayer(float Distance);
	void ClearScript();
	void SetNewScript(AScriptedSequence* NewScript);
	void ClearAnimation();
	int32 SetFireYaw(int32 FireYaw);
	FRotator AdjustAim(AAmmunition* FiredAmmunition, FVector projStart, int32 aimerror);
	void Timer();
	void Trigger(AActor* Other, APawn* EventInstigator);
	void EndState();
	void MayShootTarget();
	void MayShootAtEnemy();
	void Tick(float DeltaTime);
	void AbortScript();
	void SetMoveTarget();
	void CompleteAction();
	void LIPSincAnimEnd();
	void AnimEnd(int32 Channel);
	void DisplayDebug(UCanvas* Canvas, const class FDebugDisplayInfo& DebugDisplay, float& YL, float& YPos);
	void InitForNextAction();
	void LeaveScripting();
	//void UnPossess();
};
