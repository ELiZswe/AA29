// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AABackgroundSubPanel.h"
#include "AAParental_ParentalControls.generated.h"

class UGUIImageButton;
class UGUILabel;
class UGUIButton;
class UmoEditBox;
class UmoCheckBox;
class UGUIImage;

UCLASS()
class AA29_API UAAParental_ParentalControls : public UAABackgroundSubPanel
{
	GENERATED_BODY()
public:
	UAAParental_ParentalControls();

	UPROPERTY(EditAnywhere)			UGUIImage*			i_FieldBackground;		//var() automated XInterface.GUIImage i_FieldBackground;
	UPROPERTY(EditAnywhere)			UmoCheckBox*		ch_LanguageFilter;		//var() automated XInterface.moCheckBox ch_LanguageFilter;
	UPROPERTY(EditAnywhere)			UmoCheckBox*		ch_NoBlood;				//var() automated XInterface.moCheckBox ch_NoBlood;
	UPROPERTY(EditAnywhere)			UmoCheckBox*		ch_MilesOnly;			//var() automated XInterface.moCheckBox ch_MilesOnly;
	UPROPERTY(EditAnywhere)			UmoCheckBox*		ch_NoSniper;			//var() automated XInterface.moCheckBox ch_NoSniper;
	UPROPERTY(EditAnywhere)			UmoEditBox*			ed_Password;			//var() automated XInterface.moEditBox ed_Password;
	UPROPERTY(EditAnywhere)			UmoEditBox*			ed_PasswordConfirm;		//var() automated XInterface.moEditBox ed_PasswordConfirm;
	UPROPERTY(EditAnywhere)			UGUIButton*			b_Set;					//var() automated XInterface.GUIButton b_Set;
	UPROPERTY(EditAnywhere)			UGUILabel*			l_Status1;				//var() automated XInterface.GUILabel l_Status1;
	UPROPERTY(EditAnywhere)			UGUILabel*			l_Status2;				//var() automated XInterface.GUILabel l_Status2;
	UPROPERTY(EditAnywhere)			UGUIImageButton*	ib_ESRBLogo;			//var() automated GUIImageButton ib_ESRBLogo;
	UPROPERTY(EditAnywhere)			bool				bLanguageFilter;		//var() transient noexport bool bLanguageFilter;
	UPROPERTY(EditAnywhere)			bool				bNoBlood;				//var() transient noexport bool bNoBlood;
	UPROPERTY(EditAnywhere)			bool				bMilesOnly;				//var() transient noexport bool bMilesOnly;
	UPROPERTY(EditAnywhere)			bool				bNoSniper;				//var() transient noexport bool bNoSniper;
	UPROPERTY(EditAnywhere)			FString				sPassword;				//var() FString sPassword;
	UPROPERTY(EditAnywhere)			FString				sPasswordConfirm;		//var() FString sPasswordConfirm;
	UPROPERTY()						FString				success;				//var localized FString success;
	UPROPERTY()						FString				Failure;				//var localized FString Failure;
	UPROPERTY()						FString				InvalidPassword;		//var localized FString InvalidPassword;
	UPROPERTY()						FString				PasswordMismatch;		//var localized FString PasswordMismatch;
	UPROPERTY()						FString				TryAgain;				//var localized FString TryAgain;
	UPROPERTY()						FString				OptionsSet;				//var localized FString OptionsSet;
	UPROPERTY()						FString				ComeBack;				//var localized FString ComeBack;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void InternalOnLoadINI(UGUIComponent* Sender, FString S);
	void InternalOnChange(UGUIComponent* Sender);
	bool ButtonClick(UGUIComponent* Sender);
	void SaveSettings();

};
