// All the original content belonged to the US Army


#include "AA29/CommunicationRequestAdapter/UpdateFavoritesRequestAdapter/UpdateFavoritesRequestAdapter.h"

AUpdateFavoritesRequestAdapter::AUpdateFavoritesRequestAdapter()
{
	RetryCountMax = 0;

}


void AUpdateFavoritesRequestAdapter::CommunicationFailureCallback()
{
}
void AUpdateFavoritesRequestAdapter::CommunicationCompleteCallback()
{
	dOnUpdateFavoritesRequestComplete(ResultCode);
}

//native Function AddBuddy(string UserName, string Password, string Buddy);
void AUpdateFavoritesRequestAdapter::AddBuddy(FString UserName, FString Password, FString Buddy)
{
}

//native Function RemoveBuddy(string UserName, string Password, string Buddy);
void AUpdateFavoritesRequestAdapter::RemoveBuddy(FString UserName, FString Password, FString Buddy)
{
}

//native Function AddServer(string UserName, string Password, string Server);
void AUpdateFavoritesRequestAdapter::AddServer(FString UserName, FString Password, FString Server)
{
}

//native Function RemoveServer(string UserName, string Password, string Server);
void AUpdateFavoritesRequestAdapter::RemoveServer(FString UserName, FString Password, FString Server)
{
}

//native Function AdaptResults();
void AUpdateFavoritesRequestAdapter::AdaptResults()
{
}

void AUpdateFavoritesRequestAdapter::dOnUpdateFavoritesRequestComplete(int32 aResultCode)
{
}