// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Screenplay/Screenplay.h"
#include "LandNavScreenplaySF.generated.h"

UCLASS()
class ALandNavScreenplaySF : public AScreenplay
{
	GENERATED_BODY()
public:
	ALandNavScreenplaySF();

	void Init();
};
