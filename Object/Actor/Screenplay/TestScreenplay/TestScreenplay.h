// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Screenplay/Screenplay.h"
#include "TestScreenplay.generated.h"

UCLASS()
class ATestScreenplay : public AScreenplay
{
	GENERATED_BODY()
public:
	ATestScreenplay();

	void Init();
};
