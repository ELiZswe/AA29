// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Screenplay/Screenplay.h"
#include "SniperRangeM82Screenplay.generated.h"

UCLASS()
class ASniperRangeM82Screenplay : public AScreenplay
{
	GENERATED_BODY()
public:
	ASniperRangeM82Screenplay();

	void Init();
};
