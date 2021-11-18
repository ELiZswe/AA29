// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AAMissionsSubPanel/AAMissionsDetailsSubPanel/AADeploy_Details/AADeploy_Details.h"

UAADeploy_Details::UAADeploy_Details()
{
	TourComboCaption = "Select the tour you would like to see missions for.";
	MissionComboCaption = "Select the mission you would like to deploy to.";
	PanelCaption = "Mission Objectives";
}

bool UAADeploy_Details::UseTraining(int32 Tour)
{
	//return (!PlayerOwner().Level.GetTourIsTraining(Tour));
	return false;   //FAKE   /ELiZ
}

void UAADeploy_Details::SetStatusCaption(int32 Status)
{
	/*
	switch (Status)
	{
	case -1:
		l_Status.TextColor = NotAvailableColor;
		l_Status.Caption = NotAvailableText;
		break;
	case 0:
	case 1:
	default:
		l_Status.TextColor = AvailableColor;
		l_Status.Caption = AvailableText;
		break;
	}
	Super::SetStatusCaption(Status);
	*/
}

bool UAADeploy_Details::ButtonClick(UGUIComponent* Sender)
{
	/*
	local AAServerBrowser aasbBrowser;
	local AAMainMenu aamm;
	local AABrowser_ServerListPageInternet aabslpi;
	class'AGP_Interface.AAFilterPage'.ResetFilterToShowStandardServers();
	class'AGP_Interface.AAFilterPageGamespy'.ResetFilterToShowStandardServers();
	class'AGP_Interface.AAFilterPage'.Default.sFilterMap = PlayerOwner().Level.GetTourMissionMBSTitle(TourID, MissionID);
	class'AGP_Interface.AAFilterPageGamespy'.Default.sFilterMap = PlayerOwner().Level.GetTourMissionMBSTitle(TourID, MissionID);
	aamm = AAMainMenu(PageOwner);
	if (aamm != None)
	{
		aasbBrowser = AAServerBrowser(aamm.c_Tab.BorrowPanel("DEPLOYMENT"));
		if (aasbBrowser != None)
		{
			aasbBrowser.c_Tabs.ActivateTabByName("Internet", true);
			aabslpi = AABrowser_ServerListPageInternet(aasbBrowser.c_Tabs.BorrowPanel("Internet"));
			if (aabslpi != None)
			{
				aabslpi.FilterString = aabslpi.BuildInitialFilter();
				aabslpi.BuildInitialFilterList();
				SetFocus(aabslpi);
				aabslpi.RefreshClicked();
			}
		}
	}
	else
	{
		Log("WARNING: Couldn't find AAMainMenu page");
	}
	return Super::ButtonClick(Sender);
	*/
	return false;   //FAKE   /ELiZ
}