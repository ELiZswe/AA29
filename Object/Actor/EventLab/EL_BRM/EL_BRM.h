// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/EventLab/EventLab.h"
#include "EL_BRM.generated.h"

class AMarker;
class ATargetManager;
class AFSTS_HelpMarker;
class AAGP_Character;
class AAGP_NPC;
class ABRM_HudOverlay;
class AAGP_Objective;

UCLASS()
class AA29_API AEL_BRM : public AEventLab
{
	GENERATED_BODY()
public:
	AEL_BRM();

	UPROPERTY()		AActor*				PlayerSpawnPoint;			//var Actor PlayerSpawnPoint;
	UPROPERTY()		AMarker*			FiringPosition;				//var Marker FiringPosition;
	UPROPERTY()		ATargetManager*		ProneSupportedTM;			//var AGP_Gameplay.TargetManager ProneSupportedTM;
	UPROPERTY()		ATargetManager*		ProneUnsupportedTM;			//var AGP_Gameplay.TargetManager ProneUnsupportedTM;
	UPROPERTY()		ATargetManager*		CrouchedTM;					//var AGP_Gameplay.TargetManager CrouchedTM;
	UPROPERTY()		ATargetManager*		CurrentTM;					//var AGP_Gameplay.TargetManager CurrentTM;
	UPROPERTY()		AAGP_Character*		DSJohnson;					//var AGP_Characters.AGP_Character DSJohnson;
	UPROPERTY()		AAGP_Character*		DSBaker;					//var AGP_Characters.AGP_Character DSBaker;
	UPROPERTY()		AAGP_Character*		NCODavidson;				//var AGP_Characters.AGP_Character NCODavidson;
	UPROPERTY()		AAGP_NPC*			tower;						//var AGP_Characters.AGP_NPC tower;
	UPROPERTY()		AFSTS_HelpMarker*	HelpMarker;					//var FSTS_HelpMarker HelpMarker;
	UPROPERTY()		FName				ResetActorTag;				//var FName ResetActorTag;
	UPROPERTY()		AAGP_Objective*		AmmoPickupObjective;		//var AGP_Objective AmmoPickupObjective;
	UPROPERTY()		FName				AmmoPickupObjectiveTag;		//var FName AmmoPickupObjectiveTag;
	UPROPERTY()		AAGP_Objective*		PracticeFireObjective;		//var AGP_Objective PracticeFireObjective;
	UPROPERTY()		FName				PracticeFireObjectiveTag;	//var FName PracticeFireObjectiveTag;
	UPROPERTY()		AAGP_Objective*		RecordFireObjective;		//var AGP_Objective RecordFireObjective;
	UPROPERTY()		FName				RecordFireObjectiveTag;		//var FName RecordFireObjectiveTag;
	UPROPERTY()		FString				MissionTitle;				//var localized FString MissionTitle;
	UPROPERTY()		FString				MouseMsg;					//var localized FString MouseMsg;
	UPROPERTY()		FString				MoveForwardMsg;				//var localized FString MoveForwardMsg;
	UPROPERTY()		FString				AmmoPickupMsg1;				//var localized FString AmmoPickupMsg1;
	UPROPERTY()		FString				AmmoPickupMsg2;				//var localized FString AmmoPickupMsg2;
	UPROPERTY()		FString				ActionMsg;					//var localized FString ActionMsg;
	UPROPERTY()		FString				TalkMsg;					//var localized FString TalkMsg;
	UPROPERTY()		FString				RaiseWeaponMsg;				//var localized FString RaiseWeaponMsg;
	UPROPERTY()		FString				FireModeMsg;				//var localized FString FireModeMsg;
	UPROPERTY()		FString				LoadMsg;					//var localized FString LoadMsg;
	UPROPERTY()		FString				ZoomMsg;					//var localized FString ZoomMsg;
	UPROPERTY()		FString				ReloadMsg;					//var localized FString ReloadMsg;
	UPROPERTY()		FString				FireMsg;					//var localized FString FireMsg;
	UPROPERTY()		FString				AltFireMsg;					//var localized FString AltFireMsg;
	UPROPERTY()		FString				WeaponJamMsg;				//var localized FString WeaponJamMsg;
	UPROPERTY()		FString				MoveToLaneMsg;				//var localized FString MoveToLaneMsg;
	UPROPERTY()		FString				ReadyMsg;					//var localized FString ReadyMsg;
	UPROPERTY()		FString				KneelMsg;					//var localized FString KneelMsg;
	UPROPERTY()		FString				BreathMsg;					//var localized FString BreathMsg;
	UPROPERTY()		FString				CeaseFireMsg;				//var localized FString CeaseFireMsg;
	UPROPERTY()		bool				bShowingMessage;			//var bool bShowingMessage;
	UPROPERTY()		bool				bRaisedWeapon;				//var bool bRaisedWeapon;
	UPROPERTY()		bool				bChangedFireMode;			//var bool bChangedFireMode;
	UPROPERTY()		bool				bClearedJam;				//var bool bClearedJam;
	UPROPERTY()		bool				bCanRaiseWeapon;			//var bool bCanRaiseWeapon;
	UPROPERTY()		bool				bCanChangeFireMode;			//var bool bCanChangeFireMode;
	UPROPERTY()		bool				bCanClearJam;				//var bool bCanClearJam;
	UPROPERTY()		FString				CurrentHelpMessage;			//var FString CurrentHelpMessage;
	UPROPERTY()		FVector				HelpMarkerSmallOffset;		//var Vector HelpMarkerSmallOffset;
	UPROPERTY()		FVector				HelpMarkerLargeOffset;		//var Vector HelpMarkerLargeOffset;
	UPROPERTY()		float				AmmoPickupTimeout;			//var float AmmoPickupTimeout;
	UPROPERTY()		ABRM_HudOverlay*	BRMOverlay;					//var BRM_HudOverlay BRMOverlay;
	UPROPERTY()		int32				AuthFinalScore;				//var int32 AuthFinalScore;
	UPROPERTY()		FString				ScoreRecordText;			//var FString ScoreRecordText;
	UPROPERTY()		FString				QualifyText;				//var FString QualifyText;
	UPROPERTY()		int32				WarnCount;					//var int32 WarnCount;
	UPROPERTY()		int32				OldWeaponAmmo;				//var int32 OldWeaponAmmo;
	UPROPERTY()		bool				bResetIdle;					//var bool bResetIdle;

	void PreInit();
	void Init();
	void PostInit();
	void PostPostInit();
	void DoReferenceLinking();
	void Destroyed();
	void StartShooters();
	void EventLabNotifyCheat();
	void Give10RoundMag();
	void Give20RoundMag();
	void SetMarker(AActor* Target);
	void ShowHelpMessage(FString Message, FString secondMessage);
	void HideHelpMessage();
	bool AGP_NPC_Damaged(AAGP_NPC* NotifyActor, AController* Instigator);
	bool Pawn_Damaged(APawn* NotifyActor, AController* Instigator);
	void NPCShot(APawn* NotifyActor);
	void Suicide(APawn* Killer);
	void FriendlyFire(APawn* HitActor);
	void RestartLevel();
	void Leavenworth();
	bool AGP_Weapon_Fire(AAGP_Weapon* NotifyActor, AActor* Instigator, FString Parms);
	void FiringOutOfLane();
	void FiringOffRange();
	bool HandlePassResults();
};
