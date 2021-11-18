// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainPanel/AACreditsPanel/AACreditsPanel.h"

UAACreditsPanel::UAACreditsPanel()
{
	PanelClasses = { "AGP_Interface.AACredits_USArmy", "AGP_Interface.AACredits_DevTeam", "AGP_Interface.AACredits_Contributors" };
	PanelCaptions = { "U.S. Army", "Developers", "Contributors"};
	PanelHints = { "U.S. Army credits", "AAPA Development Team credits", "Contributor credits" };
}