// All the original content belonged to the US Army


#include "AA29/Object/Actor/Info/LocalMessage/CriticalEventPlus/StartupMessage/StartupMessage.h"



AStartupMessage::AStartupMessage()
{
	Stage = { "Waiting for other players.","Waiting for ready signals. You are READY.","The match is about to begin...3","The match is about to begin...2","The match is about to begin...1","The match has begun!","The match has begun!","OVER TIME!" };

	NotReady = "You are NOT READY. Press Fire!";
	SinglePlayer = "Press FIRE to start!";
	bIsConsoleMessage = false;
	DrawColor = FColor(255, 64, 32, 255);
}

void AStartupMessage::ClientReceive(APlayerController* p, int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2, UObject* OptionalObject, FString ExtraText)
{
	/*
	ClientReceive(p, Switch, RelatedPRI_1, RelatedPRI_2, OptionalObject);
	if (Switch < 7)
	{
		p.Level.FillPrecacheMaterialsArray(False);
		p.Level.FillPrecacheStaticMeshesArray(False);
		p.PrecacheAnnouncements();
	}
	*/
}
void AStartupMessage::GetString(int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2, UObject* OptionalObject, FString ExtraText)
{
	/*
	local int i;
	local int PlayerCount;
	local GameReplicationInfo GRI;
	if (RelatedPRI_1 != None && RelatedPRI_1.GetNetMode() == ENetMode::NM_Standalone)
	{
		if (Switch < 2)
		{
			Return Default.SinglePlayer;
		}
	}
	else
	{
		if (Switch == 0 && RelatedPRI_1 != None)
		{
			GRI = RelatedPRI_1.Level.GRI;
			if (GRI == None)
			{
				Return Default.Stage[0];
			}
			for (i = 0; i < GRI.PRIArray.Length; i++)
			{
				if (GRI.PRIArray[i] != None && !GRI.PRIArray[i].bOnlySpectator && !GRI.PRIArray[i].bIsSpectator || GRI.PRIArray[i].bWaitingPlayer)
				{
					PlayerCount++;
				}
			}
			if (GRI.MinNetPlayers - PlayerCount > 0)
			{
				Return Default.Stage[0] @ "(" $ GRI.MinNetPlayers - PlayerCount $ ")";
			}
		}
		else
		{
			if (Switch == 1)
			{
				if (RelatedPRI_1 == None || !RelatedPRI_1.bWaitingPlayer)
				{
					Return Default.Stage[0];
				}
				else
				{
					if (RelatedPRI_1.bReadyToPlay)
					{
						Return Default.Stage[1];
					}
					else
					{
						Return Default.NotReady;
					}
				}
			}
		}
	}
	Return Default.Stage[Switch];
	*/
}