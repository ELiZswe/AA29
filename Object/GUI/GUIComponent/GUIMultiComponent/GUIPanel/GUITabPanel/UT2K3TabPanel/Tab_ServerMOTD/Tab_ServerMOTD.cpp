// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/Tab_ServerMOTD/Tab_ServerMOTD.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moEditBox/moEditBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIScrollTextBox/GUIScrollTextBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"

UTab_ServerMOTD::UTab_ServerMOTD()
{
	UmoEditBox* ServerAdminEmail = NewObject<UmoEditBox>(UmoEditBox::StaticClass());
	ServerAdminEmail->bReadOnly = true;
	ServerAdminEmail->CaptionWidth = 0.33;
	ServerAdminEmail->Caption = "      Email:";
	//ServerAdminEmail->OnCreateComponent=ServerAdminEmail.InternalOnCreateComponent;
	ServerAdminEmail->Hint = "How to contact the owner";
	ServerAdminEmail->WinTop = 0.153333;
	ServerAdminEmail->WinLeft = 0.05;
	ServerAdminEmail->WinWidth = 0.9;
	ServerAdminEmail->WinHeight = 0.06;
	ServerAdminEmail->bBoundToParent = true;
	ServerAdminEmail->bScaleToParent = true;
	UmoEditBox* ServerAdminName = NewObject<UmoEditBox>(UmoEditBox::StaticClass());
	ServerAdminName->bReadOnly = true;
	ServerAdminName->CaptionWidth = 0.33;
	ServerAdminName->Caption = "Admin Name:";
	//ServerAdminName->OnCreateComponent=ServerAdminName.InternalOnCreateComponent;
	ServerAdminName->Hint = "The owner of the server";
	ServerAdminName->WinTop = 0.064583;
	ServerAdminName->WinLeft = 0.05;
	ServerAdminName->WinWidth = 0.9;
	ServerAdminName->WinHeight = 0.06;
	ServerAdminName->bBoundToParent = true;
	ServerAdminName->bScaleToParent = true;
	UGUIScrollTextBox* MOTDText = NewObject<UGUIScrollTextBox>(UGUIScrollTextBox::StaticClass());
	MOTDText->bNoTeletype = true;
	MOTDText->CharDelay = 0.0025;
	MOTDText->EOLDelay = 0;
	MOTDText->TextAlign = EeTextAlign::TXTA_Center;
	//MOTDText->OnCreateComponent=MOTDText.InternalOnCreateComponent;
	MOTDText->WinTop = 0.441667;
	MOTDText->WinHeight = 0.540625;
	MOTDText->bBoundToParent = true;
	MOTDText->bScaleToParent = true;
	MOTDText->bNeverFocus = true;
	UGUIImage* ServerBK1 = NewObject<UGUIImage>(UGUIImage::StaticClass());
	//ServerBK1->Image=Texture'InterfaceContent.Menu.BorderBoxD';
	ServerBK1->ImageColor = FColor(255, 255, 255, 160);
	ServerBK1->ImageStyle = EImgStyle::ISTY_Stretched;
	ServerBK1->WinTop = 0.352029;
	ServerBK1->WinLeft = 0.021641;
	ServerBK1->WinWidth = 0.293437;
	ServerBK1->WinHeight = 0.016522;
	ServerBK1->bBoundToParent = true;
	ServerBK1->bScaleToParent = true;
	UGUIImage* ServerBK2 = NewObject<UGUIImage>(UGUIImage::StaticClass());
	//ServerBK2->Image=Texture'InterfaceContent.Menu.BorderBoxD';
	ServerBK2->ImageColor = FColor(255, 255, 255, 160);
	ServerBK2->ImageStyle = EImgStyle::ISTY_Stretched;
	ServerBK2->WinTop = 0.352029;
	ServerBK2->WinLeft = 0.685704;
	ServerBK2->WinWidth = 0.277812;
	ServerBK2->WinHeight = 0.016522;
	ServerBK2->bBoundToParent = true;
	ServerBK2->bScaleToParent = true;
	UGUILabel* ServerMOTDLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	ServerMOTDLabel->Caption = "Message of the Day";
	ServerMOTDLabel->TextAlign = ETextAlign::TXTA_Center;
	ServerMOTDLabel->TextColor = FColor(255, 255, 255, 255);
	ServerMOTDLabel->WinTop = 0.308333;
	ServerMOTDLabel->WinHeight = 32;
	ServerMOTDLabel->bBoundToParent = true;
	ServerMOTDLabel->bScaleToParent = true;
	Controls = { MOTDText,ServerAdminName,ServerAdminEmail,ServerBK1,ServerBK2,ServerMOTDLabel };
	WinHeight = 0.7;
}

void UTab_ServerMOTD::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	FString MOTDString = "";
	Super::InitComponent(MyController, MyOwner);
	MyScrollText = GUIScrollTextBox(Controls[0]);
	AdminName = moEditBox(Controls[1]);
	AdminEmail = moEditBox(Controls[2]);
	MOTDString = PlayerOwner().GameReplicationInfo.MessageOfTheDay;
	MyScrollText.SetContent(MOTDString);
	AdminName.SetText(PlayerOwner().GameReplicationInfo.AdminName);
	AdminEmail.SetText(PlayerOwner().GameReplicationInfo.AdminEmail);
	WinWidth = Controller.ActivePage.WinWidth;
	WinHeight = (Controller.ActivePage.WinHeight * 0.7);
	WinLeft = Controller.ActivePage.WinLeft;
	*/
}