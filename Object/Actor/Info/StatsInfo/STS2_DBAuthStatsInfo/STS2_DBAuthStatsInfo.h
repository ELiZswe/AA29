// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/StatsInfo/StatsInfo.h"
#include "STS2_DBAuthStatsInfo.generated.h"

UCLASS()
class ASTS2_DBAuthStatsInfo : public AStatsInfo
{
	GENERATED_BODY()
public:
	ASTS2_DBAuthStatsInfo();

	bool Store();
};
