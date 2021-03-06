// All the original content belonged to the US Army

#include "AA29/Object/UIBase/UIFrame/MainMenuFrame/MainMenuFrame.h"
#include "AA29/Object/Actor/HUD/AGP_HUD/AGP_HUD.h"
#include "AA29/Object/UIBase/UIControl/UIMouse/UIMouse.h"
#include "AA29/Object/UIBase/UIControl/UISoundControl/UINavControl/UIKeymap/UIKeymap.h"
#include "AA29/Object/UIBase/UIScreen/UIscreen.h"
#include "AA29/Object/UIBase/UIControl/UISoundControl/UINavControl/UIEditBox/UIEditBox.h"
#include "AA29/Object/UIBase/UIControl/UISoundControl/UINavControl/UIServerListDisplay/UIServerListDisplay.h"
#include "AA29/Object/UIBase/UIControl/UITextDisplay/UITextDisplay.h"
#include "AA29/Object/UIBase/UIControl/UISoundControl/UINavControl/UISliderH/UISliderH.h"
#include "AA29/Object/UIBase/UIControl/UIControl.h"
#include "AA29/Object/UIBase/UIFrame/UIFrame.h"
#include "AA29/Object/UIBase/UIControl/UIImageListDisplay/UIImageListDisplay.h"
#include "AA29/Object/UIBase/UIControl/UISoundControl/UINavControl/UISlider/UISlider.h"
#include "AA29/Object/UIBase/UIControl/UIScrollingCredits/UIScrollingCredits.h"
#include "AA29/Object/UIBase/UIControl/UISoundControl/UINavControl/UIVideoMode/UIVideoMode.h"
#include "AA29/Object/UIBase/UIControl/UIHUDBaseDisplay/HUDMenuCrosshair/HUDMenuCrosshair.h"
#include "AA29/Object/UIBase/UIControl/UISoundControl/UINavControl/UICheckbox/UICheckbox.h"
#include "AA29/Object/UIBase/UIControl/UISoundControl/UINavControl/UICheckboxFn/UICheckboxFn.h"
#include "AA29/Object/UIBase/UIControl/UISoundControl/UINavControl/UICheckboxB/UICheckboxB.h"
#include "AA29/Object/UIBase/UIControl/UISoundControl/UINavControl/UICheckboxC/UICheckboxC.h"
#include "AA29/Object/UIBase/UIControl/UISoundControl/UINavControl/UISliderSeg/UISliderSeg.h"
#include "AA29/Object/UIBase/UIControl/UISoundControl/UINavControl/UITextButton/UITextButton.h"
#include "AA29/Object/UIBase/UIControl/UITextDisplay/UITextDisplayColor/UITextDisplayColor.h"
#include "AA29/Object/UIBase/UIControl/UITextPageDisplay/UITextPageDisplay.h"
#include "AA29/Object/Actor/Info/InternetInfo/InternetLink/UdpLink/UdpBeacon/ClientBeaconReceiver/ClientBeaconReceiver.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/Object/Actor/ServerBrowserBase/ServerBrowserBase.h"
#include "AA29/Object/Actor/HUD/AA2_HUD.h"
#include "Engine/Canvas.h"

UMainMenuFrame::UMainMenuFrame()
{
	_bToolTipActive = false;
	_Pos = FPosition({ 0, 0, 1280, 1024 });
	_bAllowScaling = false;
}

void UMainMenuFrame::Destroyed()
{
	Super::Destroyed();
	_tBackground = nullptr;
}

void UMainMenuFrame::Notify(int32 pUIEvent)
{
	UUIScreen* screen = nullptr;
	UUIScreen* screen2 = nullptr;
	UUIControl* Control = nullptr;
	UUIControl* control2 = nullptr;
	FString sTitle = "";
	FString sText = "";
	int32 iNumPages = 0;
	int32 iTour = 0;
	int32 iMission = 0;

	if (cHUD != nullptr)
	{
		if (cHUD->IsA(AAGP_HUD::StaticClass()))
		{
			if (pUIEvent == 21)
			{
				Cast<AAGP_HUD>(cHUD)->PlayerOwner->ConsoleCommand("togglefullscreen");
				return;
			}
			if (pUIEvent == 22)
			{
				MessageBox("Are you sure?", 8, "YES", "NO");
				return;
			}
			if (pUIEvent == 7)
			{
				SetActiveScreen(0);
				SetTitleScreen(700);
				SetSubScreen(800);
				return;
			}
			if (pUIEvent == 2)
			{
				SetActiveScreen(2);
				return;
			}
			if (pUIEvent == 200)
			{
				CheckFullScreen();
				Cast<AAGP_HUD>(cHUD)->PlayerOwner->ConsoleCommand("start http://www.americasarmy.com/redir.php?r=100");
				return;
			}
			if (pUIEvent == 201)
			{
				RefreshLoginScreen();
				SetActiveScreen(201);
				return;
			}
			if (pUIEvent == 202)
			{
				//Assert(false);
				UE_LOG(LogTemp, Log, TEXT("SJJ: UIE_ServerBrowser"));
				SetServerBrowserFilter("");
				RefreshServerBrowser();
				SetActiveScreen(202);
				return;
			}
			if (pUIEvent == 206)
			{
				//Assert(false);
				SetServerBrowserFilter("");
				RefreshServerBrowser();
				SetActiveScreen(202);
				return;
			}
			if (pUIEvent == 204)
			{
				CheckFullScreen();
				Cast<AAGP_HUD>(cHUD)->PlayerOwner->ConsoleCommand("start http://www.americasarmy.com/redir.php?r=5");
				Cast<AAGP_HUD>(cHUD)->PlayerOwner->ConsoleCommand("quit");
				return;
			}
			if (pUIEvent == 851)
			{
				CheckFullScreen();
				Cast<AAGP_HUD>(cHUD)->PlayerOwner->ConsoleCommand("start http://www.americasarmy.com/redir.php?r=109");
				return;
			}
			if (pUIEvent == 852)
			{
				CheckFullScreen();
				Cast<AAGP_HUD>(cHUD)->PlayerOwner->ConsoleCommand("start http://www.americasarmy.com/redir.php?r=1");
				return;
			}
			if (pUIEvent == 17)
			{
				RefreshParentalControlScreen();
				SetActiveScreen(7);
				return;
			}
			if (pUIEvent == 203)
			{
				UpdateLoginInfo();
				SetActiveScreen(2);
				return;
			}
			if (pUIEvent == 4)
			{
				SetActiveScreen(4);
				return;
			}
			if (pUIEvent == 1)
			{
				SetActiveScreen(1);
				return;
			}
			if (pUIEvent == 3)
			{
				ResetActiveScreen();
				Cast<AAGP_HUD>(cHUD)->CloseMainMenu();
				return;
			}
			if (pUIEvent == 14)
			{
				ResetActiveScreen();
				Cast<AAGP_HUD>(cHUD)->CloseMainMenu();
				return;
			}
			if (pUIEvent == 16)
			{
				Cast<AAGP_HUD>(cHUD)->PlayerOwner->ConsoleCommand("disconnect");
				Cast<AAGP_HUD>(cHUD)->PlayerOwner->ConsoleCommand("start entry");
				return;
			}
			if (pUIEvent == 325)
			{
				ParentAccept();
				return;
			}
			if (pUIEvent == 5)
			{
				SetActiveScreen(5);
				return;
			}
			if (pUIEvent == 15)
			{
				SetActiveScreen(6);
				return;
			}
			if (pUIEvent == 9)
			{
				CheckFullScreen();
				Cast<AAGP_HUD>(cHUD)->PlayerOwner->ConsoleCommand("start http://www.americasarmy.com/redir.php?r=2");
				return;
			}
			if (pUIEvent == 11)
			{
				CheckFullScreen();
				Cast<AAGP_HUD>(cHUD)->PlayerOwner->ConsoleCommand("start http://www.americasarmy.com/redir.php?r=0");
				return;
			}
			if (pUIEvent == 10)
			{
				CheckFullScreen();
				Cast<AAGP_HUD>(cHUD)->PlayerOwner->ConsoleCommand("start http://www.americasarmy.com/redir.php?r=0");
				return;
			}
			if (pUIEvent == 13)
			{
				CheckFullScreen();
				Cast<AAGP_HUD>(cHUD)->PlayerOwner->ConsoleCommand("start http://www.americasarmy.com/redir.php?r=0");
				return;
			}
			if (pUIEvent == 6)
			{
				MessageBox("Are you sure?", 8, "YES", "NO");
				return;
			}
			if (pUIEvent == 8)
			{
				ResetActiveScreen();
				Cast<AAGP_HUD>(cHUD)->CloseMainMenu();
				Cast<AAGP_HUD>(cHUD)->PlayerOwner->ConsoleCommand("disconnect");
				Cast<AAGP_HUD>(cHUD)->PlayerOwner->ConsoleCommand("quit");
				return;
			}
			if (pUIEvent == 400)
			{
				SetActiveScreen(400);
				return;
			}
			if (pUIEvent == 410)
			{
				RefreshViewSettings();
				SetActiveScreen(410);
				return;
			}
			if (pUIEvent == 411)
			{
				RefreshMovementSettings();
				SetActiveScreen(411);
				return;
			}
			if (pUIEvent == 412)
			{
				RefreshCombatSettings();
				SetActiveScreen(412);
				return;
			}
			if (pUIEvent == 413)
			{
				SetActiveScreen(413);
				return;
			}
			if (pUIEvent == 414)
			{
				RefreshControlsMisc();
				SetActiveScreen(414);
				return;
			}
			if (pUIEvent == 420)
			{
				RefreshSliders();
				RefreshVideoSettings();
				SetActiveScreen(420);
				return;
			}
			if (pUIEvent == 421)
			{
				RefreshVideoAdvancedSettings();
				SetActiveScreen(421);
				return;
			}
			if (pUIEvent == 422)
			{
				RefreshVideoDecalsSettings();
				SetActiveScreen(422);
				return;
			}
			if (pUIEvent == 430)
			{
				RefreshSliders();
				RefreshAudioSettings();
				SetActiveScreen(430);
				return;
			}
			if (pUIEvent == 440)
			{
				RefreshHUDSettings();
				SetActiveScreen(440);
				return;
			}
			if (pUIEvent == 450)
			{
				RefreshWeaponModSettings();
				SetActiveScreen(450);
			}
			if (pUIEvent == 451)
			{
				RefreshWeaponModSettings();
			}
			if (pUIEvent == 1001)
			{
				CloseMessageBox();
				return;
			}
			if (pUIEvent == 1000)
			{
				Notify(iMsgBoxYesOverride);
				return;
			}
			if (pUIEvent == 104)
			{
				screen = GetScreen(1);
				Control = screen->GetControl(102);
				Cast<UUIImageListDisplay>(Control)->PrevImage();
				Cast<UUIImageListDisplay>(screen->GetControl(103))->SetData(Cast<UUIImageListDisplay>(Control)->GetIndex());
				RefreshTourMissionDisplays();
				return;
			}
			if (pUIEvent == 105)
			{
				screen = GetScreen(1);
				Control = screen->GetControl(102);
				Cast<UUIImageListDisplay>(Control)->NextImage();
				Cast<UUIImageListDisplay>(screen->GetControl(103))->SetData(Cast<UUIImageListDisplay>(Control)->GetIndex());
				RefreshTourMissionDisplays();
				return;
			}
			if (pUIEvent == 106)
			{
				screen = GetScreen(1);
				Control = screen->GetControl(103);
				Cast<UUIImageListDisplay>(Control)->PrevImage();
				RefreshTourMissionDisplays();
				return;
			}
			if (pUIEvent == 107)
			{
				screen = GetScreen(1);
				Control = screen->GetControl(103);
				Cast<UUIImageListDisplay>(Control)->NextImage();
				RefreshTourMissionDisplays();
				return;
			}
			if (pUIEvent == 110)
			{
				screen = GetScreen(1);
				Control = screen->GetControl(102);
				screen2 = GetScreen(101);
				control2 = screen2->GetControl(110);
				iTour = Cast<UUIImageListDisplay>(Control)->GetIndex();
				sText = Cast<UUIImageListDisplay>(Control)->GetData(0);
				sTitle = Cast<UUIImageListDisplay>(Control)->GetData(1);
				Cast<UUITextPageDisplay>(control2)->SetTitle(sTitle);
				iNumPages = Cast<UUITextPageDisplay>(control2)->SetTextFile(sBriefingsDir + sText + ".txt");
				if (iNumPages > 1)
				{
					control2 = screen2->GetControl(111);
					control2->SetEnabled(true);
					control2 = screen2->GetControl(112);
					control2->SetEnabled(true);
				}
				else
				{
					control2 = screen2->GetControl(111);
					control2->SetEnabled(false);
					control2 = screen2->GetControl(112);
					control2->SetEnabled(false);
				}
				if (sText == "")
				{
					SetNoTourText(true);
				}
				else
				{
					SetNoTourText(false);
				}
				screen2 = GetScreen(102);
				control2 = screen2->GetControl(120);
				sText = Cast<UUIImageListDisplay>(Control)->GetData(2);
				sTitle = Cast<UUIImageListDisplay>(Control)->GetData(3);
				Cast<UUITextPageDisplay>(control2)->SetTitle(sTitle);
				iNumPages = Cast<UUITextPageDisplay>(control2)->SetTextFile(sBriefingsDir + sText + ".txt");
				if (iNumPages > 1)
				{
					control2 = screen2->GetControl(121);
					control2->SetEnabled(true);
					control2 = screen2->GetControl(122);
					control2->SetEnabled(true);
				}
				else
				{
					Control = screen2->GetControl(121);
					Control->SetEnabled(false);
					Control = screen2->GetControl(122);
					Control->SetEnabled(false);
				}
				Control = screen->GetControl(103);
				iMission = Cast<UUIImageListDisplay>(Control)->GetIndex();
				sText = Cast<UUIImageListDisplay>(Control)->GetData(0);
				sMission = sText;
				sTitle = Cast<UUIImageListDisplay>(Control)->GetData(1);
				sTeam0 = Cast<UUIImageListDisplay>(Control)->GetData(2);
				sTeam1 = Cast<UUIImageListDisplay>(Control)->GetData(3);
				if (sTeam0 == "")
				{
					bMissionMP = false;
					screen2 = GetScreen(103);
					control2 = screen2->GetControl(130);
					Cast<UUITextPageDisplay>(control2)->SetTitle(sTitle);
					iNumPages = Cast<UUITextPageDisplay>(control2)->SetTextFile(sBriefingsDir + sText + ".txt");
					if (iNumPages > 1)
					{
						control2 = screen2->GetControl(131);
						control2->SetEnabled(true);
						control2 = screen2->GetControl(132);
						control2->SetEnabled(true);
					}
					else
					{
						control2 = screen2->GetControl(131);
						control2->SetEnabled(false);
						control2 = screen2->GetControl(132);
						control2->SetEnabled(false);
					}
				}
				else
				{
					bMissionMP = true;
					screen2 = GetScreen(104);
					control2 = screen2->GetControl(150);
					Cast<UUITextPageDisplay>(control2)->SetTextFile(sBriefingsDir + sText + "_team0.txt");
					Cast<UUITextPageDisplay>(control2)->SetTitle(sTeam0);
					control2 = screen2->GetControl(160);
					Cast<UUITextPageDisplay>(control2)->SetTextFile(sBriefingsDir + sText + "_team1.txt");
					Cast<UUITextPageDisplay>(control2)->SetTitle(sTeam1);
				}
				/*
				if (cHUD->Level->CanPlayerPlayMissionPrivate(cHUD->PlayerOwner, iTour, iMission))
				{
					if (_bNoTourText)
					{
						SetActiveScreen(102);
					}
					else
					{
						SetActiveScreen(101);
					}
					return;
				}
				else
				{
					SetActiveScreen(101);
					return;
				}
				*/
			}

			if (pUIEvent == 113)
			{
				if (_bNoTourText)
				{
					SetActiveScreen(1);
				}
				else
				{
					SetActiveScreen(101);
				}
				return;
			}
			if (pUIEvent == 111)
			{
				Cast<UUITextPageDisplay>(GetScreen(101)->GetControl(110))->PrevPage();
				return;
			}
			if (pUIEvent == 112)
			{
				Cast<UUITextPageDisplay>(GetScreen(101)->GetControl(110))->NextPage();
				return;
			}
			if (pUIEvent == 120)
			{
				SetActiveScreen(102);
				return;
			}
			if (pUIEvent == 121)
			{
				Cast<UUITextPageDisplay>(GetScreen(102)->GetControl(120))->PrevPage();
				return;
			}
			if (pUIEvent == 122)
			{
				Cast<UUITextPageDisplay>(GetScreen(102)->GetControl(120))->NextPage();
				return;
			}
			if (pUIEvent == 130)
			{
				if (bMissionMP)
				{
					SetActiveScreen(104);
				}
				else
				{
					SetActiveScreen(103);
				}
				return;
			}
			if (pUIEvent == 131)
			{
				Cast<UUITextPageDisplay>(GetScreen(103)->GetControl(130))->PrevPage();
				return;
			}
			if (pUIEvent == 132)
			{
				Cast<UUITextPageDisplay>(GetScreen(103)->GetControl(130))->NextPage();
				return;
			}
			if (pUIEvent == 140)
			{
				if (bMissionMP)
				{
					SetServerBrowserFilter("(mapname = '" + sMission + "')");
					SetActiveScreen(202);
				}
				else
				{
					SetMouseBusy(true);
					if (IsMouseBusyDrawing())
					{
						//Cast<AAGP_HUD>(cHUD)->ConsoleCommand("start " + sMission);
					}
					else
					{
						DelayEvent(pUIEvent);
					}
					return;
				}
			}
			if (pUIEvent == 550)
			{
				SetMouseBusy(true);
				if (IsMouseBusyDrawing())
				{
					SetDefaultKeyMaps();
					SetMouseBusy(false);
				}
				else
				{
					DelayEvent(pUIEvent);
				}
				return;
			}
			if (pUIEvent == 551)
			{
				SetMouseBusy(true);
				if (IsMouseBusyDrawing())
				{
					SetDefaultViewKeys();
					SetMouseBusy(false);
				}
				else
				{
					DelayEvent(pUIEvent);
				}
				return;
			}
			if (pUIEvent == 552)
			{
				SetMouseBusy(true);
				if (IsMouseBusyDrawing())
				{
					SetDefaultMovementKeys();
					SetMouseBusy(false);
				}
				else
				{
					DelayEvent(pUIEvent);
				}
				return;
			}
			if (pUIEvent == 553)
			{
				SetMouseBusy(true);
				if (IsMouseBusyDrawing())
				{
					SetDefaultCombatKeys();
					SetMouseBusy(false);
				}
				else
				{
					DelayEvent(pUIEvent);
				}
				return;
			}
			if (pUIEvent == 556)
			{
				SetMouseBusy(true);
				if (IsMouseBusyDrawing())
				{
					SetDefaultCommKeys();
					SetMouseBusy(false);
				}
				else
				{
					DelayEvent(pUIEvent);
				}
				return;
			}
			if (pUIEvent == 554)
			{
				SetMouseBusy(true);
				if (IsMouseBusyDrawing())
				{
					SetDefaultMiscKeys();
					SetMouseBusy(false);
				}
				else
				{
					DelayEvent(pUIEvent);
				}
				return;
			}
			if (pUIEvent == 560)
			{
				ResetVideoDefault();
				return;
			}
			if (pUIEvent == 561)
			{
				AcceptVideoSettings();
				return;
			}
			if (pUIEvent == 562)
			{
				SetMouseBusy(true);
				if (IsMouseBusyDrawing())
				{
					ResetVideoAdvancedDefault();
					SetMouseBusy(false);
				}
				else
				{
					DelayEvent(pUIEvent);
				}
				return;
			}
			if (pUIEvent == 563)
			{
				SetMouseBusy(true);
				if (IsMouseBusyDrawing())
				{
					AcceptVideoAdvancedSettings();
					SetMouseBusy(false);
				}
				else
				{
					DelayEvent(pUIEvent);
				}
				return;
			}
			if (pUIEvent == 564)
			{
				SetMouseBusy(true);
				if (IsMouseBusyDrawing())
				{
					ResetVideoDecalsDefault();
					SetMouseBusy(false);
				}
				else
				{
					DelayEvent(pUIEvent);
				}
				return;
			}
			if (pUIEvent == 565)
			{
				SetMouseBusy(true);
				if (IsMouseBusyDrawing())
				{
					AcceptVideoDecalsSettings();
					SetMouseBusy(false);
				}
				else
				{
					DelayEvent(pUIEvent);
				}
				return;
			}
			if (pUIEvent == 570)
			{
				SetMouseBusy(true);
				if (IsMouseBusyDrawing())
				{
					ResetAudioDefault();
					SetMouseBusy(false);
				}
				else
				{
					DelayEvent(pUIEvent);
				}
				return;
			}
			if (pUIEvent == 571)
			{
				SetMouseBusy(true);
				if (IsMouseBusyDrawing())
				{
					AcceptAudioSettings();
					SetMouseBusy(false);
				}
				else
				{
					DelayEvent(pUIEvent);
				}
				return;
			}
			if (pUIEvent == 580)
			{
				SetMouseBusy(true);
				if (IsMouseBusyDrawing())
				{
					ResetHUDDefault();
					SetMouseBusy(false);
				}
				else
				{
					DelayEvent(pUIEvent);
				}
				return;
			}
			if (pUIEvent == 555)
			{
				SetMouseBusy(true);
				if (IsMouseBusyDrawing())
				{
					AcceptSkinTone();
					//sText = cHUD.PlayerOwner.ConsoleCommand("get humancontroller skintonepref");
					Cast<AHumanController>(cHUD->PlayerOwner)->SetSkin(sText);
					SetMouseBusy(false);
				}
				else
				{
					DelayEvent(pUIEvent);
				}
				return;
			}
			if (pUIEvent == 800)
			{
				if (Cast<AAGP_HUD>(cHUD) != nullptr)
				{
					Cast<AAGP_HUD>(cHUD)->ServerBrowserUpdateList();
				}
				return;
			}
			if (pUIEvent == 801)
			{
				if (Cast<AAGP_HUD>(cHUD) != nullptr)
				{
					Cast<AAGP_HUD>(cHUD)->ServerBrowserRefreshList();
				}
				return;
			}
			if (pUIEvent == 803)
			{
				RefreshSelectedServer();
				return;
			}
			if (pUIEvent == 850)
			{
				JoinSelectedServer();
				return;
			}
			if (pUIEvent == 814)
			{
				ServerBrowserSort(1);
				return;
			}
			if (pUIEvent == 815)
			{
				ServerBrowserSort(2);
				return;
			}
			if (pUIEvent == 816)
			{
				ServerBrowserSort(3);
				return;
			}
			if (pUIEvent == 817)
			{
				ServerBrowserSort(4);
				return;
			}
			if (pUIEvent == 818)
			{
				ServerBrowserSort(5);
				return;
			}
			if (pUIEvent == 30)
			{
				SetActiveScreen(30);
				return;
			}
			if (pUIEvent == 31)
			{
				Cast<UUITextPageDisplay>(GetScreen(30)->GetControl(20))->PrevPage();
				return;
			}
			if (pUIEvent == 32)
			{
				Cast<UUITextPageDisplay>(GetScreen(30)->GetControl(20))->NextPage();
				return;
			}
			if (pUIEvent == 205)
			{
				SelectLogin();
				return;
			}
			if (pUIEvent == 804)
			{
				NavigatePlayerList(-1);
				return;
			}
			if (pUIEvent == 805)
			{
				NavigatePlayerList(1);
				return;
			}
		}
	}
}

void UMainMenuFrame::DelayEvent(int32 iEvent)
{
	iDelayedEvent = iEvent;
	iDelayedFrame = 0;
}

void UMainMenuFrame::MessageBox(FString szMessage, int32 acceptevent, FString acceptstring, FString cancelstring)
{
	UUIScreen* screen = nullptr;
	UUIControl* Control = nullptr;
	screen = GetMessageBox();
	Control = screen->GetControl(1000);
	Cast<UUITextDisplayColor>(Control)->SetLabel(szMessage);
	Control = screen->GetControl(1001);
	Cast<UUITextButton>(Control)->SetLabel(acceptstring);
	Control = screen->GetControl(1002);
	Cast<UUITextButton>(Control)->SetLabel(cancelstring);
	iMsgBoxYesOverride = acceptevent;
	OpenMessageBox();
}

void UMainMenuFrame::MessageBoxWorking()
{
	MessageBox("...working...", 1001, "", "");
}

void UMainMenuFrame::MessageBoxLoading()
{
	MessageBox("LOADING", 1001, "", "");
}

void UMainMenuFrame::CloseMessageBox()
{
	iMsgBoxYesOverride = 0;
	Super::CloseMessageBox();
}
void UMainMenuFrame::CheckFullScreen()
{
	/*
	if (Cast<AAGP_HUD>(cHUD)->PlayerOwner->Player->bFullScreen)
	{
		Cast<AAGP_HUD>(cHUD)->PlayerOwner->ConsoleCommand("togglefullscreen");
	}
	*/
}

void UMainMenuFrame::Draw(UCanvas* Canvas)
{
	if (_tBackground != nullptr)
	{
		//Canvas.SetPos(0, 0);
		//Canvas.DrawTile(_tBackground, Canvas.SizeX, Canvas.SizeY, 0, 0, 32, 32);
	}
	if (GetActiveScreen() == nullptr)
	{
		SetActiveScreen(0);
	}
	Super::Draw(Canvas);
	if (iDelayedEvent != 0)
	{
		if (iDelayedFrame == 5)
		{
			Notify(iDelayedEvent);
			iDelayedEvent = 0;
			iDelayedFrame = 0;
		}
		else
		{
			iDelayedFrame++;
		}
	}
}

void UMainMenuFrame::Create(AAA2_HUD* pHUD)
{
	FPoint pt = FPoint({0,0});
	FString Temp = "";
	Super::Create(pHUD);
	if (cHUD->PlayerOwner != nullptr)
	{
		//bMenuRestricted = cHUD->PlayerOwner->bMenuRestricted;
	}
	//Temp = GetBaseDir();
	sBriefingsDir = Temp.Left(Temp.Len() - 7);
	sBriefingsDir = sBriefingsDir + "briefings\\";
	InitTextureDimensions();
	//_tBackground = Texture(DynamicLoadObject("T_AA2_UI.menu.hud_menu_blackfill", Class'Texture'));
	pt.X = 260;
	pt.Y = 500;
	SetToolTipLocation(pt);
	Cast<AHumanController>(Cast<AAGP_HUD>(cHUD)->PlayerOwner)->LoadJacket();
	Cast<AHumanController>(Cast<AAGP_HUD>(cHUD)->PlayerOwner)->VerifyJacket();
	Cast<AHumanController>(Cast<AAGP_HUD>(cHUD)->PlayerOwner)->SaveJacket();
	Cast<AHumanController>(Cast<AAGP_HUD>(cHUD)->PlayerOwner)->LoadPSettings();
	CreateScreens();
	CreateMainMenuScreens();
	CreateTrainingScreens();
	CreateMPMainScreens();
	CreateSettingsScreens();
	CreateGettingStartedScreen();
	CreateParentalControlScreen();
	CreateMessageBox();
	AddMouse("AGP_UI.UIMouse", 0, 0, 32, 32, "T_AA2_UI.menu.hud_menu_pointer");
}

void UMainMenuFrame::InitTextureDimensions()
{
	dCheckBox.X = 184;
	dCheckBox.Y = 103;
	dCheckBox.W = 12;
	dCheckBox.H = 12;
	dSliderBack.X = 0;
	dSliderBack.Y = 148;
	dSliderBack.W = 256;
	dSliderBack.H = 12;
	dSliderThumb.X = 210;
	dSliderThumb.Y = 106;
	dSliderThumb.W = 8;
	dSliderThumb.H = 8;
	dBackButton.X = 444;
	dBackButton.Y = 196;
	dBackButton.W = 68;
	dBackButton.H = 20;
	dNextButton.X = 444;
	dNextButton.Y = 128;
	dNextButton.W = 68;
	dNextButton.H = 20;
	dLogInButton.X = 400;
	dLogInButton.Y = 68;
	dLogInButton.W = 68;
	dLogInButton.H = 20;
	dKeyMap.X = 78;
	dKeyMap.Y = 0;
	dKeyMap.W = 128;
	dKeyMap.H = 24;
}

void UMainMenuFrame::CreateScreens()
{
	AddScreen(666, "");
	AddScreen(0, "MAIN");
	AddScreen(4, "SETTINGS");
	AddScreen(400, "CONTROLS");
	AddScreen(410, "VIEW CONTROLS");
	AddScreen(411, "MOVEMENT");
	AddScreen(412, "COMBAT");
	AddScreen(413, "COMM CONTROLS");
	AddScreen(414, "MORE CONTROLS");
	AddScreen(420, "VIDEO");
	AddScreen(421, "ADV. VIDEO");
	AddScreen(422, "DECALS");
	AddScreen(430, "AUDIO");
	AddScreen(440, "HUD");
	AddScreen(450, "WEAPON MODS");
	AddScreen(100, "MISSION SELECT");
	AddScreen(101, "TOUR");
	AddScreen(102, "HISTORY");
	AddScreen(103, "MISSION BRIEF");
	AddScreen(104, "MISSION BRIEF");
	AddScreen(2, "OPERATIONS");
	AddScreen(201, "SOLDIER LOGIN");
	AddScreen(202, "");
	AddScreen(1, "MISSION SELECT");
	AddScreen(30, "QUICK GUIDE");
	AddScreen(5, "CREDITS");
	AddScreen(6, "ARMY CREDITS");
	AddScreen(7, "PARENTAL CTRL");
	AddStaticScreen(666);
}

void UMainMenuFrame::CreateMainMenuScreens()
{
	UUIScreen* screen = nullptr;
	FPosition pos = FPosition({0,0,0,0});
	FPosition dim = FPosition({0,0,0,0});
	FString sVersion = "";
	screen = GetScreen(666);
	pos.X = 0;
	pos.Y = 0;
	pos.W = 800;
	pos.H = 600;
	dim.X = 0;
	dim.Y = 0;
	dim.W = 800;
	dim.H = 600;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_backgrnd_02", dim, 0);
	//sVersion = GetVersionAGPMajor() + "." + GetVersionAGPMinor() + "." + GetVersionAGPTiny() + "." + GetVersionAGPSubTiny();
	pos.X = 2;
	pos.Y = 36;
	pos.W = 16;
	pos.H = 16;
	screen->AddUITextDisplay(0, 0, pos, sVersion, 1, "", 0, 0);
	pos.X = 19;
	pos.Y = 64;
	pos.W = 77;
	pos.H = 101;
	dim.X = 0;
	dim.Y = 14;
	dim.W = 77;
	dim.H = 101;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements", dim, 1);
	if (!bMenuRestricted)
	{
		dim.X = 0;
		dim.Y = 138;
		dim.W = 92;
		dim.H = 23;
		pos.X = 113;
		pos.Y = 25;
		pos.W = 92;
		pos.H = 23;
		screen->AddUIWebLinkButton(15, 9, pos, "T_AA2_UI.menu.hud_menu_elements2", dim, 0);
		dim.X = 0;
		dim.Y = 92;
		dim.W = 176;
		dim.H = 23;
		pos.X = 205;
		pos.Y = 25;
		pos.W = 176;
		pos.H = 23;
		screen->AddUIWebLinkButton(16, 10, pos, "T_AA2_UI.menu.hud_menu_elements2", dim, 0);
		dim.X = 0;
		dim.Y = 0;
		dim.W = 163;
		dim.H = 23;
		pos.X = 529;
		pos.Y = 25;
		pos.W = 163;
		pos.H = 23;
		screen->AddUIWebLinkButton(0, 11, pos, "T_AA2_UI.menu.hud_menu_elements4", dim, 0);
		dim.X = 0;
		dim.Y = 0;
		dim.W = 60;
		dim.H = 23;
		pos.X = 692;
		pos.Y = 25;
		pos.W = 60;
		pos.H = 23;
		screen->AddUIWebLinkButton(0, 13, pos, "T_AA2_UI.menu.hud_menu_elements2", dim, 0);
		dim.X = 97;
		dim.Y = 16;
		dim.W = 14;
		dim.H = 13;
		pos.X = 771;
		pos.Y = 30;
		pos.W = 14;
		pos.H = 13;
		screen->AddRolloverBitmapButton(0, 21, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 0, "");
		dim.X = 113;
		dim.Y = 16;
		dim.W = 14;
		dim.H = 13;
		pos.X = 786;
		pos.Y = 30;
		pos.W = 14;
		pos.H = 13;
		screen->AddRolloverBitmapButton(0, 22, pos, "T_AA2_UI.menu.hud_menu_elements3", dim, 0, "");
	}
	screen = GetScreen(0);
	if (!bMenuRestricted)
	{
		pos.X = 222;
		pos.Y = 82;
		pos.W = 112;
		pos.H = 20;
		screen->AddUITextButton(0, 30, pos, "Getting Started", 1, "");
	}
	pos.X = 222;
	pos.Y = 126;
	pos.W = 160;
	pos.H = 20;
	screen->AddUITextButton(2, 2, pos, "Report for Duty", 1, "");
	if (!bMenuRestricted)
	{
		pos.X = 222;
		pos.Y = 174;
		pos.W = 116;
		pos.H = 20;
		screen->AddUITextButton(4, 4, pos, "Settings", 1, "");
	}
	pos.X = 222;
	pos.Y = 222;
	pos.W = 100;
	pos.H = 20;
	screen->AddUITextButton(8, 15, pos, "Army Credits", 1, "");
	pos.X = 222;
	pos.Y = 270;
	pos.W = 100;
	pos.H = 20;
	screen->AddUITextButton(5, 5, pos, "Developer Credits", 1, "");
	pos.X = 222;
	pos.Y = 318;
	pos.W = 100;
	pos.H = 20;
	screen->AddUITextButton(9, 17, pos, "Parental Control", 1, "");
	pos.X = 222;
	pos.Y = 366;
	pos.W = 100;
	pos.H = 20;
	screen->AddUITextButton(7, 14, pos, "Resume Game", 1, "");
	pos.X = 222;
	pos.Y = 414;
	pos.W = 100;
	pos.H = 20;
	screen->AddUITextButton(17, 16, pos, "Disconnect From Server", 1, "");
	if (!bMenuRestricted)
	{
		pos.X = 222;
		pos.Y = 480;
		pos.W = 55;
		pos.H = 20;
		screen->AddUITextButton(6, 6, pos, "Quit", 1, "");
	}
	pos.X = 240;
	pos.Y = 555;
	pos.W = 550;
	pos.H = 20;
	screen->AddUITextDisplay(0, 0, pos, "The presence of logos, URLs or other information identifying private companies or other non-federal", 1, "", 0, 0);
	pos.X = 230;
	pos.Y = 567;
	pos.W = 550;
	pos.H = 20;
	screen->AddUITextDisplay(0, 0, pos, "entities does not constitute an endorsement by the Department of the Army or the Department of Defense.", 1, "", 0, 0);
}

void UMainMenuFrame::CreateGettingStartedScreen()
{
	UUIControl* Control = nullptr;
	UUIScreen* screen = nullptr;
	FPosition pos = FPosition({0,0,0,0});
	FPosition dim = FPosition({0,0,0,0});
	screen = GetScreen(30);
	dim.X = 256;
	dim.Y = 48;
	dim.W = 16;
	dim.H = 16;
	pos.X = 208;
	pos.Y = 88;
	pos.W = 16;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements", dim, 1);
	dim.X = 272;
	dim.Y = 48;
	dim.W = 16;
	dim.H = 16;
	pos.X = 224;
	pos.Y = 88;
	pos.W = 527;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements", dim, 1);
	dim.X = 428;
	dim.Y = 48;
	dim.W = 16;
	dim.H = 16;
	pos.X = 751;
	pos.Y = 88;
	pos.W = 16;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements", dim, 1);
	dim.X = 256;
	dim.Y = 64;
	dim.W = 16;
	dim.H = 16;
	pos.X = 208;
	pos.Y = 104;
	pos.W = 16;
	pos.H = 416;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements", dim, 1);
	dim.X = 272;
	dim.Y = 64;
	dim.W = 16;
	dim.H = 16;
	pos.X = 224;
	pos.Y = 104;
	pos.W = 527;
	pos.H = 416;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements", dim, 1);
	dim.X = 428;
	dim.Y = 64;
	dim.W = 16;
	dim.H = 16;
	pos.X = 751;
	pos.Y = 104;
	pos.W = 16;
	pos.H = 416;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements", dim, 1);
	dim.X = 256;
	dim.Y = 144;
	dim.W = 16;
	dim.H = 16;
	pos.X = 208;
	pos.Y = 520;
	pos.W = 16;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements", dim, 1);
	dim.X = 272;
	dim.Y = 144;
	dim.W = 16;
	dim.H = 16;
	pos.X = 224;
	pos.Y = 520;
	pos.W = 527;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements", dim, 1);
	dim.X = 428;
	dim.Y = 144;
	dim.W = 16;
	dim.H = 16;
	pos.X = 751;
	pos.Y = 520;
	pos.W = 16;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements", dim, 1);
	pos.X = 220;
	pos.Y = 126;
	pos.W = 520;
	pos.H = 370;
	screen->AddUITextPageDisplay(20, pos, 0, 30, true);
	Control = screen->GetControl(20);
	Cast<UUITextPageDisplay>(Control)->SetTitle("Quick Guide to Playing America's Army");
	Cast<UUITextPageDisplay>(Control)->SetTextFile(sBriefingsDir + "gettingstarted.txt");
	dim.X = 144;
	dim.Y = 192;
	dim.W = 16;
	dim.H = 16;
	pos.X = 370;
	pos.Y = 510;
	pos.W = 16;
	pos.H = 16;
	screen->AddRolloverBitmapButton(21, 31, pos, "T_AA2_UI.menu.hud_menu_elements2", dim, 0, "");
	dim.X = 161;
	dim.Y = 192;
	dim.W = 16;
	dim.H = 16;
	pos.X = 576;
	pos.Y = 510;
	pos.W = 16;
	pos.H = 16;
	screen->AddRolloverBitmapButton(22, 32, pos, "T_AA2_UI.menu.hud_menu_elements2", dim, 0, "");
	pos.X = 224;
	pos.Y = 552;
	pos.W = 68;
	pos.H = 20;
	screen->AddRolloverBitmapButton(14, 2, pos, "T_AA2_UI.menu.hud_menu_elements", dBackButton, 0, "");
	screen->AddUIEscapeKey(0, 7);
}

void UMainMenuFrame::CreateTrainingScreens()
{
	UUIControl* Control = nullptr;
	UUIScreen* screen = nullptr;
	FPosition pos = FPosition({0,0,0,0});
	FPosition dim = FPosition({0,0,0,0});
	screen = GetScreen(1);
	pos.X = 225;
	pos.Y = 119;
	pos.W = 112;
	pos.H = 20;
	screen->AddUITextDisplay(0, 0, pos, "TOUR", 1, "", 2, 0);
	pos.Y = 327;
	screen->AddUITextDisplay(0, 0, pos, "MISSION", 1, "", 2, 0);
	dim.X = 0;
	dim.Y = 160;
	dim.W = 416;
	dim.H = 96;
	pos.X = 352;
	pos.Y = 80;
	pos.W = 416;
	pos.H = 96;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements", dim, 1);
	pos.X = 352;
	pos.Y = 288;
	pos.W = 416;
	pos.H = 96;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements", dim, 1);
	dim.X = 0;
	dim.Y = 116;
	dim.W = 256;
	dim.H = 32;
	pos.X = 436;
	pos.Y = 192;
	pos.W = 256;
	pos.H = 32;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements", dim, 1);
	pos.X = 436;
	pos.Y = 400;
	pos.W = 256;
	pos.H = 32;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements", dim, 1);
	pos.X = 504;
	pos.Y = 86;
	pos.W = 110;
	pos.H = 82;
	screen->AddUIImageListDisplay(102, pos, 1);
	Control = screen->GetControl(102);
	//sTourIni = GetBaseDir() + "tours.ini";
	Cast<UUIImageListDisplay>(Control)->SetData(0);
	pos.X = 504;
	pos.Y = 296;
	pos.W = 110;
	pos.H = 82;
	screen->AddUIImageListDisplay(103, pos, 0);
	Cast<UUIImageListDisplay>(screen->GetControl(103))->SetData(Cast<UUIImageListDisplay>(Control)->GetIndex());
	pos.X = 376;
	pos.Y = 196;
	pos.W = 44;
	pos.H = 24;
	dim.X = 183;
	dim.Y = 26;
	dim.W = 44;
	dim.H = 24;
	screen->AddRolloverBitmapButton(104, 104, pos, "T_AA2_UI.menu.hud_menu_elements", dim, 0, "");
	pos.X = 708;
	pos.Y = 196;
	pos.W = 44;
	pos.H = 24;
	dim.X = 444;
	dim.Y = 56;
	dim.W = 44;
	dim.H = 24;
	screen->AddRolloverBitmapButton(105, 105, pos, "T_AA2_UI.menu.hud_menu_elements", dim, 0, "");
	pos.X = 376;
	pos.Y = 404;
	pos.W = 44;
	pos.H = 24;
	dim.X = 183;
	dim.Y = 26;
	dim.W = 44;
	dim.H = 24;
	screen->AddRolloverBitmapButton(106, 106, pos, "T_AA2_UI.menu.hud_menu_elements", dim, 0, "");
	pos.X = 708;
	pos.Y = 404;
	pos.W = 44;
	pos.H = 24;
	dim.X = 444;
	dim.Y = 56;
	dim.W = 44;
	dim.H = 24;
	screen->AddRolloverBitmapButton(107, 107, pos, "T_AA2_UI.menu.hud_menu_elements", dim, 0, "");
	pos.X = 224;
	pos.Y = 552;
	pos.W = 68;
	pos.H = 20;
	screen->AddRolloverBitmapButton(14, 2, pos, "T_AA2_UI.menu.hud_menu_elements", dBackButton, 0, "");
	pos.X = 704;
	pos.Y = 552;
	pos.W = 68;
	pos.H = 20;
	screen->AddRolloverBitmapButton(100, 110, pos, "T_AA2_UI.menu.hud_menu_elements", dNextButton, 0, "");
	screen->AddUIEscapeKey(0, 7);
	screen = GetScreen(101);
	pos.X = 320;
	pos.Y = 63;
	pos.W = 112;
	pos.H = 20;
	screen->AddUITextDisplay(0, 0, pos, "TOUR", 1, "", 3, 1);
	pos.X = 434;
	pos.Y = 63;
	pos.W = 112;
	pos.H = 20;
	screen->AddUITextButton(0, 120, pos, "HISTORY", 0, "");
	pos.X = 578;
	pos.Y = 63;
	pos.W = 112;
	pos.H = 20;
	screen->AddUITextButton(0, 130, pos, "MISSION", 0, "");
	dim.X = 256;
	dim.Y = 48;
	dim.W = 16;
	dim.H = 16;
	pos.X = 208;
	pos.Y = 88;
	pos.W = 16;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements", dim, 1);
	dim.X = 272;
	dim.Y = 48;
	dim.W = 16;
	dim.H = 16;
	pos.X = 224;
	pos.Y = 88;
	pos.W = 527;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements", dim, 1);
	dim.X = 428;
	dim.Y = 48;
	dim.W = 16;
	dim.H = 16;
	pos.X = 751;
	pos.Y = 88;
	pos.W = 16;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements", dim, 1);
	dim.X = 256;
	dim.Y = 64;
	dim.W = 16;
	dim.H = 16;
	pos.X = 208;
	pos.Y = 104;
	pos.W = 16;
	pos.H = 416;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements", dim, 1);
	dim.X = 272;
	dim.Y = 64;
	dim.W = 16;
	dim.H = 16;
	pos.X = 224;
	pos.Y = 104;
	pos.W = 527;
	pos.H = 416;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements", dim, 1);
	dim.X = 428;
	dim.Y = 64;
	dim.W = 16;
	dim.H = 16;
	pos.X = 751;
	pos.Y = 104;
	pos.W = 16;
	pos.H = 416;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements", dim, 1);
	dim.X = 256;
	dim.Y = 144;
	dim.W = 16;
	dim.H = 16;
	pos.X = 208;
	pos.Y = 520;
	pos.W = 16;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements", dim, 1);
	dim.X = 272;
	dim.Y = 144;
	dim.W = 16;
	dim.H = 16;
	pos.X = 224;
	pos.Y = 520;
	pos.W = 527;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements", dim, 1);
	dim.X = 428;
	dim.Y = 144;
	dim.W = 16;
	dim.H = 16;
	pos.X = 751;
	pos.Y = 520;
	pos.W = 16;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements", dim, 1);
	pos.X = 220;
	pos.Y = 126;
	pos.W = 520;
	pos.H = 370;
	screen->AddUITextPageDisplay(110, pos, 0, 30, true);
	dim.X = 144;
	dim.Y = 192;
	dim.W = 16;
	dim.H = 16;
	pos.X = 370;
	pos.Y = 510;
	pos.W = 16;
	pos.H = 16;
	screen->AddRolloverBitmapButton(111, 111, pos, "T_AA2_UI.menu.hud_menu_elements2", dim, 0, "");
	dim.X = 161;
	dim.Y = 192;
	dim.W = 16;
	dim.H = 16;
	pos.X = 576;
	pos.Y = 510;
	pos.W = 16;
	pos.H = 16;
	screen->AddRolloverBitmapButton(112, 112, pos, "T_AA2_UI.menu.hud_menu_elements2", dim, 0, "");
	pos.X = 224;
	pos.Y = 552;
	pos.W = 68;
	pos.H = 20;
	screen->AddRolloverBitmapButton(0, 1, pos, "T_AA2_UI.menu.hud_menu_elements", dBackButton, 0, "");
	pos.X = 704;
	pos.Y = 552;
	pos.W = 68;
	pos.H = 20;
	screen->AddRolloverBitmapButton(0, 120, pos, "T_AA2_UI.menu.hud_menu_elements", dNextButton, 0, "");
	screen->AddUIEscapeKey(0, 1);
	screen = GetScreen(102);
	pos.X = 320;
	pos.Y = 63;
	pos.W = 112;
	pos.H = 20;
	screen->AddUITextButton(161, 113, pos, "TOUR", 0, "");
	pos.X = 434;
	pos.Y = 63;
	pos.W = 112;
	pos.H = 20;
	screen->AddUITextDisplay(0, 0, pos, "HISTORY", 1, "", 3, 1);
	pos.X = 578;
	pos.Y = 63;
	pos.W = 112;
	pos.H = 20;
	screen->AddUITextButton(0, 130, pos, "MISSION", 0, "");
	dim.X = 256;
	dim.Y = 48;
	dim.W = 16;
	dim.H = 16;
	pos.X = 208;
	pos.Y = 88;
	pos.W = 16;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements", dim, 1);
	dim.X = 272;
	dim.Y = 48;
	dim.W = 16;
	dim.H = 16;
	pos.X = 224;
	pos.Y = 88;
	pos.W = 527;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements", dim, 1);
	dim.X = 428;
	dim.Y = 48;
	dim.W = 16;
	dim.H = 16;
	pos.X = 751;
	pos.Y = 88;
	pos.W = 16;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements", dim, 1);
	dim.X = 256;
	dim.Y = 64;
	dim.W = 16;
	dim.H = 16;
	pos.X = 208;
	pos.Y = 104;
	pos.W = 16;
	pos.H = 416;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements", dim, 1);
	dim.X = 272;
	dim.Y = 64;
	dim.W = 16;
	dim.H = 16;
	pos.X = 224;
	pos.Y = 104;
	pos.W = 527;
	pos.H = 416;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements", dim, 1);
	dim.X = 428;
	dim.Y = 64;
	dim.W = 16;
	dim.H = 16;
	pos.X = 751;
	pos.Y = 104;
	pos.W = 16;
	pos.H = 416;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements", dim, 1);
	dim.X = 256;
	dim.Y = 144;
	dim.W = 16;
	dim.H = 16;
	pos.X = 208;
	pos.Y = 520;
	pos.W = 16;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements", dim, 1);
	dim.X = 272;
	dim.Y = 144;
	dim.W = 16;
	dim.H = 16;
	pos.X = 224;
	pos.Y = 520;
	pos.W = 527;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements", dim, 1);
	dim.X = 428;
	dim.Y = 144;
	dim.W = 16;
	dim.H = 16;
	pos.X = 751;
	pos.Y = 520;
	pos.W = 16;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements", dim, 1);
	pos.X = 220;
	pos.Y = 126;
	pos.W = 520;
	pos.H = 370;
	screen->AddUITextPageDisplay(120, pos, 0, 30, true);
	dim.X = 144;
	dim.Y = 192;
	dim.W = 16;
	dim.H = 16;
	pos.X = 370;
	pos.Y = 510;
	pos.W = 16;
	pos.H = 16;
	screen->AddRolloverBitmapButton(121, 121, pos, "T_AA2_UI.menu.hud_menu_elements2", dim, 0, "");
	dim.X = 161;
	dim.Y = 192;
	dim.W = 16;
	dim.H = 16;
	pos.X = 576;
	pos.Y = 510;
	pos.W = 16;
	pos.H = 16;
	screen->AddRolloverBitmapButton(122, 122, pos, "T_AA2_UI.menu.hud_menu_elements2", dim, 0, "");
	pos.X = 224;
	pos.Y = 552;
	pos.W = 68;
	pos.H = 20;
	screen->AddRolloverBitmapButton(0, 113, pos, "T_AA2_UI.menu.hud_menu_elements", dBackButton, 0, "");
	pos.X = 704;
	pos.Y = 552;
	pos.W = 68;
	pos.H = 20;
	screen->AddRolloverBitmapButton(0, 130, pos, "T_AA2_UI.menu.hud_menu_elements", dNextButton, 0, "");
	screen->AddUIEscapeKey(0, 113);
	screen = GetScreen(103);
	pos.X = 320;
	pos.Y = 63;
	pos.W = 112;
	pos.H = 20;
	screen->AddUITextButton(161, 113, pos, "TOUR", 0, "");
	pos.X = 434;
	pos.Y = 63;
	pos.W = 112;
	pos.H = 20;
	screen->AddUITextButton(0, 120, pos, "HISTORY", 0, "");
	pos.X = 578;
	pos.Y = 63;
	pos.W = 112;
	pos.H = 20;
	screen->AddUITextDisplay(0, 0, pos, "MISSION", 1, "", 3, 1);
	dim.X = 256;
	dim.Y = 48;
	dim.W = 16;
	dim.H = 16;
	pos.X = 208;
	pos.Y = 88;
	pos.W = 16;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements", dim, 1);
	dim.X = 272;
	dim.Y = 48;
	dim.W = 16;
	dim.H = 16;
	pos.X = 224;
	pos.Y = 88;
	pos.W = 527;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements", dim, 1);
	dim.X = 428;
	dim.Y = 48;
	dim.W = 16;
	dim.H = 16;
	pos.X = 751;
	pos.Y = 88;
	pos.W = 16;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements", dim, 1);
	dim.X = 256;
	dim.Y = 64;
	dim.W = 16;
	dim.H = 16;
	pos.X = 208;
	pos.Y = 104;
	pos.W = 16;
	pos.H = 416;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements", dim, 1);
	dim.X = 272;
	dim.Y = 64;
	dim.W = 16;
	dim.H = 16;
	pos.X = 224;
	pos.Y = 104;
	pos.W = 527;
	pos.H = 416;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements", dim, 1);
	dim.X = 428;
	dim.Y = 64;
	dim.W = 16;
	dim.H = 16;
	pos.X = 751;
	pos.Y = 104;
	pos.W = 16;
	pos.H = 416;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements", dim, 1);
	dim.X = 256;
	dim.Y = 144;
	dim.W = 16;
	dim.H = 16;
	pos.X = 208;
	pos.Y = 520;
	pos.W = 16;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements", dim, 1);
	dim.X = 272;
	dim.Y = 144;
	dim.W = 16;
	dim.H = 16;
	pos.X = 224;
	pos.Y = 520;
	pos.W = 527;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements", dim, 1);
	dim.X = 428;
	dim.Y = 144;
	dim.W = 16;
	dim.H = 16;
	pos.X = 751;
	pos.Y = 520;
	pos.W = 16;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements", dim, 1);
	pos.X = 220;
	pos.Y = 126;
	pos.W = 520;
	pos.H = 370;
	screen->AddUITextPageDisplay(130, pos, 0, 30, true);
	dim.X = 144;
	dim.Y = 192;
	dim.W = 16;
	dim.H = 16;
	pos.X = 370;
	pos.Y = 510;
	pos.W = 16;
	pos.H = 16;
	screen->AddRolloverBitmapButton(131, 131, pos, "T_AA2_UI.menu.hud_menu_elements2", dim, 0, "");
	dim.X = 161;
	dim.Y = 192;
	dim.W = 16;
	dim.H = 16;
	pos.X = 576;
	pos.Y = 510;
	pos.W = 16;
	pos.H = 16;
	screen->AddRolloverBitmapButton(132, 132, pos, "T_AA2_UI.menu.hud_menu_elements2", dim, 0, "");
	pos.X = 224;
	pos.Y = 552;
	pos.W = 68;
	pos.H = 20;
	screen->AddRolloverBitmapButton(0, 120, pos, "T_AA2_UI.menu.hud_menu_elements", dBackButton, 0, "");
	pos.X = 704;
	pos.Y = 552;
	pos.W = 68;
	pos.H = 20;
	screen->AddRolloverBitmapButton(0, 140, pos, "T_AA2_UI.menu.hud_menu_elements", dNextButton, 0, "");
	screen->AddUIEscapeKey(0, 120);
	screen = GetScreen(104);
	pos.X = 320;
	pos.Y = 63;
	pos.W = 112;
	pos.H = 20;
	screen->AddUITextButton(161, 113, pos, "TOUR", 0, "");
	pos.X = 434;
	pos.Y = 63;
	pos.W = 112;
	pos.H = 20;
	screen->AddUITextButton(0, 120, pos, "HISTORY", 0, "");
	pos.X = 578;
	pos.Y = 63;
	pos.W = 112;
	pos.H = 20;
	screen->AddUITextDisplay(0, 0, pos, "MISSION", 1, "", 3, 1);
	dim.X = 256;
	dim.Y = 48;
	dim.W = 16;
	dim.H = 16;
	pos.X = 208;
	pos.Y = 96;
	pos.W = 16;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements", dim, 1);
	dim.X = 272;
	dim.Y = 48;
	dim.W = 16;
	dim.H = 16;
	pos.X = 224;
	pos.Y = 96;
	pos.W = 527;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements", dim, 1);
	dim.X = 428;
	dim.Y = 48;
	dim.W = 16;
	dim.H = 16;
	pos.X = 751;
	pos.Y = 96;
	pos.W = 16;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements", dim, 1);
	dim.X = 256;
	dim.Y = 64;
	dim.W = 16;
	dim.H = 16;
	pos.X = 208;
	pos.Y = 112;
	pos.W = 16;
	pos.H = 184;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements", dim, 1);
	dim.X = 272;
	dim.Y = 64;
	dim.W = 16;
	dim.H = 16;
	pos.X = 224;
	pos.Y = 112;
	pos.W = 527;
	pos.H = 184;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements", dim, 1);
	dim.X = 428;
	dim.Y = 64;
	dim.W = 16;
	dim.H = 16;
	pos.X = 751;
	pos.Y = 112;
	pos.W = 16;
	pos.H = 184;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements", dim, 1);
	dim.X = 256;
	dim.Y = 144;
	dim.W = 16;
	dim.H = 16;
	pos.X = 208;
	pos.Y = 296;
	pos.W = 16;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements", dim, 1);
	dim.X = 272;
	dim.Y = 144;
	dim.W = 16;
	dim.H = 16;
	pos.X = 224;
	pos.Y = 296;
	pos.W = 527;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements", dim, 1);
	dim.X = 428;
	dim.Y = 144;
	dim.W = 16;
	dim.H = 16;
	pos.X = 751;
	pos.Y = 296;
	pos.W = 16;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements", dim, 1);
	dim.X = 256;
	dim.Y = 48;
	dim.W = 16;
	dim.H = 16;
	pos.X = 208;
	pos.Y = 320;
	pos.W = 16;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements", dim, 1);
	dim.X = 272;
	dim.Y = 48;
	dim.W = 16;
	dim.H = 16;
	pos.X = 224;
	pos.Y = 320;
	pos.W = 527;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements", dim, 1);
	dim.X = 428;
	dim.Y = 48;
	dim.W = 16;
	dim.H = 16;
	pos.X = 751;
	pos.Y = 320;
	pos.W = 16;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements", dim, 1);
	dim.X = 256;
	dim.Y = 64;
	dim.W = 16;
	dim.H = 16;
	pos.X = 208;
	pos.Y = 336;
	pos.W = 16;
	pos.H = 184;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements", dim, 1);
	dim.X = 272;
	dim.Y = 64;
	dim.W = 16;
	dim.H = 16;
	pos.X = 224;
	pos.Y = 336;
	pos.W = 527;
	pos.H = 184;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements", dim, 1);
	dim.X = 428;
	dim.Y = 64;
	dim.W = 16;
	dim.H = 16;
	pos.X = 751;
	pos.Y = 336;
	pos.W = 16;
	pos.H = 184;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements", dim, 1);
	dim.X = 256;
	dim.Y = 144;
	dim.W = 16;
	dim.H = 16;
	pos.X = 208;
	pos.Y = 520;
	pos.W = 16;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements", dim, 1);
	dim.X = 272;
	dim.Y = 144;
	dim.W = 16;
	dim.H = 16;
	pos.X = 224;
	pos.Y = 520;
	pos.W = 527;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements", dim, 1);
	dim.X = 428;
	dim.Y = 144;
	dim.W = 16;
	dim.H = 16;
	pos.X = 751;
	pos.Y = 520;
	pos.W = 16;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements", dim, 1);
	pos.X = 220;
	pos.Y = 126;
	pos.W = 520;
	pos.H = 100;
	screen->AddUITextPageDisplay(150, pos, 0, 14, false);
	pos.X = 220;
	pos.Y = 356;
	pos.W = 520;
	pos.H = 100;
	screen->AddUITextPageDisplay(160, pos, 0, 14, false);
	pos.X = 224;
	pos.Y = 552;
	pos.W = 68;
	pos.H = 20;
	screen->AddRolloverBitmapButton(0, 120, pos, "T_AA2_UI.menu.hud_menu_elements", dBackButton, 0, "");
	pos.X = 704;
	pos.Y = 552;
	pos.W = 68;
	pos.H = 20;
	screen->AddRolloverBitmapButton(0, 140, pos, "T_AA2_UI.menu.hud_menu_elements", dNextButton, 0, "");
	screen->AddUIEscapeKey(0, 120);
}

void UMainMenuFrame::CreateMPMainScreens()
{
	UUIScreen* screen = nullptr;
	FPosition pos = FPosition({0,0,0,0});
	FPosition dim = FPosition({0,0,0,0});
	int32 test1 = 0;
	int32 test2 = 0;
	screen = GetScreen(2);
	if (!bMenuRestricted)
	{
		pos.X = 224;
		pos.Y = 82;
		pos.W = 112;
		pos.H = 20;
		screen->AddUITextButton(200, 200, pos, "Step 1:  Create Online Soldier (opens web browser)", 1, "");
		pos.X = 224;
		pos.Y = 126;
		pos.W = 160;
		pos.H = 20;
		screen->AddUITextButton(201, 201, pos, "Step 2:  Soldier Login", 1, "");
	}
	pos.X = 224;
	pos.Y = 174;
	pos.W = 160;
	pos.H = 20;
	screen->AddUITextButton(1, 1, pos, "Step 3:  Soldier Training", 1, "");
	if (!bMenuRestricted)
	{
		pos.X = 224;
		pos.Y = 270;
		pos.W = 160;
		pos.H = 20;
		screen->AddUITextButton(0, 206, pos, "Step 4:  Find Online Games (Andromeda)", 1, "");
		pos.X = 224;
		pos.Y = 222;
		pos.W = 160;
		pos.H = 20;
		screen->AddUITextButton(0, 202, pos, "Step 4:  Find Online Games (GameSpy)", 1, "");
	}
	pos.X = 224;
	pos.Y = 314;
	pos.W = 112;
	pos.H = 20;
	screen->AddUITextDisplay(0, 0, pos, "LAN GAMES", 1, "", 2, 0);
	dim.X = 256;
	dim.Y = 48;
	dim.W = 16;
	dim.H = 16;
	pos.X = 208;
	pos.Y = 334;
	pos.W = 16;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements", dim, 1);
	dim.X = 272;
	dim.Y = 48;
	dim.W = 16;
	dim.H = 16;
	pos.X = 224;
	pos.Y = 334;
	pos.W = 527;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements", dim, 1);
	dim.X = 428;
	dim.Y = 48;
	dim.W = 16;
	dim.H = 16;
	pos.X = 751;
	pos.Y = 334;
	pos.W = 16;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements", dim, 1);
	dim.X = 256;
	dim.Y = 64;
	dim.W = 16;
	dim.H = 16;
	pos.X = 208;
	pos.Y = 350;
	pos.W = 16;
	pos.H = 168;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements", dim, 1);
	dim.X = 272;
	dim.Y = 64;
	dim.W = 16;
	dim.H = 16;
	pos.X = 224;
	pos.Y = 350;
	pos.W = 527;
	pos.H = 168;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements", dim, 1);
	dim.X = 428;
	dim.Y = 64;
	dim.W = 16;
	dim.H = 16;
	pos.X = 751;
	pos.Y = 350;
	pos.W = 16;
	pos.H = 168;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements", dim, 1);
	dim.X = 256;
	dim.Y = 144;
	dim.W = 16;
	dim.H = 16;
	pos.X = 208;
	pos.Y = 518;
	pos.W = 16;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements", dim, 1);
	dim.X = 272;
	dim.Y = 144;
	dim.W = 16;
	dim.H = 16;
	pos.X = 224;
	pos.Y = 518;
	pos.W = 527;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements", dim, 1);
	dim.X = 428;
	dim.Y = 144;
	dim.W = 16;
	dim.H = 16;
	pos.X = 751;
	pos.Y = 518;
	pos.W = 16;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements", dim, 1);
	pos.X = 224;
	pos.Y = 358;
	pos.W = 400;
	pos.H = 160;
	screen->AddUIQuickLan(0, pos, 0);
	pos.X = 224;
	pos.Y = 552;
	pos.W = 68;
	pos.H = 20;
	screen->AddRolloverBitmapButton(14, 7, pos, "T_AA2_UI.menu.hud_menu_elements", dBackButton, 0, "");
	screen->AddUIEscapeKey(0, 7);
	screen = GetScreen(201);
	test1 = 160;
	pos.X = 222;
	pos.Y = 82 + test1;
	pos.W = 112;
	pos.H = 20;
	screen->AddUITextDisplay(0, 0, pos, "SOLDIER NAME", 1, "", 2, 0);
	pos.Y += 50;
	screen->AddUITextDisplay(0, 0, pos, "PASSWORD", 1, "", 2, 0);
	dim.X = 0;
	dim.Y = 116;
	dim.W = 256;
	dim.H = 32;
	pos.X = 448;
	pos.Y = 72 + test1;
	pos.W = 256;
	pos.H = 32;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements", dim, 1);
	pos.X = 448;
	pos.Y += 50;
	pos.W = 256;
	pos.H = 32;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements", dim, 1);
	pos.X = 448;
	pos.Y = 72 + test1;
	pos.W = 256;
	pos.H = 32;
	screen->AddUIEditBox(300, 0, pos, "login", 0, "", 20);
	pos.X = 448;
	pos.Y += 50;
	pos.W = 256;
	pos.H = 32;
	screen->AddUIEditBox(301, 0, pos, "password", 1, "", 20);
	pos.X = 448;
	pos.Y += 50;
	pos.W = 68;
	pos.H = 20;
	screen->AddRolloverBitmapButton(205, 205, pos, "T_AA2_UI.menu.hud_menu_elements3", dLogInButton, 0, "");
	pos.X = 448;
	pos.Y += 50;
	pos.W = 112;
	pos.H = 20;
	screen->AddUITextDisplay(204, 0, pos, "ID_Status", 1, "", 2, 0);
	test2 = -200;
	pos.X = 224;
	pos.Y = 260 + test2;
	pos.W = 112;
	pos.H = 20;
	screen->AddUITextDisplay(0, 0, pos, "NEWS", 1, "", 2, 0);
	dim.X = 256;
	dim.Y = 48;
	dim.W = 16;
	dim.H = 16;
	pos.X = 208;
	pos.Y = 280 + test2;
	pos.W = 16;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements", dim, 1);
	dim.X = 272;
	dim.Y = 48;
	dim.W = 16;
	dim.H = 16;
	pos.X = 224;
	pos.Y = 280 + test2;
	pos.W = 527;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements", dim, 1);
	dim.X = 428;
	dim.Y = 48;
	dim.W = 16;
	dim.H = 16;
	pos.X = 751;
	pos.Y = 280 + test2;
	pos.W = 16;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements", dim, 1);
	dim.X = 256;
	dim.Y = 64;
	dim.W = 16;
	dim.H = 16;
	pos.X = 208;
	pos.Y = 296 + test2;
	pos.W = 16;
	pos.H = 100;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements", dim, 1);
	dim.X = 272;
	dim.Y = 64;
	dim.W = 16;
	dim.H = 16;
	pos.X = 224;
	pos.Y = 296 + test2;
	pos.W = 527;
	pos.H = 100;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements", dim, 1);
	dim.X = 428;
	dim.Y = 64;
	dim.W = 16;
	dim.H = 16;
	pos.X = 751;
	pos.Y = 296 + test2;
	pos.W = 16;
	pos.H = 100;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements", dim, 1);
	dim.X = 256;
	dim.Y = 144;
	dim.W = 16;
	dim.H = 16;
	pos.X = 208;
	pos.Y = 396 + test2;
	pos.W = 16;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements", dim, 1);
	dim.X = 272;
	dim.Y = 144;
	dim.W = 16;
	dim.H = 16;
	pos.X = 224;
	pos.Y = 396 + test2;
	pos.W = 527;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements", dim, 1);
	dim.X = 428;
	dim.Y = 144;
	dim.W = 16;
	dim.H = 16;
	pos.X = 751;
	pos.Y = 396 + test2;
	pos.W = 16;
	pos.H = 16;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements", dim, 1);
	pos.X = 222;
	pos.Y = 290 + test2;
	pos.W = 112;
	pos.H = 20;
	screen->AddUITextDisplay(302, 0, pos, "Welcome to the news box", 1, "", 2, 1);
	pos.Y += 30;
	screen->AddUITextDisplay(303, 0, pos, "To get the latest news please log in", 1, "", 2, 1);
	pos.Y += 30;
	screen->AddUITextDisplay(304, 0, pos, "...", 1, "", 2, 1);
	pos.Y += 30;
	screen->AddUITextDisplay(305, 0, pos, "news system is not yet operational", 1, "", 2, 1);
	pos.X = 222;
	pos.Y = 420;
	pos.W = 112;
	pos.H = 20;
	screen->AddUITextDisplay(0, 0, pos, "Click Back to cancel.", 1, "", 2, 0);
	pos.Y += 30;
	screen->AddUITextDisplay(0, 0, pos, "Click Next to accept Soldier Name and Password.", 1, "", 2, 0);
	pos.Y += 30;
	screen->AddUITextDisplay(0, 0, pos, "Soldier Name and Password will not be", 1, "", 2, 0);
	pos.Y += 30;
	screen->AddUITextDisplay(0, 0, pos, "validated until you connect to a server.", 1, "", 2, 0);
	pos.X = 224;
	pos.Y = 552;
	pos.W = 68;
	pos.H = 20;
	screen->AddRolloverBitmapButton(14, 2, pos, "T_AA2_UI.menu.hud_menu_elements", dBackButton, 0, "");
	pos.X = 704;
	pos.Y = 552;
	pos.W = 68;
	pos.H = 20;
	screen->AddRolloverBitmapButton(0, 203, pos, "T_AA2_UI.menu.hud_menu_elements", dNextButton, 0, "");
	screen->AddUIEscapeKey(0, 203);
	screen = GetScreen(202);
	pos.X = 1;
	pos.Y = 49;
	pos.W = 798;
	pos.H = 550;
	dim.X = 1;
	dim.Y = 49;
	dim.W = 798;
	dim.H = 550;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_backgrnd_03", dim, 0);
	pos.X = 19;
	pos.Y = 64;
	pos.W = 77;
	pos.H = 101;
	dim.X = 0;
	dim.Y = 14;
	dim.W = 77;
	dim.H = 101;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements", dim, 1);
	pos.X = 8;
	pos.Y = 224;
	pos.W = 97;
	pos.H = 38;
	dim.X = 8;
	dim.Y = 224;
	dim.W = 97;
	dim.H = 38;
	screen->AddRolloverBitmapButton(0, 851, pos, "T_AA2_UI.menu.hud_menu_backgrnd_03", dim, 0, "");
	pos.X = 8;
	pos.Y = 283;
	pos.W = 97;
	pos.H = 43;
	dim.X = 8;
	dim.Y = 283;
	dim.W = 97;
	dim.H = 43;
	screen->AddRolloverBitmapButton(0, 852, pos, "T_AA2_UI.menu.hud_menu_backgrnd_03", dim, 0, "");
	pos.X = 130;
	pos.Y = 134;
	pos.W = 10;
	pos.H = 10;
	screen->AddUITextButton(800, 800, pos, "UPDATE", 1, "");
	pos.X = 243;
	pos.Y = 134;
	pos.W = 10;
	pos.H = 10;
	screen->AddUITextButton(801, 801, pos, "REFRESH", 1, "");
	pos.X = 400;
	pos.Y = 134;
	pos.W = 10;
	pos.H = 10;
	screen->AddUITextButton(803, 803, pos, "REFRESH SELECTED", 1, "");
	pos.X = 680;
	pos.Y = 140;
	pos.W = 100;
	pos.H = 20;
	screen->AddUICheckBoxB(829, 0, pos, dCheckBox, "T_AA2_UI.menu.hud_menu_elements", "Auto Sort", 1, "", 0, "HumanController", "bAutoSortServerList");
	pos.X = 246;
	pos.Y = 165;
	pos.W = 10;
	pos.H = 10;
	screen->AddUITextButtonSize(814, 814, pos, "[SERVER NAME]", 1, 1);
	pos.X = 428;
	pos.Y = 165;
	pos.W = 10;
	pos.H = 10;
	screen->AddUITextButtonSize(815, 815, pos, "[PLAYERS]", 1, 1);
	pos.X = 506;
	pos.Y = 165;
	pos.W = 10;
	pos.H = 10;
	screen->AddUITextButtonSize(816, 816, pos, "[PING]", 1, 1);
	pos.X = 552;
	pos.Y = 165;
	pos.W = 10;
	pos.H = 10;
	screen->AddUITextButtonSize(817, 817, pos, "[TOUR]", 1, 1);
	pos.X = 630;
	pos.Y = 165;
	pos.W = 10;
	pos.H = 10;
	screen->AddUITextButtonSize(818, 818, pos, "[MAP NAME]", 1, 1);
	pos.X = 129;
	pos.Y = 192;
	pos.W = 623;
	pos.H = 224;
	screen->AddUIServerListDisplay(850, pos, 0);
	pos.X = 470;
	pos.Y = 418;
	pos.W = 10;
	pos.H = 10;
	screen->AddUITextDisplay(0, 0, pos, "Name", 0, "", 0, 0);
	pos.X = 625;
	pos.Y = 418;
	pos.W = 10;
	pos.H = 10;
	screen->AddUITextDisplay(0, 0, pos, "Enemy", 0, "", 0, 0);
	pos.X = 665;
	pos.Y = 418;
	pos.W = 10;
	pos.H = 10;
	screen->AddUITextDisplay(0, 0, pos, "KIA", 0, "", 0, 0);
	pos.X = 695;
	pos.Y = 418;
	pos.W = 10;
	pos.H = 10;
	screen->AddUITextDisplay(0, 0, pos, "ROE", 0, "", 0, 0);
	pos.X = 725;
	pos.Y = 418;
	pos.W = 10;
	pos.H = 10;
	screen->AddUITextDisplay(0, 0, pos, "Ping", 0, "", 0, 0);
	dim.X = 2;
	dim.Y = 3;
	dim.W = 9;
	dim.H = 8;
	pos.X = 753;
	pos.Y = 192;
	pos.W = 12;
	pos.H = 223;
	screen->AddUISliderH(804, 0, pos, "T_AA2_UI.menu.hud_menu_slider_horiz", dim, 0);
	pos.X = 450;
	pos.Y = 520;
	pos.W = 10;
	pos.H = 10;
	screen->AddUITextButtonSize(0, 804, pos, "PREV", 1, 0);
	pos.X = 490;
	pos.Y = 520;
	pos.W = 10;
	pos.H = 10;
	screen->AddUITextButtonSize(0, 805, pos, "NEXT", 1, 0);
	test1 = 400;
	dim.X = 0;
	dim.Y = 116;
	dim.W = 256;
	dim.H = 32;
	pos.X = 380;
	pos.Y = 72 + test1;
	pos.W = 256;
	pos.H = 32;
	pos.X = 420;
	pos.Y = 572;
	pos.W = 50;
	pos.H = 20;
	screen->AddUITextDisplay(0, 0, pos, "PASSWORD", 1, "", 2, 0);
	pos.X = 360;
	pos.Y = 540;
	pos.W = 256;
	pos.H = 32;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements", dim, 1);
	pos.X = 370;
	pos.Y = 540;
	pos.W = 256;
	pos.H = 32;
	screen->AddUIEditBox(805, 0, pos, "", 0, "", 16);
	dim.X = 0;
	dim.Y = 0;
	dim.W = 256;
	dim.H = 64;
	pos.X = 540;
	pos.Y = 60;
	pos.W = 256;
	pos.H = 64;
	screen->AddUIBitmapB(807, pos, "T_AA2_UI.menu.andromeda", dim, 1);
	pos.X = 224;
	pos.Y = 552;
	pos.W = 68;
	pos.H = 20;
	screen->AddRolloverBitmapButton(14, 2, pos, "T_AA2_UI.menu.hud_menu_elements", dBackButton, 0, "");
	pos.X = 704;
	pos.Y = 552;
	pos.W = 68;
	pos.H = 20;
	screen->AddRolloverBitmapButton(0, 850, pos, "T_AA2_UI.menu.hud_menu_elements", dNextButton, 0, "");
	screen->AddUIEscapeKey(0, 2);
}

void UMainMenuFrame::CreateParentalControlScreen()
{
	UUIScreen* screen = nullptr;
	FPosition pos = FPosition({0,0,0,0});
	FPosition dim = FPosition({0,0,0,0});
	int32 test1 = 0;
	screen = GetScreen(7);
	test1 = 220;
	pos.X = 380;
	pos.Y = 140;
	pos.W = 100;
	pos.H = 20;
	screen->AddUICheckBoxB(321, 0, pos, dCheckBox, "T_AA2_UI.menu.hud_menu_elements", "Language Filter", 0, "", 0, "HumanController", "a");
	pos.Y += 30;
	screen->AddUICheckBoxB(322, 0, pos, dCheckBox, "T_AA2_UI.menu.hud_menu_elements", "No Blood", 0, "", 0, "HumanController", "b");
	pos.Y += 30;
	screen->AddUICheckBoxB(323, 0, pos, dCheckBox, "T_AA2_UI.menu.hud_menu_elements", "MILES Only", 0, "", 0, "HumanController", "c");
	pos.Y += 30;
	screen->AddUICheckBoxB(324, 0, pos, dCheckBox, "T_AA2_UI.menu.hud_menu_elements", "No Advanced Marksman", 0, "", 0, "HumanController", "d");
	pos.X = 222;
	pos.Y = 82 + test1;
	pos.W = 112;
	pos.H = 20;
	screen->AddUITextDisplay(0, 0, pos, "PASSWORD", 1, "", 2, 0);
	pos.X = 222;
	pos.Y = 82 + test1 + 30;
	pos.W = 112;
	pos.H = 20;
	screen->AddUITextDisplay(0, 0, pos, "CONFIRM", 1, "", 2, 0);
	dim.X = 0;
	dim.Y = 116;
	dim.W = 256;
	dim.H = 32;
	pos.X = 380;
	pos.Y = 72 + test1;
	pos.W = 256;
	pos.H = 32;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements", dim, 1);
	pos.Y += 30;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements", dim, 1);
	pos.X = 380;
	pos.Y = 72 + test1;
	pos.W = 256;
	pos.H = 32;
	screen->AddUIEditBox(320, 0, pos, "password", 1, "", 20);
	pos.X = 380;
	pos.Y = 72 + test1 + 30;
	pos.W = 256;
	pos.H = 32;
	screen->AddUIEditBox(328, 0, pos, "password", 1, "", 20);
	pos.X = 380;
	pos.Y = 380;
	pos.W = 256;
	pos.H = 20;
	screen->AddUITextButton(325, 325, pos, "Update", 1, "");
	pos.X = 222;
	pos.Y = 420;
	pos.W = 112;
	pos.H = 20;
	pos.Y += 32;
	screen->AddUITextDisplay(326, 0, pos, "status1", 0, "", 2, 1);
	pos.Y += 32;
	screen->AddUITextDisplay(327, 0, pos, "status2", 0, "", 2, 1);
	pos.X = 224;
	pos.Y = 552;
	pos.W = 68;
	pos.H = 20;
	screen->AddRolloverBitmapButton(14, 7, pos, "T_AA2_UI.menu.hud_menu_elements", dBackButton, 0, "");
	screen->AddUIEscapeKey(0, 7);
}

void UMainMenuFrame::RefreshParentalControlScreen()
{
	UUIControl* Control = nullptr;
	UUIScreen* screen = nullptr;
	screen = GetScreen(7);
	Control = screen->GetControl(321);
	//Cast<UUICheckboxB>(Control)->SetState(GetLanguageFilter());
	Control = screen->GetControl(322);
	//Cast<UUICheckboxB>(Control)->SetState(GetNoBlood());
	Control = screen->GetControl(323);
	//Cast<UUICheckboxB>(Control)->SetState(GetMilesOnly());
	Control = screen->GetControl(324);
	//Cast<UUICheckboxB>(Control)->SetState(GetNoSniper());
	Control = screen->GetControl(320);
	Cast<UUIEditBox>(Control)->SetLabel("");
	Control = screen->GetControl(328);
	Cast<UUIEditBox>(Control)->SetLabel("");
	if (Cast<AHumanController>(Cast<AAGP_HUD>(cHUD)->PlayerOwner)->ParentPassword == "")
	{
		Control = screen->GetControl(325);
		Cast<UUITextButton>(Control)->SetLabel("Set");
		Control = screen->GetControl(326);
		Cast<UUITextDisplay>(Control)->SetLabel("Select your options, enter a password");
		Control = screen->GetControl(327);
		Cast<UUITextDisplay>(Control)->SetLabel("and click Set to set your options.");
	}
	else
	{
		Control = screen->GetControl(325);
		Cast<UUITextButton>(Control)->SetLabel("Update");
		Control = screen->GetControl(326);
		Cast<UUITextDisplay>(Control)->SetLabel("Make any changes you need, enter your password");
		Control = screen->GetControl(327);
		Cast<UUITextDisplay>(Control)->SetLabel("and then click Update to update your settings.");
	}
}

void UMainMenuFrame::ParentAccept()
{
	UUIControl* Control = nullptr;
	UUIScreen* screen = nullptr;
	FString sPassword = "";
	FString sPassword2 = "";
	screen = GetScreen(7);
	Control = screen->GetControl(320);
	sPassword = Cast<UUIEditBox>(Control)->GetLabel();
	Control = screen->GetControl(328);
	sPassword2 = Cast<UUIEditBox>(Control)->GetLabel();
	if (sPassword != sPassword2)
	{
		Control = screen->GetControl(326);
		Cast<UUITextDisplay>(Control)->SetLabel("Passwords did not match.  Please try again.");
		Control = screen->GetControl(327);
		Cast<UUITextDisplay>(Control)->SetLabel("");
		return;
	}
	if (Cast<AHumanController>(Cast<AAGP_HUD>(cHUD)->PlayerOwner)->ParentPassword == "")
	{
		Cast<AHumanController>(Cast<AAGP_HUD>(cHUD)->PlayerOwner)->ParentPassword = sPassword;
		Control = screen->GetControl(321);
		//SetLanguageFilter(Cast<UUICheckboxB>(Control)->IsSelected());
		Control = screen->GetControl(322);
		//SetNoBlood(Cast<UUICheckboxB>(Control)->IsSelected());
		Control = screen->GetControl(323);
		//SetMilesOnly(Cast<UUICheckboxB>(Control)->IsSelected());
		Control = screen->GetControl(324);
		//SetNoSniper(Cast<UUICheckboxB>(Control)->IsSelected());
		Cast<AHumanController>(Cast<AAGP_HUD>(cHUD)->PlayerOwner)->SavePSettings();
		Control = screen->GetControl(326);
		Cast<UUITextDisplay>(Control)->SetLabel("Options are set.  Come back to this page");
		Control = screen->GetControl(327);
		Cast<UUITextDisplay>(Control)->SetLabel("to make any changes in the future.");
	}
	else
	{
		if (Cast<AHumanController>(Cast<AAGP_HUD>(cHUD)->PlayerOwner)->ParentPassword == sPassword)
		{
			Control = screen->GetControl(321);
			//SetLanguageFilter(Cast<UUICheckboxB>(Control)->IsSelected());
			Control = screen->GetControl(322);
			//SetNoBlood(Cast<UUICheckboxB>(Control)->IsSelected());
			Control = screen->GetControl(323);
			//SetMilesOnly(Cast<UUICheckboxB>(Control)->IsSelected());
			Control = screen->GetControl(324);
			//SetNoSniper(Cast<UUICheckboxB>(Control)->IsSelected());
			Cast<AHumanController>(Cast<AAGP_HUD>(cHUD)->PlayerOwner)->SavePSettings();
			Control = screen->GetControl(326);
			Cast<UUITextDisplay>(Control)->SetLabel("Options are updated.  Come back to this page");
			Control = screen->GetControl(327);
			Cast<UUITextDisplay>(Control)->SetLabel("to make any more changes in the future.");
		}
		else
		{
			Control = screen->GetControl(326);
			Cast<UUITextDisplay>(Control)->SetLabel("Password did not match.  Please try again.");
			Control = screen->GetControl(327);
			Cast<UUITextDisplay>(Control)->SetLabel("");
		}
	}
}

void UMainMenuFrame::CreateSettingsScreens()
{
	UUIScreen* screen = nullptr;
	FPosition pos = FPosition({0,0,0,0});
	FPosition dim = FPosition({0,0,0,0});
	screen = GetScreen(4);
	pos.X = 222;
	pos.Y = 82;
	pos.W = 112;
	pos.H = 20;
	screen->AddUITextButton(400, 400, pos, "Player Controls", 1, "");
	pos.X = 224;
	pos.Y = 126;
	pos.W = 160;
	pos.H = 20;
	screen->AddUITextButton(420, 420, pos, "Video Settings", 1, "");
	pos.X = 224;
	pos.Y = 174;
	pos.W = 116;
	pos.H = 20;
	screen->AddUITextButton(430, 430, pos, "Audio Settings", 1, "");
	pos.X = 224;
	pos.Y = 222;
	pos.W = 116;
	pos.H = 20;
	screen->AddUITextButton(440, 440, pos, "HUD Settings", 1, "");
	pos.X = 224;
	pos.Y = 280;
	pos.W = 116;
	pos.H = 20;
	screen->AddUITextButton(450, 450, pos, "Weapon Mod Settings", 1, "");
	pos.X = 224;
	pos.Y = 552;
	pos.W = 68;
	pos.H = 20;
	screen->AddRolloverBitmapButton(14, 7, pos, "T_AA2_UI.menu.hud_menu_elements", dBackButton, 0, "");
	screen->AddUIEscapeKey(0, 7);
	screen = GetScreen(400);
	pos.X = 222;
	pos.Y = 82;
	pos.W = 112;
	pos.H = 20;
	screen->AddUITextButton(410, 410, pos, "View Controls", 1, "");
	pos.X = 224;
	pos.Y = 126;
	pos.W = 160;
	pos.H = 20;
	screen->AddUITextButton(411, 411, pos, "Movement Controls", 1, "");
	pos.X = 224;
	pos.Y = 174;
	pos.W = 116;
	pos.H = 20;
	screen->AddUITextButton(412, 412, pos, "Combat Controls", 1, "");
	pos.X = 223;
	pos.Y = 222;
	pos.W = 116;
	pos.H = 20;
	screen->AddUITextButton(0, 413, pos, "Communication Controls", 1, "");
	pos.X = 223;
	pos.Y = 270;
	pos.W = 116;
	pos.H = 20;
	screen->AddUITextButton(413, 414, pos, "More Controls", 1, "");
	pos.X = 223;
	pos.Y = 338;
	pos.W = 116;
	pos.H = 20;
	screen->AddUITextButton(550, 550, pos, "Reset All Controls To Default Values", 1, "");
	pos.X = 224;
	pos.Y = 552;
	pos.W = 68;
	pos.H = 20;
	screen->AddRolloverBitmapButton(14, 4, pos, "T_AA2_UI.menu.hud_menu_elements", dBackButton, 0, "");
	screen->AddUIEscapeKey(0, 4);
	screen = GetScreen(410);
	pos.X = 448;
	pos.Y = 82;
	pos.W = 256;
	pos.H = 24;
	screen->AddUIKeymap(513, 0, pos, "T_AA2_UI.menu.hud_menu_elements", dKeyMap, "LookUp", 0, "Look Up");
	pos.Y += 30;
	screen->AddUIKeymap(514, 0, pos, "T_AA2_UI.menu.hud_menu_elements", dKeyMap, "LookDown", 0, "Look Down");
	pos.Y += 30;
	screen->AddUIKeymap(515, 0, pos, "T_AA2_UI.menu.hud_menu_elements", dKeyMap, "CenterView", 0, "Center View");
	pos.X = 448;
	pos.Y += 30;
	pos.W = 256;
	pos.H = 12;
	screen->AddUICheckBox(0, 0, pos, dCheckBox, "T_AA2_UI.menu.hud_menu_elements", "Joystick", 0, "", 0, "WindowsClient", "UseJoyStick");
	pos.Y += 30;
	screen->AddUICheckBox(536, 0, pos, dCheckBox, "T_AA2_UI.menu.hud_menu_elements", "Invert Mouse", 1, "", 0, "PlayerInput", "bInvertMouse");
	pos.Y += 30;
	screen->AddUICheckBox(512, 0, pos, dCheckBox, "T_AA2_UI.menu.hud_menu_elements", "Mouse Look", 1, "", 0, "PlayerController", "bAlwaysMouseLook");
	pos.Y += 30;
	pos.W = 252;
	pos.H = 12;
	screen->AddUISlider(516, 0, pos, "T_AA2_UI.menu.hud_menu_elements", dSliderBack, dSliderThumb, "Mouse Sensitivity", 3, "PlayerInput", "MouseSensitivity", 1, 10);
	pos.X = 224;
	pos.Y = 502;
	pos.W = 116;
	pos.H = 20;
	screen->AddUITextButton(551, 551, pos, "Reset To Default Values", 1, "");
	pos.X = 224;
	pos.Y = 552;
	pos.W = 68;
	pos.H = 20;
	screen->AddRolloverBitmapButton(14, 400, pos, "T_AA2_UI.menu.hud_menu_elements", dBackButton, 0, "");
	screen->AddUIEscapeKey(0, 400);
	screen = GetScreen(411);
	pos.X = 448;
	pos.Y = 82;
	pos.W = 256;
	pos.H = 24;
	screen->AddUIKeymap(500, 0, pos, "T_AA2_UI.menu.hud_menu_elements", dKeyMap, "FastMove", 0, "Change Speed");
	pos.Y += 30;
	screen->AddUIKeymap(501, 0, pos, "T_AA2_UI.menu.hud_menu_elements", dKeyMap, "MoveForward", 0, "Move Forward");
	pos.Y += 30;
	screen->AddUIKeymap(502, 0, pos, "T_AA2_UI.menu.hud_menu_elements", dKeyMap, "MoveBackward", 0, "Move Backward");
	pos.Y += 30;
	screen->AddUIKeymap(503, 0, pos, "T_AA2_UI.menu.hud_menu_elements", dKeyMap, "StrafeLeft", 0, "Strafe Left");
	pos.Y += 30;
	screen->AddUIKeymap(504, 0, pos, "T_AA2_UI.menu.hud_menu_elements", dKeyMap, "StrafeRight", 0, "Strafe Right");
	pos.Y += 30;
	screen->AddUIKeymap(505, 0, pos, "T_AA2_UI.menu.hud_menu_elements", dKeyMap, "Jump", 0, "Jump");
	pos.Y += 30;
	screen->AddUIKeymap(506, 0, pos, "T_AA2_UI.menu.hud_menu_elements", dKeyMap, "Crouching", 0, "Crouch");
	pos.Y += 30;
	screen->AddUIKeymap(507, 0, pos, "T_AA2_UI.menu.hud_menu_elements", dKeyMap, "Crawling", 0, "Crawl");
	pos.Y += 30;
	screen->AddUIKeymap(508, 0, pos, "T_AA2_UI.menu.hud_menu_elements", dKeyMap, "TurnLeft", 0, "Turn Left");
	pos.Y += 30;
	screen->AddUIKeymap(509, 0, pos, "T_AA2_UI.menu.hud_menu_elements", dKeyMap, "TurnRight", 0, "Turn Right");
	pos.Y += 30;
	screen->AddUIKeymap(510, 0, pos, "T_AA2_UI.menu.hud_menu_elements", dKeyMap, "Strafe", 0, "Strafe");
	pos.Y += 30;
	screen->AddUIKeymap(537, 0, pos, "T_AA2_UI.menu.hud_menu_elements", dKeyMap, "LeanLeft", 0, "Lean/Roll Left");
	pos.Y += 30;
	screen->AddUIKeymap(538, 0, pos, "T_AA2_UI.menu.hud_menu_elements", dKeyMap, "LeanRight", 0, "Lean/Roll Right");
	pos.Y += 30;
	screen->AddUICheckBox(545, 0, pos, dCheckBox, "T_AA2_UI.menu.hud_menu_elements", "Toggle Lean", 1, "", 0, "HumanController", "bToggleLean");
	pos.X = 223;
	pos.Y = 502;
	pos.W = 116;
	pos.H = 20;
	screen->AddUITextButton(552, 552, pos, "Reset To Default Values", 1, "");
	pos.X = 224;
	pos.Y = 552;
	pos.W = 68;
	pos.H = 20;
	screen->AddRolloverBitmapButton(14, 400, pos, "T_AA2_UI.menu.hud_menu_elements", dBackButton, 0, "");
	screen->AddUIEscapeKey(0, 400);
	screen = GetScreen(412);
	pos.X = 448;
	pos.Y = 82;
	pos.W = 267;
	pos.H = 24;
	screen->AddUIKeymap(517, 0, pos, "T_AA2_UI.menu.hud_menu_elements", dKeyMap, "Fire", 0, "Fire");
	pos.Y += 30;
	screen->AddUIKeymap(518, 0, pos, "T_AA2_UI.menu.hud_menu_elements", dKeyMap, "AltFire", 0, "Alt Fire");
	pos.Y += 30;
	screen->AddUIKeymap(519, 0, pos, "T_AA2_UI.menu.hud_menu_elements", dKeyMap, "SupportedFire", 0, "Supported and M203");
	pos.Y += 30;
	screen->AddUIKeymap(520, 0, pos, "T_AA2_UI.menu.hud_menu_elements", dKeyMap, "Zoom", 0, "Zoom");
	pos.Y += 30;
	screen->AddUIKeymap(521, 0, pos, "T_AA2_UI.menu.hud_menu_elements", dKeyMap, "Reload", 0, "Reload");
	pos.Y += 30;
	screen->AddUIKeymap(522, 0, pos, "T_AA2_UI.menu.hud_menu_elements", dKeyMap, "Fixjam", 0, "Fix Jam");
	pos.Y += 30;
	screen->AddUIKeymap(523, 0, pos, "T_AA2_UI.menu.hud_menu_elements", dKeyMap, "SwapHands", 0, "Swap Hands");
	pos.Y += 30;
	screen->AddUIKeymap(525, 0, pos, "T_AA2_UI.menu.hud_menu_elements", dKeyMap, "SwapAltShoulder", 0, "Javelin Tube");
	pos.Y += 30;
	screen->AddUIKeymap(524, 0, pos, "T_AA2_UI.menu.hud_menu_elements", dKeyMap, "ThrowWeapon", 0, "Throw Weapon");
	pos.Y += 30;
	screen->AddUIKeymap(527, 0, pos, "T_AA2_UI.menu.hud_menu_elements", dKeyMap, "Grenadefrag", 0, "Frag Grenade");
	pos.Y += 30;
	screen->AddUIKeymap(528, 0, pos, "T_AA2_UI.menu.hud_menu_elements", dKeyMap, "Grenadesmoke", 0, "Smoke Grenade");
	pos.Y += 30;
	screen->AddUIKeymap(529, 0, pos, "T_AA2_UI.menu.hud_menu_elements", dKeyMap, "Grenadeflash", 0, "Flash Grenade");
	pos.Y += 30;
	screen->AddUIKeymap(905, 0, pos, "T_AA2_UI.menu.hud_menu_elements", dKeyMap, "GrenadeIncendiary", 0, "Incendiary Grenade");
	pos.Y += 30;
	screen->AddUIKeymap(526, 0, pos, "T_AA2_UI.menu.hud_menu_elements", dKeyMap, "SetSquadTarget", 0, "Set Squad Target");
	pos.Y += 30;
	screen->AddUICheckBoxFn(546, 0, pos, dCheckBox, "T_AA2_UI.menu.hud_menu_elements", "Auto Swap From Grenade", 1, "", 0, "HumanController", "bAutoSwapFromGrenade", "ServerSetAutoSwapFromGrenade");
	pos.X = 223;
	pos.Y = 502;
	pos.W = 116;
	pos.H = 20;
	screen->AddUITextButton(553, 553, pos, "Reset To Default Values", 1, "");
	pos.X = 224;
	pos.Y = 552;
	pos.W = 68;
	pos.H = 20;
	screen->AddRolloverBitmapButton(14, 400, pos, "T_AA2_UI.menu.hud_menu_elements", dBackButton, 0, "");
	screen->AddUIEscapeKey(0, 400);
	screen = GetScreen(413);
	pos.X = 448;
	pos.Y = 82;
	pos.W = 256;
	pos.H = 24;
	pos.Y += 30;
	screen->AddUIKeymap(530, 0, pos, "T_AA2_UI.menu.hud_menu_elements", dKeyMap, "CommoCycle", 0, "Commo Cycle");
	pos.Y += 30;
	screen->AddUIKeymap(532, 0, pos, "T_AA2_UI.menu.hud_menu_elements", dKeyMap, "Talk", 0, "Talk");
	pos.Y += 30;
	screen->AddUIKeymap(533, 0, pos, "T_AA2_UI.menu.hud_menu_elements", dKeyMap, "TeamTalk", 0, "Team Talk");
	pos.Y += 30;
	screen->AddUIKeymap(901, 0, pos, "T_AA2_UI.menu.hud_menu_elements", dKeyMap, "ReportIn", 0, "Report In");
	pos.Y += 30;
	screen->AddUIKeymap(903, 0, pos, "T_AA2_UI.menu.hud_menu_elements", dKeyMap, "CallMedic", 0, "Call for Medic");
	pos.Y += 30;
	screen->AddUIKeymap(902, 0, pos, "T_AA2_UI.menu.hud_menu_elements", dKeyMap, "VoteKick", 0, "Vote Kick");
	pos.Y += 30;
	screen->AddUIKeymap(542, 0, pos, "T_AA2_UI.menu.hud_menu_elements", dKeyMap, "CommoHand", 0, "Commo: Hand");
	pos.Y += 30;
	screen->AddUIKeymap(543, 0, pos, "T_AA2_UI.menu.hud_menu_elements", dKeyMap, "CommoWhisper", 0, "Commo: Whisper");
	pos.Y += 30;
	screen->AddUIKeymap(544, 0, pos, "T_AA2_UI.menu.hud_menu_elements", dKeyMap, "CommoShout", 0, "Commo: Shout");
	pos.Y += 30;
	screen->AddUIKeymap(539, 0, pos, "T_AA2_UI.menu.hud_menu_elements", dKeyMap, "CommoRadio", 0, "Commo: Radio");
	pos.Y += 30;
	screen->AddUIKeymap(540, 0, pos, "T_AA2_UI.menu.hud_menu_elements", dKeyMap, "CommoSquad", 0, "Commo: Squad Radio");
	pos.Y += 30;
	screen->AddUIKeymap(541, 0, pos, "T_AA2_UI.menu.hud_menu_elements", dKeyMap, "CommoGlobal", 0, "Commo: Global");
	pos.X = 223;
	pos.Y = 502;
	pos.W = 116;
	pos.H = 20;
	screen->AddUITextButton(555, 556, pos, "Reset To Default Values", 1, "");
	pos.X = 224;
	pos.Y = 552;
	pos.W = 68;
	pos.H = 20;
	screen->AddRolloverBitmapButton(14, 400, pos, "T_AA2_UI.menu.hud_menu_elements", dBackButton, 0, "");
	screen->AddUIEscapeKey(0, 400);
	screen = GetScreen(414);
	pos.X = 448;
	pos.Y = 82;
	pos.W = 256;
	pos.H = 24;
	screen->AddUIKeymap(511, 0, pos, "T_AA2_UI.menu.hud_menu_elements", dKeyMap, "Action", 0, "Action");
	pos.Y += 30;
	screen->AddUIKeymap(531, 0, pos, "T_AA2_UI.menu.hud_menu_elements", dKeyMap, "NV", 0, "Nightvision");
	pos.Y += 30;
	screen->AddUIKeymap(900, 0, pos, "T_AA2_UI.menu.hud_menu_elements", dKeyMap, "Binoculars", 0, "Binoculars");
	pos.Y += 30;
	screen->AddUIKeymap(534, 0, pos, "T_AA2_UI.menu.hud_menu_elements", dKeyMap, "Pause", 0, "Pause");
	pos.Y += 30;
	screen->AddUIKeymap(535, 0, pos, "T_AA2_UI.menu.hud_menu_elements", dKeyMap, "shot", 0, "Screenshot");
	pos.Y += 30;
	screen->AddUIKeymap(547, 0, pos, "T_AA2_UI.menu.hud_menu_elements", dKeyMap, "Sprint", 0, "Sprint");
	pos.X = 224;
	pos.Y += 40;
	screen->AddUITextDisplay(0, 0, pos, "Skin Color Preference", 1, "", 2, 0);
	pos.X = 448;
	screen->AddUICheckBoxC(700, 0, pos, dCheckBox, "T_AA2_UI.menu.hud_menu_elements", "None", 2, "", 4, "HumanController", "SkinTonePref", "None");
	pos.Y += 30;
	screen->AddUICheckBoxC(701, 0, pos, dCheckBox, "T_AA2_UI.menu.hud_menu_elements", "Light", 2, "", 4, "HumanController", "SkinTonePref", "Light");
	pos.Y += 30;
	screen->AddUICheckBoxC(702, 0, pos, dCheckBox, "T_AA2_UI.menu.hud_menu_elements", "Medium", 2, "", 4, "HumanController", "SkinTonePref", "Medium");
	pos.Y += 30;
	screen->AddUICheckBoxC(703, 0, pos, dCheckBox, "T_AA2_UI.menu.hud_menu_elements", "Dark", 2, "", 4, "HumanController", "SkinTonePref", "Dark");
	dim.X = 0;
	dim.Y = 0;
	dim.W = 32;
	dim.H = 32;
	pos.X = 570;
	pos.Y = 242 + 50;
	pos.W = 100;
	pos.H = 24;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.ui_menu_light", dim, 0);
	pos.X = 570;
	pos.Y = 272 + 50;
	pos.W = 100;
	pos.H = 24;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.ui_menu_med", dim, 0);
	pos.X = 570;
	pos.Y = 302 + 50;
	pos.W = 100;
	pos.H = 24;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.ui_menu_dark", dim, 0);
	pos.X = 223;
	pos.Y = 502;
	pos.W = 116;
	pos.H = 20;
	screen->AddUITextButton(554, 554, pos, "Reset To Default Values", 1, "");
	pos.X = 224;
	pos.Y = 552;
	pos.W = 68;
	pos.H = 20;
	screen->AddRolloverBitmapButton(14, 400, pos, "T_AA2_UI.menu.hud_menu_elements", dBackButton, 0, "");
	screen->AddUIEscapeKey(0, 400);
	screen = GetScreen(420);
	pos.X = 448;
	pos.Y = 84;
	pos.W = 252;
	pos.H = 12;
	screen->AddUISlider(610, 0, pos, "T_AA2_UI.menu.hud_menu_elements", dSliderBack, dSliderThumb, "Gamma", 1, "WindowsClient", "Gamma", 0.5, 1.5);
	pos.Y += 30;
	screen->AddUISlider(611, 0, pos, "T_AA2_UI.menu.hud_menu_elements", dSliderBack, dSliderThumb, "Contrast", 1, "WindowsClient", "Contrast", 0, 1);
	pos.Y += 30;
	screen->AddUISlider(612, 0, pos, "T_AA2_UI.menu.hud_menu_elements", dSliderBack, dSliderThumb, "Brightness", 1, "WindowsClient", "Brightness", 0, 2);
	pos.Y += 30;
	screen->AddUIVideoMode(613, 0, pos, "T_AA2_UI.menu.hud_menu_elements", 0);
	pos.Y += 30;
	screen->AddUICheckBox(618, 0, pos, dCheckBox, "T_AA2_UI.menu.hud_menu_elements", "Start Full Screen", 0, "", 0, "WindowsClient", "StartupFullscreen");
	pos.X = 448;
	pos.Y += 30;
	pos.W = 256;
	pos.H = 12;
	pos.X = 224;
	pos.Y += 30;
	pos.H = 30;
	screen->AddUITextButton(421, 421, pos, "Advanced", 1, "");
	pos.X = 224;
	pos.Y += 30;
	pos.H = 30;
	screen->AddUITextButton(422, 422, pos, "Decals", 1, "");
	pos.X = 274;
	pos.Y = 512;
	pos.W = 116;
	pos.H = 20;
	screen->AddUITextButton(561, 561, pos, "Accept Changes", 1, "");
	pos.X = 474;
	pos.Y = 512;
	pos.W = 116;
	pos.H = 20;
	screen->AddUITextButton(560, 560, pos, "Reset To Default", 1, "");
	pos.X = 240;
	pos.Y = 360;
	pos.W = 550;
	pos.H = 20;
	screen->AddUITextDisplay(0, 0, pos, "Please be aware that the menu resolution will not go below 800x600.", 1, "", 0, 0);
	pos.X = 224;
	pos.Y = 552;
	pos.W = 68;
	pos.H = 20;
	screen->AddRolloverBitmapButton(14, 4, pos, "T_AA2_UI.menu.hud_menu_elements", dBackButton, 0, "");
	screen->AddUIEscapeKey(0, 4);
	screen = GetScreen(421);
	pos.X = 448;
	pos.Y = 84;
	pos.W = 252;
	pos.H = 12;
	screen->AddUICheckBox(600, 0, pos, dCheckBox, "T_AA2_UI.menu.hud_menu_elements", "Reduce Mouse Lag", 0, "", 0, "D3DRenderDevice", "ReduceMouseLag");
	pos.Y += 30;
	screen->AddUICheckBox(601, 0, pos, dCheckBox, "T_AA2_UI.menu.hud_menu_elements", "Use Precaching", 0, "", 0, "D3DRenderDevice", "UsePrecaching");
	pos.Y += 30;
	screen->AddUICheckBox(602, 0, pos, dCheckBox, "T_AA2_UI.menu.hud_menu_elements", "Use Trilinear", 0, "", 0, "D3DRenderDevice", "UseTrilinear");
	pos.Y += 30;
	screen->AddUICheckBox(603, 0, pos, dCheckBox, "T_AA2_UI.menu.hud_menu_elements", "Use Triple Buffering", 0, "", 0, "D3DRenderDevice", "UseTripleBuffering");
	pos.Y += 30;
	screen->AddUICheckBox(604, 0, pos, dCheckBox, "T_AA2_UI.menu.hud_menu_elements", "Use Cubemaps", 0, "", 0, "D3DRenderDevice", "UseCubemaps");
	pos.Y += 30;
	screen->AddUICheckBox(605, 0, pos, dCheckBox, "T_AA2_UI.menu.hud_menu_elements", "Use Compressed Lightmaps", 0, "", 0, "D3DRenderDevice", "UseCompressedLightmaps");
	pos.Y += 30;
	screen->AddUICheckBox(624, 0, pos, dCheckBox, "T_AA2_UI.menu.hud_menu_elements", "No Client Side Effects", 0, "", 0, "HumanController", "bNoClientSideEffects");
	pos.Y += 30;
	screen->AddUISliderSeg(640, 0, pos, "T_AA2_UI.menu.hud_menu_elements", dSliderBack, dSliderThumb, "Interface", 0, "WindowsClient", "TextureDetailInterface", 9);
	pos.Y += 30;
	screen->AddUISliderSeg(641, 0, pos, "T_AA2_UI.menu.hud_menu_elements", dSliderBack, dSliderThumb, "Terrain", 0, "WindowsClient", "TextureDetailTerrain", 9);
	pos.Y += 30;
	screen->AddUISliderSeg(642, 0, pos, "T_AA2_UI.menu.hud_menu_elements", dSliderBack, dSliderThumb, "WeaponSkin", 0, "WindowsClient", "TextureDetailWeaponSkin", 9);
	pos.Y += 30;
	screen->AddUISliderSeg(643, 0, pos, "T_AA2_UI.menu.hud_menu_elements", dSliderBack, dSliderThumb, "PlayerSkin", 0, "WindowsClient", "TextureDetailPlayerSkin", 9);
	pos.Y += 30;
	screen->AddUISliderSeg(644, 0, pos, "T_AA2_UI.menu.hud_menu_elements", dSliderBack, dSliderThumb, "World", 0, "WindowsClient", "TextureDetailWorld", 9);
	pos.Y += 30;
	screen->AddUISliderSeg(645, 0, pos, "T_AA2_UI.menu.hud_menu_elements", dSliderBack, dSliderThumb, "RenderMap", 0, "WindowsClient", "TextureDetailRenderMap", 9);
	pos.Y += 30;
	screen->AddUISliderSeg(646, 0, pos, "T_AA2_UI.menu.hud_menu_elements", dSliderBack, dSliderThumb, "Lightmap", 0, "WindowsClient", "TextureDetailLightmap", 9);
	pos.X = 274;
	pos.Y = 512;
	pos.W = 116;
	pos.H = 20;
	screen->AddUITextButton(563, 563, pos, "Accept Changes", 1, "");
	pos.X = 474;
	pos.Y = 512;
	pos.W = 116;
	pos.H = 20;
	screen->AddUITextButton(562, 562, pos, "Reset To Default", 1, "");
	pos.X = 224;
	pos.Y = 552;
	pos.W = 68;
	pos.H = 20;
	screen->AddRolloverBitmapButton(0, 420, pos, "T_AA2_UI.menu.hud_menu_elements", dBackButton, 0, "");
	screen->AddUIEscapeKey(0, 420);
	screen = GetScreen(422);
	pos.X = 448;
	pos.Y = 84;
	pos.W = 252;
	pos.H = 12;
	screen->AddUISlider(650, 0, pos, "T_AA2_UI.menu.hud_menu_elements", dSliderBack, dSliderThumb, "Decals", 2, "LevelInfo", "KeepDecals", 10, 10000);
	pos.Y += 30;
	screen->AddUISlider(651, 0, pos, "T_AA2_UI.menu.hud_menu_elements", dSliderBack, dSliderThumb, "Decals per Door", 2, "LevelInfo", "KeepDecoDecals", 0, 20);
	pos.Y += 30;
	screen->AddUICheckBox(652, 0, pos, dCheckBox, "T_AA2_UI.menu.hud_menu_elements", "Fade Door Decals", 0, "", 0, "LevelInfo", "bFadeDecoDecals");
	pos.X = 228;
	pos.Y = 185;
	screen->AddUITextDisplay(0, 0, pos, "Decals:", 1, "", 0, 0);
	pos.Y += 40;
	screen->AddUITextDisplay(0, 0, pos, "Decals per Door:", 1, "", 0, 0);
	pos.Y += 25;
	screen->AddUITextDisplay(0, 0, pos, "Fade Door Decals:", 1, "", 0, 0);
	pos.X = 322;
	pos.Y = 185;
	screen->AddUITextDisplay(0, 0, pos, "The maximum number of (non-door) decals before decals will be removed.", 1, "", 0, 0);
	pos.Y += 15;
	screen->AddUITextDisplay(0, 0, pos, "Non-door decals will only be removed while off-screen->", 1, "", 0, 0);
	pos.Y += 25;
	screen->AddUITextDisplay(0, 0, pos, "The maximum number of decals on each door before they will be removed.", 1, "", 0, 0);
	pos.Y += 25;
	screen->AddUITextDisplay(0, 0, pos, "If this is checked, door decals will be removed while on-screen-> (Recommended)", 1, "", 0, 0);
	pos.Y += 15;
	screen->AddUITextDisplay(0, 0, pos, "If this is not checked, door decals will only be removed off-screen->", 1, "", 0, 0);
	pos.X = 274;
	pos.Y = 512;
	pos.W = 116;
	pos.H = 20;
	screen->AddUITextButton(565, 565, pos, "Accept Changes", 1, "");
	pos.X = 474;
	pos.Y = 512;
	pos.W = 116;
	pos.H = 20;
	screen->AddUITextButton(564, 564, pos, "Reset To Default", 1, "");
	pos.X = 224;
	pos.Y = 552;
	pos.W = 68;
	pos.H = 20;
	screen->AddRolloverBitmapButton(0, 420, pos, "T_AA2_UI.menu.hud_menu_elements", dBackButton, 0, "");
	screen->AddUIEscapeKey(0, 420);
	screen = GetScreen(430);
	pos.X = 448;
	pos.Y = 84;
	pos.W = 252;
	pos.H = 12;
	screen->AddUISlider(620, 0, pos, "T_AA2_UI.menu.hud_menu_elements", dSliderBack, dSliderThumb, "Sound Volume", 0, "ALAudioSubsystem", "SoundVolume", 0, 1);
	pos.X = 448;
	pos.Y = 142;
	pos.W = 256;
	pos.H = 12;
	screen->AddUICheckBox(622, 0, pos, dCheckBox, "T_AA2_UI.menu.hud_menu_elements", "Use EAX (Surround Sound)", 0, "", 0, "ALAudioSubsystem", "UseEAX");
	pos.X = 448;
	pos.Y = 172;
	pos.W = 256;
	pos.H = 12;
	screen->AddUICheckBox(623, 0, pos, dCheckBox, "T_AA2_UI.menu.hud_menu_elements", "Reverse Stereo", 0, "", 0, "ALAudioSubsystem", "ReverseStereo");
	dim.X = 0;
	dim.Y = 0;
	dim.W = 256;
	dim.H = 128;
	pos.X = 224;
	pos.Y = 220;
	pos.W = 256;
	pos.H = 128;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.dolbydigitalPC", dim, 1);
	dim.X = 0;
	dim.Y = 0;
	dim.W = 164;
	dim.H = 64;
	pos.X = 500;
	pos.Y = 220;
	pos.W = 164;
	pos.H = 64;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.EAX_3RDPARTY_BORDER_TM", dim, 1);
	pos.X = 240;
	pos.Y = 360;
	pos.W = 550;
	pos.H = 20;
	screen->AddUITextDisplay(0, 0, pos, "NVIDIA® nForce(TM) or other motherboards/soundcards containing the", 1, "", 0, 0);
	pos.X = 230;
	pos.Y = 372;
	pos.W = 550;
	pos.H = 20;
	screen->AddUITextDisplay(0, 0, pos, "Dolby® Digital Interactive Content Encoder required for Dolby Digital audio.", 1, "", 0, 0);
	pos.X = 222;
	pos.Y = 400;
	pos.W = 112;
	pos.H = 20;
	screen->AddUITextDisplay(0, 0, pos, "EAX and Reverse Stereo changes will take effect", 1, "", 2, 0);
	pos.Y += 30;
	screen->AddUITextDisplay(0, 0, pos, "next time the game is restarted.", 1, "", 2, 0);
	pos.X = 274;
	pos.Y = 512;
	pos.W = 116;
	pos.H = 20;
	screen->AddUITextButton(571, 571, pos, "Accept Changes", 1, "");
	pos.X = 474;
	pos.Y = 512;
	pos.W = 116;
	pos.H = 20;
	screen->AddUITextButton(570, 570, pos, "Reset To Default", 1, "");
	pos.X = 224;
	pos.Y = 552;
	pos.W = 68;
	pos.H = 20;
	screen->AddRolloverBitmapButton(14, 4, pos, "T_AA2_UI.menu.hud_menu_elements", dBackButton, 0, "");
	screen->AddUIEscapeKey(0, 4);
	screen = GetScreen(440);
	pos.X = 448;
	pos.Y = 52;
	pos.W = 256;
	pos.H = 24;
	pos.Y += 30;
	screen->AddUICheckBox(630, 0, pos, dCheckBox, "T_AA2_UI.menu.hud_menu_elements", "Hide Ammo Count", 1, "", 0, "PlayerController", "bHUDHideAmmoCount");
	pos.Y += 30;
	screen->AddUICheckBox(631, 0, pos, dCheckBox, "T_AA2_UI.menu.hud_menu_elements", "Hide Weapon Status", 1, "", 0, "PlayerController", "bHUDHideWeaponStatus");
	pos.Y += 30;
	screen->AddUICheckBox(632, 0, pos, dCheckBox, "T_AA2_UI.menu.hud_menu_elements", "Hide Weapon", 1, "", 0, "PlayerController", "bHUDHideWeapon");
	pos.Y += 30;
	screen->AddUICheckBox(633, 0, pos, dCheckBox, "T_AA2_UI.menu.hud_menu_elements", "Hide Grenades", 1, "", 0, "PlayerController", "bHUDHideGrenades");
	pos.Y += 30;
	screen->AddUICheckBox(634, 0, pos, dCheckBox, "T_AA2_UI.menu.hud_menu_elements", "Hide Health", 1, "", 0, "PlayerController", "bHUDHideHealth");
	pos.Y += 30;
	screen->AddUICheckBox(635, 0, pos, dCheckBox, "T_AA2_UI.menu.hud_menu_elements", "Hide Combat Effect", 1, "", 0, "PlayerController", "bHUDHideCombatEffect");
	pos.Y += 30;
	screen->AddUICheckBox(636, 0, pos, dCheckBox, "T_AA2_UI.menu.hud_menu_elements", "Hide Optics", 1, "", 0, "PlayerController", "bHUDHideOptics");
	pos.Y += 30;
	screen->AddUICheckBox(637, 0, pos, dCheckBox, "T_AA2_UI.menu.hud_menu_elements", "Hide Compass", 1, "", 0, "PlayerController", "bHUDHideCompass");
	pos.Y += 30;
	screen->AddUICheckBox(638, 0, pos, dCheckBox, "T_AA2_UI.menu.hud_menu_elements", "Hide Timer", 1, "", 0, "PlayerController", "bHUDHideTimer");
	pos.W = 252;
	pos.H = 12;
	pos.Y += 10;
	pos.Y += 30;
	screen->AddUISlider(615, 0, pos, "T_AA2_UI.menu.hud_menu_elements", dSliderBack, dSliderThumb, "HUD Color", 2, "HumanController", "HUDColor", 0, 255);
	pos.Y += 30;
	screen->AddUISlider(616, 0, pos, "T_AA2_UI.menu.hud_menu_elements", dSliderBack, dSliderThumb, "HUD Alpha", 2, "HumanController", "HUDAlpha", 0, 255);
	pos.X = 224;
	pos.Y += 30;
	screen->AddUITextDisplay(0, 0, pos, "Crosshair", 1, "", 2, 0);
	pos.X = 448;
	pos.Y = 393 + 30;
	pos.W = 42;
	pos.H = 42;
	dim.X = 0;
	dim.Y = 0;
	dim.W = 42;
	dim.H = 42;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_hudcolorbg", dim, 0);
	pos.Y += 5;
	pos.X += 5;
	pos.W = 32;
	pos.H = 32;
	screen->AddHUDBaseDisplay("AGP.HUDMenuCrosshair", 617, pos, 0);
	pos.X = 718;
	pos.Y = 332 + 30;
	pos.W = 42;
	pos.H = 42;
	dim.X = 0;
	dim.Y = 0;
	dim.W = 42;
	dim.H = 42;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_hudcolorbg", dim, 0);
	pos.X = 718;
	pos.Y = 332 + 30;
	pos.W = 42;
	pos.H = 42;
	screen->AddHUDBaseDisplay("AGP.HUDColorDisplay", 0, pos, 0);
	pos.X = 474;
	pos.Y = 512;
	pos.W = 116;
	pos.H = 20;
	screen->AddUITextButton(580, 580, pos, "Reset To Default", 1, "");
	pos.X = 224;
	pos.Y = 552;
	pos.W = 68;
	pos.H = 20;
	screen->AddRolloverBitmapButton(14, 4, pos, "T_AA2_UI.menu.hud_menu_elements", dBackButton, 0, "");
	screen->AddUIEscapeKey(0, 4);
	screen = GetScreen(450);
	pos.X = 468;
	pos.Y = 52;
	pos.W = 256;
	pos.H = 24;
	pos.Y += 30;
	screen->AddUISlider(686, 451, pos, "T_AA2_UI.menu.hud_menu_elements", dSliderBack, dSliderThumb, "Index", 20, "", "", 0, 5);
	pos.X = 320;
	pos.Y += 20;
	screen->AddUITextDisplay(0, 0, pos, "This setting allows you to have several different weapon setups stored    ", 1, "", 0, 0);
	pos.X = 468;
	pos.Y += 45;
	screen->AddUISlider(680, 0, pos, "T_AA2_UI.menu.hud_menu_elements", dSliderBack, dSliderThumb, "Main Rail", 10, "", "0", 0, 1);
	pos.Y += 30;
	screen->AddUISlider(681, 0, pos, "T_AA2_UI.menu.hud_menu_elements", dSliderBack, dSliderThumb, "Top Rail", 11, "", "1", 0, 1);
	pos.Y += 30;
	screen->AddUISlider(682, 0, pos, "T_AA2_UI.menu.hud_menu_elements", dSliderBack, dSliderThumb, "Left Rail", 12, "", "2", 0, 1);
	pos.Y += 30;
	screen->AddUISlider(683, 0, pos, "T_AA2_UI.menu.hud_menu_elements", dSliderBack, dSliderThumb, "Right Rail", 13, "", "3", 0, 1);
	pos.Y += 30;
	screen->AddUISlider(684, 0, pos, "T_AA2_UI.menu.hud_menu_elements", dSliderBack, dSliderThumb, "Bottom", 14, "", "4", 0, 1);
	pos.Y += 30;
	screen->AddUISlider(685, 0, pos, "T_AA2_UI.menu.hud_menu_elements", dSliderBack, dSliderThumb, "Barrel", 15, "", "5", 0, 1);
	pos.X = 320;
	pos.Y += 50;
	screen->AddUITextDisplay(0, 0, pos, "The Reflex sight on the Top Rail is incompatible with the following", 1, "", 0, 0);
	pos.Y += 15;
	screen->AddUITextDisplay(0, 0, pos, "          Anpvs10_Sight        Acog4x       M203_Gren              ", 1, "", 0, 0);
	pos.X = 224;
	pos.Y = 552;
	pos.W = 68;
	pos.H = 20;
	screen->AddRolloverBitmapButton(14, 4, pos, "T_AA2_UI.menu.hud_menu_elements", dBackButton, 0, "");
	screen->AddUIEscapeKey(0, 4);
}

void UMainMenuFrame::CreateCreditsScreens(FString credits, int32 creditnum)
{
	UUIControl* Control = nullptr;
	UUIScreen* screen = nullptr;
	FPosition pos = FPosition({0,0,0,0});
	FString INIfile = "";
	//INIfile = GetBaseDir();
	INIfile = INIfile + credits;
	screen = GetScreen(creditnum);
	pos.X = 300;
	pos.Y = 96;
	pos.W = 400;
	pos.H = 400;
	screen->AddUIScrollingCredits(600, 0, pos, 0);
	Control = screen->GetControl(600);
	Cast<UUIScrollingCredits>(Control)->SetTextFile(INIfile);
	pos.X = 300;
	pos.Y = 76;
	pos.W = 400;
	pos.H = 20;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_backgrnd_02", pos, 0);
	pos.X = 300;
	pos.Y = 476;
	pos.W = 400;
	pos.H = 20;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_backgrnd_02", pos, 0);
	pos.X = 224;
	pos.Y = 552;
	pos.W = 68;
	pos.H = 20;
	screen->AddRolloverBitmapButton(14, 7, pos, "T_AA2_UI.menu.hud_menu_elements", dBackButton, 0, "");
	screen->AddUIEscapeKey(0, 7);
}

void UMainMenuFrame::CreateMessageBox()
{
	UUIScreen* screen = nullptr;
	FPosition pos = FPosition({0,0,0,0});
	FPosition dim = FPosition({0,0,0,0});
	FColor cColor = FColor(0,0,0,0);
	cColor.R = 255;
	cColor.G = 255;
	cColor.B = 255;
	cColor.A = 255;
	AddMessageBox();
	screen = GetMessageBox();
	dim.X = 256;
	dim.Y = 48;
	dim.W = 188;
	dim.H = 112;
	pos.X = 306;
	pos.Y = 244;
	pos.W = 188;
	pos.H = 112;
	screen->AddUIBitmapB(0, pos, "T_AA2_UI.menu.hud_menu_elements", dim, 0);
	pos.X = 306;
	pos.Y = 254;
	pos.W = 188;
	pos.H = 30;
	screen->AddUITextDisplayColor(1000, 0, pos, "Are you sure?", 0, cColor);
	pos.X = 330;
	pos.Y = 310;
	pos.W = 50;
	pos.H = 20;
	screen->AddUITextButton(1001, 1000, pos, "YES", 1, "");
	pos.X = 430;
	pos.Y = 310;
	pos.W = 40;
	pos.H = 20;
	screen->AddUITextButton(1002, 1001, pos, "NO", 1, "");
	screen->AddUIEscapeKey(0, 1001);
}

void UMainMenuFrame::PlayMenuSoundSpecific(USoundBase* Sound)
{
	if (Cast<AAGP_HUD>(cHUD)->PlayerOwner != nullptr && Sound != nullptr)
	{
		//Cast<AAGP_HUD>(cHUD)->PlayerOwner.PlayOwnedSound(Sound, , 1, , 1000000, , false);
	}
}

AServerBrowserBase* UMainMenuFrame::GetCurrentServerBrowser()
{
	if (Cast<AAGP_HUD>(cHUD) != nullptr)
	{
		return Cast<AAGP_HUD>(cHUD)->GetCurrentServerBrowser(false);
	}
	return nullptr;
}

AClientBeaconReceiver* UMainMenuFrame::GetClientBeacon()
{
	if (Cast<AAGP_HUD>(cHUD) != nullptr)
	{
		return Cast<AAGP_HUD>(cHUD)->ClientBeacon;
	}
	return nullptr;
}

void UMainMenuFrame::RunConsoleCommand(FString comm)
{
	if (Cast<AAGP_HUD>(cHUD) != nullptr)
	{
		//Cast<AAGP_HUD>(cHUD)->ConsoleCommand(comm);
	}
}

void UMainMenuFrame::SetDefaultKeyMaps()
{
	SetDefaultMovementKeys();
	SetDefaultViewKeys();
	SetDefaultCombatKeys();
	SetDefaultMiscKeys();
	SetDefaultCommKeys();
}

void UMainMenuFrame::SetDefaultCommKeys()
{
	SetDefaultKey(71, 0, 413, 530);
	SetDefaultKey(84, 0, 413, 532);
	SetDefaultKey(89, 0, 413, 533);
	SetDefaultKey(85, 0, 413, 901);
	SetDefaultKey(77, 0, 413, 903);
	SetDefaultKey(117, 0, 413, 902);
	SetDefaultKey(0, 0, 413, 542);
	SetDefaultKey(0, 0, 413, 543);
	SetDefaultKey(0, 0, 413, 544);
	SetDefaultKey(0, 0, 413, 539);
	SetDefaultKey(0, 0, 413, 540);
	SetDefaultKey(0, 0, 413, 541);
}

void UMainMenuFrame::SetDefaultMovementKeys()
{
	SetDefaultKey(16, 0, 411, 500);
	SetDefaultKey(87, 4, 411, 501);
	SetDefaultKey(83, 0, 411, 502);
	SetDefaultKey(65, 0, 411, 503);
	SetDefaultKey(68, 0, 411, 504);
	SetDefaultKey(32, 0, 411, 505);
	SetDefaultKey(67, 0, 411, 506);
	SetDefaultKey(88, 0, 411, 507);
	SetDefaultKey(37, 0, 411, 508);
	SetDefaultKey(39, 0, 411, 509);
	SetDefaultKey(188, 0, 411, 537);
	SetDefaultKey(190, 0, 411, 538);
	SetCheckBox(411, 545, false);
}

void UMainMenuFrame::SetDefaultViewKeys()
{
	SetDefaultKey(33, 0, 410, 513);
	SetDefaultKey(34, 0, 410, 514);
	SetDefaultKey(35, 0, 410, 515);
	SetCheckBox(410, 536, false);
	SetCheckBox(410, 512, true);
}

void UMainMenuFrame::RefreshViewSettings()
{
	RefreshCheckBox(410, 536);
	RefreshCheckBox(410, 512);
	RefreshSlider(410, 516);
}

void UMainMenuFrame::RefreshMovementSettings()
{
	RefreshCheckBox(411, 545);
}

void UMainMenuFrame::RefreshCombatSettings()
{
	RefreshCheckBoxFn(412, 546);
}

void UMainMenuFrame::RefreshServerBrowser()
{
	RefreshCheckBoxB(202, 829);
}

void UMainMenuFrame::SetDefaultCombatKeys()
{
	SetDefaultKey(1, 0, 412, 517);
	SetDefaultKey(2, 0, 412, 518);
	SetDefaultKey(72, 0, 412, 519);
	SetDefaultKey(90, 0, 412, 520);
	SetDefaultKey(82, 0, 412, 521);
	SetDefaultKey(70, 0, 412, 522);
	SetDefaultKey(49, 0, 412, 523);
	SetDefaultKey(55, 0, 412, 525);
	SetDefaultKey(50, 0, 412, 527);
	SetDefaultKey(51, 0, 412, 528);
	SetDefaultKey(52, 0, 412, 529);
	SetDefaultKey(53, 0, 412, 905);
	SetDefaultKey(79, 0, 412, 526);
	SetCheckBoxFn(412, 546, true);
}

void UMainMenuFrame::SetDefaultMiscKeys()
{
	SetDefaultKey(69, 0, 414, 511);
	SetDefaultKey(86, 0, 414, 531);
	SetDefaultKey(66, 0, 414, 900);
	SetDefaultKey(19, 0, 414, 534);
	SetDefaultKey(120, 0, 414, 535);
	SetDefaultKey(18, 0, 414, 547);
	SetCheckBoxC(414, 700, true);
	SetCheckBoxC(414, 701, false);
	SetCheckBoxC(414, 702, false);
	SetCheckBoxC(414, 703, false);
}

void UMainMenuFrame::SetDefaultKey(int32 key0, int32 key1, int32 screen_id, int32 control_id)
{
	UUIScreen* screen = nullptr;
	UUIKeymap* Control = nullptr;
	screen = GetScreen(screen_id);
	Control = Cast<UUIKeymap>(screen->GetControl(control_id));
	Control->UnbindKeys();
	Control->SetInputKeyPrivate(key0);
	Control->SetInputKeyPrivate(key1);
}

void UMainMenuFrame::InitKeyMap()
{
	SetKeyMap(411, 500);
	SetKeyMap(411, 501);
	SetKeyMap(411, 502);
	SetKeyMap(411, 503);
	SetKeyMap(411, 504);
	SetKeyMap(411, 505);
	SetKeyMap(411, 506);
	SetKeyMap(411, 507);
	SetKeyMap(411, 508);
	SetKeyMap(411, 509);
	SetKeyMap(411, 510);
	SetKeyMap(411, 537);
	SetKeyMap(411, 538);
	SetKeyMap(410, 513);
	SetKeyMap(410, 514);
	SetKeyMap(410, 515);
	SetKeyMap(412, 517);
	SetKeyMap(412, 518);
	SetKeyMap(412, 519);
	SetKeyMap(412, 520);
	SetKeyMap(412, 521);
	SetKeyMap(412, 522);
	SetKeyMap(412, 523);
	SetKeyMap(412, 525);
	SetKeyMap(412, 524);
	SetKeyMap(412, 527);
	SetKeyMap(412, 528);
	SetKeyMap(412, 529);
	SetKeyMap(412, 905);
	SetKeyMap(412, 526);
	SetKeyMap(413, 530);
	SetKeyMap(413, 532);
	SetKeyMap(413, 533);
	SetKeyMap(413, 901);
	SetKeyMap(413, 903);
	SetKeyMap(413, 902);
	SetKeyMap(413, 542);
	SetKeyMap(413, 543);
	SetKeyMap(413, 544);
	SetKeyMap(413, 539);
	SetKeyMap(413, 540);
	SetKeyMap(413, 541);
	SetKeyMap(414, 511);
	SetKeyMap(414, 531);
	SetKeyMap(414, 900);
	SetKeyMap(414, 534);
	SetKeyMap(414, 535);
	SetKeyMap(414, 547);
}

void UMainMenuFrame::SetKeyMap(int32 screen_id, int32 control_id)
{
	UUIScreen* screen = nullptr;
	UUIKeymap* Control = nullptr;
	UConsole* Console = nullptr;;
	FString cmdname = "";
	FString cmdkeyname = "";
	EInputKey cmdkey = EInputKey::IK_None;
	int32 Count = 0;
	screen = GetScreen(screen_id);
	Control = Cast<UUIKeymap>(screen->GetControl(control_id));
	cmdname = Control->GetCommand();
	/*
	if (Cast<AAGP_HUD>(cHUD) != nullptr && Cast<AAGP_HUD>(cHUD)->PlayerOwner != nullptr && Cast<AAGP_HUD>(cHUD)->PlayerOwner.Player != nullptr)
	{
		Console = Cast<AAGP_HUD>(cHUD)->PlayerOwner.Player.Console;
	}
	if (Console != nullptr)
	{
		cmdkeyname = "";
		Count = 0;
		if (Console.GetCommandKey(cmdname, cmdkey, cmdkeyname, Count))
		{
			if (Count == 0 || Count == 1)
			{
				Control->SetInputKey(Count, cmdkey);
				Count++;
			}
			else
			{
				PrivateSet("input " + cmdkeyname + " ");
			}
		}
	}
	*/
}

void UMainMenuFrame::OpenQuickLan(FString serveraddr)
{
	if (Cast<AAGP_HUD>(cHUD)->PawnOwner != nullptr)
	{
		//Cast<AAGP_HUD>(cHUD)->PawnOwner->ConsoleCommand("disconnect");
		ResetActiveScreen();
		Cast<AAGP_HUD>(cHUD)->CloseMainMenu();
		//Cast<AAGP_HUD>(cHUD)->PawnOwner.ConsoleCommand("start " + aserveraddr);
	}
	else
	{
		Cast<AAGP_HUD>(cHUD)->PlayerOwner->ConsoleCommand("disconnect");
		ResetActiveScreen();
		Cast<AAGP_HUD>(cHUD)->CloseMainMenu();
		//Cast<AAGP_HUD>(cHUD)->PlayerOwner->ConsoleCommand("start " + aserveraddr);
	}
}

void UMainMenuFrame::UnbindKey(int32 Key, FString Command)
{
	if (UnbindSpecificKey(Key, Command, 411, 500))
	{
		return;
	}
	if (UnbindSpecificKey(Key, Command, 411, 501))
	{
		return;
	}
	if (UnbindSpecificKey(Key, Command, 411, 502))
	{
		return;
	}
	if (UnbindSpecificKey(Key, Command, 411, 503))
	{
		return;
	}
	if (UnbindSpecificKey(Key, Command, 411, 504))
	{
		return;
	}
	if (UnbindSpecificKey(Key, Command, 411, 505))
	{
		return;
	}
	if (UnbindSpecificKey(Key, Command, 411, 506))
	{
		return;
	}
	if (UnbindSpecificKey(Key, Command, 411, 507))
	{
		return;
	}
	if (UnbindSpecificKey(Key, Command, 411, 508))
	{
		return;
	}
	if (UnbindSpecificKey(Key, Command, 411, 509))
	{
		return;
	}
	if (UnbindSpecificKey(Key, Command, 411, 510))
	{
		return;
	}
	if (UnbindSpecificKey(Key, Command, 411, 537))
	{
		return;
	}
	if (UnbindSpecificKey(Key, Command, 411, 538))
	{
		return;
	}
	if (UnbindSpecificKey(Key, Command, 410, 513))
	{
		return;
	}
	if (UnbindSpecificKey(Key, Command, 410, 514))
	{
		return;
	}
	if (UnbindSpecificKey(Key, Command, 410, 515))
	{
		return;
	}
	if (UnbindSpecificKey(Key, Command, 412, 517))
	{
		return;
	}
	if (UnbindSpecificKey(Key, Command, 412, 518))
	{
		return;
	}
	if (UnbindSpecificKey(Key, Command, 412, 519))
	{
		return;
	}
	if (UnbindSpecificKey(Key, Command, 412, 520))
	{
		return;
	}
	if (UnbindSpecificKey(Key, Command, 412, 521))
	{
		return;
	}
	if (UnbindSpecificKey(Key, Command, 412, 522))
	{
		return;
	}
	if (UnbindSpecificKey(Key, Command, 412, 523))
	{
		return;
	}
	if (UnbindSpecificKey(Key, Command, 412, 525))
	{
		return;
	}
	if (UnbindSpecificKey(Key, Command, 412, 524))
	{
		return;
	}
	if (UnbindSpecificKey(Key, Command, 412, 527))
	{
		return;
	}
	if (UnbindSpecificKey(Key, Command, 412, 528))
	{
		return;
	}
	if (UnbindSpecificKey(Key, Command, 412, 529))
	{
		return;
	}
	if (UnbindSpecificKey(Key, Command, 412, 905))
	{
		return;
	}
	if (UnbindSpecificKey(Key, Command, 412, 526))
	{
		return;
	}
	if (UnbindSpecificKey(Key, Command, 413, 530))
	{
		return;
	}
	if (UnbindSpecificKey(Key, Command, 413, 532))
	{
		return;
	}
	if (UnbindSpecificKey(Key, Command, 413, 533))
	{
		return;
	}
	if (UnbindSpecificKey(Key, Command, 413, 901))
	{
		return;
	}
	if (UnbindSpecificKey(Key, Command, 413, 903))
	{
		return;
	}
	if (UnbindSpecificKey(Key, Command, 413, 902))
	{
		return;
	}
	if (UnbindSpecificKey(Key, Command, 413, 542))
	{
		return;
	}
	if (UnbindSpecificKey(Key, Command, 413, 543))
	{
		return;
	}
	if (UnbindSpecificKey(Key, Command, 413, 544))
	{
		return;
	}
	if (UnbindSpecificKey(Key, Command, 413, 539))
	{
		return;
	}
	if (UnbindSpecificKey(Key, Command, 413, 540))
	{
		return;
	}
	if (UnbindSpecificKey(Key, Command, 413, 541))
	{
		return;
	}
	if (UnbindSpecificKey(Key, Command, 414, 511))
	{
		return;
	}
	if (UnbindSpecificKey(Key, Command, 414, 531))
	{
		return;
	}
	if (UnbindSpecificKey(Key, Command, 414, 900))
	{
		return;
	}
	if (UnbindSpecificKey(Key, Command, 414, 534))
	{
		return;
	}
	if (UnbindSpecificKey(Key, Command, 414, 535))
	{
		return;
	}
	if (UnbindSpecificKey(Key, Command, 414, 547))
	{
		return;
	}
}

bool UMainMenuFrame::UnbindSpecificKey(int32 Key, FString Command, int32 screen_id, int32 control_id)
{
	UUIScreen* screen = nullptr;
	UUIKeymap* Control = nullptr;
	screen = GetScreen(screen_id);
	Control = Cast<UUIKeymap>(screen->GetControl(control_id));
	return Control->UnbindSpecificKey(Key, Command);
}

void UMainMenuFrame::RefreshVideoSettings()
{
	Cast<UUIVideoMode>(GetScreen(420)->GetControl(613))->Refresh();
	RefreshCheckBox(420, 618);
}

void UMainMenuFrame::RefreshVideoAdvancedSettings()
{
	RefreshCheckBox(421, 600);
	RefreshCheckBox(421, 601);
	RefreshCheckBox(421, 602);
	RefreshCheckBox(421, 603);
	RefreshCheckBox(421, 604);
	RefreshCheckBox(421, 605);
	RefreshCheckBox(421, 624);
	RefreshSliderSeg(421, 640);
	RefreshSliderSeg(421, 641);
	RefreshSliderSeg(421, 642);
	RefreshSliderSeg(421, 643);
	RefreshSliderSeg(421, 644);
	RefreshSliderSeg(421, 645);
	RefreshSliderSeg(421, 646);
}

void UMainMenuFrame::RefreshVideoDecalsSettings()
{
	RefreshCheckBox(422, 652);
	RefreshSlider(422, 650);
	RefreshSlider(422, 651);
}

void UMainMenuFrame::RefreshAudioSettings()
{
	RefreshCheckBox(430, 622);
	RefreshCheckBox(430, 623);
}
void UMainMenuFrame::RefreshHUDSettings()
{
	RefreshCheckBox(440, 630);
	RefreshCheckBox(440, 631);
	RefreshCheckBox(440, 632);
	RefreshCheckBox(440, 633);
	RefreshCheckBox(440, 634);
	RefreshCheckBox(440, 635);
	RefreshCheckBox(440, 636);
	RefreshCheckBox(440, 637);
	RefreshCheckBox(440, 638);
	RefreshSlider(440, 615);
	RefreshSlider(440, 616);
	Cast<UHUDMenuCrosshair>(GetScreen(440)->GetControl(617))->Refresh();
}

void UMainMenuFrame::RefreshWeaponModSettings()
{
	UUIScreen* screen = nullptr;
	UUIControl* Control = nullptr;
	AHumanController* HC = nullptr;
	int32 i = 0;
	HC = Cast<AHumanController>(cHUD->PlayerOwner);
	screen = GetScreen(450);
	for (i = 0; i < 6; i++)
	{
		Control = screen->GetControl(680 + i);
		Cast<UUISlider>(Control)->SetMod(HC->WM_Slot[i]);
	}
	Control = screen->GetControl(686);
	Cast<UUISlider>(Control)->SetValue(HC->GetCurrentIndex());
}

void UMainMenuFrame::RefreshCheckBox(int32 screen_id, int32 control_id)
{
	UUIScreen* screen = nullptr;
	UUICheckbox* Control = nullptr;
	screen = GetScreen(screen_id);
	Control = Cast<UUICheckbox>(screen->GetControl(control_id));
	Control->Refresh();
}

void UMainMenuFrame::RefreshCheckBoxB(int32 screen_id, int32 control_id)
{
	UUIScreen* screen = nullptr;
	UUICheckboxB* Control = nullptr;
	screen = GetScreen(screen_id);
	Control = Cast<UUICheckboxB>(screen->GetControl(control_id));
	Control->Refresh();
}

void UMainMenuFrame::RefreshCheckBoxFn(int32 screen_id, int32 control_id)
{
	UUIScreen* screen = nullptr;
	UUICheckboxFn* Control = nullptr;
	screen = GetScreen(screen_id);
	Control = Cast<UUICheckboxFn>(screen->GetControl(control_id));
	Control->Refresh();
}

void UMainMenuFrame::RefreshCheckBoxC(int32 screen_id, int32 control_id)
{
	UUIScreen* screen = nullptr;
	UUICheckboxC* Control = nullptr;
	screen = GetScreen(screen_id);
	Control = Cast<UUICheckboxC>(screen->GetControl(control_id));
	Control->Refresh();
}

void UMainMenuFrame::RefreshSliderSeg(int32 screen_id, int32 control_id)
{
	UUIScreen* screen = nullptr;
	UUISliderSeg* Control = nullptr;
	screen = GetScreen(screen_id);
	Control = Cast<UUISliderSeg>(screen->GetControl(control_id));
	Control->Refresh();
}

void UMainMenuFrame::SetCheckBox(int32 screen_id, int32 control_id, bool Status)
{
	UUIScreen* screen = nullptr;
	UUICheckbox* Control = nullptr;
	screen = GetScreen(screen_id);
	Control = Cast<UUICheckbox>(screen->GetControl(control_id));
	Control->SetState(Status);
}

void UMainMenuFrame::SetCheckBoxB(int32 screen_id, int32 control_id, bool Status)
{
	UUIScreen* screen = nullptr;
	UUICheckboxB* Control = nullptr;
	screen = GetScreen(screen_id);
	Control = Cast<UUICheckboxB>(screen->GetControl(control_id));
	Control->SetState(Status);
}

void UMainMenuFrame::SetCheckBoxFn(int32 screen_id, int32 control_id, bool Status)
{
	UUIScreen* screen = nullptr;
	UUICheckboxFn* Control = nullptr;
	screen = GetScreen(screen_id);
	Control = Cast<UUICheckboxFn>(screen->GetControl(control_id));
	Control->SetState(Status);
}

void UMainMenuFrame::SetCheckBoxC(int32 screen_id, int32 control_id, bool Status)
{
	UUIScreen* screen = nullptr;
	UUICheckboxC* Control = nullptr;
	screen = GetScreen(screen_id);
	Control = Cast<UUICheckboxC>(screen->GetControl(control_id));
	Control->SetState(Status);
}

void UMainMenuFrame::SetSliderSeg(int32 screen_id, int32 control_id, int32 Status)
{
	UUIScreen* screen = nullptr;
	UUISliderSeg* Control = nullptr;
	screen = GetScreen(screen_id);
	Control = Cast<UUISliderSeg>(screen->GetControl(control_id));
	Control->SetVideoLevelInt(Status);
}

void UMainMenuFrame::AcceptCheckBox(int32 screen_id, int32 control_id)
{
	UUIScreen* screen = nullptr;
	UUICheckbox* Control = nullptr;
	screen = GetScreen(screen_id);
	Control = Cast<UUICheckbox>(screen->GetControl(control_id));
	Control->Accept();
}

void UMainMenuFrame::AcceptCheckBoxB(int32 screen_id, int32 control_id)
{
	UUIScreen* screen = nullptr;
	UUICheckboxB* Control = nullptr;
	screen = GetScreen(screen_id);
	Control = Cast<UUICheckboxB>(screen->GetControl(control_id));
	Control->Accept();
}

void UMainMenuFrame::AcceptCheckBoxC(int32 screen_id, int32 control_id)
{
	UUIScreen* screen = nullptr;
	UUICheckboxC* Control = nullptr;
	screen = GetScreen(screen_id);
	Control = Cast<UUICheckboxC>(screen->GetControl(control_id));
	Control->Accept();
}

void UMainMenuFrame::AcceptSliderSeg(int32 screen_id, int32 control_id)
{
	UUIScreen* screen = nullptr;
	UUISliderSeg* Control = nullptr;
	screen = GetScreen(screen_id);
	Control = Cast<UUISliderSeg>(screen->GetControl(control_id));
	Control->Accept();
}

void UMainMenuFrame::AcceptVideoSettings()
{
	AcceptSlider(420, 610);
	AcceptSlider(420, 612);
	AcceptSlider(420, 611);
	AcceptCheckBox(420, 618);
	Cast<UUIVideoMode>(GetScreen(420)->GetControl(613))->Accept();
	RunConsoleCommand("flush");
}

void UMainMenuFrame::AcceptVideoAdvancedSettings()
{
	AcceptCheckBox(421, 600);
	AcceptCheckBox(421, 601);
	AcceptCheckBox(421, 602);
	AcceptCheckBox(421, 603);
	AcceptCheckBox(421, 604);
	AcceptCheckBox(421, 605);
	AcceptCheckBox(421, 624);
	AcceptSliderSeg(421, 640);
	AcceptSliderSeg(421, 641);
	AcceptSliderSeg(421, 642);
	AcceptSliderSeg(421, 643);
	AcceptSliderSeg(421, 644);
	AcceptSliderSeg(421, 645);
	AcceptSliderSeg(421, 646);
	RunConsoleCommand("flush");
}

void UMainMenuFrame::AcceptVideoDecalsSettings()
{
	AcceptCheckBox(422, 652);
	AcceptSlider(422, 650);
	AcceptSlider(422, 652);
}

void UMainMenuFrame::AcceptAudioSettings()
{
	AcceptCheckBox(430, 622);
	AcceptCheckBox(430, 623);
}

void UMainMenuFrame::ResetVideoDefault()
{
	SetSlider(420, 610, 1);
	SetSlider(420, 612, 0.7);
	SetSlider(420, 611, 0.8);
	SetCheckBox(420, 618, true);
	AcceptVideoSettings();
}

void UMainMenuFrame::ResetVideoAdvancedDefault()
{
	SetCheckBox(421, 600, true);
	SetCheckBox(421, 601, true);
	SetCheckBox(421, 602, true);
	SetCheckBox(421, 603, false);
	SetCheckBox(421, 604, true);
	SetCheckBox(421, 605, false);
	SetCheckBox(421, 624, false);
	SetSliderSeg(421, 640, 0);
	SetSliderSeg(421, 641, 4);
	SetSliderSeg(421, 642, 4);
	SetSliderSeg(421, 643, 4);
	SetSliderSeg(421, 644, 4);
	SetSliderSeg(421, 645, 4);
	SetSliderSeg(421, 646, 4);
	AcceptVideoAdvancedSettings();
}

void UMainMenuFrame::ResetVideoDecalsDefault()
{
	SetCheckBox(422, 652, true);
	SetSlider(422, 650, 100);
	SetSlider(422, 651, 10);
}
void UMainMenuFrame::ResetAudioDefault()
{
	SetCheckBox(430, 622, false);
	SetCheckBox(430, 623, false);
}
void UMainMenuFrame::ResetHUDDefault()
{
	SetCheckBox(440, 630, false);
	SetCheckBox(440, 631, false);
	SetCheckBox(440, 632, false);
	SetCheckBox(440, 633, false);
	SetCheckBox(440, 634, false);
	SetCheckBox(440, 635, false);
	SetCheckBox(440, 636, false);
	SetCheckBox(440, 637, false);
	SetCheckBox(440, 638, false);
	AcceptCheckBox(440, 630);
	AcceptCheckBox(440, 631);
	AcceptCheckBox(440, 632);
	AcceptCheckBox(440, 633);
	AcceptCheckBox(440, 634);
	AcceptCheckBox(440, 635);
	AcceptCheckBox(440, 636);
	AcceptCheckBox(440, 637);
	AcceptCheckBox(440, 638);
	SetSlider(440, 615, 100);
	SetSlider(440, 616, 200);
}

void UMainMenuFrame::RefreshSliders()
{
	RefreshSlider(420, 610);
	RefreshSlider(420, 611);
	RefreshSlider(420, 612);
	RefreshSlider(430, 620);
}

void UMainMenuFrame::RefreshControlsMisc()
{
	RefreshCheckBoxC(414, 700);
	RefreshCheckBoxC(414, 701);
	RefreshCheckBoxC(414, 702);
	RefreshCheckBoxC(414, 703);
}

void UMainMenuFrame::AcceptSkinTone()
{
	AcceptCheckBoxC(414, 700);
	AcceptCheckBoxC(414, 701);
	AcceptCheckBoxC(414, 702);
	AcceptCheckBoxC(414, 703);
}

void UMainMenuFrame::RefreshSlider(int32 screen_id, int32 control_id)
{
	UUIScreen* screen = nullptr;
	UUISlider* Control = nullptr;
	screen = GetScreen(screen_id);
	Control = Cast<UUISlider>(screen->GetControl(control_id));
	Control->Refresh();
}

void UMainMenuFrame::SetSlider(int32 screen_id, int32 control_id, float Value)
{
	UUIScreen* screen = nullptr;
	UUISlider* Control = nullptr;
	screen = GetScreen(screen_id);
	Control = Cast<UUISlider>(screen->GetControl(control_id));
	Control->SetValue(Value);
}

void UMainMenuFrame::AcceptSlider(int32 screen_id, int32 control_id)
{
	UUIScreen* screen = nullptr;
	UUISlider* Control = nullptr;
	screen = GetScreen(screen_id);
	Control = Cast<UUISlider>(screen->GetControl(control_id));
	Control->Accept();
}

void UMainMenuFrame::RefreshLoginScreen()
{
	UUIScreen* screen = nullptr;
	UUIControl* Control = nullptr;
	FString sTemp = "";
	screen = GetScreen(201);
	Control = screen->GetControl(300);
	sTemp = Cast<AHumanController>(Cast<AAGP_HUD>(cHUD)->PlayerOwner)->UserName;
	Cast<UUIEditBox>(Control)->SetLabel(sTemp);
	Control = screen->GetControl(301);
	sTemp = Cast<AHumanController>(Cast<AAGP_HUD>(cHUD)->PlayerOwner)->UserPassword;
	Cast<UUIEditBox>(Control)->SetLabel(sTemp);
	Control = screen->GetControl(302);
	sTemp = Cast<AHumanController>(Cast<AAGP_HUD>(cHUD)->PlayerOwner)->sNewsLine1;
	Cast<UUITextDisplay>(Control)->SetLabel(sTemp);
	Control = screen->GetControl(303);
	sTemp = Cast<AHumanController>(Cast<AAGP_HUD>(cHUD)->PlayerOwner)->sNewsLine2;
	Cast<UUITextDisplay>(Control)->SetLabel(sTemp);
	Control = screen->GetControl(304);
	sTemp = Cast<AHumanController>(Cast<AAGP_HUD>(cHUD)->PlayerOwner)->sNewsLine3;
	Cast<UUITextDisplay>(Control)->SetLabel(sTemp);
	Control = screen->GetControl(305);
	sTemp = Cast<AHumanController>(Cast<AAGP_HUD>(cHUD)->PlayerOwner)->sNewsLine4;
	Cast<UUITextDisplay>(Control)->SetLabel(sTemp);
	/*
	if (cHUD.Level.iTour == -1 && cHUD.Level.iMission == -1)
	{
		Control = screen->GetControl(204);
		Cast<UUITextDisplay>(Control)->SetLabel("Not Connected.");
		Control = screen->GetControl(205);
		Control->SetEnabled(true);
	}
	else
	{
		Control = screen->GetControl(204);
		Cast<UUITextDisplay>(Control)->SetLabel("");
		Control = screen->GetControl(205);
		Control->SetEnabled(false);
	}
	*/
}

void UMainMenuFrame::UpdateLoginInfo()
{
	UUIScreen* screen = nullptr;
	UUIControl* Control = nullptr;
	screen = GetScreen(201);
	Control = screen->GetControl(300);
	//PrivateSet("humancontroller username " + Cast<UUIEditBox>(Control)->GetLabel());
	Control = screen->GetControl(301);
	//PrivateSet("humancontroller userpassword " + Cast<UUIEditBox>(Control)->GetLabel());
	Cast<AHumanController>(Cast<AAGP_HUD>(cHUD)->PlayerOwner)->LoadJacket();
	Cast<AHumanController>(Cast<AAGP_HUD>(cHUD)->PlayerOwner)->VerifyJacket();
	Cast<AHumanController>(Cast<AAGP_HUD>(cHUD)->PlayerOwner)->SaveJacket();
	RefreshToursDisplay();
	RefreshTourMissionDisplays();
}

void UMainMenuFrame::SetResolution(int32 X, int32 Y)
{
	if (cHUD != nullptr)
	{
		Cast<AAGP_HUD>(cHUD)->iDesiredXRes = X;
		Cast<AAGP_HUD>(cHUD)->iDesiredYRes = Y;
		if (_iOldSizeX == X && _iOldSizeY == Y)
		{
			return;
		}
	}
	if (X < 800 || Y < 600)
	{
		
	}
	else
	{
		//cHUD.PlayerConsole.ConsoleCommand("setres "$X$"x"$Y);
	}
}

int32 UMainMenuFrame::GetDesiredX()
{
	return Cast<AAGP_HUD>(cHUD)->iDesiredXRes;
}

int32 UMainMenuFrame::GetDesiredY()
{
	return Cast<AAGP_HUD>(cHUD)->iDesiredYRes;
}

void UMainMenuFrame::RefreshToursDisplay()
{
	UUIScreen* screen = nullptr;
	UUIControl* Control = nullptr;
	screen = GetScreen(1);
	Control = screen->GetControl(102);
	Cast<UUIImageListDisplay>(Control)->SetData(0);
	Cast<UUIImageListDisplay>(screen->GetControl(103))->SetData(Cast<UUIImageListDisplay>(Control)->GetIndex());
}

void UMainMenuFrame::RefreshTourMissionDisplays()
{
	UUIScreen* screen = nullptr;
	UUIControl* Control = nullptr;
	int32 iTour = 0;
	int32 iMission = 0;
	screen = GetScreen(1);
	Control = screen->GetControl(102);
	iTour = Cast<UUIImageListDisplay>(Control)->GetIndex();
	iMission = Cast<UUIImageListDisplay>(screen->GetControl(103))->GetIndex();
	Control = screen->GetControl(100);
	/*
	if (cHUD.Level.CanPlayerPlayMissionPrivate(cHUD.PlayerOwner, iTour, iMission))
	{
		Control->SetEnabled(true);
	}
	else
	{
		Control->SetEnabled(false);
	}
	*/
}

void UMainMenuFrame::SetNoTourText(bool bNoTourText)
{
	UUIScreen* screen = nullptr;
	UUIControl* Control = nullptr;
	_bNoTourText = bNoTourText;
	if (_bNoTourText)
	{
		screen = GetScreen(102);
		Control = screen->GetControl(161);
		Control->SetEnabled(false);
		screen = GetScreen(103);
		Control = screen->GetControl(161);
		Control->SetEnabled(false);
		screen = GetScreen(104);
		Control = screen->GetControl(161);
		Control->SetEnabled(false);
	}
	else
	{
		screen = GetScreen(102);
		Control = screen->GetControl(161);
		Control->SetEnabled(true);
		screen = GetScreen(103);
		Control = screen->GetControl(161);
		Control->SetEnabled(true);
		screen = GetScreen(104);
		Control = screen->GetControl(161);
		Control->SetEnabled(true);
	}
}
void UMainMenuFrame::UpdateResumeGame()
{
	UUIScreen* screen = nullptr;
	UUIControl* Control = nullptr;
	screen = GetScreen(0);
	if (GetWorld()->GetNetMode() == ENetMode::NM_Client)
	{
		Control = screen->GetControl(7);
		Control->SetEnabled(true);
		Control = screen->GetControl(17);
		Control->SetEnabled(true);
	}
	else
	{
		if (GetWorld()->GetNetMode() == ENetMode::NM_Standalone)
		{
			Control = screen->GetControl(7);
			/*
			if ((cHUD->Level->iTour != -1) && (cHUD->Level->iMission != -1))
			{
				Control->SetEnabled(true);
			}
			else
			{
				Control->SetEnabled(false);
			}
			*/
			Control = screen->GetControl(17);
			Control->SetEnabled(false);
		}
		else
		{
			Control = screen->GetControl(7);
			Control->SetEnabled(false);
			Control = screen->GetControl(17);
			Control->SetEnabled(false);
		}
	}
}

void UMainMenuFrame::SetSkinTone()
{
	Notify(555);
}

void UMainMenuFrame::SetGameSpyPos(int32 pos)
{
	_fGameSpyPos = pos;
}

int32 UMainMenuFrame::GetGameSpyPos()
{
	return (int32)_fGameSpyPos;
}

void UMainMenuFrame::UpdateGameSpyPos(int32 pos)
{
	UUIScreen* screen = nullptr;
	UUIControl* Control = nullptr;
	if (pos >= 0 && pos <= 100)
	{
		screen = GetScreen(202);
		Control = screen->GetControl(804);
		Cast<UUISliderH>(Control)->SetValue(pos);
		_fGameSpyPos = pos;
	}
}

void UMainMenuFrame::ConnectToGameSpyServer(int32 Index)
{
	if (Cast<AAGP_HUD>(cHUD) != nullptr)
	{
		Cast<AAGP_HUD>(cHUD)->ConnectToGameSpyServer(Index,"",false);
	}
}

void UMainMenuFrame::JoinSelectedServer()
{
	UUIScreen* screen = nullptr;
	UUIControl* Control = nullptr;
	int32 selected = 0;
	screen = GetScreen(202);
	Control = screen->GetControl(850);
	selected = Cast<UUIServerListDisplay>(Control)->GetSelected();
	if (selected != -1)
	{
		ConnectToGameSpyServer(selected);
	}
}

void UMainMenuFrame::ServerBrowserSort(int32 Index)
{
	FString sField = "";
	EGameSpyCompareMode eCompareCode = EGameSpyCompareMode::SORT_INT;
	if (iSortField == 0)
	{
		iSortField = Index;
		bSortAscending = true;
	}
	else
	{
		if (iSortField == Index)
		{
			bSortAscending = !bSortAscending;
		}
		else
		{
			iSortField = Index;
			bSortAscending = true;
		}
	}
	switch(iSortField)
	{
		case 1:
			sField = "hostname";
			eCompareCode = EGameSpyCompareMode::SORT_STR_SENSITIVE;
			break;
		case 2:
			sField = "numplayers";
			eCompareCode = EGameSpyCompareMode::SORT_INT;
			break;
		case 3:
			sField = "ping";
			eCompareCode = EGameSpyCompareMode::SORT_INT;
			break;
		case 4:
			sField = "tour";
			eCompareCode = EGameSpyCompareMode::SORT_INT;
			break;
		case 5:
			sField = "mapname";
			eCompareCode = EGameSpyCompareMode::SORT_STR_INSENSITIVE;
			break;
		default:
			break;
	}
	if (Cast<AAGP_HUD>(cHUD) != nullptr)
	{
		Cast<AAGP_HUD>(cHUD)->SortServers(sField, bSortAscending, eCompareCode);
	}
}

void UMainMenuFrame::SetServerBrowserFilter(FString sFilter)
{
	if (Cast<AAGP_HUD>(cHUD) != nullptr)
	{
		Cast<AAGP_HUD>(cHUD)->SetServerBrowserFilter(sFilter);
	}
}

void UMainMenuFrame::RefreshSelectedServer()
{
	UUIScreen* screen = nullptr;
	UUIControl* Control = nullptr;
	int32 selected = 0;
	screen = GetScreen(202);
	if (screen != nullptr)
	{
		Control = screen->GetControl(850);
	}
	if (Control != nullptr)
	{
		selected = Cast<UUIServerListDisplay>(Control)->GetSelected();
		if (selected != -1)
		{
			Cast<AAGP_HUD>(cHUD)->RefreshSelectedServer(selected);
		}
	}
}

void UMainMenuFrame::SelectLogin()
{
	UUIScreen* screen = nullptr;
	UUIControl* Control = nullptr;
	if (_iLoginStatus == 0)
	{
		screen = GetScreen(201);
		if (screen != nullptr)
		{
			Control = screen->GetControl(300);
			if (Control != nullptr)
			{
				//PrivateSet("humancontroller username " + Cast<UUIEditBox>(Control)->GetLabel());
			}
			Control = screen->GetControl(301);
			if (Control != nullptr)
			{
				//PrivateSet("humancontroller userpassword " + Cast<UUIEditBox>(Control)->GetLabel());
			}
			_iLoginStatus = 1;
		}
	}
	if (_iLoginStatus == 2)
	{
	}
}

void UMainMenuFrame::SetLoginStatus(int32 iStatus, FString sStatus, FString sNavMsg)
{
	UUIScreen* screen = nullptr;
	UUIControl* Control = nullptr;
	FString sTemp = "";
	_iLoginStatus = iStatus;
	screen = GetScreen(201);
	if (screen != nullptr)
	{
		Control = screen->GetControl(204);
	}
	if (Control != nullptr)
	{
		Cast<UUITextDisplay>(Control)->SetLabel(sStatus);
	}
	if (_iLoginStatus == 2)
	{
		_iLoginStatus = 0;
		Control = screen->GetControl(302);
		if (Control != nullptr)
		{
			sTemp = Cast<AHumanController>(Cast<AAGP_HUD>(cHUD)->PlayerOwner)->sNewsLine1;
			Cast<UUITextDisplay>(Control)->SetLabel(sTemp);
		}
		Control = screen->GetControl(303);
		if (Control != nullptr)
		{
			sTemp = Cast<AHumanController>(Cast<AAGP_HUD>(cHUD)->PlayerOwner)->sNewsLine2;
			Cast<UUITextDisplay>(Control)->SetLabel(sTemp);
		}
		Control = screen->GetControl(304);
		if (Control != nullptr)
		{
			sTemp = Cast<AHumanController>(Cast<AAGP_HUD>(cHUD)->PlayerOwner)->sNewsLine3;
			Cast<UUITextDisplay>(Control)->SetLabel(sTemp);
		}
		Control = screen->GetControl(305);
		if (Control != nullptr)
		{
			sTemp = Cast<AHumanController>(Cast<AAGP_HUD>(cHUD)->PlayerOwner)->sNewsLine4;
			Cast<UUITextDisplay>(Control)->SetLabel(sTemp);
		}
	}
}

void UMainMenuFrame::NavigatePlayerList(int32 Direction)
{
	UUIScreen* screen = nullptr;
	UUIControl* Control = nullptr;
	screen = GetScreen(202);
	if (screen != nullptr)
	{
		Control = screen->GetControl(850);
	}
	if (Control != nullptr)
	{
		if (Direction == -1)
		{
			Cast<UUIServerListDisplay>(Control)->PrevPlayerList();
		}
		else
		{
			if (Direction == 1)
			{
				Cast<UUIServerListDisplay>(Control)->NextPlayerList();
			}
		}
	}
}

void UMainMenuFrame::SetNewsLine(int32 Index, FString Text)
{
	UUIScreen* screen = nullptr;
	UUIControl* Control = nullptr;
	if (Index < 0 || Index > 3)
	{
		return;
	}
	screen = GetScreen(201);
	if (screen != nullptr)
	{
		Control = screen->GetControl(302 + Index);
	}
	if (Control != nullptr)
	{
		Cast<UUITextDisplay>(Control)->SetLabel(Text);
	}
}

FString UMainMenuFrame::GetServerPassword()
{
	UUIScreen* screen = nullptr;
	UUIControl* Control = nullptr;
	screen = GetScreen(202);
	if (screen != nullptr)
	{
		Control = screen->GetControl(805);
	}
	if (Control != nullptr)
	{
		return Cast<UUIEditBox>(Control)->GetLabel();
	}
	return "";
}