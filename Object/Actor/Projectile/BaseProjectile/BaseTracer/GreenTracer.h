// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Projectile/BaseProjectile/BaseTracer/BaseTracer.h"
#include "GreenTracer.generated.h"

UCLASS()
class AGreenTracer : public ABaseTracer
{
	GENERATED_BODY()
public:
	AGreenTracer(const FObjectInitializer& ObjectInitializer);
};
