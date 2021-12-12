// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/EventLab/EL_MultiScript/FSTS_EL_Utilities/WF_EL_MasterScript/WF_EL_MasterScript.h"
#include "AA29/AA29.h"
#include "WF_EL_ExplosiveWeaponsRange.generated.h"

class AFSTS_WeaponPickup;

UCLASS()
class AA29_API AWF_EL_ExplosiveWeaponsRange : public AWF_EL_MasterScript
{
	GENERATED_BODY()
public:
	AWF_EL_ExplosiveWeaponsRange();

	UPROPERTY()   bool bWFAT4IntroHeard;				//var config bool bWFAT4IntroHeard;
	UPROPERTY()   bool bWFBDNIntroHeard;				//var config bool bWFBDNIntroHeard;
	UPROPERTY()   bool bWFM203IntroHeard;				//var config bool bWFM203IntroHeard;
	UPROPERTY()   bool bWFExplosivesIntroHeard;			//var config bool bWFExplosivesIntroHeard;
	UPROPERTY()   bool bPlayerSkippingIntro;			//var bool bPlayerSkippingIntro;
	UPROPERTY()   AActor* actTargetAT4;					//var Actor actTargetAT4;
	UPROPERTY()   AActor* actTargetBDM;					//var Actor actTargetBDM;
	UPROPERTY()   AActor* actTargetM203;				//var Actor actTargetM203;
	UPROPERTY()   FString BDMWeaponStandardsMsg;		//var localized string BDMWeaponStandardsMsg;
	UPROPERTY()   FString AT4WeaponStandardsMsg;		//var localized string AT4WeaponStandardsMsg;
	UPROPERTY()   FString M203WeaponStandardsMsg;		//var localized string M203WeaponStandardsMsg;
	UPROPERTY()   FString BDMWeaponPickupMsg;			//var localized string BDMWeaponPickupMsg;
	UPROPERTY()   FString AT4WeaponPickupMsg;			//var localized string AT4WeaponPickupMsg;
	UPROPERTY()   FString M203WeaponPickupMsg;			//var localized string M203WeaponPickupMsg;
	UPROPERTY()   FString BDMWeaponName;				//var localized string BDMWeaponName;
	UPROPERTY()   FString AT4WeaponName;				//var localized string AT4WeaponName;
	UPROPERTY()   FString M203WeaponName;				//var localized string M203WeaponName;
	UPROPERTY()   FString TargetHitMsg;					//var localized string TargetHitMsg;
	UPROPERTY()   FString ThrowMsg;						//var localized string ThrowMsg;
	UPROPERTY()   FString SupportedMsg;					//var localized string SupportedMsg;
	UPROPERTY()   FString ReloadAndFireMsg;				//var localized string ReloadAndFireMsg;
	UPROPERTY()   FString ReloadMsg;					//var localized string ReloadMsg;
	UPROPERTY()   FString ZoomMsg;						//var localized string ZoomMsg;
	UPROPERTY()   FString FireMsg;						//var localized string FireMsg;
	UPROPERTY()   FString MissionCompleteMsg;			//var localized string MissionCompleteMsg;
	UPROPERTY()   FString QualifyMsg;					//var localized string QualifyMsg;
	UPROPERTY()   FString ResultMsg;					//var localized string ResultMsg;
	UPROPERTY()   FString ShotsFiredMsg;				//var localized string ShotsFiredMsg;
	UPROPERTY()   FString HitMsg;						//var localized string HitMsg;
	UPROPERTY()   FString OutsideLaneMsg;				//var localized string OutsideLaneMsg;
	UPROPERTY()   FString DoneMsg;						//var localized string DoneMsg;
	UPROPERTY()   FString IncompleteMsg;				//var localized string IncompleteMsg;
	UPROPERTY()   FString CompleteMsg;					//var localized string CompleteMsg;
	UPROPERTY()   FString StationFailureMsg;			//var localized string StationFailureMsg;
	UPROPERTY()   FString BDMQualificationFailureMsg;	//var localized string BDMQualificationFailureMsg;
	UPROPERTY()   FString AT4QualificationFailureMsg;	//var localized string AT4QualificationFailureMsg;
	UPROPERTY()   FString M203QualificationFailureMsg;	//var localized string M203QualificationFailureMsg;
	UPROPERTY()   FString BDMQualificationSuccessMsg;	//var localized string BDMQualificationSuccessMsg;
	UPROPERTY()   FString AT4QualificationSuccessMsg;	//var localized string AT4QualificationSuccessMsg;
	UPROPERTY()   FString M203QualificationSuccessMsg;	//var localized string M203QualificationSuccessMsg;
	UPROPERTY()   FString FailureMsg;					//var localized string FailureMsg;
	UPROPERTY()   FString SuccessMsg;					//var localized string SuccessMsg;
	UPROPERTY()   FString NumRoundsMsg;					//var localized string NumRoundsMsg;
	UPROPERTY()   FString WeaponReloadMsg;				//var localized string WeaponReloadMsg;
	UPROPERTY()   FString WeaponPickupMsg;				//var localized string WeaponPickupMsg;
	UPROPERTY()   FString QualificationCountdownMsg;	//var localized string QualificationCountdownMsg;
	UPROPERTY()   FString QualificationMsg;				//var localized string QualificationMsg;
	UPROPERTY()   FString PracticeCountdownMsg;			//var localized string PracticeCountdownMsg;
	UPROPERTY()   FString PracticeMsg;					//var localized string PracticeMsg;
	UPROPERTY()   FString StationInstructionMsg;		//var localized string StationInstructionMsg;
	UPROPERTY()   FString StandardsMsg;					//var localized string StandardsMsg;
	UPROPERTY()   FString MoveMsg;						//var localized string MoveMsg;
	UPROPERTY()   FString ActionMsg;					//var localized string ActionMsg;
	UPROPERTY()   FString StationMsg;					//var localized string StationMsg;
	UPROPERTY()   FString WeaponName;					//var localized string WeaponName;
	UPROPERTY()   int32 iMaximumTargets;				//var int iMaximumTargets;
	UPROPERTY()   int32 iMinimumTargets;				//var int iMinimumTargets;
	UPROPERTY()   int32 BDMPracticeFireCounter;			//var int BDMPracticeFireCounter;
	UPROPERTY()   int32 AT4PracticeFireCounter;			//var int AT4PracticeFireCounter;
	UPROPERTY()   int32 M203QualificationFireCounter;	//var int M203QualificationFireCounter;
	UPROPERTY()   EQualificationState BDMQualState;		//var WF_EL_MasterScript.EQualificationState BDMQualState;
	UPROPERTY()   EQualificationState AT4QualState;		//var WF_EL_MasterScript.EQualificationState AT4QualState;
	UPROPERTY()   EQualificationState M203QualState;	//var WF_EL_MasterScript.EQualificationState M203QualState;
	UPROPERTY()   int32 HitCount;						//var int HitCount;
	UPROPERTY()   int32 OutsideShotLimit;				//var int OutsideShotLimit;
	UPROPERTY()   int32 OutsideShotCounter;				//var int OutsideShotCounter;
	UPROPERTY()   AFSTS_WeaponPickup* BDMPickup;		//var FSTS_WeaponPickup BDMPickup;
	UPROPERTY()   AFSTS_WeaponPickup* AT4Pickup;		//var FSTS_WeaponPickup AT4Pickup;
	UPROPERTY()   AFSTS_WeaponPickup* M203Pickup;		//var FSTS_WeaponPickup M203Pickup;

	void Reset();
	void GivePlayerAT4();
	void GivePlayerBDM();
	void DoReferenceLinking();
	void skiptoat4();
	void skiptobdm();
};
