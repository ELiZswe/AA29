// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAGamePanel/AAGameMenu_Training/AAGameMenu_Training.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIScrollTextBox/GUIScrollTextBox.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"

UAAGameMenu_Training::UAAGameMenu_Training()
{
	UGUIScrollTextBox* TrainingDescription = NewObject<UGUIScrollTextBox>(UGUIScrollTextBox::StaticClass());
	TrainingDescription->bNoTeletype = true;
	TrainingDescription->bVisibleWhenEmpty = true;
	//TrainingDescription->OnCreateComponent=TrainingDescription.InternalOnCreateComponent;
	TrainingDescription->StyleName = "MediumText";
	TrainingDescription->WinTop = 0.48;
	TrainingDescription->WinLeft = 0.03;
	TrainingDescription->WinWidth = 0.94;
	TrainingDescription->WinHeight = 0.4;
	TrainingDescription->bBoundToParent = true;
	TrainingDescription->bScaleToParent = true;
	UGUIImage* MyBackground = NewObject<UGUIImage>(UGUIImage::StaticClass());
	MyBackground->Image = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/backgroundfil_Mat.backgroundfil_Mat'"), NULL, LOAD_None, NULL);
	MyBackground->ImageStyle = EImgStyle::ISTY_Stretched;
	MyBackground->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	MyBackground->WinTop = 0.01;
	MyBackground->WinLeft = 0.01;
	MyBackground->WinWidth = 0.98;
	MyBackground->WinHeight = 0.89;
	MyBackground->RenderWeight = 0;
	MyBackground->bBoundToParent = true;
	MyBackground->bScaleToParent = true;
	UGUILabel* TourLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	TourLabel->TextAlign = ETextAlign::TXTA_Center;
	TourLabel->TextColor = FColor(255, 255, 255, 255);
	TourLabel->StyleName = "TextLabel";
	TourLabel->WinTop = 0.36;
	TourLabel->WinLeft = 0.5;
	TourLabel->WinWidth = 0.5;
	TourLabel->WinHeight = 0.04;
	UGUILabel* MissionLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	MissionLabel->TextAlign = ETextAlign::TXTA_Center;
	MissionLabel->TextColor = FColor(255, 255, 255, 255);
	MissionLabel->StyleName = "TextLabel";
	MissionLabel->WinTop = 0.02;
	MissionLabel->WinLeft = 0.02;
	MissionLabel->WinWidth = 0.98;
	UGUIImage* MapBG = NewObject<UGUIImage>(UGUIImage::StaticClass());
	MapBG->Image = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/field_translucen_Mat.field_translucen_Mat'"), NULL, LOAD_None, NULL);
	MapBG->ImageStyle = EImgStyle::ISTY_Stretched;
	MapBG->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	MapBG->WinTop = 0.08;
	MapBG->WinLeft = 0.02;
	MapBG->WinWidth = 0.47;
	MapBG->WinHeight = 0.38;
	MapBG->RenderWeight = 0.2;
	UGUIImage* TourBG = NewObject<UGUIImage>(UGUIImage::StaticClass());
	TourBG->Image = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/field_translucen_Mat.field_translucen_Mat'"), NULL, LOAD_None, NULL);
	TourBG->ImageStyle = EImgStyle::ISTY_Stretched;
	TourBG->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	TourBG->WinTop = 0.08;
	TourBG->WinLeft = 0.51;
	TourBG->WinWidth = 0.47;
	TourBG->WinHeight = 0.38;
	TourBG->RenderWeight = 0.2;
	UGUIImage* DescriptionBG = NewObject<UGUIImage>(UGUIImage::StaticClass());
	DescriptionBG->Image = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/field_translucen_Mat.field_translucen_Mat'"), NULL, LOAD_None, NULL);
	DescriptionBG->ImageStyle = EImgStyle::ISTY_Stretched;
	DescriptionBG->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	DescriptionBG->WinTop = 0.47;
	DescriptionBG->WinLeft = 0.02;
	DescriptionBG->WinWidth = 0.96;
	DescriptionBG->WinHeight = 0.42;
	DescriptionBG->RenderWeight = 0.2;
	UGUIImage* MapPic = NewObject<UGUIImage>(UGUIImage::StaticClass());
	MapPic->ImageStyle = EImgStyle::ISTY_Scaled;
	MapPic->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	MapPic->WinTop = 0.09;
	MapPic->WinLeft = 0.03;
	MapPic->WinWidth = 0.45;
	MapPic->WinHeight = 0.36;
	MapPic->RenderWeight = 0.9;
	UGUIImage* tourIcon = NewObject<UGUIImage>(UGUIImage::StaticClass());
	tourIcon->ImageStyle = EImgStyle::ISTY_Justified;
	tourIcon->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	tourIcon->WinTop = 0.09;
	tourIcon->WinLeft = 0.645;
	tourIcon->WinWidth = 0.21;
	tourIcon->WinHeight = 0.28;
	tourIcon->RenderWeight = 0.9;
	i_Background = MyBackground;
	l_Tour = TourLabel;
	l_Mission = MissionLabel;
	i_MapBG = MapBG;
	i_TourBG = TourBG;
	i_DescriptionBG = DescriptionBG;
	i_Map = MapPic;
	i_Tour = tourIcon;
	lb_Description = TrainingDescription;
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
