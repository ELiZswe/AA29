// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Info/ScoreBoard/ScoreBoard.h"
#include "AGP_Scoreboard.generated.h"

class AAA2_Playerstate;

UCLASS()
class AA29_API AAGP_Scoreboard : public AScoreBoard
{
	GENERATED_BODY()
public:
	AAGP_Scoreboard();

	UPROPERTY()						float PlayerHeaderPos;				//var float PlayerHeaderPos;
	//UPROPERTY()						AFont* LargeFont;				//var Font LargeFont;
	//UPROPERTY()						AFont* BigFont;					//var Font BigFont;
	//UPROPERTY()						AFont* MedFont;					//var Font MedFont;
	//UPROPERTY()						AFont* SmallFont;				//var Font SmallFont;
	UPROPERTY()						float LastPlayerUpdateTime;			//var float LastPlayerUpdateTime;
	UPROPERTY()						int32 PlayerCount;					//var int PlayerCount;
	UPROPERTY()						FString TieGameMessage;				//var localized string TieGameMessage;
	UPROPERTY()						FString PostGameEndMessage;			//var localized string PostGameEndMessage;
	UPROPERTY()						FString PreGameEndMessage;			//var localized string PreGameEndMessage;
	UPROPERTY()						APlayerController* PlayerOwner;		//var PlayerController PlayerOwner;
	UPROPERTY()						FString MapTitleQuote;				//var localized string MapTitleQuote;
	UPROPERTY()						bool bTimeDown;						//var bool bTimeDown;
	UPROPERTY()						float ScoreStart;					//var float ScoreStart;
	UPROPERTY()						int32 iMaxNameLen;					//var int iMaxNameLen;
	UPROPERTY()						AAA2_PlayerState* Ordered;			//var PlayerReplicationInfo Ordered;
	UPROPERTY()						FColor PurpleColor;					//var Object.Color PurpleColor;
	UPROPERTY()						FColor CyanColor;					//var Object.Color CyanColor;
	UPROPERTY()						FColor LightCyanColor;				//var Object.Color LightCyanColor;
	UPROPERTY()						FColor GoldColor;					//var Object.Color GoldColor;
	UPROPERTY()						FColor WhiteColor;					//var Object.Color WhiteColor;
	UPROPERTY()						FColor GreenColor;					//var Object.Color GreenColor;
	UPROPERTY()						FString FPHString;					//var localized string FPHString;
	UPROPERTY()						FString LossString;					//var localized string LossString;
	UPROPERTY()						FString TimeString;					//var localized string TimeString;
	UPROPERTY()						float PingPos;						//var float PingPos;
	UPROPERTY()						float DeathsPos;					//var float DeathsPos;
	UPROPERTY()						float FragsPos;						//var float FragsPos;
	UPROPERTY()						float TotalPos;						//var float TotalPos;
	UPROPERTY()						float PlayerPos;					//var float PlayerPos;
	UPROPERTY()						float IconPos;						//var float IconPos;
	UPROPERTY()						FString PingString;					//var localized string PingString;
	UPROPERTY()						FString DeathsString;				//var localized string DeathsString;
	UPROPERTY()						FString FragsString;				//var localized string FragsString;
	UPROPERTY()						FString TotalString;				//var localized string TotalString;
	UPROPERTY()						FString PlayerString;				//var localized string PlayerString;
	UPROPERTY()						FString TimeLimit;					//var localized string TimeLimit;
	UPROPERTY()						FString FragGoal;					//var localized string FragGoal;
	UPROPERTY()						FString RemainingTime;				//var localized string RemainingTime;
	UPROPERTY()						FString ElapsedTime;				//var localized string ElapsedTime;
	UPROPERTY()						FString Ended;						//var localized string Ended;
	UPROPERTY()						FString Continue;					//var localized string Continue;
	UPROPERTY()						FString Restart;					//var localized string Restart;
	UPROPERTY()						FString Author;						//var localized string Author;
	UPROPERTY()						FString MapTitle;					//var localized string MapTitle;

	void Destroyed();
	void PostBeginPlay();
	void DrawHeader(UCanvas* Canvas);
	void DrawVictoryConditions(UCanvas* Canvas);
	void TwoDigitString(int32 Num);
	void DrawTrailer(UCanvas* Canvas);
	void DrawCategoryHeaders(UCanvas* Canvas);
	FColor DeterminePlayerColor(AAA2_PlayerState* PRI);
	FString GetPlayerName(AAA2_Playerstate* namePRI, UCanvas* Canvas);
	FString VerifyPlayerName(UCanvas* Canvas, FString PlayerName, FString squadtag, float scorewidth);
	void DrawNameAndPing(UCanvas* Canvas, AAA2_Playerstate* PRI, float XOffset, float YOffset);
	int32 CompareScores(AAA2_Playerstate* PRI1, AAA2_Playerstate* PRI2);
	void SortScores(int32 N);
	void UpdatePlayerList();
	void ShowScores(UCanvas* Canvas);
	void UseSmallFont(UCanvas* Canvas);
	void UseMediumFont(UCanvas* Canvas);
	void UseLargeFont(UCanvas* Canvas);
	void UseHugeFont(UCanvas* Canvas);
	void GetOrdered(int32 i);
};
