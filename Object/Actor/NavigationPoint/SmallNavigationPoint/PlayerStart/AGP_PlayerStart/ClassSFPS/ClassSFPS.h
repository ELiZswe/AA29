// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/PlayerStart/AGP_PlayerStart/AGP_PlayerStart.h"
#include "ClassSFPS.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AClassSFPS : public AAGP_PlayerStart
{
	GENERATED_BODY()
public:
	AClassSFPS(const FObjectInitializer& ObjectInitializer);

};
