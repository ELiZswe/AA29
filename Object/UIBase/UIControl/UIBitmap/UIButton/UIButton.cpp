// All the original content belonged to the US Army


#include "AA29/Object/UIBase/UIControl/UIBitmap/UIButton/UIButton.h"


UUIButton::UUIButton()
{

}

bool UUIButton::ProcessKeyEvent(int32 Key, int32 Action, float Delta)
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
				_bButtonDown = False;
				cFrame.Notify(_iUIEvent);
			}
			Return True;
		}
		if (_bButtonDown == True && Action == 3)
		{
			_bButtonDown = False;
			Return True;
		}
	}
	*/
	return false;
}
void UUIButton::Draw(UCanvas* Canvas)
{
	/*
	if (_bDebug)
	{
		Canvas.DrawText("_Texture = " $ _Texture);
	}
	if (_Texture != None)
	{
		Canvas.SetPos(_ScaledPos.X, _ScaledPos.Y);
		if (_bButtonDown)
		{
			Canvas.DrawTile(_Texture, _ScaledPos.W, _ScaledPos.H, 0, _Pos.H, _Pos.W, _Pos.H);
		}
		else
		{
			Canvas.DrawTile(_Texture, _ScaledPos.W, _ScaledPos.H, 0, 0, _Pos.W, _Pos.H);
		}
	}
	*/
}