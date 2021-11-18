// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AASupportContentSubPanel/AASupport_Help/AASupport_Help.h"

UAASupport_Help::UAASupport_Help()
{
	SupportFile = "/x_support_help.nml";
	PanelCaption = "Helpful Player Resources and Information";
}

void UAASupport_Help::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	local NMLContent MyNML;
	Super::InitComponent(MyController, MyOwner);
	MyNML = new (None) class'AGP_Interface.NMLContent';
	if (MyNML != None)
	{
		if (MyNML.Controller == None)
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
	/*
	local AABrowserPanel aasbBrowser;
	local AAMainMenu aamm;
	local AABrowser_IRC aabirc;
	if (Param1 == 1)
	{
		aamm = AAMainMenu(PageOwner);
		if (aamm != None)
		{
			aasbBrowser = AABrowserPanel(aamm.c_Tab.BorrowPanel("AA BROWSER"));
			if (aasbBrowser != None)
			{
				aabirc = AABrowser_IRC(aasbBrowser.c_Tabs.BorrowPanel("Chat"));
				if (aabirc != None)
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
	/*
	int32 i = 0;
	for (i = 0; i < aaircp.tp_System.Channels.Length; i++)
	{
		if (aaircp.tp_System.Channels[i].ChannelName == "#aa-support")
		{
			return true;
		}
	}
	*/
	return false;
}

