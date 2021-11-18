// All the original content belonged to the US Army


#include "AA29/Object/UIBase/UIControl/UISoundControl/UINavControl/UISliderH/UISliderH.h"

UUISliderH::UUISliderH()
{
	_iThumbSize = 8;
	_fMax = 100;
}

void UUISliderH::Destroyed()
{
	Super::Destroyed();
	_Texture = nullptr;
}
void UUISliderH::MouseMove(int32 mX, int32 mY)
{
	/*
	if (!_bEnabled)
	{
		Return;
	}
	if (cFrame.cMouse.iMouseX >= _ScaledPos.X && cFrame.cMouse.iMouseX <= _ScaledPos.X + _ScaledPos.W - 1 && cFrame.cMouse.iMouseY >= _ScaledPos.Y && cFrame.cMouse.iMouseY <= _ScaledPos.Y + _ScaledPos.H - 1)
	{
		if (_bButtonDown == True)
		{
			_iThumbPos = cFrame.cMouse.iMouseY - _ScaledPos.Y - _iMouseDragOffset;
			if (_iThumbPos > _ScaledPos.H - _iThumbSize)
			{
				_iThumbPos = _ScaledPos.H - _iThumbSize;
				_iMouseDragOffset = cFrame.cMouse.iMouseY - _ScaledPos.Y + _iThumbPos;
			}
			if (_iThumbPos <= 0)
			{
				_iThumbPos = 0;
				_iMouseDragOffset = cFrame.cMouse.iMouseY - _ScaledPos.Y;
			}
			UpdateValue();
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
	}
	*/
}

bool UUISliderH::ProcessKeyEvent(int32 Key, int32 Action, float Delta)
{
	/*
	if (Key == 37 && Action == 1)
	{
		if (cFrame._cMouseOver == Self)
		{
			Dec();
			UpdateValue();
			Accept();
			Return True;
		}
	}
	if (Key == 39 && Action == 1)
	{
		if (cFrame._cMouseOver == Self)
		{
			Inc();
			UpdateValue();
			Accept();
			Return True;
		}
	}
	if (Key == 1)
	{
		if (cFrame.cMouse.iMouseX >= _ScaledPos.X && cFrame.cMouse.iMouseX <= _ScaledPos.X + _ScaledPos.W - 1 && cFrame.cMouse.iMouseY >= _ScaledPos.Y && cFrame.cMouse.iMouseY <= _ScaledPos.Y + _ScaledPos.H - 1)
		{
			if (Action == 1)
			{
				if (cFrame.cMouse.iMouseY >= _ScaledPos.Y + _iThumbPos && cFrame.cMouse.iMouseY <= _ScaledPos.Y + _iThumbPos + _iThumbSize)
				{
					_iMouseDragOffset = cFrame.cMouse.iMouseY - _ScaledPos.Y + _iThumbPos;
				}
				else
				{
					_iThumbPos = cFrame.cMouse.iMouseY - _ScaledPos.Y;
					if (_iThumbPos > _ScaledPos.H - _iThumbSize)
					{
						_iThumbPos = _ScaledPos.H - _iThumbSize;
					}
					UpdateValue();
					_iMouseDragOffset = 0;
				}
			}
			if (Action == 1)
			{
				_bButtonDown = true;
				_iState = 2;
				cFrame.SetFocus(Self);
			}
			if (Action == 3)
			{
				_bButtonDown = False;
				_iState = 1;
				_iMouseDragOffset = 0;
			}
			Return True;
		}
		if (_bButtonDown == True && Action == 3 && cFrame.cFocus == Self)
		{
			_bButtonDown = False;
			_iMouseDragOffset = 0;
			cFrame.SetFocus(None);
			Return True;
		}
	}
	*/
	return false;
}

void UUISliderH::Draw(UCanvas* Canvas)
{
	/*
	local int oldstyle;
	local Object.Color OldColor;
	if (_bDebug)
	{
		Canvas.DrawText("_Texture = " $ _Texture);
	}
	if (cFrame._cMouseOver == Self)
	{
		_iState = 1;
	}
	OldColor = Canvas.DrawColor;
	oldstyle = Canvas.Style;
	if (_Texture != None)
	{
		Canvas.Style = 6;
		Canvas.SetPos(_ScaledPos.X, _ScaledPos.Y + _iThumbPos);
		Canvas.DrawTile(_Texture, _TexDimThumb.W, _TexDimThumb.H, _TexDimThumb.X, _TexDimThumb.Y, _TexDimThumb.W, _TexDimThumb.H);
	}
	Canvas.DrawColor = OldColor;
	Canvas.Style = oldstyle;
	*/
}
void UUISliderH::SetTexture(FString Tex)
{
	if (_Texture == nullptr)
	{
		//_Texture = Texture(DynamicLoadObject(Tex, Class'Texture'));
		//Log("UISliderH::SetTexture(" $ Tex $ ") failed!");
	}
}
void UUISliderH::SetTexDimBack(FPosition dim)
{
	_TexDimBack.X = dim.X;
	_TexDimBack.Y = dim.Y;
	_TexDimBack.W = dim.W;
	_TexDimBack.H = dim.H;
}
void UUISliderH::SetTexDimThumb(FPosition dim)
{
	_TexDimThumb.X = dim.X;
	_TexDimThumb.Y = dim.Y;
	_TexDimThumb.W = dim.W;
	_TexDimThumb.H = dim.H;
	/*
	_iSliderSize = _Pos.H - _TexDimThumb.H;
	_iThumbSize = _TexDimThumb.H;
	*/
}
void UUISliderH::SetLabel(FString Label)
{
	_sLabel = Label;
}
void UUISliderH::Inc()
{
	if (_iThumbPos < _iSliderSize)
	{
		_iThumbPos++;
	}
}
void UUISliderH::Dec()
{
	if (_iThumbPos > 0)
	{
		_iThumbPos--;
	}
}
void UUISliderH::Refresh()
{
}
void UUISliderH::Accept()
{
}
void UUISliderH::UpdateValue()
{
	/*
	_fValue = _iThumbPos / _iSliderSize;
	_fValue = _fValue * _fMax - _fMin + _fMin;
	cFrame.SetGameSpyPos(_fValue);
	*/
}
void UUISliderH::SetValue(float Value)
{
	/*
	local float Temp;
	_fValue = Value;
	_fValue = FClamp(_fValue, _fMin, _fMax);
	Temp = _fValue - _fMin / _fMax - _fMin;
	_iThumbPos = Temp * _iSliderSize;
	if (_iParams == 2)
	{
		Accept();
	}
	*/
}
void UUISliderH::SetMinMax(float Min, float Max)
{
	/*
	_fMin = Min;
	_fMax = Max;
	*/
}