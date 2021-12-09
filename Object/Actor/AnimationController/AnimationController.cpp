// All the original content belonged to the US Army


#include "AA29/Object/Actor/AnimationController/AnimationController.h"

// Sets default values
AAnimationController::AAnimationController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//bHidden = true;
}

// Called every frame
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

void AAnimationController::QueueIsFull()
{
	//Return QueueFront == QueueBack + 1 % 16;
}
/*
bool AAnimationController::Enqueue(AAnimInstruction* Inst)
{
		if (QueueIsFull())
		{
			Log("ERROR: Animation Queue Overflow");
			return false;
		}
		AnimationQueue[QueueBack]=Inst;
		QueueBack=QueueBack + 1 % 16;
	return true;
}
*/
void AAnimationController::Dequeue()
{
	/*
		if (QueueIsEmpty())
		{
			Log("ERROF: Animation Queue Underflow");
			return false;
		}
		QueueFront=QueueFront + 1 % 16;
		return true;
	*/
}
void AAnimationController::BeginPlay()
{
	/*
		BeginPlay();
		if (AnimatedActorTag != 'None')
		{
			AnimatedActor=GetActorByTag(AnimatedActorTag);
		}
		else
		{
			if (Owner != None)
			{
				AnimatedActor=Owner;
			}
		}
		if (AnimatedActor == None)
		{
			Log("ERROR: AnimationController unable to find actor with tag" @ AnimatedActorTag);
		}
		else
		{
			if (AGP_Pawn(AnimatedActor) != None)
			{
				AGP_Pawn(AnimatedActor).SetAnimationMonitor(Self);
			}
		}
	*/
}
void AAnimationController::PlayNextInstruction()
{
	/*
		local AAnimInstruction* Inst;
		local bool bPlayNext;
		if (QueueIsEmpty())
		{
			Log("ERROR: Animation Queue Is Empty");
			Return;
		}
		else
		{
			if (AnimatedActor == None)
			{
				Log("ERROR: Animated Actor Is None");
				Return;
			}
		}
		Inst=AnimationQueue[QueueFront];
		if (bDebug)
		{
			Log("PlayNextInstruction -" @ GetDebugString(Inst));
		}
		LoopCount=0;
		Switch(Inst.Command)
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
				SetTimer(Inst.Time,False);
			}
			else
			{
				AnimEnd(0);
			}
			GOTO JL01F6;
			case 3:
			AnimatedActor.StopAnimating();
			bPlayNext=True;
			GOTO JL01F6;
			case 4:
			AnimatedActor.FreezeAnimAt(Inst.Time,Inst.Channel);
			bPlayNext=True;
			GOTO JL01F6;
			case 5:
			FlushInstructions();
			bPlayNext=True;
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
/*

void AAnimationController::AddInstruction(AAnimInstruction* Inst)
{
		local bool bPlayNow;
		if (bDebug)
		{
			Log("AnimationController::AddInstruction - PlayNow" @ QueueIsEmpty() @ GetDebugString(Inst));
		}
		if (QueueIsEmpty())
		{
			bPlayNow=True;
		}
		if (Enqueue(Inst) && bPlayNow)
		{
			PlayNextInstruction();
		}
}
	*/
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
	/*
		local AAnimInstruction* Inst;
		local name Seq;
		local float frame;
		local float Rate;
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
				Return;
			}
			Dequeue();
			if (! QueueIsEmpty())
			{
				PlayNextInstruction();
			}
		}
	*/
}
/*

void AAnimationController::GetDebugString(AAnimInstruction* Inst)
{
		local string t;
		Switch(Inst.Command)
		{
			case 0:
			t="AC_PlayAnim";
			break;
			case 1:
			t="AC_LoopAnim";
			break;
			case 2:
			t="AC_TweenAnim";
			break;
			case 3:
			t="AC_StopAnimating";
			break;
			case 4:
			t="AC_FreezeAnimAt";
			break;
			case 5:
			t="AC_ClearQueue";
			break;
			default:
		}
		Return "AnimationController::PlayNextInstruction - Front Index" @ QueueFront @ "Inst" @ t @ "Seq" @ Inst.Sequence @ "Rate" @ Inst.Rate @ "Time" @ Inst.Time @ "Chan" @ Inst.Channel @ "Loop" @ Inst.LoopNum;
}
	*/
