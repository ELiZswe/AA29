// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "LevelSummary.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ULevelSummary : public UObject
{
	GENERATED_BODY()
public:
	ULevelSummary();

	UPROPERTY(EditAnywhere)								FString ExtraInfo;						//var() string ExtraInfo;
	UPROPERTY(EditAnywhere)								UMaterial* Screenshot;					//var() Material Screenshot;
	UPROPERTY(EditAnywhere, Category="SinglePlayer")	int32 SinglePlayerTeamSize;				//var(SinglePlayer) int SinglePlayerTeamSize;
	UPROPERTY(EditAnywhere)								bool HideFromMenus;						//var() bool HideFromMenus;
	UPROPERTY(EditAnywhere)								int32 IdealPlayerCountMax;				//var() int IdealPlayerCountMax;
	UPROPERTY(EditAnywhere)								int32 IdealPlayerCountMin;				//var() int IdealPlayerCountMin;
	UPROPERTY(EditAnywhere)								FString DecoTextName;					//var() string DecoTextName;
	UPROPERTY(EditAnywhere)								FString Author;							//var() string Author;
	UPROPERTY(EditAnywhere)								FString LevelEnterText;					//var() localized string LevelEnterText;
	UPROPERTY(EditAnywhere)								FString Description;					//var() localized string Description;
	UPROPERTY(EditAnywhere)								FString Title;							//var() localized string Title;
};
