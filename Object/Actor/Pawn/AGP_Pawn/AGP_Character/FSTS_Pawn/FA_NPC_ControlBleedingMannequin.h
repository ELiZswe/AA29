// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/FSTS_Pawn/FSTS_NPC_Mannequin.h"
#include "FA_NPC_ControlBleedingMannequin.generated.h"

UCLASS()
class AFA_NPC_ControlBleedingMannequin : public AFSTS_NPC_Mannequin
{
	GENERATED_BODY()
public:
	AFA_NPC_ControlBleedingMannequin();
	
	UPROPERTY()		UMaterialInstance*	AlternateFaceTexture;		//var Texture AlternateFaceTexture;

	void AnimateStanding();
	void SwitchHeadTextures();
	void Reset();
};
