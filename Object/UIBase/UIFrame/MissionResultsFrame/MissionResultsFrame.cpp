// All the original content belonged to the US Army

#include "AA29/Object/UIBase/UIFrame/MissionResultsFrame/MissionResultsFrame.h"
#include "AA29/Object/UIBase/UIControl/UIHUDBaseDisplay/MissionResultDisplay/MissionResultDisplay.h"
#include "AA29/Object/UIBase/UIScreen/UIScreen.h"
#include "AA29/Object/UIBase/UIControl/UIControl.h"
#include "AA29/Object/Actor/ScoreKeeper/ScoreKeeper.h"
#include "AA29/Object/Actor/HUD/AGP_HUD/AGP_HUD.h"
#include "AA29/Object/Actor/HUD/AA2_HUD.h"
#include "Engine/Canvas.h"

UMissionResultsFrame::UMissionResultsFrame()
{
	_Pos = FPosition({ 0, 0, 1280, 1024 });
}

void UMissionResultsFrame::Notify(int32 pUIEvent)
{
	if (cHUD != nullptr)
	{
		if (cHUD->IsA(AAGP_HUD::StaticClass()))
		{
			if (pUIEvent == 1)
			{
				_bRestartScene = true;
				_bPass = GetPlayerStatus();
				ResetActiveScreen();
				Cast<AAGP_HUD>(cHUD)->CloseMissionResults();
			}
			if (pUIEvent == 2)
			{
				_bRestartScene = false;
				ResetActiveScreen();
				Cast<AAGP_HUD>(cHUD)->CloseMissionResults();
			}
		}
	}
}

void UMissionResultsFrame::Draw(UCanvas* Canvas)
{
	if (GetActiveScreen() == nullptr)
	{
		SetActiveScreen(0);
	}
	Super::Draw(Canvas);
}

void UMissionResultsFrame::Create(AAA2_HUD* pHUD)
{
	FPosition pos;
	FPosition dim;
	UUIScreen* screen = nullptr;
	Super::Create(pHUD);
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
	screen->AddUIBorder(1, 0, pos, dim, LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/AGP/Menu/YellowFrame_Mat.YellowFrame_Mat'"), NULL, LOAD_None, NULL), LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/AGP/Menu/GreyFrame_Mat.GreyFrame_Mat'"), NULL, LOAD_None, NULL), 1);
	dim.X = 0;
	dim.Y = 0;
	dim.W = 16;
	dim.H = 16;
	pos.X = 212;
	pos.Y = 410;
	pos.W = 160;
	pos.H = 38;
	screen->AddUIBorderButton(2, 1, pos, dim, LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/AGP/Menu/YellowFrame_Mat.YellowFrame_Mat'"), NULL, LOAD_None, NULL), LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/AGP/Menu/YellowFrame50_Mat.YellowFrame50_Mat'"), NULL, LOAD_None, NULL), LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/AGP/UI/Listback_Mat.Listback_Mat'"), NULL, LOAD_None, NULL), "Retry", 0, "Retry");
	pos.X += 212;
	screen->AddUIBorderButton(3, 2, pos, dim, LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/AGP/Menu/YellowFrame_Mat.YellowFrame_Mat'"), NULL, LOAD_None, NULL), LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/AGP/Menu/YellowFrame50_Mat.YellowFrame50_Mat'"), NULL, LOAD_None, NULL), LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/AGP/UI/Listback_Mat.Listback_Mat'"), NULL, LOAD_None, NULL), "Continue", 0, "Continue");
	AddMouse("AGP_UI.UIMouse", 0, 0, 32, 32, "T_AA2_UI.menu.hud_menu_pointer");
}

void UMissionResultsFrame::SetMissionResultDisplay(FString mrd)
{
	UUIScreen* screen = nullptr;
	FPosition pos;
	screen = GetScreen(0);
	pos.X = 0;
	pos.Y = 0;
	pos.W = 0;
	pos.H = 0;
	screen->AddHUDBaseDisplay(mrd, 4, pos, 0);
}

UMissionResultDisplay* UMissionResultsFrame::GetMissionResultDisplay()
{
	UUIScreen* screen = nullptr;
	UUIControl* Control = nullptr;
	UMissionResultDisplay* mrd = nullptr;
	screen = GetScreen(0);
	Control = screen->GetControl(4);
	if (Control != nullptr && Control->IsA(UMissionResultDisplay::StaticClass()))
	{
		mrd = Cast<UMissionResultDisplay>(Control);
	}
	return mrd;
}

bool UMissionResultsFrame::GetPlayerStatus()
{
	UMissionResultDisplay* mrd = nullptr;
	mrd = GetMissionResultDisplay();
	if (mrd != nullptr)
	{
		return mrd->PlayerPass();
	}
	else
	{
		return false;
	}
}

USoundBase* UMissionResultsFrame::GetStatusSound()
{
	USoundBase* Sound = nullptr;
	UMissionResultDisplay* mrd = nullptr;
	mrd = GetMissionResultDisplay();
	if (mrd != nullptr)
	{
		return mrd->GetStatusSound();
	}
	return Sound;
}

void UMissionResultsFrame::SetScoreKeeper(AScoreKeeper* sk)
{
	UUIScreen* screen = nullptr;
	UUIControl* Control = nullptr;
	screen = GetScreen(0);
	Control = screen->GetControl(4);
	if (Control != nullptr)
	{
		Cast<UMissionResultDisplay>(Control)->SetScoreKeeper(sk);
	}
}

bool UMissionResultsFrame::ShouldRestartScene()
{
	return _bRestartScene;
}

bool UMissionResultsFrame::DidPlayerPass()
{
	return _bPass;
}
