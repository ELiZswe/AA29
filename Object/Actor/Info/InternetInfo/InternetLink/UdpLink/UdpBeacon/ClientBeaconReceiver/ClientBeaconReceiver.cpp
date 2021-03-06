// All the original content belonged to the US Army

#include "AA29/Object/Actor/Info/InternetInfo/InternetLink/UdpLink/UdpBeacon/ClientBeaconReceiver/ClientBeaconReceiver.h"

AClientBeaconReceiver::AClientBeaconReceiver()
{
	Beacons.SetNum(32);

}

int32 AClientBeaconReceiver::GetBeaconCount()
{
	return 32;
}
FString AClientBeaconReceiver::GetBeaconAddress(int32 i)
{
	//return IpAddrToString(Beacons[i].Addr);
	return "127.0.0.1";     //FAKE /ELIZ
}
FString AClientBeaconReceiver::GetBeaconText(int32 i)
{
	return Beacons[i].Text;
}
void AClientBeaconReceiver::BeginPlay()
{
	if (BindPort(BeaconPort, true) > 0)
	{
		//SetTimer(1, true);
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("ClientBeaconReceiver failed: Beacon port in use. 'Error'"));
	}
}
void AClientBeaconReceiver::Timer()
{
	/*
	int32 i = 0;
	int32 j = 0;
	j = 0;
	for (i = 0; i < 32; i++)
	{
		if (Beacons[i].Addr.Addr == 0)
		{
		}
		if (GetWorld()->GetTimeSeconds() - Beacons[i].Time >= BeaconTimeout)
		{
		}
		if (i != j)
		{
			Beacons[j] = Beacons[i];
		}
		j++;
		if (j < 32)
		{
			Beacons[j].Addr.Addr = 0;
			Beacons[j].Text = "";
			j++;
		}
	}
	*/
	BroadcastQuery();
}
void AClientBeaconReceiver::BroadcastQuery()
{
	FIpAddr Addr;
	Addr.Addr = BroadcastAddr;
	Addr.Port = ServerBeaconPort;
	//SendText(Addr, "REPORT");
}
void AClientBeaconReceiver::ReceivedText(FIpAddr Addr, FString Text)
{
	/*
	int32 i = 0;
	int32 N;
	FString Product;
	N = Len(BeaconProduct);
	Product = Left(Text, N + 1);
	if (!Product ~= BeaconProduct + " ")
	{
		return;
	}
	Text = Mid(Text, N + 1);
	Addr.Port = Text;
	for (i = 0; i < 32; i++)
	{
		if (Beacons[i].Addr == Addr)
		{
		}
	}
	if (i == 32)
	{
		for (i = 0; i < 32; i++)
		{
			if (Beacons[i].Addr.Addr == 0)
			{
			}
		}
	}
	if (i == 32)
	{
		return;
	}
	Beacons[i].Addr = Addr;
	Beacons[i].Time = GetWorld()->GetTimeSeconds();
	Beacons[i].Text = Mid(Text, InStr(Text, " ") + 1);
	*/
}

void AClientBeaconReceiver::UpdateUI()
{
}

void AClientBeaconReceiver::BroadcastBeacon(FIpAddr Addr)
{
	//SendText(Addr, "REPORT");
}

void AClientBeaconReceiver::StartBeacon()
{
	FIpAddr Addr;
	_bSleep = false;
	//SetTimer(5, true);
	Addr.Addr = BroadcastAddr;
	Addr.Port = ServerBeaconPort;
	BroadcastBeacon(Addr);
}

void AClientBeaconReceiver::StopBeacon()
{
	_bSleep = true;
	/*
	SetTimer(0, false);
	__UpdateUI__Delegate = nullptr;
	*/
}
int32 AClientBeaconReceiver::GetBeaconAddressAddr(int32 i)
{
	if (i < 32)
	{
		return Beacons[i].Addr.Addr;
	}
	else
	{
		return 0;
	}
}
