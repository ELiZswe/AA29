// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/AANPCPNB_PathNodeOptions/AANPCPNB_PathNodeOptions.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"

UAANPCPNB_PathNodeOptions::UAANPCPNB_PathNodeOptions()
{
	UGUIButton* CloseButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	CloseButton->Caption="Close PNB Path Node Options";
	CloseButton->StyleName="SquareMenuButton";
	CloseButton->Hint="Click here to close the Command Post.";
	CloseButton->WinTop=0.93;
	CloseButton->WinLeft=0.38;
	CloseButton->WinWidth=0.25;
	CloseButton->WinHeight=0.053476;
	//CloseButton->OnClick=AANPCPNB_PathNodeOptions.ButtonClick;
	//CloseButton->OnKeyEvent=CloseButton.InternalOnKeyEvent;
	UGUILabel* CPTitle = NewObject<UGUILabel>(UGUILabel::StaticClass());
	CPTitle->Caption="AA NPC Path Builder NPCPlayerStart Options";
	CPTitle->TextAlign = ETextAlign::TXTA_Right;
	CPTitle->TextColor=FColor(200, 200, 200, 255);
	CPTitle->TextFont="AAFontMedium";
	CPTitle->bMultiLine=true;
	CPTitle->WinTop=0.028334;
	CPTitle->WinLeft=0.5;
	CPTitle->WinWidth=0.49;
	CPTitle->WinHeight=0.1;
	
	guibtnClose = CloseButton;
	guilTitle = CPTitle;
	WinHeight = 1;
}

void UAANPCPNB_PathNodeOptions::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	//Super::InitComponent(MyController, MyOwner);
}

void UAANPCPNB_PathNodeOptions::OnOpen()
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

void UAANPCPNB_PathNodeOptions::OnClose(bool bCanceled)
{
	/*
	local AGP_HUD HUD;
	local PlayerController PC;
	PC = PlayerOwner();
	HumanController(PlayerOwner()).guipCommandPost = nullptr;
	Super::OnClose(bCanceled);
	HUD = AGP_HUD(PlayerOwner().myHUD);
	HUD.bShowVersion = false;
	HUD.bShowSpectatorInfo = true;
	HUD.bShowHUD = bPlayerHUD;
	*/
}

bool UAANPCPNB_PathNodeOptions::OnCanClose(bool bCancelled)
{
	return true;
}

bool UAANPCPNB_PathNodeOptions::ButtonClick(UGUIComponent* Sender)
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