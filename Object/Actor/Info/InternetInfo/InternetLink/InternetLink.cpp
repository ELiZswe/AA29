// All the original content belonged to the US Army

#include "AA29/Object/Actor/Info/InternetInfo/InternetLink/InternetLink.h"

AInternetLink::AInternetLink()
{

}

bool AInternetLink::IsDataPending()
{
	return false;   //FAKE   /EliZ
}
bool AInternetLink::ParseURL(FString URL, FString &Addr, int32 &APort , FString LevelName, FString &EntryName)
{
	return false;   //FAKE   /EliZ
}
void AInternetLink::Resolve(FString Domain)
{
}

int32 AInternetLink::GetLastError()
{
	return 0;   //FAKE   /EliZ
}

FString AInternetLink::IpAddrToString(FIpAddr Arg)
{
	return "FAKE";   //FAKE   /EliZ
}

void AInternetLink::StringToIpAddr(FString str, FIpAddr &Addr, bool hostOrder)
{
}

FString AInternetLink::GameSpyValidate(FString ValidationString)
{
	return "FAKE";   //FAKE   /EliZ
}

FString AInternetLink::GameSpyGameName()
{
	return "FAKE";   //FAKE   /EliZ
}

FString AInternetLink::GetLocalHostName()
{
	return "FAKE";   //FAKE   /EliZ
}
void AInternetLink::GetLocalIP(FIpAddr &Arg)
{
}

FString AInternetLink::GetLocalIPAsString()
{
	//FIpAddr IP;
	//int32 Temp;
	FString IpAsString;
	IpAsString = "";
	/*
	'InternetLink'.GetLocalIP(IP);
	Temp = IP.Addr >> 24 & 255;
	IpAsString = Temp + ".";
	Temp = IP.Addr >> 16 & 255;
	IpAsString = IpAsString + Temp + ".";
	Temp = IP.Addr >> 8 & 255;
	IpAsString = IpAsString + Temp + ".";
	Temp = IP.Addr >> 0 & 255;
	IpAsString = IpAsString + Temp;
	*/
	return IpAsString;
}
void AInternetLink::Resolved(FIpAddr Addr)
{
}
void AInternetLink::ResolveFailed()
{
}
void AInternetLink::PostResolved()
{
}
