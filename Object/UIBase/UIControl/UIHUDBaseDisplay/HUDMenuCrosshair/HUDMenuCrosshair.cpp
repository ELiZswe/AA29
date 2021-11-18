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
		Return;
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
		if (!cFrame.SetMouseOver(Self))
		{
			_iState = 0;
		}
	}
	else
	{
		_iState = 0;
		_bButtonDown = False;
		_bButtonDown2 = False;
		if (_bEdit)
		{
			_bEdit = False;
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
		Return False;
	}
	if (Key == 37 && Action == 1)
	{
		if (cFrame._cMouseOver == Self)
		{
			PrevMode();
			Return True;
		}
	}
	if (Key == 39 && Action == 1)
	{
		if (cFrame._cMouseOver == Self)
		{
			NextMode();
			Return True;
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
				if (_bButtonDown == True)
				{
					_bButtonDown = False;
					_iState = 1;
					cFrame.SetFocus(Self);
					PrevMode();
				}
			}
			Return True;
		}
		else
		{
			if (Action == 1)
			{
				cFrame.SetFocus(None);
				Return False;
			}
		}
		if (_bButtonDown == True && Action == 3 && cFrame.cFocus == Self)
		{
			_bButtonDown = False;
			_bButtonDown2 = False;
			cFrame.SetFocus(None);
			Return True;
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
				if (_bButtonDown2 == True)
				{
					_bButtonDown2 = False;
					_iState = 1;
					cFrame.SetFocus(Self);
					NextMode();
				}
			}
			Return True;
		}
		else
		{
			if (Action == 1)
			{
				cFrame.SetFocus(None);
				Return False;
			}
		}
		if (_bButtonDown == True && Action == 3 && cFrame.cFocus == Self)
		{
			_bButtonDown = False;
			_bButtonDown2 = False;
			cFrame.SetFocus(None);
			Return True;
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
	local int oldstyle;
	local Object.Color OldColor;
	local Object.Color C;
	if (Canvas == None || cFrame == None || cFrame.cActor == None || cFrame.cActor.Level == None || cFrame.cActor.bDeleteMe || cFrame.cActor.Level.bDeleteMe)
	{
		Return;
	}
	OldColor = Canvas.DrawColor;
	oldstyle = Canvas.Style;
	C.G = 255;
	C.R = 255;
	Canvas.Style = 6;
	Canvas.DrawColor = C;
	Canvas.DrawColor.A = AGP_HUD(cFrame.cHUD).HUDColor.A;
	if (_tCrosshair[iCrosshairIndex] != None)
	{
		Canvas.SetPos(_ScaledPos.X, _ScaledPos.Y);
		Canvas.DrawTile(_tCrosshair[iCrosshairIndex], _ScaledPos.W, _ScaledPos.H, 0, 0, _Pos.W, _Pos.H);
	}
	*/
}
void UHUDMenuCrosshair::Refresh()
{
	/*
	local string Status;
	if (cFrame != None && cFrame.cHUD != None && cFrame.cHUD.PlayerOwner != None)
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
		Return;
	}
	iCrosshairIndex = C;
	if (cFrame != None && cFrame.cHUD != None && cFrame.cHUD.PlayerOwner != None)
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