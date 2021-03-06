// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AATeamGamePanel/AATab_AAScoreboard_DefenseTeam/AATab_AAScoreboard_DefenseTeam.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIContentBox/GUIContentBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUIGridLayout/GUIGridLayout.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIMultiColumnListBox/GUIMultiColumnListBox.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/GameReplicationInfo/GameReplicationInfo.h"
#include "Engine/Canvas.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/AAGUILabel/AAGUILabel.h"

UAATab_AAScoreboard_DefenseTeam::UAATab_AAScoreboard_DefenseTeam()
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
	//OnPreDraw = AATab_AAScoreboard_DefenseTeam.InternalOnPreDraw;
}

void UAATab_AAScoreboard_DefenseTeam::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	UGUIImage* Spacer = nullptr;
	Super::InitComponent(MyController, MyOwner);
	/*
	cb_MainWindow.MyPanel.bCenterItems = false;
	cb_MainWindow.MyPanel.bScaleItemsToWidth = false;
	cb_MainWindow.MyPanel.ItemSpacing = 0;
	Grid = GUIGridLayout(cb_MainWindow.addItem("AGP_Interface.GUIGridLayout"));
	Grid->RowSpacing = 0.02;
	Spacer = Cast<UGUIImage>(Grid->CreateItem("XInterface.GUIImage", 1));
	l_Defense = Cast<UAAGUILabel>(Grid->CreateItem("AGP_Interface.AAGUILabel", 1));
	lb_UnitDefense = Cast<UGUIMultiColumnListBox>(Grid->CreateItem("AGP_Interface.AAListBox_DefenseTeam", 1));
	Grid->AddComponent("AGP_Interface.AAScoreboard_DefenseTeam");
	Spacer.WinHeight = 0;
	lb_UnitDefense.WinHeight = 0.7;
	lb_UnitDefense.WinWidth = 0.95;
	l_Defense.WinWidth = 0.8;
	l_Defense.TextFont = "AAFontMedium";
	l_Defense.TextColor.R = 150;
	l_Defense.TextColor.G = 30;
	l_Defense.TextColor.B = 50;
	l_Defense.TextColor.A = 255;
	l_Defense.TextAlign = 0;
	l_Defense.Caption = "Defense";
	AAScoreboard_TeamSummary(lb_UnitDefense.List).MaxVisibleTeamEntries = 26;
	*/
}

bool UAATab_AAScoreboard_DefenseTeam::InternalOnPreDraw(UCanvas* C)
{
	/*
	AGameReplicationInfo* GRI = nullptr;
	AHumanController* HC = nullptr;
	if (PlayerOwner() != nullptr)
	{
		GRI = PlayerOwner().GameReplicationInfo;
	}
	if (GRI == nullptr)
	{
		return false;
	}
	HC = Cast<AHumanController>(PlayerOwner());
	l_Defense.Caption = PlayerOwner().Level.TeamName[1];
	if ((HC != nullptr) && HC.bTournamentServer)
	{
		if (HC.GetTeamName(1) != "")
		{
			(l_Defense.Caption += "[" + HC.GetTeamName(1) + "]");
		}
	}
	if (GRI.Teams[1] != nullptr)
	{
		(l_Defense.Caption += " " + FString::FromInt(GRI.Teams[1].teamScore) + "/" + FString::FromInt(GRI.RoundsPerMatch));
	}
	*/
	return true;
}

bool UAATab_AAScoreboard_DefenseTeam::ButtonClick(UGUIComponent* Sender)
{
	return true;
}

bool UAATab_AAScoreboard_DefenseTeam::CanShowPanel()
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
