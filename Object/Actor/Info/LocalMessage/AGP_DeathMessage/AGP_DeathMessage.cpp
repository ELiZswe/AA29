// All the original content belonged to the US Army


#include "AA29/Object/Actor/Info/LocalMessage/AGP_DeathMessage/AGP_DeathMessage.h"

AAGP_DeathMessage::AAGP_DeathMessage()
{
	KilledString = "was killed by";
	SomeoneString = "someone";
	Lifetime = 3;
	DrawColor = FColor(0, 0, 255, 255);
}

FString AAGP_DeathMessage::GetString(int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2, UObject* OptionalObject, FString ExtraText)
{
	/*
	local string KillerName;
	local string VictimName;
	if (class<DamageType>(OptionalObject) == None)
	{
		Return "";
	}
	if (RelatedPRI_2 == None)
	{
		VictimName = Default.SomeoneString;
	}
	else
	{
		VictimName = RelatedPRI_2.PlayerName;
	}
	if (Switch == 1)
	{
		Return Class'GameInfo'.ParseKillMessage(VictimName, VictimName, class<DamageType>(OptionalObject).SuicideMessage(RelatedPRI_2));
	}
	if (Switch == 3)
	{
		Return Class'GameInfo'.ParseKillMessage(VictimName, VictimName, class<DamageType>(OptionalObject).IEDDeathMessage(RelatedPRI_2));
	}
	if (RelatedPRI_1 == None)
	{
		KillerName = Default.SomeoneString;
	}
	else
	{
		KillerName = RelatedPRI_1.PlayerName;
	}
	Return Class'GameInfo'.ParseKillMessage(KillerName, VictimName, class<DamageType>(OptionalObject).DeathMessage(RelatedPRI_1, RelatedPRI_2));
	*/
	return "";    //FAKE  /ELIZ
}
void AAGP_DeathMessage::ClientReceive(APlayerController* p, int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2, UObject* OptionalObject, FString ExtraText)
{
	//ClientReceive(p, Switch, RelatedPRI_1, RelatedPRI_2, OptionalObject);
}
