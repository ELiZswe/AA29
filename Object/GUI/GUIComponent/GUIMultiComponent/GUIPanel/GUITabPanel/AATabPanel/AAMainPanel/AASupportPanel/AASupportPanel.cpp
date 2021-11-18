// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainPanel/AASupportPanel/AASupportPanel.h"

UAASupportPanel::UAASupportPanel()
{
	PanelClasses = { "AGP_Interface.AASupport_Help", "AGP_Interface.AASupport_Overview", "AGP_Interface.AASupport_ReleaseNotes", "AGP_Interface.AASupport_Glossary", "AGP_Interface.AASupport_Links", "AGP_Interface.AADeploy_Services" };
	PanelCaptions = { "Help", "Overview", "Release Notes", "Glossary", "Links", "Services" };
	PanelHints = { "Help.","General information about the game.","Latest information about the game.","Terms and abbreviations used in the game.","Links.","America's Army Services and Server Solutions" };
}
