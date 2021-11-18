// All the original content belonged to the US Army

#include "AA29/Object/UIBase/UIFrame/GameMenuFrame/GameMenuFrame.h"
#include "AA29/Object/UIBase/UIScreen/UIScreen.h"

UGameMenuFrame::UGameMenuFrame()
{
	prev_SelectedClass = -1;
	_iSettingsPage = -1;
	_bToolTipActive = false;
	//_Pos = FPosition(0, 0, 1280, 1024);
	_bAllowScaling = false;

}

void UGameMenuFrame::Notify(int32 pUIEvent)
{
	/*
	local Screenplay SP;
	if (cHUD != None && cHUD.IsA('AGP_HUD'))
	{
		if (pUIEvent == 1)
		{
			SetActiveScreen(0);
			return;
		}
		if (pUIEvent == 4)
		{
			RefreshClassSelect();
			SetActiveScreen(3);
			return;
		}
		if (pUIEvent == 2)
		{
			SetActiveScreen(1);
			return;
		}
		if (pUIEvent == 20)
		{
			SelectTeam(0);
			SetActiveScreen(2);
			return;
		}
		if (pUIEvent == 21)
		{
			SelectTeam(1);
			SetActiveScreen(2);
			return;
		}
		if (pUIEvent == 23)
		{
			DoSpectateTeam(0);
			ResetActiveScreen();
			AGP_HUD(cHUD).CloseGameMenu();
			return;
		}
		if (pUIEvent == 24)
		{
			DoSpectateTeam(1);
			ResetActiveScreen();
			AGP_HUD(cHUD).CloseGameMenu();
			return;
		}
		if (pUIEvent == 22)
		{
			DoSelectTeam();
			ResetActiveScreen();
			AGP_HUD(cHUD).CloseGameMenu();
			return;
		}
		if (pUIEvent == 3)
		{
			SetActiveScreen(2);
			return;
		}
		if (pUIEvent == 5)
		{
			ResetActiveScreen();
			AGP_HUD(cHUD).CloseGameMenu();
			return;
		}
		if (pUIEvent == 18)
		{
			DoSelectClass();
			ResetActiveScreen();
			AGP_HUD(cHUD).CloseGameMenu();
			return;
		}
		if (pUIEvent == 10)
		{
			SelectClass(10);
			return;
		}
		if (pUIEvent == 11)
		{
			SelectClass(11);
			return;
		}
		if (pUIEvent == 12)
		{
			SelectClass(12);
			return;
		}
		if (pUIEvent == 13)
		{
			SelectClass(13);
			return;
		}
		if (pUIEvent == 14)
		{
			SelectClass(14);
			return;
		}
		if (pUIEvent == 17)
		{
			SelectClass(17);
			return;
		}
		if (pUIEvent == 15)
		{
			SelectClass(15);
			return;
		}
		if (pUIEvent == 16)
		{
			SelectClass(16);
			return;
		}
		if (pUIEvent == 30)
		{
			CancelLogin();
			return;
		}
		if (pUIEvent == 31)
		{
			SelectLogin();
			return;
		}
		if (pUIEvent == 60)
		{
			ResetActiveScreen();
			AGP_HUD(cHUD).CloseGameMenu();
			AGP_HUD(cHUD).PlayerOwner.ConsoleCommand("start entry");
			return;
		}
		if (pUIEvent == 61)
		{
			ResetActiveScreen();
			AGP_HUD(cHUD).CloseGameMenu();
			SP = cHUD.Level.Game.GetScreenplay();
			if (SP != nullptr)
			{
				SP.SceneJump(nReplayScene);
			}
			else
			{
				AGP_HUD(cHUD).PlayerOwner.ConsoleCommand("reconnect");
			}
			return;
		}
		if (pUIEvent == 42)
		{
			if (cHUD.Level.DidPlayerCompleteNewMission(cHUD.PlayerOwner) == 1)
			{
				SetActiveScreen(4);
			}
			else
			{
				HumanController(AGP_HUD(cHUD).PlayerOwner).VerifyJacket();
				HumanController(AGP_HUD(cHUD).PlayerOwner).SaveJacket();
				ResetActiveScreen();
				AGP_HUD(cHUD).CloseGameMenu();
				AGP_HUD(cHUD).PlayerOwner.ConsoleCommand("start entry2");
				return;
			}
			return;
		}
		if (pUIEvent == 43)
		{
			HumanController(AGP_HUD(cHUD).PlayerOwner).VerifyJacket();
			HumanController(AGP_HUD(cHUD).PlayerOwner).SaveJacket();
			ResetActiveScreen();
			AGP_HUD(cHUD).CloseGameMenu();
			AGP_HUD(cHUD).PlayerOwner.ConsoleCommand("start entry2");
			return;
		}
		if (pUIEvent == 50)
		{
			UpdateServerSetting();
			return;
		}
		if (pUIEvent == 52)
		{
			BanPlayer();
			return;
		}
		if (pUIEvent == 51)
		{
			KickPlayer();
			return;
		}
		if (pUIEvent == 53)
		{
			PlayerList(-1);
			return;
		}
		if (pUIEvent == 54)
		{
			PlayerList(1);
			return;
		}
		if (pUIEvent == 55)
		{
			SettingList(-1);
			return;
		}
		if (pUIEvent == 56)
		{
			SettingList(1);
			return;
		}
		if (pUIEvent == 62)
		{
			ResetActiveScreen();
			AGP_HUD(cHUD).CloseGameMenu();
			AGP_HUD(cHUD).PlayerOwner.ConsoleCommand("start entry");
			return;
		}
	}
	*/
}
void UGameMenuFrame::SetActiveScreen(int32 screen_id)
{
	/*
	Super::SetActiveScreen(screen_id);
	if (screen_id == 7 && !_bSettingsListSet)
	{
		HumanController(AGP_HUD(cHUD).PlayerOwner).QueryServerList();
		_bSettingsListSet = true;
	}
	*/
}
void UGameMenuFrame::SelectClass(int32 control_id)
{
	/*
	local AGP_UI.UIScreen screen;
	local AGP_UI.UIClassButton Control;
	screen = GetScreen(3);
	if (_iSelectedClass != 0)
	{
		Control = UIClassButton(screen.GetControl(_iSelectedClass));
		Control.SetSelected(False);
	}
	_iSelectedClass = control_id;
	Control = UIClassButton(screen.GetControl(_iSelectedClass));
	Control.SetSelected(True);
	*/
}
void UGameMenuFrame::DoSelectClass()
{
	/*
	local AGP_UI.UIScreen screen;
	local AGP_UI.UIClassButton Control;
	local bool bLeader;
	local bool bMedic;
	screen = GetScreen(3);
	Control = UIClassButton(screen.GetControl(_iSelectedClass));
	if (Control.GetClassIndex() == 5 || Control.GetClassIndex() == 6)
	{
		UICheckboxB(screen.GetControl(18)).Select(False);
	}
	bLeader = UICheckboxB(screen.GetControl(18)).IsSelected();
	bMedic = UICheckboxB(screen.GetControl(19)).IsSelected();
	if (Control != nullptr)
	{
		HumanController(AGP_HUD(cHUD).PlayerOwner).SetPreferredClass(Control.GetClassIndex(), bLeader, bMedic, prev_SelectedClass, prev_AvoidLeader);
	}
	prev_AvoidLeader = bLeader;
	prev_SelectedClass = Control.GetClassIndex();
	*/
}
void UGameMenuFrame::RefreshClassSelect()
{
	/*
	local TeamInfo TeamInfo;
	local int32 iNumClasses;
	local int32 iCurIndex;
	local bool bAvail;
	local bool bQual;
	local byte yAltClass;
	local FString Label;
	local class<Actor>  aClass;
	TeamInfo = AGP_HUD(cHUD).PlayerOwner.PlayerReplicationInfo.Team;
	if (TeamInfo != nullptr)
	{
		iNumClasses = TeamInfo.GetNumClasses();
		for (iCurIndex = 0; iCurIndex < iNumClasses; iCurIndex++)
		{
			if (GetNoSniper())
			{
				if (iCurIndex == 2 || iCurIndex == 3)
				{
					bAvail = False;
				}
				else
				{
					bAvail = TeamInfo.IsClassAvailable(iCurIndex);
				}
			}
			else
			{
				bAvail = TeamInfo.IsClassAvailable(iCurIndex);
			}
			aClass = class<Actor>(TeamInfo.GetClass(iCurIndex));
			bQual = AGP_HUD(cHUD).PlayerOwner.QualifiedFor(aClass);
			yAltClass = TeamInfo.UseAltClass(iCurIndex);
			Label = TeamInfo.GetClassDisplayName(iCurIndex);
			EnableClassSelect(bAvail, bQual, yAltClass, Label, 10 + iCurIndex);
		}
		EnableLeaderPreference(TeamInfo.GetNumLeadersDesired(), TeamInfo.GetNumLeadersAvailable());
		EnableMedicPreference(TeamInfo.GetNumMedicsDesired(), TeamInfo.GetNumMedicsAvailable());
	}
	*/
}
void UGameMenuFrame::EnableMedicPreference(int32 ndesired, int32 navail)
{
	/*
	local AGP_UI.UIScreen screen;
	local AGP_UI.UICheckboxB cbox;
	screen = GetScreen(3);
	cbox = UICheckboxB(screen.GetControl(19));
	cbox.SetLabel("REQUEST MEDIC [" $ ndesired $ "/" $ navail $ "]");
	*/
}
void UGameMenuFrame::EnableLeaderPreference(int32 ndesired, int32 navail)
{
	/*
	local AGP_UI.UIScreen screen;
	local AGP_UI.UICheckboxB cbox;
	screen = GetScreen(3);
	cbox = UICheckboxB(screen.GetControl(18));
	cbox.SetLabel("AVOID LEADER ROLES [" $ ndesired $ "/" $ navail $ "]");
	*/
}
void UGameMenuFrame::EnableClassSelect(bool bState, bool bQual, uint8 yalt, FString Label, int32 control_id)
{
	/*
	local AGP_UI.UIScreen screen;
	local AGP_UI.UIClassButton Control;
	screen = GetScreen(3);
	Control = UIClassButton(screen.GetControl(control_id));
	Control.SetEnabled(bState);
	Control.SetQualified(bQual);
	Control.SetUseAltClass(yalt);
	Control.SetLabel(Label);
	*/
}
void UGameMenuFrame::SelectTeam(int32 Team)
{
	/*
	local AGP_UI.UIScreen screen;
	local AGP_UI.UITextPageDisplay Control;
	local AGP_UI.UITextPageDisplay control2;
	screen = GetScreen(1);
	Control = UITextPageDisplay(screen.GetControl(22 + Team));
	screen = GetScreen(2);
	control2 = UITextPageDisplay(screen.GetControl(21));
	_iSelectedTeam = Team;
	UITextDisplay(GetScreen(2).GetControl(20)).SetLabel(_sTeam[_iSelectedTeam]);
	control2.SetStringList(Control.GetStringList());
	*/
}
void UGameMenuFrame::DoSelectTeam()
{
	//HumanController(AGP_HUD(cHUD).PlayerOwner).SetTeam(_iSelectedTeam);
}
void UGameMenuFrame::DoSpectateTeam(int32 Team)
{
}
void UGameMenuFrame::CheckFullScreen()
{
	/*
	if (AGP_HUD(cHUD).PlayerOwner.Player.bFullScreen)
	{
		AGP_HUD(cHUD).PlayerOwner.ConsoleCommand("togglefullscreen");
	}
	*/
}
void UGameMenuFrame::Draw(UCanvas* Canvas)
{
	/*
	if (GetActiveScreen() == nullptr)
	{
		SetActiveScreen(0);
	}
	Draw(Canvas);
	*/
}
void UGameMenuFrame::Create(AHUD* pHUD)
{
	/*
	local UIBase.Point pt;
	local FString Temp;
	Create(pHUD);
	Temp = GetBaseDir();
	_sBriefingsDir = Left(Temp, Len(Temp) - 7);
	_sBriefingsDir = _sBriefingsDir $ "briefings\";
		InitTextureDimensions();
	pt.X = 260;
	pt.Y = 500;
	SetToolTipLocation(pt);
	CreateScreens();
	CreateMainMenuScreen();
	CreateClassSelectScreen();
	CreateTeamSelectScreen();
	CreateTeamBriefScreen();
	CreateLoginScreen();
	CreateMissionSuccessScreen();
	CreateMissionFailureScreen();
	CreateServerAdminScreen();
	CreateLandNavScoreScreen();
	SelectClass(10);
	AddMouse("AGP_UI.UIMouse", 0, 0, 32, 32, "T_AA2_UI.menu.hud_menu_pointer");
	*/
}
void UGameMenuFrame::InitTextureDimensions()
{
	dCheckBox.X = 184;
	dCheckBox.Y = 103;
	dCheckBox.W = 12;
	dCheckBox.H = 12;
	dCancelButton.X = 240;
	dCancelButton.Y = 68;
	dCancelButton.W = 68;
	dCancelButton.H = 20;
	dSelectButton.X = 240;
	dSelectButton.Y = 0;
	dSelectButton.W = 68;
	dSelectButton.H = 20;
	dMenuButton.X = 320;
	dMenuButton.Y = 0;
	dMenuButton.W = 68;
	dMenuButton.H = 20;
	dReplayButton.X = 320;
	dReplayButton.Y = 68;
	dReplayButton.W = 68;
	dReplayButton.H = 20;
	dContinueButton.X = 400;
	dContinueButton.Y = 0;
	dContinueButton.W = 68;
	dContinueButton.H = 20;
	dLogInButton.X = 400;
	dLogInButton.Y = 68;
	dLogInButton.W = 68;
	dLogInButton.H = 20;
	dMoreButton.X = 240;
	dMoreButton.Y = 136;
	dMoreButton.W = 68;
	dMoreButton.H = 20;
	dBackButton.X = 444;
	dBackButton.Y = 196;
	dBackButton.W = 68;
	dBackButton.H = 20;
	dNextButton.X = 444;
	dNextButton.Y = 128;
	dNextButton.W = 68;
	dNextButton.H = 20;
}
void UGameMenuFrame::CreateScreens()
{
	AddScreen(0, "");
	AddScreen(3, "");
	AddScreen(1, "");
	AddScreen(2, "");
	AddScreen(4, "");
	AddScreen(5, "");
	AddScreen(6, "");
	AddScreen(7, "");
	AddScreen(8, "");
}
void UGameMenuFrame::CreateMainMenuScreen()
{
	/*
	UUIScreen* screen;
	FPosition pos;
	//screen = GetScreen(0);
	pos.X = 200;
	pos.Y = 82;
	pos.W = 112;
	pos.H = 20;
	screen->AddUITextButton(0, 2, pos, "Team Select", 1, "");
	pos.X = 200;
	pos.Y = 126;
	pos.W = 160;
	pos.H = 20;
	screen->AddUITextButton(0, 3, pos, "Team Brief", 1, "");
	pos.X = 200;
	pos.Y = 174;
	pos.W = 116;
	pos.H = 20;
	screen->AddUITextButton(0, 4, pos, "Class Select", 1, "");
	pos.X = 200;
	pos.Y = 222;
	pos.W = 116;
	pos.H = 20;
	screen->AddUITextButton(0, 5, pos, "Exit Menu", 1, "");
	*/
}
void UGameMenuFrame::CreateClassSelectScreen()
{
	/*
	UUIScreen* screen;
	FPosition pos;
	FPosition dim;
	//screen = GetScreen(3);
	pos.Y = 16;
	dim.X = 0;
	dim.Y = 0;
	dim.W = 16;
	dim.H = 16;
	pos.X = 64;
	pos.W = 16;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 16;
	dim.Y = 0;
	dim.W = 16;
	dim.H = 16;
	pos.X = 80;
	pos.W = 480;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 32;
	dim.Y = 0;
	dim.W = 16;
	dim.H = 16;
	pos.X = 560;
	pos.W = 16;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	pos.Y += 16;
	dim.X = 0;
	dim.Y = 16;
	dim.W = 16;
	dim.H = 16;
	pos.X = 64;
	pos.W = 16;
	pos.H = 416;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 16;
	dim.Y = 16;
	dim.W = 16;
	dim.H = 16;
	pos.X = 80;
	pos.W = 480;
	pos.H = 416;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 32;
	dim.Y = 16;
	dim.W = 16;
	dim.H = 16;
	pos.X = 560;
	pos.W = 16;
	pos.H = 416;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 0;
	dim.Y = 32;
	dim.W = 16;
	dim.H = 16;
	pos.X = 64;
	pos.Y = 448;
	pos.W = 16;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 16;
	dim.Y = 32;
	dim.W = 16;
	dim.H = 16;
	pos.X = 80;
	pos.Y = 448;
	pos.W = 480;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 32;
	dim.Y = 32;
	dim.W = 16;
	dim.H = 16;
	pos.X = 560;
	pos.Y = 448;
	pos.W = 16;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 48;
	dim.Y = 0;
	dim.W = 188;
	dim.H = 16;
	pos.X = 227;
	pos.Y = 24;
	pos.W = 188;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 0;
	dim.Y = 0;
	dim.W = 224;
	dim.H = 64;
	pos.X = 80;
	pos.Y = 64;
	pos.W = 224;
	pos.H = 64;
	screen->AddUIClassButton(15, 15, pos, dim, 5, "T_AA2_UI.menu.ui_gm_rifleman", "T_AA2_UI.menu.ui_gm_m4a1", "T_AA2_UI.menu.ui_gm_m4a1_mod", "T_AA2_UI.menu.ui_gm_automaticrifleman", "T_AA2_UI.menu.ui_gm_overlay_ssg");
	pos.X = 336;
	screen->AddUIClassButton(16, 16, pos, dim, 6, "T_AA2_UI.menu.ui_gm_rifleman", "T_AA2_UI.menu.ui_gm_m4a1", "T_AA2_UI.menu.ui_gm_m4a1_mod", "T_AA2_UI.menu.ui_gm_automaticrifleman", "T_AA2_UI.menu.ui_gm_overlay_sgt");
	pos.X = 80;
	pos.Y += 96;
	screen->AddUIClassButton(10, 10, pos, dim, 0, "T_AA2_UI.menu.ui_gm_rifleman", "T_AA2_UI.menu.ui_gm_m4a1", "T_AA2_UI.menu.ui_gm_m4a1_mod");
	pos.X = 336;
	screen->AddUIClassButton(11, 11, pos, dim, 1, "T_AA2_UI.menu.ui_gm_grenadier");
	pos.Y += 96;
	pos.X = 80;
	screen->AddUIClassButton(12, 12, pos, dim, 2, "T_AA2_UI.menu.ui_gm_sniper82");
	pos.X = 336;
	screen->AddUIClassButton(13, 13, pos, dim, 3, "T_AA2_UI.menu.ui_gm_sniper24");
	pos.Y += 96;
	pos.X = 80;
	screen->AddUIClassButton(14, 14, pos, dim, 4, "T_AA2_UI.menu.ui_gm_automaticrifleman");
	pos.X = 336;
	screen->AddUIClassButton(17, 17, pos, dim, -1, "T_AA2_UI.menu.ui_gm_random");
	pos.Y += 78;
	pos.X = 192;
	pos.W = 200;
	pos.H = 20;
	screen->AddUICheckBoxB(18, 0, pos, dCheckBox, "T_AA2_UI.menu.hud_menu_elements", "AVOID LEADER ROLES", 0, "", 0, "", "");
	pos.X = 80;
	pos.W = 68;
	pos.H = 20;
	screen->AddRolloverBitmapButton(0, 5, pos, "T_AA2_UI.menu.hud_menu_elements3", dCancelButton, 0, "");
	pos.X = 496;
	screen->AddRolloverBitmapButton(0, 18, pos, "T_AA2_UI.menu.hud_menu_elements3", dSelectButton, 0, "");
	pos.Y += 40;
	pos.X = 192;
	pos.W = 200;
	pos.H = 20;
	screen->AddUICheckBoxB(19, 0, pos, dCheckBox, "T_AA2_UI.menu.hud_menu_elements", "REQUEST MEDIC", 0, "", 0, "", "");
	*/
}
void UGameMenuFrame::CreateTeamSelectScreen()
{
	/*
	local AGP_UI.UIControl Control;
	local AGP_UI.UIScreen screen;
	local UIBase.Position pos;
	local UIBase.Position dim;
	local FString string0;
	local FString string1;
	local FString string2;
	local int32 pos0;
	local int32 pos1;
	local int32 pos2;
	screen = GetScreen(1);
	_sTeam[0] = cHUD.Level.TeamName[0];
	_sTeam[1] = cHUD.Level.TeamName[1];
	dim.X = 0;
	dim.Y = 0;
	dim.W = 16;
	dim.H = 16;
	pos.X = 40;
	pos.Y = 88;
	pos.W = 16;
	pos.H = 16;
	screen.AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 16;
	dim.Y = 0;
	dim.W = 16;
	dim.H = 16;
	pos.X = 56;
	pos.Y = 88;
	pos.W = 528;
	pos.H = 16;
	screen.AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 32;
	dim.Y = 0;
	dim.W = 16;
	dim.H = 16;
	pos.X = 584;
	pos.Y = 88;
	pos.W = 16;
	pos.H = 16;
	screen.AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 0;
	dim.Y = 16;
	dim.W = 16;
	dim.H = 16;
	pos.X = 40;
	pos.Y = 104;
	pos.W = 16;
	pos.H = 80;
	screen.AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 16;
	dim.Y = 16;
	dim.W = 16;
	dim.H = 16;
	pos.X = 56;
	pos.Y = 104;
	pos.W = 528;
	pos.H = 80;
	screen.AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 32;
	dim.Y = 16;
	dim.W = 16;
	dim.H = 16;
	pos.X = 584;
	pos.Y = 104;
	pos.W = 16;
	pos.H = 80;
	screen.AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 0;
	dim.Y = 32;
	dim.W = 16;
	dim.H = 16;
	pos.X = 40;
	pos.Y = 184;
	pos.W = 16;
	pos.H = 16;
	screen.AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 16;
	dim.Y = 32;
	dim.W = 16;
	dim.H = 16;
	pos.X = 56;
	pos.Y = 184;
	pos.W = 528;
	pos.H = 16;
	screen.AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 32;
	dim.Y = 32;
	dim.W = 16;
	dim.H = 16;
	pos.X = 584;
	pos.Y = 184;
	pos.W = 16;
	pos.H = 16;
	screen.AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	pos.X = 128;
	pos.Y = 100;
	pos.W = 384;
	pos.H = 16;
	screen.AddUITextDisplay(0, 0, pos, _sTeam[0], 0, "", 1, 0);
	pos.X = 52;
	pos.Y = 120;
	pos.W = 400;
	pos.H = 170;
	screen.AddUITextPageDisplay(22, pos, 0, 6, False);
	pos.X = 512;
	pos.Y = 208;
	pos.W = 68;
	pos.H = 20;
	screen.AddRolloverBitmapButton(0, 20, pos, "T_AA2_UI.menu.hud_menu_elements3", dMoreButton, 0, "");
	dim.X = 0;
	dim.Y = 0;
	dim.W = 16;
	dim.H = 16;
	pos.X = 40;
	pos.Y = 248;
	pos.W = 16;
	pos.H = 16;
	screen.AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 16;
	dim.Y = 0;
	dim.W = 16;
	dim.H = 16;
	pos.X = 56;
	pos.Y = 248;
	pos.W = 528;
	pos.H = 16;
	screen.AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 32;
	dim.Y = 0;
	dim.W = 16;
	dim.H = 16;
	pos.X = 584;
	pos.Y = 248;
	pos.W = 16;
	pos.H = 16;
	screen.AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 0;
	dim.Y = 16;
	dim.W = 16;
	dim.H = 16;
	pos.X = 40;
	pos.Y = 264;
	pos.W = 16;
	pos.H = 80;
	screen.AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 16;
	dim.Y = 16;
	dim.W = 16;
	dim.H = 16;
	pos.X = 56;
	pos.Y = 264;
	pos.W = 528;
	pos.H = 80;
	screen.AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 32;
	dim.Y = 16;
	dim.W = 16;
	dim.H = 16;
	pos.X = 584;
	pos.Y = 264;
	pos.W = 16;
	pos.H = 80;
	screen.AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 0;
	dim.Y = 32;
	dim.W = 16;
	dim.H = 16;
	pos.X = 40;
	pos.Y = 344;
	pos.W = 16;
	pos.H = 16;
	screen.AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 16;
	dim.Y = 32;
	dim.W = 16;
	dim.H = 16;
	pos.X = 56;
	pos.Y = 344;
	pos.W = 528;
	pos.H = 16;
	screen.AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 32;
	dim.Y = 32;
	dim.W = 16;
	dim.H = 16;
	pos.X = 584;
	pos.Y = 344;
	pos.W = 16;
	pos.H = 16;
	screen.AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	pos.X = 128;
	pos.Y = 260;
	pos.W = 384;
	pos.H = 16;
	screen.AddUITextDisplay(0, 0, pos, _sTeam[1], 0, "", 1, 0);
	pos.X = 52;
	pos.Y = 280;
	pos.W = 400;
	pos.H = 170;
	screen.AddUITextPageDisplay(23, pos, 0, 6, False);
	pos.X = 64;
	pos.Y = 368;
	pos.W = 68;
	pos.H = 20;
	screen.AddRolloverBitmapButton(0, 5, pos, "T_AA2_UI.menu.hud_menu_elements3", dCancelButton, 0, "");
	pos.X = 512;
	pos.Y = 368;
	pos.W = 68;
	pos.H = 20;
	screen.AddRolloverBitmapButton(0, 21, pos, "T_AA2_UI.menu.hud_menu_elements3", dMoreButton, 0, "");
	string0 = cHUD.Level.GetLocalURL();
	pos0 = InStr(string0, "/");
	pos1 = InStr(string0, ".");
	pos2 = InStr(string0, "?");
	if (pos0 != -1)
	{
		string1 = Mid(string0, pos0 + 1, pos2 - pos0);
		string0 = string1;
		pos1 = InStr(string0, ".");
		pos2 = InStr(string0, "?");
	}
	if (pos1 == -1 || pos1 > pos2)
	{
		pos1 = pos2;
	}
	string2 = Left(string0, pos1);
	Control = screen.GetControl(22);
	UITextPageDisplay(Control).SetTextFile(_sBriefingsDir $ string2 $ "_team0.txt");
	Control = screen.GetControl(23);
	UITextPageDisplay(Control).SetTextFile(_sBriefingsDir $ string2 $ "_team1.txt");
	*/
}
void UGameMenuFrame::CreateTeamBriefScreen()
{
	/*
	local AGP_UI.UIScreen screen;
	local UIBase.Position pos;
	local UIBase.Position dim;
	screen = GetScreen(2);
	dim.X = 0;
	dim.Y = 0;
	dim.W = 16;
	dim.H = 16;
	pos.X = 40;
	pos.Y = 112;
	pos.W = 16;
	pos.H = 16;
	screen.AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 16;
	dim.Y = 0;
	dim.W = 16;
	dim.H = 16;
	pos.X = 56;
	pos.Y = 112;
	pos.W = 528;
	pos.H = 16;
	screen.AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 32;
	dim.Y = 0;
	dim.W = 16;
	dim.H = 16;
	pos.X = 584;
	pos.Y = 112;
	pos.W = 16;
	pos.H = 16;
	screen.AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 0;
	dim.Y = 16;
	dim.W = 16;
	dim.H = 16;
	pos.X = 40;
	pos.Y = 128;
	pos.W = 16;
	pos.H = 192;
	screen.AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 16;
	dim.Y = 16;
	dim.W = 16;
	dim.H = 16;
	pos.X = 56;
	pos.Y = 128;
	pos.W = 528;
	pos.H = 192;
	screen.AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 32;
	dim.Y = 16;
	dim.W = 16;
	dim.H = 16;
	pos.X = 584;
	pos.Y = 128;
	pos.W = 16;
	pos.H = 192;
	screen.AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 0;
	dim.Y = 32;
	dim.W = 16;
	dim.H = 16;
	pos.X = 40;
	pos.Y = 320;
	pos.W = 16;
	pos.H = 16;
	screen.AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 16;
	dim.Y = 32;
	dim.W = 16;
	dim.H = 16;
	pos.X = 56;
	pos.Y = 320;
	pos.W = 528;
	pos.H = 16;
	screen.AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 32;
	dim.Y = 32;
	dim.W = 16;
	dim.H = 16;
	pos.X = 584;
	pos.Y = 320;
	pos.W = 16;
	pos.H = 16;
	screen.AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	pos.X = 128;
	pos.Y = 124;
	pos.W = 384;
	pos.H = 16;
	screen.AddUITextDisplay(20, 0, pos, "TEAM NAME", 0, "", 1, 0);
	pos.X = 52;
	pos.Y = 144;
	pos.W = 400;
	pos.H = 170;
	screen.AddUITextPageDisplay(21, pos, 0, 14, False);
	pos.X = 64;
	pos.Y = 344;
	pos.W = 68;
	pos.H = 20;
	screen.AddRolloverBitmapButton(0, 2, pos, "T_AA2_UI.menu.hud_menu_elements3", dCancelButton, 0, "");
	pos.X = 512;
	pos.Y = 344;
	pos.W = 68;
	pos.H = 20;
	screen.AddRolloverBitmapButton(0, 22, pos, "T_AA2_UI.menu.hud_menu_elements3", dSelectButton, 0, "");
	*/
}
void UGameMenuFrame::CreateLoginScreen()
{
	/*
	local AGP_UI.UIScreen screen;
	local UIBase.Position pos;
	local UIBase.Position dim;
	screen = GetScreen(4);
	dim.X = 0;
	dim.Y = 0;
	dim.W = 16;
	dim.H = 16;
	pos.X = 64;
	pos.Y = 56;
	pos.W = 16;
	pos.H = 16;
	screen.AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 16;
	dim.Y = 0;
	dim.W = 16;
	dim.H = 16;
	pos.X = 80;
	pos.Y = 56;
	pos.W = 480;
	pos.H = 16;
	screen.AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 32;
	dim.Y = 0;
	dim.W = 16;
	dim.H = 16;
	pos.X = 560;
	pos.Y = 56;
	pos.W = 16;
	pos.H = 16;
	screen.AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 0;
	dim.Y = 16;
	dim.W = 16;
	dim.H = 16;
	pos.X = 64;
	pos.Y = 72;
	pos.W = 16;
	pos.H = 336;
	screen.AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 16;
	dim.Y = 16;
	dim.W = 16;
	dim.H = 16;
	pos.X = 80;
	pos.Y = 72;
	pos.W = 480;
	pos.H = 336;
	screen.AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 32;
	dim.Y = 16;
	dim.W = 16;
	dim.H = 16;
	pos.X = 560;
	pos.Y = 72;
	pos.W = 16;
	pos.H = 336;
	screen.AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 0;
	dim.Y = 32;
	dim.W = 16;
	dim.H = 16;
	pos.X = 64;
	pos.Y = 408;
	pos.W = 16;
	pos.H = 16;
	screen.AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 16;
	dim.Y = 32;
	dim.W = 16;
	dim.H = 16;
	pos.X = 80;
	pos.Y = 408;
	pos.W = 480;
	pos.H = 16;
	screen.AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 32;
	dim.Y = 32;
	dim.W = 16;
	dim.H = 16;
	pos.X = 560;
	pos.Y = 408;
	pos.W = 16;
	pos.H = 16;
	screen.AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	pos.X = 128;
	pos.Y = 64;
	pos.W = 384;
	pos.H = 16;
	screen.AddUITextDisplay(0, 0, pos, "SOLDIER LOGIN", 0, "", 2, 1);
	pos.X = 80;
	pos.Y = 146;
	pos.W = 112;
	pos.H = 20;
	screen.AddUITextDisplay(0, 0, pos, "SOLDIER NAME", 1, "", 2, 0);
	pos.Y += 50;
	screen.AddUITextDisplay(0, 0, pos, "PASSWORD", 1, "", 2, 0);
	dim.X = 0;
	dim.Y = 116;
	dim.W = 256;
	dim.H = 32;
	pos.X = 306;
	pos.Y = 136;
	pos.W = 256;
	pos.H = 32;
	screen.AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements", dim, 1);
	pos.X = 306;
	pos.Y += 50;
	pos.W = 256;
	pos.H = 32;
	screen.AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements", dim, 1);
	pos.X = 306;
	pos.Y = 136;
	pos.W = 256;
	pos.H = 32;
	screen.AddUIEditBox(30, 0, pos, "login", 0, "", 20);
	pos.X = 306;
	pos.Y += 50;
	pos.W = 256;
	pos.H = 32;
	screen.AddUIEditBox(31, 0, pos, "password", 1, "", 20);
	pos.X = 80;
	pos.W = 512;
	pos.Y += 128;
	screen.AddUITextDisplay(32, 0, pos, "WAITING", 0, "", 2, 1);
	pos.X = 80;
	pos.W = 512;
	pos.Y += 32;
	screen.AddUITextDisplay(33, 0, pos, "", 0, "", 2, 1);
	pos.X = 80;
	pos.Y = 392;
	pos.W = 68;
	pos.H = 20;
	screen.AddRolloverBitmapButton(0, 30, pos, "T_AA2_UI.menu.hud_menu_elements3", dMenuButton, 0, "");
	pos.X = 496;
	pos.Y = 392;
	pos.W = 68;
	pos.H = 20;
	screen.AddRolloverBitmapButton(34, 31, pos, "T_AA2_UI.menu.hud_menu_elements3", dLogInButton, 0, "");
	pos.X = 496;
	pos.Y = 392;
	pos.W = 68;
	pos.H = 20;
	screen.AddRolloverBitmapButton(35, 43, pos, "T_AA2_UI.menu.hud_menu_elements3", dContinueButton, 0, "");
	screen.AddUIKeyCapture(0, 0);
	*/
}
void UGameMenuFrame::CreateMissionSuccessScreen()
{
	/*
	local AGP_UI.UIScreen screen;
	local UIBase.Position pos;
	local UIBase.Position dim;
	screen = GetScreen(5);
	dim.X = 0;
	dim.Y = 0;
	dim.W = 16;
	dim.H = 16;
	pos.X = 64;
	pos.Y = 56;
	pos.W = 16;
	pos.H = 16;
	screen.AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 16;
	dim.Y = 0;
	dim.W = 16;
	dim.H = 16;
	pos.X = 80;
	pos.Y = 56;
	pos.W = 480;
	pos.H = 16;
	screen.AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 32;
	dim.Y = 0;
	dim.W = 16;
	dim.H = 16;
	pos.X = 560;
	pos.Y = 56;
	pos.W = 16;
	pos.H = 16;
	screen.AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 0;
	dim.Y = 16;
	dim.W = 16;
	dim.H = 16;
	pos.X = 64;
	pos.Y = 72;
	pos.W = 16;
	pos.H = 336;
	screen.AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 16;
	dim.Y = 16;
	dim.W = 16;
	dim.H = 16;
	pos.X = 80;
	pos.Y = 72;
	pos.W = 480;
	pos.H = 336;
	screen.AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 32;
	dim.Y = 16;
	dim.W = 16;
	dim.H = 16;
	pos.X = 560;
	pos.Y = 72;
	pos.W = 16;
	pos.H = 336;
	screen.AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 0;
	dim.Y = 32;
	dim.W = 16;
	dim.H = 16;
	pos.X = 64;
	pos.Y = 408;
	pos.W = 16;
	pos.H = 16;
	screen.AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 16;
	dim.Y = 32;
	dim.W = 16;
	dim.H = 16;
	pos.X = 80;
	pos.Y = 408;
	pos.W = 480;
	pos.H = 16;
	screen.AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 32;
	dim.Y = 32;
	dim.W = 16;
	dim.H = 16;
	pos.X = 560;
	pos.Y = 408;
	pos.W = 16;
	pos.H = 16;
	screen.AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	pos.X = 128;
	pos.Y = 64;
	pos.W = 384;
	pos.H = 16;
	screen.AddUITextDisplay(0, 0, pos, "MISSION SUCCESS", 0, "", 2, 1);
	pos.X = 80;
	pos.Y = 96;
	pos.W = 64;
	pos.H = 64;
	screen.AddUIDynamicBitmap(40, pos, "", 0);
	pos.X = 208;
	pos.Y = 96;
	pos.W = 256;
	pos.H = 32;
	screen.AddUITextDisplay(41, 0, pos, "temp test string", 0, "", 2, 1);
	pos.X = 208;
	pos.Y = 116;
	pos.W = 256;
	pos.H = 32;
	screen.AddUITextDisplay(47, 0, pos, "", 0, "", 2, 1);
	pos.X = 80;
	pos.Y = 250;
	pos.W = 480;
	pos.H = 32;
	screen.AddUITextDisplay(45, 0, pos, "", 0, "", 2, 1);
	pos.X = 80;
	pos.Y = 282;
	pos.W = 480;
	pos.H = 32;
	screen.AddUITextDisplay(46, 0, pos, "", 0, "", 2, 1);
	pos.X = 80;
	pos.Y = 392;
	pos.W = 68;
	pos.H = 20;
	screen.AddRolloverBitmapButton(42, 60, pos, "T_AA2_UI.menu.hud_menu_elements3", dMenuButton, 0, "");
	pos.X = 276;
	pos.Y = 392;
	pos.W = 68;
	pos.H = 20;
	screen.AddRolloverBitmapButton(43, 61, pos, "T_AA2_UI.menu.hud_menu_elements3", dReplayButton, 0, "");
	pos.X = 496;
	pos.Y = 392;
	pos.W = 68;
	pos.H = 20;
	screen.AddRolloverBitmapButton(44, 42, pos, "T_AA2_UI.menu.hud_menu_elements3", dContinueButton, 0, "");
	screen.AddUIKeyCapture(0, 0);
	*/
}
void UGameMenuFrame::CreateMissionFailureScreen()
{
	/*
	local AGP_UI.UIScreen screen;
	local UIBase.Position pos;
	local UIBase.Position dim;
	screen = GetScreen(6);
	dim.X = 0;
	dim.Y = 0;
	dim.W = 16;
	dim.H = 16;
	pos.X = 64;
	pos.Y = 56;
	pos.W = 16;
	pos.H = 16;
	screen.AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 16;
	dim.Y = 0;
	dim.W = 16;
	dim.H = 16;
	pos.X = 80;
	pos.Y = 56;
	pos.W = 480;
	pos.H = 16;
	screen.AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 32;
	dim.Y = 0;
	dim.W = 16;
	dim.H = 16;
	pos.X = 560;
	pos.Y = 56;
	pos.W = 16;
	pos.H = 16;
	screen.AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 0;
	dim.Y = 16;
	dim.W = 16;
	dim.H = 16;
	pos.X = 64;
	pos.Y = 72;
	pos.W = 16;
	pos.H = 336;
	screen.AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 16;
	dim.Y = 16;
	dim.W = 16;
	dim.H = 16;
	pos.X = 80;
	pos.Y = 72;
	pos.W = 480;
	pos.H = 336;
	screen.AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 32;
	dim.Y = 16;
	dim.W = 16;
	dim.H = 16;
	pos.X = 560;
	pos.Y = 72;
	pos.W = 16;
	pos.H = 336;
	screen.AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 0;
	dim.Y = 32;
	dim.W = 16;
	dim.H = 16;
	pos.X = 64;
	pos.Y = 408;
	pos.W = 16;
	pos.H = 16;
	screen.AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 16;
	dim.Y = 32;
	dim.W = 16;
	dim.H = 16;
	pos.X = 80;
	pos.Y = 408;
	pos.W = 480;
	pos.H = 16;
	screen.AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 32;
	dim.Y = 32;
	dim.W = 16;
	dim.H = 16;
	pos.X = 560;
	pos.Y = 408;
	pos.W = 16;
	pos.H = 16;
	screen.AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	pos.X = 128;
	pos.Y = 64;
	pos.W = 384;
	pos.H = 16;
	screen.AddUITextDisplay(0, 0, pos, "MISSION FAILURE", 0, "", 2, 1);
	pos.X = 208;
	pos.Y = 96;
	pos.W = 256;
	pos.H = 32;
	screen.AddUITextDisplay(41, 0, pos, "temp test string", 0, "", 2, 1);
	pos.X = 208;
	pos.Y = 116;
	pos.W = 256;
	pos.H = 32;
	screen.AddUITextDisplay(47, 0, pos, "", 0, "", 2, 1);
	pos.X = 80;
	pos.Y = 96;
	pos.W = 64;
	pos.H = 64;
	screen.AddUIDynamicBitmap(40, pos, "", 0);
	pos.X = 80;
	pos.Y = 392;
	pos.W = 68;
	pos.H = 20;
	screen.AddRolloverBitmapButton(0, 60, pos, "T_AA2_UI.menu.hud_menu_elements3", dMenuButton, 0, "");
	pos.X = 496;
	pos.Y = 392;
	pos.W = 68;
	pos.H = 20;
	screen.AddRolloverBitmapButton(0, 61, pos, "T_AA2_UI.menu.hud_menu_elements3", dReplayButton, 0, "");
	screen.AddUIKeyCapture(0, 0);
	*/
}
void UGameMenuFrame::CreateLandNavScoreScreen()
{
	/*
	local AGP_UI.UIScreen screen;
	local UIBase.Position pos;
	local UIBase.Position dim;
	screen = GetScreen(8);
	dim.X = 0;
	dim.Y = 0;
	dim.W = 16;
	dim.H = 16;
	pos.X = 64;
	pos.Y = 56;
	pos.W = 16;
	pos.H = 16;
	screen.AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 16;
	dim.Y = 0;
	dim.W = 16;
	dim.H = 16;
	pos.X = 80;
	pos.Y = 56;
	pos.W = 480;
	pos.H = 16;
	screen.AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 32;
	dim.Y = 0;
	dim.W = 16;
	dim.H = 16;
	pos.X = 560;
	pos.Y = 56;
	pos.W = 16;
	pos.H = 16;
	screen.AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 0;
	dim.Y = 16;
	dim.W = 16;
	dim.H = 16;
	pos.X = 64;
	pos.Y = 72;
	pos.W = 16;
	pos.H = 336;
	screen.AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 16;
	dim.Y = 16;
	dim.W = 16;
	dim.H = 16;
	pos.X = 80;
	pos.Y = 72;
	pos.W = 480;
	pos.H = 336;
	screen.AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 32;
	dim.Y = 16;
	dim.W = 16;
	dim.H = 16;
	pos.X = 560;
	pos.Y = 72;
	pos.W = 16;
	pos.H = 336;
	screen.AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 0;
	dim.Y = 32;
	dim.W = 16;
	dim.H = 16;
	pos.X = 64;
	pos.Y = 408;
	pos.W = 16;
	pos.H = 16;
	screen.AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 16;
	dim.Y = 32;
	dim.W = 16;
	dim.H = 16;
	pos.X = 80;
	pos.Y = 408;
	pos.W = 480;
	pos.H = 16;
	screen.AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 32;
	dim.Y = 32;
	dim.W = 16;
	dim.H = 16;
	pos.X = 560;
	pos.Y = 408;
	pos.W = 16;
	pos.H = 16;
	screen.AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	pos.X = 128;
	pos.Y = 90;
	pos.W = 384;
	pos.H = 16;
	screen.AddUITextDisplay(1009, 0, pos, "MISSION SUCCESS", 0, "", 2, 1);
	pos.X = 80;
	pos.Y = 130;
	pos.W = 480;
	pos.H = 32;
	screen.AddUITextDisplay(1001, 0, pos, "ID_LNTextString01", 0, "", 2, 1);
	pos.X = 80;
	pos.Y = 150;
	pos.W = 480;
	pos.H = 32;
	screen.AddUITextDisplay(1002, 0, pos, "ID_LNTextString02", 0, "", 2, 1);
	pos.X = 80;
	pos.Y = 170;
	pos.W = 480;
	pos.H = 32;
	screen.AddUITextDisplay(1003, 0, pos, "ID_LNTextString03", 0, "", 2, 1);
	pos.X = 80;
	pos.Y = 190;
	pos.W = 480;
	pos.H = 32;
	screen.AddUITextDisplay(1004, 0, pos, "ID_LNTextString04", 0, "", 2, 1);
	pos.X = 80;
	pos.Y = 210;
	pos.W = 480;
	pos.H = 32;
	screen.AddUITextDisplay(1005, 0, pos, "ID_LNTextString05", 0, "", 2, 1);
	pos.X = 80;
	pos.Y = 230;
	pos.W = 480;
	pos.H = 32;
	screen.AddUITextDisplay(1006, 0, pos, "ID_LNTextString06", 0, "", 2, 1);
	pos.X = 80;
	pos.Y = 250;
	pos.W = 480;
	pos.H = 32;
	screen.AddUITextDisplay(1007, 0, pos, "ID_LNTextString07", 0, "", 2, 1);
	pos.X = 80;
	pos.Y = 290;
	pos.W = 480;
	pos.H = 32;
	screen.AddUITextDisplay(1008, 0, pos, "ID_LNTextString08", 0, "", 2, 1);
	pos.X = 496;
	pos.Y = 392;
	pos.W = 68;
	pos.H = 20;
	screen.AddRolloverBitmapButton(44, 62, pos, "T_AA2_UI.menu.hud_menu_elements3", dContinueButton, 0, "");
	screen.AddUIKeyCapture(0, 0);
	*/
}
void UGameMenuFrame::CreateServerAdminScreen()
{
	/*
	local AGP_UI.UIScreen screen;
	local UIBase.Position pos;
	local UIBase.Position dim;
	screen = GetScreen(7);
	dim.X = 0;
	dim.Y = 0;
	dim.W = 16;
	dim.H = 16;
	pos.X = 78;
	pos.Y = 32;
	pos.W = 16;
	pos.H = 16;
	screen.AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 16;
	dim.Y = 0;
	dim.W = 16;
	dim.H = 16;
	pos.X = 94;
	pos.Y = 32;
	pos.W = 480;
	pos.H = 16;
	screen.AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 32;
	dim.Y = 0;
	dim.W = 16;
	dim.H = 16;
	pos.X = 574;
	pos.Y = 32;
	pos.W = 16;
	pos.H = 16;
	screen.AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 0;
	dim.Y = 16;
	dim.W = 16;
	dim.H = 16;
	pos.X = 78;
	pos.Y = 48;
	pos.W = 16;
	pos.H = 384;
	screen.AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 16;
	dim.Y = 16;
	dim.W = 16;
	dim.H = 16;
	pos.X = 94;
	pos.Y = 48;
	pos.W = 480;
	pos.H = 384;
	screen.AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 32;
	dim.Y = 16;
	dim.W = 16;
	dim.H = 16;
	pos.X = 574;
	pos.Y = 48;
	pos.W = 16;
	pos.H = 384;
	screen.AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 0;
	dim.Y = 32;
	dim.W = 16;
	dim.H = 16;
	pos.X = 78;
	pos.Y = 432;
	pos.W = 16;
	pos.H = 16;
	screen.AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 16;
	dim.Y = 32;
	dim.W = 16;
	dim.H = 16;
	pos.X = 94;
	pos.Y = 432;
	pos.W = 480;
	pos.H = 16;
	screen.AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 32;
	dim.Y = 32;
	dim.W = 16;
	dim.H = 16;
	pos.X = 574;
	pos.Y = 432;
	pos.W = 16;
	pos.H = 16;
	screen.AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	pos.X = 82;
	pos.Y = 42;
	pos.W = 508;
	pos.H = 16;
	screen.AddUITextDisplay(0, 0, pos, "SERVER ADMIN COMMAND POST", 0, "", 2, 0);
	pos.X = 82;
	pos.Y = 76;
	pos.W = 182;
	pos.H = 16;
	screen.AddUITextDisplay(0, 0, pos, "PLAYERS", 0, "", 2, 0);
	pos.X = 330;
	pos.Y = 76;
	pos.W = 256;
	pos.H = 16;
	screen.AddUITextDisplay(0, 0, pos, "SETTINGS", 0, "", 2, 0);
	pos.X = 82;
	pos.Y = 98;
	pos.W = 246;
	pos.H = 256;
	screen.AddUIPlayerList(50, pos, 0);
	pos.X = 330;
	pos.Y = 98;
	pos.W = 256;
	pos.H = 256;
	screen.AddUISettingsList(51, pos, 0);
	dim.X = 0;
	dim.Y = 116;
	dim.W = 256;
	dim.H = 32;
	pos.X = 264;
	pos.Y = 376;
	pos.W = 256;
	pos.H = 32;
	screen.AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements", dim, 1);
	pos.X = 264;
	pos.Y = 376;
	pos.W = 256;
	pos.H = 32;
	screen.AddUIEditBox(53, 0, pos, "", 0, "", 20);
	pos.X = 524;
	pos.Y = 378;
	pos.W = 10;
	pos.H = 10;
	screen.AddUITextButton(0, 50, pos, "SEND", 1, "");
	pos.X = 82;
	pos.Y = 355;
	pos.W = 68;
	pos.H = 20;
	screen.AddRolloverBitmapButton(0, 53, pos, "T_AA2_UI.menu.hud_menu_elements", dBackButton, 0, "");
	pos.X = 260;
	pos.Y = 355;
	pos.W = 68;
	pos.H = 20;
	screen.AddRolloverBitmapButton(0, 54, pos, "T_AA2_UI.menu.hud_menu_elements", dNextButton, 0, "");
	pos.X = 330;
	pos.Y = 355;
	pos.W = 68;
	pos.H = 20;
	screen.AddRolloverBitmapButton(0, 55, pos, "T_AA2_UI.menu.hud_menu_elements", dBackButton, 0, "");
	pos.X = 518;
	pos.Y = 355;
	pos.W = 68;
	pos.H = 20;
	screen.AddRolloverBitmapButton(0, 56, pos, "T_AA2_UI.menu.hud_menu_elements", dNextButton, 0, "");
	pos.X = 80;
	pos.Y = 378;
	pos.W = 10;
	pos.H = 10;
	screen.AddUITextButton(0, 51, pos, "KICK", 1, "");
	pos.X = 149;
	pos.Y = 378;
	pos.W = 10;
	pos.H = 10;
	screen.AddUITextButton(0, 52, pos, "BAN", 1, "");
	pos.X = 80;
	pos.Y = 424;
	pos.W = 500;
	pos.H = 20;
	screen.AddUIConsole(0, pos, 0);
	*/
}
void UGameMenuFrame::RefreshLoginScreen()
{
	/*
	local AGP_UI.UIScreen screen;
	local AGP_UI.UIControl Control;
	local FString sTemp;
	screen = GetScreen(4);
	Control = screen.GetControl(30);
	sTemp = HumanController(AGP_HUD(cHUD).PlayerOwner).UserName;
	UIEditBox(Control).SetLabel(sTemp);
	Control = screen.GetControl(31);
	sTemp = HumanController(AGP_HUD(cHUD).PlayerOwner).UserPassword;
	UIEditBox(Control).SetLabel(sTemp);
	Control = screen.GetControl(32);
	UITextDisplay(Control).SetLabel("Please log in to upload your results!");
	_iLoginStatus = 0;
	Control = screen.GetControl(33);
	UITextDisplay(Control).SetLabel("");
	Control = screen.GetControl(34);
	Control.SetEnabled(True);
	Control = screen.GetControl(35);
	Control.SetEnabled(False);
	*/
}
void UGameMenuFrame::CancelLogin()
{
	ResetActiveScreen();
	//AGP_HUD(cHUD).CloseGameMenu();
	//AGP_HUD(cHUD).PlayerOwner.ConsoleCommand("start entry");
}
void UGameMenuFrame::SelectLogin()
{
	/*
	local AGP_UI.UIScreen screen;
	local AGP_UI.UIControl Control;
	if (_iLoginStatus == 2)
	{
		Notify(42);
	}
	else
	{
		if (_iLoginStatus != -99)
		{
			if (AGP_HUD(cHUD).PlayerOwner.Level.Game.bBinaryAuthProtocol)
			{
			}
			screen = GetScreen(4);
			Control = screen.GetControl(30);
			PrivateSet("humancontroller username " $ UIEditBox(Control).GetLabel());
			Control = screen.GetControl(31);
			PrivateSet("humancontroller userpassword " $ UIEditBox(Control).GetLabel());
			HumanController(AGP_HUD(cHUD).PlayerOwner).MissionCompleted();
			_iLoginStatus = -99;
		}
	}
	*/
}
void UGameMenuFrame::SetLoginStatus(int32 iStatus, FString sStatus, FString sNavMsg)
{
	/*
	local AGP_UI.UIScreen screen;
	local AGP_UI.UIControl Control;
	_iLoginStatus = iStatus;
	screen = GetScreen(4);
	Control = screen.GetControl(32);
	UITextDisplay(Control).SetLabel(sStatus);
	Control = screen.GetControl(33);
	UITextDisplay(Control).SetLabel(sNavMsg);
	if (_iLoginStatus == 2)
	{
		Control = screen.GetControl(34);
		Control.SetEnabled(False);
		Control = screen.GetControl(35);
		Control.SetEnabled(True);
	}
	*/
}
void UGameMenuFrame::SetMissionSuccessScreen(FString Texture, FString Text, FString text2, int32 USize, int32 VSize, int32 RenderStyle, FName replayscene, bool bCheater)
{
	/*
	local AGP_UI.UIScreen screen;
	local AGP_UI.UIControl Control;
	screen = GetScreen(5);
	Control = screen.GetControl(40);
	UIDynamicBitmap(Control).SetTexture(Texture, USize, VSize, RenderStyle);
	Control = screen.GetControl(41);
	UITextDisplay(Control).SetLabel(Text);
	Control = screen.GetControl(47);
	UITextDisplay(Control).SetLabel(text2);
	nReplayScene = replayscene;
	if (bCheater)
	{
		Control = screen.GetControl(43);
		Control.SetEnabled(False);
		Control = screen.GetControl(44);
		Control.SetEnabled(False);
		Control = screen.GetControl(45);
		UITextDisplay(Control).SetLabel("Cannot authorize due to use of player cheats.");
		Control = screen.GetControl(46);
		UITextDisplay(Control).SetLabel("Click MENU to return to the main menu.");
	}
	else
	{
		Control = screen.GetControl(43);
		Control.SetEnabled(True);
		Control = screen.GetControl(44);
		Control.SetEnabled(True);
		Control = screen.GetControl(45);
		UITextDisplay(Control).SetLabel("Do you wish to enter these results in your permanent");
		Control = screen.GetControl(46);
		UITextDisplay(Control).SetLabel("personnel jacket?");
	}
	*/
}
void UGameMenuFrame::SetMissionFailureScreen(FString Texture, FString Text, FString text2, int32 USize, int32 VSize, int32 RenderStyle, FName replayscene)
{
	/*
	local AGP_UI.UIScreen screen;
	local AGP_UI.UIControl Control;
	screen = GetScreen(6);
	Control = screen.GetControl(40);
	UIDynamicBitmap(Control).SetTexture(Texture, USize, VSize, RenderStyle);
	Control = screen.GetControl(41);
	UITextDisplay(Control).SetLabel(Text);
	Control = screen.GetControl(47);
	UITextDisplay(Control).SetLabel(text2);
	nReplayScene = replayscene;
	*/
}
void UGameMenuFrame::SetLandNavScoreScreen(FString text1, FString text2, FString text3, FString text4, FString text5, FString text6, FString text7, FString text8, bool bCheater)
{
	/*
	local AGP_UI.UIScreen screen;
	local AGP_UI.UIControl Control;
	screen = GetScreen(8);
	if (bCheater)
	{
		Control = screen.GetControl(1009);
		UITextDisplay(Control).SetLabel("CHEATS DETECTED");
	}
	Control = screen.GetControl(1001);
	UITextDisplay(Control).SetLabel(text1);
	Control = screen.GetControl(1002);
	UITextDisplay(Control).SetLabel(text2);
	Control = screen.GetControl(1003);
	UITextDisplay(Control).SetLabel(text3);
	Control = screen.GetControl(1004);
	UITextDisplay(Control).SetLabel(text4);
	Control = screen.GetControl(1005);
	UITextDisplay(Control).SetLabel(text5);
	Control = screen.GetControl(1006);
	UITextDisplay(Control).SetLabel(text6);
	Control = screen.GetControl(1007);
	UITextDisplay(Control).SetLabel(text7);
	Control = screen.GetControl(1008);
	UITextDisplay(Control).SetLabel(text8);
	*/
}
void UGameMenuFrame::ScaleControls(UCanvas* Canvas)
{
	/*
	local AGP_UI.UIScreen screen;
	if (_iOldSizeX == Canvas.SizeX && _iOldSizeY == Canvas.SizeY)
	{
		return;
	}
	fScaleX = Canvas.SizeX / 640;
	fScaleY = Canvas.SizeY / 480;
	if (_bAllowScaling)
	{
		offset.X = _Pos.X * fScaleX;
		offset.Y = _Pos.Y * fScaleY;
	}
	else
	{
		if (Canvas.SizeX >= 640 && Canvas.SizeY >= 480)
		{
			offset.X = Canvas.SizeX - 640 / 2;
			offset.Y = Canvas.SizeY - 480 / 2;
		}
	}
	screen = cScreenList;
	if (screen != nullptr)
	{
		screen.ScaleControls(Canvas);
		screen = screen.cNextScreen;
	}
	if (cMouse != nullptr)
	{
		cMouse.ScaleControl(Canvas);
	}
	if (_bAllowScaling)
	{
		_ScaledToolTipLoc.X = _ToolTipLoc.X * fScaleX + offset.X;
		_ScaledToolTipLoc.Y = _ToolTipLoc.Y * fScaleY + offset.Y;
	}
	else
	{
		_ScaledToolTipLoc.X = _ToolTipLoc.X + offset.X;
		_ScaledToolTipLoc.Y = _ToolTipLoc.Y + offset.Y;
	}
	_iOldSizeX = Canvas.SizeX;
	_iOldSizeY = Canvas.SizeY;
	*/
}
void UGameMenuFrame::PlayMenuSoundSpecific(USoundBase* Sound)
{
	/*
	if (AGP_HUD(cHUD).PlayerOwner != None && Sound != nullptr)
	{
		AGP_HUD(cHUD).PlayerOwner.PlayOwnedSound(Sound, , 1, , 1000000, , False);
	}
	*/
}
void UGameMenuFrame::QueryServerListReply(int32 Index, FString Section, FString Setting, FString Value, int32 Type)
{
	/*
	local AGP_UI.UIScreen screen;
	local AGP_UI.UIControl Control;
	screen = GetScreen(7);
	Control = screen.GetControl(51);
	UISettingsList(Control).SetSetting(Index, Section, Setting, Value, Type);
	*/
}
void UGameMenuFrame::SetServerSettingReply(int32 Index, FString Value)
{
	/*
	local AGP_UI.UIScreen screen;
	local AGP_UI.UIControl Control;
	screen = GetScreen(7);
	Control = screen.GetControl(51);
	UISettingsList(Control).UpdateSettingValue(Index, Value);
	*/
}
void UGameMenuFrame::SetSettingsValue(FString Value)
{
	/*
	local AGP_UI.UIScreen screen;
	local AGP_UI.UIControl Control;
	screen = GetScreen(7);
	Control = screen.GetControl(53);
	UIEditBox(Control).SetLabel(Value);
	*/
}
void UGameMenuFrame::UpdateServerSetting()
{
	/*
	local AGP_UI.UIScreen screen;
	local AGP_UI.UIControl Control;
	local int32 Index;
	local FString Value;
	screen = GetScreen(7);
	Control = screen.GetControl(53);
	Value = UIEditBox(Control).GetLabel();
	Control = screen.GetControl(51);
	Index = UISettingsList(Control).GetSelectedIndex();
	cHUD.PlayerOwner.SetServerSetting(Index, Value);
	*/
}
void UGameMenuFrame::BanPlayer()
{
	/*
	local AGP_UI.UIScreen screen;
	local AGP_UI.UIControl Control;
	local FString Value;
	screen = GetScreen(7);
	Control = screen.GetControl(50);
	Value = UIPlayerList(Control).GetSelectedPlayer();
	HumanController(AGP_HUD(cHUD).PlayerOwner).Admin("kickban" @ Value);
	*/
}
void UGameMenuFrame::KickPlayer()
{
	/*
	local AGP_UI.UIScreen screen;
	local AGP_UI.UIControl Control;
	local FString Value;
	screen = GetScreen(7);
	Control = screen.GetControl(50);
	Value = UIPlayerList(Control).GetSelectedPlayer();
	HumanController(AGP_HUD(cHUD).PlayerOwner).Admin("kick" @ Value);
	*/
}
void UGameMenuFrame::PlayerList(int32 Direction)
{
	/*
	local AGP_UI.UIScreen screen;
	local AGP_UI.UIControl Control;
	screen = GetScreen(7);
	Control = screen.GetControl(50);
	if (Direction == -1)
	{
		UIPlayerList(Control).PrevPage();
	}
	if (Direction == 1)
	{
		UIPlayerList(Control).NextPage();
	}
	*/
}
void UGameMenuFrame::SettingList(int32 Direction)
{
	/*
	local AGP_UI.UIScreen screen;
	local AGP_UI.UISettingsList Control;
	screen = GetScreen(7);
	Control = UISettingsList(screen.GetControl(51));
	if (Direction == 1)
	{
		Control.NextPage();
	}
	else
	{
		Control.PrevPage();
	}
	*/
}