// All the original content belonged to the US Army


#include "AA29/CommunicationRequestAdapter/MBSPingServerRequestAdapter/MBSPingServerRequestAdapter.h"

AMBSPingServerRequestAdapter::AMBSPingServerRequestAdapter()
{
	RetryCountMax = 0;
}

void AMBSPingServerRequestAdapter::CommunicationFailureCallback()
{
	/*
	local int Quad;
	local string IP;
	Quad = ServerIP >> 0 & 255;
	IP = Quad $ ".";
	Quad = ServerIP >> 8 & 255;
	IP $ = Quad $ ".";
	Quad = ServerIP >> 16 & 255;
	IP $ = Quad $ ".";
	Quad = ServerIP >> 24 & 255;
	IP $ = Quad;
	*/
}
void AMBSPingServerRequestAdapter::CommunicationCompleteCallback()
{
/*
	if (None != ServerBrowserDBMBS(Owner))
	{
		ServerBrowserDBMBS(Owner).SetPingTime(ServerIP,ServerPort,PingTimeMS);
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