// All the original content belonged to the US Army

#include "AA29/Object/Actor/Info/InternetInfo/InternetLink/UdpLink/UdpLinkSCI/UdpLinkSCI.h"

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
	FIpAddr Addr;
	TArray<uint8> packt = {};
	packt.SetNum(255);
	int32 i = 0;
	Addr.Addr = IP;
	Addr.Port = udpport;
	i = 0;
	/*
	packt[i++] = byte(Asc("P"));
	packt[i++] = byte(Asc("I"));
	packt[i++] = byte(Asc("N"));
	packt[i++] = byte(Asc("G"));
	packt[i++] = byte(idx);
	packt[i++] = byte((idx >> 8));
	packt[i++] = byte((idx >> 16));
	packt[i++] = byte((idx >> 24));
	*/
	SendBinary(Addr, i, packt);
}

bool AUdpLinkSCI::SendPong(FIpAddr Addr, int32 idx)
{
	int32 i = 0;
	int32 j = 0;
	int32 Max = 0;
	int32 platform = 0;
	FServerResponseLine S;
	/*
	Level.Game.GetServerInfo(S);
	platform = GetPlatform();
	i = 0;
	packet[i++] = byte(Asc("P"));
	packet[i++] = byte(Asc("O"));
	packet[i++] = byte(Asc("N"));
	packet[i++] = byte(Asc("G"));
	packet[i++] = byte(idx);
	packet[i++] = byte((idx >> 8));
	packet[i++] = byte((idx >> 16));
	packet[i++] = byte((idx >> 24));
	packet[i++] = byte(GetVersionAGPMajor());
	packet[i++] = byte(GetVersionAGPMinor());
	packet[i++] = byte(GetVersionAGPTiny());
	packet[i++] = byte(GetVersionAGPSubTiny());
	packet[i++] = byte(int(Level.IsOfficialServer()));
	packet[i++] = byte(int(Level.IsLeasedServer()));
	packet[i++] = byte(int(Level.IsUltimateArenaServer()));
	packet[i++] = byte(int(Level.Game.IsTournamentMode()));
	packet[i++] = byte(int((!Level.Game.CheatsDisabled())));
	packet[i++] = byte(Level.GetLevelTour());
	packet[i++] = byte(Level.Game.GetMinHonor());
	packet[i++] = byte(Level.Game.GetMaxHonor());
	packet[i++] = byte(int(Level.IsMILES()));
	packet[i++] = byte(Level.PBIsEnabled());
	packet[i++] = byte(int(Level.Game.NeedPassword()));
	packet[i++] = byte(platform);
	packet[i++] = byte((platform >> 8));
	packet[i++] = byte((platform >> 16));
	packet[i++] = byte((platform >> 24));
	packet[i++] = byte(S.Port);
	packet[i++] = byte((S.Port >> 8));
	packet[i++] = byte((S.Port >> 16));
	packet[i++] = byte((S.Port >> 24));
	packet[i++] = byte(S.CurrentPlayers);
	packet[i++] = byte((S.CurrentPlayers >> 8));
	packet[i++] = byte((S.CurrentPlayers >> 16));
	packet[i++] = byte((S.CurrentPlayers >> 24));
	packet[i++] = byte(S.MaxPlayers);
	packet[i++] = byte((S.MaxPlayers >> 8));
	packet[i++] = byte((S.MaxPlayers >> 16));
	packet[i++] = byte((S.MaxPlayers >> 24));
	Max = Len(S.ServerName);
	if (Max > 50)
	{
		Max = 50;
	}
	for (j = 0; j < Max; j++)
	{
		packet[i++] = byte(Asc(Mid(S.ServerName, j, 1)));
	}
	packet[i++] = 0;
	Max = Len(Level.Title);
	if (Max > 50)
	{
		Max = 50;
	}
	for (j = 0; j < Max; j++)
	{
		packet[i++] = byte(Asc(Mid(Level.Title, j, 1)));
	}
	packet[i++] = 0;
	Max = Len(S.GameType);
	if (Max > 50)
	{
		Max = 50;
	}
	for (j = 0; j < Max; j++)
	{
		packet[i++] = byte(Asc(Mid(S.GameType, j, 1)));
	}
	packet[i++] = 0;
	SendBinary(Addr, i, packet);
	*/
	return true;
}

bool AUdpLinkSCI::GetPingPacket(int32& IP, int32& idx, int32& packetSize)
{
	FIpAddr Addr = FIpAddr({});
	int32 i0 = 0;
	int32 i1 = 0;
	int32 i2 = 0;
	int32 i3 = 0;
	/*
	if (true)
	{
		if (!IsDataPending())
		{
			return false;
		}
		packetSize = ReadBinary(Addr, 255, packet);
		if (packetSize <= 0)
		{
			return false;
		}
		if (packetSize < 8)
		{
		}
		IP = Addr.Addr;
		i0 = packet[4];
		i1 = packet[5];
		i2 = packet[6];
		i3 = packet[7];
		idx = (((i0 | (i1 << 8)) | (i2 << 16)) | (i3 << 24));
		if (((packet[0] != Asc("P")) || (packet[2] != Asc("N"))) || (packet[3] != Asc("G")))
		{
		}
		if ((packet[1] == Asc("I")) && bRespondToPings)
		{
			if (packetSize != 8)
			{
			}
			if (!SendPong(Addr, idx))
			{
				return false;
			}
		}
		else
		{
		else
		{
			if (packet[1] == Asc("O"))
			{
				return true;
			}
		}
		}
	}
	*/
	return true;
}
bool AUdpLinkSCI::GetPing(int32& IP, int32& idx)
{
	int32 pktsize;
	return GetPingPacket(IP, idx, pktsize);
}
