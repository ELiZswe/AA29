// All the original content belonged to the US Army

#include "AA29/Object/Actor/CommunicationRequestAdapter/AuthorizeUserRequestAdapter/AuthorizeUserRequestAdapter.h"

AAuthorizeUserRequestAdapter::AAuthorizeUserRequestAdapter()
{

}

/*
State CommunicationComplete
{
	Function CommunicationCompleteCallback()
	{
		DebugLog(DEBUG_Auth,"AuthorizeUserRequestAdapter:CommunicationComplete:CommunicationCompleteCallback()");
		if (Owner == nullptr)
		{
			return;
		}
		if (Level.NetMode == NM_DedicatedServer)
		{
			PlayerController(Owner).ServerAuthorizeUserAuthorizeComplete(ResultCode,Jacket);
		}
		else
		{
			PlayerController(Owner).ClientAuthorizeUserAuthorizeComplete(ResultCode,Jacket);
		}
	}
	Function CommunicationFailureCallback()
	{
		FString Reason = "";
		FString ShortReason = "";
		GetFailureReasons(Reason,ShortReason);
		PlayerController(Owner).AuthTransmissionErrorCallback(ResultCode,Reason,ShortReason);
	}
}
*/

void AAuthorizeUserRequestAdapter::CommunicationFailureCallback()
{
	/*
	FString Reason;
	FString ShortReason;
	GetFailureReasons(Reason,ShortReason);
	PlayerController(Owner).AuthTransmissionErrorCallback(ResultCode,Reason,ShortReason);
	*/
}
void AAuthorizeUserRequestAdapter::CommunicationCompleteCallback()
{
	/*
	DebugLog(DEBUG_Auth,"AuthorizeUserRequestAdapter:CommunicationComplete:CommunicationCompleteCallback()");
	if (Owner == nullptr)
	{
		return;
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
