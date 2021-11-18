// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/Settings_Tabs/AATab_IForceSettings/AATab_IForceSettings.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moCheckBox/moCheckBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moFloatEdit/moFloatEdit.h"

UAATab_IForceSettings::UAATab_IForceSettings()
{
	
	UGUIButton* ControlBindButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	ControlBindButton->Caption="Configure Controls";
	ControlBindButton->SizingCaption="XXXXXXXXXX";
	ControlBindButton->FontScale = EFontScale::FNS_Small;
	ControlBindButton->Hint="Configure controls and keybinds";
	ControlBindButton->WinTop=0.09;
	ControlBindButton->WinLeft=0.15;
	ControlBindButton->WinWidth=0.2;
	ControlBindButton->WinHeight=0.036;
	ControlBindButton->TabOrder=0;
	//ControlBindButton->OnClick=AATab_IForceSettings.InternalOnClick;
	//ControlBindButton->OnKeyEvent=ControlBindButton.InternalOnKeyEvent;
	UGUIButton* SpeechBindButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	SpeechBindButton->Caption="Configure Communications";
	SpeechBindButton->SizingCaption="XXXXXXXXXX";
	SpeechBindButton->FontScale = EFontScale::FNS_Small;
	SpeechBindButton->Hint="Configure custom keybinds for communications";
	SpeechBindButton->WinTop=0.09;
	SpeechBindButton->WinLeft=0.6;
	SpeechBindButton->WinWidth=0.28;
	SpeechBindButton->WinHeight=0.036;
	SpeechBindButton->TabOrder=1;
	//SpeechBindButton->OnClick=AATab_IForceSettings.InternalOnClick;
	//SpeechBindButton->OnKeyEvent=SpeechBindButton.InternalOnKeyEvent;
	UmoCheckBox* InputAutoSlope = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	InputAutoSlope->ComponentJustification = EeTextAlign::TXTA_Left;
	InputAutoSlope->CaptionWidth=0.9;
	InputAutoSlope->Caption="Auto Slope";
	//InputAutoSlope->OnCreateComponent=InputAutoSlope.InternalOnCreateComponent;
	InputAutoSlope->IniOption="@Internal";
	InputAutoSlope->Hint="When enabled, your view will automatically pitch up/down when on a slope.";
	InputAutoSlope->WinTop=0.17;
	InputAutoSlope->WinLeft=0.02;
	InputAutoSlope->WinWidth=0.45;
	InputAutoSlope->WinHeight=0.035;
	InputAutoSlope->TabOrder=2;
	InputAutoSlope->bStandardized=false;
	//InputAutoSlope->OnChange=AATab_IForceSettings.InternalOnChange;
	//InputAutoSlope->OnLoadINI=AATab_IForceSettings.InternalOnLoadINI;
	UmoCheckBox* InputInvertMouse = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	InputInvertMouse->ComponentJustification = EeTextAlign::TXTA_Left;
	InputInvertMouse->CaptionWidth=0.9;
	InputInvertMouse->Caption="Invert Mouse";
	//InputInvertMouse->OnCreateComponent=InputInvertMouse.InternalOnCreateComponent;
	InputInvertMouse->IniOption="@Internal";
	InputInvertMouse->Hint="When enabled, the Y axis of your mouse will be inverted.";
	InputInvertMouse->WinTop=0.23;
	InputInvertMouse->WinLeft=0.02;
	InputInvertMouse->WinWidth=0.45;
	InputInvertMouse->WinHeight=0.035;
	InputInvertMouse->TabOrder=3;
	InputInvertMouse->bStandardized=false;
	//InputInvertMouse->OnChange=AATab_IForceSettings.InternalOnChange;
	//InputInvertMouse->OnLoadINI=AATab_IForceSettings.InternalOnLoadINI;
	UmoCheckBox* InputMouseSmoothing = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	InputMouseSmoothing->ComponentJustification = EeTextAlign::TXTA_Left;
	InputMouseSmoothing->CaptionWidth=0.9;
	InputMouseSmoothing->Caption="Mouse Smoothing";
	//InputMouseSmoothing->OnCreateComponent=InputMouseSmoothing.InternalOnCreateComponent;
	InputMouseSmoothing->IniOption="@Internal";
	InputMouseSmoothing->Hint="Enable this option to automatically smooth out movements in your mouse.";
	InputMouseSmoothing->WinTop=0.29;
	InputMouseSmoothing->WinLeft=0.02;
	InputMouseSmoothing->WinWidth=0.45;
	InputMouseSmoothing->WinHeight=0.035;
	InputMouseSmoothing->TabOrder=4;
	InputMouseSmoothing->bStandardized=false;
	//InputMouseSmoothing->OnChange=AATab_IForceSettings.InternalOnChange;
	//InputMouseSmoothing->OnLoadINI=AATab_IForceSettings.InternalOnLoadINI;
	UmoCheckBox* InputMouseLag = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	InputMouseLag->ComponentJustification = EeTextAlign::TXTA_Left;
	InputMouseLag->CaptionWidth=0.9;
	InputMouseLag->Caption="Reduce Mouse Lag";
	//InputMouseLag->OnCreateComponent=InputMouseLag.InternalOnCreateComponent;
	InputMouseLag->IniOption="@Internal";
	InputMouseLag->Hint="Enable this option will reduce the amount of lag in your mouse.";
	InputMouseLag->WinTop=0.35;
	InputMouseLag->WinLeft=0.02;
	InputMouseLag->WinWidth=0.45;
	InputMouseLag->WinHeight=0.035;
	InputMouseLag->TabOrder=5;
	InputMouseLag->bStandardized=false;
	//InputMouseLag->OnChange=AATab_IForceSettings.InternalOnChange;
	//InputMouseLag->OnLoadINI=AATab_IForceSettings.InternalOnLoadINI;
	UmoCheckBox* InputUseJoystick = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	InputUseJoystick->ComponentJustification = EeTextAlign::TXTA_Left;
	InputUseJoystick->CaptionWidth=0.9;
	InputUseJoystick->Caption="Enable Joystick";
	//InputUseJoystick->OnCreateComponent=InputUseJoystick.InternalOnCreateComponent;
	InputUseJoystick->IniOption="@Internal";
	InputUseJoystick->Hint="Enable this option to enable joystick support.";
	InputUseJoystick->WinTop=0.41;
	InputUseJoystick->WinLeft=0.02;
	InputUseJoystick->WinWidth=0.45;
	InputUseJoystick->WinHeight=0.035;
	InputUseJoystick->TabOrder=6;
	InputUseJoystick->bStandardized=false;
	//InputUseJoystick->OnChange=AATab_IForceSettings.InternalOnChange;
	//InputUseJoystick->OnLoadINI=AATab_IForceSettings.InternalOnLoadINI;
	UmoFloatEdit* InputMouseSensitivity = NewObject<UmoFloatEdit>(UmoFloatEdit::StaticClass());
	InputMouseSensitivity->MinValue=0.25;
	InputMouseSensitivity->MaxValue=25;
	InputMouseSensitivity->Step=0.25;
	InputMouseSensitivity->ComponentJustification = EeTextAlign::TXTA_Left;
	InputMouseSensitivity->CaptionWidth=0.725;
	InputMouseSensitivity->Caption="Mouse Sens. (Game)";
	//InputMouseSensitivity->OnCreateComponent=InputMouseSensitivity.InternalOnCreateComponent;
	InputMouseSensitivity->IniOption="@Internal";
	InputMouseSensitivity->Hint="Adjust mouse sensitivity";
	InputMouseSensitivity->WinTop=0.17;
	InputMouseSensitivity->WinLeft=0.52;
	InputMouseSensitivity->WinWidth=0.45;
	InputMouseSensitivity->WinHeight=0.035;
	InputMouseSensitivity->TabOrder=7;
	//InputMouseSensitivity->OnChange=AATab_IForceSettings.InternalOnChange;
	//InputMouseSensitivity->OnLoadINI=AATab_IForceSettings.InternalOnLoadINI;
	UmoFloatEdit* InputMenuSensitivity = NewObject<UmoFloatEdit>(UmoFloatEdit::StaticClass());
	InputMenuSensitivity->MinValue=1;
	InputMenuSensitivity->MaxValue=6;
	InputMenuSensitivity->Step=0.25;
	InputMenuSensitivity->ComponentJustification = EeTextAlign::TXTA_Left;
	InputMenuSensitivity->CaptionWidth=0.725;
	InputMenuSensitivity->Caption="Mouse Sens. (Menus)";
	//InputMenuSensitivity->OnCreateComponent=InputMenuSensitivity.InternalOnCreateComponent;
	InputMenuSensitivity->IniOption="@Internal";
	InputMenuSensitivity->Hint="Adjust mouse speed within the menus";
	InputMenuSensitivity->WinTop=0.23;
	InputMenuSensitivity->WinLeft=0.52;
	InputMenuSensitivity->WinWidth=0.45;
	InputMenuSensitivity->WinHeight=0.045352;
	InputMenuSensitivity->TabOrder=8;
	//InputMenuSensitivity->OnChange=AATab_IForceSettings.InternalOnChange;
	//InputMenuSensitivity->OnLoadINI=AATab_IForceSettings.InternalOnLoadINI;
	UmoFloatEdit* InputMouseSmoothStr = NewObject<UmoFloatEdit>(UmoFloatEdit::StaticClass());
	InputMouseSmoothStr->MinValue=0;
	InputMouseSmoothStr->MaxValue=1;
	InputMouseSmoothStr->Step=0.05;
	InputMouseSmoothStr->ComponentJustification = EeTextAlign::TXTA_Left;
	InputMouseSmoothStr->CaptionWidth=0.725;
	InputMouseSmoothStr->Caption="Mouse Smooth. Strength";
	//InputMouseSmoothStr->OnCreateComponent=InputMouseSmoothStr.InternalOnCreateComponent;
	InputMouseSmoothStr->IniOption="@Internal";
	InputMouseSmoothStr->Hint="Adjust the amount of smoothing that is applied to mouse movements";
	InputMouseSmoothStr->WinTop=0.29;
	InputMouseSmoothStr->WinLeft=0.52;
	InputMouseSmoothStr->WinWidth=0.45;
	InputMouseSmoothStr->WinHeight=0.045352;
	InputMouseSmoothStr->TabOrder=9;
	//InputMouseSmoothStr->OnChange=AATab_IForceSettings.InternalOnChange;
	//InputMouseSmoothStr->OnLoadINI=AATab_IForceSettings.InternalOnLoadINI;
	UmoFloatEdit* InputMouseAccel = NewObject<UmoFloatEdit>(UmoFloatEdit::StaticClass());
	InputMouseAccel->MinValue=0;
	InputMouseAccel->MaxValue=100;
	InputMouseAccel->Step=5;
	InputMouseAccel->ComponentJustification = EeTextAlign::TXTA_Left;
	InputMouseAccel->CaptionWidth=0.725;
	InputMouseAccel->Caption="Mouse Accel. Threshold";
	//InputMouseAccel->OnCreateComponent=InputMouseAccel.InternalOnCreateComponent;
	InputMouseAccel->IniOption="@Internal";
	InputMouseAccel->Hint="Adjust to determine the amount of movement needed before acceleration is applied";
	InputMouseAccel->WinTop=0.35;
	InputMouseAccel->WinLeft=0.52;
	InputMouseAccel->WinWidth=0.45;
	InputMouseAccel->WinHeight=0.045352;
	InputMouseAccel->TabOrder=10;
	//InputMouseAccel->OnChange=AATab_IForceSettings.InternalOnChange;
	//InputMouseAccel->OnLoadINI=AATab_IForceSettings.InternalOnLoadINI;
	
	ch_AutoSlope = InputAutoSlope;
	ch_InvertMouse = InputInvertMouse;
	ch_MouseSmoothing = InputMouseSmoothing;
	ch_Joystick = InputUseJoystick;
	ch_MouseLag = InputMouseLag;
	fl_Sensitivity = InputMouseSensitivity;
	fl_MenuSensitivity = InputMenuSensitivity;
	fl_MouseAccel = InputMouseAccel;
	fl_SmoothingStrength = InputMouseSmoothStr;
	b_Controls = ControlBindButton;
	b_Speech = SpeechBindButton;
	ControlBindMenu = "AGP_Interface.AAControlBinder";
	SpeechBindMenu = "AGP_Interface.AACommunicationsBinder";
	PanelCaption = "Input";
	PropagateVisibility = false;
	WinTop = 0.15;
	WinHeight = 0.74;

}

void UAATab_IForceSettings::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	Super::InitComponent(MyController, MyOwner);
	if ((!PlatformIsWindows()) || PlatformIs64Bit())
	{
		ch_WeaponEffects.DisableMe();
		ch_PickupEffects.DisableMe();
		ch_DamageEffects.DisableMe();
		ch_GUIEffects.DisableMe();
	}
	*/
}

void UAATab_IForceSettings::InternalOnLoadINI(UGUIComponent* Sender, FString S)
{
	/*
	local PlayerController PC;
	PC = PlayerOwner();
	switch (Sender)
	{
	case ch_AutoSlope:
		bSlope = PC.bSnapToLevel;
		ch_AutoSlope.SetComponentValue(string(bSlope), true);
		break;
	case ch_InvertMouse:
		bInvert = Class'PlayerInput'.Default.bInvertMouse;
		ch_InvertMouse.SetComponentValue(string(bInvert), true);
		break;
	case ch_MouseSmoothing:
		bSmoothing = (Class'PlayerInput'.Default.MouseSmoothingMode > 0);
		ch_MouseSmoothing.SetComponentValue(string(bSmoothing), true);
		break;
	case ch_Joystick:
		bJoystick = bool(PC.ConsoleCommand("get ini:Engine.Engine.ViewportManager UseJoystick"));
		ch_Joystick.SetComponentValue(string(bJoystick), true);
		break;
	case ch_WeaponEffects:
		bWFX = PC.bEnableWeaponForceFeedback;
		ch_WeaponEffects.SetComponentValue(string(bWFX), true);
		break;
	case ch_PickupEffects:
		bPFX = PC.bEnablePickupForceFeedback;
		ch_PickupEffects.SetComponentValue(string(bPFX), true);
		break;
	case ch_DamageEffects:
		bDFX = PC.bEnableDamageForceFeedback;
		ch_DamageEffects.SetComponentValue(string(bDFX), true);
		break;
	case ch_GUIEffects:
		bGFX = PC.bEnableGUIForceFeedback;
		ch_GUIEffects.SetComponentValue(string(bGFX), true);
		break;
	case ch_MouseLag:
		bLag = bool(PC.ConsoleCommand("get ini:Engine.Engine.RenderDevice ReduceMouseLag"));
		ch_MouseLag.Checked(bLag);
		break;
	case fl_Sensitivity:
		fSens = Class'PlayerInput'.Default.MouseSensitivity;
		fl_Sensitivity.SetComponentValue(string(fSens), true);
		break;
	case fl_MenuSensitivity:
		fMSens = Controller.MenuMouseSens;
		fl_MenuSensitivity.SetComponentValue(string(fMSens), true);
		break;
	case fl_MouseAccel:
		fAccel = Class'PlayerInput'.Default.MouseAccelThreshold;
		fl_MouseAccel.SetComponentValue(string(fAccel), true);
		break;
	case fl_SmoothingStrength:
		fSmoothing = Class'PlayerInput'.Default.MouseSmoothingStrength;
		fl_SmoothingStrength.SetComponentValue(string(fSmoothing), true);
		break;
	default:
		Log(string(Name) @ "Unknown component calling LoadINI:" $ GUIMenuOption(Sender).Caption);
		GUIMenuOption(Sender).SetComponentValue(S, true);
	}
	*/
}

void UAATab_IForceSettings::SaveSettings()
{
	/*
	local PlayerController PC;
	bool bSave = false;
	bool bInputSave = false;
	bool bIForce = false;
	Super::SaveSettings();
	PC = PlayerOwner();
	if (bool(PC.ConsoleCommand("get ini:Engine.Engine.ViewportManager UseJoystick")) != bJoystick)
	{
		PC.ConsoleCommand("set ini:Engine.Engine.ViewportManager UseJoystick" @ string(bJoystick));
	}
	if (bool(PC.ConsoleCommand("get ini:Engine.Engine.RenderDevice ReduceMouseLag")) != bLag)
	{
		PC.ConsoleCommand("set ini:Engine.Engine.RenderDevice ReduceMouseLag" @ string(bLag));
	}
	if (PC.bSnapToLevel != bSlope)
	{
		PC.bSnapToLevel = bSlope;
		bSave = true;
	}
	if (PC.bEnableWeaponForceFeedback != bWFX)
	{
		PC.bEnableWeaponForceFeedback = bWFX;
		bSave = true;
		bIForce = true;
	}
	if (PC.bEnablePickupForceFeedback != bPFX)
	{
		PC.bEnablePickupForceFeedback = bPFX;
		bIForce = true;
		bSave = true;
	}
	if (PC.bEnableDamageForceFeedback != bDFX)
	{
		PC.bEnableDamageForceFeedback = bDFX;
		bIForce = true;
		bSave = true;
	}
	if (PC.bEnableGUIForceFeedback != bGFX)
	{
		PC.bEnableGUIForceFeedback = bGFX;
		bIForce = true;
		bSave = true;
	}
	if (Controller.MenuMouseSens != FMax(0, fMSens))
	{
		Controller.SaveConfig();
	}
	if (Class'PlayerInput'.Default.MouseAccelThreshold != FMax(0, fAccel))
	{
		PC.SetMouseAccel(fAccel);
		bInputSave = false;
	}
	if (Class'PlayerInput'.Default.MouseSmoothingStrength != FMax(0, fSmoothing))
	{
		PC.ConsoleCommand("SetSmoothingStrength" @ string(fSmoothing));
		bInputSave = false;
	}
	if (Class'PlayerInput'.Default.bInvertMouse != bInvert)
	{
		PC.InvertMouse(string(bInvert));
		bInputSave = false;
	}
	if (Class'PlayerInput'.Default.MouseSmoothingMode != byte(bSmoothing))
	{
		PC.SetMouseSmoothing(int(bSmoothing));
		bInputSave = false;
	}
	if (Class'PlayerInput'.Default.MouseSensitivity != FMax(0, fSens))
	{
		PC.SetSensitivity(fSens);
		bInputSave = false;
	}
	if (bInputSave)
	{
		Class'PlayerInput'.StaticSaveConfig();
	}
	if (bIForce)
	{
		PC.bForceFeedbackSupported = PC.ForceFeedbackSupported((((bGFX || bWFX) || bPFX) || bDFX));
	}
	if (bSave)
	{
		PC.SaveConfig();
	}
	*/
}

void UAATab_IForceSettings::ResetClicked()
{
	/*
	int32 i = 0;
	FString str = "";
	local class<Object>  ViewportClass;
	local class<RenderDevice>  RenderClass;
	Super::ResetClicked();
	str = PlayerOwner().ConsoleCommand("get ini:Engine.Engine.ViewportManager Class");
	str = Mid(str, (InStr(str, "'") + 1));
	str = Left(str, (Len(str) - 1));
	ViewportClass = class<Object>(DynamicLoadObject(str, Class'Class'));
	str = PlayerOwner().ConsoleCommand("get ini:Engine.Engine.RenderDevice Class");
	str = Mid(str, (InStr(str, "'") + 1));
	str = Left(str, (Len(str) - 1));
	RenderClass = class<RenderDevice>(DynamicLoadObject(str, Class'Class'));
	ViewportClass.ResetConfig("UseJoystick");
	RenderClass.ResetConfig("ReduceMouseLag");
	Controller.ResetConfig("MenuMouseSens");
	Class'PlayerController'.ResetConfig("bSnapToLevel");
	Class'PlayerController'.ResetConfig("bEnableWeaponForceFeedback");
	Class'PlayerController'.ResetConfig("bEnablePickupForceFeedback");
	Class'PlayerController'.ResetConfig("bEnableDamageForceFeedback");
	Class'PlayerController'.ResetConfig("bEnableGUIForceFeedback");
	Class'PlayerInput'.ResetConfig("bInvertMouse");
	Class'PlayerInput'.ResetConfig("MouseSmoothingMode");
	Class'PlayerInput'.ResetConfig("MouseSensitivity");
	Class'PlayerInput'.ResetConfig("MouseSmoothingStrength");
	Class'PlayerInput'.ResetConfig("DoubleClickTime");
	Class'PlayerInput'.ResetConfig("MouseAccelThreshold");
	for (i = 0; i < Components.Length; i++)
	{
		Components[i].LoadINI();
	}
	*/
}

void UAATab_IForceSettings::InternalOnChange(UGUIComponent* Sender)
{
	/*
	Super::InternalOnChange(Sender);
	switch (Sender)
	{
	case ch_AutoSlope:
		bSlope = ch_AutoSlope.IsChecked();
		break;
	case ch_InvertMouse:
		bInvert = ch_InvertMouse.IsChecked();
		break;
	case ch_MouseSmoothing:
		bSmoothing = ch_MouseSmoothing.IsChecked();
		break;
	case ch_Joystick:
		bJoystick = ch_Joystick.IsChecked();
		break;
	case ch_WeaponEffects:
		bWFX = ch_WeaponEffects.IsChecked();
		break;
	case ch_PickupEffects:
		bPFX = ch_PickupEffects.IsChecked();
		break;
	case ch_DamageEffects:
		bDFX = ch_DamageEffects.IsChecked();
		break;
	case ch_GUIEffects:
		bGFX = ch_GUIEffects.IsChecked();
		break;
	case ch_MouseLag:
		bLag = ch_MouseLag.IsChecked();
		break;
	case fl_Sensitivity:
		fSens = fl_Sensitivity.GetValue();
		break;
	case fl_MenuSensitivity:
		Controller.MenuMouseSens = fl_MenuSensitivity.GetValue();
		break;
	case fl_MouseAccel:
		fAccel = fl_MouseAccel.GetValue();
		break;
	case fl_SmoothingStrength:
		fSmoothing = fl_SmoothingStrength.GetValue();
		break;
	default:
	}
	SaveSettings();
	*/
}

bool UAATab_IForceSettings::InternalOnClick(UGUIComponent* Sender)
{
	/*
	if (Sender == b_Controls)
	{
		Controller.OpenMenu(ControlBindMenu);
	}
	else
	{
		if (Sender == b_Speech)
		{
			Controller.OpenMenu(SpeechBindMenu);
		}
	}
	*/
	return true;
}