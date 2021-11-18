// All the original content belonged to the US Army


#include "AA29/Object/UIBase/UIControl/UISoundControl/UINavControl/UIKeymap/UIKeymap.h"

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
		if (_bEdit)
		{
			_bEdit = False;
			cFrame.SetFocus(None);
		}
	}
	*/
}
bool UUIKeymap::ProcessKeyEvent(int32 Key, int32 Action, float Delta)
{
	/*
	if (!_bEnabled)
	{
		Return False;
	}
	if (Key == 27)
	{
		_iState = 0;
		_bButtonDown = False;
		if (_bEdit)
		{
			_bEdit = False;
			cFrame.SetFocus(None);
			Return True;
		}
		Return False;
	}
	if (Key >= 112 && Key <= 115)
	{
		Return False;
	}
	if (_bEdit == True)
	{
		if (Action == 1)
		{
			Return True;
		}
		if (Action == 3)
		{
			SetInputKeyPrivate(Key);
			_bButtonDown = False;
			cFrame.SetFocus(None);
			Return True;
		}
	}
	else
	{
		if (cFrame._cMouseOver == Self && Action == 3)
		{
			if (Key == 13)
			{
				cFrame.SetFocus(Self);
				_bEdit = true;
				Return True;
			}
			if (Key == 8 || Key == 46)
			{
				UnbindKeys();
				Return True;
			}
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
void UUIKeymap::SetInputKey(int32 Index, int32 Key)
{
	/*
	if (Index == 0)
	{
		_iKey = Key;
		_sKey = GetInputKeyString(Key);
	}
	else
	{
		if (Index == 1)
		{
			_iAltKey = Key;
			_sAltKey = GetInputKeyString(Key);
		}
	}
	*/
}
void UUIKeymap::UnbindKeys()
{
	/*
	if (_sKey != "")
	{
		PrivateSet("input " $ _sKey $ " ");
	}
	if (_sAltKey != "")
	{
		PrivateSet("input " $ _sKey $ " ");
	}
	_iKey = -1;
	_sKey = "";
	_iAltKey = -1;
	_sAltKey = "";
	*/
}
void UUIKeymap::SetInputKeyPrivate(int32 Key)
{
	/*
	local string KeyBinding;
	local string keystring;
	if (Key == 0 || Key == -1)
	{
		Return;
	}
	KeyBinding = cFrame.cHUD.PlayerConsole.GetKeyBinding(Key);
	keystring = GetInputKeyString(Key);
	if (_iKey == Key || _iAltKey == Key || _iKey != -1 && _iAltKey != -1)
	{
		PrivateSet("input " $ keystring $ " ");
		PrivateSet("input " $ _sKey $ " ");
		PrivateSet("input " $ _sAltKey $ " ");
		cFrame.UnbindKey(Key, KeyBinding);
		_iKey = -1;
		_iAltKey = -1;
		_sKey = "";
		_sAltKey = "";
		_iKey = Key;
		_sKey = GetInputKeyString(Key);
		PrivateSet("input " $ _sKey $ " " $ _sCommand);
	}
	else
	{
		PrivateSet("input " $ keystring $ " " $ _sCommand);
		cFrame.UnbindKey(Key, KeyBinding);
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
	*/
}
int32 UUIKeymap::GetInputKey()
{
	return _iKey;
}
FString UUIKeymap::GetLowerCase(FString upper)
{
	FString Lower="";
	/*
	Switch(upper)
	{
			case "A":
				Lower = "a";
				break;
			case "B":
				Lower = "b";
				break;
			case "C":
				Lower = "c";
				break;
			case "D":
				Lower = "d";
				break;
			case "E":
				Lower = "e";
				break;
			case "F":
				Lower = "f";
				break;
			case "G":
				Lower = "g";
				break;
			case "H":
				Lower = "h";
				break;
			case "I":
				Lower = "i";
				break;
			case "J":
				Lower = "j";
				break;
			case "K":
				Lower = "k";
				break;
			case "L":
				Lower = "l";
				break;
			case "M":
				Lower = "m";
				break;
			case "N":
				Lower = "n";
				break;
			case "O":
				Lower = "o";
				break;
			case "P":
				Lower = "p";
				break;
			case "Q":
				Lower = "q";
				break;
			case "R":
				Lower = "r";
				break;
			case "S":
				Lower = "s";
				break;
			case "T":
				Lower = "t";
				break;
			case "U":
				Lower = "u";
				break;
			case "V":
				Lower = "v";
				break;
			case "W":
				Lower = "w";
				break;
			case "X":
				Lower = "x";
				break;
			case "Y":
				Lower = "y";
				break;
			case "Z":
				Lower = "z";
				break;
			default:
	}
	*/
	return Lower;
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
	/*
	local Font oldfont;
	local int oldstyle;
	local Object.Color OldColor;
	if (!_bEnabled)
	{
		Return;
	}
	if (cFrame._cMouseOver == Self)
	{
		_iState = 1;
	}
	oldfont = Canvas.Font;
	Canvas.Font = cFrame.Fonts[2];
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
		Canvas.DrawText(_sKey $ " or " $ _sAltKey);
	}
	if (_iState == 1)
	{
		Canvas.SetPos(200 + cFrame.offset.X, _ScaledPos.Y + 7);
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
	Canvas.SetPos(224 + cFrame.offset.X, _ScaledPos.Y + 2);
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
		//Log("UICheckBox::SetTexture(" $ Tex $ ") failed!");
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
void UUIKeymap::UnbindSpecificKey(int32 Key, FString Command)
{
	/*
	if (Command != _sCommand)
	{
		Return False;
	}
	if (_iKey == Key)
	{
		_iKey = _iAltKey;
		_sKey = _sAltKey;
		_iAltKey = -1;
		_sAltKey = "";
		Return True;
	}
	if (_iAltKey == Key)
	{
		_iAltKey = -1;
		_sAltKey = "";
		Return True;
	}
	*/
}
FString UUIKeymap::GetCommand()
{
	return _sCommand;
}