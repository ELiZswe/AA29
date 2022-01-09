// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Screenplay/Screenplay.h"
#include "USWeaponsScreenplay.generated.h"

UCLASS()
class AUSWeaponsScreenplay : public AScreenplay
{
	GENERATED_BODY()
public:
	AUSWeaponsScreenplay();

	void Init();
};
