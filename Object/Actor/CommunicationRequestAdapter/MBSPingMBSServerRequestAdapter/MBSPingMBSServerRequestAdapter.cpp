// All the original content belonged to the US Army

#include "AA29/Object/Actor/CommunicationRequestAdapter/MBSPingMBSServerRequestAdapter/MBSPingMBSServerRequestAdapter.h"

AMBSPingMBSServerRequestAdapter::AMBSPingMBSServerRequestAdapter()
{
	RetryCountMax = 0;
}

/*
State CommunicationComplete
{
	Function CommunicationCompleteCallback()
	{
		if (nullptr != DBMBS(GetOwner()))
		{
			DBMBS(GetOwner())->SetPingTime(PingTimeMS);
		}
	}
	Function CommunicationFailureCallback()
	{
		Log("Failed to ping MBS server.");
	}
}
*/

void AMBSPingMBSServerRequestAdapter::CommunicationFailureCallback()
{
	/*
	Log("Failed to ping MBS server.");
	*/
}
void AMBSPingMBSServerRequestAdapter::CommunicationCompleteCallback()
{
	/*
	if (None != DBMBS(GetOwner()))
	{
		DBMBS(GetOwner())->SetPingTime(PingTimeMS);
	}
	*/
}

//native Function Request(string GameServerIPAddress);
void AMBSPingMBSServerRequestAdapter::Request(FString GameServerIPAddress)
{
}

//native Function AdaptResults();
void AMBSPingMBSServerRequestAdapter::AdaptResults()
{
}
