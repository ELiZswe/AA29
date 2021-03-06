// All the original content belonged to the US Army

#include "AA29/Object/Actor/EventLab/FSTS_EventLab/FSTS_EventLab.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/AGP_Character.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/FSTS_Pawn/FSTS_NPC_DrillSergeant.h"
#include "AA29/Object/FSTS_PlayerHint/FSTS_PlayerHint.h"

AFSTS_EventLab::AFSTS_EventLab()
{
	ActiveHint = -1;
}

void AFSTS_EventLab::QueueHint(UFSTS_PlayerHint* Hint)
{
	/*
	Hint.MyEventlab = this;
	HintQueue[HintQueue.Num()] = Hint;
	*/
}

void AFSTS_EventLab::RemoveHint(UFSTS_PlayerHint* Hint)
{
	/*
	int32 i = 0;
	i = 0;
	if (i < HintQueue.Num())
	{
		if (HintQueue[i] == Hint)
		{
			HintQueue.RemoveAt(i, 1);
			Hint.Reset();
		}
		else
		{
			i++;
		}
	}
	*/
}

void AFSTS_EventLab::RemoveAllHints()
{
	/*
	if (HintQueue.Num() > 0)
	{
		RemoveHint(HintQueue[0]);
	}
	*/
}

void AFSTS_EventLab::EventLabTick(float DeltaTime)
{
	/*
	int32 i = 0;
	Super::EventLabTick(DeltaTime);
	if (ActiveHint > -1)
	{
		if (HintQueue[ActiveHint].ContinueDisplay())
		{
			return;
		}
		else
		{
			ActiveHint = -1;
		}
	}
	else
	{
		i = 0;
		if (i < HintQueue.Num())
		{
			if (HintQueue[i].StartDisplay())
			{
				ActiveHint = i;
			}
			else
			{
				i++;
			}
		}
	}
	*/
}

void AFSTS_EventLab::LinkDrillSergeants()
{
	AActor* SearchActor = nullptr;
	/*
	ForEach AllActors(Class'Actor', SearchActor)
	{
		if ((DrillSergeant == nullptr) && (DrillSergeantTag == SearchActor.Tag))
		{
			DrillSergeant = FSTS_NPC_DrillSergeant(SearchActor);
		}
		if ((AltDrillSergeant == nullptr) && (AltDrillSergeantTag == SearchActor.Tag))
		{
			AltDrillSergeant = FSTS_NPC_DrillSergeant(SearchActor);
		}
	}
	*/
}

void AFSTS_EventLab::DrillSergeantUsed(AAGP_Character* Sarge)
{
	//NotifyDrillSergeantUsed();
}

void AFSTS_EventLab::SetDrillSergeantParams(bool bAcceptDSUse, bool bStartFromDSUse, bool bFadeMoveOnDSUse)
{
	/*
	DrillSergeant.bUseActionIcon = bAcceptDSUse;
	bAcceptDrillSergeantUse = bAcceptDSUse;
	bStartFromDrillSergeantUse = bStartFromDSUse;
	bFadeMoveFromDrillSergeantUse = bFadeMoveOnDSUse;
	*/
}

void AFSTS_EventLab::FadeMoveStart(AActor* PlayerMovePoint, AFSTS_EventLab* CallBackScript)
{
	/*
	if (bFadeMoveActive)
	{
		Log("Trying to do a Fade-Move while one is in progress, breaking out...", 'FSTS_EventLab');
		return;
	}
	bFadeMoveActive = true;
	FadeMoveInfo.PlayerMovePoint = PlayerMovePoint;
	FadeMoveInfo.CallBackScript = CallBackScript;
	PlayerLock(true, true);
	FadeMoveInfo.CallBackScript.NotifyFadeMoveStart(FadeMoveInfo.PlayerMovePoint.Tag);
	SetCustomTimer(1, false, 'FadeMoveMiddle');
	FadeOutBlack(1);
	*/
}

void AFSTS_EventLab::FadeMoveMiddle()
{
	/*
	if (FadeMoveInfo.PlayerMovePoint != nullptr)
	{
		Controller.SetRotation(FadeMoveInfo.PlayerMovePoint.Rotation);
		Player.SetLocation(FadeMoveInfo.PlayerMovePoint.Location);
	}
	else
	{
		Log("WARNING! Trying to move player to a non-existant point.", 'FSTS_EventLab');
	}
	FadeMoveInfo.CallBackScript.NotifyFadeMoveMiddle(FadeMoveInfo.PlayerMovePoint.Tag);
	SetCustomTimer(1, false, 'FadeMoveEnd');
	FadeInBlack(1);
	*/
}

void AFSTS_EventLab::FadeMoveEnd()
{
	/*
	PlayerLock(false, false);
	FadeMoveInfo.CallBackScript.NotifyFadeMoveEnd(FadeMoveInfo.PlayerMovePoint.Tag);
	bFadeMoveActive = false;
	*/
}

void AFSTS_EventLab::NotifyDrillSergeantUsed()
{
}

void AFSTS_EventLab::NotifyFadeMoveStart(FName PlayerMoveName)
{
}

void AFSTS_EventLab::NotifyFadeMoveMiddle(FName PlayerMoveName)
{
}

void AFSTS_EventLab::NotifyFadeMoveEnd(FName PlayerMoveName)
{
}
