// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAGamePanel/AAGameMenu_CP_MapSelection/AAGameMenu_CP_MapSelection.h"

UAAGameMenu_CP_MapSelection::UAAGameMenu_CP_MapSelection()
{
	//gimgMapPanel = GUIImage'AGP_Interface.AAGameMenu_CP_MapSelection.MyMapPanel';
	//gimgTourPanel = GUIImage'AGP_Interface.AAGameMenu_CP_MapSelection.MyTourPanel';
	//gimgDescriptionPanel = GUIImage'AGP_Interface.AAGameMenu_CP_MapSelection.MyDescPanel';
	//gimgMap = GUIImage'AGP_Interface.AAGameMenu_CP_MapSelection.MapPic';
	//gimgTour = GUIImage'AGP_Interface.AAGameMenu_CP_MapSelection.tourIcon';
	//mcbTour = moComboBox'AGP_Interface.AAGameMenu_CP_MapSelection.MyTourCombo';
	//mcbMission = moComboBox'AGP_Interface.AAGameMenu_CP_MapSelection.MyMissionCombo';
	//gbtnSwitchMaps = GUIButton'AGP_Interface.AAGameMenu_CP_MapSelection.SwitchMapsButton';
	//glblTour = GUILabel'AGP_Interface.AAGameMenu_CP_MapSelection.MyTourLabel';
	//glblDescription = GUIScrollTextBox'AGP_Interface.AAGameMenu_CP_MapSelection.MyDescList';
	//gulInstructions = GUILabel'AGP_Interface.AAGameMenu_CP_MapSelection.InstructionsLabel';
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
	if (gimgTour.Image == None)
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