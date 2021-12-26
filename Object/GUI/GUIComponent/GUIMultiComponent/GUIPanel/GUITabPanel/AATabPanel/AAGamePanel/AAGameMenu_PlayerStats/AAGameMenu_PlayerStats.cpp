// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAGamePanel/AAGameMenu_PlayerStats/AAGameMenu_PlayerStats.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"

UAAGameMenu_PlayerStats::UAAGameMenu_PlayerStats()
{
	UGUIButton* HiddenButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	HiddenButton->WinTop = 0.03;
	HiddenButton->WinLeft = 0.96;
	HiddenButton->WinWidth = 0;
	HiddenButton->WinHeight = 0;
	//HiddenButton->OnClick=AAGameMenu_PlayerStats.InternalOnClick;
	//HiddenButton->OnKeyEvent=HiddenButton.InternalOnKeyEvent;
	UGUIImage* MyBackground = NewObject<UGUIImage>(UGUIImage::StaticClass());
	MyBackground->Image = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/backgroundfil_Mat.backgroundfil_Mat'"), NULL, LOAD_None, NULL);
	MyBackground->ImageStyle = EImgStyle::ISTY_Stretched;
	MyBackground->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	MyBackground->WinTop = 0.01;
	MyBackground->WinLeft = 0.01;
	MyBackground->WinWidth = 0.98;
	MyBackground->WinHeight = 0.89;
	MyBackground->RenderWeight = 0;
	MyBackground->bBoundToParent = true;
	MyBackground->bScaleToParent = true;
	UGUIImage* BG1 = NewObject<UGUIImage>(UGUIImage::StaticClass());
	BG1->Image = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/field_translucen_Mat.field_translucen_Mat'"), NULL, LOAD_None, NULL);
	BG1->ImageStyle = EImgStyle::ISTY_Stretched;
	BG1->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	BG1->WinTop = 0.02;
	BG1->WinLeft = 0.02;
	BG1->WinWidth = 0.96;
	BG1->WinHeight = 0.87;
	UGUILabel* TitleLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	TitleLabel->Caption = "Current Match Player Statistics";
	TitleLabel->TextAlign = ETextAlign::TXTA_Center;
	TitleLabel->TextColor = FColor(52, 180, 217, 255);
	TitleLabel->TextFont = "AAFontMedium";
	TitleLabel->WinTop = 0.1;
	TitleLabel->WinLeft = 0.1;
	TitleLabel->WinWidth = 0.8;
	UGUILabel* ShotsFiredLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	ShotsFiredLabel->TextColor = FColor(255, 255, 255, 255);
	ShotsFiredLabel->TextFont = "AAFontMedium";
	ShotsFiredLabel->WinTop = 0.15;
	ShotsFiredLabel->WinLeft = 0.1;
	ShotsFiredLabel->WinWidth = 0.8;
	UGUILabel* ShotsHitLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	ShotsHitLabel->TextColor = FColor(255, 255, 255, 255);
	ShotsHitLabel->TextFont = "AAFontMedium";
	ShotsHitLabel->WinTop = 0.2;
	ShotsHitLabel->WinLeft = 0.1;
	ShotsHitLabel->WinWidth = 0.8;
	UGUILabel* GrenadesThrownLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	GrenadesThrownLabel->TextColor = FColor(255, 255, 255, 255);
	GrenadesThrownLabel->TextFont = "AAFontMedium";
	GrenadesThrownLabel->WinTop = 0.25;
	GrenadesThrownLabel->WinLeft = 0.1;
	GrenadesThrownLabel->WinWidth = 0.8;
	UGUILabel* TimePlayedInfoLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	TimePlayedInfoLabel->TextColor = FColor(255, 255, 255, 255);
	TimePlayedInfoLabel->TextFont = "AAFontMedium";
	TimePlayedInfoLabel->WinTop = 0.3;
	TimePlayedInfoLabel->WinLeft = 0.1;
	TimePlayedInfoLabel->WinWidth = 0.8;
	UGUILabel* RoundInfoLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	RoundInfoLabel->TextColor = FColor(255, 255, 255, 255);
	RoundInfoLabel->TextFont = "AAFontMedium";
	RoundInfoLabel->WinTop = 0.35;
	RoundInfoLabel->WinLeft = 0.1;
	RoundInfoLabel->WinWidth = 0.8;
	UGUILabel* ObjectiveInfoLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	ObjectiveInfoLabel->TextColor = FColor(255, 255, 255, 255);
	ObjectiveInfoLabel->TextFont = "AAFontMedium";
	ObjectiveInfoLabel->WinTop = 0.4;
	ObjectiveInfoLabel->WinLeft = 0.1;
	ObjectiveInfoLabel->WinWidth = 0.8;
	i_Background = MyBackground;
	i_Info = BG1;
	l_Title = TitleLabel;
	l_ShotsFired = ShotsFiredLabel;
	l_ShotsHit = ShotsHitLabel;
	l_GrenadesThrown = GrenadesThrownLabel;
	l_TimeInfo = TimePlayedInfoLabel;
	l_RoundsInfo = RoundInfoLabel;
	l_ObjectiveInfo = ObjectiveInfoLabel;
	b_Hidden = HiddenButton;

	//OnPreDraw = AAGameMenu_PlayerStats.InternalOnPreDraw;
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
	if (GRI == nullptr)
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