// All the original content belonged to the US Army


#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCDummyPawnController/NPCDummyPawnController.h"

ANPCDummyPawnController::ANPCDummyPawnController()
{

}

/*
State PawnStartsAsPermanentDummy
{
	simulated Function PlayLoopingAnimation()
	{
		Pawn.AnimBlendParams(AnimChannel,1,Pawn.BlendChangeTime,Pawn.BlendChangeTime);
		Pawn.LoopAnim(AnimSequence,1,0,AnimChannel);
	}
	simulated Function StopAnimation()
	{
		StopAnimating(false);
	}
Begin:
	NPCLog(string(Self) $ "." $ string(GetStateName()) $ " trying to start dummy pawn with anim: " $ string(AnimSequence));
	if (bDummyPawnLoopIdleAnim)
	{
		Disable('AnimEnd');
		PlayLoopingAnimation();
		if (fpAnimFreezeTime > 0)
		{
			Sleep(fpAnimFreezeTime);
			StopAnimation();
		}
		JL'DoNothing'
;
	}
}
*/
