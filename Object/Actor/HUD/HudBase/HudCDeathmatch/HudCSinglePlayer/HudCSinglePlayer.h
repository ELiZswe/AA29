// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/HUD/HudBase/HudCDeathmatch/HudCDeathmatch.h"
#include "HudCSinglePlayer.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AHudCSinglePlayer : public AHudCDeathmatch
{
	GENERATED_BODY()
public:
	AHudCSinglePlayer(const FObjectInitializer& ObjectInitializer);

};
