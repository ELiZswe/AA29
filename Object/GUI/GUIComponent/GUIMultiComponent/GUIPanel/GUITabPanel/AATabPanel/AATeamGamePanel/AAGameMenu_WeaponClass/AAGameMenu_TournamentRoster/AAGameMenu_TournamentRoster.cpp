// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AATeamGamePanel/AAGameMenu_WeaponClass/AAGameMenu_TournamentRoster/AAGameMenu_TournamentRoster.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIMultiColumnListBox/GUIMultiColumnListBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moCheckBox/moCheckBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moEditBox/moEditBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moComboBox/moComboBox.h"

UAAGameMenu_TournamentRoster::UAAGameMenu_TournamentRoster()
{
	UGUIMultiColumnListBox* UnitBox = NewObject<UGUIMultiColumnListBox>(UGUIMultiColumnListBox::StaticClass());
	UnitBox->DefaultListClass="AGP_Interface.AATournamentUnitGMCList";
	UnitBox->bVisibleWhenEmpty=true;
	//UnitBox->OnCreateComponent=UnitBox.InternalOnCreateComponent;
	UnitBox->StyleName="RosterUnitText";
	UnitBox->WinTop=0.02;
	UnitBox->WinLeft=0.02;
	UnitBox->WinWidth=0.47;
	UnitBox->WinHeight=0.78;
	UnitBox->bBoundToParent=true;
	UnitBox->bScaleToParent=true;
	UGUIButton* TeamRosterLockButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	TeamRosterLockButton->Caption="Lock";
	TeamRosterLockButton->StyleName="SquareMenuButton";
	TeamRosterLockButton->Hint="Click to lock the current roster.";
	TeamRosterLockButton->WinTop=0.82;
	TeamRosterLockButton->WinLeft=0.75;
	TeamRosterLockButton->WinWidth=0.2;
	TeamRosterLockButton->WinHeight=0.053476;
	TeamRosterLockButton->TabOrder=4;
	//TeamRosterLockButton->OnClick=AAGameMenu_TournamentRoster.InternalOnClick;
	//TeamRosterLockButton->OnKeyEvent=TeamRosterLockButton.InternalOnKeyEvent;
	UGUIButton* TeamReadyButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	TeamReadyButton->Caption="Ready";
	TeamReadyButton->StyleName="SquareMenuButton";
	TeamReadyButton->Hint="Click to signal that your team is ready.";
	TeamReadyButton->WinTop=0.82;
	TeamReadyButton->WinLeft=0.52;
	TeamReadyButton->WinWidth=0.2;
	TeamReadyButton->WinHeight=0.053476;
	TeamReadyButton->TabOrder=3;
	//TeamReadyButton->OnClick=AAGameMenu_TournamentRoster.InternalOnClick;
	//TeamReadyButton->OnKeyEvent=TeamReadyButton.InternalOnKeyEvent;
	UmoCheckBox* TeamCaptainCheck = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	TeamCaptainCheck->ComponentJustification = EeTextAlign::TXTA_Left;
	TeamCaptainCheck->CaptionWidth=0.94;
	TeamCaptainCheck->Caption="Team Captain";
	//TeamCaptainCheck->OnCreateComponent=TeamCaptainCheck.InternalOnCreateComponent;
	TeamCaptainCheck->IniOption="@Internal";
	TeamCaptainCheck->IniDefault="False";
	TeamCaptainCheck->Hint="Click to become Team Captain.";
	TeamCaptainCheck->WinTop=0.82;
	TeamCaptainCheck->WinLeft=0.03;
	TeamCaptainCheck->WinWidth=0.2;
	TeamCaptainCheck->WinHeight=0.053476;
	TeamCaptainCheck->TabOrder=2;
	TeamCaptainCheck->bStandardized=false;
	//TeamCaptainCheck->OnChange=AAGameMenu_TournamentRoster.InternalOnChange;
	//TeamCaptainCheck->OnLoadINI=AAGameMenu_TournamentRoster.InternalOnLoadINI;
	UmoEditBox* TeamNameEdit = NewObject<UmoEditBox>(UmoEditBox::StaticClass());
	TeamNameEdit->CaptionWidth=0.3;
	TeamNameEdit->Caption="Team Name";
	//TeamNameEdit->OnCreateComponent=TeamNameEdit.InternalOnCreateComponent;
	TeamNameEdit->IniOption="@Internal";
	TeamNameEdit->Hint="Click here and enter a team name.";
	TeamNameEdit->WinTop=0.03;
	TeamNameEdit->WinLeft=0.52;
	TeamNameEdit->WinWidth=0.45;
	TeamNameEdit->WinHeight=0.053476;
	TeamNameEdit->TabOrder=1;
	TeamNameEdit->bStandardized=false;
	//TeamNameEdit->OnChange=AAGameMenu_TournamentRoster.InternalOnChange;
	//TeamNameEdit->OnLoadINI=AAGameMenu_TournamentRoster.InternalOnLoadINI;
	UmoComboBox* TeamCombo = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	TeamCombo->bReadOnly=true;
	TeamCombo->CaptionWidth=0.24;
	TeamCombo->Caption="Team";
	TeamCombo->LabelFont="AAFontLabel";
	//TeamCombo->OnCreateComponent=TeamCombo.InternalOnCreateComponent;
	TeamCombo->IniOption="@Internal";
	TeamCombo->Hint="Select the team.";
	TeamCombo->WinTop=0.03;
	TeamCombo->WinLeft=0.03;
	TeamCombo->WinWidth=0.45;
	TeamCombo->WinHeight=0.053476;
	TeamCombo->TabOrder=0;
	TeamCombo->bStandardized=false;
	//TeamCombo->OnChange=AAGameMenu_TournamentRoster.InternalOnChangeTeam;
	//TeamCombo->OnLoadINI=AAGameMenu_TournamentRoster.InternalOnLoadTeam;
	UGUIImage* TMBG_Top = NewObject<UGUIImage>(UGUIImage::StaticClass());
	//TMBG_Top->Image=Texture'T_AA2_UI.Menu.field_translucent';
	TMBG_Top->ImageStyle = EImgStyle::ISTY_Stretched;
	TMBG_Top->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	TMBG_Top->WinTop=0.02;
	TMBG_Top->WinLeft=0.02;
	TMBG_Top->WinWidth=0.96;
	TMBG_Top->WinHeight=0.08;
	UGUIImage* TMBG_Bottom = NewObject<UGUIImage>(UGUIImage::StaticClass());
	//TMBG_Bottom->Image=Texture'T_AA2_UI.Menu.field_translucent';
	TMBG_Bottom->ImageStyle = EImgStyle::ISTY_Stretched;
	TMBG_Bottom->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	TMBG_Bottom->WinTop=0.81;
	TMBG_Bottom->WinLeft=0.02;
	TMBG_Bottom->WinWidth=0.96;
	TMBG_Bottom->WinHeight=0.08;
	
	i_TournamentBackgroundTop = TMBG_Top;
	i_TournamentBackgroundBottom = TMBG_Bottom;
	co_Team = TeamCombo;
	ed_TeamName = TeamNameEdit;
	ch_TeamCaptain = TeamCaptainCheck;
	b_TeamReady = TeamReadyButton;
	b_TeamRosterLock = TeamRosterLockButton;
	LockText = "Lock";
	UnlockText = "Unlock";
	ReadyText = "Ready";
	NotReadyText = "Cancel";
	AdminReadyText = "Start Next Round";
	TeamCaptainHint = "Click to become Team Captain";
	NotTeamCaptainHint = "Click to choose not to become Team Captain";
	LockHint = "Click here to stop non-captains from assigning their own weapon class";
	UnlockHint = "Click here to enable non-captains to assign their own weapon class";
	ReadyHint = "Click when Ready to continue the tournament";
	NotReadyHint = "Click to resume class selection";
	AdminReadyHint = "Click to move the tournament to the next round just as if both Team Captains had clicked \"Ready\".";
	lb_Unit = UnitBox;
}

void UAAGameMenu_TournamentRoster::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	int32 i = 0;
	local HumanController HC;
	Super::InitComponent(MyController, MyOwner);
	i_PreferencePanel.WinTop = 0.72;
	i_LoadoutPanel.WinTop = 0.72;
	ch_Medic.WinTop = 0.73;
	cb_Loadout.WinTop = 0.73;
	lb_Unit.WinTop = 0.11;
	lb_Unit.WinHeight = 0.6;
	lb_UnassignedTeam.WinTop = 0.11;
	lb_UnassignedTeam.WinHeight = 0.6;
	HC = HumanController(PlayerOwner());
	for (i = 0; i < 2; i++)
	{
		if (HC != None)
		{
			TeamNameText[i] = HC.GetTeamName(i);
		}
	}
	if (HC.bTournamentServer && PlayerOwner().PlayerReplicationInfo.bAdmin)
	{
		if (co_Team.GetIndex() != -1)
		{
			Team = AGP_TeamInfo(PlayerOwner().GameReplicationInfo.Teams[co_Team.GetIndex()]);
		}
		else
		{
			Team = AGP_TeamInfo(PlayerOwner().GameReplicationInfo.Teams[0]);
		}
	}
	else
	{
		Team = AGP_TeamInfo(PlayerOwner().PlayerReplicationInfo.Team);
	}
	SetTeam(Team);
	if (HC != None)
	{
		ch_Medic.Checked(HC.PlayerReplicationInfo.bWantsMedic);
	}
	*/
}

void UAAGameMenu_TournamentRoster::Refresh()
{
	/*
	local HumanController HC;
	HC = HumanController(PlayerOwner());
	if (HC != None)
	{
		ch_TeamCaptain.SetComponentValue(string(HC.PlayerReplicationInfo.bTournamentTeamCaptain), true);
	}
	RefreshTeamName();
	if ((HC != None) && HC.PlayerReplicationInfo.bAdmin)
	{
		b_TeamReady.Caption = AdminReadyText;
		b_TeamReady.Hint = AdminReadyHint;
	}
	else
	{
		if ((HC != None) && HC.TournamentIsTeamReady(Team.TeamIndex))
		{
			bReady = true;
			b_TeamReady.Caption = NotReadyText;
			b_TeamReady.Hint = NotReadyHint;
		}
		else
		{
			bReady = false;
			b_TeamReady.Caption = ReadyText;
			b_TeamReady.Hint = ReadyHint;
		}
	}
	Super::Refresh();
	*/
}

bool UAAGameMenu_TournamentRoster::MyOnPreDraw(UCanvas* C)
{
	/*
	local HumanController HC;
	local GameReplicationInfo GRI;
	local PlayerReplicationInfo PRI;
	PRI = PlayerOwner().PlayerReplicationInfo;
	HC = HumanController(PlayerOwner());
	GRI = PlayerOwner().GameReplicationInfo;
	Super::MyOnPreDraw(C);
	if ((HC != None) && HC.bTournamentServer)
	{
		if (PlayerOwner().PlayerReplicationInfo.bAdmin)
		{
			co_Team.bVisible = true;
		}
		else
		{
			co_Team.bVisible = false;
		}
		if (PlayerOwner().PlayerReplicationInfo.bAdmin)
		{
			DisableComponent(ch_Medic);
		}
		else
		{
			EnableComponent(ch_Medic);
		}
		if (PlayerOwner().PlayerReplicationInfo.bAdmin || PlayerOwner().PlayerReplicationInfo.bTournamentTeamCaptain)
		{
			ed_TeamName.ReadOnly(false);
			EnableComponent(ed_TeamName);
		}
		else
		{
			ed_TeamName.ReadOnly(true);
			DisableComponent(ed_TeamName);
		}
		if (((!PlayerOwner().PlayerReplicationInfo.bAdmin) && ((HumanController(PlayerOwner()) != None) && HumanController(PlayerOwner()).TournamentAreCaptainsAllowed())) && (PlayerOwner().PlayerReplicationInfo.bTournamentTeamCaptain || ((HumanController(PlayerOwner()) != None) && (!HumanController(PlayerOwner()).TournamentIsTeamCaptainSelected(PlayerOwner().PlayerReplicationInfo.Team.TeamIndex)))))
		{
			EnableComponent(ch_TeamCaptain);
		}
		else
		{
			DisableComponent(ch_TeamCaptain);
		}
		if (((HumanController(PlayerOwner()) != None) && HumanController(PlayerOwner()).TournamentAreCaptainsAllowed()) && PlayerOwner().PlayerReplicationInfo.bTournamentTeamCaptain)
		{
			EnableComponent(b_TeamRosterLock);
		}
		else
		{
			DisableComponent(b_TeamRosterLock);
		}
		if (((PlayerOwner().PlayerReplicationInfo.bAdmin && (PlayerOwner().GameReplicationInfo.sTournamentState != "Live Play")) && (PlayerOwner().GameReplicationInfo.sTournamentState != "Between Rounds")) || (((((HumanController(PlayerOwner()) != None) && HumanController(PlayerOwner()).TournamentAreCaptainsAllowed()) && PlayerOwner().PlayerReplicationInfo.bTournamentTeamCaptain) && (PlayerOwner().GameReplicationInfo.sTournamentState != "Live Play")) && (PlayerOwner().GameReplicationInfo.sTournamentState != "Between Rounds")))
		{
			EnableComponent(b_TeamReady);
		}
		else
		{
			DisableComponent(b_TeamReady);
		}
	}
	*/
	return true;
}

void UAAGameMenu_TournamentRoster::InternalOnLoadINI(UGUIComponent* Sender, FString S)
{
	/*
	if (Sender == co_Team)
	{
		LoadTeams(Sender, S);
	}
	else
	{
		if (Sender == ed_TeamName)
		{
			LoadTeamName();
		}
	}
	*/
}

void UAAGameMenu_TournamentRoster::LoadTeams(UGUIComponent* Sender, FString S)
{
	/*
	local HumanController HC;
	HC = HumanController(PlayerOwner());
	if (Sender == co_Team)
	{
		if (HC != None)
	}
	{
	}
	*/
}

void UAAGameMenu_TournamentRoster::RefreshTeamName()
{
	/*
	local HumanController HC;
	int32 TeamNum = 0;
	HC = HumanController(PlayerOwner());
	if (HC != None)
	{
		if (HC.PlayerReplicationInfo.bAdmin)
		{
			TeamNum = co_Team.GetIndex();
		}
		else
		{
			TeamNum = HC.PlayerReplicationInfo.Team.TeamIndex;
		}
		ed_TeamName.SetComponentValue(HC.GetTeamName(TeamNum), true);
	}
	*/
}

void UAAGameMenu_TournamentRoster::LoadTeamName()
{
	/*
	local HumanController HC;
	int32 TeamNum = 0;
	HC = HumanController(PlayerOwner());
	if (HC != None)
	{
		if (HC.PlayerReplicationInfo.bAdmin)
		{
			TeamNum = co_Team.GetIndex();
		}
		else
		{
			TeamNum = HC.PlayerReplicationInfo.Team.TeamIndex;
		}
		ed_TeamName.SetText(HC.GetTeamName(TeamNum));
	}
	*/
}

void UAAGameMenu_TournamentRoster::InternalOnChange(UGUIComponent* Sender)
{
	/*
	local HumanController HC;
	int32 TeamNum = 0;
	HC = HumanController(PlayerOwner());
	if (Sender == ch_TeamCaptain)
	{
		if ((HC != None) && HC.bTournamentServer)
		{
			if (HC.PlayerReplicationInfo.bTournamentTeamCaptain || (!HC.TournamentIsTeamCaptainSelected(PlayerOwner().PlayerReplicationInfo.Team.TeamIndex)))
			{
				HC.TournamentRequestTeamCaptain(HC.PlayerReplicationInfo);
				if (ch_TeamCaptain.IsChecked())
				{
					ch_TeamCaptain.MyComponent.Hint = NotTeamCaptainHint;
				}
				else
				{
					ch_TeamCaptain.MyComponent.Hint = TeamCaptainHint;
				}
				if (bLocked)
				{
					bLocked = false;
					b_TeamRosterLock.Caption = LockText;
					b_TeamRosterLock.Hint = LockHint;
					HC.TournamentCaptainLockWeaponClasses(bLocked);
				}
				if (bReady)
				{
					bReady = false;
					b_TeamReady.Caption = ReadyText;
					b_TeamReady.Hint = ReadyHint;
					HC.TournamentTeamReady();
				}
			}
		}
	}
	else
	{
		if (Sender == ed_TeamName)
		{
			if ((HC != None) && HC.bTournamentServer)
			{
				if (HC.PlayerReplicationInfo.bAdmin)
				{
					TeamNum = co_Team.GetIndex();
				}
				else
				{
					TeamNum = HC.PlayerReplicationInfo.Team.TeamIndex;
				}
				TeamNum = Team.TeamIndex;
				if (ed_TeamName.GetText() != "")
				{
					TeamNameText[TeamNum] = ed_TeamName.GetText();
					HC.TournamentSetTeamName(TeamNum, ed_TeamName.GetText());
				}
				if (co_Team.bVisible)
				{
					InternalOnLoadTeam(co_Team, "clear");
				}
			}
		}
	}
	Super::InternalOnChange(Sender);
	*/
}

bool UAAGameMenu_TournamentRoster::InternalOnClick(UGUIComponent* Sender)
{
	/*
	local HumanController HC;
	HC = HumanController(PlayerOwner());
	if (Sender == b_TeamReady)
	{
		if ((HC != None) && HC.bTournamentServer)
		{
			if (HC.PlayerReplicationInfo.bTournamentTeamCaptain || HC.PlayerReplicationInfo.bAdmin)
			{
				if (!HC.PlayerReplicationInfo.bAdmin)
				{
					if (b_TeamReady.Caption == ReadyText)
					{
						bReady = true;
						b_TeamReady.Caption = NotReadyText;
						b_TeamReady.Hint = NotReadyHint;
					}
					else
					{
						bReady = false;
						b_TeamReady.Caption = ReadyText;
						b_TeamReady.Hint = ReadyHint;
					}
				}
				HC.TournamentTeamReady();
			}
		}
	}
	else
	{
		if (Sender == b_TeamRosterLock)
		{
			if ((HC != None) && HC.bTournamentServer)
			{
				if (HC.PlayerReplicationInfo.bTournamentTeamCaptain || HC.PlayerReplicationInfo.bAdmin)
				{
					if (b_TeamRosterLock.Caption == LockText)
					{
						bLocked = true;
						b_TeamRosterLock.Caption = UnlockText;
						b_TeamRosterLock.Hint = UnlockHint;
					}
					else
					{
						bLocked = false;
						b_TeamRosterLock.Caption = LockText;
						b_TeamRosterLock.Hint = LockHint;
					}
					HC.TournamentCaptainLockWeaponClasses(bLocked);
				}
			}
		}
	}
	*/
	return true;
}

void UAAGameMenu_TournamentRoster::InternalOnLoadTeam(UGUIComponent* Sender, FString S)
{
	/*
	local HumanController HC;
	int32 i = 0;
	HC = HumanController(PlayerOwner());
	if (Sender == co_Team)
	{
		if ((HC != None) && HC.bTournamentServer)
		{
			if (S ~= "clear")
			{
				co_Team.__OnChange__Delegate = None;
				co_Team.RemoveItem(0, co_Team.ItemCount());
			}
			for (i = 0; i < 2; i++)
			{
				co_Team.addItem(TeamNameText[i]);
			}
			co_Team.SetIndex(Team.TeamIndex);
			if (S ~= "clear")
			{
				co_Team.__OnChange__Delegate = InternalOnChangeTeam;
			}
		}
	}
	*/
}

void UAAGameMenu_TournamentRoster::InternalOnChangeTeam(UGUIComponent* Sender)
{
	/*
	local HumanController HC;
	HC = HumanController(PlayerOwner());
	if (Sender == co_Team)
	{
		if ((HC != None) && HC.bTournamentServer)
		{
			if (co_Team.GetIndex() > -1)
			{
				Team = AGP_TeamInfo(HC.GameReplicationInfo.Teams[co_Team.GetIndex()]);
				if (AAUnassignedTeamList(lb_UnassignedTeam.List) != None)
				{
					AAUnassignedTeamList(lb_UnassignedTeam.List).Team = Team;
				}
				SetTeam(HC.GameReplicationInfo.Teams[co_Team.GetIndex()]);
				TeamNameText[co_Team.GetIndex()] = co_Team.GetText();
				ed_TeamName.SetComponentValue(co_Team.GetText(), true);
			}
		}
	}
	*/
}

bool UAAGameMenu_TournamentRoster::CanShowPanel()
{
	/*
	local HumanController HC;
	HC = HumanController(PlayerOwner());
	if ((HC != None) && HC.bTournamentServer)
	{
		if (PlayerOwner().PlayerReplicationInfo.bAdmin)
		{
			return true;
		}
		if (PlayerOwner().PlayerReplicationInfo.bTournamentTeamCaptain)
		{
			return true;
		}
		return ((PlayerOwner().PlayerReplicationInfo.Team.TeamIndex != 255) || (PlayerOwner().PlayerReplicationInfo.DesiredTeam != 255));
	}
	return (PlayerOwner().PlayerReplicationInfo.Team.TeamIndex != 255);
	*/

	return false;    //FAKE   /ELiZ
}

void UAAGameMenu_TournamentRoster::ShowPanel(bool bShow)
{
	/*
	Super::ShowPanel(bShow);
	if (bShow)
	{
		RefreshComponents();
	}
	Refresh();
	*/
}

void UAAGameMenu_TournamentRoster::RefreshComponents()
{
	/*
	local HumanController HC;
	HC = HumanController(PlayerOwner());
	if ((HC != None) && HC.bTournamentServer)
	{
		if (PlayerOwner().PlayerReplicationInfo.bTournamentTeamCaptain)
		{
			bLocked = HC.TournamentIsTeamRosterLocked(Team.TeamIndex);
			if (!bLocked)
			{
				b_TeamRosterLock.Caption = LockText;
				b_TeamRosterLock.Hint = LockHint;
			}
			else
			{
				b_TeamRosterLock.Caption = UnlockText;
				b_TeamRosterLock.Hint = UnlockHint;
			}
		}
	}
	*/
}

void UAAGameMenu_TournamentRoster::SetTeam(ATeamInfo* TI)
{
	/*
	if (PlayerOwner().PlayerReplicationInfo.bAdmin)
	{
		if (co_Team.GetIndex() == -1)
		{
			TI = PlayerOwner().GameReplicationInfo.Teams[0];
		}
		else
		{
			TI = PlayerOwner().GameReplicationInfo.Teams[co_Team.GetIndex()];
		}
	}
	Super::SetTeam(TI);
	*/
}