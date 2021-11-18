// All the original content belonged to the US Army


#include "AA29/Info/MasterServerLink/ServerQueryClient/ServerQueryClient.h"

AServerQueryClient::AServerQueryClient()
{

}

void AServerQueryClient::OnReceivedPingInfo(int32 ListID, EPingCause PingCause, FServerResponseLine S)
{
}

void AServerQueryClient::OnPingTimeout(int32 ListID, EPingCause PingCause)
{
}

//native Function PingServer(int32 ListID, EPingCause PingCause, FString IP, int32 Port, EQueryInterfaceCommand Command, GameInfo.ServerResponseLine CurrentState);
void AServerQueryClient::PingServer(int32 ListID, EPingCause PingCause, FString IP, int32 Port, EQueryInterfaceCommand Command, FServerResponseLine CurrentState)
{

}

//native Function CancelPings();
void AServerQueryClient::CancelPings()
{

}

//native Function bool NetworkError();
bool AServerQueryClient::NetworkError()
{
	return false;     //FAKE   /ELiZ
}

void AServerQueryClient::BroadcastPingRequest()
{
	/*
	local GameInfo.ServerResponseLine Temp;
	if (class'IpDrv.MasterServerUplink'.Default.LANServerPort >= 0)
	{
		PingServer(-1, 3, "BROADCAST", class'IpDrv.MasterServerUplink'.Default.LANServerPort, 0, Temp);
	}
	*/
}
