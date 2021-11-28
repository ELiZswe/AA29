// All the original content belonged to the US Army


#include "AA29/Object/Actor/Info/LocalMessage/FailedConnect/FailedConnect.h"

AFailedConnect::AFailedConnect()
{
	FailMessage = { "FAILED TO JOIN GAME.  NEED PASSWORD.","FAILED TO JOIN GAME.  WRONG PASSWORD.","FAILED TO JOIN GAME.  GAME HAS STARTED.","FAILED TO JOIN GAME." };
	bIsUnique = true;
	bFadeMessage = true;
	DrawColor = FColor(128, 0, 255, 255);
	FontSize = 1;
}


void AFailedConnect::GetFailSwitch(FString FailString)
{
	/*
	if (FailString ~= "NEEDPW")
	{
		Return 0;
	}
	if (FailString ~= "WRONGPW")
	{
		Return 1;
	}
	if (FailString ~= "GAMESTARTED")
	{
		Return 2;
	}
	Return 3;
	*/
}
void AFailedConnect::GetString(int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2, UObject* OptionalObject, FString ExtraText)
{
	/*
	Return Default.FailMessage[Clamp(Switch, 0, 3)];
	*/
}