// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAGamePanel/AAGameMenu_CP_PlayerManagement/AAGameMenu_CP_PlayerManagement.h"

UAAGameMenu_CP_PlayerManagement::UAAGameMenu_CP_PlayerManagement()
{
	//guilInstructions = GUILabel'AGP_Interface.AAGameMenu_CP_PlayerManagement.InstructionsLabel';
	//guilPlayerListTitle = GUILabel'AGP_Interface.AAGameMenu_CP_PlayerManagement.PlayersListTitle';
	//guilbPlayersList = GUIListBox'AGP_Interface.AAGameMenu_CP_PlayerManagement.PlayersListBox';
	//guilSpectatorListTitle = GUILabel'AGP_Interface.AAGameMenu_CP_PlayerManagement.SpectatorsListTitle';
	//guilbSpectatorList = GUIListBox'AGP_Interface.AAGameMenu_CP_PlayerManagement.SpectatorsListBox';
	//mcbWeaponSelections = moComboBox'AGP_Interface.AAGameMenu_CP_PlayerManagement.WeaponSelectionDropDown';
	//guilWeaponSelectAMNotice = GUILabel'AGP_Interface.AAGameMenu_CP_PlayerManagement.WeaponSelectAMNotice';
	//guibViewPlayer = GUIButton'AGP_Interface.AAGameMenu_CP_PlayerManagement.ViewButton';
	//guibKickPlayer = GUIButton'AGP_Interface.AAGameMenu_CP_PlayerManagement.KickButton';
	//guibMutePlayer = GUIButton'AGP_Interface.AAGameMenu_CP_PlayerManagement.MuteButton';
	//mebPrivateMessage = moEditBox'AGP_Interface.AAGameMenu_CP_PlayerManagement.PrivateMessageEntryField';
	//guibMessagePlayer = GUIButton'AGP_Interface.AAGameMenu_CP_PlayerManagement.MessageButton';
	//guibChangeWeapon = GUIButton'AGP_Interface.AAGameMenu_CP_PlayerManagement.ChangeWeaponButton';
	//guilPlayerDetailsTitle = GUILabel'AGP_Interface.AAGameMenu_CP_PlayerManagement.PlayerDetailsTitle';
	//guilPlayerDetailsName = GUILabel'AGP_Interface.AAGameMenu_CP_PlayerManagement.PlayerDetailsName';
	//guilPlayerDetailsScore = GUILabel'AGP_Interface.AAGameMenu_CP_PlayerManagement.PlayerDetailsScore';
	//guilPlayerDetailsTeam = GUILabel'AGP_Interface.AAGameMenu_CP_PlayerManagement.PlayerDetailsTeam';
	//guilPlayerDetailsLocation = GUILabel'AGP_Interface.AAGameMenu_CP_PlayerManagement.PlayerDetailsLocation';
	//guibSwapTeams = GUIButton'AGP_Interface.AAGameMenu_CP_PlayerManagement.SwapTeamButton';
	sInstructions = "Use this to manage players.  You can assign players to teams, assign weapons, kick, mute, privately message, or view players.";
	sPlayerListBoxTitle = "Players";
	sPlayerDetailsTitle = "Player Details";
	asWeaponNames = { "M4-A1", "M4-A1 Auto", "M249 SAW", "M16 Rifleman", "Recruit", "AK47 Rifleman", "AK74 SU", "RPK", "M4 SOPMOD Rifleman", "M16/M203", "AK47/GP30", "*MOS", "*M-82 Barret", "*M-24", "*SVD", "RPG", "AT-4", "BDM", "M-9 (Pistol)", "Special Forces", "*SPR (SF)", "IF PSO", "*IF Advanced Marksman", "IF RPG", "SF Weapons Sergeant", "Javelin", "IF RPG 9" };
	asWeaponForceClassCommand = { "M4A1", "M4A1Auto", "AutomaticRifleman", "Rifleman", "Recruit", "RiflemanAK", "AK74SU", "RPK", "M4M", "Grenadier", "GP", "Mos", "Sniper82", "Sniper24", "SVD", "RPG", "AT4", "BDM", "M9", "SF", "SPR", "GuerrillaPSO", "GuerrillaSniper", "GuerrillaRPG", "D", "J", "rpg9" };
	asWeaponClassNames = { "AGP_Characters.ClassRiflemanM4A1AutoIron", "AGP_Characters.ClassRiflemanM4A1Auto", "AGP_Characters.ClassAutomaticRifleman", "AGP_Characters.ClassRifleman""AGP_Characters.ClassRecruit","AGP_Characters.ClassRiflemanAK","AGP_Characters.ClassRiflemanAK74SU","AGP_Characters.ClassAutomaticRiflemanRPK","AGP_Characters.ClassRiflemanM4A1Mod","AGP_Characters.ClassGrenadier","AGP_Characters.ClassGrenadierGP30_Op","AGP_Characters.ClassSniperMos","AGP_Characters.ClassSniper","AGP_Characters.ClassSniper24_US","AGP_Characters.ClassSniperSVD","AGP_Characters.ClassRPG","AGP_Characters.ClassAT4Rocket","AGP_Characters.ClassBDMRocket","AGP_Characters.ClassPistol","AGP_Characters.ClassSF","AGP_Characters.ClassSFSniper","AGP_Characters.ClassGuerrillaPSO","AGP_Characters.ClassGuerrillaSniper","AGP_Characters.ClassGuerrillaRPG","AGP_Characters.ClassDemolitions","AGP_Characters.ClassJavelin","AGP_Characters.ClassGuerrillaRPGNine" };
	asWeaponAltClassNames = {"", "", "AGP_Inventory.Weapon_M249_SAW", "AGP_Inventory.Weapon_M16A2_Rifle", "", "AGP_Inventory.Weapon_AK47_Rifle", "AGP_Inventory.Weapon_AK74su_Rifle", "AGP_Inventory.Weapon_RPK_SAW", "AGP_Inventory.Weapon_M4A1_Rifle_Mod", "AGP_Inventory.Weapon_M203_Gren", "AGP_Inventory.Weapon_GP30_Gren", "AGP_Inventory.Weapon_MosNagant_Sniper", "AGP_Inventory.Weapon_M82_Sniper", "AGP_Inventory.Weapon_M24_Sniper", "AGP_Inventory.Weapon_SVD_Sniper", "AGP_Inventory.Weapon_RPG7", "AGP_Inventory.Weapon_AT4_Rocket", "AGP_Inventory.Weapon_BDM_Rocket", "AGP_Inventory.Weapon_M9_Pistol", "", "AGP_Inventory.Weapon_SPR_Sniper"};
	WinHeight = 1;
	bTabStop = true;
}

void UAAGameMenu_CP_PlayerManagement::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	local int32 iWeaponIndex;
	InitComponent(MyController, MyOwner);
	guilInstructions.Caption = sInstructions;
	guilPlayerListTitle.Caption = sPlayerListBoxTitle;
	guilbPlayersList.List.__CompareItem__Delegate = ComparePlayerListItems;
	guilbPlayersList.List.TextAlign = 0;
	guilbSpectatorList.List.TextAlign = 0;
	for (iWeaponIndex = 0; iWeaponIndex < asWeaponNames.Length; iWeaponIndex++)
	{
		mcbWeaponSelections.addItem(asWeaponNames[iWeaponIndex], , asWeaponForceClassCommand[iWeaponIndex]);
	}
	RefreshPlayerList();
	RefreshSpectatorList();
	iCurrentlySelectedPlayerID = 0;
	OnPlayerListClick(guilbPlayersList);
	if (HumanController(PlayerOwner()).TournamentIsTournament())
	{
		mcbWeaponSelections.Hint = "Weapon's should usually be assigned using the Tournament Roster tools.";
		mcbWeaponSelections.MyComboBox.Edit.Hint = "Weapon's should usually be assigned using the Tournament Roster tools.";
	}
	SetTimer(2, True);
	*/
}

void UAAGameMenu_CP_PlayerManagement::OnPlayerListDrawItem(UCanvas* Canvas, int32 iItemIndex, float fpX, float fpY, float fpWidth, float fpHeight, bool bSelected, bool bPending)
{
	//DrawListItem(guilbPlayersList, Canvas, iItemIndex, fpX, fpY, fpWidth, fpHeight, bSelected, bPending);
}

void UAAGameMenu_CP_PlayerManagement::OnSpectatorListDrawItem(UCanvas* Canvas, int32 iItemIndex, float fpX, float fpY, float fpWidth, float fpHeight, bool bSelected, bool bPending)
{
	//DrawListItem(guilbSpectatorList, Canvas, iItemIndex, fpX, fpY, fpWidth, fpHeight, False, bPending);
}

void UAAGameMenu_CP_PlayerManagement::DrawListItem(UGUIListBox* guilb, UCanvas* Canvas, int32 iItemIndex, float fpX, float fpY, float fpWidth, float fpHeight, bool bSelected, bool bPending)
{
	/*
	local string sItemText;
	local XInterface.GUIStyles guistyle;
	sItemText = guilb.List.getItemAtIndex(iItemIndex);
	if (bSelected && guilb.List.SelectedStyle != None)
	{
		guistyle.Draw(Canvas, guilb.List.MenuState, fpX, fpY, fpWidth, fpHeight);
	}
	else
	{
		guistyle = guilb.List.Style;
	}
	guistyle.DrawText(Canvas, 0, fpX, fpY, fpWidth, fpHeight, 0, sItemText, guilb.FontScale);
	*/
}

void UAAGameMenu_CP_PlayerManagement::RefreshPlayerList()
{
	/*
	local string sPlayerEntry;
	local string sTeamName;
	local GameReplicationInfo GRI;
	local int32 iPlayerIndex;
	local int32 iFoundPlayers;
	local int32 iFoundPlayerIndex;
	local bool bRefillList;
	bRefillList = False;
	GRI = PlayerOwner().GameReplicationInfo;
	for (iPlayerIndex = 0; iPlayerIndex < GRI.PRIArray.Length; iPlayerIndex++)
	{
		if (GRI.PRIArray[iPlayerIndex] != None)
		{
			if (GRI.PRIArray[iPlayerIndex].bOnlySpectator == False && GRI.PRIArray[iPlayerIndex].PlayerName != "Recruit")
			{
				iFoundPlayers++;
			}
		}
	}
	if (iFoundPlayers != guilbPlayersList.List.Elements.Length)
	{
		bRefillList = True;
	}
	else
	{
		iPlayerIndex = 0;
		if (iPlayerIndex < GRI.PRIArray.Length)
		{
			if (GRI.PRIArray[iPlayerIndex] != None && GRI.PRIArray[iPlayerIndex].bOnlySpectator == False && GRI.PRIArray[iPlayerIndex].PlayerName != "Recruit")
			{
				iFoundPlayerIndex = guilbPlayersList.List.FindExtra(GRI.PRIArray[iPlayerIndex].PlayerID);
				if (iFoundPlayerIndex == -1)
				{
					bRefillList = True;
				}
				else
				{
			else
			{
				if (HumanController(PlayerOwner()).TournamentIsTournament())
				{
					if (GRI.PRIArray[iPlayerIndex].bTournamentTeamCaptain && InStr(guilbPlayersList.List.getItemAtIndex(iFoundPlayerIndex), "(Team Captain)") == -1 || !GRI.PRIArray[iPlayerIndex].bTournamentTeamCaptain && InStr(guilbPlayersList.List.getItemAtIndex(iFoundPlayerIndex), "(Team Captain)") != -1)
					{
						bRefillList = True;
					}
				}
				else
				{
					if (GRI.PRIArray[iPlayerIndex].Team.TeamIndex == 0 && Right(guilbPlayersList.List.getItemAtIndex(iFoundPlayerIndex), 2) == "t)")
					{
					}
					else
					{
						if (GRI.PRIArray[iPlayerIndex].Team.TeamIndex == 1 && Right(guilbPlayersList.List.getItemAtIndex(iFoundPlayerIndex), 2) == "e)")
						{
						}
						else
						{
							if (GRI.PRIArray[iPlayerIndex].Team.TeamIndex != 255)
							{
								bRefillList = True;
							}
						}
					}
				}
			}
			iPlayerIndex++;
				}
			}
		}
	}
	if (!bRefillList)
	{
		Return;
	}
	guilbPlayersList.List.Clear();
	for (iPlayerIndex = 0; iPlayerIndex < GRI.PRIArray.Length; iPlayerIndex++)
	{
		if (GRI.PRIArray[iPlayerIndex] != None)
		{
			if (GRI.PRIArray[iPlayerIndex].bOnlySpectator == False && GRI.PRIArray[iPlayerIndex].PlayerName != "Recruit")
			{
				if (GRI.PRIArray[iPlayerIndex].Team.TeamIndex == 0)
				{
					if (HumanController(PlayerOwner()).TournamentIsTournament())
					{
						sTeamName = HumanController(PlayerOwner()).GetTeamName(0) $ " Assault";
					}
					else
					{
						sTeamName = "Assault";
					}
				}
				else
				{
					if (GRI.PRIArray[iPlayerIndex].Team.TeamIndex == 1)
					{
						if (HumanController(PlayerOwner()).TournamentIsTournament())
						{
							sTeamName = HumanController(PlayerOwner()).GetTeamName(1) $ " Defense";
						}
						else
						{
							sTeamName = "Defense";
						}
					}
					else
					{
						sTeamName = "Unassigned";
					}
				}
				sPlayerEntry = GRI.PRIArray[iPlayerIndex].PlayerName;
				if (GRI.PRIArray[iPlayerIndex].bAdmin)
				{
					sPlayerEntry = sPlayerEntry $ " (Player Admin)";
				}
				if (GRI.PRIArray[iPlayerIndex].bTournamentTeamCaptain)
				{
					sPlayerEntry = sPlayerEntry $ " (Team Captain)";
				}
				sPlayerEntry = sPlayerEntry $ " (" $ sTeamName $ ")";
				guilbPlayersList.List.Add(sPlayerEntry, , GRI.PRIArray[iPlayerIndex].PlayerID);
			}
		}
	}
	guilbPlayersList.List.SortList();
	*/
}

void UAAGameMenu_CP_PlayerManagement::RefreshSpectatorList()
{
	/*
	local string sSpectatorName;
	local GameReplicationInfo GRI;
	local int32 iPlayerIndex;
	local int32 iNumSpectators;
	GRI = PlayerOwner().GameReplicationInfo;
	for (iPlayerIndex = 0; iPlayerIndex < GRI.PRIArray.Length; iPlayerIndex++)
	{
		if (GRI.PRIArray[iPlayerIndex] != None)
		{
			if (GRI.PRIArray[iPlayerIndex].bOnlySpectator)
			{
				iNumSpectators++;
			}
		}
	}
	if (iNumSpectators == guilbSpectatorList.List.Elements.Length)
	{
		Return;
	}
	guilbSpectatorList.List.Clear();
	for (iPlayerIndex = 0; iPlayerIndex < GRI.PRIArray.Length; iPlayerIndex++)
	{
		if (GRI.PRIArray[iPlayerIndex] != None)
		{
			if (GRI.PRIArray[iPlayerIndex].bOnlySpectator)
			{
				sSpectatorName = GRI.PRIArray[iPlayerIndex].PlayerName;
				if (GRI.PRIArray[iPlayerIndex].bAdmin)
				{
					sSpectatorName = sSpectatorName $ " (Admin)";
				}
				guilbSpectatorList.List.Add(sSpectatorName, GRI.PRIArray[iPlayerIndex]);
			}
		}
	}
	*/
}

void UAAGameMenu_CP_PlayerManagement::ComparePlayerListItems(FGUIListElem ElemA, FGUIListElem ElemB)
{
	/*
	if (StrCmp(Right(ElemA.Item, 2), Right(ElemB.Item, 2), , False) == 0)
	{
		Return StrCmp(ElemA.Item, ElemB.Item, , False);
	}
	else
	{
		Return StrCmp(Right(ElemA.Item, 2), Right(ElemB.Item, 2), , False);
	}
	*/
}

void UAAGameMenu_CP_PlayerManagement::Timer()
{
	/*
	RefreshPlayerList();
	RefreshSpectatorList();
	if (FindPRIFromID(iCurrentlySelectedPlayerID) != None)
	{
		guilbPlayersList.List.SetIndex(guilbPlayersList.List.FindExtra(iCurrentlySelectedPlayerID));
		UpdateSelectedPlayerDetails(False);
	}
	else
	{
		UpdateSelectedPlayerDetails(True);
	}
	*/
}

bool UAAGameMenu_CP_PlayerManagement::IsAdmin()
{
	//Return PlayerOwner() != None && PlayerOwner().PlayerReplicationInfo != None && PlayerOwner().PlayerReplicationInfo.bAdmin;
	return false;   //FAKE   /ELiZ
}

bool UAAGameMenu_CP_PlayerManagement::CanShowPanel()
{
	return true;
}

bool UAAGameMenu_CP_PlayerManagement::ButtonClick(UGUIComponent* Sender)
{
	/*
	Switch(Sender)
	{
			case guibChangeWeapon:
				if (FindPRIFromID(iCurrentlySelectedPlayerID) != None)
				{
					HumanController(PlayerOwner()).ConsoleCommand("admin forceclass " $ FindPRIFromID(iCurrentlySelectedPlayerID).PlayerName $ " " $ mcbWeaponSelections.GetExtra());
				}
				guibChangeWeapon.DisableMe();
				break;
			case guibMessagePlayer:
				if (FindPRIFromID(iCurrentlySelectedPlayerID) != None)
				{
					HumanController(PlayerOwner()).ServerSendClientNotifyAdminMessage(FindPRIFromID(iCurrentlySelectedPlayerID), mebPrivateMessage.GetText());
					mebPrivateMessage.SetText("");
					guibMessagePlayer.DisableMe();
				}
				break;
			case guibSwapTeams:
				if (FindPRIFromID(iCurrentlySelectedPlayerID) != None)
				{
					if (HumanController(PlayerOwner()).TournamentIsTournament())
					{
						if (FindPRIFromID(iCurrentlySelectedPlayerID).Team.TeamIndex == 0)
						{
							HumanController(PlayerOwner()).TournamentServerAdminAssignPlayerToTeam(1, FindPRIFromID(iCurrentlySelectedPlayerID));
						}
						else
						{
							HumanController(PlayerOwner()).TournamentServerAdminAssignPlayerToTeam(0, FindPRIFromID(iCurrentlySelectedPlayerID));
						}
					}
					else
					{
						HumanController(PlayerOwner()).ConsoleCommand("admin A_SwitchTeam " $ FindPRIFromID(iCurrentlySelectedPlayerID).PlayerName);
					}
				}
				GOTO JL02DF;
			case guibMutePlayer:
				if (FindPRIFromID(iCurrentlySelectedPlayerID) != None)
				{
					HumanController(PlayerOwner()).ConsoleCommand("admin mute " $ FindPRIFromID(iCurrentlySelectedPlayerID).PlayerName);
				}
				GOTO JL02DF;
			case guibKickPlayer:
				if (FindPRIFromID(iCurrentlySelectedPlayerID) != None)
				{
					HumanController(PlayerOwner()).ConsoleCommand("admin kick " $ FindPRIFromID(iCurrentlySelectedPlayerID).PlayerName);
				}
				GOTO JL02DF;
			case guibViewPlayer:
				if (FindPRIFromID(iCurrentlySelectedPlayerID) != None)
				{
					HumanController(PlayerOwner()).ConsoleCommand("admin spectate " $ FindPRIFromID(iCurrentlySelectedPlayerID).PlayerName);
					HumanController(PlayerOwner()).ClientCloseMenu(True);
					guibViewPlayer.DisableMe();
				}
				GOTO JL02DF;
			default:
			JL02DF:
	}
	*/
	return true;
}

void UAAGameMenu_CP_PlayerManagement::InternalOnChange(UGUIComponent* Sender)
{
	/*
	Switch(Sender)
	{
			case mebPrivateMessage:
				if (Len(mebPrivateMessage.GetText()) > 0)
				{
					guibMessagePlayer.EnableMe();
					break;
				}
				guibMessagePlayer.DisableMe();
	}
	Return;
		case mcbWeaponSelections:
			guibChangeWeapon.EnableMe();
			Return;
		default:
*/
}

bool UAAGameMenu_CP_PlayerManagement::OnPlayerListClick(UGUIComponent* Sender)
{
	/*
	if (Sender == guilbPlayersList)
	{
		UpdateSelectedPlayerDetails(True);
	}
	*/
	return true;
}

void UAAGameMenu_CP_PlayerManagement::UpdateSelectedPlayerDetails(bool fUpdateWeaponSelection)
{
	/*
	local PlayerReplicationInfo priSelected;
	if (Len(guilbPlayersList.List.GetExtra()) > 0 && FindPRIFromID(guilbPlayersList.List.GetExtra()) != None)
	{
		iCurrentlySelectedPlayerID = guilbPlayersList.List.GetExtra();
		priSelected = FindPRIFromID(iCurrentlySelectedPlayerID);
		guilPlayerDetailsName.Caption = "Name: " $ priSelected.PlayerName;
		guilPlayerDetailsName.EnableMe();
		if (priSelected.Team.TeamIndex == 0)
		{
			guilPlayerDetailsTeam.Caption = "Team: Assault";
		}
		else
		{
			if (priSelected.Team.TeamIndex == 1)
			{
				guilPlayerDetailsTeam.Caption = "Team: Defense";
			}
			else
			{
				guilPlayerDetailsTeam.Caption = "Team: Unassigned";
			}
		}
		guilPlayerDetailsTeam.EnableMe();
		if (CommVolume(priSelected.PlayerVolume) != None)
		{
			guilPlayerDetailsLocation.Caption = "Location: " $ CommVolume(priSelected.PlayerVolume).LocationName;
		}
		else
		{
			guilPlayerDetailsLocation.Caption = "Location: Unavailable";
		}
		guilPlayerDetailsLocation.EnableMe();
		guilPlayerDetailsScore.Caption = "Score: " $ priSelected.Score_Total $ "  Kills: " $ priSelected.Score_Kills $ " Deaths: " $ priSelected.Score_Deaths $ "  ROE: " $ priSelected.Score_ROE;
		guilPlayerDetailsScore.EnableMe();
		if (fUpdateWeaponSelection)
		{
			mcbWeaponSelections.SetText(GetPlayerWeapon(iCurrentlySelectedPlayerID));
			guibChangeWeapon.DisableMe();
		}
		mcbWeaponSelections.EnableMe();
		guibSwapTeams.EnableMe();
		guilWeaponSelectAMNotice.EnableMe();
		guilPlayerDetailsTitle.EnableMe();
		mebPrivateMessage.EnableMe();
		guibViewPlayer.EnableMe();
		guibKickPlayer.EnableMe();
		guibMutePlayer.EnableMe();
	}
	else
	{
		guilPlayerDetailsName.Caption = "Name: ";
		guilPlayerDetailsName.DisableMe();
		guilPlayerDetailsTeam.Caption = "Team: ";
		guilPlayerDetailsTeam.DisableMe();
		guilPlayerDetailsLocation.Caption = "Location: ";
		guilPlayerDetailsLocation.DisableMe();
		guilPlayerDetailsScore.Caption = "Score: ";
		guilPlayerDetailsScore.DisableMe();
		mcbWeaponSelections.DisableMe();
		guibChangeWeapon.DisableMe();
		guibSwapTeams.DisableMe();
		guilWeaponSelectAMNotice.DisableMe();
		guilPlayerDetailsTitle.DisableMe();
		guibViewPlayer.DisableMe();
		guibKickPlayer.DisableMe();
		guibMutePlayer.DisableMe();
		mebPrivateMessage.DisableMe();
	}
	*/
}

FString UAAGameMenu_CP_PlayerManagement::GetPlayerWeapon(int32 iPlayerID)
{
	/*
	local int32 iWeaponScan;
	local string sWeaponClass;
	local PlayerReplicationInfo priPlayer;
	priPlayer = FindPRIFromID(iPlayerID);
	if (priPlayer == None)
	{
		Return "No Weapon";
	}
	sWeaponClass = priPlayer.sCurrentWeaponClass;
	for (iWeaponScan = 0; iWeaponScan < asWeaponClassNames.Length; iWeaponScan++)
	{
		if (sWeaponClass ~= asWeaponClassNames[iWeaponScan] || sWeaponClass ~= asWeaponAltClassNames[iWeaponScan])
		{
			Return asWeaponNames[iWeaponScan];
		}
	}
	*/
	return "No Weapon";
}

void UAAGameMenu_CP_PlayerManagement::FindPRIFromID(int32 iPlayerID)
{
	/*
	local GameReplicationInfo GRI;
	local int32 iPlayerIndex;
	GRI = PlayerOwner().GameReplicationInfo;
	if (GRI == None)
	{
		Return None;
	}
	for (iPlayerIndex = 0; iPlayerIndex < GRI.PRIArray.Length; iPlayerIndex++)
	{
		if (GRI.PRIArray[iPlayerIndex] != None && GRI.PRIArray[iPlayerIndex].PlayerID == iPlayerID)
		{
			Return GRI.PRIArray[iPlayerIndex];
		}
	}
	Return None;
	*/
}