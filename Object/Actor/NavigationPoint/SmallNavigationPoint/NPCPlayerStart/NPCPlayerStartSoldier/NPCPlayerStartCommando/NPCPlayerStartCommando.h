// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/NPCPlayerStart/NPCPlayerStartSoldier/NPCPlayerStartSoldier.h"
#include "NPCPlayerStartCommando.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ANPCPlayerStartCommando : public ANPCPlayerStartSoldier
{
	GENERATED_BODY()
public:
	ANPCPlayerStartCommando();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCCommandoAttachments")		bool bAttachCommandoKnife;							//var(NPCCommandoAttachments) bool bAttachCommandoKnife;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCCommandoAttachments")		ECommandoHeadGear echgHeadGear;						//var(NPCCommandoAttachments) ECommandoHeadGear echgHeadGear;
};
