// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/AGP_Character.h"
#include "NPC_Student.generated.h"

UCLASS()
class ANPC_Student : public AAGP_Character
{
	GENERATED_BODY()
public:
	ANPC_Student();

	bool IsFriend(APawn* Other);
};
