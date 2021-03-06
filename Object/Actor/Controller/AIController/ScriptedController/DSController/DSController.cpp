// All the original content belonged to the US Army

#include "AA29/Object/Actor/Controller/AIController/ScriptedController/DSController/DSController.h"
#include "AA29/Object/Actor/Keypoint/AIScript/ScriptedSequence/ScriptedSequence.h"
#include "AA29/Object/ScriptedAction/LatentScriptedAction/Action_MOVETOPOINT/Action_MOVETOPOINT.h"
#include "AA29/Object/ScriptedAction/Action_PLAYANIM/Action_PLAYANIM.h"
#include "AA29/Object/ScriptedAction/Action_SETVIEWTARGET/Action_SETVIEWTARGET.h"
#include "AA29/Object/ScriptedAction/LatentScriptedAction/Action_WAITFORANIMEND/Action_WAITFORANIMEND.h"
#include "AA29/Object/Actor/Info/GameInfo/GameInfo.h"
#include "AA29/Object/ScriptedAction/Action_CROUCH/Action_CROUCH.h"
#include "AA29/Object/ScriptedAction/ACTION_PlayLIPSinc/ACTION_PlayLIPSinc.h"
#include "AA29/Object/ScriptedAction/Action_RUN/Action_RUN.h"
#include "AA29/Object/ScriptedAction/ACTION_Stand/ACTION_Stand.h"
#include "AA29/Object/ScriptedAction/ACTION_TriggerEvent/ACTION_TriggerEvent.h"
#include "AA29/Object/ScriptedAction/LatentScriptedAction/Action_TURNTOWARDPLAYER/Action_TURNTOWARDPLAYER.h"
#include "AA29/Object/ScriptedAction/Action_USE/Action_USE.h"
#include "AA29/Object/ScriptedAction/LatentScriptedAction/Action_WAITFOREVENT/Action_WAITFOREVENT.h"
#include "AA29/Object/ScriptedAction/LatentScriptedAction/ACTION_WaitForLIPSincAnimEnd/ACTION_WaitForLIPSincAnimEnd.h"
#include "AA29/Object/ScriptedAction/LatentScriptedAction/Action_WAITFORTIMER/Action_WAITFORTIMER.h"
#include "AA29/Object/ScriptedAction/Action_WALK/Action_WALK.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/FSTS_Pawn/FSTS_NPC_DrillSergeant.h"
#include "AA29/Object/Actor/Pawn/Vehicle/VehiclePosition/VehiclePosition.h"

ADSController::ADSController()
{
	PendingFSTSParm3.SetNum(20);
	PendingFSTSParm2.SetNum(20);
	PendingFSTSParm1.SetNum(20);
	PendingFSTSActions.SetNum(20);
	bReadyForScripting = true;
	bChangingPawns = true;
	bAdvancedTactics = false;
}

/*
State Scripting
{
	Function InitForNextAction()
	{
		CheckForNewCommand();
		SequenceScript.SetActions(this);
		if (CurrentAction == nullptr)
		{
			LeaveScripting();
			return;
		}
		MyScript=SequenceScript;
		if (CurrentAnimation == nullptr)
		{
			ClearAnimation();
		}
		Enable("Tick");
	}
	Function LeaveScripting()
	{
		bReadyForScripting=false;
		bReadyToBuild=true;
		GotoState("Idle","Begin");
	}
	Function EndCurrentScript()
	{
		MoveTimer=-1;
		Destination=Pawn.Location;
		MoveTarget=nullptr;
		CurrentAction.ActionCompleted();
		LeaveScripting();
	}
Begin:
	ElapsedTime=0;
	InitForNextAction();
	if (bBroken)
	{
		GotoState("Broken");
	}
	if (CurrentAction.TickedAction())
	{
		Enable("Tick");
	}
	if (! bFineWeaponControl)
	{
		if (! bShootTarget)
		{
			bFire=0;
			bAltFire=0;
		}
		else
		{
			Pawn.Weapon.RateSelf();
			if (bShootSpray)
			{
				MayShootTarget();
			}
		}
	}
	if (CurrentAction.MoveToGoal())
	{
		if (Cast<AVehiclePosition>(Pawn) != nullptr)
		{
			GotoState("Idle");
		}
		assignedPosition=CurrentAction.GetMoveTargetFor(this);
		Pawn.SetMovementPhysics();
		WaitForLanding();
		bControlAnimations=false;
		SetMoveTarget();
		Pawn.MakeNoise(1);
		MayShootTarget();
		if ((MoveTarget != nullptr) && (MoveTarget != Pawn))
		{
			MoveToward(MoveTarget,Focus,,,Pawn.bIsWalking);
			if ((MoveTarget != CurrentAction.GetMoveTargetFor(this)) || (! Pawn.ReachedDestination(CurrentAction.GetMoveTargetFor(this))))
			{
				JL"KeepMoving"
;
			}
		}
		bControlAnimations=true;
		CompleteAction();
	}
	else
	{
		if (CurrentAction.TurnToGoal())
		{
			Pawn.SetMovementPhysics();
			Focus=CurrentAction.GetMoveTargetFor(this);
			if (Focus == nullptr)
			{
				FocalPoint=(Pawn.Location + (float(1000) *  Vector(SequenceScript.Rotation)));
			}
			FinishRotation();
			CompleteAction();
		}
		else
		{
			Pawn.Acceleration=FVector(0,0,0);
			Focus=ScriptedFocus;
			if (! bUseScriptFacing)
			{
				FocalPoint=(Pawn.Location + (float(1000) *  Vector(Pawn.Rotation)));
			}
			else
			{
				if (Focus == nullptr)
				{
					MayShootAtEnemy();
					FocalPoint=(Pawn.Location + (float(1000) *  Vector(SequenceScript.Rotation)));
				}
			}
			FinishRotation();
			MayShootTarget();
		}
	}
}
*/

/*
State Idle
{
	Function BeginState()
	{
		Pawn.StopAnimating(true);
		Pawn.PlayAnim(Cast<AFSTS_NPC_DrillSergeant>(Pawn).DSIdleAnim,1,0.2);
	}
	Function SetMoveTarget()
	{
		AActor* NextMoveTarget = nullptr;
		Focus=ScriptedFocus;
		NextMoveTarget=assignedPosition;
		if (NextMoveTarget == nullptr)
		{
			GotoState("Broken");
			return;
		}
		if (Focus == nullptr)
		{
			Focus=NextMoveTarget;
		}
		MoveTarget=NextMoveTarget;
		if (! actorReachable(MoveTarget))
		{
			MoveTarget=FindPathToward(MoveTarget,false);
			if (MoveTarget == nullptr)
			{
				MoveTarget=assignedPosition;
				return;
			}
			if (Focus == NextMoveTarget)
			{
				Focus=MoveTarget;
			}
		}
	}
Begin:
	if (Pawn.bIsCrouched)
	{
		Pawn.LoopAnim("CrhNo",1,0.2);
	}
	else
	{
		if (Pawn.bIsProne)
		{
			Pawn.LoopAnim("PrnNo",1,0.2);
		}
		else
		{
			if (Cast<AFSTS_NPC_DrillSergeant>(Pawn) != nullptr)
			{
				if (! Pawn.IsAnimating())
				{
					if (Pawn.IsPlayingLIPSincAnim() || (FMath::FRand() > (ElapsedTime / FSTS_NPC_DrillSergeant(Pawn).TwitchInterval)))
					{
						Pawn.PlayAnim(Cast<AFSTS_NPC_DrillSergeant>(Pawn).DSIdleAnim,1,0.2);
						if (Pawn.IsPlayingLIPSincAnim())
						{
							ElapsedTime=-5;
						}
					}
					else
					{
						Pawn.PlayAnim(Cast<AFSTS_NPC_DrillSergeant>(Pawn).IdleGestureAnims[int((FMath::FRand() * float(Cast<AFSTS_NPC_DrillSergeant>(Pawn).IdleGestureAnims.Num())))],1,0.5);
						ElapsedTime=0;
					}
				}
			}
		}
	}
	if ((assignedPosition != nullptr) && (! Pawn.ReachedDestination(assignedPosition)))
	{
		SetMoveTarget();
		MoveToward(MoveTarget,Focus,,,true);
	}
	Sleep(0.5);
	CheckForNewCommand();
	if (bReadyForScripting)
	{
		MyScript=DynamicScript;
		Focus=nullptr;
		ClearScript();
		GotoState("Scripting","Begin");
	}
	JL"Begin"
;
}
*/

void ADSController::PostBeginPlay()
{
	/*
		SetNewScript(DynamicScript);
		ActionNum=0;
		if (SequenceScript != nullptr)
		{
			SequenceScript.SetActions(this);
		}
		bControlAnimations=true;
	*/
}
void ADSController::InitPlayerReplicationInfo()
{
	/*
		if (PlayerReplicationInfo != nullptr)
		{
			if (PlayerReplicationInfo.PlayerName == "")
			{
				PlayerReplicationInfo.SetPlayerName(AGameInfo::StaticClass().Default.DefaultPlayerName);
			}
			PlayerReplicationInfo.bNoTeam=! Level.Game.bTeamGame;
		}
	*/
}
void ADSController::InitializeFor(AScriptedSequence* t)
{
	//MyScript=t;
	//bIsPlayer=false;
	SetNewScript(t);
	ActionNum=0;
	//SequenceScript->SetActions(this);
	//GotoState('Scripting');
}
void ADSController::TakeControlOf(APawn* aPawn)
{
	/*
		if (Pawn != aPawn)
		{
			aPawn.PossessedBy(this);
			Pawn=aPawn;
		}
		Pawn.PlayAnim('AE_Idle_A',1,0.2);
		GotoState('Idle','Begin');
	*/
}
void ADSController::ClearScript()
{
	/*
	ActionNum=0;
	CurrentAction=nullptr;
	CurrentAnimation=nullptr;
	ScriptedFocus=nullptr;
	if (Pawn != nullptr)
	{
		Pawn.SetWalking(false);
		Pawn.ShouldCrouch(false);
	}
	*/
}
void ADSController::SetNewScript(AScriptedSequence* NewScript)
{
	/*
	int32 i = 0;
	if (DynamicScript == nullptr || NewScript != DynamicScript)
	{
		DynamicScript=Spawn('FSTS_ScriptedSequence');
		if (DynamicScript == nullptr)
		{
			Log("DSConSpawn of dynamic ScriptedSequence failed",'DSController');
			DynamicScript=NewScript;
		}
		if (MyScript != nullptr)
		{
			OriginalScript=ScriptedSequence(MyScript);
		}
		if (OriginalScript != nullptr)
		{
			for (i=0; i<OriginalScript.Actions.Num(); i++)
			{
				DynamicScript.Actions[i]=OriginalScript.Actions[i];
			}
		}
		DynamicScript.Actions[DynamicScript.Actions.Num()]=new() UAction_WAITFORTIMER::StaticClass();
		Action_WAITFORTIMER(DynamicScript.Actions[DynamicScript.Actions.Num() - 1]).PauseTime=3;
	}
	bReadyToBuild=false;
	bReadyForScripting=true;
	MyScript=DynamicScript;
	SequenceScript=DynamicScript;
	Focus=nullptr;
	ClearScript();
	SetEnemyReaction(3);
	*/
}

bool ADSController::CheckForNewCommand()
{
	if (bReadyToBuild && numPendingFSTSActions > 0)
	{
		bReadyToBuild=false;
		SequenceScript=DynamicScript;
		BuildDynamicScriptFromFSTS();
		bReadyForScripting=true;
	}
	return false;
}
void ADSController::MoveToPoint(FName DestinationTag)
{
	/*
	PendingFSTSActions[numPendingFSTSActions]="MoveToPoint";
	PendingFSTSParm1[numPendingFSTSActions]=DestinationTag;
	numPendingFSTSActions ++;
	*/
}
void ADSController::PlayAnimation(FName BaseAnimation)
{
	/*
	PendingFSTSActions[numPendingFSTSActions]="PlayAnim";
	PendingFSTSParm1[numPendingFSTSActions]=BaseAnimation;
	numPendingFSTSActions ++;
	*/
}
void ADSController::WaitForAnimEnd(int32 Channel)
{
	/*
	PendingFSTSActions[numPendingFSTSActions]="WaitForAnimEnd";
	PendingFSTSParm1[numPendingFSTSActions]=Channel;
	numPendingFSTSActions ++;
	*/
}
void ADSController::PlayLipSinc(FName AnimName)
{
	/*
	PendingFSTSActions[numPendingFSTSActions]="PlayLipSinc";
	PendingFSTSParm1[numPendingFSTSActions]=AnimName;
	numPendingFSTSActions ++;
	*/
}
void ADSController::WaitForLipSincAnimEnd(int32 Channel)
{
	/*
		PendingFSTSActions[numPendingFSTSActions]="WaitForLipSincAnimEnd";
		numPendingFSTSActions ++;
	*/
}
void ADSController::SetViewTarget(FName ViewTargetTag)
{
	/*
		PendingFSTSActions[numPendingFSTSActions]="SetViewTarget";
		PendingFSTSParm1[numPendingFSTSActions]=ViewTargetTag;
		numPendingFSTSActions ++;
	*/
}
void ADSController::TurnTowardPlayer()
{
	/*
		PendingFSTSActions[numPendingFSTSActions]="TurnTowardPlayer";
		numPendingFSTSActions ++;
	*/
}
void ADSController::Crouch()
{
	/*
		PendingFSTSActions[numPendingFSTSActions]="Crouch";
		numPendingFSTSActions ++;
	*/
}
void ADSController::Stand()
{
	/*
		PendingFSTSActions[numPendingFSTSActions]="Stand";
		numPendingFSTSActions ++;
	*/
}
void ADSController::Walk()
{
	/*
		PendingFSTSActions[numPendingFSTSActions]="Walk";
		numPendingFSTSActions ++;
	*/
}
void ADSController::Run()
{
	/*
		PendingFSTSActions[numPendingFSTSActions]="Run";
		numPendingFSTSActions ++;
	*/
}
void ADSController::WaitForTimer(float PauseTime)
{
	/*
		PendingFSTSActions[numPendingFSTSActions]="WaitForTimer";
		PendingFSTSParm1[numPendingFSTSActions]=PauseTime;
		numPendingFSTSActions ++;
	*/
}
void ADSController::WaitForEvent(FName ExternalEvent)
{
	/*
		PendingFSTSActions[numPendingFSTSActions]="WaitForEvent";
		PendingFSTSParm1[numPendingFSTSActions]=ExternalEvent;
		numPendingFSTSActions ++;
	*/
}
void ADSController::BuildDynamicScriptFromFSTS()
{
	/*
	int32 i = 0;
	SequenceScript.Actions.Length=0;
	if (numPendingFSTSActions > 0)
	{
		if (PendingFSTSActions[0] == "MoveToPoint")
		{
			FSTSMoveToAction=new () UAction_MOVETOPOINT::StaticClass();
			FSTSMoveToAction.DestinationTag=string(PendingFSTSParm1[0]);
			SequenceScript.Actions[SequenceScript.Actions.Length]=FSTSMoveToAction;
		}
		if (PendingFSTSActions[0] == "Use")
		{
			Enemy=nullptr;
			Enable("SeePlayer");
			SequenceScript.Actions[SequenceScript.Actions.Length]=new () UAction_USE::StaticClass();
		}
		if (PendingFSTSActions[0] == "SetViewTarget")
		{
			SequenceScript.Actions[SequenceScript.Actions.Length]=new () UAction_SETVIEWTARGET::StaticClass();
			Action_SETVIEWTARGET(SequenceScript.Actions[(DynamicScript.Actions.Length - 1)]).ViewTargetTag=string(PendingFSTSParm1[0]);
		}
		if (PendingFSTSActions[0] == "PlayAnim")
		{
			SequenceScript.Actions[SequenceScript.Actions.Length]=new () UAction_PLAYANIM::StaticClass();
			Action_PLAYANIM(SequenceScript.Actions[(DynamicScript.Actions.Length - 1)]).BaseAnim=string(PendingFSTSParm1[0]);
		}
		if (PendingFSTSActions[0] == "WaitForAnimEnd")
		{
			SequenceScript.Actions[SequenceScript.Actions.Length]=new () UAction_WAITFORANIMEND::StaticClass();
			Action_WAITFORANIMEND(SequenceScript.Actions[(DynamicScript.Actions.Length - 1)]).Channel=int(PendingFSTSParm1[0]);
		}
		if (PendingFSTSActions[0] == "PlayLipSinc")
		{
			SequenceScript.Actions[SequenceScript.Actions.Length]=new () UACTION_PlayLIPSinc::StaticClass();
			ACTION_PlayLIPSinc(SequenceScript.Actions[(DynamicScript.Actions.Length - 1)]).LIPSincAnimName=string(PendingFSTSParm1[0]);
			ACTION_PlayLIPSinc(SequenceScript.Actions[(DynamicScript.Actions.Length - 1)]).LIPSincAnimName=string(PendingFSTSParm1[0]);
			ACTION_PlayLIPSinc(SequenceScript.Actions[(DynamicScript.Actions.Length - 1)]).LIPSincAnimName=string(PendingFSTSParm1[0]);
			ACTION_PlayLIPSinc(SequenceScript.Actions[(DynamicScript.Actions.Length - 1)]).LIPSincAnimName=string(PendingFSTSParm1[0]);
		}
		if (PendingFSTSActions[0] == "WaitForLipSincAnimEnd")
		{
			SequenceScript.Actions[SequenceScript.Actions.Length]=new () UACTION_WaitForLIPSincAnimEnd::StaticClass();
		}
		if (PendingFSTSActions[0] == "WaitForTimer")
		{
			SequenceScript.Actions[SequenceScript.Actions.Length]=new () UAction_WAITFORTIMER::StaticClass();
			Action_WAITFORTIMER(SequenceScript.Actions[(DynamicScript.Actions.Length - 1)]).PauseTime=float(PendingFSTSParm1[0]);
		}
		if (PendingFSTSActions[0] == "WaitForEvent")
		{
			SequenceScript.Actions[SequenceScript.Actions.Length]=new () UAction_WAITFOREVENT::StaticClass();
			Action_WAITFOREVENT(SequenceScript.Actions[(DynamicScript.Actions.Length - 1)]).ExternalEvent=string(PendingFSTSParm1[0]);
		}
		if (PendingFSTSActions[0] == "Event")
		{
			SequenceScript.Actions[SequenceScript.Actions.Length]=new () UACTION_TriggerEvent::StaticClass();
			ACTION_TriggerEvent(SequenceScript.Actions[(SequenceScript.Actions.Length - 1)]).Event=string(PendingFSTSParm1[0]);
		}
		if (PendingFSTSActions[0] == "Crouch")
		{
			SequenceScript.Actions[SequenceScript.Actions.Length]=new () UAction_CROUCH::StaticClass();
		}
		if (PendingFSTSActions[0] == "Stand")
		{
			SequenceScript.Actions[SequenceScript.Actions.Length]=new () UACTION_Stand::StaticClass();
		}
		if (PendingFSTSActions[0] == "Walk")
		{
			SequenceScript.Actions[SequenceScript.Actions.Length]=new () UAction_WALK::StaticClass();
		}
		if (PendingFSTSActions[0] == "Run")
		{
			SequenceScript.Actions[SequenceScript.Actions.Length]=new () UAction_RUN::StaticClass();
		}
		if (PendingFSTSActions[0] == "TurnTowardPlayer")
		{
			SequenceScript.Actions[SequenceScript.Actions.Length]=new () UAction_TURNTOWARDPLAYER::StaticClass();
		}
		for (i=0; i<numPendingFSTSActions; i++)
		{
			PendingFSTSActions[i]=PendingFSTSActions[(i + 1)];
			PendingFSTSParm1[i]=PendingFSTSParm1[(i + 1)];
			PendingFSTSParm2[i]=PendingFSTSParm2[(i + 1)];
			PendingFSTSParm3[i]=PendingFSTSParm3[(i + 1)];
		}
		numPendingFSTSActions --;
	}
		}
	*/
}
void ADSController::DestinationOccupied()
{
	//Pawn.bAbortMoveIfGoalOccupied=false;
}
void ADSController::EndCurrentScript()
{
	//GotoState('Idle','Begin');
}
void ADSController::ClearAnimation()
{
}
void ADSController::Tick(float Delta)
{
	/*
		tickAccumulator += Delta;
		ElapsedTime += Delta;
		CheckForNewCommand();
	*/
}
void ADSController::PawnDied(APawn* p)
{
	/*
		Log("Pawn died?",'DSController');
		if (Pawn != p)
		{
			return;
		}
		Pawn=nullptr;
		PendingMover=nullptr;
		Destroy();
	*/
}
void ADSController::Destroyed()
{
	//Log("Destroyed",'DSController');
	Super::Destroyed();
	return;
}
