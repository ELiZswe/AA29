// All the original content belonged to the US Army


#include "AA29/CommunicationRequestAdapter/MBSUpdateServerStateRequestAdapter/MBSUpdateServerStateRequestAdapt.h"

AMBSUpdateServerStateRequestAdapt::AMBSUpdateServerStateRequestAdapt()
{
	RetryCountMax = 0;
}

void AMBSUpdateServerStateRequestAdapt::CommunicationFailureCallback()
{
	//Log("Failed to send server state to MBS server.");
}
void AMBSUpdateServerStateRequestAdapt::CommunicationCompleteCallback()
{
	/*
	if (ResultCode != 1)
	{
		Log(Self @ "Failed to send state to MBS server:" @ ResultCode);
	}
	*/
}

//native Function Request(string UserName, string Password, string IPAddress, int HostPort, int QueryPort, int PlayerCount, int MaxPlayers, int AveragePlayerPing, array<GameInfo.KeyValuePair> ServerAttributes);
void AMBSUpdateServerStateRequestAdapt::Request(FString UserName, FString Password, FString IPAddress, int32 HostPort, int32 QueryPort, int32 PlayerCount, int32 MaxPlayers, int32 AveragePlayerPing, TArray<FKeyValuePair> ServerAttributes)
{

}

//native Function AdaptResults();
void AMBSUpdateServerStateRequestAdapt::AdaptResults()
{

}

void AMBSUpdateServerStateRequestAdapt::AddPlayer(FString PlayerName, FString IPAddress, int32 Ping, TArray<FKeyValuePair> Attributes)
{
	FPlayerMBSInfo NewRecord;
	NewRecord.PlayerName = PlayerName;
	NewRecord.IPAddress = IPAddress;
	NewRecord.Ping = Ping;
	NewRecord.Attributes = Attributes;
	PlayerRecords.Add(NewRecord);
}