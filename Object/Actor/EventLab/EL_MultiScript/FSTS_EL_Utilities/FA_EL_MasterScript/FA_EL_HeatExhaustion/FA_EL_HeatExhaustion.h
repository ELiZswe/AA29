// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/EventLab/EL_MultiScript/FSTS_EL_Utilities/FA_EL_MasterScript/FA_EL_MasterScript.h"
#include "FA_EL_HeatExhaustion.generated.h"

/**
 * 
 */
class AFSTS_HelpMarker;
class AFSTS_HelpMarker;
class AFA_HeatExhaustionRuckSackAttachm;
class AFA_NPC_HeatExhaustionMannequin;
class AFA_RightBootAttachment;
class AFA_LeftBootAttachment;
class AFA_RucksackPickup;
class AFA_CanteenPickup;
class AFA_CanteenPickup;
class AFA_CanvasShadePickup;


UCLASS()
class AA29_API AFA_EL_HeatExhaustion : public AFA_EL_MasterScript
{
	GENERATED_BODY()
public:
	AFA_EL_HeatExhaustion();


	UPROPERTY()						AFSTS_HelpMarker* bInExtraHelpMarker2itialized;						//var FSTS_HelpMarker ExtraHelpMarker2;
	UPROPERTY()						AFSTS_HelpMarker* ExtraHelpMarker1;									//var FSTS_HelpMarker ExtraHelpMarker1;
	UPROPERTY()						AFA_HeatExhaustionRuckSackAttachm* RuckSackAttachment;				//var FA_HeatExhaustionRuckSackAttachment RuckSackAttachment;
	UPROPERTY()						AFA_NPC_HeatExhaustionMannequin* HeatExhaustionMannequin;			//var FA_NPC_HeatExhaustionMannequin HeatExhaustionMannequin;
	UPROPERTY()						AFA_RightBootAttachment* MannequinRightBoot;						//var FA_RightBootAttachment MannequinRightBoot;
	UPROPERTY()						AFA_LeftBootAttachment* MannequinLeftBoot;							//var FA_LeftBootAttachment MannequinLeftBoot;
	UPROPERTY()						AFA_RucksackPickup* RucksackPickup;									//var FA_RucksackPickup RucksackPickup;
	UPROPERTY()						AFA_CanteenPickup* Canteen2;										//var FA_CanteenPickup Canteen2;
	UPROPERTY()						AFA_CanteenPickup* Canteen1;										//var FA_CanteenPickup Canteen1;
	UPROPERTY()						AFA_CanvasShadePickup* CanvasShadePickup;							//var FA_CanvasShadePickup CanvasShadePickup;
	UPROPERTY()						bool bElevateLegs;													//var bool bElevateLegs;
	UPROPERTY()						bool bGetFirstCanteen;												//var bool bGetFirstCanteen;
	UPROPERTY()						EMedicalItemState RucksackState;									//var FA_EL_MasterScript.EMedicalItemState RucksackState;
	UPROPERTY()						EMedicalItemState Canteen2State;									//var FA_EL_MasterScript.EMedicalItemState Canteen2State;
	UPROPERTY()						EMedicalItemState Canteen1State;									//var FA_EL_MasterScript.EMedicalItemState Canteen1State;
	UPROPERTY()						EMedicalItemState CanvasShadeState;									//var FA_EL_MasterScript.EMedicalItemState CanvasShadeState;
	UPROPERTY()						EMedicalItemState LeftBootState;									//var FA_EL_MasterScript.EMedicalItemState LeftBootState;
	UPROPERTY()						EMedicalItemState RightBootState;									//var FA_EL_MasterScript.EMedicalItemState RightBootState;
	UPROPERTY()						EMedicalItemState ShirtState;										//var FA_EL_MasterScript.EMedicalItemState ShirtState;
};
