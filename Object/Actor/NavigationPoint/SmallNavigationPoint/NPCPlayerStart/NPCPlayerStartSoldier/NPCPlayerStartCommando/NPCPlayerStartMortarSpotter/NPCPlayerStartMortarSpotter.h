// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/NPCPlayerStart/NPCPlayerStartSoldier/NPCPlayerStartCommando/NPCPlayerStartCommando.h"
#include "NPCPlayerStartMortarSpotter.generated.h"

class AAGP_Pawn;
class ANPCBaseController;
UCLASS()
class ANPCPlayerStartMortarSpotter : public ANPCPlayerStartCommando
{
	GENERATED_BODY()
public:
	ANPCPlayerStartMortarSpotter();

	UPROPERTY(EditAnywhere, Category = "NPCMortarSpotter")		bool bSmokeAssaultLocation;							//var(NPCMortarSpotter) bool bSmokeAssaultLocation;

	void CustomCreation(ANPCBaseController* npbcController, AAGP_Pawn* agpPawn);
};
