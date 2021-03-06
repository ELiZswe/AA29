// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/AANPCPNB_StartPatrolPath/AANPCPNB_StartPatrolPath.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moEditBox/moEditBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"
#include "AA29/Object/Actor/HUD/AGP_HUD/AGP_HUD.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/StudentController/StudentController.h"

UAANPCPNB_StartPatrolPath::UAANPCPNB_StartPatrolPath()
{
	UGUIButton* ButtonStartPatrolPath = NewObject<UGUIButton>(UGUIButton::StaticClass());
	ButtonStartPatrolPath->Caption = "Start Patrol";
	ButtonStartPatrolPath->StyleName = "SquareMenuButton";
	ButtonStartPatrolPath->Hint = "Click here to start a new patrol path using the Patrol name you have specified.";
	ButtonStartPatrolPath->WinTop = 0.7;
	ButtonStartPatrolPath->WinLeft = 0.3;
	ButtonStartPatrolPath->WinWidth = 0.15;
	ButtonStartPatrolPath->WinHeight = 0.053476;
	//ButtonStartPatrolPath->OnClick=AANPCPNB_StartPatrolPath.ButtonClick;
	//ButtonStartPatrolPath->OnKeyEvent=ButtonStartPatrolPath.InternalOnKeyEvent;
	UGUIButton* ButtonCancel = NewObject<UGUIButton>(UGUIButton::StaticClass());
	ButtonCancel->Caption = "Cancel";
	ButtonCancel->StyleName = "SquareMenuButton";
	ButtonCancel->Hint = "Click here to cancel starting a new patrol path.";
	ButtonCancel->WinTop = 0.7;
	ButtonCancel->WinLeft = 0.55;
	ButtonCancel->WinWidth = 0.15;
	ButtonCancel->WinHeight = 0.053476;
	//ButtonCancel->OnClick=AANPCPNB_StartPatrolPath.ButtonClick;
	//ButtonCancel->OnKeyEvent=ButtonCancel.InternalOnKeyEvent;
	UmoEditBox* EditBoxPatrolPathName = NewObject<UmoEditBox>(UmoEditBox::StaticClass());
	EditBoxPatrolPathName->CaptionWidth = 0.4;
	EditBoxPatrolPathName->Caption = "Patrol Path Name:";
	//EditBoxPatrolPathName->OnCreateComponent=EditBoxPatrolPathName.InternalOnCreateComponent;
	EditBoxPatrolPathName->IniOption = "@Internal";
	EditBoxPatrolPathName->Hint = "Use this to enter the name of the patrol path you want to create.";
	EditBoxPatrolPathName->WinTop = 0.4;
	EditBoxPatrolPathName->WinLeft = 0.26;
	EditBoxPatrolPathName->WinWidth = 0.44;
	EditBoxPatrolPathName->WinHeight = 0.05;
	EditBoxPatrolPathName->TabOrder = 1;
	EditBoxPatrolPathName->bStandardized = false;
	//EditBoxPatrolPathName->OnChange=AANPCPNB_StartPatrolPath.InternalOnChange;
	UGUILabel* CPTitle = NewObject<UGUILabel>(UGUILabel::StaticClass());
	CPTitle->Caption = "Create New Path Node Builder Patrol Path";
	CPTitle->TextAlign = ETextAlign::TXTA_Center;
	CPTitle->TextColor = FColor(200, 200, 200, 255);
	CPTitle->TextFont = "AAFontMedium";
	CPTitle->bMultiLine = true;
	CPTitle->WinTop = 0.26;
	CPTitle->WinLeft = 0.3;
	CPTitle->WinWidth = 0.4;
	CPTitle->WinHeight = 0.1;
	guibtnCancel = ButtonCancel;
	guilTitle = CPTitle;
	mebPatrolPathName = EditBoxPatrolPathName;
	guibtnStartPatrolPath = ButtonStartPatrolPath;
	WinTop = 0.25;
	WinLeft = 0.25;
	WinWidth = 0.75;
	WinHeight = 0.75;
}

void UAANPCPNB_StartPatrolPath::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	AStudentController* SC = nullptr;
	Super::InitComponent(MyController, MyOwner);
	SC = Cast<AStudentController>(PlayerOwner());
	Cast<AAGP_HUD>(SC->MyHUD)->bShowHUD = false;
	mebPatrolPathName->SetText(SC->npcpnbPathNodeBuilder->sWaypointNavTag);
}

void UAANPCPNB_StartPatrolPath::OnOpen()
{
	AAGP_HUD* HUD = nullptr;
	Super::OnOpen();
	HUD = Cast<AAGP_HUD>(PlayerOwner()->MyHUD);
	bPlayerHUD = HUD->bShowHUD;
	HUD->bShowVersion = true;
	HUD->bShowSpectatorInfo = false;
	HUD->bShowHUD = false;
}

void UAANPCPNB_StartPatrolPath::OnClose(bool bCanceled)
{
	AAGP_HUD* HUD = nullptr;
	APlayerController* PC = nullptr;
	PC = PlayerOwner();
	Cast<AHumanController>(PlayerOwner())->guipCommandPost = nullptr;
	Super::OnClose(bCanceled);
	HUD = Cast<AAGP_HUD>(PlayerOwner()->MyHUD);
	HUD->bShowVersion = false;
	HUD->bShowSpectatorInfo = true;
	HUD->bShowHUD = bPlayerHUD;
}

bool UAANPCPNB_StartPatrolPath::OnCanClose(bool bCancelled)
{
	return true;
}

bool UAANPCPNB_StartPatrolPath::ButtonClick(UGUIComponent* Sender)
{
	AStudentController* SC = nullptr;
	SC = Cast<AStudentController>(PlayerOwner());
	/*
	switch (Sender)
	{
	case guibtnStartPatrolPath:
		SC.npcpnbPathNodeBuilder.StartNewPatrolPath(mebPatrolPathName.GetText());
		Sender.SetFocus(nullptr);
		fCloseRequested = true;
		Cast<AHumanController>(PlayerOwner())->Player.bShowWindowsMouse = false;
		Cast<AHumanController>(PlayerOwner())->ClientCloseMenu(true);
		break;
	case guibtnCancel:
		Sender.SetFocus(nullptr);
		fCloseRequested = true;
		Cast<AHumanController>(PlayerOwner())->Player.bShowWindowsMouse = false;
		Cast<AHumanController>(PlayerOwner())->ClientCloseMenu(true);
		break;
	default:
	}
	*/
	return true;
}

void UAANPCPNB_StartPatrolPath::InternalOnChange(UGUIComponent* Sender)
{
}
