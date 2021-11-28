// All the original content belonged to the US Army


#include "AA29/Object/Actor/Info/LocalMessage/CriticalEventPlus/TimerMessage/TimerMessage.h"

ATimerMessage::ATimerMessage()
{
	CountDown = { "one","two","three","four","five","six","seven","eight","nine","ten" };
	CountDownTrailer = "...";
	bIsConsoleMessage = false;
	Lifetime = 1;
	DrawColor = FColor(0, 255, 255, 255);
	StackMode = EStackMode::SM_Down;
	PosY = 0.1;
	FontSize = 0;
}

void ATimerMessage::GetString(int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2, UObject* OptionalObject, FString ExtraText)
{
	/*
	Return Switch $ Default.CountDownTrailer;
	*/
}
void ATimerMessage::ClientReceive(APlayerController* p, int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2, UObject* OptionalObject, FString ExtraText)
{
	/*
	ClientReceive(p, Switch, RelatedPRI_1, RelatedPRI_2, OptionalObject);
	if (Switch > 0 && Switch < 11 && p.GameReplicationInfo != None && p.GameReplicationInfo.Winner == None && p.GameReplicationInfo.RemainingTime > 10 || p.GameReplicationInfo.RemainingTime == 0)
	{
		p.QueueAnnouncement(Default.CountDown[Switch - 1], 1, 3, 1);
	}
	*/
}
