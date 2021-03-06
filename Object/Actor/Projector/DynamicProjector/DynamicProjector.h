// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Projector/Projector.h"
#include "DynamicProjector.generated.h"

UCLASS()
class ADynamicProjector : public AProjector
{
	GENERATED_BODY()
public:
	ADynamicProjector();

	void Tick(float DeltaTime);
};
