// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/AAGameMenu_CommandPost/AAGameMenu_CommandPost.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUITabControl/AAGUITabControl/AAGUITabControl.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"

UAAGameMenu_CommandPost::UAAGameMenu_CommandPost()
{

	UGUIButton* CloseButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	CloseButton->Caption="Close Command Post";
	CloseButton->StyleName="SquareMenuButton";
	CloseButton->Hint="Click here to close the Command Post.";
	CloseButton->WinTop=0.93;
	CloseButton->WinLeft=0.38;
	CloseButton->WinWidth=0.25;
	CloseButton->WinHeight=0.053476;
	//CloseButton->OnClick=AAGameMenu_CommandPost.ButtonClick;
	//CloseButton->OnKeyEvent=CloseButton.InternalOnKeyEvent;
	UAAGUITabControl* TabC = NewObject<UAAGUITabControl>(UAAGUITabControl::StaticClass());
	TabC->ButtonStyleName="MainMenuButton";
	TabC->bDockPanels=true;
	TabC->TabHeight=0.05;
	TabC->WinHeight=1;
	TabC->RenderWeight=0.49;
	//TabC->OnActivate=TabC.InternalOnActivate;
	UGUILabel* CPTitle = NewObject<UGUILabel>(UGUILabel::StaticClass());
	CPTitle->Caption="AA Admin Command Post";
	CPTitle->TextAlign = ETextAlign::TXTA_Right;
	CPTitle->TextColor=FColor(200, 200, 200, 255);
	CPTitle->TextFont="AAFontMedium";
	CPTitle->bMultiLine=true;
	CPTitle->WinTop=0.028334;
	CPTitle->WinLeft=0.5;
	CPTitle->WinWidth=0.49;
	CPTitle->WinHeight=0.1;
	guitcCommandPostPanels = TabC;
	guibtnClose = CloseButton;
	guilTitle = CPTitle;
	iMaxPanels = 6;
	PanelClasses = { "AGP_Interface.AAGameMenu_CP_MapSelection","AGP_Interface.AAGameMenu_CP_Configuration","AGP_Interface.AAGameMenu_CP_Rules","AGP_Interface.AAGameMenu_CP_PlayerManagement","AGP_Interface.AAGameMenu_CP_BanlistManagement","AGP_Interface.AAGameMenu_CP_Tournament" };
	PanelCaptions = { "Mission","Configuration","Rules","Players","Ban List","Tournament" };
	PanelHints = { "Select a new mission","Configure server options","Customize game rules.","Manage Players (change teams, assign weapons)","Manage the server ban list","Modify Tournament Configuration" };
	WinHeight = 1;
}

void UAAGameMenu_CommandPost::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	local int32 iTabIndex;
	Super::InitComponent(MyController, MyOwner);
	if (!IsAdmin())
	{
		fCloseRequested = true;
		HumanController(PlayerOwner()).ClientCloseMenu(true);
		return;
	}
	fCloseRequested = false;
	iTabIndex = 0;
	aaguipPanels[iTabIndex] = guitcCommandPostPanels.AddTab(PanelCaptions[iTabIndex], PanelClasses[iTabIndex], , PanelHints[iTabIndex]);
	AAGameMenu_CP_MapSelection(aaguipPanels[iTabIndex]).aagpCommandPost = Self;
	iTabIndex = 1;
	aaguipPanels[iTabIndex] = guitcCommandPostPanels.AddTab(PanelCaptions[iTabIndex], PanelClasses[iTabIndex], , PanelHints[iTabIndex]);
	AAGameMenu_CP_Configuration(aaguipPanels[iTabIndex]).aagpCommandPost = Self;
	AAGameMenu_CP_Configuration(aaguipPanels[iTabIndex]).InitializeDataFields();
	iTabIndex = 2;
	aaguipPanels[iTabIndex] = guitcCommandPostPanels.AddTab(PanelCaptions[iTabIndex], PanelClasses[iTabIndex], , PanelHints[iTabIndex]);
	AAGameMenu_CP_Rules(aaguipPanels[iTabIndex]).aagpCommandPost = Self;
	AAGameMenu_CP_Rules(aaguipPanels[iTabIndex]).InitializeDataFields();
	iTabIndex = 3;
	aaguipPanels[iTabIndex] = guitcCommandPostPanels.AddTab(PanelCaptions[iTabIndex], PanelClasses[iTabIndex], , PanelHints[iTabIndex]);
	AAGameMenu_CP_PlayerManagement(aaguipPanels[iTabIndex]).aagpCommandPost = Self;
	iTabIndex = 4;
	aaguipPanels[iTabIndex] = guitcCommandPostPanels.AddTab(PanelCaptions[iTabIndex], PanelClasses[iTabIndex], , PanelHints[iTabIndex]);
	AAGameMenu_CP_BanlistManagement(aaguipPanels[iTabIndex]).aagpCommandPost = Self;
	AAGameMenu_CP_BanlistManagement(aaguipPanels[iTabIndex]).InitializeDataFields();
	iTabIndex = 5;
	aaguipPanels[iTabIndex] = guitcCommandPostPanels.AddTab(PanelCaptions[iTabIndex], PanelClasses[iTabIndex], , PanelHints[iTabIndex]);
	AAGameMenu_CP_Tournament(aaguipPanels[iTabIndex]).aagpCommandPost = Self;
	AAGameMenu_CP_Tournament(aaguipPanels[iTabIndex]).InitializeDataFields();
	*/
}

bool UAAGameMenu_CommandPost::IsAdmin()
{
	//return (((PlayerOwner() != None) && (PlayerOwner().PlayerReplicationInfo != None)) && PlayerOwner().PlayerReplicationInfo.bAdmin);
	return false;    //FAKE   /ELiZ
}

void UAAGameMenu_CommandPost::OnOpen()
{
	/*
	local AGP_HUD HUD;
	Super::OnOpen();
	HUD = AGP_HUD(PlayerOwner().myHUD);
	bPlayerHUD = HUD.bShowHUD;
	HUD.bShowVersion = true;
	HUD.bShowSpectatorInfo = false;
	HUD.bShowHUD = false;
	*/
}

void UAAGameMenu_CommandPost::NotifyCommandPostPage(FString sPanelName, FString sParam1, FString sParam2, FString sParam3)
{
	/*
	local int32 iPanel;
	iPanel = 0;
	if (iPanel < iMaxPanels)
	{
		if (PanelCaptions[iPanel] ~= sPanelName)
		{
			aaguipPanels[iPanel].NotifyCustomParameters(sParam1, sParam2, sParam3);
		}
		else
		{
			iPanel++;
		}
	}
	*/
}

void UAAGameMenu_CommandPost::OnClose(bool bCanceled)
{
	/*
	local AGP_HUD HUD;
	local PlayerController PC;
	PC = PlayerOwner();
	HumanController(PlayerOwner()).guipCommandPost = None;
	Super::OnClose(bCanceled);
	HUD = AGP_HUD(PlayerOwner().myHUD);
	HUD.bShowVersion = false;
	HUD.bShowSpectatorInfo = true;
	HUD.bShowHUD = bPlayerHUD;
	*/
}

bool UAAGameMenu_CommandPost::OnCanClose(bool bCancelled)
{
	/*
	if (PlayerOwner().Level.GetLevelName() ~= "entry")
	{
		return true;
	}
	*/
	return fCloseRequested;
}

bool UAAGameMenu_CommandPost::ButtonClick(UGUIComponent* Sender)
{
	/*
	switch (Sender)
	{
	case guibtnClose:
		Sender.SetFocus(None);
		fCloseRequested = true;
		HumanController(PlayerOwner()).ClientCloseMenu(true);
		break;
	default:
	}
	*/
	return true;
}

void UAAGameMenu_CommandPost::SwitchPanel(int32 NewPanel)
{
	/*
	Log("SwitchPanel() - " $ PanelCaptions[NewPanel]);
	if (guitcCommandPostPanels.ActiveTab.Caption ~= PanelCaptions[NewPanel])
	{
		Controller.CloseMenu();
	}
	else
	{
		guitcCommandPostPanels.ActivateTabByName(PanelCaptions[NewPanel], true);
	}
	*/
}

void UAAGameMenu_CommandPost::HandleParameters(FString Param1, FString Param2)
{
	/*
	Super::HandleParameters(Param1, Param2);
	guitcCommandPostPanels.ActivateTabByName(Param1, true);
	*/
}
