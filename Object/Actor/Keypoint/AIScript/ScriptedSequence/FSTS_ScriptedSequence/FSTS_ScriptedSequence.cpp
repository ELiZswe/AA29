// All the original content belonged to the US Army


#include "AA29/Object/Actor/Keypoint/AIScript/ScriptedSequence/FSTS_ScriptedSequence/FSTS_ScriptedSequence.h"

AFSTS_ScriptedSequence::AFSTS_ScriptedSequence(const FObjectInitializer& objectInitializer)	:Super(objectInitializer)
{
	//ScriptControllerClass = class'FSTS.DSController';
	//bStatic = false;
	//bCollideWhenPlacing = false;
}

void TakeOver(APawn* p)
{
	/*
	local Gameplay.ScriptedController S;
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