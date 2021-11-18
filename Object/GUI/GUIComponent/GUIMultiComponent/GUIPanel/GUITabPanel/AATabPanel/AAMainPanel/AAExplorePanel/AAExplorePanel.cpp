// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainPanel/AAExplorePanel/AAExplorePanel.h"

UAAExplorePanel::UAAExplorePanel()
{
	PanelClasses = { "AGP_Interface.AAExploreTheArmySubPanel", "AGP_Interface.AAEverySoldierIsASensorSubpanel" };
	PanelCaptions = { "Instant Action",		"Every Soldier Is A Sensor" };
	PanelHints = {"Instant Action is a game play mode requiring no training up to honor level 20", "Explanation of the Every Soldier Is A Sensor (ES2) Gameplay"};
	PanelCaption = "'Free Play' quick missions on special servers";
}