// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/NPCPlayerStart/NPCPlayerStartRecruiter/NPCPlayerStartRecruiter.h"
#include "NPCPlayerStartRealHero.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ANPCPlayerStartRealHero : public ANPCPlayerStartRecruiter
{
	GENERATED_BODY()
public:
	ANPCPlayerStartRealHero();


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCRealHeroAudio")				float fpVertCollisionOffsetDown;		//var(NPCRealHero) float fpVertCollisionOffsetDown;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCRealHeroAudio")				float RHPitch;							//var(NPCRealHeroAudio) float RHPitch;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCRealHeroAudio")				float RHRadius;							//var(NPCRealHeroAudio) float RHRadius;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCRealHeroAudio")				float bEnableEyeTracRHVolumeking;		//var(NPCRealHeroAudio) float RHVolume;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCRealHeroAudio")				TArray<FName> anameRealHeroAudio;		//var(NPCRealHeroAudio) array<name> anameRealHeroAudio;
};
