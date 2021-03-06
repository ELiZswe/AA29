// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AATraining_Details/AATraining_Details.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moComboBox/moComboBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIContentBox/GUIContentBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"
#include "AA29/Object/GUI/GUIComponent/NMLContent/NMLContent.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/AAMainMenu/AAMainMenu.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainPanel/AATrainingPanel/AATrainingPanel.h"
#include "AA29/Object/MissionInfoObject/MissionInfoObject.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/AAGUIController/AAGUIController.h"

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
	DeployButton->FontScale = EeFontScale::FNS_Small;
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
	BackButton->FontScale = EeFontScale::FNS_Small;
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
	MyNML = new (None) UNMLContent::StaticClass();
	if (MyNML != nullptr)
	{
		if (MyNML.Controller == nullptr)
		{
			MyNML.InitComponent(MyController, MyOwner);
		}
	}
	bDeploy.DisableMe();
	*/
}

void UAATraining_Details::ShowPanel(bool bShow)
{
	UMissionInfoObject* MIO = nullptr;
	Super::ShowPanel(bShow);
	MIO = Cast<UMissionInfoObject>(co_Tour->GetObject());
	/*
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
	int32 NumMissions = 0;
	int32 i = 0;
	int32 j = 0;
	FString File = "";
	FString TourName = "";
	UMissionInfoObject* MissionInfo = nullptr;
	TArray<int32> ValidTours= {};
	/*
	File = GetBaseDir() + ToursFile;
	co_Tour.ResetComponent();
	for (i = 0; i < GetPrivateProfileInt(File, "Tours", "NumTours"); i++)
	{
		if (PlayerOwner().Level.GetTourIsTraining(i))
		{
			ValidTours[ValidTours.Num()] = i;
		}
	}
	for (i = 0; i < ValidTours.Num(); i++)
	{
		TourName = GetPrivateProfileString(File, "Tours", "Tour(" + FString::FromInt(ValidTours[i]) + ")");
		NumMissions = GetPrivateProfileInt(File, TourName, "NumMissions");
		for (j = 0; j < NumMissions; j++)
		{
			MissionInfo = new (None) UMissionInfoObject::StaticClass();
			MissionInfo.TourID = ValidTours[i];
			MissionInfo.MissionID = j;
			co_Tour.addItem(GetPrivateProfileString(File, TourName, "MissionTitle(" + FString::FromInt(j) + ")"), MissionInfo, GetPrivateProfileString(File, TourName, "MissionNMLFilename(" + FString::FromInt(j) + ")"));
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
	UMissionInfoObject* MIO = nullptr;
	/*
	switch (Sender)
	{
	case co_Tour:
		if (MyNML != nullptr)
		{
			MIO = MissionInfoObject(co_Tour.GetObject());
			if ((!PlayerOwner().Level.CanPlayerPlayMissionPrivate(PlayerOwner(), MIO.TourID, MIO.MissionID)) || (!Cast<UAAGUIController>(Controller).bLoggedIn))
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
	UMissionInfoObject* MIO = nullptr;
	UAAMainMenu* aamm = nullptr;
	UAATrainingPanel* aatp = nullptr;
	/*
	if (Sender == bDeploy)
	{
		MIO = MissionInfoObject(co_Tour.GetObject());
		if (Cast<AHumanController>(PlayerOwner()) != nullptr)
		{
			if (((Cast<AHumanController>(PlayerOwner())->UserName ~= "UserName") || (Cast<AHumanController>(PlayerOwner())->UserPassword ~= "UserPassword")) || (Len(Cast<AHumanController>(PlayerOwner())->UserPassword) == 0))
			{
				Controller.OpenMenu("AGP_Interface.AAGenericMessageBox", "Profile Not Found", "You must login in order to do training.");
				return false;
			}
		}
		PlayerOwner().ConsoleCommand("start " + PlayerOwner().Level.GetTourMissionMapFilename(MIO.TourID, MIO.MissionID));
		Controller.CloseMenu(false);
	}
	else
	{
		if (Sender == bBack)
		{
			aamm = AAMainMenu(PageOwner);
			if (aamm != nullptr)
			{
				aatp = AATrainingPanel(aamm.c_Tab.BorrowPanel("TRAINING"));
				if (aatp != nullptr)
				{
					aatp.c_Tabs.ActivateTabByName("Overview", true);
				}
			}
		}
	}
	*/
	return true;
}
