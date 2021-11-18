// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/AASplashPage/AASplashPage.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/BackgroundImage/BackgroundImage.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/AAGUILabel/AAGUILabel.h"

UAASplashPage::UAASplashPage()
{
	UBackgroundImage* PageBackground = NewObject<UBackgroundImage>(UBackgroundImage::StaticClass());
	PageBackground->Image = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/GUI/t_ui_gui_splas_Mat.t_ui_gui_splas_Mat'"), NULL, LOAD_None, NULL);
	PageBackground->ImageStyle = EImgStyle::ISTY_Scaled;
	UGUIImage* ESRBLogoImageButton = NewObject<UGUIImage>(UGUIImage::StaticClass());
	ESRBLogoImageButton->Image = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/Logo_esr_Mat.Logo_esr_Mat'"), NULL, LOAD_None, NULL);
	ESRBLogoImageButton->ImageStyle = EImgStyle::ISTY_Scaled;
	ESRBLogoImageButton->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	ESRBLogoImageButton->WinTop = 0.824689;
	ESRBLogoImageButton->WinLeft = 0.885;
	ESRBLogoImageButton->WinWidth = 0.115;
	ESRBLogoImageButton->WinHeight = 0.14;
	ESRBLogoImageButton->RenderWeight = 0.5;
	UGUIImage* ArmyStarLogoImageButton = NewObject<UGUIImage>(UGUIImage::StaticClass());
	ArmyStarLogoImageButton->Image = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/Logo/t_ui_logo_goarm_Mat.t_ui_logo_goarm_Mat'"), NULL, LOAD_None, NULL);
	ArmyStarLogoImageButton->ImageStyle = EImgStyle::ISTY_Scaled;
	ArmyStarLogoImageButton->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	ArmyStarLogoImageButton->WinTop = 0.85;
	ArmyStarLogoImageButton->WinLeft = 0.04;
	ArmyStarLogoImageButton->WinWidth = 0.0765;
	ArmyStarLogoImageButton->WinHeight = 0.09775;
	ArmyStarLogoImageButton->RenderWeight = 0.5;
	UGUIImage* AALogoImageButton = NewObject<UGUIImage>(UGUIImage::StaticClass());
	AALogoImageButton->Image = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/Logo_AA_hori_Mat.Logo_AA_hori_Mat'"), NULL, LOAD_None, NULL);
	AALogoImageButton->ImageStyle = EImgStyle::ISTY_Scaled;
	AALogoImageButton->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	AALogoImageButton->WinTop = 0.05;
	AALogoImageButton->WinLeft = 0.1;
	AALogoImageButton->WinWidth = 0.8;
	AALogoImageButton->WinHeight = 0.115;
	AALogoImageButton->RenderWeight = 0.5;
	UAAGUILabel* DisclaimerLabel = NewObject<UAAGUILabel>(UAAGUILabel::StaticClass());
	DisclaimerLabel->Caption = "The presence of logos, URLs or other information identifying private companies or other non-federal entities does not constitute endorsement by the Department of the Army or the Department of Defense||ESRB Notice: Game Experience May Change During Online Play";
	DisclaimerLabel->TextAlign = ETextAlign::TXTA_Center;
	DisclaimerLabel->bMultiLine = true;
	DisclaimerLabel->StyleName = "NMLSmallText";
	DisclaimerLabel->WinTop = 0.828055;
	DisclaimerLabel->WinLeft = 0.2;
	DisclaimerLabel->WinWidth = 0.6;
	DisclaimerLabel->WinHeight = 0.175;
	DisclaimerLabel->RenderWeight = 0.5;
	UAAGUILabel* VersionLabel = NewObject<UAAGUILabel>(UAAGUILabel::StaticClass());
	VersionLabel->Caption = "Version 2.8.5";
	VersionLabel->TextAlign = ETextAlign::TXTA_Right;
	VersionLabel->bMultiLine = true;
	VersionLabel->StyleName = "NMLMediumText";
	VersionLabel->WinTop = 0.1625;
	VersionLabel->WinLeft = 0.5;
	VersionLabel->WinWidth = 0.375;
	VersionLabel->WinHeight = 0.075;
	VersionLabel->RenderWeight = 0.5;
	i_Background = PageBackground;
	iAALogo = AALogoImageButton;
	lVersion = VersionLabel;
	lDisclaimer = DisclaimerLabel;
	iArmyStar = ArmyStarLogoImageButton;
	iESRBLogo = ESRBLogoImageButton;
	fDisplayTime = 5;
	EntryPage = "AGP_Interface.AAPreLoginPage";
	bAllowedAsLast = true;
	//OnOpen = AASplashPage.InternalOnOpen;
	//OnClose = AASplashPage.InternalOnClose;
	//OnCanClose = AASplashPage.CanClose;
	WinHeight = 1;
}

void UAASplashPage::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	//Super::InitComponent(MyController, MyOwner);
	//SetTimer(fDisplayTime, false);
}

void UAASplashPage::Timer()
{
	/*
	local AAGUIController AAGC;
	AAGC = AAGUIController(Controller);
	if (AAGC != None)
	{
		AAGC.bHideMouseCursor = false;
		if (AAGC.bLoggedIn)
		{
			EntryPage = "AGP_Interface.AAMainMenu";
		}
	}
	bAllowClose = true;
	Controller.OpenMenu(EntryPage);
	*/
}

bool UAASplashPage::internalKeyEvent(uint8& Key, uint8& State, float Delta)
{
	return false;
}

bool UAASplashPage::CanClose(bool bCancelled)
{
	return bAllowClose;
}

void UAASplashPage::InternalOnOpen()
{
	/*
	OnOpen();
	if (AAGUIController(Controller) != None)
	{
		AAGUIController(Controller).bHideMouseCursor = true;
	}
	*/
}

void UAASplashPage::InternalOnClose(bool bCanceled)
{
	/*
	if (AAGUIController(Controller) != None)
	{
		AAGUIController(Controller).bHideMouseCursor = false;
	}
	OnClose(bCanceled);
	*/
}