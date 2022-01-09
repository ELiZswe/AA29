// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Screenplay/Screenplay.h"
#include "SniperRangeScreenplay.generated.h"

UCLASS()
class ASniperRangeScreenplay : public AScreenplay
{
	GENERATED_BODY()
public:
	ASniperRangeScreenplay();

	void Init();
};
