// All the original content belonged to the US Army

#include "AA29/Object/UIBase/UIControl/UISoundControl/UINavControl/UIConsole/UIConsole.h"
#include "AA29/Object/UIBase/UIFrame/UIFrame.h"
#include "AA29/Object/UIBase/UIControl/UIMouse/UIMouse.h"

UUIConsole::UUIConsole()
{

}

void UUIConsole::MouseMove(int32 mX, int32 mY)
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
			if (!_bFirstOver)
			{
				_bFirstOver = true;
			}
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
		_bFirstOver = false;
	}
}

bool UUIConsole::ProcessKeyEvent(int32 Key, int32 Action, float Delta)
{
	int32 pos = 0;
	if (!_bEnabled)
	{
		return false;
	}
	if (Key == 13)
	{
		if (cFrame->_cMouseOver == this)
		{
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
	if (Key == 236 && Action == 3)
	{
		if (cFrame->cMouse->iMouseX >= _ScaledPos.X && cFrame->cMouse->iMouseX <= _ScaledPos.X + _ScaledPos.W - 1 && cFrame->cMouse->iMouseY >= _ScaledPos.Y && cFrame->cMouse->iMouseY <= _ScaledPos.Y + _ScaledPos.H - 1)
		{
			pos = cFrame->GetGameSpyPos();
			cFrame->UpdateGameSpyPos(pos - 1);
			return true;
		}
	}
	if (Key == 237 && Action == 3)
	{
		if (cFrame->cMouse->iMouseX >= _ScaledPos.X && cFrame->cMouse->iMouseX <= _ScaledPos.X + _ScaledPos.W - 1 && cFrame->cMouse->iMouseY >= _ScaledPos.Y && cFrame->cMouse->iMouseY <= _ScaledPos.Y + _ScaledPos.H - 1)
		{
			pos = cFrame->GetGameSpyPos();
			cFrame->UpdateGameSpyPos(pos + 1);
			return true;
		}
	}
	return false;
}
void UUIConsole::Draw(UCanvas* Canvas)
{
	UFont* temp_font = nullptr;
	int32 oldclipx = 0;
	int32 oldClipY = 0;
	int32 old_style = 0;
	FColor OldColor = FColor(0,0,0,0);
	UConsole* Console = nullptr;
	/*
	if (!_bEnabled)
	{
		return;
	}
	Console = cFrame->cHUD.PlayerConsole;
	if (Console == nullptr)
	{
		return;
	}
	old_style = Canvas.Style;
	Canvas.Style = 1;
	OldColor.R = Canvas.DrawColor.R;
	OldColor.G = Canvas.DrawColor.G;
	OldColor.B = Canvas.DrawColor.B;
	temp_font = Canvas.Font;
	Canvas.Font = cFrame->Fonts[8];
	if (Console.bTyping)
	{
		oldclipx = Canvas.ClipX;
		oldClipY = Canvas.ClipY;
		Canvas.SetClip(_ScaledPos.X + _ScaledPos.W, _ScaledPos.Y + _ScaledPos.H);
		Canvas.SetPos(_ScaledPos.X, _ScaledPos.Y);
		Canvas.DrawTextClipped("(>" @ Console.TypedStr + "_", false);
		Canvas.SetClip(oldclipx, oldClipY);
	}
	Canvas.Font = temp_font;
	Canvas.SetDrawColor(OldColor.R, OldColor.G, OldColor.B);
	Canvas.Style = old_style;
	*/
}
