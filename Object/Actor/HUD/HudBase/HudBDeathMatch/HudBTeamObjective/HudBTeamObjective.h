// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/HUD/HudBase/HudBDeathMatch/HudBDeathMatch.h"
#include "HudBTeamObjective.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AHudBTeamObjective : public AHudBDeathMatch
{
	GENERATED_BODY()
public:
	AHudBTeamObjective(const FObjectInitializer& ObjectInitializer);

};
