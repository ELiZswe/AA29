// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/NPCPlayerStart/NPCPlayerStartRecruiter/NPCPlayerStartRecruiter.h"
#include "NPCPlayerStartVAERecruiter.generated.h"

class AAGP_Pawn;
class ANPCBaseController;
UCLASS()
class ANPCPlayerStartVAERecruiter : public ANPCPlayerStartRecruiter
{
	GENERATED_BODY()
public:
	ANPCPlayerStartVAERecruiter();


	UPROPERTY(EditAnywhere, Category = "NPCVAERecruiter")				FName			nameVAEBlockingNPC;				//var(NPCVAERecruiter) name nameVAEBlockingNPC;
	UPROPERTY(EditAnywhere, Category = "NPCVAERecruiter")				bool			bGivesLanyards;					//var(NPCVAERecruiter) bool bGivesLanyards;
	UPROPERTY(EditAnywhere, Category = "NPCVAERecruiter")				float			fpVertCollisionOffsetDown;		//var(NPCVAERecruiter) float fpVertCollisionOffsetDown;
	UPROPERTY(EditAnywhere, Category = "NPCRealHeroAudio")				float			RHPitch;						//var(NPCVAERecruiterAudio) float RHPitch;
	UPROPERTY(EditAnywhere, Category = "NPCRealHeroAudio")				float			RHRadius;						//var(NPCVAERecruiterAudio) float RHRadius;
	UPROPERTY(EditAnywhere, Category = "NPCRealHeroAudio")				float			RHVolume;						//var(NPCVAERecruiterAudio) float RHVolume;
	UPROPERTY(EditAnywhere, Category = "NPCRealHeroAudio")				TArray<FName>	anameRealHeroAudio;				//var(NPCVAERecruiterAudio) array<name> anameRealHeroAudio;

	void CustomCreation(ANPCBaseController* npbcController, AAGP_Pawn* agpPawn);
	void ConfigurePawn(ANPCBaseController* npbcController, AAGP_Pawn* agpPawnNew);
};
