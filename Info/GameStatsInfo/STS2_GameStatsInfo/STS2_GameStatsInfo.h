// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Info/GameStatsInfo/GameStatsInfo.h"
#include "STS2_GameStatsInfo.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ASTS2_GameStatsInfo : public AGameStatsInfo
{
	GENERATED_BODY()
public:
	ASTS2_GameStatsInfo();

	UPROPERTY()		float LastRoundTimeStamp;						//var float LastRoundTimeStamp;
	UPROPERTY()		int32 PlayTime;									//var int PlayTime;
	UPROPERTY()		FString GameVersion;							//var string GameVersion;
	UPROPERTY()		int32 RoundsPlayed;								//var int RoundsPlayed;
	UPROPERTY()		int32 MissionID;								//var int MissionID;
	UPROPERTY()		int32 TourID;									//var int TourID;
	UPROPERTY()		FString MapName;								//var string MapName;
	UPROPERTY()		int32 ServerMode;								//var int ServerMode;
	UPROPERTY()		int32 Port;										//var int Port;
	UPROPERTY()		FString IP;										//var string IP;
	UPROPERTY()		bool bRoundHasEnded;							//var bool bRoundHasEnded;

	void PostBeginPlay();
	void StatEvent_RoundBegin();
	void StatEvent_RoundEnd();
	void IgnoreStatsThisRound();

};
