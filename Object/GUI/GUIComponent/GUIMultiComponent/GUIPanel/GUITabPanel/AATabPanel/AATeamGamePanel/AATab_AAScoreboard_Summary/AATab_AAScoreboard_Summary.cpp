// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AATeamGamePanel/AATab_AAScoreboard_Summary/AATab_AAScoreboard_Summary.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIContentBox/GUIContentBox.h"

UAATab_AAScoreboard_Summary::UAATab_AAScoreboard_Summary()
{
	UGUIImage* MyBackground = NewObject<UGUIImage>(UGUIImage::StaticClass());
	//MyBackground->Image=Texture'T_AA2_UI.Menu.backgroundfill';
	MyBackground->ImageStyle = EImgStyle::ISTY_Stretched;
	MyBackground->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	MyBackground->WinWidth=0.98;
	MyBackground->WinHeight=0.89;
	MyBackground->RenderWeight=0;
	MyBackground->bBoundToParent=true;
	MyBackground->bScaleToParent=true;
	UGUIContentBox* MyPanel = NewObject<UGUIContentBox>(UGUIContentBox::StaticClass());
	MyPanel->ItemSpacing=0;
	MyPanel->bCenterItems=true;
	MyPanel->WinTop=0.005;
	MyPanel->WinWidth=0.98;
	MyPanel->WinHeight=0.8815;
	MyPanel->RenderWeight=0.01;
	MyPanel->bBoundToParent=true;
	MyPanel->bScaleToParent=true;
	MyPanel->bAcceptsInput=false;
	MyPanel->bNeverFocus=true;

	i_Background = MyBackground;
	cb_MainWindow = MyPanel;
	bAlwaysAutomate = true;
	WinTop = 0.03;
	bNeverFocus = true;
	//OnPreDraw = AATab_AAScoreboard_Summary.InternalOnPreDraw;
	//OnDraw = AATab_AAScoreboard_Summary.InternalOnDraw;
}

void UAATab_AAScoreboard_Summary::InitGrid(int32 TeamID)
{
	/*
	local XInterface.GUIImage Spacer;
	Grid = GUIGridLayout(cb_MainWindow.addItem("AGP_Interface.GUIGridLayout"));
	Grid.bAcceptsInput = false;
	Grid.bNeverFocus = true;
	Grid.InitializeControls();
	Grid.RowSpacing = 0.02;
	if (TeamID == 0)
	{
		Spacer = GUIImage(Grid.CreateItem("XInterface.GUIImage", 1));
		l_Assault = AAGUILabel(Grid.CreateItem("AGP_Interface.AAGUILabel", 1));
		lb_UnitAssault = GUIMultiColumnListBox(Grid.CreateItem("AGP_Interface.AAListBox_AutoScaleAssaultTeam", 1));
		Spacer = GUIImage(Grid.CreateItem("XInterface.GUIImage", 1));
		l_Defense = AAGUILabel(Grid.CreateItem("AGP_Interface.AAGUILabel", 1));
		lb_UnitDefense = GUIMultiColumnListBox(Grid.CreateItem("AGP_Interface.AAListBox_AutoScaleDefenseTeam", 1));
		Spacer = GUIImage(Grid.CreateItem("XInterface.GUIImage", 1));
		l_Spectator = AAGUILabel(Grid.CreateItem("AGP_Interface.AAGUILabel", 1));
		lb_UnitSpectator = GUIMultiColumnListBox(Grid.CreateItem("AGP_Interface.AAListBox_AutoScaleSpectatorTeam", 1));
		Spacer = GUIImage(Grid.CreateItem("XInterface.GUIImage", 1));
	}
	else
	{
		Spacer = GUIImage(Grid.CreateItem("XInterface.GUIImage", 1));
		l_Defense = AAGUILabel(Grid.CreateItem("AGP_Interface.AAGUILabel", 1));
		lb_UnitDefense = GUIMultiColumnListBox(Grid.CreateItem("AGP_Interface.AAListBox_AutoScaleDefenseTeam", 1));
		Spacer = GUIImage(Grid.CreateItem("XInterface.GUIImage", 1));
		l_Assault = AAGUILabel(Grid.CreateItem("AGP_Interface.AAGUILabel", 1));
		lb_UnitAssault = GUIMultiColumnListBox(Grid.CreateItem("AGP_Interface.AAListBox_AutoScaleAssaultTeam", 1));
		Spacer = GUIImage(Grid.CreateItem("XInterface.GUIImage", 1));
		l_Spectator = AAGUILabel(Grid.CreateItem("AGP_Interface.AAGUILabel", 1));
		lb_UnitSpectator = GUIMultiColumnListBox(Grid.CreateItem("AGP_Interface.AAListBox_AutoScaleSpectatorTeam", 1));
		Spacer = GUIImage(Grid.CreateItem("XInterface.GUIImage", 1));
	}
	l_Assault.WinWidth = 0.8;
	l_Assault.TextFont = "AAFontMedium";
	l_Assault.TextColor.R = 150;
	l_Assault.TextColor.G = 30;
	l_Assault.TextColor.B = 50;
	l_Assault.TextColor.A = 255;
	l_Assault.TextAlign = 0;
	l_Assault.Caption = "Assault";
	l_Defense.WinWidth = 0.8;
	l_Defense.TextFont = "AAFontMedium";
	l_Defense.TextColor.R = 82;
	l_Defense.TextColor.G = 82;
	l_Defense.TextColor.B = 159;
	l_Defense.TextColor.A = 255;
	l_Defense.TextAlign = 0;
	l_Defense.Caption = "Defense";
	l_Spectator.WinWidth = 0.8;
	l_Spectator.TextFont = "AAFontMedium";
	l_Spectator.TextColor.R = 116;
	l_Spectator.TextColor.G = 179;
	l_Spectator.TextColor.B = 125;
	l_Spectator.TextColor.A = 255;
	l_Spectator.TextAlign = 0;
	l_Spectator.Caption = "SPECTATORS";
	lb_UnitAssault.WinWidth = 0.95;
	lb_UnitDefense.WinWidth = 0.95;
	lb_UnitSpectator.WinWidth = 0.95;
	AAScoreboard_AutoScaleTeamSummary(lb_UnitSpectator.List).bIsSpectatorPanel = true;
	*/
}

void UAATab_AAScoreboard_Summary::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	Super::InitComponent(MyController, MyOwner);
	LastTeamID = PlayerOwner().PlayerReplicationInfo.Team.TeamIndex;
	cb_MainWindow.MyPanel.bCenterItems = false;
	cb_MainWindow.MyPanel.bScaleItemsToWidth = false;
	cb_MainWindow.MyPanel.ItemSpacing = 0;
	InitGrid(0);
	*/
}

bool UAATab_AAScoreboard_Summary::InternalOnPreDraw(UCanvas* C)
{
	/*
	int32 numUnassignedTeam0 = 0;
	int32 numUnassignedTeam1 = 0;
	int32 numAssignedTeam0 = 0;
	int32 numAssignedTeam1 = 0;
	int32 i = 0;
	local GameReplicationInfo GRI;
	local HumanController HC;
	numUnassignedTeam0 = 0;
	numUnassignedTeam1 = 0;
	numAssignedTeam0 = 0;
	numAssignedTeam1 = 0;
	if (LastTeamID != PlayerOwner().PlayerReplicationInfo.Team.TeamIndex)
	{
		cb_MainWindow.RemoveItem(Grid);
		if (PlayerOwner().PlayerReplicationInfo.Team.TeamIndex == 1)
		{
			InitGrid(1);
		}
		else
		{
			InitGrid(0);
		}
		LastTeamID = PlayerOwner().PlayerReplicationInfo.Team.TeamIndex;
	}
	if (PlayerOwner() != None)
	{
		GRI = PlayerOwner().GameReplicationInfo;
	}
	if (GRI == nullptr)
	{
		return false;
	}
	HC = HumanController(PlayerOwner());
	l_Assault.Caption = PlayerOwner().Level.TeamName[0];
	l_Defense.Caption = PlayerOwner().Level.TeamName[1];
	if ((HC != None) && HC.bTournamentServer)
	{
		if (HC.GetTeamName(0) != "")
		{
			l_Assault.Caption $ = "[" $ HC.GetTeamName(0) $ "]";
		}
		if (HC.GetTeamName(1) != "")
		{
			l_Defense.Caption $ = "[" $ HC.GetTeamName(1) $ "]";
		}
	}
	if (GRI.Teams[0] != None)
	{
		l_Assault.Caption $ = " " $ string(GRI.Teams[0].teamScore) $ "/" $ string(GRI.RoundsPerMatch);
	}
	if (GRI.Teams[1] != None)
	{
		l_Defense.Caption $ = " " $ string(GRI.Teams[1].teamScore) $ "/" $ string(GRI.RoundsPerMatch);
	}
	for (i = 0; i < GRI.PRIArray.Length; i++)
	{
		if (AGP_TeamInfo(GRI.PRIArray[i].Team).GetPlayerIndex(GRI.PRIArray[i]) == -1)
		{
			if (GRI.PRIArray[i].Team.TeamIndex == 0)
			{
				numUnassignedTeam0++;
			}
			else
			{
				if (GRI.PRIArray[i].Team.TeamIndex == 1)
				{
					numUnassignedTeam1++;
				}
			}
		}
		else
		{
			if (GRI.PRIArray[i].Team.TeamIndex == 0)
			{
				numAssignedTeam0++;
			}
			else
			{
				if (GRI.PRIArray[i].Team.TeamIndex == 1)
				{
					numAssignedTeam1++;
				}
			}
		}
	}
	if (numUnassignedTeam0 > 0)
	{
		numUnassignedTeam0 += 2;
	}
	if (numUnassignedTeam1 > 0)
	{
		numUnassignedTeam1 += 2;
	}
	if ((numAssignedTeam0 + numUnassignedTeam0) < 4)
	{
		AAScoreboard_AutoScaleTeamSummary(lb_UnitAssault.List).MaxVisibleTeamEntries = 6;
		lb_UnitAssault.WinHeight = (((4 * MenuOwner.MenuOwner.WinHeight) * 0.0208) + (MenuOwner.MenuOwner.WinHeight * 0.055));
	}
	else
	{
		AAScoreboard_AutoScaleTeamSummary(lb_UnitAssault.List).MaxVisibleTeamEntries = ((numAssignedTeam0 + numUnassignedTeam0) + 3);
		lb_UnitAssault.WinHeight = ((MenuOwner.MenuOwner.WinHeight * 0.055) + ((float((numAssignedTeam0 + numUnassignedTeam0)) * MenuOwner.MenuOwner.WinHeight) * 0.0208));
	}
	if ((numAssignedTeam1 + numUnassignedTeam1) < 4)
	{
		AAScoreboard_AutoScaleTeamSummary(lb_UnitDefense.List).MaxVisibleTeamEntries = 6;
		lb_UnitDefense.WinHeight = (((4 * MenuOwner.MenuOwner.WinHeight) * 0.0208) + (MenuOwner.MenuOwner.WinHeight * 0.055));
	}
	else
	{
		AAScoreboard_AutoScaleTeamSummary(lb_UnitDefense.List).MaxVisibleTeamEntries = ((numAssignedTeam1 + numUnassignedTeam1) + 3);
		lb_UnitDefense.WinHeight = ((MenuOwner.MenuOwner.WinHeight * 0.055) + ((float((numAssignedTeam1 + numUnassignedTeam1)) * MenuOwner.MenuOwner.WinHeight) * 0.0208));
	}
	if (GRI.SpecTeam.Size < 4)
	{
		AAScoreboard_AutoScaleTeamSummary(lb_UnitSpectator.List).MaxVisibleTeamEntries = 6;
		lb_UnitSpectator.WinHeight = (((4 * MenuOwner.MenuOwner.WinHeight) * 0.0208) + (MenuOwner.MenuOwner.WinHeight * 0.055));
	}
	else
	{
		AAScoreboard_AutoScaleTeamSummary(lb_UnitSpectator.List).MaxVisibleTeamEntries = (GRI.SpecTeam.Size + 3);
		lb_UnitSpectator.WinHeight = ((MenuOwner.MenuOwner.WinHeight * 0.055) + ((float(GRI.SpecTeam.Size) * MenuOwner.MenuOwner.WinHeight) * 0.0208));
	}
	*/
	return true;
}

bool UAATab_AAScoreboard_Summary::ButtonClick(UGUIComponent* Sender)
{
	return true;
}

bool UAATab_AAScoreboard_Summary::CanShowPanel()
{
	/*
	local GameReplicationInfo GRI;
	if (PlayerOwner() != None)
	{
		GRI = PlayerOwner().GameReplicationInfo;
		if (GRI != None)
		{
			return ((GRI.bShouldShowScoreboard || PlayerOwner().PlayerReplicationInfo.bAdmin) || PlayerOwner().PlayerReplicationInfo.bOnlySpectator);
		}
	}
	*/
	return false;      //FAKE   /ELiZ
}

bool UAATab_AAScoreboard_Summary::InternalOnDraw(UCanvas* C)
{
	/*
	OnActivate();
	AAScoreboard_AutoScaleTeamSummary(lb_UnitAssault.List).renderCounter = 0;
	AAScoreboard_AutoScaleTeamSummary(lb_UnitDefense.List).renderCounter = 0;
	AAScoreboard_AutoScaleTeamSummary(lb_UnitSpectator.List).renderCounter = 0;
	return OnDraw(C);
	*/
	return false;      //FAKE   /ELiZ
}