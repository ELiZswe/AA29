// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/EventLab/EventLab.h"
#include "EL_SFMOUT.generated.h"

class ALight;
class AAGP_Sound;
class AMover;
class APickup;
class AAGP_Character_NPC;
class ADoorTrigger;
class ATextDisplay;
class AAGP_DumbEndPoint;

UCLASS()
class AEL_SFMOUT : public AEventLab
{
	GENERATED_BODY()
public:
	AEL_SFMOUT();

	
	UPROPERTY()   APickup* w_m4a1;								//var Pickup w_m4a1;
	UPROPERTY()   APickup* w_m9;								//var Pickup w_m9;
	UPROPERTY()   APickup* w_doorbreacher;						//var Pickup w_doorbreacher;
	UPROPERTY()   ATextDisplay* TextDisplay;					//var AGP_Gameplay.TextDisplay TextDisplay;
	UPROPERTY()   ATextDisplay* aarDisplay;						//var AGP_Gameplay.TextDisplay aarDisplay;
	UPROPERTY()   ATextDisplay* room1Timer1;					//var AGP_Gameplay.TextDisplay room1Timer1;
	UPROPERTY()   ATextDisplay* room2Timer1;					//var AGP_Gameplay.TextDisplay room2Timer1;
	UPROPERTY()   ATextDisplay* room3Timer1;					//var AGP_Gameplay.TextDisplay room3Timer1;
	UPROPERTY()   ATextDisplay* room4Timer1;					//var AGP_Gameplay.TextDisplay room4Timer1;
	UPROPERTY()   ATextDisplay* room5Timer1;					//var AGP_Gameplay.TextDisplay room5Timer1;
	UPROPERTY()   ATextDisplay* room6Timer1;					//var AGP_Gameplay.TextDisplay room6Timer1;
	UPROPERTY()   ATextDisplay* room7Timer1;					//var AGP_Gameplay.TextDisplay room7Timer1;
	UPROPERTY()   ATextDisplay* room8Timer1;					//var AGP_Gameplay.TextDisplay room8Timer1;
	UPROPERTY()   ATextDisplay* room9Timer1;					//var AGP_Gameplay.TextDisplay room9Timer1;
	UPROPERTY()   ADamageDetector* damageDetector1;				//var AGP_Gameplay.DamageDetector damageDetector1;
	UPROPERTY()   ADamageDetector* damageDetector2;				//var AGP_Gameplay.DamageDetector damageDetector2;
	UPROPERTY()   ADamageDetector* damageDetector3;				//var AGP_Gameplay.DamageDetector damageDetector3;
	UPROPERTY()   ADamageDetector* damageDetector4;				//var AGP_Gameplay.DamageDetector damageDetector4;
	UPROPERTY()   ADamageDetector* damageDetector5;				//var AGP_Gameplay.DamageDetector damageDetector5;
	UPROPERTY()   ADamageDetector* damageDetector6;				//var AGP_Gameplay.DamageDetector damageDetector6;
	UPROPERTY()   ADamageDetector* damageDetector7;				//var AGP_Gameplay.DamageDetector damageDetector7;
	UPROPERTY()   ADamageDetector* damageDetector8;				//var AGP_Gameplay.DamageDetector damageDetector8;
	UPROPERTY()   AAGP_Character_NPC* cadreFrago;				//var AGP_Characters.AGP_Character_NPC cadreFrago;
	UPROPERTY()   AAGP_Character_NPC* cadreHistory;				//var AGP_Characters.AGP_Character_NPC cadreHistory;
	UPROPERTY()   AAGP_Character_NPC* cadreAAR;					//var AGP_Characters.AGP_Character_NPC cadreAAR;
	UPROPERTY()   AAGP_Character_NPC* cadreObserver;			//var AGP_Characters.AGP_Character_NPC cadreObserver;
	UPROPERTY()   AMover* door1;								//var Mover door1;
	UPROPERTY()   AMover* door2;								//var Mover door2;
	UPROPERTY()   AMover* door3;								//var Mover door3;
	UPROPERTY()   AMover* door4;								//var Mover door4;
	UPROPERTY()   AMover* door5;								//var Mover door5;
	UPROPERTY()   AMover* door6;								//var Mover door6;
	UPROPERTY()   AMover* door7;								//var Mover door7;
	UPROPERTY()   AMover* door8;								//var Mover door8;
	UPROPERTY()   AMover* door9;								//var Mover door9;
	UPROPERTY()   ADoorTrigger* doorTrigger1;					//var AGP_Gameplay.DoorTrigger doorTrigger1;
	UPROPERTY()   ADoorTrigger* doorTrigger2;					//var AGP_Gameplay.DoorTrigger doorTrigger2;
	UPROPERTY()   ADoorTrigger* doorTrigger3;					//var AGP_Gameplay.DoorTrigger doorTrigger3;
	UPROPERTY()   ADoorTrigger* doorTrigger4;					//var AGP_Gameplay.DoorTrigger doorTrigger4;
	UPROPERTY()   ADoorTrigger* doorTrigger5;					//var AGP_Gameplay.DoorTrigger doorTrigger5;
	UPROPERTY()   ADoorTrigger* doorTrigger6;					//var AGP_Gameplay.DoorTrigger doorTrigger6;
	UPROPERTY()   ADoorTrigger* doorTrigger7;					//var AGP_Gameplay.DoorTrigger doorTrigger7;
	UPROPERTY()   ADoorTrigger* doorTrigger8;					//var AGP_Gameplay.DoorTrigger doorTrigger8;
	UPROPERTY()   ADoorTrigger* doorTrigger9;					//var AGP_Gameplay.DoorTrigger doorTrigger9;
	UPROPERTY()   AAGP_UseTrigger* cadreUseTrigger1;			//var AGP.AGP_UseTrigger cadreUseTrigger1;
	UPROPERTY()   AAGP_UseTrigger* cadreUseTrigger2;			//var AGP.AGP_UseTrigger cadreUseTrigger2;
	UPROPERTY()   AAGP_UseTrigger* cadreUseTrigger3;			//var AGP.AGP_UseTrigger cadreUseTrigger3;
	UPROPERTY()   AAGP_UseTrigger* skipVOTrigger;				//var AGP.AGP_UseTrigger skipVOTrigger;
	UPROPERTY()   AAGP_UseTrigger* sbUseTrigger;				//var AGP.AGP_UseTrigger sbUseTrigger;
	UPROPERTY()   AAGP_UseTrigger* inspectUseTrigger;			//var AGP.AGP_UseTrigger inspectUseTrigger;
	UPROPERTY()   FString cadreUseTip1;							//var string cadreUseTip1;
	UPROPERTY()   FString cadreUseTip2;							//var string cadreUseTip2;
	UPROPERTY()   FString cadreUseTipAAR;						//var string cadreUseTipAAR;
	UPROPERTY()   FString inspectUseTip;						//var string inspectUseTip;
	UPROPERTY()   ATriggerVolume* cadreTrigger1;				//var AGP_Gameplay.TriggerVolume cadreTrigger1;
	UPROPERTY()   ATriggerVolume* cadreTrigger2;				//var AGP_Gameplay.TriggerVolume cadreTrigger2;
	UPROPERTY()   ATriggerVolume* cadreTrigger3;				//var AGP_Gameplay.TriggerVolume cadreTrigger3;
	UPROPERTY()   ATriggerVolume* room1Trigger1;				//var AGP_Gameplay.TriggerVolume room1Trigger1;
	UPROPERTY()   ATriggerVolume* room1Trigger2;				//var AGP_Gameplay.TriggerVolume room1Trigger2;
	UPROPERTY()   ATriggerVolume* room1Trigger3;				//var AGP_Gameplay.TriggerVolume room1Trigger3;
	UPROPERTY()   ATriggerVolume* room2Trigger1;				//var AGP_Gameplay.TriggerVolume room2Trigger1;
	UPROPERTY()   ATriggerVolume* room2Trigger2;				//var AGP_Gameplay.TriggerVolume room2Trigger2;
	UPROPERTY()   ATriggerVolume* room2Trigger3;				//var AGP_Gameplay.TriggerVolume room2Trigger3;
	UPROPERTY()   ATriggerVolume* room3Trigger1;				//var AGP_Gameplay.TriggerVolume room3Trigger1;
	UPROPERTY()   ATriggerVolume* room3Trigger2;				//var AGP_Gameplay.TriggerVolume room3Trigger2;
	UPROPERTY()   ATriggerVolume* room3Trigger3;				//var AGP_Gameplay.TriggerVolume room3Trigger3;
	UPROPERTY()   ATriggerVolume* room4Trigger1;				//var AGP_Gameplay.TriggerVolume room4Trigger1;
	UPROPERTY()   ATriggerVolume* room4Trigger2;				//var AGP_Gameplay.TriggerVolume room4Trigger2;
	UPROPERTY()   ATriggerVolume* room4Trigger3;				//var AGP_Gameplay.TriggerVolume room4Trigger3;
	UPROPERTY()   ATriggerVolume* room4Trigger4;				//var AGP_Gameplay.TriggerVolume room4Trigger4;
	UPROPERTY()   ATriggerVolume* room5Trigger1;				//var AGP_Gameplay.TriggerVolume room5Trigger1;
	UPROPERTY()   ATriggerVolume* room5Trigger2;				//var AGP_Gameplay.TriggerVolume room5Trigger2;
	UPROPERTY()   ATriggerVolume* room5Trigger3;				//var AGP_Gameplay.TriggerVolume room5Trigger3;
	UPROPERTY()   ATriggerVolume* room6Trigger1;				//var AGP_Gameplay.TriggerVolume room6Trigger1;
	UPROPERTY()   ATriggerVolume* room6Trigger2;				//var AGP_Gameplay.TriggerVolume room6Trigger2;
	UPROPERTY()   ATriggerVolume* room7Trigger1;				//var AGP_Gameplay.TriggerVolume room7Trigger1;
	UPROPERTY()   ATriggerVolume* room7Trigger2;				//var AGP_Gameplay.TriggerVolume room7Trigger2;
	UPROPERTY()   ATriggerVolume* room7Trigger3;				//var AGP_Gameplay.TriggerVolume room7Trigger3;
	UPROPERTY()   ATriggerVolume* room8Trigger1;				//var AGP_Gameplay.TriggerVolume room8Trigger1;
	UPROPERTY()   ATriggerVolume* room8Trigger2;				//var AGP_Gameplay.TriggerVolume room8Trigger2;
	UPROPERTY()   ATriggerVolume* room8Trigger3;				//var AGP_Gameplay.TriggerVolume room8Trigger3;
	UPROPERTY()   ATriggerVolume* room9Trigger1;				//var AGP_Gameplay.TriggerVolume room9Trigger1;
	UPROPERTY()   ATriggerVolume* room9Trigger2;				//var AGP_Gameplay.TriggerVolume room9Trigger2;
	UPROPERTY()   ATriggerVolume* room9Trigger3;				//var AGP_Gameplay.TriggerVolume room9Trigger3;
	UPROPERTY()   ATriggerVolume* authTrigger;					//var AGP_Gameplay.TriggerVolume authTrigger;
	UPROPERTY()   ATriggerVolume* holsterTrigger;				//var AGP_Gameplay.TriggerVolume holsterTrigger;
	UPROPERTY()   ATriggerVolume* WeaponClearVolumeTrigger;		//var AGP_Gameplay.TriggerVolume WeaponClearVolumeTrigger;
	UPROPERTY()   ATriggerVolume* breacherTrigger;				//var AGP_Gameplay.TriggerVolume breacherTrigger;
	UPROPERTY()   AAGP_Sound* terrainSound1;					//var AGP_Gameplay.AGP_Sound terrainSound1;
	UPROPERTY()   AAGP_Sound* ambientSound1;					//var AGP_Gameplay.AGP_Sound ambientSound1;
	UPROPERTY()   AAGP_Sound* room0Sound;						//var AGP_Gameplay.AGP_Sound room0Sound;
	UPROPERTY()   AAGP_Sound* room1Sound;						//var AGP_Gameplay.AGP_Sound room1Sound;
	UPROPERTY()   AAGP_Sound* room2Sound;						//var AGP_Gameplay.AGP_Sound room2Sound;
	UPROPERTY()   AAGP_Sound* room3Sound;						//var AGP_Gameplay.AGP_Sound room3Sound;
	UPROPERTY()   AAGP_Sound* room4Sound;						//var AGP_Gameplay.AGP_Sound room4Sound;
	UPROPERTY()   AAGP_Sound* room5Sound;						//var AGP_Gameplay.AGP_Sound room5Sound;
	UPROPERTY()   AAGP_Sound* room6Sound;						//var AGP_Gameplay.AGP_Sound room6Sound;
	UPROPERTY()   AAGP_Sound* room7Sound;						//var AGP_Gameplay.AGP_Sound room7Sound;
	UPROPERTY()   AAGP_Sound* room8Sound;						//var AGP_Gameplay.AGP_Sound room8Sound;
	UPROPERTY()   AAGP_Sound* room9Sound;						//var AGP_Gameplay.AGP_Sound room9Sound;
	UPROPERTY()   ALight* room1Light1;							//var Light room1Light1;
	UPROPERTY()   ALight* room2Light1;							//var Light room2Light1;
	UPROPERTY()   ALight* room3Light1;							//var Light room3Light1;
	UPROPERTY()   ALight* room4Light1;							//var Light room4Light1;
	UPROPERTY()   ALight* room5Light1;							//var Light room5Light1;
	UPROPERTY()   ALight* room6Light1;							//var Light room6Light1;
	UPROPERTY()   ALight* room7Light1;							//var Light room7Light1;
	UPROPERTY()   ALight* room8Light1;							//var Light room8Light1;
	UPROPERTY()   ALight* room9Light1;							//var Light room9Light1;
	UPROPERTY()   AMarksmanTarget* room1Target1;				//var AGP_Gameplay.MarksmanTarget room1Target1;
	UPROPERTY()   AMarksmanTarget* room1Target2;				//var AGP_Gameplay.MarksmanTarget room1Target2;
	UPROPERTY()   AMarksmanTarget* room1Target3;				//var AGP_Gameplay.MarksmanTarget room1Target3;
	UPROPERTY()   AMarksmanTarget* room1Target4;				//var AGP_Gameplay.MarksmanTarget room1Target4;
	UPROPERTY()   AMarksmanTarget* room1Target5;				//var AGP_Gameplay.MarksmanTarget room1Target5;
	UPROPERTY()   AMarksmanTarget* room1Target6;				//var AGP_Gameplay.MarksmanTarget room1Target6;
	UPROPERTY()   AMarksmanTarget* room1Target7;				//var AGP_Gameplay.MarksmanTarget room1Target7;
	UPROPERTY()   AMarksmanTarget* room1Target8;				//var AGP_Gameplay.MarksmanTarget room1Target8;
	UPROPERTY()   AMarksmanTarget* room2Target1;				//var AGP_Gameplay.MarksmanTarget room2Target1;
	UPROPERTY()   AMarksmanTarget* room2Target2;				//var AGP_Gameplay.MarksmanTarget room2Target2;
	UPROPERTY()   AMarksmanTarget* room2Target3;				//var AGP_Gameplay.MarksmanTarget room2Target3;
	UPROPERTY()   AMarksmanTarget* room2Target4;				//var AGP_Gameplay.MarksmanTarget room2Target4;
	UPROPERTY()   AMarksmanTarget* room2Target5;				//var AGP_Gameplay.MarksmanTarget room2Target5;
	UPROPERTY()   AMarksmanTarget* room2Target6;				//var AGP_Gameplay.MarksmanTarget room2Target6;
	UPROPERTY()   AMarksmanTarget* room2Target7;				//var AGP_Gameplay.MarksmanTarget room2Target7;
	UPROPERTY()   AMarksmanTarget* room3Target1;				//var AGP_Gameplay.MarksmanTarget room3Target1;
	UPROPERTY()   AMarksmanTarget* room3Target2;				//var AGP_Gameplay.MarksmanTarget room3Target2;
	UPROPERTY()   AMarksmanTarget* room3Target3;				//var AGP_Gameplay.MarksmanTarget room3Target3;
	UPROPERTY()   AMarksmanTarget* room3Target4;				//var AGP_Gameplay.MarksmanTarget room3Target4;
	UPROPERTY()   AMarksmanTarget* room3Target5;				//var AGP_Gameplay.MarksmanTarget room3Target5;
	UPROPERTY()   AMarksmanTarget* room3Target6;				//var AGP_Gameplay.MarksmanTarget room3Target6;
	UPROPERTY()   AMarksmanTarget* room3Target7;				//var AGP_Gameplay.MarksmanTarget room3Target7;
	UPROPERTY()   AMarksmanTarget* room3Target8;				//var AGP_Gameplay.MarksmanTarget room3Target8;
	UPROPERTY()   AMarksmanTarget* room3Target9;				//var AGP_Gameplay.MarksmanTarget room3Target9;
	UPROPERTY()   AMarksmanTarget* room3Target10;				//var AGP_Gameplay.MarksmanTarget room3Target10;
	UPROPERTY()   AMarksmanTarget* room4Target1;				//var AGP_Gameplay.MarksmanTarget room4Target1;
	UPROPERTY()   AMarksmanTarget* room4Target2;				//var AGP_Gameplay.MarksmanTarget room4Target2;
	UPROPERTY()   AMarksmanTarget* room4Target3;				//var AGP_Gameplay.MarksmanTarget room4Target3;
	UPROPERTY()   AMarksmanTarget* room4Target4;				//var AGP_Gameplay.MarksmanTarget room4Target4;
	UPROPERTY()   AMarksmanTarget* room4Target5;				//var AGP_Gameplay.MarksmanTarget room4Target5;
	UPROPERTY()   AMarksmanTarget* room4Target6;				//var AGP_Gameplay.MarksmanTarget room4Target6;
	UPROPERTY()   AMarksmanTarget* room4Target7;				//var AGP_Gameplay.MarksmanTarget room4Target7;
	UPROPERTY()   AMarksmanTarget* room4Target8;				//var AGP_Gameplay.MarksmanTarget room4Target8;
	UPROPERTY()   AMarksmanTarget* room4Target9;				//var AGP_Gameplay.MarksmanTarget room4Target9;
	UPROPERTY()   AMarksmanTarget* room5Target1;				//var AGP_Gameplay.MarksmanTarget room5Target1;
	UPROPERTY()   AMarksmanTarget* room5Target2;				//var AGP_Gameplay.MarksmanTarget room5Target2;
	UPROPERTY()   AMarksmanTarget* room5Target3;				//var AGP_Gameplay.MarksmanTarget room5Target3;
	UPROPERTY()   AMarksmanTarget* room5Target4;				//var AGP_Gameplay.MarksmanTarget room5Target4;
	UPROPERTY()   AMarksmanTarget* room5Target5;				//var AGP_Gameplay.MarksmanTarget room5Target5;
	UPROPERTY()   AMarksmanTarget* room5Target6;				//var AGP_Gameplay.MarksmanTarget room5Target6;
	UPROPERTY()   AMarksmanTarget* room6Target1;				//var AGP_Gameplay.MarksmanTarget room6Target1;
	UPROPERTY()   AMarksmanTarget* room6Target2;				//var AGP_Gameplay.MarksmanTarget room6Target2;
	UPROPERTY()   AMarksmanTarget* room6Target3;				//var AGP_Gameplay.MarksmanTarget room6Target3;
	UPROPERTY()   AMarksmanTarget* room6Target4;				//var AGP_Gameplay.MarksmanTarget room6Target4;
	UPROPERTY()   AMarksmanTarget* room6Target5;				//var AGP_Gameplay.MarksmanTarget room6Target5;
	UPROPERTY()   AMarksmanTarget* room6Target6;				//var AGP_Gameplay.MarksmanTarget room6Target6;
	UPROPERTY()   AMarksmanTarget* room6Target7;				//var AGP_Gameplay.MarksmanTarget room6Target7;
	UPROPERTY()   AMarksmanTarget* room7Target1;				//var AGP_Gameplay.MarksmanTarget room7Target1;
	UPROPERTY()   AMarksmanTarget* room7Target2;				//var AGP_Gameplay.MarksmanTarget room7Target2;
	UPROPERTY()   AMarksmanTarget* room7Target3;				//var AGP_Gameplay.MarksmanTarget room7Target3;
	UPROPERTY()   AMarksmanTarget* room7Target4;				//var AGP_Gameplay.MarksmanTarget room7Target4;
	UPROPERTY()   AMarksmanTarget* room7Target5;				//var AGP_Gameplay.MarksmanTarget room7Target5;
	UPROPERTY()   AMarksmanTarget* room7Target6;				//var AGP_Gameplay.MarksmanTarget room7Target6;
	UPROPERTY()   AMarksmanTarget* room7Target7;				//var AGP_Gameplay.MarksmanTarget room7Target7;
	UPROPERTY()   AMarksmanTarget* room7Target8;				//var AGP_Gameplay.MarksmanTarget room7Target8;
	UPROPERTY()   AMarksmanTarget* room7Target9;				//var AGP_Gameplay.MarksmanTarget room7Target9;
	UPROPERTY()   AMarksmanTarget* room8Target1;				//var AGP_Gameplay.MarksmanTarget room8Target1;
	UPROPERTY()   AMarksmanTarget* room8Target2;				//var AGP_Gameplay.MarksmanTarget room8Target2;
	UPROPERTY()   AMarksmanTarget* room8Target3;				//var AGP_Gameplay.MarksmanTarget room8Target3;
	UPROPERTY()   AMarksmanTarget* room8Target4;				//var AGP_Gameplay.MarksmanTarget room8Target4;
	UPROPERTY()   AMarksmanTarget* room8Target5;				//var AGP_Gameplay.MarksmanTarget room8Target5;
	UPROPERTY()   AMarksmanTarget* room8Target6;				//var AGP_Gameplay.MarksmanTarget room8Target6;
	UPROPERTY()   AMarksmanTarget* room8Target7;				//var AGP_Gameplay.MarksmanTarget room8Target7;
	UPROPERTY()   AMarksmanTarget* room8Target8;				//var AGP_Gameplay.MarksmanTarget room8Target8;
	UPROPERTY()   AMarksmanTarget* room9Target1;				//var AGP_Gameplay.MarksmanTarget room9Target1;
	UPROPERTY()   AMarksmanTarget* room9Target2;				//var AGP_Gameplay.MarksmanTarget room9Target2;
	UPROPERTY()   AMarksmanTarget* room9Target3;				//var AGP_Gameplay.MarksmanTarget room9Target3;
	UPROPERTY()   AMarksmanTarget* room9Target4;				//var AGP_Gameplay.MarksmanTarget room9Target4;
	UPROPERTY()   AMarksmanTarget* room9Target5;				//var AGP_Gameplay.MarksmanTarget room9Target5;
	UPROPERTY()   AMarksmanTarget* room9Target6;				//var AGP_Gameplay.MarksmanTarget room9Target6;
	UPROPERTY()   AMarksmanTarget* room9Target7;				//var AGP_Gameplay.MarksmanTarget room9Target7;
	UPROPERTY()   AMarksmanTarget* room9Target8;				//var AGP_Gameplay.MarksmanTarget room9Target8;
	UPROPERTY()   AMarksmanTarget* room9Target9;				//var AGP_Gameplay.MarksmanTarget room9Target9;
	UPROPERTY()   AMarksmanTarget* room9Target10;				//var AGP_Gameplay.MarksmanTarget room9Target10;
	UPROPERTY()   float Room1TimerDelay;						//var float Room1TimerDelay;
	UPROPERTY()   float Room2TimerDelay;						//var float Room2TimerDelay;
	UPROPERTY()   float Room3TimerDelay;						//var float Room3TimerDelay;
	UPROPERTY()   float Room4TimerDelay;						//var float Room4TimerDelay;
	UPROPERTY()   float Room5TimerDelay;						//var float Room5TimerDelay;
	UPROPERTY()   float Room6TimerDelay;						//var float Room6TimerDelay;
	UPROPERTY()   float Room7TimerDelay;						//var float Room7TimerDelay;
	UPROPERTY()   float Room8TimerDelay;						//var float Room8TimerDelay;
	UPROPERTY()   float Room9TimerDelay;						//var float Room9TimerDelay;
	UPROPERTY()   float preTimerPause;							//var float preTimerPause;
	UPROPERTY()   float keepMovingIdleTime;						//var float keepMovingIdleTime;
	UPROPERTY()   AAGP_DumbEndPoint* aarLocation;				//var AGP_Gameplay.AGP_DumbEndPoint aarLocation;
	UPROPERTY()   bool interrupt;								//var bool interrupt;
	UPROPERTY()   bool interrupt2;								//var bool interrupt2;
	UPROPERTY()   bool breacherSpeech;							//var bool breacherSpeech;
	UPROPERTY()   int32 timerdelay;								//var int timerdelay;
	UPROPERTY()   int32 roundsFired;							//var int roundsFired;
	UPROPERTY()   int32 accuracyScore;							//var int accuracyScore;
	UPROPERTY()   int32 roundsRemaining;						//var int roundsRemaining;
	UPROPERTY()   int32 opforHit;								//var int opforHit;
	UPROPERTY()   int32 opforHitScore;							//var int opforHitScore;
	UPROPERTY()   bool bopforScoreDoubled;						//var bool bopforScoreDoubled;
	UPROPERTY()   int32 friendlyHit;							//var int friendlyHit;
	UPROPERTY()   int32 friendlyHitScore;						//var int friendlyHitScore;
	UPROPERTY()   int32 TotalScore;								//var int TotalScore;
	UPROPERTY()   FString timeOverall;							//var string timeOverall;
	UPROPERTY()   int32 timeOverallScore;						//var int timeOverallScore;
	UPROPERTY()   float TimeRemaining;							//var float TimeRemaining;
	UPROPERTY()   float timeKeeper;								//var float timeKeeper;
	UPROPERTY()   int32 targetA;								//var int targetA;
	UPROPERTY()   int32 targetB;								//var int targetB;
	UPROPERTY()   int32 targetC;								//var int targetC;
	UPROPERTY()   int32 opforRunningCount;						//var int opforRunningCount;
	UPROPERTY()   FString finalGo;								//var string finalGo;
	UPROPERTY()   FString finalNoGo;							//var string finalNoGo;
	UPROPERTY()   int32 goNoGo;									//var int goNoGo;
	UPROPERTY()   FString dateToday;							//var string dateToday;
	UPROPERTY()   FString UserName;								//var string UserName;
	UPROPERTY()   FString newTimer;								//var string newTimer;
	UPROPERTY()   FString dataUrl;								//var string dataUrl;
	UPROPERTY()   float aarReportDelay;							//var float aarReportDelay;
	UPROPERTY()   FString sWeaponAtCompletion;					//var string sWeaponAtCompletion;
	UPROPERTY()   int32 AmmoFadeTime;							//var int AmmoFadeTime;
	UPROPERTY()   bool bFlashed;								//var bool bFlashed;
	UPROPERTY()   bool bCanRunOutOfAmmo;						//var bool bCanRunOutOfAmmo;
	UPROPERTY()   bool bNoSecurityViolation;					//var bool bNoSecurityViolation;
	UPROPERTY()   float Accuracy;								//var float Accuracy;
	UPROPERTY()   float FlashTimerDelay;						//var float FlashTimerDelay;
	UPROPERTY()   float TargetFlipModifier;						//var float TargetFlipModifier;
	UPROPERTY()   bool bPlayedNoWeapVO;							//var bool bPlayedNoWeapVO;
	UPROPERTY()   bool bPlayedEntranceVO;						//var bool bPlayedEntranceVO;
	UPROPERTY()   bool bRoom1Flipped;							//var bool bRoom1Flipped;
	UPROPERTY()   bool bRoom2Flipped;							//var bool bRoom2Flipped;
	UPROPERTY()   bool bRoom3Flipped;							//var bool bRoom3Flipped;
	UPROPERTY()   bool bRoom4Flipped;							//var bool bRoom4Flipped;
	UPROPERTY()   bool bRoom5Flipped;							//var bool bRoom5Flipped;
	UPROPERTY()   bool bRoom6Flipped;							//var bool bRoom6Flipped;
	UPROPERTY()   bool bRoom7Flipped;							//var bool bRoom7Flipped;
	UPROPERTY()   bool bRoom8Flipped;							//var bool bRoom8Flipped;
	UPROPERTY()   bool bRoom9Flipped;							//var bool bRoom9Flipped;
	UPROPERTY()   bool bDonels6;								//var bool bDonels6;
	UPROPERTY()   bool bRestartls6;								//var bool bRestartls6;
	UPROPERTY()   bool bIntroed;								//var bool bIntroed;
	UPROPERTY()   bool bDisallowPickup;							//var bool bDisallowPickup;
	UPROPERTY()   FVector PlayerLocation;						//var FVector PlayerLocation;
	UPROPERTY()   FRotator PlayerRotation;						//var Object.Rotator PlayerRotation;
	UPROPERTY()   bool bWarned;									//var bool bWarned;
	UPROPERTY()   bool bLastViolation;							//var bool bLastViolation;
	UPROPERTY()   bool bWarnedPlay;								//var bool bWarnedPlay;
	UPROPERTY()   bool bHaveNotMoved;							//var bool bHaveNotMoved;
	UPROPERTY()   FName aarAnimName;							//var name aarAnimName;
	UPROPERTY()   FString UIClass;								//var string UIClass;
	UPROPERTY()   FString Msg1;									//var string Msg1;
	UPROPERTY()   FString Msg2;									//var string Msg2;

	bool DecoMesh_Damaged(ADecoMesh* NotifyActor, AActor* aInstigator, FString Parms);
	bool Pawn_Custom(APawn* NotifyActor, AActor* aInstigator, FString Parms);
	bool AGP_Pawn_Custom(AAGP_Pawn* NotifyActor, AActor* aInstigator, FString Parms);
	bool AGP_Character_Custom(AAGP_Character* NotifyActor, AActor* aInstigator, FString Parms);
	bool AGP_Weapon_Throw(AAGP_Weapon* NotifyActor, AActor* aInstigator, FString Parms);
	bool Pickup_PickedUp(APickup* NotifyActor, AActor* aInstigator, FString Parms);
	void doCantDrop();
	bool Pickup_AbortPickup(APickup* NotifyPickup, APawn* User);
	bool ThrowWeaponPickup_GrenadeEffects(AThrowWeaponPickup* Grenade);
	bool AGP_Character_Died(AAGP_Character* NotifyActor, AController* aInstigator);
	bool Pawn_Damaged(APawn* NotifyActor, AController* aInstigator);
	void Leavenworth();
	void PreInit();
	void doCantTouch();
	void PostPostInit();
	bool TriggerVolume_Enter(ATriggerVolume* Trigger, AActor* aInstigator);
	bool holsterTrigger_Enter(ATriggerVolume* Trigger, AActor* aInstigator);
	bool WeaponClearTrigger_Enter(ATriggerVolume* Trigger, AActor* aInstigator);
	void RemoveWeapons();
	void holsterweapon();
	bool cadreTrigger1_Enter(ATriggerVolume* Trigger, AActor* aInstigator);
	bool cadreTrigger2_Enter(ATriggerVolume* Trigger, AActor* aInstigator);
	bool cadreTrigger3_Enter(ATriggerVolume* Trigger, AActor* aInstigator);
	bool room1Trigger1_Enter(ATriggerVolume* Trigger, AActor* aInstigator);
	bool room1Trigger2_Enter(ATriggerVolume* Trigger, AActor* aInstigator);
	bool room1Trigger3_Enter(ATriggerVolume* Trigger, AActor* aInstigator);
	bool room2Trigger1_Enter(ATriggerVolume* Trigger, AActor* aInstigator);
	bool room2Trigger2_Enter(ATriggerVolume* Trigger, AActor* aInstigator);
	bool room2Trigger3_Enter(ATriggerVolume* Trigger, AActor* aInstigator);
	bool room3Trigger1_Enter(ATriggerVolume* Trigger, AActor* aInstigator);
	bool room3Trigger2_Enter(ATriggerVolume* Trigger, AActor* aInstigator);
	bool room3Trigger3_Enter(ATriggerVolume* Trigger, AActor* aInstigator);
	bool room4Trigger1_Enter(ATriggerVolume* Trigger, AActor* aInstigator);
	bool room4Trigger2_Enter(ATriggerVolume* Trigger, AActor* aInstigator);
	bool room4Trigger3_Enter(ATriggerVolume* Trigger, AActor* aInstigator);
	bool room4Trigger4_Enter(ATriggerVolume* Trigger, AActor* aInstigator);
	bool room5Trigger1_Enter(ATriggerVolume* Trigger, AActor* aInstigator);
	bool room5Trigger2_Enter(ATriggerVolume* Trigger, AActor* aInstigator);
	bool room5Trigger3_Enter(ATriggerVolume* Trigger, AActor* aInstigator);
	bool room6Trigger1_Enter(ATriggerVolume* Trigger, AActor* aInstigator);
	bool room6Trigger2_Enter(ATriggerVolume* Trigger, AActor* aInstigator);
	bool room6Trigger3_Enter(ATriggerVolume* Trigger, AActor* aInstigator);
	bool room7Trigger1_Enter(ATriggerVolume* Trigger, AActor* aInstigator);
	bool room7Trigger2_Enter(ATriggerVolume* Trigger, AActor* aInstigator);
	bool room7Trigger3_Enter(ATriggerVolume* Trigger, AActor* aInstigator);
	bool room8Trigger1_Enter(ATriggerVolume* Trigger, AActor* aInstigator);
	bool room8Trigger2_Enter(ATriggerVolume* Trigger, AActor* aInstigator);
	bool room8Trigger3_Enter(ATriggerVolume* Trigger, AActor* aInstigator);
	bool room9Trigger1_Enter(ATriggerVolume* Trigger, AActor* aInstigator);
	bool room9Trigger2_Enter(ATriggerVolume* Trigger, AActor* aInstigator);
	bool room9Trigger3_Enter(ATriggerVolume* Trigger, AActor* aInstigator);
	bool authTrigger_Enter(ATriggerVolume* Trigger, AActor* aInstigator);
	bool PlayerHasWeapon(APawn* Player);
	bool breacherTrigger_Enter(ATriggerVolume* Trigger, AActor* aInstigator);
	bool Timer_Timer(FName Name);
	bool Timer_Sound(FName Name);
	bool DoorTrigger_UsedBy(ADoorTrigger* Trigger, AActor* aInstigator);
	bool doorTrigger1_UsedBy(ADoorTrigger* Trigger, AActor* aInstigator);
	bool doorTrigger2_UsedBy(ADoorTrigger* Trigger, AActor* aInstigator);
	bool doorTrigger3_UsedBy(ADoorTrigger* Trigger, AActor* aInstigator);
	bool doorTrigger4_UsedBy(ADoorTrigger* Trigger, AActor* aInstigator);
	bool doorTrigger5_UsedBy(ADoorTrigger* Trigger, AActor* aInstigator);
	bool doorTrigger6_UsedBy(ADoorTrigger* Trigger, AActor* aInstigator);
	bool doorTrigger7_UsedBy(ADoorTrigger* Trigger, AActor* aInstigator);
	bool doorTrigger8_UsedBy(ADoorTrigger* Trigger, AActor* aInstigator);
	bool doorTrigger9_UsedBy(ADoorTrigger* Trigger, AActor* aInstigator);
	bool AGP_UseTrigger_UsedBy(AAGP_UseTrigger* Trigger, AActor* aInstigator);
	bool cadreUseTrigger1_UsedBy(AAGP_UseTrigger* Trigger, AActor* aInstigator);
	bool inspectUseTrigger_UsedBy(AAGP_UseTrigger* Trigger, AActor* aInstigator);
	bool cadreUseTrigger2_UsedBy(AAGP_UseTrigger* Trigger, AActor* aInstigator);
	bool cadreUseTrigger3_UsedBy(AAGP_UseTrigger* Trigger, AActor* aInstigator);
	void StopVO();
	void DoIntroLSVO(APawn* Target, FName LSAnim);
	bool sbUseTrigger_UsedBy(AAGP_UseTrigger* Trigger, AActor* aInstigator);
	bool skipVOTrigger_UsedBy(AAGP_UseTrigger* Trigger, AActor* aInstigator);
	void FinishCadreVO();
	bool Timer_LSAnim(FName Name);
	void EventLabTick(float DeltaTime);
	void flipTargets();
	bool AGP_Weapon_Fire(AAGP_Weapon* NotifyActor, AActor* aInstigator, FString Parms);
	bool AGP_Weapon_Trace_Hit(AAGP_Weapon* NotifyActor, AActor* HitActor, FString Parms);
	void SecurityViolation();
	void SecurityViolationPart2();
	void JumpToAAR();
	void JumpToAARFadeIn();
	void OutOfAmmoFadeIn();
	void OutOfTime();
	void PlayKeepMoving();
	void CheckPlayerMove();
	void RestartLevel();
	void StartCountDown();
	bool DamageDetector_Damaged(ADamageDetector* NotifyActor, AActor* aInstigator, FString Parms);
	void RoomFlashed(ADamageDetector* NotifyActor);
	void FlashedTime();
	void StartRoom();
	bool MarksmanTarget_Damaged(AMarksmanTarget* NotifyActor, AActor* aInstigator, FString Parms);
	bool exitRedState(int32 opforNum);
	bool aarScoreboard();
	bool uploadStats();
	void DoWeapClearVO();
	void UnlockPlayer();
};
