// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/Settings_Tabs/AATab_Demos/AATab_Demos.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moCheckBox/moCheckBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moEditBox/moEditBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"

UAATab_Demos::UAATab_Demos()
{
	UmoCheckBox* EnableDemoModeCheck = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	EnableDemoModeCheck->ComponentJustification = EeTextAlign::TXTA_Left;
	EnableDemoModeCheck->CaptionWidth=0.9;
	EnableDemoModeCheck->Caption="Enable Demo Mode";
	//EnableDemoModeCheck->OnCreateComponent=EnableDemoModeCheck.InternalOnCreateComponent;
	EnableDemoModeCheck->IniOption="@Internal";
	EnableDemoModeCheck->Hint="Check this box to enable demo mode (requires restart)";
	EnableDemoModeCheck->WinTop=0.2;
	EnableDemoModeCheck->WinLeft=0.02;
	EnableDemoModeCheck->WinWidth=0.45;
	EnableDemoModeCheck->WinHeight=0.048476;
	EnableDemoModeCheck->TabOrder=1;
	EnableDemoModeCheck->bStandardized=false;
	//EnableDemoModeCheck->OnChange=AATab_Demos.InternalOnChange;
	//EnableDemoModeCheck->OnLoadINI=AATab_Demos.InternalOnLoadINI;
	UmoEditBox* TriggerTimeEdit = NewObject<UmoEditBox>(UmoEditBox::StaticClass());
	TriggerTimeEdit->CaptionWidth=0.4;
	TriggerTimeEdit->Caption="Idle time";
	//TriggerTimeEdit->OnCreateComponent=TriggerTimeEdit.InternalOnCreateComponent;
	TriggerTimeEdit->IniOption="@Internal";
	TriggerTimeEdit->Hint="Please click here and enter a time (in seconds)";
	TriggerTimeEdit->WinTop=0.25;
	TriggerTimeEdit->WinLeft=0.02;
	TriggerTimeEdit->WinWidth=0.45;
	TriggerTimeEdit->TabOrder=2;
	//TriggerTimeEdit->OnChange=AATab_Demos.InternalOnChange;
	//TriggerTimeEdit->OnLoadINI=AATab_Demos.InternalOnLoadINI;
	UGUIImage* GameBK1 = NewObject<UGUIImage>(UGUIImage::StaticClass());
	//GameBK1->Image=Texture'T_AA2_UI.Menu.field_translucent';
	GameBK1->ImageStyle = EImgStyle::ISTY_Stretched;
	GameBK1->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	GameBK1->WinTop=0.07;
	GameBK1->WinLeft=0.01;
	GameBK1->WinWidth=0.98;
	GameBK1->WinHeight=0.42;
	GameBK1->RenderWeight=0.01;
	UGUIImage* GameBK2 = NewObject<UGUIImage>(UGUIImage::StaticClass());
	//GameBK2->Image=Texture'T_AA2_UI.Menu.field_translucent';
	GameBK2->ImageStyle = EImgStyle::ISTY_Stretched;
	GameBK2->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	GameBK2->WinTop=0.51;
	GameBK2->WinLeft=0.01;
	GameBK2->WinWidth=0.98;
	GameBK2->WinHeight=0.48;
	GameBK2->RenderWeight=0.01;

	i_BG1 = GameBK1;
	i_BG2 = GameBK2;
	ch_Enable = EnableDemoModeCheck;
	ed_TriggerTime = TriggerTimeEdit;
	RelaunchQuestion = "Demo Mode has been enabled. However, it will not take effect until the next time the game is started.  Would you like to restart America's Army right now?";
	PanelCaption = "Demos";
	WinTop = 0.15;
	WinHeight = 0.74;
}



void InternalOnLoadINI(UGUIComponent* Sender, FString S)
{
	/*
	int32 i = 0;
	local DemoController DC;
	FString sFile = "";
	FString sSection = "";
	FString sKey = "";
	FString sValue = "";
	int32 iValue = 0;
	sFile = "ArmyOps.ini";
	if (GUIMenuOption(Sender) != None)
	{
		switch (GUIMenuOption(Sender))
		{
		case ch_Enable:
			sSection = "Engine.Engine";
			sKey = "StartInDemoMode";
			sValue = GetPrivateProfileString(sFile, sSection, sKey);
			bEnableDemos = bool(sValue);
			ch_Enable.SetComponentValue(string(bEnableDemos), true);
			break;
		case ed_TriggerTime:
			i = 0;
			if (i < Controller.Master.GlobalInteractions.Length)
			{
				if (Controller.Master.GlobalInteractions[i].IsA('DemoController'))
				{
					DC = DemoController(Controller.Master.GlobalInteractions[i]);
				}
				else
				{
					i++;
				}
			}
			if (DC != None)
			{
				sTriggerTime = string(DC.DemoPlayTriggerTime);
				ed_TriggerTime.SetText(sTriggerTime);
			}
			else
			{
				sSection = "Engine.DemoController";
				sKey = "DemoPlayTriggerTime";
				iValue = GetPrivateProfileInt(sFile, sSection, sKey);
				if (iValue < 0)
				{
					iValue = 0;
				}
				sTriggerTime = string(iValue);
				ed_TriggerTime.SetText(sTriggerTime);
			}
		default:
		}
	}
	*/
}

void InternalOnChange(UGUIComponent* Sender)
{
	/*
	Super::InternalOnChange(Sender);
	if (bIgnoreChange)
	{
		return;
	}
	switch (Sender)
	{
	case ch_Enable:
		bEnableDemos = ch_Enable.IsChecked();
		break;
	case ed_TriggerTime:
		sTriggerTime = ed_TriggerTime.GetText();
		break;
	default:
	}
	SaveSettings();
	*/
}

bool EnableDemoModeClick(uint8 Btn)
{
	/*
	switch (Btn)
	{
	case 16:
		SaveSettings();
		Console(Controller.Master.Console).DelayedConsoleCommand("relaunch");
		break;
	case 2:
		ch_Enable.Checked(bEnableDemos);
		break;
	default:
	}
	*/
	return true;
}

void SaveSettings()
{
	/*
	int32 i = 0;
	local DemoController DC;
	FString sFile = "";
	FString sSection = "";
	FString sKey = "";
	FString sValue = "";
	Super::SaveSettings();
	sFile = "ArmyOps.ini";
	sSection = "Engine.Engine";
	sKey = "StartInDemoMode";
	sValue = string(bEnableDemos);
	SetPrivateProfileString(sValue, sFile, sSection, sKey);
	i = 0;
	if (i < Controller.Master.GlobalInteractions.Length)
	{
		if (Controller.Master.GlobalInteractions[i].IsA('DemoController'))
		{
			DC = DemoController(Controller.Master.GlobalInteractions[i]);
		}
		else
		{
			i++;
		}
	}
	if (DC != None)
	{
		DC.DemoPlayTriggerTime = int(sTriggerTime);
		DC.SaveConfig();
	}
	else
	{
		sSection = "Engine.DemoController";
		sKey = "DemoPlayTriggerTime";
		sValue = sTriggerTime;
		SetPrivateProfileString(sValue, sFile, sSection, sKey);
	}
	*/
}