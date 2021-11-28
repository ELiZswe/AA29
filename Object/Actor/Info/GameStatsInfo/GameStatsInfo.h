// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/AA2_Info.h"
#include "GameStatsInfo.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AGameStatsInfo : public AAA2_Info
{
	GENERATED_BODY()
public:
	AGameStatsInfo();

	void Aggregate();
	void IgnoreStatsThisRound();
	void StatEvent_RoundBegin();
	void StatEvent_RoundEnd();
};
