// All the original content belonged to the US Army

#include "AA29/Object/Actor/CommunicationRequestAdapter/MissionCompleteRequestAdapter/MissionCompleteRequestAdapter.h"

AMissionCompleteRequestAdapter::AMissionCompleteRequestAdapter()
{

}

/*
State CommunicationComplete
{
	Function CommunicationCompleteCallback()
	{
		if (Owner == nullptr)
		{
			return;
		}
		if (GetWorld()->GetNetMode() == NM_DedicatedServer)
		{
			Cast<APlayerController>(GetOwner())->ServerMissionCompleteAuthorizeComplete(ResultCode,Jacket);
		}
		else
		{
			Cast<APlayerController>(GetOwner())->ClientMissionCompleteAuthorizeComplete(ResultCode,Jacket);
		}
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

void AMissionCompleteRequestAdapter::CommunicationFailureCallback()
{
	/*
	FString Reason;
	FString ShortReason;
	GetFailureReasons(Reason,ShortReason);
	Cast<APlayerController>(GetOwner())->AuthTransmissionErrorCallback(ResultCode,Reason,ShortReason);
	*/
}
void AMissionCompleteRequestAdapter::CommunicationCompleteCallback()
{
	/*
	if (Owner == nullptr)
	{
		return;
	}
	if (GetNetMode() == ENetMode::NM_DedicatedServer)
	{
		Cast<APlayerController>(GetOwner())->ServerMissionCompleteAuthorizeComplete(ResultCode,Jacket);
	}
	else
	{
		Cast<APlayerController>(GetOwner())->ClientMissionCompleteAuthorizeComplete(ResultCode,Jacket);
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
