// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAGamePanel/AAGameMenu_CP_Rules/AAGameMenu_CP_Rules.h"

UAAGameMenu_CP_Rules::UAAGameMenu_CP_Rules()
{
	//mchkbEnableCheats = moCheckBox'AGP_Interface.AAGameMenu_CP_Rules.EnableCheatsCheckbox';
	//mcbRoundsPerMatch = moComboBox'AGP_Interface.AAGameMenu_CP_Rules.RoundsPerMatchDropDown';
	//mcbTimeLimit = moComboBox'AGP_Interface.AAGameMenu_CP_Rules.TimeLimitDropDown';
	//mcbSpectatingMode = moComboBox'AGP_Interface.AAGameMenu_CP_Rules.SpectatingRulesDropDown';
	//mchkbEnableDeathMessages = moCheckBox'AGP_Interface.AAGameMenu_CP_Rules.EnableDeathMessagesCheckbox';
	//mchkbOpenAllWeaponSlots = moCheckBox'AGP_Interface.AAGameMenu_CP_Rules.OpenAllWeaponSlotsCheckbox';
	//mchkbDisableAllClientShadows = moCheckBox'AGP_Interface.AAGameMenu_CP_Rules.DisableAllClientShadowsCheckbox';
	//mcbChatLoggingLevel = moComboBox'AGP_Interface.AAGameMenu_CP_Rules.ChatLoggingLevelDropDown';
	//mcbScoreboardMode = moComboBox'AGP_Interface.AAGameMenu_CP_Rules.ScoreboardRulesDropDown';
	//mneROELimit = moNumericEdit'AGP_Interface.AAGameMenu_CP_Rules.ROEKickEditField';
	//mcbROEKick = moComboBox'AGP_Interface.AAGameMenu_CP_Rules.ROEKickDropDown';
	//mchkbROEKickTimer = moCheckBox'AGP_Interface.AAGameMenu_CP_Rules.EnableROETimerCheckbox';
	//guibSaveChanges = GUIButton'AGP_Interface.AAGameMenu_CP_Rules.SaveChanges';
	//mchkbESSDisable = moCheckBox'AGP_Interface.AAGameMenu_CP_Rules.ESSDisableCheckbox';
	//mcbIdleKickMinutes = moComboBox'AGP_Interface.AAGameMenu_CP_Rules.IdleKickMinutesDropDown';
	//mcbIdleKickRounds = moComboBox'AGP_Interface.AAGameMenu_CP_Rules.IdleKickRoundsDropDown';
	//mchkbHUDHideAmmoCount = moCheckBox'AGP_Interface.AAGameMenu_CP_Rules.HideHUDAmmoCountCheckbox';
	//mchkbHUDHideWeaponStatus = moCheckBox'AGP_Interface.AAGameMenu_CP_Rules.HideHUDWeaponStatusCheckbox';
	//mchkbHUDHideWeaponSelection = moCheckBox'AGP_Interface.AAGameMenu_CP_Rules.HideHUDWeaponSelectionCheckbox';
	//mchkbHUDHideGrenades = moCheckBox'AGP_Interface.AAGameMenu_CP_Rules.HideHUDGrenadesCheckbox';
	//mchkbHUDHideHealth = moCheckBox'AGP_Interface.AAGameMenu_CP_Rules.HideHUDHealthCheckbox';
	//mchkbHUDHideCEM = moCheckBox'AGP_Interface.AAGameMenu_CP_Rules.HideHUDCEMCheckbox';
	//mchkbHUDHideTimer = moCheckBox'AGP_Interface.AAGameMenu_CP_Rules.HideHUDTimerCheckbox';
	//mchkbHUDHideRadar = moCheckBox'AGP_Interface.AAGameMenu_CP_Rules.HideHUDRadarCheckbox';
	//mchkbHUDHideOptics = moCheckBox'AGP_Interface.AAGameMenu_CP_Rules.HideHUDOpticsCheckbox';
	//gulInstructions = GUILabel'AGP_Interface.AAGameMenu_CP_Rules.InstructionsLabel';
	//gulHUDOptionsTitle = GUILabel'AGP_Interface.AAGameMenu_CP_Rules.HUDOptionsLabel';
	//gulROEKickOptionsTitle = GUILabel'AGP_Interface.AAGameMenu_CP_Rules.ROEKickOptionsLabel';
	sInstructions = "Use this to customize game-play rules.";
	sHUDOptionsTitle = "HUD Options For Enhanced Difficulty";
	WinHeight = 1;
}

void UAAGameMenu_CP_Rules::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	local int iTimeEntry;
	local int iRounds;
	InitComponent(MyController, MyOwner);
	gulInstructions.Caption = sInstructions;
	gulHUDOptionsTitle.Caption = sHUDOptionsTitle;
	mcbRoundsPerMatch.MyComboBox.Edit.bReadOnly = True;
	mcbTimeLimit.MyComboBox.Edit.bReadOnly = True;
	mcbSpectatingMode.MyComboBox.Edit.bReadOnly = True;
	mcbScoreboardMode.MyComboBox.Edit.bReadOnly = True;
	mcbROEKick.MyComboBox.Edit.bReadOnly = True;
	mcbIdleKickMinutes.MyComboBox.Edit.bReadOnly = True;
	mcbIdleKickRounds.MyComboBox.Edit.bReadOnly = True;
	for (iTimeEntry = 1; iTimeEntry <= 20; iTimeEntry++)
	{
		mcbTimeLimit.MyComboBox.List.Insert(iTimeEntry - 1, "" $ iTimeEntry $ " minutes", , "" $ iTimeEntry);
	}
	mcbIdleKickMinutes.MyComboBox.List.Insert(0, "Disabled", , "0");
	for (iTimeEntry = 1; iTimeEntry <= 10; iTimeEntry++)
	{
		mcbIdleKickMinutes.MyComboBox.List.Insert(iTimeEntry - 1, "" $ iTimeEntry, , "" $ iTimeEntry);
	}
	for (iRounds = 1; iRounds <= 30; iRounds++)
	{
		mcbRoundsPerMatch.MyComboBox.List.Insert(iRounds - 1, "" $ iRounds $ " rounds", , "" $ iRounds);
	}
	if (HumanController(PlayerOwner()).TournamentIsTournament())
	{
		if (HumanController(PlayerOwner()).GameReplicationInfo.sTournamentState != "Setup")
		{
			mcbRoundsPerMatch.DisableMe();
			mcbRoundsPerMatch.MyComboBox.Hint = "You may only adjust rounds per match for tournaments before the tournament starts.";
			mcbTimeLimit.DisableMe();
			mcbTimeLimit.MyComboBox.Hint = "You may only adjust round length for tournaments before the tournament starts.";
		}
	}
	mcbIdleKickRounds.MyComboBox.List.Insert(0, "Disabled");
	for (iRounds = 1; iRounds <= 10; iRounds++)
	{
		mcbIdleKickRounds.MyComboBox.List.Insert(iRounds - 1, "" $ iRounds, , "" $ iRounds);
	}
	mcbSpectatingMode.MyComboBox.List.Insert(0, "Players Only First Person View");
	mcbSpectatingMode.MyComboBox.List.Insert(1, "Players Only First and Third Person Views");
	mcbSpectatingMode.MyComboBox.List.Insert(2, "Viewpoints and Same Team Players' Views");
	mcbSpectatingMode.MyComboBox.List.Insert(3, "Viewpoints and All Players' Views");
	mcbScoreboardMode.MyComboBox.List.Insert(0, "Scoreboard Always Available", , "SSM_On");
	mcbScoreboardMode.MyComboBox.List.Insert(1, "Scoreboard Never Available", , "SSM_Off");
	mcbScoreboardMode.MyComboBox.List.Insert(2, "Scoreboard Available At End of Round Only", , "SSM_Round");
	mcbScoreboardMode.MyComboBox.List.Insert(3, "Scoreboard Available At End of Match Only", , "SSM_Match");
	mcbChatLoggingLevel.MyComboBox.List.Insert(0, "Logging Disabled", , "0");
	mcbChatLoggingLevel.MyComboBox.List.Insert(1, "Basic Chat Text Only", , "1");
	mcbChatLoggingLevel.MyComboBox.List.Insert(2, "Admin Actions + Chat Text", , "2");
	mcbChatLoggingLevel.MyComboBox.List.Insert(3, "System, Admin, and Chat", , "3");
	mcbScoreboardMode.MyComboBox.List.SetIndex(0);
	mneROELimit.MyNumericEdit.MinValue = 0;
	mneROELimit.MyNumericEdit.MaxValue = 5000;
	mcbROEKick.MyComboBox.List.Insert(0, "Kick player to Leavenworth");
	mcbROEKick.MyComboBox.List.Insert(1, "Kill Player");
	mcbROEKick.MyComboBox.List.Insert(2, "Ignore Violations");
	*/
}

void UAAGameMenu_CP_Rules::InitializeDataFields()
{
	/*
	if (aagpCommandPost == None)
	{
		Log("Warning: The CP Rules page does not have a valid Command Post page.");
		Return;
	}
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Rules", "AGP_GameMultiPlayer bMPCheatsEnabled");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Rules", "AGP_GameTeam FFScoreLimit");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Rules", "AGP_GameDeathMatch RoundsPerMatch");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Rules", "GameInfo TimeLimit");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Rules", "GameReplicationInfo bForceShadowsOff");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Rules", "BroadcastHandler iLogChatLevel");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Rules", "AGP_GameTeam bSpectatePlayersOnly");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Rules", "AGP_GameTeam bSpectateFirstPersonOnly");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Rules", "AGP_GameTeam bSpectateFriendsOnly");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Rules", "AGP_GameDeathMatch IdlePlayerKickTime");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Rules", "AGP_GameDeathMatch bKickIdlePlayersTimed");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Rules", "AGP_GameDeathMatch IdlePlayerKickRounds");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Rules", "AGP_GameDeathMatch bKickIdlePlayersRounds");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Rules", "AGP_GameTeam bEnableROEKickTimer");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Rules", "AGP_GameTeam bEnableROEKickDeath");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Rules", "AGP_GameTeam bEnableROEKick");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Rules", "GameInfo ScoreMode");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Rules", "GameInfo bDeathMessages");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Rules", "AGP_GameInfo bOpenAllWeaponClassSlots");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Rules", "AGP_GameInfo bDisableESS");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Rules", "GameReplicationInfo bHUDHideAmmoCount");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Rules", "GameReplicationInfo bHUDHideWeaponStatus");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Rules", "GameReplicationInfo bHUDHideWeapon");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Rules", "GameReplicationInfo bHUDHideGrenades");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Rules", "GameReplicationInfo bHUDHideHealth");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Rules", "GameReplicationInfo bHUDHideCombatEffect");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Rules", "GameReplicationInfo bHUDHideOptics");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Rules", "GameReplicationInfo bHUDHideTimer");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Rules", "GameReplicationInfo bHUDHideMedical");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Rules", "GameReplicationInfo bHUDHideRadar");
	*/
}

bool UAAGameMenu_CP_Rules::IsAdmin()
{
	//Return PlayerOwner() != None && PlayerOwner().PlayerReplicationInfo != None && PlayerOwner().PlayerReplicationInfo.bAdmin;
	return false;    //FAKE    /ELiZ
}

bool UAAGameMenu_CP_Rules::CanShowPanel()
{
	return true;
}

void UAAGameMenu_CP_Rules::InternalOnChange(UGUIComponent* Sender)
{
	/*
	Switch(Sender)
	{
			default:
				guibSaveChanges.EnableMe();
				break;
	}
	*/
}

bool UAAGameMenu_CP_Rules::ButtonClick(UGUIComponent* Sender)
{
	/*
	Switch(Sender)
	{
			case guibSaveChanges:
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameMultiPlayer bMPCheatsEnabled " $ mchkbEnableCheats.IsChecked());
				if (mcbRoundsPerMatch.GetComponentValue() > 0)
				{
					HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameDeathMatch RoundsPerMatch " $ mcbRoundsPerMatch.GetComponentValue());
					HumanController(PlayerOwner()).ServerUpdateActiveTournamentField("AGP_GameDeathMatch RoundsPerMatch", mcbRoundsPerMatch.GetComponentValue());
				}
				if (mcbTimeLimit.GetComponentValue() > 0)
				{
					HumanController(PlayerOwner()).ServerSetINISetting("GameInfo TimeLimit " $ mcbTimeLimit.GetComponentValue());
					HumanController(PlayerOwner()).ServerUpdateActiveTournamentField("GameInfo TimeLimit", mcbTimeLimit.GetComponentValue());
				}
				Switch(mcbSpectatingMode.GetIndex())
				{
			case 0:
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameTeam bSpectatePlayersOnly true");
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameTeam bSpectateFirstPersonOnly true");
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameTeam bSpectateFriendsOnly true");
				break;
			case 1:
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameTeam bSpectatePlayersOnly true");
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameTeam bSpectateFirstPersonOnly false");
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameTeam bSpectateFriendsOnly true");
				break;
			case 2:
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameTeam bSpectatePlayersOnly false");
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameTeam bSpectateFirstPersonOnly false");
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameTeam bSpectateFriendsOnly true");
				break;
			case 3:
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameTeam bSpectatePlayersOnly false");
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameTeam bSpectateFirstPersonOnly false");
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameTeam bSpectateFriendsOnly false");
				break;
			default:
				}
				HumanController(PlayerOwner()).ServerSetINISetting("GameInfo bDeathMessages " $ mchkbEnableDeathMessages.GetComponentValue());
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameInfo bDisableESS " $ mchkbESSDisable.GetComponentValue());
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameInfo bOpenAllWeaponClassSlots " $ mchkbOpenAllWeaponSlots.GetComponentValue());
				HumanController(PlayerOwner()).ServerSetINISetting("GameReplicationInfo bForceShadowsOff " $ mchkbDisableAllClientShadows.GetComponentValue());
				HumanController(PlayerOwner()).ServerSetINISetting("BroadcastHandler iLogChatLevel " $ mcbChatLoggingLevel.GetExtra());
				HumanController(PlayerOwner()).ServerSetINISetting("GameInfo ScoreMode " $ mcbScoreboardMode.GetExtra());
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameTeam FFScoreLimit " $ mneROELimit.GetComponentValue());
				Switch(mcbROEKick.GetIndex())
				{
			case 0:
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameTeam bEnableROEKickDeath false");
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameTeam bEnableROEKick true");
				break;
			case 1:
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameTeam bEnableROEKickDeath true");
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameTeam bEnableROEKick true");
				break;
			case 2:
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameTeam bEnableROEKickDeath false");
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameTeam bEnableROEKick false");
				break;
			default:
				}
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameTeam bEnableROEKickTimer " $ mchkbROEKickTimer.GetComponentValue());
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameDeathMatch IdlePlayerKickTime " $ mcbIdleKickMinutes.GetExtra());
				if (mcbIdleKickMinutes.GetExtra() > 0)
				{
					HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameDeathMatch bKickIdlePlayersTimed true");
				}
				else
				{
					HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameDeathMatch bKickIdlePlayersTimed false");
				}
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameDeathMatch IdlePlayerKickRounds " $ mcbIdleKickRounds.GetExtra());
				if (mcbIdleKickRounds.GetExtra() > 0)
				{
					HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameDeathMatch bKickIdlePlayersRounds true");
				}
				else
				{
					HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameDeathMatch bKickIdlePlayersRounds false");
				}
				HumanController(PlayerOwner()).ServerSetINISetting("GameReplicationInfo bHUDHideAmmoCount " $ mchkbHUDHideAmmoCount.GetComponentValue());
				HumanController(PlayerOwner()).ServerSetINISetting("GameReplicationInfo bHUDHideWeaponStatus " $ mchkbHUDHideWeaponStatus.GetComponentValue());
				HumanController(PlayerOwner()).ServerSetINISetting("GameReplicationInfo bHUDHideWeapon " $ mchkbHUDHideWeaponSelection.GetComponentValue());
				HumanController(PlayerOwner()).ServerSetINISetting("GameReplicationInfo bHUDHideGrenades " $ mchkbHUDHideGrenades.GetComponentValue());
				HumanController(PlayerOwner()).ServerSetINISetting("GameReplicationInfo bHUDHideHealth " $ mchkbHUDHideHealth.GetComponentValue());
				HumanController(PlayerOwner()).ServerSetINISetting("GameReplicationInfo bHUDHideCombatEffect " $ mchkbHUDHideCEM.GetComponentValue());
				HumanController(PlayerOwner()).ServerSetINISetting("GameReplicationInfo bHUDHideOptics " $ mchkbHUDHideOptics.GetComponentValue());
				HumanController(PlayerOwner()).ServerSetINISetting("GameReplicationInfo bHUDHideTimer " $ mchkbHUDHideTimer.GetComponentValue());
				HumanController(PlayerOwner()).ServerSetINISetting("GameReplicationInfo bHUDHideMedical " $ mchkbHUDHideHealth.GetComponentValue());
				HumanController(PlayerOwner()).ServerSetINISetting("GameReplicationInfo bHUDHideRadar " $ mchkbHUDHideRadar.GetComponentValue());
				guibSaveChanges.DisableMe();
				GOTO JL0CCF;
			default:
			JL0CCF:
				Return True;
	}
	*/
	return false;    //FAKE  /EliZ
}

void UAAGameMenu_CP_Rules::NotifyCustomParameters(FString sParam1, FString sParam2, FString sParam3)
{
	/*
	if (sParam1 ~= "INIEntry")
	{
		if (sParam2 ~= "AGP_GameMultiPlayer bMPCheatsEnabled")
		{
			mchkbEnableCheats.SetComponentValue(sParam3, True);
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "AGP_GameTeam bSpectatePlayersOnly")
		{
			bSpectatePlayersOnly = sParam3;
			UpdateSpectatingRulesField();
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "AGP_GameTeam bSpectateFirstPersonOnly")
		{
			bSpectateFirstPersonOnly = sParam3;
			UpdateSpectatingRulesField();
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "AGP_GameTeam bSpectateFriendsOnly")
		{
			bSpectateFriendsOnly = sParam3;
			UpdateSpectatingRulesField();
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "AGP_GameDeathMatch RoundsPerMatch")
		{
			if (sParam3 > 1)
			{
				sParam3 = sParam3 $ " rounds";
			}
			else
			{
				sParam3 = sParam3 $ " round";
			}
			mcbRoundsPerMatch.SetText(sParam3);
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "GameInfo TimeLimit")
		{
			if (sParam3 > 1)
			{
				sParam3 = sParam3 $ " minutes";
			}
			else
			{
				sParam3 = sParam3 $ " minute";
			}
			mcbTimeLimit.SetText(sParam3);
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "AGP_GameTeam FFScoreLimit")
		{
			mneROELimit.SetComponentValue(sParam3, True);
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "AGP_GameTeam bEnableROEKickTimer")
		{
			mchkbROEKickTimer.SetComponentValue(sParam3, True);
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "AGP_GameTeam bEnableROEKickDeath")
		{
			bROEKickDeath = sParam3;
			UpdateROEKickOptions();
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "AGP_GameTeam bEnableROEKick")
		{
			bEnableROEKick = sParam3;
			UpdateROEKickOptions();
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "GameInfo ScoreMode")
		{
			if (sParam3 ~= "SSM_On")
			{
				mcbScoreboardMode.MyComboBox.List.SetIndex(0);
				guibSaveChanges.DisableMe();
				Return;
			}
			if (sParam3 ~= "SSM_Off")
			{
				mcbScoreboardMode.MyComboBox.List.SetIndex(1);
				guibSaveChanges.DisableMe();
				Return;
			}
			if (sParam3 ~= "SSM_Round")
			{
				mcbScoreboardMode.MyComboBox.List.SetIndex(2);
				guibSaveChanges.DisableMe();
				Return;
			}
			if (sParam3 ~= "SSM_Match")
			{
				mcbScoreboardMode.MyComboBox.List.SetIndex(3);
				guibSaveChanges.DisableMe();
				Return;
			}
			Return;
		}
		if (sParam2 ~= "GameReplicationInfo bHUDHideAmmoCount")
		{
			mchkbHUDHideAmmoCount.SetComponentValue(sParam3, True);
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "GameReplicationInfo bHUDHideWeaponStatus")
		{
			mchkbHUDHideWeaponStatus.SetComponentValue(sParam3, True);
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "GameReplicationInfo bHUDHideWeapon")
		{
			mchkbHUDHideWeaponSelection.SetComponentValue(sParam3, True);
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "GameReplicationInfo bHUDHideGrenades")
		{
			mchkbHUDHideGrenades.SetComponentValue(sParam3, True);
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "GameReplicationInfo bHUDHideHealth")
		{
			mchkbHUDHideHealth.SetComponentValue(sParam3, True);
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "GameReplicationInfo bHUDHideCombatEffect")
		{
			mchkbHUDHideCEM.SetComponentValue(sParam3, True);
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "GameReplicationInfo bHUDHideOptics")
		{
			mchkbHUDHideOptics.SetComponentValue(sParam3, True);
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "GameReplicationInfo bHUDHideTimer")
		{
			mchkbHUDHideTimer.SetComponentValue(sParam3, True);
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "GameReplicationInfo bHUDHideMedical")
		{
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "GameReplicationInfo bHUDHideRadar")
		{
			mchkbHUDHideRadar.SetComponentValue(sParam3, True);
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "BroadcastHandler iLogChatLevel")
		{
			mcbChatLoggingLevel.MyComboBox.List.SetIndex(sParam3);
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "AGP_GameInfo bDisableESS")
		{
			mchkbESSDisable.SetComponentValue(sParam3, True);
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "GameInfo bDeathMessages")
		{
			mchkbEnableDeathMessages.SetComponentValue(sParam3, True);
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "AGP_GameInfo bOpenAllWeaponClassSlots")
		{
			Log("Param passed in is " $ sParam2 $ " value is " $ sParam3);
			mchkbOpenAllWeaponSlots.SetComponentValue(sParam3, True);
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "GameReplicationInfo bForceShadowsOff")
		{
			mchkbDisableAllClientShadows.SetComponentValue(sParam3, True);
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "AGP_GameDeathMatch IdlePlayerKickRounds")
		{
			iIdlePlayerKickRounds = sParam3;
			UpdateIdlePlayerOptions();
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "AGP_GameDeathMatch bKickIdlePlayersRounds")
		{
			bKickIdlePlayersRounds = sParam3;
			UpdateIdlePlayerOptions();
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "AGP_GameDeathMatch bKickIdlePlayersTimed")
		{
			bKickIdlePlayersTimed = sParam3;
			UpdateIdlePlayerOptions();
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "AGP_GameDeathMatch IdlePlayerKickTime")
		{
			iIdlePlayerKickMinutes = sParam3;
			UpdateIdlePlayerOptions();
			guibSaveChanges.DisableMe();
			Return;
		}
	}
	*/
}

void UAAGameMenu_CP_Rules::UpdateIdlePlayerOptions()
{
	/*
	if (bKickIdlePlayersTimed && iIdlePlayerKickMinutes > 0)
	{
		mcbIdleKickMinutes.SetText("" $ iIdlePlayerKickMinutes);
	}
	else
	{
		mcbIdleKickMinutes.SetText("Disabled");
	}
	if (bKickIdlePlayersRounds && iIdlePlayerKickRounds > 0)
	{
		mcbIdleKickRounds.SetText("" $ iIdlePlayerKickRounds);
	}
	else
	{
		mcbIdleKickRounds.SetText("Disabled");
	}
	*/
}

void UAAGameMenu_CP_Rules::UpdateROEKickOptions()
{
	/*
	if (!bEnableROEKick)
	{
		mcbROEKick.MyComboBox.List.SetIndex(2);
		Return;
	}
	if (!bROEKickDeath)
	{
		mcbROEKick.MyComboBox.List.SetIndex(0);
	}
	else
	{
		mcbROEKick.MyComboBox.List.SetIndex(1);
	}
	*/
}

void UAAGameMenu_CP_Rules::UpdateSpectatingRulesField()
{
	/*
	if (!bSpectatePlayersOnly && !bSpectateFriendsOnly)
	{
		mcbSpectatingMode.MyComboBox.List.SetIndex(3);
		Return;
	}
	if (!bSpectatePlayersOnly && bSpectateFriendsOnly)
	{
		mcbSpectatingMode.MyComboBox.List.SetIndex(2);
		Return;
	}
	if (bSpectatePlayersOnly && !bSpectateFirstPersonOnly)
	{
		mcbSpectatingMode.MyComboBox.List.SetIndex(1);
		Return;
	}
	if (bSpectatePlayersOnly && bSpectateFirstPersonOnly)
	{
		mcbSpectatingMode.MyComboBox.List.SetIndex(0);
		Return;
	}
	mcbSpectatingMode.MyComboBox.List.SetIndex(1);
	*/
}