// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AADeploymentDetailsSubPanel/AADeploy_Details_Ranger/AADeploy_Details_Ranger.h"

UAADeploy_Details_Ranger::UAADeploy_Details_Ranger()
{
	MissionsFile = "Deployment.ini";
	MissionsSection = "Ranger";
	ComboBoxDefaultText = "-- Review Ranger Missions --";
	DefaultPage = "/x_deployment_rng_mission.nml";
	ValidTours = { 6,7, 8 };
	PanelCaption = "Ranger Ops Pre-Mission Intel";
}