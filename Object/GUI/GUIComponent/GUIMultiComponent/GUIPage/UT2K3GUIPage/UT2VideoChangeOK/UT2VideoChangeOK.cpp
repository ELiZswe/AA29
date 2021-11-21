// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/UT2K3GUIPage/UT2VideoChangeOK/UT2VideoChangeOK.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"

UUT2VideoChangeOK::UUT2VideoChangeOK()
{
	UGUIButton* BackButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	BackButton->Caption = "Restore Settings";
	BackButton->WinTop = 0.75;
	BackButton->WinLeft = 0.65;
	BackButton->WinWidth = 0.2;
	BackButton->bBoundToParent = true;
	//BackButton->OnClick=UT2VideoChangeOK.InternalOnClick;
	//BackButton->OnKeyEvent=BackButton.InternalOnKeyEvent;
	UGUIButton* AcceptButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	AcceptButton->Caption = "Keep Settings";
	AcceptButton->WinTop = 0.75;
	AcceptButton->WinLeft = 0.125;
	AcceptButton->WinWidth = 0.2;
	AcceptButton->bBoundToParent = true;
	//AcceptButton->OnClick=UT2VideoChangeOK.InternalOnClick;
	//AcceptButton->OnKeyEvent=AcceptButton.InternalOnKeyEvent;
	UGUIButton* VidOKBackground = NewObject<UGUIButton>(UGUIButton::StaticClass());
	VidOKBackground->StyleName = "SquareBar";
	VidOKBackground->WinHeight = 1;
	VidOKBackground->bBoundToParent = true;
	VidOKBackground->bScaleToParent = true;
	VidOKBackground->bAcceptsInput = false;
	VidOKBackground->bNeverFocus = true;
	//VidOKBackground->OnKeyEvent=VidOKBackground.InternalOnKeyEvent;
	UGUILabel* VideoOKDesc = NewObject<UGUILabel>(UGUILabel::StaticClass());
	VideoOKDesc->Caption = "Accept these settings?";
	VideoOKDesc->TextAlign = ETextAlign::TXTA_Center;
	VideoOKDesc->TextColor = FColor(0, 200, 230, 255);
	VideoOKDesc->TextFont = "UT2HeaderFont";
	VideoOKDesc->WinTop = 0.4;
	VideoOKDesc->WinHeight = 32;
	UGUILabel* VideoOkTimerDesc = NewObject<UGUILabel>(UGUILabel::StaticClass());
	VideoOkTimerDesc->Caption = "(Original settings will be restored in 15 seconds)";
	VideoOkTimerDesc->TextAlign = ETextAlign::TXTA_Center;
	VideoOkTimerDesc->TextColor = FColor(0, 200, 230, 255);
	VideoOkTimerDesc->WinTop = 0.46;
	VideoOkTimerDesc->WinHeight = 32;
	RestoreTextPre = "(Original settings will be restored in ";
	RestoreTextPost = " seconds)";
	RestoreTextSingular = "(Original settings will be restored in 1 second)";
	InactiveFadeColor = FColor(128, 128, 128, 255);
	Controls = { VidOKBackground,AcceptButton,BackButton,VideoOKDesc,VideoOkTimerDesc };
	WinTop = 0.375;
	WinHeight = 0.25;
	//OnActivate = UT2VideoChangeOK.StartTimer;
}

void UUT2VideoChangeOK::Timer()
{
	Count--;
	/*
	if (Count > 1)
	{
		GUILabel(Controls[4]).Caption = RestoreTextPre $ string(Count) $ RestoreTextPost;
	}
	else
	{
		GUILabel(Controls[4]).Caption = RestoreTextSingular;
	}
	if (Count <= 0)
	{
		SetTimer(0);
		PlayerOwner().ConsoleCommand("set ini:Engine.Engine.RenderDevice Use16bit" @ string((InStr(OrigRes, "x16") != -1)));
		PlayerOwner().ConsoleCommand("setres" @ OrigRes);
		Controller.CloseMenu(true);
	}
	*/
}

void UUT2VideoChangeOK::Execute(FString DesiredRes)
{
	/*
	FString res = "";
	FString bit = "";
	FString X = "";
	FString Y = "";
	int32 i = 0;
	if (DesiredRes == "")
	{
		return;
	}
	res = Controller.GetCurrentRes();
	bit = PlayerOwner().ConsoleCommand("get ini:Engine.Engine.RenderDevice Use16bit");
	if (bit == "true")
	{
		OrigRes = res $ "x16";
	}
	else
	{
		OrigRes = res $ "x32";
	}
	if (bool(PlayerOwner().ConsoleCommand("ISFULLSCREEN")))
	{
		OrigRes = OrigRes $ "f";
	}
	else
	{
		OrigRes = OrigRes $ "w";
	}
	PlayerOwner().ConsoleCommand("set ini:Engine.Engine.RenderDevice Use16bit" @ string((InStr(DesiredRes, "x16") != -1)));
	PlayerOwner().ConsoleCommand("setres" @ DesiredRes);
	i = InStr(DesiredRes, "x");
	X = Left(DesiredRes, i);
	Y = Mid(DesiredRes, (i + 1));
	if ((int(X) < 640) || (int(Y) < 480))
	{
		PlayerOwner().ConsoleCommand("tempsetres 640x480");
		SetTimer(0, false);
		Controller.ReplaceMenu("xinterface.UT2DeferChangeRes");
		Controller.GameResolution = Left(DesiredRes, (Len(DesiredRes) - 4));
	}
	else
	{
		Controller.GameResolution = "";
	}
	*/
}

void UUT2VideoChangeOK::StartTimer()
{
	/*
	Count = 15;
	SetTimer(1, true);
	*/
}

bool UUT2VideoChangeOK::InternalOnClick(UGUIComponent* Sender)
{
	/*
	SetTimer(0);
	if (Sender == Controls[2])
	{
		PlayerOwner().ConsoleCommand("set ini:Engine.Engine.RenderDevice Use16bit" @ string((InStr(OrigRes, "x16") != -1)));
		PlayerOwner().ConsoleCommand("setres" @ OrigRes);
	}
	GUILabel(Controls[3]).Caption = "Accept these settings?";
	Controller.CloseMenu((Sender == Controls[2]));
	*/
	return true;
}