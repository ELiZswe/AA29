// All the original content belonged to the US Army

#include "AA29/Object/Actor/Info/InternetInfo/InternetLink/UdpLink/UdpLink.h"

AUdpLink::AUdpLink()
{
	BroadcastAddr = -1;
	//bAlwaysTick = true;
}

// BindPort: Binds a free port or optional port specified in argument one.
int32 AUdpLink::BindPort(int32 APort, bool bUseNextAvailable)
{
	return 0;   //FAKE ELIZ
}
bool AUdpLink::SendText(FIpAddr Addr, FString str)
{
	return false;   //FAKE ELIZ
}
bool AUdpLink::SendBinary(FIpAddr Addr, int32 Count, TArray<uint8> B)
{
	return false;   //FAKE ELIZ
}
int32 AUdpLink::ReadText(FIpAddr& Addr, FString& str)
{
	return 0;   //FAKE ELIZ
}
int32 AUdpLink::ReadBinary(FIpAddr& Addr, int32 Count, uint8& B)
{
	return 0;   //FAKE ELIZ
}
void AUdpLink::ReceivedText(FIpAddr Addr, FString Text)
{
}
void AUdpLink::ReceivedLine(FIpAddr Addr, FString Line)
{
}
void AUdpLink::ReceivedBinary(FIpAddr Addr, int32 Count, uint8 B)
{
}

