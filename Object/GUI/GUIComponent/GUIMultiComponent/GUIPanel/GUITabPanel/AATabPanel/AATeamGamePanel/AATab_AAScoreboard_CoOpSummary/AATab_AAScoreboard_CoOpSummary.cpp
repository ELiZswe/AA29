// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AATeamGamePanel/AATab_AAScoreboard_CoOpSummary/AATab_AAScoreboard_CoOpSummary.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIContentBox/GUIContentBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUIGridLayout/GUIGridLayout.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIMultiColumnListBox/GUIMultiColumnListBox.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/GameReplicationInfo/GameReplicationInfo.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/TeamInfo/AGP_TeamInfo/AGP_TeamInfo.h"
#include "Engine/Canvas.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/AAGUILabel/AAGUILabel.h"

UAATab_AAScoreboard_CoOpSummary::UAATab_AAScoreboard_CoOpSummary()
{
	UGUIImage* MyBackground = NewObject<UGUIImage>(UGUIImage::StaticClass());
	//MyBackground->Image=Texture'T_AA2_UI.Menu.backgroundfill';
	MyBackground->ImageStyle = EImgStyle::ISTY_Stretched;
	MyBackground->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	MyBackground->WinWidth = 0.98;
	MyBackground->WinHeight = 0.89;
	MyBackground->RenderWeight = 0;
	MyBackground->bBoundToParent = true;
	MyBackground->bScaleToParent = true;
	UGUIContentBox* MyPanel = NewObject<UGUIContentBox>(UGUIContentBox::StaticClass());
	MyPanel->ItemSpacing = 0;
	MyPanel->bCenterItems = true;
	MyPanel->WinTop = 0.005;
	MyPanel->WinWidth = 0.98;
	MyPanel->WinHeight = 0.8815;
	MyPanel->RenderWeight = 0.01;
	MyPanel->bBoundToParent = true;
	MyPanel->bScaleToParent = true;
	MyPanel->bAcceptsInput = false;
	MyPanel->bNeverFocus = true;

	i_Background = MyBackground;
	cb_MainWindow = MyPanel;
	bAlwaysAutomate = true;
	WinTop = 0.03;
	bNeverFocus = true;
	//OnPreDraw = AATab_AAScoreboard_CoOpSummary.InternalOnPreDraw;
	//OnDraw = AATab_AAScoreboard_CoOpSummary.InternalOnDraw;
}

void UAATab_AAScoreboard_CoOpSummary::InitGrid(int32 TeamID)
{
	UGUIImage* Spacer = nullptr;
	/*
	Grid = GUIGridLayout(cb_MainWindow.addItem("AGP_Interface.GUIGridLayout"));
	Grid->bAcceptsInput = false;
	Grid->bNeverFocus = true;
	Grid->InitializeControls();
	Grid->RowSpacing = 0.02;
	Spacer = Cast<UGUIImage>(Grid->CreateItem("XInterface.GUIImage", 1));
	l_Assault = Cast<UAAGUILabel>(Grid->CreateItem("AGP_Interface.AAGUILabel", 1));
	lb_UnitAssault = Cast<UGUIMultiColumnListBox>(Grid->CreateItem("AGP_Interface.AAListBox_AutoScaleAssaultTeam", 1));
	Spacer = Cast<UGUIImage>(Grid->CreateItem("XInterface.GUIImage", 1));
	l_Spectator = Cast<UAAGUILabel>(Grid->CreateItem("AGP_Interface.AAGUILabel", 1));
	lb_UnitSpectator = Cast<UGUIMultiColumnListBox>(Grid->CreateItem("AGP_Interface.AAListBox_AutoScaleSpectatorTeam", 1));
	Spacer = Cast<UGUIImage>(Grid->CreateItem("XInterface.GUIImage", 1));
	l_Assault.WinWidth = 0.8;
	l_Assault.TextFont = "AAFontMedium";
	l_Assault.TextColor.R = 150;
	l_Assault.TextColor.G = 30;
	l_Assault.TextColor.B = 50;
	l_Assault.TextColor.A = 255;
	l_Assault.TextAlign = 0;
	l_Assault.Caption = "Assault";
	l_Spectator.WinWidth = 0.8;
	l_Spectator.TextFont = "AAFontMedium";
	l_Spectator.TextColor.R = 116;
	l_Spectator.TextColor.G = 179;
	l_Spectator.TextColor.B = 125;
	l_Spectator.TextColor.A = 255;
	l_Spectator.TextAlign = 0;
	l_Spectator.Caption = "SPECTATORS";
	lb_UnitAssault.WinWidth = 0.95;
	lb_UnitSpectator.WinWidth = 0.95;
	AAScoreboard_AutoScaleTeamSummary(lb_UnitSpectator.List).bIsSpectatorPanel = true;
	*/
}

void UAATab_AAScoreboard_CoOpSummary::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
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

bool UAATab_AAScoreboard_CoOpSummary::InternalOnPreDraw(UCanvas* C)
{
	/*
	int32 numUnassignedTeam0 = 0;
	int32 numUnassignedTeam1 = 0;
	int32 numAssignedTeam0 = 0;
	int32 numAssignedTeam1 = 0;
	int32 i = 0;
	AGameReplicationInfo* GRI = nullptr;
	AHumanController* HC = nullptr;
	numUnassignedTeam0 = 0;
	numAssignedTeam0 = 0;
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
	if (PlayerOwner() != nullptr)
	{
		GRI = PlayerOwner().GameReplicationInfo;
	}
	if (GRI == nullptr)
	{
		return false;
	}
	HC = Cast<AHumanController>(PlayerOwner());
	l_Assault.Caption = PlayerOwner().Level.TeamName[0];
	if ((HC != nullptr) && HC.bTournamentServer)
	{
		if (HC.GetTeamName(0) != "")
		{
			l_Assault.Caption += "[" + HC.GetTeamName(0) + "]";
		}
	}
	if (GRI.Teams[0] != nullptr)
	{
		l_Assault.Caption += " " + FString::FromInt(GRI.Teams[0].teamScore) + "/" + FString::FromInt(GRI.RoundsPerMatch);
	}
	for (i = 0; i < GRI.PRIArray.Num(); i++)
	{
		if (Cast<AAGP_TeamInfo>(GRI.PRIArray[i].Team).GetPlayerIndex(GRI.PRIArray[i]) == -1)
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
	if ((numAssignedTeam0 + numUnassignedTeam0) < 14)
	{
		AAScoreboard_AutoScaleTeamSummary(lb_UnitAssault.List).MaxVisibleTeamEntries = 15;
		lb_UnitAssault.WinHeight = (((13 * MenuOwner.MenuOwner.WinHeight) * 0.0208) + (MenuOwner.MenuOwner.WinHeight * 0.055));
	}
	else
	{
		AAScoreboard_AutoScaleTeamSummary(lb_UnitAssault.List).MaxVisibleTeamEntries = ((numAssignedTeam0 + numUnassignedTeam0) + 12);
		lb_UnitAssault.WinHeight = ((MenuOwner.MenuOwner.WinHeight * 0.055) + ((float((numAssignedTeam0 + numUnassignedTeam0)) * MenuOwner.MenuOwner.WinHeight) * 0.0208));
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

bool UAATab_AAScoreboard_CoOpSummary::ButtonClick(UGUIComponent* Sender)
{
	return true;
}

bool UAATab_AAScoreboard_CoOpSummary::CanShowPanel()
{
	/*
	AGameReplicationInfo* GRI = nullptr;
	if (PlayerOwner() != nullptr)
	{
		GRI = PlayerOwner().GameReplicationInfo;
		if (GRI != nullptr)
		{
			return ((GRI.bShouldShowScoreboard || PlayerOwner().PlayerReplicationInfo.bAdmin) || PlayerOwner().PlayerReplicationInfo.bOnlySpectator);
		}
	}
	*/

	return false;   //FAKE   /ELiZ
}

bool UAATab_AAScoreboard_CoOpSummary::InternalOnDraw(UCanvas* C)
{
	/*
	OnActivate();
	AAScoreboard_AutoScaleTeamSummary(lb_UnitAssault.List).renderCounter = 0;
	AAScoreboard_AutoScaleTeamSummary(lb_UnitSpectator.List).renderCounter = 0;
	return OnDraw(C);
	*/

	return false;   //FAKE   /ELiZ
}
