// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/Settings_Tabs/Settings_Tabs.h"

USettings_Tabs::USettings_Tabs()
{
	bAlwaysApply = true;
	PerformanceWarningMenu = "AGP_Interface.AAPerformWarn";
	PerformanceWarningText = "The change you are making may adversely affect your performance.";
	FadeInTime = 0.15;
}

void USettings_Tabs::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	//Super::InitComponent(MyController, MyOwner);
}

void USettings_Tabs::Opened(UGUIComponent* Sender)
{
	//Super::Opened(Sender);
}

void USettings_Tabs::ShowPanel(bool bShow)
{
	//Super::ShowPanel(bShow);
}

void USettings_Tabs::AcceptClicked()
{
	//SaveSettings();
}

void USettings_Tabs::Closed(UGUIComponent* Sender, bool bCancelled)
{
	/*
	Super::Closed(Sender, bCancelled);
	if (bAlwaysApply)
	{
		AcceptClicked();
		return;
	}
	if (!bCancelled)
	{
		SaveSettings();
	}
	*/
}

void USettings_Tabs::SaveSettings()
{
}

void USettings_Tabs::ResetClicked()
{
}

FString USettings_Tabs::GetNativeClassName(FString VarName)
{
	int32 i = 0;
	FString str = "";
	/*
	if (PlayerOwner() == None)
	{
		return "";
	}
	str = PlayerOwner().ConsoleCommand("get ini:" $ VarName @ "Class");
	i = InStr(str, "'");
	if (i != -1)
	{
		str = Mid(str, (InStr(str, "'") + 1));
		str = Left(str, (Len(str) - 1));
	}
	*/
	return str;
}

void USettings_Tabs::ShowPerformanceWarning(float Seconds)
{
	/*
	if ((Controller == None) || Default.bExpert)
	{
		return;
	}
	if (!Controller.OpenMenu(PerformanceWarningMenu, string(Seconds)))
	{
		if (Seconds <= 0)
		{
			Seconds = 3.5;
		}
		WarningLength = Seconds;
		WarningCounter = 0;
		SetTimer(0.1, true);
		__OnRendered__Delegate = DrawPerfWarn;
	}
	*/
}

void USettings_Tabs::Timer()
{
	//WarningCounter += 0.1;
}

void USettings_Tabs::DrawPerfWarn(UCanvas* C)
{
	/*
	C.Style = 5;
	C.SetDrawColor(250, 250, 250, byte((float(255) * FMax(((WarningLength - WarningCounter) / WarningLength), 0))));
	C.Font = Controller.GetMenuFont("AASmallHeaderFont").GetFont(C.SizeX);
	C.DrawTextJustified(PerformanceWarningText, 1, ActualLeft(), ActualTop(), (ActualLeft() + ActualWidth()), ((ActualTop() + ActualHeight()) * 0.8));
	if (WarningCounter >= WarningLength)
	{
		WarningLength = 0;
		WarningCounter = 0;
		__OnRendered__Delegate = None;
		KillTimer();
	}
	*/
}

void USettings_Tabs::InternalOnChange(UGUIComponent* Sender)
{
}
