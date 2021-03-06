// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/AGP_Character_NPC/NPC_civilian/NPC_civilian.h"
#include "NPC_WoundedPilot.generated.h"

UCLASS()
class ANPC_WoundedPilot : public ANPC_civilian
{
	GENERATED_BODY()
public:
	ANPC_WoundedPilot();

	void DoAnimLoop();
	void AnimateRunning();
	void AnimateSprinting();
	void AnimateCrouchWalking();
	void AnimateWalking();
};
