// All the original content belonged to the US Army


#include "AA29/CommunicationRequestAdapter/STSRequestAdapter/STSRequestAdapter.h"

ASTSRequestAdapter::ASTSRequestAdapter()
{

}


void ASTSRequestAdapter::CommunicationFailureCallback()
{
}
void ASTSRequestAdapter::CommunicationCompleteCallback()
{
	//DebugLog(DEBUG_Auth,"STSRequestAdapter:CommunicationComplete:CommunicationCompleteCallback -" @ ResultCode);
}
void ASTSRequestAdapter::AddPlayerEvents(FPlayerEvents Events)
{
	//PlayerEventsList[PlayerEventsList.Length] = Events;
}
//native Function Request(string ServerIPAddress, int ServerPort, int ServerMode, string MapName, string DMSID, int RoundsPlayed, int PlayTimeSeconds);
void ASTSRequestAdapter::Request(FString ServerIPAddress, int32 ServerPort, int32 ServerMode, FString MapName, FString DMSID, int32 RoundsPlayed, int32 PlayTimeSeconds)
{
}

//native Function AdaptResults();
void ASTSRequestAdapter::AdaptResults()
{
}