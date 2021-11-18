// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AATraining_Overview/AATraining_Overview.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIContentBox/GUIContentBox.h"

UAATraining_Overview::UAATraining_Overview()
{
	UGUIContentBox* MyPanel = NewObject<UGUIContentBox>(UGUIContentBox::StaticClass());
	MyPanel->ItemSpacing=0.02;
	MyPanel->bScaleItemsToWidth=true;
	MyPanel->WinTop=0.06625;
	MyPanel->WinHeight=0.8825;
	MyPanel->RenderWeight=0.6;
	MyPanel->bBoundToParent=true;
	MyPanel->bScaleToParent=true;

	guicbPanel = MyPanel;
	DefaultPage = "/x_training_overview.nml";
	PanelCaption = "America's Army Training Overview";
}

void UAATraining_Overview::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	Super::InitComponent(MyController, MyOwner);
	MyNML = new (None) class'AGP_Interface.NMLContent';
	if (MyNML != None)
	{
		if (MyNML.Controller == None)
		{
			MyNML.InitComponent(MyController, MyOwner);
		}
		MyNML.__dInterPanelLink__Delegate = OnInterPanelLink;
		MyNML.__dPreParser__Delegate = TrainingNMLPreParser;
		MyNML.ParseNMLFromServer(DefaultPage, "dms1.americasarmy.com", 80, guicbPanel, i_NMLStatusIcon, l_NMLStatusText);
	}
	*/
}

void UAATraining_Overview::ShowPanel(bool bShow)
{
	/*
	if (bShow && bHasLeftPage)
	{
		bHasLeftPage = false;
		MyNML.ParseNMLFromFile(MyNML.FixFilePath(DefaultPage), guicbPanel);
	}
	else
	{
		bHasLeftPage = true;
	}
	*/
}

void UAATraining_Overview::OnInterPanelLink(FString PanelName, int32 Param1, int32 Param2, FString Param3)
{
	/*
	local AAMainMenu aamm;
	local AATrainingPanel aatp;
	local AATraining_Details aatd;
	int32 NewComboBoxIndex = 0;
	aamm = AAMainMenu(PageOwner);
	if (aamm != None)
	{
		aatp = AATrainingPanel(aamm.c_Tab.BorrowPanel("TRAINING"));
		if (aatp != None)
		{
			aatd = AATraining_Details(aatp.c_Tabs.BorrowPanel("Details"));
			if (aatd != None)
			{
				NewComboBoxIndex = aatd.co_Tour.FindIndex(PlayerOwner().Level.GetTourMissionTitle(Param1, Param2), false);
				if (NewComboBoxIndex >= 0)
				{
					aatd.co_Tour.SetIndex(NewComboBoxIndex);
					aatp.c_Tabs.ActivateTabByName("Details", true);
				}
			}
		}
	}
	*/
}

void UAATraining_Overview::TrainingNMLPreParser(FString& TrainingNML)
{
	/*
	local AAMainMenu aamm;
	local AARecordBriefPanel rbp;
	local AARecordBrief_Badges rbb;
	local LevelInfo PL;
	FString ReplString = "";
	int32 iBCTQualification = 0;
	int32 iAirborneQualification = 0;
	int32 iMedicQualification = 0;
	int32 iAdvMarksmanQualification = 0;
	int32 iSFQualification = 0;
	int32 iAdvInfQualification = 0;
	if (PlayerOwner() == None)
	{
		return;
	}
	PL = PlayerOwner().Level;
	aamm = AAMainMenu(PageOwner);
	if (aamm != None)
	{
		rbp = AARecordBriefPanel(aamm.c_Tab.BorrowPanel("RECORD BRIEF"));
		if (rbp != None)
		{
			rbb = AARecordBrief_Badges(rbp.c_Tabs.BorrowPanel("Badges"));
			if (rbb != None)
			{
				iBCTQualification = rbb.BCTQualification();
				iAirborneQualification = rbb.AirborneQualification();
				iMedicQualification = rbb.MedicQualification();
				iAdvMarksmanQualification = rbb.AdvMarksmanQualification();
				iSFQualification = rbb.SFQualification();
				iAdvInfQualification = rbb.EIBQualification();
			}
		}
	}
	switch (iBCTQualification)
	{
	case 0:
		ReplString = "NOT AVAILABLE";
		break;
	case 1:
		ReplString = "AVAILABLE";
		break;
	default:
		ReplString = "COMPLETED";
		break;
	}
	if (PL != None)
	{
		GreyOutImages(TrainingNML, "BCT.0", (!PL.CanPlayerPlayMissionPrivate(PlayerOwner(), 0, 0)));
		GreyOutImages(TrainingNML, "BCT.1", (!PL.CanPlayerPlayMissionPrivate(PlayerOwner(), 0, 1)));
		GreyOutImages(TrainingNML, "BCT.2", (!PL.CanPlayerPlayMissionPrivate(PlayerOwner(), 0, 2)));
		GreyOutImages(TrainingNML, "BCT.3", (!PL.CanPlayerPlayMissionPrivate(PlayerOwner(), 0, 3)));
	}
	else
	{
		GreyOutImages(TrainingNML, "BCT.0", (iBCTQualification == 0));
		GreyOutImages(TrainingNML, "BCT.1", (iBCTQualification == 0));
		GreyOutImages(TrainingNML, "BCT.2", (iBCTQualification == 0));
		GreyOutImages(TrainingNML, "BCT.3", (iBCTQualification == 0));
	}
	ReplaceText(TrainingNML, "%BCTStatus%", ReplString);
	switch (iAirborneQualification)
	{
	case 0:
		ReplString = "NOT AVAILABLE";
		break;
	case 1:
		ReplString = "AVAILABLE";
		break;
	default:
		ReplString = "COMPLETED";
		break;
	}
	if (PL != None)
	{
		GreyOutImages(TrainingNML, "Airborne.0", (!PL.CanPlayerPlayMissionPrivate(PlayerOwner(), 5, 0)));
		GreyOutImages(TrainingNML, "Airborne.1", (!PL.CanPlayerPlayMissionPrivate(PlayerOwner(), 5, 1)));
	}
	else
	{
		GreyOutImages(TrainingNML, "Airborne.0", (iAirborneQualification == 0));
		GreyOutImages(TrainingNML, "Airborne.1", (iAirborneQualification == 0));
	}
	ReplaceText(TrainingNML, "%AirborneStatus%", ReplString);
	switch (iMedicQualification)
	{
	case 0:
		ReplString = "NOT AVAILABLE";
		break;
	case 1:
		ReplString = "AVAILABLE";
		break;
	default:
		ReplString = "COMPLETED";
		break;
	}
	if (PL != None)
	{
		GreyOutImages(TrainingNML, "Medic.0", (!PL.CanPlayerPlayMissionPrivate(PlayerOwner(), 9, 0)));
		GreyOutImages(TrainingNML, "Medic.1", (!PL.CanPlayerPlayMissionPrivate(PlayerOwner(), 9, 1)));
		GreyOutImages(TrainingNML, "Medic.2", (!PL.CanPlayerPlayMissionPrivate(PlayerOwner(), 9, 2)));
		GreyOutImages(TrainingNML, "Medic.3", (!PL.CanPlayerPlayMissionPrivate(PlayerOwner(), 9, 3)));
	}
	else
	{
		GreyOutImages(TrainingNML, "Medic.0", (iMedicQualification == 0));
		GreyOutImages(TrainingNML, "Medic.1", (iMedicQualification == 0));
		GreyOutImages(TrainingNML, "Medic.2", (iMedicQualification == 0));
		GreyOutImages(TrainingNML, "Medic.3", (iMedicQualification == 0));
	}
	ReplaceText(TrainingNML, "%MedicStatus%", ReplString);
	switch (iAdvMarksmanQualification)
	{
	case 0:
		ReplString = "NOT AVAILABLE";
		break;
	case 1:
		ReplString = "AVAILABLE";
		break;
	default:
		ReplString = "COMPLETED";
		break;
	}
	if (PL != None)
	{
		GreyOutImages(TrainingNML, "AdvMarksman.0", (!PL.CanPlayerPlayMissionPrivate(PlayerOwner(), 4, 0)));
		GreyOutImages(TrainingNML, "AdvMarksman.1", (!PL.CanPlayerPlayMissionPrivate(PlayerOwner(), 4, 1)));
	}
	else
	{
		GreyOutImages(TrainingNML, "AdvMarksman.0", (iAdvMarksmanQualification == 0));
		GreyOutImages(TrainingNML, "AdvMarksman.1", (iAdvMarksmanQualification == 0));
	}
	ReplaceText(TrainingNML, "%AdvMarksmanStatus%", ReplString);
	switch (iSFQualification)
	{
	case 0:
		ReplString = "NOT AVAILABLE";
		break;
	case 1:
		ReplString = "AVAILABLE";
		break;
	default:
		ReplString = "COMPLETED";
		break;
	}
	if (PL != None)
	{
		GreyOutImages(TrainingNML, "SF.0", (!PL.CanPlayerPlayMissionPrivate(PlayerOwner(), 10, 0)));
		GreyOutImages(TrainingNML, "SF.1", (!PL.CanPlayerPlayMissionPrivate(PlayerOwner(), 10, 1)));
	}
	else
	{
		GreyOutImages(TrainingNML, "SF.0", (iSFQualification == 0));
		GreyOutImages(TrainingNML, "SF.1", (iSFQualification == 0));
	}
	ReplaceText(TrainingNML, "%SFStatus%", ReplString);
	switch (iAdvInfQualification)
	{
	case 0:
		ReplString = "NOT AVAILABLE";
		break;
	case 1:
		ReplString = "AVAILABLE";
		break;
	default:
		ReplString = "COMPLETED";
		break;
	}
	if (PL != None)
	{
		GreyOutImages(TrainingNML, "AdvInf.0", (!PL.CanPlayerPlayMissionPrivate(PlayerOwner(), 13, 0)));
		GreyOutImages(TrainingNML, "AdvInf.1", (!PL.CanPlayerPlayMissionPrivate(PlayerOwner(), 13, 1)));
		GreyOutImages(TrainingNML, "AdvInf.2", (!PL.CanPlayerPlayMissionPrivate(PlayerOwner(), 13, 2)));
		GreyOutImages(TrainingNML, "AdvInf.3", (!PL.CanPlayerPlayMissionPrivate(PlayerOwner(), 13, 3)));
	}
	else
	{
		GreyOutImages(TrainingNML, "AdvInf.0", (iAdvInfQualification == 0));
		GreyOutImages(TrainingNML, "AdvInf.1", (iAdvInfQualification == 0));
		GreyOutImages(TrainingNML, "AdvInf.2", (iAdvInfQualification == 0));
		GreyOutImages(TrainingNML, "AdvInf.3", (iAdvInfQualification == 0));
	}
	ReplaceText(TrainingNML, "%AdvInfStatus%", ReplString);
	*/
}

void UAATraining_Overview::GreyOutImages(FString& NMLChunk, FString aTag, bool bDoGreyOut)
{
	/*
	if (bDoGreyOut)
	{
		ReplaceText(NMLChunk, "%" $ aTag $ "%", "_g");
	}
	else
	{
		ReplaceText(NMLChunk, "%" $ aTag $ "%", "");
	}
	*/
}