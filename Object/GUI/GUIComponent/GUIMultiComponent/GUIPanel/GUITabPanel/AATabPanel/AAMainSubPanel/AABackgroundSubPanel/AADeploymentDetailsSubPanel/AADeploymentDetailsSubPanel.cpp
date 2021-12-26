// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AADeploymentDetailsSubPanel/AADeploymentDetailsSubPanel.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moComboBox/moComboBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIContentBox/GUIContentBox.h"

UAADeploymentDetailsSubPanel::UAADeploymentDetailsSubPanel()
{
	UmoComboBox* MyTourCombo = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	MyTourCombo->bReadOnly = true;
	MyTourCombo->CaptionWidth = 0;
	//MyTourCombo->OnCreateComponent=MyTourCombo.InternalOnCreateComponent;
	MyTourCombo->IniOption = "@Internal";
	MyTourCombo->Hint = "Review Missions";
	MyTourCombo->WinTop = 0.06625;
	MyTourCombo->WinLeft = 0.3;
	MyTourCombo->WinWidth = 0.4;
	MyTourCombo->bStandardized = false;
	//MyTourCombo->OnChange=AADeploymentDetailsSubPanel.InternalOnChange;
	//MyTourCombo->OnLoadINI=AADeploymentDetailsSubPanel.InternalOnLoadINI;
	UGUIButton* ExploreButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	ExploreButton->Caption = "EXPLORE MAP";
	ExploreButton->FontScale = EFontScale::FNS_Small;
	ExploreButton->Hint = "Explore the map in single-player mode.";
	ExploreButton->WinTop = 0.965;
	ExploreButton->WinLeft = 0.59;
	ExploreButton->WinWidth = 0.16;
	ExploreButton->WinHeight = 0.036;
	ExploreButton->RenderWeight = 0.8;
	ExploreButton->bBoundToParent = true;
	ExploreButton->bScaleToParent = true;
	//ExploreButton->OnClick=AADeploymentDetailsSubPanel.ButtonClick;
	//ExploreButton->OnKeyEvent=ExploreButton.InternalOnKeyEvent;
	UGUIButton* DeployButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	DeployButton->Caption = "DEPLOY";
	DeployButton->FontScale = EFontScale::FNS_Small;
	DeployButton->Hint = "Load this mission!";
	DeployButton->WinTop = 0.965;
	DeployButton->WinLeft = 0.42;
	DeployButton->WinWidth = 0.16;
	DeployButton->WinHeight = 0.036;
	DeployButton->RenderWeight = 0.8;
	DeployButton->bBoundToParent = true;
	DeployButton->bScaleToParent = true;
	//DeployButton->OnClick=AADeploymentDetailsSubPanel.ButtonClick;
	//DeployButton->OnKeyEvent=DeployButton.InternalOnKeyEvent;
	UGUIButton* BackButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	BackButton->Caption = "BACK";
	BackButton->FontScale = EFontScale::FNS_Small;
	BackButton->Hint = "Back to the mission overview page";
	BackButton->WinTop = 0.965;
	BackButton->WinLeft = 0.25;
	BackButton->WinWidth = 0.16;
	BackButton->WinHeight = 0.036;
	BackButton->RenderWeight = 0.8;
	BackButton->bBoundToParent = true;
	BackButton->bScaleToParent = true;
	//BackButton->OnClick=AADeploymentDetailsSubPanel.ButtonClick;
	//BackButton->OnKeyEvent=BackButton.InternalOnKeyEvent;
	UGUIContentBox* MyPanel = NewObject<UGUIContentBox>(UGUIContentBox::StaticClass());
	MyPanel->ItemSpacing = 0.02;
	MyPanel->bScaleItemsToWidth = true;
	MyPanel->WinTop = 0.105;
	MyPanel->WinHeight = 0.84375;
	MyPanel->RenderWeight = 0.6;
	MyPanel->bBoundToParent = true;
	MyPanel->bScaleToParent = true;
	guicbPanel = MyPanel;
	DefaultPage = "/x_deployment_inf_mission.nml";
	CurrentPage = "/x_deployment_inf_mission.nml";
	co_Tour = MyTourCombo;
	bDeploy = DeployButton;
	bExploreMap = ExploreButton;
	bBack = BackButton;
	ToursFile = "Tours.ini";
	//OnShow = AADeploymentDetailsSubPanel.InternalOnShow;
}

void UAADeploymentDetailsSubPanel::InternalOnShow()
{
	/*
	PopulateComboBox();
	MyNML.ParseNMLFromServer(DefaultPage, "dms1.americasarmy.com", 80, guicbPanel, i_NMLStatusIcon, l_NMLStatusText);
	*/
}

void UAADeploymentDetailsSubPanel::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	Super::InitComponent(MyController, MyOwner);
	CurrentPage = DefaultPage;
	if (!bComboBoxInitialized)
	{
		PopulateComboBox();
		bComboBoxInitialized = true;
	}
	MyNML = new (None) class'AGP_Interface.NMLContent';
	if (MyNML != None)
	{
		if (MyNML.Controller == nullptr)
		{
			MyNML.InitComponent(MyController, MyOwner);
		}
		MyNML.__dInterPanelLink__Delegate = OnInterPanelLink;
		MyNML.__dPreParser__Delegate = NMLPreParser;
	}
	bDeploy.DisableMe();
	bExploreMap.DisableMe();
	*/
}

bool UAADeploymentDetailsSubPanel::DoesUserHaveMap(FString MapFilename)
{
	/*
	if (FOpen("../Maps/" $ MapFilename $ ".aao"))
	{
		FClose();
		return true;
	}
	*/
	return false;
}

void UAADeploymentDetailsSubPanel::NMLPreParser(FString& TrainingNML)
{
	/*
	local FString tmpstr;
	local int32 i;
	local MissionInfoObject MIO;
	for (i = 0; i < co_Tour.ItemCount(); i++)
	{
		MIO = MissionInfoObject(co_Tour.GetItemObject(i));
		if (MIO != None)
		{
			tmpstr = MIO.MissionImage;
			if (DoesUserHaveMap(MIO.MapFilename))
			{
				ReplaceText(TrainingNML, MIO.MissionImage $ "%INF%", MIO.MissionImage);
			}
			else
			{
				ReplaceText(TrainingNML, MIO.MissionImage $ "%INF%", MIO.MissionImage $ "_g");
			}
		}
	}
	*/
}

void UAADeploymentDetailsSubPanel::InternalOnLoadINI(UGUIComponent* Sender, FString S)
{
	/*
	switch (Sender)
	{
	case co_Tour:
		if (!bComboBoxInitialized)
		{
			PopulateComboBox();
			bComboBoxInitialized = true;
		}
		break;
	default:
	}
	*/
}

void UAADeploymentDetailsSubPanel::PopulateComboBox()
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
	*/
}

bool UAADeploymentDetailsSubPanel::UseTraining(int32 Tour)
{
	//return (!PlayerOwner().Level.GetTourIsTraining(Tour));
	return false;     //FAKE   /ELiZ
}

void UAADeploymentDetailsSubPanel::InternalOnChange(UGUIComponent* Sender)
{
	/*
	local MissionInfoObject MIO;
	switch (Sender)
	{
	case co_Tour:
		MIO = MissionInfoObject(co_Tour.GetObject());
		if ((co_Tour.GetText() == ComboBoxDefaultText) || (!PlayerOwner().Level.CanPlayerPlayMissionPrivate(PlayerOwner(), MIO.TourID, MIO.MissionID)))
		{
			bDeploy.DisableMe();
			break;
		}
		bDeploy.EnableMe();
	}
	if (co_Tour.GetText() == ComboBoxDefaultText)
	{
		bExploreMap.DisableMe();
	}
	else
	{
		bExploreMap.EnableMe();
	}
	if (MIO != None)
	{
		if (!DoesUserHaveMap(MIO.MapFilename))
		{
			SetDeployButtonToDCDS();
			bExploreMap.DisableMe();
		}
		else
		{
			SetDeployButtonToDeploy();
			bExploreMap.EnableMe();
			if (!PlayerOwner().Level.CanPlayerPlayMissionPrivate(PlayerOwner(), MIO.TourID, MIO.MissionID))
			{
				bDeploy.DisableMe();
			}
			else
			{
				bDeploy.EnableMe();
			}
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
	GOTO JL0240;
	default:
	JL0240:
	*/
}

bool UAADeploymentDetailsSubPanel::ButtonClick(UGUIComponent* Sender)
{
	/*
	local AABrowserPanel aasbBrowser;
	local AADeploy_DCDS DCDSPanel;
	local AAMainMenu aamm;
	local AADeploy_Internet aabslpi;
	local AADeploymentPanel aadp;
	local MissionInfoObject MIO;
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
	return true;
}

void UAADeploymentDetailsSubPanel::OnInterPanelLink(FString PanelName, int32 Param1, int32 Param2, FString Param3)
{
	/*
	local AAMainMenu aamm;
	local AADeploymentPanel aadp;
	local AADeploymentDetailsSubPanel aadd;
	local int32 NewComboBoxIndex;
	if (PanelName != "")
	{
		aamm = AAMainMenu(PageOwner);
		if (aamm != None)
		{
			aadp = AADeploymentPanel(aamm.c_Tab.BorrowPanel("DEPLOYMENT"));
			if (aadp != None)
			{
				aadp.c_Tabs.ActivateTabByName(PanelName, true);
				aadd = AADeploymentDetailsSubPanel(aadp.c_Tabs.BorrowPanel(PanelName));
				CurrentPage = aadd.DefaultPage;
				aadp = AADeploymentPanel(aamm.c_Tab.BorrowPanel("DEPLOYMENT"));
				if (aadd != None)
				{
					SetFocus(aadd);
				}
			}
		}
	}
	else
	{
		if (Param1 != 0)
		{
			NewComboBoxIndex = co_Tour.FindIndex(PlayerOwner().Level.GetTourMissionTitle(Param1, Param2), false);
			if (NewComboBoxIndex >= 0)
			{
				co_Tour.SetIndex(NewComboBoxIndex);
			}
		}
	}
	*/
}

void UAADeploymentDetailsSubPanel::SetDeployButtonToDCDS()
{
	//bDeploy.Caption = "DOWNLOAD";
	//bDeploy.EnableMe();
	bUserHasThisMap = false;
}

void UAADeploymentDetailsSubPanel::SetDeployButtonToDeploy()
{
	//bDeploy.Caption = "DEPLOY";
	bUserHasThisMap = true;
}
