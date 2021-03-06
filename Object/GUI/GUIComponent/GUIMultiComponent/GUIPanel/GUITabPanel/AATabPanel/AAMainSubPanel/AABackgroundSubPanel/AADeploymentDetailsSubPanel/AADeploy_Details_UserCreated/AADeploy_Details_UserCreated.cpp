// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AADeploymentDetailsSubPanel/AADeploy_Details_UserCreated/AADeploy_Details_UserCreated.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainPanel/AABrowserPanel/AABrowserPanel.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AADeploy_DCDS/AADeploy_DCDS.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AADeploy_Internet/AADeploy_Internet.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainPanel/AADeploymentPanel/AADeploymentPanel.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/AAMainMenu/AAMainMenu.h"
#include "AA29/Object/MissionInfoObject/MissionInfoObject.h"

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
	UMissionInfoObject* MIO = nullptr;
	/*
	switch (Sender)
	{
	case co_Tour:
		MIO = MissionInfoObject(co_Tour.GetObject());
		if (MIO != nullptr)
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
	if (MyNML != nullptr)
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
	UAABrowserPanel* aasbBrowser = nullptr;
	UAADeploy_DCDS* DCDSPanel = nullptr;
	UAAMainMenu* aamm = nullptr;
	UAADeploy_Internet* aabslpi = nullptr;
	UMissionInfoObject* MIO = nullptr;
	UAADeploymentPanel* aadp = nullptr;
	/*
	if (Sender == bDeploy)
	{
		aamm = AAMainMenu(PageOwner);
		if (aamm != nullptr)
		{
			aasbBrowser = AABrowserPanel(aamm.c_Tab.BorrowPanel("AA BROWSER"));
			if (aasbBrowser != nullptr)
			{
				if (bUserHasThisMap)
				{
					aasbBrowser.c_Tabs.ActivateTabByName("Internet", true);
					aabslpi = AADeploy_Internet(aasbBrowser.c_Tabs.BorrowPanel("Internet"));
					if (aabslpi != nullptr)
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
					if (DCDSPanel != nullptr)
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
				if (aamm != nullptr)
				{
					aadp = AADeploymentPanel(aamm.c_Tab.BorrowPanel("DEPLOYMENT"));
					if (aadp != nullptr)
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
				if (MIO != nullptr)
				{
					PlayerOwner().ConsoleCommand("open " + MIO.MapFilename + "?singleplayerexploremode");
				}
			}
		}
	}
	*/
	return false;      //FAKE //ELiZ

}

void UAADeploy_Details_UserCreated::SetDeployButtonToDCDS()
{
	bDeploy->Caption = "DOWNLOAD";
	bDeploy->EnableMe();
	bUserHasThisMap = false;
}

void UAADeploy_Details_UserCreated::SetDeployButtonToDeploy()
{
	bDeploy->Caption = "DEPLOY";
	bUserHasThisMap = true;
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
	int32 NumMissions = 0;
	int32 i = 0;
	int32 j = 0;
	FString File = "";
	FString TourName = "";
	UMissionInfoObject* MissionInfo = nullptr;
	/*
	File = GetBaseDir() + ToursFile;
	co_Tour.ResetComponent();
	co_Tour.addItem(ComboBoxDefaultText, , DefaultPage);
	for (i = 0; i < ValidTours.Num(); i++)
	{
		TourName = GetPrivateProfileString(File, "Tours", "Tour(" + FString::FromInt(ValidTours[i]) + ")");
		NumMissions = GetPrivateProfileInt(File, TourName, "NumMissions");
		for (j = 0; j < NumMissions; j++)
		{
			MissionInfo = new (None) UMissionInfoObject::StaticClass();
			MissionInfo.TourID = ValidTours[i];
			MissionInfo.MissionID = j;
			MissionInfo.MapFilename = GetPrivateProfileString(File, TourName, "MissionMapFilename(" + FString::FromInt(j) + ")");
			MissionInfo.MBSTitle = GetPrivateProfileString(File, TourName, "MissionMBSTitle(" + FString::FromInt(j) + ")");
			MissionInfo.MissionImage = GetPrivateProfileString(File, TourName, "MissionImage(" + FString::FromInt(j) + ")");
			co_Tour.addItem(GetPrivateProfileString(File, TourName, "MissionTitle(" + FString::FromInt(j) + ")"), MissionInfo, GetPrivateProfileString(File, TourName, "MissionNMLFilename(" + FString::FromInt(j) + ")"));
		}
	}
	co_Tour.Sort();
	co_Tour.SetIndex(0);
	*/
}
