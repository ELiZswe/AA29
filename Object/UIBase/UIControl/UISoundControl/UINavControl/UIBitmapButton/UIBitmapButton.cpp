// All the original content belonged to the US Army


#include "AA29/Object/UIBase/UIControl/UISoundControl/UINavControl/UIBitmapButton/UIBitmapButton.h"

UUIBitmapButton::UUIBitmapButton()
{
	_sOverSound = "S_AA2_UI.Generic.click2";
	_sClickSound = "S_AA2_Foley.Nightvision.NOD_off";
}


void UUIBitmapButton::Destroyed()
{
	Super::Destroyed();
	_Texture = nullptr;
}
void UUIBitmapButton::MouseMove(int32 mX, int32 mY)
{
	/*
	if (!_bEnabled)
	{
		Return;
	}
	if (mX >= _ScaledPos.X && mX <= _ScaledPos.X + _ScaledPos.W - 1 && mY >= _ScaledPos.Y && mY <= _ScaledPos.Y + _ScaledPos.H - 1)
	{
		if (!cFrame.SetMouseOver(Self))
		{
			_iState = 0;
		}
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
	}
	else
	{
		_iState = 0;
		_bButtonDown = False;
		_bFirstOver = False;
	}
	*/
}
bool UUIBitmapButton::ProcessKeyEvent(int32 Key, int32 Action, float Delta)
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
void UUIBitmapButton::Draw(UCanvas* Canvas)
{
	/*
	local int oldstyle;
	if (!_bEnabled)
	{
		Return;
	}
	if (_bDebug)
	{
		Canvas.SetPos(0, 0);
		Canvas.DrawText("_Texture = " $ _Texture);
	}
	if (cFrame._cMouseOver == Self && _iState != 2)
	{
		_iState = 1;
	}
	oldstyle = Canvas.Style;
	if (_Texture != None)
	{
		Canvas.Style = 6;
		Canvas.SetPos(_ScaledPos.X, _ScaledPos.Y);
		Canvas.DrawTile(_Texture, _ScaledPos.W, _ScaledPos.H, _iTexDim.X, _iTexDim.Y, _iTexDim.W, _iTexDim.H);
		if (_bDebug)
		{
			Canvas.SetPos(_ScaledPos.X, _ScaledPos.Y);
			Canvas.DrawText("X: " $ _ScaledPos.X $ " Y: " $ _ScaledPos.Y $ " W: " $ _ScaledPos.W $ " H: " $ _ScaledPos.H);
		}
	}
	Canvas.Style = oldstyle;
	*/
}
void UUIBitmapButton::SetTextureDimensions(FPosition dim)
{
	_iTexDim.X = dim.X;
	_iTexDim.Y = dim.Y;
	_iTexDim.W = dim.W;
	_iTexDim.H = dim.H;
}
void UUIBitmapButton::SetTexture(FString Tex)
{
	if (_Texture == nullptr)
	{
		//_Texture = Texture(DynamicLoadObject(Tex, Class'Texture'));
		//Log("UIRolloverBitmapButton::SetTexture(" $ Tex $ ") failed!");
	}
}
