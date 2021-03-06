// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/AA2_Info.h"
#include "LandNavScoreManager.generated.h"

UCLASS()
class ALandNavScoreManager : public AAA2_Info
{
	GENERATED_BODY()
public:
	ALandNavScoreManager();

	UPROPERTY()			TArray<int32>	Objectives;							//var int Objectives;

	void SetObjectiveTime(int32 Index, int32 Time);
	int32 GetObjectiveTime(int32 Index);
	int32 GetMaxIndex();
	FString FormatTime(int32 Time);
};
