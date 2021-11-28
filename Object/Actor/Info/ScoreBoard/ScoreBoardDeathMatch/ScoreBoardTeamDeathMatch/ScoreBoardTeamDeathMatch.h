// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/ScoreBoard/ScoreBoardDeathMatch/ScoreBoardDeathMatch.h"
#include "ScoreBoardTeamDeathMatch.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AScoreBoardTeamDeathMatch : public AScoreBoardDeathMatch
{
	GENERATED_BODY()
public:
	AScoreBoardTeamDeathMatch();


	UPROPERTY()						TArray<FColor> TeamColors;							//var Object.Color TeamColors;
	UPROPERTY()						UMaterialInstance* ScoreboardU;						//var Material ScoreboardU;
	UPROPERTY()						UMaterialInstance* FlagIcon;						//var Material FlagIcon;
	UPROPERTY()						UMaterialInstance* ScoreBack;						//var Material ScoreBack;
	UPROPERTY()						UMaterialInstance* TeamBoxMaterial;					//var Material TeamBoxMaterial;



	void UpdatePrecacheMaterials();
	void UpdateScoreBoard(UCanvas* Canvas);
	void DrawTeam(int32 TeamNum, int32 PlayerCount, int32 OwnerOffset, UCanvas* Canvas, int32 FontReduction, int32 BoxSpaceY, int32 PlayerBoxSizeY, int32 HeaderOffsetY);

};
