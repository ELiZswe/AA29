// All the original content belonged to the US Army

#include "AA29/Object/Actor/CommunicationRequestAdapter/GetNewsRequestAdapter/GetNewsRequestAdapter.h"

AGetNewsRequestAdapter::AGetNewsRequestAdapter()
{
	Lines.SetNum(4);

}

/*
State CommunicationComplete
{
	Function CommunicationCompleteCallback()
	{
		Cast<APlayerController>(GetOwner())->ClientNewsAuthorizeComplete(ResultCode,NewsVersion,Lines);
	}
	Function CommunicationFailureCallback()
	{
		FString Reason = "";
		FString ShortReason = "";
		GetFailureReasons(Reason,ShortReason);
		Cast<APlayerController>(GetOwner())->AuthTransmissionErrorCallback(ResultCode,Reason,ShortReason);
	}
}
*/

void AGetNewsRequestAdapter::CommunicationFailureCallback()
{
	/*
	FString Reason;
	FString ShortReason;
	GetFailureReasons(Reason,ShortReason);
	Cast<APlayerController>(GetOwner())->AuthTransmissionErrorCallback(ResultCode,Reason,ShortReason);
	*/
}
void AGetNewsRequestAdapter::CommunicationCompleteCallback()
{
	/*
	Cast<APlayerController>(GetOwner())->ClientNewsAuthorizeComplete(ResultCode,NewsVersion,Lines);
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
