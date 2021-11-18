// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/AAGameMenu_DemoControls/AAGameMenu_DemoControls.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
UAAGameMenu_DemoControls::UAAGameMenu_DemoControls()
{
	UGUIButton* PlayPauseDemoButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	PlayPauseDemoButton->Caption="Pause";
	PlayPauseDemoButton->FontScale = EFontScale::FNS_Small;
	PlayPauseDemoButton->Hint="Play / Pause the demo playback";
	PlayPauseDemoButton->WinTop=0.04;
	PlayPauseDemoButton->WinLeft=0.4375;
	PlayPauseDemoButton->WinWidth=0.125;
	PlayPauseDemoButton->WinHeight=0.044;
	PlayPauseDemoButton->RenderWeight=0.9;
	PlayPauseDemoButton->bBoundToParent=true;
	PlayPauseDemoButton->bScaleToParent=true;
	//PlayPauseDemoButton->OnClick=AAGameMenu_DemoControls.ButtonClick;
	//PlayPauseDemoButton->OnKeyEvent=PlayPauseDemoButton.InternalOnKeyEvent;
	UGUIButton* FastForwardDemoButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	FastForwardDemoButton->Caption="Fast Forward";
	FastForwardDemoButton->FontScale = EFontScale::FNS_Small;
	FastForwardDemoButton->Hint="Fast forward the demo playback";
	FastForwardDemoButton->WinTop=0.04;
	FastForwardDemoButton->WinLeft=0.5875;
	FastForwardDemoButton->WinWidth=0.125;
	FastForwardDemoButton->WinHeight=0.044;
	FastForwardDemoButton->RenderWeight=0.9;
	FastForwardDemoButton->bBoundToParent=true;
	FastForwardDemoButton->bScaleToParent=true;
	FastForwardDemoButton->bRepeatClick=true;
	//FastForwardDemoButton->OnClick=AAGameMenu_DemoControls.ButtonClick;
	//FastForwardDemoButton->OnKeyEvent=FastForwardDemoButton.InternalOnKeyEvent;
	UGUIButton* RewindDemoButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	RewindDemoButton->Caption="Restart Demo";
	RewindDemoButton->FontScale = EFontScale::FNS_Small;
	RewindDemoButton->Hint="Restart the demo";
	RewindDemoButton->WinTop=0.04;
	RewindDemoButton->WinLeft=0.2875;
	RewindDemoButton->WinWidth=0.125;
	RewindDemoButton->WinHeight=0.044;
	RewindDemoButton->RenderWeight=0.9;
	RewindDemoButton->bBoundToParent=true;
	RewindDemoButton->bScaleToParent=true;
	//RewindDemoButton->OnClick=AAGameMenu_DemoControls.ButtonClick;
	//RewindDemoButton->OnKeyEvent=RewindDemoButton.InternalOnKeyEvent;
	
	btnPlayPause = PlayPauseDemoButton;
	btnFastForward = FastForwardDemoButton;
	btnRewind = RewindDemoButton;
	bRenderWorld = true;
	bPersistent = true;
	bAllowedAsLast = true;
	WinHeight = 1;

}

void UAAGameMenu_DemoControls::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	Super::InitComponent(MyController, MyOwner);
	OriginalGameSpeed = PlayerOwner().Level.TimeDilation;
	*/
}

bool UAAGameMenu_DemoControls::ButtonClick(UGUIComponent* Sender)
{
	/*
	switch (Sender)
	{
	case btnPlayPause:
		if (PlayerOwner().Level.TimeDilation == OriginalGameSpeed)
		{
			PlayerOwner().ConsoleCommand("pause");
			bDemoPaused = (!bDemoPaused);
			if (bDemoPaused)
			{
				GUIButton(Sender).Caption = "Play";
				break;
			}
			GUIButton(Sender).Caption = "Pause";
		}
	}
	else
	{
	PlayerOwner().Level.TimeDilation = OriginalGameSpeed;
	}
	return true;
	case btnFastForward:
		PlayerOwner().ConsoleCommand("DEMOFORWARD");
		return true;
	case btnRewind:
		PlayerOwner().ConsoleCommand("DEMORESTART");
		return true;
	default:
		return false;
	}
	*/
	return false;    //FAKE   /ELiZ
}
