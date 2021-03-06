// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AACreditsSubPanel/AACreditsSubPanel.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIContentBox/GUIContentBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"
#include "AA29/Object/GUI/GUIComponent/NMLContent/NMLContent.h"

UAACreditsSubPanel::UAACreditsSubPanel()
{
	UGUIContentBox* MyPanel = NewObject<UGUIContentBox>(UGUIContentBox::StaticClass());
	MyPanel->ItemSpacing = 0.02;
	MyPanel->bScaleItemsToWidth = true;
	MyPanel->WinTop = 0.06625;
	MyPanel->WinHeight = 0.8825;
	MyPanel->RenderWeight = 0.6;
	MyPanel->bBoundToParent = true;
	MyPanel->bScaleToParent = true;
	guicbPanel = MyPanel;
	PanelCaption = "Meet the America's Army Creative and Management Teams";
}

void UAACreditsSubPanel::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	UNMLContent* MyNML = nullptr;
	Super::InitComponent(MyController, MyOwner);
	/*
	MyNML = new (None) UNMLContent::StaticClass();
	if (MyNML != nullptr)
	{
		if (MyNML.Controller == nullptr)
		{
			MyNML.InitComponent(MyController, MyOwner);
		}
		MyNML.ParseNMLFromServer(NMLPage, "dms1.americasarmy.com", 80, guicbPanel, i_NMLStatusIcon, l_NMLStatusText);
	}
	*/
}
