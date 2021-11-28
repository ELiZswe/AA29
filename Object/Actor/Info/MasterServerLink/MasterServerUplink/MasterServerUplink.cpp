// All the original content belonged to the US Army


#include "AA29/Object/Actor/Info/MasterServerLink/MasterServerUplink/MasterServerUplink.h"
#include "AA29/Object/Actor/Info/GameInfo/GameInfo.h"
#include "AA29/AA2_WorldSettings.h"

AMasterServerUplink::AMasterServerUplink()
{
	CachePlayerCount = -1;
	DoUplink = true;
	UplinkToGamespy = true;
	SendStats = true;
	MSUPropText = { "Advertise Server", "Process Stats" };
	MSUPropDesc = { "if true, your server is advertised on the internet server browser.", "Publishes player stats from your server on the UT2004 stats website." };
}
void AMasterServerUplink::Reconnect()
{
}
void AMasterServerUplink::BeginPlay()
{
	/*
	local class<UdpLink>  LinkClass;
	if (DoUplink)
	{
		if (UplinkToGamespy)
		{
			LinkClass = class<UdpLink>(DynamicLoadObject("IpDrv.UdpGamespyQuery", Class'Class'));
			if (LinkClass != nullptr)
			{
				GamespyQueryLink = Spawn(LinkClass);
			}
			LinkClass = class<UdpLink>(DynamicLoadObject("IpDrv.UdpGamespyUplink", Class'Class'));
			if (LinkClass != nullptr)
			{
				Spawn(LinkClass);
			}
		}
		if (SendStats)
		{
			ForEach AllActors('MasterServerGameStats', GameStats)
			{
				if (GameStats.Uplink == nullptr)
				{
					GameStats.Uplink = this;
				}
				else
				{
					GameStats = nullptr;
				}
			}
			if (GameStats == nullptr)
			{
				UE_LOG(LogTemp, Warning, TEXT("MasterServerUplink: MasterServerGameStats not found - stats uploading disabled."));
			}
		}
	}
	*/
	Reconnect();
}
void AMasterServerUplink::ConnectionFailed(bool bShouldReconnect)
{
	UE_LOG(LogTemp, Warning, TEXT("Master server connection failed"));
	bReconnectPending = bShouldReconnect;
	if (bShouldReconnect)
	{
		if (ActiveMasterServerList.Max() > 0 && LastMSIndex < ActiveMasterServerList.Max())
		{
			//ActiveMasterServerList.remove(LastMSIndex, 1);
		}
		if (ActiveMasterServerList.Max() == 0)
		{
			ReconnectTime = 10;
		}
		else
		{
			ReconnectTime = 2;
		}
	}
	else
	{
		ReconnectTime = 0;
	}
}
void AMasterServerUplink::Refresh()
{
	if (!bInitialStateCached || GetWorld()->GetTimeSeconds() > CacheRefreshTime)
	{
		Cast<AAA2_WorldSettings>(GetWorldSettings())->Game->GetServerInfo(FullCachedServerState);
		Cast<AAA2_WorldSettings>(GetWorldSettings())->Game->GetServerDetails(FullCachedServerState);
		CachedServerState = FullCachedServerState;
		Cast<AAA2_WorldSettings>(GetWorldSettings())->Game->GetServerPlayers(FullCachedServerState);
		ServerState = FullCachedServerState;
		CacheRefreshTime = GetWorld()->GetTimeSeconds() + 60;
		bInitialStateCached =false;
	}
	else
	{
		if (Cast<AAA2_WorldSettings>(GetWorldSettings())->Game->NumPlayers != CachePlayerCount)
		{
			ServerState = CachedServerState;
			Cast<AAA2_WorldSettings>(GetWorldSettings())->Game->GetServerPlayers(ServerState);
			FullCachedServerState = ServerState;
		}
		else
		{
			ServerState = FullCachedServerState;
		}
	}
	CachePlayerCount = Cast<AAA2_WorldSettings>(GetWorldSettings())->Game->NumPlayers;
}
bool AMasterServerUplink::LogStatLine(FString StatLine)
{
	return false;		//FAKE ELiZ
}
void AMasterServerUplink::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (bReconnectPending)
	{
		ReconnectTime -= DeltaTime;
		if (ReconnectTime <= 0)
		{
			UE_LOG(LogTemp, Warning, TEXT("Attempting to reconnect to master server!"));
			bReconnectPending = false;
			Reconnect();
		}
	}
}
void AMasterServerUplink::FillPlayInfo(UPlayInfo* PlayInfo)
{
	/*
	Super::FillPlayInfo(PlayInfo);
	PlayInfo.AddSetting(Default.ServerGroup, "DoUplink", Default.MSUPropText[0], 255, 1, "Check", , , true);
	*/
}

FString AMasterServerUplink::GetDescriptionText(FString PropName)
{
	if (PropName == "DoUplink")		{ return GetDefault<AMasterServerUplink>()->MSUPropDesc[0]; }
	if (PropName == "SendStats")	{ return GetDefault<AMasterServerUplink>()->MSUPropDesc[1]; }
	return Super::GetDescriptionText(PropName);
}