// All the original content belonged to the US Army

#include "AA29/Object/UIBase/UIControl/UIHUDBaseDisplay/HUDMenuCrosshair/HUDMenuCrosshair.h"
#include "AA29/Object/Actor/HUD/AGP_HUD/AGP_HUD.h"
#include "AA29/Object/UIBase/UIFrame/UIFrame.h"
#include "AA29/Object/UIBase/UIControl/UIMouse/UIMouse.h"
#include "Engine/Canvas.h"

UHUDMenuCrosshair::UHUDMenuCrosshair()
{
	_tCrosshair.SetNum(7);
	iCrosshairIndex = 1;
	_tCrosshair = {
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_crosshair_01_Mat.hud_crosshair_01_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_crosshair_02_Mat.hud_crosshair_02_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_crosshair_03_Mat.hud_crosshair_03_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_crosshair_04_Mat.hud_crosshair_04_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_crosshair_05_Mat.hud_crosshair_05_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_crosshair_06_Mat.hud_crosshair_06_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_crosshair_07_Mat.hud_crosshair_07_Mat'"), NULL, LOAD_None, NULL)
	};
}

void UHUDMenuCrosshair::Destroyed()
{
	int i=0;
	Super::Destroyed();
	for (i = 0; i < 6; i++)
	{
		_tCrosshair[i] = nullptr;
	}
}
void UHUDMenuCrosshair::MouseMove(int32 mX, int32 mY)
{
	if (!_bEnabled)
	{
		return;
	}
	if (mX >= _ScaledPos.X && mX <= _ScaledPos.X + _ScaledPos.W - 1 && mY >= _ScaledPos.Y && mY <= _ScaledPos.Y + _ScaledPos.H - 1)
	{
		if (_bButtonDown)
		{
			_iState = 2;
		}
		else
		{
			_iState = 1;
		}
		if (!cFrame->SetMouseOver(this))
		{
			_iState = 0;
		}
	}
	else
	{
		_iState = 0;
		_bButtonDown = false;
		_bButtonDown2 = false;
		if (_bEdit)
		{
			_bEdit = false;
			cFrame->SetFocus(nullptr);
		}
	}
}

bool UHUDMenuCrosshair::ProcessKeyEvent(int32 Key, int32 Action, float Delta)
{
	if (!_bEnabled)
	{
		return false;
	}
	if (Key == 37 && Action == 1)
	{
		if (cFrame->_cMouseOver == this)
		{
			PrevMode();
			return true;
		}
	}
	if (Key == 39 && Action == 1)
	{
		if (cFrame->_cMouseOver == this)
		{
			NextMode();
			return true;
		}
	}
	if (Key == 1)
	{
		if (cFrame->cMouse->iMouseX >= _ScaledPos.X && cFrame->cMouse->iMouseX <= _ScaledPos.X + _ScaledPos.W - 1 && cFrame->cMouse->iMouseY >= _ScaledPos.Y && cFrame->cMouse->iMouseY <= _ScaledPos.Y + _ScaledPos.H - 1)
		{
			if (Action == 1)
			{
				_bButtonDown = true;
				_iState = 2;
			}
			if (Action == 3)
			{
				if (_bButtonDown == true)
				{
					_bButtonDown = false;
					_iState = 1;
					cFrame->SetFocus(this);
					PrevMode();
				}
			}
			return true;
		}
		else
		{
			if (Action == 1)
			{
				cFrame->SetFocus(nullptr);
				return false;
			}
		}
		if (_bButtonDown == true && Action == 3 && cFrame->cFocus == this)
		{
			_bButtonDown = false;
			_bButtonDown2 = false;
			cFrame->SetFocus(nullptr);
			return true;
		}
	}
	if (Key == 2)
	{
		if (cFrame->cMouse->iMouseX >= _ScaledPos.X && cFrame->cMouse->iMouseX <= _ScaledPos.X + _ScaledPos.W - 1 && cFrame->cMouse->iMouseY >= _ScaledPos.Y && cFrame->cMouse->iMouseY <= _ScaledPos.Y + _ScaledPos.H - 1)
		{
			if (Action == 1)
			{
				_bButtonDown2 = true;
				_iState = 2;
			}
			if (Action == 3)
			{
				if (_bButtonDown2 == true)
				{
					_bButtonDown2 = false;
					_iState = 1;
					cFrame->SetFocus(this);
					NextMode();
				}
			}
			return true;
		}
		else
		{
			if (Action == 1)
			{
				cFrame->SetFocus(nullptr);
				return false;
			}
		}
		if (_bButtonDown == true && Action == 3 && cFrame->cFocus == this)
		{
			_bButtonDown = false;
			_bButtonDown2 = false;
			cFrame->SetFocus(nullptr);
			return true;
		}
	}
	return false;
}

void UHUDMenuCrosshair::PrevMode()
{
	NextCrosshair();
}

void UHUDMenuCrosshair::NextMode()
{
	NextCrosshair();
}

void UHUDMenuCrosshair::Draw(UCanvas* Canvas)
{
	int32 oldstyle = 0;
	FColor OldColor = FColor(0,0,0,0);
	FColor C = FColor(0, 0, 0, 0);
	/*
	if (Canvas == nullptr || cFrame == nullptr || cFrame->cActor == nullptr || cFrame->cActor.Level == nullptr || cFrame->cActor.bDeleteMe || cFrame->cActor.Level.bDeleteMe)
	{
		return;
	}
	OldColor = Canvas.DrawColor;
	oldstyle = Canvas.Style;
	C.G = 255;
	C.R = 255;
	Canvas.Style = 6;
	Canvas.DrawColor = C;
	Canvas.DrawColor.A = Cast<AAGP_HUD>(cFrame->cHUD).HUDColor.A;
	if (_tCrosshair[iCrosshairIndex] != nullptr)
	{
		Canvas.SetPos(_ScaledPos.X, _ScaledPos.Y);
		Canvas.DrawTile(_tCrosshair[iCrosshairIndex], _ScaledPos.W, _ScaledPos.H, 0, 0, _Pos.W, _Pos.H);
	}
	*/
}
void UHUDMenuCrosshair::Refresh()
{
	/*
	FString Status;
	if (cFrame != nullptr && cFrame->cHUD != nullptr && cFrame->cHUD.PlayerOwner != nullptr)
	{
		Status = cFrame->cHUD.PlayerOwner.ConsoleCommand("get humancontroller hudcrosshair");
		SetCrosshair(Status);
	}
	*/
}
void UHUDMenuCrosshair::SetCrosshair(int32 C)
{
	/*
	if (C < 0 || C > 6)
	{
		return;
	}
	iCrosshairIndex = C;
	if (cFrame != nullptr && cFrame->cHUD != nullptr && cFrame->cHUD.PlayerOwner != nullptr)
	{
		cFrame->cHUD.PlayerOwner.ConsoleCommand("get humancontroller hudcrosshair " + iCrosshairIndex);
	}
	*/
}
void UHUDMenuCrosshair::NextCrosshair()
{
	/*
	Cast<AAGP_HUD>(cFrame->cHUD).NextCrosshair();
	*/
	Refresh();
}
