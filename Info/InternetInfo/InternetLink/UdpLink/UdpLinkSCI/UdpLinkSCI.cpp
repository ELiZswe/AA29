// All the original content belonged to the US Army


#include "AA29/Info/InternetInfo/InternetLink/UdpLink/UdpLinkSCI/UdpLinkSCI.h"

AUdpLinkSCI::AUdpLinkSCI()
{
	udpport = 14200;
	//bAlwaysTick = false;
}

void AUdpLinkSCI::PostBeginPlay()
{
	LinkMode = ELinkMode::MODE_Binary;
	ReceiveMode = EReceiveMode::RMODE_Manual;
	BindPort(udpport, false);
}
void AUdpLinkSCI::SendPing(int32 IP, int32 idx)
{
	/*
	local InternetLink.IpAddr Addr;
	local byte packt;
	local int i;
	Addr.Addr = IP;
	Addr.Port = udpport;
	i = 0;
	packt[i++] = Asc("P");
	packt[i++] = Asc("I");
	packt[i++] = Asc("N");
	packt[i++] = Asc("G");
	packt[i++] = idx;
	packt[i++] = idx >> 8;
	packt[i++] = idx >> 16;
	packt[i++] = idx >> 24;
	SendBinary(Addr, i, packt);
	*/
}
bool AUdpLinkSCI::SendPong(FIpAddr Addr, int32 idx)
{
	/*
	local int i;
	local int j;
	local int Max;
	local int platform;
	local GameInfo.ServerResponseLine S;
	Level.Game.GetServerInfo(S);
	platform = GetPlatform();
	i = 0;
	packet[i++] = Asc("P");
	packet[i++] = Asc("O");
	packet[i++] = Asc("N");
	packet[i++] = Asc("G");
	packet[i++] = idx;
	packet[i++] = idx >> 8;
	packet[i++] = idx >> 16;
	packet[i++] = idx >> 24;
	packet[i++] = GetVersionAGPMajor();
	packet[i++] = GetVersionAGPMinor();
	packet[i++] = GetVersionAGPTiny();
	packet[i++] = GetVersionAGPSubTiny();
	packet[i++] = Cast<AAA2_WorldSettings>(GetWorldSettings())->IsLeasedServer();
	packet[i++] = Cast<AAA2_WorldSettings>(GetWorldSettings())->IsLeasedServer();
	packet[i++] = Level.IsUltimateArenaServer();
	packet[i++] = Level.Game.IsTournamentMode();
	packet[i++] = !Level.Game.CheatsDisabled();
	packet[i++] = Level.GetLevelTour();
	packet[i++] = Level.Game.GetMinHonor();
	packet[i++] = Level.Game.GetMaxHonor();
	packet[i++] = Cast<AAA2_WorldSettings>(GetWorldSettings())->IsMILES();
	packet[i++] = Level.PBIsEnabled();
	packet[i++] = Level.Game.NeedPassword();
	packet[i++] = platform;
	packet[i++] = platform >> 8;
	packet[i++] = platform >> 16;
	packet[i++] = platform >> 24;
	packet[i++] = S.Port;
	packet[i++] = S.Port >> 8;
	packet[i++] = S.Port >> 16;
	packet[i++] = S.Port >> 24;
	packet[i++] = S.CurrentPlayers;
	packet[i++] = S.CurrentPlayers >> 8;
	packet[i++] = S.CurrentPlayers >> 16;
	packet[i++] = S.CurrentPlayers >> 24;
	packet[i++] = S.MaxPlayers;
	packet[i++] = S.MaxPlayers >> 8;
	packet[i++] = S.MaxPlayers >> 16;
	packet[i++] = S.MaxPlayers >> 24;
	Max = Len(S.ServerName);
	if (Max > 50)
	{
		Max = 50;
	}
	for (j = 0; j < Max; j++)
	{
		packet[i++] = Asc(Mid(S.ServerName, j, 1));
	}
	packet[i++] = 0;
	Max = Len(Level.Title);
	if (Max > 50)
	{
		Max = 50;
	}
	for (j = 0; j < Max; j++)
	{
		packet[i++] = Asc(Mid(Level.Title, j, 1));
	}
	packet[i++] = 0;
	Max = Len(S.GameType);
	if (Max > 50)
	{
		Max = 50;
	}
	for (j = 0; j < Max; j++)
	{
		packet[i++] = Asc(Mid(S.GameType, j, 1));
	}
	packet[i++] = 0;
	SendBinary(Addr, i, packet);
	*/
	return true;
}
bool AUdpLinkSCI::GetPingPacket(int32 &IP, int32 &idx, int32 &packetSize)
{
	/*
	local InternetLink.IpAddr Addr;
	local int i0;
	local int i1;
	local int i2;
	local int i3;
	if (True)
	{
		if (!IsDataPending())
		{
			Return False;
		}
		packetSize = ReadBinary(Addr, 255, packet);
		if (packetSize <= 0)
		{
			Return False;
		}
		if (packetSize < 8)
		{
		}
		IP = Addr.Addr;
		i0 = packet[4];
		i1 = packet[5];
		i2 = packet[6];
		i3 = packet[7];
		idx = i0 | i1 << 8 | i2 << 16 | i3 << 24;
		if (packet[0] != Asc("P") || packet[2] != Asc("N") || packet[3] != Asc("G"))
		{
		}
		if (packet[1] == Asc("I") && bRespondToPings)
		{
			if (packetSize != 8)
			{
			}
			if (!SendPong(Addr, idx))
			{
				Return False;
			}
		}
		else
		{
		else
		{
			if (packet[1] == Asc("O"))
			{
				Return True;
			}
		}
		}
	}
	*/
	return true;
}
bool AUdpLinkSCI::GetPing(int32 &IP, int32 &idx)
{
	int32 pktsize;
	return GetPingPacket(IP, idx, pktsize);
}