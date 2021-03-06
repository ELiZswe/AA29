// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/NPCPlayerStart/NPCPlayerStartSoldier/NPCPlayerStartSoldier.h"
#include "NPCPlayerStartCommando.generated.h"

class AAGP_Pawn;

class ANPCBaseController;
UCLASS()
class ANPCPlayerStartCommando : public ANPCPlayerStartSoldier
{
	GENERATED_BODY()
public:
	ANPCPlayerStartCommando();

	UPROPERTY(EditAnywhere, Category = "NPCCommandoAttachments")		bool bAttachCommandoKnife;							//var(NPCCommandoAttachments) bool bAttachCommandoKnife;
	UPROPERTY(EditAnywhere, Category = "NPCCommandoAttachments")		ECommandoHeadGear echgHeadGear;						//var(NPCCommandoAttachments) ECommandoHeadGear echgHeadGear;

	AAGP_Pawn* GetPawnSpawnClass();
	void ConfigurePawn(ANPCBaseController* npbcController, AAGP_Pawn* agpPawnNew);
};
