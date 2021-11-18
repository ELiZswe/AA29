// All the original content belonged to the US Army


#include "DSController.h"

ADSController::ADSController()
{
	bReadyForScripting = true;
	bChangingPawns = true;
	bAdvancedTactics = false;
}

/*
* State Scripting
{
	Function EndCurrentScript ()
	{
		MoveTimer=-1;
		Destination=Pawn.Location;
		MoveTarget=None;
		CurrentAction.ActionCompleted();
		LeaveScripting();
	}
	Function LeaveScripting ()
	{
		bReadyForScripting=False;
		bReadyToBuild=True;
		GotoState('Idle','Begin');
	}
	Function InitForNextAction ()
	{
		CheckForNewCommand();
		SequenceScript.SetActions(Self);
		if (CurrentAction == None)
		{
			LeaveScripting();
			Return;
		}
		MyScript=SequenceScript;
		if (CurrentAnimation == None)
		{
			ClearAnimation();
		}
		Enable('Tick');
	}
}
State Idle
{
	Function SetMoveTarget ()
	{
		local Actor NextMoveTarget;
		Focus=ScriptedFocus;
		NextMoveTarget=assignedPosition;
		if (NextMoveTarget == None)
		{
			GotoState('Broken');
			Return;
		}
		if (Focus == None)
		{
			Focus=NextMoveTarget;
		}
		MoveTarget=NextMoveTarget;
		if (! actorReachable(MoveTarget))
		{
			MoveTarget=FindPathToward(MoveTarget,False);
			if (MoveTarget == None)
			{
				MoveTarget=assignedPosition;
				Return;
			}
			if (Focus == NextMoveTarget)
			{
				Focus=MoveTarget;
			}
		}
	}
	Function BeginState ()
	{
		Pawn.StopAnimating(True);
		Pawn.PlayAnim(FSTS_NPC_DrillSergeant(Pawn).DSIdleAnim,1,0.2);
	}
}

*/


void ADSController::PostBeginPlay()
{
	/*
		SetNewScript(DynamicScript);
		ActionNum=0;
		if (SequenceScript != None)
		{
			SequenceScript.SetActions(Self);
		}
		bControlAnimations=True;
	*/
}
void ADSController::InitPlayerReplicationInfo()
{
	/*
		if (PlayerReplicationInfo != None)
		{
			if (PlayerReplicationInfo.PlayerName == "")
			{
				PlayerReplicationInfo.SetPlayerName(Class'GameInfo'.Default.DefaultPlayerName);
			}
			PlayerReplicationInfo.bNoTeam=! Level.Game.bTeamGame;
		}
	*/
}
/*
void ADSController::InitializeFor(AScriptedSequence* t)
{
		MyScript=t;
		bIsPlayer=False;
		SetNewScript(t);
		ActionNum=0;
		SequenceScript.SetActions(Self);
		GotoState('Scripting');
}
*/
void ADSController::TakeControlOf(APawn* aPawn)
{
	/*
		if (Pawn != aPawn)
		{
			aPawn.PossessedBy(Self);
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
		CurrentAction=None;
		CurrentAnimation=None;
		ScriptedFocus=None;
		if (Pawn != None)
		{
			Pawn.SetWalking(False);
			Pawn.ShouldCrouch(False);
		}
	*/
}
/*
void ADSController::SetNewScript(AScriptedSequence* NewScript)
{
		local int i;
		if (DynamicScript == None || NewScript != DynamicScript)
		{
			DynamicScript=Spawn('FSTS_ScriptedSequence');
			if (DynamicScript == None)
			{
				Log("DSConSpawn of dynamic ScriptedSequence failed",'DSController');
				DynamicScript=NewScript;
			}
			if (MyScript != None)
			{
				OriginalScript=ScriptedSequence(MyScript);
			}
			if (OriginalScript != None)
			{
				for (i=0; i<OriginalScript.Actions.Length; i++)
				{
					DynamicScript.Actions[i]=OriginalScript.Actions[i];
				}
			}
			DynamicScript.Actions[DynamicScript.Actions.Length]=new() classClass'Action_WAITFORTIMER';
			Action_WAITFORTIMER(DynamicScript.Actions[DynamicScript.Actions.Length - 1]).PauseTime=3;
		}
		bReadyToBuild=False;
		bReadyForScripting=True;
		MyScript=DynamicScript;
		SequenceScript=DynamicScript;
		Focus=None;
		ClearScript();
		SetEnemyReaction(3);
}
*/
void ADSController::CheckForNewCommand()
{
	/*
		if (bReadyToBuild && numPendingFSTSActions > 0)
		{
			bReadyToBuild=False;
			SequenceScript=DynamicScript;
			BuildDynamicScriptFromFSTS();
			bReadyForScripting=True;
		}
		Return False;
	*/
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
		local int i;
		SequenceScript.Actions.Length=0;
		if (numPendingFSTSActions > 0)
		{
			if (PendingFSTSActions[0] == "MoveToPoint")
			{
				FSTSMoveToAction=new() classClass'Action_MOVETOPOINT';
				FSTSMoveToAction.DestinationTag=PendingFSTSParm1[0];
				SequenceScript.Actions[SequenceScript.Actions.Length]=FSTSMoveToAction;
			}
			if (PendingFSTSActions[0] == "Use")
			{
				Enemy=None;
				Enable('SeePlayer');
				SequenceScript.Actions[SequenceScript.Actions.Length]=new() classClass'Action_USE';
			}
			if (PendingFSTSActions[0] == "SetViewTarget")
			{
				SequenceScript.Actions[SequenceScript.Actions.Length]=new() classClass'Action_SETVIEWTARGET';
				Action_SETVIEWTARGET(SequenceScript.Actions[DynamicScript.Actions.Length - 1]).ViewTargetTag=PendingFSTSParm1[0];
			}
			if (PendingFSTSActions[0] == "PlayAnim")
			{
				SequenceScript.Actions[SequenceScript.Actions.Length]=new() classClass'Action_PLAYANIM';
				Action_PLAYANIM(SequenceScript.Actions[DynamicScript.Actions.Length - 1]).BaseAnim=PendingFSTSParm1[0];
			}
			if (PendingFSTSActions[0] == "WaitForAnimEnd")
			{
				SequenceScript.Actions[SequenceScript.Actions.Length]=new() classClass'Action_WAITFORANIMEND';
				Action_WAITFORANIMEND(SequenceScript.Actions[DynamicScript.Actions.Length - 1]).Channel=PendingFSTSParm1[0];
			}
			if (PendingFSTSActions[0] == "PlayLipSinc")
			{
				SequenceScript.Actions[SequenceScript.Actions.Length]=new() classClass'ACTION_PlayLIPSinc';
				ACTION_PlayLIPSinc(SequenceScript.Actions[DynamicScript.Actions.Length - 1]).LIPSincAnimName=PendingFSTSParm1[0];
				ACTION_PlayLIPSinc(SequenceScript.Actions[DynamicScript.Actions.Length - 1]).LIPSincAnimName=PendingFSTSParm1[0];
				ACTION_PlayLIPSinc(SequenceScript.Actions[DynamicScript.Actions.Length - 1]).LIPSincAnimName=PendingFSTSParm1[0];
				ACTION_PlayLIPSinc(SequenceScript.Actions[DynamicScript.Actions.Length - 1]).LIPSincAnimName=PendingFSTSParm1[0];
			}
			if (PendingFSTSActions[0] == "WaitForLipSincAnimEnd")
			{
				SequenceScript.Actions[SequenceScript.Actions.Length]=new() classClass'ACTION_WaitForLIPSincAnimEnd';
			}
			if (PendingFSTSActions[0] == "WaitForTimer")
			{
				SequenceScript.Actions[SequenceScript.Actions.Length]=new() classClass'Action_WAITFORTIMER';
				Action_WAITFORTIMER(SequenceScript.Actions[DynamicScript.Actions.Length - 1]).PauseTime=PendingFSTSParm1[0];
			}
			if (PendingFSTSActions[0] == "WaitForEvent")
			{
				SequenceScript.Actions[SequenceScript.Actions.Length]=new() classClass'Action_WAITFOREVENT';
				Action_WAITFOREVENT(SequenceScript.Actions[DynamicScript.Actions.Length - 1]).ExternalEvent=PendingFSTSParm1[0];
			}
			if (PendingFSTSActions[0] == "Event")
			{
				SequenceScript.Actions[SequenceScript.Actions.Length]=new() classClass'ACTION_TriggerEvent';
				ACTION_TriggerEvent(SequenceScript.Actions[SequenceScript.Actions.Length - 1]).Event=PendingFSTSParm1[0];
			}
			if (PendingFSTSActions[0] == "Crouch")
			{
				SequenceScript.Actions[SequenceScript.Actions.Length]=new() classClass'Action_CROUCH';
			}
			if (PendingFSTSActions[0] == "Stand")
			{
				SequenceScript.Actions[SequenceScript.Actions.Length]=new() classClass'ACTION_Stand';
			}
			if (PendingFSTSActions[0] == "Walk")
			{
				SequenceScript.Actions[SequenceScript.Actions.Length]=new() classClass'Action_WALK';
			}
			if (PendingFSTSActions[0] == "Run")
			{
				SequenceScript.Actions[SequenceScript.Actions.Length]=new() classClass'Action_RUN';
			}
			if (PendingFSTSActions[0] == "TurnTowardPlayer")
			{
				SequenceScript.Actions[SequenceScript.Actions.Length]=new() classClass'Action_TURNTOWARDPLAYER';
			}
			for (i=0; i<numPendingFSTSActions; i++)
			{
				PendingFSTSActions[i]=PendingFSTSActions[i + 1];
				PendingFSTSParm1[i]=PendingFSTSParm1[i + 1];
				PendingFSTSParm2[i]=PendingFSTSParm2[i + 1];
				PendingFSTSParm3[i]=PendingFSTSParm3[i + 1];
			}
			numPendingFSTSActions --;
		}
	*/
}
void ADSController::DestinationOccupied()
{
	//Pawn.bAbortMoveIfGoalOccupied=False;
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
			Return;
		}
		Pawn=None;
		PendingMover=None;
		Destroy();
	*/
}
void ADSController::Destroyed()
{
	//Log("Destroyed",'DSController');
	Super::Destroyed();
	return;
}