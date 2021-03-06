// All the original content belonged to the US Army

#include "AA29/Object/Actor/AnimationController/AnimationController.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"

// Sets default values
AAnimationController::AAnimationController()
{
	AnimationQueue.SetNum(16);
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//bHidden = true;
}


void AAnimationController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AAnimationController::QueueClear()
{
	QueueFront = 0;
	QueueBack = 0;
}

bool AAnimationController::QueueIsEmpty()
{
	//return (QueueFront == QueueBack);
	return true;      //FAKE    /ELiZ
}

bool AAnimationController::QueueIsFull()
{
	//return QueueFront == QueueBack + 1 % 16;
	return false;    //FAKE   /EliZ
}

bool AAnimationController::Enqueue(FAnimInstruction Inst)
{
	if (QueueIsFull())
	{
		//Log("ERROR: Animation Queue Overflow");
		return false;
	}
	//AnimationQueue[QueueBack]=Inst;
	//QueueBack=QueueBack + 1 % 16;
	return true;
}

bool AAnimationController::Dequeue()
{
	if (QueueIsEmpty())
	{
		//Log("ERROF: Animation Queue Underflow");
		return false;
	}
	//QueueFront=QueueFront + 1 % 16;
	return true;
}
void AAnimationController::BeginPlay()
{
	/*
		BeginPlay();
		if (AnimatedActorTag != "None")
		{
			AnimatedActor=GetActorByTag(AnimatedActorTag);
		}
		else
		{
			if (Owner != nullptr)
			{
				AnimatedActor=Owner;
			}
		}
		if (AnimatedActor == nullptr)
		{
			Log("ERROR: AnimationController unable to find actor with tag" @ AnimatedActorTag);
		}
		else
		{
			if (Cast<AAGP_Pawn>(AnimatedActor) != nullptr)
			{
				Cast<AAGP_Pawn>(AnimatedActor).SetAnimationMonitor(this);
			}
		}
	*/
}

void AAnimationController::PlayNextInstruction()
{
	FAnimInstruction Inst = FAnimInstruction({});
	bool bPlayNext = false; 
	/*
		if (QueueIsEmpty())
		{
			Log("ERROR: Animation Queue Is Empty");
			return;
		}
		else
		{
			if (AnimatedActor == nullptr)
			{
				Log("ERROR: Animated Actor Is None");
				return;
			}
		}
		Inst=AnimationQueue[QueueFront];
		if (bDebug)
		{
			Log("PlayNextInstruction -" @ GetDebugString(Inst));
		}
		LoopCount=0;
		switch(Inst.Command)
		{
			case 0:
			AnimatedActor.PlayAnim(Inst.Sequence,Inst.Rate,Inst.Time,Inst.Channel);
			break;
			case 1:
			AnimatedActor.LoopAnim(Inst.Sequence,Inst.Rate,Inst.Time,Inst.Channel);
			break;
			case 2:
			AnimatedActor.TweenAnim(Inst.Sequence,Inst.Time,Inst.Channel);
			if (Inst.Time > 0)
			{
				SetTimer(Inst.Time,false);
			}
			else
			{
				AnimEnd(0);
			}
			GOTO JL01F6;
			case 3:
			AnimatedActor.StopAnimating();
			bPlayNext=true;
			GOTO JL01F6;
			case 4:
			AnimatedActor.FreezeAnimAt(Inst.Time,Inst.Channel);
			bPlayNext=true;
			GOTO JL01F6;
			case 5:
			FlushInstructions();
			bPlayNext=true;
			GOTO JL01F6;
			default:
			GOTO JL01F6;
	JL01F6:
		}
		if (bPlayNext)
		{
			AnimEnd(0);
		}
	*/
}

void AAnimationController::AddInstruction(FAnimInstruction Inst)
{
	bool bPlayNow = false;
	if (bDebug)
	{
		//Log("AnimationController::AddInstruction - PlayNow" @ QueueIsEmpty() @ GetDebugString(Inst));
	}
	if (QueueIsEmpty())
	{
		bPlayNow=true;
	}
	if (Enqueue(Inst) && bPlayNow)
	{
		PlayNextInstruction();
	}
}

void AAnimationController::FlushInstructions()
{
	QueueClear();
}

void AAnimationController::Timer()
{
	//AnimEnd(0);
}

void AAnimationController::AnimEnd(int32 Channel)
{
	FAnimInstruction Inst  = FAnimInstruction({});
	FName Seq = "";
	float frame = 0;
	float Rate = 0;
	/*
		if (bDebug)
		{
			AnimatedActor.GetAnimParams(0,Seq,frame,Rate);
			Log("AnimationController::AnimEnd" @ Seq @ frame @ Rate @ "Num" @ AnimationQueue[QueueFront].LoopNum @ "Count" @ LoopCount);
		}
		if (! QueueIsEmpty())
		{
			Inst=AnimationQueue[QueueFront];
			if (Inst.Command == 1 && Inst.LoopNum < 0 || ++ LoopCount < Inst.LoopNum)
			{
				return;
			}
			Dequeue();
			if (! QueueIsEmpty())
			{
				PlayNextInstruction();
			}
		}
	*/
}

FString AAnimationController::GetDebugString(FAnimInstruction Inst)
{
	FString t = "";
	switch(Inst.Command)
	{
		case EeAnimationCommand::AC_PlayAnim:
			t="AC_PlayAnim";
			break;
		case EeAnimationCommand::AC_LoopAnim:
			t="AC_LoopAnim";
			break;
		case EeAnimationCommand::AC_TweenAnim:
			t="AC_TweenAnim";
			break;
		case EeAnimationCommand::AC_StopAnimating:
			t="AC_StopAnimating";
			break;
		case EeAnimationCommand::AC_FreezeAnimAt:
			t="AC_FreezeAnimAt";
			break;
		case EeAnimationCommand::AC_ClearQueue:
			t="AC_ClearQueue";
			break;
		default:
			break;
	}
	//return "AnimationController::PlayNextInstruction - Front Index" @ QueueFront @ "Inst" @ t @ "Seq" @ Inst.Sequence @ "Rate" @ Inst.Rate @ "Time" @ Inst.Time @ "Chan" @ Inst.Channel @ "Loop" @ Inst.LoopNum;
	return "FAKE";    //FAKE   /EliZ
}

