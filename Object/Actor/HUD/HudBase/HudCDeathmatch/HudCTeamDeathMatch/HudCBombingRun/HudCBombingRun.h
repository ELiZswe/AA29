// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/HUD/HudBase/HudCDeathmatch/HudCTeamDeathMatch/HudCTeamDeathMatch.h"
#include "HudCBombingRun.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AHudCBombingRun : public AHudCTeamDeathMatch
{
	GENERATED_BODY()
public:
	AHudCBombingRun(const FObjectInitializer& ObjectInitializer);

};
