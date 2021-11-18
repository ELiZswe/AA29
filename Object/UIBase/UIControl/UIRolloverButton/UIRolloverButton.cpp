// All the original content belonged to the US Army


#include "AA29/Object/UIBase/UIControl/UIRolloverButton/UIRolloverButton.h"

UUIRolloverButton::UUIRolloverButton()
{

}


void UUIRolloverButton::Destroyed()
{
	Super::Destroyed();
	_Texture = nullptr;
}
void UUIRolloverButton::CreateTexture()
{
	if (_Texture == nullptr)
	{
		//_Texture = Texture(DynamicLoadObject(_sTexture, Class'Texture'));
	}
}
void UUIRolloverButton::SetSounds(USoundBase* sOver, USoundBase* sClick)
{
	_sndOver = sOver;
	_sndClick = sClick;
}
void UUIRolloverButton::MouseMove(int32 mX, int32 mY)
{
	/*
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
				if (_sndOver != None)
				{
					PlaySound(_sndOver);
				}
			}
		}
	}
	else
	{
		_iState = 0;
		_bButtonDown = False;
		_bFirstOver = False;
	}
	*/
}
bool UUIRolloverButton::ProcessKeyEvent(int32 Key, int32 Action, float Delta)
{
	/*
	if (Key == 1)
	{
		if (cFrame.cMouse.iMouseX >= _ScaledPos.X && cFrame.cMouse.iMouseX <= _ScaledPos.X + _ScaledPos.W - 1 && cFrame.cMouse.iMouseY >= _ScaledPos.Y && cFrame.cMouse.iMouseY <= _ScaledPos.Y + _ScaledPos.H - 1)
		{
			if (Action == 1)
			{
				_bButtonDown = true;
				_iState = 2;
				if (_sndClick != None)
				{
					PlaySound(_sndClick);
				}
			}
			if (Action == 3)
			{
				if (_bButtonDown == True)
				{
					_bButtonDown = False;
					_iState = 1;
					cFrame.Notify(_iUIEvent);
				}
			}
			Return True;
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
void UUIRolloverButton::Draw(UCanvas* Canvas)
{
	/*
	if (_bDebug)
	{
		Canvas.SetPos(0, 0);
		Canvas.DrawText("_Texture = " $ _Texture);
	}
	if (_Texture != None)
	{
		Canvas.SetPos(_ScaledPos.X, _ScaledPos.Y);
		Canvas.DrawTile(_Texture, _ScaledPos.W, _ScaledPos.H, 0, _iState * _Pos.H, _Pos.W, _Pos.H);
		if (_bDebug)
		{
			Canvas.SetPos(_ScaledPos.X, _ScaledPos.Y);
			Canvas.DrawText("X: " $ _ScaledPos.X $ " Y: " $ _ScaledPos.Y $ " W: " $ _ScaledPos.W $ " H: " $ _ScaledPos.H);
		}
	}
	else
	{
		if (_bDebug)
		{
			Canvas.SetPos(0, 0);
			Canvas.DrawText("UIBitmap - NO BITMAP " $ _sTexture);
		}
	}
	*/
}
void UUIRolloverButton::SetTextureString(FString tString)
{
	_sTexture = tString;
}
void UUIRolloverButton::PlaySound(USoundBase* pSound)
{
}
