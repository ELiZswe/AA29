// All the original content belonged to the US Army


#include "AA29/Object/UIBase/UIFrame/MissionResultsFrame/MissionResultsFrame.h"

UMissionResultsFrame::UMissionResultsFrame()
{
	//_Pos = (X = 0, Y = 0, W = 1280, H = 1024)M
}


void UMissionResultsFrame::Notify(int32 pUIEvent)
{
	/*
	if (cHUD != None)
	{
		if (cHUD.IsA('AGP_HUD'))
		{
			if (pUIEvent == 1)
			{
				_bRestartScene = true;
				_bPass = GetPlayerStatus();
				ResetActiveScreen();
				AGP_HUD(cHUD).CloseMissionResults();
			}
			if (pUIEvent == 2)
			{
				_bRestartScene = False;
				ResetActiveScreen();
				AGP_HUD(cHUD).CloseMissionResults();
			}
		}
	}
	*/
}
void UMissionResultsFrame::Draw(UCanvas* Canvas)
{
	/*
	if (GetActiveScreen() == None)
	{
		SetActiveScreen(0);
	}
	*/
	Super::Draw(Canvas);
}
void UMissionResultsFrame::Create(AHUD* pHUD)
{
	/*
	local UIBase.Position pos;
	local UIBase.Position dim;
	local AGP_UI.UIScreen screen;
	Create(pHUD);
	AddScreen(0, "Main");
	screen = GetScreen(0);
	pos.X = 80;
	pos.Y = 75;
	pos.W = 640;
	pos.H = 450;
	dim.X = 0;
	dim.Y = 0;
	dim.W = 16;
	dim.H = 16;
	screen.AddUIBorder(1, 0, pos, dim, Texture'YellowFrame', Texture'GreyFrame', 1);
	dim.X = 0;
	dim.Y = 0;
	dim.W = 16;
	dim.H = 16;
	pos.X = 212;
	pos.Y = 410;
	pos.W = 160;
	pos.H = 38;
	screen.AddUIBorderButton(2, 1, pos, dim, Texture'YellowFrame', Texture'YellowFrame50', Texture'Listback', "Retry", 0, "Retry");
	pos.X += 212;
	screen.AddUIBorderButton(3, 2, pos, dim, Texture'YellowFrame', Texture'YellowFrame50', Texture'Listback', "Continue", 0, "Continue");
	AddMouse("AGP_UI.UIMouse", 0, 0, 32, 32, "T_AA2_UI.menu.hud_menu_pointer");
	*/
}
void UMissionResultsFrame::SetMissionResultDisplay(FString mrd)
{
	/*
	local AGP_UI.UIScreen screen;
	local UIBase.Position pos;
	screen = GetScreen(0);
	pos.X = 0;
	pos.Y = 0;
	pos.W = 0;
	pos.H = 0;
	screen.AddHUDBaseDisplay(mrd, 4, pos, 0);
	*/
}
void UMissionResultsFrame::GetMissionResultDisplay()
{
	/*
	local AGP_UI.UIScreen screen;
	local AGP_UI.UIControl Control;
	local MissionResultDisplay mrd;
	screen = GetScreen(0);
	Control = screen.GetControl(4);
	if (Control != None && Control.IsA('MissionResultDisplay'))
	{
		mrd = MissionResultDisplay(Control);
	}
	Return mrd;
	*/
}
bool UMissionResultsFrame::GetPlayerStatus()
{
	/*
	local MissionResultDisplay mrd;
	mrd = GetMissionResultDisplay();
	if (mrd != None)
	{
		return mrd.PlayerPass();
	}
	else
	{
		return False;
	}
	*/

	return true;     //FAKE   /ELiZ
}
USoundBase* UMissionResultsFrame::GetStatusSound()
{
	USoundBase* Sound = nullptr;
	/*
	local MissionResultDisplay mrd;
	
	mrd = GetMissionResultDisplay();
	if (mrd != None)
	{
		Return mrd.GetStatusSound();
	}
	*/
	return Sound;
}
void UMissionResultsFrame::SetScoreKeeper(AScoreKeeper* sk)
{
	/*
	local AGP_UI.UIScreen screen;
	local AGP_UI.UIControl Control;
	screen = GetScreen(0);
	Control = screen.GetControl(4);
	if (Control != None)
	{
		MissionResultDisplay(Control).SetScoreKeeper(sk);
	}
	*/
}
bool UMissionResultsFrame::ShouldRestartScene()
{
	return _bRestartScene;
}
bool UMissionResultsFrame::DidPlayerPass()
{
	return _bPass;
}
