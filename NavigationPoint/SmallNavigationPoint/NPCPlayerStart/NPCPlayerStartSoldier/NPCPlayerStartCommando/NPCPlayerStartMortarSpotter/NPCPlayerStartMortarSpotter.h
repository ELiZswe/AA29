// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/NavigationPoint/SmallNavigationPoint/NPCPlayerStart/NPCPlayerStartSoldier/NPCPlayerStartCommando/NPCPlayerStartCommando.h"
#include "NPCPlayerStartMortarSpotter.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ANPCPlayerStartMortarSpotter : public ANPCPlayerStartCommando
{
	GENERATED_BODY()
public:
	ANPCPlayerStartMortarSpotter();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCMortarSpotter")		bool bSmokeAssaultLocation;							//var(NPCMortarSpotter) bool bSmokeAssaultLocation;
};
