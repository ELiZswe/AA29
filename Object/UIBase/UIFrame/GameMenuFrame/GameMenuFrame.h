// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/UIBase/UIFrame/UIFrame.h"
#include "GameMenuFrame.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UGameMenuFrame : public UUIFrame
{
	GENERATED_BODY()
public:
	UGameMenuFrame();

	/*
	const UIE_None = 0;
	const UIE_MainMenu = 1;
	const UIE_TeamSelect = 2;
	const UIE_TeamBrief = 3;
	const UIE_ClassSelect = 4;
	const UIE_ExitMenu = 5;
	const UIE_ClassRifleman = 10;
	const UIE_ClassGrenadier = 11;
	const UIE_ClassSniper = 12;
	const UIE_ClassSniper24 = 13;
	const UIE_ClassAutoRifleman = 14;
	const UIE_LeaderSquad = 15;
	const UIE_LeaderFT = 16;
	const UIE_ClassRandom = 17;
	const UIE_SelectClass = 18;
	const UIE_SelectTeam0 = 20;
	const UIE_SelectTeam1 = 21;
	const UIE_SelectTeam = 22;
	const UIE_SpectateTeam0 = 23;
	const UIE_SpectateTeam1 = 24;
	const UIE_CancelLogin = 30;
	const UIE_SelectLogin = 31;
	const UIE_MissionSuccessContinue = 42;
	const UIE_ContinueMissionsButton = 43;
	const UIE_UpdateServerSetting = 50;
	const UIE_KickPlayer = 51;
	const UIE_BanPlayer = 52;
	const UIE_PlayerListPrev = 53;
	const UIE_PlayerListNext = 54;
	const UIE_SettingListPrev = 55;
	const UIE_SettingListNext = 56;
	const UIE_MissionEndMenu = 60;
	const UIE_MissionEndReplay = 61;
	const UIE_LandNavContinue = 62;
	const SID_Main = 0;
	const SID_TeamSelect = 1;
	const SID_TeamBrief = 2;
	const SID_ClassSelect = 3;
	const SID_Login = 4;
	const SID_MissionSuccess = 5;
	const SID_MissionFailure = 6;
	const SID_ServerAdmin = 7;
	const SID_LandNavScore = 8;
	const ID_None = 0;
	const ID_Training = 1;
	const ID_MPMain = 2;
	const ID_QuickMP = 3;
	const ID_Settings = 4;
	const ID_Credits = 5;
	const ID_Quit = 6;
	const ID_ClassRifleman = 10;
	const ID_ClassGrenadier = 11;
	const ID_ClassSniper = 12;
	const ID_ClassSniper24 = 13;
	const ID_ClassAutoRifleman = 14;
	const ID_LeaderSquad = 15;
	const ID_LeaderFT = 16;
	const ID_ClassRandom = 17;
	const ID_TeamLeader = 18;
	const ID_Medic = 19;
	const ID_TeamName = 20;
	const ID_TeamBrief = 21;
	const ID_Team0Brief = 22;
	const ID_Team1Brief = 23;
	const ID_Login = 30;
	const ID_Password = 31;
	const ID_Status = 32;
	const ID_NavMsg = 33;
	const ID_LoginButton = 34;
	const ID_ContinueMissionsButton = 35;
	const ID_DynamicBitmap = 40;
	const ID_TextString1 = 41;
	const ID_MenuButton = 42;
	const ID_ReplayButton = 43;
	const ID_ContinueButton = 44;
	const ID_TextString2 = 45;
	const ID_TextString3 = 46;
	const ID_TextString4 = 47;
	const ID_PlayerList = 50;
	const ID_SettingsList = 51;
	const ID_SettingsCheckbox = 52;
	const ID_SettingsEditbox = 53;
	const ID_LNTextString01 = 1001;
	const ID_LNTextString02 = 1002;
	const ID_LNTextString03 = 1003;
	const ID_LNTextString04 = 1004;
	const ID_LNTextString05 = 1005;
	const ID_LNTextString06 = 1006;
	const ID_LNTextString07 = 1007;
	const ID_LNTextString08 = 1008;
	const ID_LNTextString09 = 1009;
	const ID_LNTextString10 = 1010;
	const kNumSettingsPages = 4;
	*/

	UPROPERTY()										bool _bSettingsListSet;					//var bool _bSettingsListSet;
	UPROPERTY()										int32 _iSettingsPage;					//var int _iSettingsPage;
	UPROPERTY()										FString nReplayScene;					//var string nReplayScene;
	UPROPERTY()										int32 _iLoginStatus;					//var int _iLoginStatus;
	UPROPERTY()										FString _sBriefingsDir;					//var string _sBriefingsDir;
	UPROPERTY()										bool prev_AvoidLeader;					//var bool prev_AvoidLeader;
	UPROPERTY()										int32 prev_SelectedClass;				//var int prev_SelectedClass;
	UPROPERTY()										int32 _iSelectedClass;					//var int _iSelectedClass;
	UPROPERTY()										int32 _iSelectedTeam;					//var int _iSelectedTeam;
	UPROPERTY()										FString _sTeam;							//var string _sTeam;
	UPROPERTY()										int32 iMsgBoxYesOverride;				//var int iMsgBoxYesOverride;
	UPROPERTY()										FPosition dMoreButton;					//var UIBase.Position dMoreButton;
	UPROPERTY()										FPosition dLogInButton;					//var UIBase.Position dLogInButton;
	UPROPERTY()										FPosition dContinueButton;				//var UIBase.Position dContinueButton;
	UPROPERTY()										FPosition dReplayButton;				//var UIBase.Position dReplayButton;
	UPROPERTY()										FPosition dMenuButton;					//var UIBase.Position dMenuButton;
	UPROPERTY()										FPosition dBackButton;					//var UIBase.Position dBackButton;
	UPROPERTY()										FPosition dNextButton;					//var UIBase.Position dNextButton;
	UPROPERTY()										FPosition dSelectButton;				//var UIBase.Position dSelectButton;
	UPROPERTY()										FPosition dCancelButton;				//var UIBase.Position dCancelButton;
	UPROPERTY()										FPosition dCheckBox;					//var UIBase.Position dCheckBox;

	void Notify(int32 pUIEvent);
	void SetActiveScreen(int32 screen_id);
	void SelectClass(int32 control_id);
	void DoSelectClass();
	void RefreshClassSelect();
	void EnableMedicPreference(int32 ndesired, int32 navail);
	void EnableLeaderPreference(int32 ndesired, int32 navail);
	void EnableClassSelect(bool bState, bool bQual, uint8 yalt, FString Label, int32 control_id);
	void SelectTeam(int32 Team);
	void DoSelectTeam();
	void DoSpectateTeam(int32 Team);
	void CheckFullScreen();
	void Draw(UCanvas* Canvas);
	void Create(AHUD* pHUD);
	void InitTextureDimensions();
	void CreateScreens();
	void CreateMainMenuScreen();
	void CreateClassSelectScreen();
	void CreateTeamSelectScreen();
	void CreateTeamBriefScreen();
	void CreateLoginScreen();
	void CreateMissionSuccessScreen();
	void CreateMissionFailureScreen();
	void CreateLandNavScoreScreen();
	void CreateServerAdminScreen();
	void RefreshLoginScreen();
	void CancelLogin();
	void SelectLogin();
	void SetLoginStatus(int32 iStatus, FString sStatus, FString sNavMsg);
	void SetMissionSuccessScreen(FString Texture, FString Text, FString text2, int32 USize, int32 VSize, int32 RenderStyle, FName replayscene, bool bCheater);
	void SetMissionFailureScreen(FString Texture, FString Text, FString text2, int32 USize, int32 VSize, int32 RenderStyle, FName replayscene);
	void SetLandNavScoreScreen(FString text1, FString text2, FString text3, FString text4, FString text5, FString text6, FString text7, FString text8, bool bCheater);
	void ScaleControls(UCanvas* Canvas);
	void PlayMenuSoundSpecific(USoundBase* Sound);
	void QueryServerListReply(int32 Index, FString Section, FString Setting, FString Value, int32 Type);
	void SetServerSettingReply(int32 Index, FString Value);
	void SetSettingsValue(FString Value);
	void UpdateServerSetting();
	void BanPlayer();
	void KickPlayer();
	void PlayerList(int32 Direction);
	void SettingList(int32 Direction);


};
