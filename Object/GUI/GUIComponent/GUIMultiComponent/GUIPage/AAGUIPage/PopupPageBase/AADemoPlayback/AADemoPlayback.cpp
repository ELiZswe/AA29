// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/AADemoPlayback/AADemoPlayback.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/StateButton/StateButton.h"

UAADemoPlayback::UAADemoPlayback()
{
	UStateButton* bFF = NewObject<UStateButton>(UStateButton::StaticClass());
	bFF->WinTop = 0.1;
	bFF->WinLeft = 0.0975;
	bFF->WinWidth = 0.04;
	bFF->WinHeight = 0.8;
	bFF->TabOrder = 2;
	bFF->bBoundToParent = true;
	bFF->bScaleToParent = true;
	//bFF->OnClick=AADemoPlayback.FastForwardClick;
	//bFF->OnKeyEvent=bFF.InternalOnKeyEvent;
	UStateButton* bPlayPause = NewObject<UStateButton>(UStateButton::StaticClass());
	bPlayPause->WinTop = 0.1;
	bPlayPause->WinLeft = 0.055;
	bPlayPause->WinWidth = 0.04;
	bPlayPause->WinHeight = 0.8;
	bPlayPause->TabOrder = 1;
	bPlayPause->bBoundToParent = true;
	bPlayPause->bScaleToParent = true;
	//bPlayPause->OnClick=AADemoPlayback.PlayPauseClick;
	//bPlayPause->OnKeyEvent=bPlayPause.InternalOnKeyEvent;
	UStateButton* bStop = NewObject<UStateButton>(UStateButton::StaticClass());
	bStop->WinTop = 0.1;
	bStop->WinLeft = 0.01375;
	bStop->WinWidth = 0.04;
	bStop->WinHeight = 0.8;
	bStop->TabOrder = 0;
	bStop->bBoundToParent = true;
	bStop->bScaleToParent = true;
	//bStop->OnClick=AADemoPlayback.StopClick;
	//bStop->OnKeyEvent=bStop.InternalOnKeyEvent;
	UGUILabel* lbMapName = NewObject<UGUILabel>(UGUILabel::StaticClass());
	lbMapName->TextAlign = ETextAlign::TXTA_Right;
	lbMapName->FontScale = EFontScale::FNS_Large;
	lbMapName->StyleName = "DarkTextLabel";
	lbMapName->WinLeft = 0.15;
	lbMapName->WinWidth = 0.825;
	lbMapName->WinHeight = 1;
	lbMapName->bBoundToParent = true;
	lbMapName->bScaleToParent = true;
	UGUILabel* lbMod = NewObject<UGUILabel>(UGUILabel::StaticClass());
	lbMod->Caption = "2X";
	lbMod->TextColor = FColor(106, 41, 14, 0);
	lbMod->TextFont = "UT2LargeFont";
	lbMod->WinLeft = 0.15;
	lbMod->WinWidth = 0.825;
	lbMod->WinHeight = 1;
	lbMod->bBoundToParent = true;
	lbMod->bScaleToParent = true;
	//lbMod->OnDraw = AADemoPlayback.ModDraw;
	b_FF = bFF;
	b_PlayPause = bPlayPause;
	b_Stop = bStop;
	lb_MapName = lbMapName;
	lb_Mod = lbMod;
	GameSpeedMods = { 1,2,4,8 };
	bAllowedAsLast = true;
	WinTop = -0.065;
	WinHeight = 0.065;
	//OnArrival = AADemoPlayback.Arrival;
}

void UAADemoPlayback::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	Super::InitComponent(MyController, MyOwner);
	OriginalGameSpeed = PlayerOwner().Level.TimeDilation;
	lb_MapName.Caption = PlayerOwner().Level.Title;
	Animate(0, 0, 0.15);
	*/
}

void UAADemoPlayback::Free()
{
	/*
	l_ViewTargets.Clear();
	Super::Free();
	*/
}

void UAADemoPlayback::Arrival(UGUIComponent* Sender, EAnimationType Type)
{
	//WinTop = 0;
}

bool UAADemoPlayback::StopClick(UGUIComponent* Sender)
{
	/*
	PlayerOwner().Level.TimeDilation = OriginalGameSpeed;
	PlayerOwner().ConsoleCommand("disconnect");
	*/
	return true;
}

bool UAADemoPlayback::PlayPauseClick(UGUIComponent* Sender)
{
	return true;
}

bool UAADemoPlayback::FastForwardClick(UGUIComponent* Sender)
{
	/*
	if (GameSpeedModifier < 3)
	{
		GameSpeedModifier++;
	}
	else
	{
		GameSpeedModifier = 0;
	}
	lb_Mod.Caption = "x" $ string(int(GameSpeedMods[GameSpeedModifier]));
	modfade = 255;
	PlayerOwner().Level.TimeDilation = (OriginalGameSpeed * GameSpeedMods[GameSpeedModifier]);
	*/
	return true;
}

bool UAADemoPlayback::ModDraw(UCanvas* C)
{
	/*
	if (modfade > 0)
	{
		(modfade -= (float(255) * Controller.RenderDelta));
		if (modfade >= 0)
		{
			lb_Mod.TextColor.A = byte(int(modfade));
			return false;
		}
	}
	lb_Mod.TextColor.A = 0;
	*/
	return false;
}