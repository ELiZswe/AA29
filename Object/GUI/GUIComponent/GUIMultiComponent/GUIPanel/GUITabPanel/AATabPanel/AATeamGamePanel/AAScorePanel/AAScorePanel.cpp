// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AATeamGamePanel/AAScorePanel/AAScorePanel.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUITabControl/AAGUITabControl/AAGUITabControl.h"

UAAScorePanel::UAAScorePanel()
{
	UAAGUITabControl* PageTabs = NewObject<UAAGUITabControl>(UAAGUITabControl::StaticClass());
	PageTabs->ButtonStyleName="TabButton";
	PageTabs->UniformTabWidth=0.12;
	PageTabs->bDockPanels=true;
	PageTabs->TabHeight=0.035;
	PageTabs->WinTop=0.03;
	PageTabs->WinLeft=0.01;
	PageTabs->WinHeight=1;
	PageTabs->RenderWeight=0.01;
	PageTabs->TabOrder=1;
	PageTabs->bBoundToParent=true;
	PageTabs->bScaleToParent=true;
	//PageTabs->OnActivate=PageTabs.InternalOnActivate;

	c_Tabs = PageTabs;
	PanelClasses = { "AGP_Interface.AAGameMenu_Score","AGP_Interface.AATab_AAScoreboard_AssaultTeam","AGP_Interface.AATab_AAScoreboard_DefenseTeam""AGP_Interface.AATab_AAScoreboard_SpectatorTeam" };
	PanelCaptions = { "Summary","Assault","Defense","Spectators" };
	PanelHints = { "All Players and Spectators", "My Team", "Other Team", "Spectators" };
	bApplyImmediately = true;
	InvalidStats = "Invalid Stats Info";
	//OnPreDraw = AAScorePanel.InternalOnPreDraw;
}

void UAAScorePanel::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	int32 i = 0;
	local GameReplicationInfo GRI;
	local HumanController HC;
	Super::InitComponent(MyController, MyOwner);
	for (i = 0; i < PanelClasses.Length; i++)
	{
		c_Tabs.AddTab(PanelCaptions[i], PanelClasses[i], , PanelHints[i]);
	}
	if (PlayerOwner() != None)
	{
		GRI = PlayerOwner().GameReplicationInfo;
	}
	HC = HumanController(PlayerOwner());
	PanelCaptions[1] = Lower(Caps(PlayerOwner().Level.TeamName[0]));
	PanelCaptions[2] = Lower(Caps(PlayerOwner().Level.TeamName[1]));
	if ((HC != None) && HC.bTournamentServer)
	{
		if (HC.GetTeamName(0) != "")
		{
			PanelCaptions[1] $ = Lower(Caps("[" $ HC.GetTeamName(0) $ "]"));
		}
		if (HC.GetTeamName(1) != "")
		{
			PanelCaptions[2] $ = Lower(Caps("[" $ HC.GetTeamName(1) $ "]"));
		}
	}
	for (i = 0; i < PanelClasses.Length; i++)
	{
		c_Tabs.TabStack[i].Caption = PanelCaptions[i];
	}
	LastTeamID = PlayerOwner().PlayerReplicationInfo.Team.TeamIndex;
	*/
}

void UAAScorePanel::HandleParameters(FString Param1, FString Param2)
{
	/*
	if (Param1 != "")
	{
		c_Tabs.ActivateTabByName(Param1, true);
	}
	*/
}

bool UAAScorePanel::GetRestoreParams(FString& Param1, FString& Param2)
{
	/*
	if ((c_Tabs != None) && (c_Tabs.ActiveTab != None))
	{
		Param1 = c_Tabs.ActiveTab.Caption;
		return true;
	}
	*/
	return false;
}

bool UAAScorePanel::ButtonClicked(UGUIComponent* Sender)
{
	return true;
}

bool UAAScorePanel::InternalOnPreDraw(UCanvas* C)
{
	/*
	if (LastTeamID != PlayerOwner().PlayerReplicationInfo.Team.TeamIndex)
	{
		if (PlayerOwner().PlayerReplicationInfo.Team.TeamIndex == 1)
		{
			c_Tabs.ReplaceTab(c_Tabs.TabStack[1], PanelCaptions[2], PanelClasses[2], , PanelHints[2]);
			c_Tabs.ReplaceTab(c_Tabs.TabStack[2], PanelCaptions[1], PanelClasses[1], , PanelHints[1]);
		}
		else
		{
			c_Tabs.ReplaceTab(c_Tabs.TabStack[1], PanelCaptions[1], PanelClasses[1], , PanelHints[1]);
			c_Tabs.ReplaceTab(c_Tabs.TabStack[2], PanelCaptions[2], PanelClasses[2], , PanelHints[2]);
		}
		LastTeamID = PlayerOwner().PlayerReplicationInfo.Team.TeamIndex;
	}
	*/
	return true;
}

FString UAAScorePanel::Lower(FString Text)
{
	/*
	int32 IndexChar = 0;
	for (IndexChar = 1; IndexChar < Len(Text); IndexChar++)
	{
		if ((Mid(Text, IndexChar, 1) == " ") && (IndexChar < (Len(Text) - 1)))
		{
			IndexChar++;
		}
		else
		{
			if ((Mid(Text, IndexChar, 1) >= "A") && (Mid(Text, IndexChar, 1) <= "Z"))
			{
				Text = Left(Text, IndexChar) $ Chr((Asc(Mid(Text, IndexChar, 1)) + 32)) $ Mid(Text, (IndexChar + 1));
			}
		}
	}
	*/
	return Text;
}