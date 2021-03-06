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
		return;
	}
	if (cFrame->cMouse->iMouseX >= _ScaledPos.X && cFrame->cMouse->iMouseX <= _ScaledPos.X + _ScaledPos.W - 1 && cFrame->cMouse->iMouseY >= _ScaledPos.Y && cFrame->cMouse->iMouseY <= _ScaledPos.Y + _ScaledPos.H - 1)
	{
		if (_bButtonDown == true)
		{
			_iThumbPos = cFrame->cMouse->iMouseX - _ScaledPos.X - _iMouseDragOffset;
			if (_iThumbPos > _ScaledPos.W - _iThumbSize)
			{
				_iThumbPos = _ScaledPos.W - _iThumbSize;
				_iMouseDragOffset = cFrame->cMouse->iMouseX - _ScaledPos.X + _iThumbPos;
			}
			if (_iThumbPos <= 0)
			{
				_iThumbPos = 0;
				_iMouseDragOffset = cFrame->cMouse->iMouseX - _ScaledPos.X;
			}
			UpdateValue();
			Accept();
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
	}
	*/
}
bool UUISlider::ProcessKeyEvent(int32 Key, int32 Action, float Delta)
{
	/*
	if (Key == 37 && Action == 1)
	{
		if (cFrame->_cMouseOver == this)
		{
			Dec();
			UpdateValue();
			Accept();
			return true;
		}
	}
	if (Key == 39 && Action == 1)
	{
		if (cFrame->_cMouseOver == this)
		{
			Inc();
			UpdateValue();
			Accept();
			return true;
		}
	}
	if (Key == 1)
	{
		if (cFrame->cMouse->iMouseX >= _ScaledPos.X && cFrame->cMouse->iMouseX <= _ScaledPos.X + _ScaledPos.W - 1 && cFrame->cMouse->iMouseY >= _ScaledPos.Y && cFrame->cMouse->iMouseY <= _ScaledPos.Y + _ScaledPos.H - 1)
		{
			if (Action == 1)
			{
				if (cFrame->cMouse->iMouseX >= _ScaledPos.X + _iThumbPos && cFrame->cMouse->iMouseX <= _ScaledPos.X + _iThumbPos + _iThumbSize)
				{
					_iMouseDragOffset = cFrame->cMouse->iMouseX - _ScaledPos.X + _iThumbPos;
				}
				else
				{
					_iThumbPos = cFrame->cMouse->iMouseX - _ScaledPos.X;
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
				cFrame->SetFocus(this);
			}
			if (Action == 3)
			{
				_bButtonDown = false;
				_iState = 1;
				_iMouseDragOffset = 0;
			}
			return true;
		}
		if (_bButtonDown == true && Action == 3 && cFrame->cFocus == this)
		{
			_bButtonDown = false;
			_iMouseDragOffset = 0;
			cFrame->SetFocus(nullptr);
			return true;
		}
	}
	*/
	return false;
}

void UUISlider::Draw(UCanvas* Canvas)
{
	int32 oldstyle = 0;
	FColor OldColor = FColor(0,0,0,0);
	int32 iTemp = 0;
	/*
	if (_bDebug)
	{
		Canvas.DrawText("_Texture = " + _Texture);
	}
	if (cFrame->_cMouseOver == this)
	{
		_iState = 1;
	}
	OldColor = Canvas.DrawColor;
	oldstyle = Canvas.Style;
	if (_Texture != nullptr)
	{
		Canvas.Style = 6;
		Canvas.SetPos(_ScaledPos.X - 2, _ScaledPos.Y);
		Canvas.DrawTile(_Texture, _TexDimBack.W, _TexDimBack.H, _TexDimBack.X, _TexDimBack.Y, _TexDimBack.W, _TexDimBack.H);
		Canvas.SetPos(_ScaledPos.X + _iThumbPos, _ScaledPos.Y + 2);
		Canvas.DrawTile(_Texture, _TexDimThumb.W, _TexDimThumb.H, _TexDimThumb.X, _TexDimThumb.Y, _TexDimThumb.W, _TexDimThumb.H);
	}
	if (_iState == 1)
	{
		Canvas.SetPos(200 + cFrame->offset.X, _ScaledPos.Y + 2);
		Canvas.DrawTile(_Texture, 11, 9, 207, 0, 11, 9);
		Canvas.SetDrawColor(255, 255, 255);
	}
	else
	{
		Canvas.SetDrawColor(196, 190, 141);
	}
	Canvas.Font = cFrame->Fonts[2];
	Canvas.SetPos(224 + cFrame->offset.X, _ScaledPos.Y - 2);
	Canvas.DrawText(_sLabel);
	Canvas.SetPos(384 + cFrame->offset.X, _ScaledPos.Y - 2);
	iTemp = _fValue;
	switch(_iParams)
	{
			case 0:
				iTemp = _fValue * 100;
				Canvas.DrawText(iTemp + "%");
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
				Canvas.Font = cFrame->Fonts[1];
				Canvas.SetPos(336 + cFrame->offset.X, _ScaledPos.Y - 1);
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
		//Log("UISlider::SetTexture(" + Tex + ") failed!");
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
	FString Status = "";
	float Temp = 0;
	/*
	if (cFrame != nullptr && cFrame->cHUD != nullptr && cFrame->cHUD.PlayerOwner != nullptr)
	{
		Status = cFrame->cHUD.PlayerOwner.ConsoleCommand("get " + _sClassName + " " + _sPropertyName);
		_fValue = Status;
		_fValue =FMath::Clamp(_fValue, _fMin, _fMax);
		Temp = _fValue - _fMin / _fMax - _fMin;
		_iThumbPos = Temp * 244;
	}
	else
	{
		Log("cFrame->cHUD.PlayerOwner == nullptr");
	}
	*/
}

void UUISlider::Accept()
{
	FString mod = "";
	FString Console = "";
	/*
	if (cFrame != nullptr && cFrame->cHUD != nullptr && cFrame->cHUD.PlayerOwner != nullptr)
	{
		switch(_iParams)
		{
			case 0:
			case 2:
			case 3:
				PrivateSet(_sClassName @ _sPropertyName @ _fValue);
				return;
			case 1:
				cFrame->cHUD.PlayerOwner.ConsoleCommand(_sPropertyName @ _fValue);
				return;
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
					Console = "SetMod" @ _sPropertyName @ "AGP_Inventory.WeaponMod_" + mod;
					cFrame->cHUD.PlayerOwner.ConsoleCommand(Console);
					Log(Console);
				}
				return;
			case 20:
				if (lastint != _fValue)
				{
					lastint = _fValue;
					Console = "SetIndex" @ lastint;
					cFrame->cHUD.PlayerOwner.ConsoleCommand(Console);
					Log(Console);
					cFrame->Notify(_iUIEvent);
				}
				return;
			default:
		}
	}
	*/
}

FString UUISlider::GetMod()
{
	switch (_iParams)
	{
		case 10:
			if (_fValue < 0.25)
			{
				return "Ironsight";
				break;
			}
			if (_fValue < 0.5)
			{
				return "Anpvs10_Sight";
				break;
			}
			if (_fValue < 0.75)
			{
				return "M68_Aimpoint";
				break;
			}
			return "Acog4x";
	
		case 11:
			if (_fValue < 0.5)
			{
				return "Heatshield";
			}
			else
			{
				return "Reflex";
			}
		case 12:
		case 13:
			if (_fValue < 0.33)
			{
				return "Heatshield";
			}
			else
			{
				if (_fValue < 0.66)
				{
					return "Anpeq5_Laser";
				}
				else
				{
					return "VliFlashLight";
				}
			}
		case 14:
			if (_fValue < 0.33)
			{
				return "Heatshield";
			}
			else
			{
				if (_fValue < 0.66)
				{
					return "Harris_Bipod";
				}
				else
				{
					return "M203_Gren";
				}
			}
		case 15:
			if (_fValue < 0.5)
			{
				return "NONE";
			}
			else
			{
				return "M4qd_Suppressor";
			}
		default:
			return "UNKNOWN";
	}
}

void UUISlider::SetMod(FString mod)
{
	/*
	mod = Mid(mod, Len("AGP_Inventory.WeaponMod_"), Len(mod));
	lastmod = mod;
	switch(_iParams)
	{
		case 10:
			SetModValue(mod, "Anpvs10_Sight", "Acog4x");
			return;
		case 11:
			SetModValue(mod, "Reflex");
			return;
		case 12:
		case 13:
			SetModValue(mod, "Anpeq5_Laser", "VliFlashlight");
			return;
		case 14:
			SetModValue(mod, "Harris_Bipod", "M203_Gren");
			return;
		case 15:
			SetModValue(mod, "M4qd_Suppressor");
			return;
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
	_fValue =FMath::Clamp(_fValue, _fMin, _fMax);
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
