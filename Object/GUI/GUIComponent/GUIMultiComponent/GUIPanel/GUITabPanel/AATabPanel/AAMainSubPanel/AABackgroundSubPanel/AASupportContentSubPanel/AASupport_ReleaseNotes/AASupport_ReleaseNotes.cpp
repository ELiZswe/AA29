// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AASupportContentSubPanel/AASupport_ReleaseNotes/AASupport_ReleaseNotes.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"
#include "AA29/Object/GUI/GUIComponent/NMLContent/NMLContent.h"

UAASupport_ReleaseNotes::UAASupport_ReleaseNotes()
{
	SupportFile = "/x_support_releasenotes.nml";
	PanelCaption = "Release Notes";
}

void UAASupport_ReleaseNotes::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
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
		MyNML.ParseNMLFromServer(SupportFile, "dms1.americasarmy.com", 80, cob_Panel, i_NMLStatusIcon, l_NMLStatusText);
	}
	*/
}
