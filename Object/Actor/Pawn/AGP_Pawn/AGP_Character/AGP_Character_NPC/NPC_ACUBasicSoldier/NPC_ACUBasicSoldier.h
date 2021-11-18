// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/AGP_Character_NPC/AGP_Character_NPC.h"
#include "NPC_ACUBasicSoldier.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ANPC_ACUBasicSoldier : public AAGP_Character_NPC
{
	GENERATED_BODY()
public:
	ANPC_ACUBasicSoldier();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCAudio")		TArray<FName> anameIdleRandomLipSyncAudio;	//var(NPCAudio) array<name> anameIdleRandomLipSyncAudio;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCAudio")		bool bUseLipSynch;							//var(NPCAudio) bool bUseLipSynch;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCAudio")		TArray<USoundBase *> asndIdleRandomAudio;	//var(NPCAudio) array<Sound> asndIdleRandomAudio;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCAudio")		float fpAudioFullVolumeRadius;				//var(NPCAudio) float fpAudioFullVolumeRadius;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCAudio")		bool bTrackPlayer;							//var(EyeTracking) bool bTrackPlayer;
};
