// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/PlayerStart/AGP_PlayerStart/AGP_PlayerStart.h"
#include "ClassVIPPS.generated.h"

UCLASS()
class AClassVIPPS : public AAGP_PlayerStart
{
	GENERATED_BODY()
public:
	AClassVIPPS(const FObjectInitializer& ObjectInitializer);

};
