// All the original content belonged to the US Army

#include "AA29/Object/Actor/CommunicationRequestAdapter/GetRecordBriefRequestAdapter/GetRecordBriefRequestAdapter.h"

AGetRecordBriefRequestAdapter::AGetRecordBriefRequestAdapter()
{
	RetryCountMax = 0;
}

/*
State CommunicationComplete
{
	Function CommunicationCompleteCallback()
	{
		dOnGetRecordBriefComplete(ResultCode,RecordBrief);
	}
	Function CommunicationFailureCallback()
	{
	}
}
*/

void AGetRecordBriefRequestAdapter::CommunicationFailureCallback()
{
}
void AGetRecordBriefRequestAdapter::CommunicationCompleteCallback()
{
	//dOnGetRecordBriefComplete(ResultCode,RecordBrief);
}
//native Function Request(string UserName, string Password, string IPAddress, array<int> DistributionHistory);
void AGetRecordBriefRequestAdapter::Request(FString UserName, FString Password, FString IPAddress, TArray<int32> DistributionHistory)
{
}

//native Function AdaptResults();
void AGetRecordBriefRequestAdapter::AdaptResults()
{

}

void AGetRecordBriefRequestAdapter::dOnGetRecordBriefComplete(int32 aResultCode, FRecordBriefStruct aRecordBrief)
{
}
