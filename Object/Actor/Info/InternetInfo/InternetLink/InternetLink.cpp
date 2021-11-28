// All the original content belonged to the US Army


#include "AA29/Object/Actor/Info/InternetInfo/InternetLink/InternetLink.h"

AInternetLink::AInternetLink()
{

}


void AInternetLink::IsDataPending()
{
}
void AInternetLink::ParseURL(FString URL, FString &Addr, int32 &APort , FString LevelName, FString &EntryName)
{
}
void AInternetLink::Resolve(FString Domain)
{
}
void AInternetLink::GetLastError()
{
}
void AInternetLink::IpAddrToString(FIpAddr Arg)
{
}
void AInternetLink::StringToIpAddr(FString str, FIpAddr &Addr, bool hostOrder)
{
}
void AInternetLink::GameSpyValidate(FString ValidationString)
{
}
void AInternetLink::GameSpyGameName()
{
}
void AInternetLink::GetLocalHostName()
{
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
	IpAsString = Temp $ ".";
	Temp = IP.Addr >> 16 & 255;
	IpAsString = IpAsString $ Temp $ ".";
	Temp = IP.Addr >> 8 & 255;
	IpAsString = IpAsString $ Temp $ ".";
	Temp = IP.Addr >> 0 & 255;
	IpAsString = IpAsString $ Temp;
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
