// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainPanel/AATrainingPanel/AATrainingPanel.h"

UAATrainingPanel::UAATrainingPanel()
{
	PanelClasses = { "AGP_Interface.AATraining_Overview", "AGP_Interface.AATraining_Details" };
	PanelCaptions = { "Overview", "Details" };
	PanelHints = {"Training missions overview", "Training missions details"};
}