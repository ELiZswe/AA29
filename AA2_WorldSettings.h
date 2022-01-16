// All the original content belonged to the US Army
// Orig name is LevelInfo
#pragma once

#include "CoreMinimal.h"
#include "AA29/MyEnums.h"
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
class ANavigationPoint;
class AAA2_Controller;
class UObjectPool;

UCLASS()
class AAA2_WorldSettings : public AWorldSettings
{
	GENERATED_BODY()
private:
	void LoadTours();
public:
	AAA2_WorldSettings();

	UPROPERTY(EditAnywhere, Category = "LevelSummary")	FString				Title;										//var(LevelSummary) localized string Title;
	UPROPERTY(EditAnywhere, Category = "LevelSummary")	FString				Author;										//var(LevelSummary) string Author;
	UPROPERTY(EditAnywhere, Category = "LevelSummary")	FString				Description;								//var(LevelSummary) string Description;
	UPROPERTY(EditAnywhere, Category = "LevelSummary")	UTexture2D*			Screenshot;									//var(LevelSummary) Material Screenshot;
	UPROPERTY(EditAnywhere, Category = "LevelSummary")	FString				DecoTextName;								//var(LevelSummary) string DecoTextName;
	UPROPERTY(EditAnywhere, Category = "LevelSummary")	int32				IdealPlayerCountMin;						//var(LevelSummary) int IdealPlayerCountMin;
	UPROPERTY(EditAnywhere, Category = "LevelSummary")	int32				IdealPlayerCountMax;						//var(LevelSummary) int IdealPlayerCountMax;
	UPROPERTY(EditAnywhere, Category = "LevelSummary")	FString				ExtraInfo;									//var(LevelSummary) string ExtraInfo;
	UPROPERTY(EditAnywhere, Category = "LevelSummary")	float				fpSinglePlayerFadeInTime;					//var(LevelSummary) float fpSinglePlayerFadeInTime;
	UPROPERTY(EditAnywhere, Category = "LevelSummary")	float				fpSinglePlayerFadeInStart;					//var(LevelSummary) float fpSinglePlayerFadeInStart;
	UPROPERTY(EditAnywhere, Category = "LevelSummary")	bool				bSinglePlayerHideHUD;						//var(LevelSummary) bool bSinglePlayerHideHUD;
	UPROPERTY(EditAnywhere, Category = "LevelSummary")	bool				bSinglePlayerStartUnlocked;					//var(LevelSummary) bool bSinglePlayerStartUnlocked;
	UPROPERTY(EditAnywhere, Category = "RadarMap")		bool				bShowRadarMap;								//var(RadarMap) bool bShowRadarMap;
	UPROPERTY(EditAnywhere, Category = "RadarMap")		UMaterialInstance*	RadarMapImage;								//var(RadarMap) Material RadarMapImage;
	UPROPERTY(EditAnywhere, Category = "RadarMap")		FVector				RadarMapOffset;								//var(RadarMap) FVector RadarMapOffset;
	UPROPERTY(EditAnywhere, Category = "RadarMap")		float				RadarMapSize;								//var(RadarMap) float RadarMapSize;
	UPROPERTY(EditAnywhere, Category = "RadarMap")		TArray<float>		RadarZoomLevels;							//var(RadarMap) array<float> RadarZoomLevels;
	//agp superville
	UPROPERTY(EditAnywhere, Category = "AGP")			EGameplayModes		GamePlayMode;								//var(AGP) EGameplayModes GamePlayMode;					// States the weapon/ammunition type to use for this level
	UPROPERTY(EditAnywhere, Category = "AGP")			bool				allowAI;									//var(AGP) bool allowAI;								//if true, all non-player Pawns have AI modules installed during BeginPlay
	UPROPERTY(EditAnywhere, Category = "AGP")			bool				bDayMission;								//var(AGP) bool bDayMission;
	UPROPERTY(EditAnywhere, Category = "AGP")			bool				bHideInactiveObjectives;					//var(AGP) bool bHideInactiveObjectives;
	UPROPERTY(EditAnywhere, Category = "AGP")			ESkinSet			SkinSetFriendly;							//var(AGP) ESkinSet SkinSetFriendly;
	UPROPERTY(EditAnywhere, Category = "AGP")			ESkinSet			SkinSetEnemy;								//var(AGP) ESkinSet SkinSetEnemy;
	UPROPERTY(EditAnywhere, Category = "AGP")			EMesh				MeshFriendly;								//var(AGP) EMesh MeshFriendly;
	UPROPERTY(EditAnywhere, Category = "AGP")			EMesh				MeshEnemy;									//var(AGP) EMesh MeshEnemy;
	UPROPERTY(EditAnywhere, Category = "AGP")			EWeaponSkinSet		WeaponSkinSetFriendly;						//var(AGP) EWeaponSkinSet WeaponSkinSetFriendly;
	UPROPERTY(EditAnywhere, Category = "AGP")			FString				sAssaultSituationText;						//var string sAssaultSituationText;
	UPROPERTY(EditAnywhere, Category = "AGP")			FString				sDefenseSituationText;						//var string sDefenseSituationText;
	UPROPERTY(EditAnywhere, Category = "AGP")			FString				sAssaultMissionText;						//var string sAssaultMissionText;
	UPROPERTY(EditAnywhere, Category = "AGP")			FString				sDefenseMissionText;						//var string sDefenseMissionText;
	UPROPERTY(EditAnywhere, Category = "AGP")			FString				sAssaultTerrainText;						//var string sAssaultTerrainText;
	UPROPERTY(EditAnywhere, Category = "AGP")			FString				sDefenseTerrainText;						//var string sDefenseTerrainText;
	UPROPERTY(EditAnywhere, Category = "AGP")			FString				sAssaultEnemyForcesText;					//var string sAssaultEnemyForcesText;
	UPROPERTY(EditAnywhere, Category = "AGP")			FString				sDefenseEnemyForcesText;					//var string sDefenseEnemyForcesText;
	UPROPERTY(EditAnywhere, Category = "AGP")			FString				sAssaultFriendlyForcesText;					//var string sAssaultFriendlyForcesText;
	UPROPERTY(EditAnywhere, Category = "AGP")			FString				sDefenseFriendlyForcesText;					//var string sDefenseFriendlyForcesText;
	UPROPERTY(EditAnywhere, Category = "AGP")			FString				sAssaultROEText;							//var string sAssaultROEText;
	UPROPERTY(EditAnywhere, Category = "AGP")			FString				sDefenseROEText;							//var string sDefenseROEText;
	UPROPERTY(EditAnywhere, Category = "AGP")			bool				bDisableOverbright;							//var() bool bDisableOverbright;
	//	UPROPERTY(EditAnywhere, Category = "AGP")			EDetailMode			DetailMode;									//var const Object.EDetailMode DetailMode;						// Client detail mode.
	UPROPERTY(EditAnywhere, Category = "AGP")			int32				YoungestDecal;								//var int YoungestDecal;
	UPROPERTY(EditAnywhere, Category = "AGP")			AInventory*			Team0Inventory;								//var(AGP) class<Inventory> Team0Inventory;				// inventory added to team0 players on spawn
	UPROPERTY(EditAnywhere, Category = "AGP")			AInventory*			Team1Inventory;								//var(AGP) class<Inventory> Team1Inventory;				// inventory added to team1 players on spawn
	UPROPERTY(EditAnywhere, Category = "AGP")			TArray<FString>		TeamName;									//var(AGP) string TeamName;
	UPROPERTY(EditAnywhere, Category = "AGP")			TArray<uint8>		NumAccomplishedObjectivesRequired;			//var(AGP) int NumAccomplishedObjectivesRequired;		// number of objectives a team is required to accomplish
	UPROPERTY(EditAnywhere, Category = "AGP")			bool				bDelayedSpawnNotAllowed;					//var(AGP) bool bDelayedSpawnNotAllowed;
	UPROPERTY(EditAnywhere, Category = "AGP")			bool				bNighttimeMission;							//var(AGP) bool bNighttimeMission;
	UPROPERTY(EditAnywhere, Category = "AGP")			bool				bTeam0HasParachute;							//var(AGP) bool bTeam0HasParachute;
	UPROPERTY(EditAnywhere, Category = "AGP")			bool				bTeam1HasParachute;							//var(AGP) bool bTeam1HasParachute;
	UPROPERTY(EditAnywhere, Category = "AGP")			bool				bTeam0HasNVGs;								//var(AGP) bool bTeam0HasNVGs;							// whether team 0 spawns with NVGs
	UPROPERTY(EditAnywhere, Category = "AGP")			bool				bTeam1HasNVGs;								//var(AGP) bool bTeam1HasNVGs;							// whether team 1 spawns with NVGs
	UPROPERTY(EditAnywhere, Category = "AGP")			bool				bTeam0AllowFlares;							//var(AGP) bool bTeam0AllowFlares;
	UPROPERTY(EditAnywhere, Category = "AGP")			bool				bTeam1AllowFlares;							//var(AGP) bool bTeam1AllowFlares;
	UPROPERTY(EditAnywhere, Category = "AGP")			bool				bTeam0AllowM203Mod;							//var(AGP) bool bTeam0AllowM203Mod;
	UPROPERTY(EditAnywhere, Category = "AGP")			bool				bTeam1AllowM203Mod;							//var(AGP) bool bTeam1AllowM203Mod;
	UPROPERTY(EditAnywhere, Category = "AGP")			bool				bAllowRespawn;								//var(AGP) bool bAllowRespawn;							// allows respawn until playerstarts are used up
	UPROPERTY(EditAnywhere, Category = "AGP")			bool				bUnlimitedRespawn;							//var(AGP) bool bUnlimitedRespawn;						// allows unlimited reuse of playerstarts
	UPROPERTY(EditAnywhere, Category = "AGP")			bool				bAllowLateJoin;								//var(AGP) bool bAllowLateJoin;							// allows players to join in a match in progress
	UPROPERTY(EditAnywhere, Category = "AGP")			uint8				Pawn_NV_AmbientGlow;						//var(AGP) byte Pawn_NV_AmbientGlow;
	UPROPERTY(EditAnywhere, Category = "AGP")			bool				bCoOpGame;									//var(AGP) bool bCoOpGame;
	UPROPERTY(EditAnywhere, Category = "AGP")			bool				bEntryMap;									//var(AGP) bool bEntryMap;
	UPROPERTY(EditAnywhere, Category = "AGP")			bool				bEnableCommo;								//var(AGP) bool bEnableCommo;
	UPROPERTY()																bool				bSkipTest;									//var bool bSkipTest;
	UPROPERTY(EditAnywhere, Category = "AGP")			bool				bAddSLBinocs;								//var(AGP) bool bAddSLBinocs;							// add squad leader binocs
	UPROPERTY(EditAnywhere, Category = "AGP")			bool				bAddFTBinocs;								//var(AGP) bool bAddFTBinocs;							// add fire team leader binocs
	UPROPERTY(EditAnywhere, Category = "AGP")			EDefaultBinoc		DefaultBinoc;								//var(AGP) EDefaultBinoc DefaultBinoc;
	UPROPERTY(EditAnywhere, Category = "AGP")			int32				JavelinMinRangeDirect;						//var(AGP) int JavelinMinRangeDirect;
	UPROPERTY(EditAnywhere, Category = "AGP")			int32				JavelinMinRangeTop;							//var(AGP) int JavelinMinRangeTop;
	UPROPERTY(EditAnywhere, Category = "Scoring")		int32				Score_Team0_Win;							//var(Scoring) int Score_Team0_Win;
	UPROPERTY(EditAnywhere, Category = "Scoring")		int32				Score_Team0_SurviveWin;						//var(Scoring) int Score_Team0_SurviveWin;
	UPROPERTY(EditAnywhere, Category = "Scoring")		int32				Score_Team0_SquadLeaderBonusPerSurvivor;	//var(Scoring) int Score_Team0_SquadLeaderBonusPerSurvivor;
	UPROPERTY(EditAnywhere, Category = "Scoring")		int32				Score_Team0_FTLeaderBonusPerSurvivor;		//var(Scoring) int Score_Team0_FTLeaderBonusPerSurvivor;
	UPROPERTY(EditAnywhere, Category = "Scoring")		int32				Score_Team1_Win;							//var(Scoring) int Score_Team1_Win;
	UPROPERTY(EditAnywhere, Category = "Scoring")		int32				Score_Team1_SurviveWin;						//var(Scoring) int Score_Team1_SurviveWin;
	UPROPERTY(EditAnywhere, Category = "Scoring")		int32				Score_Team1_SquadLeaderBonusPerSurvivor;	//var(Scoring) int Score_Team1_SquadLeaderBonusPerSurvivor;
	UPROPERTY(EditAnywhere, Category = "Scoring")		int32				Score_Team1_FTLeaderBonusPerSurvivor;		//var(Scoring) int Score_Team1_FTLeaderBonusPerSurvivor;
	UPROPERTY(EditAnywhere, Category = "Karma")			float				KarmaTimeScale;								//var(Karma) float KarmaTimeScale;							// Karma physics timestep scaling.
	UPROPERTY(EditAnywhere, Category = "Karma")			float				RagdollTimeScale;							//var(Karma) float RagdollTimeScale;						// Ragdoll physics timestep scaling. This is applied on top of KarmaTimeScale.
	UPROPERTY(EditAnywhere, Category = "Karma")			int32				MaxRagdolls;								//var(Karma) int MaxRagdolls;								// Maximum number of simultaneous rag-dolls.
	UPROPERTY(EditAnywhere, Category = "Karma")			float				KarmaGravScale;								//var(Karma) float KarmaGravScale;							// Allows you to make ragdolls use lower friction than normal.
	UPROPERTY(EditAnywhere, Category = "Karma")			bool				bKStaticFriction;							//var(Karma) bool bKStaticFriction;							// Better rag-doll/ground friction model, but more CPU.
	UPROPERTY(EditAnywhere, Category = "SinglePlayer")	int32				SinglePlayerTeamSize;						//var(SinglePlayer) int SinglePlayerTeamSize;
	UPROPERTY(EditAnywhere, Category = "SaveGames")		bool				bSupportSaveGames;							//var(SaveGames) bool bSupportSaveGames;					// needs to be true to support savegames
	UPROPERTY(EditAnywhere, Category = "Camouflage")	UStaticMesh*		IndoorCamouflageMesh;						//var(Camouflage) StaticMesh IndoorCamouflageMesh;
	UPROPERTY(EditAnywhere, Category = "Camouflage")	float				IndoorMeshDrawscale;						//var(Camouflage) float IndoorMeshDrawscale;
	UPROPERTY(EditAnywhere, Category = "Camouflage")	UStaticMesh*		OutdoorCamouflageMesh;						//var(Camouflage) StaticMesh OutdoorCamouflageMesh;
	UPROPERTY(EditAnywhere, Category = "Camouflage")	float				OutdoorMeshDrawscale;						//var(Camouflage) float OutdoorMeshDrawscale;
	
// When kicking up dust in this level - what colour to use?
	UPROPERTY(EditAnywhere, Category = "DustColor")		FColor				DustColor;									//var(DustColor) Object.Color DustColor;
	UPROPERTY(EditAnywhere, Category = "DustColor")		FColor				WaterDustColor;								//var(DustColor) Object.Color WaterDustColor;
	UPROPERTY()																float				fProjectileMod;								//var float fProjectileMod;								// Stored modification to AGP projectile acceleration
	UPROPERTY()																bool				bSinglePlayerExploreMode;					//var bool bSinglePlayerExploreMode;
	UPROPERTY(EditAnywhere,Config)						EPhysicsDetailLevel PhysicsDetailLevel;							//var() config EPhysicsDetailLevel PhysicsDetailLevel;
	UPROPERTY(EditAnywhere,Config)						EMeshLODDetailLevel MeshLODDetailLevel;							//var() config EMeshLODDetailLevel MeshLODDetailLevel;
	UPROPERTY()																float				TimeSeconds;								//var float TimeSeconds;									// Time in seconds since level began play.
	UPROPERTY()																float				RealSeconds;								//var float RealSeconds;									// AGP - does not get paused!
	UPROPERTY()																int32				Year;										//var transient int Year;
	UPROPERTY()																int32				Month;										//var transient int Month;
	UPROPERTY()																int32				Day;										//var transient int Day;
	UPROPERTY()																int32				DayOfWeek;									//var transient int DayOfWeek;
	UPROPERTY()																int32				Hour;										//var transient int Hour;
	UPROPERTY()																int32				Minute;										//var transient int Minute;
	UPROPERTY()																int32				Second;										//var transient int Second;
	UPROPERTY()																int32				Millisecond;								//var transient int Millisecond;
	UPROPERTY()																float				PauseDelay;									//var float PauseDelay;										// time at which to start pause
	UPROPERTY(EditAnywhere)								bool				bKNoInit;									//var() bool bKNoInit;										// Start _NO_ Karma for this level. Only really for the Entry level.
	UPROPERTY()																int32				LastTaunt;									//var int LastTaunt;										// 'Global' last taunts used.
	UPROPERTY(config)														float				DecalStayScale;								//var config float DecalStayScale;							// affects decal stay time
	UPROPERTY(EditAnywhere)													FString				LevelEnterText;								//var() localized string LevelEnterText;					// Message to tell players when they enter.
	UPROPERTY(EditAnywhere)													FString				LocalizedPkg;								//var() string LocalizedPkg;								// Package to look in for localizations.
	// UPROPERTY(EditAnywhere)												AAA2_PlayerState*	Pauser;										//var PlayerReplicationInfo Pauser;							// If paused, name of person pausing the game.
	UPROPERTY(EditAnywhere)													ULevelSummary*		Summary;									//var LevelSummary Summary;
	UPROPERTY(EditAnywhere)													FString				VisibleGroups;								//var string VisibleGroups;									// List of the group names which were checked when the level was last saved


//-----------------------------------------------------------------------------
// Flags affecting the level.

	UPROPERTY(EditAnywhere, Category="LevelSummary")	bool				HideFromMenus;								//var(LevelSummary) bool HideFromMenus;
	UPROPERTY(EditAnywhere)								bool				bLonePlayer;								//var() bool bLonePlayer;									// No multiplayer coordination, i.e. for entranceways.
	UPROPERTY()																bool				bBegunPlay;									//var bool bBegunPlay;										// Whether gameplay has begun.
	UPROPERTY()																bool				bPlayersOnly;								//var bool bPlayersOnly;									// Only update players.
	UPROPERTY()																bool				bFreezeKarma;								//var bool bFreezeKarma;									// Stop all Karma physics from being evolved.
	UPROPERTY()																bool				bDropDetail;								//var bool bDropDetail;										// frame rate is below DesiredFrameRate, so drop high detail actors
	UPROPERTY()																bool				bAggressiveLOD;								//var bool bAggressiveLOD;									// frame rate is well below DesiredFrameRate, so make LOD more aggressive
	UPROPERTY()																bool				bStartup;									//var bool bStartup;										// Starting gameplay.
	UPROPERTY(config)														bool				bLowSoundDetail;							//var config bool bLowSoundDetail;
	UPROPERTY()																bool				bPathsRebuilt;								//var bool bPathsRebuilt;									// True if path network is valid
	UPROPERTY()																bool				bHasPathNodes;								//var bool bHasPathNodes;	
	UPROPERTY()																bool				bLevelChange;								//var bool bLevelChange;
	UPROPERTY(globalconfig)													bool				bShouldPreload;								//var globalconfig bool bShouldPreload;						// if true, preload all skins (initially set true if > 512 MB of system memory)
	UPROPERTY(globalconfig)													bool				bDesireSkinPreload;							//var globalconfig bool bDesireSkinPreload;					// user set property
	UPROPERTY(globalconfig)													bool				bKickLiveIdlers;							//var globalconfig bool bKickLiveIdlers;					// if true, even playercontrollers with pawns can be kicked for idling
	UPROPERTY()																bool				bSkinsPreloaded;							//var bool bSkinsPreloaded;									// set after skins are preloaded
	UPROPERTY()																bool				bClassicView;								//var bool bClassicView;									// FOV at least 90, eyeheight up, small weapons OBSOLETE
	UPROPERTY()																bool				bIsSaveGame;								//var bool bIsSaveGame;										// true while save game is being loaded (GameInfo bIsSaveGame stays true through entire game)

//-----------------------------------------------------------------------------
// Renderer Management.
	UPROPERTY(EditAnywhere, Category = "LevelSummary")	bool				bAlwaysTickMovies;							//var(LevelSummary) bool bAlwaysTickMovies;
	UPROPERTY(config)														bool				bNeverPrecache;								//var config bool bNeverPrecache;
	UPROPERTY(EditAnywhere)								int32				LevelTextureLODBias;						//var() int LevelTextureLODBias;
	UPROPERTY()																float				AnimMeshGlobalLOD;							//var float AnimMeshGlobalLOD;

//-----------------------------------------------------------------------------
// Legend - used for saving the viewport camera positions
	UPROPERTY(EditAnywhere)													FVector				CameraLocationDynamic;						//var() FVector CameraLocationDynamic;
	UPROPERTY(EditAnywhere)													FVector				CameraLocationTop;							//var() FVector CameraLocationTop;
	UPROPERTY(EditAnywhere)													FVector				CameraLocationFront;						//var() FVector CameraLocationFront;
	UPROPERTY(EditAnywhere)													FVector				CameraLocationSide;							//var() FVector CameraLocationSide;
	UPROPERTY(EditAnywhere)													FRotator			CameraRotationDynamic;						//var() Object.Rotator CameraRotationDynamic;
	
//-----------------------------------------------------------------------------
// Audio properties.
	UPROPERTY(EditAnywhere, Category = "Audio")			FString				Song;										//var(Audio) string Song;
	UPROPERTY(EditAnywhere, Category = "Audio")			float				PlayerDoppler;								//var(Audio) float PlayerDoppler;
	UPROPERTY(EditAnywhere, Category = "Audio")			float				MusicVolumeOverride;						//var(Audio) float MusicVolumeOverride;

//-----------------------------------------------------------------------------
// Miscellaneous information.
	UPROPERTY(EditAnywhere)								float				Brightness;									//var() float Brightness;
	UPROPERTY()																UMaterialInstance*	DefaultTexture;								//var Texture DefaultTexture;
	UPROPERTY()																UMaterialInstance*	WireframeTexture;							//var Texture WireframeTexture;
	UPROPERTY()																UMaterialInstance*	WhiteSquareTexture;							//var Texture WhiteSquareTexture;
	UPROPERTY()																UMaterialInstance*	LargeVertex;								//var Texture LargeVertex;
	UPROPERTY()																int32				HubStackLevel;								//var int HubStackLevel;
	UPROPERTY()																ELevelAction		LevelAction;								//var transient ELevelAction LevelAction;

//-----------------------------------------------------------------------------
// Networking.
	UPROPERTY()																AAA2_GameState*		GRI;										//var transient GameReplicationInfo GRI;
	UPROPERTY()																FString				ComputerName;								//var string ComputerName;
	UPROPERTY()																FString				EngineVersion;								//var string EngineVersion;
	UPROPERTY()																FString				LevelNameMinNetVersion;						//var string MinNetVersion;

//-----------------------------------------------------------------------------
// Gameplay rules
	UPROPERTY(EditAnywhere)								FString DefaultGameType;						//var() string DefaultGameType;
	UPROPERTY(EditAnywhere)								FString PreCacheGame;							//var() string PreCacheGame;
	UPROPERTY()																AGameInfo* Game;								//var GameInfo Game;
	UPROPERTY()																float DefaultGravity;							//var float DefaultGravity;
	UPROPERTY()																float LastVehicleCheck;							//var float LastVehicleCheck;
	UPROPERTY(EditAnywhere)								float StallZ;									//var() float StallZ;

//-----------------------------------------------------------------------------
// Navigation point and Pawn lists (chained using nextNavigationPoint and nextPawn).
	UPROPERTY(EditAnywhere)								ANavigationPoint*	NavigationPointList;		//var const NavigationPoint NavigationPointList;
	UPROPERTY()																AController*	ControllerList;				//var const Controller ControllerList;
	UPROPERTY()																APlayerController*	LocalPlayerController;		//var PlayerController LocalPlayerController;

//-----------------------------------------------------------------------------
// Headlights
	UPROPERTY(EditAnywhere, Category = "Headlights")	bool bUseHeadlights;							//var(Headlights) bool bUseHeadlights;
	UPROPERTY(EditAnywhere, Category = "Headlights")	float HeadlightScaling;							//var(Headlights) float HeadlightScaling;

//-----------------------------------------------------------------------------
// Server related.
	UPROPERTY()																FString NextURL;								//var string NextURL;
	UPROPERTY()																bool bNextItems;								//var bool bNextItems;
	UPROPERTY()																float NextSwitchCountdown;						//var float NextSwitchCountdown;

//-----------------------------------------------------------------------------
// Global object recycling pool.
	UPROPERTY(EditAnywhere)							UObjectPool* ObjectPool;						//var transient ObjectPool ObjectPool;

//-----------------------------------------------------------------------------
// Additional resources to precache (e.g. Playerskins).
	UPROPERTY()																TArray<UMaterialInstance*> PrecacheMaterials;			//var transient array<Material> PrecacheMaterials;
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
	UPROPERTY()																bool					bFirstDraw;				//var bool bFirstDraw;									//Flags the first draw call from UnGame.cpp
	UPROPERTY()																AAGP_Viewpoint*			ViewpointList;			//var AGP_Viewpoint ViewpointList;
	UPROPERTY()																TSubclassOf<APickup>	PickupList;				//var Pickup PickupList;
	UPROPERTY()																AGrenadeHelper*			GrenHelper; 			//var GrenadeHelper GrenHelper;
	UPROPERTY()																AAA2_PlayerState*		Client;					//var PlayerReplicationInfo Client;




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
	UPROPERTY()																	TArray<FString> asETASurNames;					//var TArray<FString> asETASurNames;
	UPROPERTY()																	TArray<FString> asETANickNames;					//var TArray<FString> asETANickNames;
	UPROPERTY()																	TArray<FString> asETAFirstNames;				//var string asETAFirstNames;
	UPROPERTY()																	AController* actrlETAUsedFirstNamePrefixes;		//var Controller actrlETAUsedFirstNamePrefixes;
	UPROPERTY(EditAnywhere, Category="NPCPlayBalancing")	float fpMaxNPCToPlayerRatio;					//var(NPCPlayBalancing) float fpMaxNPCToPlayerRatio;
	UPROPERTY()																	int32 iPBEnabled;								//var int iPBEnabled;

//mission completed variables - used to send to authentication server
	UPROPERTY()																	int32 iNumTours;								//var int iNumTours;
	UPROPERTY()																	FString sLevelName;								//var string sLevelName;
	UPROPERTY()																	int32 iTour;									//var int iTour;
	UPROPERTY()																	int32 iMission;									//var int iMission;
	UPROPERTY()																	FString TourCategory;							//var string TourCategory;
	UPROPERTY()																	bool bTourSequential;							//var bool bTourSequential;
	UPROPERTY()																	FString sMapsDir;								//var string sMapsDir;
	UPROPERTY(BlueprintReadOnly)												TArray<FTourStruct> TourInfo;					//var TourStruct TourInfo;
	UPROPERTY()																	TArray<int32> IgnoreTours;						//var array<int> IgnoreTours;
	UPROPERTY(globalconfig)														bool bEDT;										//var globalconfig bool bEDT;
	UPROPERTY()																	int32 iUID;										//var int iUID;
	
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
	void removePickup(TSubclassOf<APickup> remove_pickup);
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
	APlayerController* GetClientController();
	APawn* GetClientPawn();
	void SetClientController(AController* C);
	AAA2_PlayerState* GetClient();
	bool IsMILES();
	bool IsServer();
	FString GetLevelNamePrivate();
	void GetLevelMissionPrivate(FString sLevelName, int32 iTour, FString sLevelFile);
	void GetLevelTourAndMissionPrivate(FString sLevelName, int32 iTour, int32 iMission);
	void GetMBSTitleTourAndMissionPrivate(FString sLevelName, int32 iTour, int32 iMission);
	void GetLevelTourCategory(FString sLevelName, FString TourCategory);
	bool IsTourSequentialPrivate(int32 iTour);
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
	bool DoesMapExist(FString MapName);
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
	void AddPrecacheMaterial(UMaterialInstance* mat);
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
