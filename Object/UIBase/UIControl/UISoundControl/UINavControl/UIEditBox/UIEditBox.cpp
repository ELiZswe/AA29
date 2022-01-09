// All the original content belonged to the US Army

#include "AA29/Object/UIBase/UIControl/UISoundControl/UINavControl/UIEditBox/UIEditBox.h"
#include "AA29/Object/UIBase/UIFrame/UIFrame.h"

UUIEditBox::UUIEditBox()
{

}

void UUIEditBox::Destroyed()
{
	Super::Destroyed();
	_BorderTexture = nullptr;
	_BackTexture = nullptr;
}

void UUIEditBox::ProcessParams()
{
	if (_iParams == 1)
	{
		_bSecret = true;
		SetLabel(_sLabel);
	}
}
void UUIEditBox::MouseMove(int32 mX, int32 mY)
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
		cFrame.SetMouseOver(this);
	}
	else
	{
		_iState = 0;
		_bButtonDown = false;
	}
	*/
}
bool UUIEditBox::KeyType(int32 Key)
{
	/*
	if (_bEdit == true)
	{
		switch(Key)
		{
				case 9:
					return false;
					break;
				case 13:
					_bEdit = false;
					cFrame.SetFocus(None);
					return true;
					break;
				case 8:
					Backspace();
					break;
				default:
					if (Key >= 32 && Key < 256)
					{
						Insert(Key);
						return true;
					}
		}
		return true;
	}
	*/
	return false;
}
bool UUIEditBox::ProcessKeyEvent(int32 Key, int32 Action, float Delta)
{
	/*
	if (!_bEnabled)
	{
		return false;
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
				if (_bButtonDown == true)
				{
					_bButtonDown = false;
					_iState = 1;
					cFrame.SetFocus(this);
				}
			}
			return true;
		}
		else
		{
			if (Action == 1)
			{
				cFrame.SetFocus(None);
				return false;
			}
		}
		if (_bButtonDown == True && Action == 3 && cFrame.cFocus == this)
		{
			_bButtonDown = false;
			cFrame.SetFocus(None);
			return true;
		}
	}
	if (cFrame._cMouseOver == this)
	{
		if (Action == 3 && Key == 13)
		{
			if (_bEdit)
			{
				cFrame.SetFocus(None);
				_bEdit = false;
				return true;
			}
			else
			{
				cFrame.SetFocus(this);
				_bEdit = true;
				return true;
			}
		}
	}
	if (_bEdit)
	{
		if (Key == 9)
		{
			return false;
		}
		return true;
	}
	*/
	return false;
}
bool UUIEditBox::Backspace()
{
	/*
	FString NewValue;
	if (CaretOffset == 0)
	{
		return false;
	}
	NewValue = Left(_sLabel, CaretOffset - 1) $ Mid(_sLabel, CaretOffset);
	CaretOffset--;
	SetLabel(NewValue);
	*/
	return true;
}
bool UUIEditBox::Insert(uint8 C)
{
	/*
	FString NewValue;
	FString cVal;
	cVal = Chr(C);
	NewValue = Left(_sLabel, CaretOffset) $ cVal $ Mid(_sLabel, CaretOffset);
	if (Len(NewValue) > MaxLength)
	{
		return false;
	}
	if (Len(cVal) == 1)
	{
		CaretOffset++;
	}
	SetLabel(NewValue);
	*/
	return true;
}
FString UUIEditBox::GetLowerCase(FString upper)
{
	FString Lower="";
	/*
	switch(upper)
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
void UUIEditBox::Focus(bool bFocus)
{
	/*
	Log("UIEditBox::Focus(" $ bFocus $ ")");
	_bFocus = bFocus;
	if (_bFocus)
	{
		_bEdit = true;
		CaretOffset = Len(_sLabel);
		Log("UIEditBox::Focus CaretOffset=" $ CaretOffset);
	}
	else
	{
		_bEdit = false;
		_bShowCaret = false;
	}
	*/
}
void UUIEditBox::Draw(UCanvas* Canvas)
{
	/*
	local Font temp_font;
	local Object.Color OldColor;
	if (!_bEnabled)
	{
		return;
	}
	if (cFrame._cMouseOver == this)
	{
		_iState = 1;
	}
	else
	{
		_bButtonDown = false;
		_bEdit = false;
	}
	OldColor = Canvas.DrawColor;
	temp_font = Canvas.Font;
	Canvas.Font = cFrame.Fonts[2];
	if (_bEdit)
	{
		if (GetLastDrawTime() > _fLastDrawTime + 0.3 || GetLastDrawTime() < _fLastDrawTime)
		{
			_fLastDrawTime = GetLastDrawTime();
			_bShowCaret = !_bShowCaret;
		}
	}
	if (_iState == 1)
	{
		if (_bEdit)
		{
			Canvas.SetDrawColor(0, 255, 0);
		}
		else
		{
			Canvas.SetDrawColor(255, 255, 255);
			_bShowCaret = false;
		}
	}
	else
	{
		Canvas.SetDrawColor(196, 190, 141);
		_bShowCaret = false;
	}
	Canvas.SetPos(_ScaledPos.X + 6, _ScaledPos.Y + 6);
	if (_bSecret)
	{
		if (_bShowCaret)
		{
			Canvas.DrawText(_sSecret $ "|");
		}
		else
		{
			Canvas.DrawText(_sSecret);
		}
	}
	else
	{
		if (_bShowCaret)
		{
			Canvas.DrawText(_sLabel $ "|");
		}
		else
		{
			Canvas.DrawText(_sLabel);
		}
	}
	Canvas.Font = temp_font;
	Canvas.DrawColor = OldColor;
	*/
}

float UUIEditBox::GetLastDrawTime()
{
	return cFrame->GetLastDrawTime();
}

void UUIEditBox::SetLabel(FString Label)
{
	/*
	int32 i;
	_sLabel = Label;
	if (_bSecret)
	{
		_sSecret = "";
		for (i = 0; i < Len(_sLabel); i++)
		{
			_sSecret = _sSecret $ "*";
		}
	}
	*/
}
FString UUIEditBox::GetLabel()
{
	return _sLabel;
}
void UUIEditBox::SetMaxLength(int32 Len)
{
	MaxLength = Len;
}
