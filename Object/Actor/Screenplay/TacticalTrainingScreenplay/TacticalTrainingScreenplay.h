// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Screenplay/Screenplay.h"
#include "TacticalTrainingScreenplay.generated.h"

UCLASS()
class ATacticalTrainingScreenplay : public AScreenplay
{
	GENERATED_BODY()
public:
	ATacticalTrainingScreenplay();

	void Init();
};
