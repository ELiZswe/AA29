// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/AGP_Character_NPC/AGP_Character_NPC.h"
#include "NPC_ACUBasicSoldier.generated.h"

UCLASS()
class ANPC_ACUBasicSoldier : public AAGP_Character_NPC
{
	GENERATED_BODY()
public:
	ANPC_ACUBasicSoldier();

	UPROPERTY(EditAnywhere, Category = "EyeTracking")	bool					bTrackPlayer;					//var(EyeTracking) bool bTrackPlayer;
	UPROPERTY(EditAnywhere, Category = "NPCAudio")		float					fpAudioFullVolumeRadius;		//var(NPCAudio) float fpAudioFullVolumeRadius;
	UPROPERTY(EditAnywhere, Category = "NPCAudio")		TArray<USoundBase*>		asndIdleRandomAudio;			//var(NPCAudio) array<Sound> asndIdleRandomAudio;
	UPROPERTY(EditAnywhere, Category = "NPCAudio")		bool					bUseLipSynch;					//var(NPCAudio) bool bUseLipSynch;
	UPROPERTY(EditAnywhere, Category = "NPCAudio")		TArray<FName>			anameIdleRandomLipSyncAudio;	//var(NPCAudio) array<name> anameIdleRandomLipSyncAudio;

	//Mine
	void BeginPlay();

	//Builtin
	void PostBeginPlay();
	void MatchStarting();
	void PostNetBeginPlay();
	void DoAnimLoop();
	bool IsFriend(APawn* Other);
	void LoadSkinsAndMeshes();
	void SetSkinsAndMeshes();
	void Tick(float DeltaTime);
	FRotator NPC_SwapAxes(FRotator R);
	void NPC_EyeTrack(FVector TrackThis, bool useHead);
	void RandomAudioTimer();
};
