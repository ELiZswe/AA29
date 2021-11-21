// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AAParental_ParentalControls/AAParental_ParentalControls.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moCheckBox/moCheckBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moEditBox/moEditBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImageButton/GUIImageButton.h"

UAAParental_ParentalControls::UAAParental_ParentalControls()
{
	UmoCheckBox* LanguageFilterCheckBox = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	LanguageFilterCheckBox->ComponentJustification = EeTextAlign::TXTA_Left;
	LanguageFilterCheckBox->CaptionWidth = 0.94;
	LanguageFilterCheckBox->Caption = "Language Filter";
	//LanguageFilterCheckBox->OnCreateComponent=LanguageFilterCheckBox.InternalOnCreateComponent;
	LanguageFilterCheckBox->IniOption = "@Internal";
	LanguageFilterCheckBox->IniDefault = "False";
	LanguageFilterCheckBox->Hint = "Enables language filter.";
	LanguageFilterCheckBox->WinTop = 0.1;
	LanguageFilterCheckBox->WinLeft = 0.05;
	LanguageFilterCheckBox->WinWidth = 0.4;
	LanguageFilterCheckBox->WinHeight = 0.053476;
	LanguageFilterCheckBox->TabOrder = 0;
	LanguageFilterCheckBox->bStandardized = false;
	//LanguageFilterCheckBox->OnChange=AAParental_ParentalControls.InternalOnChange;
	//LanguageFilterCheckBox->OnLoadINI=AAParental_ParentalControls.InternalOnLoadINI;
	UmoCheckBox* NoBloodCheckBox = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	NoBloodCheckBox->ComponentJustification = EeTextAlign::TXTA_Left;
	NoBloodCheckBox->CaptionWidth = 0.94;
	NoBloodCheckBox->Caption = "No Blood";
	//NoBloodCheckBox->OnCreateComponent=NoBloodCheckBox.InternalOnCreateComponent;
	NoBloodCheckBox->IniOption = "@Internal";
	NoBloodCheckBox->IniDefault = "False";
	NoBloodCheckBox->Hint = "Disallows blood.";
	NoBloodCheckBox->WinTop = 0.15;
	NoBloodCheckBox->WinLeft = 0.05;
	NoBloodCheckBox->WinWidth = 0.4;
	NoBloodCheckBox->WinHeight = 0.053476;
	NoBloodCheckBox->TabOrder = 1;
	NoBloodCheckBox->bStandardized = false;
	//NoBloodCheckBox->OnChange=AAParental_ParentalControls.InternalOnChange;
	//NoBloodCheckBox->OnLoadINI=AAParental_ParentalControls.InternalOnLoadINI;
	UmoCheckBox* MilesOnlyCheckBox = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	MilesOnlyCheckBox->ComponentJustification = EeTextAlign::TXTA_Left;
	MilesOnlyCheckBox->CaptionWidth = 0.94;
	MilesOnlyCheckBox->Caption = "MILES Only";
	//MilesOnlyCheckBox->OnCreateComponent=MilesOnlyCheckBox.InternalOnCreateComponent;
	MilesOnlyCheckBox->IniOption = "@Internal";
	MilesOnlyCheckBox->IniDefault = "False";
	MilesOnlyCheckBox->Hint = "Live-fire missions cannot be played.";
	MilesOnlyCheckBox->WinTop = 0.2;
	MilesOnlyCheckBox->WinLeft = 0.05;
	MilesOnlyCheckBox->WinWidth = 0.4;
	MilesOnlyCheckBox->WinHeight = 0.053476;
	MilesOnlyCheckBox->TabOrder = 2;
	MilesOnlyCheckBox->bStandardized = false;
	//MilesOnlyCheckBox->OnChange=AAParental_ParentalControls.InternalOnChange;
	//MilesOnlyCheckBox->OnLoadINI=AAParental_ParentalControls.InternalOnLoadINI;
	UmoCheckBox* NoSniperCheckBox = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	NoSniperCheckBox->ComponentJustification = EeTextAlign::TXTA_Left;
	NoSniperCheckBox->CaptionWidth = 0.94;
	NoSniperCheckBox->Caption = "No Advanced Marksman";
	//NoSniperCheckBox->OnCreateComponent=NoSniperCheckBox.InternalOnCreateComponent;
	NoSniperCheckBox->IniOption = "@Internal";
	NoSniperCheckBox->IniDefault = "False";
	NoSniperCheckBox->Hint = "Sniper training will not be available.";
	NoSniperCheckBox->WinTop = 0.25;
	NoSniperCheckBox->WinLeft = 0.05;
	NoSniperCheckBox->WinWidth = 0.4;
	NoSniperCheckBox->WinHeight = 0.053476;
	NoSniperCheckBox->TabOrder = 3;
	NoSniperCheckBox->bStandardized = false;
	//NoSniperCheckBox->OnChange=AAParental_ParentalControls.InternalOnChange;
	//NoSniperCheckBox->OnLoadINI=AAParental_ParentalControls.InternalOnLoadINI;
	UmoEditBox* PasswordEdit = NewObject<UmoEditBox>(UmoEditBox::StaticClass());
	PasswordEdit->bMaskText = true;
	PasswordEdit->CaptionWidth = 0.3;
	PasswordEdit->Caption = "Password";
	//PasswordEdit->OnCreateComponent=PasswordEdit.InternalOnCreateComponent;
	PasswordEdit->IniOption = "@Internal";
	PasswordEdit->Hint = "Click here and enter a password.";
	PasswordEdit->WinTop = 0.35;
	PasswordEdit->WinLeft = 0.05;
	PasswordEdit->WinWidth = 0.65;
	PasswordEdit->WinHeight = 0.053476;
	PasswordEdit->TabOrder = 4;
	PasswordEdit->bStandardized = false;
	//PasswordEdit->OnChange=AAParental_ParentalControls.InternalOnChange;
	//PasswordEdit->OnLoadINI=AAParental_ParentalControls.InternalOnLoadINI;
	UmoEditBox* PasswordConfirmEdit = NewObject<UmoEditBox>(UmoEditBox::StaticClass());
	PasswordConfirmEdit->bMaskText = true;
	PasswordConfirmEdit->CaptionWidth = 0.3;
	PasswordConfirmEdit->Caption = "Confirm";
	//PasswordConfirmEdit->OnCreateComponent=PasswordConfirmEdit.InternalOnCreateComponent;
	PasswordConfirmEdit->IniOption = "@Internal";
	PasswordConfirmEdit->Hint = "Click here to confirm password.";
	PasswordConfirmEdit->WinTop = 0.41;
	PasswordConfirmEdit->WinLeft = 0.05;
	PasswordConfirmEdit->WinWidth = 0.65;
	PasswordConfirmEdit->WinHeight = 0.053476;
	PasswordConfirmEdit->TabOrder = 5;
	PasswordConfirmEdit->bStandardized = false;
	//PasswordConfirmEdit->OnChange=AAParental_ParentalControls.InternalOnChange;
	//PasswordConfirmEdit->OnLoadINI=AAParental_ParentalControls.InternalOnLoadINI;
	UGUIButton* SetButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	SetButton->Caption = "SET";
	SetButton->StyleName = "SquareMenuButton";
	SetButton->Hint = "Click to set options and password.";
	SetButton->WinTop = 0.475;
	SetButton->WinLeft = 0.5;
	SetButton->WinWidth = 0.2;
	SetButton->WinHeight = 0.053476;
	SetButton->TabOrder = 6;
	//SetButton->OnClick=AAParental_ParentalControls.ButtonClick;
	//SetButton->OnKeyEvent=SetButton.InternalOnKeyEvent;
	UGUIImageButton* ESRBLogoImageButton = NewObject<UGUIImageButton>(UGUIImageButton::StaticClass());
	ESRBLogoImageButton->Caption = "http://www.esrb.org/";
	ESRBLogoImageButton->link = "http://www.americasarmy.com/redir.php?r=17";
	ESRBLogoImageButton->Image = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/Logo_esr_Mat.Logo_esr_Mat'"), NULL, LOAD_None, NULL);
	ESRBLogoImageButton->ImageStyle = EImgStyle::ISTY_Scaled;
	ESRBLogoImageButton->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	ESRBLogoImageButton->WinTop = 0.75;
	ESRBLogoImageButton->WinLeft = 0.05;
	ESRBLogoImageButton->WinWidth = 0.2;
	ESRBLogoImageButton->WinHeight = 0.2;
	ESRBLogoImageButton->RenderWeight = 0.5;
	ESRBLogoImageButton->TabOrder = 7;
	//ESRBLogoImageButton->OnClick=AAParental_ParentalControls.ButtonClick;
	//ESRBLogoImageButton->OnKeyEvent=ESRBLogoImageButton.InternalOnKeyEvent;
	UGUIImage* FieldBackground = NewObject<UGUIImage>(UGUIImage::StaticClass());
	FieldBackground->Image = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/field_translucen_Mat.field_translucen_Mat'"), NULL, LOAD_None, NULL);
	FieldBackground->ImageStyle = EImgStyle::ISTY_Stretched;
	FieldBackground->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	FieldBackground->WinTop = 0.07;
	FieldBackground->WinLeft = 0.01;
	FieldBackground->WinWidth = 0.98;
	FieldBackground->WinHeight = 0.92;
	FieldBackground->RenderWeight = 0.2;
	UGUILabel* StatusMessage1Label = NewObject<UGUILabel>(UGUILabel::StaticClass());
	StatusMessage1Label->TextAlign = ETextAlign::TXTA_Center;
	StatusMessage1Label->TextColor = FColor(156, 201, 168, 255);
	StatusMessage1Label->TextFont = "TextLabel";
	StatusMessage1Label->VertAlign = ETextAlign::TXTA_Center;
	StatusMessage1Label->WinTop = 0.6;
	StatusMessage1Label->WinLeft = 0.05;
	StatusMessage1Label->WinWidth = 0.411;
	StatusMessage1Label->WinHeight = 0.15;
	StatusMessage1Label->bScaleToParent = true;
	UGUILabel* StatusMessage2Label = NewObject<UGUILabel>(UGUILabel::StaticClass());
	StatusMessage2Label->TextAlign = ETextAlign::TXTA_Center;
	StatusMessage2Label->TextColor = FColor(156, 201, 168, 255);
	StatusMessage2Label->TextFont = "TextLabel";
	StatusMessage2Label->VertAlign = ETextAlign::TXTA_Center;
	StatusMessage2Label->WinTop = 0.665;
	StatusMessage2Label->WinLeft = 0.05;
	StatusMessage2Label->WinWidth = 0.411;
	StatusMessage2Label->WinHeight = 0.15;
	StatusMessage2Label->bScaleToParent = true;
	i_FieldBackground = FieldBackground;
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
}

void UAAParental_ParentalControls::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	Super::InitComponent(MyController, MyOwner);
	ed_Password.MyEditBox.AllowedCharSet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
	ed_PasswordConfirm.MyEditBox.AllowedCharSet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
	Refresh();
	*/
}

void UAAParental_ParentalControls::InternalOnLoadINI(UGUIComponent* Sender, FString S)
{
	/*
	if (HumanController(PlayerOwner()) != None)
	{
		HumanController(PlayerOwner()).LoadPSettings();
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
		Log(string(Name) @ "Unknown component calling LoadINI:" $ GUIMenuOption(Sender).Caption);
		GUIMenuOption(Sender).SetComponentValue(S, true);
	}
	*/
}

void UAAParental_ParentalControls::InternalOnChange(UGUIComponent* Sender)
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

bool UAAParental_ParentalControls::ButtonClick(UGUIComponent* Sender)
{
	/*
	switch (Sender)
	{
	case ib_ESRBLogo:
		Controller.OpenMenu("AGP_Interface.AAExternalLinkPage", ib_ESRBLogo.Caption, ib_ESRBLogo.link);
		return true;
	case b_Set:
		SaveSettings();
		return true;
	default:
		return true;
	}
	*/
	return false;   //FAKE   /ELiZ
}

void UAAParental_ParentalControls::SaveSettings()
{
	/*
	local PlayerController PC;
	local HumanController HC;
	bool bSave = false;
	PC = PlayerOwner();
	HC = HumanController(PC);
	if (HC == None)
	{
		return;
	}
	if ((((bLanguageFilter != GetLanguageFilter()) || (bNoBlood != GetNoBlood())) || (bMilesOnly != GetMilesOnly())) || (bNoSniper != GetNoSniper()))
	{
		bSave = true;
	}
	if (HC.ParentPassword != "")
	{
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
	HC.ParentPassword = sPassword;
	SetLanguageFilter(bLanguageFilter);
	SetNoBlood(bNoBlood);
	SetMilesOnly(bMilesOnly);
	SetNoSniper(bNoSniper);
	if (AAGUIController(Controller) != None)
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
	*/
}
