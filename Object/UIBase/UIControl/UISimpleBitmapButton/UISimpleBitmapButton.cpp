// All the original content belonged to the US Army

#include "AA29/Object/UIBase/UIControl/UISimpleBitmapButton/UISimpleBitmapButton.h"

UUISimpleBitmapButton::UUISimpleBitmapButton()
{

}

void UUISimpleBitmapButton::Destroyed()
{
	Super::Destroyed();
	_Texture = nullptr;
}
void UUISimpleBitmapButton::MouseMove(int32 mX, int32 mY)
{
	/*
	if (mX >= _ScaledPos.X && mX <= _ScaledPos.X + _ScaledPos.W - 1 && mY >= _ScaledPos.Y && mY <= _ScaledPos.Y + _ScaledPos.H - 1)
	{
		iState = 1;
		cFrame->SetMouseOver(this);
	}
	else
	{
		iState = 0;
		_bButtonDown = false;
	}
	*/
}
bool UUISimpleBitmapButton::ProcessKeyEvent(int32 Key, int32 Action, float Delta)
{
	/*
	if (Key == 1)
	{
		if (cFrame->cMouse->iMouseX >= _ScaledPos.X && cFrame->cMouse->iMouseX <= _ScaledPos.X + _ScaledPos.W - 1 && cFrame->cMouse->iMouseY >= _ScaledPos.Y && cFrame->cMouse->iMouseY <= _ScaledPos.Y + _ScaledPos.H - 1)
		{
			if (Action == 1)
			{
				_bButtonDown = true;
			}
			if (Action == 3)
			{
				if (_bButtonDown == true)
				{
					_bButtonDown = false;
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
	*/
	return false;
}
void UUISimpleBitmapButton::Draw(UCanvas* Canvas)
{
	/*
	if (_bDebug)
	{
		Canvas.SetPos(0, 0);
		Canvas.DrawText("_Texture = " + _Texture);
	}
	if (_Texture != nullptr)
	{
		Canvas.SetPos(_ScaledPos.X, _ScaledPos.Y);
		Canvas.DrawTile(_Texture, _ScaledPos.W, _ScaledPos.H, 0, 0, _Pos.W, _Pos.H);
		if (_bDebug)
		{
			Canvas.SetPos(_ScaledPos.X, _ScaledPos.Y);
			Canvas.DrawText("X: " + _ScaledPos.X + " Y: " + _ScaledPos.Y + " W: " + _ScaledPos.W + " H: " + _ScaledPos.H);
		}
	}
	*/
}
void UUISimpleBitmapButton::SetTexture(UMaterialInstance* Tex)
{
	_Texture = Tex;
}
