// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29\NavigationPoint/SmallNavigationPoint/NPCPlayerStart/NPCPlayerStart.h"
#include "NPCPlayerStartCivilian.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ANPCPlayerStartCivilian : public ANPCPlayerStart
{
	GENERATED_BODY()
public:
	ANPCPlayerStartCivilian();


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCPawnOptions")			ECivMeshType cmtMeshType;								//var(NPCPawnOptions) CivMeshType cmtMeshType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCAudio")					float fpMinTimeBetweenAudio;							//var(NPCAudio) float fpMinTimeBetweenAudio;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCAudio")					TArray<UTexture2D*> anameWounded;						//var(NPCAudio) array<name> anameWounded;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCAudio")					TArray<UTexture2D*> anameFrightened;					//var(NPCAudio) array<name> anameFrightened;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCAudio")					TArray<UTexture2D*> anameAcknowledgeOrderNegative;		//var(NPCAudio) array<name> anameAcknowledgeOrderNegative;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCAudio")					TArray<UTexture2D*> anameAcknowledgeOrderPositive;		//var(NPCAudio) array<name> anameAcknowledgeOrderPositive;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCAudio")					TArray<FName> anameWaitForNPC;							//var(NPCAudio) array<name> anameWaitForNPC;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCAudio")					TArray<FName> anameCannotFollow;						//var(NPCAudio) array<name> anameCannotFollow;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCAudio")					TArray<FName> anameSeePlayer;							//var(NPCAudio) array<name> anameSeePlayer;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCPawnOptions")			UTexture2D* setHair;									//var(NPCPawnOptions) Material setHair;
	UPROPERTY()																			TArray<UMaterialInstance*> asRandomShirtTextures;		//var array<String> asRandomShirtTextures;
	UPROPERTY()																			TArray<UMaterialInstance*> asRandomPantTextures;		//var array<String> asRandomPantTextures;
	UPROPERTY()																			TArray<UMaterialInstance*> asRandomHandTextures;		//var array<String> asRandomHandTextures;
	UPROPERTY()																			TArray<UMaterialInstance*> asRandomFaceTextures;		//var array<String> asRandomFaceTextures;
	UPROPERTY()																			TArray<UMaterialInstance*> asOldRandomShirtTextures;	//var array<String> asOldRandomShirtTextures;
	UPROPERTY()																			TArray<UMaterialInstance*> asOldRandomPantTextures;		//var array<String> asOldRandomPantTextures;
	UPROPERTY()																			TArray<UMaterialInstance*> asOldRandomHandTextures;		//var array<String> asOldRandomHandTextures;
	UPROPERTY()																			TArray<UMaterialInstance*> asOldRandomFaceTextures;		//var array<String> asOldRandomFaceTextures;
	UPROPERTY()																			FString sDefaultPawnClass;								//var string sDefaultPawnClass;
	UPROPERTY()																			FString sDefaultMeshName;								//var string sDefaultMeshName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCHealed")					float fpAnimationDelayAfterHealing;						//var(NPCHealed) float fpAnimationDelayAfterHealing;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCHealed")					bool bStandAfterHealing;								//var(NPCHealed) bool bStandAfterHealing;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCHealed")					FName namePostHealedEvent;								//var(NPCHealed) name namePostHealedEvent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCHealed")					TArray<USoundBase*> asndPreHealingAudio;				//var(NPCHealed) array<Sound> asndPreHealingAudio;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCHealed")					TArray<USoundBase*> asndPostHealingAudio;				//var(NPCHealed) array<Sound> asndPostHealingAudio;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCHealed")					FName namePostHealingAnimation;							//var(NPCHealed) name namePostHealingAnimation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCHealed")					FName nameInitialInjuredAnimation;						//var(NPCHealed) name nameInitialInjuredAnimation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCHealed")					bool bMustBeHealedToCommand;							//var(NPCHealed) bool bMustBeHealedToCommand;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCHealed")					bool bStartsInjured;									//var(NPCHealed) bool bStartsInjured;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCHealed")					float fpDistanceToTriggerPreHealingAudio;				//var(NPCHealed) float fpDistanceToTriggerPreHealingAudio;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCCivilianAttachments")	bool bSunglasses;										//var(NPCCivilianAttachments) bool bSunglasses;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCSkins")					bool bUseRandomSkins;									//var(NPCSkins) bool bUseRandomSkins;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCNavigation")				float fpFollowDistance;									//var(NPCNavigation) float fpFollowDistance;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPCNavigation")				bool bShouldFollowUser;									//var(NPCNavigation) bool bShouldFollowUser;
};
