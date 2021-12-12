// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/EventLab/EL_MultiScript/FSTS_EL_Utilities/FA_EL_MasterScript/FA_EL_MasterScript.h"
#include "FA_EL_SplintFracture.generated.h"

class AFA_NPC_SplintFractureMannequin;
class AFA_SplintAttachment;
class AFA_CravatPadAttachment;
class AFA_CravatAttachment;
class AFA_SplintPickup;
class AFA_RolledCravatPickup;
class AFA_CravatPadPickup;

UCLASS()
class AA29_API AFA_EL_SplintFracture : public AFA_EL_MasterScript
{
	GENERATED_BODY()
public:
	AFA_EL_SplintFracture();

	UPROPERTY()						AFA_NPC_SplintFractureMannequin* Mannequin;					//var FA_NPC_SplintFractureMannequin Mannequin;
	UPROPERTY()						AFA_SplintAttachment* SplintAttachment;						//var FA_SplintAttachment SplintAttachment;
	UPROPERTY()						AFA_CravatPadAttachment* CravatPadAttachment;				//var FA_CravatPadAttachment CravatPadAttachment;
	UPROPERTY()						AFA_CravatAttachment* CravatAttachment;						//var FA_CravatAttachment CravatAttachment;
	UPROPERTY()						AFA_SplintPickup* SplintPickup;								//var FA_SplintPickup SplintPickup;
	UPROPERTY()						AFA_RolledCravatPickup* RolledCravatPickup;					//var FA_RolledCravatPickup RolledCravatPickup;
	UPROPERTY()						AFA_CravatPadPickup* CravatPadPickup;						//var FA_CravatPadPickup CravatPadPickup;
	UPROPERTY()						EMedicalItemState SplintState;								//var FA_EL_MasterScript.EMedicalItemState SplintState;
	UPROPERTY()						EMedicalItemState CravatPadState;							//var FA_EL_MasterScript.EMedicalItemState CravatPadState;
	UPROPERTY()						EMedicalItemState CravatState;								//var FA_EL_MasterScript.EMedicalItemState CravatState;
	UPROPERTY()						bool bTieCravats;											//var bool bTieCravats;

	void PostBeginPlay();
	void PostPostInit();
	void DoReferenceLinking();
	void AssignDrillSergeants(AFSTS_NPC_DrillSergeant* Sergeant);
	void Reset();
	void Destroyed();
	void FFDrillSergeantScold();
	void DrillSergeantMoveOn(AFSTS_NPC_DrillSergeant* Sergeant);
};
