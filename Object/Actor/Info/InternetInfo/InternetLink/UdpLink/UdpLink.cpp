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
void AUdpLink::SendText(FIpAddr Addr, FString str)
{
}
void AUdpLink::SendBinary(FIpAddr Addr, int32 Count, uint8 B)
{
}
void AUdpLink::ReadText(FIpAddr& Addr, FString& str)
{
}
void AUdpLink::ReadBinary(FIpAddr& Addr, int32 Count, uint8& B)
{
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