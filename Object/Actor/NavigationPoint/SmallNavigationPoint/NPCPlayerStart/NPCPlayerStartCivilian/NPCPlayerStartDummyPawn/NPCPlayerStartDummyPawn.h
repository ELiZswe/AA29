// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/NPCPlayerStart/NPCPlayerStartCivilian/NPCPlayerStartCivilian.h"
#include "NPCPlayerStartDummyPawn.generated.h"

class AAGP_Pawn;
class ANPCBaseController;
UCLASS()
class ANPCPlayerStartDummyPawn : public ANPCPlayerStartCivilian
{
	GENERATED_BODY()
public:
	ANPCPlayerStartDummyPawn();

	AAGP_Pawn* GetPawnSpawnClass();
	void CustomCreation(ANPCBaseController* npbcController, AAGP_Pawn* agpPawn);
};
