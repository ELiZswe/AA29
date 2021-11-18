// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/EventLab/EventLab.h"
#include "EL_EscapeAndEvade.generated.h"

class ANoiseMarker;
class AGP_UseTrigger;
class AAGP_NPC;
class ACameraPoint;
class AGP_Objective;
class AAGP_UseTrigger;

UCLASS()
class AA29_API AEL_EscapeAndEvade : public AEventLab
{
	GENERATED_BODY()
public:
	AEL_EscapeAndEvade();


	UPROPERTY()												AAGP_UseTrigger* MusicTrigger;					//var AGP.AGP_UseTrigger MusicTrigger;
	UPROPERTY()												bool bPlayingMusic;								//var bool bPlayingMusic;
	UPROPERTY()												FName StartLocationTag;							//var name StartLocationTag;
	UPROPERTY()												FName LastLocationTag;							//var name LastLocationTag;
	UPROPERTY()												AAGP_NPC* Scout;								//var AGP_Characters.AGP_NPC Scout;
	UPROPERTY()												ACameraPoint* Cam06;							//var AGP_Gameplay.CameraPoint Cam06;
	UPROPERTY()												ACameraPoint* Cam05;							//var AGP_Gameplay.CameraPoint Cam05;
	UPROPERTY()												ACameraPoint* Cam04;							//var AGP_Gameplay.CameraPoint Cam04;
	UPROPERTY()												ACameraPoint* Cam03;							//var AGP_Gameplay.CameraPoint Cam03;
	UPROPERTY()												ACameraPoint* Cam02;							//var AGP_Gameplay.CameraPoint Cam02;
	UPROPERTY()												ACameraPoint* Cam01;							//var AGP_Gameplay.CameraPoint Cam01;
	UPROPERTY()												AAGP_Objective* CheckpointC;					//var AGP.AGP_Objective CheckpointC;
	UPROPERTY()												AAGP_Objective* CheckpointB;					//var AGP.AGP_Objective CheckpointB;
	UPROPERTY()												AAGP_Objective* CheckpointA;					//var AGP.AGP_Objective CheckpointA;
	UPROPERTY()												AAGP_UseTrigger* TruckUse;						//var AGP.AGP_UseTrigger TruckUse;
	//UPROPERTY()												AEEBlackHawk* blackhawk;					//var AGP_Gameplay.EEBlackHawk blackhawk;
	//UPROPERTY()												TArray<ANPC_EEGuard*> Guards;				//var array<NPC_EEGuard> Guards;
	UPROPERTY()												int32 ViewedCinematicCount;						//var int ViewedCinematicCount;
	UPROPERTY()												FString MissionTime;							//var string MissionTime;
	UPROPERTY()												float FOVTweenTime;								//var float FOVTweenTime;
	UPROPERTY()												float EndFOV;									//var float EndFOV;
	UPROPERTY()												float StartFOV;									//var float StartFOV;
	UPROPERTY()												TArray<FBoneProfile> PlayerBones;				//var array<BoneProfile> PlayerBones;
	UPROPERTY()												TArray<USoundBase*> DogAmbient;					//var array<Sound> DogAmbient;
	UPROPERTY()												TArray<USoundBase*> RareAmbient;				//var array<Sound> RareAmbient;
	UPROPERTY()												TArray<USoundBase*> CommonAmbient;				//var array<Sound> CommonAmbient;
	UPROPERTY()												TArray<float> PlayerVelocities;					//var array<float> PlayerVelocities;
	UPROPERTY()												EPlayerPosture PlayerPosture;					//var EPlayerPosture PlayerPosture;
	UPROPERTY()												ANoiseMarker* SoundMarkers;						//var AGP_Gameplay.NoiseMarker SoundMarkers;
	UPROPERTY()												float VolumeRisk;								//var float VolumeRisk;
	UPROPERTY()												float PlayerAudibility;							//var float PlayerAudibility;
	UPROPERTY()												float PlayerVisibility;							//var float PlayerVisibility;
	UPROPERTY()												int32 AvgVelCounter;							//var int AvgVelCounter;
	UPROPERTY()												float AverageVelocity;							//var float AverageVelocity;
	UPROPERTY()												float AvgVelOldTime;							//var float AvgVelOldTime;
	UPROPERTY()												float PlayerStealth;							//var float PlayerStealth;
	UPROPERTY()												float PlayerVelocity;							//var float PlayerVelocity;
	UPROPERTY()												bool bDisableAmbient;							//var bool bDisableAmbient;
	UPROPERTY()												TArray<USoundBase*> BustedSounds;				//var array<Sound> BustedSounds;
	UPROPERTY()												TArray<USoundBase*> FalseSounds;				//var array<Sound> FalseSounds;
	UPROPERTY()												TArray<USoundBase*> SeeSounds;					//var array<Sound> SeeSounds;
	UPROPERTY()												TArray<USoundBase*> HearSounds;					//var array<Sound> HearSounds;
	UPROPERTY(EditAnywhere)									bool bStartAtEnd;								//var() bool bStartAtEnd;
	UPROPERTY(EditAnywhere)									bool bSkipIntro;								//var() bool bSkipIntro;
	UPROPERTY(EditAnywhere)									bool bDisableGuardScript;						//var() bool bDisableGuardScript;
	UPROPERTY(EditAnywhere)									bool bUseDeathCameras;							//var() bool bUseDeathCameras;
	UPROPERTY(EditAnywhere)									EAlertLanguage AlertLanguage;					//var() EAlertLanguage AlertLanguage;
	UPROPERTY(EditAnywhere, Category = "GuardSounds")		TArray<USoundBase*> OpforBustedSounds;			//var(GuardSounds) array<Sound> OpforBustedSounds;
	UPROPERTY(EditAnywhere, Category = "GuardSounds")		TArray<USoundBase*> OpforFalseSounds;			//var(GuardSounds) array<Sound> OpforFalseSounds;
	UPROPERTY(EditAnywhere, Category = "GuardSounds")		TArray<USoundBase*> OpforSeeSounds;				//var(GuardSounds) array<Sound> OpforSeeSounds;
	UPROPERTY(EditAnywhere, Category = "GuardSounds")		TArray<USoundBase*> OpforHearSounds;			//var(GuardSounds) array<Sound> OpforHearSounds;
	UPROPERTY(EditAnywhere, Category = "GuardSounds")		TArray<USoundBase*> BlueforBustedSounds;		//var(GuardSounds) array<Sound> BlueforBustedSounds;
	UPROPERTY(EditAnywhere, Category = "GuardSounds")		TArray<USoundBase*> BlueforFalseSounds;			//var(GuardSounds) array<Sound> BlueforFalseSounds;
	UPROPERTY(EditAnywhere, Category = "GuardSounds")		TArray<USoundBase*> BlueforSeeSounds;			//var(GuardSounds) array<Sound> BlueforSeeSounds;
	UPROPERTY(EditAnywhere, Category = "GuardSounds")		TArray<USoundBase*> BlueforHearSounds;			//var(GuardSounds) array<Sound> BlueforHearSounds;


};
