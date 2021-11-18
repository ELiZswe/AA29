// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/CommunicationRequestAdapter/CommunicationRequestAdapter.h"
#include "STSRequestAdapter.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ASTSRequestAdapter : public ACommunicationRequestAdapter
{
	GENERATED_BODY()
public:
	ASTSRequestAdapter();
	UPROPERTY()						TArray<FPlayerEvents> PlayerEventsList;								//var array<PlayerEvents> PlayerEventsList;

	void CommunicationFailureCallback();
	void CommunicationCompleteCallback();
	void AddPlayerEvents(FPlayerEvents Events);
	void Request(FString ServerIPAddress, int32 ServerPort, int32 ServerMode, FString MapName, FString DMSID, int32 RoundsPlayed, int32 PlayTimeSeconds);
	void AdaptResults();

};
