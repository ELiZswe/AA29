// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAGamePanel/AAGameMenu_CP_Configuration/AAGameMenu_CP_Configuration.h"

UAAGameMenu_CP_Configuration::UAAGameMenu_CP_Configuration()
{
	//mchkbPrivateServer = moCheckBox'AGP_Interface.AAGameMenu_CP_Configuration.PrivateServerCheckbox';
	//mebGamePassword = moEditBox'AGP_Interface.AAGameMenu_CP_Configuration.GamePasswordEntryField';
	//mcbDelayedStartTime = moComboBox'AGP_Interface.AAGameMenu_CP_Configuration.DelayedStartTimeComboListBox';
	//mcbAutoBalanceOptions = moComboBox'AGP_Interface.AAGameMenu_CP_Configuration.AutoBalanceComboListBox';
	//mcbFireMode = moComboBox'AGP_Interface.AAGameMenu_CP_Configuration.FireModeComboListBox';
	//gulInstructions = GUILabel'AGP_Interface.AAGameMenu_CP_Configuration.InstructionsLabel';
	//guibSaveChanges = GUIButton'AGP_Interface.AAGameMenu_CP_Configuration.SaveChanges';
	//mneMinHonor = moNumericEdit'AGP_Interface.AAGameMenu_CP_Configuration.MinHonorEditField';
	//mneMaxHonor = moNumericEdit'AGP_Interface.AAGameMenu_CP_Configuration.MaxHonorEditField';
	//gulMOTDTitle = GUILabel'AGP_Interface.AAGameMenu_CP_Configuration.MOTDOptionsLabel';
	//mebMOTD1 = moEditBox'AGP_Interface.AAGameMenu_CP_Configuration.MOTD1EntryField';
	//mebMOTD2 = moEditBox'AGP_Interface.AAGameMenu_CP_Configuration.MOTD2EntryField';
	//mebMOTD3 = moEditBox'AGP_Interface.AAGameMenu_CP_Configuration.MOTD3EntryField';
	//mebMOTD4 = moEditBox'AGP_Interface.AAGameMenu_CP_Configuration.MOTD4EntryField';
	//mneMOTDDisplayTime = moNumericEdit'AGP_Interface.AAGameMenu_CP_Configuration.MOTDDisplayTimeEditField';
	//mneMaxPlayers = moNumericEdit'AGP_Interface.AAGameMenu_CP_Configuration.MaxPlayersEditField';
	//mneMaxAdmins = moNumericEdit'AGP_Interface.AAGameMenu_CP_Configuration.MaxAdminsEditField';
	sInstructions = "Use this to customize your server settings.";
	sMOTDTitle = "Message of the Day Text and Options";
	WinHeight = 1;
}

void UAAGameMenu_CP_Configuration::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	InitComponent(MyController, MyOwner);
	mneMinHonor.MyNumericEdit.MinValue = 1;
	mneMinHonor.MyNumericEdit.MaxValue = 100;
	mneMaxHonor.MyNumericEdit.MinValue = 1;
	mneMaxHonor.MyNumericEdit.MaxValue = 100;
	mneMaxPlayers.MyNumericEdit.MinValue = 1;
	mneMaxPlayers.MyNumericEdit.MaxValue = 26;
	mneMaxAdmins.MyNumericEdit.MinValue = 1;
	mneMaxAdmins.MyNumericEdit.MaxValue = 8;
	mcbAutoBalanceOptions.MyComboBox.Edit.bReadOnly = True;
	mcbFireMode.MyComboBox.Edit.bReadOnly = True;
	mcbDelayedStartTime.MyComboBox.Edit.bReadOnly = True;
	mcbDelayedStartTime.MyComboBox.Edit.bReadOnly = True;
	mcbDelayedStartTime.MyComboBox.List.Insert(0, "Disabled (Pre 2.8.3 Start)", , "0");
	mcbDelayedStartTime.MyComboBox.List.Insert(1, "5 Seconds", , "5");
	mcbDelayedStartTime.MyComboBox.List.Insert(2, "6 Seconds", , "6");
	mcbDelayedStartTime.MyComboBox.List.Insert(3, "7 Seconds", , "7");
	mcbDelayedStartTime.MyComboBox.List.Insert(4, "8 Seconds", , "8");
	mcbDelayedStartTime.MyComboBox.List.Insert(5, "9 Seconds", , "9");
	mcbDelayedStartTime.MyComboBox.List.Insert(6, "10 Seconds", , "10");
	mcbDelayedStartTime.MyComboBox.List.Insert(7, "11 Seconds", , "11");
	mcbDelayedStartTime.MyComboBox.List.Insert(8, "12 Seconds", , "12");
	mcbDelayedStartTime.MyComboBox.List.Insert(9, "13 Seconds", , "13");
	mcbDelayedStartTime.MyComboBox.List.Insert(10, "14 Seconds", , "14");
	mcbDelayedStartTime.MyComboBox.List.Insert(11, "15 Seconds", , "15");
	mcbAutoBalanceOptions.MyComboBox.List.Insert(0, "Auto-balance Teams");
	mcbAutoBalanceOptions.MyComboBox.List.Insert(1, "Never Auto-balance Teams");
	mcbFireMode.MyComboBox.List.Insert(0, "Force MILES Weapons", , "FORCE_MILES");
	mcbFireMode.MyComboBox.List.Insert(1, "Force Live-Fire Weapons", , "FORCE_Normal");
	mcbFireMode.MyComboBox.List.Insert(2, "Use Standard Weapons For Mission", , "FORCE_None");
	gulInstructions.Caption = sInstructions;
	*/
}

void UAAGameMenu_CP_Configuration::InitializeDataFields()
{
	/*
	if (aagpCommandPost == None)
	{
		Log("Warning: The CP Configuration page does not have a valid Command Post page.");
		Return;
	}
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Configuration", "AGP_GameInfo ForceGameplay");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Configuration", "GameInfo MaxPlayers");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Configuration", "GameInfo AbsoluteMaxPlayers");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Configuration", "GameInfo MaxAdmins");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Configuration", "AccessControl GamePassword");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Configuration", "AGP_GameTeam bPlayersBalanceTeams");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Configuration", "AGP_GameTeam bAutoBalanceBetweenRounds");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Configuration", "AGP_GameTeam bNeverAutoBalance");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Configuration", "AGP_GameMultiPlayer MinHonor");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Configuration", "AGP_GameMultiPlayer MaxHonor");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Configuration", "GameReplicationInfo MOTDLine1");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Configuration", "GameReplicationInfo MOTDLine2");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Configuration", "GameReplicationInfo MOTDLine3");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Configuration", "GameReplicationInfo MOTDLine4");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Configuration", "GameReplicationInfo MOTDDisplaySeconds");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Configuration", "AGP_GameInfo iDelayedRoundStartTimeSeconds");
	*/
}

void UAAGameMenu_CP_Configuration::NotifyCustomParameters(FString sParam1, FString sParam2, FString sParam3)
{
	/*
	if (sParam1 ~= "INIEntry")
	{
		if (sParam2 ~= "AccessControl GamePassword")
		{
			if (Len(sParam3) > 0)
			{
				mchkbPrivateServer.SetComponentValue(True);
				mebGamePassword.SetText(sParam3);
				mebGamePassword.EnableMe();
			}
			else
			{
				mchkbPrivateServer.SetComponentValue(False);
				mebGamePassword.DisableMe();
			}
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "AGP_GameTeam bPlayersBalanceTeams")
		{
			bPlayersBalanceTeams = sParam3;
			UpdateAutoBalanceOptions();
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "AGP_GameTeam bAutoBalanceBetweenRounds")
		{
			bAutoBalanceBetweenRounds = sParam3;
			UpdateAutoBalanceOptions();
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "AGP_GameInfo iDelayedRoundStartTimeSeconds")
		{
			UpdateDelayedStartSelection(sParam3);
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "AGP_GameTeam bNeverAutoBalance")
		{
			bNeverAutoBalance = sParam3;
			UpdateAutoBalanceOptions();
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "AGP_GameMultiPlayer MinHonor")
		{
			mneMinHonor.SetComponentValue(sParam3, True);
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "AGP_GameMultiPlayer MaxHonor")
		{
			mneMaxHonor.SetComponentValue(sParam3, True);
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "GameInfo MaxAdmins")
		{
			mneMaxAdmins.SetComponentValue(sParam3, True);
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "GameInfo MaxPlayers")
		{
			mneMaxPlayers.SetComponentValue(sParam3, True);
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "GameInfo AbsoluteMaxPlayers")
		{
			mneMaxPlayers.SetComponentValue(Min(sParam3, mneMaxPlayers.GetComponentValue()));
			mneMaxPlayers.MyNumericEdit.MaxValue = sParam3;
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "GameReplicationInfo MOTDLine1")
		{
			mebMOTD1.SetText(sParam3);
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "GameReplicationInfo MOTDLine2")
		{
			mebMOTD2.SetText(sParam3);
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "GameReplicationInfo MOTDLine3")
		{
			mebMOTD3.SetText(sParam3);
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "GameReplicationInfo MOTDLine4")
		{
			mebMOTD4.SetText(sParam3);
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "GameReplicationInfo MOTDDisplaySeconds")
		{
			mneMOTDDisplayTime.SetComponentValue(sParam3, True);
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "AGP_GameInfo ForceGameplay")
		{
			if (sParam3 ~= "FORCE_MILES")
			{
				mcbFireMode.MyComboBox.List.SetIndex(0);
				guibSaveChanges.DisableMe();
				Return;
			}
			else
			{
				if (sParam3 ~= "FORCE_Normal")
				{
					mcbFireMode.MyComboBox.List.SetIndex(1);
					guibSaveChanges.DisableMe();
					Return;
				}
				else
				{
					mcbFireMode.MyComboBox.List.SetIndex(2);
					guibSaveChanges.DisableMe();
					Return;
				}
			}
		}
	}
	*/
}

void UAAGameMenu_CP_Configuration::UpdateDelayedStartSelection(int32 iDelayedStartTime)
{
	/*
	if (iDelayedStartTime == 0)
	{
		mcbDelayedStartTime.MyComboBox.List.SetIndex(0);
	}
	else
	{
		if (iDelayedStartTime < 5)
		{
			iDelayedStartTime = 5;
		}
		mcbDelayedStartTime.MyComboBox.List.SetIndex(iDelayedStartTime - 4);
	}
	*/
}

void UAAGameMenu_CP_Configuration::UpdateAutoBalanceOptions()
{
	/*
	if (bNeverAutoBalance)
	{
		mcbAutoBalanceOptions.MyComboBox.List.SetIndex(1);
		Return;
	}
	if (bPlayersBalanceTeams || bAutoBalanceBetweenRounds)
	{
		mcbAutoBalanceOptions.MyComboBox.List.SetIndex(0);
		Return;
	}
	mcbAutoBalanceOptions.MyComboBox.List.SetIndex(2);
	Return;
	*/
}

bool UAAGameMenu_CP_Configuration::IsAdmin()
{
	//Return PlayerOwner() != None && PlayerOwner().PlayerReplicationInfo != None && PlayerOwner().PlayerReplicationInfo.bAdmin;
	return false;    //FAKE    /ELiZ
}

bool UAAGameMenu_CP_Configuration::CanShowPanel()
{
	return true;
}

void UAAGameMenu_CP_Configuration::InternalOnChange(UGUIComponent* Sender)
{
	/*
	Switch(Sender)
	{
			case mchkbPrivateServer:
				if (mchkbPrivateServer.IsChecked())
				{
					mebGamePassword.EnableMe();
					mebGamePassword.SetText("");
					break;
				}
				mebGamePassword.DisableMe();
				mebGamePassword.SetText("");
	}
	GOTO JL007C;
		default:
			guibSaveChanges.EnableMe();
			GOTO JL007C;
		JL007C:
		*/
}

bool UAAGameMenu_CP_Configuration::ButtonClick(UGUIComponent* Sender)
{
	/*
	Switch(Sender)
	{
			case guibSaveChanges:
				HumanController(PlayerOwner()).ServerSetINISetting("GameInfo MaxPlayers " $ mneMaxPlayers.GetComponentValue());
				if (mneMaxPlayers.GetComponentValue() % 2 == 0)
				{
					HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameTeam MaxTeamSize " $ mneMaxPlayers.GetComponentValue() / 2);
					break;
				}
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameTeam MaxTeamSize " $ mneMaxPlayers.GetComponentValue() / 2 + 1);
	}
	HumanController(PlayerOwner()).ServerSetINISetting("GameInfo MaxAdmins " $ mneMaxAdmins.GetComponentValue());
	HumanController(PlayerOwner()).ServerSetINISetting("AccessControl GamePassword " $ mebGamePassword.GetText());
	Switch(mcbAutoBalanceOptions.GetIndex())
	{
			case 0:
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameTeam bPlayersBalanceTeams true");
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameTeam bAutoBalanceBetweenRounds true ");
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameTeam bNeverAutoBalance false");
				break;
			case 1:
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameTeam bPlayersBalanceTeams false");
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameTeam bAutoBalanceBetweenRounds false");
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameTeam bNeverAutoBalance true");
				break;
			default:
	}
	HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameInfo ForceGameplay " $ mcbFireMode.GetExtra());
	HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameMultiPlayer MinHonor " $ mneMinHonor.GetComponentValue());
	HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameMultiPlayer MaxHonor " $ mneMaxHonor.GetComponentValue());
	HumanController(PlayerOwner()).ServerSetINISetting("GameReplicationInfo MOTDLine1 " $ mebMOTD1.GetText());
	HumanController(PlayerOwner()).ServerSetINISetting("GameReplicationInfo MOTDLine2 " $ mebMOTD2.GetText());
	HumanController(PlayerOwner()).ServerSetINISetting("GameReplicationInfo MOTDLine3 " $ mebMOTD3.GetText());
	HumanController(PlayerOwner()).ServerSetINISetting("GameReplicationInfo MOTDLine4 " $ mebMOTD4.GetText());
	HumanController(PlayerOwner()).ServerSetINISetting("GameReplicationInfo MOTDDisplaySeconds " $ mneMOTDDisplayTime.GetComponentValue());
	HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameInfo iDelayedRoundStartTimeSeconds " $ mcbDelayedStartTime.GetExtra());
	guibSaveChanges.DisableMe();
	GOTO JL057A;
		default:
		JL057A:
			Return True;

	*/

	return false;    //FAKE   /ELiZ
}