// All the original content belonged to the US Army

#include "AA29/Object/Actor/CommunicationRequestAdapter/GetNewsRequestAdapter/GetNewsRequestAdapter.h"

AGetNewsRequestAdapter::AGetNewsRequestAdapter()
{

}

/*
State CommunicationComplete
{
	Function CommunicationCompleteCallback()
	{
		PlayerController(Owner).ClientNewsAuthorizeComplete(ResultCode,NewsVersion,Lines);
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

void AGetNewsRequestAdapter::CommunicationFailureCallback()
{
	/*
	FString Reason;
	FString ShortReason;
	GetFailureReasons(Reason,ShortReason);
	PlayerController(Owner).AuthTransmissionErrorCallback(ResultCode,Reason,ShortReason);
	*/
}
void AGetNewsRequestAdapter::CommunicationCompleteCallback()
{
	/*
	PlayerController(Owner).ClientNewsAuthorizeComplete(ResultCode,NewsVersion,Lines);
	*/
}

//native Function Request(string UserName, string Password, int NewsId);
void AGetNewsRequestAdapter::Request(FString UserName, FString Password, int32 NewsId)
{

}
//native Function AdaptResults();
void AGetNewsRequestAdapter::AdaptResults()
{

}
