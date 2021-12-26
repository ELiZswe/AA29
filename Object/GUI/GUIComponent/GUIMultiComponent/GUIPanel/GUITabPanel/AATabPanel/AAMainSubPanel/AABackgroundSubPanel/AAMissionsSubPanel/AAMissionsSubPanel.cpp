// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AAMissionsSubPanel/AAMissionsSubPanel.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moComboBox/moComboBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIScrollTextBox/GUIScrollTextBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"

UAAMissionsSubPanel::UAAMissionsSubPanel()
{
	UmoComboBox* MyTourCombo = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	MyTourCombo->bReadOnly=true;
	MyTourCombo->CaptionWidth=0.2;
	MyTourCombo->Caption="Tours";
	MyTourCombo->LabelFont="AAFontLabel";
	//MyTourCombo->OnCreateComponent=MyTourCombo.InternalOnCreateComponent;
	MyTourCombo->IniOption="@Internal";
	MyTourCombo->Hint="Select the tour you would like to see missions for.";
	MyTourCombo->WinTop=0.07;
	MyTourCombo->WinLeft=0.01;
	MyTourCombo->WinWidth=0.48;
	MyTourCombo->WinHeight=0.053476;
	MyTourCombo->bStandardized=false;
	//MyTourCombo->OnChange=AAMissionsSubPanel.InternalOnChange;
	//MyTourCombo->OnLoadINI=AAMissionsSubPanel.InternalOnLoadINI;
	UmoComboBox* MyMissionCombo = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	MyMissionCombo->bReadOnly=true;
	MyMissionCombo->CaptionWidth=0.2;
	MyMissionCombo->Caption="Missions";
	MyMissionCombo->LabelFont="AAFontLabel";
	//MyMissionCombo->OnCreateComponent=MyMissionCombo.InternalOnCreateComponent;
	MyMissionCombo->IniOption="@Internal";
	MyMissionCombo->Hint="Select the mission you would like to train in.";
	MyMissionCombo->WinTop=0.07;
	MyMissionCombo->WinLeft=0.51;
	MyMissionCombo->WinWidth=0.48;
	MyMissionCombo->WinHeight=0.053476;
	MyMissionCombo->bStandardized=false;
	//MyMissionCombo->OnChange=AAMissionsSubPanel.InternalOnChange;
	UGUIScrollTextBox* MyDescList = NewObject<UGUIScrollTextBox>(UGUIScrollTextBox::StaticClass());
	MyDescList->bNoTeletype=true;
	MyDescList->bVisibleWhenEmpty=true;
	//MyDescList->OnCreateComponent=MyDescList.InternalOnCreateComponent;
	MyDescList->StyleName="MediumText";
	MyDescList->WinTop=0.53;
	MyDescList->WinLeft=0.02;
	MyDescList->WinWidth=0.96;
	MyDescList->WinHeight=0.38;
	MyDescList->bBoundToParent=true;
	MyDescList->bScaleToParent=true;
	UGUIButton* MyDeployButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	MyDeployButton->Caption="DEPLOY";
	MyDeployButton->StyleName="SquareMenuButton";
	MyDeployButton->Hint="Click here to begin mission.";
	MyDeployButton->WinTop=0.93;
	MyDeployButton->WinLeft=0.425;
	MyDeployButton->WinWidth=0.15;
	MyDeployButton->WinHeight=0.053476;
	MyDeployButton->RenderWeight=0.6;
	//MyDeployButton->OnClick=AAMissionsSubPanel.ButtonClick;
	//MyDeployButton->OnKeyEvent=MyDeployButton.InternalOnKeyEvent;
	UGUIImage* MyMapPanel = NewObject<UGUIImage>(UGUIImage::StaticClass());
	MyMapPanel->Image = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/field_translucen_Mat.field_translucen_Mat'"), NULL, LOAD_None, NULL);
	MyMapPanel->ImageStyle = EImgStyle::ISTY_Stretched;
	MyMapPanel->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	MyMapPanel->WinTop=0.13;
	MyMapPanel->WinLeft=0.01;
	MyMapPanel->WinWidth=0.48;
	MyMapPanel->WinHeight=0.38;
	MyMapPanel->RenderWeight=0.2;
	UGUIImage* MyTourPanel = NewObject<UGUIImage>(UGUIImage::StaticClass());
	MyTourPanel->Image = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/field_translucen_Mat.field_translucen_Mat'"), NULL, LOAD_None, NULL);
	MyTourPanel->ImageStyle = EImgStyle::ISTY_Stretched;
	MyTourPanel->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	MyTourPanel->WinTop=0.13;
	MyTourPanel->WinLeft=0.51;
	MyTourPanel->WinWidth=0.48;
	MyTourPanel->WinHeight=0.38;
	MyTourPanel->RenderWeight=0.2;
	UGUIImage* MapPic = NewObject<UGUIImage>(UGUIImage::StaticClass());
	MapPic->ImageStyle= EImgStyle::ISTY_Scaled;
	MapPic->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	MapPic->WinTop=0.14;
	MapPic->WinLeft=0.02;
	MapPic->WinWidth=0.46;
	MapPic->WinHeight=0.36;
	MapPic->RenderWeight=0.9;
	UGUIImage* tourIcon = NewObject<UGUIImage>(UGUIImage::StaticClass());
	tourIcon->ImageStyle = EImgStyle::ISTY_Justified;
	tourIcon->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	tourIcon->WinTop=0.14;
	tourIcon->WinLeft=0.645;
	tourIcon->WinWidth=0.21;
	tourIcon->WinHeight=0.28;
	tourIcon->RenderWeight=0.9;
	UGUILabel* MyTourLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	MyTourLabel->TextAlign = ETextAlign::TXTA_Center;
	MyTourLabel->TextColor=FColor(255, 255, 255, 255);
	MyTourLabel->StyleName="TextLabel";
	MyTourLabel->WinTop=0.39;
	MyTourLabel->WinLeft=0.5;
	MyTourLabel->WinWidth=0.5;
	MyTourLabel->WinHeight=0.04;
	UGUILabel* MyRequirementsLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	MyRequirementsLabel->TextAlign = ETextAlign::TXTA_Center;
	MyRequirementsLabel->TextColor=FColor(255, 255, 255, 255);
	MyRequirementsLabel->TextFont="AAFontLabel";
	MyRequirementsLabel->WinTop=0.42;
	MyRequirementsLabel->WinLeft=0.5;
	MyRequirementsLabel->WinWidth=0.5;
	MyRequirementsLabel->WinHeight=0.04;
	UGUILabel* MyStatusLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	MyStatusLabel->TextAlign = ETextAlign::TXTA_Center;
	MyStatusLabel->TextColor=FColor(255, 255, 255, 255);
	MyStatusLabel->TextFont="AAFontLabel";
	MyStatusLabel->WinTop=0.45;
	MyStatusLabel->WinLeft=0.5;
	MyStatusLabel->WinWidth=0.5;
	MyStatusLabel->WinHeight=0.04;
	UGUIImage* MyDescPanel = NewObject<UGUIImage>(UGUIImage::StaticClass());
	MyDescPanel->Image = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/field_translucen_Mat.field_translucen_Mat'"), NULL, LOAD_None, NULL);
	MyDescPanel->ImageStyle = EImgStyle::ISTY_Stretched;
	MyDescPanel->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	MyDescPanel->WinTop=0.52;
	MyDescPanel->WinLeft=0.01;
	MyDescPanel->WinWidth=0.98;
	MyDescPanel->WinHeight=0.4;
	MyDescPanel->RenderWeight=0.2;
	co_Tour = MyTourCombo;
	co_Mission = MyMissionCombo;
	p_Map = MyMapPanel;
	p_Tour = MyTourPanel;
	p_Description = MyDescPanel;
	i_Map = MapPic;
	i_Tour = tourIcon;
	l_Tour = MyTourLabel;
	l_Requirements = MyRequirementsLabel;
	l_Status = MyStatusLabel;
	lb_Description = MyDescList;
	b_Deploy = MyDeployButton;

	NotAvailableText = "Not Available";
	AvailableText = "Available";
	CompletedText = "Completed";
	MissionFilters = { "All", "Training", "Deployment" };
	NotAvailableColor = FColor(0, 0, 192, 255);
	AvailableColor = FColor(64, 255, 0, 255);
	CompletedColor = FColor(255, 255, 255, 255);
	ToursFile = "Tours.ini";
	bAreMissionsAlphabetized = true;
}

void UAAMissionsSubPanel::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	Super::InitComponent(MyController, MyOwner);
	BriefingDir = GetBaseDir();
	BriefingDir = Left(BriefingDir, (Len(BriefingDir) - 7));
	BriefingDir = BriefingDir $ "Briefings\\";
	InitializeCombos();
	SetTimer(1, true);
	*/
}

void UAAMissionsSubPanel::InitializeCombos()
{
}

void UAAMissionsSubPanel::InternalOnLoadINI(UGUIComponent* Sender, FString S)
{
	/*
	switch (Sender)
	{
	case co_Tour:
		LoadToursAndMissions();
		break;
	case co_Mission:
		break;
	default:
	}
	*/
}

void UAAMissionsSubPanel::LoadToursAndMissions()
{
	/*
	local int32 NumTours;
	local int32 i;
	local FString File;
	local AAGUIController C;
	C = AAGUIController(Controller);
	File = GetBaseDir() $ ToursFile;
	co_Tour.ResetComponent();
	co_Mission.ResetComponent();
	NumTours = GetPrivateProfileInt(File, "Tours", "NumTours");
	for (i = 0; i < NumTours; i++)
	{
		if (UseTraining(i) && ((i != C.4) || (!C.bFilterNoSniper)))
		{
			co_Tour.addItem(PlayerOwner().Level.GetTourName(i), , string(i));
		}
	}
	TourID = int(co_Tour.GetExtra());
	ReloadMissions();
	UpdateTourInfo();
	UpdateMissionStatus();
	*/
}

void UAAMissionsSubPanel::ReloadMissions()
{
	/*
	local int32 NumMissions;
	local int32 i;
	local int32 j;
	local FString MissionName;
	local TArray<FString> MissionNames;
	local TArray<int32> MissionNums;
	co_Mission.RemoveItem(0, co_Mission.ItemCount());
	NumMissions = PlayerOwner().Level.GetTourMissions(TourID);
	if (bAreMissionsAlphabetized)
	{
		for (i = 0; i < NumMissions; i++)
		{
			MissionName = PlayerOwner().Level.GetTourMissionTitle(TourID, i);
			j = 0;
			if (j < MissionNames.Length)
			{
				if (MissionName <= MissionNames[j])
				{
				}
				else
				{
					if (((j + 1) < MissionNames.Length) && (MissionName <= MissionNames[(j + 1)]))
					{
						j++;
					}
				}
			else
			{
				j++;
			}
			}
			if (j < MissionNames.Length)
			{
				MissionNames.insert(j, 1);
				MissionNums.insert(j, 1);
			}
			MissionNames[j] = MissionName;
			MissionNums[j] = i;
		}
		for (i = 0; i < NumMissions; i++)
		{
			co_Mission.addItem(MissionNames[i], , string(MissionNums[i]));
		}
	}
	else
	{
		for (i = 0; i < NumMissions; i++)
		{
			co_Mission.addItem(PlayerOwner().Level.GetTourMissionTitle(TourID, i), , string(i));
		}
	}
	MissionID = int(co_Mission.GetExtra());
	*/
}

void UAAMissionsSubPanel::InternalOnChange(UGUIComponent* Sender)
{
	/*
	local int32 Num;
	local int32 i;
	if (!Controller.bCurMenuInitialized)
	{
		return;
	}
	if (Sender == co_Tour)
	{
		TourID = int(co_Tour.GetExtra());
		ReloadMissions();
		for (i = 0; i < Num; i++)
		{
			co_Mission.addItem(PlayerOwner().Level.GetTourMissionTitle(TourID, i), , string(i));
		}
		MissionID = int(co_Mission.GetExtra());
	}
	else
	{
		if (Sender == co_Mission)
		{
			MissionID = int(co_Mission.GetExtra());
		}
	}
	UpdateTourInfo();
	UpdateMissionStatus();
	*/
}

bool UAAMissionsSubPanel::UseTraining(int32 Tour)
{
	return true;
}

bool UAAMissionsSubPanel::ShouldDisableSniper()
{
	/*
	if (AAGUIController(Controller) != None)
	{
		return ((TourID == AAGUIController(Controller).4) && AAGUIController(Controller).bFilterNoSniper);
	}
	*/
	return false;
}

bool UAAMissionsSubPanel::ShouldDisableLifeFire()
{
	/*
	if (AAGUIController(Controller) != None)
	{
		return AAGUIController(Controller).bFilterMilesOnly;
	}
	*/
	return false;
}

void UAAMissionsSubPanel::SetStatusCaption(int32 Status)
{
	/*
	if (ShouldDisableSniper() || ((AAGUIController(Controller) != None) && (!AAGUIController(Controller).LoggedIn())))
	{
		l_Status.TextColor = NotAvailableColor;
		l_Status.Caption = NotAvailableText;
	}
	*/
}

void UAAMissionsSubPanel::Timer()
{
	//UpdateMissionStatus();
}

void UAAMissionsSubPanel::UpdateMissionStatus()
{
	/*
	local FString MissionImage;
	if ((PlayerOwner().Level.CanPlayerPlayMissionPrivate(PlayerOwner(), TourID, MissionID) && (!ShouldDisableSniper())) && AAGUIController(Controller).LoggedIn())
	{
		MissionImage = PlayerOwner().Level.GetTourMissionImage(TourID, MissionID);
	}
	else
	{
		MissionImage = PlayerOwner().Level.GetTourMissionImageDisabled(TourID, MissionID);
	}
	i_Map.Image = Material(DynamicLoadObject(MissionImage, Class'Material', true));
	SetStatusCaption(PlayerOwner().Level.GetMissionStatus(TourID, MissionID));
	CanDeploy();
	*/
}

void UAAMissionsSubPanel::CanDeploy()
{
	/*
	local GUI.eMenuState CurrentMenuState;
	if (b_Deploy == nullptr)
	{
		return;
	}
	if (b_Deploy.MenuState != 4)
	{
		CurrentMenuState = b_Deploy.MenuState;
	}
	if (((!PlayerOwner().Level.CanPlayerPlayMissionPrivate(PlayerOwner(), TourID, MissionID)) || ShouldDisableSniper()) || ((AAGUIController(Controller) != None) && (!AAGUIController(Controller).LoggedIn())))
	{
		b_Deploy.MenuStateChange(4);
	}
	else
	{
		b_Deploy.MenuStateChange(CurrentMenuState);
	}
	*/
}

bool UAAMissionsSubPanel::ButtonClick(UGUIComponent* Sender)
{
	return true;
}

void UAAMissionsSubPanel::UpdateTourInfo()
{
	/*
	local AAGUIController C;
	local FString S;
	local int32 i;
	C = AAGUIController(Controller);
	i_Tour.Image = Material(DynamicLoadObject(PlayerOwner().Level.GetTourImage(TourID), Class'Material', true));
	l_Tour.Caption = PlayerOwner().Level.GetTourMissionTitle(TourID, MissionID);
	i = PlayerOwner().Level.GetTourDependency(TourID);
	S = PlayerOwner().Level.GetTourName(i);
	if (S == "")
	{
		l_Requirements.Caption = "Requirements: None";
	}
	else
	{
		l_Requirements.Caption = "Requirements: " $ S;
	}
	if ((TourID == 0) && (MissionID == 3))
	{
		S = "THE FINAL BCT CHALLENGE|" $ C.LoadTextFromFile(BriefingDir $ "mout.txt") $ "|||" $ Caps(PlayerOwner().Level.GetTourHistoryTextTitle(TourID)) $ "|" $ C.LoadTextFromFile(BriefingDir $ PlayerOwner().Level.GetTourHistoryText(TourID) $ ".txt") $ "|||" $ Caps(PlayerOwner().Level.GetTourTextTitle(TourID)) $ "|" $ C.LoadTextFromFile(BriefingDir $ PlayerOwner().Level.GetTourText(TourID) $ ".txt");
	}
	else
	{
		S = Caps(PlayerOwner().Level.GetTourHistoryTextTitle(TourID)) $ "|" $ C.LoadTextFromFile(BriefingDir $ PlayerOwner().Level.GetTourHistoryText(TourID) $ ".txt") $ "||" $ Caps(PlayerOwner().Level.GetTourTextTitle(TourID)) $ "|" $ C.LoadTextFromFile(BriefingDir $ PlayerOwner().Level.GetTourText(TourID) $ ".txt") $ "||" $ Caps(PlayerOwner().Level.GetTourMissionTitle(TourID, MissionID)) $ "|" $ C.LoadTextFromFile(BriefingDir $ PlayerOwner().Level.GetTourMissionMapFilename(TourID, MissionID) $ ".txt");
	}
	lb_Description.SetContent(S);
	*/
}
