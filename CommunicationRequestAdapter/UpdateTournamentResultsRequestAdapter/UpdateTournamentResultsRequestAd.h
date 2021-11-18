// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/CommunicationRequestAdapter/CommunicationRequestAdapter.h"
#include "UpdateTournamentResultsRequestAd.generated.h"

/**
 * 
 */
UCLASS()
//Fullname is UpdateTournamentResultsRequestAdapter
class AA29_API AUpdateTournamentResultsRequestAd : public ACommunicationRequestAdapter
{
	GENERATED_BODY()
public:
	AUpdateTournamentResultsRequestAd();

	UPROPERTY()						TArray<FTournamentPlayer> PlayerRecords;								//var array<TournamentPlayer> PlayerRecords;

	void CommunicationFailureCallback();
	void CommunicationCompleteCallback();
	void Request(FString LeagueName, FString TournamentName, FString MatchID, FString Team0Name, FString Team1Name, int32 Team0Score, int32 Team1Score, int32 Team0CululativeScore, int32 Team1CumulativeScore, FString ServerName, FString MapName, FString AdminName, int32 PlannedLength, int32 ActualLength, int32 RoundLength, FString ServerIP);
	void AdaptResults();
	void AddPlayer(FString PlayerName, int32 TeamIndex, int32 Score);
};
