// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Screenplay/Screenplay.h"
#include "LandNavScreenplay.generated.h"

UCLASS()
class ALandNavScreenplay : public AScreenplay
{
	GENERATED_BODY()
public:
	ALandNavScreenplay();

	void Init();
};
