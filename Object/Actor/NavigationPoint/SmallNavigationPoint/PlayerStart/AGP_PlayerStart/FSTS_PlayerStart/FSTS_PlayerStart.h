// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/PlayerStart/AGP_PlayerStart/AGP_PlayerStart.h"
#include "FSTS_PlayerStart.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AFSTS_PlayerStart : public AAGP_PlayerStart
{
	GENERATED_BODY()
public:
	AFSTS_PlayerStart(const FObjectInitializer& ObjectInitializer);

};
