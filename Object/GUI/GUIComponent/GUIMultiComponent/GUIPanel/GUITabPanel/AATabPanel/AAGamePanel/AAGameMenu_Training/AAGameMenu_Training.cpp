// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAGamePanel/AAGameMenu_Training/AAGameMenu_Training.h"

UAAGameMenu_Training::UAAGameMenu_Training()
{
	/*
	Begin Object Class=GUIScrollTextBox Name=TrainingDescription
		bNoTeletype=True
		bVisibleWhenEmpty=True
		OnCreateComponent=TrainingDescription.InternalOnCreateComponent
		StyleName="MediumText"
		WinTop=0.48
		WinLeft=0.03
		WinWidth=0.94
		WinHeight=0.4
		bBoundToParent=True
		bScaleToParent=True
	End Object
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
	Begin Object Class=GUILabel Name=TourLabel
		TextAlign=1
		TextColor=(R=255,G=255,B=255,A=255)
		StyleName="TextLabel"
		WinTop=0.36
		WinLeft=0.5
		WinWidth=0.5
		WinHeight=0.04
	End Object
	Begin Object Class=GUILabel Name=MissionLabel
		TextAlign=1
		TextColor=(R=255,G=255,B=255,A=255)
		StyleName="TextLabel"
		WinTop=0.02
		WinLeft=0.02
		WinWidth=0.98
	End Object
	Begin Object Class=GUIImage Name=MapBG
		Image=Texture'T_AA2_UI.Menu.field_translucent'
		ImageStyle=ISTY_Stretched
		ImageRenderStyle=1
		WinTop=0.08
		WinLeft=0.02
		WinWidth=0.47
		WinHeight=0.38
		RenderWeight=0.2
	End Object
	Begin Object Class=GUIImage Name=TourBG
		Image=Texture'T_AA2_UI.Menu.field_translucent'
		ImageStyle=ISTY_Stretched
		ImageRenderStyle=1
		WinTop=0.08
		WinLeft=0.51
		WinWidth=0.47
		WinHeight=0.38
		RenderWeight=0.2
	End Object
	Begin Object Class=GUIImage Name=DescriptionBG
		Image=Texture'T_AA2_UI.Menu.field_translucent'
		ImageStyle=ISTY_Stretched
		ImageRenderStyle=1
		WinTop=0.47
		WinLeft=0.02
		WinWidth=0.96
		WinHeight=0.42
		RenderWeight=0.2
	End Object
	Begin Object Class=GUIImage Name=MapPic
		ImageStyle=ISTY_Scaled
		ImageRenderStyle=1
		WinTop=0.09
		WinLeft=0.03
		WinWidth=0.45
		WinHeight=0.36
		RenderWeight=0.9
	End Object
	Begin Object Class=GUIImage Name=tourIcon
		ImageStyle=ISTY_Justified
		ImageRenderStyle=1
		WinTop=0.09
		WinLeft=0.645
		WinWidth=0.21
		WinHeight=0.28
		RenderWeight=0.9
	End Object
	*/
	//i_Background = GUIImage'AGP_Interface.AAGameMenu_Training.MyBackground';
	//l_Tour = GUILabel'AGP_Interface.AAGameMenu_Training.TourLabel';
	//l_Mission = GUILabel'AGP_Interface.AAGameMenu_Training.MissionLabel';
	//i_MapBG = GUIImage'AGP_Interface.AAGameMenu_Training.MapBG';
	//i_TourBG = GUIImage'AGP_Interface.AAGameMenu_Training.TourBG';
	//i_DescriptionBG = GUIImage'AGP_Interface.AAGameMenu_Training.DescriptionBG';
	//i_Map = GUIImage'AGP_Interface.AAGameMenu_Training.MapPic';
	//i_Tour = GUIImage'AGP_Interface.AAGameMenu_Training.tourIcon';
	//lb_Description = GUIScrollTextBox'AGP_Interface.AAGameMenu_Training.TrainingDescription';
}


void UAAGameMenu_Training::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	Super.InitComponent(MyController, MyOwner);
	BriefingDir = GetBaseDir();
	BriefingDir = Left(BriefingDir, (Len(BriefingDir) - 7));
	BriefingDir = BriefingDir $ "Briefings\\";
	TourID = PlayerOwner().Level.iTour;
	MissionID = PlayerOwner().Level.iMission;
	UpdateTourInfo();
	*/
}

void UAAGameMenu_Training::UpdateMissionStatus()
{
	/*
	local FString MissionImage;
	MissionImage = PlayerOwner().Level.GetTourMissionImage(TourID, MissionID);
	i_Map.Image = Material(DynamicLoadObject(MissionImage, Class'Material', true));
	*/
}

void UAAGameMenu_Training::UpdateTourInfo()
{
	/*
	local AAGUIController C;
	local FString S;
	C = AAGUIController(Controller);
	if ("" $ string(PlayerOwner().Level) ~= "Leavenworth.LevelInfo0")
	{
		l_Mission.Caption = "Leavenworth Prison";
		i_Tour.Image = Material(DynamicLoadObject("T_AA2_UI.Menu.logo_AA", Class'Material', true));
		i_Map.Image = Material(DynamicLoadObject("T_AA2_Maps.LevelShots.map_levelshot_leavenworth", Class'Material', true));
		l_Tour.Caption = "Leavenworth";
		S = C.LoadTextFromFile(BriefingDir $ "Leavenworth.txt");
		lb_Description.SetContent(S);
		return;
	}
	if ("" $ string(PlayerOwner().Level) ~= "Recruiting_Station.LevelInfo0")
	{
		l_Mission.Caption = "Virtual Recruiting Station";
		i_Tour.Image = Material(DynamicLoadObject("T_AA2_UI.Menu.logo_AA", Class'Material', true));
		i_Map.Image = Material(DynamicLoadObject("T_AA2_Maps.LevelShots.map_levelshot_eta", Class'Material', true));
		l_Tour.Caption = "Virtual Recruiting Station";
		S = C.LoadTextFromFile(BriefingDir $ "Recruiting_Station.txt");
		lb_Description.SetContent(S);
		return;
	}
	l_Tour.Caption = PlayerOwner().Level.GetTourName(TourID);
	l_Mission.Caption = PlayerOwner().Level.GetTourMissionTitle(TourID, MissionID);
	i_Tour.Image = Material(DynamicLoadObject(PlayerOwner().Level.GetTourImage(TourID), Class'Material', true));
	i_Map.Image = Material(DynamicLoadObject(PlayerOwner().Level.GetTourMissionImage(TourID, MissionID), Class'Material', true));
	S = Caps(PlayerOwner().Level.GetTourMissionTitle(TourID, MissionID));
	(S $ = "|");
	if (PlayerOwner().Level.sAssaultSituationText != "")
	{
		(S $ = BuildMissionBriefing());
	}
	else
	{
		(S $ = C.LoadTextFromFile(BriefingDir $ PlayerOwner().Level.GetTourMissionMapFilename(TourID, MissionID) $ ".txt"));
		if (FOpen(C.LoadTextFromFile(BriefingDir $ PlayerOwner().Level.GetTourText(TourID) $ ".txt")))
		{
			FClose();
			(S $ = "||");
			(S $ = Caps(PlayerOwner().Level.GetTourTextTitle(TourID)) $ "|");
			(S $ = C.LoadTextFromFile(BriefingDir $ PlayerOwner().Level.GetTourText(TourID) $ ".txt"));
		}
		if (FOpen(C.LoadTextFromFile(BriefingDir $ PlayerOwner().Level.GetTourHistoryText(TourID) $ ".txt")))
		{
			FClose();
			(S $ = "||");
			(S $ = Caps(PlayerOwner().Level.GetTourHistoryTextTitle(TourID)));
			(S $ = "|");
			(S $ = C.LoadTextFromFile(BriefingDir $ PlayerOwner().Level.GetTourHistoryText(TourID) $ ".txt"));
		}
	}
	lb_Description.SetContent(S);
	*/
}

FString UAAGameMenu_Training::BuildMissionBriefing()
{
	FString Briefing="";
	/*
	local PlayerController PC;
	PC = PlayerOwner();
	if (PC != None)
	{
		Briefing = "=====  WARNING ORDER  =====||";
		Briefing = Briefing $ "ASSAULT||";
		Briefing = Briefing $ "1. SITUATION: " $ PC.Level.sAssaultSituationText $ "||";
		Briefing = Briefing $ "2. MISSION: " $ PC.Level.sAssaultMissionText $ "||";
		Briefing = Briefing $ "3. GENERAL INSTRUCTIONS: ||";
		Briefing = Briefing $ "    A. ENEMY FORCES: " $ PC.Level.sAssaultEnemyForcesText $ "||";
		Briefing = Briefing $ "    B. FRIENDLY FORCES: " $ PC.Level.sAssaultFriendlyForcesText $ "||";
		Briefing = Briefing $ "    C. TERRAIN: " $ PC.Level.sAssaultTerrainText $ "||";
		Briefing = Briefing $ "    D. ROE: " $ PC.Level.sAssaultROEText $ "||";
		Briefing = Briefing $ "DEFENSE||";
		Briefing = Briefing $ "1. SITUATION: " $ PC.Level.sDefenseSituationText $ "||";
		Briefing = Briefing $ "2. MISSION: " $ PC.Level.sDefenseMissionText $ "||";
		Briefing = Briefing $ "3. GENERAL INSTRUCTIONS: ||";
		Briefing = Briefing $ "    A. ENEMY FORCES: " $ PC.Level.sDefenseEnemyForcesText $ "||";
		Briefing = Briefing $ "    B. FRIENDLY FORCES: " $ PC.Level.sDefenseFriendlyForcesText $ "||";
		Briefing = Briefing $ "    C. TERRAIN: " $ PC.Level.sDefenseTerrainText $ "||";
		Briefing = Briefing $ "    D. ROE: " $ PC.Level.sDefenseROEText $ "||";
	}
	*/
	return Briefing;
}
