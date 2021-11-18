// All the original content belonged to the US Army


#include "AA29/CommunicationRequestAdapter/UpdateTournamentResultsRequestAdapter/UpdateTournamentResultsRequestAd.h"

AUpdateTournamentResultsRequestAd::AUpdateTournamentResultsRequestAd()
{

}



void AUpdateTournamentResultsRequestAd::CommunicationFailureCallback()
{
	/*
	local string Reason;
	local string ShortReason;
	GetFailureReasons(Reason,ShortReason);
	PlayerController(Owner).AuthTransmissionErrorCallback(ResultCode,Reason,ShortReason);
	*/
}
void AUpdateTournamentResultsRequestAd::CommunicationCompleteCallback()
{
	/*
	if (GameInfo(Owner) != None)
	{
		GameInfo(Owner).TournamentResultsAuthCallback(ResultCode);
	}
	*/
}

//native Function Request(string LeagueName, string TournamentName, string MatchID, string Team0Name, string Team1Name, int Team0Score, int Team1Score, int Team0CululativeScore, int Team1CumulativeScore, string ServerName, string MapName, string AdminName, int PlannedLength, int ActualLength, int RoundLength, string ServerIP);
void AUpdateTournamentResultsRequestAd::Request(FString LeagueName, FString TournamentName, FString MatchID, FString Team0Name, FString Team1Name, int32 Team0Score, int32 Team1Score, int32 Team0CululativeScore, int32 Team1CumulativeScore, FString ServerName, FString MapName, FString AdminName, int32 PlannedLength, int32 ActualLength, int32 RoundLength, FString ServerIP)
{
}

//native Function AdaptResults();
void AUpdateTournamentResultsRequestAd::AdaptResults()
{
}

void AUpdateTournamentResultsRequestAd::AddPlayer(FString PlayerName, int32 TeamIndex, int32 Score)
{
	FTournamentPlayer NewRecord;
	NewRecord.PlayerName = PlayerName;
	NewRecord.TeamIndex = TeamIndex;
	NewRecord.Score = Score;
	PlayerRecords.Add(NewRecord);
}