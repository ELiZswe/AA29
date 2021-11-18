// All the original content belonged to the US Army


#include "AA29/Info/InternetInfo/InternetLink/UdpLink/UdpBeacon/UdpBeacon.h"

AUdpBeacon::AUdpBeacon()
{
	DoBeacon = true;
	ServerBeaconPort = 8777;
	BeaconPort = 8777;
	BeaconTimeout = 5;
	BeaconProduct = "armyops";
}

void AUdpBeacon::BeginPlay()
{
	
	FIpAddr Addr;
	boundport = BindPort(ServerBeaconPort, true);
	if (boundport == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("UdpBeacon failed to bind a port."));
		return;
	}
	Addr.Addr = BroadcastAddr;
	Addr.Port = BeaconPort;
	BroadcastBeacon(Addr);
	
}
void AUdpBeacon::BroadcastBeacon(FIpAddr Addr)
{
	//SendText(Addr, BeaconProduct @ Mid(Level.GetAddressURL(), InStr(Level.GetAddressURL(), ":") + 1) @ Level.Game.GetBeaconText());
}
void AUdpBeacon::BroadcastBeaconQuery(FIpAddr Addr)
{
	//SendText(Addr, BeaconProduct @ UdpServerQueryPort);
}
void AUdpBeacon::ReceivedText(FIpAddr Addr, FString Text)
{
	/*
	if (Text == "REPORT")
	{
		BroadcastBeacon(Addr);
	}
	if (Text == "REPORTQUERY")
	{
		BroadcastBeaconQuery(Addr);
	}
	*/
}
void AUdpBeacon::Destroyed()
{
	Super::Destroyed();
}
