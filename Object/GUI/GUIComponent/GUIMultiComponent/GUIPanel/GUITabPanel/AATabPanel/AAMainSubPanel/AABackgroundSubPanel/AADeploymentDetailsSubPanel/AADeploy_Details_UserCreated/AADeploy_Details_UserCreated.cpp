// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AADeploymentDetailsSubPanel/AADeploy_Details_UserCreated/AADeploy_Details_UserCreated.h"

UAADeploy_Details_UserCreated::UAADeploy_Details_UserCreated()
{
	MissionsFile = "Deployment.ini";
	MissionsSection = "User Created";
	ComboBoxDefaultText = "-- User Created Missions --";
	DefaultPage = "/x_deployment_uc_mission.nml";
	ValidTours = { 15, 16 };
	PanelCaption = "User Created Mission Intel";
}

void UAADeploy_Details_UserCreated::InternalOnChange(UGUIComponent* Sender)
{
	/*
	local MissionInfoObject MIO;
	switch (Sender)
	{
	case co_Tour:
		MIO = MissionInfoObject(co_Tour.GetObject());
		if (MIO != None)
		{
			if (!DoesUserHaveMap(MIO.MapFilename))
			{
				SetDeployButtonToDCDS();
				bExploreMap.DisableMe();
				break;
			}
			SetDeployButtonToDeploy();
			bExploreMap.EnableMe();
			if (!PlayerOwner().Level.CanPlayerPlayMissionPrivate(PlayerOwner(), MIO.TourID, MIO.MissionID))
			{
				bDeploy.DisableMe();
				break;
			}
			bDeploy.EnableMe();
		}
	}
	if (MyNML != None)
	{
		guicbPanel.RemoveAllComponents();
		if (co_Tour.GetExtra() == "")
		{
			MyNML.ParseNMLFromServer(DefaultPage, "dms1.americasarmy.com", 80, guicbPanel, i_NMLStatusIcon, l_NMLStatusText);
		}
		else
		{
			MyNML.ParseNMLFromServer(co_Tour.GetExtra(), "dms1.americasarmy.com", 80, guicbPanel, i_NMLStatusIcon, l_NMLStatusText);
		}
	}
	if ((co_Tour.GetText() == ComboBoxDefaultText) || (co_Tour.GetText() == "-- SMU Guildhall --"))
	{
		bDeploy.DisableMe();
		bExploreMap.DisableMe();
	}
	GOTO JL01F2;
	default:
	JL01F2:
	*/
}

bool UAADeploy_Details_UserCreated::ButtonClick(UGUIComponent* Sender)
{
	/*
	local AABrowserPanel aasbBrowser;
	local AADeploy_DCDS DCDSPanel;
	local AAMainMenu aamm;
	local AADeploy_Internet aabslpi;
	local MissionInfoObject MIO;
	local AADeploymentPanel aadp;
	if (Sender == bDeploy)
	{
		aamm = AAMainMenu(PageOwner);
		if (aamm != None)
		{
			aasbBrowser = AABrowserPanel(aamm.c_Tab.BorrowPanel("AA BROWSER"));
			if (aasbBrowser != None)
			{
				if (bUserHasThisMap)
				{
					aasbBrowser.c_Tabs.ActivateTabByName("Internet", true);
					aabslpi = AADeploy_Internet(aasbBrowser.c_Tabs.BorrowPanel("Internet"));
					if (aabslpi != None)
					{
						MIO = MissionInfoObject(co_Tour.GetObject());
						aabslpi.SetDeploymentModeOnNextShowPanel(MIO.MBSTitle);
						SetFocus(aabslpi);
						Controller.ReplaceMenu("AGP_Interface.AAMainMenu", "AA BROWSER");
						return true;
					}
				}
				else
				{
					aasbBrowser.c_Tabs.ActivateTabByName("DCDS", true);
					DCDSPanel = AADeploy_DCDS(aasbBrowser.c_Tabs.BorrowPanel("DCDS"));
					if (DCDSPanel != None)
					{
						SetFocus(DCDSPanel);
						Controller.ReplaceMenu("AGP_Interface.AAMainMenu", "AA BROWSER");
						return true;
					}
				}
			}
		}
		else
		{
			Log("WARNING: Couldn't find AAMainMenu page");
		}
	}
	else
	{
		if (Sender == bBack)
		{
			if (co_Tour.GetIndex() != 0)
			{
				co_Tour.SetIndex(0);
			}
			else
			{
				aamm = AAMainMenu(PageOwner);
				if (aamm != None)
				{
					aadp = AADeploymentPanel(aamm.c_Tab.BorrowPanel("DEPLOYMENT"));
					if (aadp != None)
					{
						aadp.c_Tabs.ActivateTabByName("Overview", true);
					}
				}
			}
		}
		else
		{
			if (Sender == bExploreMap)
			{
				MIO = MissionInfoObject(co_Tour.GetObject());
				if (MIO != None)
				{
					PlayerOwner().ConsoleCommand("open " $ MIO.MapFilename $ "?singleplayerexploremode");
				}
			}
		}
	}
	*/
	return false;      //FAKE //ELiZ

}

void UAADeploy_Details_UserCreated::SetDeployButtonToDCDS()
{
	/*
	bDeploy.Caption = "DOWNLOAD";
	bDeploy.EnableMe();
	bUserHasThisMap = false;
	*/
}

void UAADeploy_Details_UserCreated::SetDeployButtonToDeploy()
{
	/*
	bDeploy.Caption = "DEPLOY";
	bUserHasThisMap = true;
	*/
}

int32 UAADeploy_Details_UserCreated::MyCompareItem(FGUIListElem ElemA, FGUIListElem ElemB)
{
	/*
	if (ElemA.Item == "-- SMU Guildhall --")
	{
		return -1;
	}
	else
	{
		if (ElemB.Item == "-- SMU Guildhall --")
		{
			return 1;
		}
	}
	if ((StrCmp("SMU ", ElemA.Item, 4) == 0) && (StrCmp("SMU ", ElemB.Item, 4) == 0))
	{
		return StrCmp(ElemA.Item, ElemB.Item);
	}
	else
	{
		if (StrCmp("SMU ", ElemA.Item, 4) == 0)
		{
			return -1;
		}
		else
		{
			if (StrCmp("SMU ", ElemB.Item, 4) == 0)
			{
				return 1;
			}
		}
	}
	return StrCmp(ElemA.Item, ElemB.Item);
	*/
	return 0;    //FAKE   /ELiZ
}

void UAADeploy_Details_UserCreated::PopulateComboBox()
{
	/*
	local int32 NumMissions;
	local int32 i;
	local int32 j;
	local FString File;
	local FString TourName;
	local MissionInfoObject MissionInfo;
	File = GetBaseDir() $ ToursFile;
	co_Tour.ResetComponent();
	co_Tour.addItem(ComboBoxDefaultText, , DefaultPage);
	for (i = 0; i < ValidTours.Length; i++)
	{
		TourName = GetPrivateProfileString(File, "Tours", "Tour(" $ string(ValidTours[i]) $ ")");
		NumMissions = GetPrivateProfileInt(File, TourName, "NumMissions");
		for (j = 0; j < NumMissions; j++)
		{
			MissionInfo = new (None) class'AGP_Interface.MissionInfoObject';
			MissionInfo.TourID = ValidTours[i];
			MissionInfo.MissionID = j;
			MissionInfo.MapFilename = GetPrivateProfileString(File, TourName, "MissionMapFilename(" $ string(j) $ ")");
			MissionInfo.MBSTitle = GetPrivateProfileString(File, TourName, "MissionMBSTitle(" $ string(j) $ ")");
			MissionInfo.MissionImage = GetPrivateProfileString(File, TourName, "MissionImage(" $ string(j) $ ")");
			co_Tour.addItem(GetPrivateProfileString(File, TourName, "MissionTitle(" $ string(j) $ ")"), MissionInfo, GetPrivateProfileString(File, TourName, "MissionNMLFilename(" $ string(j) $ ")"));
		}
	}
	co_Tour.Sort();
	co_Tour.SetIndex(0);
	*/
}