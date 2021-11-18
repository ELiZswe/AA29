// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainPanel/AARealHeroesPanel/AARealHeroesPanel.h"

UAARealHeroesPanel::UAARealHeroesPanel()
{
	PanelClasses = { "AGP_Interface.AARealHeroesSubPanel", "AGP_Interface.AARealHeroBrief" };
	PanelCaptions = {"Real Heroes", "Bios"};
	PanelHints = { "Real Heroes","Real Hero Biographies" };
	PanelCaption = "Real Heroes";
}