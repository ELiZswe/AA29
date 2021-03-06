// All the original content belonged to the US Army

#include "AA29/Object/UIBase/UIControl/UISoundControl/UINavControl/UICheckbox/UICheckbox.h"
#include "AA29/Object/UIBase/UIFrame/UIFrame.h"

UUICheckbox::UUICheckbox()
{

}

void UUICheckbox::Destroyed()
{
	Super::Destroyed();
	_Texture = nullptr;
}
void UUICheckbox::MouseMove(int32 mX, int32 mY)
{
	/*
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
	}
	*/
}
bool UUICheckbox::ProcessKeyEvent(int32 Key, int32 Action, float Delta)
{
	/*
	if (!_bEnabled)
	{
		return false;
	}
	if (cFrame->_cMouseOver == this && Action == 3)
	{
		if (Key == 13 || Key == 32)
		{
			if (_iGroup == 0)
			{
				Select(!_bChecked);
				cFrame->SetFocus(this);
				if (_bChecked)
				{
					cFrame->Notify(_iUIEvent);
				}
			}
			else
			{
				if (!_bChecked)
				{
					Select(!_bChecked);
					cFrame->SetFocus(this);
					if (_bChecked)
					{
						cFrame->Notify(_iUIEvent);
					}
				}
			}
			return true;
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
					if (_iGroup == 0)
					{
						Select(!_bChecked);
						cFrame->SetFocus(this);
						if (_bChecked)
						{
							cFrame->Notify(_iUIEvent);
						}
					}
					else
					{
						if (!_bChecked)
						{
							Select(!_bChecked);
							cFrame->SetFocus(this);
							if (_bChecked)
							{
								cFrame->Notify(_iUIEvent);
							}
						}
					}
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
	*/
	return false;
}
void UUICheckbox::Draw(UCanvas* Canvas)
{
	/*
	int32 oldstyle = 0;
	UFont* oldfont = nullptr;
	FColor OldColor = FColor(0,0,0,0);
	if (cFrame->_cMouseOver == this)
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
		Canvas.SetPos(200 + cFrame->offset.X, _ScaledPos.Y + 2);
		Canvas.DrawTile(_Texture, 11, 9, 207, 0, 11, 9);
		Canvas.SetDrawColor(255, 255, 255);
	}
	else
	{
		Canvas.SetDrawColor(196, 190, 141);
	}
	Canvas.Font = cFrame->Fonts[2];
	Canvas.SetPos(224 + cFrame->offset.X, _ScaledPos.Y + 2);
	Canvas.DrawText(_sLabel);
	Canvas.Style = oldstyle;
	Canvas.DrawColor = OldColor;
	Canvas.Font = oldfont;
	*/
}
void UUICheckbox::SetTextureDimensions(FPosition dim)
{
	_iTexDim.X = dim.X;
	_iTexDim.Y = dim.Y;
	_iTexDim.W = dim.W;
	_iTexDim.H = dim.H;
}
void UUICheckbox::SetLabel(FString Label)
{
	_sLabel = Label;
}
void UUICheckbox::SetTexture(FString Tex)
{
	if (_Texture == nullptr)
	{
		//_Texture = Texture(DynamicLoadObject(Tex, Class'Texture'));
		//Log("UICheckBox::SetTexture(" + Tex + ") failed!");
	}
}
void UUICheckbox::Select(bool State)
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
void UUICheckbox::SetClassName(FString ClassName)
{
	//_sClassName = ClassName;
}
void UUICheckbox::SetPropertyName(FString PropName)
{
	//_sPropertyName = PropName;
}
bool UUICheckbox::IsSelected()
{
	return _bChecked;
}
void UUICheckbox::SetState(bool Checked)
{
	_bChecked = Checked;
}
void UUICheckbox::Refresh()
{
	/*
	FString Status;
	if (cFrame != nullptr && cFrame->cHUD != nullptr && cFrame->cHUD.PlayerOwner != nullptr)
	{
		Status = cFrame->cHUD.PlayerOwner.ConsoleCommand("get " + _sClassName + " " + _sPropertyName);
		_bChecked = Status;
	}
	else
	{
		Log("cFrame->cHUD.PlayerOwner == nullptr");
	}
	*/
}
void UUICheckbox::Accept()
{
	/*
	if (cFrame != nullptr && cFrame->cHUD != nullptr && cFrame->cHUD.PlayerOwner != nullptr)
	{
		PrivateSet(_sClassName + " " + _sPropertyName + " " + _bChecked);
	}
	*/
}
