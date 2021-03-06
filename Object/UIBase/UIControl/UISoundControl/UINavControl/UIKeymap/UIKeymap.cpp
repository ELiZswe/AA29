// All the original content belonged to the US Army

#include "AA29/Object/UIBase/UIControl/UISoundControl/UINavControl/UIKeymap/UIKeymap.h"
#include "AA29/Object/UIBase/UIFrame/UIFrame.h"
#include "AA29/Object/UIBase/UIControl/UIMouse/UIMouse.h"

UUIKeymap::UUIKeymap()
{
	_iKey = -1;
	_iAltKey = -1;
}

void UUIKeymap::Destroyed()
{
	Super::Destroyed();
	_Texture = nullptr;
}
void UUIKeymap::MouseMove(int32 mX, int32 mY)
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
		if (_bEdit)
		{
			_bEdit = false;
			cFrame->SetFocus(nullptr);
		}
	}
}

bool UUIKeymap::ProcessKeyEvent(int32 Key, int32 Action, float Delta)
{
	if (!_bEnabled)
	{
		return false;
	}
	if (Key == 27)
	{
		_iState = 0;
		_bButtonDown = false;
		if (_bEdit)
		{
			_bEdit = false;
			cFrame->SetFocus(nullptr);
			return true;
		}
		return false;
	}
	if (Key >= 112 && Key <= 115)
	{
		return false;
	}
	if (_bEdit == true)
	{
		if (Action == 1)
		{
			return true;
		}
		if (Action == 3)
		{
			SetInputKeyPrivate(Key);
			_bButtonDown = false;
			cFrame->SetFocus(nullptr);
			return true;
		}
	}
	else
	{
		if (cFrame->_cMouseOver == this && Action == 3)
		{
			if (Key == 13)
			{
				cFrame->SetFocus(this);
				_bEdit = true;
				return true;
			}
			if (Key == 8 || Key == 46)
			{
				UnbindKeys();
				return true;
			}
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
			cFrame->SetFocus(nullptr);
			return true;
		}
	}
	return false;
}

void UUIKeymap::SetInputKey(int32 Index, int32 Key)
{
	if (Index == 0)
	{
		_iKey = Key;
		//_sKey = GetInputKeyString(Key);
	}
	else
	{
		if (Index == 1)
		{
			_iAltKey = Key;
			//_sAltKey = GetInputKeyString(Key);
		}
	}
}

void UUIKeymap::UnbindKeys()
{
	if (_sKey != "")
	{
		//PrivateSet("input " + _sKey + " ");
	}
	if (_sAltKey != "")
	{
		//PrivateSet("input " + _sKey + " ");
	}
	_iKey = -1;
	_sKey = "";
	_iAltKey = -1;
	_sAltKey = "";
}

void UUIKeymap::SetInputKeyPrivate(int32 Key)
{
	FString KeyBinding = "";
	FString keystring = "";
	if (Key == 0 || Key == -1)
	{
		return;
	}
	//KeyBinding = cFrame->cHUD->PlayerConsole->GetKeyBinding(Key);
	//keystring = GetInputKeyString(Key);
	if (_iKey == Key || _iAltKey == Key || _iKey != -1 && _iAltKey != -1)
	{
		//PrivateSet("input " + keystring + " ");
		//PrivateSet("input " + _sKey + " ");
		//PrivateSet("input " + _sAltKey + " ");
		cFrame->UnbindKey(Key, KeyBinding);
		_iKey = -1;
		_iAltKey = -1;
		_sKey = "";
		_sAltKey = "";
		_iKey = Key;
		//_sKey = GetInputKeyString(Key);
		//PrivateSet("input " + _sKey + " " + _sCommand);
	}
	else
	{
		//PrivateSet("input " + keystring + " " + _sCommand);
		cFrame->UnbindKey(Key, KeyBinding);
		if (_iKey == -1)
		{
			_iKey = Key;
			_sKey = keystring;
		}
		else
		{
			if (_iAltKey == -1)
			{
				_iAltKey = Key;
				_sAltKey = keystring;
			}
		}
	}
}

int32 UUIKeymap::GetInputKey()
{
	return _iKey;
}

FString UUIKeymap::GetLowerCase(FString upper)
{
	return upper.ToLower();
}

void UUIKeymap::Focus(bool bFocus)
{
	_bFocus = bFocus;
	if (_bFocus)
	{
		_bEdit = true;
	}
	else
	{
		_bEdit = false;
	}
}

void UUIKeymap::Draw(UCanvas* Canvas)
{
	UFont* oldfont = nullptr;
	int32 oldstyle = 0;
	FColor OldColor = FColor(0,0,0,0);
	if (!_bEnabled)
	{
		return;
	}
	if (cFrame->_cMouseOver == this)
	{
		_iState = 1;
	}
	/*
	oldfont = Canvas.Font;
	Canvas.Font = cFrame->Fonts[2];
	OldColor = Canvas.DrawColor;
	oldstyle = Canvas.Style;
	Canvas.Style = 6;
	Canvas.SetPos(_ScaledPos.X, _ScaledPos.Y);
	Canvas.DrawTile(_Texture, _iTexDim.W - 4, _iTexDim.H, _iTexDim.X, _iTexDim.Y, _iTexDim.W - 4, _iTexDim.H);
	Canvas.SetPos(_ScaledPos.X + _iTexDim.W - 4, _ScaledPos.Y);
	Canvas.DrawTile(_Texture, _iTexDim.W - 4, _iTexDim.H, _iTexDim.X + 4, _iTexDim.Y, _iTexDim.W - 4, _iTexDim.H);
	if (_bEdit)
	{
		Canvas.SetDrawColor(0, 255, 0);
	}
	else
	{
		Canvas.SetDrawColor(255, 255, 255);
	}
	Canvas.SetPos(_ScaledPos.X + 2, _ScaledPos.Y + 2);
	if (_sAltKey == "")
	{
		Canvas.DrawText(_sKey);
	}
	else
	{
		Canvas.DrawText(_sKey + " or " + _sAltKey);
	}
	if (_iState == 1)
	{
		Canvas.SetPos(200 + cFrame->offset.X, _ScaledPos.Y + 7);
		if (_bEdit)
		{
			Canvas.DrawTile(_Texture, 11, 9, 207, 9, 11, 9);
			Canvas.SetDrawColor(0, 255, 0);
		}
		else
		{
			Canvas.DrawTile(_Texture, 11, 9, 207, 0, 11, 9);
			Canvas.SetDrawColor(255, 255, 255);
		}
	}
	else
	{
		Canvas.SetDrawColor(196, 190, 141);
	}
	Canvas.SetPos(224 + cFrame->offset.X, _ScaledPos.Y + 2);
	Canvas.DrawText(_sLabel);
	Canvas.Style = oldstyle;
	Canvas.DrawColor = OldColor;
	Canvas.Font = oldfont;
	*/
}

void UUIKeymap::SetTexture(FString Tex)
{
	if (_Texture == nullptr)
	{
		//_Texture = Texture(DynamicLoadObject(Tex, Class'Texture'));
		//Log("UICheckBox::SetTexture(" + Tex + ") failed!");
	}
}

void UUIKeymap::SetTextureDimensions(FPosition dim)
{
	_iTexDim.X = dim.X;
	_iTexDim.Y = dim.Y;
	_iTexDim.W = dim.W;
	_iTexDim.H = dim.H;
}

void UUIKeymap::SetCommand(FString Command)
{
	_sCommand = Command;
}

void UUIKeymap::SetLabel(FString Label)
{
	_sLabel = Label;
}

bool UUIKeymap::UnbindSpecificKey(int32 Key, FString Command)
{
	if (Command != _sCommand)
	{
		return false;
	}
	if (_iKey == Key)
	{
		_iKey = _iAltKey;
		_sKey = _sAltKey;
		_iAltKey = -1;
		_sAltKey = "";
		return true;
	}
	if (_iAltKey == Key)
	{
		_iAltKey = -1;
		_sAltKey = "";
		return true;
	}
	return false;     //FAKE   /ELiZ
}

FString UUIKeymap::GetCommand()
{
	return _sCommand;
}
