// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/EventLab/EventLab.h"
#include "EL_GabrielDemo.generated.h"

class AAGP_PlayerStart;
class ANPC_Ambient;
class AEEBlackHawk;

class AAGP_UseTrigger;
class ASceneManager;
UCLASS()
class AEL_GabrielDemo : public AEventLab
{
	GENERATED_BODY()

public:
	AEL_GabrielDemo();

	UPROPERTY()												bool bBlackHawkBusy;							//var bool bBlackHawkBusy;
	UPROPERTY()												AAGP_PlayerStart* PlayerStartLocation;			//var AGP.AGP_PlayerStart PlayerStartLocation;
	UPROPERTY()												AEEBlackHawk* blackhawk;						//var AGP_Gameplay.EEBlackHawk blackhawk;
	UPROPERTY()												ATriggerVolume* SodaGuy_Trigger;				//var AGP_Gameplay.TriggerVolume SodaGuy_Trigger;
	UPROPERTY()												USoundBase* SodaGuySound;						//var Sound SodaGuySound;
	UPROPERTY()												ANPC_Ambient* SodaMachine;						//var AGP_Characters.NPC_Ambient SodaMachine;
	UPROPERTY()												ANPC_Ambient* SodaGuy;							//var AGP_Characters.NPC_Ambient SodaGuy;
	UPROPERTY()												TArray<FHeliPath> HeliPaths;					//var array<HeliPath> HeliPaths;
	UPROPERTY()												TArray<FLevelTrigger> LevelTriggers;			//var array<LevelTrigger> LevelTriggers;
	UPROPERTY()												TArray<FMissionInfo> Missions;					//var array<MissionInfo> Missions;
	UPROPERTY()												TArray<UMaterialInstance*> StatusImages;		//var array<Texture> StatusImages;
	UPROPERTY()												TArray<FLevelTex> LevelImages;					//var array<LevelTex> LevelImages;
	UPROPERTY()												TArray<FTeamMember> Team;						//var array<TeamMember> Team;
	UPROPERTY()												TArray<FName> SFIntelligence_Idles;				//var array<name> SFIntelligence_Idles;
	UPROPERTY()												TArray<FName> SFCommunications_Idles;			//var array<name> SFCommunications_Idles;
	UPROPERTY()												TArray<FName> SFMedical_Idles;					//var array<name> SFMedical_Idles;
	UPROPERTY()												TArray<FName> SFEngineer_Idles;					//var array<name> SFEngineer_Idles;
	UPROPERTY()												TArray<FName> SFWeapons_Idles;					//var array<name> SFWeapons_Idles;
	UPROPERTY()												TArray<FName> SFSergeant_Idles;					//var array<name> SFSergeant_Idles;
	UPROPERTY()												TArray<FName> SFCommander_Idles;				//var array<name> SFCommander_Idles;
	UPROPERTY()												TArray<FName> SFLeader_Idles;					//var array<name> SFLeader_Idles;
	UPROPERTY()												uint8 SFIntelligence_ConvIndex;					//var byte SFIntelligence_ConvIndex;
	UPROPERTY()												uint8 SFCommunications_ConvIndex;				//var byte SFCommunications_ConvIndex;
	UPROPERTY()												uint8 SFMedical_ConvIndex;						//var byte SFMedical_ConvIndex;
	UPROPERTY()												uint8 SFEngineer_ConvIndex;						//var byte SFEngineer_ConvIndex;
	UPROPERTY()												uint8 SFWeapons_ConvIndex;						//var byte SFWeapons_ConvIndex;
	UPROPERTY()												uint8 SFSergeant_ConvIndex;						//var byte SFSergeant_ConvIndex;
	UPROPERTY()												uint8 SFCommander_ConvIndex;					//var byte SFCommander_ConvIndex;
	UPROPERTY()												uint8 SFLeader_ConvIndex;						//var byte SFLeader_ConvIndex;
	UPROPERTY(Config)										int32 SF132;									//var config int SF132;
	UPROPERTY(Config)										int32 SF324;									//var config int SF324;
	UPROPERTY(Config)										int32 SF843;									//var config int SF843;
	UPROPERTY(Config)										int32 SF292;									//var config int SF292;
	UPROPERTY(Config)										int32 SF468;									//var config int SF468;
	UPROPERTY(Config)										int32 SF572;									//var config int SF572;
	UPROPERTY(Config)										int32 SF624;									//var config int SF624;
	UPROPERTY(Config)										int32 SF785;									//var config int SF785;
	UPROPERTY()												FCSound ChopperSound;							//var EL_GabrielDemo.CSound ChopperSound;

	bool AGP_UseTrigger_UsedBy(AAGP_UseTrigger* Trigger, AActor* aInstigator);
	bool SF18A_UsedBy(AAGP_UseTrigger* Trigger, AActor* aInstigator);
	bool SF180_UsedBy(AAGP_UseTrigger* Trigger, AActor* aInstigator);
	bool SF18Z_UsedBy(AAGP_UseTrigger* Trigger, AActor* aInstigator);
	bool SF18B_UsedBy(AAGP_UseTrigger* Trigger, AActor* aInstigator);
	bool SF18C_UsedBy(AAGP_UseTrigger* Trigger, AActor* aInstigator);
	bool SF18D_UsedBy(AAGP_UseTrigger* Trigger, AActor* aInstigator);
	bool SF18E_UsedBy(AAGP_UseTrigger* Trigger, AActor* aInstigator);
	bool SF18F_UsedBy(AAGP_UseTrigger* Trigger, AActor* aInstigator);
	bool LevelTrigger_AVWID_UsedBy(AAGP_UseTrigger* Trigger, AActor* aInstigator);
	bool LevelTrigger_EANDE_UsedBy(AAGP_UseTrigger* Trigger, AActor* aInstigator);
	bool LevelTrigger_LANGUAGE_UsedBy(AAGP_UseTrigger* Trigger, AActor* aInstigator);
	bool LevelTrigger_SURVIVAL_UsedBy(AAGP_UseTrigger* Trigger, AActor* aInstigator);
	bool LevelTrigger_SFWEAPONS_UsedBy(AAGP_UseTrigger* Trigger, AActor* aInstigator);
	bool TriggerVolume_Enter(ATriggerVolume* Trigger, AActor* aInstigator);
	bool SF18A_Trigger_Enter(ATriggerVolume* Trigger, AActor* aInstigator);
	bool SF180_Trigger_Enter(ATriggerVolume* Trigger, AActor* aInstigator);
	bool SF18Z_Trigger_Enter(ATriggerVolume* Trigger, AActor* aInstigator);
	bool SF18B_Trigger_Enter(ATriggerVolume* Trigger, AActor* aInstigator);
	bool SF18C_Trigger_Enter(ATriggerVolume* Trigger, AActor* aInstigator);
	bool SF18D_Trigger_Enter(ATriggerVolume* Trigger, AActor* aInstigator);
	bool SF18E_Trigger_Enter(ATriggerVolume* Trigger, AActor* aInstigator);
	bool SF18F_Trigger_Enter(ATriggerVolume* Trigger, AActor* aInstigator);
	bool TriggerVolume_Exit(ATriggerVolume* Trigger, AActor* aInstigator);
	bool SF18A_Trigger_Exit(ATriggerVolume* Trigger, AActor* aInstigator);
	bool SF180_Trigger_Exit(ATriggerVolume* Trigger, AActor* aInstigator);
	bool SF18Z_Trigger_Exit(ATriggerVolume* Trigger, AActor* aInstigator);
	bool SF18B_Trigger_Exit(ATriggerVolume* Trigger, AActor* aInstigator);
	bool SF18C_Trigger_Exit(ATriggerVolume* Trigger, AActor* aInstigator);
	bool SF18D_Trigger_Exit(ATriggerVolume* Trigger, AActor* aInstigator);
	bool SF18E_Trigger_Exit(ATriggerVolume* Trigger, AActor* aInstigator);
	bool SF18F_Trigger_Exit(ATriggerVolume* Trigger, AActor* aInstigator);
	bool SceneManager_SceneStart(ASceneManager* NotifyActor, AActor* aInstigator, FString Parms);
	bool SceneManager_SceneEnd(ASceneManager* NotifyActor, AActor* aInstigator, FString Parms);
	bool TeamTriggerEnter(int32 TeamIndex);
	bool TeamTriggerExit(int32 TeamIndex);
	bool TeamUse(int32 TeamIndex);
	bool LevelTriggerUse(int32 iLevel);
	void PreInit();
	void Init();
	void PostInit();
	void PostPostInit();
	void EventLabTick(float DeltaTime);
	void ChopperDoFadeUp(float Time);
	void ChopperDoFadeDown(float Time);
	void FadeChopperSoundUp(float DeltaTime);
	void FadeChopperSoundDown(float DeltaTime);
	void InitChopper();
	void ChopperFlyBy();
	FName ChooseHeliPath();
	void ResetHeliPaths();
	void UpdateTeamUseTrigger(uint8 TeamIndex);
	void InitTeamTriggers();
	void UpdateMissionStatus();
	uint8 GetMissionStatus(uint8 iLevel);
	bool CanEnterLevel(uint8 iLevel);
	bool PlayerIsQualified(uint8 iLevel);
	FString GetRequiredTour(uint8 iLevel);
	int32 GetRequiredConversation(uint8 iLevel, uint8 iMemberIndex);
	FString GetTeamTitle(int32 TeamIndex);
	bool DidHearTeamDemo(int32 TeamIndex);
	bool DidHearLevelDemos(uint8 iLevel);
	bool SodaGuy_Trigger_Enter(ATriggerVolume* Trigger, AActor* aInstigator);
	bool OutOfBounds_Trigger_Enter(ATriggerVolume* Trigger, AActor* aInstigator);
	bool Timer_Timer(FName Name);
	void DisableTeamUseTriggers();
	void EnableTeamUseTriggers();
	void DisableTeamVolTriggers();
	void EnableTeamVolTriggers();
	void SetLevelStatus(uint8 iLevel, uint8 Status);
	int32 GetTeamCode(int32 TeamIndex);
	void SetTeamCode(int32 TeamIndex);
	FRotator RandLookRotation();
	void StopLipSincAnims();



};
