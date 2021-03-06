// All the original content belonged to the US Army

#include "AA29/Object/UIBase/UIControl/UISoundControl/UINavControl/UIClassButton/UIClassButton.h"
#include "AA29/Object/UIBase/UIFrame/UIFrame.h"
#include "AA29/Object/UIBase/UIControl/UIMouse/UIMouse.h"

UUIClassButton::UUIClassButton()
{
	_sOverSound = "S_AA2_UI.Generic.click2";
	_sClickSound = "S_AA2_Foley.Nightvision.NOD_off";
}

void UUIClassButton::Destroyed()
{
	Super::Destroyed();
	_tClass = nullptr;
	_tAltClass1 = nullptr;
	_tAltClass2 = nullptr;
	_tAltClass3 = nullptr;
	_tNotAvail = nullptr;
	_tNotQual = nullptr;
	_tSelect = nullptr;
}

void UUIClassButton::MouseMove(int32 mX, int32 mY)
{
	if (!IsActive())
	{
		return;
	}
	if (mX >= _ScaledPos.X && mX <= _ScaledPos.X + _ScaledPos.W - 1 && mY >= _ScaledPos.Y && mY <= _ScaledPos.Y + _ScaledPos.H - 1)
	{
		if (!cFrame->SetMouseOver(this))
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
				cFrame->PlayMenuSoundSpecific(_sMouseOver);
			}
		}
	}
	else
	{
		_iState = 0;
		_bButtonDown = false;
		_bFirstOver = false;
	}
}
bool UUIClassButton::ProcessKeyEvent(int32 Key, int32 Action, float Delta)
{
	if (!IsActive())
	{
		return false;
	}
	if (Key == 13 && Action == 3)
	{
		if (cFrame->_cMouseOver == this)
		{
			cFrame->Notify(_iUIEvent);
			return true;
		}
	}
	if (Key == 32 && Action == 3)
	{
		if (cFrame->_cMouseOver == this)
		{
			_bSelected = true;
			cFrame->Notify(_iUIEvent);
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
				cFrame->PlayMenuSoundSpecific(_sMouseClick);
			}
			if (Action == 3)
			{
				if (_bButtonDown == true)
				{
					_bButtonDown = false;
					_iState = 1;
					cFrame->Notify(_iUIEvent);
				}
			}
			return true;
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

void UUIClassButton::Draw(UCanvas* Canvas)
{
	int32 oldstyle = 0;
	float XL = 0;
	float YL = 0;
	UFont* oldfont = nullptr;
	FColor OldColor = FColor(0,0,0,0);
	/*
	OldColor = Canvas.DrawColor;
	oldfont = Canvas.Font;
	Canvas.Font = cFrame->Fonts[1];
	Canvas.SetDrawColor(196, 190, 141);
	Canvas.TextSize(_sLabel, XL, YL);
	Canvas.SetPos(_ScaledPos.X + _ScaledPos.W - XL / 2, _ScaledPos.Y - 20);
	Canvas.DrawText(_sLabel);
	Canvas.SetDrawColor(255, 255, 255);
	if (!_bEnabled)
	{
		if (_tNotAvail != nullptr)
		{
			Canvas.SetPos(_ScaledPos.X, _ScaledPos.Y);
			Canvas.DrawTile(_tNotAvail, _ScaledPos.W, _ScaledPos.H, _iTexDim.X, _iTexDim.Y, _iTexDim.W, _iTexDim.H);
		}
	}
	else
	{
		if (!IsQualified())
		{
			if (_tNotQual != nullptr)
			{
				Canvas.SetPos(_ScaledPos.X, _ScaledPos.Y);
				Canvas.DrawTile(_tNotQual, _ScaledPos.W, _ScaledPos.H, _iTexDim.X, _iTexDim.Y, _iTexDim.W, _iTexDim.H);
			}
		}
		else
		{
			if (_bDebug)
			{
				Canvas.SetPos(0, 0);
				Canvas.DrawText("_tClass = " + GetClassTexture());
			}
			if (cFrame->_cMouseOver == this && _iState != 2)
			{
				_iState = 1;
			}
			oldstyle = Canvas.Style;
			if (GetClassTexture() != nullptr)
			{
				Canvas.Style = 6;
				Canvas.SetPos(_ScaledPos.X, _ScaledPos.Y);
				Canvas.DrawTile(GetClassTexture(), _ScaledPos.W, _ScaledPos.H, _iTexDim.X, _iTexDim.Y, _iTexDim.W, _iTexDim.H);
				if (GetOverlayTexture() != nullptr)
				{
					Canvas.SetPos(_ScaledPos.X, _ScaledPos.Y);
					Canvas.DrawTile(GetOverlayTexture(), _ScaledPos.W, _ScaledPos.H, _iTexDim.X, _iTexDim.Y, _iTexDim.W, _iTexDim.H);
				}
			}
			if (_iState == 1)
			{
				Canvas.SetDrawColor(196, 190, 141);
				Canvas.SetPos(_ScaledPos.X, _ScaledPos.Y);
				Canvas.DrawTile(_tSelect, _ScaledPos.W, _ScaledPos.H, _iTexDim.X, _iTexDim.Y, _iTexDim.W, _iTexDim.H);
			}
			else
			{
				if (_bSelected == true)
				{
					Canvas.SetPos(_ScaledPos.X, _ScaledPos.Y);
					Canvas.DrawTile(_tSelect, _ScaledPos.W, _ScaledPos.H, _iTexDim.X, _iTexDim.Y, _iTexDim.W, _iTexDim.H);
				}
			}
			Canvas.Style = oldstyle;
		}
	}
	Canvas.DrawColor = OldColor;
	Canvas.Font = oldfont;
	*/
}
void UUIClassButton::SetTextureDimensions(FPosition dim)
{
	_iTexDim.X = dim.X;
	_iTexDim.Y = dim.Y;
	_iTexDim.W = dim.W;
	_iTexDim.H = dim.H;
}
void UUIClassButton::SetClassTexture(FString Tex)
{
	if (_tClass == nullptr)
	{
		//_tClass = Texture(DynamicLoadObject(Tex, Class'Texture'));
		//Log("UIClassButton::SetClassTexture(" + Tex + ") failed!");
	}
}
void UUIClassButton::SetAltClass1Texture(FString Tex)
{
	if (Tex == "")
	{
		return;
	}
	if (_tAltClass1 == nullptr)
	{
		//_tAltClass1 = Texture(DynamicLoadObject(Tex, Class'Texture'));
	}
	if (_tAltClass1 == nullptr)
	{
		//Log("UIClassButton::SetAltClass1Texture(" + Tex + ") failed!");
	}
}
void UUIClassButton::SetAltClass2Texture(FString Tex)
{
	if (Tex == "")
	{
		return;
	}
	if (_tAltClass2 == nullptr)
	{
		//_tAltClass2 = Texture(DynamicLoadObject(Tex, Class'Texture'));
	}
	if (_tAltClass2 == nullptr)
	{
		//Log("UIClassButton::SetAltClass2Texture(" + Tex + ") failed!");
	}
}
void UUIClassButton::SetAltClass3Texture(FString Tex)
{
	if (Tex == "")
	{
		return;
	}
	if (_tAltClass3 == nullptr)
	{
		//_tAltClass3 = Texture(DynamicLoadObject(Tex, Class'Texture'));
	}
	if (_tAltClass3 == nullptr)
	{
		//Log("UIClassButton::SetAltClass3Texture(" + Tex + ") failed!");
	}
}
void UUIClassButton::SetOverlayTexture(FString Tex)
{
	if (Tex == "")
	{
		return;
	}
	if (_tOverlay == nullptr)
	{
		//_tOverlay = Texture(DynamicLoadObject(Tex, Class'Texture'));
	}
	if (_tOverlay == nullptr)
	{
		//Log("UIClassButton::SetOverlayTexture(" + Tex + ") failed!");
	}
}
void UUIClassButton::SetNotAvailTexture(FString Tex)
{
	if (_tNotAvail == nullptr)
	{
		//_tNotAvail = Texture(DynamicLoadObject(Tex, Class'Texture'));
	}
	if (_tNotAvail == nullptr)
	{
		//Log("UIClassButton::SetNotAvailTexture(" + Tex + ") failed!");
	}
}
void UUIClassButton::SetNotQualTexture(FString Tex)
{
	if (_tNotQual == nullptr)
	{
		//_tNotQual = Texture(DynamicLoadObject(Tex, Class'Texture'));
	}
	if (_tNotQual == nullptr)
	{
		//Log("UIClassButton::SetNotQualTexture(" + Tex + ") failed!");
	}
}
void UUIClassButton::SetSelectTexture(FString Tex)
{
	if (_tSelect == nullptr)
	{
		//_tSelect = Texture(DynamicLoadObject(Tex, Class'Texture'));
		//Log("UIClassButton::SetSelectTexture(" + Tex + ") failed!");
	}
}
UMaterialInstance* UUIClassButton::GetClassTexture()
{
	if (_yUseAltClass == 1 && _tAltClass1 != nullptr)
	{
		return _tAltClass1;
	}
	else
	{
		if (_yUseAltClass == 2 && _tAltClass2 != nullptr)
		{
			return _tAltClass2;
		}
		else
		{
			if (_yUseAltClass == 3 && _tAltClass3 != nullptr)
			{
				return _tAltClass3;
			}
		}
	}
	return _tClass;
}

UMaterialInstance* UUIClassButton::GetOverlayTexture()
{
	return _tOverlay;
}

void UUIClassButton::SetLabel(FString Label)
{
	_sLabel = Label;
}

void UUIClassButton::SetClassIndex(int32 Index)
{
	_iClassIndex = Index;
}

int32 UUIClassButton::GetClassIndex()
{
	return _iClassIndex;
}

void UUIClassButton::SetUseAltClass(uint8 alt)
{
	_yUseAltClass = alt;
}

void UUIClassButton::SetSelected(bool Select)
{
	_bSelected = Select;
}

void UUIClassButton::SetQualified(bool qual)
{
	_bQualified = qual;
}

bool UUIClassButton::IsQualified()
{
	if (_iClassIndex == -1)
	{
		return true;
	}
	return _bQualified;
}

bool UUIClassButton::IsActive()
{
	return _bEnabled && IsQualified();
}

bool UUIClassButton::IsSelected()
{
	return _bSelected;
}
