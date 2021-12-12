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

	//UPROPERTY()			EMedicalItemState				SplintState;					//var Enum EMedicalItemState SplintState
	//UPROPERTY()			EMedicalItemState				CravatPadState;					//var Enum EMedicalItemState CravatPadState
	//UPROPERTY()			EMedicalItemState				CravatState;					//var Enum EMedicalItemState CravatState
	//UPROPERTY()			EMedicalItemState				Canteen1State;					//var Enum EMedicalItemState Canteen1State
	//UPROPERTY()			EMedicalItemState				Canteen2State;					//var Enum EMedicalItemState Canteen2State
	//UPROPERTY()			EMedicalItemState				ETDState;						//var Enum EMedicalItemState ETDState
	//UPROPERTY()			EMedicalItemState				CATState;						//var Enum EMedicalItemState CATState
	//UPROPERTY()			EMedicalItemState				RucksackState;					//var Enum EMedicalItemState RucksackState
	//UPROPERTY()			EMedicalItemState				LeftBootState;					//var Enum EMedicalItemState LeftBootState
	//UPROPERTY()			EMedicalItemState				RightBootState;					//var Enum EMedicalItemState RightBootState
	//UPROPERTY()			EMedicalItemState				ShirtState;						//var Enum EMedicalItemState ShirtState
	//UPROPERTY()			EMedicalItemState				CanvasShadeState;				//var Enum EMedicalItemState CanvasShadeState
	UPROPERTY()			bool							bLockWeaponPosition;			//var bool bLockWeaponPosition;
	UPROPERTY()			bool							bFriendlyFireFailure;			//var bool bFriendlyFireFailure;
	UPROPERTY()			AFA_EL_MasterScript*			FAMasterScript;					//var FA_EL_MasterScript FAMasterScript;
	UPROPERTY()			AFA_EL_CasualtyEvaluation*		Station1;						//var FA_EL_CasualtyEvaluation Station1;
	UPROPERTY()			AFA_EL_LowCrawlUnderFire*		Station2;						//var FA_EL_LowCrawlUnderFire Station2;
	UPROPERTY()			AFA_EL_BleedingControl*			Station3;						//var FA_EL_BleedingControl Station3;
	UPROPERTY()			AFA_EL_SplintFracture*			Station4;						//var FA_EL_SplintFracture Station4;
	UPROPERTY()			AFA_EL_Ambush*					Station5;						//var FA_EL_Ambush Station5;
	UPROPERTY()			AFA_EL_HeatExhaustion*			Station6;						//var FA_EL_HeatExhaustion Station6;
	UPROPERTY()			int32							TeleportStationID;				//var int TeleportStationID;
	UPROPERTY()			AFA_NPC_DS_Koch*				DS_Koch;						//var FA_NPC_DS_Koch DS_Koch;
	UPROPERTY()			AFA_NPC_DS_Moore*				DS_Moore;						//var FA_NPC_DS_Moore DS_Moore;
	UPROPERTY()			AFA_NPC_DS_Acosta*				DS_Acosta;						//var FA_NPC_DS_Acosta DS_Acosta;
	UPROPERTY()			AFA_NPC_DS_Mateo*				DS_Mateo;						//var FA_NPC_DS_Mateo DS_Mateo;
	UPROPERTY()			AFA_NPC_DS_Johnson*				DS_Johnson;						//var FA_NPC_DS_Johnson DS_Johnson;
	UPROPERTY()			AFA_NPC_DS_Kelly*				DS_Kelly;						//var FA_NPC_DS_Kelly DS_Kelly;

	void EventLabTick(float DeltaTime);
	void PostInit();
	void PostPostInit();
	FString GetTrainingMapName();
	void SetMasterScript();
	void CreateCustomLevelScriptsLinks();
	void Reset();
	bool AllowScriptStart(AEL_MultiScript* StationToStart);
	void CheatSkipToStation(int32 StationNum);
	AFA_EL_MasterScript* GetFAActiveScript();
	void DrillSergeantMoveOn(AFSTS_NPC_DrillSergeant* Sergeant);
	bool Volume_Enter(AVolume* NotifyActor, AActor* aInstigator);
	bool Volume_Exit(AVolume* NotifyActor, AActor* aInstigator);
	void DoReferenceLinking();
	void GrenadeExploded(AActor* Grenade, EEventType Event, AActor* aInstigator, FString Parms);
	void SetPlayerWeapon(bool bWeaponUp, bool bSetLockWeaponPosition);
	void MoveDSKochToStation6();
	void MovePlayerToStation(int32 StationID);
	void Destroyed();
	bool AGP_NPC_Damaged(AAGP_NPC* NotifyActor, AController* aInstigator);
	bool Pawn_Damaged(APawn* NotifyActor, AController* aInstigator);
	void FriendlyFire(APawn* HitActor);
	bool AGP_Weapon_Empty(AAGP_Weapon* NotifyActor, AActor* aInstigator, FString Parms);
	void ForceLevelReset();
	void AssignDrillSergeants(AFSTS_NPC_DrillSergeant* Sergeant);
	void MannequinTrace(AActor* HitActor, FBoneInfo HitBone);
	void HandleMedPickup(AActor* HitActor);
	bool LockWeaponPosition();
	void FFDrillSergeantScold();
	void PlayerNoGoAwarded();
};
