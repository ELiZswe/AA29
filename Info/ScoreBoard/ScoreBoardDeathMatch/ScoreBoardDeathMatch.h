// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Info/ScoreBoard/ScoreBoard.h"
#include "ScoreBoardDeathMatch.generated.h"

class AAA2_PlayerState;

UCLASS()
class AA29_API AScoreBoardDeathMatch : public AScoreBoard
{
	GENERATED_BODY()
public:
	AScoreBoardDeathMatch();


	UPROPERTY(EditAnywhere)			UMaterialInstance* BoxMaterial;		//var() Material BoxMaterial;
	UPROPERTY(EditAnywhere)			FString Spacer;						//var() localized string Spacer;
	UPROPERTY(EditAnywhere)			FString TimeLimit;					//var() localized string TimeLimit;
	UPROPERTY(EditAnywhere)			FString Ended;						//var() localized string Ended;
	UPROPERTY(EditAnywhere)			FString Continue;					//var() localized string Continue;
	UPROPERTY(EditAnywhere)			FString Restart;					//var() localized string Restart;
	UPROPERTY(EditAnywhere)			FString MapName;					//var() localized string MapName;
	UPROPERTY(EditAnywhere)			FString GameType;					//var() localized string GameType;
	UPROPERTY(EditAnywhere)			FString FPH;						//var() localized string FPH;
	UPROPERTY(EditAnywhere)			FString FragLimit;					//var() localized string FragLimit;
	UPROPERTY(EditAnywhere)			FString MaxLives;					//var() localized string MaxLives;
	UPROPERTY()						float FPHTime;						//var float FPHTime;
	UPROPERTY()						AAA2_PlayerState* PRIArray;			//var PlayerReplicationInfo PRIArray;
	UPROPERTY()						TArray<FString> SkillLevel;			//var localized string SkillLevel;
	UPROPERTY()						FString NotReadyText;				//var localized string NotReadyText;
	UPROPERTY()						FString ReadyText;					//var localized string ReadyText;
	UPROPERTY()						FString OutFireText;				//var localized string OutFireText;
	UPROPERTY()						FString OutText;					//var localized string OutText;
	UPROPERTY()						FString MatchIDText;				//var localized string MatchIDText;
	UPROPERTY(EditAnywhere)			FString FooterText;					//var() localized string FooterText;
	UPROPERTY(EditAnywhere)			FString NetText;					//var() localized string NetText;
	UPROPERTY(EditAnywhere)			FString AdminText;					//var() localized string AdminText;
	UPROPERTY(EditAnywhere)			FString DeathsText;					//var() localized string DeathsText;
	UPROPERTY(EditAnywhere)			FString PLText;						//var() localized string PLText;
	UPROPERTY(EditAnywhere)			FString PingText;					//var() localized string PingText;
	UPROPERTY(EditAnywhere)			FString TimeText;					//var() localized string TimeText;
	UPROPERTY(EditAnywhere)			FString PointsText;					//var() localized string PointsText;
	UPROPERTY(EditAnywhere)			FString PlayerText;					//var() localized string PlayerText;
	UPROPERTY(EditAnywhere)			FString RankText;					//var() localized string RankText;

	void UpdatePrecacheMaterials();
	void UpdatePrecacheFonts();
	void DrawTitle(UCanvas* Canvas, float HeaderOffsetY, float PlayerAreaY, float PlayerBoxSizeY);
	FString GetTitleString();
	FString GetRestartString();
	FString GetDefaultScoreInfoString();
	void ExtraMarking(UCanvas* Canvas, int32 PlayerCount, int32 OwnerOffset, int32 XPos, int32 YPos, int32 YOffset);
	void UpdateScoreBoard(UCanvas* Canvas);
	void DrawMatchID(UCanvas* Canvas, int32 FontReduction);
	void DrawNetInfo(UCanvas* Canvas, int32 FontReduction, int32 HeaderOffsetY, int32 PlayerBoxSizeY, int32 BoxSpaceY, int32 BoxTextOffsetY, int32 OwnerOffset, int32 PlayerCount, int32 NetXPos);

};
