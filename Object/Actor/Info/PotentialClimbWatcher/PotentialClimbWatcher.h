// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/AA2_Info.h"
#include "PotentialClimbWatcher.generated.h"

UCLASS()
class APotentialClimbWatcher : public AAA2_Info
{
	GENERATED_BODY()
public:
	APotentialClimbWatcher();
	
	void Tick(float DeltaTime);
};
