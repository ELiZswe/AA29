// All the original content belonged to the US Army

#include "AA29/Object/UIBase/UIFrame/GameMenuFrame/GameMenuFrame.h"
#include "AA29/Object/UIBase/UIScreen/UIScreen.h"
#include "AA29/Object/UIBase/UIControl/UISoundControl/UINavControl/UICheckboxB/UICheckboxB.h"
#include "AA29/Object/UIBase/UIControl/UIControl.h"
#include "AA29/Object/Actor/HUD/AGP_HUD/AGP_HUD.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/Object/Actor/Screenplay/Screenplay.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/TeamInfo/TeamInfo.h"
#include "AA29/Object/UIBase/UIControl/UISoundControl/UINavControl/UIClassButton/UIClassButton.h"
#include "AA29/Object/UIBase/UIControl/UIDynamicBitmap/UIDynamicBitmap.h"
#include "AA29/Object/UIBase/UIControl/UISoundControl/UINavControl/UIEditBox/UIEditBox.h"
#include "AA29/Object/UIBase/UIControl/UISoundControl/UINavControl/UIPlayerList/UIPlayerList.h"
#include "AA29/Object/UIBase/UIControl/UISoundControl/UINavControl/UISettingsList/UISettingsList.h"
#include "AA29/Object/UIBase/UIControl/UITextDisplay/UITextDisplay.h"
#include "AA29/Object/UIBase/UIControl/UITextPageDisplay/UITextPageDisplay.h"
#include "AA29/Object/UIBase/UIControl/UIMouse/UIMouse.h"
#include "Engine/Canvas.h"

UGameMenuFrame::UGameMenuFrame()
{
	_sTeam.SetNum(2);
	prev_SelectedClass = -1;
	_iSettingsPage = -1;
	_bToolTipActive = false;
	_Pos = FPosition({ 0, 0, 1280, 1024 });
	_bAllowScaling = false;

}

void UGameMenuFrame::Notify(int32 pUIEvent)
{
	AScreenplay* SP = nullptr;
	if (cHUD != nullptr && cHUD->IsA(AAGP_HUD::StaticClass()))
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
			Cast<AAGP_HUD>(cHUD)->CloseGameMenu();
			return;
		}
		if (pUIEvent == 24)
		{
			DoSpectateTeam(1);
			ResetActiveScreen();
			Cast<AAGP_HUD>(cHUD)->CloseGameMenu();
			return;
		}
		if (pUIEvent == 22)
		{
			DoSelectTeam();
			ResetActiveScreen();
			Cast<AAGP_HUD>(cHUD)->CloseGameMenu();
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
			Cast<AAGP_HUD>(cHUD)->CloseGameMenu();
			return;
		}
		if (pUIEvent == 18)
		{
			DoSelectClass();
			ResetActiveScreen();
			Cast<AAGP_HUD>(cHUD)->CloseGameMenu();
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
			Cast<AAGP_HUD>(cHUD)->CloseGameMenu();
			Cast<AAGP_HUD>(cHUD)->PlayerOwner->ConsoleCommand("start entry");
			return;
		}
		if (pUIEvent == 61)
		{
			ResetActiveScreen();
			Cast<AAGP_HUD>(cHUD)->CloseGameMenu();
			//SP = cHUD->Level->Game->GetScreenplay();
			if (SP != nullptr)
			{
				//SP->SceneJump(nReplayScene);
			}
			else
			{
				Cast<AAGP_HUD>(cHUD)->PlayerOwner->ConsoleCommand("reconnect");
			}
			return;
		}
		if (pUIEvent == 42)
		{
			/*
			if (cHUD->Level->DidPlayerCompleteNewMission(cHUD->PlayerOwner) == 1)
			{
				SetActiveScreen(4);
			}
			else
			{
				Cast<AHumanController>(Cast<AAGP_HUD>(cHUD)->PlayerOwner)->VerifyJacket();
				Cast<AHumanController>(Cast<AAGP_HUD>(cHUD)->PlayerOwner)->SaveJacket();
				ResetActiveScreen();
				Cast<AAGP_HUD>(cHUD)->CloseGameMenu();
				Cast<AAGP_HUD>(cHUD)->PlayerOwner->ConsoleCommand("start entry2");
				return;
			}
			*/
			return;
		}
		if (pUIEvent == 43)
		{
			Cast<AHumanController>(Cast<AAGP_HUD>(cHUD)->PlayerOwner)->VerifyJacket();
			Cast<AHumanController>(Cast<AAGP_HUD>(cHUD)->PlayerOwner)->SaveJacket();
			ResetActiveScreen();
			Cast<AAGP_HUD>(cHUD)->CloseGameMenu();
			Cast<AAGP_HUD>(cHUD)->PlayerOwner->ConsoleCommand("start entry2");
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
			Cast<AAGP_HUD>(cHUD)->CloseGameMenu();
			Cast<AAGP_HUD>(cHUD)->PlayerOwner->ConsoleCommand("start entry");
			return;
		}
	}
}

void UGameMenuFrame::SetActiveScreen(int32 screen_id)
{
	Super::SetActiveScreen(screen_id);
	if (screen_id == 7 && !_bSettingsListSet)
	{
		Cast<AHumanController>(Cast<AAGP_HUD>(cHUD)->PlayerOwner)->QueryServerList();
		_bSettingsListSet = true;
	}
}

void UGameMenuFrame::SelectClass(int32 control_id)
{
	UUIScreen* screen = nullptr;
	UUIClassButton* Control = nullptr;
	screen = GetScreen(3);
	if (_iSelectedClass != 0)
	{
		Control = Cast<UUIClassButton>(screen->GetControl(_iSelectedClass));
		Control->SetSelected(false);
	}
	_iSelectedClass = control_id;
	Control = Cast<UUIClassButton>(screen->GetControl(_iSelectedClass));
	Control->SetSelected(true);
}

void UGameMenuFrame::DoSelectClass()
{
	UUIScreen* screen = nullptr;
	UUIClassButton* Control = nullptr;
	bool bLeader = false;
	bool bMedic = false;
	screen = GetScreen(3);
	Control = Cast<UUIClassButton>(screen->GetControl(_iSelectedClass));
	if (Control->GetClassIndex() == 5 || Control->GetClassIndex() == 6)
	{
		Cast<UUICheckboxB>(screen->GetControl(18))->Select(false);
	}
	bLeader = Cast<UUICheckboxB>(screen->GetControl(18))->IsSelected();
	bMedic = Cast<UUICheckboxB>(screen->GetControl(19))->IsSelected();
	if (Control != nullptr)
	{
		Cast<AHumanController>(Cast<AAGP_HUD>(cHUD)->PlayerOwner)->SetPreferredClass(Control->GetClassIndex(), bLeader, bMedic, prev_SelectedClass, prev_AvoidLeader);
	}
	prev_AvoidLeader = bLeader;
	prev_SelectedClass = Control->GetClassIndex();
}

void UGameMenuFrame::RefreshClassSelect()
{
	ATeamInfo* TeamInfo = nullptr;
	int32 iNumClasses = 0;
	int32 iCurIndex = 0;
	bool bAvail = false;
	bool bQual = false;
	uint8 yAltClass = 0;
	FString Label = "";
	AActor* aClass = nullptr;
	//TeamInfo = Cast<AAGP_HUD>(cHUD)->PlayerOwner->PlayerReplicationInfo->Team;
	if (TeamInfo != nullptr)
	{
		iNumClasses = TeamInfo->GetNumClasses();
		for (iCurIndex = 0; iCurIndex < iNumClasses; iCurIndex++)
		{
			/*
			if (GetNoSniper())
			{
				if (iCurIndex == 2 || iCurIndex == 3)
				{
					bAvail = false;
				}
				else
				{
					bAvail = TeamInfo->IsClassAvailable(iCurIndex);
				}
			}
			else
			{
				bAvail = TeamInfo->IsClassAvailable(iCurIndex);
			}
			*/
			//aClass = class<Actor>(TeamInfo.GetClass(iCurIndex));
			//bQual = Cast<AAGP_HUD>(cHUD)->PlayerOwner->QualifiedFor(aClass);
			yAltClass = TeamInfo->UseAltClass(iCurIndex);
			Label = TeamInfo->GetClassDisplayName(iCurIndex);
			EnableClassSelect(bAvail, bQual, yAltClass, Label, 10 + iCurIndex);
		}
		EnableLeaderPreference(TeamInfo->GetNumLeadersDesired(), TeamInfo->GetNumLeadersAvailable());
		EnableMedicPreference(TeamInfo->GetNumMedicsDesired(), TeamInfo->GetNumMedicsAvailable());
	}
}

void UGameMenuFrame::EnableMedicPreference(int32 ndesired, int32 navail)
{
	UUIScreen* screen = nullptr;
	UUICheckboxB* cbox = nullptr;
	screen = GetScreen(3);
	cbox = Cast<UUICheckboxB>(screen->GetControl(19));
	//cbox->SetLabel("REQUEST MEDIC [" + ndesired + "/" + navail + "]");
}

void UGameMenuFrame::EnableLeaderPreference(int32 ndesired, int32 navail)
{
	UUIScreen* screen = nullptr;
	UUICheckboxB* cbox = nullptr;
	screen = GetScreen(3);
	cbox = Cast<UUICheckboxB>(screen->GetControl(18));
	//cbox->SetLabel("AVOID LEADER ROLES [" + ndesired + "/" + navail + "]");
}

void UGameMenuFrame::EnableClassSelect(bool bState, bool bQual, uint8 yalt, FString Label, int32 control_id)
{
	UUIScreen* screen = nullptr;
	UUIClassButton* Control = nullptr;
	screen = GetScreen(3);
	Control = Cast<UUIClassButton>(screen->GetControl(control_id));
	Control->SetEnabled(bState);
	Control->SetQualified(bQual);
	Control->SetUseAltClass(yalt);
	Control->SetLabel(Label);
}

void UGameMenuFrame::SelectTeam(int32 Team)
{
	UUIScreen* screen = nullptr;
	UUITextPageDisplay* Control = nullptr;
	UUITextPageDisplay* control2 = nullptr;
	screen = GetScreen(1);
	Control = Cast<UUITextPageDisplay>(screen->GetControl(22 + Team));
	screen = GetScreen(2);
	control2 = Cast<UUITextPageDisplay>(screen->GetControl(21));
	_iSelectedTeam = Team;
	Cast<UUITextDisplay>(GetScreen(2)->GetControl(20))->SetLabel(_sTeam[_iSelectedTeam]);
	control2->SetStringList(Control->GetStringList());
}

void UGameMenuFrame::DoSelectTeam()
{
	Cast<AHumanController>(Cast<AAGP_HUD>(cHUD)->PlayerOwner)->SetTeam(_iSelectedTeam);
}
void UGameMenuFrame::DoSpectateTeam(int32 Team)
{
}
void UGameMenuFrame::CheckFullScreen()
{
	/*
	if (Cast<AAGP_HUD>(cHUD)->PlayerOwner->Player->bFullScreen)
	{
		Cast<AAGP_HUD>(cHUD)->PlayerOwner->ConsoleCommand("togglefullscreen");
	}
	*/
}

void UGameMenuFrame::Draw(UCanvas* Canvas)
{
	if (GetActiveScreen() == nullptr)
	{
		SetActiveScreen(0);
	}
	Super::Draw(Canvas);
}

void UGameMenuFrame::Create(AAA2_HUD* pHUD)
{
	FPoint pt = FPoint({});
	FString Temp = "";
	Super::Create(pHUD);
	//Temp = GetBaseDir();
	_sBriefingsDir = Temp.Left(Temp.Len() - 7);
	_sBriefingsDir = _sBriefingsDir + "briefings\\";
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
	UUIScreen* screen;
	FPosition pos = {};
	screen = GetScreen(0);
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
}

void UGameMenuFrame::CreateClassSelectScreen()
{
	UUIScreen* screen;
	FPosition pos = {};
	FPosition dim = {};
	screen = GetScreen(3);
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
	screen->AddUIClassButton(10, 10, pos, dim, 0, "T_AA2_UI.menu.ui_gm_rifleman", "T_AA2_UI.menu.ui_gm_m4a1", "T_AA2_UI.menu.ui_gm_m4a1_mod","", "");
	pos.X = 336;
	screen->AddUIClassButton(11, 11, pos, dim, 1, "T_AA2_UI.menu.ui_gm_grenadier", "", "", "", "");
	pos.Y += 96;
	pos.X = 80;
	screen->AddUIClassButton(12, 12, pos, dim, 2, "T_AA2_UI.menu.ui_gm_sniper82", "", "", "", "");
	pos.X = 336;
	screen->AddUIClassButton(13, 13, pos, dim, 3, "T_AA2_UI.menu.ui_gm_sniper24", "", "", "", "");
	pos.Y += 96;
	pos.X = 80;
	screen->AddUIClassButton(14, 14, pos, dim, 4, "T_AA2_UI.menu.ui_gm_automaticrifleman", "", "", "", "");
	pos.X = 336;
	screen->AddUIClassButton(17, 17, pos, dim, -1, "T_AA2_UI.menu.ui_gm_random", "", "", "", "");
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
}

void UGameMenuFrame::CreateTeamSelectScreen()
{
	
	UUIControl* Control = nullptr;
	UUIScreen* screen = nullptr;
	FPosition pos = {};
	FPosition dim = {};

	FString string0 = "";
	FString string1 = "";
	FString string2 = "";
	int32 pos0 = 0;
	int32 pos1 = 0;
	int32 pos2 = 0;
	screen = GetScreen(1);
	//_sTeam[0] = cHUD.Level.TeamName[0];
	//_sTeam[1] = cHUD.Level.TeamName[1];
	dim.X = 0;
	dim.Y = 0;
	dim.W = 16;
	dim.H = 16;
	pos.X = 40;
	pos.Y = 88;
	pos.W = 16;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 16;
	dim.Y = 0;
	dim.W = 16;
	dim.H = 16;
	pos.X = 56;
	pos.Y = 88;
	pos.W = 528;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 32;
	dim.Y = 0;
	dim.W = 16;
	dim.H = 16;
	pos.X = 584;
	pos.Y = 88;
	pos.W = 16;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 0;
	dim.Y = 16;
	dim.W = 16;
	dim.H = 16;
	pos.X = 40;
	pos.Y = 104;
	pos.W = 16;
	pos.H = 80;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 16;
	dim.Y = 16;
	dim.W = 16;
	dim.H = 16;
	pos.X = 56;
	pos.Y = 104;
	pos.W = 528;
	pos.H = 80;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 32;
	dim.Y = 16;
	dim.W = 16;
	dim.H = 16;
	pos.X = 584;
	pos.Y = 104;
	pos.W = 16;
	pos.H = 80;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 0;
	dim.Y = 32;
	dim.W = 16;
	dim.H = 16;
	pos.X = 40;
	pos.Y = 184;
	pos.W = 16;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 16;
	dim.Y = 32;
	dim.W = 16;
	dim.H = 16;
	pos.X = 56;
	pos.Y = 184;
	pos.W = 528;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 32;
	dim.Y = 32;
	dim.W = 16;
	dim.H = 16;
	pos.X = 584;
	pos.Y = 184;
	pos.W = 16;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	pos.X = 128;
	pos.Y = 100;
	pos.W = 384;
	pos.H = 16;
	screen->AddUITextDisplay(0, 0, pos, _sTeam[0], 0, "", 1, 0);
	pos.X = 52;
	pos.Y = 120;
	pos.W = 400;
	pos.H = 170;
	screen->AddUITextPageDisplay(22, pos, 0, 6, false);
	pos.X = 512;
	pos.Y = 208;
	pos.W = 68;
	pos.H = 20;
	screen->AddRolloverBitmapButton(0, 20, pos, "T_AA2_UI.menu.hud_menu_elements3", dMoreButton, 0, "");
	dim.X = 0;
	dim.Y = 0;
	dim.W = 16;
	dim.H = 16;
	pos.X = 40;
	pos.Y = 248;
	pos.W = 16;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 16;
	dim.Y = 0;
	dim.W = 16;
	dim.H = 16;
	pos.X = 56;
	pos.Y = 248;
	pos.W = 528;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 32;
	dim.Y = 0;
	dim.W = 16;
	dim.H = 16;
	pos.X = 584;
	pos.Y = 248;
	pos.W = 16;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 0;
	dim.Y = 16;
	dim.W = 16;
	dim.H = 16;
	pos.X = 40;
	pos.Y = 264;
	pos.W = 16;
	pos.H = 80;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 16;
	dim.Y = 16;
	dim.W = 16;
	dim.H = 16;
	pos.X = 56;
	pos.Y = 264;
	pos.W = 528;
	pos.H = 80;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 32;
	dim.Y = 16;
	dim.W = 16;
	dim.H = 16;
	pos.X = 584;
	pos.Y = 264;
	pos.W = 16;
	pos.H = 80;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 0;
	dim.Y = 32;
	dim.W = 16;
	dim.H = 16;
	pos.X = 40;
	pos.Y = 344;
	pos.W = 16;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 16;
	dim.Y = 32;
	dim.W = 16;
	dim.H = 16;
	pos.X = 56;
	pos.Y = 344;
	pos.W = 528;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 32;
	dim.Y = 32;
	dim.W = 16;
	dim.H = 16;
	pos.X = 584;
	pos.Y = 344;
	pos.W = 16;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	pos.X = 128;
	pos.Y = 260;
	pos.W = 384;
	pos.H = 16;
	screen->AddUITextDisplay(0, 0, pos, _sTeam[1], 0, "", 1, 0);
	pos.X = 52;
	pos.Y = 280;
	pos.W = 400;
	pos.H = 170;
	screen->AddUITextPageDisplay(23, pos, 0, 6, false);
	pos.X = 64;
	pos.Y = 368;
	pos.W = 68;
	pos.H = 20;
	screen->AddRolloverBitmapButton(0, 5, pos, "T_AA2_UI.menu.hud_menu_elements3", dCancelButton, 0, "");
	pos.X = 512;
	pos.Y = 368;
	pos.W = 68;
	pos.H = 20;
	screen->AddRolloverBitmapButton(0, 21, pos, "T_AA2_UI.menu.hud_menu_elements3", dMoreButton, 0, "");
	//string0 = cHUD.Level.GetLocalURL();
	pos0 = string0.Find("/");
	pos1 = string0.Find(".");
	pos2 = string0.Find("?");
	if (pos0 != -1)
	{
		string1 = string0.Mid(pos0 + 1, pos2 - pos0);
		string0 = string1;
		pos1 = string0.Find(".");
		pos2 = string0.Find("?");
	}
	if (pos1 == -1 || pos1 > pos2)
	{
		pos1 = pos2;
	}
	string2 = string0.Left(pos1);
	Control = screen->GetControl(22);
	Cast<UUITextPageDisplay>(Control)->SetTextFile(_sBriefingsDir + string2 + "_team0.txt");
	Control = screen->GetControl(23);
	Cast<UUITextPageDisplay>(Control)->SetTextFile(_sBriefingsDir + string2 + "_team1.txt");
}

void UGameMenuFrame::CreateTeamBriefScreen()
{
	UUIScreen* screen = nullptr;
	FPosition pos = {};
	FPosition dim = {};
	screen = GetScreen(2);
	dim.X = 0;
	dim.Y = 0;
	dim.W = 16;
	dim.H = 16;
	pos.X = 40;
	pos.Y = 112;
	pos.W = 16;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 16;
	dim.Y = 0;
	dim.W = 16;
	dim.H = 16;
	pos.X = 56;
	pos.Y = 112;
	pos.W = 528;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 32;
	dim.Y = 0;
	dim.W = 16;
	dim.H = 16;
	pos.X = 584;
	pos.Y = 112;
	pos.W = 16;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 0;
	dim.Y = 16;
	dim.W = 16;
	dim.H = 16;
	pos.X = 40;
	pos.Y = 128;
	pos.W = 16;
	pos.H = 192;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 16;
	dim.Y = 16;
	dim.W = 16;
	dim.H = 16;
	pos.X = 56;
	pos.Y = 128;
	pos.W = 528;
	pos.H = 192;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 32;
	dim.Y = 16;
	dim.W = 16;
	dim.H = 16;
	pos.X = 584;
	pos.Y = 128;
	pos.W = 16;
	pos.H = 192;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 0;
	dim.Y = 32;
	dim.W = 16;
	dim.H = 16;
	pos.X = 40;
	pos.Y = 320;
	pos.W = 16;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 16;
	dim.Y = 32;
	dim.W = 16;
	dim.H = 16;
	pos.X = 56;
	pos.Y = 320;
	pos.W = 528;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 32;
	dim.Y = 32;
	dim.W = 16;
	dim.H = 16;
	pos.X = 584;
	pos.Y = 320;
	pos.W = 16;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	pos.X = 128;
	pos.Y = 124;
	pos.W = 384;
	pos.H = 16;
	screen->AddUITextDisplay(20, 0, pos, "TEAM NAME", 0, "", 1, 0);
	pos.X = 52;
	pos.Y = 144;
	pos.W = 400;
	pos.H = 170;
	screen->AddUITextPageDisplay(21, pos, 0, 14, false);
	pos.X = 64;
	pos.Y = 344;
	pos.W = 68;
	pos.H = 20;
	screen->AddRolloverBitmapButton(0, 2, pos, "T_AA2_UI.menu.hud_menu_elements3", dCancelButton, 0, "");
	pos.X = 512;
	pos.Y = 344;
	pos.W = 68;
	pos.H = 20;
	screen->AddRolloverBitmapButton(0, 22, pos, "T_AA2_UI.menu.hud_menu_elements3", dSelectButton, 0, "");
}

void UGameMenuFrame::CreateLoginScreen()
{
	UUIScreen* screen = nullptr;
	FPosition pos = {};
	FPosition dim = {};
	screen = GetScreen(4);
	dim.X = 0;
	dim.Y = 0;
	dim.W = 16;
	dim.H = 16;
	pos.X = 64;
	pos.Y = 56;
	pos.W = 16;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 16;
	dim.Y = 0;
	dim.W = 16;
	dim.H = 16;
	pos.X = 80;
	pos.Y = 56;
	pos.W = 480;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 32;
	dim.Y = 0;
	dim.W = 16;
	dim.H = 16;
	pos.X = 560;
	pos.Y = 56;
	pos.W = 16;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 0;
	dim.Y = 16;
	dim.W = 16;
	dim.H = 16;
	pos.X = 64;
	pos.Y = 72;
	pos.W = 16;
	pos.H = 336;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 16;
	dim.Y = 16;
	dim.W = 16;
	dim.H = 16;
	pos.X = 80;
	pos.Y = 72;
	pos.W = 480;
	pos.H = 336;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 32;
	dim.Y = 16;
	dim.W = 16;
	dim.H = 16;
	pos.X = 560;
	pos.Y = 72;
	pos.W = 16;
	pos.H = 336;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 0;
	dim.Y = 32;
	dim.W = 16;
	dim.H = 16;
	pos.X = 64;
	pos.Y = 408;
	pos.W = 16;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 16;
	dim.Y = 32;
	dim.W = 16;
	dim.H = 16;
	pos.X = 80;
	pos.Y = 408;
	pos.W = 480;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 32;
	dim.Y = 32;
	dim.W = 16;
	dim.H = 16;
	pos.X = 560;
	pos.Y = 408;
	pos.W = 16;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	pos.X = 128;
	pos.Y = 64;
	pos.W = 384;
	pos.H = 16;
	screen->AddUITextDisplay(0, 0, pos, "SOLDIER LOGIN", 0, "", 2, 1);
	pos.X = 80;
	pos.Y = 146;
	pos.W = 112;
	pos.H = 20;
	screen->AddUITextDisplay(0, 0, pos, "SOLDIER NAME", 1, "", 2, 0);
	pos.Y += 50;
	screen->AddUITextDisplay(0, 0, pos, "PASSWORD", 1, "", 2, 0);
	dim.X = 0;
	dim.Y = 116;
	dim.W = 256;
	dim.H = 32;
	pos.X = 306;
	pos.Y = 136;
	pos.W = 256;
	pos.H = 32;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements", dim, 1);
	pos.X = 306;
	pos.Y += 50;
	pos.W = 256;
	pos.H = 32;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements", dim, 1);
	pos.X = 306;
	pos.Y = 136;
	pos.W = 256;
	pos.H = 32;
	screen->AddUIEditBox(30, 0, pos, "login", 0, "", 20);
	pos.X = 306;
	pos.Y += 50;
	pos.W = 256;
	pos.H = 32;
	screen->AddUIEditBox(31, 0, pos, "password", 1, "", 20);
	pos.X = 80;
	pos.W = 512;
	pos.Y += 128;
	screen->AddUITextDisplay(32, 0, pos, "WAITING", 0, "", 2, 1);
	pos.X = 80;
	pos.W = 512;
	pos.Y += 32;
	screen->AddUITextDisplay(33, 0, pos, "", 0, "", 2, 1);
	pos.X = 80;
	pos.Y = 392;
	pos.W = 68;
	pos.H = 20;
	screen->AddRolloverBitmapButton(0, 30, pos, "T_AA2_UI.menu.hud_menu_elements3", dMenuButton, 0, "");
	pos.X = 496;
	pos.Y = 392;
	pos.W = 68;
	pos.H = 20;
	screen->AddRolloverBitmapButton(34, 31, pos, "T_AA2_UI.menu.hud_menu_elements3", dLogInButton, 0, "");
	pos.X = 496;
	pos.Y = 392;
	pos.W = 68;
	pos.H = 20;
	screen->AddRolloverBitmapButton(35, 43, pos, "T_AA2_UI.menu.hud_menu_elements3", dContinueButton, 0, "");
	screen->AddUIKeyCapture(0, 0);
}

void UGameMenuFrame::CreateMissionSuccessScreen()
{
	UUIScreen* screen = nullptr;
	FPosition pos = {};
	FPosition dim = {};
	screen = GetScreen(5);
	dim.X = 0;
	dim.Y = 0;
	dim.W = 16;
	dim.H = 16;
	pos.X = 64;
	pos.Y = 56;
	pos.W = 16;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 16;
	dim.Y = 0;
	dim.W = 16;
	dim.H = 16;
	pos.X = 80;
	pos.Y = 56;
	pos.W = 480;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 32;
	dim.Y = 0;
	dim.W = 16;
	dim.H = 16;
	pos.X = 560;
	pos.Y = 56;
	pos.W = 16;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 0;
	dim.Y = 16;
	dim.W = 16;
	dim.H = 16;
	pos.X = 64;
	pos.Y = 72;
	pos.W = 16;
	pos.H = 336;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 16;
	dim.Y = 16;
	dim.W = 16;
	dim.H = 16;
	pos.X = 80;
	pos.Y = 72;
	pos.W = 480;
	pos.H = 336;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 32;
	dim.Y = 16;
	dim.W = 16;
	dim.H = 16;
	pos.X = 560;
	pos.Y = 72;
	pos.W = 16;
	pos.H = 336;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 0;
	dim.Y = 32;
	dim.W = 16;
	dim.H = 16;
	pos.X = 64;
	pos.Y = 408;
	pos.W = 16;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 16;
	dim.Y = 32;
	dim.W = 16;
	dim.H = 16;
	pos.X = 80;
	pos.Y = 408;
	pos.W = 480;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 32;
	dim.Y = 32;
	dim.W = 16;
	dim.H = 16;
	pos.X = 560;
	pos.Y = 408;
	pos.W = 16;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	pos.X = 128;
	pos.Y = 64;
	pos.W = 384;
	pos.H = 16;
	screen->AddUITextDisplay(0, 0, pos, "MISSION SUCCESS", 0, "", 2, 1);
	pos.X = 80;
	pos.Y = 96;
	pos.W = 64;
	pos.H = 64;
	screen->AddUIDynamicBitmap(40, pos, "", 0);
	pos.X = 208;
	pos.Y = 96;
	pos.W = 256;
	pos.H = 32;
	screen->AddUITextDisplay(41, 0, pos, "temp test string", 0, "", 2, 1);
	pos.X = 208;
	pos.Y = 116;
	pos.W = 256;
	pos.H = 32;
	screen->AddUITextDisplay(47, 0, pos, "", 0, "", 2, 1);
	pos.X = 80;
	pos.Y = 250;
	pos.W = 480;
	pos.H = 32;
	screen->AddUITextDisplay(45, 0, pos, "", 0, "", 2, 1);
	pos.X = 80;
	pos.Y = 282;
	pos.W = 480;
	pos.H = 32;
	screen->AddUITextDisplay(46, 0, pos, "", 0, "", 2, 1);
	pos.X = 80;
	pos.Y = 392;
	pos.W = 68;
	pos.H = 20;
	screen->AddRolloverBitmapButton(42, 60, pos, "T_AA2_UI.menu.hud_menu_elements3", dMenuButton, 0, "");
	pos.X = 276;
	pos.Y = 392;
	pos.W = 68;
	pos.H = 20;
	screen->AddRolloverBitmapButton(43, 61, pos, "T_AA2_UI.menu.hud_menu_elements3", dReplayButton, 0, "");
	pos.X = 496;
	pos.Y = 392;
	pos.W = 68;
	pos.H = 20;
	screen->AddRolloverBitmapButton(44, 42, pos, "T_AA2_UI.menu.hud_menu_elements3", dContinueButton, 0, "");
	screen->AddUIKeyCapture(0, 0);
}

void UGameMenuFrame::CreateMissionFailureScreen()
{
	UUIScreen* screen = nullptr;
	FPosition pos = {};
	FPosition dim = {};
	screen = GetScreen(6);
	dim.X = 0;
	dim.Y = 0;
	dim.W = 16;
	dim.H = 16;
	pos.X = 64;
	pos.Y = 56;
	pos.W = 16;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 16;
	dim.Y = 0;
	dim.W = 16;
	dim.H = 16;
	pos.X = 80;
	pos.Y = 56;
	pos.W = 480;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 32;
	dim.Y = 0;
	dim.W = 16;
	dim.H = 16;
	pos.X = 560;
	pos.Y = 56;
	pos.W = 16;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 0;
	dim.Y = 16;
	dim.W = 16;
	dim.H = 16;
	pos.X = 64;
	pos.Y = 72;
	pos.W = 16;
	pos.H = 336;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 16;
	dim.Y = 16;
	dim.W = 16;
	dim.H = 16;
	pos.X = 80;
	pos.Y = 72;
	pos.W = 480;
	pos.H = 336;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 32;
	dim.Y = 16;
	dim.W = 16;
	dim.H = 16;
	pos.X = 560;
	pos.Y = 72;
	pos.W = 16;
	pos.H = 336;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 0;
	dim.Y = 32;
	dim.W = 16;
	dim.H = 16;
	pos.X = 64;
	pos.Y = 408;
	pos.W = 16;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 16;
	dim.Y = 32;
	dim.W = 16;
	dim.H = 16;
	pos.X = 80;
	pos.Y = 408;
	pos.W = 480;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 32;
	dim.Y = 32;
	dim.W = 16;
	dim.H = 16;
	pos.X = 560;
	pos.Y = 408;
	pos.W = 16;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	pos.X = 128;
	pos.Y = 64;
	pos.W = 384;
	pos.H = 16;
	screen->AddUITextDisplay(0, 0, pos, "MISSION FAILURE", 0, "", 2, 1);
	pos.X = 208;
	pos.Y = 96;
	pos.W = 256;
	pos.H = 32;
	screen->AddUITextDisplay(41, 0, pos, "temp test string", 0, "", 2, 1);
	pos.X = 208;
	pos.Y = 116;
	pos.W = 256;
	pos.H = 32;
	screen->AddUITextDisplay(47, 0, pos, "", 0, "", 2, 1);
	pos.X = 80;
	pos.Y = 96;
	pos.W = 64;
	pos.H = 64;
	screen->AddUIDynamicBitmap(40, pos, "", 0);
	pos.X = 80;
	pos.Y = 392;
	pos.W = 68;
	pos.H = 20;
	screen->AddRolloverBitmapButton(0, 60, pos, "T_AA2_UI.menu.hud_menu_elements3", dMenuButton, 0, "");
	pos.X = 496;
	pos.Y = 392;
	pos.W = 68;
	pos.H = 20;
	screen->AddRolloverBitmapButton(0, 61, pos, "T_AA2_UI.menu.hud_menu_elements3", dReplayButton, 0, "");
	screen->AddUIKeyCapture(0, 0);
}

void UGameMenuFrame::CreateLandNavScoreScreen()
{
	UUIScreen* screen = nullptr;
	FPosition pos = {};
	FPosition dim = {};
	screen = GetScreen(8);
	dim.X = 0;
	dim.Y = 0;
	dim.W = 16;
	dim.H = 16;
	pos.X = 64;
	pos.Y = 56;
	pos.W = 16;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 16;
	dim.Y = 0;
	dim.W = 16;
	dim.H = 16;
	pos.X = 80;
	pos.Y = 56;
	pos.W = 480;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 32;
	dim.Y = 0;
	dim.W = 16;
	dim.H = 16;
	pos.X = 560;
	pos.Y = 56;
	pos.W = 16;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 0;
	dim.Y = 16;
	dim.W = 16;
	dim.H = 16;
	pos.X = 64;
	pos.Y = 72;
	pos.W = 16;
	pos.H = 336;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 16;
	dim.Y = 16;
	dim.W = 16;
	dim.H = 16;
	pos.X = 80;
	pos.Y = 72;
	pos.W = 480;
	pos.H = 336;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 32;
	dim.Y = 16;
	dim.W = 16;
	dim.H = 16;
	pos.X = 560;
	pos.Y = 72;
	pos.W = 16;
	pos.H = 336;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 0;
	dim.Y = 32;
	dim.W = 16;
	dim.H = 16;
	pos.X = 64;
	pos.Y = 408;
	pos.W = 16;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 16;
	dim.Y = 32;
	dim.W = 16;
	dim.H = 16;
	pos.X = 80;
	pos.Y = 408;
	pos.W = 480;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 32;
	dim.Y = 32;
	dim.W = 16;
	dim.H = 16;
	pos.X = 560;
	pos.Y = 408;
	pos.W = 16;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	pos.X = 128;
	pos.Y = 90;
	pos.W = 384;
	pos.H = 16;
	screen->AddUITextDisplay(1009, 0, pos, "MISSION SUCCESS", 0, "", 2, 1);
	pos.X = 80;
	pos.Y = 130;
	pos.W = 480;
	pos.H = 32;
	screen->AddUITextDisplay(1001, 0, pos, "ID_LNTextString01", 0, "", 2, 1);
	pos.X = 80;
	pos.Y = 150;
	pos.W = 480;
	pos.H = 32;
	screen->AddUITextDisplay(1002, 0, pos, "ID_LNTextString02", 0, "", 2, 1);
	pos.X = 80;
	pos.Y = 170;
	pos.W = 480;
	pos.H = 32;
	screen->AddUITextDisplay(1003, 0, pos, "ID_LNTextString03", 0, "", 2, 1);
	pos.X = 80;
	pos.Y = 190;
	pos.W = 480;
	pos.H = 32;
	screen->AddUITextDisplay(1004, 0, pos, "ID_LNTextString04", 0, "", 2, 1);
	pos.X = 80;
	pos.Y = 210;
	pos.W = 480;
	pos.H = 32;
	screen->AddUITextDisplay(1005, 0, pos, "ID_LNTextString05", 0, "", 2, 1);
	pos.X = 80;
	pos.Y = 230;
	pos.W = 480;
	pos.H = 32;
	screen->AddUITextDisplay(1006, 0, pos, "ID_LNTextString06", 0, "", 2, 1);
	pos.X = 80;
	pos.Y = 250;
	pos.W = 480;
	pos.H = 32;
	screen->AddUITextDisplay(1007, 0, pos, "ID_LNTextString07", 0, "", 2, 1);
	pos.X = 80;
	pos.Y = 290;
	pos.W = 480;
	pos.H = 32;
	screen->AddUITextDisplay(1008, 0, pos, "ID_LNTextString08", 0, "", 2, 1);
	pos.X = 496;
	pos.Y = 392;
	pos.W = 68;
	pos.H = 20;
	screen->AddRolloverBitmapButton(44, 62, pos, "T_AA2_UI.menu.hud_menu_elements3", dContinueButton, 0, "");
	screen->AddUIKeyCapture(0, 0);
}

void UGameMenuFrame::CreateServerAdminScreen()
{
	FPosition pos = {};
	FPosition dim = {};
	UUIScreen* screen = nullptr;
	screen = GetScreen(7);
	dim.X = 0;
	dim.Y = 0;
	dim.W = 16;
	dim.H = 16;
	pos.X = 78;
	pos.Y = 32;
	pos.W = 16;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 16;
	dim.Y = 0;
	dim.W = 16;
	dim.H = 16;
	pos.X = 94;
	pos.Y = 32;
	pos.W = 480;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 32;
	dim.Y = 0;
	dim.W = 16;
	dim.H = 16;
	pos.X = 574;
	pos.Y = 32;
	pos.W = 16;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 0;
	dim.Y = 16;
	dim.W = 16;
	dim.H = 16;
	pos.X = 78;
	pos.Y = 48;
	pos.W = 16;
	pos.H = 384;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 16;
	dim.Y = 16;
	dim.W = 16;
	dim.H = 16;
	pos.X = 94;
	pos.Y = 48;
	pos.W = 480;
	pos.H = 384;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 32;
	dim.Y = 16;
	dim.W = 16;
	dim.H = 16;
	pos.X = 574;
	pos.Y = 48;
	pos.W = 16;
	pos.H = 384;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 0;
	dim.Y = 32;
	dim.W = 16;
	dim.H = 16;
	pos.X = 78;
	pos.Y = 432;
	pos.W = 16;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 16;
	dim.Y = 32;
	dim.W = 16;
	dim.H = 16;
	pos.X = 94;
	pos.Y = 432;
	pos.W = 480;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	dim.X = 32;
	dim.Y = 32;
	dim.W = 16;
	dim.H = 16;
	pos.X = 574;
	pos.Y = 432;
	pos.W = 16;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 1);
	pos.X = 82;
	pos.Y = 42;
	pos.W = 508;
	pos.H = 16;
	screen->AddUITextDisplay(0, 0, pos, "SERVER ADMIN COMMAND POST", 0, "", 2, 0);
	pos.X = 82;
	pos.Y = 76;
	pos.W = 182;
	pos.H = 16;
	screen->AddUITextDisplay(0, 0, pos, "PLAYERS", 0, "", 2, 0);
	pos.X = 330;
	pos.Y = 76;
	pos.W = 256;
	pos.H = 16;
	screen->AddUITextDisplay(0, 0, pos, "SETTINGS", 0, "", 2, 0);
	pos.X = 82;
	pos.Y = 98;
	pos.W = 246;
	pos.H = 256;
	screen->AddUIPlayerList(50, pos, 0);
	pos.X = 330;
	pos.Y = 98;
	pos.W = 256;
	pos.H = 256;
	screen->AddUISettingsList(51, pos, 0);
	dim.X = 0;
	dim.Y = 116;
	dim.W = 256;
	dim.H = 32;
	pos.X = 264;
	pos.Y = 376;
	pos.W = 256;
	pos.H = 32;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements", dim, 1);
	pos.X = 264;
	pos.Y = 376;
	pos.W = 256;
	pos.H = 32;
	screen->AddUIEditBox(53, 0, pos, "", 0, "", 20);
	pos.X = 524;
	pos.Y = 378;
	pos.W = 10;
	pos.H = 10;
	screen->AddUITextButton(0, 50, pos, "SEND", 1, "");
	pos.X = 82;
	pos.Y = 355;
	pos.W = 68;
	pos.H = 20;
	screen->AddRolloverBitmapButton(0, 53, pos, "T_AA2_UI.menu.hud_menu_elements", dBackButton, 0, "");
	pos.X = 260;
	pos.Y = 355;
	pos.W = 68;
	pos.H = 20;
	screen->AddRolloverBitmapButton(0, 54, pos, "T_AA2_UI.menu.hud_menu_elements", dNextButton, 0, "");
	pos.X = 330;
	pos.Y = 355;
	pos.W = 68;
	pos.H = 20;
	screen->AddRolloverBitmapButton(0, 55, pos, "T_AA2_UI.menu.hud_menu_elements", dBackButton, 0, "");
	pos.X = 518;
	pos.Y = 355;
	pos.W = 68;
	pos.H = 20;
	screen->AddRolloverBitmapButton(0, 56, pos, "T_AA2_UI.menu.hud_menu_elements", dNextButton, 0, "");
	pos.X = 80;
	pos.Y = 378;
	pos.W = 10;
	pos.H = 10;
	screen->AddUITextButton(0, 51, pos, "KICK", 1, "");
	pos.X = 149;
	pos.Y = 378;
	pos.W = 10;
	pos.H = 10;
	screen->AddUITextButton(0, 52, pos, "BAN", 1, "");
	pos.X = 80;
	pos.Y = 424;
	pos.W = 500;
	pos.H = 20;
	screen->AddUIConsole(0, pos, 0);
}

void UGameMenuFrame::RefreshLoginScreen()
{
	UUIScreen* screen = nullptr;
	UUIControl* Control = nullptr;
	FString sTemp = "";
	screen = GetScreen(4);
	Control = screen->GetControl(30);
	sTemp = Cast<AHumanController>(Cast<AAGP_HUD>(cHUD)->PlayerOwner)->UserName;
	Cast<UUIEditBox>(Control)->SetLabel(sTemp);
	Control = screen->GetControl(31);
	sTemp = Cast<AHumanController>(Cast<AAGP_HUD>(cHUD)->PlayerOwner)->UserPassword;
	Cast<UUIEditBox>(Control)->SetLabel(sTemp);
	Control = screen->GetControl(32);
	Cast<UUITextDisplay>(Control)->SetLabel("Please log in to upload your results!");
	_iLoginStatus = 0;
	Control = screen->GetControl(33);
	Cast<UUITextDisplay>(Control)->SetLabel("");
	Control = screen->GetControl(34);
	Control->SetEnabled(true);
	Control = screen->GetControl(35);
	Control->SetEnabled(false);
}

void UGameMenuFrame::CancelLogin()
{
	ResetActiveScreen();
	Cast<AAGP_HUD>(cHUD)->CloseGameMenu();
	Cast<AAGP_HUD>(cHUD)->PlayerOwner->ConsoleCommand("start entry");
}

void UGameMenuFrame::SelectLogin()
{
	UUIScreen* screen = nullptr;
	UUIControl* Control = nullptr;
	if (_iLoginStatus == 2)
	{
		Notify(42);
	}
	else
	{
		if (_iLoginStatus != -99)
		{
			/*
			if (Cast<AAGP_HUD>(cHUD)->PlayerOwner.Level.Game.bBinaryAuthProtocol)
			{
			}
			*/
			screen = GetScreen(4);
			Control = screen->GetControl(30);
			//PrivateSet("humancontroller username " + Cast<UUIEditBox>(Control).GetLabel());
			Control = screen->GetControl(31);
			//PrivateSet("humancontroller userpassword " + Cast<UUIEditBox>(Control).GetLabel());
			Cast<AHumanController>(Cast<AAGP_HUD>(cHUD)->PlayerOwner)->MissionCompleted();
			_iLoginStatus = -99;
		}
	}
}

void UGameMenuFrame::SetLoginStatus(int32 iStatus, FString sStatus, FString sNavMsg)
{
	UUIScreen* screen = nullptr;
	UUIControl* Control = nullptr;
	_iLoginStatus = iStatus;
	screen = GetScreen(4);
	Control = screen->GetControl(32);
	Cast<UUITextDisplay>(Control)->SetLabel(sStatus);
	Control = screen->GetControl(33);
	Cast<UUITextDisplay>(Control)->SetLabel(sNavMsg);
	if (_iLoginStatus == 2)
	{
		Control = screen->GetControl(34);
		Control->SetEnabled(false);
		Control = screen->GetControl(35);
		Control->SetEnabled(true);
	}
}

void UGameMenuFrame::SetMissionSuccessScreen(FString Texture, FString Text, FString text2, int32 USize, int32 VSize, int32 RenderStyle, FName replayscene, bool bCheater)
{
	UUIScreen* screen = nullptr;
	UUIControl* Control = nullptr;
	screen = GetScreen(5);
	Control = screen->GetControl(40);
	Cast<UUIDynamicBitmap>(Control)->SetTexture(Texture, USize, VSize, RenderStyle);
	Control = screen->GetControl(41);
	Cast<UUITextDisplay>(Control)->SetLabel(Text);
	Control = screen->GetControl(47);
	Cast<UUITextDisplay>(Control)->SetLabel(text2);
	//nReplayScene = replayscene;
	if (bCheater)
	{
		Control = screen->GetControl(43);
		Control->SetEnabled(false);
		Control = screen->GetControl(44);
		Control->SetEnabled(false);
		Control = screen->GetControl(45);
		Cast<UUITextDisplay>(Control)->SetLabel("Cannot authorize due to use of player cheats.");
		Control = screen->GetControl(46);
		Cast<UUITextDisplay>(Control)->SetLabel("Click MENU to return to the main menu.");
	}
	else
	{
		Control = screen->GetControl(43);
		Control->SetEnabled(true);
		Control = screen->GetControl(44);
		Control->SetEnabled(true);
		Control = screen->GetControl(45);
		Cast<UUITextDisplay>(Control)->SetLabel("Do you wish to enter these results in your permanent");
		Control = screen->GetControl(46);
		Cast<UUITextDisplay>(Control)->SetLabel("personnel jacket?");
	}
}

void UGameMenuFrame::SetMissionFailureScreen(FString Texture, FString Text, FString text2, int32 USize, int32 VSize, int32 RenderStyle, FName replayscene)
{
	UUIScreen* screen = nullptr;
	UUIControl* Control = nullptr;
	screen = GetScreen(6);
	Control = screen->GetControl(40);
	Cast<UUIDynamicBitmap>(Control)->SetTexture(Texture, USize, VSize, RenderStyle);
	Control = screen->GetControl(41);
	Cast<UUITextDisplay>(Control)->SetLabel(Text);
	Control = screen->GetControl(47);
	Cast<UUITextDisplay>(Control)->SetLabel(text2);
	//nReplayScene = replayscene;
}

void UGameMenuFrame::SetLandNavScoreScreen(FString text1, FString text2, FString text3, FString text4, FString text5, FString text6, FString text7, FString text8, bool bCheater)
{
	UUIScreen* screen = nullptr;
	UUIControl* Control = nullptr;
	screen = GetScreen(8);
	if (bCheater)
	{
		Control = screen->GetControl(1009);
		Cast<UUITextDisplay>(Control)->SetLabel("CHEATS DETECTED");
	}
	Control = screen->GetControl(1001);
	Cast<UUITextDisplay>(Control)->SetLabel(text1);
	Control = screen->GetControl(1002);
	Cast<UUITextDisplay>(Control)->SetLabel(text2);
	Control = screen->GetControl(1003);
	Cast<UUITextDisplay>(Control)->SetLabel(text3);
	Control = screen->GetControl(1004);
	Cast<UUITextDisplay>(Control)->SetLabel(text4);
	Control = screen->GetControl(1005);
	Cast<UUITextDisplay>(Control)->SetLabel(text5);
	Control = screen->GetControl(1006);
	Cast<UUITextDisplay>(Control)->SetLabel(text6);
	Control = screen->GetControl(1007);
	Cast<UUITextDisplay>(Control)->SetLabel(text7);
	Control = screen->GetControl(1008);
	Cast<UUITextDisplay>(Control)->SetLabel(text8);
}

void UGameMenuFrame::ScaleControls(UCanvas* Canvas)
{
	UUIScreen* screen = nullptr;
	if ((_iOldSizeX == Canvas->SizeX) && (_iOldSizeY == Canvas->SizeY))
	{
		return;
	}
	fScaleX = float((Canvas->SizeX / 640));
	fScaleY = float((Canvas->SizeY / 480));
	if (_bAllowScaling)
	{
		offset.X = int((float(_Pos.X) * fScaleX));
		offset.Y = int((float(_Pos.Y) * fScaleY));
	}
	else
	{
		if ((Canvas->SizeX >= 640) && (Canvas->SizeY >= 480))
		{
			offset.X = ((Canvas->SizeX - 640) / 2);
			offset.Y = ((Canvas->SizeY - 480) / 2);
		}
	}
	for (screen = cScreenList; screen != nullptr; screen = screen->cNextScreen)
	{
		screen->ScaleControls(Canvas);
	}
	if (cMouse != nullptr)
	{
		cMouse->ScaleControl(Canvas);
	}
	if (_bAllowScaling)
	{
		_ScaledToolTipLoc.X = int(((float(_ToolTipLoc.X) * fScaleX) + float(offset.X)));
		_ScaledToolTipLoc.Y = int(((float(_ToolTipLoc.Y) * fScaleY) + float(offset.Y)));
	}
	else
	{
		_ScaledToolTipLoc.X = (_ToolTipLoc.X + offset.X);
		_ScaledToolTipLoc.Y = (_ToolTipLoc.Y + offset.Y);
	}
	_iOldSizeX = Canvas->SizeX;
	_iOldSizeY = Canvas->SizeY;
}

void UGameMenuFrame::PlayMenuSoundSpecific(USoundBase* Sound)
{
	if (Cast<AAGP_HUD>(cHUD)->PlayerOwner != nullptr && Sound != nullptr)
	{
		//Cast<AAGP_HUD>(cHUD)->PlayerOwner.PlayOwnedSound(Sound, , 1, , 1000000, , false);
	}
}

void UGameMenuFrame::QueryServerListReply(int32 Index, FString Section, FString Setting, FString Value, int32 Type)
{
	UUIScreen* screen = nullptr;
	UUIControl* Control = nullptr;
	screen = GetScreen(7);
	Control = screen->GetControl(51);
	Cast<UUISettingsList>(Control)->SetSetting(Index, Section, Setting, Value, Type);
}

void UGameMenuFrame::SetServerSettingReply(int32 Index, FString Value)
{
	UUIScreen* screen = nullptr;
	UUIControl* Control = nullptr;
	screen = GetScreen(7);
	Control = screen->GetControl(51);
	Cast<UUISettingsList>(Control)->UpdateSettingValue(Index, Value);
}

void UGameMenuFrame::SetSettingsValue(FString Value)
{
	UUIScreen* screen = nullptr;
	UUIControl* Control = nullptr;
	screen = GetScreen(7);
	Control = screen->GetControl(53);
	Cast<UUIEditBox>(Control)->SetLabel(Value);
}

void UGameMenuFrame::UpdateServerSetting()
{
	UUIScreen* screen = nullptr;
	UUIControl* Control = nullptr;
	int32 Index = 0;
	FString Value = "";
	screen = GetScreen(7);
	Control = screen->GetControl(53);
	Value = Cast<UUIEditBox>(Control)->GetLabel();
	Control = screen->GetControl(51);
	Index = Cast<UUISettingsList>(Control)->GetSelectedIndex();
	//cHUD->PlayerOwner->SetServerSetting(Index, Value);
}

void UGameMenuFrame::BanPlayer()
{
	UUIScreen* screen = nullptr;
	UUIControl* Control = nullptr;
	FString Value = "";
	screen = GetScreen(7);
	Control = screen->GetControl(50);
	Value = Cast<UUIPlayerList>(Control)->GetSelectedPlayer();
	Cast<AHumanController>(Cast<AAGP_HUD>(cHUD)->PlayerOwner)->Admin("kickban" + Value);
}

void UGameMenuFrame::KickPlayer()
{
	UUIScreen* screen = nullptr;
	UUIControl* Control = nullptr;
	FString Value = "";
	screen = GetScreen(7);
	Control = screen->GetControl(50);
	Value = Cast<UUIPlayerList>(Control)->GetSelectedPlayer();
	Cast<AHumanController>(Cast<AAGP_HUD>(cHUD)->PlayerOwner)->Admin("kick" + Value);
}

void UGameMenuFrame::PlayerList(int32 Direction)
{
	UUIScreen* screen = nullptr;
	UUIControl* Control = nullptr;
	screen = GetScreen(7);
	Control = screen->GetControl(50);
	if (Direction == -1)
	{
		Cast<UUIPlayerList>(Control)->PrevPage();
	}
	if (Direction == 1)
	{
		Cast<UUIPlayerList>(Control)->NextPage();
	}
}

void UGameMenuFrame::SettingList(int32 Direction)
{
	UUIScreen* screen = nullptr;
	UUISettingsList* Control = nullptr;
	screen = GetScreen(7);
	Control = Cast<UUISettingsList>(screen->GetControl(51));
	if (Direction == 1)
	{
		Control->NextPage();
	}
	else
	{
		Control->PrevPage();
	}
}
