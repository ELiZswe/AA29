// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/UIBase/UIFrame/UIFrame.h"
#include "GameMenuFrame.generated.h"

class UUICheckboxB;
class AAA2_HUD;

UCLASS()
class UGameMenuFrame : public UUIFrame
{
	GENERATED_BODY()
public:
	UGameMenuFrame();

	UPROPERTY()				bool			_bSettingsListSet;			//var bool _bSettingsListSet;
	UPROPERTY()				int32			_iSettingsPage;				//var int _iSettingsPage;
	UPROPERTY()				FString			nReplayScene;				//var string nReplayScene;
	UPROPERTY()				int32			_iLoginStatus;				//var int _iLoginStatus;
	UPROPERTY()				FString			_sBriefingsDir;				//var string _sBriefingsDir;
	UPROPERTY()				bool			prev_AvoidLeader;			//var bool prev_AvoidLeader;
	UPROPERTY()				int32			prev_SelectedClass;			//var int prev_SelectedClass;
	UPROPERTY()				int32			_iSelectedClass;			//var int _iSelectedClass;
	UPROPERTY()				int32			_iSelectedTeam;				//var int _iSelectedTeam;
	UPROPERTY()				TArray<FString>	_sTeam;						//var string _sTeam;
	UPROPERTY()				int32			iMsgBoxYesOverride;			//var int iMsgBoxYesOverride;
	UPROPERTY()				FPosition		dMoreButton;				//var UIBase.Position dMoreButton;
	UPROPERTY()				FPosition		dLogInButton;				//var UIBase.Position dLogInButton;
	UPROPERTY()				FPosition		dContinueButton;			//var UIBase.Position dContinueButton;
	UPROPERTY()				FPosition		dReplayButton;				//var UIBase.Position dReplayButton;
	UPROPERTY()				FPosition		dMenuButton;				//var UIBase.Position dMenuButton;
	UPROPERTY()				FPosition		dBackButton;				//var UIBase.Position dBackButton;
	UPROPERTY()				FPosition		dNextButton;				//var UIBase.Position dNextButton;
	UPROPERTY()				FPosition		dSelectButton;				//var UIBase.Position dSelectButton;
	UPROPERTY()				FPosition		dCancelButton;				//var UIBase.Position dCancelButton;
	UPROPERTY()				FPosition		dCheckBox;					//var UIBase.Position dCheckBox;

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
	void Create(AAA2_HUD* pHUD);
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
