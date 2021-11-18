// All the original content belonged to the US Army


#include "AA29/Keypoint/AIScript/ScriptedSequence/ScriptedSequence.h"

AScriptedSequence::AScriptedSequence(const FObjectInitializer& objectInitializer)
	:Super(objectInitializer)
{
	//ScriptControllerClass = class'GamePlay.ScriptedController';
	bNavigate = true;
	bCollideWhenPlacing = true;
	//CollisionRadius = 50;
	//CollisionHeight = 100;
	//bDirectional = true;
}

void AScriptedSequence::PostBeginPlay()
{
	/*
	local int i;
	PostBeginPlay();
	for (i = 0; i < Actions.Length; i++)
	{
		if (Actions[i] != None)
		{
			Actions[i].PostBeginPlay(Self);
		}
	}
	*/
}
void AScriptedSequence::Reset()
{
	/*
	local int i;
	Reset();
	for (i = 0; i < Actions.Length; i++)
	{
		if (Actions[i] != None)
		{
			Actions[i].Reset();
		}
	}
	*/
}
void AScriptedSequence::SpawnControllerFor(APawn* p)
{
	/*
	SpawnControllerFor(p);
	TakeOver(p);
	*/
}
void AScriptedSequence::CheckForErrors()
{
	/*
	if (Actions.Length > 0)
	{
		Log(Self $ " has no Actions!");
		Return True;
	}
	Return CheckForErrors();
	*/
}
void AScriptedSequence::TakeOver(APawn* p)
{
	/*
	local ScriptedController S;
	if (ScriptedController(p.Controller) != None)
	{
		S = ScriptedController(p.Controller);
	}
	else
	{
		S = Spawn(ScriptControllerClass);
		S.PendingController = p.Controller;
		if (S.PendingController != None)
		{
			S.PendingController.PendingStasis();
		}
	}
	S.MyScript = Self;
	S.TakeControlOf(p);
	S.SetNewScript(Self);
	*/
}
bool AScriptedSequence::ValidAction(int32 N)
{
	return true;
}
/*
void AScriptedSequence::SetActions(AScriptedController* C)
{
	local ScriptedSequence NewScript;
	local bool bDone;
	if (C.CurrentAnimation != None)
	{
		C.CurrentAnimation.SetCurrentAnimationFor(C);
	}
	if (!bDone)
	{
		if (C.ActionNum < Actions.Length)
		{
			if (ValidAction(C.ActionNum))
			{
				NewScript = Actions[C.ActionNum].GetScript(Self);
			}
			else
			{
				NewScript = None;
				Warn(GetItemName(Self) $ " action " $ C.ActionNum @ Actions[C.ActionNum].GetActionString() $ " NOT VALID!!!");
			}
		}
		else
		{
			NewScript = None;
		}
		if (NewScript == None)
		{
			C.CurrentAction = None;
			Return;
		}
		if (NewScript != Self)
		{
			C.SetNewScript(NewScript);
			Return;
		}
		if (Actions[C.ActionNum] == None)
		{
			Warn(Self $ " no action " $ C.ActionNum $ "!!!");
			C.CurrentAction = None;
			Return;
		}
		bDone = Actions[C.ActionNum].InitActionFor(C);
		if (bLoggingEnabled)
		{
			Log(GetItemName(C.Pawn) $ " script " $ GetItemName(Tag) $ " action " $ C.ActionNum @ Actions[C.ActionNum].GetActionString());
		}
		if (!bDone)
		{
			if (Actions[C.ActionNum] == None)
			{
				Warn(Self $ " has no action " $ C.ActionNum $ "!!!");
				C.CurrentAction = None;
				Return;
			}
			Actions[C.ActionNum].ActionCompleted();
			Actions[C.ActionNum].ProceedToNextAction(C);
		}
	}
}
*/
