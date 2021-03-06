// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/UIBase/UIFrame/UIFrame.h"
#include "MainMenuFrame.generated.h"

class UUISlider;
class UUICheckbox;
class UUICheckboxB;
class AAA2_HUD;
class AClientBeaconReceiver;
class AServerBrowserBase;

UCLASS()
class UMainMenuFrame : public UUIFrame
{
	GENERATED_BODY()
public:
	UMainMenuFrame();

	UPROPERTY()			bool				bMenuRestricted;		//var bool bMenuRestricted;
	UPROPERTY()			int32				_iLoginStatus;			//var int _iLoginStatus;
	UPROPERTY()			bool				bSortAscending;			//var bool bSortAscending;
	UPROPERTY()			int32				iSortField;				//var int iSortField;
	UPROPERTY()			float				_fGameSpyPos;			//var float _fGameSpyPos;
	UPROPERTY()			bool				_bNoTourText;			//var bool _bNoTourText;
	UPROPERTY()			FString				sBriefingsDir;			//var string sBriefingsDir;
	UPROPERTY()			int32				iDelayedFrame;			//var int iDelayedFrame;
	UPROPERTY()			int32				iDelayedEvent;			//var int iDelayedEvent;
	UPROPERTY()			bool				bMissionMP;				//var bool bMissionMP;
	UPROPERTY()			FString				sTeam1;					//var string sTeam1;
	UPROPERTY()			FString				sTeam0;					//var string sTeam0;
	UPROPERTY()			FString				sMission;				//var string sMission;
	UPROPERTY()			FString				sTour;					//var string sTour;
	UPROPERTY()			FString				sTourIni;				//var string sTourIni;
	UPROPERTY()			int32				iMsgBoxYesOverride;		//var int iMsgBoxYesOverride;
	UPROPERTY()			FPosition			dLogInButton;			//var UIBase.Position dLogInButton;
	UPROPERTY()			FPosition			dKeyMap;				//var UIBase.Position dKeyMap;
	UPROPERTY()			FPosition			dNextButton;			//var UIBase.Position dNextButton;
	UPROPERTY()			FPosition			dBackButton;			//var UIBase.Position dBackButton;
	UPROPERTY()			FPosition			dSliderThumb;			//var UIBase.Position dSliderThumb;
	UPROPERTY()			FPosition			dSliderBack;			//var UIBase.Position dSliderBack;
	UPROPERTY()			FPosition			dCheckBox;				//var UIBase.Position dCheckBox;
	UPROPERTY()			UMaterialInstance*	_tBackground;			//var Texture _tBackground;
	UPROPERTY()			int32				temp_id;				//var int temp_id;

	void Destroyed();
	void Notify(int32 pUIEvent);
	void DelayEvent(int32 iEvent);
	void MessageBox(FString szMessage, int32 acceptevent, FString acceptstring, FString cancelstring);
	void MessageBoxWorking();
	void MessageBoxLoading();
	void CloseMessageBox();
	void CheckFullScreen();
	void Draw(UCanvas* Canvas);
	void Create(AAA2_HUD* pHUD);
	void InitTextureDimensions();
	void CreateScreens();
	void CreateMainMenuScreens();
	void CreateGettingStartedScreen();
	void CreateTrainingScreens();
	void CreateMPMainScreens();
	void CreateParentalControlScreen();
	void RefreshParentalControlScreen();
	void ParentAccept();
	void CreateSettingsScreens();
	void CreateCreditsScreens(FString credits, int32 creditnum);
	void CreateMessageBox();
	void PlayMenuSoundSpecific(USoundBase* Sound);
	AServerBrowserBase* GetCurrentServerBrowser();
	AClientBeaconReceiver* GetClientBeacon();
	void RunConsoleCommand(FString comm);
	void SetDefaultKeyMaps();
	void SetDefaultCommKeys();
	void SetDefaultMovementKeys();
	void SetDefaultViewKeys();
	void RefreshViewSettings();
	void RefreshMovementSettings();
	void RefreshCombatSettings();
	void RefreshServerBrowser();
	void SetDefaultCombatKeys();
	void SetDefaultMiscKeys();
	void SetDefaultKey(int32 key0, int32 key1, int32 screen_id, int32 control_id);
	void InitKeyMap();
	void SetKeyMap(int32 screen_id, int32 control_id);
	void OpenQuickLan(FString serveraddr);
	void UnbindKey(int32 Key, FString Command);
	bool UnbindSpecificKey(int32 Key, FString Command, int32 screen_id, int32 control_id);
	void RefreshVideoSettings();
	void RefreshVideoAdvancedSettings();
	void RefreshVideoDecalsSettings();
	void RefreshAudioSettings();
	void RefreshHUDSettings();
	void RefreshWeaponModSettings();
	void RefreshCheckBox(int32 screen_id, int32 control_id);
	void RefreshCheckBoxB(int32 screen_id, int32 control_id);
	void RefreshCheckBoxFn(int32 screen_id, int32 control_id);
	void RefreshCheckBoxC(int32 screen_id, int32 control_id);
	void RefreshSliderSeg(int32 screen_id, int32 control_id);
	void SetCheckBox(int32 screen_id, int32 control_id, bool Status);
	void SetCheckBoxB(int32 screen_id, int32 control_id, bool Status);
	void SetCheckBoxFn(int32 screen_id, int32 control_id, bool Status);
	void SetCheckBoxC(int32 screen_id, int32 control_id, bool Status);
	void SetSliderSeg(int32 screen_id, int32 control_id, int32 Status);
	void AcceptCheckBox(int32 screen_id, int32 control_id);
	void AcceptCheckBoxB(int32 screen_id, int32 control_id);
	void AcceptCheckBoxC(int32 screen_id, int32 control_id);
	void AcceptSliderSeg(int32 screen_id, int32 control_id);
	void AcceptVideoSettings();
	void AcceptVideoAdvancedSettings();
	void AcceptVideoDecalsSettings();
	void AcceptAudioSettings();
	void ResetVideoDefault();
	void ResetVideoAdvancedDefault();
	void ResetVideoDecalsDefault();
	void ResetAudioDefault();
	void ResetHUDDefault();
	void RefreshSliders();
	void RefreshControlsMisc();
	void AcceptSkinTone();
	void RefreshSlider(int32 screen_id, int32 control_id);
	void SetSlider(int32 screen_id, int32 control_id, float Value);
	void AcceptSlider(int32 screen_id, int32 control_id);
	void RefreshLoginScreen();
	void UpdateLoginInfo();
	void SetResolution(int32 X, int32 Y);
	int32 GetDesiredX();
	int32 GetDesiredY();
	void RefreshToursDisplay();
	void RefreshTourMissionDisplays();
	void SetNoTourText(bool bNoTourText);
	void UpdateResumeGame();
	void SetSkinTone();
	void SetGameSpyPos(int32 pos);
	int32 GetGameSpyPos();
	void UpdateGameSpyPos(int32 pos);
	void ConnectToGameSpyServer(int32 Index);
	void JoinSelectedServer();
	void ServerBrowserSort(int32 Index);
	void SetServerBrowserFilter(FString sFilter);
	void RefreshSelectedServer();
	void SelectLogin();
	void SetLoginStatus(int32 iStatus, FString sStatus, FString sNavMsg);
	void NavigatePlayerList(int32 Direction);
	void SetNewsLine(int32 Index, FString Text);
	FString GetServerPassword();
};
