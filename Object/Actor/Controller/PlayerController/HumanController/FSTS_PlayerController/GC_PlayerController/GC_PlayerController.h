// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/FSTS_PlayerController/FSTS_PlayerController.h"
#include "GC_PlayerController.generated.h"

UCLASS()
class AA29_API AGC_PlayerController : public AFSTS_PlayerController
{
	GENERATED_BODY()
public:
	AGC_PlayerController();
	
};
