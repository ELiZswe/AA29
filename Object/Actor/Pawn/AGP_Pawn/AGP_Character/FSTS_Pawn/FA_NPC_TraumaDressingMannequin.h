// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/FSTS_Pawn/FSTS_NPC_Mannequin.h"
#include "FA_NPC_TraumaDressingMannequin.generated.h"

class AFA_EL_BleedingControl;

UCLASS()
class AFA_NPC_TraumaDressingMannequin : public AFSTS_NPC_Mannequin
{
	GENERATED_BODY()
public:
	AFA_NPC_TraumaDressingMannequin();


	UPROPERTY()						AFA_EL_BleedingControl*		BC_EL_Lab;			//var FA_EL_BleedingControl BC_EL_Lab;

	void AnimateStanding();
	void RaiseLeftLeg();
	void Destroyed();
};
