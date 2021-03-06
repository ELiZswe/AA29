// All the original content belonged to the US Army

#include "AA29/Object/Actor/Info/InternetInfo/InternetLink/UdpLink/UdpGamespyUplink/UdpGamespyUplink.h"
#include "AA29/Object/Actor/Info/InternetInfo/InternetLink/UdpLink/UdpGamespyQuery/UdpGamespyQuery.h"

AUdpGamespyUplink::AUdpGamespyUplink()
{
	UpdateMinutes = 1;
	MasterServerPort = 27900;
	TargetQueryName = "MasterUplink";
}

void AUdpGamespyUplink::PreBeginPlay()
{
	/*
	ForEach AllActors('UdpGamespyQuery',Query,TargetQueryName)
	{
		GOTO JL0019;
JL0019:
	}
	if (Query == nullptr)
	{
		Log("UdpGameSpyUplink: Could not find a UdpGameSpyQuery object, aborting.");
		return;
	}
	HeartbeatMessage="\heartbeat\" + Query.Port + "\gamename\" + GameSpyGameName();
	MasterServerIpAddr.Port=MasterServerPort;
	if (MasterServerAddress == "")
	{
		MasterServerAddress="master" + ServerRegion + ".gamespy.com";
	}
	Resolve(MasterServerAddress);
	*/
}
void AUdpGamespyUplink::Resolved(FIpAddr Addr)
{
	/*
	int32 UplinkPort;
	MasterServerIpAddr.Addr=Addr.Addr;
	if (MasterServerIpAddr.Addr == 0)
	{
		Log("UdpGameSpyUplink: Invalid master server address, aborting.");
		return;
	}
	Log("UdpGameSpyUplink: Master Server is " + MasterServerAddress + ":" + MasterServerIpAddr.Port);
	UplinkPort=Query.Port + 1;
	if (BindPort(UplinkPort,True) == 0)
	{
		Log("UdpGameSpyUplink: Error binding port, aborting.");
		return;
	}
	Log("UdpGameSpyUplink: Port " + UplinkPort + " successfully bound.");
	Resume();
	*/
}
void AUdpGamespyUplink::ResolveFailed()
{
	/*
	Log("UdpGameSpyUplink: Failed to resolve master server address, aborting.");
	*/
}
void AUdpGamespyUplink::Timer()
{
	bool Result = false;
	/*
	Result=SendText(MasterServerIpAddr,HeartbeatMessage);
	if (! Result)
	{
		Log("Failed to send heartbeat to master server.");
	}
	*/
}

void AUdpGamespyUplink::Halt()
{
	//SetTimer(0,false);
}

void AUdpGamespyUplink::Resume()
{
	/*
	SetTimer(UpdateMinutes * 60,true);
	Timer();
	*/
}

void AUdpGamespyUplink::ReceivedText(FIpAddr Addr, FString Text)
{
	FString QueryStr = "";
	bool QueryRemaining = false;
	int32 QueryNum = 0;
	int32 PacketNum = 0;
	CurrentQueryNum++;
	/*
	if (CurrentQueryNum > 100)
	{
		CurrentQueryNum=1;
	}
	QueryNum=CurrentQueryNum;
	QueryStr=Text;
	if (QueryStr == "")
	{
		QueryRemaining=false;
	}
	else
	{
		QueryRemaining=true;
	}
	if (QueryRemaining)
	{
		QueryStr=ParseQuery(Addr,QueryStr,QueryNum,PacketNum);
		if (QueryStr == "")
		{
			QueryRemaining=false;
		}
		else
		{
			QueryRemaining=true;
		}
	}
	*/
}

bool AUdpGamespyUplink::ParseNextQuery(FString aQuery, FString& QueryType, FString& QueryValue, FString& QueryRest, FString& FinalPacket)
{
	/*
	FString TempQuery;
	int32 ClosingSlash;
	if (Query == "")
	{
		return false;
	}
	if (Left(Query,1) == "\")
	{
		ClosingSlash=InStr(Right(Query,Len(Query) - 1),"\");
		if (ClosingSlash == 0)
		{
			return false;
		}
		TempQuery=Query;
		QueryType=Right(Query,Len(Query) - 1);
		QueryType=Left(QueryType,ClosingSlash);
		QueryRest=Right(Query,Len(Query) - Len(QueryType) + 2);
		if (QueryRest == "" || Len(QueryRest) == 1)
		{
			FinalPacket="final";
			return true;
		}
		else
		{
			if (Left(QueryRest,1) == "\")
			{
				return true;
			}
		}
		ClosingSlash=InStr(QueryRest,"\");
		if (ClosingSlash >= 0)
		{
			QueryValue=Left(QueryRest,ClosingSlash);
		}
		else
		{
			QueryValue=QueryRest;
		}
		QueryRest=Right(Query,Len(Query) - Len(QueryType) + Len(QueryValue) + 3);
		if (QueryRest == "")
		{
			FinalPacket="final";
			return true;
		}
		else
		{
			return true;
		}
	}
	else
	{
		return false;
	}
	*/
	return false;    //FAKE   /ELiZ
}

FString AUdpGamespyUplink::ParseQuery(FIpAddr Addr, FString QueryStr, int32 QueryNum, int32& PacketNum)
{
	FString QueryType = "";
	FString QueryValue = "";
	FString QueryRest = "";
	FString ValidationString = "";
	bool Result = false;
	FString FinalPacket = "";
	/*
	Result=ParseNextQuery(QueryStr,QueryType,QueryValue,QueryRest,FinalPacket);
	if (! Result)
	{
		return "";
	}
	if (QueryType == "basic")
	{
		Result=true;
	}
	else
	{
		if (QueryType == "secure")
		{
			ValidationString="\validate\" + GameSpyValidate(QueryValue);
			Result=SendQueryPacket(Addr,ValidationString,QueryNum,++ PacketNum,FinalPacket);
		}
	}
	*/
	return QueryRest;
}

bool AUdpGamespyUplink::SendQueryPacket(FIpAddr Addr, FString SendString, int32 QueryNum, int32 PacketNum, FString FinalPacket)
{
	bool Result = false;
	/*
	if (FinalPacket == "final")
	{
		SendString=SendString + "\final\";
	}
	SendString=SendString + "\queryid\" + QueryNum + "." + PacketNum;
	Result=SendText(Addr,SendString);
	*/
	return Result;
}
