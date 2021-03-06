// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/NPCPlayerStart/NPCPlayerStart.h"
#include "NPCPlayerStartRecruiter.generated.h"

class AAGP_Pawn;
class ANPCBaseController;
UCLASS()
class ANPCPlayerStartRecruiter : public ANPCPlayerStart
{
	GENERATED_BODY()
public:
	ANPCPlayerStartRecruiter();

	UPROPERTY(EditAnywhere, Category = "NPCVision")				bool			bEnableEyeTracking;				//var(NPCVision) bool bEnableEyeTracking;
	UPROPERTY(EditAnywhere, Category = "NPCRecruiterAudio")		FName			nameUserLeavingAudio;			//var(NPCRecruiterAudio) name nameUserLeavingAudio;
	UPROPERTY(EditAnywhere, Category = "NPCRecruiterAudio")		bool			bLockPlayerDuringSpeech;		//var(NPCRecruiterAudio) bool bLockPlayerDuringSpeech;
	UPROPERTY(EditAnywhere, Category = "NPCRecruiterAudio")		float			fpPlayerDetectionRange;			//var(NPCRecruiterAudio) float fpPlayerDetectionRange;
	UPROPERTY(EditAnywhere, Category = "NPCRecruiterAudio")		float			Pitch;							//var(NPCRecruiterAudio) float Pitch;
	UPROPERTY(EditAnywhere, Category = "NPCRecruiterAudio")		float			Radius;							//var(NPCRecruiterAudio) float Radius;
	UPROPERTY(EditAnywhere, Category = "NPCRecruiterAudio")		float			Volume;							//var(NPCRecruiterAudio) float Volume;
	UPROPERTY(EditAnywhere, Category = "NPCRecruiterAudio")		TArray<FName>	anameRecruiterLipSynchAudio;	//var(NPCRecruiterAudio) array<name> anameRecruiterLipSynchAudio;

	void CustomCreation(ANPCBaseController* npbcController, AAGP_Pawn* agpPawn);
	void ConfigurePawn(ANPCBaseController* npbcController, AAGP_Pawn* agpPawnNew);
};
