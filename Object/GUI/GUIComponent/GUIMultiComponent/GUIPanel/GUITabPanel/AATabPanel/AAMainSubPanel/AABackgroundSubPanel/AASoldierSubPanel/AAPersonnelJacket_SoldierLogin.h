// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AASoldierSubPanel/AAPersonnelJacketSubPanel.h"
#include "AAPersonnelJacket_SoldierLogin.generated.h"

class UGUIImage;
class UGUIButton;
class UmoEditBox;
class UmoCheckBox;
class UGUILabel;
class UGUIScrollTextBox;

UCLASS()
class AA29_API UAAPersonnelJacket_SoldierLogin : public UAAPersonnelJacketSubPanel
{
	GENERATED_BODY()
public:
	UAAPersonnelJacket_SoldierLogin();


	UPROPERTY(EditAnywhere)			UGUIImage* i_FieldBackground;					//var() automated XInterface.GUIImage i_FieldBackground;
	UPROPERTY(EditAnywhere)			UGUIButton* b_CreateAccount;					//var() automated XInterface.GUIButton b_CreateAccount;
	UPROPERTY(EditAnywhere)			UGUIButton* b_GetNews;							//var() automated XInterface.GUIButton b_GetNews;
	UPROPERTY(EditAnywhere)			UGUIButton* b_LogIn;							//var() automated XInterface.GUIButton b_LogIn;
	UPROPERTY(EditAnywhere)			UGUIButton* b_LogOut;							//var() automated XInterface.GUIButton b_LogOut;
	UPROPERTY(EditAnywhere)			UmoEditBox* ed_Username;						//var() automated XInterface.moEditBox ed_Username;
	UPROPERTY(EditAnywhere)			UmoEditBox* ed_Password;						//var() automated XInterface.moEditBox ed_Password;
	UPROPERTY(EditAnywhere)			UmoCheckBox* ch_RememberUser;					//var() automated XInterface.moCheckBox ch_RememberUser;
	UPROPERTY(EditAnywhere)			UGUILabel* l_Status;							//var() automated XInterface.GUILabel l_Status;
	UPROPERTY(EditAnywhere)			UGUIScrollTextBox* stb_News;					//var() automated XInterface.GUIScrollTextBox stb_News;
	UPROPERTY()						FString NotConnectedText;						//var localized FString NotConnectedText;
	UPROPERTY()						FString CreateAccountText;						//var localized FString CreateAccountText;
	UPROPERTY()						FString _iLoginStatus;							//var int32 _iLoginStatus;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	bool ButtonClick(UGUIComponent* Sender);
	void InternalOnLoadINI(UGUIComponent* Sender, FString S);
	void GetNews();
	void SelectLogin();
	void Logout();
	void RefreshLoginScreen();
	void MySetLoginStatus(int32 iStatus, FString sStatus, FString sNavMsg);
	void SaveSettings();
	void InternalOnChange(UGUIComponent* Sender);
};
