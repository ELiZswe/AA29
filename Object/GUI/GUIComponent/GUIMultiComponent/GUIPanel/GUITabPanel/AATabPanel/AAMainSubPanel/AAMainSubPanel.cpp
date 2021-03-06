// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AAMainSubPanel.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUITabControl/AAGUITabControl/AAGUITabControl.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"

UAAMainSubPanel::UAAMainSubPanel()
{
	UAAGUITabControl* MyTabC = NewObject<UAAGUITabControl>(UAAGUITabControl::StaticClass());
	MyTabC->TabIndent = 0.0225;
	MyTabC->bDockPanels = true;
	MyTabC->TabHeight = 0.05;
	MyTabC->WinHeight = 1;
	MyTabC->bBoundToParent = true;
	MyTabC->bScaleToParent = true;
	//MyTabC->OnActivate=MyTabC.InternalOnActivate;
	c_Tab = MyTabC;

	WinHeight = 1;
	bBoundToParent = true;
	bScaleToParent = true;
}

void UAAMainSubPanel::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	int32 i = 0;
	Super::InitComponent(MyController, MyOwner);
	for (i = 0; i < PanelClasses.Num(); i++)
	{
		c_Tab.AddTab(PanelCaptions[i], PanelClasses[i], , PanelHints[i]);
	}
	*/
}
