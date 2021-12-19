// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/HUD/AA2_HUD.h"
#include "AA29/MyEnums.h"
#include "Engine/Canvas.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "AGP_HUD.generated.h"

class ULocalMessage;
class AServerBrowserBase;
class UUIControl;
class UScriptObject;
class UGameMenuFrame;
class UMissionResultsFrame;
class UHUDFrame;
class AClientBeaconReceiver;
class AGameSpyServerList;
class UI3DL2Listener;
class AServerBrowserSCI;
class AServerBrowserDBMBS;

UCLASS()
class AA29_API AAGP_HUD : public AAA2_HUD
{
	GENERATED_BODY()

public:
	AAGP_HUD(const FObjectInitializer& ObjectInitializer);

public:

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
	UPROPERTY()													UGameMenuFrame* gmFrame;					//var GameMenuFrame gmFrame;
	UPROPERTY()													UGameMenuFrame* mmFrame;					//var MainMenuFrame mmFrame;
	UPROPERTY()													UMissionResultsFrame* mrFrame;				//var MissionResultsFrame mrFrame;		
	UPROPERTY()													UHUDFrame* _cHUDFrame;						//var HUDFrame _cHUDFrame;
	UPROPERTY()													bool bShowCoords;							//var bool bShowCoords;
	UPROPERTY()													float fSpectateTextOffset;					//var float fSpectateTextOffset;
	UPROPERTY()													UScriptObject* _MissionResultTarget;		//var ScriptObject _MissionResultTarget;			// mission result target
		
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

	UPROPERTY()													AClientBeaconReceiver* ClientBeacon;		//var IpDrv.ClientBeaconReceiver ClientBeacon;
	UPROPERTY()													AGameSpyServerList* BrowserGSPY;			//var IpDrv.GameSpyServerList BrowserGSPY;
	UPROPERTY()													AServerBrowserSCI* BrowserSCI;				//var IpDrv.ServerBrowserSCI BrowserSCI;
	UPROPERTY()													AServerBrowserDBMBS* BrowserDBMBS;			//var DBAuth.ServerBrowserDBMBS BrowserDBMBS;
	UPROPERTY()													UI3DL2Listener* SavedZoneEffect;			//var I3DL2Listener SavedZoneEffect;				// store zone effect while in menu

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

	//From AA2 HUD.uc
	UPROPERTY()													UFont* UE4Font;
	UPROPERTY()													float DefaultFontScale;

	void DetermineVersionLabel(bool bCheat, bool bDev, bool bBeta, bool bLeased, bool bOfficial, bool bNATO, bool bTournament, bool bUltimateArena, bool bIsAuthorized, bool bExploreTheArmyServer, bool bAllowForceclassing);
	int32 GetVersionAGPMajor();
	int32 GetVersionAGPMinor();
	int32 GetVersionAGPTiny();
	int32 GetVersionAGPSubTiny();
	bool AllowFade();
	void GetMouseX();
	void GetMouseY();
	void UpdatePrecacheMaterials();
	void PrecacheFonts(UCanvas* C);
	void UseSmallFont(UCanvas* C);
	void TournamentNotifyNewTeamCaptain();
	void TournamentNotifyOtherTeamReady();
	void TournamentNotifyNewTeamName();																					//Function TournamentNotifyNewTeamName();
	void TournamentNotifyNewWeaponClassLockState();																		//Function TournamentNotifyNewWeaponClassLockState();
	void TournamentNotifyMyTeamReady();																					//Function TournamentNotifyMyTeamReady();
	void SetHUDActor();																									//Function SetHUDActor();
	void FreeHUDActor();																								//Function FreeHUDActor();
	UUIControl* GetHUDControl(int32 Id);																						//Function GetHUDControl(int Id);
	UObject* CreateUIObject(FString ObjectName);																			//static Function CreateUIObject(string ObjectName);
	void Destroyed();																									//Function Destroyed();

	void PostRender_Stage2(UCanvas* C);																					//Event PostRender_Stage2(Canvas Canvas);
	void DrawConsole(UCanvas* C);																						//Function DrawConsole(Canvas Canvas);
	void PostRender_Stage1(UCanvas* C);																					//Event PostRender_Stage1(Canvas Canvas);
	void PostRender_Stage2_DrawConsole(UCanvas* C);																		//simulated Function PostRender_Stage2_DrawConsole(Canvas Canvas);
	void DrawMenu(UCanvas* C);																							//simulated Function DrawMenu(Canvas Canvas);
	void DrawAngleEditor(UCanvas* C);																					//Function DrawAngleEditor(Canvas Canvas);

	void WorldSpaceOverlays();																							//simulated Event WorldSpaceOverlays();
	void SetMissionResultTarget(UScriptObject* so);																	//Function SetMissionResultTarget(ScriptObject so);
	void CreateFrame();																									//Function CreateFrame();
	void FillListBox();																									//Function FillListBox();
	bool FrameOverride();																								//Function FrameOverride();
	void DisablePlayer();																								//Function DisablePlayer();
	void EnablePlayer();																								//Function EnablePlayer();
	void SetConsoleWidth(FString sNewWidthPercent);																		//Function SetConsoleWidth(string sNewWidthPercent);
	void OLD_ShowScores();																								//Function OLD_ShowScores();
	void ShowScores();																									//Function ShowScores();
	void OpenGameMenu();																								//Function OpenGameMenu();
	void CloseGameMenu();																								//Function CloseGameMenu();
	void ToggleAGPGameMenu();																							//Function ToggleAGPGameMenu();
	void ToggleAGPMainMenu();																							//Function ToggleAGPMainMenu();
	void CloseAllMenus();																								//Function CloseAllMenus();
	void  OpenMainMenu();																								//Function OpenMainMenu();
	void CloseMainMenu();																								//Function CloseMainMenu();
	void OpenMissionResults();																							//Function OpenMissionResults();
	void CloseMissionResults();																							//Function CloseMissionResults();
	void OpenMap(FString sMap);																							//Function OpenMap(string sMap);
	void SpawnItem(FString Item);																						//Function SpawnItem(string Item);
	bool KeyType(int32 Key);																							//Function KeyType(int Key);
	bool ProcessKeyEvent(int32 Key, int32 Action, float Delta);															//Function ProcessKeyEvent(int Key, int Action, float Delta);
	void ConsoleOpened();																								//Function ConsoleOpened();

	void PostBeginPlay();																										//simulated Function PostBeginPlay();
	void HUDSetup(UCanvas* C);																									//simulated Function HUDSetup(Canvas Canvas);
	void PlayStartupMessage(uint8 Stage);																						//simulated Function PlayStartupMessage(byte Stage);
	float GetConsoleMessageOffsetX(UCanvas* C);																					//Function GetConsoleMessageOffsetX(Canvas Canvas);
	void DisplayMOTD();
	void DrawHUD();
	int32 GetMessagePromptPosition();
	int32 GetMessagePosition();
	void LocalizedMessage(ULocalMessage* Message, int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2, UObject* OptionalObject, FString CriticalString);
	void DrawTypingPrompt(UCanvas* C, FString Text, int32 pos);
	float GetTextHeight(UCanvas* C);
	float GetTextWidth(UCanvas* C);
	void ReWrapMessages(UConsole* MyConsole, UCanvas* MyCanvas);
	void DisplayMessages(UCanvas* C);
	void SetCrosshair(int32 C);
	void NextCrosshair();
	void SetHue(uint8 H);
	void SetAlpha(uint8 A);
	bool DrawPMessage(UCanvas* C);
	void DrawCenteredMessages(UCanvas* C);
	void DrawCenteredLongMessage(UCanvas* C);
	void DisplayCenteredMessage(float Time, FString Message, FString message2);
	void DisplayCenteredMessageLong(float Time, FString in_message);
	void DrawArmyBox(UCanvas* C, float StartX, float StartY, float boxw, float boxh);
	void DrawArmyLine(UCanvas* C, float StartX, float StartY, float boxw);
	void ToggleClassSelect();
	void ToggleTeamSelect();
	void ToggleServerAdmin();
	void OpenTeamSelect();
	void OpenClassSelect();
	void ToggleLogin();
	void SetLoginStatus(int32 iStatus, FString sStatus, FString sNavMsg);
	void OnSetLoginStatus(int32 iStatus, FString sStatus, FString sNavMsg);
	void OpenMissionSuccess(FString Texture, FString Text, FString text2, int32 USize, int32 VSize, int32 RenderStyle, FName replayscene, bool bCheater);
	void OpenMissionFailure(FString Texture, FString Text, FString text2, int32 USize, int32 VSize, int32 RenderStyle, FName replayscene);
	void OpenLandNavScore(FString text1, FString text2, FString text3, FString text4, FString text5, FString text6, FString text7, FString text8, bool bCheater);
	void RefreshTourMissionDisplays();
	void GameSpyTest();
	int32 GetServerBrowserAsInt();
	AServerBrowserBase* GetCurrentServerBrowser(bool IsLAN);
	void ServerBrowserUpdateList();
	void ServerBrowserRefreshList();
	void ConnectToGameSpyServer(int32 Index, FString sPassword, bool bSpectatorOnly);
	void ConnectToServer(int32 Index, FString sPassword, bool bSpectatorOnly);
	void SortServers(FString sField, bool bAscending, EGameSpyCompareMode eType);
	void RefreshSelectedServer(int32 Index);
	void SetServerBrowserFilter(FString sFilter);
	void QueryServerListReply(int32 Index, FString Section, FString Setting, FString Value, int32 Type);
	void SetServerSettingReply(int32 Index, FString Value);
	bool GetAutoSort();
	void SetHUDColor(FColor NewColor);
	void ShowCoords();
	void ToggleBRoll();
	void DisplayVoiceGain(UCanvas* C);


	//From AA2 HUD
	void BuildMOTD();

//Exists in HUD																																	

//	void ShowHud();
//	void HideHUD();
	
	void ShowDebug(FName DebugType = NAME_None);

private:
	/** Crosshair asset pointer */
	UTexture2D* CrosshairTex;

};
