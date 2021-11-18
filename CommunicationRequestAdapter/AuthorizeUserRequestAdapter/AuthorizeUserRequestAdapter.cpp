// All the original content belonged to the US Army


#include "AA29/CommunicationRequestAdapter/AuthorizeUserRequestAdapter/AuthorizeUserRequestAdapter.h"

AAuthorizeUserRequestAdapter::AAuthorizeUserRequestAdapter()
{

}


void AAuthorizeUserRequestAdapter::CommunicationFailureCallback()
{
	/*
	local string Reason;
	local string ShortReason;
	GetFailureReasons(Reason,ShortReason);
	PlayerController(Owner).AuthTransmissionErrorCallback(ResultCode,Reason,ShortReason);
	*/
}
void AAuthorizeUserRequestAdapter::CommunicationCompleteCallback()
{
	/*
	DebugLog(DEBUG_Auth,"AuthorizeUserRequestAdapter:CommunicationComplete:CommunicationCompleteCallback()");
	if (Owner == None)
	{
		Return;
	}
	if (GetNetMode() == ENetMode::NM_DedicatedServer)
	{
		PlayerController(Owner).ServerAuthorizeUserAuthorizeComplete(ResultCode,Jacket);
	}
	else
	{
		PlayerController(Owner).ClientAuthorizeUserAuthorizeComplete(ResultCode,Jacket);
	}
	*/
}

//native Function Request(string UserName, string Password, string IPAddress, array<int> DistributionHistory);
void AAuthorizeUserRequestAdapter::Request(FString UserName, FString Password, FString IPAddress, TArray<int32> DistributionHistory)
{
}
//native Function AdaptResults();
void AAuthorizeUserRequestAdapter::AdaptResults()
{
}