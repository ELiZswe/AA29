// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/UT2K3GUIPage/UT2SinglePlayerMain/UT2SinglePlayerMain.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUITabControl/GUITabControl.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIBorder/GUITitleBar/GUITitleBar.h"

UUT2SinglePlayerMain::UUT2SinglePlayerMain()
{
	UGUIButton* SPPlay = NewObject<UGUIButton>(UGUIButton::StaticClass());
	SPPlay->Caption = "PLAY";
	SPPlay->StyleName = "SquareMenuButton";
	SPPlay->Hint = "Play the selected match";
	SPPlay->WinTop = 0.93;
	SPPlay->WinLeft = 0.88;
	SPPlay->WinWidth = 0.12;
	SPPlay->WinHeight = 0.055;
	SPPlay->bFocusOnWatch = true;
	//SPPlay->OnClick=UT2SinglePlayerMain.ButtonClick;
	//SPPlay->OnKeyEvent=SPPlay.InternalOnKeyEvent;
	UGUIButton* SPBack = NewObject<UGUIButton>(UGUIButton::StaticClass());
	SPBack->Caption = "MENU";
	SPBack->StyleName = "SquareMenuButton";
	SPBack->Hint = "Return to main menu";
	SPBack->WinTop = 0.93;
	SPBack->WinWidth = 0.12;
	SPBack->WinHeight = 0.055;
	SPBack->bFocusOnWatch = true;
	//SPBack->OnClick=UT2SinglePlayerMain.ButtonClick;
	//SPBack->OnKeyEvent=SPBack.InternalOnKeyEvent;
	UGUITabControl* SPTabs = NewObject<UGUITabControl>(UGUITabControl::StaticClass());
	SPTabs->bFillSpace = true;
	SPTabs->TabHeight = 0.04;
	SPTabs->WinTop = 0.25;
	SPTabs->WinHeight = 48;
	SPTabs->bAcceptsInput = true;
	//SPTabs->OnActivate=SPTabs.InternalOnActivate;
	//SPTabs->OnChange=UT2SinglePlayerMain.TabChange;
	UGUITitleBar* SPHints = NewObject<UGUITitleBar>(UGUITitleBar::StaticClass());
	SPHints->bUseTextHeight = false;
	SPHints->StyleName = "Footer";
	SPHints->WinTop = 0.93;
	SPHints->WinLeft = 0.12;
	SPHints->WinWidth = 0.76;
	SPHints->WinHeight = 0.055;
	UGUITitleBar* SPPageHeader = NewObject<UGUITitleBar>(UGUITitleBar::StaticClass());
	SPPageHeader->Caption = "Single Player";
	SPPageHeader->StyleName = "Header";
	SPPageHeader->WinTop = 0.036406;
	SPPageHeader->WinHeight = 46;
	MessageLadderAvailable = "ladder is now available.";
	MessageLadderComplete = "ladder completed.";
	MessageCreateProfileFirst = "You must create or load a profile before playing.";
	TabNameProfileNew = "Create Profile";
	TabNameProfileLoad = "Manage Profiles";
	TabNameQualification = "Qualification";
	TabNameLadder = "Ladder";
	TabNameRoster = "Roster";
	TabNameTutorials = "Tutorials";
	TabHintProfileNew = "Create a new single player campaign";
	TabHintProfileLoad = "Manage your existing single player campaigns";
	TabHintQualification = "Individual competition to qualify for the Unreal Tournament";
	TabHintLadder = "Team competition in the Unreal Tournament";
	TabHintRoster = "Manage your lineup for the next match";
	TabHintTutorials = "View tutorials for each game type";
	Controls = { SPTabs,SPHints,SPBack,SPPlay,SPPageHeader };
	WinHeight = 1;
}

void UUT2SinglePlayerMain::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	Super::InitComponent(MyController, MyOwner);
	TabC = GUITabControl(Controls[0]);
	ButtonMenu = GUIButton(Controls[2]);
	ButtonPlay = GUIButton(Controls[3]);
	GUITitleBar(Controls[4]).DockedTabs = TabC;
	TP_Profile = Tab_SPPanelBase(TabC.AddTab(TabNameProfileLoad, "xinterface.Tab_SPProfileLoad", , "", true));
	TP_Tutorials = Tab_SPPanelBase(TabC.AddTab(TabNameTutorials, "xinterface.Tab_SPTutorials", , ""));
	TP_Tutorials.MyButton.Hint = TabHintTutorials;
	TP_Qual = Tab_SPPanelBase(TabC.AddTab(TabNameQualification, "xinterface.Tab_SPLadderQualify", , ""));
	TP_Qual.MyButton.Hint = TabHintQualification;
	TP_Ladder = Tab_SPPanelBase(TabC.AddTab(TabNameLadder, "xinterface.Tab_SPLadderTeam", , ""));
	TP_Ladder.MyButton.Hint = TabHintLadder;
	bFinishedPanels = true;
	ProfileUpdated();
	TabC.bDockPanels = true;
	TP_Qual.bAcceptsInput = false;
	TP_Ladder.bAcceptsInput = false;
	*/
}

void UUT2SinglePlayerMain::HandleParameters(FString Param1, FString Param2)
{
	/*
	local GameProfile GP;
	Super::HandleParameters(Param1, Param2);
	GP = PlayerOwner().Level.Game.CurrentGameProfile;
	if (GP != None)
	{
		TP_Qual.bAcceptsInput = true;
		if (GP.ladderrung[1] >= 0)
		{
			TP_Ladder.bAcceptsInput = true;
			TabC.ActivateTab(TP_Ladder.MyButton, true);
		}
		else
		{
			TabC.ActivateTab(TP_Qual.MyButton, true);
		}
		if (GP.SpecialEvent != "")
		{
			HandleSpecialEvent(GP.SpecialEvent);
		}
	}
	*/
}

void UUT2SinglePlayerMain::PopupButton(uint8 yButton)
{
	//PlayerOwner().Level.Game.CurrentGameProfile.SpecialEvent = "";
}

void UUT2SinglePlayerMain::HandleSpecialEvent(FString SpecialEvent)
{
	/*
	local UT2SP_LadderEventPage LPage;
	local UT2SP_PlayerTradePage TPage;
	FString tmp = "";
	Log("SINGLEPLAYER  UT2SinglePlayerMain detected special event of " $ SpecialEvent);
	if (PlayerOwner().Level.Game.CurrentGameProfile != None)
	{
		PlayerOwner().Level.Game.CurrentGameProfile.SpecialEvent = "";
		PlayerOwner().Level.Game.SavePackage(PlayerOwner().Level.Game.CurrentGameProfile.PackageName);
	}
	if (SpecialEvent == "DRAFT")
	{
		Controller.OpenMenu("XInterface.UT2SP_DraftEventPage");
		LPage = UT2SP_LadderEventPage(Controller.ActivePage);
		LPage.gImage.Image = Material(DynamicLoadObject("Laddershots.TeamDMShot", Class'Material', true));
	}
	else
	{
		if (InStr(SpecialEvent, "TRADE") >= 0)
		{
			tmp = Mid(SpecialEvent, 6, Len(SpecialEvent));
			Controller.OpenMenu("XInterface.UT2SP_PlayerTradePage");
			TPage = UT2SP_PlayerTradePage(Controller.ActivePage);
			TPage.Initialize(tmp);
		}
		else
		{
			if (InStr(SpecialEvent, "COMPLETE") >= 0)
			{
				if (Left(SpecialEvent, 5) != "CHAMP")
				{
					Controller.OpenMenu("XInterface.UT2SP_LadderEventPage");
					LPage = UT2SP_LadderEventPage(Controller.ActivePage);
				}
				else
				{
					class'XInterface.Tab_PlayerSettings'.Default.bUnlocked = true;
					class'XInterface.Tab_PlayerSettings'.StaticSaveConfig();
					bAllowedAsLast = true;
					PlayerOwner().Level.Game.CurrentGameProfile.bInLadderGame = false;
					PlayerOwner().ConsoleCommand("START endgame.ut2?quickstart=true?TeamScreen=false?savegame=" $ PlayerOwner().Level.Game.CurrentGameProfile.PackageName);
					Controller.CloseAll(false);
				}
			}
			else
			{
				if (InStr(SpecialEvent, "OPENED") >= 0)
				{
					Controller.OpenMenu("XInterface.UT2SP_LadderEventPage");
					LPage = UT2SP_LadderEventPage(Controller.ActivePage);
				}
			}
		}
	}
	*/
}

void UUT2SinglePlayerMain::ChangeHint(FString NewHint)
{
	//GUITitleBar(Controls[1]).SetCaption(NewHint);
}

bool UUT2SinglePlayerMain::ButtonClick(UGUIComponent* Sender)
{
	/*
	local GameProfile GP;
	local LevelInfo myLevel;
	local GUIQuestionPage GPage;
	if (Sender == ButtonMenu)
	{
		Controller.CloseMenu();
	}
	else
	{
		if (Sender == ButtonPlay)
		{
			GP = PlayerOwner().Level.Game.CurrentGameProfile;
			if (GP != None)
			{
				PlayerOwner().Level.Game.SavePackage(GP.PackageName);
				if (((GP.CurrentLadder > 0) || ((GP.CurrentLadder == 0) && (GP.CurrentMenuRung == 5))) && (GP.PlayerTeam[0] == ""))
				{
					HandleSpecialEvent("DRAFT");
					return true;
				}
				myLevel = PlayerOwner().Level;
				TabC.ActivateTab(TP_Ladder.MyButton, true);
				Controller.CloseAll(false);
				GP.StartNewMatch(GP.CurrentLadder, myLevel);
			}
			else
			{
				if (Controller.OpenMenu("XInterface.GUIQuestionPage"))
				{
					GPage = GUIQuestionPage(Controller.TopPage());
					GPage.SetupQuestion(MessageCreateProfileFirst, 1, 1);
				}
			}
		}
	}
	*/
	return true;
}

void UUT2SinglePlayerMain::TabChange(UGUIComponent* Sender)
{
	/*
	if (GUITabButton(Sender) == nullptr)
	{
		return;
	}
	ResetTitleBar(GUITabButton(Sender));
	*/
}

void UUT2SinglePlayerMain::ResetTitleBar(UGUITabButton* TB)
{
	/*
	if (PlayerOwner().Level.Game.CurrentGameProfile != None)
	{
		GUITitleBar(Controls[4]).SetCaption(GUITitleBar(Default.Controls[4]).GetCaption() @ "|" @ PlayerOwner().Level.Game.CurrentGameProfile.PlayerName @ "|" @ TB.Caption);
	}
	else
	{
		GUITitleBar(Controls[4]).SetCaption(GUITitleBar(Default.Controls[4]).GetCaption() @ "|" @ TB.Caption);
	}
	*/
}

void UUT2SinglePlayerMain::BoxChange(UGUIComponent* Sender)
{
	//HandleSpecialEvent(moComboBox(Sender).GetText());
}

void UUT2SinglePlayerMain::PassThroughProfileUpdated()
{
	//TP_Qual.ProfileUpdated();
}

void UUT2SinglePlayerMain::ProfileUpdated()
{
	/*
	local GameProfile GP;
	bool bRosterOn = false;
	if ((TabC != None) && (TabC.ActiveTab != None))
	{
		ResetTitleBar(TabC.ActiveTab);
	}
	if (!bFinishedPanels)
	{
		return;
	}
	GP = PlayerOwner().Level.Game.CurrentGameProfile;
	if (GP == nullptr)
	{
		bRosterOn = false;
	}
	else
	{
		bRosterOn = (GP.PlayerTeam[0] != "");
	}
	if (bRosterOn)
	{
		if (TP_Roster == nullptr)
		{
			TP_Roster = Tab_SPPanelBase(TabC.AddTab(TabNameRoster, "xinterface.Tab_SPRoster", , ""));
			TP_Roster.MyButton.Hint = TabHintRoster;
		}
	}
	else
	{
		if (TP_Roster != None)
		{
			TabC.RemoveTab(TabNameRoster);
			TP_Roster = nullptr;
		}
	}
	*/
}