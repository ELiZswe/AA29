// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/FSTS_Pawn/FSTS_NPC_Mannequin.h"
#include "FA_NPC_HeatExhaustionMannequin.generated.h"

class AFA_LeftBootAttachment;
class AFA_RightBootAttachment;
class AFA_EL_HeatExhaustion;

UCLASS()
class AFA_NPC_HeatExhaustionMannequin : public AFSTS_NPC_Mannequin
{
	GENERATED_BODY()
public:
	AFA_NPC_HeatExhaustionMannequin();

	UPROPERTY()			AFA_LeftBootAttachment*		LeftBoot;					//var FA_LeftBootAttachment LeftBoot;
	UPROPERTY()			AFA_RightBootAttachment*	RightBoot;					//var FA_RightBootAttachment RightBoot;
	UPROPERTY()			UMaterialInstance*			AlternateChestTexture;		//var Texture AlternateChestTexture;
	UPROPERTY()			UMaterialInstance*			AlternateChestTexture2;		//var Shader AlternateChestTexture2;
	UPROPERTY()			AFA_EL_HeatExhaustion*		HE_EL_Lab;					//var FA_EL_HeatExhaustion HE_EL_Lab;

	void PostBeginPlay();
	void AnimateStanding();
	void RaiseLegs();
	void SwitchChestTextures();
	void SwitchChestTextures2();
	void Reset();
};
