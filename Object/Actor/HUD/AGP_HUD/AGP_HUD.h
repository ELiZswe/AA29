// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/HUD/AA2_HUD.h"
#include "AA29/MyEnums.h"
#include "Engine/Canvas.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "AGP_HUD.generated.h"


static const int32 kHUDResX = 800;
static const int32 kHUDResY = 600;
static const int32 kConsoleSizeY = 240;
static const int32 kServerInfoX = 10;
static const int32 kServerInfoY = 10;
static const int32 kSpectateTextRightX = 10;
static const int32 kSpectateTextY = 25;
static const int32 kConsoleOffsetX = 35;
static const int32 kMessagePromptPosition = 1;										    // vertical position to draw message prompt, scaled off of 800x600
static const int32 kMessagePosition = 18;												// vertical position to start drawing messages, scaled by 800x600
static const int32 kMessagePromptPositionWithFocusDebug = 305;
static const int32 kMessagePositionWithFocusDebug = 320;
static const int32 kMessagePromptPositionWithTrainingWindow = 260;
static const int32 kMessagePositionWithFocusWithTrainingWindow = 275;
static const float kCMessageFade = 2.0f;												// time to start fading the message
static const float SHORTMESSAGE_DELAYTIME = 0.10f;

/**
 *
 */
UCLASS()
class AA29_API AAGP_HUD : public AAA2_HUD
{
	GENERATED_BODY()

public:
		virtual void DrawHUD();

	AAGP_HUD(const FObjectInitializer& ObjectInitializer);

public:
	UPROPERTY()													bool bHideHUD;								//var bool bHideHUD; // now defined in HUD.uc

/** Primary draw call for the HUD */
	UPROPERTY()													UTexture2D* tFill;							//var Texture tFill;						// texture for the objective display
	UPROPERTY()													int32 oldclipx;								//var int oldclipx;
	UPROPERTY()													int32 LastMOTDDisplaySeconds;				//var int LastMOTDDisplaySeconds;

// configuration options
	UPROPERTY()													bool bDrawHUD;								//var bool bDrawHUD;
	UPROPERTY()													FString FontInfoClass;						//var string FontInfoClass;
	UPROPERTY()													bool bShowGameMenu;							//var bool bShowGameMenu;
	UPROPERTY()													bool bShowMainMenu;							//var bool bShowMainMenu;
	UPROPERTY()													bool bShowMissionResults;					//var bool bShowMissionResults;
//Already in HUD	
	//UPROPERTY()												bool bShowHUD;								//var bool bShowHUD;									// display any HUD elements
	UPROPERTY()													bool bShowVersion;							//var bool bShowVersion;								// display the version number
	UPROPERTY()													bool bShowLogo;								//var bool bShowLogo;									// display the developer logo
	UPROPERTY()													bool bShowTimer;							//var bool bShowTimer;
	UPROPERTY()													bool bMouseClick;							//var bool bMouseClick;
	UPROPERTY()													bool bFirstTime;							//var bool bFirstTime;
	UPROPERTY()													bool bMainMenuFirstTime;					//var bool bMainMenuFirstTime;
	UPROPERTY()													bool bShowDebugCE;							//var bool bShowDebugCE;
	UPROPERTY()													bool bShowSpectatorInfo;					//var bool bShowSpectatorInfo;
	//UPROPERTY()												AGameMenuFrame* gmFrame;					//var GameMenuFrame gmFrame;
	//UPROPERTY()												AGameMenuFrame* mmFrame;					//var MainMenuFrame mmFrame;
	//UPROPERTY()												AMissionResultsFrame* mrFrame;				//var MissionResultsFrame mrFrame;		
	//UPROPERTY()												AHUDFrame* _cHUDFrame;						//var HUDFrame _cHUDFrame;
	UPROPERTY()													bool bShowCoords;							//var bool bShowCoords;
	UPROPERTY()													float fSpectateTextOffset;					//var float fSpectateTextOffset;
	//UPROPERTY()												UScriptObject* _MissionResultTarget;		//var ScriptObject _MissionResultTarget;			// mission result target
		
	// VERSION INFO
	UPROPERTY()													FString _sVersionInfo;						//var string _sVersionInfo;

	// HUD customization
	UPROPERTY(Config)											FColor CustomHUDColor;						//var config Object.Color CustomHUDColor;
	UPROPERTY(Config)											bool bUsingCustomHUDColor;					//var config bool bUsingCustomHUDColor;
	UPROPERTY(Config)											float CustomHUDAlpha;						//var config float CustomHUDAlpha;
	UPROPERTY()													bool LanServerBrowser;						//var bool LanServerBrowser;
	UPROPERTY(Config)											FString ServerBrowser;						//var config string ServerBrowser;
	UPROPERTY(Config)											float fpConsoleWidthPercent;				//var config float fpConsoleWidthPercent;
	UPROPERTY(Config)											bool bDisableNotificationMessages;			//var config bool bDisableNotificationMessages;
	UPROPERTY()													FColor MessagePromptColor;					//var Object.Color MessagePromptColor;					// draw color of message prompt

	//UPROPERTY()												AClientBeaconReceiver* ClientBeacon;		//var IpDrv.ClientBeaconReceiver ClientBeacon;
	//UPROPERTY()												AGameSpyServerList* BrowserGSPY;			//var IpDrv.GameSpyServerList BrowserGSPY;
	//UPROPERTY()												AServerBrowserSCI* BrowserSCI;				//var IpDrv.ServerBrowserSCI BrowserSCI;
	//UPROPERTY()												AServerBrowserDBMBS* BrowserDBMBS;			//var DBAuth.ServerBrowserDBMBS BrowserDBMBS;
	//UPROPERTY()												AI3DL2Listener* SavedZoneEffect;			//var I3DL2Listener SavedZoneEffect;				// store zone effect while in menu

	// centered message variables
	UPROPERTY()													TArray<FString> _sCMessage;					//var string _sCMessage;								// message to display
	UPROPERTY()													FString LongMessage;						//var string LongMessage;								// long message to display
	UPROPERTY()													float _fCMessageTimeout;					//var float _fCMessageTimeout;							// time to stop drawing the message
	UPROPERTY()													float LongMessageTimeout;					//var float LongMessageTimeout;							// time to stop drawing long message
	//UPROPERTY()												AFont* LongMessageFont;						//var Font LongMessageFont;							// Font to use when drawing long message (optional)
	UPROPERTY()													UTexture2D* tArmyBox;						//var Texture tArmyBox;
	UPROPERTY()													int32 PMessage;								//var int PMessage;
	UPROPERTY()													int32 iPrevHUDAlpha;						//var int iPrevHUDAlpha;
	UPROPERTY()													int32 iPrevHUDColor;						//var int iPrevHUDColor;
	UPROPERTY()													FColor cPrevHUDColor;						//var Object.Color cPrevHUDColor;

// resolution variables to handle 640x480
	UPROPERTY()													int32 iDesiredXRes;							//var int iDesiredXRes;
	UPROPERTY()													int32 iDesiredYRes;							//var int iDesiredYRes;
	UPROPERTY()													bool _bUIConsole;							//var bool _bUIConsole;									// flag to tell us that the console is being drawn by the UIConsole - for server admin command post
	UPROPERTY()													FString sServerMode;						//var string sServerMode;
	UPROPERTY(Config)											int32 RadarMaskIndex;						//var config int RadarMaskIndex;
	UPROPERTY(Config)											bool bRotateRadarAroundPlayer;				//var config bool bRotateRadarAroundPlayer;
	//UPROPERTY()												AMovieTexture* mtMovieToPlay;				//var MovieTexture mtMovieToPlay;
	UPROPERTY()													USoundBase* sndMovieSoundToPlay;			//var Sound sndMovieSoundToPlay;
	UPROPERTY()													int32 iMovieFrameRate;						//var int iMovieFrameRate;
	UPROPERTY()													FString sMovieTitle;						//var string sMovieTitle;
	UPROPERTY()													FString sMovieCaption;						//var string sMovieCaption;
	UPROPERTY()													FString sMOSMovieTitle;						//var string sMOSMovieTitle;
	UPROPERTY()													FString sMOSMovieCaption;					//var string sMOSMovieCaption;
	UPROPERTY()													float fpVolumeMovieToPlayOnUse;				//var float fpVolumeMovieToPlayOnUse;
	UPROPERTY()													FString sRHModalText;						//var string sRHModalText;
	UPROPERTY()													FString sRHExternalLinkTitle;				//var string sRHExternalLinkTitle;
	UPROPERTY()													FString sRHExternalLinkCaption;				//var string sRHExternalLinkCaption;
	UPROPERTY()													float LastSizeX;							//var float LastSizeX;
	UPROPERTY()													FRotator CirclingRotation;					//var Object.Rotator CirclingRotation;
	UPROPERTY()													float fpTimeSinceMessagesRebuilt;			//var float fpTimeSinceMessagesRebuilt;
	UPROPERTY()													FString ShortMessages;						//var string ShortMessages;
	UPROPERTY()													FColor ShortColor;							//var Object.Color ShortColor;
	UPROPERTY()													float afpShortMessageLengthYL;				//var float afpShortMessageLengthYL;
	UPROPERTY()													FColor HUDColor;

	//From AA2 HUD.uc
	UPROPERTY()													bool bShowObjectives;						//var bool  bShowObjectives;			// whether should draw the objectives
	UPROPERTY()													bool bHideCompassObjPoints;					//var bool  bHideCompassObjPoints;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)					APawn* PawnOwner;							//var() Pawn PawnOwner;
	UPROPERTY()													bool bBuiltMOTD;							//var bool bBuiltMOTD;					// Set to true when the MOTD has been set
	UPROPERTY()													bool bShowScores;							//var bool bShowScores;
	UPROPERTY()													bool bHideCenterMessages;					//var bool	bHideCenterMessages;		// don't draw centered messages (screen center being used)
	UPROPERTY()													bool bBadConnectionAlert;					//var bool  bBadConnectionAlert;		// display warning about bad connection
	UPROPERTY()													bool bMenuVisible;							//var bool	bMenuVisible;
	UPROPERTY()													bool bPortalDebugView;						//var bool bPortalDebugView;
	UPROPERTY()													UFont* UE4Font;
	UPROPERTY()													float DefaultFontScale;

	UFUNCTION()	void DetermineVersionLabel(bool bCheat, bool bDev, bool bBeta, bool bLeased, bool bOfficial, bool bNATO, bool bTournament, bool bUltimateArena, bool bIsAuthorized, bool bExploreTheArmyServer, bool bAllowForceclassing);
	UFUNCTION()	int32 GetVersionAGPMajor();
	UFUNCTION()	int32 GetVersionAGPMinor();
	UFUNCTION()	int32 GetVersionAGPTiny();
	UFUNCTION()	int32 GetVersionAGPSubTiny();
	UFUNCTION()	bool AllowFade();


	UFUNCTION()	void GetMouseX();																									//native final Function GetMouseX();
	UFUNCTION()	void GetMouseY();																									//native final Function GetMouseY();
	UFUNCTION()	void UpdatePrecacheMaterials();																						//simulated Function UpdatePrecacheMaterials();
	UFUNCTION()	void PrecacheFonts(UCanvas* C);																						//simulated Function PrecacheFonts(Canvas C);
	UFUNCTION()	void UseSmallFont(UCanvas* C);																						//Function UseSmallFont(Canvas Canvas);
	UFUNCTION()	void TournamentNotifyNewTeamCaptain();																				//Function TournamentNotifyNewTeamCaptain();
	UFUNCTION()	void TournamentNotifyOtherTeamReady();																				//Function TournamentNotifyOtherTeamReady();
	UFUNCTION()	void TournamentNotifyNewTeamName();																					//Function TournamentNotifyNewTeamName();
	UFUNCTION()	void TournamentNotifyNewWeaponClassLockState();																		//Function TournamentNotifyNewWeaponClassLockState();
	UFUNCTION()	void TournamentNotifyMyTeamReady();																					//Function TournamentNotifyMyTeamReady();
	UFUNCTION()	void SetHUDActor();																									//Function SetHUDActor();
	UFUNCTION()	void FreeHUDActor();																								//Function FreeHUDActor();
	UFUNCTION()	void GetHUDControl(int32 Id);																						//Function GetHUDControl(int Id);
	UFUNCTION()	void CreateUIObject(FString ObjectName);																			//static Function CreateUIObject(string ObjectName);
	UFUNCTION()	void Destroyed();																									//Function Destroyed();

	UFUNCTION()	void PostRender_Stage2(UCanvas* C);																					//Event PostRender_Stage2(Canvas Canvas);
	UFUNCTION()	void DrawConsole(UCanvas* C);																						//Function DrawConsole(Canvas Canvas);
	UFUNCTION()	void PostRender_Stage1(UCanvas* C);																					//Event PostRender_Stage1(Canvas Canvas);
	UFUNCTION()	void PostRender_Stage2_DrawConsole(UCanvas* C);																		//simulated Function PostRender_Stage2_DrawConsole(Canvas Canvas);
	UFUNCTION()	void DrawMenu(UCanvas* C);																							//simulated Function DrawMenu(Canvas Canvas);
	UFUNCTION()	void DrawAngleEditor(UCanvas* C);																					//Function DrawAngleEditor(Canvas Canvas);

	UFUNCTION()	void WorldSpaceOverlays();																							//simulated Event WorldSpaceOverlays();
	//UFUNCTION()	void  SetMissionResultTarget(ScriptObject so);																	//Function SetMissionResultTarget(ScriptObject so);
	UFUNCTION()	void CreateFrame();																									//Function CreateFrame();
	UFUNCTION()	void FillListBox();																									//Function FillListBox();
	UFUNCTION()	void FrameOverride();																								//Function FrameOverride();
	UFUNCTION()	void DisablePlayer();																								//Function DisablePlayer();
	UFUNCTION()	void EnablePlayer();																								//Function EnablePlayer();
	UFUNCTION()	void SetConsoleWidth(FString sNewWidthPercent);																		//Function SetConsoleWidth(string sNewWidthPercent);
	UFUNCTION()	void OLD_ShowScores();																								//Function OLD_ShowScores();
	UFUNCTION()	void ShowScores();																									//Function ShowScores();
	UFUNCTION()	void OpenGameMenu();																								//Function OpenGameMenu();
	UFUNCTION()	void CloseGameMenu();																								//Function CloseGameMenu();
	UFUNCTION()	void ToggleAGPGameMenu();																							//Function ToggleAGPGameMenu();
	UFUNCTION()	void ToggleAGPMainMenu();																							//Function ToggleAGPMainMenu();
	UFUNCTION()	void CloseAllMenus();																								//Function CloseAllMenus();
	UFUNCTION()	void  OpenMainMenu();																								//Function OpenMainMenu();
	UFUNCTION()	void CloseMainMenu();																								//Function CloseMainMenu();
	UFUNCTION()	void OpenMissionResults();																							//Function OpenMissionResults();
	UFUNCTION()	void CloseMissionResults();																							//Function CloseMissionResults();
	UFUNCTION()	void OpenMap(FString sMap);																							//Function OpenMap(string sMap);
	UFUNCTION()	void SpawnItem(FString Item);																						//Function SpawnItem(string Item);
	UFUNCTION()	bool KeyType(int32 Key);																							//Function KeyType(int Key);
	UFUNCTION()	void ProcessKeyEvent(int32 Key, int32 Action, float Delta);															//Function ProcessKeyEvent(int Key, int Action, float Delta);
	UFUNCTION()	void ConsoleOpened();																								//Function ConsoleOpened();

	UFUNCTION()	void PostBeginPlay();																										//simulated Function PostBeginPlay();
	UFUNCTION()	void HUDSetup(UCanvas* C);																									//simulated Function HUDSetup(Canvas Canvas);
	UFUNCTION()	void PlayStartupMessage(uint8 Stage);																						//simulated Function PlayStartupMessage(byte Stage);
	UFUNCTION()	void GetConsoleMessageOffsetX(UCanvas* C);																					//Function GetConsoleMessageOffsetX(Canvas Canvas);
	UFUNCTION()	void  DisplayMOTD();																										//simulated Function DisplayMOTD();
	UFUNCTION()	void DrawHUD(UCanvas* C);																									//simulated Function DrawHUD(Canvas Canvas);
	UFUNCTION()	int32 GetMessagePromptPosition();																							//simulated Function GetMessagePromptPosition();
	UFUNCTION()	int32 GetMessagePosition();																									//simulated Function GetMessagePosition();
	//UFUNCTION()	void LocalizedMessage(class<LocalMessage>  Message, int32 Switch, PlayerReplicationInfo RelatedPRI_1, PlayerReplicationInfo RelatedPRI_2, Object OptionalObject, FString CriticalString);		//simulated Function LocalizedMessage(class<LocalMessage>  Message, optional int Switch, optional PlayerReplicationInfo RelatedPRI_1, optional PlayerReplicationInfo RelatedPRI_2, optional Object OptionalObject, optional string CriticalString);
	UFUNCTION()	void DrawTypingPrompt(UCanvas* C, FString Text, int32 pos);																	//simulated Function DrawTypingPrompt(Canvas Canvas, string Text, optional int pos);
	UFUNCTION()	float GetTextHeight(UCanvas* C);																							//Function GetTextHeight(Canvas Canvas);
	UFUNCTION()	float GetTextWidth(UCanvas* C);																								//Function GetTextWidth(Canvas Canvas);
	UFUNCTION()	void ReWrapMessages(UConsole* MyConsole, UCanvas* MyCanvas);																//Function ReWrapMessages(Console MyConsole, Canvas MyCanvas);
	UFUNCTION()	void DisplayMessages(UCanvas* C);																							//simulated Function DisplayMessages(Canvas Canvas);
	UFUNCTION()	void SetCrosshair(int32 C);																									//Function SetCrosshair(int C);
	UFUNCTION()	void NextCrosshair();																										//Function NextCrosshair();
	UFUNCTION()	void SetHue(uint8 H);																										//Function SetHue(byte H);
	UFUNCTION()	void SetAlpha(uint8 A);																										//Function SetAlpha(byte A);
	UFUNCTION()	void DrawPMessage(UCanvas* C);																								//Function DrawPMessage(Canvas Canvas);
	UFUNCTION()	void DrawCenteredMessages(UCanvas* C);																						//Function DrawCenteredMessages(Canvas Canvas);
	UFUNCTION()	void DrawCenteredLongMessage(UCanvas* C);																					//Function DrawCenteredLongMessage(Canvas Canvas);
	UFUNCTION()	void DisplayCenteredMessage(float Time, FString Message, FString message2);													//Event DisplayCenteredMessage(float Time, string Message, optional string message2);
	UFUNCTION()	void DisplayCenteredMessageLong(float Time, FString in_message);														//Function DisplayCenteredMessageLong(float Time, string in_message, optional Font F);
	UFUNCTION()	void DrawArmyBox(UCanvas* C, float StartX, float StartY, float boxw, float boxh);											//Function DrawArmyBox(Canvas Canvas, float StartX, float StartY, float boxw, float boxh);
	UFUNCTION()	void DrawArmyLine(UCanvas* C, float StartX, float StartY, float boxw);														//Function DrawArmyLine(Canvas Canvas, float StartX, float StartY, float boxw);
	UFUNCTION()	void ToggleClassSelect();																									//Function ToggleClassSelect();
	UFUNCTION()	void ToggleTeamSelect();																									//Function ToggleTeamSelect();
	UFUNCTION()	void ToggleServerAdmin();																									//Function ToggleServerAdmin();
	UFUNCTION()	void OpenTeamSelect();																										//Function OpenTeamSelect();
	UFUNCTION()	void OpenClassSelect();																										//Function OpenClassSelect();
	UFUNCTION()	void ToggleLogin();																											//Function ToggleLogin();
	UFUNCTION()	void SetLoginStatus(int32 iStatus, FString sStatus, FString sNavMsg);														//Function SetLoginStatus(int iStatus, string sStatus, string sNavMsg);
	UFUNCTION()	void OnSetLoginStatus(int32 iStatus, FString sStatus, FString sNavMsg);														//Delegate OnSetLoginStatus(int iStatus, string sStatus, string sNavMsg);
	UFUNCTION()	void OpenMissionSuccess(FString Texture, FString Text, FString text2, int32 USize, int32 VSize, int32 RenderStyle, FName replayscene, bool bCheater);		//Function OpenMissionSuccess(string Texture, string Text, string text2, int USize, int VSize, int RenderStyle, name replayscene, bool bCheater);
	UFUNCTION()	void OpenMissionFailure(FString Texture, FString Text, FString text2, int32 USize, int32 VSize, int32 RenderStyle, FName replayscene);						//Function OpenMissionFailure(string Texture, string Text, string text2, int USize, int VSize, int RenderStyle, name replayscene);
	UFUNCTION()	void OpenLandNavScore(FString text1, FString text2, FString text3, FString text4, FString text5, FString text6, FString text7, FString text8, bool bCheater);		//Function OpenLandNavScore(string text1, string text2, string text3, string text4, string text5, string text6, string text7, string text8, bool bCheater);
	UFUNCTION()	void RefreshTourMissionDisplays();																							//Function RefreshTourMissionDisplays();
	UFUNCTION()	void GameSpyTest();																											//Function GameSpyTest();
	UFUNCTION()	int32 GetServerBrowserAsInt();																								//Function GetServerBrowserAsInt();
	UFUNCTION()	void GetCurrentServerBrowser(bool IsLAN);																					//Function GetCurrentServerBrowser(optional bool IsLAN);
	UFUNCTION()	void ServerBrowserUpdateList();																								//Function ServerBrowserUpdateList();
	UFUNCTION()	void ServerBrowserRefreshList();																							//Function ServerBrowserRefreshList();
	UFUNCTION()	void ConnectToGameSpyServer(int32 Index, FString sPassword, bool bSpectatorOnly);											//Function ConnectToGameSpyServer(int Index, optional string sPassword, optional bool bSpectatorOnly);
	UFUNCTION()	void ConnectToServer(int32 Index, FString sPassword, bool bSpectatorOnly);													//Function ConnectToServer(int Index, optional string sPassword, optional bool bSpectatorOnly);
	UFUNCTION()	void SortServers(FString sField, bool bAscending, EGameSpyCompareMode eType);												//Function SortServers(string sField, bool bAscending, ServerBrowserBase.EGameSpyCompareMode eType);
	UFUNCTION()	void RefreshSelectedServer(int32 Index);																					//Function RefreshSelectedServer(int Index);
	UFUNCTION()	void SetServerBrowserFilter(FString sFilter);																				//Function SetServerBrowserFilter(string sFilter);
	UFUNCTION()	void QueryServerListReply(int32 Index, FString Section, FString Setting, FString Value, int32 Type);						//Function QueryServerListReply(int Index, string Section, string Setting, string Value, int Type);
	UFUNCTION()	void SetServerSettingReply(int32 Index, FString Value);																		//Function SetServerSettingReply(int Index, string Value);
	UFUNCTION()	bool GetAutoSort();																											//Function GetAutoSort();
	UFUNCTION()	void SetHUDColor(FColor NewColor);																							//Function SetHUDColor(Object.Color NewColor);
	UFUNCTION()	void ShowCoords();																											//Function ShowCoords();
	UFUNCTION()	void ToggleBRoll();																											//Function ToggleBRoll();
	UFUNCTION()	void DisplayVoiceGain(UCanvas* C);																							//Function DisplayVoiceGain(Canvas C);


	//From AA2 HUD
	UFUNCTION()	void BuildMOTD();																							//Function DisplayVoiceGain(Canvas C);

//Exists in HUD																																	

//	UFUNCTION()	void ShowHud();
//	UFUNCTION()	void HideHUD();
//	UFUNCTION()	void ShowDebug();																											//Function ShowDebug()


private:
	/** Crosshair asset pointer */
	UTexture2D* CrosshairTex;


	
};
