// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAGamePanel/AAGameMenu_ServerInfo/AAGameMenu_ServerInfo.h"

UAAGameMenu_ServerInfo::UAAGameMenu_ServerInfo()
{
	/*
	Begin Object Class=GUIButton Name=HiddenButton
		WinTop=0.03
		WinLeft=0.96
		WinWidth=0
		WinHeight=0
		OnClick=AAGameMenu_ServerInfo.InternalOnClick
		OnKeyEvent=HiddenButton.InternalOnKeyEvent
	End Object
	*/
	/*
	Begin Object Class=GUIImage Name=MyBackground
		Image=Texture'T_AA2_UI.Menu.backgroundfill'
		ImageStyle=ISTY_Stretched
		ImageRenderStyle=1
		WinTop=0.01
		WinLeft=0.01
		WinWidth=0.98
		WinHeight=0.89
		RenderWeight=0
		bBoundToParent=True
		bScaleToParent=True
	End Object
	*/
	/*
	Begin Object Class=GUIImage Name=BG1
		Image=Texture'T_AA2_UI.Menu.field_translucent'
		ImageStyle=ISTY_Stretched
		ImageRenderStyle=1
		WinTop=0.02
		WinLeft=0.02
		WinWidth=0.96
		WinHeight=0.87
	End Object
	*/
	/*
	Begin Object Class=GUILabel Name=ServerNameLabel
		TextAlign=1
		TextColor=(R=52,G=180,B=217,A=255)
		TextFont="AAFontMedium"
		WinTop=0.04
		WinLeft=0.1
		WinWidth=0.8
	End Object
	*/
	/*
	Begin Object Class=GUILabel Name=AdminNameLabel
		TextAlign=1
		TextColor=(R=255,G=255,B=255,A=255)
		TextFont="AAFontMedium"
		WinTop=0.07
		WinLeft=0.1
		WinWidth=0.8
	End Object
	*/
	/*
	Begin Object Class=GUILabel Name=ServerMOTD1Label
		TextAlign=1
		TextColor=(R=255,G=255,B=255,A=255)
		TextFont="AAFontMedium"
		WinTop=0.11
		WinLeft=0.1
		WinWidth=0.8
	End Object
	*/
	/*
	Begin Object Class=GUILabel Name=ServerMOTD2Label
		TextAlign=1
		TextColor=(R=255,G=255,B=255,A=255)
		TextFont="AAFontMedium"
		WinTop=0.14
		WinLeft=0.1
		WinWidth=0.8
	End Object
	*/
	/*
	Begin Object Class=GUILabel Name=ServerMOTD3Label
		TextAlign=1
		TextColor=(R=255,G=255,B=255,A=255)
		TextFont="AAFontMedium"
		WinTop=0.17
		WinLeft=0.1
		WinWidth=0.8
	End Object
	*/
	/*
	Begin Object Class=GUILabel Name=ServerMOTD4Label
		TextAlign=1
		TextColor=(R=255,G=255,B=255,A=255)
		TextFont="AAFontMedium"
		WinTop=0.2
		WinLeft=0.1
		WinWidth=0.8
	End Object
	*/
	/*
	Begin Object Class=GUILabel Name=GameLabel
		TextAlign=1
		TextColor=(R=255,G=255,B=255,A=255)
		TextFont="AAFontMedium"
		WinTop=0.24
		WinLeft=0.1
		WinWidth=0.8
	End Object
	*/
	/*
	Begin Object Class=GUILabel Name=Team1Label
		TextAlign=1
		TextColor=(R=50,G=30,B=150,A=255)
		TextFont="AAFontMedium"
		WinTop=0.27
		WinLeft=0.1
		WinWidth=0.8
	End Object
	*/
	/*
	Begin Object Class=GUILabel Name=Team2Label
		TextAlign=1
		TextColor=(R=159,G=82,B=82,A=255)
		TextFont="AAFontMedium"
		WinTop=0.3
		WinLeft=0.1
		WinWidth=0.8
	End Object
	*/
	//i_Background = GUIImage'AGP_Interface.AAGameMenu_ServerInfo.MyBackground';
	//i_Info = GUIImage'AGP_Interface.AAGameMenu_ServerInfo.BG1';
	//l_ServerName = GUILabel'AGP_Interface.AAGameMenu_ServerInfo.ServerNameLabel';
	//l_AdminName = GUILabel'AGP_Interface.AAGameMenu_ServerInfo.AdminNameLabel';
	//l_MOTDLine1 = GUILabel'AGP_Interface.AAGameMenu_ServerInfo.ServerMOTD1Label';
	//l_MOTDLine2 = GUILabel'AGP_Interface.AAGameMenu_ServerInfo.ServerMOTD2Label';
	//l_MOTDLine3 = GUILabel'AGP_Interface.AAGameMenu_ServerInfo.ServerMOTD3Label';
	//l_MOTDLine4 = GUILabel'AGP_Interface.AAGameMenu_ServerInfo.ServerMOTD4Label';
	//l_Game = GUILabel'AGP_Interface.AAGameMenu_ServerInfo.GameLabel';
	//l_Teams(0) = GUILabel'AGP_Interface.AAGameMenu_ServerInfo.Team1Label';
	//l_Teams(1) = GUILabel'AGP_Interface.AAGameMenu_ServerInfo.Team2Label';
	//b_Hidden = GUIButton'AGP_Interface.AAGameMenu_ServerInfo.HiddenButton';
	//OnPreDraw = AAGameMenu_ServerInfo.InternalOnPreDraw;

}

void UAAGameMenu_ServerInfo::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	//Super:InitComponent(MyController, MyOwner);
}

int32 UAAGameMenu_ServerInfo::RoundNumber()
{
	/*
	local GameReplicationInfo GRI;
	if (PlayerOwner() != None)
	{
		GRI = PlayerOwner().GameReplicationInfo;
	}
	if (GRI != None)
	{
		return (GRI.RoundsPerMatch - GRI.RemainingRounds);
	}
	*/
	return 0;
}

FString UAAGameMenu_ServerInfo::TwoDigitString(int32 Num)
{
	/*
	if ((Num < 10) && (Num >= 0))
	{
		return "0" $ string(Num);
	}
	else
	{
		return string(Num);
	}
	*/
	return "FAKE";     //FAKE    /ELiZ
}

bool UAAGameMenu_ServerInfo::InternalOnPreDraw(UCanvas* C)
{
	/*
	local int32 i;
	local GameReplicationInfo GRI;
	local HumanController HC;
	local FString AdminText;
	local int32 minutes;
	local int32 Seconds;
	local FString MapName;
	local FString GameRound;
	local FString GameTimer;
	if (PlayerOwner() != None)
	{
		GRI = PlayerOwner().GameReplicationInfo;
	}
	if (GRI == None)
	{
		return false;
	}
	HC = HumanController(PlayerOwner());
	l_ServerName.Caption = GRI.ServerName @ PlayerOwner().Level.GetAddressURL();
	AdminText = GRI.AdminName;
	if (GRI.AdminEmail != "")
	{
		AdminText $ = " (" $ GRI.AdminEmail $ ") ";
	}
	l_AdminName.Caption = AdminText;
	l_MOTDLine1.Caption = GRI.MOTDLine1;
	l_MOTDLine2.Caption = GRI.MOTDLine2;
	l_MOTDLine3.Caption = GRI.MOTDLine3;
	l_MOTDLine4.Caption = GRI.MOTDLine4;
	for (i = 0; i < 2; i++)
	{
		l_Teams[i].Caption = PlayerOwner().Level.TeamName[i];
		if (GRI.Teams[i] != None)
		{
			l_Teams[i].Caption $ = " " $ string(GRI.Teams[i].teamScore) $ "/" $ string(GRI.RoundsPerMatch);
		}
	}
	MapName = PlayerOwner().Level.GetLevelNamePrivate();
	if (GRI != None)
	{
		GameRound = "Round" @ string((GRI.RoundsPerMatch - GRI.RemainingRounds)) $ "/" $ string(GRI.RoundsPerMatch);
	}
	if (GRI.RemainingTime >= 0)
	{
		minutes = (GRI.RemainingTime / 60);
		Seconds = int((float(GRI.RemainingTime) % float(60)));
	}
	else
	{
		minutes = (GRI.ElapsedTime / 60);
		Seconds = int((float(GRI.ElapsedTime) % float(60)));
	}
	GameTimer = TwoDigitString(minutes) $ ":" $ TwoDigitString(Seconds);
	l_Game.Caption = MapName @ "-" @ GameRound @ GameTimer;
	*/
	return true;
}

bool UAAGameMenu_ServerInfo::InternalOnClick(UGUIComponent* Sender)
{
	return true;
}
