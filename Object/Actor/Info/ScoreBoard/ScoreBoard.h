// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/AA2_Info.h"
#include "ScoreBoard.generated.h"

class AAA2_PlayerState;
class AGameReplicationInfo;

UCLASS()
class AScoreBoard : public AAA2_Info
{
	GENERATED_BODY()
public:
	AScoreBoard();

	UPROPERTY()						AHUD*					OwnerHUD;				//var HUD OwnerHUD;
	UPROPERTY()						UFont*					RegFont;				//var Font RegFont;
	UPROPERTY()						bool					bDisplayMessages;		//var bool bDisplayMessages;
	UPROPERTY(EditAnywhere)			AHUD*					HudClass;				//var() class<HUD> HudClass;
	UPROPERTY(EditAnywhere)			AGameReplicationInfo*	GRI;					//var() GameReplicationInfo GRI;

	void PostBeginPlay();
	UFont* GetSmallerFontFor(UCanvas* Canvas, int32 offset);
	bool HaveHalfFont(UCanvas* Canvas, int32 offset);
	UFont* GetSmallFontFor(int32 ScreenWidth, int32 offset);
	void InitGRI();
	FString InitTitle();
	void Init();
	void DrawScoreboard(UCanvas* C);
	bool UpdateGRI();
	FString FormatTime(int32 Seconds);
	void UpdateScoreBoard(UCanvas* Canvas);
	bool InOrder(AAA2_PlayerState* P1, AAA2_PlayerState* P2);
	void SortPRIArray();
	void ShowScores(UCanvas* Canvas);
	void PreBeginPlay();
	void NextStats();
};
