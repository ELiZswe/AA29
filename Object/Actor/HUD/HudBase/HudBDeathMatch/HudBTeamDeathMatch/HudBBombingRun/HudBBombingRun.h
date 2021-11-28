// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/HUD/HudBase/HudBDeathMatch/HudBTeamDeathMatch/HudBTeamDeathMatch.h"
#include "HudBBombingRun.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AHudBBombingRun : public AHudBTeamDeathMatch
{
	GENERATED_BODY()
public:
	AHudBBombingRun(const FObjectInitializer& ObjectInitializer);

};
