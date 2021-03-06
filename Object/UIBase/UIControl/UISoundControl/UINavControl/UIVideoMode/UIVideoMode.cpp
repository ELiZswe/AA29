// All the original content belonged to the US Army

#include "AA29/Object/UIBase/UIControl/UISoundControl/UINavControl/UIVideoMode/UIVideoMode.h"
#include "AA29/Object/UIBase/UIFrame/UIFrame.h"
#include "AA29/Object/UIBase/UIControl/UIMouse/UIMouse.h"

UUIVideoMode::UUIVideoMode()
{

}

void UUIVideoMode::Destroyed()
{
	Super::Destroyed();
	_tVideoModes.Empty();
	_Texture = nullptr;
}

void UUIVideoMode::MouseMove(int32 mX, int32 mY)
{
	if (!_bEnabled)
	{
		return;
	}
	if (((mX >= _ScaledPos.X) && (mX <= ((_ScaledPos.X + _ScaledPos.W) - 1))) && ((mY >= _ScaledPos.Y) && (mY <= ((_ScaledPos.Y + _ScaledPos.H) - 1))))
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
		_bButtonDown2 = false;
		if (_bEdit)
		{
			_bEdit = false;
			cFrame->SetFocus(nullptr);
		}
	}
}

bool UUIVideoMode::ProcessKeyEvent(int32 Key, int32 Action, float Delta)
{
	if (!_bEnabled)
	{
		return false;
	}
	if ((Key == 37) && (Action == 1))
	{
		if (cFrame->_cMouseOver == this)
		{
			PrevMode();
			return true;
		}
	}
	if ((Key == 39) && (Action == 1))
	{
		if (cFrame->_cMouseOver == this)
		{
			NextMode();
			return true;
		}
	}
	if (Key == 1)
	{
		if (((cFrame->cMouse->iMouseX >= _ScaledPos.X) && (cFrame->cMouse->iMouseX <= ((_ScaledPos.X + _ScaledPos.W) - 1))) && ((cFrame->cMouse->iMouseY >= _ScaledPos.Y) && (cFrame->cMouse->iMouseY <= ((_ScaledPos.Y + _ScaledPos.H) - 1))))
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
					PrevMode();
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
		if (((_bButtonDown == true) && (Action == 3)) && (cFrame->cFocus == this))
		{
			_bButtonDown = false;
			_bButtonDown2 = false;
			cFrame->SetFocus(nullptr);
			return true;
		}
	}
	if (Key == 2)
	{
		if (((cFrame->cMouse->iMouseX >= _ScaledPos.X) && (cFrame->cMouse->iMouseX <= ((_ScaledPos.X + _ScaledPos.W) - 1))) && ((cFrame->cMouse->iMouseY >= _ScaledPos.Y) && (cFrame->cMouse->iMouseY <= ((_ScaledPos.Y + _ScaledPos.H) - 1))))
		{
			if (Action == 1)
			{
				_bButtonDown2 = true;
				_iState = 2;
			}
			if (Action == 3)
			{
				if (_bButtonDown2 == true)
				{
					_bButtonDown2 = false;
					_iState = 1;
					cFrame->SetFocus(this);
					NextMode();
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
		if (((_bButtonDown == true) && (Action == 3)) && (cFrame->cFocus == this))
		{
			_bButtonDown = false;
			_bButtonDown2 = false;
			cFrame->SetFocus(nullptr);
			return true;
		}
	}
	return false;
}

void UUIVideoMode::Draw(UCanvas* Canvas)
{
	UFont* oldfont = nullptr;
	int32 oldstyle = 0;
	FColor OldColor = FColor(0, 0, 0, 0);
	float XL = 0;
	float YL = 0;
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
	Canvas.Style = ERenderStyle.STY_Alpha;
	if (_bEdit)
	{
		Canvas.SetDrawColor(0, 255, 0);
	}
	else
	{
		Canvas.SetDrawColor(255, 255, 255);
	}
	if (_iState == 1)
	{
		Canvas.SetPos((200 + float(cFrame->offset.X)), float((_ScaledPos.Y + 7)));
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
	Canvas.SetPos((224 + float(cFrame->offset.X)), float((_ScaledPos.Y + 2)));
	Canvas.DrawText("Game Resolution");
	if (_sStringList.Num() > _iCurrMode)
	{
		Canvas.TextSize(_sStringList[_iCurrMode], XL, YL);
		Canvas.SetPos((float(_ScaledPos.X) + ((float(_ScaledPos.W) - XL) / 2)), (float(_ScaledPos.Y) + ((float(_ScaledPos.H) - YL) / 2)));
		Canvas.DrawText(_sStringList[_iCurrMode]);
	}
	Canvas.Style = uint8(oldstyle);
	Canvas.DrawColor = OldColor;
	Canvas.Font = oldfont;
	*/
}

void UUIVideoMode::AddMode(FString sMode)
{
	int32 new_index = 0;
	Ft_VideoMode videoMode;
	int32 XPos = 0;
	int32 X = 0;
	int32 Y = 0;
	new_index = _tVideoModes.Num();
	/*
	XPos = InStr(sMode, "x");
	X = int(Left(sMode, XPos));
	Y = int(Right(sMode, ((Len(sMode) - XPos) - 1)));
	if ((X < 640) || (Y < 480))
	{
		return;
	}
	*/
	_sStringList[new_index] = sMode;
	_tVideoModes[new_index] = videoMode;
	_tVideoModes[new_index].X = X;
	_tVideoModes[new_index].Y = Y;
}

void UUIVideoMode::Refresh()
{
	int32 currmode = 0;
	int32 modes = 0;
	int32 iNumModes = 0;
	FString sMode = "";
	FString sPrevMode = "";
	if (_bRefreshed)
	{
		SetCurrentMode();
	}
	else
	{
		/*
		iNumModes = cFrame->cHUD->PlayerConsole->GetNumVideoModes();
		if (iNumModes == 0)
		{
			return;
		}
		modes = cFrame->cHUD->PlayerConsole->GetNumVideoModes();
		for (currmode = 0; currmode < modes; currmode++)
		{
			sMode = cFrame->cHUD.PlayerConsole->GetVideoModeString(currmode);
			if ((sMode != "") && (sMode != sPrevMode))
			{
				AddMode(sMode);
				sPrevMode = sMode;
			}
		}
		_bRefreshed = true;
		SetCurrentMode();
		DumpModes();
		*/
	}
}

void UUIVideoMode::Accept()
{
	if (_sStringList.Num() > 0)
	{
		cFrame->SetResolution(_tVideoModes[_iCurrMode].X, _tVideoModes[_iCurrMode].Y);
	}
}

void UUIVideoMode::SetCurrentMode()
{
	int32 Len = 0;
	int32 curr = 0;
	bool bFound = false;
	Len = _tVideoModes.Num();
	for (curr = 0; curr < Len; curr++)
	{
		/*
		if ((_tVideoModes[curr].X == cFrame->GetDesiredX()) && (_tVideoModes[curr].Y == cFrame->GetDesiredY()))
		{
			_iCurrMode = curr;
			bFound = true;
		}
		*/
	}
	if (!bFound)
	{
		_iCurrMode = 0;
	}
}

void UUIVideoMode::DumpModes()
{
	int32 Len = 0;
	int32 curr = 0;
	Len = _tVideoModes.Num();
	for (curr = 0; curr < Len; curr++)
	{
	}
}

void UUIVideoMode::PrevMode()
{
	if (_iCurrMode > 0)
	{
		_iCurrMode--;
	}
}

void UUIVideoMode::NextMode()
{
	if (_iCurrMode < (_tVideoModes.Num() - 1))
	{
		_iCurrMode++;
	}
}

void UUIVideoMode::SetTexture(FString Tex)
{
	if (_Texture == nullptr)
	{
		//_Texture = Texture(DynamicLoadObject(Tex, Class'Texture'));
	}
	if (_Texture == nullptr)
	{
	}
}
