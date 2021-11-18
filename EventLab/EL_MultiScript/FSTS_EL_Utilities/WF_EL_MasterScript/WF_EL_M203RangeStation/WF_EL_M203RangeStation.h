// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/EventLab/EL_MultiScript/FSTS_EL_Utilities/WF_EL_MasterScript/WF_EL_MasterScript.h"
#include "WF_EL_M203RangeStation.generated.h"

class AFSTS_WeaponPickup;
class ACounter;

UCLASS()
class AA29_API AWF_EL_M203RangeStation : public AWF_EL_MasterScript
{
	GENERATED_BODY()
public:
	AWF_EL_M203RangeStation();

	UPROPERTY()						FString QualifyMsg;										//var localized string QualifyMsg;
	UPROPERTY()						FString ResultMsg;											//var localized string ResultMsg;
	UPROPERTY()						FString ShotsFiredMsg;										//var localized string ShotsFiredMsg;
	UPROPERTY()						FString HitMsg;											//var localized string HitMsg;
	UPROPERTY()						FString OutsideLaneMsg;									//var localized string OutsideLaneMsg;
	UPROPERTY()						FString DoneMsg;											//var localized string DoneMsg;
	UPROPERTY()						FString IncompleteMsg;										//var localized string IncompleteMsg;
	UPROPERTY()						FString CompleteMsg;										//var localized string CompleteMsg;
	UPROPERTY()						FString StationFailureMsg;									//var localized string StationFailureMsg;
	UPROPERTY()						FString QualificationFailureMsg;							//var localized string QualificationFailureMsg;
	UPROPERTY()						FString QualificationSuccessMsg;							//var localized string QualificationSuccessMsg;
	UPROPERTY()						FString FailureMsg;										//var localized string FailureMsg;
	UPROPERTY()						FString SuccessMsg;										//var localized string SuccessMsg;
	UPROPERTY()						FString NumRoundsMsg;										//var localized string NumRoundsMsg;
	UPROPERTY()						FString WeaponReloadMsg;									//var localized string WeaponReloadMsg;
	UPROPERTY()						FString WeaponPickupMsg;									//var localized string WeaponPickupMsg;
	UPROPERTY()						FString QualificationCountdownMsg;							//var localized string QualificationCountdownMsg;
	UPROPERTY()						FString QualificationMsg;									//var localized string QualificationMsg;
	UPROPERTY()						FString PracticeCountdownMsg;								//var localized string PracticeCountdownMsg;
	UPROPERTY()						FString PracticeMsg;										//var localized string PracticeMsg;
	UPROPERTY()						FString StationInstructionMsg;								//var localized string StationInstructionMsg;
	UPROPERTY()						FString StandardsMsg;										//var localized string StandardsMsg;
	UPROPERTY()						FString MoveMsg;											//var localized string MoveMsg;
	UPROPERTY()						FString ActionMsg;											//var localized string ActionMsg;
	UPROPERTY()						FString StationMsg;										//var localized string StationMsg;
	UPROPERTY()						FString WeaponName;										//var localized string WeaponName;
	UPROPERTY()						int32 iMaximumTargets;									//var int iMaximumTargets;
	UPROPERTY()						int32 iMinimumTargets;									//var int iMinimumTargets;
	UPROPERTY()						bool bStudentHasFired;									//var bool bStudentHasFired;
	UPROPERTY()						int32 HitCount;											//var int HitCount;
	UPROPERTY()						int32 ShotsRemaining;									//var int ShotsRemaining;
	UPROPERTY()						bool bQualification;									//var bool bQualification;
	UPROPERTY()						int32 OutsideShotLimit;									//var int OutsideShotLimit;
	UPROPERTY()						int32 OutsideShotCounter;								//var int OutsideShotCounter;
	UPROPERTY()						ACounter* Lane04Counter;								//var Gameplay.Counter Lane04Counter;
	UPROPERTY()						AFSTS_WeaponPickup* WeaponPickup;						//var FSTS_WeaponPickup WeaponPickup;
};
