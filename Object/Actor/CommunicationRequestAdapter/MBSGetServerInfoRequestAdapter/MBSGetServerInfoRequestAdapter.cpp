// All the original content belonged to the US Army

#include "AA29/Object/Actor/CommunicationRequestAdapter/MBSGetServerInfoRequestAdapter/MBSGetServerInfoRequestAdapter.h"

AMBSGetServerInfoRequestAdapter::AMBSGetServerInfoRequestAdapter()
{
	RetryCountMax = 0;
}

/*
State CommunicationComplete
{
	Function CommunicationCompleteCallback()
	{
		if (None != ServerBrowserDBMBS(Owner))
		{
			ServerBrowserDBMBS(Owner).SetPlayerList(ServerItem.IP,ServerItem.Port,PlayerList);
		}
	}
	Function CommunicationFailureCallback()
	{
		Log("Failed to obtain MBS info from game server.");
	}
}
*/

void AMBSGetServerInfoRequestAdapter::CommunicationFailureCallback()
{
	/*
	Log("Failed to obtain MBS info from game server.");
	*/
}
void AMBSGetServerInfoRequestAdapter::CommunicationCompleteCallback()
{
	/*
	if (None != ServerBrowserDBMBS(Owner))
	{
		ServerBrowserDBMBS(Owner).SetPlayerList(ServerItem.IP,ServerItem.Port,PlayerList);
	}
	*/
}

//native Function Request(string IPAddress, int QueryPort);
void AMBSGetServerInfoRequestAdapter::Request(FString IPAddress, int32 QueryPort)
{
}
//native Function AdaptResults();
void AMBSGetServerInfoRequestAdapter::AdaptResults()
{
}
