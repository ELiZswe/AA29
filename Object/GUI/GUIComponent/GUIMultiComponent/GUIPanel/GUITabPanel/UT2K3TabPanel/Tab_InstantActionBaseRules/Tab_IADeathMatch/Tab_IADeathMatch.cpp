// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/Tab_InstantActionBaseRules/Tab_IADeathMatch/Tab_IADeathMatch.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moCheckBox/moCheckBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"

UTab_IADeathMatch::UTab_IADeathMatch()
{
	UmoCheckBox* IARulesAutoAdjustSkill = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	IARulesAutoAdjustSkill->ComponentJustification = EeTextAlign::TXTA_Left;
	IARulesAutoAdjustSkill->CaptionWidth = 0.9;
	IARulesAutoAdjustSkill->Caption = "Auto-Adjust Skill";
	//IARulesAutoAdjustSkill->OnCreateComponent=IARulesAutoAdjustSkill.InternalOnCreateComponent;
	IARulesAutoAdjustSkill->Hint = "When enabled, bots will adjust their skill to match yours.";
	IARulesAutoAdjustSkill->WinTop = 0.858295;
	IARulesAutoAdjustSkill->WinLeft = 0.375;
	IARulesAutoAdjustSkill->WinWidth = 0.25;
	IARulesAutoAdjustSkill->WinHeight = 0.156016;
	UGUIImage* IARulesBK4 = NewObject<UGUIImage>(UGUIImage::StaticClass());
	//IARulesBK4->Image=Texture'InterfaceContent.Menu.BorderBoxD';
	IARulesBK4->ImageColor = FColor(255, 255, 255, 160);
	IARulesBK4->ImageStyle = EImgStyle::ISTY_Stretched;
	IARulesBK4->WinTop = 0.78543;
	IARulesBK4->WinLeft = 0.021641;
	IARulesBK4->WinWidth = 0.9575;
	IARulesBK4->WinHeight = 0.156016;

	GoalScoreText = "Frag Limit";

	/*
	UTab_InstantActionBaseRules* AAA = NewObject<UTab_InstantActionBaseRules>(UTab_InstantActionBaseRules::StaticClass());
	Controls[0] = AAA->IARulesBK1;
	Controls[1] = AAA.IARulesBK2;
	Controls[2] = AAA.IARulesBK3;
	Controls[3] = AAA.IARulesGameSpeedLabel;
	Controls[4] = AAA.IARulesGameSpeedSlider;
	Controls[5] = AAA.IARulesWeaponStay;
	Controls[6] = AAA.IARulesTranslocator;
	Controls[7] = AAA.IARulesFriendlyFireLabel;
	Controls[8] = AAA.IARulesFriendlyFireSlider;
	Controls[9] = AAA.IARulesGoalScore;
	Controls[10] = AAA.IARulesTimeLimit;
	Controls[11] = AAA.IARulesMaxLives;
	Controls[12] = AAA.IARulesAllowWeaponThrow;
	Controls[13] = AAA->IARulesBrightSkins;
	Controls[14] = IARulesBK4;
	Controls[15] = IARulesAutoAdjustSkill;
	*/
}

void UTab_IADeathMatch::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	Super::InitComponent(MyController, MyOwner);
	MyGoalScore.MyLabel.Caption = GoalScoreText;
	moCheckBox(Controls[15]).Checked(LastAutoAdjustSkill);
	*/
}

FString UTab_IADeathMatch::Play()
{
	/*
	LastAutoAdjustSkill = moCheckBox(Controls[15]).IsChecked();
	SaveConfig();
	return Super::Play() $ "?AutoAdjust=" $ string(LastAutoAdjustSkill);
	*/

	return "FAKE";   //FAKE   /ELiZ
}