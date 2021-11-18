// All the original content belonged to the US Army


#include "AA29/Object/UIBase/UIControl/UISoundControl/UINavControl/UIConsole/UIConsole.h"

UUIConsole::UUIConsole()
{

}


void UUIConsole::MouseMove(int32 mX, int32 mY)
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
			if (!_bFirstOver)
			{
				_bFirstOver = true;
			}
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
		_bFirstOver = False;
	}
	*/
}
bool UUIConsole::ProcessKeyEvent(int32 Key, int32 Action, float Delta)
{
	/*
	local int pos;
	if (!_bEnabled)
	{
		Return False;
	}
	if (Key == 13)
	{
		if (cFrame._cMouseOver == Self)
		{
			cFrame.Notify(_iUIEvent);
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
				cFrame.PlayMenuSoundSpecific(_sMouseClick);
			}
			if (Action == 3)
			{
				if (_bButtonDown == True)
				{
					_bButtonDown = False;
				}
			}
			Return True;
		}
		if (_bButtonDown == True && Action == 3 && cFrame.cFocus == Self)
		{
			_bButtonDown = False;
			cFrame.SetFocus(None);
			Return True;
		}
	}
	if (Key == 236 && Action == 3)
	{
		if (cFrame.cMouse.iMouseX >= _ScaledPos.X && cFrame.cMouse.iMouseX <= _ScaledPos.X + _ScaledPos.W - 1 && cFrame.cMouse.iMouseY >= _ScaledPos.Y && cFrame.cMouse.iMouseY <= _ScaledPos.Y + _ScaledPos.H - 1)
		{
			pos = cFrame.GetGameSpyPos();
			cFrame.UpdateGameSpyPos(pos - 1);
			Return True;
		}
	}
	if (Key == 237 && Action == 3)
	{
		if (cFrame.cMouse.iMouseX >= _ScaledPos.X && cFrame.cMouse.iMouseX <= _ScaledPos.X + _ScaledPos.W - 1 && cFrame.cMouse.iMouseY >= _ScaledPos.Y && cFrame.cMouse.iMouseY <= _ScaledPos.Y + _ScaledPos.H - 1)
		{
			pos = cFrame.GetGameSpyPos();
			cFrame.UpdateGameSpyPos(pos + 1);
			Return True;
		}
	}
	*/
	return false;
}
void UUIConsole::Draw(UCanvas* Canvas)
{
	/*
	local Font temp_font;
	local int oldclipx;
	local int oldClipY;
	local int old_style;
	local Object.Color OldColor;
	local Console Console;
	if (!_bEnabled)
	{
		Return;
	}
	Console = cFrame.cHUD.PlayerConsole;
	if (Console == None)
	{
		Return;
	}
	old_style = Canvas.Style;
	Canvas.Style = 1;
	OldColor.R = Canvas.DrawColor.R;
	OldColor.G = Canvas.DrawColor.G;
	OldColor.B = Canvas.DrawColor.B;
	temp_font = Canvas.Font;
	Canvas.Font = cFrame.Fonts[8];
	if (Console.bTyping)
	{
		oldclipx = Canvas.ClipX;
		oldClipY = Canvas.ClipY;
		Canvas.SetClip(_ScaledPos.X + _ScaledPos.W, _ScaledPos.Y + _ScaledPos.H);
		Canvas.SetPos(_ScaledPos.X, _ScaledPos.Y);
		Canvas.DrawTextClipped("(>" @ Console.TypedStr $ "_", False);
		Canvas.SetClip(oldclipx, oldClipY);
	}
	Canvas.Font = temp_font;
	Canvas.SetDrawColor(OldColor.R, OldColor.G, OldColor.B);
	Canvas.Style = old_style;
	*/
}
