// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/EventLab/EventLab.h"
#include "EL_JavelinTraining.generated.h"

class ANPC_ACUBasicSoldier;
class AAGP_Sound;
class AAGP_Viewpoint;
class APickup;
class AAGP_Weapon;
class ATextDisplay;
class ATeleporter;



UCLASS()
class AA29_API AEL_JavelinTraining : public AEventLab
{
	GENERATED_BODY()
public:
	AEL_JavelinTraining();

	UPROPERTY()														bool bHelpIcon;									//var bool bHelpIcon;
	UPROPERTY()														bool bAllowCheats;								//var bool bAllowCheats;
	UPROPERTY()														float PlayTipDisplayTime;						//var float PlayTipDisplayTime;
	UPROPERTY()														float MaxJavelinFlyoutTime;						//var float MaxJavelinFlyoutTime;
	UPROPERTY()														UStaticMesh* PCtoCLUWire2;						//var StaticMeshActor PCtoCLUWire2;
	UPROPERTY()														UStaticMesh* PCtoCLUWire1;						//var StaticMeshActor PCtoCLUWire1;
	UPROPERTY()														UStaticMesh* Javelin_Assembled;					//var StaticMeshActor Javelin_Assembled;
	UPROPERTY()														bool bFirstLock;								//var bool bFirstLock;
	UPROPERTY()														int32 NumNoLock;								//var int NumNoLock;
	UPROPERTY()														bool bLengthyLockVO;							//var bool bLengthyLockVO;
	UPROPERTY()														int32 IdleWarn;									//var int IdleWarn;
	UPROPERTY()														bool bEnteredTent;								//var bool bEnteredTent;
	UPROPERTY()														bool bJLoadedAndCrouchedOnce;					//var bool bJLoadedAndCrouchedOnce;
	UPROPERTY()														bool bBSTLoaded;								//var bool bBSTLoaded;
	UPROPERTY()														bool bUserCrouched;								//var bool bUserCrouched;
	UPROPERTY()														bool bBSTReloadedOnce;							//var bool bBSTReloadedOnce;
	UPROPERTY()														bool bCLUCycled;								//var bool bCLUCycled;
	UPROPERTY()														bool bJTShouldered;								//var bool bJTShouldered;
	UPROPERTY()														bool bReadyForOpportunity;						//var bool bReadyForOpportunity;
	UPROPERTY()														bool bPassedBST;								//var bool bPassedBST;
	UPROPERTY()														bool bInTent;									//var bool bInTent;
	UPROPERTY()														bool bInLF;										//var bool bInLF;
	UPROPERTY()														bool bInVirtual;								//var bool bInVirtual;
	UPROPERTY()														bool bInBST;									//var bool bInBST;
	UPROPERTY(EditAnywhere)											float LFSpeakerRadius;							//var() float LFSpeakerRadius;
	UPROPERTY(EditAnywhere)											float LFSpeakerVolume;							//var() float LFSpeakerVolume;
	UPROPERTY()														AAGP_Sound* Speaker_LF05;						//var AGP_Gameplay.AGP_Sound Speaker_LF05;
	UPROPERTY()														AAGP_Sound* Speaker_LF04;						//var AGP_Gameplay.AGP_Sound Speaker_LF04;
	UPROPERTY()														AAGP_Sound* Speaker_LF03;						//var AGP_Gameplay.AGP_Sound Speaker_LF03;
	UPROPERTY()														AAGP_Sound* Speaker_LF02;						//var AGP_Gameplay.AGP_Sound Speaker_LF02;
	UPROPERTY()														AAGP_Sound* Speaker_LF01;						//var AGP_Gameplay.AGP_Sound Speaker_LF01;
	UPROPERTY()														AAGP_Viewpoint* BSTRangeLockpoint;				//var AGP_Viewpoint BSTRangeLockpoint;
	UPROPERTY()														ATeleporter* ScoreboardLockpoint;				//var Teleporter ScoreboardLockpoint;
	UPROPERTY()														ATeleporter* LiveFireLockpoint;					//var Teleporter LiveFireLockpoint;
	UPROPERTY()														ATeleporter* TentLockpoint;						//var Teleporter TentLockpoint;
	UPROPERTY()														FString LFTimeTotal;							//var string LFTimeTotal;
	UPROPERTY()														int32 LFFinalScore;								//var int LFFinalScore;
	UPROPERTY()														int32 LFTimeScore;								//var int LFTimeScore;
	UPROPERTY()														int32 LFAccuracyScore;							//var int LFAccuracyScore;
	UPROPERTY()														int32 LFTubeScore;								//var int LFTubeScore;
	UPROPERTY()														int32 LFValidScore;								//var int LFValidScore;
	UPROPERTY()														int32 LFInvalidScore;							//var int LFInvalidScore;
	UPROPERTY()														ATextDisplay* aarDisplay;						//var AGP_Gameplay.TextDisplay aarDisplay;
	UPROPERTY()														bool bFailLFZone;								//var bool bFailLFZone;
	UPROPERTY()														bool bLFInSafeZone;								//var bool bLFInSafeZone;
	UPROPERTY()														float LFStopTime;								//var float LFStopTime;
	UPROPERTY()														float LFStartTime;								//var float LFStartTime;
	UPROPERTY()														int32 LFAccuracy;								//var int LFAccuracy;
	UPROPERTY()														int32 LFTubesUsed;								//var int LFTubesUsed;
	UPROPERTY()														int32 LFInvalidTargetsHit;						//var int LFInvalidTargetsHit;
	UPROPERTY()														int32 LFValidTargetsHit;						//var int LFValidTargetsHit;
	UPROPERTY(EditAnywhere, Category = "JavelinTraining")			int32 LFInitialTubes;							//var(JavelinTraining) int LFInitialTubes;
	UPROPERTY(EditAnywhere, Category = "JavelinTraining")			int32 LFInitialValidTargets;					//var(JavelinTraining) int LFInitialValidTargets;
	UPROPERTY(EditAnywhere, Category = "JavelinTraining")			float LFCourseTimeLimit;						//var(JavelinTraining) float LFCourseTimeLimit;
	UPROPERTY()														FLFTargetStruct LFTargetGroup;					//var EL_JavelinTraining.LFTargetStruct LFTargetGroup;
	UPROPERTY(EditAnywhere, Category = "JavelinTraining")			float VirtualCourseTimeLimit;					//var(JavelinTraining) float VirtualCourseTimeLimit;
	UPROPERTY()														int32 NumVirtualTargetsHit;						//var int NumVirtualTargetsHit;
	UPROPERTY(EditAnywhere, Category = "JavelinTraining")			int32 NumVirtualTargets;						//var(JavelinTraining) int NumVirtualTargets;
	//UPROPERTY()													TArray<AAGP_VehicleFactory*> BSTValidFactory;	//var array<AGP_VehicleFactory> BSTValidFactory;
	//UPROPERTY()													TArray<AAGP_VehicleFactory*> BSTInvalidFactory;	//var array<AGP_VehicleFactory> BSTInvalidFactory;
	//UPROPERTY()													AAGP_VehicleFactory* target2;					//var AGP_Vehicles.AGP_Vehicle target2;
	//UPROPERTY()													AAGP_VehicleFactory* Target1;					//var AGP_Vehicles.AGP_Vehicle Target1;
	//UPROPERTY()													AAGP_VehicleFactory* TargetFactory2;			//var AGP_Vehicles.AGP_VehicleFactory TargetFactory2;
	//UPROPERTY()													AAGP_VehicleFactory* TargetFactory1;			//var AGP_Vehicles.AGP_VehicleFactory TargetFactory1;
	UPROPERTY()														USoundBase* WelcomeSound;						//var Sound WelcomeSound;
	UPROPERTY()														USoundBase* CurrentLFEncouragement;				//var Sound CurrentLFEncouragement;
	UPROPERTY()														USoundBase* PlayerDiedNotLFSound;				//var Sound PlayerDiedNotLFSound;
	UPROPERTY()														USoundBase* LFInstructorSound;					//var Sound LFInstructorSound;
	UPROPERTY()														USoundBase* BSTInstructorSound;					//var Sound BSTInstructorSound;
	UPROPERTY()														int32 LengthLFEcho;								//var int LengthLFEcho;
	UPROPERTY()														float LengthDelay;								//var float LengthDelay;
	UPROPERTY()														float LengthPlayerDiedNotLFSound;				//var float LengthPlayerDiedNotLFSound;
	UPROPERTY()														float LengthLFInstructor;						//var float LengthLFInstructor;
	UPROPERTY()														float LengthTentInstructor;						//var float LengthTentInstructor;
	UPROPERTY()														float LengthBSTInstructor;						//var float LengthBSTInstructor;
	UPROPERTY()														float LengthLFSignUpInstructor;					//var float LengthLFSignUpInstructor;
	UPROPERTY()														APickup* LFCLU;									//var Pickup LFCLU;
	UPROPERTY()														APickup* JTube;									//var Pickup JTube;
	UPROPERTY()														APickup* BSTCLU;								//var Pickup BSTCLU;
	UPROPERTY()														AAGP_Weapon* USERJT;							//var AGP.AGP_Weapon USERJT;
	UPROPERTY()														AAGP_Weapon* USERCLU;							//var AGP.AGP_Weapon USERCLU;
	UPROPERTY()														uint8 BinkVolume;								//var byte BinkVolume;
	UPROPERTY()														AAGP_Sound* BinkSound;							//var AGP_Gameplay.AGP_Sound BinkSound;
	UPROPERTY()														FString LFSkipIntroUseTip;						//var string LFSkipIntroUseTip;
	UPROPERTY()														FString LiveFireSignUpUseTip;					//var string LiveFireSignUpUseTip;
	UPROPERTY()														FString TentInstructorUseTip;					//var string TentInstructorUseTip;
	UPROPERTY()														AAGP_UseTrigger* LFSkipIntroTrigger;			//var AGP.AGP_UseTrigger LFSkipIntroTrigger;
	UPROPERTY()														AAGP_UseTrigger* sbUseTrigger;					//var AGP.AGP_UseTrigger sbUseTrigger;
	UPROPERTY()														AAGP_UseTrigger* LiveFireSignUpTrigger;			//var AGP.AGP_UseTrigger LiveFireSignUpTrigger;
	UPROPERTY()														AAGP_UseTrigger* TentInstructorTrigger;			//var AGP.AGP_UseTrigger TentInstructorTrigger;
	UPROPERTY()														AAGP_UseTrigger* BST_Instructor_Trigger;		//var AGP.AGP_UseTrigger BST_Instructor_Trigger;
	UPROPERTY()														ATriggerVolume* TentVolume;						//var AGP_Gameplay.TriggerVolume TentVolume;
	UPROPERTY()														ATriggerVolume* Tent_Instructor_Volume;			//var AGP_Gameplay.TriggerVolume Tent_Instructor_Volume;
	UPROPERTY()														ATriggerVolume* BST_Instructor_Volume;			//var AGP_Gameplay.TriggerVolume BST_Instructor_Volume;
	UPROPERTY()														ATriggerVolume* TVolumeLFTargets05;				//var AGP_Gameplay.TriggerVolume TVolumeLFTargets05;
	UPROPERTY()														ATriggerVolume* TVolumeLFTargets04;				//var AGP_Gameplay.TriggerVolume TVolumeLFTargets04;
	UPROPERTY()														ATriggerVolume* TVolumeLFTargets03;				//var AGP_Gameplay.TriggerVolume TVolumeLFTargets03;
	UPROPERTY()														ATriggerVolume* TVolumeLFTargets02;				//var AGP_Gameplay.TriggerVolume TVolumeLFTargets02;
	UPROPERTY()														ATriggerVolume* TVolumeLF05;					//var AGP_Gameplay.TriggerVolume TVolumeLF05;
	UPROPERTY()														ATriggerVolume* TVolumeLF04;					//var AGP_Gameplay.TriggerVolume TVolumeLF04;
	UPROPERTY()														ATriggerVolume* TVolumeLF03;					//var AGP_Gameplay.TriggerVolume TVolumeLF03;
	UPROPERTY()														ATriggerVolume* TVolumeLF02;					//var AGP_Gameplay.TriggerVolume TVolumeLF02;
	UPROPERTY()														ATriggerVolume* TVolumeLF01;					//var AGP_Gameplay.TriggerVolume TVolumeLF01;
	UPROPERTY()														ANPC_ACUBasicSoldier* LFSignUp_Instructor;		//var AGP_Characters.NPC_ACUBasicSoldier LFSignUp_Instructor;
	UPROPERTY()														ANPC_ACUBasicSoldier* Tent_Instructor;			//var AGP_Characters.NPC_ACUBasicSoldier Tent_Instructor;
	UPROPERTY()														ANPC_ACUBasicSoldier* BST_Instructor;			//var AGP_Characters.NPC_ACUBasicSoldier BST_Instructor;

};
