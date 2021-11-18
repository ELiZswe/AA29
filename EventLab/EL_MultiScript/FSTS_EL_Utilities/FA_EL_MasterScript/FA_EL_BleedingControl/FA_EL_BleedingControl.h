// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/EventLab/EL_MultiScript/FSTS_EL_Utilities/FA_EL_MasterScript/FA_EL_MasterScript.h"
#include "FA_EL_BleedingControl.generated.h"

class AFA_NPC_TraumaDressingMannequin;
class AFA_NPC_ControlBleedingMannequin;
class AFA_RuckSackAttachment; 
class AFA_ETDAttachment;
class AFA_CATAttachment;
class AFA_RucksackPickup;
class AFA_ETDPickup;
class AFA_CATPickup;

UCLASS()
class AA29_API AFA_EL_BleedingControl : public AFA_EL_MasterScript
{
	GENERATED_BODY()
public:
	AFA_EL_BleedingControl();


	UPROPERTY()						AFA_NPC_TraumaDressingMannequin* TraumaMannequin;		//var FA_NPC_TraumaDressingMannequin TraumaMannequin;
	UPROPERTY()						AFA_NPC_ControlBleedingMannequin* AmputatedMannequin;	//var FA_NPC_ControlBleedingMannequin AmputatedMannequin;
	UPROPERTY()						AFA_RuckSackAttachment* RuckSackAttachment;				//var FA_RuckSackAttachment RuckSackAttachment;
	UPROPERTY()						AFA_ETDAttachment* ETDAttachment;						//var FA_ETDAttachment ETDAttachment;
	UPROPERTY()						AFA_CATAttachment* CATAttachment;						//var FA_CATAttachment CATAttachment;
	UPROPERTY()						AFA_RucksackPickup* RucksackPickup;						//var FA_RucksackPickup RucksackPickup;
	UPROPERTY()						AFA_ETDPickup* ETDPickup;								//var FA_ETDPickup ETDPickup;
	UPROPERTY()						AFA_CATPickup* CATPickup;								//var FA_CATPickup CATPickup;
	UPROPERTY()						EMedicalItemState RucksackState;						//var FA_EL_MasterScript.EMedicalItemState RucksackState;
	UPROPERTY()						EMedicalItemState ETDState;								//var FA_EL_MasterScript.EMedicalItemState ETDState;
	UPROPERTY()						EMedicalItemState CATState;								//var FA_EL_MasterScript.EMedicalItemState CATState;
	UPROPERTY()						bool bRaiseTraumaMannequinLeftLeg;						//var bool bRaiseTraumaMannequinLeftLeg;
	UPROPERTY()						bool bApplyCAT;											//var bool bApplyCAT;
	UPROPERTY()						bool bSwapCATHeadTexture;								//var bool bSwapCATHeadTexture;
};
