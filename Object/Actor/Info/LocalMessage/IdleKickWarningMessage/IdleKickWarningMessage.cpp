// All the original content belonged to the US Army

#include "AA29/Object/Actor/Info/LocalMessage/IdleKickWarningMessage/IdleKickWarningMessage.h"
#include "AA29/Object/Actor/Info/LocalMessage/GameMessage/GameMessage.h"

AIdleKickWarningMessage::AIdleKickWarningMessage()
{
	bIsPartiallyUnique = true;
	bIsConsoleMessage = false;
	bFadeMessage = true;
	Lifetime = 1;
	DrawColor = FColor(64, 255, 255, 255);
	StackMode = EStackMode::SM_Down;
	PosY = 0.242;
	FontSize = 1;
}

FString AIdleKickWarningMessage::GetString(int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2, UObject* OptionalObject, FString ExtraText)
{
	/*
	AGP_Player(OptionalObject).LastKickWarningTime = AGP_Player(OptionalObject).GetWorld()->GetTimeSeconds();
	return AGameMessage::StaticClass().Default.KickWarning;
	*/
	return "FAKE";      //FAKE  /EliZ
}
