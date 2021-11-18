// All the original content belonged to the US Army


#include "AA29/Object/UIBase/UIControl/UIRolloverBitmapButtonB/UIRolloverBitmapButtonB.h"

UUIRolloverBitmapButtonB::UUIRolloverBitmapButtonB()
{

}


void UUIRolloverBitmapButtonB::Destroyed()
{
	Super::Destroyed();
	_Texture = nullptr;
}
void UUIRolloverBitmapButtonB::MouseMove(int32 mX, int32 mY)
{
	/*
	if (mX >= _ScaledPos.X && mX <= _ScaledPos.X + _ScaledPos.W - 1 && mY >= _ScaledPos.Y && mY <= _ScaledPos.Y + _ScaledPos.H - 1)
	{
		iState = 1;
	}
	else
	{
		iState = 0;
		_bButtonDown = False;
	}
	*/
}
bool UUIRolloverBitmapButtonB::ProcessKeyEvent(int32 Key, int32 Action, float Delta)
{
	/*
	if (Key == 1)
	{
		if (cFrame.cMouse.iMouseX >= _ScaledPos.X && cFrame.cMouse.iMouseX <= _ScaledPos.X + _ScaledPos.W - 1 && cFrame.cMouse.iMouseY >= _ScaledPos.Y && cFrame.cMouse.iMouseY <= _ScaledPos.Y + _ScaledPos.H - 1)
		{
			if (Action == 1)
			{
				_bButtonDown = true;
			}
			if (Action == 3)
			{
				if (_bButtonDown == True)
				{
					_bButtonDown = False;
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
void UUIRolloverBitmapButtonB::Draw(UCanvas* Canvas)
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
		Canvas.DrawTile(_Texture, _ScaledPos.W, _ScaledPos.H, 0, iState * _iTexDim.H, _iTexDim.W, _iTexDim.H);
		if (_bDebug)
		{
			Canvas.SetPos(_ScaledPos.X, _ScaledPos.Y);
			Canvas.DrawText("X: " $ _ScaledPos.X $ " Y: " $ _ScaledPos.Y $ " W: " $ _ScaledPos.W $ " H: " $ _ScaledPos.H);
		}
	}
	*/
}
void UUIRolloverBitmapButtonB::SetTextureDimensions(FPosition dim)
{
	_iTexDim.X = dim.X;
	_iTexDim.Y = dim.Y;
	_iTexDim.W = dim.W;
	_iTexDim.H = dim.H;
}
void UUIRolloverBitmapButtonB::ScaleControl(UCanvas* Canvas)
{
	/*
	_ScaledPos.X = _Pos.X * Canvas.SizeX * 1280 / 1280 * 1024;
	_ScaledPos.Y = _Pos.Y * Canvas.SizeY * 1024 / 1024 * 768;
	_ScaledPos.W = _Pos.W * Canvas.SizeX * 1280 / 1280 * 1024;
	_ScaledPos.H = _Pos.H * Canvas.SizeY * 1024 / 1024 * 768;
	*/
}
void UUIRolloverBitmapButtonB::SetTexture(UMaterialInstance* Tex)
{
	_Texture = Tex;
}
