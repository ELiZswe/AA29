// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AATraining_Details/AATraining_Details.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moComboBox/moComboBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIContentBox/GUIContentBox.h"

UAATraining_Details::UAATraining_Details()
{
	UmoComboBox* MyTourCombo = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	MyTourCombo->bReadOnly=true;
	MyTourCombo->CaptionWidth=0;
	//MyTourCombo->OnCreateComponent=MyTourCombo.InternalOnCreateComponent;
	MyTourCombo->IniOption="@Internal";
	MyTourCombo->Hint="Review Missions";
	MyTourCombo->WinTop=0.06625;
	MyTourCombo->WinLeft=0.3;
	MyTourCombo->WinWidth=0.4;
	MyTourCombo->bStandardized=false;
	//MyTourCombo->OnChange=AATraining_Details.InternalOnChange;
	//MyTourCombo->OnLoadINI=AATraining_Details.InternalOnLoadINI;
	UGUIButton* DeployButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	DeployButton->Caption="DEPLOY";
	DeployButton->FontScale = EFontScale::FNS_Small;
	DeployButton->Hint="Load this training mission";
	DeployButton->WinTop=0.965;
	DeployButton->WinLeft=0.505;
	DeployButton->WinWidth=0.16;
	DeployButton->WinHeight=0.036;
	DeployButton->RenderWeight=0.8;
	//DeployButton->OnClick=AATraining_Details.ButtonClick;
	//DeployButton->OnKeyEvent=DeployButton.InternalOnKeyEvent;
	UGUIButton* BackButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	BackButton->Caption="BACK";
	BackButton->FontScale = EFontScale::FNS_Small;
	BackButton->Hint="Back to the mission overview page";
	BackButton->WinTop=0.965;
	BackButton->WinLeft=0.335;
	BackButton->WinWidth=0.16;
	BackButton->WinHeight=0.036;
	BackButton->RenderWeight=0.8;
	BackButton->bBoundToParent=true;
	BackButton->bScaleToParent=true;
	//BackButton->OnClick=AATraining_Details.ButtonClick;
	//BackButton->OnKeyEvent=BackButton.InternalOnKeyEvent;
	UGUIContentBox* MyPanel = NewObject<UGUIContentBox>(UGUIContentBox::StaticClass());
	MyPanel->ItemSpacing=0.02;
	MyPanel->bScaleItemsToWidth=true;
	MyPanel->WinTop=0.105;
	MyPanel->WinHeight=0.84375;
	MyPanel->RenderWeight=0.6;
	MyPanel->bBoundToParent=true;
	MyPanel->bScaleToParent=true;

	guicbPanel = MyPanel;
	co_Tour = MyTourCombo;
	bDeploy = DeployButton;
	bBack = BackButton;
	ToursFile = "Tours.ini";
	DefaultPage = "/x_training_mission.nml";
	PanelCaption = "Basic Combat Training Objectives";
}

void UAATraining_Details::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	Super::InitComponent(MyController, MyOwner);
	bIsFirstLoad = true;
	MyNML = new (None) class'AGP_Interface.NMLContent';
	if (MyNML != None)
	{
		if (MyNML.Controller == None)
		{
			MyNML.InitComponent(MyController, MyOwner);
		}
	}
	bDeploy.DisableMe();
	*/
}

void UAATraining_Details::ShowPanel(bool bShow)
{
	/*
	local MissionInfoObject MIO;
	Super::ShowPanel(bShow);
	MIO = MissionInfoObject(co_Tour.GetObject());
	if (PlayerOwner().Level.CanPlayerPlayMissionPrivate(PlayerOwner(), MIO.TourID, MIO.MissionID) && AAGUIController(Controller).bLoggedIn)
	{
		bDeploy.EnableMe();
	}
	else
	{
		bDeploy.DisableMe();
	}
	*/
}

void UAATraining_Details::InternalOnLoadINI(UGUIComponent* Sender, FString S)
{
	/*
	switch (Sender)
	{
	case co_Tour:
		if (bIsFirstLoad)
		{
			PopulateComboBox();
		}
		bIsFirstLoad = false;
		break;
	default:
	}
	*/
}

void UAATraining_Details::PopulateComboBox()
{
	/*
	int32 NumMissions = 0;
	int32 i = 0;
	int32 j = 0;
	FString File = "";
	FString TourName = "";
	local MissionInfoObject MissionInfo;
	local TArray<int32> ValidTours;
	File = GetBaseDir() $ ToursFile;
	co_Tour.ResetComponent();
	for (i = 0; i < GetPrivateProfileInt(File, "Tours", "NumTours"); i++)
	{
		if (PlayerOwner().Level.GetTourIsTraining(i))
		{
			ValidTours[ValidTours.Length] = i;
		}
	}
	for (i = 0; i < ValidTours.Length; i++)
	{
		TourName = GetPrivateProfileString(File, "Tours", "Tour(" $ string(ValidTours[i]) $ ")");
		NumMissions = GetPrivateProfileInt(File, TourName, "NumMissions");
		for (j = 0; j < NumMissions; j++)
		{
			MissionInfo = new (None) class'AGP_Interface.MissionInfoObject';
			MissionInfo.TourID = ValidTours[i];
			MissionInfo.MissionID = j;
			co_Tour.addItem(GetPrivateProfileString(File, TourName, "MissionTitle(" $ string(j) $ ")"), MissionInfo, GetPrivateProfileString(File, TourName, "MissionNMLFilename(" $ string(j) $ ")"));
		}
	}
	if (bIsFirstLoad)
	{
		InternalOnChange(co_Tour);
	}
	*/
}

void UAATraining_Details::InternalOnChange(UGUIComponent* Sender)
{
	/*
	local MissionInfoObject MIO;
	switch (Sender)
	{
	case co_Tour:
		if (MyNML != None)
		{
			MIO = MissionInfoObject(co_Tour.GetObject());
			if ((!PlayerOwner().Level.CanPlayerPlayMissionPrivate(PlayerOwner(), MIO.TourID, MIO.MissionID)) || (!AAGUIController(Controller).bLoggedIn))
			{
				bDeploy.DisableMe();
				break;
			}
			bDeploy.EnableMe();
		}
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
	GOTO JL015A;
	default:
	JL015A:
	*/
}

bool UAATraining_Details::ButtonClick(UGUIComponent* Sender)
{
	/*
	local MissionInfoObject MIO;
	local AAMainMenu aamm;
	local AATrainingPanel aatp;
	if (Sender == bDeploy)
	{
		MIO = MissionInfoObject(co_Tour.GetObject());
		if (HumanController(PlayerOwner()) != None)
		{
			if (((HumanController(PlayerOwner()).UserName ~= "UserName") || (HumanController(PlayerOwner()).UserPassword ~= "UserPassword")) || (Len(HumanController(PlayerOwner()).UserPassword) == 0))
			{
				Controller.OpenMenu("AGP_Interface.AAGenericMessageBox", "Profile Not Found", "You must login in order to do training.");
				return false;
			}
		}
		PlayerOwner().ConsoleCommand("start " $ PlayerOwner().Level.GetTourMissionMapFilename(MIO.TourID, MIO.MissionID));
		Controller.CloseMenu(false);
	}
	else
	{
		if (Sender == bBack)
		{
			aamm = AAMainMenu(PageOwner);
			if (aamm != None)
			{
				aatp = AATrainingPanel(aamm.c_Tab.BorrowPanel("TRAINING"));
				if (aatp != None)
				{
					aatp.c_Tabs.ActivateTabByName("Overview", true);
				}
			}
		}
	}
	*/
	return true;
}
