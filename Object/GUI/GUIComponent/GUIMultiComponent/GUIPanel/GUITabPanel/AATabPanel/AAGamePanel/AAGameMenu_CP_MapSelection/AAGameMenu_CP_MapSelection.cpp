// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAGamePanel/AAGameMenu_CP_MapSelection/AAGameMenu_CP_MapSelection.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIScrollTextBox/GUIScrollTextBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moComboBox/moComboBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"

UAAGameMenu_CP_MapSelection::UAAGameMenu_CP_MapSelection()
{
	UGUIScrollTextBox* MyDescList = NewObject<UGUIScrollTextBox>(UGUIScrollTextBox::StaticClass());
	MyDescList->bNoTeletype = true;
	MyDescList->bVisibleWhenEmpty = true;
	//MyDescList->OnCreateComponent=MyDescList.InternalOnCreateComponent;
	MyDescList->StyleName = "MediumText";
	MyDescList->WinTop = 0.48;
	MyDescList->WinLeft = 0.02;
	MyDescList->WinWidth = 0.96;
	MyDescList->WinHeight = 0.44;
	MyDescList->bBoundToParent = true;
	MyDescList->bScaleToParent = true;
	UmoComboBox* MyMissionCombo = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	MyMissionCombo->bReadOnly = true;
	MyMissionCombo->CaptionWidth = 0.2;
	MyMissionCombo->Caption = "Missions";
	MyMissionCombo->LabelFont = "AAFontLabel";
	//MyMissionCombo->OnCreateComponent=MyMissionCombo.InternalOnCreateComponent;
	MyMissionCombo->IniOption = "@Internal";
	MyMissionCombo->Hint = "Select the mission you would like to switch the server to.";
	MyMissionCombo->WinTop = 0.01;
	MyMissionCombo->WinLeft = 0.51;
	MyMissionCombo->WinWidth = 0.48;
	MyMissionCombo->WinHeight = 0.053476;
	MyMissionCombo->bStandardized = false;
	//MyMissionCombo->OnChange=AAGameMenu_CP_MapSelection.InternalOnChange;
	UmoComboBox* MyTourCombo = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	MyTourCombo->bReadOnly = true;
	MyTourCombo->CaptionWidth = 0.2;
	MyTourCombo->Caption = "Tours";
	MyTourCombo->LabelFont = "AAFontLabel";
	//MyTourCombo->OnCreateComponent=MyTourCombo.InternalOnCreateComponent;
	MyTourCombo->IniOption = "@Internal";
	MyTourCombo->Hint = "Select the tour you would like to see missions for.";
	MyTourCombo->WinTop = 0.01;
	MyTourCombo->WinLeft = 0.01;
	MyTourCombo->WinWidth = 0.48;
	MyTourCombo->WinHeight = 0.053476;
	MyTourCombo->bStandardized = false;
	//MyTourCombo->OnChange=AAGameMenu_CP_MapSelection.InternalOnChange;
	//MyTourCombo->OnLoadINI=AAGameMenu_CP_MapSelection.InternalOnLoadINI;
	UGUIButton* SwitchMapsButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	SwitchMapsButton->Caption = "Change Mission";
	SwitchMapsButton->StyleName = "SquareMenuButton";
	SwitchMapsButton->Hint = "Click here to switch the server to the currently displayed mission.";
	SwitchMapsButton->WinTop = 0.392082;
	SwitchMapsButton->WinLeft = 0.76;
	SwitchMapsButton->WinWidth = 0.2;
	SwitchMapsButton->WinHeight = 0.057;
	SwitchMapsButton->RenderWeight = 0.6;
	//SwitchMapsButton->OnClick=AAGameMenu_CP_MapSelection.ButtonClick;
	//SwitchMapsButton->OnKeyEvent=SwitchMapsButton.InternalOnKeyEvent;
	UGUILabel* InstructionsLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	InstructionsLabel->TextColor = FColor(255, 255, 255, 255);
	InstructionsLabel->bMultiLine = true;
	InstructionsLabel->StyleName = "TextLabel";
	InstructionsLabel->WinTop = 0.098308;
	InstructionsLabel->WinLeft = 0.758753;
	InstructionsLabel->WinWidth = 0.22;
	InstructionsLabel->WinHeight = 0.35;
	UGUIImage* MyMapPanel = NewObject<UGUIImage>(UGUIImage::StaticClass());
	MyMapPanel->Image = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/field_translucen_Mat.field_translucen_Mat'"), NULL, LOAD_None, NULL);
	MyMapPanel->ImageStyle = EImgStyle::ISTY_Stretched;
	MyMapPanel->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	MyMapPanel->WinTop = 0.08;
	MyMapPanel->WinLeft = 0.01;
	MyMapPanel->WinWidth = 0.48;
	MyMapPanel->WinHeight = 0.38;
	MyMapPanel->RenderWeight = 0.2;
	UGUIImage* MyTourPanel = NewObject<UGUIImage>(UGUIImage::StaticClass());
	MyTourPanel->Image = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/field_translucen_Mat.field_translucen_Mat'"), NULL, LOAD_None, NULL);
	MyTourPanel->ImageStyle = EImgStyle::ISTY_Stretched;
	MyTourPanel->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	MyTourPanel->WinTop = 0.08;
	MyTourPanel->WinLeft = 0.51;
	MyTourPanel->WinWidth = 0.48;
	MyTourPanel->WinHeight = 0.38;
	MyTourPanel->RenderWeight = 0.2;
	UGUIImage* MapPic = NewObject<UGUIImage>(UGUIImage::StaticClass());
	MapPic->ImageStyle = EImgStyle::ISTY_Scaled;
	MapPic->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	MapPic->WinTop = 0.09;
	MapPic->WinLeft = 0.02;
	MapPic->WinWidth = 0.46;
	MapPic->WinHeight = 0.36;
	MapPic->RenderWeight = 0.9;
	UGUIImage* tourIcon = NewObject<UGUIImage>(UGUIImage::StaticClass());
	tourIcon->ImageStyle = EImgStyle::ISTY_Justified;
	tourIcon->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	tourIcon->WinTop = 0.09;
	tourIcon->WinLeft = 0.532497;
	tourIcon->WinWidth = 0.21;
	tourIcon->WinHeight = 0.28;
	tourIcon->RenderWeight = 0.9;
	UGUILabel* MyTourLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	MyTourLabel->TextAlign = ETextAlign::TXTA_Center;
	MyTourLabel->TextColor = FColor(255, 255, 255, 255);
	MyTourLabel->StyleName = "TextLabel";
	MyTourLabel->WinTop = 0.397878;
	MyTourLabel->WinLeft = 0.44;
	MyTourLabel->WinWidth = 0.39;
	MyTourLabel->WinHeight = 0.04;
	UGUIImage* MyDescPanel = NewObject<UGUIImage>(UGUIImage::StaticClass());
	MyDescPanel->Image = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/field_translucen_Mat.field_translucen_Mat'"), NULL, LOAD_None, NULL);
	MyDescPanel->ImageStyle = EImgStyle::ISTY_Stretched;
	MyDescPanel->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	MyDescPanel->WinTop = 0.47;
	MyDescPanel->WinLeft = 0.01;
	MyDescPanel->WinWidth = 0.98;
	MyDescPanel->WinHeight = 0.45;
	MyDescPanel->RenderWeight = 0.2;
	gimgMapPanel = MyMapPanel;
	gimgTourPanel = MyTourPanel;
	gimgDescriptionPanel = MyDescPanel;
	gimgMap = MapPic;
	gimgTour = tourIcon;
	mcbTour = MyTourCombo;
	mcbMission = MyMissionCombo;
	gbtnSwitchMaps = SwitchMapsButton;
	glblTour = MyTourLabel;
	glblDescription = MyDescList;
	gulInstructions = InstructionsLabel;

	bAreMissionsAlphabetized = true;
	sInstructions = "Use the Tours and Missions drop-down lists to select the mission you would like to change the server to and then click ""Change Mission"".";
	WinTop = 0.1;
	WinHeight = 0.9;
	bTabStop = true;
}

void UAAGameMenu_CP_MapSelection::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	InitComponent(MyController, MyOwner);
	iTimeLeftBeforeSwitch = 0;
	gulInstructions.Caption = sInstructions;
	sBriefingDir = GetBaseDir();
	sBriefingDir = Left(sBriefingDir, Len(sBriefingDir) - 7);
	sBriefingDir = sBriefingDir $ "Briefings\";
	*/
}

bool UAAGameMenu_CP_MapSelection::IsAdmin()
{
	//Return PlayerOwner() != None && PlayerOwner().PlayerReplicationInfo != None && PlayerOwner().PlayerReplicationInfo.bAdmin;
	return false;    //FAKE   /ELIZ

}

void UAAGameMenu_CP_MapSelection::InternalOnLoadINI(UGUIComponent* Sender, FString S)
{
	/*
	Switch(Sender)
	{
			case mcbTour:
				LoadToursAndMissions();
				break;
			case mcbMission:
				break;
			default:
				Log(Name @ "Unknown component calling LoadINI:" $ GUIMenuOption(Sender).Caption);
				GUIMenuOption(Sender).SetComponentValue(S, True);
	}
	*/
}

void UAAGameMenu_CP_MapSelection::LoadToursAndMissions()
{
	/*
	local int NumTours;
	local int i;
	local FString File;
	local AAGUIController C;
	File = GetBaseDir() $ "Tours.ini";
	C = AAGUIController(Controller);
	mcbTour.ResetComponent();
	mcbMission.ResetComponent();
	NumTours = GetPrivateProfileInt(File, "Tours", "NumTours");
	for (i = 0; i < NumTours; i++)
	{
		if (!PlayerOwner().Level.GetTourIsTraining(i))
		{
			if (Len(PlayerOwner().Level.GetTourName(i)) > 0)
			{
				mcbTour.addItem(PlayerOwner().Level.GetTourName(i), , i);
			}
		}
	}
	iTourID = mcbTour.GetExtra();
	ReloadMissions();
	UpdateTourInfo();
	gimgMap.Image = Material(DynamicLoadObject(PlayerOwner().Level.GetTourMissionImage(iTourID, iMissionID), Class'Material', True));
	*/
}

void UAAGameMenu_CP_MapSelection::ReloadMissions()
{
	/*
	local int NumMissions;
	local int i;
	local int j;
	local FString MissionName;
	local array<String> MissionNames;
	local array<int> MissionNums;
	mcbMission.RemoveItem(0, mcbMission.ItemCount());
	NumMissions = PlayerOwner().Level.GetTourMissions(iTourID);
	if (bAreMissionsAlphabetized)
	{
		for (i = 0; i < NumMissions; i++)
		{
			MissionName = PlayerOwner().Level.GetTourMissionMBSTitle(iTourID, i);
			j = 0;
			if (j < MissionNames.Length)
			{
				if (MissionName <= MissionNames[j])
				{
				}
				else
				{
					if (j + 1 < MissionNames.Length && MissionName <= MissionNames[j + 1])
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
			mcbMission.addItem(MissionNames[i], , MissionNums[i]);
		}
	}
	else
	{
		for (i = 0; i < NumMissions; i++)
		{
			mcbMission.addItem(PlayerOwner().Level.GetTourMissionTitle(iTourID, i), , i);
		}
	}
	iMissionID = mcbMission.GetExtra();
	*/
}

void UAAGameMenu_CP_MapSelection::InternalOnChange(UGUIComponent* Sender)
{
	/*
	local int Num;
	local int i;
	if (Sender == mcbTour)
	{
		iTourID = mcbTour.GetExtra();
		ReloadMissions();
		for (i = 0; i < Num; i++)
		{
			mcbMission.addItem(PlayerOwner().Level.GetTourMissionTitle(iTourID, i), , i);
		}
		iMissionID = mcbMission.GetExtra();
	}
	else
	{
		if (Sender == mcbMission)
		{
			iMissionID = mcbMission.GetExtra();
		}
	}
	UpdateTourInfo();
	gimgMap.Image = Material(DynamicLoadObject(PlayerOwner().Level.GetTourMissionImage(iTourID, iMissionID), Class'Material', True));
	*/
}

void UAAGameMenu_CP_MapSelection::UpdateTourInfo()
{
	/*
	local AAGUIController C;
	local FString S;
	C = AAGUIController(Controller);
	gimgTour.Image = Material(DynamicLoadObject(PlayerOwner().Level.GetTourImage(iTourID), Class'Material', True));
	if (gimgTour.Image == nullptr)
	{
		gimgTour.Image = Material(DynamicLoadObject("T_AAO_UI.Logo.T_UI_LOGO_AA", Class'Material', True));
	}
	glblTour.Caption = PlayerOwner().Level.GetTourMissionMBSTitle(iTourID, iMissionID);
	S = Caps(PlayerOwner().Level.GetTourHistoryTextTitle(iTourID)) $ "|" $ C.LoadTextFromFile(sBriefingDir $ PlayerOwner().Level.GetTourHistoryText(iTourID) $ ".txt") $ "||" $ Caps(PlayerOwner().Level.GetTourTextTitle(iTourID)) $ "|" $ C.LoadTextFromFile(sBriefingDir $ PlayerOwner().Level.GetTourText(iTourID) $ ".txt") $ "||";
	if (iTourID != 30)
	{
		S = S $ Caps(PlayerOwner().Level.GetTourMissionTitle(iTourID, iMissionID)) $ "|" $ C.LoadTextFromFile(sBriefingDir $ PlayerOwner().Level.GetTourMissionMapFilename(iTourID, iMissionID) $ ".txt");
	}
	glblDescription.SetContent(S);
	*/
}

void UAAGameMenu_CP_MapSelection::Timer()
{
	/*
	local FString sMsg;
	if (--iTimeLeftBeforeSwitch > 0)
	{
		sMsg = "Warning: The server is switching maps to " $ PlayerOwner().Level.GetTourMissionMBSTitle(iTourID, iMissionID) $ " in " $ iTimeLeftBeforeSwitch $ " second";
		if (iTimeLeftBeforeSwitch > 1)
		{
			sMsg = sMsg $ "s";
		}
		sMsg = sMsg $ ".";
		HumanController(PlayerOwner()).ConsoleCommand("Admin message " $ sMsg);
		gbtnSwitchMaps.Caption = "Cancel Change " $ iTimeLeftBeforeSwitch;
		HumanController(PlayerOwner()).ServerSay(sMsg, 'AdminSay');
	}
	else
	{
		SetTimer(0, False);
		HumanController(PlayerOwner()).ServerSay("Warning: The server is switching maps to " $ PlayerOwner().Level.GetTourMissionMBSTitle(iTourID, iMissionID) $ " now.", 'AdminSay');
		HumanController(PlayerOwner()).ConsoleCommand("admin switch " $ PlayerOwner().Level.GetTourMissionMapFilename(iTourID, iMissionID), False);
		aagpCommandPost.fCloseRequested = True;
		HumanController(PlayerOwner()).ClientCloseMenu(True);
	}
	*/
}

bool UAAGameMenu_CP_MapSelection::ButtonClick(UGUIComponent* Sender)
{
	/*
	Switch(Sender)
	{
			case gbtnSwitchMaps:
				OnSwitchMaps();
				break;
			default:
	}
	*/
	return true;
}

void UAAGameMenu_CP_MapSelection::OnSwitchMaps()
{
	/*
	if (iTimeLeftBeforeSwitch == 0)
	{
		aagpCommandPost.guibtnClose.DisableMe();
		gbtnSwitchMaps.Caption = "Cancel Change";
		iTimeLeftBeforeSwitch = 10;
		SetTimer(1, True);
	}
	else
	{
		aagpCommandPost.guibtnClose.EnableMe();
		HumanController(PlayerOwner()).ConsoleCommand("The administrator has cancelled the mission change.");
		HumanController(PlayerOwner()).ServerSay("The administrator has cancelled the mission change.", 'AdminSay');
		gbtnSwitchMaps.Caption = "Change Mission";
		SetTimer(0, False);
		iTimeLeftBeforeSwitch = 0;
	}
	*/
}