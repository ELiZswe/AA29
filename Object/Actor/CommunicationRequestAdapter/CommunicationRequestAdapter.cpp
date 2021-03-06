// All the original content belonged to the US Army

#include "AA29/Object/Actor/CommunicationRequestAdapter/CommunicationRequestAdapter.h"

// Sets default values
ACommunicationRequestAdapter::ACommunicationRequestAdapter()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RetryCountMax = 10;
	RetryTimeoutDuration = 120;

	ErrorMessages.SetNum(111);
	ErrorMessages[0] = "Unknown Error";
	ErrorMessages[1] = "Invalid Password";
	ErrorMessages[2] = "Invalid Login";
	ErrorMessages[3] = "Player is Banned";
	ErrorMessages[4] = "Invalid Port";
	ErrorMessages[8] = "Cheat Experience";
	ErrorMessages[9] = "Invalid User IP";
	ErrorMessages[10] = "Update Tours Unhandled";
	ErrorMessages[11] = "Invalid Server";
	ErrorMessages[12] = "Invalid Mission";
	ErrorMessages[15] = "Invalid IP";
	ErrorMessages[16] = "Invalid Event";
	ErrorMessages[20] = "Invalid Version";
	ErrorMessages[41] = "Cheat Marksmanship";
	ErrorMessages[51] = "Invalid Buddy";
	ErrorMessages[52] = "Buddy Max Exceeded";
	ErrorMessages[53] = "Duplicate Buddy";
	ErrorMessages[54] = "Buddy Not Found";
	ErrorMessages[61] = "Invalid Favorite Server";
	ErrorMessages[62] = "Favorite Server Max Exceeded";
	ErrorMessages[63] = "Duplicate Favorite Server";
	ErrorMessages[64] = "Favorite Server Not Found";
	ErrorMessages[65] = "Nonunique Server";
	ErrorMessages[99] = "The MBS server has lost its connection to the database";
	ErrorMessages[100] = "Shoothouse Error";
	ErrorMessages[101] = "Shoothouse Error";
	ErrorMessages[102] = "Shoothouse Error";
	ErrorMessages[103] = "Shoothouse Error";
	ErrorMessages[104] = "Shoothouse Error";
	ErrorMessages[105] = "Shoothouse Error";
	ErrorMessages[106] = "Shoothouse Error";
	ErrorMessages[107] = "Shoothouse Error";
	ErrorMessages[108] = "Shoothouse Error";
	ErrorMessages[109] = "Shoothouse Error";
	ErrorMessages[110] = "Shoothouse Error";
	//bHidden = true;
}

/*
State WaitingForCommunicationToComplete
{
	Function BeginState()
	{
		fpWaitForCommResponseTime=0;
	}
	Function EndState()
	{
	}
	Event Tick(float fpDeltaTime)
	{
		Super::Tick(fpDeltaTime);
		(fpWaitForCommResponseTime += fpDeltaTime);
		if (fpWaitForCommResponseTime < 2)
		{
			return;
		}
		fpWaitForCommResponseTime=0;
		if (RequestIsComplete())
		{
			GotoState("CommunicationComplete");
		}
		else
		{
			UpdateBytesReceived();
		}
	}
}
*/

/*
State CommunicationComplete
{
	Event BeginState()
	{
		if (RequestWasSuccessful())
		{
			AdaptResults();
			DebugLog(DEBUG_Auth,string(this) + ":CommunicationComplete:BeginState - Success - ResultCode:" @ FString::FromInt(ResultCode) @ "RetryCount:" @ FString::FromInt(RetryCount) + "/" + FString::FromInt(RetryCountMax) @ "Timeout:" @ FString::FromInt(GetWorld()->GetTimeSeconds()) + "/" + FString::FromInt(RetryTimeout) @ FString::FromInt(BytesReceived) @ "bytes");
			if (bFailAllAuthRequests)
			{
				ResultCode=FailAllAuthRequestsResultCode;
			}
			if (ResultCode != 1)
			{
				Log(string(this) @ "ResultCode:" @ FString::FromInt(ResultCode) @ "/" @ GetErrorMessage(ResultCode));
			}
			CommunicationCompleteCallback();
			DestroyRequest();
			Destroy();
		}
		else
		{
			DebugLog(DEBUG_Auth,string(this) + ":CommunicationComplete:BeginState - Failure - RetryCount:" @ FString::FromInt(RetryCount) + "/" + FString::FromInt(RetryCountMax) @ "Timeout:" @ FString::FromInt(GetWorld()->GetTimeSeconds()) + "/" + FString::FromInt(RetryTimeout) @ FString::FromInt(BytesReceived) @ "bytes");
			if ((RetryCount < RetryCountMax) && (GetWorld()->GetTimeSeconds() < RetryTimeout))
			{
				Retry();
			}
			else
			{
				ResultCode=-4;
				if (bFailAllAuthRequests)
				{
					ResultCode=FailAllAuthRequestsResultCode;
				}
				CommunicationFailureCallback();
				CommunicationCompleteCallback();
				DestroyRequest();
				Destroy();
			}
		}
	}
	Function CommunicationCompleteCallback()
	{
	}
	Function CommunicationFailureCallback()
	{
	}
}
*/


void ACommunicationRequestAdapter::BeginPlay()
{
	Super::BeginPlay();
	
}


void ACommunicationRequestAdapter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	/*
	fpWaitForCommResponseTime += fpDeltaTime;
	if (fpWaitForCommResponseTime < 2)
	{
		return;
	}
	fpWaitForCommResponseTime = 0;
	if (RequestIsComplete())
	{
		GotoState('CommunicationComplete');
	}
	else
	{
		UpdateBytesReceived();
	}
	*/
}

bool ACommunicationRequestAdapter::RequestConnectionFailed()
{
	return false;    //FAKE  /ELiZ
}

bool ACommunicationRequestAdapter::RequestIsComplete()
{
	return false;    //FAKE  /ELiZ
}

void ACommunicationRequestAdapter::UpdateBytesReceived()
{
}

bool ACommunicationRequestAdapter::RequestWasSuccessful()
{
	return false;    //FAKE  /ELiZ
}

void ACommunicationRequestAdapter::AdaptResults()
{
}

void ACommunicationRequestAdapter::Retry()
{
}

void ACommunicationRequestAdapter::DestroyRequest()
{
}

FString ACommunicationRequestAdapter::GetErrorMessage(int32 aResultCode)
{
	if (((ResultCode <= 0) && (ResultCode >= -111)) && (GetDefault<ACommunicationRequestAdapter>()->ErrorMessages[(-ResultCode)].Len() > 0))
	{
		return GetDefault<ACommunicationRequestAdapter>()->ErrorMessages[(-ResultCode)];
	}
	return ("<unknown error> (" + FString::FromInt(ResultCode) + ")");
}

void ACommunicationRequestAdapter::GetFailureReasons(FString &Reason, FString &ShortReason)
{
	/*
	if (RequestConnectionFailed())
	{
		Reason="Failed to connect to Authorization Server.";
		ShortReason="Comm Err:";
	}
	else
	{
		Reason="Unknown error communicating with the Authorization Server.";
		ShortReason="Unknown";
	}
	*/
}

void ACommunicationRequestAdapter::CommunicationFailureCallback()
{
}

void ACommunicationRequestAdapter::CommunicationCompleteCallback()
{
}

void ACommunicationRequestAdapter::BeginState()
{
	/*
	if (RequestWasSuccessful())
	{
		AdaptResults();
		DebugLog(DEBUG_Auth,Self + ":CommunicationComplete:BeginState - Success - ResultCode:" @ ResultCode @ "RetryCount:" @ RetryCount + "/" + RetryCountMax @ "Timeout:" @ GetWorld()->GetTimeSeconds() + "/" + RetryTimeout @ BytesReceived @ "bytes");
		if (bFailAllAuthRequests)
		{
			ResultCode=FailAllAuthRequestsResultCode;
		}
		if (ResultCode != 1)
		{
			Log(Self @ "ResultCode:" @ ResultCode @ "/" @ GetErrorMessage(ResultCode));
		}
		CommunicationCompleteCallback();
		DestroyRequest();
		Destroy();
	}
	else
	{
		DebugLog(DEBUG_Auth,Self + ":CommunicationComplete:BeginState - Failure - RetryCount:" @ RetryCount + "/" + RetryCountMax @ "Timeout:" @ GetWorld()->GetTimeSeconds() + "/" + RetryTimeout @ BytesReceived @ "bytes");
		if (RetryCount < RetryCountMax && GetWorld()->GetTimeSeconds() < RetryTimeout)
		{
			Retry();
		}
		else
		{
			ResultCode=-4;
			if (bFailAllAuthRequests)
			{
				ResultCode=FailAllAuthRequestsResultCode;
			}
			CommunicationFailureCallback();
			CommunicationCompleteCallback();
			DestroyRequest();
			Destroy();
		}
	}
	*/
}

