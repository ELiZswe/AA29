// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AADeploy_LAN/AADeploy_LAN.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIEditBox/GUIEditBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/AABrowser_ServersPlayersRulesPanel/AABrowser_ServersPlayersRulesPan.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/AABrowser_UpdateJoinAndPBPanel/AABrowser_UpdateJoinAndPBPanel.h"

UAADeploy_LAN::UAADeploy_LAN()
{
	UGUIEditBox* PlayerName = NewObject<UGUIEditBox>(UGUIEditBox::StaticClass());
	PlayerName->Hint = "The player name used when joining LAN servers which do not require authorization.";
	PlayerName->WinTop = 0.871008;
	PlayerName->WinLeft = 0.197368;
	PlayerName->WinWidth = 0.179279;
	PlayerName->WinHeight = 0.035;
	PlayerName->bBoundToParent = true;
	//PlayerName->OnActivate=PlayerName.InternalActivate;
	//PlayerName->OnDeActivate=AADeploy_LAN.InternalOnPlayerNameDeactivate;
	//PlayerName->OnKeyType=PlayerName.InternalOnKeyType;
	//PlayerName->OnKeyEvent=PlayerName.InternalOnKeyEvent;
	UAABrowser_ServersPlayersRulesPan* ServersPlayersRules = NewObject<UAABrowser_ServersPlayersRulesPan>(UAABrowser_ServersPlayersRulesPan::StaticClass());
	ServersPlayersRules->bIsLAN = true;
	//ServersPlayersRules->OnUpdateServerList = AADeploy_LAN.InternalOnUpdateServerList;
	ServersPlayersRules->WinTop = 0.06;
	ServersPlayersRules->WinHeight = 0.79;
	//ServersPlayersRules->OnSaveINI=ServersPlayersRules.InternalOnSaveINI;
	UAABrowser_UpdateJoinAndPBPanel* UpdateJoinAndPB = NewObject<UAABrowser_UpdateJoinAndPBPanel>(UAABrowser_UpdateJoinAndPBPanel::StaticClass());
	UpdateJoinAndPB->HideBorder = true;
	//UpdateJoinAndPB->OnPunkBusterChanged = AADeploy_LAN.InternalOnPunkBusterChanged;
	//UpdateJoinAndPB->OnUpdateServerList = AADeploy_LAN.InternalOnUpdateServerList;
	//UpdateJoinAndPB->OnJoinServer = AADeploy_LAN.InternalOnJoinServer;
	UpdateJoinAndPB->WinTop = 0.905271;
	UpdateJoinAndPB->WinLeft = 0.333;
	UpdateJoinAndPB->WinWidth = 0.666;
	UpdateJoinAndPB->WinHeight = 0.057237;
	UGUIImage* PlayerNameBackground = NewObject<UGUIImage>(UGUIImage::StaticClass());
	PlayerNameBackground->Image = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/backgroundfil_Mat.backgroundfil_Mat'"), NULL, LOAD_None, NULL);
	PlayerNameBackground->ImageStyle = EImgStyle::ISTY_Stretched;
	PlayerNameBackground->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	PlayerNameBackground->WinTop = 0.850748;
	PlayerNameBackground->WinHeight = 0.111185;
	PlayerNameBackground->RenderWeight = 0;
	PlayerNameBackground->bBoundToParent = true;
	PlayerNameBackground->bScaleToParent = true;
	UGUILabel* LANPlayerName = NewObject<UGUILabel>(UGUILabel::StaticClass());
	LANPlayerName->Caption = "LAN Player Name:";
	LANPlayerName->TextColor = FColor(255, 255, 255, 255);
	LANPlayerName->StyleName = "SmallText";
	LANPlayerName->WinTop = 0.871008;
	LANPlayerName->WinLeft = 0.005197;
	LANPlayerName->WinWidth = 0.194082;
	LANPlayerName->WinHeight = 0.041908;
	LANPlayerName->bBoundToParent = true;
	UGUILabel* ServerCountLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	ServerCountLabel->TextAlign = ETextAlign::TXTA_Right;
	ServerCountLabel->FontScale = EFontScale::FNS_Small;
	ServerCountLabel->StyleName = "TextLabel";
	ServerCountLabel->WinTop = 0.858218;
	ServerCountLabel->WinLeft = 0.712168;
	ServerCountLabel->WinWidth = 0.282237;
	ServerCountLabel->WinHeight = 0.025515;
	ServerCountLabel->RenderWeight = 10;
	ServerCountLabel->bBoundToParent = true;
	ServerCountLabel->bScaleToParent = true;
	ServersPlayersRulesPanel = ServersPlayersRules;
	UpdateJoinAndPBPanel = UpdateJoinAndPB;
	PlayerNameBackgroundBorder = PlayerNameBackground;
	PlayerNameLabel = LANPlayerName;
	PlayerNameEditBox = PlayerName;
	ServerCount = ServerCountLabel;
	bIsLAN = true;
	PanelCaption = "LAN Servers";
	//OnTimer = AADeploy_LAN.InternalOnTimer;
}

void UAADeploy_LAN::ShowPanel(bool bShow)
{
	/*
	Super::ShowPanel(bShow);
	if (bShow)
	{
		ServerCount.Caption = "";
		PlayerNameEditBox.SetText(HumanController(PlayerOwner()).LANPlayerName);
		if (!HumanController(PlayerOwner()).bDisableAutoServerlistRetrieval)
		{
			UpdateServerList();
		}
	}
	else
	{
		SaveLANPlayerName();
		KillTimer();
	}
	*/
}

void UAADeploy_LAN::InternalOnTimer(UGUIComponent* Sender)
{
	//UpdateServerList();
}

void UAADeploy_LAN::InternalOnPunkBusterChanged(bool PunkBusterEnabled)
{
	/*
	if (PunkBusterEnabled)
	{
		PlayerOwner().Level.PBEnable();
	}
	else
	{
		PlayerOwner().Level.PBDisable();
		Controller.OpenMenu("AGP_Interface.AAGenericMessageBox", "PunkBuster Client", "The PunkBuster Client will be disabled the NEXT TIME upon startup.");
	}
	*/
}

void UAADeploy_LAN::InternalOnUpdateServerList()
{
	//UpdateServerList();
}

void UAADeploy_LAN::InternalOnJoinServer()
{
	/*
	SaveLANPlayerName();
	ServersPlayersRulesPanel.JoinCurrentlySelectedServer();
	*/
}

void UAADeploy_LAN::InternalOnRecievedServer(int32 Index)
{
	/*
	local IpDrv.ServerBrowserBase ServerBrowser;
	local int32 NumServers;
	ServerBrowser = AGP_HUD(HumanController(PlayerOwner()).myHUD).GetCurrentServerBrowser(bIsLAN);
	if (ServerBrowser != None)
	{
		NumServers = ServerBrowser.GetNumServers();
		ServerCount.Caption = string(NumServers) @ "server" $ Eval((NumServers != 1), "s", "");
	}
	ServersPlayersRulesPanel.ReceivedServer(Index);
	*/
}

void UAADeploy_LAN::UpdateServerList()
{
	/*
	local IpDrv.ServerBrowserBase ServerBrowser;
	ServersPlayersRulesPanel.Clear();
	ServerBrowser = AGP_HUD(HumanController(PlayerOwner()).myHUD).GetCurrentServerBrowser(bIsLAN);
	if (PlayerOwner() == None)
	{
		return;
	}
	ServerCount.Caption = "";
	ServerBrowser.__OnReceivedServer__Delegate = InternalOnRecievedServer;
	ServerBrowser.SetPublic((!bIsLAN));
	ServerBrowser.SetFilter("");
	ServerBrowser.UpdateServerList();
	SetTimer(20, true);
	*/
}

void UAADeploy_LAN::InternalOnPlayerNameDeactivate()
{
	//SaveLANPlayerName();
}

void UAADeploy_LAN::SaveLANPlayerName()
{
	/*
	if (HumanController(PlayerOwner()).LANPlayerName != PlayerNameEditBox.GetText())
	{
		HumanController(PlayerOwner()).LANPlayerName = PlayerNameEditBox.GetText();
		PlayerOwner().SaveConfig();
	}
	*/
}
