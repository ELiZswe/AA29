// All the original content belonged to the US Army

#include "AA29/Object/UIBase/UIControl/UIHUDBaseDisplay/HUDMenuCrosshair/HUDMenuCrosshair.h"

UHUDMenuCrosshair::UHUDMenuCrosshair()
{
	iCrosshairIndex = 1;
	//_tCrosshair(0) = Texture'T_AA2_UI.HUD.hud_crosshair_01'
	//_tCrosshair(1) = Texture'T_AA2_UI.HUD.hud_crosshair_02'
	//_tCrosshair(2) = Texture'T_AA2_UI.HUD.hud_crosshair_03'
	//_tCrosshair(3) = Texture'T_AA2_UI.HUD.hud_crosshair_04'
	//_tCrosshair(4) = Texture'T_AA2_UI.HUD.hud_crosshair_05'
	//_tCrosshair(5) = Texture'T_AA2_UI.HUD.hud_crosshair_06'
	//_tCrosshair(6) = Texture'T_AA2_UI.HUD.hud_crosshair_07'
}

void UHUDMenuCrosshair::Destroyed()
{
	int i=0;
	Super::Destroyed();
	/*
	for (i = 0; i < 6; i++)
	{
		_tCrosshair[i] = nullptr;
	}
	*/
}
void UHUDMenuCrosshair::MouseMove(int32 mX, int32 mY)
{
	/*
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
		if (!cFrame.SetMouseOver(this))
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
			cFrame.SetFocus(None);
		}
	}
	*/
}
bool UHUDMenuCrosshair::ProcessKeyEvent(int32 Key, int32 Action, float Delta)
{
	/*
	if (!_bEnabled)
	{
		return false;
	}
	if (Key == 37 && Action == 1)
	{
		if (cFrame._cMouseOver == this)
		{
			PrevMode();
			return true;
		}
	}
	if (Key == 39 && Action == 1)
	{
		if (cFrame._cMouseOver == this)
		{
			NextMode();
			return true;
		}
	}
	if (Key == 1)
	{
		if (cFrame.cMouse.iMouseX >= _ScaledPos.X && cFrame.cMouse.iMouseX <= _ScaledPos.X + _ScaledPos.W - 1 && cFrame.cMouse.iMouseY >= _ScaledPos.Y && cFrame.cMouse.iMouseY <= _ScaledPos.Y + _ScaledPos.H - 1)
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
					cFrame.SetFocus(this);
					PrevMode();
				}
			}
			return true;
		}
		else
		{
			if (Action == 1)
			{
				cFrame.SetFocus(None);
				return false;
			}
		}
		if (_bButtonDown == True && Action == 3 && cFrame.cFocus == this)
		{
			_bButtonDown = false;
			_bButtonDown2 = false;
			cFrame.SetFocus(None);
			return true;
		}
	}
	if (Key == 2)
	{
		if (cFrame.cMouse.iMouseX >= _ScaledPos.X && cFrame.cMouse.iMouseX <= _ScaledPos.X + _ScaledPos.W - 1 && cFrame.cMouse.iMouseY >= _ScaledPos.Y && cFrame.cMouse.iMouseY <= _ScaledPos.Y + _ScaledPos.H - 1)
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
					cFrame.SetFocus(this);
					NextMode();
				}
			}
			return true;
		}
		else
		{
			if (Action == 1)
			{
				cFrame.SetFocus(None);
				return false;
			}
		}
		if (_bButtonDown == True && Action == 3 && cFrame.cFocus == this)
		{
			_bButtonDown = false;
			_bButtonDown2 = false;
			cFrame.SetFocus(None);
			return true;
		}
	}
	*/
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
	/*
	int32 oldstyle;
	local Object.Color OldColor;
	local Object.Color C;
	if (Canvas == nullptr || cFrame == nullptr || cFrame.cActor == nullptr || cFrame.cActor.Level == nullptr || cFrame.cActor.bDeleteMe || cFrame.cActor.Level.bDeleteMe)
	{
		return;
	}
	OldColor = Canvas.DrawColor;
	oldstyle = Canvas.Style;
	C.G = 255;
	C.R = 255;
	Canvas.Style = 6;
	Canvas.DrawColor = C;
	Canvas.DrawColor.A = AGP_HUD(cFrame.cHUD).HUDColor.A;
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
	if (cFrame != nullptr && cFrame.cHUD != nullptr && cFrame.cHUD.PlayerOwner != nullptr)
	{
		Status = cFrame.cHUD.PlayerOwner.ConsoleCommand("get humancontroller hudcrosshair");
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
	if (cFrame != nullptr && cFrame.cHUD != nullptr && cFrame.cHUD.PlayerOwner != nullptr)
	{
		cFrame.cHUD.PlayerOwner.ConsoleCommand("get humancontroller hudcrosshair " $ iCrosshairIndex);
	}
	*/
}
void UHUDMenuCrosshair::NextCrosshair()
{
	/*
	AGP_HUD(cFrame.cHUD).NextCrosshair();
	*/
	Refresh();
}
