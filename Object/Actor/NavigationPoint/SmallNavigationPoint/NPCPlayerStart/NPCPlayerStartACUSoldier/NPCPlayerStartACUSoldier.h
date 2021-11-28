// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/NPCPlayerStart/NPCPlayerStart.h"
#include "NPCPlayerStartACUSoldier.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ANPCPlayerStartACUSoldier : public ANPCPlayerStart
{
	GENERATED_BODY()
public:
	ANPCPlayerStartACUSoldier();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)										FString sDefaultPawnClass;							//var string sDefaultPawnClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)										FString sDefaultMeshName;							//var string sDefaultMeshName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCSkins")				ESoldierFace esfFaceType;							//var(NPCSkins) ESoldierFace esfFaceType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCSkins")				ESoldierPants espPantsType;							//var(NPCSkins) ESoldierPants espPantsType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCSkins")				ESoldierHands eshHandType;							//var(NPCSkins) ESoldierHands eshHandType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCSkins")				ESoldierShirt essShirtType;							//var(NPCSkins) ESoldierShirt essShirtType;
	UPROPERTY()																		TArray<UMaterialInstance*> asRandomSFHandTextures;				//var array<String> asRandomSFHandTextures;
	UPROPERTY()																		TArray<UMaterialInstance*> asRandomSFFaceTextures;				//var array<String> asRandomSFFaceTextures;
	UPROPERTY()																		TArray<UMaterialInstance*> asRandomShirtTextures;				//var array<String> asRandomShirtTextures;
	UPROPERTY()																		TArray<UMaterialInstance*> asRandomHandTextures;				//var array<String> asRandomHandTextures;
	UPROPERTY()																		TArray<UMaterialInstance*> asRandomFaceTextures;				//var array<String> asRandomFaceTextures;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCSoldierAttachments")	bool bMedicRucksack;								//var(NPCSoldierAttachments) bool bMedicRucksack;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCSoldierAttachments")	ESoldierHeadGear eshgHeadGear;						//var(NPCSoldierAttachments) ESoldierHeadGear eshgHeadGear;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCVision")				bool bEnableEyeTracking;							//var(NPCVision) bool bEnableEyeTracking;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCACUAudio")			FName nameUserLeavingAudio;							//var(NPCACUAudio) name nameUserLeavingAudio;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCACUAudio")			bool bLockPlayerDuringSpeech;						//var(NPCACUAudio) bool bLockPlayerDuringSpeech;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCACUAudio")			float fpPlayerDetectionRange;						//var(NPCACUAudio) float fpPlayerDetectionRange;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCACUAudio")			float Pitch;										//var(NPCACUAudio) float Pitch;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCACUAudio")			float Radius;										//var(NPCACUAudio) float Radius;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCACUAudio")			float Volume;										//var(NPCACUAudio) float Volume;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCACUAudio")			TArray<FName> anameRecruiterLipSynchAudio;				//var(NPCACUAudio) array<name> anameRecruiterLipSynchAudio;

};
