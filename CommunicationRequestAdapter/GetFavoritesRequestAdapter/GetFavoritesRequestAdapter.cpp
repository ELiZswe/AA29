// All the original content belonged to the US Army


#include "AA29/CommunicationRequestAdapter/GetFavoritesRequestAdapter/GetFavoritesRequestAdapter.h"

AGetFavoritesRequestAdapter::AGetFavoritesRequestAdapter()
{
	RetryCountMax = 0;
}


void AGetFavoritesRequestAdapter::CommunicationFailureCallback()
{
}
void AGetFavoritesRequestAdapter::CommunicationCompleteCallback()
{
	//dOnGetFavoritesRequestComplete(ResultCode,BuddyList,serverList);
}

//native Function Request(string UserName, string Password);
void AGetFavoritesRequestAdapter::Request(FString UserName, FString Password)
{
}
//native Function AdaptResults();
void AGetFavoritesRequestAdapter::AdaptResults()
{
}
void AGetFavoritesRequestAdapter::dOnGetFavoritesRequestComplete(int32 aResultCode, TArray<FString> aBuddyList, TArray<FString> aserverList)
{
}