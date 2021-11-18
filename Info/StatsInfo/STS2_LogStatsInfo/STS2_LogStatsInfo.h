// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Info/StatsInfo/StatsInfo.h"
#include "STS2_LogStatsInfo.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ASTS2_LogStatsInfo : public AStatsInfo
{
	GENERATED_BODY()
public:
	ASTS2_LogStatsInfo();


	void IgnoreStatsThisRound();
	bool Store();
};
