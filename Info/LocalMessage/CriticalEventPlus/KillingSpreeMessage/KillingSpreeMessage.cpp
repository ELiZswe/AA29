// All the original content belonged to the US Army


#include "AA29/Info/LocalMessage/CriticalEventPlus/KillingSpreeMessage/KillingSpreeMessage.h"

AKillingSpreeMessage::AKillingSpreeMessage()
{
	EndSpreeNote = "'s killing spree ended by";
	EndSelfSpree = "was looking good till he killed himself!";
	EndFemaleSpree = "was looking good till she killed herself!";
	SpreeNote = {"is on a killing spree!","is on a rampage!","is dominating!","is unstoppable!","is Godlike!","is Wicked SICK!"};
	SelfSpreeNote = {"Killing Spree!","Rampage!","Dominating!","Unstoppable!","GODLIKE!","WICKED SICK!"};
	SpreeSoundName = {"Killing_Spree","Rampage","Dominating","Unstoppable","GodLike","WhickedSick"};
	FontSize = 0;
}


void AKillingSpreeMessage::GetFontSize(int32 Switch, AAA2_PlayerState* RelatedPRI1, AAA2_PlayerState* RelatedPRI2, AAA2_PlayerState* LocalPlayer)
{
	/*
	local Pawn ViewPawn;
	if (RelatedPRI2 == None)
	{
		if (LocalPlayer == RelatedPRI1)
		{
			Return 2;
		}
		if (LocalPlayer.bOnlySpectator)
		{
			ViewPawn = Pawn(LocalPlayer.Level.GetLocalPlayerController().ViewTarget);
			if (ViewPawn != None && ViewPawn.PlayerReplicationInfo == RelatedPRI1)
			{
				Return 2;
			}
		}
	}
	Return Default.FontSize;
	*/
}
void AKillingSpreeMessage::GetRelatedString(int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2, UObject* OptionalObject)
{
	/*
	if (RelatedPRI_2 == None)
	{
		Return Default.SelfSpreeNote[Switch];
	}
	Return GetString(Switch, RelatedPRI_1, RelatedPRI_2, OptionalObject);
	*/
}
void AKillingSpreeMessage::GetString(int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2, UObject* OptionalObject, FString ExtraText)
{
	/*
	if (RelatedPRI_2 == None)
	{
		if (RelatedPRI_1 == None)
		{
			Return "";
		}
		if (RelatedPRI_1.PlayerName != "")
		{
			Return RelatedPRI_1.PlayerName @ Default.SpreeNote[Switch];
		}
	}
	else
	{
		if (RelatedPRI_1 == None)
		{
			if (RelatedPRI_2.PlayerName != "")
			{
				if (RelatedPRI_2.bIsFemale)
				{
					Return RelatedPRI_2.PlayerName @ Default.EndFemaleSpree;
				}
				else
				{
					Return RelatedPRI_2.PlayerName @ Default.EndSelfSpree;
				}
			}
		}
		else
		{
			Return RelatedPRI_1.PlayerName $ Default.EndSpreeNote @ RelatedPRI_2.PlayerName @ Default.EndSpreeNoteTrailer;
		}
	}
	Return "";
	*/
}
void AKillingSpreeMessage::ClientReceive(APlayerController* p, int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2, UObject* OptionalObject, FString ExtraText)
{
	/*
	ClientReceive(p, Switch, RelatedPRI_1, RelatedPRI_2, OptionalObject);
	if (RelatedPRI_2 != None)
	{
		Return;
	}
	if (RelatedPRI_1 == p.PlayerReplicationInfo || p.PlayerReplicationInfo.bOnlySpectator && Pawn(p.ViewTarget) != None && Pawn(p.ViewTarget).PlayerReplicationInfo == RelatedPRI_1)
	{
		p.PlayRewardAnnouncement(Default.SpreeSoundName[Switch], 1, true);
	}
	else
	{
		p.PlayBeepSound();
	}
	*/
}