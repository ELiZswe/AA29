// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/NPCPlayerStart/NPCPlayerStart.h"
#include "NPCPlayerStartRecruiter.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ANPCPlayerStartRecruiter : public ANPCPlayerStart
{
	GENERATED_BODY()
public:
	ANPCPlayerStartRecruiter();


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCVision")				bool bEnableEyeTracking;						//var(NPCVision) bool bEnableEyeTracking;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCRecruiterAudio")		FName nameUserLeavingAudio;						//var(NPCRecruiterAudio) name nameUserLeavingAudio;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCRecruiterAudio")		bool bLockPlayerDuringSpeech;					//var(NPCRecruiterAudio) bool bLockPlayerDuringSpeech;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCRecruiterAudio")		float fpPlayerDetectionRange;					//var(NPCRecruiterAudio) float fpPlayerDetectionRange;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCRecruiterAudio")		float Pitch;									//var(NPCRecruiterAudio) float Pitch;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCRecruiterAudio")		float Radius;									//var(NPCRecruiterAudio) float Radius;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCRecruiterAudio")		float Volume;									//var(NPCRecruiterAudio) float Volume;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCRecruiterAudio")		TArray<FName> anameRecruiterLipSynchAudio;		//var(NPCRecruiterAudio) array<name> anameRecruiterLipSynchAudio;
};
