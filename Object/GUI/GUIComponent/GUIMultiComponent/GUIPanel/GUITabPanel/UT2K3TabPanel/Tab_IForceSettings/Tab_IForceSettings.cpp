// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/Tab_IForceSettings/Tab_IForceSettings.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moCheckBox/moCheckBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moFloatEdit/moFloatEdit.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"

UTab_IForceSettings::UTab_IForceSettings()
{
	UmoCheckBox* InputMouseLag = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	InputMouseLag->ComponentJustification = EeTextAlign::TXTA_Left;
	InputMouseLag->CaptionWidth=0.9;
	InputMouseLag->Caption="Reduce Mouse Lag";
	InputMouseLag->ComponentClassName="xinterface.GUICheckBoxButton";
	//InputMouseLag->OnCreateComponent=InputMouseLag.InternalOnCreateComponent;
	InputMouseLag->Hint="Enable this option will reduce the amount of lag in your mouse.";
	InputMouseLag->WinTop=0.509791;
	InputMouseLag->WinLeft=0.060938;
	InputMouseLag->WinWidth=0.3;
	InputMouseLag->WinHeight=0.04;
	UmoFloatEdit* InputDodgeTime = NewObject<UmoFloatEdit>(UmoFloatEdit::StaticClass());
	InputDodgeTime->MinValue=0;
	InputDodgeTime->MaxValue=1;
	InputDodgeTime->Step=0.05;
	InputDodgeTime->ComponentJustification = EeTextAlign::TXTA_Left;
	InputDodgeTime->CaptionWidth=0.725;
	InputDodgeTime->Caption="Dodge Double-Click Time";
	//InputDodgeTime->OnCreateComponent=InputDodgeTime.InternalOnCreateComponent;
	InputDodgeTime->Hint="Determines how fast you have to double click to dodge";
	InputDodgeTime->WinTop=0.582083;
	InputDodgeTime->WinLeft=0.472266;
	InputDodgeTime->WinWidth=0.421875;
	UmoFloatEdit* InputMouseAccel = NewObject<UmoFloatEdit>(UmoFloatEdit::StaticClass());
	InputMouseAccel->MinValue=0;
	InputMouseAccel->MaxValue=100;
	InputMouseAccel->Step=5;
	InputMouseAccel->ComponentJustification = EeTextAlign::TXTA_Left;
	InputMouseAccel->CaptionWidth=0.725;
	InputMouseAccel->Caption="Mouse Accel. Threshold";
	//InputMouseAccel->OnCreateComponent=InputMouseAccel.InternalOnCreateComponent;
	InputMouseAccel->Hint="Adjust to determine the amount of movement needed before acceleration is applied";
	InputMouseAccel->WinTop=0.405;
	InputMouseAccel->WinLeft=0.472266;
	InputMouseAccel->WinWidth=0.421875;
	UmoFloatEdit* InputMouseSmoothStr = NewObject<UmoFloatEdit>(UmoFloatEdit::StaticClass());
	InputMouseSmoothStr->MinValue=0;
	InputMouseSmoothStr->MaxValue=1;
	InputMouseSmoothStr->Step=0.05;
	InputMouseSmoothStr->ComponentJustification = EeTextAlign::TXTA_Left;
	InputMouseSmoothStr->CaptionWidth=0.725;
	InputMouseSmoothStr->Caption="Mouse Smoothing Strength";
	//InputMouseSmoothStr->OnCreateComponent=InputMouseSmoothStr.InternalOnCreateComponent;
	InputMouseSmoothStr->Hint="Adjust the amount of smoothing that is applied to mouse movements";
	InputMouseSmoothStr->WinTop=0.324167;
	InputMouseSmoothStr->WinLeft=0.472266;
	InputMouseSmoothStr->WinWidth=0.421875;
	UmoCheckBox* InputIFGUIEffects = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	InputIFGUIEffects->ComponentJustification = EeTextAlign::TXTA_Left;
	InputIFGUIEffects->CaptionWidth=0.9;
	InputIFGUIEffects->Caption="GUI Effects";
	InputIFGUIEffects->ComponentClassName="xinterface.GUICheckBoxButton";
	//InputIFGUIEffects->OnCreateComponent=InputIFGUIEffects.InternalOnCreateComponent;
	InputIFGUIEffects->Hint="Turn this option On/Off to feel the GUI.";
	InputIFGUIEffects->WinTop=0.933;
	InputIFGUIEffects->WinLeft=0.563867;
	InputIFGUIEffects->WinWidth=0.3;
	InputIFGUIEffects->WinHeight=0.04;
	UmoCheckBox* InputIFDamageEffects = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	InputIFDamageEffects->ComponentJustification = EeTextAlign::TXTA_Left;
	InputIFDamageEffects->CaptionWidth=0.9;
	InputIFDamageEffects->Caption="Damage Effects";
	InputIFDamageEffects->ComponentClassName="xinterface.GUICheckBoxButton";
	//InputIFDamageEffects->OnCreateComponent=InputIFDamageEffects.InternalOnCreateComponent;
	InputIFDamageEffects->Hint="Turn this option On/Off to feel the damage you take.";
	InputIFDamageEffects->WinTop=0.852;
	InputIFDamageEffects->WinLeft=0.563867;
	InputIFDamageEffects->WinWidth=0.3;
	InputIFDamageEffects->WinHeight=0.04;
	UmoCheckBox* InputIFPickupEffects = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	InputIFPickupEffects->ComponentJustification = EeTextAlign::TXTA_Left;
	InputIFPickupEffects->CaptionWidth=0.9;
	InputIFPickupEffects->Caption="Pickup Effects";
	InputIFPickupEffects->ComponentClassName="xinterface.GUICheckBoxButton";
	//InputIFPickupEffects->OnCreateComponent=InputIFPickupEffects.InternalOnCreateComponent;
	InputIFPickupEffects->Hint="Turn this option On/Off to feel the items you pick up.";
	InputIFPickupEffects->WinTop=0.933;
	InputIFPickupEffects->WinLeft=0.1;
	InputIFPickupEffects->WinWidth=0.3;
	InputIFPickupEffects->WinHeight=0.04;
	UmoCheckBox* InputIFWeaponEffects = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	InputIFWeaponEffects->ComponentJustification = EeTextAlign::TXTA_Left;
	InputIFWeaponEffects->CaptionWidth=0.9;
	InputIFWeaponEffects->Caption="Weapon Effects";
	InputIFWeaponEffects->ComponentClassName="xinterface.GUICheckBoxButton";
	//InputIFWeaponEffects->OnCreateComponent=InputIFWeaponEffects.InternalOnCreateComponent;
	InputIFWeaponEffects->Hint="Turn this option On/Off to feel the weapons you fire.";
	InputIFWeaponEffects->WinTop=0.852;
	InputIFWeaponEffects->WinLeft=0.1;
	InputIFWeaponEffects->WinWidth=0.3;
	InputIFWeaponEffects->WinHeight=0.04;
	UmoFloatEdit* InputMenuSensitivity = NewObject<UmoFloatEdit>(UmoFloatEdit::StaticClass());
	InputMenuSensitivity->MinValue=1;
	InputMenuSensitivity->MaxValue=6;
	InputMenuSensitivity->Step=0.25;
	InputMenuSensitivity->ComponentJustification = EeTextAlign::TXTA_Left;
	InputMenuSensitivity->CaptionWidth=0.725;
	InputMenuSensitivity->Caption="Mouse Sensitivity (Menus)";
	//InputMenuSensitivity->OnCreateComponent=InputMenuSensitivity.InternalOnCreateComponent;
	InputMenuSensitivity->Hint="Adjust mouse speed within the menus";
	InputMenuSensitivity->WinTop=0.188698;
	InputMenuSensitivity->WinLeft=0.472266;
	InputMenuSensitivity->WinWidth=0.421875;
	UmoFloatEdit* InputMouseSensitivity = NewObject<UmoFloatEdit>(UmoFloatEdit::StaticClass());
	InputMouseSensitivity->MinValue=1;
	InputMouseSensitivity->MaxValue=25;
	InputMouseSensitivity->Step=0.25;
	InputMouseSensitivity->ComponentJustification = EeTextAlign::TXTA_Left;
	InputMouseSensitivity->CaptionWidth=0.725;
	InputMouseSensitivity->Caption="Mouse Sensitivity (In Game)";
	//InputMouseSensitivity->OnCreateComponent=InputMouseSensitivity.InternalOnCreateComponent;
	InputMouseSensitivity->Hint="Adjust mouse sensitivity";
	InputMouseSensitivity->WinTop=0.105365;
	InputMouseSensitivity->WinLeft=0.472266;
	InputMouseSensitivity->WinWidth=0.421875;
	UmoCheckBox* InputUseJoystick = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	InputUseJoystick->ComponentJustification = EeTextAlign::TXTA_Left;
	InputUseJoystick->CaptionWidth=0.9;
	InputUseJoystick->Caption="Enable Joystick";
	InputUseJoystick->ComponentClassName="xinterface.GUICheckBoxButton";
	//InputUseJoystick->OnCreateComponent=InputUseJoystick.InternalOnCreateComponent;
	InputUseJoystick->Hint="Enable this option to enable joystick support.";
	InputUseJoystick->WinTop=0.651302;
	InputUseJoystick->WinLeft=0.060938;
	InputUseJoystick->WinWidth=0.3;
	InputUseJoystick->WinHeight=0.04;
	UmoCheckBox* InputMouseSmoothing = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	InputMouseSmoothing->ComponentJustification = EeTextAlign::TXTA_Left;
	InputMouseSmoothing->CaptionWidth=0.9;
	InputMouseSmoothing->Caption="Mouse Smoothing";
	InputMouseSmoothing->ComponentClassName="xinterface.GUICheckBoxButton";
	//InputMouseSmoothing->OnCreateComponent=InputMouseSmoothing.InternalOnCreateComponent;
	InputMouseSmoothing->Hint="Enable this option to automatically smooth out movements in your mouse.";
	InputMouseSmoothing->WinTop=0.416041;
	InputMouseSmoothing->WinLeft=0.060938;
	InputMouseSmoothing->WinWidth=0.3;
	InputMouseSmoothing->WinHeight=0.04;
	UmoCheckBox* InputInvertMouse = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	InputInvertMouse->ComponentJustification = EeTextAlign::TXTA_Left;
	InputInvertMouse->CaptionWidth=0.9;
	InputInvertMouse->Caption="Invert Mouse";
	InputInvertMouse->ComponentClassName="xinterface.GUICheckBoxButton";
	//InputInvertMouse->OnCreateComponent=InputInvertMouse.InternalOnCreateComponent;
	InputInvertMouse->Hint="When enabled, the Y axis of your mouse will be inverted.";
	InputInvertMouse->WinTop=0.321927;
	InputInvertMouse->WinLeft=0.060938;
	InputInvertMouse->WinWidth=0.3;
	InputInvertMouse->WinHeight=0.04;
	UmoCheckBox* InputAutoSlope = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	InputAutoSlope->ComponentJustification = EeTextAlign::TXTA_Left;
	InputAutoSlope->CaptionWidth=0.9;
	InputAutoSlope->Caption="Auto Slope";
	InputAutoSlope->ComponentClassName="xinterface.GUICheckBoxButton";
	//InputAutoSlope->OnCreateComponent=InputAutoSlope.InternalOnCreateComponent;
	InputAutoSlope->Hint="When enabled, your view will automatically pitch up/down when on a slope.";
	InputAutoSlope->WinTop=0.175989;
	InputAutoSlope->WinLeft=0.060937;
	InputAutoSlope->WinWidth=0.3;
	InputAutoSlope->WinHeight=0.04;
	UmoCheckBox* InputAutoAim = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	InputAutoAim->ComponentJustification = EeTextAlign::TXTA_Left;
	InputAutoAim->CaptionWidth=0.9;
	InputAutoAim->Caption="Auto Aim";
	InputAutoAim->ComponentClassName="xinterface.GUICheckBoxButton";
	//InputAutoAim->OnCreateComponent=InputAutoAim.InternalOnCreateComponent;
	InputAutoAim->Hint="Enabling this option will activate computer-assisted aiming in single player games.";
	InputAutoAim->WinTop=0.057396;
	InputAutoAim->WinLeft=0.060938;
	InputAutoAim->WinWidth=0.3;
	InputAutoAim->WinHeight=0.04;
	InputAutoAim->bVisible=false;
	UGUIImage* InputBK1 = NewObject<UGUIImage>(UGUIImage::StaticClass());
	//InputBK1->Image=Texture'InterfaceContent.Menu.BorderBoxD';
	InputBK1->ImageColor=FColor(255, 255, 255, 160);
	InputBK1->ImageStyle = EImgStyle::ISTY_Stretched;
	InputBK1->WinTop=0.10651;
	InputBK1->WinLeft=0.021641;
	InputBK1->WinWidth=0.381328;
	InputBK1->WinHeight=0.636485;
	UGUILabel* InputSliderLabel1 = NewObject<UGUILabel>(UGUILabel::StaticClass());
	InputSliderLabel1->Caption="Mouse Sensitivity (In Game)";
	InputSliderLabel1->TextAlign = ETextAlign::TXTA_Center;
	InputSliderLabel1->TextColor=FColor(255, 255, 255, 255);
	InputSliderLabel1->WinTop=0.126042;
	InputSliderLabel1->WinLeft=0.543945;
	InputSliderLabel1->WinWidth=0.332422;
	InputSliderLabel1->WinHeight=32;
	InputSliderLabel1->bVisible=false;
	UGUILabel* InputSliderLabel2 = NewObject<UGUILabel>(UGUILabel::StaticClass());
	InputSliderLabel2->Caption="Mouse Sensitivity (Menus)";
	InputSliderLabel2->TextAlign = ETextAlign::TXTA_Center;
	InputSliderLabel2->TextColor=FColor(255, 255, 255, 255);
	InputSliderLabel2->WinTop=0.327865;
	InputSliderLabel2->WinLeft=0.548828;
	InputSliderLabel2->WinWidth=0.308594;
	InputSliderLabel2->WinHeight=32;
	InputSliderLabel2->bVisible=false;
	UGUIImage* InputBK2 = NewObject<UGUIImage>(UGUIImage::StaticClass());
	//InputBK2->Image=Texture'InterfaceContent.Menu.BorderBoxD';
	InputBK2->ImageColor=FColor(255, 255, 255, 160);
	InputBK2->ImageStyle = EImgStyle::ISTY_Stretched;
	InputBK2->WinTop=0.76;
	InputBK2->WinLeft=0.021641;
	InputBK2->WinWidth=0.9575;
	InputBK2->WinHeight=0.240977;
	UGUILabel* InputIForceLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	InputIForceLabel->Caption="TouchSense Force Feedback";
	InputIForceLabel->TextAlign = ETextAlign::TXTA_Center;
	InputIForceLabel->TextColor=FColor(255, 255, 255, 255);
	InputIForceLabel->WinTop=0.777;
	InputIForceLabel->WinLeft=0.023437;
	InputIForceLabel->WinWidth=0.95625;
	InputIForceLabel->WinHeight=32;

	Controls = { InputBK1,InputAutoAim,InputAutoSlope,InputInvertMouse,InputMouseSmoothing,InputUseJoystick,InputSliderLabel1,InputMouseSensitivity,InputSliderLabel2,InputMenuSensitivity,InputBK2,InputIFWeaponEffects,InputIFPickupEffects,InputIFDamageEffects,InputIFGUIEffects,InputIForceLabel,InputMouseSmoothStr,InputMouseAccel,InputDodgeTime,InputMouseLag };
	WinTop = 0.15;
	WinHeight = 0.74;
}

void UTab_IForceSettings::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	int32 i = 0;
	FString S = "";
	Super::InitComponent(MyController, MyOwner);
	for (i = 0; i < Controls.Length; i++)
	{
		Controls[i].__OnChange__Delegate = InternalOnChange;
	}
	AutoAim = moCheckBox(Controls[1]);
	AutoAim.Checked((PlayerOwner().Level.Game.AutoAim == 1));
	AutoSlope = moCheckBox(Controls[2]);
	AutoSlope.Checked(PlayerOwner().bSnapToLevel);
	InvertMouse = moCheckBox(Controls[3]);
	InvertMouse.Checked(Class'PlayerInput'.Default.bInvertMouse);
	MouseSmooth = moCheckBox(Controls[4]);
	MouseSmooth.Checked((Class'PlayerInput'.Default.MouseSmoothingMode > 0));
	UseJoystick = moCheckBox(Controls[5]);
	UseJoystick.Checked(bool(PlayerOwner().ConsoleCommand("get ini:Engine.Engine.ViewportManager UseJoystick")));
	MouseLag = moCheckBox(Controls[19]);
	S = PlayerOwner().ConsoleCommand("get ini:Engine.Engine.RenderDevice ReduceMouseLag");
	MouseLag.Checked(bool(S));
	MouseSens = moFloatEdit(Controls[7]);
	MouseSens.SetValue(Class'PlayerInput'.Default.MouseSensitivity);
	MenuSens = moFloatEdit(Controls[9]);
	MenuSens.SetValue(Controller.MenuMouseSens);
	ifWeapon = moCheckBox(Controls[11]);
	ifWeapon.Checked(Class'PlayerController'.Default.bEnableWeaponForceFeedback);
	ifPickup = moCheckBox(Controls[12]);
	ifPickup.Checked(Class'PlayerController'.Default.bEnablePickupForceFeedback);
	ifDamage = moCheckBox(Controls[13]);
	ifDamage.Checked(Class'PlayerController'.Default.bEnableDamageForceFeedback);
	ifGUI = moCheckBox(Controls[14]);
	ifGUI.Checked(Class'PlayerController'.Default.bEnableGUIForceFeedback);
	MouseSmoothStr = moFloatEdit(Controls[16]);
	MouseSmoothStr.SetValue(Class'PlayerInput'.Default.MouseSmoothingStrength);
	MouseThreshold = moFloatEdit(Controls[17]);
	MouseThreshold.SetValue(Class'PlayerInput'.Default.MouseAccelThreshold);
	DoubleClick = moFloatEdit(Controls[18]);
	DoubleClick.SetValue(Class'PlayerInput'.Default.DoubleClickTime);
	*/
}

void UTab_IForceSettings::InternalOnChange(UGUIComponent* Sender)
{
	/*
	if (!Controller.bCurMenuInitialized)
	{
		return;
	}
	if ((PlayerOwner().Level.Game != None) && (Sender == AutoAim))
	{
		if (AutoAim.IsChecked())
		{
			PlayerOwner().Level.Game.AutoAim = 1;
		}
		else
		{
			PlayerOwner().Level.Game.AutoAim = 0;
		}
		PlayerOwner().Level.Game.SaveConfig();
	}
	if (Sender == MouseLag)
	{
		PlayerOwner().ConsoleCommand("set ini:Engine.Engine.RenderDevice ReduceMouseLag " $ string(MouseLag.IsChecked()));
	}
	if (Sender == AutoSlope)
	{
		PlayerOwner().bSnapToLevel = AutoSlope.IsChecked();
		PlayerOwner().SaveConfig();
	}
	if (Sender == InvertMouse)
	{
		PlayerOwner().ConsoleCommand("set PlayerInput bInvertMouse " $ string(InvertMouse.IsChecked()));
		Class'PlayerInput'.Default.bInvertMouse = InvertMouse.IsChecked();
		Class'PlayerInput'.StaticSaveConfig();
	}
	if (Sender == MouseSmooth)
	{
		if (MouseSmooth.IsChecked())
		{
			Class'PlayerInput'.Default.MouseSmoothingMode = 1;
		}
		else
		{
			Class'PlayerInput'.Default.MouseSmoothingMode = 0;
		}
	}
	if (Sender == UseJoystick)
	{
		PlayerOwner().ConsoleCommand("set ini:Engine.Engine.ViewportManager UseJoystick" @ string(UseJoystick.IsChecked()));
	}
	if (Sender == MouseSens)
	{
		Class'PlayerInput'.Default.MouseSensitivity = MouseSens.GetValue();
		PlayerOwner().ConsoleCommand("set PlayerInput MouseSensitivity " $ string(MouseSens.GetValue()));
		Class'PlayerInput'.StaticSaveConfig();
	}
	if (Sender == MouseSmoothStr)
	{
		Class'PlayerInput'.Default.MouseSmoothingStrength = MouseSmoothStr.GetValue();
		PlayerOwner().ConsoleCommand("set PlayerInput MouseSmoothingStrength " $ string(MouseSmoothStr.GetValue()));
		Class'PlayerInput'.StaticSaveConfig();
	}
	if (Sender == MouseThreshold)
	{
		Class'PlayerInput'.Default.MouseAccelThreshold = MouseThreshold.GetValue();
		PlayerOwner().ConsoleCommand("set PlayerInput MouseAccelThreshold " $ string(MouseThreshold.GetValue()));
		Class'PlayerInput'.StaticSaveConfig();
	}
	if (Sender == DoubleClick)
	{
		Class'PlayerInput'.Default.DoubleClickTime = DoubleClick.GetValue();
		PlayerOwner().ConsoleCommand("set PlayerInput DoubleClickTime " $ string(DoubleClick.GetValue()));
		Class'PlayerInput'.StaticSaveConfig();
	}
	if (Sender == MenuSens)
	{
		Controller.MenuMouseSens = MenuSens.GetValue();
		Controller.SaveConfig();
	}
	if (Sender == ifWeapon)
	{
		PlayerOwner().bEnableWeaponForceFeedback = ifWeapon.IsChecked();
		PlayerOwner().bForceFeedbackSupported = PlayerOwner().ForceFeedbackSupported((((ifWeapon.IsChecked() || ifPickup.IsChecked()) || ifDamage.IsChecked()) || ifGUI.IsChecked()));
		Class'PlayerController'.SaveConfig();
	}
	if (Sender == ifPickup)
	{
		PlayerOwner().bEnablePickupForceFeedback = ifPickup.IsChecked();
		PlayerOwner().bForceFeedbackSupported = PlayerOwner().ForceFeedbackSupported((((ifWeapon.IsChecked() || ifPickup.IsChecked()) || ifDamage.IsChecked()) || ifGUI.IsChecked()));
		Class'PlayerController'.SaveConfig();
	}
	if (Sender == ifDamage)
	{
		PlayerOwner().bEnableDamageForceFeedback = ifDamage.IsChecked();
		PlayerOwner().bForceFeedbackSupported = PlayerOwner().ForceFeedbackSupported((((ifWeapon.IsChecked() || ifPickup.IsChecked()) || ifDamage.IsChecked()) || ifGUI.IsChecked()));
		Class'PlayerController'.SaveConfig();
	}
	if (Sender == ifGUI)
	{
		PlayerOwner().bEnableGUIForceFeedback = ifGUI.IsChecked();
		PlayerOwner().bForceFeedbackSupported = PlayerOwner().ForceFeedbackSupported((((ifWeapon.IsChecked() || ifPickup.IsChecked()) || ifDamage.IsChecked()) || ifGUI.IsChecked()));
		Class'PlayerController'.SaveConfig();
	}
	*/
}