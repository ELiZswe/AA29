// All the original content belonged to the US Army

#include "AA29/Object/UIBase/UIControl/UIScrollbar/UIScrollbarH/UIScrollbarH.h"

UUIScrollbarH::UUIScrollbarH()
{

}

void UUIScrollbarH::SizeThumb(float percentage)
{
	/*
	if (percentage > 1)
	{
		percentage = 1;
	}
	_iThumbSize = percentage * _ScaledPos.W;
	_iScaledThumbSize = _iThumbSize * cFrame->fScaleX;
	*/
}
void UUIScrollbarH::ScaleControl(UCanvas* Canvas)
{
	/*
	ScaleControl(Canvas);
	ClippingRegion.X = _ScaledPos.X;
	ClippingRegion.Y = _ScaledPos.Y;
	ClippingRegion.W = _ScaledPos.W;
	ClippingRegion.H = _ScaledPos.H;
	_iScaledThumbPos = cFrame->fScaleX * _iThumbPos;
	_iScaledThumbSize = cFrame->fScaleX * _iThumbSize;
	*/
}
void UUIScrollbarH::MouseMove(int32 mX, int32 mY)
{
	/*
	if (_bButtonDown == true)
	{
		if (cFrame->cMouse->iMouseX >= _ScaledPos.X && cFrame->cMouse->iMouseX <= _ScaledPos.X + _ScaledPos.W - 1 && cFrame->cMouse->iMouseY >= _ScaledPos.Y && cFrame->cMouse->iMouseY <= _ScaledPos.Y + _ScaledPos.H - 1)
		{
			_iScaledThumbPos = cFrame->cMouse->iMouseX - _ScaledPos.X - _iMouseDragOffset;
			if (_iScaledThumbPos > _ScaledPos.W - _iScaledThumbSize)
			{
				_iScaledThumbPos = _ScaledPos.W - _iScaledThumbSize;
				_iMouseDragOffset = cFrame->cMouse->iMouseX - _ScaledPos.X + _iScaledThumbPos;
			}
			if (_iScaledThumbPos <= 0)
			{
				_iScaledThumbPos = 0;
				_iMouseDragOffset = cFrame->cMouse->iMouseX - _ScaledPos.X;
			}
			_iThumbPos = _iScaledThumbPos / cFrame->fScaleX;
		}
	}
	*/
}

bool UUIScrollbarH::ProcessKeyEvent(int32 Key, int32 Action, float Delta)
{
	/*
	if (Key == 1)
	{
		if (cFrame->cMouse->iMouseX >= _ScaledPos.X && cFrame->cMouse->iMouseX <= _ScaledPos.X + _ScaledPos.W - 1 && cFrame->cMouse->iMouseY >= _ScaledPos.Y && cFrame->cMouse->iMouseY <= _ScaledPos.Y + _ScaledPos.H - 1)
		{
			if (Action == 1)
			{
				if (cFrame->cMouse->iMouseX >= _ScaledPos.X + _iScaledThumbPos && cFrame->cMouse->iMouseX <= _ScaledPos.X + _iScaledThumbPos + _iScaledThumbSize)
				{
					_iMouseDragOffset = cFrame->cMouse->iMouseX - _ScaledPos.X + _iScaledThumbPos;
				}
				else
				{
					_iScaledThumbPos = cFrame->cMouse->iMouseX - _ScaledPos.X;
					if (_iScaledThumbPos > _ScaledPos.W - _iScaledThumbSize - 1)
					{
						_iScaledThumbPos = _ScaledPos.W - _iScaledThumbSize - 1;
					}
					_iThumbPos = _iScaledThumbPos / cFrame->fScaleX;
					_iMouseDragOffset = 0;
				}
			}
			if (Action == 1)
			{
				_bButtonDown = true;
				cFrame->SetFocus(this);
			}
			if (Action == 3)
			{
				_bButtonDown = false;
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
void UUIScrollbarH::Draw(UCanvas* Canvas)
{
	/*
	if (_bDebug)
	{
		Canvas.DrawText("_BackTex = " + _BackTex);
	}
	if (_BackTex != nullptr)
	{
		Canvas.SetPos(_ScaledPos.X, _ScaledPos.Y);
		Canvas.DrawTile(_BackTex, _ScaledPos.W, _ScaledPos.H, 0, 0, _Pos.W, _Pos.H);
	}
	if (_ThumbTex != nullptr)
	{
		Canvas.SetPos(_ScaledPos.X + _iScaledThumbPos, _ScaledPos.Y);
		Canvas.DrawTile(_ThumbTex, _iScaledThumbSize, _ScaledPos.H, 0, 0, _Pos.W, _Pos.H);
	}
	*/
}
