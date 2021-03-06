// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AASupportContentSubPanel/AASupport_Help/AASupport_Help.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/AAGUIPanel/AAIRC_Panel/AAIRC_Panel.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AABrowser_Page/AABrowser_IRC/AABrowser_IRC.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainPanel/AABrowserPanel/AABrowserPanel.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/AAMainMenu/AAMainMenu.h"
#include "AA29/Object/GUI/GUIComponent/NMLContent/NMLContent.h"

UAASupport_Help::UAASupport_Help()
{
	SupportFile = "/x_support_help.nml";
	PanelCaption = "Helpful Player Resources and Information";
}

void UAASupport_Help::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	UNMLContent* MyNML = nullptr;
	Super::InitComponent(MyController, MyOwner);
	/*
	MyNML = new (None) UNMLContent::StaticClass();
	if (MyNML != nullptr)
	{
		if (MyNML.Controller == nullptr)
		{
			MyNML.InitComponent(MyController, MyOwner);
		}
		MyNML.__dInterPanelLink__Delegate = OnInterPanelLink;
		MyNML.ParseNMLFromServer(SupportFile, "dms1.americasarmy.com", 80, cob_Panel, i_NMLStatusIcon, l_NMLStatusText);
	}
	*/
}

void UAASupport_Help::OnInterPanelLink(FString PanelName, int32 Param1, int32 Param2, FString Param3)
{
	UAABrowserPanel* aasbBrowser = nullptr;
	UAAMainMenu* aamm = nullptr;
	UAABrowser_IRC* aabirc = nullptr;
	/*
	if (Param1 == 1)
	{
		aamm = AAMainMenu(PageOwner);
		if (aamm != nullptr)
		{
			aasbBrowser = AABrowserPanel(aamm.c_Tab.BorrowPanel("AA BROWSER"));
			if (aasbBrowser != nullptr)
			{
				aabirc = AABrowser_IRC(aasbBrowser.c_Tabs.BorrowPanel("Chat"));
				if (aabirc != nullptr)
				{
					aasbBrowser.c_Tabs.ActivateTabByName("Chat", true);
					Controller.ReplaceMenu("AGP_Interface.AAMainMenu", "AA BROWSER");
					aaircp = aabirc.tp_System.p_IRC;
					if (aaircp.IsCurrentServer("irc.americasarmy.com"))
					{
						aaircp.tp_System.Disconnect();
					}
					aaircp.tp_System.Connect("irc.americasarmy.com");
					SetTimer(2.5, true);
				}
			}
		}
	}
	else
	{
		Controller.OpenMenu("AGP_Interface.AAExternalLinkPage", Param3, PanelName);
	}
	*/
}

void UAASupport_Help::Timer()
{
	/*
	if (aaircp.tp_System.IsConnected() && (!IsInSupportChannel()))
	{
		aaircp.tp_System.JoinChannel("#aa-support");
		SetTimer(0, false);
	}
	*/
}

bool UAASupport_Help::IsInSupportChannel()
{
	int32 i = 0;
	/*
	for (i = 0; i < aaircp.tp_System.Channels.Num(); i++)
	{
		if (aaircp.tp_System.Channels[i].ChannelName == "#aa-support")
		{
			return true;
		}
	}
	*/
	return false;
}
