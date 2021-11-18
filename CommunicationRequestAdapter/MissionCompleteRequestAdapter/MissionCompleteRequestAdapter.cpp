// All the original content belonged to the US Army


#include "AA29/CommunicationRequestAdapter/MissionCompleteRequestAdapter/MissionCompleteRequestAdapter.h"

AMissionCompleteRequestAdapter::AMissionCompleteRequestAdapter()
{

}



void AMissionCompleteRequestAdapter::CommunicationFailureCallback()
{
	/*
	local string Reason;
	local string ShortReason;
	GetFailureReasons(Reason,ShortReason);
	PlayerController(Owner).AuthTransmissionErrorCallback(ResultCode,Reason,ShortReason);
	*/
}
void AMissionCompleteRequestAdapter::CommunicationCompleteCallback()
{
	/*
	if (Owner == None)
	{
		Return;
	}
	if (GetNetMode() == ENetMode::NM_DedicatedServer)
	{
		PlayerController(Owner).ServerMissionCompleteAuthorizeComplete(ResultCode,Jacket);
	}
	else
	{
		PlayerController(Owner).ClientMissionCompleteAuthorizeComplete(ResultCode,Jacket);
	}
	*/
}

//native Function Request(string UserName, string Password, int Tour, int Mission, int Marksmanship, bool passFail, array<int> DistributionHistory, string IPAddress);
void AMissionCompleteRequestAdapter::Request(FString UserName, FString Password, int32 Tour, int32 Mission, int32 Marksmanship, bool passFail, TArray<int32> DistributionHistory, FString IPAddress)
{
}

//native Function AdaptResults();
void AMissionCompleteRequestAdapter::AdaptResults()
{
}

void AMissionCompleteRequestAdapter::AddExtraMissionData(FString Data)
{
	ExtraMissionData.Add(Data);
}