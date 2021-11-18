// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/CommunicationRequestAdapter/CommunicationRequestAdapter.h"
#include "UpdateTrustAndExperienceRequestA.generated.h"

/**
 * 
 */
UCLASS()
//Fullname is UpdateTrustAndExperienceRequestAdapter
class AA29_API AUpdateTrustAndExperienceRequestA : public ACommunicationRequestAdapter
{
	GENERATED_BODY()
public:
	AUpdateTrustAndExperienceRequestA();

	UPROPERTY()						int32 Experience;								//var int Experience;


	void CommunicationFailureCallback();
	void CommunicationCompleteCallback();
	void Request(FString UserName, FString Password, int32 aExperience, bool Logout, int32 RoundsPlayed, int32 TimePlayed, int32 Tour, int32 Mission, FString ServerIP);
	void AdaptResults();
};
