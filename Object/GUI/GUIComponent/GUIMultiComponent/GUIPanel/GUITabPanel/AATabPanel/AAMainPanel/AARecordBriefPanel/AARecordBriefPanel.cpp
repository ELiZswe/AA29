// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainPanel/AARecordBriefPanel/AARecordBriefPanel.h"

UAARecordBriefPanel::UAARecordBriefPanel()
{
	PanelClasses = { "AGP_Interface.AARecordBrief_News", "AGP_Interface.AARecordBrief_PlayerStats", "AGP_Interface.AARecordBrief_Badges", "AGP_Interface.AAPersonnelJacket_Weapon" };
	PanelCaptions = { "News", "Player Stats", "Badges", "M4A1 Mods" };
	PanelHints = { "News", "Player Stats", "Badges", "Configure your soldier's weapon." };
}