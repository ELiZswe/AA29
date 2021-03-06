// All the original content belonged to the US Army

#include "AA29/Object/Actor/Info/InternetInfo/InternetLink/UdpLink/UdpLinkSCI/UdpLinkSCI.h"

AUdpLinkSCI::AUdpLinkSCI()
{
	packet.SetNum(255);
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
	packt[i++] = uint8(Asc("P"));
	packt[i++] = uint8(Asc("I"));
	packt[i++] = uint8(Asc("N"));
	packt[i++] = uint8(Asc("G"));
	packt[i++] = uint8(idx);
	packt[i++] = uint8((idx >> 8));
	packt[i++] = uint8((idx >> 16));
	packt[i++] = uint8((idx >> 24));
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
	packet[i++] = uint8(Asc("P"));
	packet[i++] = uint8(Asc("O"));
	packet[i++] = uint8(Asc("N"));
	packet[i++] = uint8(Asc("G"));
	packet[i++] = uint8(idx);
	packet[i++] = uint8((idx >> 8));
	packet[i++] = uint8((idx >> 16));
	packet[i++] = uint8((idx >> 24));
	packet[i++] = uint8(GetVersionAGPMajor());
	packet[i++] = uint8(GetVersionAGPMinor());
	packet[i++] = uint8(GetVersionAGPTiny());
	packet[i++] = uint8(GetVersionAGPSubTiny());
	packet[i++] = uint8(int(Level.IsOfficialServer()));
	packet[i++] = uint8(int(Level.IsLeasedServer()));
	packet[i++] = uint8(int(Level.IsUltimateArenaServer()));
	packet[i++] = uint8(int(Level.Game.IsTournamentMode()));
	packet[i++] = uint8(int((!Level.Game.CheatsDisabled())));
	packet[i++] = uint8(Level.GetLevelTour());
	packet[i++] = uint8(Level.Game.GetMinHonor());
	packet[i++] = uint8(Level.Game.GetMaxHonor());
	packet[i++] = uint8(int(Level.IsMILES()));
	packet[i++] = uint8(Level.PBIsEnabled());
	packet[i++] = uint8(int(Level.Game.NeedPassword()));
	packet[i++] = uint8(platform);
	packet[i++] = uint8((platform >> 8));
	packet[i++] = uint8((platform >> 16));
	packet[i++] = uint8((platform >> 24));
	packet[i++] = uint8(S.Port);
	packet[i++] = uint8((S.Port >> 8));
	packet[i++] = uint8((S.Port >> 16));
	packet[i++] = uint8((S.Port >> 24));
	packet[i++] = uint8(S.CurrentPlayers);
	packet[i++] = uint8((S.CurrentPlayers >> 8));
	packet[i++] = uint8((S.CurrentPlayers >> 16));
	packet[i++] = uint8((S.CurrentPlayers >> 24));
	packet[i++] = uint8(S.MaxPlayers);
	packet[i++] = uint8((S.MaxPlayers >> 8));
	packet[i++] = uint8((S.MaxPlayers >> 16));
	packet[i++] = uint8((S.MaxPlayers >> 24));
	Max = Len(S.ServerName);
	if (Max > 50)
	{
		Max = 50;
	}
	for (j = 0; j < Max; j++)
	{
		packet[i++] = uint8(Asc(Mid(S.ServerName, j, 1)));
	}
	packet[i++] = 0;
	Max = Len(Level.Title);
	if (Max > 50)
	{
		Max = 50;
	}
	for (j = 0; j < Max; j++)
	{
		packet[i++] = uint8(Asc(Mid(Level.Title, j, 1)));
	}
	packet[i++] = 0;
	Max = Len(S.GameType);
	if (Max > 50)
	{
		Max = 50;
	}
	for (j = 0; j < Max; j++)
	{
		packet[i++] = uint8(Asc(Mid(S.GameType, j, 1)));
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
