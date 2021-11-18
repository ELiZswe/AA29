// All the original content belonged to the US Army


#include "AA29/Object/UIBase/UIFrame/HUDFrame/HUDFrame.h"

UHUDFrame::UHUDFrame()
{
	//_compassBracketTexture = Texture'T_AA2_UI.HUD.hud_nav_bracket';
	fScaleY = 1;
	//_Pos = (X = 0, Y = 0, W = 800, H = 600);
}


void UHUDFrame::Destroyed()
{
	bFrameInitialized = false;
	Super::Destroyed();
	_cHUDTaskDisplay = nullptr;
	_compassTexture = nullptr;
	_compassBracketTexture = nullptr;
}
void UHUDFrame::SetHUDActor()
{
	/*
	if (PlayerOwner == nullptr)
	{
		return;
	}
	cActor = PlayerOwner.Pawn;
	*/
}
void UHUDFrame::FreeHUDActor()
{
	cActor = nullptr;
}
void UHUDFrame::GetControl(int32 Id)
{
	//return GetScreen(0).GetControl(Id);
}
void UHUDFrame::Draw(UCanvas* Canvas)
{
	/*
	if (!bFrameInitialized)
	{
		Return;
	}
	if (Canvas == None || cHUD == None || AGP_HUD(cHUD) == None)
	{
		Return;
	}
	if (PlayerOwner == None)
	{
		Return;
	}
	SetHUDActor();
	if (Canvas == None || cActor == None || cActor.Level == None || cActor.bDeleteMe || cActor.Level.bDeleteMe)
	{
		Return;
	}
	_bContainersSet = False;
	if (GetActiveScreen() == None)
	{
		SetActiveScreen(0);
	}
	Canvas.DrawColor = AGP_HUD(cHUD).HUDColor;
	Canvas.Style = 6;
	Draw(Canvas);
	FreeHUDActor();
	*/
}
void UHUDFrame::CreateHUDFrame(AHUD* pHUD, AAA2_Playerstate* pcPlayerController)
{
	/*
	local UIBase.Position pos;
	local AGP_UI.UIScreen screen;
	PlayerOwner = pcPlayerController;
	bFrameInitialized = False;
	Create(pHUD);
	AddScreen(0, "HUD");
	screen = GetScreen(0);
	if (screen == None)
	{
		Return;
	}
	screen.AddHUDCompass(5, 0, _compassTexture, _compassBracketTexture, 0);
	pos.X = 20;
	pos.Y = 403;
	pos.W = 180;
	pos.H = 180;
	screen.AddHUDBaseDisplay("AGP_Gameplay.HUDRadar", 24, pos, 0);
	pos.X = 0;
	pos.Y = 0;
	pos.W = 800;
	pos.H = 600;
	screen.AddHUDBaseDisplay("AGP_Vehicles.HUDDriver", 25, pos, 0);
	pos.X = 37;
	pos.Y = 558;
	pos.W = 128;
	pos.H = 32;
	screen.AddHUDBaseDisplay("AGP.HUDTaskDisplay", 7, pos, 1);
	_cHUDTaskDisplay = HUDTaskDisplay(screen.GetControl(7));
	pos.X = 384;
	pos.Y = 284;
	pos.W = 32;
	pos.H = 32;
	screen.AddHUDBaseDisplay("AGP.HUDCrosshair", 10, pos, 0);
	pos.X = 400;
	pos.Y = 80;
	pos.W = 128;
	pos.H = 16;
	screen.AddHUDBaseDisplay("AGP_UI.UIHUDPercentageBar", 20, pos, 0);
	pos.X = 400;
	pos.Y = 528;
	pos.W = 128;
	pos.H = 16;
	screen.AddHUDBaseDisplay("AGP_UI.UIHUDPercentageBar", 21, pos, 0);
	pos.X = 400;
	pos.Y = 490;
	pos.W = 128;
	pos.H = 16;
	screen.AddHUDBaseDisplay("AGP_UI.UIHUDPercentageBar", 23, pos, 0);
	pos.X = 400;
	pos.Y = 300;
	pos.W = 128;
	pos.H = 16;
	screen.AddHUDBaseDisplay("AGP_UI.UIHUDPercentageBar", 22, pos, 0);
	pos.X = 400;
	pos.Y = 448;
	screen.AddHUDBaseDisplay("AGP.HUDPlayerID", 16, pos, 0);
	pos.X = 400;
	pos.Y = 432;
	screen.AddHUDBaseDisplay("AGP.HUDWeaponTarget", 17, pos, 0);
	pos.X = 717;
	pos.Y = 528;
	pos.W = 61;
	pos.H = 61;
	screen.AddHUDBaseDisplay("AGP.HUDBodyInfo", 8, pos, 0);
	pos.X = 6;
	pos.Y = 20;
	pos.W = 32;
	pos.H = 32;
	screen.AddHUDBaseDisplay("AGP.HUDCommoInfo", 13, pos, 0);
	pos.X = 784;
	pos.Y = 526;
	pos.W = 10;
	pos.H = 64;
	screen.AddHUDBaseDisplay("AGP.HUDCombatEff", 15, pos, 0);
	bFrameInitialized = true;
	*/
}
void UHUDFrame::SetTask(int32 task)
{
	if (_cHUDTaskDisplay != nullptr)
	{
		//_cHUDTaskDisplay.SetCurrentTask(task);
	}
}
void UHUDFrame::ShowRackItems(bool Status)
{
	_bShowRackItems = Status;
}
void UHUDFrame::ClearRackItems()
{
	/*
	local AGP_UI.UIScreen screen;
	local InvContainer container;
	Log("HUDFrame::ClearRackItems()");
	screen = GetScreen(0);
	container = None;
	UIHUDRackItem(screen.GetControl(0)).SetContainer(container);
	UIHUDRackItem(screen.GetControl(1)).SetContainer(container);
	UIHUDRackItem(screen.GetControl(2)).SetContainer(container);
	UIHUDRackItem(screen.GetControl(3)).SetContainer(container);
	*/
}