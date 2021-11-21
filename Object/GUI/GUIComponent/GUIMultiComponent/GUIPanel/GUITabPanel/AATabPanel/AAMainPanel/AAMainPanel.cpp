// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainPanel/AAMainPanel.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUITabControl/AAGUITabControl/AAGUITabControl.h"

UAAMainPanel::UAAMainPanel()
{
	UAAGUITabControl* PageTabs = NewObject<UAAGUITabControl>(UAAGUITabControl::StaticClass());
	PageTabs->ButtonStyleName = "TabButton";
	PageTabs->UniformTabWidth = 0.12;
	PageTabs->bDockPanels = true;
	PageTabs->TabHeight = 0.035;
	PageTabs->WinHeight = 1;
	PageTabs->RenderWeight = 0.49;
	PageTabs->TabOrder = 1;
	PageTabs->bBoundToParent = true;
	PageTabs->bScaleToParent = true;
	PageTabs->bAcceptsInput = true;
	//PageTabs->OnActivate=PageTabs.InternalOnActivate;
	//PageTabs->OnChange=AAMainPanel.InternalOnChange;
	c_Tabs = PageTabs;

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
