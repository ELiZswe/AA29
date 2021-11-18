// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/AANPCPNB_OpenPNBFile/AANPCPNB_OpenPNBFile.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIListBox/GUIListBox.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"

UAANPCPNB_OpenPNBFile::UAANPCPNB_OpenPNBFile()
{
	UGUIButton* ButtonOpen = NewObject<UGUIButton>(UGUIButton::StaticClass());
	ButtonOpen->Caption="Open File";
	ButtonOpen->StyleName="SquareMenuButton";
	ButtonOpen->Hint="Click here to open the selected Path Node Builderr file.";
	ButtonOpen->WinTop=0.7;
	ButtonOpen->WinLeft=0.3;
	ButtonOpen->WinWidth=0.15;
	ButtonOpen->WinHeight=0.053476;
	//ButtonOpen->OnClick=AANPCPNB_OpenPNBFile.ButtonClick;
	//ButtonOpen->OnKeyEvent=ButtonOpen.InternalOnKeyEvent;
	UGUIButton* ButtonCancel = NewObject<UGUIButton>(UGUIButton::StaticClass());
	ButtonCancel->Caption="Cancel";
	ButtonCancel->StyleName="SquareMenuButton";
	ButtonCancel->Hint="Click here to cancel opening a new Path Node Builder file.";
	ButtonCancel->WinTop=0.7;
	ButtonCancel->WinLeft=0.55;
	ButtonCancel->WinWidth=0.15;
	ButtonCancel->WinHeight=0.053476;
	//ButtonCancel->OnClick=AANPCPNB_OpenPNBFile.ButtonClick;
	//ButtonCancel->OnKeyEvent=ButtonCancel.InternalOnKeyEvent;
	UGUIListBox* ListBoxFileList = NewObject<UGUIListBox>(UGUIListBox::StaticClass());
	ListBoxFileList->bVisibleWhenEmpty=true;
	ListBoxFileList->bSorted=true;
	//ListBoxFileList->OnCreateComponent=ListBoxFileList.InternalOnCreateComponent;
	ListBoxFileList->StyleName="ServerBrowserGrid";
	ListBoxFileList->WinTop=0.35;
	ListBoxFileList->WinLeft=0.3;
	ListBoxFileList->WinWidth=0.4;
	ListBoxFileList->WinHeight=0.3;
	ListBoxFileList->bAcceptsInput=false;
	ListBoxFileList->bNeverFocus=true;
	UGUILabel* CPTitle = NewObject<UGUILabel>(UGUILabel::StaticClass());
	CPTitle->Caption="Open Path Node Builder File";
	CPTitle->TextAlign = ETextAlign::TXTA_Center;
	CPTitle->TextColor=FColor(200, 200, 200, 255);
	CPTitle->TextFont="AAFontMedium";
	CPTitle->bMultiLine=true;
	CPTitle->WinTop=0.26;
	CPTitle->WinLeft=0.3;
	CPTitle->WinWidth=0.4;
	CPTitle->WinHeight=0.1;

	guibtnCancel = ButtonCancel;
	guilTitle = CPTitle;
	guilbAvailableFiles = ListBoxFileList;
	guibtnOpen = ButtonOpen;
	WinTop = 0.25;
	WinLeft = 0.25;
	WinWidth = 0.75;
	WinHeight = 0.75;

}

void UAANPCPNB_OpenPNBFile::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	local StudentController SC;
	int32 iFile = 0;
	Super::InitComponent(MyController, MyOwner);
	SC = StudentController(PlayerOwner());
	AGP_HUD(SC.myHUD).bShowHUD = false;
	SC.npcpnbPathNodeBuilder.GetPathNodeFileList();
	for (iFile = 0; iFile < SC.npcpnbPathNodeBuilder.asPNBFileList.Length; iFile++)
	{
		guilbAvailableFiles.List.Insert(iFile, SC.npcpnbPathNodeBuilder.asPNBFileList[iFile]);
	}
	*/
}

void UAANPCPNB_OpenPNBFile::OnOpen()
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

void UAANPCPNB_OpenPNBFile::OnClose(bool bCanceled)
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

bool UAANPCPNB_OpenPNBFile::OnCanClose(bool bCancelled)
{
	return true;
}

bool UAANPCPNB_OpenPNBFile::ButtonClick(UGUIComponent* Sender)
{
	/*
	switch (Sender)
	{
	case guibtnOpen:
		HumanController(PlayerOwner()).ClientMessage("Loading " $ guilbAvailableFiles.List.Get());
		HumanController(PlayerOwner()).ConsoleCommand("LoadPaths " $ guilbAvailableFiles.List.Get());
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
