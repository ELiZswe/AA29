// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AASupportContentSubPanel/AASupport_Glossary/AASupport_Glossary.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"

UAASupport_Glossary::UAASupport_Glossary()
{
	SupportFile = "/x_support_glossary.nml";
	PanelCaption = "Glossary";
}

void UAASupport_Glossary::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	local NMLContent MyNML;
	Super::InitComponent(MyController, MyOwner);
	MyNML = new (None) class'AGP_Interface.NMLContent';
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
