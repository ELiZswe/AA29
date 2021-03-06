// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/ReplicationInfo.h"
#include "GameReplicationInfo.generated.h"

class ATeamInfo;
class AVoiceChatReplicationInfo;
class AVehicleReplicationInfo;
class AAA2_PlayerState;
class UPlayInfo;

UCLASS()
class AGameReplicationInfo : public AReplicationInfo
{
	GENERATED_BODY()
public:
	AGameReplicationInfo();

	UPROPERTY()								FString								GameName;									//var FString GameName;
	UPROPERTY()								FString								GameClass;									//var FString GameClass;
	UPROPERTY()								bool								bTeamGame;									//var bool bTeamGame;
	UPROPERTY()								bool								bStopCountDown;								//var bool bStopCountDown;
	UPROPERTY()								bool								bMatchHasBegun;								//var bool bMatchHasBegun;
	UPROPERTY()								bool								bTeamSymbolsUpdated;						//var bool bTeamSymbolsUpdated;
	UPROPERTY()								bool								bNoTeamSkins;								//var bool bNoTeamSkins;
	UPROPERTY()								bool								bForceTeamSkins;							//var bool bForceTeamSkins;
	UPROPERTY()								bool								bForceNoPlayerLights;						//var bool bForceNoPlayerLights;
	UPROPERTY()								bool								bAllowPlayerLights;							//var bool bAllowPlayerLights;
	UPROPERTY()								bool								bFastWeaponSwitching;						//var bool bFastWeaponSwitching;
	UPROPERTY()								bool								bNoTeamChanges;								//var bool bNoTeamChanges;
	UPROPERTY()								bool								bCountUp;									//var bool bCountUp;
	UPROPERTY()								int32								RemainingTime;								//var int32 RemainingTime;
	UPROPERTY()								int32								ElapsedTime;								//var int32 ElapsedTime;
	UPROPERTY()								int32								RemainingMinute;							//var int32 RemainingMinute;
	UPROPERTY()								float								SecondCount;								//var float SecondCount;
	UPROPERTY()								int32								GoalScore;									//var int32 GoalScore;
	UPROPERTY()								int32								TimeLimit;									//var int32 TimeLimit;
	UPROPERTY()								int32								MaxLives;									//var int32 MaxLives;
	UPROPERTY()								int32								MinNetPlayers;								//var int32 MinNetPlayers;
	UPROPERTY()								float								WeaponBerserk;								//var float WeaponBerserk;
	UPROPERTY()								bool								bShouldShowScoreboard;						//var bool bShouldShowScoreboard;
	UPROPERTY()								int32								RoundsPerMatch;								//var int32 RoundsPerMatch;
	UPROPERTY()								int32								RemainingRounds;							//var int32 RemainingRounds;
	UPROPERTY()								int32								MatchesBeforeCycle;							//var int32 MatchesBeforeCycle;
	UPROPERTY()								TArray<ATeamInfo*>					Teams;										//var ATeamInfo* Teams[2];
	UPROPERTY()								ATeamInfo*							SpecTeam;									//var ATeamInfo* SpecTeam;
	UPROPERTY(EditAnywhere, globalconfig)	FString								ServerName;									//var() globalconfig FString ServerName;
	UPROPERTY(EditAnywhere, globalconfig)	FString								ShortName;									//var() globalconfig FString ShortName;
	UPROPERTY(EditAnywhere, globalconfig)	FString								AdminName;									//var() globalconfig FString AdminName;
	UPROPERTY(EditAnywhere, globalconfig)	FString								AdminEmail;									//var() globalconfig FString AdminEmail;
	UPROPERTY(EditAnywhere, globalconfig)	FString								ServerRegion;								//var() globalconfig int32 ServerRegion;
	UPROPERTY(EditAnywhere, globalconfig)	FString								MessageOfTheDay;							//var() globalconfig FString MessageOfTheDay;
	UPROPERTY(EditAnywhere, globalconfig)	FString								MOTDLine1;									//var() globalconfig FString MOTDLine1;
	UPROPERTY(EditAnywhere, globalconfig)	FString								MOTDLine2;									//var() globalconfig FString MOTDLine2;
	UPROPERTY(EditAnywhere, globalconfig)	FString								MOTDLine3;									//var() globalconfig FString MOTDLine3;
	UPROPERTY(EditAnywhere, globalconfig)	FString								MOTDLine4;									//var() globalconfig FString MOTDLine4;
	UPROPERTY(EditAnywhere, globalconfig)	int32								MOTDDisplaySeconds;							//var() globalconfig int32 MOTDDisplaySeconds;
	UPROPERTY()								AActor*								Winner;										//var AActor* Winner;
	UPROPERTY()								AVoiceChatReplicationInfo*			VoiceReplicationInfo;						//var AVoiceChatReplicationInfo* VoiceReplicationInfo;
	UPROPERTY(EditAnywhere)					TArray<UMaterialInstance*>			TeamSymbols;								//var() UTexture* TeamSymbols[2];
	UPROPERTY(EditAnywhere)					TArray<AAA2_PlayerState*>			PRIArray;									//var() TArray<PlayerReplicationInfo> PRIArray;
	UPROPERTY()								TArray<FString>						GRIPropsDisplayText;						//var localized FString GRIPropsDisplayText[4];
	UPROPERTY()								TArray<FString>						GRIPropDescText;							//var localized FString GRIPropDescText[4];
	UPROPERTY()								FVector								FlagPos;									//var Vector FlagPos;
	UPROPERTY()								TArray<AAA2_PlayerState*>			FlagHolder;									//var AAA2_PlayerState* FlagHolder[2];
	UPROPERTY()								AAA2_PlayerState*					FlagTarget;									//var AAA2_PlayerState* FlagTarget;
	UPROPERTY()								int32								MatchID;									//var int32 MatchID;
	UPROPERTY()								int32								BotDifficulty;								//var int32 BotDifficulty;
	UPROPERTY(globalconfig)					bool								bHUDHideAmmoCount;							//var globalconfig bool bHUDHideAmmoCount;
	UPROPERTY(globalconfig)					bool								bHUDHideWeaponStatus;						//var globalconfig bool bHUDHideWeaponStatus;
	UPROPERTY(globalconfig)					bool								bHUDHideWeapon;								//var globalconfig bool bHUDHideWeapon;
	UPROPERTY(globalconfig)					bool								bHUDHideGrenades;							//var globalconfig bool bHUDHideGrenades;
	UPROPERTY(globalconfig)					bool								bHUDHideHealth;								//var globalconfig bool bHUDHideHealth;
	UPROPERTY(globalconfig)					bool								bHUDHideMedical;							//var globalconfig bool bHUDHideMedical;
	UPROPERTY(globalconfig)					bool								bHUDHideCombatEffect;						//var globalconfig bool bHUDHideCombatEffect;
	UPROPERTY(globalconfig)					bool								bHUDHideOptics;								//var globalconfig bool bHUDHideOptics;
	UPROPERTY(globalconfig)					bool								bHUDHideCompass;							//var globalconfig bool bHUDHideCompass;
	UPROPERTY(globalconfig)					bool								bHUDHideTimer;								//var globalconfig bool bHUDHideTimer;
	UPROPERTY(globalconfig)					bool								bHUDHideObjectives;							//var globalconfig bool bHUDHideObjectives;
	UPROPERTY(globalconfig)					bool								bHUDHideRadar;								//var globalconfig bool bHUDHideRadar;
	UPROPERTY(globalconfig)					bool								bHUDHideSupport;							//var globalconfig bool bHUDHideSupport;
	UPROPERTY()								bool								bRoundIsSuspended;							//var bool bRoundIsSuspended;
	UPROPERTY()								int32								SecsTillRoundResume;						//var int32 SecsTillRoundResume;
	UPROPERTY()								FString								sTournamentState;							//var FString sTournamentState;
	UPROPERTY()								bool								bTournamentInProgress;						//var bool bTournamentInProgress;
	UPROPERTY()								bool								bTournamentWarmupJustEnded;					//var bool bTournamentWarmupJustEnded;
	UPROPERTY()								bool								bTournamentInWarmup;						//var bool bTournamentInWarmup;
	UPROPERTY()								int32								TournamentCountDownTime;					//var int32 TournamentCountDownTime;
	UPROPERTY()								FString								sTournamentName;							//var FString sTournamentName;
	UPROPERTY()								FString								sLeagueName;								//var FString sLeagueName;
	UPROPERTY()								FString								sTournamentResultsFileName;					//var FString sTournamentResultsFileName;
	UPROPERTY()								TArray<FString>						asTournamentTeamName;						//var FString asTournamentTeamName[2];
	UPROPERTY()								int32								iTournamentRoundDelayTime;					//var int32 iTournamentRoundDelayTime;
	UPROPERTY()								int32								iTournamentRequestDelayTime;				//var int32 iTournamentRequestDelayTime;
	UPROPERTY()								int32								iTournamentWarmupDuration;					//var int32 iTournamentWarmupDuration;
	UPROPERTY()								int32								iTournamentSwapTime;						//var int32 iTournamentSwapTime;
	UPROPERTY()								int32								iTournamentSwapLimit;						//var int32 iTournamentSwapLimit;
	UPROPERTY()								int32								iTournamentPauseLimit;						//var int32 iTournamentPauseLimit;
	UPROPERTY()								bool								bTournamentMercyRule;						//var bool bTournamentMercyRule;
	UPROPERTY()								bool								bTournamentOpenAllWeaponClassSlots;			//var bool bTournamentOpenAllWeaponClassSlots;
	UPROPERTY()								bool								bTournamentTeamCaptainsAllowed;				//var bool bTournamentTeamCaptainsAllowed;
	UPROPERTY()								bool								bTournamentTeamPasswordsRequired;			//var bool bTournamentTeamPasswordsRequired;
	UPROPERTY()								bool								bTournamentTieSuddenDeath;					//var bool bTournamentTieSuddenDeath;
	UPROPERTY()								bool								bTournamentTieScore;						//var bool bTournamentTieScore;
	UPROPERTY()								bool								bTournamentEnableRandomTeamAssignments;		//var bool bTournamentEnableRandomTeamAssignments;
	UPROPERTY(globalconfig)					bool								bForceShadowsOff;							//var globalconfig bool bForceShadowsOff;
	UPROPERTY(globalconfig)					bool								bAllowForceclassing;						//var globalconfig bool bAllowForceclassing;
	UPROPERTY()								bool								bForceClassUsedInRound;						//var bool bForceClassUsedInRound;
	UPROPERTY(globalconfig)					bool								bDisableFragGrenades;						//var globalconfig bool bDisableFragGrenades;
	UPROPERTY(globalconfig)					bool								bDisableFlashbangs;							//var globalconfig bool bDisableFlashbangs;
	UPROPERTY(globalconfig)					bool								bDisableSmokeGrenades;						//var globalconfig bool bDisableSmokeGrenades;
	UPROPERTY(globalconfig)					bool								bDisableThermiteGrenades;					//var globalconfig bool bDisableThermiteGrenades;
	UPROPERTY(globalconfig)					bool								bDisable203Grenades;						//var globalconfig bool bDisable203Grenades;
	UPROPERTY(globalconfig)					bool								bDGO;										//var globalconfig bool bDGO;
	UPROPERTY()								int32								iSpotterBaseGridX;							//var int32 iSpotterBaseGridX;
	UPROPERTY()								int32								iSpotterBaseGridY;							//var int32 iSpotterBaseGridY;
	UPROPERTY()								int32								iDelayedStartTimeRemaining;					//var int32 iDelayedStartTimeRemaining;
	UPROPERTY()								bool								bTempDisableRoundScoring;					//var bool bTempDisableRoundScoring;
	UPROPERTY()								TArray<AVehicleReplicationInfo*>	VRIArray;									//var TArray<VehicleReplicationInfo> VRIArray;

	void PostNetBeginPlay();
	void TeamSymbolNotify();
	void UpdatePrecacheMaterials();
	void PostBeginPlay();
	void Reset();
	void Timer();
	AAA2_PlayerState* FindPlayerByID(int32 PlayerID);
	void AddPRI(AAA2_PlayerState* PRI);
	void AddVRI(AVehicleReplicationInfo* VRI);
	void RemovePRI(AAA2_PlayerState* PRI);
	void RemoveVRI(AVehicleReplicationInfo* VRI);
	void GetPRIArray(TArray<AAA2_PlayerState>& pris);
	void FillPlayInfo(UPlayInfo* PlayInfo);
	FString GetDescriptionText(FString PropName);
	void ASDebugLog(APlayerController* PC);
	void SuspendRound(bool bEnabled);
	void SetTournamentTeamName(int32 Team, FString NewName);
	FString GetTournamentTeamName(int32 Team);
	bool DisableFragGrenades();
	bool DisableFlashbangs();
	bool DisableSmokeGrenades();
	bool DisableThermiteGrenades();
	bool Disable203Grenades();
};
