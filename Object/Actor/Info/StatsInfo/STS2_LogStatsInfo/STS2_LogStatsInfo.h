// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/StatsInfo/StatsInfo.h"
#include "STS2_LogStatsInfo.generated.h"

UCLASS()
class ASTS2_LogStatsInfo : public AStatsInfo
{
	GENERATED_BODY()
public:
	ASTS2_LogStatsInfo();


	void IgnoreStatsThisRound();
	bool Store();
};
