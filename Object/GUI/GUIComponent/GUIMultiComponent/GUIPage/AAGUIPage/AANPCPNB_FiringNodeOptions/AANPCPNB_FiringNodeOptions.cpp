// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/AANPCPNB_FiringNodeOptions/AANPCPNB_FiringNodeOptions.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"
#include "AA29/Object/Actor/HUD/AGP_HUD/AGP_HUD.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"

UAANPCPNB_FiringNodeOptions::UAANPCPNB_FiringNodeOptions()
{
	UGUIButton* CloseButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	CloseButton->Caption="Close PNB Firing Node Options";
	CloseButton->StyleName="SquareMenuButton";
	CloseButton->Hint="Click here to close the Command Post.";
	CloseButton->WinTop=0.93;
	CloseButton->WinLeft=0.38;
	CloseButton->WinWidth=0.25;
	CloseButton->WinHeight=0.053476;
	//CloseButton->OnClick=AANPCPNB_FiringNodeOptions.ButtonClick;
	//CloseButton->OnKeyEvent=CloseButton.InternalOnKeyEvent;
	UGUILabel* CPTitle = NewObject<UGUILabel>(UGUILabel::StaticClass());
	CPTitle->Caption="AA NPC Path Builder Firing Node Options";
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

void UAANPCPNB_FiringNodeOptions::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	//Super::InitComponent(MyController, MyOwner);
}

void UAANPCPNB_FiringNodeOptions::OnOpen()
{
	/*
	AAGP_HUD* HUD = nullptr;
	Super::OnOpen();
	HUD = Cast<AAGP_HUD>(PlayerOwner()->MyHUD);
	bPlayerHUD = HUD.bShowHUD;
	HUD.bShowVersion = true;
	HUD.bShowSpectatorInfo = false;
	HUD.bShowHUD = false;
	*/
}

void UAANPCPNB_FiringNodeOptions::OnClose(bool bCanceled)
{
	/*
	AAGP_HUD* HUD = nullptr;
	APlayerController* PC = nullptr;
	PC = PlayerOwner();
	Cast<AHumanController>(PlayerOwner())->guipCommandPost = nullptr;
	Super::OnClose(bCanceled);
	HUD = Cast<AAGP_HUD>(PlayerOwner()->MyHUD);
	HUD.bShowVersion = false;
	HUD.bShowSpectatorInfo = true;
	HUD.bShowHUD = bPlayerHUD;
	*/
}

bool UAANPCPNB_FiringNodeOptions::OnCanClose(bool bCancelled)
{
	return true;
}

bool UAANPCPNB_FiringNodeOptions::ButtonClick(UGUIComponent* Sender)
{
	/*
	switch (Sender)
	{
	case guibtnClose:
		Sender.SetFocus(nullptr);
		fCloseRequested = true;
		Cast<AHumanController>(PlayerOwner())->ClientCloseMenu(true);
		break;
	default:
	}
	*/
	return true;
}
