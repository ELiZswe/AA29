// All the original content belonged to the US Army

#include "AA29/Object/Actor/Info/LocalMessage/PlayerNameMessage/PlayerNameMessage.h"
#include "AA29/AA2_PlayerState.h"

APlayerNameMessage::APlayerNameMessage()
{
	bIsUnique = true;
	bIsConsoleMessage = false;
	bFadeMessage = true;
	Lifetime = 1;
	DrawColor = FColor(0, 200, 0, 200);
	PosY = 0.58;
}

FString APlayerNameMessage::GetString(int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2, UObject* OptionalObject, FString ExtraText)
{
	return RelatedPRI_1->PlayerName;
}
