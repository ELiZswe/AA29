// All the original content belonged to the US Army

#include "AA29/Object/Actor/CommunicationRequestAdapter/MBSPingServerRequestAdapter/MBSPingServerRequestAdapter.h"

AMBSPingServerRequestAdapter::AMBSPingServerRequestAdapter()
{
	RetryCountMax = 0;
}

/*
State CommunicationComplete
{
	Function CommunicationCompleteCallback()
	{
		if (nullptr != ServerBrowserDBMBS(GetOwner()))
		{
			ServerBrowserDBMBS(GetOwner())->SetPingTime(ServerIP,ServerPort,PingTimeMS);
		}
	}
	Function CommunicationFailureCallback()
	{
		int32 Quad = 0;
		FString IP = "";
		Quad=((ServerIP >> 0) & 255);
		IP=string(Quad) + ".";
		Quad=((ServerIP >> 8) & 255);
		(IP $= FString::FromInt(Quad) + ".");
		Quad=((ServerIP >> 16) & 255);
		(IP $= FString::FromInt(Quad) + ".");
		Quad=((ServerIP >> 24) & 255);
		(IP $= FString::FromInt(Quad));
	}
}
*/

void AMBSPingServerRequestAdapter::CommunicationFailureCallback()
{
	/*
	int32 Quad;
	FString IP;
	Quad = ServerIP >> 0 & 255;
	IP = Quad + ".";
	Quad = ServerIP >> 8 & 255;
	IP += Quad + ".";
	Quad = ServerIP >> 16 & 255;
	IP += Quad + ".";
	Quad = ServerIP >> 24 & 255;
	IP += Quad;
	*/
}
void AMBSPingServerRequestAdapter::CommunicationCompleteCallback()
{
/*
	if (None != ServerBrowserDBMBS(GetOwner()))
	{
		ServerBrowserDBMBS(GetOwner())->SetPingTime(ServerIP,ServerPort,PingTimeMS);
	}
*/
}
//native Function Request(string IPAddress, int QueryPort, int ServerPort);
void AMBSPingServerRequestAdapter::Request(FString IPAddress, int32 QueryPort, int32 aServerPort)
{

}

//native Function AdaptResults();
void AMBSPingServerRequestAdapter::AdaptResults()
{

}
