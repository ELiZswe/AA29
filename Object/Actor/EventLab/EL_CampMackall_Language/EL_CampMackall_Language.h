// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/EventLab/EventLab.h"
#include "EL_CampMackall_Language.generated.h"

class ANPC_MedStudent;
class ANPC_MedInstructor;
class AAGP_Location;
class AAGP_Trigger;
class AAGP_HUD;
class AMedExam;
class ADoorTrigger;
class AAGP_UseTrigger;
class ASlideProjector;
class ATriggerVolume;

UCLASS()
class AA29_API AEL_CampMackall_Language : public AEventLab
{
	GENERATED_BODY()
public:
	AEL_CampMackall_Language();

	UPROPERTY()   bool TalkedToInstructor;						//var bool TalkedToInstructor;
	UPROPERTY()   bool PlayerAnswered;							//var bool PlayerAnswered;
	UPROPERTY()   FVector HeadPhonesStartPosition;				//var FVector HeadPhonesStartPosition;
	UPROPERTY()   UStaticMesh* headphones;						//var StaticMeshActor headphones;
	UPROPERTY()   int32 iOldTestPage;							//var int iOldTestPage;
	UPROPERTY()   ADoorTrigger* DoorTriggerOne;					//var AGP_Gameplay.DoorTrigger DoorTriggerOne;
	UPROPERTY()   bool bHeadPhonesOn;							//var bool bHeadPhonesOn;
	UPROPERTY()   bool bTestingHack;							//var bool bTestingHack;
	UPROPERTY()   int32 iCurrentQuestion;						//var int iCurrentQuestion;
	UPROPERTY()   float GetDownTimer;							//var float GetDownTimer;
	UPROPERTY()   int32 CheatExamCount;							//var int CheatExamCount;
	UPROPERTY()   float CheatExamTime;							//var float CheatExamTime;
	UPROPERTY()   AAGP_UseTrigger* CheatExamTrigger;			//var AGP.AGP_UseTrigger CheatExamTrigger;
	UPROPERTY()   FVector SFTestStartLocation;					//var FVector SFTestStartLocation;
	UPROPERTY()   FString sTheAnswer;							//var string sTheAnswer;
	UPROPERTY()   float fRepeatQuestionTime;					//var float fRepeatQuestionTime;
	UPROPERTY()   int32 LastQuestion;							//var int LastQuestion;
	UPROPERTY()   bool bNoVoice;								//var bool bNoVoice;
	UPROPERTY()   bool bFinishTest;								//var bool bFinishTest;
	UPROPERTY()   bool bEnteredAudioLab;						//var bool bEnteredAudioLab;
	UPROPERTY()   bool bStartTest;								//var bool bStartTest;
	UPROPERTY()   bool bNextQuestion;							//var bool bNextQuestion;
	UPROPERTY()   bool LectureDone;								//var bool LectureDone;
	UPROPERTY()   bool bAnswer15;								//var bool bAnswer15;
	UPROPERTY()   bool bAnswer14;								//var bool bAnswer14;
	UPROPERTY()   bool bAnswer13;								//var bool bAnswer13;
	UPROPERTY()   bool bAnswer12;								//var bool bAnswer12;
	UPROPERTY()   bool bAnswer11;								//var bool bAnswer11;
	UPROPERTY()   bool bAnswer10;								//var bool bAnswer10;
	UPROPERTY()   bool bAnswer9;								//var bool bAnswer9;
	UPROPERTY()   bool bAnswer8;								//var bool bAnswer8;
	UPROPERTY()   bool bAnswer7;								//var bool bAnswer7;
	UPROPERTY()   bool bAnswer6;								//var bool bAnswer6;
	UPROPERTY()   bool bAnswer5;								//var bool bAnswer5;
	UPROPERTY()   bool bAnswer4;								//var bool bAnswer4;
	UPROPERTY()   bool bAnswer3;								//var bool bAnswer3;
	UPROPERTY()   bool bAnswer2;								//var bool bAnswer2;
	UPROPERTY()   bool bAnswer1;								//var bool bAnswer1;
	UPROPERTY()   int32 CorrectCounter;							//var int CorrectCounter;
	UPROPERTY()   int32 theCorrectAnswerIs;						//var int theCorrectAnswerIs;
	UPROPERTY()   AMedExam* SFExamTwo;							//var AGP_Gameplay.MedExam SFExamTwo;
	UPROPERTY()   AMedExam* SFLanguageExamOne;					//var AGP_Gameplay.MedExam SFLanguageExamOne;
	UPROPERTY()   AAGP_HUD* AGP_MyHud;							//var AGP.AGP_HUD AGP_MyHud;
	UPROPERTY()   AAGP_Trigger* SeatVolumeTwo;					//var AGP_Gameplay.AGP_Trigger SeatVolumeTwo;
	UPROPERTY()   AAGP_Trigger* SeatVolumeOne;					//var AGP_Gameplay.AGP_Trigger SeatVolumeOne;
	UPROPERTY()   ATriggerVolume* HasHeardLecture;				//var AGP_Gameplay.TriggerVolume HasHeardLecture;
	UPROPERTY()   ATriggerVolume* AudioLabTalkToInstructor;		//var AGP_Gameplay.TriggerVolume AudioLabTalkToInstructor;
	UPROPERTY()   ATriggerVolume* AudioLabTrigger;				//var AGP_Gameplay.TriggerVolume AudioLabTrigger;
	UPROPERTY()   ATriggerVolume* TestVolumeOne;				//var AGP_Gameplay.TriggerVolume TestVolumeOne;
	UPROPERTY()   ATriggerVolume* LeavingVolumeOne;				//var AGP_Gameplay.TriggerVolume LeavingVolumeOne;
	UPROPERTY()   ATriggerVolume* ClassVolumeOne;				//var AGP_Gameplay.TriggerVolume ClassVolumeOne;
	UPROPERTY()   AAGP_UseTrigger* SeatTriggerTwo;				//var AGP.AGP_UseTrigger SeatTriggerTwo;
	UPROPERTY()   AAGP_UseTrigger* SeatTriggerOne;				//var AGP.AGP_UseTrigger SeatTriggerOne;
	UPROPERTY()   ASlideProjector* SlideProjectorOne;			//var SlideProjector SlideProjectorOne;
	UPROPERTY()   AAGP_Location* ReprimandPlayerLoc;			//var AGP_Gameplay.AGP_Location ReprimandPlayerLoc;
	UPROPERTY()   AAGP_Location* ReprimandInstructorLoc;		//var AGP_Gameplay.AGP_Location ReprimandInstructorLoc;
	UPROPERTY()   ANPC_MedStudent* NPC_AudioLabStudent01_07;	//var AGP_Characters.NPC_MedStudent NPC_AudioLabStudent01_07;
	UPROPERTY()   ANPC_MedStudent* Student07;					//var AGP_Characters.NPC_MedStudent Student07;
	UPROPERTY()   ANPC_MedStudent* Student06;					//var AGP_Characters.NPC_MedStudent Student06;
	UPROPERTY()   ANPC_MedStudent* Student05;					//var AGP_Characters.NPC_MedStudent Student05;
	UPROPERTY()   ANPC_MedStudent* Student04;					//var AGP_Characters.NPC_MedStudent Student04;
	UPROPERTY()   ANPC_MedStudent* Student03;					//var AGP_Characters.NPC_MedStudent Student03;
	UPROPERTY()   ANPC_MedStudent* Student02;					//var AGP_Characters.NPC_MedStudent Student02;
	UPROPERTY()   ANPC_MedStudent* Student01;					//var AGP_Characters.NPC_MedStudent Student01;
	UPROPERTY()   ANPC_MedInstructor* SFFirstSergeant;			//var AGP_Characters.NPC_MedInstructor SFFirstSergeant;
	UPROPERTY()   ANPC_MedInstructor* InstructorTwo;			//var AGP_Characters.NPC_MedInstructor InstructorTwo;
	UPROPERTY()   ANPC_MedInstructor* InstructorOne;			//var AGP_Characters.NPC_MedInstructor InstructorOne;
	UPROPERTY()   AAGP_UseTrigger* InstructorTriggerTwo;		//var AGP.AGP_UseTrigger InstructorTriggerTwo;
	UPROPERTY()   AAGP_UseTrigger* InstructorTriggerOne;		//var AGP.AGP_UseTrigger InstructorTriggerOne;
	UPROPERTY()   bool bClassEntered;							//var bool bClassEntered;
	UPROPERTY()   bool bTestDone;								//var bool bTestDone;
	UPROPERTY()   bool bInstUseDisable;							//var bool bInstUseDisable;
	UPROPERTY()   int32 Grade;									//var int Grade;
	UPROPERTY()   int32 GetDownCount;							//var int GetDownCount;
	UPROPERTY()   int32 LookCount;								//var int LookCount;
	UPROPERTY()   int32 GoofCount;								//var int GoofCount;
	UPROPERTY()   int32 InstructorUseCount;						//var int InstructorUseCount;

	//bool DoorTrigger_UsedBy(ADoorTrigger* Trigger, AActor* aInstigator);
	//bool DoorTriggerOne_UsedBy(ADoorTrigger* Trigger, AActor* aInstigator);
	//bool AGP_UseTrigger_UsedBy(AAGP_UseTrigger* Trigger, AActor* aInstigator);
	//bool Pickup_PickedUp(APickup* NotifyActor, AActor* Instigator, FString Parms);
	//bool headphones_PickedUp(APickup* NotifyActor, AActor* Instigator, FString Parms);
	//bool SeatTriggerOne_UsedBy(AAGP_UseTrigger* Trigger, AActor* aInstigator);
	//bool SeatTriggerTwo_UsedBy(AAGP_UseTrigger* Trigger, AActor* aInstigator);
	//bool CheatExamTrigger_UsedBy(AAGP_UseTrigger* Trigger, AActor* aInstigator);
	//bool AGP_Trigger_Trigger(AAGP_Trigger* Trigger, AActor* aInstigator);
	//bool AGP_Trigger_UnTrigger(AAGP_Trigger* Trigger, AActor* aInstigator);
	//bool SeatVolumeOne_Trigger(AAGP_Trigger* Trigger, AActor* aInstigator);
	//bool SeatVolumeOne_UnTrigger(AAGP_Trigger* Trigger, AActor* aInstigator);
	//bool SeatVolumeTwo_Trigger(AAGP_Trigger* Trigger, AActor* aInstigator);
	//bool SeatVolumeTwo_UnTrigger(AAGP_Trigger* Trigger, AActor* aInstigator);
	//bool TriggerVolume_Enter(ATriggerVolume* Trigger, AActor* aInstigator);
	//bool ClassVolumeOne_Enter(ATriggerVolume* Trigger, AActor* aInstigator);

	//void PreInit();
	//void Init();
	//void PostInit();
	//void PostPostInit();
	//bool InstructorTriggerOne_UsedBy(AAGP_UseTrigger* Trigger, AActor* aInstigator);
	//bool InstructorTriggerTwo_UsedBy(AAGP_UseTrigger* Trigger, AActor* aInstigator);
	//bool HasHeardLecture_Enter(ATriggerVolume* Trigger, AActor* aInstigator);
	//bool GetDown_Trigger(ATriggerVolume* Trigger, AActor* aInstigator);
	//bool resetvolume_Trigger(ATriggerVolume* Trigger, AActor* aInstigator);
	//bool AudioLabTalkToInstructor_Enter(ATriggerVolume* Trigger, AActor* aInstigator);
	//bool DeskVolumeOne_Trigger(AAGP_Trigger* Trigger, AActor* aInstigator);
	//void ResetLipsincAnim();
	//bool GlobalTimer(FName Name);
	//bool UpdateTestAnswers(int32 Switch);
	//void StudentsTakeNotes();
	//void StudentsIdle();
	//void StudentsRaiseHands(int32 Which);
	//void StudentsLowerHands(int32 Which);
	//void SayTestWord(int32 Snd);
	//void StudentAnswer(int32 Which);
	//void StudentReturnsToIdle(int32 Which);
	//void DisplayCorrectAnswer(int32 Key);
	//void PrepareQuestion();
	//void DisplayCorrectPageOnTest();

	void UpdateCorrectAnswersFromLecture();
	void SayTestQuestion(bool bMessageOnly);
	void UpdatePlayerCheaterLevel();
};

