// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/AA2_Info.h"
#include "AA29/AA2_GameMode.h"
#include "AA29/Object/Actor/Info/StatsInfo/StatsInfo.h"
#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/PlayerStart/AGP_PlayerStart/AGP_PlayerStart.h"
#include "AA29/MyStructs.h"
#include "AA29/AA29.h"
#include "AA29/PSSet/PSSet.h"

#include "GameInfo.generated.h"

class AAA2_PlayerState;
class AAA2_GameState;

class UaDamageType;
class APickup;
class ATeamInfo;
class AAccessControl;
class AGameStats;
class AVotingHandler;
class APlayInfo;
class UGameRules;
class AaLocalMessage;

UCLASS()
class AA29_API AGameInfo : public AAA2_GameMode
{
	GENERATED_BODY()
	
public:
	AGameInfo();

	UPROPERTY()							AStatsInfo* StatsClass;									//var class<StatsInfo> StatsClass;
	UPROPERTY()							AStatsInfo* Stats;										//var StatsInfo Stats;
	UPROPERTY(globalconfig)				bool bSendExperienceTimestamp;							//var globalconfig bool bSendExperienceTimestamp;


	UPROPERTY()							bool bStopLogins;										//var bool bStopLogins;											//agp mpr - to prevent logins right before cycling a map
	UPROPERTY()							float MaxIdleTime;										//var float MaxIdleTime;										// maximum time players are allowed to idle before being kicked
	UPROPERTY()							FString ServerSkillLevel;								//var string ServerSkillLevel;									// The Server Skill Level ( 0 - 2, Beginner - Advanced )
	UPROPERTY()							TArray<FString> CallSigns;								//var string CallSigns;
	//UPROPERTY()						AVehicle* VehicleList;									//var Vehicle VehicleList;

	// Maplist management
	UPROPERTY()							FString MaplistHandlerType;								//var string MaplistHandlerType;
	//UPROPERTY()						AMaplistManagerBase* MaplistHandlerClass;				//var class<MaplistManagerBase> MaplistHandlerClass;
	//UPROPERTY()						AMaplistManagerBase* MaplistHandler;					//var transient MaplistManagerBase MaplistHandler;

	// Stats - jmw
	UPROPERTY()							AGameStats* GameStats;									//var GameStats GameStats;
	UPROPERTY()							FString GameStatsClass;									//var string GameStatsClass;

	// Server demo recording - rjp
	UPROPERTY()							FString DemoCommand;									//var transient string DemoCommand;

	// Cheat Protection
	UPROPERTY()							FString SecurityClass;									//var string SecurityClass;

	// Cache-related information
	UPROPERTY(EditAnywhere)				FString GameName;										//var() localized string GameName;
	UPROPERTY(EditAnywhere)				FString Description;									//var() localized string Description;
	UPROPERTY(EditAnywhere)				FString ScreenShotName;									//var() string ScreenShotName;
	UPROPERTY(EditAnywhere)				FString DecoTextName;									//var() string DecoTextName;
	UPROPERTY(EditAnywhere)				FString Acronym;										//var() string Acronym;

	// voting handler
	UPROPERTY()							FString VotingHandlerType;								//var string VotingHandlerType;
	UPROPERTY()							AVotingHandler* VotingHandlerClass;						//var class<VotingHandler> VotingHandlerClass;
	UPROPERTY()							AVotingHandler* VotingHandler;							//var transient VotingHandler VotingHandler;

	// persistant game data management
	//UPROPERTY(EditAnywhere)			UGameProfile* CurrentGameProfile;						//var() transient GameProfile CurrentGameProfile;
	//UPROPERTY(EditAnywhere)			AManifest* SaveGameManifest;							//var() const transient Manifest SaveGameManifest;

	// localized PlayInfo descriptions & extra info
	UPROPERTY()							TArray<FString> GIPropsDisplayText;						//var localized string GIPropsDisplayText;
	UPROPERTY()							TArray<FString> GIPropDescText;							//var localized string GIPropDescText;
	UPROPERTY()							TArray<FString> GIPropsExtras;							//var localized string GIPropsExtras;

	//Loading screen hints
	UPROPERTY()							FString NoBindString;									//var localized string NoBindString;
	UPROPERTY()							FColor BindColor;										//var Object.Color BindColor;

	// Admin server commands
	UPROPERTY(globalconfig)				bool bDeathMessages;									//var globalconfig bool bDeathMessages;

	UPROPERTY(globalconfig)				EServerScoreMode ScoreMode;								//var globalconfig EServerScoreMode ScoreMode;

	//agp - admin command post
	UPROPERTY()							TArray<FString> ServerSetting;							//var array<String> ServerSetting;
	UPROPERTY()							TArray<FString> Section;								//var array<String> Section;
	UPROPERTY()							TArray<FString> Setting;								//var array<String> Setting;
	UPROPERTY()							TArray<FString> MutedPlayers;							//var array<String> MutedPlayers;

	//agp - auth
	UPROPERTY()							bool bBinaryAuthProtocol;								//var bool bBinaryAuthProtocol;
	UPROPERTY(globalconfig)				bool bSendDistributionHistory;							//var globalconfig bool bSendDistributionHistory;
	UPROPERTY(globalconfig)				bool bSendRoundTimeInfo;								//var globalconfig bool bSendRoundTimeInfo;
																												
	//UPROPERTY()						AVoiceChatReplicationInfo* VoiceReplicationInfo;		//var VoiceChatReplicationInfo VoiceReplicationInfo;
	//UPROPERTY(EditAnywhere)			AVoiceChatReplicationInfo* VoiceReplicationInfoClass;	//var() class<VoiceChatReplicationInfo> VoiceReplicationInfoClass;
	UPROPERTY()							AAA2_GameState* GameReplicationInfo;					//var GameReplicationInfo GameReplicationInfo;
	UPROPERTY(EditAnywhere)				AAA2_GameState* GameReplicationInfoClass;				//var() class<GameReplicationInfo> GameReplicationInfoClass;
	UPROPERTY()							FString PlayerControllerClassName;						//var string PlayerControllerClassName;
	UPROPERTY()							APlayerController* KilPlayerControllerClassls;			//var class<PlayerController> PlayerControllerClass;
	//UPROPERTY()						ABroadcastHandler* BroadcastHandler;					//var BroadcastHandler BroadcastHandler;
	//UPROPERTY(EditAnywhere)			ABroadcastHandler* BroadcastClass;						//var() class<BroadcastHandler> BroadcastClass;
	UPROPERTY(EditAnywhere)				FString BroadcastHandlerClass;							//var() string BroadcastHandlerClass;
	UPROPERTY()							UGameRules* GameRulesModifiers;							//var GameRules GameRulesModifiers;
	UPROPERTY()							AAccessControl* AccessControl;							//var AccessControl AccessControl;
	UPROPERTY(EditAnywhere, globalconfig)	FString AccessControlClass;								//var() globalconfig string AccessControlClass;
	//UPROPERTY()						AMutator* BaseMutator;									//var Mutator BaseMutator;
	UPROPERTY()							FString MutatorClass;									//var string MutatorClass;
	UPROPERTY()							FName OtherMesgGroup;									//var name OtherMesgGroup;

	//UPROPERTY()						AGameMessage* GameMessageClass;							//var class<GameMessage> GameMessageClass;
	UPROPERTY()							AaLocalMessage* DeathMessageClass;						//var class<LocalMessage> DeathMessageClass;

	// user interface
	UPROPERTY()							FString ScoreBoardType;									//var string ScoreBoardType;							// Type of class<Menu> to use for scoreboards. (gam)
	UPROPERTY()							FString BotMenuType;									//var string BotMenuType;								// Type of bot menu to display. -NOT USED-
	UPROPERTY()							FString RulesMenuType;									//var string RulesMenuType;								// Type of rules menu to display.
	UPROPERTY()							FString SettingsMenuType;								//var string SettingsMenuType;							// Type of settings menu to display. -NOT USED-
	UPROPERTY()							FString GameUMenuType;									//var string GameUMenuType;								// Type of Game dropdown to display. (Used as map menu in Onslaught)
	UPROPERTY()							FString MultiplayerUMenuType;							//var string MultiplayerUMenuType;						// Type of Multiplayer dropdown to display. -NOT USED-
	UPROPERTY()							FString GameOptionsMenuType;							//var string GameOptionsMenuType;						// Type of options dropdown to display. -NOT USED-
	UPROPERTY()							FString HUDSettingsMenu;								//var string HUDSettingsMenu;							// Optional GUI page for configuring HUD options specific to this gametype
	UPROPERTY()							FString HUDType;										//var string HUDType;									// HUD class this game uses.
	UPROPERTY()							FString MapListType;									//var string MapListType;								// Maplist this game uses.
	UPROPERTY()							FString MapPrefix;										//var string MapPrefix;									// Prefix characters for names of maps for this game type.
	UPROPERTY()							FString BeaconName;										//var string BeaconName;								// Identifying string used for finding LAN servers.
	UPROPERTY()							TArray<FString> GoreLevelText;							//var localized string GoreLevelText;
	UPROPERTY(EditAnywhere)				int32 ResetCountDown;									//var() int ResetCountDown;								
	UPROPERTY(EditAnywhere, globalconfig)			int32 ResetTimeDelay;									//var() globalconfig int ResetTimeDelay;				// time (seconds) before restarting teams
	UPROPERTY(globalconfig)				int32 MaxSpectators;									//var globalconfig int MaxSpectators;					// Maximum number of spectators.
	UPROPERTY()							int32 NumSpectators;									//var int NumSpectators;								// Current number of spectators.
	UPROPERTY(globalconfig)				int32 MaxPlayers;										//var globalconfig int MaxPlayers;
	UPROPERTY()							int32 AbsoluteMaxPlayers;								//var int AbsoluteMaxPlayers;
	UPROPERTY()							int32 NumPlayers;										//var int NumPlayers;									// number of human players
	UPROPERTY(globalconfig)				int32 MaxAdmins;										//var globalconfig int MaxAdmins;						// Max number of admins allowed
	UPROPERTY()							int32 NumAdmins;										//var int NumAdmins;									
	UPROPERTY()							int32 NumBots;											//var int NumBots;										// number of non-human players (AI controlled but participating as a player)
	UPROPERTY()							int32 CurrentID;										//var int CurrentID;
	//AlreadyInGameModeBase	
	//UPROPERTY()						FString DefaultPlayerName;								//var localized string DefaultPlayerName;
	UPROPERTY()							float FearCostFallOff;									//var float FearCostFallOff;							// how fast the FearCost in NavigationPoints falls off
	UPROPERTY(globalconfig)				int32 GoalScore;										//var globalconfig int GoalScore;						// what score is needed to end the match
	UPROPERTY(globalconfig)				int32 MaxLives;											//var globalconfig int MaxLives;						// max number of lives for match, unless overruled by level's GameDetails
	UPROPERTY(globalconfig)				int32 TimeLimit;										//var globalconfig int TimeLimit;						// time limit in minutes


	UPROPERTY()						bool bRestartLevel;										//var bool bRestartLevel;								// Level should be restarted when player dies
	//AlreadyInGameModeBase	
	//UPROPERTY()					bool bPauseable;										//var bool bPauseable;									// Whether the game is pauseable.
	UPROPERTY(globalconfig)			bool bWeaponStay;										//var globalconfig bool bWeaponStay;					// Whether or not weapons stay when picked up.
	UPROPERTY()						bool bCanChangeSkin;									//var bool bCanChangeSkin;								// Allow player to change skins in game.
	UPROPERTY()						bool bTeamGame;											//var bool bTeamGame;									// This is a team game.
	UPROPERTY()						bool bGameEnded;										//var bool bGameEnded;									// set when game ends
	UPROPERTY()						bool bOverTime;											//var bool bOverTime;
	UPROPERTY()						bool bAlternateMode;									//var localized bool bAlternateMode;
	UPROPERTY()						bool bCanViewOthers;									//var bool bCanViewOthers;
	UPROPERTY()						bool bDelayedStart;										//var bool bDelayedStart;
	UPROPERTY()						bool bWaitingToStartMatch;								//var bool bWaitingToStartMatch;
	UPROPERTY(globalconfig)			bool bChangeLevels;										//var globalconfig bool bChangeLevels;
	UPROPERTY()						bool bAlreadyChanged;									//var bool bAlreadyChanged;
	UPROPERTY()						bool bLoggingGame;										//var bool bLoggingGame;								// Does this gametype log?
	UPROPERTY(globalconfig)			bool bEnableStatLogging;								//var globalconfig bool bEnableStatLogging;				// If True, games will log
	UPROPERTY()						bool bAllowWeaponThrowing;								//var bool bAllowWeaponThrowing;
	UPROPERTY(globalconfig)			bool bAllowBehindView;									//var globalconfig bool bAllowBehindView;
	UPROPERTY(globalconfig)			bool bAdminCanPause;									//var globalconfig bool bAdminCanPause;
	UPROPERTY()						bool bGameRestarted;									//var bool bGameRestarted;
	UPROPERTY(globalconfig)			bool bWeaponShouldViewShake;							//var globalconfig bool bWeaponShouldViewShake;
	UPROPERTY()						bool bModViewShake;										//var bool bModViewShake;								// for mutators to turn off weaponviewshake
	UPROPERTY()						bool bForceClassicView;									//var bool bForceClassicView;							// OBSOLETE
	UPROPERTY()						bool bLowGore;											//var bool bLowGore;									// OBSOLETE - use GoreLevel instead;
	UPROPERTY()						bool bWelcomePending;									//var bool bWelcomePending;
	UPROPERTY()						bool bAttractCam;										//var bool bAttractCam;
	UPROPERTY()						bool bMustJoinBeforeStart;								//var bool bMustJoinBeforeStart;						// players can only spectate if they join after the game starts
	UPROPERTY()						bool bTestMode;											//var bool bTestMode;
	UPROPERTY()						bool bAllowVehicles;									//var bool bAllowVehicles;								//are vehicles allowed in this gametype?
	UPROPERTY()						bool bAllowMPGameSpeed;									//var bool bAllowMPGameSpeed;
	UPROPERTY()						bool bIsSaveGame;										//var bool bIsSaveGame;									// stays true during entire game (unlike LevelInfo property)
	UPROPERTY()						bool bLiberalVehiclePaths;								//var bool bLiberalVehiclePaths;
	UPROPERTY()						bool bLargeGameVOIP;									//var bool bLargeGameVOIP;
	UPROPERTY(globalconfig)			int32 GoreLevel;										//var globalconfig int GoreLevel;
	UPROPERTY(globalconfig)			float GameDifficulty;									//var globalconfig float GameDifficulty;
	UPROPERTY()						float AutoAim;											//var float AutoAim;									// OBSOLETE How much autoaiming to do (1 = none, 0 = always).
	//agp superville: Don't allow changing of timedilation through the ini file (allows cheating for SP)
	UPROPERTY()						float GameSpeed;										//var float GameSpeed;									// Scale applied to game rate.
	UPROPERTY()						float StartTime;										//var float StartTime;
	UPROPERTY()						FString DefaultPlayerClassName;							//var string DefaultPlayerClassName;


	virtual void BeginPlay();
	virtual void PostBeginPlay();
	virtual void PreBeginPlay();
	virtual void StartMatch(); 
	virtual void EndGame(AAA2_PlayerState*  Winner, FString Reason);
	virtual void StartPlay();
	void PreLogin(const FString& Options, const FString& Address, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage);
	

	void PostLogin(APlayerController* NewPlayer);

	void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage);


	virtual bool IsMultiPlayer();
	void Timer();
	void Logout(AController* Exiting);
	void NotifyLogin(int32 NewPlayerID);
	void NotifyLogout(AController* Exiting);


	void GetSavedGames();
	void CreateDataObject(UObject* objClass, FString objName, FString PackageName);
	void DeleteDataObject(UObject* objClass, FString objName, FString PackageName);
	void LoadDataObject(UObject* objClass, FString objName, FString PackageName);
	void AllDataObjects(UObject* objClass, UObject* obj, FString PackageName);
	void SavePackage(FString PackageName);
	void DeletePackage(FString PackageName);
	void LoadMapList(FString MapPrefix, TArray<FString> Maps);
	bool CheatsDisabled();
	AActor* GetDefaultTeamClass();
	AActor* GetTeamRole(AController* C);
	float GetProjectileMod();
	
	uint8 GetPlayerTeamIndex(AController* C);
	void ConnectionResolved();
	void GetScreenplay();
	void RequestChangeTeam(AController* Other, int32 N);
	bool IsRequireAuthorization();
	void SetRequireAuthorization(bool bReqAuth);
	void IsSpectateFirstPersonOnly();
	void IsSpectatePlayersOnly();
	void IsSpectateBodies();
	float GetROELimit();
	void InitiateVoteRequest(AAA2_PlayerState*  PRI, FString PlayerName, FString Reason);
	void CastVote(AAA2_PlayerState*  PRI);
	void ActiveVote();
	void CheckDevKick(AController* Kicker, FString PlayerName);
	void NotifyIdlePlayer(AController* C, float LastMovedTime);
	void NotifyIdlePlayerRounds(AController* C, int32 nIdleRounds, bool bMessage);
	void TestForIdlePlayers(AAA2_PlayerState*  PRI);
	float GetTimeElapsed();
	void GetTeam(uint8 Index);
	void GetOtherTeam(uint8 Index);
	void CheckHonor(AController* C);
	void CheckGroup(AController* C);
	void GetLegalGroupsString();
	void GetMinHonor();
	void GetMaxHonor();
	void LogPlayerStart(APlayerController* PC);
	void LogPlayerFinish(APlayerController* PC);
	void SetROEKickTimer(bool bEnabled);
	void SetROEKick(bool bEnabled);
	void SetROEKickDead(bool bEnabled);
	void NotifyReportLogoutStarted();
	void NotifyReportLogoutFinished();
	void grenadeNotifier(AActor* Explosive, UaDamageType* DamageType, AController* KillerController);
	void FakeRestartGame();
	void AuthorizeServer();
	void AuthAuthenticateServerCallback(int32 ResultCode, int32 ServerMode, FString ServerModeName);
	void AuthTransmissionErrorCallback(int32 iReason, FString sMsg, FString sShortMsg);
	void GetPossibleCommandlineOverride(FString CommandLineFlag, FString DefaultValue);

	//void NotifyAuthTransactionResolving(AInternetInfo* ILink, bool bHighPriority);
	//void IsAuthAvailable(AInternetInfo* ILink);
	//void NotifyAuthTransactionComplete(AInternetInfo* ILink);
	void TournamentSetPlayerTeam(AAA2_PlayerState*  PRI, FString SetPlayerName, int32 SetTeamID);
	void TournamentSetPlayerClass(AAA2_PlayerState*  PRI, FString SetPlayerName, int32 SetUnitSlot, int32 SetPlayerClass);
	void TournamentSendMessage(FString S);
	void TournamentSendTeamCaptainOnlyMessage(FString sMsg);
	void TournamentSendNonTeamCaptainMessages(FString sMsg);
	void TournamentSetPlayerTeamByString(FString S);
	void TournamentSetPlayerClassByString(FString S);
	void TournamentRequestSwapSides();
	void TournamentAssignRandomTeams();
	void TournamentRequestPauseTournament();
	void TournamentRequestStartMatch();
	void TournamentRequestRestartMatch();
	void TournamentRequestWarmup();
	void TournamentRequestResetMatch();
	void TournamentRequestResetTournament();
	void TournamentSetTeamName(int32 iTeam, FString sTeamName);
	void TournamentIsTournament();
	void TournamentGetTeamName(int32 iTeamIndex);
	void TournamentJoinTeam(APlayerController* PC, int32 iTeamIndex, FString sPassword);
	void TournamentJoinSpectatorTeam(APlayerController* PC, int32 iTeamIndex);
	void TournamentTeamsReady();
	void TournamentResumeFromPause();
	void TournamentWarmupJustEnded();
	bool TournamentAreAllWeaponClassesAvailable();
	void TournamentEndCurrentRound();
	void TournamentIsWarmup();
	void TournamentGetMaxTeamSize();
	void TournamentAssignClass(AAA2_PlayerState*  PRI, int32 iUnit, int32 iSlotIndex);
	void TournamentEndedByMercyRule();
	void TournamentGetTeam(uint8 Index);
	void TournamentResultsAuthCallback(int32 iResultCode);
	void TournamentServerINISetTeamName(int32 iTeam, FString sTeamName);
	void TournamentServerINIGetTeamName(int32 iTeam);
	void TournamentSendCenteredMessage(FString sMsg);
	void SimulateAuthFailure();
	void SimulateAuthRecovery();
	void TournamentRequestDeadRound();
	bool TournamentIsDeadRound();
	void TournamentUpdateGameReplicationInfo();
	void TournamentSetRoundsPerMatch(int32 iNewRounds);
	void TournamentSetRoundsTimeLimit(int32 iNewTimeLimit);
	bool IsTournamentMode();

	void Destroyed();
	void UpdatePrecacheMaterials();
	void UpdatePrecacheStaticMeshes();
	//void PrecacheGameTextures(ALevelInfo* myLevel);
	//void PrecacheGameStaticMeshes(ALevelInfo* myLevel);
	//void PrecacheGameAnnouncements(AAnnouncerVoice* V, bool bRewardSounds);
	void FindPlayerByID(int32 PlayerID);
	void ChangeMap(int32 ContextID);
	void UseLowGore();
	void NoBlood();
	void Reset();
	void InitLogging();
	void GameEnding();
	void ApplicationShutdown();
	void InitGameReplicationInfo();
	void InitVoiceReplicationInfo();
	void InitMaplistHandler();
	void GetNetworkNumber();

	void GetServerInfo(FServerResponseLine &ServerState);

	int32 GetNumPlayers();
	void GetServerDetails(FServerResponseLine ServerState);
	void GetServerPlayers(FServerResponseLine ServerState);
	int32 GetServerPort();
	//bool SetPause(bool bPause, APlayerController* p);
	bool AllowGameSpeedChange();
	void SetGameSpeed(float t);
	void DetailChange();
	bool GrabOption(FString &Options, FString &Result);
	void GetKeyValue(FString Pair, FString &Key, FString& Value);
	FString ParseOption(FString Options, FString InKey);
	bool HasOption(FString Options, FString InKey);

	
	
	void AddMutator(FString mutname, bool bUserAdded);

	void AddGameModifier(UGameRules* NewRule);
	FString GetBeaconText();
	//void ProcessServerTravel(FString URL, bool bItems);
	int32 GetIntOption(FString Options, FString ParseString, int32 CurrentValue);
	void BecomeSpectator(APlayerController* p);
	void AllowBecomeActivePlayer(APlayerController* p);
	bool AtCapacity(bool bSpectator, bool bAdmin);
	void InitSavedLevel();
	void TestLevel();
	bool PlayerCanRestart(APlayerController* aPlayer);
	bool PlayerCanRestartGame(APlayerController* aPlayer);
	void RestartPlayer(AController* aPlayer);
	void GetDefaultPlayerClass(AController* C);
	void SetWeaponViewShake(APlayerController* p);
	void AcceptInventory(APawn* PlayerPawn);
	void AddGameSpecificInventory(APawn* p);
	void AddDefaultInventory(APawn* PlayerPawn);
	void SetPlayerDefaults(APawn* PlayerPawn);
	void NotifyKilled(AController* Killer, AController* Killed, APawn* KilledPawn);
	void KillEvent(FString KillType, AAA2_PlayerState*  Killer, AAA2_PlayerState*  Victim, UaDamageType* Damage);
	void Killed(AController* Killer, AController* Killed, APawn* KilledPawn, UaDamageType* DamageType);
	bool PreventDeath(APawn* Killed, AController* Killer, UaDamageType* DamageType, FVector HitLocation);
	bool PreventSever(APawn* Killed, FName BoneName, int32 Damage, UaDamageType* DamageType);
	void BroadcastDeathMessage(AController* Killer, AController* Other, UaDamageType* DamageType);
	void ParseKillMessage(FString KillerName, FString VictimName, FString DeathMessage);
	void KickByController(AController* C, FString Reason, bool bMaybeFail);
	void Kick(FString S, FString Reason, bool bMaybeFail);
	void KickBan(APlayerController* PCAdmin, FString PlayerName, FString time_to_ban_for, FString BanOptions);
	void Ban(APlayerController* PCAdmin, FString PlayerName, FString time_to_ban_for, FString BanOptions);
	bool IsOnTeam(AController* Other, int32 TeamNum);
	bool CanSpectate(APlayerController* Viewer, bool bOnlySpectator, AActor* ViewTarget);
	void ReduceDamage(int32 Damage, APawn* injured, APawn* instigatedBy, FVector HitLocation, FVector Momentum, UaDamageType* DamageType);
	void ShouldRespawn(APickup* Other);
	void PickupQuery(APawn* Other, APickup* Item);
	void DiscardInventory(APawn* Other);
	//void ChangeName(AController* Other, FString S, bool bNameChange);
	bool ChangeTeam(AController* Other, int32 N, bool bNewTeam);
	uint8 PickTeam(uint8 Current, AController* C);
	void SendPlayer(APlayerController* aPlayer, FString URL);
	void RestartGame();
	void GetMapRotation();
	void GetMapList(FString MapListClassType);
	void ChangeVoiceChannel(AAA2_PlayerState*  PRI, int32 NewChannelIndex, int32 OldChannelIndex);
	void Broadcast(AActor* Sender, FString Msg, FName Type);
	void BroadcastTeam(AController* Sender, FString Msg, FName Type);
	//void BroadcastLocalized(AActor* Sender, AaLocalMessage* Message, int32 Switch, AAA2_PlayerState*  RelatedPRI_1, AAA2_PlayerState*  RelatedPRI_2, UObject* OptionalObject);
	bool CheckEndGame(AAA2_PlayerState*  Winner, FString Reason);
	void EndLogging(FString Reason);
	//AAGP_PlayerStart* FindPlayerStart(AController* Player, uint8 InTeam, FString incomingName);
	//void RatePlayerStart(ANavigationPoint* N, uint8 Team, AController* Player);
	void ScoreObjective(AAA2_PlayerState*  Scorer, float Score);
	void CheckScore(AAA2_PlayerState*  Scorer);
	void ScoreEvent(AAA2_PlayerState*  Who, float Points, FString Desc);
	void TeamScoreEvent(int32 Team, float Points, FString Desc);
	void ScoreKill(AController* Killer, AController* Other, UaDamageType*  DamageType);
	bool TooManyBots(AController* botToRemove);
	UTexture2D* GetRandomTeamSymbol(int32 Base);
	FString FindTeamDesignation(AAA2_GameState* GRI, AActor* A);
	//void ParseChatPercVar(AMutator* BaseMutator, AController* Who, FString Cmd);
	//void ParseMessageString(AMutator* BaseMutator, AController* Who, FString Message);
	void FillPlayInfo(APlayInfo* PlayInfo);
	FString GetDisplayText(FString PropName);
	FString GetDescriptionText(FString PropName);
	bool AcceptPlayInfoProperty(FString PropName);
	int32 OrderToIndex(int32 Order);
	void ReviewJumpSpots(FName TestLabel);
	FString RecommendCombo(FString ComboName);
	//void NewRecommendCombo(FString ComboName, AAIController* C);
	//void CanEnterVehicle(AVehicle* V, APawn* p);
	//void DriverEnteredVehicle(AVehicle* V, APawn* p);
	//void CanLeaveVehicle(AVehicle* V, APawn* p);
	//void DriverLeftVehicle(AVehicle* V, APawn* p);
	ATeamInfo* otherTeam(ATeamInfo* Requester);
	void KillBots(int32 Num);
	void AdminSay(FString Msg);
	//void RegisterVehicle(AVehicle* V);
	AActor* FindSpecGoalFor(AAA2_PlayerState*  PRI, int32 TeamIndex);
	uint8 GetDefenderNum();
	void SetGrammar();
	void LoadSRGrammar(FString Grammar);
	void GetPlayerControllerList(TArray<APlayerController*> ControllerArray);
	void ParseVoiceCommand(APlayerController* Sender, FString RecognizedString);
	void AdjustBotInterface(bool bSinglePlayer);
	//void SceneStarted(ASceneManager* SM, AActor* Other);
	//void SceneEnded(ASceneManager* SM, AActor* Other);
	void SceneAbort();
	void NoTranslocatorKeyPressed(APlayerController* PC);
	void GetAllLoadHints(bool bThisClassOnly);
	FString GetLoadingHint(APlayerController* Ref, FString MapName, FColor HintColor);
	FString ParseLoadingHint(FString Hint, APlayerController* Ref, FColor HintColor);
	FString GetKeyBindName(FString Cmd, APlayerController* Ref);
	FString GetNextLoadHint(FString MapName);
	FString MakeColorCode(FColor NewColor);
	int32 GetBindWeight(uint8 KeyNumber);
	bool IsVehicleMutator(FString MutatorClassName);
	bool AllowMutator(FString MutatorClassName);
	void AddServerDetail(FServerResponseLine ServerState, FString RuleName, FString RuleValue);
	FString StripColor(FString S);
	bool JustStarted(float t);
	int32 MultiMinPlayers();
	void WeakObjectives();
	void DisableNextObjective();
	void DeadUse(APlayerController* PC);
	void ResetDecoMeshes();
	void ToggleMutedPlayer(FString PlayerName);
	bool SetScoreMode(FString NewScoreMode);
	void UpdateAllClientsScoreMode();
	void UpdateClientScoreMode(AController* C);
	bool PauseGame(bool bPause, APlayerController* p);
	//void SetLogTarget(AInternetInfo* iinfo);
	void ReadServerSettings();
	bool NeedPassword();
};
