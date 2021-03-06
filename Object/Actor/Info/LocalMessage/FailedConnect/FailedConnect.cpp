// All the original content belonged to the US Army

#include "AA29/Object/Actor/Info/LocalMessage/FailedConnect/FailedConnect.h"

AFailedConnect::AFailedConnect()
{
	FailMessage.SetNum(4);
	FailMessage = { "FAILED TO JOIN GAME.  NEED PASSWORD.","FAILED TO JOIN GAME.  WRONG PASSWORD.","FAILED TO JOIN GAME.  GAME HAS STARTED.","FAILED TO JOIN GAME." };
	bIsUnique = true;
	bFadeMessage = true;
	DrawColor = FColor(128, 0, 255, 255);
	FontSize = 1;
}

int32 AFailedConnect::GetFailswitch(FString FailString)
{
	if (FailString.Compare("NEEDPW", ESearchCase::IgnoreCase))
	{
		return 0;
	}
	if (FailString.Compare("WRONGPW", ESearchCase::IgnoreCase))
	{
		return 1;
	}
	if (FailString.Compare("GAMESTARTED", ESearchCase::IgnoreCase))
	{
		return 2;
	}
	return 3;
}
FString AFailedConnect::GetString(int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2, UObject* OptionalObject, FString ExtraText)
{
	//return Default.FailMessage[Clamp(Switch, 0, 3)];
	return "FAKE";   //FAKE   /ELiZ
}
