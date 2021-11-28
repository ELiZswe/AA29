// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/EventLab/EL_MultiScript/FSTS_EL_Utilities/FSTS_EL_Utilities.h"
#include "FA_EL_MasterScript.generated.h"

class AFA_EL_CasualtyEvaluation;
class AFA_EL_LowCrawlUnderFire;
class AFA_EL_BleedingControl;
class AFA_EL_SplintFracture;
class AFA_EL_Ambush;
class AFA_EL_HeatExhaustion;
class AFA_NPC_DS_Koch;
class AFA_NPC_DS_Moore;
class AFA_NPC_DS_Acosta;
class AFA_NPC_DS_Mateo;
class AFA_NPC_DS_Johnson;
class AFA_NPC_DS_Kelly;

UCLASS()
class AA29_API AFA_EL_MasterScript : public AFSTS_EL_Utilities
{
	GENERATED_BODY()
public:
	AFA_EL_MasterScript();


	UPROPERTY()			bool bLockWeaponPosition;					//var bool bLockWeaponPosition;
	UPROPERTY()			bool bFriendlyFireFailure;					//var bool bFriendlyFireFailure;
	UPROPERTY()			AFA_EL_MasterScript* FAMasterScript;		//var FA_EL_MasterScript FAMasterScript;
	UPROPERTY()			AFA_EL_CasualtyEvaluation* Station1;		//var FA_EL_CasualtyEvaluation Station1;
	UPROPERTY()			AFA_EL_LowCrawlUnderFire* Station2;			//var FA_EL_LowCrawlUnderFire Station2;
	UPROPERTY()			AFA_EL_BleedingControl* Station3;			//var FA_EL_BleedingControl Station3;
	UPROPERTY()			AFA_EL_SplintFracture* Station4;			//var FA_EL_SplintFracture Station4;
	UPROPERTY()			AFA_EL_Ambush* Station5;					//var FA_EL_Ambush Station5;
	UPROPERTY()			AFA_EL_HeatExhaustion* Station6;			//var FA_EL_HeatExhaustion Station6;
	UPROPERTY()			int32 TeleportStationID;					//var int TeleportStationID;
	UPROPERTY()			AFA_NPC_DS_Koch* DS_Koch;					//var FA_NPC_DS_Koch DS_Koch;
	UPROPERTY()			AFA_NPC_DS_Moore* DS_Moore;					//var FA_NPC_DS_Moore DS_Moore;
	UPROPERTY()			AFA_NPC_DS_Acosta* DS_Acosta;				//var FA_NPC_DS_Acosta DS_Acosta;
	UPROPERTY()			AFA_NPC_DS_Mateo* DS_Mateo;					//var FA_NPC_DS_Mateo DS_Mateo;
	UPROPERTY()			AFA_NPC_DS_Johnson* DS_Johnson;				//var FA_NPC_DS_Johnson DS_Johnson;
	UPROPERTY()			AFA_NPC_DS_Kelly* DS_Kelly;					//var FA_NPC_DS_Kelly DS_Kelly;

};
