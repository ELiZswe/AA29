// All the original content belonged to the US Army


#include "AA29/Info/MasterServerLink/ServerQueryClient/MasterServerClient/MasterServerClient.h"

AMasterServerClient::AMasterServerClient()
{
	/*
	PointerProperty* MSLinkPtr = NewObject<PointerProperty>(PointerProperty::StaticClass());
	*/
}

//native Function StartQuery(EClientToMaster Command);
void AMasterServerClient::StartQuery(EClientToMaster Command)
{

}

//native Function Stop();
void AMasterServerClient::Stop()
{

}

//native Function LaunchAutoUpdate();
void AMasterServerClient::LaunchAutoUpdate()
{

}

void AMasterServerClient::OnQueryFinished(EResponseInfo ResponseInfo, int32 Info)
{
}

void AMasterServerClient::OnReceivedServer(FServerResponseLine S)
{
}

void AMasterServerClient::OnReceivedMOTDData(EMOTDResponse Command, FString Value)
{
}

void AMasterServerClient::OnReceivedModMOTDData(FString Value)
{
}

void AMasterServerClient::OnReceivedOwnageItem(int32 Level, FString ItemName, FString ItemDesc, FString ItemURL)
{
}
