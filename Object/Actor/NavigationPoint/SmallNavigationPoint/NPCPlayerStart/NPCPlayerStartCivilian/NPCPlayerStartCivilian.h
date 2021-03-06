// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/NPCPlayerStart/NPCPlayerStart.h"
#include "NPCPlayerStartCivilian.generated.h"

class AAGP_Pawn;
class ANPCBaseController;
UCLASS()
class ANPCPlayerStartCivilian : public ANPCPlayerStart
{
	GENERATED_BODY()
public:
	ANPCPlayerStartCivilian();


	UPROPERTY(EditAnywhere, Category = "NPCPawnOptions")			ECivMeshType cmtMeshType;								//var(NPCPawnOptions) CivMeshType cmtMeshType;
	UPROPERTY(EditAnywhere, Category = "NPCAudio")					float fpMinTimeBetweenAudio;							//var(NPCAudio) float fpMinTimeBetweenAudio;
	UPROPERTY(EditAnywhere, Category = "NPCAudio")					TArray<UTexture2D*> anameWounded;						//var(NPCAudio) array<name> anameWounded;
	UPROPERTY(EditAnywhere, Category = "NPCAudio")					TArray<UTexture2D*> anameFrightened;					//var(NPCAudio) array<name> anameFrightened;
	UPROPERTY(EditAnywhere, Category = "NPCAudio")					TArray<UTexture2D*> anameAcknowledgeOrderNegative;		//var(NPCAudio) array<name> anameAcknowledgeOrderNegative;
	UPROPERTY(EditAnywhere, Category = "NPCAudio")					TArray<UTexture2D*> anameAcknowledgeOrderPositive;		//var(NPCAudio) array<name> anameAcknowledgeOrderPositive;
	UPROPERTY(EditAnywhere, Category = "NPCAudio")					TArray<FName> anameWaitForNPC;							//var(NPCAudio) array<name> anameWaitForNPC;
	UPROPERTY(EditAnywhere, Category = "NPCAudio")					TArray<FName> anameCannotFollow;						//var(NPCAudio) array<name> anameCannotFollow;
	UPROPERTY(EditAnywhere, Category = "NPCAudio")					TArray<FName> anameSeePlayer;							//var(NPCAudio) array<name> anameSeePlayer;
	UPROPERTY(EditAnywhere, Category = "NPCPawnOptions")			UTexture2D* setHair;									//var(NPCPawnOptions) Material setHair;
	UPROPERTY()														TArray<UMaterialInstance*> asRandomShirtTextures;		//var TArray<FString> asRandomShirtTextures;
	UPROPERTY()														TArray<UMaterialInstance*> asRandomPantTextures;		//var TArray<FString> asRandomPantTextures;
	UPROPERTY()														TArray<UMaterialInstance*> asRandomHandTextures;		//var TArray<FString> asRandomHandTextures;
	UPROPERTY()														TArray<UMaterialInstance*> asRandomFaceTextures;		//var TArray<FString> asRandomFaceTextures;
	UPROPERTY()														TArray<UMaterialInstance*> asOldRandomShirtTextures;	//var TArray<FString> asOldRandomShirtTextures;
	UPROPERTY()														TArray<UMaterialInstance*> asOldRandomPantTextures;		//var TArray<FString> asOldRandomPantTextures;
	UPROPERTY()														TArray<UMaterialInstance*> asOldRandomHandTextures;		//var TArray<FString> asOldRandomHandTextures;
	UPROPERTY()														TArray<UMaterialInstance*> asOldRandomFaceTextures;		//var TArray<FString> asOldRandomFaceTextures;
	UPROPERTY()														FString sDefaultPawnClass;								//var string sDefaultPawnClass;
	UPROPERTY()														FString sDefaultMeshName;								//var string sDefaultMeshName;
	UPROPERTY(EditAnywhere, Category = "NPCHealed")					float fpAnimationDelayAfterHealing;						//var(NPCHealed) float fpAnimationDelayAfterHealing;
	UPROPERTY(EditAnywhere, Category = "NPCHealed")					bool bStandAfterHealing;								//var(NPCHealed) bool bStandAfterHealing;
	UPROPERTY(EditAnywhere, Category = "NPCHealed")					FName namePostHealedEvent;								//var(NPCHealed) name namePostHealedEvent;
	UPROPERTY(EditAnywhere, Category = "NPCHealed")					TArray<USoundBase*> asndPreHealingAudio;				//var(NPCHealed) array<Sound> asndPreHealingAudio;
	UPROPERTY(EditAnywhere, Category = "NPCHealed")					TArray<USoundBase*> asndPostHealingAudio;				//var(NPCHealed) array<Sound> asndPostHealingAudio;
	UPROPERTY(EditAnywhere, Category = "NPCHealed")					FName namePostHealingAnimation;							//var(NPCHealed) name namePostHealingAnimation;
	UPROPERTY(EditAnywhere, Category = "NPCHealed")					FName nameInitialInjuredAnimation;						//var(NPCHealed) name nameInitialInjuredAnimation;
	UPROPERTY(EditAnywhere, Category = "NPCHealed")					bool bMustBeHealedToCommand;							//var(NPCHealed) bool bMustBeHealedToCommand;
	UPROPERTY(EditAnywhere, Category = "NPCHealed")					bool bStartsInjured;									//var(NPCHealed) bool bStartsInjured;
	UPROPERTY(EditAnywhere, Category = "NPCHealed")					float fpDistanceToTriggerPreHealingAudio;				//var(NPCHealed) float fpDistanceToTriggerPreHealingAudio;
	UPROPERTY(EditAnywhere, Category = "NPCCivilianAttachments")	bool bSunglasses;										//var(NPCCivilianAttachments) bool bSunglasses;
	UPROPERTY(EditAnywhere, Category = "NPCSkins")					bool bUseRandomSkins;									//var(NPCSkins) bool bUseRandomSkins;
	UPROPERTY(EditAnywhere, Category = "NPCNavigation")				float fpFollowDistance;									//var(NPCNavigation) float fpFollowDistance;
	UPROPERTY(EditAnywhere, Category = "NPCNavigation")				bool bShouldFollowUser;									//var(NPCNavigation) bool bShouldFollowUser;

	AAGP_Pawn* GetPawnSpawnClass();
	void ConfigurePawn(ANPCBaseController* npbcController, AAGP_Pawn* agpPawnNew);
	void ConfigureRandomSkins(AAGP_Pawn* agpPawnNew);
	void CustomCreation(ANPCBaseController* npbcController, AAGP_Pawn* agpPawn);
};
