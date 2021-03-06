// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/HUD/HudBase/HudBDeathMatch/HudBDeathMatch.h"
#include "HudBTeamDeathMatch.generated.h"

UCLASS()
class AHudBTeamDeathMatch : public AHudBDeathMatch
{
	GENERATED_BODY()
public:
	AHudBTeamDeathMatch(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(EditAnywhere)		TArray<FNumericWidget>	ScoreTeam;					//var() HudBase.NumericWidget ScoreTeam[2];
	UPROPERTY(EditAnywhere)		FNumericWidget			totalLinks;					//var() HudBase.NumericWidget totalLinks;
	UPROPERTY(EditAnywhere)		FNumericWidget			Score;						//var() HudBase.NumericWidget Score;
	UPROPERTY(EditAnywhere)		TArray<FSpriteWidget>	LTeamHud;					//var() HudBase.SpriteWidget LTeamHud[3];
	UPROPERTY(EditAnywhere)		TArray<FSpriteWidget>	RTeamHud;					//var() HudBase.SpriteWidget RTeamHud[3];
	UPROPERTY(EditAnywhere)		TArray<FSpriteWidget>	TeamSymbols;				//var() HudBase.SpriteWidget TeamSymbols[2];
	UPROPERTY(EditAnywhere)		int32					Links;						//var() int32 Links;
	UPROPERTY(EditAnywhere)		FColor					CarrierTextColor1;			//var() Color CarrierTextColor1;
	UPROPERTY(EditAnywhere)		FColor					CarrierTextColor2;			//var() Color CarrierTextColor2;
	UPROPERTY(EditAnywhere)		FColor					CarrierTextColor3;			//var() Color CarrierTextColor3;
	UPROPERTY(EditAnywhere)		FString					CarriersName;				//var() FString CarriersName;
	UPROPERTY(EditAnywhere)		FString					CarriersLocation;			//var() FString CarriersLocation;
	UPROPERTY(EditAnywhere)		float					CNPosX;						//var() float CNPosX;
	UPROPERTY(EditAnywhere)		float					CNPosY;						//var() float CNPosY;
	UPROPERTY()					FString					LinkEstablishedMessage;		//var localized FString LinkEstablishedMessage;

	void DrawSpectatingHud(UCanvas* C);
	void Tick(float DeltaTime);
	void showLinks();
	void drawLinkText(UCanvas* C);
	void UpdateRankAndSpread(UCanvas* C);
	void DrawHudPassA(UCanvas* C);
	void ShowTeamScorePassA(UCanvas* C);
	void ShowTeamScorePassC(UCanvas* C);
	void TeamScoreOffset();
	void ShowPersonalScore(UCanvas* C);
	void DrawHudPassC(UCanvas* C);
	void UpdateTeamHud();
	void UpdateHUD();
};
