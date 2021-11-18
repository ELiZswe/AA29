// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/Tab_ServerInfo/Tab_ServerInfo.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIScrollTextBox/GUIScrollTextBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"

UTab_ServerInfo::UTab_ServerInfo()
{
	UGUIScrollTextBox* InfoText = NewObject<UGUIScrollTextBox>(UGUIScrollTextBox::StaticClass());
	InfoText->bNoTeletype = true;
	InfoText->CharDelay = 0.0025;
	InfoText->EOLDelay = 0;
	InfoText->TextAlign = EeTextAlign::TXTA_Center;
	//InfoText->OnCreateComponent=InfoText.InternalOnCreateComponent;
	InfoText->WinTop = 0.14375;
	InfoText->WinHeight = 0.834375;
	InfoText->bBoundToParent = true;
	InfoText->bScaleToParent = true;
	InfoText->bNeverFocus = true;
	UGUIImage* ServerInfoBK1 = NewObject<UGUIImage>(UGUIImage::StaticClass());
	//ServerInfoBK1->Image=Texture'InterfaceContent.Menu.BorderBoxD';
	ServerInfoBK1->ImageColor = FColor(255, 255, 255, 160);
	ServerInfoBK1->ImageStyle = EImgStyle::ISTY_Stretched;
	ServerInfoBK1->WinTop = 0.070779;
	ServerInfoBK1->WinLeft = 0.021641;
	ServerInfoBK1->WinWidth = 0.418437;
	ServerInfoBK1->WinHeight = 0.016522;
	ServerInfoBK1->bBoundToParent = true;
	ServerInfoBK1->bScaleToParent = true;
	UGUIImage* ServerInfoBK2 = NewObject<UGUIImage>(UGUIImage::StaticClass());
	//ServerInfoBK2->Image=Texture'InterfaceContent.Menu.BorderBoxD';
	ServerInfoBK2->ImageColor = FColor(255, 255, 255, 160);
	ServerInfoBK2->ImageStyle = EImgStyle::ISTY_Stretched;
	ServerInfoBK2->WinTop = 0.070779;
	ServerInfoBK2->WinLeft = 0.576329;
	ServerInfoBK2->WinWidth = 0.395;
	ServerInfoBK2->WinHeight = 0.016522;
	ServerInfoBK2->bBoundToParent = true;
	ServerInfoBK2->bScaleToParent = true;
	UGUILabel* ServerInfoLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	ServerInfoLabel->Caption = "Rules";
	ServerInfoLabel->TextAlign = ETextAlign::TXTA_Center;
	ServerInfoLabel->TextColor = FColor(255, 255, 255, 255);
	ServerInfoLabel->WinTop = 0.027083;
	ServerInfoLabel->WinHeight = 32;
	ServerInfoLabel->bBoundToParent = true;
	ServerInfoLabel->bScaleToParent = true;
	DefaultText = "Receiving Rules from Server...||This feature requires that the server be running the latest patch";
	Controls = { InfoText,ServerInfoBK1,ServerInfoBK2,ServerInfoLabel };
	WinHeight = 0.7;
}

void UTab_ServerInfo::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	Super::InitComponent(MyController, MyOwner);
	MyScrollText = GUIScrollTextBox(Controls[0]);
	WinWidth = Controller.ActivePage.WinWidth;
	WinHeight = (Controller.ActivePage.WinHeight * 0.7);
	WinLeft = Controller.ActivePage.WinLeft;
	bClean = true;
	MyScrollText.SetContent(DefaultText);
	*/
}

void UTab_ServerInfo::ProcessRule(FString NewRule)
{
	/*
	if (NewRule == "")
	{
		bClean = true;
		MyScrollText.SetContent(DefaultText);
	}
	else
	{
		if (bClean)
		{
			MyScrollText.SetContent(NewRule);
		}
		else
		{
			MyScrollText.AddText(NewRule);
		}
		bClean = false;
	}
	*/
}