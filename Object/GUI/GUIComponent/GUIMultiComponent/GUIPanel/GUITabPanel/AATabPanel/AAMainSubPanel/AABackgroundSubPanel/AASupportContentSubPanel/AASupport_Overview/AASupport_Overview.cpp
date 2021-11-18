// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AASupportContentSubPanel/AASupport_Overview/AASupport_Overview.h"

UAASupport_Overview::UAASupport_Overview()
{
	SupportFile = "/x_support_overview.nml";
	PanelCaption = "Overview";
}


void UAASupport_Overview::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	local NMLContent MyNML;
	Super::InitComponent(MyController, MyOwner);
	MyNML = new (None) class'AGP_Interface.NMLContent';
	if (MyNML != None)
	{
		if (MyNML.Controller == None)
		{
			MyNML.InitComponent(MyController, MyOwner);
		}
		MyNML.ParseNMLFromServer(SupportFile, "dms1.americasarmy.com", 80, cob_Panel, i_NMLStatusIcon, l_NMLStatusText);
	}
	*/
}