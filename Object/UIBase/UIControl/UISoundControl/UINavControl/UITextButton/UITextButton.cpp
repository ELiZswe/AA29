// All the original content belonged to the US Army


#include "AA29/Object/UIBase/UIControl/UISoundControl/UINavControl/UITextButton/UITextButton.h"

UUITextButton::UUITextButton()
{
	_sLabel = "thisisatest";
	_sOverSound = "S_AA2_UI.Generic.click2";
	_sClickSound = "S_AA2_Foley.Nightvision.NOD_off";
}


void UUITextButton::MouseMove(int32 mX, int32 mY)
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
				cFrame.PlayMenuSoundSpecific(_sMouseOver);
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

bool UUITextButton::ProcessKeyEvent(int32 Key, int32 Action, float Delta)
{
	/*
	if (!_bEnabled)
	{
		Return False;
	}
	if (Key == 13 && Action == 3)
	{
		if (cFrame._cMouseOver == Self)
		{
			cFrame.Notify(_iUIEvent);
			Return True;
		}
	}
	if (Key == 32 && Action == 3)
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
					_iState = 1;
					cFrame.Notify(_iUIEvent);
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
	*/
	return false;
}

void UUITextButton::Draw(UCanvas* Canvas)
{
	/*
	local Font temp_font;
	local int old_style;
	local Object.Color OldColor;
	if (_bLabelChanged)
	{
		ScaleControl(Canvas);
	}
	if (!_bEnabled)
	{
		Return;
	}
	old_style = Canvas.Style;
	Canvas.Style = 1;
	if (cFrame._cMouseOver == Self)
	{
		_iState = 1;
	}
	OldColor.R = Canvas.DrawColor.R;
	OldColor.G = Canvas.DrawColor.G;
	OldColor.B = Canvas.DrawColor.B;
	if (_iParams == 0)
	{
		Canvas.SetDrawColor(196, 190, 141);
	}
	else
	{
		if (_iState == 1)
		{
			Canvas.SetDrawColor(255, 255, 255);
		}
		else
		{
			Canvas.SetDrawColor(196, 190, 141);
		}
	}
	temp_font = Canvas.Font;
	Canvas.Font = cFrame.GetProperSizeFont(Canvas);
	Canvas.SetPos(_iLabelX, _iLabelY);
	Canvas.DrawText(_sLabel);
	Canvas.Font = temp_font;
	Canvas.SetDrawColor(OldColor.R, OldColor.G, OldColor.B);
	Canvas.Style = old_style;
	*/
}

void UUITextButton::ScaleControl(UCanvas* Canvas)
{
	/*
	local Font temp_font;
	local float Xsize;
	local float Ysize;
	ScaleControl(Canvas);
	temp_font = Canvas.Font;
	Canvas.Font = cFrame.GetProperSizeFont(Canvas);
	Canvas.TextSize(_sLabel, Xsize, Ysize);
	_Pos.W = Xsize;
	_Pos.H = Ysize;
	ScaleControl(Canvas);
	_iLabelX = _ScaledPos.X;
	_iLabelY = _ScaledPos.Y;
	Canvas.Font = temp_font;
	_bLabelChanged = False;
	*/
}

void UUITextButton::SetLabel(FString Label)
{
	_sLabel = Label;
	if (_sLabel == "")
	{
		_bEnabled = false;
	}
	else
	{
		_bEnabled = true;
	}
	_bLabelChanged = true;
}