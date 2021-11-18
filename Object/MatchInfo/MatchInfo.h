// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MatchInfo.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UMatchInfo : public UObject
{
	GENERATED_BODY()
public:
	UMatchInfo();

	UPROPERTY(EditAnywhere)											FString ThumbName;									//var string ThumbName;
	UPROPERTY(EditAnywhere)											FString GameType;									//var string GameType;
	UPROPERTY(EditAnywhere)											int32 NumBots;										//var int NumBots;
	UPROPERTY(EditAnywhere)											FString MenuDescription;							//var string MenuDescription;
	UPROPERTY(EditAnywhere)											FString URLString;									//var string URLString;
	UPROPERTY(EditAnywhere)											float GoalScore;									//var float GoalScore;
	UPROPERTY(EditAnywhere)											float DifficultyModifier;							//var float DifficultyModifier;
	UPROPERTY(EditAnywhere)											FString SpecialEvent;								//var string SpecialEvent;
	UPROPERTY(EditAnywhere)											FString EnemyTeamName;								//var string EnemyTeamName;
	UPROPERTY(EditAnywhere)											FString MenuName;									//var localized string MenuName;
	UPROPERTY(EditAnywhere)											FString LevelName;									//var string LevelName;

};
