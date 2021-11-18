// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/AALoginPage/AALoginPage.h"
#include "AAPreLoginPage.generated.h"

class UGUIButton;
class UmoCheckBox;
class UGUILabel;
class UmoEditBox;

UCLASS()
class AA29_API UAAPreLoginPage : public UAALoginPage
{
	GENERATED_BODY()
public:
	UAAPreLoginPage();

	UPROPERTY(EditAnywhere)		UGUIButton*		b_LogIn;							//var() automated XInterface.GUIButton b_LogIn;
	UPROPERTY(EditAnywhere)		UGUIButton*		b_Explore;							//var() automated XInterface.GUIButton b_Explore;
	UPROPERTY(EditAnywhere)		UGUIButton*		b_Support;							//var() automated XInterface.GUIButton b_Support;
	UPROPERTY(EditAnywhere)		UGUIButton*		b_NewAccount;						//var() automated XInterface.GUIButton b_NewAccount;
	UPROPERTY(EditAnywhere)		UGUIButton*		btnLANPlay;							//var() automated XInterface.GUIButton btnLANPlay;
	UPROPERTY(EditAnywhere)		UmoCheckBox*	ch_RememberUser;					//var() automated XInterface.moCheckBox ch_RememberUser;
	UPROPERTY(EditAnywhere)		UmoCheckBox*	ch_AutoLoad;						//var() automated XInterface.moCheckBox ch_AutoLoad;
	UPROPERTY(EditAnywhere)		UGUILabel*		l_Status;							//var() automated XInterface.GUILabel l_Status;
	UPROPERTY(EditAnywhere)		UGUILabel*		l_AuthMessage;						//var() automated XInterface.GUILabel l_AuthMessage;
	UPROPERTY(EditAnywhere)		UGUILabel*		l_Login;							//var() automated XInterface.GUILabel l_Login;
	UPROPERTY(EditAnywhere)		UGUILabel*		l_Options;							//var() automated XInterface.GUILabel l_Options;
	UPROPERTY(EditAnywhere)		UGUILabel*		l_OptionExplore;					//var() automated XInterface.GUILabel l_OptionExplore;
	UPROPERTY(EditAnywhere)		UGUILabel*		l_OptionExploreDescription;			//var() automated XInterface.GUILabel l_OptionExploreDescription;
	UPROPERTY(EditAnywhere)		UGUILabel*		l_OptionSupport;					//var() automated XInterface.GUILabel l_OptionSupport;
	UPROPERTY(EditAnywhere)		UGUILabel*		l_OptionSupportDescription;			//var() automated XInterface.GUILabel l_OptionSupportDescription;
	UPROPERTY(EditAnywhere)		UGUILabel*		l_OptionNewAccount;					//var() automated XInterface.GUILabel l_OptionNewAccount;
	UPROPERTY(EditAnywhere)		UGUILabel*		l_OptionNewAccountDescription;		//var() automated XInterface.GUILabel l_OptionNewAccountDescription;
	UPROPERTY(EditAnywhere)		UmoEditBox*		ed_Username;						//var() automated XInterface.moEditBox ed_Username;
	UPROPERTY(EditAnywhere)		UmoEditBox*		ed_Password;						//var() automated XInterface.moEditBox ed_Password;
	UPROPERTY(EditAnywhere)		bool			bSaveProfile;						//var() noexport bool bSaveProfile;
	UPROPERTY(EditAnywhere)		bool			bAutoLoad;							//var() noexport bool bAutoLoad;
	UPROPERTY()					FString			sStatus;							//var localized FString sStatus;
	UPROPERTY()					FString			sAuthMessage;						//var localized FString sAuthMessage;
	UPROPERTY()					FString			sReady;								//var localized FString sReady;
	UPROPERTY()					FString			sError;								//var localized FString sError;
	UPROPERTY()					FString			sUserName;							//var localized FString sUserName;
	UPROPERTY()					FString			sUserNameDescription;				//var localized FString sUserNameDescription;
	UPROPERTY()					FString			sPassword;							//var localized FString sPassword;
	UPROPERTY()					FString			sPasswordDescription;				//var localized FString sPasswordDescription;
	UPROPERTY()					int32			_iLoginStatus;						//var int32 _iLoginStatus;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void Opened(UGUIComponent* Sender);
	bool ButtonClick(UGUIComponent* Sender);
	void InternalOnLoadINI(UGUIComponent* Sender, FString S);
	void InternalOnChange(UGUIComponent* Sender);
	void InternalSetLoginStatus(int32 iStatus, FString sStatus, FString sNavMsg);
	void SaveSettings();
	bool Login(UGUIComponent* Sender);

};
