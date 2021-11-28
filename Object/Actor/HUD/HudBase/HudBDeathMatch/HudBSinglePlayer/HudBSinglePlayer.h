// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/HUD/HudBase/HudBDeathMatch/HudBDeathMatch.h"
#include "HudBSinglePlayer.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AHudBSinglePlayer : public AHudBDeathMatch
{
	GENERATED_BODY()
public:
	AHudBSinglePlayer(const FObjectInitializer& ObjectInitializer);

};
