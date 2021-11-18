// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/Tab_InstantActionBaseRules/Tab_InstantActionBaseRules.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"
#include "AA29/Object/GUI/GUIComponent/GUISlider/GUISlider.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moCheckBox/moCheckBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moNumericEdit/moNumericEdit.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"

UTab_InstantActionBaseRules::UTab_InstantActionBaseRules()
{
	UGUISlider* IARulesGameSpeedSlider = NewObject<UGUISlider>(UGUISlider::StaticClass());
	IARulesGameSpeedSlider->MinValue = 50;
	IARulesGameSpeedSlider->MaxValue = 200;
	IARulesGameSpeedSlider->Hint = "This option controls how fast the game will be played.";
	IARulesGameSpeedSlider->WinTop = 0.097552;
	IARulesGameSpeedSlider->WinLeft = 0.375;
	IARulesGameSpeedSlider->WinWidth = 0.25;
	//IARulesGameSpeedSlider->OnClick=IARulesGameSpeedSlider.InternalOnClick;
	//IARulesGameSpeedSlider->OnMousePressed=IARulesGameSpeedSlider.InternalOnMousePressed;
	//IARulesGameSpeedSlider->OnMouseRelease=IARulesGameSpeedSlider.InternalOnMouseRelease;
	//IARulesGameSpeedSlider->OnKeyEvent=IARulesGameSpeedSlider.InternalOnKeyEvent;
	//IARulesGameSpeedSlider->OnCapturedMouseMove=IARulesGameSpeedSlider.InternalCapturedMouseMove;
	UGUISlider* IARulesFriendlyFireSlider = NewObject<UGUISlider>(UGUISlider::StaticClass());
	IARulesFriendlyFireSlider->MaxValue = 200;
	IARulesFriendlyFireSlider->Hint = "This option controls how much damage you do to teammates.";
	IARulesFriendlyFireSlider->WinTop = 0.6;
	IARulesFriendlyFireSlider->WinLeft = 0.05;
	IARulesFriendlyFireSlider->WinWidth = 0.4;
	IARulesFriendlyFireSlider->WinHeight = 0.04;
	//IARulesFriendlyFireSlider->OnClick=IARulesFriendlyFireSlider.InternalOnClick;
	//IARulesFriendlyFireSlider->OnMousePressed=IARulesFriendlyFireSlider.InternalOnMousePressed;
	//IARulesFriendlyFireSlider->OnMouseRelease=IARulesFriendlyFireSlider.InternalOnMouseRelease;
	//IARulesFriendlyFireSlider->OnKeyEvent=IARulesFriendlyFireSlider.InternalOnKeyEvent;
	//IARulesFriendlyFireSlider->OnCapturedMouseMove=IARulesFriendlyFireSlider.InternalCapturedMouseMove;
	UmoCheckBox* IARulesBrightSkins = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	IARulesBrightSkins->ComponentJustification = EeTextAlign::TXTA_Left;
	IARulesBrightSkins->CaptionWidth = 0.925;
	IARulesBrightSkins->Caption = "Bright Skins";
	//IARulesBrightSkins->OnCreateComponent=IARulesBrightSkins.InternalOnCreateComponent;
	IARulesBrightSkins->Hint = "When selected, the server will cause the skins to be brighter than usual.";
	IARulesBrightSkins->WinTop = 0.479585;
	IARulesBrightSkins->WinLeft = 0.048242;
	IARulesBrightSkins->WinWidth = 0.390626;
	IARulesBrightSkins->WinHeight = 0.04;
	//IARulesBrightSkins->OnChange=Tab_InstantActionBaseRules.BrightOnchange;
	UmoCheckBox* IARulesAllowWeaponThrow = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	IARulesAllowWeaponThrow->ComponentJustification = EeTextAlign::TXTA_Left;
	IARulesAllowWeaponThrow->CaptionWidth = 0.9;
	IARulesAllowWeaponThrow->Caption = "Allow Weapon Throwing";
	//IARulesAllowWeaponThrow->OnCreateComponent=IARulesAllowWeaponThrow.InternalOnCreateComponent;
	IARulesAllowWeaponThrow->Hint = "When selected, a player will have the ability to throw out his current weapon.";
	IARulesAllowWeaponThrow->WinTop = 0.370833;
	IARulesAllowWeaponThrow->WinLeft = 0.05;
	IARulesAllowWeaponThrow->WinWidth = 0.4;
	IARulesAllowWeaponThrow->WinHeight = 0.04;
	UmoNumericEdit* IARulesMaxLives = NewObject<UmoNumericEdit>(UmoNumericEdit::StaticClass());
	IARulesMaxLives->MinValue = 0;
	IARulesMaxLives->MaxValue = 255;
	IARulesMaxLives->ComponentJustification = EeTextAlign::TXTA_Left;
	IARulesMaxLives->CaptionWidth = 0.7;
	IARulesMaxLives->Caption = "Max Lives";
	//IARulesMaxLives->OnCreateComponent=IARulesMaxLives.InternalOnCreateComponent;
	IARulesMaxLives->Hint = "If this value is not 0, you will only respawn this many times.";
	IARulesMaxLives->WinTop = 0.547656;
	IARulesMaxLives->WinLeft = 0.553906;
	IARulesMaxLives->WinWidth = 0.4;
	IARulesMaxLives->WinHeight = 0.04;
	UmoNumericEdit* IARulesTimeLimit = NewObject<UmoNumericEdit>(UmoNumericEdit::StaticClass());
	IARulesTimeLimit->MinValue = 0;
	IARulesTimeLimit->MaxValue = 3600;
	IARulesTimeLimit->ComponentJustification = EeTextAlign::TXTA_Left;
	IARulesTimeLimit->CaptionWidth = 0.7;
	IARulesTimeLimit->Caption = "Time Limit";
	//IARulesTimeLimit->OnCreateComponent=IARulesTimeLimit.InternalOnCreateComponent;
	IARulesTimeLimit->Hint = "The game will end after this many minutes of play.";
	IARulesTimeLimit->WinTop = 0.428125;
	IARulesTimeLimit->WinLeft = 0.553906;
	IARulesTimeLimit->WinWidth = 0.4;
	IARulesTimeLimit->WinHeight = 0.04;
	UmoNumericEdit* IARulesGoalScore = NewObject<UmoNumericEdit>(UmoNumericEdit::StaticClass());
	IARulesGoalScore->MinValue = 0;
	IARulesGoalScore->MaxValue = 99;
	IARulesGoalScore->ComponentJustification = EeTextAlign::TXTA_Left;
	IARulesGoalScore->CaptionWidth = 0.7;
	IARulesGoalScore->Caption = "Goal Score";
	//IARulesGoalScore->OnCreateComponent=IARulesGoalScore.InternalOnCreateComponent;
	IARulesGoalScore->Hint = "The game will end when this threshold is met.";
	IARulesGoalScore->WinTop = 0.315104;
	IARulesGoalScore->WinLeft = 0.553906;
	IARulesGoalScore->WinWidth = 0.4;
	IARulesGoalScore->WinHeight = 0.04;
	UmoCheckBox* IARulesTranslocator = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	IARulesTranslocator->ComponentJustification = EeTextAlign::TXTA_Left;
	IARulesTranslocator->CaptionWidth = 0.9;
	IARulesTranslocator->Caption = "Include Translocator";
	//IARulesTranslocator->OnCreateComponent=IARulesTranslocator.InternalOnCreateComponent;
	IARulesTranslocator->Hint = "Enable this option to allow Translocators.";
	IARulesTranslocator->WinTop = 0.428125;
	IARulesTranslocator->WinLeft = 0.05;
	IARulesTranslocator->WinWidth = 0.4;
	IARulesTranslocator->WinHeight = 0.04;
	UmoCheckBox* IARulesWeaponStay = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	IARulesWeaponStay->ComponentJustification = EeTextAlign::TXTA_Left;
	IARulesWeaponStay->CaptionWidth = 0.9;
	IARulesWeaponStay->Caption = "Weapon Stay";
	//IARulesWeaponStay->OnCreateComponent=IARulesWeaponStay.InternalOnCreateComponent;
	IARulesWeaponStay->Hint = "When enabled, weapons will always be available for pickup.";
	IARulesWeaponStay->WinTop = 0.315104;
	IARulesWeaponStay->WinLeft = 0.05;
	IARulesWeaponStay->WinWidth = 0.4;
	IARulesWeaponStay->WinHeight = 0.04;
	UGUILabel* IARulesFriendlyFireLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	IARulesFriendlyFireLabel->Caption = "FriendlyFire";
	IARulesFriendlyFireLabel->TextAlign = ETextAlign::TXTA_Center;
	IARulesFriendlyFireLabel->TextColor = FColor(255, 255, 255, 255);
	IARulesFriendlyFireLabel->StyleName = "TextLabel";
	IARulesFriendlyFireLabel->WinTop = 0.540833;
	IARulesFriendlyFireLabel->WinLeft = 0.05;
	IARulesFriendlyFireLabel->WinWidth = 0.4;
	IARulesFriendlyFireLabel->WinHeight = 0.04;
	UGUILabel* IARulesGameSpeedLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	IARulesGameSpeedLabel->Caption = "Game Speed";
	IARulesGameSpeedLabel->TextAlign = ETextAlign::TXTA_Center;
	IARulesGameSpeedLabel->TextColor = FColor(255, 255, 255, 255);
	IARulesGameSpeedLabel->StyleName = "TextLabel";
	IARulesGameSpeedLabel->WinTop = 0.041406;
	IARulesGameSpeedLabel->WinLeft = 0.25;
	IARulesGameSpeedLabel->WinWidth = 0.5;
	IARulesGameSpeedLabel->WinHeight = 32;
	UGUIImage* IARulesBK3 = NewObject<UGUIImage>(UGUIImage::StaticClass());
	//IARulesBK3->Image=Texture'InterfaceContent.Menu.BorderBoxD';
	IARulesBK3->ImageColor = FColor(255, 255, 255, 160);
	IARulesBK3->ImageStyle = EImgStyle::ISTY_Stretched;
	IARulesBK3->WinTop = 0.239531;
	IARulesBK3->WinLeft = 0.019531;
	IARulesBK3->WinWidth = 0.469219;
	IARulesBK3->WinHeight = 0.487071;
	UGUIImage* IARulesBK2 = NewObject<UGUIImage>(UGUIImage::StaticClass());
	//IARulesBK2->Image=Texture'InterfaceContent.Menu.BorderBoxD';
	IARulesBK2->ImageColor = FColor(255, 255, 255, 160);
	IARulesBK2->ImageStyle = EImgStyle::ISTY_Stretched;
	IARulesBK2->WinTop = 0.239531;
	IARulesBK2->WinLeft = 0.509922;
	IARulesBK2->WinWidth = 0.469219;
	IARulesBK2->WinHeight = 0.487071;
	UGUIImage* IARulesBK1 = NewObject<UGUIImage>(UGUIImage::StaticClass());
	//IARulesBK1->Image=Texture'InterfaceContent.Menu.BorderBoxD';
	IARulesBK1->ImageColor = FColor(255, 255, 255, 160);
	IARulesBK1->ImageStyle = EImgStyle::ISTY_Stretched;
	IARulesBK1->WinTop = 0.024687;
	IARulesBK1->WinLeft = 0.021641;
	IARulesBK1->WinWidth = 0.9575;
	IARulesBK1->WinHeight = 0.156016;

	bLastWeaponThrowing = true;
	PercentText = "percent";
	Controls = { IARulesBK1,IARulesBK2,IARulesBK3,IARulesGameSpeedLabel,IARulesGameSpeedSlider,IARulesWeaponStay,IARulesTranslocator,IARulesFriendlyFireLabel,IARulesFriendlyFireSlider,IARulesGoalScore,IARulesTimeLimit,IARulesMaxLives,IARulesAllowWeaponThrow,IARulesBrightSkins };
	WinTop = 0.15;
	WinHeight = 0.77;
}


void UTab_InstantActionBaseRules::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	int32 NewGameSpeed = 0;
	Super::InitComponent(MyController, MyOwner);
	MyGameSpeed = GUISlider(Controls[4]);
	MyWeaponStay = moCheckBox(Controls[5]);
	MyTranslocator = moCheckBox(Controls[6]);
	MyFriendlyFire = GUISlider(Controls[8]);
	MyGoalScore = moNumericEdit(Controls[9]);
	MyTimeLimit = moNumericEdit(Controls[10]);
	MyMaxLives = moNumericEdit(Controls[11]);
	NewGameSpeed = int((LastGameSpeed * float(100)));
	MyGameSpeed.Value = float(Clamp(NewGameSpeed, 50, 200));
	MyWeaponStay.Checked(LastWeaponStay);
	MyFriendlyFire.Value = (LastFriendlyFire * float(100));
	MyTranslocator.Checked(LastTranslocator);
	MyGoalScore.SetValue(LastGoalScore);
	MyTimeLimit.SetValue(LastTimeLimit);
	MyMaxLives.SetValue(LastMaxLives);
	MyGameSpeed.__OnDrawCaption__Delegate = InternalGameSpeedDraw;
	MyFriendlyFire.__OnDrawCaption__Delegate = InternalFriendlyFireDraw;
	Controls[4].FriendlyLabel = GUILabel(Controls[3]);
	Controls[8].FriendlyLabel = GUILabel(Controls[7]);
	MyWeaponThrowing = moCheckBox(Controls[12]);
	MyWeaponThrowing.Checked(bLastWeaponThrowing);
	*/
}

FString UTab_InstantActionBaseRules::Play()
{
	FString URL = "";
	/*
	LastGameSpeed = (MyGameSpeed.Value / float(100));
	LastWeaponStay = MyWeaponStay.IsChecked();
	LastTranslocator = MyTranslocator.IsChecked();
	LastFriendlyFire = (MyFriendlyFire.Value / float(100));
	LastGoalScore = MyGoalScore.GetValue();
	LastTimeLimit = MyTimeLimit.GetValue();
	LastMaxLives = MyMaxLives.GetValue();
	bLastWeaponThrowing = MyWeaponThrowing.IsChecked();
	SaveConfig();
	URL = "?GameSpeed=" $ string(LastGameSpeed) $ "?WeaponStay=" $ string(LastWeaponStay) $ "?Translocator=" $ string(LastTranslocator) $ "?FriendlyFireScale=" $ string(LastFriendlyFire);
	URL = URL $ "?GoalScore=" $ string(LastGoalScore) $ "?TimeLimit=" $ string(LastTimeLimit) $ "?MaxLives=" $ string(LastMaxLives);
	if (bLastWeaponThrowing)
	{
		URL = URL $ "?AllowThrowing=" $ string(bLastWeaponThrowing);
	}
	*/
	return URL;
}

FString UTab_InstantActionBaseRules::InternalGameSpeedDraw()
{
	//return "(" $ string(int(MyGameSpeed.Value)) @ PercentText $ ")";
	return "FAKE";   //FAKE   /ELiZ
}

FString UTab_InstantActionBaseRules::InternalFriendlyFireDraw()
{
	//return "(" $ string(int(MyFriendlyFire.Value)) @ PercentText $ ")";
	return "FAKE";   //FAKE   /ELiZ
}

void UTab_InstantActionBaseRules::BrightOnchange(UGUIComponent* Sender)
{
}