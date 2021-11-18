// All the original content belonged to the US Army


#include "AA29/CommunicationRequestAdapter/GetNewsRequestAdapter/GetNewsRequestAdapter.h"

AGetNewsRequestAdapter::AGetNewsRequestAdapter()
{

}



void AGetNewsRequestAdapter::CommunicationFailureCallback()
{
	/*
	local string Reason;
	local string ShortReason;
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