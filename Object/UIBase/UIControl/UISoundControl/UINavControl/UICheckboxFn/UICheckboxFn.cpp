// All the original content belonged to the US Army


#include "AA29/Object/UIBase/UIControl/UISoundControl/UINavControl/UICheckboxFn/UICheckboxFn.h"

UUICheckboxFn::UUICheckboxFn()
{

}


void UUICheckboxFn::Destroyed()
{
	Super::Destroyed();
	_Texture = nullptr;
}
void UUICheckboxFn::MouseMove(int32 mX, int32 mY)
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
	}
	*/
}
bool UUICheckboxFn::ProcessKeyEvent(int32 Key, int32 Action, float Delta)
{
	/*
	if (!_bEnabled)
	{
		Return False;
	}
	if (cFrame._cMouseOver == Self && Action == 3)
	{
		if (Key == 13 || Key == 32)
		{
			if (_iGroup == 0)
			{
				Select(!_bChecked);
				cFrame.SetFocus(Self);
				if (_bChecked)
				{
					cFrame.Notify(_iUIEvent);
				}
			}
			else
			{
				if (!_bChecked)
				{
					Select(!_bChecked);
					cFrame.SetFocus(Self);
					if (_bChecked)
					{
						cFrame.Notify(_iUIEvent);
					}
				}
			}
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
					if (_iGroup == 0)
					{
						Select(!_bChecked);
						cFrame.SetFocus(Self);
						if (_bChecked)
						{
							cFrame.Notify(_iUIEvent);
						}
					}
					else
					{
						if (!_bChecked)
						{
							Select(!_bChecked);
							cFrame.SetFocus(Self);
							if (_bChecked)
							{
								cFrame.Notify(_iUIEvent);
							}
						}
					}
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
			cFrame.SetFocus(None);
			Return True;
		}
	}
	*/
	return false;
}
void UUICheckboxFn::Draw(UCanvas* Canvas)
{
	/*
	local int oldstyle;
	local Font oldfont;
	local Object.Color OldColor;
	if (cFrame._cMouseOver == Self)
	{
		_iState = 1;
	}
	Canvas.SetPos(_ScaledPos.X + 100, _ScaledPos.Y);
	OldColor = Canvas.DrawColor;
	oldstyle = Canvas.Style;
	oldfont = Canvas.Font;
	Canvas.Style = 6;
	if (_bChecked)
	{
		Canvas.DrawTile(_Texture, _iTexDim.W, _iTexDim.H, _iTexDim.X, _iTexDim.Y, _iTexDim.W, _iTexDim.H);
	}
	else
	{
		Canvas.DrawTile(_Texture, _iTexDim.W, _iTexDim.H, _iTexDim.X + _iTexDim.W, _iTexDim.Y, _iTexDim.W, _iTexDim.H);
	}
	if (_iState == 1)
	{
		Canvas.SetPos(200 + cFrame.offset.X, _ScaledPos.Y + 2);
		Canvas.DrawTile(_Texture, 11, 9, 207, 0, 11, 9);
		Canvas.SetDrawColor(255, 255, 255);
	}
	else
	{
		Canvas.SetDrawColor(196, 190, 141);
	}
	Canvas.Font = cFrame.Fonts[2];
	Canvas.SetPos(224 + cFrame.offset.X, _ScaledPos.Y + 2);
	Canvas.DrawText(_sLabel);
	Canvas.Style = oldstyle;
	Canvas.DrawColor = OldColor;
	Canvas.Font = oldfont;
	*/
}
void UUICheckboxFn::SetTextureDimensions(FPosition dim)
{
	_iTexDim.X = dim.X;
	_iTexDim.Y = dim.Y;
	_iTexDim.W = dim.W;
	_iTexDim.H = dim.H;
}
void UUICheckboxFn::SetLabel(FString Label)
{
	_sLabel = Label;
}
void UUICheckboxFn::SetTexture(FString Tex)
{
	if (_Texture == nullptr)
	{
		//_Texture = Texture(DynamicLoadObject(Tex, Class'Texture'));
		//Log("UICheckBox::SetTexture(" $ Tex $ ") failed!");
	}
}
void UUICheckboxFn::Select(bool State)
{
	/*
	if (_iGroup != 0 && State)
	{
		cScreen.SetCheckBoxGroup(_iGroup, _iID);
	}
	_bChecked = State;
	if (_iParams == 1)
	{
		Accept();
	}
	*/
}
void UUICheckboxFn::SetClassName(FString ClassName)
{
	_sClassName = ClassName;
}
void UUICheckboxFn::SetPropertyName(FString PropName)
{
	_sPropertyName = PropName;
}
void UUICheckboxFn::SetFuncName(FString funcname)
{
	_sFuncName = funcname;
}
bool UUICheckboxFn::IsSelected()
{
	return _bChecked;
}
void UUICheckboxFn::SetState(bool Checked)
{
	_bChecked = Checked;
}
void UUICheckboxFn::Refresh()
{
	/*
	local string Status;
	if (cFrame != None && cFrame.cHUD != None && cFrame.cHUD.PlayerOwner != None)
	{
		Status = cFrame.cHUD.PlayerOwner.ConsoleCommand("get " $ _sClassName $ " " $ _sPropertyName);
		_bChecked = Status;
	}
	else
	{
		Log("cFrame.cHUD.PlayerOwner == None");
	}
	*/
}
void UUICheckboxFn::Accept()
{
	/*
	if (cFrame != None && cFrame.cHUD != None && cFrame.cHUD.PlayerOwner != None)
	{
		PrivateSet(_sClassName $ " " $ _sPropertyName $ " " $ _bChecked);
		cFrame.cHUD.PlayerOwner.ConsoleCommand(_sFuncName @ _bChecked);
	}
	*/
}
