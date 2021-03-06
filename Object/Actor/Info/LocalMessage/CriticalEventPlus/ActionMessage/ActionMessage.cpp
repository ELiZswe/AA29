// All the original content belonged to the US Army

#include "AA29/Object/Actor/Info/LocalMessage/CriticalEventPlus/ActionMessage/ActionMessage.h"

AActionMessage::AActionMessage()
{
	Lifetime = 8;
	DrawColor = FColor(0, 255, 255, 255);
	PosY = 0.85;
	FontSize = 0;
	Messages.SetNum(32);
}

FString AActionMessage::GetString(int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2, UObject* OptionalObject, FString ExtraText)
{
	return GetDefault<AActionMessage>()->Messages[Switch];
}
