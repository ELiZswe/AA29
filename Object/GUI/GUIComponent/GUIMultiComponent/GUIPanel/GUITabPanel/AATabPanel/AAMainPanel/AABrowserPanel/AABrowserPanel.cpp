// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainPanel/AABrowserPanel/AABrowserPanel.h"

UAABrowserPanel::UAABrowserPanel()
{
	PanelClasses = { "AGP_Interface.AADeploy_Internet", "AGP_Interface.AADeploy_LAN", "AGP_Interface.AADeploy_Favorites", "AGP_Interface.AABrowser_IRC", "AGP_Interface.AADeploy_DCDS" };
	PanelCaptions = { "Internet", "LAN", "Favorites", "Chat", "DCDS" };
	PanelHints = { "Play online missions on servers over the Internet", "View all America's Army servers currently running on your LAN", "Choose a server to join from among your favorites", "America's Army integrated IRC client", "Dynamic Content and Delivery Service" };
}

void UAABrowserPanel::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	//Super::InitComponent(MyController, MyOwner);
}

void UAABrowserPanel::ShowPanel(bool bShow)
{
	/*
	local bool FavoritesAvailable;
	Super::ShowPanel(bShow);
	if (bShow)
	{
		FavoritesAvailable = AGP_HUD(HumanController(PlayerOwner()).myHUD).GetCurrentServerBrowser().IsSupportsFavorites();
		if (FavoritesAvailable)
		{
			c_Tabs.TabStack[c_Tabs.TabIndex("Favorites")].EnableMe();
		}
		else
		{
			if (c_Tabs.ActiveTab.Caption == "Favorites")
			{
				c_Tabs.ActivateTabByName("Internet", true);
			}
			c_Tabs.TabStack[c_Tabs.TabIndex("Favorites")].DisableMe();
		}
	}
	*/
}
