// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/PlayerStart/AGP_PlayerStart/AGP_PlayerStart.h"
#include "ClassGrenadierPS.generated.h"

UCLASS()
class AClassGrenadierPS : public AAGP_PlayerStart
{
	GENERATED_BODY()
public:
	AClassGrenadierPS(const FObjectInitializer& ObjectInitializer);
	
};
