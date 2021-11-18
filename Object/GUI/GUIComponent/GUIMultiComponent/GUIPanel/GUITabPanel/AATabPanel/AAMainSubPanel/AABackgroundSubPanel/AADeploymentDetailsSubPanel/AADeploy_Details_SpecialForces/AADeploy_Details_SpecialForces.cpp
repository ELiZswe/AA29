// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AADeploymentDetailsSubPanel/AADeploy_Details_SpecialForces/AADeploy_Details_SpecialForces.h"

UAADeploy_Details_SpecialForces::UAADeploy_Details_SpecialForces()
{
	MissionsFile = "Deployment.ini";
	MissionsSection = "SpecialForces";
	ComboBoxDefaultText = "-- Review Special Forces Missions --";
	DefaultPage = "/x_deployment_sf_mission.nml";
	ValidTours = { 11, 12 };
	PanelCaption = "Special Forces Operational Intel";
}