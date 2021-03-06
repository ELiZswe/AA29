// All the original content belonged to the US Army

#include "AA29/Object/Actor/Info/LocalMessage/CriticalEventPlus/StartupMessage/StartupMessage.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/GameReplicationInfo/GameReplicationInfo.h"

AStartupMessage::AStartupMessage()
{
	Stage.SetNum(8);
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
		p.Level.FillPrecacheMaterialsArray(false);
		p.Level.FillPrecacheStaticMeshesArray(false);
		p.PrecacheAnnouncements();
	}
	*/
}

FString AStartupMessage::GetString(int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2, UObject* OptionalObject, FString ExtraText)
{
	/*
	int32 i = 0;
	int32 PlayerCount;
	AGameReplicationInfo* GRI = nullptr;
	if (RelatedPRI_1 != nullptr && RelatedPRI_1.GetNetMode() == ENetMode::NM_Standalone)
	{
		if (Switch < 2)
		{
			return Default.SinglePlayer;
		}
	}
	else
	{
		if (Switch == 0 && RelatedPRI_1 != nullptr)
		{
			GRI = RelatedPRI_1.Level.GRI;
			if (GRI == nullptr)
			{
				return Default.Stage[0];
			}
			for (i = 0; i < GRI.PRIArray.Num(); i++)
			{
				if (GRI.PRIArray[i] != nullptr && !GRI.PRIArray[i].bOnlySpectator && !GRI.PRIArray[i].bIsSpectator || GRI.PRIArray[i].bWaitingPlayer)
				{
					PlayerCount++;
				}
			}
			if (GRI.MinNetPlayers - PlayerCount > 0)
			{
				return Default.Stage[0] @ "(" + GRI.MinNetPlayers - PlayerCount + ")";
			}
		}
		else
		{
			if (Switch == 1)
			{
				if (RelatedPRI_1 == nullptr || !RelatedPRI_1.bWaitingPlayer)
				{
					return Default.Stage[0];
				}
				else
				{
					if (RelatedPRI_1.bReadyToPlay)
					{
						return Default.Stage[1];
					}
					else
					{
						return Default.NotReady;
					}
				}
			}
		}
	}
	*/
	return GetDefault<AStartupMessage>()->Stage[Switch];
}
