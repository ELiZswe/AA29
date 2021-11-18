// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAGamePanel/AAGameMenu_CP_Tournament/AAGameMenu_CP_Tournament.h"

UAAGameMenu_CP_Tournament::UAAGameMenu_CP_Tournament()
{
	//mebMatchName = moEditBox'AGP_Interface.AAGameMenu_CP_Tournament.MatchNameEntryField';
	//mebLeagueName = moEditBox'AGP_Interface.AAGameMenu_CP_Tournament.LeagueNameEntryField';
	//mebTournamentName = moEditBox'AGP_Interface.AAGameMenu_CP_Tournament.TournamentNameEntryField';
	//mebTournamentTeamName0 = moEditBox'AGP_Interface.AAGameMenu_CP_Tournament.Team0NameEntryField';
	//mebTournamentTeamName1 = moEditBox'AGP_Interface.AAGameMenu_CP_Tournament.Team1NameEntryField';
	//mebTournamentTeamPassword0 = moEditBox'AGP_Interface.AAGameMenu_CP_Tournament.Team0PasswordEntryField';
	//mebTournamentTeamPassword1 = moEditBox'AGP_Interface.AAGameMenu_CP_Tournament.Team1PasswordEntryField';
	//mchkbDisableFragGrenade = moCheckBox'AGP_Interface.AAGameMenu_CP_Tournament.DisableFragGrenadeCheckbox';
	//mchkbDisableSmokeGrenade = moCheckBox'AGP_Interface.AAGameMenu_CP_Tournament.DisableSmokeGrenadeCheckbox';
	//mchkbDisableThermiteGrenade = moCheckBox'AGP_Interface.AAGameMenu_CP_Tournament.DisableThermiteGrenadeCheckbox';
	//mchkbDisableFlashbangGrenade = moCheckBox'AGP_Interface.AAGameMenu_CP_Tournament.DisableFlashbangGrenadeCheckbox';
	//mchkbDisable203Reloads = moCheckBox'AGP_Interface.AAGameMenu_CP_Tournament.Disable203ReloadsCheckbox';
	//mneTournamentPauseLimit = moNumericEdit'AGP_Interface.AAGameMenu_CP_Tournament.PauseTimeLimitNumEditField';
	//mcbTournamentSwapLimit = moComboBox'AGP_Interface.AAGameMenu_CP_Tournament.SwapLimitDropDown';
	//mneTournamentSwapTime = moNumericEdit'AGP_Interface.AAGameMenu_CP_Tournament.SwapTimeLimitNumEditField';
	//mcbTournamentWarmupDuration = moComboBox'AGP_Interface.AAGameMenu_CP_Tournament.WarmupTimeDropDown';
	//guibSaveChanges = GUIButton'AGP_Interface.AAGameMenu_CP_Tournament.SaveChanges';
	//guibSwitchServerMode = GUIButton'AGP_Interface.AAGameMenu_CP_Tournament.SwitchServerModes';
	//mcbTournamentRequestDelayTime = moComboBox'AGP_Interface.AAGameMenu_CP_Tournament.RequestDelayTimeDropDown';
	//mcbTournamentRoundDelayTime = moComboBox'AGP_Interface.AAGameMenu_CP_Tournament.RoundDelayTimeDropDown';
	//mchkbMercyRule = moCheckBox'AGP_Interface.AAGameMenu_CP_Tournament.EnableMercyRuleCheckbox';
	//mchkbTournamentOpenAllWeaponClassSlots = moCheckBox'AGP_Interface.AAGameMenu_CP_Tournament.OpenAllWeaponSlotsCheckbox';
	//mchkbTournamentTeamCaptainsAllowed = moCheckBox'AGP_Interface.AAGameMenu_CP_Tournament.AllowTeamCaptainsCheckbox';
	//mchkbTournamentTeamPasswordsRequired = moCheckBox'AGP_Interface.AAGameMenu_CP_Tournament.TeamPasswordsRequiredCheckbox';
	//mchkbTournamentEnableRandomTeamAssignments = moCheckBox'AGP_Interface.AAGameMenu_CP_Tournament.RandomTeamAssignmentsCheckbox';
	//mcbTournamentTieBreakingRules = moComboBox'AGP_Interface.AAGameMenu_CP_Tournament.TieBreakingRulesDropDown';
	//gulInstructions = GUILabel'AGP_Interface.AAGameMenu_CP_Tournament.InstructionsLabel';
	//sInstructions = "Use this to customize tournament options.";
	//WinHeight = 1;

}

void UAAGameMenu_CP_Tournament::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	local int iTimeEntry;
	local int iRounds;
	InitComponent(MyController, MyOwner);
	gulInstructions.Caption = sInstructions;
	mcbTournamentSwapLimit.MyComboBox.Edit.bReadOnly = True;
	mcbTournamentWarmupDuration.MyComboBox.Edit.bReadOnly = True;
	mcbTournamentRequestDelayTime.MyComboBox.Edit.bReadOnly = True;
	mcbTournamentRoundDelayTime.MyComboBox.Edit.bReadOnly = True;
	mcbTournamentTieBreakingRules.MyComboBox.Edit.bReadOnly = True;
	mneTournamentPauseLimit.MinValue = 0;
	mneTournamentPauseLimit.MinValue = 120;
	mneTournamentSwapTime.MinValue = 0;
	mneTournamentSwapTime.MinValue = 120;
	mcbTournamentSwapLimit.MyComboBox.List.Insert(0, "Disabled", , "0");
	for (iRounds = 1; iRounds <= 20; iRounds++)
	{
		if (iRounds > 1)
		{
			mcbTournamentSwapLimit.MyComboBox.List.Insert(iRounds, "" $ iRounds $ " rounds", , "" $ iRounds);
		}
		else
		{
			mcbTournamentSwapLimit.MyComboBox.List.Insert(iRounds, "" $ iRounds $ " round", , "" $ iRounds);
		}
	}
	mcbTournamentWarmupDuration.MyComboBox.List.Insert(0, "Disabled", , "0");
	for (iTimeEntry = 1; iTimeEntry <= 10; iTimeEntry++)
	{
		if (iTimeEntry > 1)
		{
			mcbTournamentWarmupDuration.MyComboBox.List.Insert(iTimeEntry - 1, "" $ iTimeEntry $ " minutes", , "" $ iTimeEntry);
		}
		else
		{
			mcbTournamentWarmupDuration.MyComboBox.List.Insert(iTimeEntry - 1, "" $ iTimeEntry $ " minute", , "" $ iTimeEntry);
		}
	}
	mcbTournamentRequestDelayTime.MyComboBox.List.Insert(0, "30 seconds", , "30");
	mcbTournamentRequestDelayTime.MyComboBox.List.Insert(1, "45 seconds", , "45");
	mcbTournamentRequestDelayTime.MyComboBox.List.Insert(2, "1 minute", , "60");
	mcbTournamentRequestDelayTime.MyComboBox.List.Insert(3, "2 minutes", , "120");
	for (iTimeEntry = 1; iTimeEntry <= 12; iTimeEntry++)
	{
		if (iTimeEntry > 1)
		{
			mcbTournamentRoundDelayTime.MyComboBox.List.Insert(iTimeEntry - 1, "" $ iTimeEntry * 5 $ " seconds", , "" $ iTimeEntry * 5);
		}
		else
		{
			mcbTournamentRoundDelayTime.MyComboBox.List.Insert(iTimeEntry - 1, "" $ iTimeEntry * 5 $ " seconds", , "" $ iTimeEntry * 5);
		}
	}
	mcbTournamentTieBreakingRules.MyComboBox.List.Insert(0, "Allow Ties");
	mcbTournamentTieBreakingRules.MyComboBox.List.Insert(1, "Overtime");
	mcbTournamentTieBreakingRules.MyComboBox.List.Insert(2, "By Team Scores (points)");
	if (HumanController(PlayerOwner()).TournamentIsTournament())
	{
		guibSwitchServerMode.Caption = "Activate Standard Play";
		guibSwitchServerMode.Hint = "Click here to restart the server in standard non-Tournament Mode.";
	}
	else
	{
		guibSwitchServerMode.Caption = "Activate Tournament Mode";
		guibSwitchServerMode.Hint = "Click here to restart the server in Tournament Mode (changes will be saved).";
	}
	*/
}

void UAAGameMenu_CP_Tournament::InitializeDataFields()
{
	/*
	if (aagpCommandPost == None)
	{
		Log("Warning: The CP Rules page does not have a valid Command Post page.");
		Return;
	}
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Tournament", "AGP_GameTournament iTournamentRequestDelayTime");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Tournament", "AGP_GameTournament iTournamentRoundDelayTime");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Tournament", "AGP_GameTournament iTournamentSwapTime");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Tournament", "AGP_GameTournament iTournamentSwapLimit");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Tournament", "AGP_GameTournament iTournamentPauseLimit");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Tournament", "AGP_GameTournament iTournamentWarmupDuration");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Tournament", "AGP_GameTournament bTournamentMercyRule");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Tournament", "AGP_GameTournament bTournamentOpenAllWeaponClassSlots");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Tournament", "AGP_GameTournament bTournamentTeamCaptainsAllowed");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Tournament", "AGP_GameTournament bTournamentTeamCaptainsAllowed");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Tournament", "AGP_GameTournament bTournamentTieSuddenDeath");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Tournament", "AGP_GameTournament bTournamentTieScore");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Tournament", "AGP_GameTournament bTournamentEnableRandomTeamAssignments");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Tournament", "AGP_GameTournament bTournamentTeamPasswordsRequired");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Tournament", "AGP_GameTournament sMatchName");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Tournament", "AGP_GameTournament sTournamentName");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Tournament", "AGP_GameTournament sLeagueName");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Tournament", "AGP_GameTournament asTournamentTeamName[0]");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Tournament", "AGP_GameTournament asTournamentTeamName[1]");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Tournament", "AccessControl asTeamPasswords[0]");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Tournament", "AccessControl asTeamPasswords[1]");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Tournament", "GameReplicationInfo bDisableFragGrenades");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Tournament", "GameReplicationInfo bDisableFlashbangs");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Tournament", "GameReplicationInfo bDisableSmokeGrenades");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Tournament", "GameReplicationInfo bDisableThermiteGrenades");
	HumanController(PlayerOwner()).RequestServerINISetting(aagpCommandPost, "Tournament", "GameReplicationInfo bDisable203Grenades");
	*/
}

bool UAAGameMenu_CP_Tournament::IsAdmin()
{
	//Return PlayerOwner() != None && PlayerOwner().PlayerReplicationInfo != None && PlayerOwner().PlayerReplicationInfo.bAdmin;
	return false;   //FAKE   /ELiZ
}

bool UAAGameMenu_CP_Tournament::CanShowPanel()
{
	return true;
}

void UAAGameMenu_CP_Tournament::InternalOnChange(UGUIComponent* Sender)
{
	/*
	Switch(Sender)
	{
			case mchkbTournamentTeamPasswordsRequired:
				if (mchkbTournamentTeamPasswordsRequired.IsChecked())
				{
					mebTournamentTeamPassword0.EnableMe();
					mebTournamentTeamPassword1.EnableMe();
					break;
				}
				mebTournamentTeamPassword0.SetText("");
				mebTournamentTeamPassword0.DisableMe();
				mebTournamentTeamPassword1.SetText("");
				mebTournamentTeamPassword1.DisableMe();
	}
	GOTO JL009A;
		default:
			guibSaveChanges.EnableMe();
			GOTO JL009A;
		JL009A:

	*/
}

void UAAGameMenu_CP_Tournament::Timer()
{
	/*
	if (--iSwitchTimer == 0)
	{
		SetTimer(0, False);
		guibSwitchServerMode.DisableMe();
		if (HumanController(PlayerOwner()).TournamentIsTournament())
		{
			HumanController(PlayerOwner()).ConsoleCommand("admin message Server restarting in Standard Play Mode now.");
			HumanController(PlayerOwner()).ChangeServerToStandardMode();
		}
		else
		{
			HumanController(PlayerOwner()).ConsoleCommand("admin message Server restarting in Tournament Mode now.");
			HumanController(PlayerOwner()).ChangeServerToTournamentMode();
		}
		aagpCommandPost.fCloseRequested = True;
		HumanController(PlayerOwner()).ClientCloseMenu(True);
		Return;
	}
	if (HumanController(PlayerOwner()).TournamentIsTournament())
	{
		guibSwitchServerMode.Caption = "Cancel Switch To SPM in " $ iSwitchTimer;
		if (iSwitchTimer > 1)
		{
			HumanController(PlayerOwner()).ConsoleCommand("admin message Server restarting in Standard Play Mode in " $ iSwitchTimer $ " seconds");
		}
		else
		{
			HumanController(PlayerOwner()).ConsoleCommand("admin message Server restarting in Standard Play Mode in " $ iSwitchTimer $ " second");
		}
	}
	else
	{
		if (iSwitchTimer > 1)
		{
			HumanController(PlayerOwner()).ConsoleCommand("admin message Server restarting in Tournament Mode in " $ iSwitchTimer $ " seconds");
		}
		else
		{
			HumanController(PlayerOwner()).ConsoleCommand("admin message Server restarting in Tournament Mode in " $ iSwitchTimer $ " second");
		}
		guibSwitchServerMode.Caption = "Cancel Switch To TM in " $ iSwitchTimer;
	}
	*/
}

bool UAAGameMenu_CP_Tournament::ButtonClick(UGUIComponent* Sender)
{
	/*
	Switch(Sender)
	{
			case guibSwitchServerMode:
				if (iSwitchTimer > 0)
				{
					SetTimer(0, False);
					iSwitchTimer = 0;
					aagpCommandPost.guibtnClose.EnableMe();
					if (HumanController(PlayerOwner()).TournamentIsTournament())
					{
						HumanController(PlayerOwner()).ConsoleCommand("admin message Administrator has cancelled the switch to Standard Play Mode.");
						guibSwitchServerMode.Caption = "Activate Standard Play";
						guibSwitchServerMode.Hint = "Click here to restart the server in standard non-Tournament Mode.";
						break;
					}
					HumanController(PlayerOwner()).ConsoleCommand("admin message Administrator has cancelled the switch to Tournament Mode.");
					guibSwitchServerMode.Caption = "Activate Tournament Mode";
					guibSwitchServerMode.Hint = "Click here to restart the server in Tournament Mode (changes will be saved).";
				}
	}
		else
		{
		ButtonClick(guibSaveChanges);
		aagpCommandPost.guibtnClose.DisableMe();
		iSwitchTimer = 10;
		SetTimer(1, True);
		if (HumanController(PlayerOwner()).TournamentIsTournament())
		{
			guibSwitchServerMode.Caption = "Cancel Switch To SPM in 10";
		}
		else
		{
			guibSwitchServerMode.Caption = "Cancel Switch To TM in 10";
		}
		guibSwitchServerMode.Hint = "Click here to cancel the server mode change.";
			case guibSaveChanges:
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameTournament sMatchName " $ mebMatchName.GetText());
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameTournament sLeagueName " $ mebLeagueName.GetText());
				HumanController(PlayerOwner()).ServerUpdateActiveTournamentField("AGP_GameTournament sLeagueName", mebLeagueName.GetText());
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameTournament sTournamentName " $ mebTournamentName.GetText());
				HumanController(PlayerOwner()).ServerUpdateActiveTournamentField("AGP_GameTournament sTournamentName", mebTournamentName.GetText());
				HumanController(PlayerOwner()).ServerSetTournamentINITeamName(0, mebTournamentTeamName0.GetText());
				HumanController(PlayerOwner()).ServerUpdateActiveTournamentField("AGP_GameTournament asTournamentTeamName[0]", mebTournamentTeamName0.GetText());
				HumanController(PlayerOwner()).ServerSetTournamentINITeamName(1, mebTournamentTeamName1.GetText());
				HumanController(PlayerOwner()).ServerUpdateActiveTournamentField("AGP_GameTournament asTournamentTeamName[1]", mebTournamentTeamName1.GetText());
				HumanController(PlayerOwner()).ServerSetTournamentINITeamPassword(0, mebTournamentTeamPassword0.GetText());
				HumanController(PlayerOwner()).ServerSetTournamentINITeamPassword(1, mebTournamentTeamPassword1.GetText());
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameTournament iTournamentRequestDelayTime " $ mcbTournamentRequestDelayTime.GetExtra());
				HumanController(PlayerOwner()).ServerUpdateActiveTournamentField("AGP_GameTournament iTournamentRequestDelayTime", mcbTournamentRequestDelayTime.GetExtra());
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameTournament iTournamentRoundDelayTime " $ mcbTournamentRoundDelayTime.GetExtra());
				HumanController(PlayerOwner()).ServerUpdateActiveTournamentField("AGP_GameTournament iTournamentRoundDelayTime", mcbTournamentRoundDelayTime.GetExtra());
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameTournament iTournamentSwapTime " $ mneTournamentSwapTime.GetComponentValue());
				HumanController(PlayerOwner()).ServerUpdateActiveTournamentField("AGP_GameTournament iTournamentSwapTime", mneTournamentSwapTime.GetComponentValue());
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameTournament iTournamentSwapLimit " $ mcbTournamentSwapLimit.GetExtra());
				HumanController(PlayerOwner()).ServerUpdateActiveTournamentField("AGP_GameTournament iTournamentSwapLimit", mcbTournamentSwapLimit.GetExtra());
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameTournament iTournamentWarmupDuration " $ mcbTournamentWarmupDuration.GetExtra());
				HumanController(PlayerOwner()).ServerUpdateActiveTournamentField("AGP_GameTournament iTournamentWarmupDuration", mcbTournamentWarmupDuration.GetExtra());
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameTournament iTournamentPauseLimit " $ mneTournamentPauseLimit.GetComponentValue());
				HumanController(PlayerOwner()).ServerUpdateActiveTournamentField("AGP_GameTournament iTournamentPauseLimit", mneTournamentPauseLimit.GetComponentValue());
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameTournament bTournamentMercyRule " $ mchkbMercyRule.GetComponentValue());
				HumanController(PlayerOwner()).ServerUpdateActiveTournamentField("AGP_GameTournament bTournamentMercyRule", mchkbMercyRule.GetComponentValue());
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameTournament bTournamentOpenAllWeaponClassSlots " $ mchkbTournamentOpenAllWeaponClassSlots.GetComponentValue());
				HumanController(PlayerOwner()).ServerUpdateActiveTournamentField("AGP_GameTournament bTournamentOpenAllWeaponClassSlots", mchkbTournamentOpenAllWeaponClassSlots.GetComponentValue());
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameTournament bTournamentTeamCaptainsAllowed " $ mchkbTournamentTeamCaptainsAllowed.GetComponentValue());
				HumanController(PlayerOwner()).ServerUpdateActiveTournamentField("AGP_GameTournament bTournamentTeamCaptainsAllowed", mchkbTournamentTeamCaptainsAllowed.GetComponentValue());
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameTournament bTournamentTeamPasswordsRequired " $ mchkbTournamentTeamPasswordsRequired.GetComponentValue());
				HumanController(PlayerOwner()).ServerUpdateActiveTournamentField("AGP_GameTournament bTournamentTeamPasswordsRequired", mchkbTournamentTeamPasswordsRequired.GetComponentValue());
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameTournament bTournamentEnableRandomTeamAssignments " $ mchkbTournamentEnableRandomTeamAssignments.GetComponentValue());
				HumanController(PlayerOwner()).ServerUpdateActiveTournamentField("AGP_GameTournament bTournamentEnableRandomTeamAssignments", mchkbTournamentEnableRandomTeamAssignments.GetComponentValue());
				HumanController(PlayerOwner()).ServerSetINISetting("GameReplicationInfo bDisableFragGrenades " $ mchkbDisableFragGrenade.GetComponentValue());
				HumanController(PlayerOwner()).ServerSetINISetting("GameReplicationInfo bDisableFlashbangs " $ mchkbDisableFlashbangGrenade.GetComponentValue());
				HumanController(PlayerOwner()).ServerSetINISetting("GameReplicationInfo bDisableSmokeGrenades " $ mchkbDisableSmokeGrenade.GetComponentValue());
				HumanController(PlayerOwner()).ServerSetINISetting("GameReplicationInfo bDisableThermiteGrenades " $ mchkbDisableThermiteGrenade.GetComponentValue());
				HumanController(PlayerOwner()).ServerSetINISetting("GameReplicationInfo bDisable203Grenades " $ mchkbDisable203Reloads.GetComponentValue());
				Switch(mcbTournamentTieBreakingRules.GetIndex())
				{
			case 0:
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameTournament bTournamentTieScore false");
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameTournament bTournamentTieSuddenDeath false");
				HumanController(PlayerOwner()).ServerUpdateActiveTournamentField("AGP_GameTournament bTournamentTieScore", "false");
				HumanController(PlayerOwner()).ServerUpdateActiveTournamentField("AGP_GameTournament bTournamentTieSuddenDeath", "false");
				break;
			case 1:
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameTournament bTournamentTieScore false");
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameTournament bTournamentTieSuddenDeath true");
				HumanController(PlayerOwner()).ServerUpdateActiveTournamentField("AGP_GameTournament bTournamentTieScore", "false");
				HumanController(PlayerOwner()).ServerUpdateActiveTournamentField("AGP_GameTournament bTournamentTieSuddenDeath", "true");
				break;
			case 2:
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameTournament bTournamentTieScore true");
				HumanController(PlayerOwner()).ServerSetINISetting("AGP_GameTournament bTournamentTieSuddenDeath false");
				HumanController(PlayerOwner()).ServerUpdateActiveTournamentField("AGP_GameTournament bTournamentTieScore", "true");
				HumanController(PlayerOwner()).ServerUpdateActiveTournamentField("AGP_GameTournament bTournamentTieSuddenDeath", "false");
				break;
			default:
				}
				guibSaveChanges.DisableMe();
			default:
		}
	*/
	return true;
}

void UAAGameMenu_CP_Tournament::NotifyCustomParameters(FString sParam1, FString sParam2, FString sParam3)
{
	/*
	if (sParam1 ~= "INIEntry")
	{
		if (sParam2 ~= "AGP_GameTournament bTournamentMercyRule")
		{
			mchkbMercyRule.SetComponentValue(sParam3, True);
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "AGP_GameTournament bTournamentOpenAllWeaponClassSlots")
		{
			mchkbTournamentOpenAllWeaponClassSlots.SetComponentValue(sParam3, True);
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "AGP_GameTournament bTournamentTeamCaptainsAllowed")
		{
			mchkbTournamentTeamCaptainsAllowed.SetComponentValue(sParam3, True);
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "AGP_GameTournament bTournamentTeamPasswordsRequired")
		{
			mchkbTournamentTeamPasswordsRequired.SetComponentValue(sParam3, True);
			InternalOnChange(mchkbTournamentTeamPasswordsRequired);
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "AGP_GameTournament bTournamentEnableRandomTeamAssignments")
		{
			mchkbTournamentEnableRandomTeamAssignments.SetComponentValue(sParam3, True);
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "AGP_GameTournament bTournamentTieSuddenDeath")
		{
			bTournamentTieSuddenDeath = sParam3;
			UpdateTieBreakingRulesField();
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "AGP_GameTournament bTournamentTieScore")
		{
			bTournamentTieScore = sParam3;
			UpdateTieBreakingRulesField();
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "GameReplicationInfo bDisableFragGrenades")
		{
			mchkbDisableFragGrenade.SetComponentValue(sParam3, True);
			InternalOnChange(mchkbDisableFragGrenade);
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "GameReplicationInfo bDisableFlashbangs")
		{
			mchkbDisableFlashbangGrenade.SetComponentValue(sParam3, True);
			InternalOnChange(mchkbDisableFlashbangGrenade);
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "GameReplicationInfo bDisableSmokeGrenades")
		{
			mchkbDisableSmokeGrenade.SetComponentValue(sParam3, True);
			InternalOnChange(mchkbDisableSmokeGrenade);
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "GameReplicationInfo bDisableThermiteGrenades")
		{
			mchkbDisableThermiteGrenade.SetComponentValue(sParam3, True);
			InternalOnChange(mchkbDisableThermiteGrenade);
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "GameReplicationInfo bDisable203Grenades")
		{
			mchkbDisable203Reloads.SetComponentValue(sParam3, True);
			InternalOnChange(mchkbDisable203Reloads);
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "AGP_GameTournament iTournamentPauseLimit")
		{
			mneTournamentPauseLimit.SetComponentValue(sParam3, True);
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "AGP_GameTournament iTournamentRoundDelayTime")
		{
			if (sParam3 > 1)
			{
				mcbTournamentRoundDelayTime.SetText(sParam3 $ " seconds");
			}
			else
			{
				mcbTournamentRoundDelayTime.SetText(sParam3 $ " second");
			}
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "AGP_GameTournament iTournamentSwapTime")
		{
			mneTournamentSwapTime.SetComponentValue(sParam3, True);
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "AGP_GameTournament iTournamentSwapLimit")
		{
			if (sParam3 > 0)
			{
				if (sParam3 > 1)
				{
					mcbTournamentSwapLimit.SetText(sParam3 $ " rounds", True);
				}
				else
				{
					mcbTournamentSwapLimit.SetText(sParam3 $ " round", True);
				}
			}
			else
			{
				mcbTournamentSwapLimit.SetText("Disabled", True);
			}
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "AGP_GameTournament iTournamentWarmupDuration")
		{
			if (sParam3 > 0)
			{
				if (sParam3 > 1)
				{
					mcbTournamentWarmupDuration.SetText(sParam3 $ " minutes", True);
				}
				else
				{
					mcbTournamentWarmupDuration.SetText(sParam3 $ " minute", True);
				}
			}
			else
			{
				mcbTournamentWarmupDuration.SetText("Disabled", True);
			}
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "AGP_GameTournament sMatchName")
		{
			mebMatchName.SetComponentValue(sParam3, True);
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "AGP_GameTournament sLeagueName")
		{
			mebLeagueName.SetComponentValue(sParam3, True);
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "AGP_GameTournament sTournamentName")
		{
			mebTournamentName.SetComponentValue(sParam3, True);
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "AGP_GameTournament asTournamentTeamName[0]")
		{
			mebTournamentTeamName0.SetComponentValue(sParam3, True);
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "AGP_GameTournament asTournamentTeamName[1]")
		{
			mebTournamentTeamName1.SetComponentValue(sParam3, True);
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "AccessControl asTeamPasswords[0]")
		{
			mebTournamentTeamPassword0.SetComponentValue(sParam3, True);
			guibSaveChanges.DisableMe();
			Return;
		}
		if (sParam2 ~= "AccessControl asTeamPasswords[1]")
		{
			mebTournamentTeamPassword1.SetComponentValue(sParam3, True);
			guibSaveChanges.DisableMe();
			Return;
		}
	}
	*/
}

void UAAGameMenu_CP_Tournament::UpdateTieBreakingRulesField()
{
	/*
	if (!bTournamentTieScore && !bTournamentTieSuddenDeath)
	{
		mcbTournamentTieBreakingRules.MyComboBox.List.SetIndex(0);
		Return;
	}
	if (!bTournamentTieScore && bTournamentTieSuddenDeath)
	{
		mcbTournamentTieBreakingRules.MyComboBox.List.SetIndex(1);
		Return;
	}
	if (bTournamentTieScore && !bTournamentTieSuddenDeath)
	{
		mcbTournamentTieBreakingRules.MyComboBox.List.SetIndex(2);
		Return;
	}
	mcbTournamentTieBreakingRules.MyComboBox.List.SetIndex(1);
	*/
}
