// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/MyStructs.h"
#include "AA29/AA29.h"
#include "AA29/AA2_GameState.h"


#include "GameFramework/WorldSettings.h"
#include "AA2_WorldSettings.generated.h"

class AInventory;
class AAGP_Viewpoint;
class APickup;
class USkeletalMesh;
class AGrenadeHelper;
class ULevelSummary;
class AGameInfo;

UCLASS()
class AA29_API AAA2_WorldSettings : public AWorldSettings
{
	GENERATED_BODY()
private:
	void LoadTours();
public:
	AAA2_WorldSettings();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LevelSummary")	FString Title;									//var(LevelSummary) localized string Title;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LevelSummary")	FString Author;									//var(LevelSummary) string Author;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LevelSummary")	FString Description;							//var(LevelSummary) string Description;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LevelSummary")	UTexture2D* Screenshot;							//var(LevelSummary) Material Screenshot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LevelSummary")	FString DecoTextName;							//var(LevelSummary) string DecoTextName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LevelSummary")	int32 IdealPlayerCountMin;						//var(LevelSummary) int IdealPlayerCountMin;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LevelSummary")	int32 IdealPlayerCountMax;						//var(LevelSummary) int IdealPlayerCountMax;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LevelSummary")	FString ExtraInfo;								//var(LevelSummary) string ExtraInfo;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LevelSummary")	float fpSinglePlayerFadeInTime;					//var(LevelSummary) float fpSinglePlayerFadeInTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LevelSummary")	float fpSinglePlayerFadeInStart;				//var(LevelSummary) float fpSinglePlayerFadeInStart;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LevelSummary")	bool bSinglePlayerHideHUD;						//var(LevelSummary) bool bSinglePlayerHideHUD;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LevelSummary")	bool bSinglePlayerStartUnlocked;				//var(LevelSummary) bool bSinglePlayerStartUnlocked;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RadarMap")		bool bShowRadarMap;								//var(RadarMap) bool bShowRadarMap;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RadarMap")		UTexture2D* RadarMapImage;						//var(RadarMap) Material RadarMapImage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RadarMap")		FVector RadarMapOffset;							//var(RadarMap) FVector RadarMapOffset;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RadarMap")		float RadarMapSize;								//var(RadarMap) float RadarMapSize;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RadarMap")		TArray<float> RadarZoomLevels;					//var(RadarMap) array<float> RadarZoomLevels;
	//agp superville
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AGP")			EGameplayModes GamePlayMode;					//var(AGP) EGameplayModes GamePlayMode;					// States the weapon/ammunition type to use for this level
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AGP")			bool allowAI;									//var(AGP) bool allowAI;								//if true, all non-player Pawns have AI modules installed during BeginPlay
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AGP")			bool bDayMission;								//var(AGP) bool bDayMission;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AGP")			bool bHideInactiveObjectives;					//var(AGP) bool bHideInactiveObjectives;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AGP")			ESkinSet SkinSetFriendly;						//var(AGP) ESkinSet SkinSetFriendly;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AGP")			ESkinSet SkinSetEnemy;							//var(AGP) ESkinSet SkinSetEnemy;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AGP")			EMesh MeshFriendly;								//var(AGP) EMesh MeshFriendly;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AGP")			EMesh MeshEnemy;								//var(AGP) EMesh MeshEnemy;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AGP")			EWeaponSkinSet WeaponSkinSetFriendly;			//var(AGP) EWeaponSkinSet WeaponSkinSetFriendly;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AGP")			FString sAssaultSituationText;					//var string sAssaultSituationText;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AGP")			FString sDefenseSituationText;					//var string sDefenseSituationText;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AGP")			FString sAssaultMissionText;					//var string sAssaultMissionText;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AGP")			FString sDefenseMissionText;					//var string sDefenseMissionText;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AGP")			FString sAssaultTerrainText;					//var string sAssaultTerrainText;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AGP")			FString sDefenseTerrainText;					//var string sDefenseTerrainText;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AGP")			FString sAssaultEnemyForcesText;				//var string sAssaultEnemyForcesText;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AGP")			FString sDefenseEnemyForcesText;				//var string sDefenseEnemyForcesText;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AGP")			FString sAssaultFriendlyForcesText;				//var string sAssaultFriendlyForcesText;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AGP")			FString sDefenseFriendlyForcesText;				//var string sDefenseFriendlyForcesText;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AGP")			FString sAssaultROEText;						//var string sAssaultROEText;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AGP")			FString sDefenseROEText;						//var string sDefenseROEText;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AGP")			bool bDisableOverbright;						//var() bool bDisableOverbright;
//	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AGP")			EDetailMode DetailMode;							//var const Object.EDetailMode DetailMode;						// Client detail mode.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AGP")			int32 YoungestDecal;							//var int YoungestDecal;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AGP")			AInventory* Team0Inventory;						//var(AGP) class<Inventory> Team0Inventory;				// inventory added to team0 players on spawn
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AGP")			AInventory* Team1Inventory;						//var(AGP) class<Inventory> Team1Inventory;				// inventory added to team1 players on spawn
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AGP")			TArray<FString> TeamName;						//var(AGP) string TeamName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AGP")			TArray<uint8> NumAccomplishedObjectivesRequired;		//var(AGP) int NumAccomplishedObjectivesRequired;		// number of objectives a team is required to accomplish
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AGP")			bool bDelayedSpawnNotAllowed;					//var(AGP) bool bDelayedSpawnNotAllowed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AGP")			bool bNighttimeMission;							//var(AGP) bool bNighttimeMission;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AGP")			bool bTeam0HasParachute;						//var(AGP) bool bTeam0HasParachute;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AGP")			bool bTeam1HasParachute;						//var(AGP) bool bTeam1HasParachute;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AGP")			bool bTeam0HasNVGs;								//var(AGP) bool bTeam0HasNVGs;							// whether team 0 spawns with NVGs
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AGP")			bool bTeam1HasNVGs;								//var(AGP) bool bTeam1HasNVGs;							// whether team 1 spawns with NVGs
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AGP")			bool bTeam0AllowFlares;							//var(AGP) bool bTeam0AllowFlares;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AGP")			bool bTeam1AllowFlares;							//var(AGP) bool bTeam1AllowFlares;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AGP")			bool bTeam0AllowM203Mod;						//var(AGP) bool bTeam0AllowM203Mod;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AGP")			bool bTeam1AllowM203Mod;						//var(AGP) bool bTeam1AllowM203Mod;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AGP")			bool bAllowRespawn;								//var(AGP) bool bAllowRespawn;							// allows respawn until playerstarts are used up
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AGP")			bool bUnlimitedRespawn;							//var(AGP) bool bUnlimitedRespawn;						// allows unlimited reuse of playerstarts
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AGP")			bool bAllowLateJoin;							//var(AGP) bool bAllowLateJoin;							// allows players to join in a match in progress
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AGP")			uint8 Pawn_NV_AmbientGlow;						//var(AGP) byte Pawn_NV_AmbientGlow;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AGP")			bool bCoOpGame;									//var(AGP) bool bCoOpGame;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AGP")			bool bEntryMap;									//var(AGP) bool bEntryMap;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AGP")			bool bEnableCommo;								//var(AGP) bool bEnableCommo;
	UPROPERTY()																bool bSkipTest;									//var bool bSkipTest;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AGP")			bool bAddSLBinocs;								//var(AGP) bool bAddSLBinocs;							// add squad leader binocs
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AGP")			bool bAddFTBinocs;								//var(AGP) bool bAddFTBinocs;							// add fire team leader binocs
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AGP")			EDefaultBinoc DefaultBinoc;						//var(AGP) EDefaultBinoc DefaultBinoc;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AGP")			int32 JavelinMinRangeDirect;					//var(AGP) int JavelinMinRangeDirect;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AGP")			int32 JavelinMinRangeTop;						//var(AGP) int JavelinMinRangeTop;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scoring")		int32 Score_Team0_Win;							//var(Scoring) int Score_Team0_Win;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scoring")		int32 Score_Team0_SurviveWin;					//var(Scoring) int Score_Team0_SurviveWin;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scoring")		int32 Score_Team0_SquadLeaderBonusPerSurvivor;	//var(Scoring) int Score_Team0_SquadLeaderBonusPerSurvivor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scoring")		int32 Score_Team0_FTLeaderBonusPerSurvivor;		//var(Scoring) int Score_Team0_FTLeaderBonusPerSurvivor;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scoring")		int32 Score_Team1_Win;							//var(Scoring) int Score_Team1_Win;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scoring")		int32 Score_Team1_SurviveWin;					//var(Scoring) int Score_Team1_SurviveWin;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scoring")		int32 Score_Team1_SquadLeaderBonusPerSurvivor;	//var(Scoring) int Score_Team1_SquadLeaderBonusPerSurvivor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scoring")		int32 Score_Team1_FTLeaderBonusPerSurvivor;		//var(Scoring) int Score_Team1_FTLeaderBonusPerSurvivor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Karma")			float KarmaTimeScale;							//var(Karma) float KarmaTimeScale;							// Karma physics timestep scaling.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Karma")			float RagdollTimeScale;							//var(Karma) float RagdollTimeScale;						// Ragdoll physics timestep scaling. This is applied on top of KarmaTimeScale.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Karma")			int32 MaxRagdolls;								//var(Karma) int MaxRagdolls;								// Maximum number of simultaneous rag-dolls.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Karma")			float KarmaGravScale;							//var(Karma) float KarmaGravScale;							// Allows you to make ragdolls use lower friction than normal.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Karma")			bool bKStaticFriction;							//var(Karma) bool bKStaticFriction;							// Better rag-doll/ground friction model, but more CPU.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SinglePlayer")	int32 SinglePlayerTeamSize;						//var(SinglePlayer) int SinglePlayerTeamSize;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SaveGames")		bool bSupportSaveGames;							//var(SaveGames) bool bSupportSaveGames;					// needs to be true to support savegames
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camouflage")	UStaticMesh* IndoorCamouflageMesh;				//var(Camouflage) StaticMesh IndoorCamouflageMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camouflage")	float IndoorMeshDrawscale;						//var(Camouflage) float IndoorMeshDrawscale;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camouflage")	UStaticMesh* OutdoorCamouflageMesh;				//var(Camouflage) StaticMesh OutdoorCamouflageMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camouflage")	float OutdoorMeshDrawscale;						//var(Camouflage) float OutdoorMeshDrawscale;

// When kicking up dust in this level - what colour to use?
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DustColor")		FColor DustColor;								//var(DustColor) Object.Color DustColor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DustColor")		FColor WaterDustColor;							//var(DustColor) Object.Color WaterDustColor;

	UPROPERTY()																float fProjectileMod;							//var float fProjectileMod;								// Stored modification to AGP projectile acceleration
	UPROPERTY()																bool bSinglePlayerExploreMode;					//var bool bSinglePlayerExploreMode;
	UPROPERTY(EditAnywhere, BlueprintReadWrite,Config)						EPhysicsDetailLevel PhysicsDetailLevel;			//var() config EPhysicsDetailLevel PhysicsDetailLevel;
	UPROPERTY(EditAnywhere, BlueprintReadWrite,Config)						EMeshLODDetailLevel MeshLODDetailLevel;			//var() config EMeshLODDetailLevel MeshLODDetailLevel;
	UPROPERTY()																float TimeSeconds;								//var float TimeSeconds;									// Time in seconds since level began play.
	UPROPERTY()																float RealSeconds;								//var float RealSeconds;									// AGP - does not get paused!
	UPROPERTY()																int32 Year;										//var transient int Year;
	UPROPERTY()																int32 Month;									//var transient int Month;
	UPROPERTY()																int32 Day;										//var transient int Day;
	UPROPERTY()																int32 DayOfWeek;								//var transient int DayOfWeek;
	UPROPERTY()																int32 Hour;										//var transient int Hour;
	UPROPERTY()																int32 Minute;									//var transient int Minute;
	UPROPERTY()																int32 Second;									//var transient int Second;
	UPROPERTY()																int32 Millisecond;								//var transient int Millisecond;
	UPROPERTY()																float PauseDelay;								//var float PauseDelay;										// time at which to start pause

	UPROPERTY(EditAnywhere, BlueprintReadWrite)								bool bKNoInit;									//var() bool bKNoInit;										// Start _NO_ Karma for this level. Only really for the Entry level.
	UPROPERTY()																int32 LastTaunt;								//var int LastTaunt;										// 'Global' last taunts used.
	UPROPERTY(config)														float DecalStayScale;							//var config float DecalStayScale;							// affects decal stay time
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								FString LevelEnterText;							//var() localized string LevelEnterText;					// Message to tell players when they enter.
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								FString LocalizedPkg;							//var() string LocalizedPkg;								// Package to look in for localizations.
	//UPROPERTY(EditAnywhere, BlueprintReadWrite)							AAA2_PlayerState* Pauser;						//var PlayerReplicationInfo Pauser;							// If paused, name of person pausing the game.
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								ULevelSummary* Summary;							//var LevelSummary Summary;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								FString VisibleGroups;							//var string VisibleGroups;									// List of the group names which were checked when the level was last saved


//-----------------------------------------------------------------------------
// Flags affecting the level.

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="LevelSummary")	bool HideFromMenus;								//var(LevelSummary) bool HideFromMenus;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								bool bLonePlayer;								//var() bool bLonePlayer;									// No multiplayer coordination, i.e. for entranceways.
	UPROPERTY()																bool bBegunPlay;								//var bool bBegunPlay;										// Whether gameplay has begun.
	UPROPERTY()																bool bPlayersOnly;								//var bool bPlayersOnly;									// Only update players.
	UPROPERTY()																bool bFreezeKarma;								//var bool bFreezeKarma;									// Stop all Karma physics from being evolved.
	UPROPERTY()																bool bDropDetail;								//var bool bDropDetail;										// frame rate is below DesiredFrameRate, so drop high detail actors
	UPROPERTY()																bool bAggressiveLOD;							//var bool bAggressiveLOD;									// frame rate is well below DesiredFrameRate, so make LOD more aggressive
	UPROPERTY()																bool bStartup;									//var bool bStartup;										// Starting gameplay.
	UPROPERTY(config)														bool bLowSoundDetail;							//var config bool bLowSoundDetail;
	UPROPERTY()																bool bPathsRebuilt;								//var bool bPathsRebuilt;									// True if path network is valid
	UPROPERTY()																bool bHasPathNodes;								//var bool bHasPathNodes;	
	UPROPERTY()																bool bLevelChange;								//var bool bLevelChange;
	UPROPERTY(globalconfig)													bool bShouldPreload;							//var globalconfig bool bShouldPreload;						// if true, preload all skins (initially set true if > 512 MB of system memory)
	UPROPERTY(globalconfig)													bool bDesireSkinPreload;						//var globalconfig bool bDesireSkinPreload;					// user set property
	UPROPERTY(globalconfig)													bool bKickLiveIdlers;							//var globalconfig bool bKickLiveIdlers;					// if true, even playercontrollers with pawns can be kicked for idling
	UPROPERTY()																bool bSkinsPreloaded;							//var bool bSkinsPreloaded;									// set after skins are preloaded
	UPROPERTY()																bool bClassicView;								//var bool bClassicView;									// FOV at least 90, eyeheight up, small weapons OBSOLETE
	UPROPERTY()																bool bIsSaveGame;								//var bool bIsSaveGame;										// true while save game is being loaded (GameInfo bIsSaveGame stays true through entire game)

//-----------------------------------------------------------------------------
// Renderer Management.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LevelSummary")	bool bAlwaysTickMovies;							//var(LevelSummary) bool bAlwaysTickMovies;
	UPROPERTY(config)														bool bNeverPrecache;							//var config bool bNeverPrecache;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								int32 LevelTextureLODBias;						//var() int LevelTextureLODBias;
	UPROPERTY()																float AnimMeshGlobalLOD;						//var float AnimMeshGlobalLOD;

																															//-----------------------------------------------------------------------------
// Legend - used for saving the viewport camera positions
	UPROPERTY()																FVector CameraLocationDynamic;					//var() FVector CameraLocationDynamic;
	UPROPERTY()																FVector CameraLocationTop;						//var() FVector CameraLocationTop;
	UPROPERTY()																FVector CameraLocationFront;					//var() FVector CameraLocationFront;
	UPROPERTY()																FVector CameraLocationSide;						//var() FVector CameraLocationSide;
	UPROPERTY()																FRotator CameraRotationDynamic;					//var() Object.Rotator CameraRotationDynamic;

//-----------------------------------------------------------------------------
// Audio properties.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Audio")			FString Song;									//var(Audio) string Song;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Audio")			float PlayerDoppler;							//var(Audio) float PlayerDoppler;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Audio")			float MusicVolumeOverride;						//var(Audio) float MusicVolumeOverride;

//-----------------------------------------------------------------------------
// Miscellaneous information.
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								float Brightness;								//var() float Brightness;
	UPROPERTY()																UTexture2D* DefaultTexture;						//var Texture DefaultTexture;
	UPROPERTY()																UTexture2D* WireframeTexture;					//var Texture WireframeTexture;
	UPROPERTY()																UTexture2D* WhiteSquareTexture;					//var Texture WhiteSquareTexture;
	UPROPERTY()																UTexture2D* LargeVertex;						//var Texture LargeVertex;
	UPROPERTY()																int32 HubStackLevel;							//var int HubStackLevel;
	UPROPERTY()																ELevelAction LevelAction;						//var transient ELevelAction LevelAction;

//-----------------------------------------------------------------------------
// Networking.
	UPROPERTY()																AAA2_GameState* GRI;							//var transient GameReplicationInfo GRI;
	UPROPERTY()																FString ComputerName;							//var string ComputerName;
	UPROPERTY()																FString EngineVersion;							//var string EngineVersion;
	UPROPERTY()																FString LevelNameMinNetVersion;					//var string MinNetVersion;

//-----------------------------------------------------------------------------
// Gameplay rules
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								FString DefaultGameType;						//var() string DefaultGameType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								FString PreCacheGame;							//var() string PreCacheGame;
	UPROPERTY()																AGameInfo* Game;								//var GameInfo Game;
	UPROPERTY()																float DefaultGravity;							//var float DefaultGravity;
	UPROPERTY()																float LastVehicleCheck;							//var float LastVehicleCheck;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								float StallZ;									//var() float StallZ;

//-----------------------------------------------------------------------------
// Navigation point and Pawn lists (chained using nextNavigationPoint and nextPawn).
	//UPROPERTY(EditAnywhere, BlueprintReadWrite)							ANavigationPoint* NavigationPointList;			//var const NavigationPoint NavigationPointList;
	UPROPERTY()																AController* ControllerList;					//var const Controller ControllerList;
	UPROPERTY()																APlayerController* LocalPlayerController;		//var PlayerController LocalPlayerController;

//-----------------------------------------------------------------------------
// Headlights
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Headlights")	bool bUseHeadlights;							//var(Headlights) bool bUseHeadlights;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Headlights")	float HeadlightScaling;							//var(Headlights) float HeadlightScaling;

//-----------------------------------------------------------------------------
// Server related.
	UPROPERTY()																FString NextURL;								//var string NextURL;
	UPROPERTY()																bool bNextItems;								//var bool bNextItems;
	UPROPERTY()																float NextSwitchCountdown;						//var float NextSwitchCountdown;

//-----------------------------------------------------------------------------
// Global object recycling pool.
	//UPROPERTY(EditAnywhere, BlueprintReadWrite)							AObjectPool* ObjectPool;						//var transient ObjectPool ObjectPool;

//-----------------------------------------------------------------------------
// Additional resources to precache (e.g. Playerskins).
	UPROPERTY()																TArray<UTexture2D*> PrecacheMaterials;			//var transient array<Material> PrecacheMaterials;
	UPROPERTY()																TArray<UStaticMesh*> PrecacheStaticMeshes;		//var transient array<StaticMesh> PrecacheStaticMeshes;
	UPROPERTY()																float MoveRepSize;								//var float MoveRepSize;
	UPROPERTY(globalconfig)													float MaxClientFrameRate;						//var globalconfig float MaxClientFrameRate;
	UPROPERTY(globalconfig)													float MaxTimeMargin;							//var globalconfig float MaxTimeMargin;
	UPROPERTY(globalconfig)													float TimeMarginSlack;							//var globalconfig float TimeMarginSlack;
	UPROPERTY(globalconfig)													float MinTimeMargin;							//var globalconfig float MinTimeMargin;
	UPROPERTY()																APlayerController* ReplicationViewer;			//var const PlayerController ReplicationViewer;
	UPROPERTY()																AActor* ReplicationViewTarget;					//var const Actor ReplicationViewTarget;

	/************************/
	/*	BEGIN AGP VARIABLES	*/
	/************************/
	UPROPERTY()																bool bFirstDraw;								//var bool bFirstDraw;									//Flags the first draw call from UnGame.cpp
	UPROPERTY()																AAGP_Viewpoint* ViewpointList;					//var AGP_Viewpoint ViewpointList;
	UPROPERTY()																APickup* PickupList;							//var Pickup PickupList;
	UPROPERTY()																AGrenadeHelper* GrenHelper; 					//var GrenadeHelper GrenHelper;
	UPROPERTY()																AAA2_PlayerState* Client;						//var PlayerReplicationInfo Client;




	//agp	superville
	//debug
	UPROPERTY()																	bool debugRecoil;								//var bool debugRecoil;									// Toggle printout of recoil info
	UPROPERTY()																	bool debugFireMode;								//var bool debugFireMode;								// Toggle printout of fire mod effects
	UPROPERTY()																	bool debugTracer;								//var bool debugTracer;									// Toggle printout of tracer firing
	UPROPERTY()																	bool debugParachute;							//var bool debugParachute;								// Toggle printout of parachute info
	UPROPERTY()																	bool debugInventory;							//var bool debugInventory;								// Toggle printout of inventory info
	UPROPERTY()																	bool debugPosture;								//var bool debugPosture;								// Toggle printout of posture info
	UPROPERTY()																	bool debugGrenade;								//var bool debugGrenade;								// Toggle printout of grenade info
	UPROPERTY()																	bool debugScreenplay;							//var bool debugScreenplay;								// Toggle printout of screenplay info
	UPROPERTY()																	bool debugFalling;								//var bool debugFalling;
	UPROPERTY()																	bool debugShoot;								//var bool debugShoot;
	UPROPERTY()																	bool debugZoom;									//var bool debugZoom;									// Toggle printout of zoom info
	UPROPERTY()																	bool debugMantle;								//var bool debugMantle;
	UPROPERTY()																	bool debugMisFire;								//var bool debugMisFire;
	UPROPERTY()																	bool debugWeaponState;							//var bool debugWeaponState;
	UPROPERTY()																	bool debugPawnState;							//var bool debugPawnState;
	UPROPERTY()																	bool debugWeaponAcc;							//var bool debugWeaponAcc;
	UPROPERTY()																	bool debugBoneTrace;							//var bool debugBoneTrace;
	UPROPERTY()																	bool debugAuth;									//var bool debugAuth;									// Toggle printout of auth/player save info
	UPROPERTY()																	bool debugTours;								//var bool debugTours;									// Toggle printout of tours.ini debug info
	UPROPERTY()																	bool debugObjective;							//var bool debugObjective;								// Toggle printout of objective debug info
	UPROPERTY()																	bool debugDeath;								//var bool debugDeath;
	UPROPERTY()																	bool debugCombatEffect;							//var bool debugCombatEffect;
	UPROPERTY()																	bool debugControllerState;						//var bool debugControllerState;						// Toggle printout of controller state changes

	UPROPERTY(globalconfig)														TArray<EDebugTag> debugList;					//var globalconfig Actor.EDebugTag debugList;
	UPROPERTY(globalconfig)														int32 debug_num;								//var globalconfig int debug_num;

	UPROPERTY()																	int32 DecalSession;								//var int DecalSession;
	UPROPERTY(globalconfig)														int32 KeepDecals;								//var globalconfig int KeepDecals;
	UPROPERTY(globalconfig)														int32 KeepDecoDecals;							//var globalconfig int KeepDecoDecals;
	UPROPERTY(globalconfig)														bool bFadeDecoDecals;							//var globalconfig bool bFadeDecoDecals;
	UPROPERTY(globalconfig)														int32 PMessage;									//var globalconfig int PMessage;
	UPROPERTY(config)															bool bSilentLog;								//var config bool bSilentLog;
	UPROPERTY(globalconfig)														EShadowDetail ShadowDetail;						//var globalconfig EShadowDetail ShadowDetail;

	UPROPERTY()																	AActor* BoneTracer;								//var Actor BoneTracer;
	UPROPERTY()																	TArray<FString> asETASurNames;					//var array<String> asETASurNames;
	UPROPERTY()																	TArray<FString> asETANickNames;					//var array<String> asETANickNames;
	UPROPERTY()																	TArray<FString> asETAFirstNames;				//var string asETAFirstNames;
	UPROPERTY()																	AController* actrlETAUsedFirstNamePrefixes;		//var Controller actrlETAUsedFirstNamePrefixes;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="NPCPlayBalancing")	float fpMaxNPCToPlayerRatio;					//var(NPCPlayBalancing) float fpMaxNPCToPlayerRatio;
	UPROPERTY()																	int32 iPBEnabled;								//var int iPBEnabled;

//mission completed variables - used to send to authentication server
	UPROPERTY()																	int32 iNumTours;								//var int iNumTours;
	UPROPERTY()																	FString sLevelName;								//var string sLevelName;
	UPROPERTY()																	int32 iTour;									//var int iTour;
	UPROPERTY()																	int32 iMission;									//var int iMission;
	UPROPERTY()																	FString TourCategory;							//var string TourCategory;
	UPROPERTY()																	bool bTourSequential;							//var bool bTourSequential;
	UPROPERTY()																	FString sMapsDir;								//var string sMapsDir;
	UPROPERTY()																	TArray<FTourStruct> TourInfo;					//var TourStruct TourInfo;
	UPROPERTY()																	TArray<int32> IgnoreTours;						//var array<int> IgnoreTours;
	UPROPERTY(globalconfig)														bool bEDT;										//var globalconfig bool bEDT;
	UPROPERTY()																	int32 iUID;										//var int iUID;
	
//Already in WorldSettings:
	//UPROPERTY(EditAnywhere, BlueprintReadWrite)								float TimeDilation;								//var float TimeDilation;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite)								ENetMode NetMode;								//var ENetMode NetMode;


	


	void BeginPlay();
	bool IsLanOnlyServer();
	void SetLanOnlyServer();
	void UnsetLanOnlyServer();
	bool IsBetaServer();
	bool IsLeasedServer();
	bool IsOfficialServer();
	bool IsUnofficialServer();
	bool IsNATOServer();
	bool IsTournamentServer();
	bool IsUltimateArenaServer();
	bool IsAuthorizedServer();
	bool IsExploreTheArmyServer();
	FString IsExploreTheArmyAccount(AController* ctrlr, FString sUserName, bool bTestOnly);
	bool EnableDebugThis();
	void PBNotifyServerTravel();
	void PBIsEnabled();
	void PBEnable();
	void PBDisable();
	void FirstDraw();
	void SetupProjectileMod();
	float GetProjectileMod();
	void AddViewpoint(AAGP_Viewpoint* nextv);
	bool debugThis(EDebugTag Debug);
	bool addDebug(EDebugTag Debug);
	bool removeDebug(EDebugTag Debug);
	bool toggleDebug(EDebugTag Debug);
	void addPickup(APickup* add_pickup);
	void removePickup(APickup* remove_pickup);
	void LogPickupList(FString printstring);
	FString GetDefaultBinoc();
	ESkinSet GetSkinSet(bool bFriendly);
	EWeaponSkinSet GetWeaponSkinSet(bool bFriendly);
	bool IsUSSkin(bool bFriendly);
	FString GetSkin_Package();
	ESkinSet GetMILESSkin(ESkinSet tSkin);
	EMesh GetMILESMesh(EMesh tMesh);
	FString GetSkin_Option(bool bFriendly);
	FString GetSkin_Option_Parachute(bool bFriendly);
	FString GetSkin_Group(bool bFriendly);
	EMesh GetMesh(bool bFriendly);
	void SetActorLevelSkin(AActor* A, bool bFriendly, FString level_tag);
	AGrenadeHelper* GetGrenadeHelper();
	void GetClientController();
	void GetClientPawn();
	void SetClientController(AController* C);
	AAA2_PlayerState* GetClient();
	bool IsMILES();
	bool IsServer();
	void GetLevelNamePrivate();
	void GetLevelMissionPrivate(FString sLevelName, int32 iTour, FString sLevelFile);
	void GetLevelTourAndMissionPrivate(FString sLevelName, int32 iTour, int32 iMission);
	void GetMBSTitleTourAndMissionPrivate(FString sLevelName, int32 iTour, int32 iMission);
	void GetLevelTourCategory(FString sLevelName, FString TourCategory);
	void IsTourSequentialPrivate(int32 iTour);
	void CanPlayerPlayMissionPrivate(APlayerController* PC, int32 iTour, int32 iMission);
	int32 DidPlayerCompleteNewMission(APlayerController* PC);
	int32 DidPlayerCompleteNewMissionPrivate(APlayerController* PC, int32 iTour, int32 iMission);
	FString GetLevelName();
	int32 GetLevelTour();
	int32 GetLevelMission();
	bool IsTourSequential();
	void CanPlayerPlayMission(APlayerController* PC);
	void LoadTourInfo();
	FTourStruct GetTour(int32 Index);
	FString GetTourName(int32 Index);
	FString GetTourImage(int32 Index);
	FString GetTourText(int32 Index);
	FString GetTourTextTitle(int32 Index);
	FString GetTourHistoryText(int32 Index);
	FString GetTourHistoryTextTitle(int32 Index);
	int32 GetTourDependency(int32 Index);
	bool GetTourIsSequential(int32 Index);
	bool GetTourIsTraining(int32 Index);
	int32 GetTourMissions(int32 Index);
	FString GetTourMissionTitle(int32 Tour, int32 Mission);
	FString GetTourMissionMBSTitle(int32 Tour, int32 Mission);
	FString GetTourMissionImage(int32 Tour, int32 Mission);
	FString GetTourMissionImageDisabled(int32 Tour, int32 Mission);
	FString GetTourMissionMapFilename(int32 Tour, int32 Mission);
	void ClientGetInfo();
	void DoesMapExist(FString MapName);
	bool IgnoreTourComplete(int32 TourIndex);
	void UpdateAllMissionsStatus(APlayerController* PC);
	int32 GetTourStatus(int32 Tour);
	int32 GetMissionStatus(int32 Tour, int32 Mission);
	FString GetTimeString();
	void PBKickPlayerByController(AController* C, FString Reason);
	void PBKickPlayer(FString PlayerName, FString Reason);
	void DetailChange(EDetailMode NewDetailMode);
	void IsEntry();
	void UpdateDistanceFogLOD(float LOD);
	void ForceLoadTexture(UTexture2D* Texture);
	void GetPhysicsVolume(FVector loc);
	void GetPBGUID(APlayerController* PC);
	void GetPBGUIDFromIP(FString sIPAddress);
	void PostBeginPlay();
	void GetGameClass();
	void FillPrecacheMaterialsArray(bool FullPrecache);
	void PrecacheAnnouncements();
	void FillPrecacheStaticMeshesArray(bool FullPrecache);
	void AddPrecacheMaterial(UTexture2D* mat);
	void AddPrecacheStaticMesh(UStaticMesh* stat);
	void GetLocalURL();
	void IsDemoBuild();
	void IsSoftwareRendering();
	FString GetAddressURL();
	void IsPendingConnection();
	void ServerTravel(FString URL, bool bItems);
	void ThisIsNeverExecuted();
	void Reset();
	void PreBeginPlay();
	void GetLocalPlayerController();

	
};
