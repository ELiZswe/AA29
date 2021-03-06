// All the original content belonged to the US Army

#include "AA29/Object/UIBase/UIControl/UISoundControl/UINavControl/UIEditBox/UIEditBox.h"
#include "AA29/Object/UIBase/UIFrame/UIFrame.h"
#include "AA29/Object/UIBase/UIControl/UIMouse/UIMouse.h"

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
		cFrame->SetMouseOver(this);
	}
	else
	{
		_iState = 0;
		_bButtonDown = false;
	}
}

bool UUIEditBox::KeyType(int32 Key)
{
	if (_bEdit == true)
	{
		switch(Key)
		{
			case 9:
				return false;
				break;
			case 13:
				_bEdit = false;
				cFrame->SetFocus(nullptr);
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
	return false;
}

bool UUIEditBox::ProcessKeyEvent(int32 Key, int32 Action, float Delta)
{
	if (!_bEnabled)
	{
		return false;
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
	if (cFrame->_cMouseOver == this)
	{
		if (Action == 3 && Key == 13)
		{
			if (_bEdit)
			{
				cFrame->SetFocus(nullptr);
				_bEdit = false;
				return true;
			}
			else
			{
				cFrame->SetFocus(this);
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
	return false;
}

bool UUIEditBox::Backspace()
{
	FString NewValue = "";
	if (CaretOffset == 0)
	{
		return false;
	}
	NewValue = _sLabel.Left(CaretOffset - 1) + _sLabel.Mid(CaretOffset);
	CaretOffset--;
	SetLabel(NewValue);
	return true;
}

bool UUIEditBox::Insert(uint8 C)
{
	FString NewValue = "";
	FString cVal = "";
	
	/*
	cVal = Chr(C);
	NewValue = Left(_sLabel, CaretOffset) + cVal + Mid(_sLabel, CaretOffset);
	*/
	if (NewValue.Len() > MaxLength)
	{
		return false;
	}
	if (cVal.Len() == 1)
	{
		CaretOffset++;
	}
	SetLabel(NewValue);
	return true;
}

FString UUIEditBox::GetLowerCase(FString upper)
{
	return upper.ToLower();
}

void UUIEditBox::Focus(bool bFocus)
{
	//Log("UIEditBox::Focus(" + bFocus + ")");
	_bFocus = bFocus;
	if (_bFocus)
	{
		_bEdit = true;
		CaretOffset = _sLabel.Len();
		//Log("UIEditBox::Focus CaretOffset=" + CaretOffset);
	}
	else
	{
		_bEdit = false;
		_bShowCaret = false;
	}
}

void UUIEditBox::Draw(UCanvas* Canvas)
{
	UFont* temp_font = nullptr;
	FColor OldColor = FColor(0,0,0,0);
	if (!_bEnabled)
	{
		return;
	}
	if (cFrame->_cMouseOver == this)
	{
		_iState = 1;
	}
	else
	{
		_bButtonDown = false;
		_bEdit = false;
	}
	//OldColor = Canvas->DrawColor;
	//temp_font = Canvas->Font;
	//Canvas->Font = cFrame->Fonts[2];
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
			//Canvas->SetDrawColor(0, 255, 0);
		}
		else
		{
			//Canvas->SetDrawColor(255, 255, 255);
			_bShowCaret = false;
		}
	}
	else
	{
		//Canvas->SetDrawColor(196, 190, 141);
		_bShowCaret = false;
	}
	//Canvas->SetPos(_ScaledPos.X + 6, _ScaledPos.Y + 6);
	if (_bSecret)
	{
		if (_bShowCaret)
		{
			//Canvas->DrawText(_sSecret + "|");
		}
		else
		{
			//Canvas->DrawText(_sSecret);
		}
	}
	else
	{
		if (_bShowCaret)
		{
			//Canvas->DrawText(_sLabel + "|");
		}
		else
		{
			//Canvas->DrawText(_sLabel);
		}
	}
	//Canvas->Font = temp_font;
	//Canvas->DrawColor = OldColor;
}

float UUIEditBox::GetLastDrawTime()
{
	return cFrame->GetLastDrawTime();
}

void UUIEditBox::SetLabel(FString Label)
{
	int32 i = 0;
	_sLabel = Label;
	if (_bSecret)
	{
		_sSecret = "";
		for (i = 0; i < _sLabel.Len(); i++)
		{
			_sSecret = _sSecret + "*";
		}
	}
}

FString UUIEditBox::GetLabel()
{
	return _sLabel;
}

void UUIEditBox::SetMaxLength(int32 Len)
{
	MaxLength = Len;
}
