// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainPanel/AAMainPanel.h"

UAAMainPanel::UAAMainPanel()
{
	/*
	Begin Object Class=AAGUITabControl Name=PageTabs
		ButtonStyleName="TabButton"
		UniformTabWidth=0.12
		bDockPanels=True
		TabHeight=0.035
		WinHeight=1
		RenderWeight=0.49
		TabOrder=1
		bBoundToParent=True
		bScaleToParent=True
		bAcceptsInput=True
		OnActivate=PageTabs.InternalOnActivate
		OnChange=AAMainPanel.InternalOnChange
	End Object
	*/
	//c_Tabs = AAGUITabControl'AGP_Interface.AAMainPanel.PageTabs';
	WinTop = 0.01;
	WinLeft = 0.23;
	WinWidth = 0.76;
	WinHeight = 0.98;
}


void UAAMainPanel::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	local int32 i;
	Super::InitComponent(MyController, MyOwner);
	for (i = 0; i < PanelClasses.Length; i++)
	{
		c_Tabs.AddTab(PanelCaptions[i], PanelClasses[i], , PanelHints[i]);
	}
	*/
}

void UAAMainPanel::InternalOnChange(UGUIComponent* Sender)
{
}

void UAAMainPanel::HandleParameters(FString Param1, FString Param2)
{
	/*
	if (Param1 != "")
	{
		c_Tabs.ActivateTabByName(Param1, true);
	}
	*/
}

bool UAAMainPanel::GetRestoreParams(FString& Param1, FString& Param2)
{
	/*
	if ((c_Tabs != None) && (c_Tabs.ActiveTab != None))
	{
		Param1 = c_Tabs.ActiveTab.Caption;
		return true;
	}
	*/
	return false;
}
