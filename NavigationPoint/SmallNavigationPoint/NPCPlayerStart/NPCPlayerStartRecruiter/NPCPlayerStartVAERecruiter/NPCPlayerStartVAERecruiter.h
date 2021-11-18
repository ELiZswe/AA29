// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/NavigationPoint/SmallNavigationPoint/NPCPlayerStart/NPCPlayerStartRecruiter/NPCPlayerStartRecruiter.h"
#include "NPCPlayerStartVAERecruiter.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ANPCPlayerStartVAERecruiter : public ANPCPlayerStartRecruiter
{
	GENERATED_BODY()
public:
	ANPCPlayerStartVAERecruiter();


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCRealHeroAudio")				FName nameVAEBlockingNPC;					//var(NPCVAERecruiter) name nameVAEBlockingNPC;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCRealHeroAudio")				bool bGivesLanyards;						//var(NPCVAERecruiter) bool bGivesLanyards;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCRealHeroAudio")				float fpVertCollisionOffsetDown;			//var(NPCVAERecruiter) float fpVertCollisionOffsetDown;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCRealHeroAudio")				float RHPitch;								//var(NPCVAERecruiterAudio) float RHPitch;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCRealHeroAudio")				float RHRadius;								//var(NPCVAERecruiterAudio) float RHRadius;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCRealHeroAudio")				float RHVolume;								//var(NPCVAERecruiterAudio) float RHVolume;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCRealHeroAudio")				TArray<FName> anameRealHeroAudio;			//var(NPCVAERecruiterAudio) array<name> anameRealHeroAudio;
};
