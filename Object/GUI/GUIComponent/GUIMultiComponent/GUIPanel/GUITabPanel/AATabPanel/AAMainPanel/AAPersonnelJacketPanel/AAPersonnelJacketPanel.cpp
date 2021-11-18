// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainPanel/AAPersonnelJacketPanel/AAPersonnelJacketPanel.h"

UAAPersonnelJacketPanel::UAAPersonnelJacketPanel()
{
	PanelClasses = {"AGP_Interface.AAPersonnelJacket_Profile", "AGP_Interface.AAPersonnelJacket_Weapon"};
	PanelCaptions = { "Profile", "Weapons" };
	PanelHints = { "Login and View Soldier Information", "Weapon modifications" };
}