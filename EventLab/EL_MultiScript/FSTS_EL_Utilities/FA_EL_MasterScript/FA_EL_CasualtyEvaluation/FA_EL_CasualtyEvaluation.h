// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/EventLab/EL_MultiScript/FSTS_EL_Utilities/FA_EL_MasterScript/FA_EL_MasterScript.h"
#include "FA_EL_CasualtyEvaluation.generated.h"

class AFA_NPC_CasualtyEvalMannequin;
class AFSTS_HelpMarker;

UCLASS()
class AA29_API AFA_EL_CasualtyEvaluation : public AFA_EL_MasterScript
{
	GENERATED_BODY()
public:
	AFA_EL_CasualtyEvaluation();

	UPROPERTY()						AFSTS_HelpMarker* ExtraHelpMarker3;							//var FSTS_HelpMarker ExtraHelpMarker3;
	UPROPERTY()						AFSTS_HelpMarker* ExtraHelpMarker2;							//var FSTS_HelpMarker ExtraHelpMarker2;
	UPROPERTY()						AFSTS_HelpMarker* ExtraHelpMarker1;							//var FSTS_HelpMarker ExtraHelpMarker1;
	UPROPERTY()						AFA_NPC_CasualtyEvalMannequin* Mannequin;					//var FA_NPC_CasualtyEvalMannequin Mannequin;
	UPROPERTY()						bool bLegsChecked;											//var bool bLegsChecked;
	UPROPERTY()						bool bChestChecked;											//var bool bChestChecked;
	UPROPERTY()						bool bHeadChecked;											//var bool bHeadChecked;
	UPROPERTY()						bool bSearchForInjury;										//var bool bSearchForInjury;
};
