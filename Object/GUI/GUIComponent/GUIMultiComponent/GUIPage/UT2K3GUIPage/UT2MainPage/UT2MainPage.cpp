// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/UT2K3GUIPage/UT2MainPage/UT2MainPage.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUITabControl/GUITabControl.h"

UUT2MainPage::UUT2MainPage()
{
	UGUITabControl* PageTabs = NewObject<UGUITabControl>(UGUITabControl::StaticClass());
	PageTabs->bDockPanels = true;
	PageTabs->TabHeight = 0.04;
	PageTabs->WinTop = 0.25;
	PageTabs->WinHeight = 48;
	PageTabs->bAcceptsInput = true;
	//PageTabs->OnActivate=PageTabs.InternalOnActivate;
	//PageTabs->OnChange=UT2MainPage.InternalOnChange;
	c_Tabs = PageTabs;
}

void UUT2MainPage::InitComponent(UGUIController* MyC, UGUIComponent* MyO)
{
	/*
	Super::InitComponent(MyC, MyO);
	c_Tabs.__OnChange__Delegate = InternalOnChange;
	t_Header.DockedTabs = c_Tabs;
	*/
}

void UUT2MainPage::InternalOnChange(UGUIComponent* Sender)
{
}
