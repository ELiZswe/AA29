// All the original content belonged to the US Army

#include "AA29/Object/Actor/Info/MessageTextureClient/MessageTextureClient.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/PlayerReplicationInfo/PlayerReplicationInfo.h"

AMessageTextureClient::AMessageTextureClient()
{
	HisMessage = "his";
	HerMessage = "her";
	//bNoDelete = true;
	//RemoteRole = ROLE_SimulatedProxy;
}

void AMessageTextureClient::PostNetBeginPlay()
{
	if (MessageTexture != nullptr)
	{
		//MessageTexture.Client = this;
	}
	//SetTimer(1, true);
}

void AMessageTextureClient::Timer()
{
	FString Text = "";
	/*
	AAA2_PlayerState* Leading;
	AAA2_PlayerState* PRI;
	Text = ScrollingMessage;
	if ((InStr(Text, "%lf") != -1) || (InStr(Text, "%lp") != -1))
	{
		Leading = nullptr;
		ForEach AllActors(APlayerReplicationInfo::StaticClass(), PRI)
		{
			if ((!PRI.bIsSpectator) && ((Leading == nullptr) || (PRI.Score_Total > Leading.Score_Total)))
			{
				Leading = PRI;
			}
		}
		if (Leading != nullptr)
		{
			Text = Replace(Text, "%lp", Leading.PlayerName);
			Text = Replace(Text, "%lf", FString::FromInt(Leading.Score_Total));
		}
		else
		{
			Text = "";
		}
	}
	if (bCaps)
	{
		Text = Caps(Text);
	}
	if (Text != OldText)
	{
		OldText = Text;
		MessageTexture.Revision++;
	}
	*/
}

void AMessageTextureClient::RenderTexture(UMaterialInstance* Tex)
{
	int32 SizeX = 0;
	int32 SizeY = 0;
	/*
	Tex.TextSize(OldText, Font, SizeX, SizeY);
	Tex.DrawText(int((float((Tex.USize - SizeX)) * 0.5)), int((float((Tex.VSize - SizeY)) * 0.5)), OldText, Font, FontColor);
	*/
}

FString AMessageTextureClient::Replace(FString Text, FString Match, FString Replacement)
{
	int32 i = 0;
	/*
	i = InStr(Text, Match);
	if (i != -1)
	{
		return Left(Text, i) + Replacement + Replace(Mid(Text, (i + Len(Match))), Match, Replacement);
	}
	else
	{
		return Text;
	}
	*/
	return "FAKE";    //FAKE   /EliZ
}
