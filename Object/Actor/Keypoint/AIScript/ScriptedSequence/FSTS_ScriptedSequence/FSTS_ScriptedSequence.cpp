// All the original content belonged to the US Army

#include "AA29/Object/Actor/Keypoint/AIScript/ScriptedSequence/FSTS_ScriptedSequence/FSTS_ScriptedSequence.h"

AFSTS_ScriptedSequence::AFSTS_ScriptedSequence(const FObjectInitializer& objectInitializer)	:Super(objectInitializer)
{
	//ScriptControllerClass = class'FSTS.DSController';
	//bStatic = false;
	//bCollideWhenPlacing = false;
}

void AFSTS_ScriptedSequence::TakeOver(APawn* p)
{
	/*
	local Gameplay.ScriptedController S;
	if (ScriptedController(p.Controller) != nullptr)
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
