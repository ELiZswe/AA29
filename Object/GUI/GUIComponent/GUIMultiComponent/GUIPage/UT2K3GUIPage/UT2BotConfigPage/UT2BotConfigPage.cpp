// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/UT2K3GUIPage/UT2BotConfigPage/UT2BotConfigPage.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moComboBox/moComboBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moCheckBox/moCheckBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moSlider/moSlider.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"

UUT2BotConfigPage::UUT2BotConfigPage()
{
	UmoComboBox* BotWeapon = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	BotWeapon->bReadOnly = true;
	BotWeapon->ComponentJustification = EeTextAlign::TXTA_Left;
	BotWeapon->CaptionWidth = 0.45;
	BotWeapon->Caption = "Preferred Weapon";
	//BotWeapon->OnCreateComponent=BotWeapon.InternalOnCreateComponent;
	BotWeapon->Hint = "Select which weapon this bot should prefer.";
	BotWeapon->WinTop = 0.729062;
	BotWeapon->WinLeft = 0.345313;
	BotWeapon->WinWidth = 0.598438;
	BotWeapon->WinHeight = 0.044375;
	UmoCheckBox* BotJumpy = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	BotJumpy->CaptionWidth = 0.9;
	BotJumpy->Caption = "Jump Happy";
	//BotJumpy->OnCreateComponent=BotJumpy.InternalOnCreateComponent;
	BotJumpy->Hint = "Controls whether this bot jumps a lot during the game.";
	BotJumpy->WinTop = 0.666562;
	BotJumpy->WinLeft = 0.345313;
	BotJumpy->WinWidth = 0.598438;
	BotJumpy->WinHeight = 0.04;
	//BotJumpy->OnChange=UT2BotConfigPage.CheckBoxChange;
	UmoSlider* BotReactionSlider = NewObject<UmoSlider>(UmoSlider::StaticClass());
	BotReactionSlider->MaxValue = 4;
	BotReactionSlider->MinValue = -4;
	BotReactionSlider->Caption = "Reaction Time";
	//BotReactionSlider->OnCreateComponent=BotReactionSlider.InternalOnCreateComponent;
	BotReactionSlider->Hint = "Adjusts the reaction speed of this bot.";
	BotReactionSlider->WinTop = 0.593645;
	BotReactionSlider->WinLeft = 0.345313;
	BotReactionSlider->WinWidth = 0.598438;
	//BotReactionSlider->OnChange=UT2BotConfigPage.SliderChange;
	UmoSlider* BotTacticsSlider = NewObject<UmoSlider>(UmoSlider::StaticClass());
	BotTacticsSlider->MaxValue = 1;
	BotTacticsSlider->MinValue = -1;
	BotTacticsSlider->Caption = "Tactics";
	//BotTacticsSlider->OnCreateComponent=BotTacticsSlider.InternalOnCreateComponent;
	BotTacticsSlider->Hint = "Adjusts the team-play awareness ability of this bot.";
	BotTacticsSlider->WinTop = 0.499895;
	BotTacticsSlider->WinLeft = 0.345313;
	BotTacticsSlider->WinWidth = 0.598438;
	//BotTacticsSlider->OnChange=UT2BotConfigPage.SliderChange;
	UmoSlider* BotStrafeSlider = NewObject<UmoSlider>(UmoSlider::StaticClass());
	BotStrafeSlider->MaxValue = 1;
	BotStrafeSlider->Caption = "Strafing Ability";
	//BotStrafeSlider->OnCreateComponent=BotStrafeSlider.InternalOnCreateComponent;
	BotStrafeSlider->Hint = "Adjusts the strafing ability of this bot.";
	BotStrafeSlider->WinTop = 0.426979;
	BotStrafeSlider->WinLeft = 0.345313;
	BotStrafeSlider->WinWidth = 0.598438;
	//BotStrafeSlider->OnChange=UT2BotConfigPage.SliderChange;
	UmoSlider* BotCStyleSlider = NewObject<UmoSlider>(UmoSlider::StaticClass());
	BotCStyleSlider->MaxValue = 1;
	BotCStyleSlider->Caption = "Combat Style";
	//BotCStyleSlider->OnCreateComponent=BotCStyleSlider.InternalOnCreateComponent;
	BotCStyleSlider->Hint = "Adjusts the combat style of this bot.";
	BotCStyleSlider->WinTop = 0.354062;
	BotCStyleSlider->WinLeft = 0.345313;
	BotCStyleSlider->WinWidth = 0.598438;
	//BotCStyleSlider->OnChange=UT2BotConfigPage.SliderChange;
	UmoSlider* BotAccuracySlider = NewObject<UmoSlider>(UmoSlider::StaticClass());
	BotAccuracySlider->MaxValue = 1;
	BotAccuracySlider->MinValue = -1;
	BotAccuracySlider->Caption = "Accuracy";
	//BotAccuracySlider->OnCreateComponent=BotAccuracySlider.InternalOnCreateComponent;
	BotAccuracySlider->Hint = "Configures the accuracy rating of this bot.";
	BotAccuracySlider->WinTop = 0.281145;
	BotAccuracySlider->WinLeft = 0.345313;
	BotAccuracySlider->WinWidth = 0.598438;
	//BotAccuracySlider->OnChange=UT2BotConfigPage.SliderChange;
	UmoSlider* BotAggrSlider = NewObject<UmoSlider>(UmoSlider::StaticClass());
	BotAggrSlider->MaxValue = 1;
	BotAggrSlider->Caption = "Aggressiveness";
	//BotAggrSlider->OnCreateComponent=BotAggrSlider.InternalOnCreateComponent;
	BotAggrSlider->Hint = "Configures the aggressiveness rating of this bot.";
	BotAggrSlider->WinTop = 0.208229;
	BotAggrSlider->WinLeft = 0.345313;
	BotAggrSlider->WinWidth = 0.598438;
	BotAggrSlider->TabOrder = 0;
	//BotAggrSlider->OnChange=UT2BotConfigPage.SliderChange;
	UGUIButton* OkButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	OkButton->Caption = "OK";
	OkButton->WinTop = 0.825001;
	OkButton->WinLeft = 0.765625;
	OkButton->WinWidth = 0.167187;
	OkButton->WinHeight = 0.045313;
	//OkButton->OnClick=UT2BotConfigPage.OkClick;
	//OkButton->OnKeyEvent=OkButton.InternalOnKeyEvent;
	UGUIButton* ResetButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	ResetButton->Caption = "Reset";
	ResetButton->WinTop = 0.825001;
	ResetButton->WinLeft = 0.585938;
	ResetButton->WinWidth = 0.167187;
	ResetButton->WinHeight = 0.045313;
	//ResetButton->OnClick=UT2BotConfigPage.ResetClick;
	//ResetButton->OnKeyEvent=ResetButton.InternalOnKeyEvent;
	UGUIImage* PageBack = NewObject<UGUIImage>(UGUIImage::StaticClass());
	PageBack->ImageStyle = EImgStyle::ISTY_Stretched;
	PageBack->WinLeft = 0.0625;
	PageBack->WinWidth = 0.890625;
	PageBack->WinHeight = 1;
	PageBack->bBoundToParent = true;
	PageBack->bScaleToParent = true;
	UGUIImage* imgBotPic = NewObject<UGUIImage>(UGUIImage::StaticClass());
	imgBotPic->ImageStyle = EImgStyle::ISTY_Justified;
	imgBotPic->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	imgBotPic->WinTop = 0.193982;
	imgBotPic->WinLeft = 0.078125;
	imgBotPic->WinWidth = 0.246875;
	imgBotPic->WinHeight = 0.658008;
	imgBotPic->RenderWeight = 0.1001;
	UGUIImage* BotPortraitBorder = NewObject<UGUIImage>(UGUIImage::StaticClass());
	BotPortraitBorder->ImageStyle = EImgStyle::ISTY_Stretched;
	BotPortraitBorder->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	BotPortraitBorder->DropShadowX = 8;
	BotPortraitBorder->DropShadowY = 8;
	BotPortraitBorder->WinTop = 0.188427;
	BotPortraitBorder->WinLeft = 0.076563;
	BotPortraitBorder->WinWidth = 0.253125;
	BotPortraitBorder->WinHeight = 0.664258;
	UGUILabel* BotCfgName = NewObject<UGUILabel>(UGUILabel::StaticClass());
	BotCfgName->Caption = "Unknown";
	BotCfgName->FontScale = EFontScale::FNS_Large;
	BotCfgName->StyleName = "TextLabel";
	BotCfgName->WinTop = 0.119068;
	BotCfgName->WinLeft = 0.084744;
	BotCfgName->WinWidth = 0.598437;
	BotCfgName->WinHeight = 0.052539;
	NoInformation = "No Information Available!";
	Controls = { PageBack,imgBotPic,BotPortraitBorder,BotCfgName,ResetButton,OkButton,BotAggrSlider,BotAccuracySlider,BotCStyleSlider,BotStrafeSlider,BotTacticsSlider,BotReactionSlider,BotJumpy,BotWeapon };
	WinTop = 0.1;
	WinHeight = 0.8;
}

void UUT2BotConfigPage::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	int32 i = 0;
	Super::InitComponent(MyController, MyOwner);
	BotPortrait = GUIImage(Controls[1]);
	botname = GUILabel(Controls[3]);
	Class'CacheManager'.GetWeaponList(Records);
	Wep = moComboBox(Controls[13]);
	Wep.addItem("None");
	for (i = 0; i < Records.Length; i++)
	{
		Wep.addItem(Records[i].FriendlyName, , Records[i].ClassName);
	}
	Wep.__OnChange__Delegate = ComboBoxChange;
	moSlider(Controls[6]).MySlider.__OnDrawCaption__Delegate = AggDC;
	moSlider(Controls[7]).MySlider.__OnDrawCaption__Delegate = AccDC;
	moSlider(Controls[8]).MySlider.__OnDrawCaption__Delegate = ComDC;
	moSlider(Controls[9]).MySlider.__OnDrawCaption__Delegate = StrDC;
	moSlider(Controls[10]).MySlider.__OnDrawCaption__Delegate = TacDC;
	moSlider(Controls[11]).MySlider.__OnDrawCaption__Delegate = ReaDC;
	*/
}

bool UUT2BotConfigPage::OkClick(UGUIComponent* Sender)
{
	//Controller.CloseMenu(false);
	return true;
}

bool UUT2BotConfigPage::ResetClick(UGUIComponent* Sender)
{
	bIgnoreChange = true;
	SetDefaults();
	bIgnoreChange = false;
	return true;
}

FString UUT2BotConfigPage::DoPerc(UGUISlider* Control)
{
	/*
	float R = 0;
	float V = 0;
	float vmin = 0;
	vmin = Control.MinValue;
	R = (Control.MaxValue - vmin);
	V = (Control.Value - vmin);
	return string(int(((V / R) * float(100))));
	*/
	return "FAKE";   //FAKE   /ELiZ
}

FString UUT2BotConfigPage::AggDC()
{
	//return DoPerc(moSlider(Controls[6]).MySlider) $ "%";
	return "FAKE";   //FAKE   /ELiZ
}

FString UUT2BotConfigPage::AccDC()
{
	//return DoPerc(moSlider(Controls[7]).MySlider) $ "%";
	return "FAKE";   //FAKE   /ELiZ
}

FString UUT2BotConfigPage::ComDC()
{
	//return DoPerc(moSlider(Controls[8]).MySlider) $ "%";
	return "FAKE";   //FAKE   /ELiZ
}

FString UUT2BotConfigPage::StrDC()
{
	//return DoPerc(moSlider(Controls[9]).MySlider) $ "%";
	return "FAKE";   //FAKE   /ELiZ
}

FString UUT2BotConfigPage::TacDC()
{
	//return DoPerc(moSlider(Controls[10]).MySlider) $ "%";
	return "FAKE";   //FAKE   /ELiZ
}

FString UUT2BotConfigPage::ReaDC()
{
	//return DoPerc(moSlider(Controls[11]).MySlider) $ "%";
	return "FAKE";   //FAKE   /ELiZ
}

void UUT2BotConfigPage::SetDefaults()
{
}

void UUT2BotConfigPage::SliderChange(UGUIComponent* Sender)
{
	/*
	local GUISlider S;
	if (moSlider(Sender) != None)
	{
		S = moSlider(Sender).MySlider;
	}
	if (bIgnoreChange || (S == nullptr))
	{
		return;
	}
	*/
}

void UUT2BotConfigPage::CheckBoxChange(UGUIComponent* Sender)
{
	/*
	if (bIgnoreChange || (Sender != Controls[18]))
	{
		return;
	}
	*/
}

void UUT2BotConfigPage::ComboBoxChange(UGUIComponent* Sender)
{
	/*
	if (bIgnoreChange || (Sender != Controls[13]))
	{
		return;
	}
	*/
}