// All the original content belonged to the US Army


#include "AA29/Object/Actor/Info/InternetInfo/InternetLink/UdpLink/UdpGamespyUplink/UdpGamespyUplink.h"


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
	if (Query == None)
	{
		Log("UdpGameSpyUplink: Could not find a UdpGameSpyQuery object, aborting.");
		Return;
	}
	HeartbeatMessage="\heartbeat\" $ Query.Port $ "\gamename\" $ GameSpyGameName();
	MasterServerIpAddr.Port=MasterServerPort;
	if (MasterServerAddress == "")
	{
		MasterServerAddress="master" $ ServerRegion $ ".gamespy.com";
	}
	Resolve(MasterServerAddress);
	*/
}
void AUdpGamespyUplink::Resolved(FIpAddr Addr)
{
	/*
	local int UplinkPort;
	MasterServerIpAddr.Addr=Addr.Addr;
	if (MasterServerIpAddr.Addr == 0)
	{
		Log("UdpGameSpyUplink: Invalid master server address, aborting.");
		Return;
	}
	Log("UdpGameSpyUplink: Master Server is " $ MasterServerAddress $ ":" $ MasterServerIpAddr.Port);
	UplinkPort=Query.Port + 1;
	if (BindPort(UplinkPort,True) == 0)
	{
		Log("UdpGameSpyUplink: Error binding port, aborting.");
		Return;
	}
	Log("UdpGameSpyUplink: Port " $ UplinkPort $ " successfully bound.");
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
	/*
	local bool Result;
	Result=SendText(MasterServerIpAddr,HeartbeatMessage);
	if (! Result)
	{
		Log("Failed to send heartbeat to master server.");
	}
	*/
}
void AUdpGamespyUplink::Halt()
{
	/*
	SetTimer(0,False);
	*/
}
void AUdpGamespyUplink::Resume()
{
	/*
	SetTimer(UpdateMinutes * 60,True);
	Timer();
	*/
}
void AUdpGamespyUplink::ReceivedText(FIpAddr Addr, FString Text)
{
	/*
	local string QueryStr;
	local bool QueryRemaining;
	local int QueryNum;
	local int PacketNum;
	CurrentQueryNum ++;
	if (CurrentQueryNum > 100)
	{
		CurrentQueryNum=1;
	}
	QueryNum=CurrentQueryNum;
	QueryStr=Text;
	if (QueryStr == "")
	{
		QueryRemaining=False;
	}
	else
	{
		QueryRemaining=True;
	}
	if (QueryRemaining)
	{
		QueryStr=ParseQuery(Addr,QueryStr,QueryNum,PacketNum);
		if (QueryStr == "")
		{
			QueryRemaining=False;
		}
		else
		{
			QueryRemaining=True;
		}
	}
	*/
}
void AUdpGamespyUplink::ParseNextQuery(FString aQuery, FString& QueryType, FString& QueryValue, FString& QueryRest, FString& FinalPacket)
{
	/*
	local string TempQuery;
	local int ClosingSlash;
	if (Query == "")
	{
		Return False;
	}
	if (Left(Query,1) == "\")
	{
		ClosingSlash=InStr(Right(Query,Len(Query) - 1),"\");
		if (ClosingSlash == 0)
		{
			Return False;
		}
		TempQuery=Query;
		QueryType=Right(Query,Len(Query) - 1);
		QueryType=Left(QueryType,ClosingSlash);
		QueryRest=Right(Query,Len(Query) - Len(QueryType) + 2);
		if (QueryRest == "" || Len(QueryRest) == 1)
		{
			FinalPacket="final";
			Return True;
		}
		else
		{
			if (Left(QueryRest,1) == "\")
			{
				Return True;
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
			Return True;
		}
		else
		{
			Return True;
		}
	}
	else
	{
		Return False;
	}
	*/
}
void AUdpGamespyUplink::ParseQuery(FIpAddr Addr, FString QueryStr, int32 QueryNum, int32& PacketNum)
{
	/*
	local string QueryType;
	local string QueryValue;
	local string QueryRest;
	local string ValidationString;
	local bool Result;
	local string FinalPacket;
	Result=ParseNextQuery(QueryStr,QueryType,QueryValue,QueryRest,FinalPacket);
	if (! Result)
	{
		Return "";
	}
	if (QueryType == "basic")
	{
		Result=True;
	}
	else
	{
		if (QueryType == "secure")
		{
			ValidationString="\validate\" $ GameSpyValidate(QueryValue);
			Result=SendQueryPacket(Addr,ValidationString,QueryNum,++ PacketNum,FinalPacket);
		}
	}
	Return QueryRest;
	*/
}
void AUdpGamespyUplink::SendQueryPacket(FIpAddr Addr, FString SendString, int32 QueryNum, int32 PacketNum, FString FinalPacket)
{
	/*
	local bool Result;
	if (FinalPacket == "final")
	{
		SendString=SendString $ "\final\";
	}
	SendString=SendString $ "\queryid\" $ QueryNum $ "." $ PacketNum;
	Result=SendText(Addr,SendString);
	Return Result;
	*/
}