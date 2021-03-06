// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/HUD/HudBase/HudCDeathmatch/HudCDeathmatch.h"
#include "AA29/AA29.h"
#include "HudCTeamDeathMatch.generated.h"

UCLASS()
class AHudCTeamDeathMatch : public AHudCDeathmatch
{
	GENERATED_BODY()
public:
	AHudCTeamDeathMatch(const FObjectInitializer& ObjectInitializer);

	UPROPERTY()		TArray<FNumericWidget>		ScoreTeam;					//var() HudBase.NumericWidget ScoreTeam[2];
	UPROPERTY()		FNumericWidget				totalLinks;					//var() HudBase.NumericWidget totalLinks;
	UPROPERTY()		FSpriteWidget				VersusSymbol;				//var() HudBase.SpriteWidget VersusSymbol;
	UPROPERTY()		TArray<FSpriteWidget>		TeamScoreBackGround;		//var() HudBase.SpriteWidget TeamScoreBackGround[2];
	UPROPERTY()		TArray<FSpriteWidget>		TeamScoreBackGroundDisc;	//var() HudBase.SpriteWidget TeamScoreBackGroundDisc[2];
	UPROPERTY()		FSpriteWidget				LinkIcon;					//var() HudBase.SpriteWidget LinkIcon;
	UPROPERTY()		TArray<FSpriteWidget>		TeamSymbols;				//var() HudBase.SpriteWidget TeamSymbols[2];
	UPROPERTY()		int32						Links;						//var() int32 Links;
	UPROPERTY()		FColor						CarrierTextColor1;			//var() Color CarrierTextColor1;
	UPROPERTY()		FColor						CarrierTextColor2;			//var() Color CarrierTextColor2;
	UPROPERTY()		FColor						CarrierTextColor3;			//var() Color CarrierTextColor3;
	UPROPERTY()		FString						CarriersName;				//var() FString CarriersName;
	UPROPERTY()		FString						CarriersLocation;			//var() FString CarriersLocation;
	UPROPERTY()		float						CNPosX;						//var() float CNPosX;
	UPROPERTY()		float						CNPosY;						//var() float CNPosY;
	UPROPERTY()		FString						LinkEstablishedMessage;		//var localized FString LinkEstablishedMessage;

	void DrawSpectatingHud(UCanvas* C);
	void Tick(float DeltaTime);
	void showLinks();
	void drawLinkText(UCanvas* C);
	void UpdateRankAndSpread(UCanvas* C);
	void DrawTeamOverlay(UCanvas* C);
	void DrawMyScore(UCanvas* C);
	void DrawHudPassA(UCanvas* C);
	void ShowTeamScorePassA(UCanvas* C);
	void ShowVersusIcon(UCanvas* C);
	void ShowTeamScorePassC(UCanvas* C);
	void TeamScoreOffset();
	void DrawHudPassC(UCanvas* C);
	void UpdateTeamHud();
	void UpdateHUD();
	bool CustomHUDColorAllowed();
};
