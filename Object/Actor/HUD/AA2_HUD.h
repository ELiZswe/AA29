// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "AA29/MyEnums.h"
#include "AA29/AA29.h"
#include "AA2_HUD.generated.h"

class AScoreBoard;
class ASceneSubtitles;
class AHudOverlay;

UCLASS()
class AAA2_HUD : public AHUD
{
	GENERATED_BODY()
public:
	AAA2_HUD(const FObjectInitializer& ObjectInitializer);

	//Already in HUD
	// UPROPERTY(EditAnywhere)						APlayerController*		PlayerOwner;					//var() PlayerController PlayerOwner;
	// UPROPERTY(EditAnywhere)						bool					bShowDebugInfo;					//var() bool bShowDebugInfo;


	UPROPERTY(EditAnywhere)						APawn*					PawnOwner;						//var() Pawn PawnOwner;
	UPROPERTY(EditAnywhere)						AAA2_PlayerState*		PawnOwnerPRI;					//var() PlayerReplicationInfo PawnOwnerPRI;
	UPROPERTY(EditAnywhere)						UConsole*				PlayerConsole;					//var() Console PlayerConsole;
	UPROPERTY(EditAnywhere)						AScoreBoard*			ScoreBoard;						//var() ScoreBoard ScoreBoard;
	UPROPERTY(EditAnywhere)						AScoreBoard*			LocalStatsScreen;				//var() ScoreBoard LocalStatsScreen;
	UPROPERTY(EditAnywhere)						AActor*					VoteMenu;						//var() Actor VoteMenu;
	UPROPERTY()									FColor					WhiteColor;						//var Color WhiteColor;
	UPROPERTY()									FColor					RedColor;						//var Color RedColor;
	UPROPERTY()									FColor					GreenColor;						//var Color GreenColor;
	UPROPERTY()									FColor					CyanColor;						//var Color CyanColor;
	UPROPERTY()									FColor					BlueColor;						//var Color BlueColor;
	UPROPERTY()									FColor					GoldColor;						//var Color GoldColor;
	UPROPERTY()									FColor					PurpleColor;					//var Color PurpleColor;
	UPROPERTY()									FColor					TurqColor;						//var Color TurqColor;
	UPROPERTY()									FColor					GrayColor;						//var Color GrayColor;
	UPROPERTY()									FColor					BlackColor;						//var Color BlackColor;
	UPROPERTY(EditAnywhere)						bool					bShowVoteMenu;					//var() bool bShowVoteMenu;
	UPROPERTY(EditAnywhere)						bool					bHideHUD;						//var() globalconfig bool bHideHUD;
	UPROPERTY(EditAnywhere)						bool					bShowScoreBoard;				//var() bool bShowScoreBoard;
	UPROPERTY(EditAnywhere)						bool					bShowBadConnectionAlert;		//var() bool bShowBadConnectionAlert;
	UPROPERTY(EditAnywhere)						bool					bMessageBeep;					//var() globalconfig bool bMessageBeep;
	UPROPERTY(EditAnywhere)						bool					bShowWeaponInfo;				//var() globalconfig bool bShowWeaponInfo;
	UPROPERTY(EditAnywhere)						bool					bShowPersonalInfo;				//var() globalconfig bool bShowPersonalInfo;
	UPROPERTY(EditAnywhere)						bool					bShowPoints;					//var() globalconfig bool bShowPoints;
	UPROPERTY(EditAnywhere)						bool					bShowWeaponBar;					//var() globalconfig bool bShowWeaponBar;
	UPROPERTY(EditAnywhere)						bool					bCrosshairShow;					//var() globalconfig bool bCrosshairShow;
	UPROPERTY(EditAnywhere)						bool					bShowPortrait;					//var() globalconfig bool bShowPortrait;
	UPROPERTY(EditAnywhere)						bool					bShowPortraitVC;				//var() globalconfig bool bShowPortraitVC;
	UPROPERTY(globalconfig)						bool					bNoEnemyNames;					//var globalconfig bool bNoEnemyNames;
	UPROPERTY(globalconfig)						bool					bSmallWeaponBar;				//var globalconfig bool bSmallWeaponBar;
	UPROPERTY(EditAnywhere)						bool					bShowVehicleDebugInfo;			//var() bool bShowVehicleDebugInfo;
	UPROPERTY()									bool					bBuiltMOTD;						//var bool bBuiltMOTD;
	UPROPERTY()									bool					bShowLocalStats;				//var bool bShowLocalStats;
	UPROPERTY(EditAnywhere)						FColor					ConsoleColor;					//var() Color ConsoleColor;
	UPROPERTY()									AAA2_PlayerState*		PortraitPRI;					//var PlayerReplicationInfo PortraitPRI;
	UPROPERTY(EditAnywhere)						FString					ProgressFontName;				//var() localized FString ProgressFontName;
	UPROPERTY(EditAnywhere)						UFont*					ProgressFontFont;				//var() Font ProgressFontFont;
	UPROPERTY(EditAnywhere)						FString					OverrideConsoleFontName;		//var() localized FString OverrideConsoleFontName;
	UPROPERTY(EditAnywhere)						UFont*					OverrideConsoleFont;			//var() Font OverrideConsoleFont;
	UPROPERTY(EditAnywhere)						float					ProgressFadeTime;				//var() float ProgressFadeTime;
	UPROPERTY(EditAnywhere)						FColor					MOTDColor;						//var() Color MOTDColor;
	UPROPERTY(EditAnywhere, globalconfig)		float					HudScale;						//var() globalconfig float HudScale;
	UPROPERTY(EditAnywhere, globalconfig)		float					HudOpacity;						//var() globalconfig float HudOpacity;
	UPROPERTY(EditAnywhere, globalconfig)		float					HudCanvasScale;					//var() globalconfig float HudCanvasScale;
	UPROPERTY(EditAnywhere, globalconfig)		int32					CrosshairStyle;					//var() globalconfig int32 CrosshairStyle;
	UPROPERTY(EditAnywhere, globalconfig)		float					CrosshairScale;					//var() globalconfig float CrosshairScale;
	UPROPERTY(EditAnywhere, globalconfig)		float					CrosshairOpacity;				//var() globalconfig float CrosshairOpacity;
	UPROPERTY(EditAnywhere, globalconfig)		FColor					CrossHairColor;					//var() globalconfig Color CrossHairColor;
	UPROPERTY()									float					ResScaleX;						//var transient float ResScaleX;
	UPROPERTY()									float					ResScaleY;						//var transient float ResScaleY;
	UPROPERTY()									int32					ConsoleMessageCount;			//var globalconfig int32 ConsoleMessageCount;
	UPROPERTY(globalconfig)						int32					ConsoleFontSize;				//var globalconfig int32 ConsoleFontSize;
	UPROPERTY(globalconfig)						int32					MessageFontOffset;				//var globalconfig int32 MessageFontOffset;
	UPROPERTY()									bool					bPortalDebugView;				//var bool bPortalDebugView;
	UPROPERTY(EditAnywhere, globalconfig)		float					DebugSceneXLocation;			//var() globalconfig float DebugSceneXLocation;
	UPROPERTY(EditAnywhere, globalconfig)		float					DebugSceneYLocation;			//var() globalconfig float DebugSceneYLocation;
	UPROPERTY(EditAnywhere, globalconfig)		float					DebugSceneSizeX;				//var() globalconfig float DebugSceneSizeX;
	UPROPERTY(EditAnywhere, globalconfig)		float					DebugSceneSizeY;				//var() globalconfig float DebugSceneSizeY;
	UPROPERTY(EditAnywhere, globalconfig)		int32					DebugSceneFOV;					//var() globalconfig int32 DebugSceneFOV;
	UPROPERTY(EditAnywhere, globalconfig)		bool					LowSpamDebugInfo;				//var() globalconfig bool LowSpamDebugInfo;
	UPROPERTY(EditAnywhere, globalconfig)		FColor					LowSpamDebugInfoTextColor;		//var() globalconfig Color LowSpamDebugInfoTextColor;
	UPROPERTY(EditAnywhere, globalconfig)		float					DebugSceneDistanceOverride;		//var() globalconfig float DebugSceneDistanceOverride;
	UPROPERTY()									TArray<FConsoleMessage>	TextMessages;					//var ConsoleMessage TextMessages[8];
	UPROPERTY(EditAnywhere)						float					ConsoleMessagePosX;				//var() float ConsoleMessagePosX;
	UPROPERTY(EditAnywhere)						float					ConsoleMessagePosY;				//var() float ConsoleMessagePosY;
	UPROPERTY()									TArray<FString>			FontArrayNames;					//var localized FString FontArrayNames[9];
	UPROPERTY()									TArray<UFont*>			FontArrayFonts;					//var Font FontArrayFonts[9];
	UPROPERTY()									TArray<int32>			FontScreenWidthMedium;			//var int32 FontScreenWidthMedium[9];
	UPROPERTY()									TArray<int32>			FontScreenWidthSmall;			//var int32 FontScreenWidthSmall[9];
	UPROPERTY()									TArray<FString>			MOTD;							//var FString MOTD[4];
	UPROPERTY()									int32					MOTDState;						//var int32 MOTDState;
	UPROPERTY()									float					LastPickupTime;					//var float LastPickupTime;
	UPROPERTY()									float					LastAmmoPickupTime;				//var float LastAmmoPickupTime;
	UPROPERTY()									float					LastWeaponPickupTime;			//var float LastWeaponPickupTime;
	UPROPERTY()									float					LastHealthPickupTime;			//var float LastHealthPickupTime;
	UPROPERTY()									float					LastArmorPickupTime;			//var float LastArmorPickupTime;
	UPROPERTY()									float					LastVoiceGain;					//var const float LastVoiceGain;
	UPROPERTY()									float					LastVoiceGainTime;				//var const float LastVoiceGainTime;
	UPROPERTY()									int32					LastPlayerIDTalking;			//var int32 LastPlayerIDTalking;
	UPROPERTY()									float					LastPlayerIDTalkingTime;		//var const float LastPlayerIDTalkingTime;
	UPROPERTY()									ASceneSubtitles*		SubTitles;						//var SceneSubtitles SubTitles;
	UPROPERTY()									TArray<AHudOverlay*>	Overlays;						//var TArray<HudOverlay> Overlays;
	UPROPERTY()									UFont*					SmallFont;						//var Font SmallFont;
	UPROPERTY()									UFont*					MedFont;						//var Font MedFont;
	UPROPERTY()									UFont*					BigFont;						//var Font BigFont;
	UPROPERTY()									UFont*					LargeFont;						//var Font LargeFont;
	UPROPERTY()									FString					HUDConfigWindowType;			//var FString HUDConfigWindowType;
	UPROPERTY()									AHUD*					nextHUD;						//var HUD nextHUD;
	UPROPERTY()									bool					bShowScores;					//var bool bShowScores;
	UPROPERTY()									bool					bHideCenterMessages;			//var bool bHideCenterMessages;
	UPROPERTY()									bool					bBadConnectionAlert;			//var bool bBadConnectionAlert;
	UPROPERTY()									bool					bMenuVisible;					//var bool bMenuVisible;
	UPROPERTY()									FString					LoadingMessage;					//var localized FString LoadingMessage;
	UPROPERTY()									FString					SavingMessage;					//var localized FString SavingMessage;
	UPROPERTY()									FString					ConnectingMessage;				//var localized FString ConnectingMessage;
	UPROPERTY()									FString					PausedMessage;					//var localized FString PausedMessage;
	UPROPERTY()									FString					PrecachingMessage;				//var localized FString PrecachingMessage;
	UPROPERTY()									FColor					HUDColor;						//var Color HUDColor;
	UPROPERTY()									bool					bShowObjectives;				//var bool bShowObjectives;
	UPROPERTY()									bool					bHideCompassObjPoints;			//var bool bHideCompassObjPoints;
	UPROPERTY()									bool					bBRoll;							//var bool bBRoll;
	UPROPERTY()									UMaterialInstance*		Movie;							//var const transient Movie Movie;
	UPROPERTY()									int32					MoviePosX;						//var int32 MoviePosX;
	UPROPERTY()									int32					MoviePosY;						//var int32 MoviePosY;
	UPROPERTY()									float					TexMovieTop;					//var float TexMovieTop;
	UPROPERTY()									float					TexMovieLeft;					//var float TexMovieLeft;
	UPROPERTY()									float					TexMovieBottom;					//var float TexMovieBottom;
	UPROPERTY()									float					TexMovieRight;					//var float TexMovieRight;
	UPROPERTY()									bool					TexMovieTranslucent;			//var bool TexMovieTranslucent;
	UPROPERTY()									UMaterialInstance*		TextureMovie;					//var MovieTexture TextureMovie;
	UPROPERTY(EditAnywhere)						bool					bShowPaths;						//var() bool bShowPaths;
	UPROPERTY(EditAnywhere)						bool					bShowRoads;						//var() bool bShowRoads;
	UPROPERTY()									FString					sDebugPostRenderStage2Status;	//var FString sDebugPostRenderStage2Status;

};
