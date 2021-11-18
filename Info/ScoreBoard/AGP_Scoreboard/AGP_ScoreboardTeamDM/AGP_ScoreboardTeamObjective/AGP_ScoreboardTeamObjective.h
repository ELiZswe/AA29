// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Info/ScoreBoard/AGP_Scoreboard/AGP_ScoreboardTeamDM/AGP_ScoreboardTeamDM.h"
#include "AGP_ScoreboardTeamObjective.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AAGP_ScoreboardTeamObjective : public AAGP_ScoreboardTeamDM
{
	GENERATED_BODY()
public:
	AAGP_ScoreboardTeamObjective();

	UPROPERTY()			float LeaderPos;					//var float LeaderPos;
	UPROPERTY()			float ObjPos;						//var float ObjPos;
	UPROPERTY()			FString LeaderString;				//var localized string LeaderString;
	UPROPERTY()			FString ObjString;					//var localized string ObjString;


	void DrawCategoryHeaders(UCanvas* Canvas);
	void DrawNameAndPing(UCanvas* Canvas, AAA2_PlayerState* PRI, float XOffset, float YOffset);
	int32 CompareScores(AAA2_PlayerState* PRI1, AAA2_PlayerState* PRI2);
};
