// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/AGP_Character_NPC/AGP_Character_NPC.h"
#include "NPC_AirborneInstructor.generated.h"

UCLASS()
class ANPC_AirborneInstructor : public AAGP_Character_NPC
{
	GENERATED_BODY()
public:
	ANPC_AirborneInstructor();

	bool IsFriend(APawn* Other);
	void PostBeginPlay();
};
