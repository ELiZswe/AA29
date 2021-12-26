// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAGamePanel/AAGameMenu_CP_PlayerManagement/AAGameMenu_CP_PlayerManagement.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moEditBox/moEditBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moComboBox/moComboBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIListBox/GUIListBox.h"

UAAGameMenu_CP_PlayerManagement::UAAGameMenu_CP_PlayerManagement()
{
	UGUIButton* MessageButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	MessageButton->Caption = "Send";
	MessageButton->MenuState = EMenuState::MSAT_Disabled;
	MessageButton->StyleName = "SquareMenuButton";
	MessageButton->Hint = "Click here to send this player a private message.";
	MessageButton->WinTop = 0.66;
	MessageButton->WinLeft = 0.92;
	MessageButton->WinWidth = 0.07;
	MessageButton->WinHeight = 0.053476;
	MessageButton->TabOrder = 9;
	//MessageButton->OnClick=AAGameMenu_CP_PlayerManagement.ButtonClick;
	//MessageButton->OnKeyEvent=MessageButton.InternalOnKeyEvent;
	UmoEditBox* PrivateMessageEntryField = NewObject<UmoEditBox>(UmoEditBox::StaticClass());
	PrivateMessageEntryField->CaptionWidth = 0.09;
	PrivateMessageEntryField->Caption = "PM: ";
	//PrivateMessageEntryField->OnCreateComponent=PrivateMessageEntryField.InternalOnCreateComponent;
	PrivateMessageEntryField->IniOption = "@Internal";
	PrivateMessageEntryField->Hint = "Enter a message to send privately to the selected player.";
	PrivateMessageEntryField->WinTop = 0.66;
	PrivateMessageEntryField->WinLeft = 0.5;
	PrivateMessageEntryField->WinWidth = 0.41;
	PrivateMessageEntryField->WinHeight = 0.05;
	PrivateMessageEntryField->TabOrder = 8;
	PrivateMessageEntryField->bStandardized = false;
	//PrivateMessageEntryField->OnChange=AAGameMenu_CP_PlayerManagement.InternalOnChange;
	UGUIButton* ChangeWeaponButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	ChangeWeaponButton->Caption = "Apply";
	ChangeWeaponButton->MenuState = EMenuState::MSAT_Disabled;
	ChangeWeaponButton->StyleName = "SquareMenuButton";
	ChangeWeaponButton->Hint = "Click here to change the player's weapon to the one you have selected.";
	ChangeWeaponButton->WinTop = 0.5;
	ChangeWeaponButton->WinLeft = 0.91;
	ChangeWeaponButton->WinWidth = 0.08;
	ChangeWeaponButton->WinHeight = 0.053476;
	ChangeWeaponButton->TabOrder = 7;
	//ChangeWeaponButton->OnClick=AAGameMenu_CP_PlayerManagement.ButtonClick;
	//ChangeWeaponButton->OnKeyEvent=ChangeWeaponButton.InternalOnKeyEvent;
	UmoComboBox* WeaponSelectionDropDown = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	WeaponSelectionDropDown->bReadOnly = true;
	WeaponSelectionDropDown->CaptionWidth = 0.225;
	WeaponSelectionDropDown->Caption = "Weapon:";
	//WeaponSelectionDropDown->OnCreateComponent=WeaponSelectionDropDown.InternalOnCreateComponent;
	WeaponSelectionDropDown->MenuState = EMenuState::MSAT_Disabled;
	WeaponSelectionDropDown->IniOption = "@Internal";
	WeaponSelectionDropDown->StyleName = "STY_AAComboListBox";
	WeaponSelectionDropDown->Hint = "Select the weapon to assign to the currently selected player.";
	WeaponSelectionDropDown->WinTop = 0.5;
	WeaponSelectionDropDown->WinLeft = 0.5;
	WeaponSelectionDropDown->WinWidth = 0.4;
	WeaponSelectionDropDown->WinHeight = 0.05;
	WeaponSelectionDropDown->TabOrder = 6;
	WeaponSelectionDropDown->bStandardized = false;
	//WeaponSelectionDropDown->OnChange=AAGameMenu_CP_PlayerManagement.InternalOnChange;
	UGUIButton* SwapTeamButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	SwapTeamButton->Caption = "Change Team";
	SwapTeamButton->MenuState = EMenuState::MSAT_Disabled;
	SwapTeamButton->StyleName = "SquareMenuButton";
	SwapTeamButton->Hint = "Click here to move this player to the other team.";
	SwapTeamButton->WinTop = 0.312875;
	SwapTeamButton->WinLeft = 0.815003;
	SwapTeamButton->WinWidth = 0.15;
	SwapTeamButton->WinHeight = 0.053476;
	SwapTeamButton->TabOrder = 5;
	//SwapTeamButton->OnClick=AAGameMenu_CP_PlayerManagement.ButtonClick;
	//SwapTeamButton->OnKeyEvent=SwapTeamButton.InternalOnKeyEvent;
	UGUIListBox* SpectatorsListBox = NewObject<UGUIListBox>(UGUIListBox::StaticClass());
	SpectatorsListBox->bVisibleWhenEmpty = true;
	SpectatorsListBox->bSorted = true;
	//SpectatorsListBox->OnCreateComponent=SpectatorsListBox.InternalOnCreateComponent;
	SpectatorsListBox->StyleName = "ServerBrowserGrid";
	SpectatorsListBox->WinTop = 0.8;
	SpectatorsListBox->WinLeft = 0.5;
	SpectatorsListBox->WinWidth = 0.4;
	SpectatorsListBox->WinHeight = 0.1;
	SpectatorsListBox->bAcceptsInput = false;
	SpectatorsListBox->bNeverFocus = true;
	UGUIButton* KickButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	KickButton->Caption = "Kick";
	KickButton->MenuState = EMenuState::MSAT_Disabled;
	KickButton->StyleName = "SquareMenuButton";
	KickButton->Hint = "Click here to kick this player from the server.";
	KickButton->WinTop = 0.847;
	KickButton->WinLeft = 0.35;
	KickButton->WinWidth = 0.1;
	KickButton->WinHeight = 0.053476;
	KickButton->TabOrder = 4;
	//KickButton->OnClick=AAGameMenu_CP_PlayerManagement.ButtonClick;
	//KickButton->OnKeyEvent=KickButton.InternalOnKeyEvent;
	UGUIButton* ViewButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	ViewButton->Caption = "View";
	ViewButton->MenuState = EMenuState::MSAT_Disabled;
	ViewButton->StyleName = "SquareMenuButton";
	ViewButton->Hint = "Click here to change view to this player.";
	ViewButton->WinTop = 0.847;
	ViewButton->WinLeft = 0.2;
	ViewButton->WinWidth = 0.1;
	ViewButton->WinHeight = 0.053476;
	ViewButton->TabOrder = 3;
	//ViewButton->OnClick=AAGameMenu_CP_PlayerManagement.ButtonClick;
	//ViewButton->OnKeyEvent=ViewButton.InternalOnKeyEvent;
	UGUIButton* MuteButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	MuteButton->Caption = "Mute";
	MuteButton->MenuState = EMenuState::MSAT_Disabled;
	MuteButton->StyleName = "SquareMenuButton";
	MuteButton->Hint = "Click here to toggle muting this player.";
	MuteButton->WinTop = 0.847;
	MuteButton->WinLeft = 0.05;
	MuteButton->WinWidth = 0.1;
	MuteButton->WinHeight = 0.053476;
	MuteButton->TabOrder = 2;
	//MuteButton->OnClick=AAGameMenu_CP_PlayerManagement.ButtonClick;
	//MuteButton->OnKeyEvent=MuteButton.InternalOnKeyEvent;
	UGUIListBox* PlayersListBox = NewObject<UGUIListBox>(UGUIListBox::StaticClass());
	PlayersListBox->bVisibleWhenEmpty = true;
	PlayersListBox->bSorted = true;
	//PlayersListBox->OnCreateComponent=PlayersListBox.InternalOnCreateComponent;
	PlayersListBox->StyleName = "ServerBrowserGrid";
	PlayersListBox->Hint = "Left click on a player to manage that player.";
	PlayersListBox->WinTop = 0.2;
	PlayersListBox->WinLeft = 0.05;
	PlayersListBox->WinWidth = 0.4;
	PlayersListBox->WinHeight = 0.63;
	PlayersListBox->TabOrder = 1;
	PlayersListBox->bAcceptsInput = false;
	PlayersListBox->bNeverFocus = true;
	//PlayersListBox->OnClick=AAGameMenu_CP_PlayerManagement.OnPlayerListClick;
	//PlayersListBox->OnChange=AAGameMenu_CP_PlayerManagement.InternalOnChange;
	UGUILabel* InstructionsLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	InstructionsLabel->TextColor = FColor(255, 255, 255, 255);
	InstructionsLabel->bMultiLine = true;
	InstructionsLabel->StyleName = "TextLabel";
	InstructionsLabel->WinTop = 0.07;
	InstructionsLabel->WinLeft = 0.05;
	InstructionsLabel->WinWidth = 0.9;
	InstructionsLabel->WinHeight = 0.1;
	UGUILabel* PlayersListTitle = NewObject<UGUILabel>(UGUILabel::StaticClass());
	PlayersListTitle->Caption = "Active Players";
	PlayersListTitle->TextAlign = ETextAlign::TXTA_Center;
	PlayersListTitle->TextColor = FColor(255, 255, 255, 255);
	PlayersListTitle->StyleName = "TextLabel";
	PlayersListTitle->WinTop = 0.15;
	PlayersListTitle->WinLeft = 0.05;
	PlayersListTitle->WinWidth = 0.4;
	PlayersListTitle->WinHeight = 0.05;
	UGUILabel* SpectatorsListTitle = NewObject<UGUILabel>(UGUILabel::StaticClass());
	SpectatorsListTitle->Caption = "Spectators";
	SpectatorsListTitle->TextAlign = ETextAlign::TXTA_Center;
	SpectatorsListTitle->TextColor = FColor(255, 255, 255, 255);
	SpectatorsListTitle->StyleName = "TextLabel";
	SpectatorsListTitle->WinTop = 0.75;
	SpectatorsListTitle->WinLeft = 0.5;
	SpectatorsListTitle->WinWidth = 0.4;
	SpectatorsListTitle->WinHeight = 0.05;
	UGUILabel* PlayerDetailsTitle = NewObject<UGUILabel>(UGUILabel::StaticClass());
	PlayerDetailsTitle->Caption = "Player Details";
	PlayerDetailsTitle->TextAlign = ETextAlign::TXTA_Center;
	PlayerDetailsTitle->TextColor = FColor(255, 255, 255, 255);
	PlayerDetailsTitle->StyleName = "TextLabel";
	PlayerDetailsTitle->WinTop = 0.2;
	PlayerDetailsTitle->WinLeft = 0.5;
	PlayerDetailsTitle->WinWidth = 0.5;
	PlayerDetailsTitle->WinHeight = 0.05;
	UGUILabel* PlayerDetailsName = NewObject<UGUILabel>(UGUILabel::StaticClass());
	PlayerDetailsName->Caption = "Name: ";
	PlayerDetailsName->TextColor = FColor(255, 255, 255, 255);
	PlayerDetailsName->StyleName = "TextLabel";
	PlayerDetailsName->WinTop = 0.26;
	PlayerDetailsName->WinLeft = 0.5;
	PlayerDetailsName->WinWidth = 0.5;
	PlayerDetailsName->WinHeight = 0.05;
	UGUILabel* PlayerDetailsTeam = NewObject<UGUILabel>(UGUILabel::StaticClass());
	PlayerDetailsTeam->Caption = "Team: ";
	PlayerDetailsTeam->TextColor = FColor(255, 255, 255, 255);
	PlayerDetailsTeam->StyleName = "TextLabel";
	PlayerDetailsTeam->WinTop = 0.32;
	PlayerDetailsTeam->WinLeft = 0.5;
	PlayerDetailsTeam->WinWidth = 0.5;
	PlayerDetailsTeam->WinHeight = 0.05;
	UGUILabel* PlayerDetailsScore = NewObject<UGUILabel>(UGUILabel::StaticClass());
	PlayerDetailsScore->Caption = "Scoring: ";
	PlayerDetailsScore->TextColor = FColor(255, 255, 255, 255);
	PlayerDetailsScore->StyleName = "TextLabel";
	PlayerDetailsScore->WinTop = 0.38;
	PlayerDetailsScore->WinLeft = 0.5;
	PlayerDetailsScore->WinWidth = 0.5;
	PlayerDetailsScore->WinHeight = 0.05;
	UGUILabel* PlayerDetailsLocation = NewObject<UGUILabel>(UGUILabel::StaticClass());
	PlayerDetailsLocation->Caption = "Location: ";
	PlayerDetailsLocation->TextColor = FColor(255, 255, 255, 255);
	PlayerDetailsLocation->StyleName = "TextLabel";
	PlayerDetailsLocation->WinTop = 0.44;
	PlayerDetailsLocation->WinLeft = 0.5;
	PlayerDetailsLocation->WinWidth = 0.5;
	PlayerDetailsLocation->WinHeight = 0.05;
	UGUILabel* WeaponSelectAMNotice = NewObject<UGUILabel>(UGUILabel::StaticClass());
	WeaponSelectAMNotice->Caption = "* Weapon Requires Advanced Marksmanship Training";
	WeaponSelectAMNotice->TextAlign = ETextAlign::TXTA_Center;
	WeaponSelectAMNotice->TextColor = FColor(200, 200, 200, 255);
	WeaponSelectAMNotice->TextFont = "AAFontSmall";
	WeaponSelectAMNotice->WinTop = 0.56;
	WeaponSelectAMNotice->WinLeft = 0.5;
	WeaponSelectAMNotice->WinWidth = 0.5;
	WeaponSelectAMNotice->WinHeight = 0.05;
	guilInstructions = InstructionsLabel;
	guilPlayerListTitle = PlayersListTitle;
	guilbPlayersList = PlayersListBox;
	guilSpectatorListTitle = SpectatorsListTitle;
	guilbSpectatorList = SpectatorsListBox;
	mcbWeaponSelections = WeaponSelectionDropDown;
	guilWeaponSelectAMNotice = WeaponSelectAMNotice;
	guibViewPlayer = ViewButton;
	guibKickPlayer = KickButton;
	guibMutePlayer = MuteButton;
	mebPrivateMessage = PrivateMessageEntryField;
	guibMessagePlayer = MessageButton;
	guibChangeWeapon = ChangeWeaponButton;
	guilPlayerDetailsTitle = PlayerDetailsTitle;
	guilPlayerDetailsName = PlayerDetailsName;
	guilPlayerDetailsScore = PlayerDetailsScore;
	guilPlayerDetailsTeam = PlayerDetailsTeam;
	guilPlayerDetailsLocation = PlayerDetailsLocation;
	guibSwapTeams = SwapTeamButton;

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
		return StrCmp(ElemA.Item, ElemB.Item, , False);
	}
	else
	{
		return StrCmp(Right(ElemA.Item, 2), Right(ElemB.Item, 2), , False);
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
	if (priPlayer == nullptr)
	{
		return "No Weapon";
	}
	sWeaponClass = priPlayer.sCurrentWeaponClass;
	for (iWeaponScan = 0; iWeaponScan < asWeaponClassNames.Length; iWeaponScan++)
	{
		if (sWeaponClass ~= asWeaponClassNames[iWeaponScan] || sWeaponClass ~= asWeaponAltClassNames[iWeaponScan])
		{
			return asWeaponNames[iWeaponScan];
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
	if (GRI == nullptr)
	{
		return None;
	}
	for (iPlayerIndex = 0; iPlayerIndex < GRI.PRIArray.Length; iPlayerIndex++)
	{
		if (GRI.PRIArray[iPlayerIndex] != None && GRI.PRIArray[iPlayerIndex].PlayerID == iPlayerID)
		{
			return GRI.PRIArray[iPlayerIndex];
		}
	}
	return None;
	*/
}