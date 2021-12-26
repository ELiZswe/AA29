// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAGamePanel/AAGameMenu_ServerInfo/AAGameMenu_ServerInfo.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"

UAAGameMenu_ServerInfo::UAAGameMenu_ServerInfo()
{
	UGUIButton* HiddenButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	HiddenButton->WinTop = 0.03;
	HiddenButton->WinLeft = 0.96;
	HiddenButton->WinWidth = 0;
	HiddenButton->WinHeight = 0;
	//HiddenButton->OnClick=AAGameMenu_ServerInfo.InternalOnClick;
	//HiddenButton->OnKeyEvent=HiddenButton.InternalOnKeyEvent;
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
	UGUIImage* BG1 = NewObject<UGUIImage>(UGUIImage::StaticClass());
	BG1->Image = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/field_translucen_Mat.field_translucen_Mat'"), NULL, LOAD_None, NULL);
	BG1->ImageStyle = EImgStyle::ISTY_Stretched;
	BG1->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	BG1->WinTop = 0.02;
	BG1->WinLeft = 0.02;
	BG1->WinWidth = 0.96;
	BG1->WinHeight = 0.87;
	UGUILabel* ServerNameLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	ServerNameLabel->TextAlign = ETextAlign::TXTA_Center;
	ServerNameLabel->TextColor = FColor(52, 180, 217, 255);
	ServerNameLabel->TextFont = "AAFontMedium";
	ServerNameLabel->WinTop = 0.04;
	ServerNameLabel->WinLeft = 0.1;
	ServerNameLabel->WinWidth = 0.8;
	UGUILabel* AdminNameLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	AdminNameLabel->TextAlign = ETextAlign::TXTA_Center;
	AdminNameLabel->TextColor = FColor(255, 255, 255, 255);
	AdminNameLabel->TextFont = "AAFontMedium";
	AdminNameLabel->WinTop = 0.07;
	AdminNameLabel->WinLeft = 0.1;
	AdminNameLabel->WinWidth = 0.8;
	UGUILabel* ServerMOTD1Label = NewObject<UGUILabel>(UGUILabel::StaticClass());
	ServerMOTD1Label->TextAlign = ETextAlign::TXTA_Center;
	ServerMOTD1Label->TextColor = FColor(255, 255, 255, 255);
	ServerMOTD1Label->TextFont = "AAFontMedium";
	ServerMOTD1Label->WinTop = 0.11;
	ServerMOTD1Label->WinLeft = 0.1;
	ServerMOTD1Label->WinWidth = 0.8;
	UGUILabel* ServerMOTD2Label = NewObject<UGUILabel>(UGUILabel::StaticClass());
	ServerMOTD2Label->TextAlign = ETextAlign::TXTA_Center;
	ServerMOTD2Label->TextColor = FColor(255, 255, 255, 255);
	ServerMOTD2Label->TextFont = "AAFontMedium";
	ServerMOTD2Label->WinTop = 0.14;
	ServerMOTD2Label->WinLeft = 0.1;
	ServerMOTD2Label->WinWidth = 0.8;
	UGUILabel* ServerMOTD3Label = NewObject<UGUILabel>(UGUILabel::StaticClass());
	ServerMOTD3Label->TextAlign = ETextAlign::TXTA_Center;
	ServerMOTD3Label->TextColor = FColor(255, 255, 255, 255);
	ServerMOTD3Label->TextFont = "AAFontMedium";
	ServerMOTD3Label->WinTop = 0.17;
	ServerMOTD3Label->WinLeft = 0.1;
	ServerMOTD3Label->WinWidth = 0.8;
	UGUILabel* ServerMOTD4Label = NewObject<UGUILabel>(UGUILabel::StaticClass());
	ServerMOTD4Label->TextAlign = ETextAlign::TXTA_Center;
	ServerMOTD4Label->TextColor = FColor(255, 255, 255, 255);
	ServerMOTD4Label->TextFont = "AAFontMedium";
	ServerMOTD4Label->WinTop = 0.2;
	ServerMOTD4Label->WinLeft = 0.1;
	ServerMOTD4Label->WinWidth = 0.8;
	UGUILabel* GameLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	GameLabel->TextAlign = ETextAlign::TXTA_Center;
	GameLabel->TextColor = FColor(255, 255, 255, 255);
	GameLabel->TextFont = "AAFontMedium";
	GameLabel->WinTop = 0.24;
	GameLabel->WinLeft = 0.1;
	GameLabel->WinWidth = 0.8;
	UGUILabel* Team1Label = NewObject<UGUILabel>(UGUILabel::StaticClass());
	Team1Label->TextAlign = ETextAlign::TXTA_Center;
	Team1Label->TextColor = FColor(50, 30, 150, 255);
	Team1Label->TextFont = "AAFontMedium";
	Team1Label->WinTop = 0.27;
	Team1Label->WinLeft = 0.1;
	Team1Label->WinWidth = 0.8;
	UGUILabel* Team2Label = NewObject<UGUILabel>(UGUILabel::StaticClass());
	Team2Label->TextAlign = ETextAlign::TXTA_Center;
	Team2Label->TextColor = FColor(159, 82, 82, 255);
	Team2Label->TextFont = "AAFontMedium";
	Team2Label->WinTop = 0.3;
	Team2Label->WinLeft = 0.1;
	Team2Label->WinWidth = 0.8;
	i_Background = MyBackground;
	i_Info = BG1;
	l_ServerName = ServerNameLabel;
	l_AdminName = AdminNameLabel;
	l_MOTDLine1 = ServerMOTD1Label;
	l_MOTDLine2 = ServerMOTD2Label;
	l_MOTDLine3 = ServerMOTD3Label;
	l_MOTDLine4 = ServerMOTD4Label;
	l_Game = GameLabel;
	l_Teams = { Team1Label,Team2Label };
	b_Hidden = HiddenButton;

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
	if (GRI == nullptr)
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
