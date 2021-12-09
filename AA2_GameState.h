// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "Net/UnrealNetwork.h"
#include "AA29/MyEnums.h"
#include "AA2_GameState.generated.h"


class ATeamInfo;
class APlayInfo;
class AAA2_PlayerState;

UCLASS()
class AA29_API AAA2_GameState : public AGameStateBase
{
	GENERATED_BODY()
public:
	AAA2_GameState();


	// Replicated Specifier used to mark this variable to replicate

	bool bWaitingToStartMatch;
	int32 NumSpectators;
	int32 MaxSpectators;

	UPROPERTY()											FString GameName;									//var string GameName;						// Assigned by GameInfo.
	UPROPERTY()											FString GameClass;									//var string GameClass;						// Assigned by GameInfo.
	UPROPERTY()											bool bTeamGame;										//var bool bTeamGame;						// Assigned by GameInfo.
	UPROPERTY()											bool bStopCountDown;								//var bool bStopCountDown;
	UPROPERTY()											bool bMatchHasBegun;								//var bool bMatchHasBegun;
	UPROPERTY()											bool bTeamSymbolsUpdated;							//var bool bTeamSymbolsUpdated;
	UPROPERTY()											bool bNoTeamSkins;									//var bool bNoTeamSkins;
	UPROPERTY()											bool bForceTeamSkins;								//var bool bForceTeamSkins;
	UPROPERTY()											bool bForceNoPlayerLights;							//var bool bForceNoPlayerLights;
	UPROPERTY()											bool bAllowPlayerLights;							//var bool bAllowPlayerLights;
	UPROPERTY()											bool bFastWeaponSwitching;							//var bool bFastWeaponSwitching;
	UPROPERTY()											bool bNoTeamChanges;								//var bool bNoTeamChanges;
	UPROPERTY()											bool bCountUp;										//var bool bCountUp;
	UPROPERTY()											int32 RemainingTime;								//var int RemainingTime;
	UPROPERTY()											int32 ElapsedTime;									//var int ElapsedTime;
//agp [cmb] RemainingMinute is actually in seconds, but is updated once per minute server-side (to sync client-server clocks) [6/18/2002]
	UPROPERTY()											int32 RemainingMinute;								//var int RemainingMinute;
	UPROPERTY()											float SecondCount;									//var float SecondCount;
	UPROPERTY()											int32 GoalScore;									//var int GoalScore;
	UPROPERTY()											int32 TimeLimit;									//var int TimeLimit;
	UPROPERTY()											int32 MaxLives;										//var int MaxLives;
	UPROPERTY()											int32 MinNetPlayers;								//var int MinNetPlayers;
	UPROPERTY()											float WeaponBerserk;								//var float WeaponBerserk;
	UPROPERTY()											bool bShouldShowScoreboard;							//var bool bShouldShowScoreboard;
	UPROPERTY()											int32 RoundsPerMatch;								//var int RoundsPerMatch;
	UPROPERTY()											int32 RemainingRounds;								//var int RemainingRounds;
	UPROPERTY()											int32 MatchesBeforeCycle;							//var int MatchesBeforeCycle;
	UPROPERTY()											TArray<ATeamInfo*> Teams;									//var TeamInfo Teams;
	UPROPERTY()											ATeamInfo* SpecTeam;								//var TeamInfo SpecTeam;
	UPROPERTY(EditAnywhere, BluePrintReadOnly, Config)	FString ServerName;									//var() globalconfig string ServerName;					// Name of the server, i.e.: Bob's Server.
	UPROPERTY(EditAnywhere, BluePrintReadOnly, Config)	FString ShortName;									//var() globalconfig string ShortName;					// Abbreviated name of server, i.e.: B's Serv (stupid example)
	UPROPERTY(EditAnywhere, BluePrintReadOnly, Config)	FString AdminName;									//var() globalconfig string AdminName;					// Name of the server admin.
	UPROPERTY(EditAnywhere, BluePrintReadOnly, Config)	FString AdminEmail;									//var() globalconfig string AdminEmail;					// Email address of the server admin.
	UPROPERTY(EditAnywhere, BluePrintReadOnly, Config)	int32 ServerRegion;									//var() globalconfig int ServerRegion;					// Region of the game server.
	UPROPERTY(EditAnywhere, BluePrintReadOnly, Config)	FString MessageOfTheDay;							//var() globalconfig string MessageOfTheDay;
	UPROPERTY(EditAnywhere, BluePrintReadOnly, Config)	FString MOTDLine1;									//var() globalconfig string MOTDLine1;
	UPROPERTY(EditAnywhere, BluePrintReadOnly, Config)	FString MOTDLine2;									//var() globalconfig string MOTDLine2;
	UPROPERTY(EditAnywhere, BluePrintReadOnly, Config)	FString MOTDLine3;									//var() globalconfig string MOTDLine3;
	UPROPERTY(EditAnywhere, BluePrintReadOnly, Config)	FString MOTDLine4;									//var() globalconfig string MOTDLine4;
	UPROPERTY(EditAnywhere, BluePrintReadOnly, Config)	int32 MOTDDisplaySeconds;							//var() globalconfig int MOTDDisplaySeconds;
	UPROPERTY()											AActor* Winner;										//var Actor Winner;										// set by gameinfo when game ends
	//UPROPERTY()										VoiceChatReplicationInfo* VoiceReplicationInfo;		//var VoiceChatReplicationInfo VoiceReplicationInfo;
	UPROPERTY(EditAnywhere, BluePrintReadOnly)			UTexture2D* TeamSymbols;							//var() Texture TeamSymbols;
	UPROPERTY(EditAnywhere, BluePrintReadOnly)			TArray<AAA2_PlayerState*> PRIArray;					//var() array<PlayerReplicationInfo> PRIArray;

	// mc - localized PlayInfo descriptions & extra info
	UPROPERTY()											TArray<FString> GRIPropsDisplayText;				//var localized string GRIPropsDisplayText;
	UPROPERTY()											TArray<FString> GRIPropDescText;					//var localized string GRIPropDescText;
	UPROPERTY()											FVector FlagPos;									//var FVector FlagPos;							// replicated 2D position of one object
	UPROPERTY()											EFlagState FlagState;								//var Actor.EFlagState FlagState;
	UPROPERTY()											AAA2_PlayerState* FlagHolder;						//var PlayerReplicationInfo FlagHolder;					// hack to work around flag holder replication FIXME remove when break net compatibility
	UPROPERTY()											AAA2_PlayerState* FlagTarget;						//var PlayerReplicationInfo FlagTarget;					// used by Bombing Run (targeted player)
	
																											// stats
	UPROPERTY()											int32 MatchID;										//var int MatchID;
	UPROPERTY()											int32 BotDifficulty;								//var int BotDifficulty;								// for bPlayersVsBots
	
	// server side HUD element hiding - server will override clients
	UPROPERTY(Config)									bool bHUDHideAmmoCount;								//var globalconfig bool bHUDHideAmmoCount;				// hide how many rounds are in current clip
	UPROPERTY(Config)									bool bHUDHideWeaponStatus;							//var globalconfig bool bHUDHideWeaponStatus;			// hide reloading, fix jam messages
	UPROPERTY(Config)									bool bHUDHideWeapon;								//var globalconfig bool bHUDHideWeapon;
	UPROPERTY(Config)									bool bHUDHideGrenades;								//var globalconfig bool bHUDHideGrenades;
	UPROPERTY(Config)									bool bHUDHideHealth;								//var globalconfig bool bHUDHideHealth;
	UPROPERTY(Config)									bool bHUDHideMedical;								//var globalconfig bool bHUDHideMedical;
	UPROPERTY(Config)									bool bHUDHideCombatEffect;							//var globalconfig bool bHUDHideCombatEffect;
	UPROPERTY(Config)									bool bHUDHideOptics;								//var globalconfig bool bHUDHideOptics;
	UPROPERTY(Config)									bool bHUDHideCompass;								//var globalconfig bool bHUDHideCompass;
	UPROPERTY(Config)									bool bHUDHideTimer;									//var globalconfig bool bHUDHideTimer;
	UPROPERTY(Config)									bool bHUDHideObjectives;							//var globalconfig bool bHUDHideObjectives;
	UPROPERTY(Config)									bool bHUDHideRadar;									//var globalconfig bool bHUDHideRadar;
	UPROPERTY(Config)									bool bHUDHideSupport;								//var globalconfig bool bHUDHideSupport;

	// For admin command "roundsuspend"
	//
	UPROPERTY()											bool bRoundIsSuspended;								//var bool bRoundIsSuspended;
	UPROPERTY()											int32 SecsTillRoundResume;							//var int SecsTillRoundResume;
	UPROPERTY()											FString sTournamentState;							//var string sTournamentState;
	UPROPERTY()											bool bTournamentInProgress;							//var bool bTournamentInProgress;
	UPROPERTY()											bool bTournamentWarmupJustEnded;					//var bool bTournamentWarmupJustEnded;
	UPROPERTY()											bool bTournamentInWarmup;							//var bool bTournamentInWarmup;
	UPROPERTY()											int32 TournamentCountDownTime;						//var int TournamentCountDownTime;
	UPROPERTY()											FString sTournamentName;							//var string sTournamentName;
	UPROPERTY()											FString sLeagueName;								//var string sLeagueName;
	UPROPERTY()											FString sTournamentResultsFileName;					//var string sTournamentResultsFileName;
	UPROPERTY()											TArray<FString> asTournamentTeamName;				//var string asTournamentTeamName;
	UPROPERTY()											int32 iTournamentRoundDelayTime;					//var int iTournamentRoundDelayTime;
	UPROPERTY()											int32 iTournamentRequestDelayTime;					//var int iTournamentRequestDelayTime;
	UPROPERTY()											int32 iTournamentWarmupDuration;					//var int iTournamentWarmupDuration;
	UPROPERTY()											int32 iTournamentSwapTime;							//var int iTournamentSwapTime;
	UPROPERTY()											int32 iTournamentSwapLimit;							//var int iTournamentSwapLimit;
	UPROPERTY()											int32 iTournamentPauseLimit;						//var int iTournamentPauseLimit;
	UPROPERTY()											bool bTournamentMercyRule;							//var bool bTournamentMercyRule;
	UPROPERTY()											bool bTournamentOpenAllWeaponClassSlots;			//var bool bTournamentOpenAllWeaponClassSlots;
	UPROPERTY()											bool bTournamentTeamCaptainsAllowed;				//var bool bTournamentTeamCaptainsAllowed;
	UPROPERTY()											bool bTournamentTeamPasswordsRequired;				//var bool bTournamentTeamPasswordsRequired;
	UPROPERTY()											bool bTournamentTieSuddenDeath;						//var bool bTournamentTieSuddenDeath;
	UPROPERTY()											bool bTournamentTieScore;							//var bool bTournamentTieScore;
	UPROPERTY()											bool bTournamentEnableRandomTeamAssignments;		//var bool bTournamentEnableRandomTeamAssignments;
	UPROPERTY(Config)									bool bForceShadowsOff;								//var globalconfig bool bForceShadowsOff;
	UPROPERTY(Config)									bool bAllowForceclassing;							//var globalconfig bool bAllowForceclassing;
	UPROPERTY()											bool bForceClassUsedInRound;						//var bool bForceClassUsedInRound;
	UPROPERTY(Config)									bool bDisableFragGrenades;							//var globalconfig bool bDisableFragGrenades;
	UPROPERTY(Config)									bool bDisableFlashbangs;							//var globalconfig bool bDisableFlashbangs;
	UPROPERTY(Config)									bool bDisableSmokeGrenades;							//var globalconfig bool bDisableSmokeGrenades;
	UPROPERTY(Config)									bool bDisableThermiteGrenades;						//var globalconfig bool bDisableThermiteGrenades;
	UPROPERTY(Config)									bool bDisable203Grenades;							//var globalconfig bool bDisable203Grenades;
	UPROPERTY(Config)									bool bDGO;											//var globalconfig bool bDGO;
	UPROPERTY()											int32 iSpotterBaseGridX;							//var int iSpotterBaseGridX;
	UPROPERTY()											int32 iSpotterBaseGridY;							//var int iSpotterBaseGridY;
	UPROPERTY()											int32 iDelayedStartTimeRemaining;					//var int iDelayedStartTimeRemaining;
	UPROPERTY()											bool bTempDisableRoundScoring;						//var bool bTempDisableRoundScoring;
	//UPROPERTY()										VehicleReplicationInfo* VRIArray;					//var array<VehicleReplicationInfo> VRIArray;

	


	virtual void BeginPlay();

	void PostNetBeginPlay();
	void TeamSymbolNotify();
	void UpdatePrecacheMaterials();
	void PostBeginPlay();
	void Reset();
	void Timer();
	void FindPlayerByID(int32 PlayerID);
	void AddPRI(AAA2_PlayerState* PRI);
	//void AddVRI(VehicleReplicationInfo VRI);
	void RemovePRI(AAA2_PlayerState* PRI);
	//void RemoveVRI(VehicleReplicationInfo VRI);
	void GetPRIArray(TArray<AAA2_PlayerState*> pris);
	void FillPlayInfo(APlayInfo* PlayInfo);
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


	//virtual void PostInitializeComponents();
	//virtual void AddPlayerState(APlayerState* PlayerState);

};
