// All the original content belonged to the US Army


#include "AA29/Info/LocalMessage/PlayerNameMessage/PlayerNameMessage.h"


APlayerNameMessage::APlayerNameMessage()
{
	bIsUnique = true;
	bIsConsoleMessage = false;
	bFadeMessage = true;
	Lifetime = 1;
	DrawColor = FColor(0, 200, 0, 200);
	PosY = 0.58;
}


void APlayerNameMessage::GetString(int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2, UObject* OptionalObject, FString ExtraText)
{
	//Return RelatedPRI_1.PlayerName;
}