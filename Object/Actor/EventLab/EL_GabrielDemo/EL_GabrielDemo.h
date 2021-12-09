// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/EventLab/EventLab.h"
#include "EL_GabrielDemo.generated.h"

class AAGP_PlayerStart;
class ANPC_Ambient;

UCLASS()
class AEL_GabrielDemo : public AEventLab
{
	GENERATED_BODY()
public:
	AEL_GabrielDemo();

	UPROPERTY()												bool bBlackHawkBusy;							//var bool bBlackHawkBusy;
	UPROPERTY()												AAGP_PlayerStart* PlayerStartLocation;			//var AGP.AGP_PlayerStart PlayerStartLocation;
	//UPROPERTY()											AEEBlackHawk* blackhawk;						//var AGP_Gameplay.EEBlackHawk blackhawk;
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

};
