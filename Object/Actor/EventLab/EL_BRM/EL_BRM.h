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

/**
 * 
 */
UCLASS()
class AA29_API AEL_BRM : public AEventLab
{
	GENERATED_BODY()
public:
	AEL_BRM();


	UPROPERTY()   bool TalkedToInstructor;				//var bool bResetIdle;
	UPROPERTY()   int32 PlayerAnswered;					//var int OldWeaponAmmo;
	UPROPERTY()   int32 WarnCount;						//var int WarnCount;
	UPROPERTY()   FString headphones;					//var string QualifyText;
	UPROPERTY()   FString iOldTestPage;					//var string ScoreRecordText;
	UPROPERTY()   int32 DoorTriggerOne;					//var int AuthFinalScore;
	//UPROPERTY()   ABRM_HudOverlay* bHeadPhonesOn;		//var BRM_HudOverlay BRMOverlay;
	UPROPERTY()   float bTestingHack;					//var float AmmoPickupTimeout;
	UPROPERTY()   FVector iCurrentQuestion;				//var FVector HelpMarkerLargeOffset;
	UPROPERTY()   FVector GetDownTimer;					//var FVector HelpMarkerSmallOffset;
	UPROPERTY()   FString CheatExamCount;				//var string CurrentHelpMessage;
	UPROPERTY()   bool CheatExamTime;					//var bool bCanClearJam;
	UPROPERTY()   bool CheatExamTrigger;				//var bool bCanChangeFireMode;
	UPROPERTY()   bool SFTestStartLocation;				//var bool bCanRaiseWeapon;
	UPROPERTY()   bool sTheAnswer;						//var bool bClearedJam;
	UPROPERTY()   bool fRepeatQuestionTime;				//var bool bChangedFireMode;
	UPROPERTY()   bool LastQuestion;					//var bool bRaisedWeapon;
	UPROPERTY()   bool bNoVoice;						//var bool bShowingMessage;
	UPROPERTY()   FString bFinishTest;					//var localized string CeaseFireMsg;
	UPROPERTY()   FString bEnteredAudioLab;				//var localized string BreathMsg;
	UPROPERTY()   FString bStartTest;					//var localized string KneelMsg;
	UPROPERTY()   FString bNextQuestion;				//var localized string ReadyMsg;
	UPROPERTY()   FString LectureDone;					//var localized string MoveToLaneMsg;
	UPROPERTY()   FString bAnswer15;					//var localized string WeaponJamMsg;
	UPROPERTY()   FString bAnswer14;					//var localized string AltFireMsg;
	UPROPERTY()   FString bAnswer13;					//var localized string FireMsg;
	UPROPERTY()   FString bAnswer12;					//var localized string ReloadMsg;
	UPROPERTY()   FString bAnswer11;					//var localized string ZoomMsg;
	UPROPERTY()   FString bAnswer10;					//var localized string LoadMsg;
	UPROPERTY()   FString bAnswer9;						//var localized string FireModeMsg;
	UPROPERTY()   FString bAnswer8;						//var localized string RaiseWeaponMsg;
	UPROPERTY()   FString bAnswer7;						//var localized string TalkMsg;
	UPROPERTY()   FString bAnswer6;						//var localized string ActionMsg;
	UPROPERTY()   FString bAnswer5;						//var localized string AmmoPickupMsg2;
	UPROPERTY()   FString bAnswer4;						//var localized string AmmoPickupMsg1;
	UPROPERTY()   FString bAnswer3;						//var localized string MoveForwardMsg;
	UPROPERTY()   FString bAnswer2;						//var localized string MouseMsg;
	UPROPERTY()   FString bAnswer1;						//var localized string MissionTitle;
	UPROPERTY()   FName CorrectCounter;					//var name RecordFireObjectiveTag;
	UPROPERTY()   AAGP_Objective* theCorrectAnswerIs;	//var AGP.AGP_Objective RecordFireObjective;
	UPROPERTY()   FName SFExamTwo;						//var name PracticeFireObjectiveTag;
	UPROPERTY()   AAGP_Objective* SFLanguageExamOne;	//var AGP.AGP_Objective PracticeFireObjective;
	UPROPERTY()   FName AGP_MyHud;						//var name AmmoPickupObjectiveTag;
	UPROPERTY()   AAGP_Objective* SeatVolumeTwo;		//var AGP.AGP_Objective AmmoPickupObjective;
	UPROPERTY()   FName SeatVolumeOne;					//var name ResetActorTag;
	UPROPERTY()   AFSTS_HelpMarker* HasHeardLecture;	//var FSTS_HelpMarker HelpMarker;
	UPROPERTY()   AAGP_NPC* AudioLabTalkToInstructor;	//var AGP_Characters.AGP_NPC tower;
	UPROPERTY()   AAGP_Character* AudioLabTrigger;		//var AGP_Characters.AGP_Character NCODavidson;
	UPROPERTY()   AAGP_Character* TestVolumeOne;		//var AGP_Characters.AGP_Character DSBaker;
	UPROPERTY()   AAGP_Character* LeavingVolumeOne;		//var AGP_Characters.AGP_Character DSJohnson;
	UPROPERTY()   ATargetManager* ClassVolumeOne;		//var AGP_Gameplay.TargetManager CurrentTM;
	UPROPERTY()   ATargetManager* SeatTriggerTwo;		//var AGP_Gameplay.TargetManager CrouchedTM;
	UPROPERTY()   ATargetManager* SeatTriggerOne;		//var AGP_Gameplay.TargetManager ProneUnsupportedTM;
	UPROPERTY()   ATargetManager* SlideProjectorOne;	//var AGP_Gameplay.TargetManager ProneSupportedTM;
	UPROPERTY()   AMarker* ReprimandPlayerLoc;			//var AGP.Marker FiringPosition;
	UPROPERTY()   AActor* ReprimandInstructorLoc;		//var Actor PlayerSpawnPoint;


};
