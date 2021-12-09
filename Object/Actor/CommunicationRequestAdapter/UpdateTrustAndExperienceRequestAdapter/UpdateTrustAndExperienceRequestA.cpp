// All the original content belonged to the US Army


#include "AA29/Object/Actor/CommunicationRequestAdapter/UpdateTrustAndExperienceRequestAdapter/UpdateTrustAndExperienceRequestA.h"

AUpdateTrustAndExperienceRequestA::AUpdateTrustAndExperienceRequestA()
{

}

void AUpdateTrustAndExperienceRequestA::CommunicationFailureCallback()
{
	/*
	local string Reason;
	local string ShortReason;
	GetFailureReasons(Reason,ShortReason);
	PlayerController(Owner).AuthTransmissionErrorCallback(ResultCode,Reason,ShortReason);
	*/
}
void AUpdateTrustAndExperienceRequestA::CommunicationCompleteCallback()
{
	/*
	if (Owner == None || PlayerController(Owner) == None)
	{
		Return;
	}
	PlayerController(Owner).ServerExperienceUpdateAuthorizeComplete(ResultCode);
	*/
}

//native Function Request(string UserName, string Password, int Experience, bool Logout, int RoundsPlayed, int TimePlayed, int Tour, int Mission, string ServerIP);
void AUpdateTrustAndExperienceRequestA::Request(FString UserName, FString Password, int32 aExperience, bool Logout, int32 RoundsPlayed, int32 TimePlayed, int32 Tour, int32 Mission, FString ServerIP)
{

}

//native Function AdaptResults();
void AUpdateTrustAndExperienceRequestA::AdaptResults()
{

}