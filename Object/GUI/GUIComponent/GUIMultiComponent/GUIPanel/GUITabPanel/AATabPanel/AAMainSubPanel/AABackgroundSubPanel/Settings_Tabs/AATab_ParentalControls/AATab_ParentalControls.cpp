// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/Settings_Tabs/AATab_ParentalControls/AATab_ParentalControls.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moCheckBox/moCheckBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moEditBox/moEditBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImageButton/GUIImageButton.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIEditBox/GUIEditBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/AAGUIController/AAGUIController.h"

UAATab_ParentalControls::UAATab_ParentalControls()
{
	UmoCheckBox* LanguageFilterCheckBox = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	LanguageFilterCheckBox->ComponentJustification = EeTextAlign::TXTA_Left;
	LanguageFilterCheckBox->CaptionWidth=0.94;
	LanguageFilterCheckBox->Caption="Language Filter";
	//LanguageFilterCheckBox->OnCreateComponent=LanguageFilterCheckBox.InternalOnCreateComponent;
	LanguageFilterCheckBox->IniOption="@Internal";
	LanguageFilterCheckBox->IniDefault="False";
	LanguageFilterCheckBox->Hint="Enables language filter.";
	LanguageFilterCheckBox->WinTop=0.1;
	LanguageFilterCheckBox->WinLeft=0.05;
	LanguageFilterCheckBox->WinWidth=0.4;
	LanguageFilterCheckBox->WinHeight=0.035;
	LanguageFilterCheckBox->TabOrder=0;
	LanguageFilterCheckBox->bStandardized=false;
	//LanguageFilterCheckBox->OnChange=AATab_ParentalControls.InternalOnChange;
	//LanguageFilterCheckBox->OnLoadINI=AATab_ParentalControls.InternalOnLoadINI;
	UmoCheckBox* NoBloodCheckBox = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	NoBloodCheckBox->ComponentJustification = EeTextAlign::TXTA_Left;
	NoBloodCheckBox->CaptionWidth=0.94;
	NoBloodCheckBox->Caption="No Blood";
	//NoBloodCheckBox->OnCreateComponent=NoBloodCheckBox.InternalOnCreateComponent;
	NoBloodCheckBox->IniOption="@Internal";
	NoBloodCheckBox->IniDefault="False";
	NoBloodCheckBox->Hint="Disallows blood.";
	NoBloodCheckBox->WinTop=0.15;
	NoBloodCheckBox->WinLeft=0.05;
	NoBloodCheckBox->WinWidth=0.4;
	NoBloodCheckBox->WinHeight=0.035;
	NoBloodCheckBox->TabOrder=1;
	NoBloodCheckBox->bStandardized=false;
	//NoBloodCheckBox->OnChange=AATab_ParentalControls.InternalOnChange;
	//NoBloodCheckBox->OnLoadINI=AATab_ParentalControls.InternalOnLoadINI;
	UmoCheckBox* MilesOnlyCheckBox = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	MilesOnlyCheckBox->ComponentJustification = EeTextAlign::TXTA_Left;
	MilesOnlyCheckBox->CaptionWidth=0.94;
	MilesOnlyCheckBox->Caption="MILES Only";
	//MilesOnlyCheckBox->OnCreateComponent=MilesOnlyCheckBox.InternalOnCreateComponent;
	MilesOnlyCheckBox->IniOption="@Internal";
	MilesOnlyCheckBox->IniDefault="False";
	MilesOnlyCheckBox->Hint="Live-fire missions cannot be played.";
	MilesOnlyCheckBox->WinTop=0.2;
	MilesOnlyCheckBox->WinLeft=0.05;
	MilesOnlyCheckBox->WinWidth=0.4;
	MilesOnlyCheckBox->WinHeight=0.035;
	MilesOnlyCheckBox->TabOrder=2;
	MilesOnlyCheckBox->bStandardized=false;
	//MilesOnlyCheckBox->OnChange=AATab_ParentalControls.InternalOnChange;
	//MilesOnlyCheckBox->OnLoadINI=AATab_ParentalControls.InternalOnLoadINI;
	UmoCheckBox* NoSniperCheckBox = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	NoSniperCheckBox->ComponentJustification = EeTextAlign::TXTA_Left;
	NoSniperCheckBox->CaptionWidth=0.94;
	NoSniperCheckBox->Caption="No Advanced Marksman";
	//NoSniperCheckBox->OnCreateComponent=NoSniperCheckBox.InternalOnCreateComponent;
	NoSniperCheckBox->IniOption="@Internal";
	NoSniperCheckBox->IniDefault="False";
	NoSniperCheckBox->Hint="Sniper training will not be available.";
	NoSniperCheckBox->WinTop=0.25;
	NoSniperCheckBox->WinLeft=0.05;
	NoSniperCheckBox->WinWidth=0.4;
	NoSniperCheckBox->WinHeight=0.035;
	NoSniperCheckBox->TabOrder=3;
	NoSniperCheckBox->bStandardized=false;
	//NoSniperCheckBox->OnChange=AATab_ParentalControls.InternalOnChange;
	//NoSniperCheckBox->OnLoadINI=AATab_ParentalControls.InternalOnLoadINI;
	UmoEditBox* PasswordEdit = NewObject<UmoEditBox>(UmoEditBox::StaticClass());
	PasswordEdit->bMaskText=true;
	PasswordEdit->CaptionWidth=0.3;
	PasswordEdit->Caption="Password";
	//PasswordEdit->OnCreateComponent=PasswordEdit.InternalOnCreateComponent;
	PasswordEdit->IniOption="@Internal";
	PasswordEdit->Hint="Click here and enter a password.";
	PasswordEdit->WinTop=0.35;
	PasswordEdit->WinLeft=0.05;
	PasswordEdit->WinWidth=0.4;
	PasswordEdit->WinHeight=0.04;
	PasswordEdit->TabOrder=4;
	PasswordEdit->bStandardized=false;
	//PasswordEdit->OnChange=AATab_ParentalControls.InternalOnChange;
	//PasswordEdit->OnLoadINI=AATab_ParentalControls.InternalOnLoadINI;
	UmoEditBox* PasswordConfirmEdit = NewObject<UmoEditBox>(UmoEditBox::StaticClass());
	PasswordConfirmEdit->bMaskText=true;
	PasswordConfirmEdit->CaptionWidth=0.3;
	PasswordConfirmEdit->Caption="Confirm";
	//PasswordConfirmEdit->OnCreateComponent=PasswordConfirmEdit.InternalOnCreateComponent;
	PasswordConfirmEdit->IniOption="@Internal";
	PasswordConfirmEdit->Hint="Click here to confirm password.";
	PasswordConfirmEdit->WinTop=0.41;
	PasswordConfirmEdit->WinLeft=0.05;
	PasswordConfirmEdit->WinWidth=0.4;
	PasswordConfirmEdit->WinHeight=0.04;
	PasswordConfirmEdit->TabOrder=5;
	PasswordConfirmEdit->bStandardized=false;
	//PasswordConfirmEdit->OnChange=AATab_ParentalControls.InternalOnChange;
	//PasswordConfirmEdit->OnLoadINI=AATab_ParentalControls.InternalOnLoadINI;
	UGUIButton* SetButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	SetButton->Caption="SET";
	SetButton->StyleName="SquareMenuButton";
	SetButton->Hint="Click to set options and password.";
	SetButton->WinTop=0.475;
	SetButton->WinLeft=0.29;
	SetButton->WinWidth=0.16;
	SetButton->WinHeight=0.035;
	SetButton->TabOrder=6;
	//SetButton->OnClick=AATab_ParentalControls.ButtonClick;
	//SetButton->OnKeyEvent=SetButton.InternalOnKeyEvent;
	UGUIImageButton* ESRBLogoImageButton = NewObject<UGUIImageButton>(UGUIImageButton::StaticClass());
	ESRBLogoImageButton->Caption="http://www.esrb.org/";
	ESRBLogoImageButton->link="http://www.americasarmy.com/redir.php?r=17";
	//ESRBLogoImageButton->Image=Texture'T_AA2_UI.Menu.Logo_esrb';
	ESRBLogoImageButton->ImageStyle = EImgStyle::ISTY_Scaled;
	ESRBLogoImageButton->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	ESRBLogoImageButton->WinTop=0.7;
	ESRBLogoImageButton->WinLeft=0.05;
	ESRBLogoImageButton->WinWidth=0.2;
	ESRBLogoImageButton->WinHeight=0.2;
	ESRBLogoImageButton->RenderWeight=0.5;
	ESRBLogoImageButton->TabOrder=7;
	//ESRBLogoImageButton->OnClick=AATab_ParentalControls.ButtonClick;
	//ESRBLogoImageButton->OnKeyEvent=ESRBLogoImageButton.InternalOnKeyEvent;
	UGUILabel* StatusMessage1Label = NewObject<UGUILabel>(UGUILabel::StaticClass());
	StatusMessage1Label->TextAlign = ETextAlign::TXTA_Center;
	StatusMessage1Label->TextColor=FColor(156, 201, 168, 255);
	StatusMessage1Label->TextFont="TextLabel";
	StatusMessage1Label->VertAlign = ETextAlign::TXTA_Center;
	StatusMessage1Label->WinTop=0.6;
	StatusMessage1Label->WinLeft=0.05;
	StatusMessage1Label->WinWidth=0.411;
	StatusMessage1Label->WinHeight=0.15;
	StatusMessage1Label->bScaleToParent=true;
	UGUILabel* StatusMessage2Label = NewObject<UGUILabel>(UGUILabel::StaticClass());
	StatusMessage2Label->TextAlign = ETextAlign::TXTA_Center;
	StatusMessage2Label->TextColor=FColor(156, 201, 168, 255);
	StatusMessage2Label->TextFont="TextLabel";
	StatusMessage2Label->VertAlign = ETextAlign::TXTA_Center;
	StatusMessage2Label->WinTop=0.665;
	StatusMessage2Label->WinLeft=0.05;
	StatusMessage2Label->WinWidth=0.411;
	StatusMessage2Label->WinHeight=0.15;
	StatusMessage2Label->bScaleToParent=true;

	ch_LanguageFilter = LanguageFilterCheckBox;
	ch_NoBlood = NoBloodCheckBox;
	ch_MilesOnly = MilesOnlyCheckBox;
	ch_NoSniper = NoSniperCheckBox;
	ed_Password = PasswordEdit;
	ed_PasswordConfirm = PasswordConfirmEdit;
	b_Set = SetButton;
	l_Status1 = StatusMessage1Label;
	l_Status2 = StatusMessage2Label;
	ib_ESRBLogo = ESRBLogoImageButton;
	success = "Parental Control Settings have been saved.";
	Failure = "Password did not match.";
	InvalidPassword = "Invalid Password.";
	PasswordMismatch = "Passwords did not match.";
	TryAgain = "Please try again.";
	OptionsSet = "Options are set.";
	ComeBack = "Come back to this page to make any changes in the future.";
	PanelCaption = "Parental Controls";
}

void UAATab_ParentalControls::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	Super::InitComponent(MyController, MyOwner);
	ed_Password->MyEditBox->AllowedCharSet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
	ed_PasswordConfirm->MyEditBox->AllowedCharSet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
	Refresh();
}

void UAATab_ParentalControls::InternalOnLoadINI(UGUIComponent* Sender, FString S)
{
	/*
	if (Cast<AHumanController>(PlayerOwner()) != nullptr)
	{
		Cast<AHumanController>(PlayerOwner())->LoadPSettings();
	}
	switch (Sender)
	{
	case ch_LanguageFilter:
		bLanguageFilter = GetLanguageFilter();
		ch_LanguageFilter.SetComponentValue(string(bLanguageFilter), true);
		break;
	case ch_NoBlood:
		bNoBlood = GetNoBlood();
		ch_NoBlood.SetComponentValue(string(bNoBlood), true);
		break;
	case ch_MilesOnly:
		bMilesOnly = GetMilesOnly();
		ch_MilesOnly.SetComponentValue(string(bMilesOnly), true);
		break;
	case ch_NoSniper:
		bNoSniper = GetNoSniper();
		ch_NoSniper.SetComponentValue(string(bNoSniper), true);
		break;
	case ed_Password:
		break;
	case ed_PasswordConfirm:
		break;
	default:
		Log(string(Name) @ "Unknown component calling LoadINI:" + GUIMenuOption(Sender).Caption);
		GUIMenuOption(Sender).SetComponentValue(S, true);
	}
	*/
}

void UAATab_ParentalControls::InternalOnChange(UGUIComponent* Sender)
{
	/*
	switch (Sender)
	{
	case ch_LanguageFilter:
		bLanguageFilter = ch_LanguageFilter.IsChecked();
		break;
	case ch_NoBlood:
		bNoBlood = ch_NoBlood.IsChecked();
		break;
	case ch_MilesOnly:
		bMilesOnly = ch_MilesOnly.IsChecked();
		break;
	case ch_NoSniper:
		bNoSniper = ch_NoSniper.IsChecked();
		break;
	case ed_Password:
		sPassword = ed_Password.GetText();
		break;
	case ed_PasswordConfirm:
		sPasswordConfirm = ed_PasswordConfirm.GetText();
		break;
	default:
		break;
	}
	*/
}

bool UAATab_ParentalControls::ButtonClick(UGUIComponent* Sender)
{
	/*
	switch (Sender)
	{
	case ib_ESRBLogo:
		Controller.OpenMenu("AGP_Interface.AAExternalLinkPage", ib_ESRBLogo.Caption, ib_ESRBLogo.link);
		return true;
	case b_Set:
		bSavingInUI = true;
		SaveSettings();
		return true;
	default:
		return true;
	}
	*/
	return false;    //FAKE   /ELiZ
}

void UAATab_ParentalControls::SaveSettings()
{
	/*
	APlayerController* PC = nullptr;
	AHumanController* HC = nullptr;
	bool bSave = false;
	PC = PlayerOwner();
	HC = Cast<AHumanController>(PC);
	if (HC == nullptr)
	{
		return;
	}
	if ((((bLanguageFilter != GetLanguageFilter()) || (bNoBlood != GetNoBlood())) || (bMilesOnly != GetMilesOnly())) || (bNoSniper != GetNoSniper()))
	{
		bSave = true;
	}
	if ((HC.ParentPassword != "") && bSavingInUI)
	{
		bSavingInUI = false;
		if (sPassword != sPasswordConfirm)
		{
			Controller.OpenMenu("AGP_Interface.AAGenericMessageBox", PasswordMismatch, TryAgain);
			return;
		}
		if (HC.ParentPassword != sPassword)
		{
			Controller.OpenMenu("AGP_Interface.AAGenericMessageBox", InvalidPassword, TryAgain);
			return;
		}
	}
	if (bSavingInUI)
	{
		HC.ParentPassword = sPassword;
	}
	SetLanguageFilter(bLanguageFilter);
	SetNoBlood(bNoBlood);
	SetMilesOnly(bMilesOnly);
	SetNoSniper(bNoSniper);
	if (Cast<UAAGUIController>(Controller) != nullptr)
	{
		AAGUIController(Controller).bFilterLanguage = GetLanguageFilter();
		AAGUIController(Controller).bFilterNoBlood = GetNoBlood();
		AAGUIController(Controller).bFilterMilesOnly = GetMilesOnly();
		AAGUIController(Controller).bFilterNoSniper = GetNoSniper();
	}
	if (bSave)
	{
		PC.SaveConfig();
		HC.SavePSettings();
		Controller.OpenMenu("AGP_Interface.AAGenericMessageBox", OptionsSet);
	}
	bSavingInUI = false;
	*/
}
