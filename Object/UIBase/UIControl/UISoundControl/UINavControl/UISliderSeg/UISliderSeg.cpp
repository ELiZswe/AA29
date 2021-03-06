// All the original content belonged to the US Army

#include "AA29/Object/UIBase/UIControl/UISoundControl/UINavControl/UISliderSeg/UISliderSeg.h"
#include "AA29/Object/UIBase/UIFrame/UIFrame.h"
#include "AA29/Object/UIBase/UIScreen/UIScreen.h"
#include "Engine/Canvas.h"

UUISliderSeg::UUISliderSeg()
{
	_sVideoLevel.SetNum(9);
	_iThumbSize = 30;
}

void UUISliderSeg::Create(UUIFrame* frame, UUIScreen* screen, int32 pID, int32 pUIEvent, int32 pParams)
{
	Super::Create(frame, screen, pID, pUIEvent, pParams);
	_sVideoLevel = {"UltraLow", "VeryLow", "Low", "Lower", "Normal", "Higher", "High", "VeryHigh", "UltraHigh"};
}
void UUISliderSeg::Destroyed()
{
	Super::Destroyed();
	_Texture = nullptr;
}
void UUISliderSeg::MouseMove(int32 mX, int32 mY)
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
bool UUISliderSeg::ProcessKeyEvent(int32 Key, int32 Action, float Delta)
{
	/*
	if (Key == 37 && Action == 1)
	{
		if (cFrame->_cMouseOver == this)
		{
			Dec();
			UpdateValue();
			return true;
		}
	}
	if (Key == 39 && Action == 1)
	{
		if (cFrame->_cMouseOver == this)
		{
			Inc();
			UpdateValue();
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
void UUISliderSeg::Draw(UCanvas* Canvas)
{
	int32 oldstyle = 0;
	FColor OldColor = FColor(0,0,0,0);
	if (_bDebug)
	{
		//Canvas.DrawText("_Texture = " + _Texture);
	}
	if (cFrame->_cMouseOver == this)
	{
		_iState = 1;
	}
	/*
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
	Canvas.SetPos(364 + cFrame->offset.X, _ScaledPos.Y - 2);
	if (_iParams == 0)
	{
		Canvas.DrawText(_sVideoLevel[_iCurrSegment]);
	}
	Canvas.DrawColor = OldColor;
	Canvas.Style = oldstyle;
	*/
}
void UUISliderSeg::SetTexture(FString Tex)
{
	if (_Texture == nullptr)
	{
		//_Texture = Texture(DynamicLoadObject(Tex, Class'Texture'));
		//Log("UISlider::SetTexture(" + Tex + ") failed!");
	}
}

void UUISliderSeg::SetTexDimBack(FPosition dim)
{
	_TexDimBack.X = dim.X;
	_TexDimBack.Y = dim.Y;
	_TexDimBack.W = dim.W;
	_TexDimBack.H = dim.H;
}

void UUISliderSeg::SetTexDimThumb(FPosition dim)
{
	_TexDimThumb.X = dim.X;
	_TexDimThumb.Y = dim.Y;
	_TexDimThumb.W = dim.W;
	_TexDimThumb.H = dim.H;
	_iThumbSize = _TexDimThumb.W;
}

void UUISliderSeg::SetLabel(FString Label)
{
	_sLabel = Label;
}

void UUISliderSeg::Inc()
{
	if (_iThumbPos < 244)
	{
		_iThumbPos++;
	}
}

void UUISliderSeg::Dec()
{
	if (_iThumbPos > 0)
	{
		_iThumbPos--;
	}
}

void UUISliderSeg::SetClassName(FString ClassName)
{
	_sClassName = ClassName;
}

void UUISliderSeg::SetPropertyName(FString PropName)
{
	_sPropertyName = PropName;
}

void UUISliderSeg::Refresh()
{
	FString Status = "";
	/*
	if (cFrame != nullptr && cFrame->cHUD != nullptr && cFrame->cHUD.PlayerOwner != nullptr)
	{
		Status = cFrame->cHUD.PlayerOwner.ConsoleCommand("get " + _sClassName + " " + _sPropertyName);
		SetVideoLevelString(Status);
	}
	else
	{
		Log("cFrame->cHUD.PlayerOwner == nullptr");
	}
	*/
}

void UUISliderSeg::Accept()
{
	/*
	if (cFrame != nullptr && cFrame->cHUD != nullptr && cFrame->cHUD.PlayerOwner != nullptr)
	{
		if (_iParams == 0)
		{
			PrivateSet(_sClassName + " " + _sPropertyName + " " + _sVideoLevel[_iCurrSegment]);
		}
	}
	*/
}

void UUISliderSeg::UpdateValue()
{
	UpdatePosition(_iThumbPos);
}

int32 UUISliderSeg::GetCurrentSegment()
{
	return _iCurrSegment;
}

void UUISliderSeg::SetCurrentSegment(int32 seg)
{
	/*
	if (seg >= 0 && seg < _iNumSegments)
	{
		_iCurrSegment = seg;
	}
	*/
}
void UUISliderSeg::SetNumSegments(int32 seg)
{
	/*
	if (seg >= 0)
	{
		_iNumSegments = seg;
		_iMaxSegment = seg - 1;
		_iSegSize = 244 / _iMaxSegment;
	}
	UpdatePosition(_iThumbPos);
	*/
}
void UUISliderSeg::UpdatePosition(int32 pos)
{
	/*
	int32 NewPos;
	NewPos = pos / _iSegSize * _iSegSize;
	if (pos - NewPos > _iSegSize / 2)
	{
		NewPos += _iSegSize;
	}
	if (NewPos > 244)
	{
		NewPos = 244;
	}
	SetCurrentSegment(NewPos / _iSegSize);
	_iThumbPos = NewPos;
	*/
}
FString UUISliderSeg::GetVideoLevelString()
{
	return _sVideoLevel[_iCurrSegment];
}
int32 UUISliderSeg::GetVideoLevelInt()
{
	return _iCurrSegment - 4;
}
void UUISliderSeg::SetVideoLevelString(FString sLevel)
{
	/*
	int32 i = 0;
	i = 0;
	if (i < 9)
	{
		if (sLevel == _sVideoLevel[i])
		{
			SetVideoLevelInt(i - 4);
		}
		else
		{
			i++;
		}
	}
	*/
}
void UUISliderSeg::SetVideoLevelInt(int32 iLevel)
{
	//UpdatePosition(iLevel + 4 * _iSegSize);
}
