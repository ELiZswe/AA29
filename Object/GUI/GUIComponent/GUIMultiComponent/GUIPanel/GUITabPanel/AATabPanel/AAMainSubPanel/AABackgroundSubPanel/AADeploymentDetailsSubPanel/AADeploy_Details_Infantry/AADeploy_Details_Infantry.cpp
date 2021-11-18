// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AADeploymentDetailsSubPanel/AADeploy_Details_Infantry/AADeploy_Details_Infantry.h"

UAADeploy_Details_Infantry::UAADeploy_Details_Infantry()
{
	MissionsFile = "Deployment.ini";
	MissionsSection = "Infantry";
	ComboBoxDefaultText = "-- Review Infantry Missions --";
	ValidTours = {1, 2, 3};
	PanelCaption = "Infantry Pre-Mission Intel";
}