// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/EventLab/EventLab.h"
#include "EL_SpotterRange.generated.h"

class AAGP_Location;
class AGP_Pawn;
class AAGP_DestroyableObjective;
class ABaseSmokeEmitter;
class AAGP_USMortarTeamFDC;
class ATrigger;
class UAA2_CheatManager;

class AAGP_Pawn;
UCLASS()
class AEL_SpotterRange : public AEventLab
{
	GENERATED_BODY()
public:
	AEL_SpotterRange();

	UPROPERTY()						UAA2_CheatManager* cmSpotterViewingTool;						//var transient CheatManager cmSpotterViewingTool;
	UPROPERTY()						float fpPracticeStartTime;										//var float fpPracticeStartTime;
	UPROPERTY()						float fadeoutTimer;												//var float fadeoutTimer;
	UPROPERTY()						bool InstructorMoved;											//var bool InstructorMoved;
	UPROPERTY()						AAGP_Location* locDrillStart;									//var AGP_Gameplay.AGP_Location locDrillStart;
	UPROPERTY()						AAGP_Location* TranslatePosition;								//var AGP_Gameplay.AGP_Location TranslatePosition;
	UPROPERTY()						ATriggerVolume* InstructorStart;								//var ATriggerVolume* InstructorStart;
	UPROPERTY()						ATriggerVolume* TranslateInstructor;							//var ATriggerVolume* TranslateInstructor;
	UPROPERTY()						ATrigger* trigVehicleTargetDamaged;								//var Trigger trigVehicleTargetDamaged;
	UPROPERTY()						ATrigger* trigVehicleTargetDestroyed;							//var Trigger trigVehicleTargetDestroyed;
	UPROPERTY()						ATrigger* trigSoftTargetDamaged;								//var Trigger trigSoftTargetDamaged;
	UPROPERTY()						ATrigger* trigSoftTargetDestroyed;								//var Trigger trigSoftTargetDestroyed;
	UPROPERTY()						ATrigger* trigPlayerMannedPosition;								//var Trigger trigPlayerMannedPosition;
	UPROPERTY()						int32 iPracticeTipIndex;										//var int iPracticeTipIndex;
	UPROPERTY()						int32 iPracticeRoundsHit;										//var int iPracticeRoundsHit;
	UPROPERTY()						int32 iPracticeRoundsFired;										//var int iPracticeRoundsFired;
	UPROPERTY()						int32 iGridTargetRoundsHit;										//var int iGridTargetRoundsHit;
	UPROPERTY()						int32 iVehicleTargetRoundsHit;									//var int iVehicleTargetRoundsHit;
	UPROPERTY()						int32 iSoftTargetRoundsHit;										//var int iSoftTargetRoundsHit;
	UPROPERTY()						int32 iGridTargetRoundsFired;									//var int iGridTargetRoundsFired;
	UPROPERTY()						int32 iVehicleTargetRoundsFired;								//var int iVehicleTargetRoundsFired;
	UPROPERTY()						int32 iSoftTargetRoundsFired;									//var int iSoftTargetRoundsFired;
	UPROPERTY()						AAGP_USMortarTeamFDC* agpusmtfdcFDC;							//var AGP.AGP_USMortarTeamFDC agpusmtfdcFDC;
	UPROPERTY()						ABaseSmokeEmitter* bseCurrentTarget;							//var AGP_Effects.BaseSmokeEmitter bseCurrentTarget;
	UPROPERTY()						AAGP_DestroyableObjective* agpdoCurrentTarget;					//var AGP_Gameplay.AGP_DestroyableObjective agpdoCurrentTarget;
	UPROPERTY()						AAGP_DestroyableObjective* agpdoRandomGridSoftTarget;			//var AGP_Gameplay.AGP_DestroyableObjective agpdoRandomGridSoftTarget;
	UPROPERTY()						AAGP_DestroyableObjective* agpdoRandomVehicleTarget;			//var AGP_Gameplay.AGP_DestroyableObjective agpdoRandomVehicleTarget;
	UPROPERTY()						AAGP_DestroyableObjective* agpdoRandomSoftTarget;				//var AGP_Gameplay.AGP_DestroyableObjective agpdoRandomSoftTarget;
	UPROPERTY()						AAGP_Pawn* agpQualficationSgt;									//var AGP.AGP_Pawn agpQualficationSgt;
	UPROPERTY()						AAGP_Pawn* agpPracticeSgt;										//var AGP.AGP_Pawn agpPracticeSgt;
	UPROPERTY()						AAGP_Pawn* agpIntroSgt;											//var AGP.AGP_Pawn agpIntroSgt;
	UPROPERTY()						TArray<FString> asPracticeTipsA;								//var TArray<FString> asPracticeTipsA;
	UPROPERTY()						TArray<FString> asPracticeTips;									//var TArray<FString> asPracticeTips;
	UPROPERTY()						TArray<FString> asGridTargetInstructionsA;						//var TArray<FString> asGridTargetInstructionsA;
	UPROPERTY()						TArray<FString> asGridTargetInstructions;						//var TArray<FString> asGridTargetInstructions;
	UPROPERTY()						TArray<FString> asVehicleTargetInstructionsA;					//var TArray<FString> asVehicleTargetInstructionsA;
	UPROPERTY()						TArray<FString> asVehicleTargetInstructions;					//var TArray<FString> asVehicleTargetInstructions;
	UPROPERTY()						TArray<FString> asSoftTargetInstructionsA;						//var TArray<FString> asSoftTargetInstructionsA;
	UPROPERTY()						TArray<FString> asSoftTargetInstructions;						//var TArray<FString> asSoftTargetInstructions;
	UPROPERTY()						TArray<FString> asWelcomeInstructionsA;							//var TArray<FString> asWelcomeInstructionsA;
	UPROPERTY()						TArray<FString> asWelcomeInstructions;							//var TArray<FString> asWelcomeInstructions;
	UPROPERTY()						TArray<USoundBase*> asndWelcomeInstructions;					//var array<Sound> asndWelcomeInstructions;
	UPROPERTY()						USoundBase* sndInitialWelcome;									//var Sound sndInitialWelcome;
	UPROPERTY()						int32 iInstructionStep;											//var int iInstructionStep;
	UPROPERTY()						FName nameFOTQualificationCheckFire;							//var name nameFOTQualificationCheckFire;
	UPROPERTY()						FName nameFOTQualificationGood;									//var name nameFOTQualificationGood;
	UPROPERTY()						FName nameFOTQualificationMarginal;								//var name nameFOTQualificationMarginal;
	UPROPERTY()						FName nameFOTQualificationFailure;								//var name nameFOTQualificationFailure;
	UPROPERTY()						FName nameFOTQualificationStageTwoComplete;						//var name nameFOTQualificationStageTwoComplete;
	UPROPERTY()						FName nameFOTQualificationStageOneComplete;						//var name nameFOTQualificationStageOneComplete;
	UPROPERTY()						FName nameFOTQualificationStageOne;								//var name nameFOTQualificationStageOne;
	UPROPERTY()						FName nameFOTQualificationIntro;								//var name nameFOTQualificationIntro;
	UPROPERTY()						FName nameFOTQualificationGoodShotCheckFire;					//var name nameFOTQualificationGoodShotCheckFire;
	UPROPERTY()						FName nameSoftTargetQualificationIntroduction;					//var name nameSoftTargetQualificationIntroduction;
	UPROPERTY()						TArray<FName> namePracticeCheckFire;							//var array<name> namePracticeCheckFire;
	UPROPERTY()						TArray<FName> namePracticePoorShot;								//var array<name> namePracticePoorShot;
	UPROPERTY()						TArray<FName> namePracticeGoodShot;								//var array<name> namePracticeGoodShot;
	UPROPERTY()						TArray<FName> namePracticeComment;								//var array<name> namePracticeComment;
	UPROPERTY()						float fpTimeSinceLastCheckFire;									//var float fpTimeSinceLastCheckFire;
	UPROPERTY()						float fpTimeSinceLastComment;									//var float fpTimeSinceLastComment;
	UPROPERTY()						FName namePracticeIntroduction;									//var name namePracticeIntroduction;
	UPROPERTY()						FName nameWelcomeIntroduction;									//var name nameWelcomeIntroduction;
	UPROPERTY()						FString sIntroduction;											//var string sIntroduction;
	UPROPERTY()						bool bInstructorTranslate;										//var bool bInstructorTranslate;

	void PreInit();
	void DetermineRandomTargets();
	void SpawnCurrentTargetMarker();
	void Init();
	void PostInit();
	void PostPostInit();
	void MortarDamagedTarget(AActor* agpmrdoTarget, AActor* aInstigator);
	void MortarDestroyedTarget(AActor* agpmrdoTarget, AActor* aInstigator);
	void EnableCurrentTarget();
	void ResetCurrentTarget();
	bool TriggerVolume_Enter(ATriggerVolume* Trigger, AActor* aInstigator);
	bool TranslateInstructorPosition(ATriggerVolume* Trigger, AActor* aInstigator);
	FString GetCorrectionNeeded(FVector vHitLocation);
};
