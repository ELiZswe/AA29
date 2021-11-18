// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AATeamGamePanel/AAGameMenu_CoOpScore/AAGameMenu_CoOpScore.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUITabControl/AAGUITabControl/AAGUITabControl.h"

UAAGameMenu_CoOpScore::UAAGameMenu_CoOpScore()
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
	PageTabs->bNeverFocus=true;
	//PageTabs->OnActivate=PageTabs.InternalOnActivate;
	
	c_Tabs = PageTabs;
	PanelClasses = { "AGP_Interface.AATab_AAScoreboard_CoOpSummary", "AGP_Interface.AATab_AAScoreboard_AssaultTeam","AGP_Interface.AATab_AAScoreboard_SpectatorTeam" };
	PanelCaptions = { "Summary","Assault","Spectators" };
	PanelHints = { "All Players and Spectators","My Team","Spectators" };
	bApplyImmediately = true;
	InvalidStats = "Invalid Stats Info";
	bNeverFocus = true;
}

void UAAGameMenu_CoOpScore::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
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
	if ((HC != None) && HC.bTournamentServer)
	{
		if (HC.GetTeamName(0) != "")
		{
			PanelCaptions[1] $ = Lower(Caps("[" $ HC.GetTeamName(0) $ "]"));
		}
	}
	for (i = 0; i < PanelClasses.Length; i++)
	{
		c_Tabs.TabStack[i].Caption = PanelCaptions[i];
	}
	c_Tabs.TabStack[1].Hint = PanelHints[1];
	c_Tabs.TabStack[2].Hint = PanelHints[2];
	LastTeamID = PlayerOwner().PlayerReplicationInfo.Team.TeamIndex;
	*/
}

void UAAGameMenu_CoOpScore::HandleParameters(FString Param1, FString Param2)
{
	/*
	if (Param1 != "")
	{
		c_Tabs.ActivateTabByName(Param1, true);
	}
	*/
}

bool UAAGameMenu_CoOpScore::GetRestoreParams(FString& Param1, FString& Param2)
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

bool UAAGameMenu_CoOpScore::ButtonClicked(UGUIComponent* Sender)
{
	return true;
}

FString UAAGameMenu_CoOpScore::Lower(FString Text)
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