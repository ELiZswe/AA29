// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/AANPCPNB_SavePNBFile/AANPCPNB_SavePNBFile.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moEditBox/moEditBox.h"

UAANPCPNB_SavePNBFile::UAANPCPNB_SavePNBFile()
{
	UGUIButton* ButtonSave = NewObject<UGUIButton>(UGUIButton::StaticClass());
	ButtonSave->Caption = "Save File";
	ButtonSave->StyleName = "SquareMenuButton";
	ButtonSave->Hint = "Click here to open the selected Path Node Builder file.";
	ButtonSave->WinTop = 0.7;
	ButtonSave->WinLeft = 0.3;
	ButtonSave->WinWidth = 0.15;
	ButtonSave->WinHeight = 0.053476;
	//ButtonSave->OnClick=AANPCPNB_SavePNBFile.ButtonClick;
	//ButtonSave->OnKeyEvent=ButtonSave.InternalOnKeyEvent;
	UGUIButton* ButtonCancel = NewObject<UGUIButton>(UGUIButton::StaticClass());
	ButtonCancel->Caption = "Cancel";
	ButtonCancel->StyleName = "SquareMenuButton";
	ButtonCancel->Hint = "Click here to cancel saving the Path Node Builder file.";
	ButtonCancel->WinTop = 0.7;
	ButtonCancel->WinLeft = 0.55;
	ButtonCancel->WinWidth = 0.15;
	ButtonCancel->WinHeight = 0.053476;
	//ButtonCancel->OnClick=AANPCPNB_SavePNBFile.ButtonClick;
	//ButtonCancel->OnKeyEvent=ButtonCancel.InternalOnKeyEvent;
	UmoEditBox* EditBoxSaveFileName = NewObject<UmoEditBox>(UmoEditBox::StaticClass());
	EditBoxSaveFileName->CaptionWidth = 0.4;
	EditBoxSaveFileName->Caption = "File Name:";
	//EditBoxSaveFileName->OnCreateComponent=EditBoxSaveFileName.InternalOnCreateComponent;
	EditBoxSaveFileName->IniOption = "@Internal";
	EditBoxSaveFileName->Hint = "Use this to enter the name of the file to save the Path Node Builder information to.";
	EditBoxSaveFileName->WinTop = 0.4;
	EditBoxSaveFileName->WinLeft = 0.26;
	EditBoxSaveFileName->WinWidth = 0.44;
	EditBoxSaveFileName->WinHeight = 0.05;
	EditBoxSaveFileName->TabOrder = 1;
	EditBoxSaveFileName->bStandardized = false;
	//EditBoxSaveFileName->OnChange=AANPCPNB_SavePNBFile.InternalOnChange;
	UGUILabel* CPTitle = NewObject<UGUILabel>(UGUILabel::StaticClass());
	CPTitle->Caption = "Open Path Node Builder File";
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
	mebSaveFileName = EditBoxSaveFileName;
	guibtnSave = ButtonSave;
	WinTop = 0.25;
	WinLeft = 0.25;
	WinWidth = 0.75;
	WinHeight = 0.75;
}

void UAANPCPNB_SavePNBFile::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	local StudentController SC;
	Super::InitComponent(MyController, MyOwner);
	SC = StudentController(PlayerOwner());
	AGP_HUD(SC.myHUD).bShowHUD = false;
	mebSaveFileName.SetText(SC.npcpnbPathNodeBuilder.sCurrentPNBFileName);
	*/
}

void UAANPCPNB_SavePNBFile::OnOpen()
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

void UAANPCPNB_SavePNBFile::OnClose(bool bCanceled)
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

bool UAANPCPNB_SavePNBFile::OnCanClose(bool bCancelled)
{
	return true;
}

bool UAANPCPNB_SavePNBFile::ButtonClick(UGUIComponent* Sender)
{
	/*
	local StudentController SC;
	SC = StudentController(PlayerOwner());
	switch (Sender)
	{
	case guibtnSave:
		SC.npcpnbPathNodeBuilder.sCurrentPNBFileName = mebSaveFileName.GetText();
		SC.npcpnbPathNodeBuilder.SavePathNodesToFile(SC.npcpnbPathNodeBuilder.sCurrentPNBFileName);
		Sender.SetFocus(None);
		fCloseRequested = true;
		HumanController(PlayerOwner()).Player.bShowWindowsMouse = false;
		HumanController(PlayerOwner()).ClientCloseMenu(true);
		break;
	case guibtnCancel:
		Sender.SetFocus(None);
		fCloseRequested = true;
		HumanController(PlayerOwner()).Player.bShowWindowsMouse = false;
		HumanController(PlayerOwner()).ClientCloseMenu(true);
		break;
	default:
	}
	*/
	return true;
}

void UAANPCPNB_SavePNBFile::InternalOnChange(UGUIComponent* Sender)
{
}