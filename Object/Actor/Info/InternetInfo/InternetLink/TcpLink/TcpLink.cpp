// All the original content belonged to the US Army


#include "AA29/Object/Actor/Info/InternetInfo/InternetLink/TcpLink/TcpLink.h"

ATcpLink::ATcpLink()
{
	//bAlwaysTick = true;
}

//native Function BindPort(optional int Port, optional bool bUseNextAvailable);
void ATcpLink::BindPort(int32 aPort, bool bUseNextAvailable)
{
}

//native Function Listen();
void ATcpLink::Listen()
{
}

//native Function Open(InternetLink.IpAddr Addr);
void ATcpLink::Open(FIpAddr Addr)
{
}

//native Function Close();
void ATcpLink::Close()
{
}

//native Function HardClose(optional bool bPerformClosedEventCallback);
void ATcpLink::HardClose(bool bPerformClosedEventCallback)
{
}

//native Function IsConnected();
void ATcpLink::IsConnected()
{
}

//native Function SendText(coerce string str);
void ATcpLink::SendText(FString str)
{
}

//native Function SendBinary(int Count, byte B);
void ATcpLink::SendBinary(int32 Count, uint8 B)
{
}

//native Function SendLongBinary(int Count, int B);
void ATcpLink::SendLongBinary(int32 Count, int32 B)
{
}

//native Function ReadText(out string str);
void ATcpLink::ReadText(FString str)
{
}

//native Function ReadBinary(int Count, out byte B);
void ATcpLink::ReadBinary(int32 Count, uint8 B)
{
}

//native Function ReadLongBinary(int Count, out int B);
void ATcpLink::ReadLongBinary(int32 Count, int32 &B)
{
}

void ATcpLink::Accepted()
{
}
void ATcpLink::Opened()
{
}
void ATcpLink::Closed()
{
}
void ATcpLink::ReceivedText(FString Text)
{
}
void ATcpLink::ReceivedLine(FString Line)
{
}
void ATcpLink::ReceivedBinary(int32 Count, uint8 B)
{
}
void ATcpLink::ReceivedLongBinary(int32 Count, int32 B)
{
}
