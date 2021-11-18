// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AASoldierSubPanel/AAPersonnelJacketSubPanel.h"
#include "AAPersonnelJacket_Profile.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UAAPersonnelJacket_Profile : public UAAPersonnelJacketSubPanel
{
	GENERATED_BODY()
public:
	UAAPersonnelJacket_Profile();

	UPROPERTY(EditAnywhere)			UGUIImage*		i_BG1;						//var() automated XInterface.GUIImage i_BG1;
	UPROPERTY(EditAnywhere)			UGUIImage*		i_BG2;						//var() automated XInterface.GUIImage i_BG2;
	UPROPERTY(EditAnywhere)			UGUIImage*		i_BG3;						//var() automated XInterface.GUIImage i_BG3;
	UPROPERTY(EditAnywhere)			UGUIImage*		i_SoldierBK;				//var() automated XInterface.GUIImage i_SoldierBK;
	UPROPERTY(EditAnywhere)			UGUIButton*		b_CreateAccount;			//var() automated XInterface.GUIButton b_CreateAccount;
	UPROPERTY(EditAnywhere)			UGUIButton*		b_Load;						//var() automated XInterface.GUIButton b_Load;
	UPROPERTY(EditAnywhere)			UGUIButton*		b_Delete;					//var() automated XInterface.GUIButton b_Delete;
	UPROPERTY(EditAnywhere)			UmoEditBox*		ed_Username;				//var() automated XInterface.moEditBox ed_Username;
	UPROPERTY(EditAnywhere)			UmoEditBox*		ed_Password;				//var() automated XInterface.moEditBox ed_Password;
	UPROPERTY(EditAnywhere)			UmoCheckBox*	ch_RememberUser;			//var() automated XInterface.moCheckBox ch_RememberUser;
	UPROPERTY(EditAnywhere)			UmoCheckBox*	ch_AutoLoad;				//var() automated XInterface.moCheckBox ch_AutoLoad;
	UPROPERTY(EditAnywhere)			UGUILabel*		l_Status;					//var() automated XInterface.GUILabel l_Status;
	UPROPERTY(EditAnywhere)			UGUILabel*		l_UserName;					//var() automated XInterface.GUILabel l_UserName;
	UPROPERTY(EditAnywhere)			UGUILabel*		l_Password;					//var() automated XInterface.GUILabel l_Password;
	UPROPERTY(EditAnywhere)			UGUILabel*		l_Honor;					//var() automated XInterface.GUILabel l_Honor;
	UPROPERTY(EditAnywhere)			UGUILabel*		l_Experience;				//var() automated XInterface.GUILabel l_Experience;
	UPROPERTY(EditAnywhere)			UGUILabel*		l_ExperienceNeeded;			//var() automated XInterface.GUILabel l_ExperienceNeeded;
	UPROPERTY(EditAnywhere)			UGUILabel*		l_News1;					//var() automated XInterface.GUILabel l_News1;
	UPROPERTY(EditAnywhere)			UGUILabel*		l_News2;					//var() automated XInterface.GUILabel l_News2;
	UPROPERTY(EditAnywhere)			UGUILabel*		l_News3;					//var() automated XInterface.GUILabel l_News3;
	UPROPERTY(EditAnywhere)			UGUILabel*		l_News4;					//var() automated XInterface.GUILabel l_News4;
	UPROPERTY(EditAnywhere)			UGUILabel*		l_PlayerAccountStatus;		//var() automated XInterface.GUILabel l_PlayerAccountStatus;
	UPROPERTY(EditAnywhere)			UGUILabel*		l_PlayerLogin;				//var() automated XInterface.GUILabel l_PlayerLogin;
	UPROPERTY(EditAnywhere)			UGUILabel*		l_NewPlayer;				//var() automated XInterface.GUILabel l_NewPlayer;
	//UPROPERTY(EditAnywhere)			ASpinnySoldier* SpinnyCharacter;			//var() editconst noexport SpinnySoldier SpinnyCharacter;
	UPROPERTY(EditAnywhere)			FVector			SpinnyCharacterOffset;		//var() Vector SpinnyCharacterOffset;
	UPROPERTY(EditAnywhere)			bool			bRenderCharacter;			//var() bool bRenderCharacter;
	UPROPERTY(EditAnywhere)			bool			bSaveProfile;				//var() noexport bool bSaveProfile;
	UPROPERTY(EditAnywhere)			bool			bAutoLoad;					//var() noexport bool bAutoLoad;
	UPROPERTY()						FString			DeleteProfile;				//var localized FString DeleteProfile;
	UPROPERTY()						FString			ConnectionText;				//var localized FString ConnectionText;
	UPROPERTY()						int32			_iLoginStatus;				//var int32 _iLoginStatus;
	UPROPERTY(EditAnywhere)			int32			nfov;						//var() int32 nfov;
	UPROPERTY(EditAnywhere)			int32			YawValue;					//var() int32 YawValue;

	void VoiceTypeChanged(FString NewVoiceType);
	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void InternalOnLoadINI(UGUIComponent* Sender, FString S);
	void InternalOnChange(UGUIComponent* Sender);
	void UpdateProfileList();
	bool ButtonClick(UGUIComponent* Sender);
	bool LoadClick(UGUIComponent* Sender);
	bool DeleteClick(UGUIComponent* Sender);
	void InternalSetLoginStatus(int32 iStatus, FString sStatus, FString sNavMsg);
	void ClearAll();
	void ClearProfile();
	void ClearNews();
	void Refresh();
	void SaveSettings();
	void UpdateSpinnyCharacter();
	void InternalDraw(UCanvas* Canvas);
	void ShowSpinnyCharacter();
	bool Toggle3DView(UGUIComponent* Sender);
	bool NextAnim(UGUIComponent* Sender);
	bool RaceCapturedMouseMove(float deltaX, float deltaY);
	void IntializeCharacter();
	void ShowPanel(bool bShow);
	void Opened(UGUIComponent* Sender);
	void Closed(UGUIComponent* Sender, bool bCancelled);
	void Free();
	void logspinnycharacter();

};
