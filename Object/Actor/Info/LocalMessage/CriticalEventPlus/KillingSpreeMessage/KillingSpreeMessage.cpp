// All the original content belonged to the US Army

#include "AA29/Object/Actor/Info/LocalMessage/CriticalEventPlus/KillingSpreeMessage/KillingSpreeMessage.h"

AKillingSpreeMessage::AKillingSpreeMessage()
{
	SpreeSoundName.SetNum(10);
	SpreeSound.SetNum(10);
	SelfSpreeNote.SetNum(10);
	SpreeNote.SetNum(10);
	EndSpreeNote = "'s killing spree ended by";
	EndSelfSpree = "was looking good till he killed himself!";
	EndFemaleSpree = "was looking good till she killed herself!";
	SpreeNote = {"is on a killing spree!","is on a rampage!","is dominating!","is unstoppable!","is Godlike!","is Wicked SICK!"};
	SelfSpreeNote = {"Killing Spree!","Rampage!","Dominating!","Unstoppable!","GODLIKE!","WICKED SICK!"};
	SpreeSoundName = {"Killing_Spree","Rampage","Dominating","Unstoppable","GodLike","WhickedSick"};
	FontSize = 0;
}

int32 AKillingSpreeMessage::GetFontSize(int32 Switch, AAA2_PlayerState* RelatedPRI1, AAA2_PlayerState* RelatedPRI2, AAA2_PlayerState* LocalPlayer)
{
	APawn* ViewPawn = nullptr;
	if (RelatedPRI2 == nullptr)
	{
		if (LocalPlayer == RelatedPRI1)
		{
			return 2;
		}
		/*
		if (LocalPlayer->bOnlySpectator)
		{
			ViewPawn = Cast<APawn>(LocalPlayer->Level->GetLocalPlayerController()->ViewTarget);
			if (ViewPawn != nullptr && ViewPawn->PlayerReplicationInfo == RelatedPRI1)
			{
				return 2;
			}
		}
		*/
	}
	return GetDefault<AKillingSpreeMessage>()->FontSize;
}

FString AKillingSpreeMessage::GetRelatedString(int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2, UObject* OptionalObject)
{
	/*
	if (RelatedPRI_2 == nullptr)
	{
		return Default.SelfSpreeNote[Switch];
	}
	return GetString(Switch, RelatedPRI_1, RelatedPRI_2, OptionalObject);
	*/
	return "FAKE";     //FAKE   /ELiZ
}

FString AKillingSpreeMessage::GetString(int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2, UObject* OptionalObject, FString ExtraText)
{
	/*
	if (RelatedPRI_2 == nullptr)
	{
		if (RelatedPRI_1 == nullptr)
		{
			return "";
		}
		if (RelatedPRI_1.PlayerName != "")
		{
			return RelatedPRI_1.PlayerName @ Default.SpreeNote[Switch];
		}
	}
	else
	{
		if (RelatedPRI_1 == nullptr)
		{
			if (RelatedPRI_2.PlayerName != "")
			{
				if (RelatedPRI_2.bIsFemale)
				{
					return RelatedPRI_2.PlayerName @ Default.EndFemaleSpree;
				}
				else
				{
					return RelatedPRI_2.PlayerName @ Default.EndSelfSpree;
				}
			}
		}
		else
		{
			return RelatedPRI_1.PlayerName + Default.EndSpreeNote @ RelatedPRI_2.PlayerName @ Default.EndSpreeNoteTrailer;
		}
	}
	*/
	return "";
}

void AKillingSpreeMessage::ClientReceive(APlayerController* p, int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2, UObject* OptionalObject, FString ExtraText)
{
	/*
	ClientReceive(p, Switch, RelatedPRI_1, RelatedPRI_2, OptionalObject);
	if (RelatedPRI_2 != nullptr)
	{
		return;
	}
	if (RelatedPRI_1 == p.PlayerReplicationInfo || p.PlayerReplicationInfo.bOnlySpectator && Pawn(p.ViewTarget) != nullptr && Pawn(p.ViewTarget).PlayerReplicationInfo == RelatedPRI_1)
	{
		p.PlayRewardAnnouncement(Default.SpreeSoundName[Switch], 1, true);
	}
	else
	{
		p.PlayBeepSound();
	}
	*/
}
