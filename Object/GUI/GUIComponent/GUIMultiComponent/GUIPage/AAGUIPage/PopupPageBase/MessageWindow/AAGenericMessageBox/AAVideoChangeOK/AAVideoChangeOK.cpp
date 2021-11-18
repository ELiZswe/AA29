// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/MessageWindow/AAGenericMessageBox/AAVideoChangeOK/AAVideoChangeOK.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"

UAAVideoChangeOK::UAAVideoChangeOK()
{
	UGUIButton* bCancel = NewObject<UGUIButton>(UGUIButton::StaticClass());
	bCancel->Caption = "Restore Settings";
	bCancel->WinTop = 0.558334;
	bCancel->WinLeft = 0.65;
	bCancel->WinWidth = 0.2;
	bCancel->bBoundToParent = true;
	//bCancel->OnClick=AAVideoChangeOK.InternalOnClick;
	//bCancel->OnKeyEvent=bCancel.InternalOnKeyEvent;
	UGUIButton* bOk = NewObject<UGUIButton>(UGUIButton::StaticClass());
	bOk->Caption = "Keep Settings";
	bOk->WinTop = 0.558334;
	bOk->WinLeft = 0.175;
	bOk->WinWidth = 0.2;
	bOk->bBoundToParent = true;
	//bOk->OnClick=AAVideoChangeOK.InternalOnClick;
	//bOk->OnKeyEvent=bOk.InternalOnKeyEvent;
	UGUILabel* lbText = NewObject<UGUILabel>(UGUILabel::StaticClass());
	lbText->Caption = "Accept these settings?";
	lbText->TextAlign = ETextAlign::TXTA_Center;
	lbText->StyleName = "TextButton";
	lbText->WinTop = 0.39;
	lbText->WinHeight = 0.06875;
	UGUILabel* lbText2 = NewObject<UGUILabel>(UGUILabel::StaticClass());
	lbText2->Caption = "(Original settings will be restored in 15 seconds)";
	lbText2->TextAlign = ETextAlign::TXTA_Center;
	lbText2->StyleName = "TextButton";
	lbText2->WinTop = 0.46;
	lbText2->WinHeight = 0.045;
	RestoreText = "(Original settings will be restored in %count% %seconds%)";
	SecondText = "second";
	SecondsText = "seconds";
	b_Cancel = bCancel;
	b_OK = bOk;
	l_Text = lbText;
	l_Text2 = lbText2;
}

void UAAVideoChangeOK::InitComponent(UGUIController* InController, UGUIComponent* InOwner)
{
	//Super::InitComponent(InController, InOwner);
	//OverrideResNotice = Localize("UT2DeferChangeRes", "DialogText.Caption", "XInterface") $ "|" $ Localize("UT2DeferChangeRes", "DialogText2.Caption", "XInterface");
}

void UAAVideoChangeOK::Execute(FString DesiredRes)
{
	/*
	if (DesiredRes == "")
	{
		KillTimer();
		if (Controller.ActivePage == Self)
		{
			Controller.CloseMenu();
		}
		return;
	}
	if ((InStr(DesiredRes, "x16") != -1) || (InStr(DesiredRes, "x32") != -1))
	{
		ChangeType = 0;
		ChangeResolution(DesiredRes);
	}
	else
	{
		if (DesiredRes ~= "togglefullscreen")
		{
			ChangeType = 1;
			ToggleFullScreen();
		}
		else
		{
			ChangeType = 2;
			SetDevice(DesiredRes);
		}
	}
	*/
}

void UAAVideoChangeOK::ToggleFullScreen()
{
	/*
	RevertString = "togglefullscreen";
	PlayerOwner().ConsoleCommand(RevertString);
	StartTimer();
	*/
}

void UAAVideoChangeOK::ChangeResolution(FString DesiredRes)
{
	/*
	int32 i = 0;
	FString CurrentRes = "";
	FString NewX = "";
	FString NewY = "";
	FString NewDepth = "";
	FString NewScreen = "";
	bool LowRes = false;
	CurrentRes = Controller.GetCurrentRes();
	LowRes = bool(PlayerOwner().ConsoleCommand("get ini:Engine.Engine.RenderDevice Use16bit"));
	RevertString = "setres" @ CurrentRes;
	if (LowRes)
	{
		(RevertString $ = "x32");
	}
	else
	{
		(RevertString $ = "x32");
	}
	if (bool(PlayerOwner().ConsoleCommand("ISFULLSCREEN")))
	{
		(RevertString $ = "f");
	}
	else
	{
		(RevertString $ = "w");
	}
	PlayerOwner().ConsoleCommand("set ini:Engine.Engine.RenderDevice Use16bit 0");
	i = InStr(DesiredRes, "x");
	NewX = Left(DesiredRes, i);
	NewY = Mid(DesiredRes, (i + 1));
	i = InStr(NewY, "x");
	if (i != -1)
	{
		NewDepth = Mid(NewY, i);
		NewY = Left(NewY, i);
		if ((Right(NewDepth, 1) ~= "f") || (Right(NewDepth, 1) ~= "w"))
		{
			NewScreen = Right(NewDepth, 1);
			NewDepth = Left(NewDepth, (Len(NewDepth) - 1));
		}
	}
	if ((int(NewX) < 640) || (int(NewY) < 480))
	{
		KillTimer();
		PlayerOwner().ConsoleCommand("TEMPSETRES 640x480" $ NewDepth $ NewScreen);
		if (Controller.OpenMenu("GUI2K4.UT2K4GenericMessageBox", "", OverrideResNotice))
		{
			Controller.ActivePage.__OnClose__Delegate = DeferChangeOnClose;
		}
	}
	else
	{
		PlayerOwner().ConsoleCommand("SETRES" @ DesiredRes);
		StartTimer();
	}
	*/
}

void UAAVideoChangeOK::SetDevice(FString NewRenderDevice)
{
	/*
	RevertString = PlayerOwner().ConsoleCommand("get ini:Engine.Engine.RenderDevice Class");
	if ((RevertString ~= NewRenderDevice) || (!Controller.SetRenderDevice(NewRenderDevice)))
	{
		KillTimer();
		if (Controller.ActivePage == Self)
		{
			Controller.CloseMenu();
		}
		return;
	}
	*/
	StartTimer();
}

void UAAVideoChangeOK::DeferChangeOnClose(bool bCancelled)
{
	StartTimer();
}

void UAAVideoChangeOK::StartTimer()
{
	Count = 15;
	//SetTimer(1, true);
}

void UAAVideoChangeOK::Timer()
{
	/*
	(Count);
	l_Text2.Caption = Repl(RestoreText, "%count%", string(Count));
	if (Count == 1)
	{
		l_Text2.Caption = Repl(l_Text2.Caption, "%seconds%", SecondText);
	}
	else
	{
		l_Text2.Caption = Repl(l_Text2.Caption, "%seconds%", SecondsText);
	}
	if (Count <= 0)
	{
		InternalOnClick(b_Cancel);
	}
	*/
}

bool UAAVideoChangeOK::InternalOnClick(UGUIComponent* Sender)
{
	/*
	KillTimer();
	if (Sender == b_Cancel)
	{
		switch (ChangeType)
		{
		case 0:
			PlayerOwner().ConsoleCommand("set ini:Engine.Engine.RenderDevice Use16bit 0");
			PlayerOwner().ConsoleCommand(RevertString);
			break;
		case 1:
			PlayerOwner().ConsoleCommand(RevertString);
			break;
		case 2:
			Controller.SetRenderDevice(RevertString);
			break;
		default:
		}
	}
	Controller.CloseMenu((Sender == b_Cancel));
	*/
	return true;
}