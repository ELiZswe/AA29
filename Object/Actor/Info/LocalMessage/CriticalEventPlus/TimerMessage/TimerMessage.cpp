// All the original content belonged to the US Army

#include "AA29/Object/Actor/Info/LocalMessage/CriticalEventPlus/TimerMessage/TimerMessage.h"

ATimerMessage::ATimerMessage()
{
	CountDown.SetNum(10);
	CountDownSounds.SetNum(10);
	CountDown = { "one","two","three","four","five","six","seven","eight","nine","ten" };
	CountDownTrailer = "...";
	bIsConsoleMessage = false;
	Lifetime = 1;
	DrawColor = FColor(0, 255, 255, 255);
	StackMode = EStackMode::SM_Down;
	PosY = 0.1;
	FontSize = 0;
}

FString ATimerMessage::GetString(int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2, UObject* OptionalObject, FString ExtraText)
{
	//return Switch + Default.CountDownTrailer;
	return "FAKE";    //FAKE   /ELiZ
}

void ATimerMessage::ClientReceive(APlayerController* p, int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2, UObject* OptionalObject, FString ExtraText)
{
	/*
	ClientReceive(p, Switch, RelatedPRI_1, RelatedPRI_2, OptionalObject);
	if (Switch > 0 && Switch < 11 && p.GameReplicationInfo != nullptr && p.GameReplicationInfo.Winner == nullptr && p.GameReplicationInfo.RemainingTime > 10 || p.GameReplicationInfo.RemainingTime == 0)
	{
		p.QueueAnnouncement(Default.CountDown[Switch - 1], 1, 3, 1);
	}
	*/
}
