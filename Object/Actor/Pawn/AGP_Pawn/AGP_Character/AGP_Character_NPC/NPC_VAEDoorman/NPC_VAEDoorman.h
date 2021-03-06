// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/AGP_Character_NPC/AGP_Character_NPC.h"
#include "NPC_VAEDoorman.generated.h"

UCLASS()
class ANPC_VAEDoorman : public AAGP_Character_NPC
{
	GENERATED_BODY()
public:
	ANPC_VAEDoorman();

	UPROPERTY(EditAnywhere, Category = "LipSincAudio")		FName nameAudioToPlay;			//var(LipSincAudio) name nameAudioToPlay;
	UPROPERTY(EditAnywhere, Category = "LipSincAudio")		float LipSincVolume;			//var(LipSincAudio) float LipSincVolume;
	UPROPERTY()                             				bool bAlreadySpoke;				//var bool bAlreadySpoke;
	UPROPERTY()                             				bool bSpeakOnlyOnce;			//var bool bSpeakOnlyOnce;

	void PostBeginPlay();
	void Touch(AActor* Other);
};
