// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/PlayerStart/AGP_PlayerStart/AGP_PlayerStart.h"
#include "ClassPrisonerPS.generated.h"

UCLASS()
class AA29_API AClassPrisonerPS : public AAGP_PlayerStart
{
	GENERATED_BODY()
public:
	AClassPrisonerPS(const FObjectInitializer& ObjectInitializer);

};
