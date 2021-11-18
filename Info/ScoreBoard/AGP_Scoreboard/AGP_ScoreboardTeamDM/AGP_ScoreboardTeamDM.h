// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Info/ScoreBoard/AGP_Scoreboard/AGP_Scoreboard.h"
#include "AGP_ScoreboardTeamDM.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AAGP_ScoreboardTeamDM : public AAGP_Scoreboard
{
	GENERATED_BODY()
public:
	AAGP_ScoreboardTeamDM();

	//UPROPERTY()			AFont* _fFont;						//var Font _fFont;
	UPROPERTY()			FString FFString;					//var localized string FFString;
	UPROPERTY()			FColor DeadColor;					//var Object.Color DeadColor;
	UPROPERTY()			FColor OpforLeaderColor;			//var Object.Color OpforLeaderColor;
	UPROPERTY()			FColor OpforTeamColor;				//var Object.Color OpforTeamColor;
	UPROPERTY()			FColor ArmyLeaderColor;				//var Object.Color ArmyLeaderColor;
	UPROPERTY()			FColor ArmyTeamColor;				//var Object.Color ArmyTeamColor;
	UPROPERTY()			UMaterialInstance* tBoxFill;		//var Texture tBoxFill;
	UPROPERTY()			UMaterialInstance* tArmyBox;		//var Texture tArmyBox;
	UPROPERTY()			UMaterialInstance* _tRanger;		//var Texture _tRanger;
	UPROPERTY()			UMaterialInstance* _tGroup;			//var Texture _tGroup;
	UPROPERTY()			UMaterialInstance* _tTrust;			//var Texture _tTrust;
	UPROPERTY()			UMaterialInstance* _t2D;			//var Texture _t2D;
	UPROPERTY()			float FFPos;						//var float FFPos;
	UPROPERTY()			float teampos;						//var float teampos;
	UPROPERTY()			FString teamstring;					//var localized string teamstring;


	int32 GetTeamOrVirtualTeam();
	bool NoRealTeam();
	void DrawHeader(UCanvas* Canvas);
	void DrawCategoryHeaders(UCanvas* Canvas);
	FColor DeterminePlayerColor(AAA2_PlayerState* PRI);
	void DrawBox(UCanvas* Canvas, float StartX, float StartY, float boxw, float boxh);
	void DrawLine(UCanvas* Canvas, float StartX, float StartY, float boxw);
	void ShowScores(UCanvas* Canvas);
	void DrawNameAndPing(UCanvas* Canvas, AAA2_PlayerState* PRI, float XOffset, float YOffset);
	int32 CompareScores(AAA2_PlayerState* PRI1, AAA2_PlayerState* PRI2);

};
