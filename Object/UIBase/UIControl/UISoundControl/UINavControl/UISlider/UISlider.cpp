// All the original content belonged to the US Army


#include "AA29/Object/UIBase/UIControl/UISoundControl/UINavControl/UISlider/UISlider.h"

UUISlider::UUISlider()
{
	_iThumbSize = 30;
}



void UUISlider::Destroyed()
{
	Super::Destroyed();
	_Texture = nullptr;
}
void UUISlider::MouseMove(int32 mX, int32 mY)
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
			_iThumbPos = cFrame.cMouse.iMouseX - _ScaledPos.X - _iMouseDragOffset;
			if (_iThumbPos > _ScaledPos.W - _iThumbSize)
			{
				_iThumbPos = _ScaledPos.W - _iThumbSize;
				_iMouseDragOffset = cFrame.cMouse.iMouseX - _ScaledPos.X + _iThumbPos;
			}
			if (_iThumbPos <= 0)
			{
				_iThumbPos = 0;
				_iMouseDragOffset = cFrame.cMouse.iMouseX - _ScaledPos.X;
			}
			UpdateValue();
			Accept();
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
bool UUISlider::ProcessKeyEvent(int32 Key, int32 Action, float Delta)
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
				if (cFrame.cMouse.iMouseX >= _ScaledPos.X + _iThumbPos && cFrame.cMouse.iMouseX <= _ScaledPos.X + _iThumbPos + _iThumbSize)
				{
					_iMouseDragOffset = cFrame.cMouse.iMouseX - _ScaledPos.X + _iThumbPos;
				}
				else
				{
					_iThumbPos = cFrame.cMouse.iMouseX - _ScaledPos.X;
					if (_iThumbPos > _ScaledPos.W - _iThumbSize - 1)
					{
						_iThumbPos = _ScaledPos.W - _iThumbSize - 1;
					}
					UpdateValue();
					Accept();
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
void UUISlider::Draw(UCanvas* Canvas)
{
	/*
	local int oldstyle;
	local Object.Color OldColor;
	local int iTemp;
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
		Canvas.SetPos(_ScaledPos.X - 2, _ScaledPos.Y);
		Canvas.DrawTile(_Texture, _TexDimBack.W, _TexDimBack.H, _TexDimBack.X, _TexDimBack.Y, _TexDimBack.W, _TexDimBack.H);
		Canvas.SetPos(_ScaledPos.X + _iThumbPos, _ScaledPos.Y + 2);
		Canvas.DrawTile(_Texture, _TexDimThumb.W, _TexDimThumb.H, _TexDimThumb.X, _TexDimThumb.Y, _TexDimThumb.W, _TexDimThumb.H);
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
	Canvas.SetPos(224 + cFrame.offset.X, _ScaledPos.Y - 2);
	Canvas.DrawText(_sLabel);
	Canvas.SetPos(384 + cFrame.offset.X, _ScaledPos.Y - 2);
	iTemp = _fValue;
	Switch(_iParams)
	{
			case 0:
				iTemp = _fValue * 100;
				Canvas.DrawText(iTemp $ "%");
				break;
			case 1:
				Canvas.DrawText(_fValue);
				break;
			case 2:
				Canvas.DrawText(iTemp);
				break;
			case 3:
				Canvas.DrawText(_fValue);
				break;
			case 10:
			case 11:
			case 12:
			case 13:
			case 14:
			case 15:
				Canvas.Font = cFrame.Fonts[1];
				Canvas.SetPos(336 + cFrame.offset.X, _ScaledPos.Y - 1);
				Canvas.DrawText(GetMod());
				break;
			case 20:
				Canvas.DrawText(iTemp);
				break;
			default:
	}
	Canvas.DrawColor = OldColor;
	Canvas.Style = oldstyle;
	*/
}
void UUISlider::SetTexture(FString Tex)
{
	if (_Texture == nullptr)
	{
		//_Texture = Texture(DynamicLoadObject(Tex, Class'Texture'));
		//Log("UISlider::SetTexture(" $ Tex $ ") failed!");
	}
}
void UUISlider::SetTexDimBack(FPosition dim)
{
	_TexDimBack.X = dim.X;
	_TexDimBack.Y = dim.Y;
	_TexDimBack.W = dim.W;
	_TexDimBack.H = dim.H;
}
void UUISlider::SetTexDimThumb(FPosition dim)
{
	_TexDimThumb.X = dim.X;
	_TexDimThumb.Y = dim.Y;
	_TexDimThumb.W = dim.W;
	_TexDimThumb.H = dim.H;
	_iThumbSize = _TexDimThumb.W;
}
void UUISlider::SetLabel(FString Label)
{
	_sLabel = Label;
}
void UUISlider::Inc()
{
	if (_iThumbPos < 244)
	{
		_iThumbPos++;
	}
}
void UUISlider::Dec()
{
	if (_iThumbPos > 0)
	{
		_iThumbPos--;
	}
}
void UUISlider::SetClassName(FString ClassName)
{
	_sClassName = ClassName;
}
void UUISlider::SetPropertyName(FString PropName)
{
	_sPropertyName = PropName;
}
void UUISlider::Refresh()
{
	/*
	local string Status;
	local float Temp;
	if (cFrame != None && cFrame.cHUD != None && cFrame.cHUD.PlayerOwner != None)
	{
		Status = cFrame.cHUD.PlayerOwner.ConsoleCommand("get " $ _sClassName $ " " $ _sPropertyName);
		_fValue = Status;
		_fValue = FClamp(_fValue, _fMin, _fMax);
		Temp = _fValue - _fMin / _fMax - _fMin;
		_iThumbPos = Temp * 244;
	}
	else
	{
		Log("cFrame.cHUD.PlayerOwner == None");
	}
	*/
}
void UUISlider::Accept()
{
	/*
	local string mod;
	local string Console;
	if (cFrame != None && cFrame.cHUD != None && cFrame.cHUD.PlayerOwner != None)
	{
		Switch(_iParams)
		{
			case 0:
			case 2:
			case 3:
				PrivateSet(_sClassName @ _sPropertyName @ _fValue);
				Return;
			case 1:
				cFrame.cHUD.PlayerOwner.ConsoleCommand(_sPropertyName @ _fValue);
				Return;
			case 10:
			case 11:
			case 12:
			case 13:
			case 14:
			case 15:
				mod = GetMod();
				if (lastmod != mod)
				{
					lastmod = mod;
					Console = "SetMod" @ _sPropertyName @ "AGP_Inventory.WeaponMod_" $ mod;
					cFrame.cHUD.PlayerOwner.ConsoleCommand(Console);
					Log(Console);
				}
				Return;
			case 20:
				if (lastint != _fValue)
				{
					lastint = _fValue;
					Console = "SetIndex" @ lastint;
					cFrame.cHUD.PlayerOwner.ConsoleCommand(Console);
					Log(Console);
					cFrame.Notify(_iUIEvent);
				}
				Return;
			default:
		}
	}
	*/
}

void UUISlider::GetMod()
{
	/*
	Switch(_iParams)
	{
		case 10:
			if (_fValue < 0.25)
			{
				Return "Ironsight";
				break;
			}
			if (_fValue < 0.5)
			{
				Return "Anpvs10_Sight";
				break;
			}
			if (_fValue < 0.75)
			{
				Return "M68_Aimpoint";
				break;
			}
			Return "Acog4x";
	}
		case 11:
			if (_fValue < 0.5)
			{
				Return "Heatshield";
			}
			else
			{
				Return "Reflex";
			}
		case 12:
		case 13:
			if (_fValue < 0.33)
			{
				Return "Heatshield";
			}
			else
			{
				if (_fValue < 0.66)
				{
					Return "Anpeq5_Laser";
				}
				else
				{
					Return "VliFlashLight";
				}
			}
		case 14:
			if (_fValue < 0.33)
			{
				Return "Heatshield";
			}
			else
			{
				if (_fValue < 0.66)
				{
					Return "Harris_Bipod";
				}
				else
				{
					Return "M203_Gren";
				}
			}
		case 15:
			if (_fValue < 0.5)
			{
				Return "NONE";
			}
			else
			{
				Return "M4qd_Suppressor";
			}
		default:
			Return "UNKNOWN";
		}
		*/
}

void UUISlider::SetMod(FString mod)
{
	/*
	mod = Mid(mod, Len("AGP_Inventory.WeaponMod_"), Len(mod));
	lastmod = mod;
	Switch(_iParams)
	{
		case 10:
			SetModValue(mod, "Anpvs10_Sight", "Acog4x");
			Return;
		case 11:
			SetModValue(mod, "Reflex");
			Return;
		case 12:
		case 13:
			SetModValue(mod, "Anpeq5_Laser", "VliFlashlight");
			Return;
		case 14:
			SetModValue(mod, "Harris_Bipod", "M203_Gren");
			Return;
		case 15:
			SetModValue(mod, "M4qd_Suppressor");
			Return;
		default:
	}
	*/
}

void UUISlider::SetModValue(FString mod, FString s1, FString s2)
{
	/*
	if (s2 == "")
	{
		if (mod ~= s1)
		{
			SetValue(1);
		}
		else
		{
			SetValue(0);
		}
	}
	else
	{
		if (mod ~= s1)
		{
			SetValue(0.5);
		}
		else
		{
			if (mod ~= s2)
			{
				SetValue(1);
			}
			else
			{
				SetValue(0);
			}
		}
	}
	*/
}
void UUISlider::UpdateValue()
{
	_fValue = _iThumbPos / 244;
	_fValue = _fValue * _fMax - _fMin + _fMin;
}
void UUISlider::SetValue(float Value)
{
	/*
	float Temp = 0f;
	lastint = Value;
	_fValue = Value;
	_fValue = FClamp(_fValue, _fMin, _fMax);
	Temp = _fValue - _fMin / _fMax - _fMin;
	_iThumbPos = Temp * 244;
	if (_iParams == 2 || _iParams == 3)
	{
		Accept();
	}
	*/
}
void UUISlider::SetMinMax(float Min, float Max)
{
	_fMin = Min;
	_fMax = Max;
}