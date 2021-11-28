// All the original content belonged to the US Army


#include "AA29/Object/Actor/Info/LocalMessage/CriticalEventPlus/LastSecondMessage/LastSecondMessage.h"

ALastSecondMessage::ALastSecondMessage()
{
	LastSecondRed = "Last second save by Red!";
	LastSecondBlue = "Last second save by Blue!";
	StackMode = EStackMode::SM_Down;
	PosY = 0.1;
}



void ALastSecondMessage::ClientReceive(APlayerController* p, int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2, UObject* OptionalObject, FString ExtraText)
{
	/*
	ClientReceive(p, Switch, RelatedPRI_1, RelatedPRI_2, OptionalObject);
	if (Switch == 1)
	{
		p.PlayRewardAnnouncement('Denied', 1, true);
	}
	else
	{
		p.PlayStatusAnnouncement('Last_Second_Save', 1, true);
	}
	*/
}
void ALastSecondMessage::GetString(int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2, UObject* OptionalObject, FString ExtraText)
{
	/*
	if (TeamInfo(OptionalObject) == None)
	{
		Return "";
	}
	if (TeamInfo(OptionalObject).TeamIndex == 0)
	{
		Return Default.LastSecondRed;
	}
	else
	{
		Return Default.LastSecondBlue;
	}
	*/
}
