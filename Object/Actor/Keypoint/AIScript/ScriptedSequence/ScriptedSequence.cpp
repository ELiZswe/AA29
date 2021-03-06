// All the original content belonged to the US Army

#include "AA29/Object/Actor/Keypoint/AIScript/ScriptedSequence/ScriptedSequence.h"
#include "AA29/Object/Actor/Controller/AIController/ScriptedController/ScriptedController.h"

AScriptedSequence::AScriptedSequence(const FObjectInitializer& objectInitializer) :Super(objectInitializer)
{
	//ScriptControllerClass = AScriptedController::StaticClass();
	bNavigate = true;
	bCollideWhenPlacing = true;
	//CollisionRadius = 50;
	//CollisionHeight = 100;
	//bDirectional = true;
}

void AScriptedSequence::PostBeginPlay()
{
	/*
	int32 i = 0;
	PostBeginPlay();
	for (i = 0; i < Actions.Num(); i++)
	{
		if (Actions[i] != nullptr)
		{
			Actions[i].PostBeginPlay(this);
		}
	}
	*/
}
void AScriptedSequence::Reset()
{
	/*
	int32 i = 0;
	Reset();
	for (i = 0; i < Actions.Num(); i++)
	{
		if (Actions[i] != nullptr)
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
	if (Actions.Num() > 0)
	{
		Log(Self + " has no Actions!");
		return true;
	}
	return Super::CheckForErrors();
	*/
}

void AScriptedSequence::TakeOver(APawn* p)
{
	AScriptedController* S = nullptr;
	/*
	if (Cast<AScriptedController>(p.Controller) != nullptr)
	{
		S = ScriptedController(p.Controller);
	}
	else
	{
		S = Spawn(ScriptControllerClass);
		S.PendingController = p.Controller;
		if (S.PendingController != nullptr)
		{
			S.PendingController.PendingStasis();
		}
	}
	S.MyScript = this;
	S.TakeControlOf(p);
	S.SetNewScript(this);
	*/
}

bool AScriptedSequence::ValidAction(int32 N)
{
	return true;
}

void AScriptedSequence::SetActions(AScriptedController* C)
{
	AScriptedSequence* NewScript = nullptr;
	bool bDone = false;
	/*
	if (C.CurrentAnimation != nullptr)
	{
		C.CurrentAnimation.SetCurrentAnimationFor(C);
	}
	if (!bDone)
	{
		if (C.ActionNum < Actions.Num())
		{
			if (ValidAction(C.ActionNum))
			{
				NewScript = Actions[C.ActionNum].GetScript(this);
			}
			else
			{
				NewScript = nullptr;
				Warn(GetItemName(this) + " action " + C.ActionNum @ Actions[C.ActionNum].GetActionString() + " NOT VALID!!!");
			}
		}
		else
		{
			NewScript = nullptr;
		}
		if (NewScript == nullptr)
		{
			C.CurrentAction = nullptr;
			return;
		}
		if (NewScript != Self)
		{
			C.SetNewScript(NewScript);
			return;
		}
		if (Actions[C.ActionNum] == nullptr)
		{
			Warn(Self + " no action " + C.ActionNum + "!!!");
			C.CurrentAction = nullptr;
			return;
		}
		bDone = Actions[C.ActionNum].InitActionFor(C);
		if (bLoggingEnabled)
		{
			Log(GetItemName(C.Pawn) + " script " + GetItemName(Tag) + " action " + C.ActionNum @ Actions[C.ActionNum].GetActionString());
		}
		if (!bDone)
		{
			if (Actions[C.ActionNum] == nullptr)
			{
				Warn(Self + " has no action " + C.ActionNum + "!!!");
				C.CurrentAction = nullptr;
				return;
			}
			Actions[C.ActionNum].ActionCompleted();
			Actions[C.ActionNum].ProceedToNextAction(C);
		}
	}
	*/
}

