// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/HUD/HudBase/HudBDeathMatch/HudBTeamDeathMatch/HudBTeamDeathMatch.h"
#include "HudBCaptureTheFlag.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AHudBCaptureTheFlag : public AHudBTeamDeathMatch
{
	GENERATED_BODY()
public:
	AHudBCaptureTheFlag(const FObjectInitializer& ObjectInitializer);

};
