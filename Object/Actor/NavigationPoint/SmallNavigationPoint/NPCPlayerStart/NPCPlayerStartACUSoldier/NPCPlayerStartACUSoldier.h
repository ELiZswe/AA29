// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/NPCPlayerStart/NPCPlayerStart.h"
#include "NPCPlayerStartACUSoldier.generated.h"

class AAGP_Pawn;
class ANPCBaseController;
UCLASS()
class ANPCPlayerStartACUSoldier : public ANPCPlayerStart
{
	GENERATED_BODY()
public:
	ANPCPlayerStartACUSoldier();

	UPROPERTY(EditAnywhere)										FString sDefaultPawnClass;								//var string sDefaultPawnClass;
	UPROPERTY(EditAnywhere)										FString sDefaultMeshName;								//var string sDefaultMeshName;
	UPROPERTY(EditAnywhere, Category = "NPCSkins")				ESoldierFace esfFaceType;								//var(NPCSkins) ESoldierFace esfFaceType;
	UPROPERTY(EditAnywhere, Category = "NPCSkins")				ESoldierPants espPantsType;								//var(NPCSkins) ESoldierPants espPantsType;
	UPROPERTY(EditAnywhere, Category = "NPCSkins")				ESoldierHands eshHandType;								//var(NPCSkins) ESoldierHands eshHandType;
	UPROPERTY(EditAnywhere, Category = "NPCSkins")				ESoldierShirt essShirtType;								//var(NPCSkins) ESoldierShirt essShirtType;
	UPROPERTY()																		TArray<UMaterialInstance*> asRandomSFHandTextures;		//var array<String> asRandomSFHandTextures;
	UPROPERTY()																		TArray<UMaterialInstance*> asRandomSFFaceTextures;		//var array<String> asRandomSFFaceTextures;
	UPROPERTY()																		TArray<UMaterialInstance*> asRandomShirtTextures;		//var array<String> asRandomShirtTextures;
	UPROPERTY()																		TArray<UMaterialInstance*> asRandomHandTextures;		//var array<String> asRandomHandTextures;
	UPROPERTY()																		TArray<UMaterialInstance*> asRandomFaceTextures;		//var array<String> asRandomFaceTextures;
	UPROPERTY(EditAnywhere, Category = "NPCSoldierAttachments")	bool bMedicRucksack;									//var(NPCSoldierAttachments) bool bMedicRucksack;
	UPROPERTY(EditAnywhere, Category = "NPCSoldierAttachments")	ESoldierHeadGear eshgHeadGear;							//var(NPCSoldierAttachments) ESoldierHeadGear eshgHeadGear;
	UPROPERTY(EditAnywhere, Category = "NPCVision")				bool bEnableEyeTracking;								//var(NPCVision) bool bEnableEyeTracking;
	UPROPERTY(EditAnywhere, Category = "NPCACUAudio")			FName nameUserLeavingAudio;								//var(NPCACUAudio) name nameUserLeavingAudio;
	UPROPERTY(EditAnywhere, Category = "NPCACUAudio")			bool bLockPlayerDuringSpeech;							//var(NPCACUAudio) bool bLockPlayerDuringSpeech;
	UPROPERTY(EditAnywhere, Category = "NPCACUAudio")			float fpPlayerDetectionRange;							//var(NPCACUAudio) float fpPlayerDetectionRange;
	UPROPERTY(EditAnywhere, Category = "NPCACUAudio")			float Pitch;											//var(NPCACUAudio) float Pitch;
	UPROPERTY(EditAnywhere, Category = "NPCACUAudio")			float Radius;											//var(NPCACUAudio) float Radius;
	UPROPERTY(EditAnywhere, Category = "NPCACUAudio")			float Volume;											//var(NPCACUAudio) float Volume;
	UPROPERTY(EditAnywhere, Category = "NPCACUAudio")			TArray<FName> anameRecruiterLipSynchAudio;				//var(NPCACUAudio) array<name> anameRecruiterLipSynchAudio;

	AAGP_Pawn* GetPawnSpawnClass();
	void CustomCreation(ANPCBaseController* npbcController, AAGP_Pawn* agpPawn);
	void ConfigurePawn(ANPCBaseController* npbcController, AAGP_Pawn* agpPawnNew);
	void ConfigureRandomSkins(AAGP_Pawn* agpPawnNew);
};
