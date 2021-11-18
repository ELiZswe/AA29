// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AATeamGamePanel/AATab_AAScoreboard_SpectatorTeam/AATab_AAScoreboard_SpectatorTeam.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIContentBox/GUIContentBox.h"

UAATab_AAScoreboard_SpectatorTeam::UAATab_AAScoreboard_SpectatorTeam()
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
	MyPanel->WinWidth=0.98;
	MyPanel->WinHeight=0.89;
	MyPanel->RenderWeight=0.01;
	MyPanel->bBoundToParent=true;
	MyPanel->bScaleToParent=true;
	MyPanel->bAcceptsInput=false;
	MyPanel->bNeverFocus=true;

	i_Background = MyBackground;
	cb_MainWindow = MyPanel;
	bAlwaysAutomate = true;
	bNeverFocus = true;
}

void UAATab_AAScoreboard_SpectatorTeam::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	local XInterface.GUIImage Spacer;
	Super::InitComponent(MyController, MyOwner);
	cb_MainWindow.MyPanel.bCenterItems = false;
	cb_MainWindow.MyPanel.bScaleItemsToWidth = false;
	cb_MainWindow.MyPanel.ItemSpacing = 0;
	Grid = GUIGridLayout(cb_MainWindow.addItem("AGP_Interface.GUIGridLayout"));
	Grid.RowSpacing = 0.02;
	Spacer = GUIImage(Grid.CreateItem("XInterface.GUIImage", 1));
	l_Spectator = AAGUILabel(Grid.CreateItem("AGP_Interface.AAGUILabel", 1));
	lb_UnitSpectator = GUIMultiColumnListBox(Grid.CreateItem("AGP_Interface.AAListBox_SpectatorTeam", 1));
	Grid.AddComponent("AGP_Interface.AAScoreboard_SpectatorTeam");
	Spacer.WinHeight = 0;
	lb_UnitSpectator.WinHeight = 0.7;
	lb_UnitSpectator.WinWidth = 0.95;
	l_Spectator.WinWidth = 0.8;
	l_Spectator.TextFont = "AAFontMedium";
	l_Spectator.TextColor.R = 150;
	l_Spectator.TextColor.G = 30;
	l_Spectator.TextColor.B = 50;
	l_Spectator.TextColor.A = 255;
	l_Spectator.TextAlign = 0;
	l_Spectator.Caption = "SPECTATORS";
	AAScoreboard_AutoScaleTeamSummary(lb_UnitSpectator.List).bIsSpectatorPanel = true;
	AAScoreboard_AutoScaleTeamSummary(lb_UnitSpectator.List).bFullSpectatorPanel = true;
	AAScoreboard_AutoScaleTeamSummary(lb_UnitSpectator.List).MaxVisibleTeamEntries = 26;
	*/
}

bool UAATab_AAScoreboard_SpectatorTeam::ButtonClick(UGUIComponent* Sender)
{
	return true;
}

bool UAATab_AAScoreboard_SpectatorTeam::CanShowPanel()
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
	return false;   //FAKE   /ELiZ
}