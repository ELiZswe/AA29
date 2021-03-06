// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/NPCPlayerStart/NPCPlayerStartRecruiter/NPCPlayerStartRecruiter.h"
#include "NPCPlayerStartRealHero.generated.h"

class AAGP_Pawn;
class ANPCBaseController;
UCLASS()
class ANPCPlayerStartRealHero : public ANPCPlayerStartRecruiter
{
	GENERATED_BODY()
public:
	ANPCPlayerStartRealHero();

	UPROPERTY(EditAnywhere, Category = "NPCRealHero")					float fpVertCollisionOffsetDown;		//var(NPCRealHero) float fpVertCollisionOffsetDown;
	UPROPERTY(EditAnywhere, Category = "NPCRealHeroAudio")				float RHPitch;							//var(NPCRealHeroAudio) float RHPitch;
	UPROPERTY(EditAnywhere, Category = "NPCRealHeroAudio")				float RHRadius;							//var(NPCRealHeroAudio) float RHRadius;
	UPROPERTY(EditAnywhere, Category = "NPCRealHeroAudio")				float bEnableEyeTracRHVolumeking;		//var(NPCRealHeroAudio) float RHVolume;
	UPROPERTY(EditAnywhere, Category = "NPCRealHeroAudio")				TArray<FName> anameRealHeroAudio;		//var(NPCRealHeroAudio) array<name> anameRealHeroAudio;

	void CustomCreation(ANPCBaseController* npbcController, AAGP_Pawn* agpPawn);
};
