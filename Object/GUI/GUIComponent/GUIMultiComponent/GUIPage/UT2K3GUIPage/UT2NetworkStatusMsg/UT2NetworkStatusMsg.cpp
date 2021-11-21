// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/UT2K3GUIPage/UT2NetworkStatusMsg/UT2NetworkStatusMsg.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"


UUT2NetworkStatusMsg::UUT2NetworkStatusMsg()
{
	UGUIButton* NetStatOk = NewObject<UGUIButton>(UGUIButton::StaticClass());
	NetStatOk->Caption = "OK";
	NetStatOk->StyleName = "MidGameButton";
	NetStatOk->WinTop = 0.675;
	NetStatOk->WinLeft = 0.375;
	NetStatOk->WinWidth = 0.25;
	NetStatOk->WinHeight = 0.05;
	NetStatOk->bBoundToParent = true;
	//NetStatOk->OnClick=UT2NetworkStatusMsg.InternalOnClick;
	//NetStatOk->OnKeyEvent=NetStatOk.InternalOnKeyEvent;
	UGUIButton* NetStatBackground = NewObject<UGUIButton>(UGUIButton::StaticClass());
	NetStatBackground->StyleName = "SquareBar";
	NetStatBackground->WinTop = 0.375;
	NetStatBackground->WinHeight = 0.25;
	NetStatBackground->bAcceptsInput = false;
	NetStatBackground->bNeverFocus = true;
	//NetStatBackground->OnKeyEvent=NetStatBackground.InternalOnKeyEvent;
	UGUILabel* NetStatLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	NetStatLabel->TextAlign = ETextAlign::TXTA_Center;
	NetStatLabel->TextColor = FColor(255, 255, 255, 255);
	NetStatLabel->TextFont = "UT2HeaderFont";
	NetStatLabel->bMultiLine = true;
	NetStatLabel->WinTop = 0.125;
	NetStatLabel->WinHeight = 0.5;
	NetStatLabel->bBoundToParent = true;
	bIgnoreEsc = true;
	bRequire640x480 = false;
	Controls = { NetStatBackground,NetStatOk,NetStatLabel };
	WinTop = 0.375;
	WinHeight = 0.25;
}

void UUT2NetworkStatusMsg::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	Super::InitComponent(MyController, MyOwner);
	PlayerOwner().ClearProgressMessages();
	*/
}

bool UUT2NetworkStatusMsg::InternalOnClick(UGUIComponent* Sender)
{
	/*
	if (Sender == Controls[1])
	{
		Controller.ReplaceMenu("xinterface.ServerBrowser");
	}
	*/
	return true;
}

void UUT2NetworkStatusMsg::HandleParameters(FString Param1, FString Param2)
{
	/*
	GUILabel(Controls[2]).Caption = Param1 $ "|" $ Param2;
	PlayerOwner().ClearProgressMessages();
	*/
}