// All the original content belonged to the US Army

#include "AA29/Object/Actor/Info/InternetInfo/InternetLink/TcpLink/TcpLink.h"

ATcpLink::ATcpLink()
{
	//bAlwaysTick = true;
}

//native Function BindPort(optional int Port, optional bool bUseNextAvailable);
int32 ATcpLink::BindPort(int32 aPort, bool bUseNextAvailable)
{
	return 0;     //FAKE   /ELiZ
}

//native Function Listen();
bool ATcpLink::Listen()
{
	return false;     //FAKE   /ELiZ
}

//native Function Open(InternetLink.IpAddr Addr);
bool ATcpLink::Open(FIpAddr Addr)
{
	return false;     //FAKE   /ELiZ
}

//native Function Close();
bool ATcpLink::Close()
{
	return false;     //FAKE   /ELiZ
}

//native Function HardClose(optional bool bPerformClosedEventCallback);
bool ATcpLink::HardClose(bool bPerformClosedEventCallback)
{
	return false;     //FAKE   /ELiZ
}

//native Function IsConnected();
bool ATcpLink::IsConnected()
{
	return false;     //FAKE   /ELiZ
}

//native Function SendText(coerce string str);
int32 ATcpLink::SendText(FString str)
{
	return 0;     //FAKE   /ELiZ
}

//native Function SendBinary(int32 Count, byte B);
int32 ATcpLink::SendBinary(int32 Count, uint8 B)
{
	return 0;     //FAKE   /ELiZ
}

//native Function SendLongBinary(int32 Count, int B);
int32 ATcpLink::SendLongBinary(int32 Count, int32 B)
{
	return 0;     //FAKE   /ELiZ
}

//native Function ReadText(out string str);
int32 ATcpLink::ReadText(FString& str)
{
	return 0;     //FAKE   /ELiZ
}

//native Function ReadBinary(int32 Count, out byte B);
int32 ATcpLink::ReadBinary(int32 Count, uint8& B)
{
	return 0;     //FAKE   /ELiZ
}

//native Function ReadLongBinary(int32 Count, out int B);
int32 ATcpLink::ReadLongBinary(int32 Count, int32 &B)
{
	return 0;     //FAKE   /ELiZ
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
