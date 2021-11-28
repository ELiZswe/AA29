// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/HUD/HudBase/HudCDeathmatch/HudCTeamDeathMatch/HudCTeamDeathMatch.h"
#include "HudCCaptureTheFlag.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AHudCCaptureTheFlag : public AHudCTeamDeathMatch
{
	GENERATED_BODY()
public:
	AHudCCaptureTheFlag(const FObjectInitializer& ObjectInitializer);

};
