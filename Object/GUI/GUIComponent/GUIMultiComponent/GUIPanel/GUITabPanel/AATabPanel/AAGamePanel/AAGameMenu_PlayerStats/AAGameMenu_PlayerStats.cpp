// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAGamePanel/AAGameMenu_PlayerStats/AAGameMenu_PlayerStats.h"

UAAGameMenu_PlayerStats::UAAGameMenu_PlayerStats()
{
	//i_Background = GUIImage'AGP_Interface.AAGameMenu_PlayerStats.MyBackground';
	//i_Info = GUIImage'AGP_Interface.AAGameMenu_PlayerStats.BG1';
	//l_Title = GUILabel'AGP_Interface.AAGameMenu_PlayerStats.TitleLabel';
	//l_ShotsFired = GUILabel'AGP_Interface.AAGameMenu_PlayerStats.ShotsFiredLabel';
	//l_ShotsHit = GUILabel'AGP_Interface.AAGameMenu_PlayerStats.ShotsHitLabel';
	//l_GrenadesThrown = GUILabel'AGP_Interface.AAGameMenu_PlayerStats.GrenadesThrownLabel';
	//l_TimeInfo = GUILabel'AGP_Interface.AAGameMenu_PlayerStats.TimePlayedInfoLabel';
	//l_RoundsInfo = GUILabel'AGP_Interface.AAGameMenu_PlayerStats.RoundInfoLabel';
	//l_ObjectiveInfo = GUILabel'AGP_Interface.AAGameMenu_PlayerStats.ObjectiveInfoLabel';
	//b_Hidden = GUIButton'AGP_Interface.AAGameMenu_PlayerStats.HiddenButton';
	//__OnPreDraw__Delegate = "AAGameMenu_PlayerStats.InternalOnPreDraw";
}

void UAAGameMenu_PlayerStats::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	InitComponent(MyController, MyOwner);
	l_Title.Caption = "Current Match Stats for " $ HumanController(PlayerOwner()).UserName;
	*/
}

void UAAGameMenu_PlayerStats::InitializeStatRetrieval()
{
	/*
	l_ShotsFired.Caption = "Shots Fired -  ";
	l_ShotsHit.Caption = "Shots Hit - ";
	l_GrenadesThrown.Caption = "Grenades - ";
	l_TimeInfo.Caption = "Time Info - ";
	l_RoundsInfo.Caption = "Round Info - ";
	l_ObjectiveInfo.Caption = "Objective Info - ";
	HumanController(PlayerOwner()).guipStats = guipOwner;
	HumanController(PlayerOwner()).ServerRequestStat("CapturedObjectives");
	HumanController(PlayerOwner()).ServerRequestStat("CapturedObjectiveDeaths");
	HumanController(PlayerOwner()).ServerRequestStat("TimePlayedSeconds");
	HumanController(PlayerOwner()).ServerRequestStat("TimeAliveSeconds");
	HumanController(PlayerOwner()).ServerRequestStat("RoundsStarted");
	HumanController(PlayerOwner()).ServerRequestStat("RoundsSurvivedWon");
	HumanController(PlayerOwner()).ServerRequestStat("RoundsSurvivedLost");
	HumanController(PlayerOwner()).ServerRequestStat("ShotsFiredMachineGun");
	HumanController(PlayerOwner()).ServerRequestStat("ShotsFiredAssaultRifle");
	HumanController(PlayerOwner()).ServerRequestStat("ShotsFiredPistol");
	HumanController(PlayerOwner()).ServerRequestStat("ShotsFiredGrenade");
	HumanController(PlayerOwner()).ServerRequestStat("ShotsFiredSniper");
	HumanController(PlayerOwner()).ServerRequestStat("ShotsFiredRocket");
	HumanController(PlayerOwner()).ServerRequestStat("ShotsHitMachineGun");
	HumanController(PlayerOwner()).ServerRequestStat("ShotsHitAssaultRifle");
	HumanController(PlayerOwner()).ServerRequestStat("ShotsHitPistol");
	HumanController(PlayerOwner()).ServerRequestStat("ShotsHitGrenade");
	HumanController(PlayerOwner()).ServerRequestStat("ShotsHitSniper");
	HumanController(PlayerOwner()).ServerRequestStat("ShotsHitRocket");
	*/
}

void UAAGameMenu_PlayerStats::ShowPanel(bool bShow)
{
	/*
	ShowPanel(bShow);
	InitializeStatRetrieval();
	*/
}

bool UAAGameMenu_PlayerStats::InternalOnPreDraw(UCanvas* C)
{
	/*
	local GameReplicationInfo GRI;
	if (PlayerOwner() != None)
	{
		GRI = PlayerOwner().GameReplicationInfo;
	}
	if (GRI == None)
	{
		return false;
	}
	*/
	return true;
}

bool UAAGameMenu_PlayerStats::InternalOnClick(UGUIComponent* Sender)
{
	return true;
}

void UAAGameMenu_PlayerStats::NotifyStatsPage(FString sStatRequested, FString sValue)
{
	/*
	Switch(sStatRequested)
	{
			case "CapturedObjectives":
				l_ObjectiveInfo.Caption = l_ObjectiveInfo.Caption $ " Captured: " $ sValue $ "   ";
				break;
			case "CapturedObjectiveDeaths":
				l_ObjectiveInfo.Caption = l_ObjectiveInfo.Caption $ " Deaths While Capturing: " $ sValue $ "   ";
				break;
			case "Healed":
				break;
			case "UsedMedic":
				break;
			case "MedPacksUsed":
				break;
			case "TimePlayedSeconds":
				l_TimeInfo.Caption = l_TimeInfo.Caption $ "Played: " $ sValue $ "   ";
				break;
			case "TimeAliveSeconds":
				l_TimeInfo.Caption = l_TimeInfo.Caption $ "Alive: " $ sValue $ "   ";
				break;
			case "RoundsStarted":
				l_RoundsInfo.Caption = l_RoundsInfo.Caption $ "Started: " $ sValue $ "   ";
				break;
			case "RoundsSurvivedWon":
				l_RoundsInfo.Caption = l_RoundsInfo.Caption $ "Survived & Won: " $ sValue $ "   ";
				break;
			case "RoundsSurvivedLost":
				l_RoundsInfo.Caption = l_RoundsInfo.Caption $ "Survived & Lost: " $ sValue $ "   ";
				break;
			case "ShotsFiredMachineGun":
				l_ShotsFired.Caption = l_ShotsFired.Caption $ "SAW/RPK: " $ sValue $ "   ";
				break;
			case "ShotsFiredAssaultRifle":
				l_ShotsFired.Caption = l_ShotsFired.Caption $ "M4/M16/AK: " $ sValue $ "   ";
				break;
			case "ShotsFiredPistol":
				l_ShotsFired.Caption = l_ShotsFired.Caption $ "Pistol: " $ sValue $ "   ";
				break;
			case "ShotsFiredGrenade":
				l_GrenadesThrown.Caption = l_GrenadesThrown.Caption $ "Thrown: " $ sValue $ "   ";
				break;
			case "ShotsFiredSniper":
				l_ShotsFired.Caption = l_ShotsFired.Caption $ "Adv. Marksman: " $ sValue $ "   ";
				break;
			case "ShotsFiredRocket":
				l_ShotsFired.Caption = l_ShotsFired.Caption $ "AT4/Jav/RPG: " $ sValue $ "   ";
				break;
			case "ShotsHitMachineGun":
				if (sValue == "-1")
				{
					l_ShotsHit.Caption = l_ShotsHit.Caption $ "Server rules prohibit showing hit statistics during match";
				}
				else
				{
					l_ShotsHit.Caption = l_ShotsHit.Caption $ "SAW/RPK: " $ sValue $ "   ";
				}
				GOTO JL0721;
			case "ShotsHitAssaultRifle":
				if (sValue != "-1")
				{
					l_ShotsHit.Caption = l_ShotsHit.Caption $ "M4/M16/AK: " $ sValue $ "   ";
				}
				GOTO JL0721;
			case "ShotsHitPistol":
				if (sValue != "-1")
				{
					l_ShotsHit.Caption = l_ShotsHit.Caption $ "Pistol: " $ sValue $ "   ";
				}
				GOTO JL0721;
			case "ShotsHitGrenade":
				if (sValue != "-1")
				{
					l_GrenadesThrown.Caption = l_GrenadesThrown.Caption $ "Hit: " $ sValue $ "   ";
				}
				GOTO JL0721;
			case "ShotsHitSniper":
				if (sValue != "-1")
				{
					l_ShotsHit.Caption = l_ShotsHit.Caption $ "Adv. Marksman: " $ sValue $ "   ";
				}
				GOTO JL0721;
			case "ShotsHitRocket":
				if (sValue != "-1")
				{
					l_ShotsHit.Caption = l_ShotsHit.Caption $ "AT4/Jav/RPG: " $ sValue $ "   ";
				}
				GOTO JL0721;
			default:
			JL0721:
	}
	*/
}