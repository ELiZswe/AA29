// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainPanel/AADeploymentPanel/AADeploymentPanel.h"

UAADeploymentPanel::UAADeploymentPanel()
{
	PanelClasses = { "AGP_Interface.AADeploy_Overview", "AGP_Interface.AADeploy_Details_Infantry", "AGP_Interface.AADeploy_Details_Ranger", "AGP_Interface.AADeploy_Details_SpecialForces", "AGP_Interface.AADeploy_Details_UserCreated" };
	PanelCaptions = { "Overview", "Infantry", "Ranger", "Special Forces", "User-Created" };
	PanelHints = { "Online Missions Overview", "Infantry Missions", "Ranger Missions", "Special Forces Missions", "User-Created Maps and Missions" };
}


void UAADeploymentPanel::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	c_Tabs.BeginOppositeRowIndex = 5;
	Super::InitComponent(MyController, MyOwner);
	*/
}

void UAADeploymentPanel::ShowPanel(bool bShow)
{
	//Super::ShowPanel(bShow);
}
