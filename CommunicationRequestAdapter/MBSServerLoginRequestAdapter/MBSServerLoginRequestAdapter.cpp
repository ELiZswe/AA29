// All the original content belonged to the US Army


#include "AA29/CommunicationRequestAdapter/MBSServerLoginRequestAdapter/MBSServerLoginRequestAdapter.h"

AMBSServerLoginRequestAdapter::AMBSServerLoginRequestAdapter()
{
	RetryCountMax = 0;

}

void AMBSServerLoginRequestAdapter::CommunicationFailureCallback()
{
	//Log("Failed to login to MBS server.");
}
void AMBSServerLoginRequestAdapter::CommunicationCompleteCallback()
{
}

//native Function Request(string UserName, string Password, string IPAddress, int HostPort, int QueryPort, int MaxPlayers);
void AMBSServerLoginRequestAdapter::Request(FString UserName, FString Password, FString IPAddress, int32 HostPort, int32 QueryPort, int32 MaxPlayers)
{
}

//native Function AdaptResults();
void AMBSServerLoginRequestAdapter::AdaptResults()
{
}