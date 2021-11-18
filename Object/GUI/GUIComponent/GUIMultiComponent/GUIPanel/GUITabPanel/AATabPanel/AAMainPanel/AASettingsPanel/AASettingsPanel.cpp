// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainPanel/AASettingsPanel/AASettingsPanel.h"

UAASettingsPanel::UAASettingsPanel()
{
	bApplyImmediately = true;
	InvalidStats = "Invalid Stats Info";

	PanelClasses = { "AGP_Interface.AATab_DetailSettings","AGP_Interface.AATab_AudioSettings","AGP_Interface.AATab_IForceSettings","AGP_Interface.AATab_GameSettings","AGP_Interface.AATab_HudSettings","AGP_Interface.AATab_ParentalControls" };
	PanelCaptions = { "Video","Audio","Input","Game","HUD","Parental" };
	PanelHints = { "Select your resolution or change your display and detail settings...","Adjust your audio experience...","Configure misc. input options...","Configure game and network related settings...","Customize your HUD...","Set content control and password...." };
}

