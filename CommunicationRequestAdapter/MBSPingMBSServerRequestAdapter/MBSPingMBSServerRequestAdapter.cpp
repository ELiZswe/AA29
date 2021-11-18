// All the original content belonged to the US Army


#include "AA29/CommunicationRequestAdapter/MBSPingMBSServerRequestAdapter/MBSPingMBSServerRequestAdapter.h"

AMBSPingMBSServerRequestAdapter::AMBSPingMBSServerRequestAdapter()
{
	RetryCountMax = 0;
}



void AMBSPingMBSServerRequestAdapter::CommunicationFailureCallback()
{
	/*
	Log("Failed to ping MBS server.");
	*/
}
void AMBSPingMBSServerRequestAdapter::CommunicationCompleteCallback()
{
	/*
	if (None != DBMBS(Owner))
	{
		DBMBS(Owner).SetPingTime(PingTimeMS);
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
