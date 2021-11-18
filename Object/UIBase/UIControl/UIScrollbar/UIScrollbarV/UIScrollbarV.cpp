// All the original content belonged to the US Army


#include "AA29/Object/UIBase/UIControl/UIScrollbar/UIScrollbarV/UIScrollbarV.h"

UUIScrollbarV::UUIScrollbarV()
{
	_iTrackSizeX = 60;
	_iTrackSizeY = 40;
}

void UUIScrollbarV::SizeThumb(float percentage)
{
	/*
	if (percentage > 1)
	{
		percentage = 1;
	}
	_iThumbSize = percentage * _Pos.H;
	_iScaledThumbSize = percentage * _ScaledPos.H;
	if (_iThumbPos + _iThumbSize > _Pos.H)
	{
		_iThumbPos = _Pos.H - _iThumbSize;
		if (_bAllowScaling)
		{
			_iScaledThumbPos = cFrame.fScaleY * _iThumbPos;
		}
		else
		{
			_iScaledThumbPos = _iThumbPos;
		}
		if (cParentControl != None)
		{
			NotifyParent(_iScaledThumbPos / _ScaledPos.H);
		}
	}
	*/
}
void UUIScrollbarV::ScaleControl(UCanvas* Canvas)
{
	/*
	ScaleControl(Canvas);
	ClippingRegion.X = _ScaledPos.X;
	ClippingRegion.Y = _ScaledPos.Y;
	ClippingRegion.W = _ScaledPos.W;
	ClippingRegion.H = _ScaledPos.H;
	if (_bAllowScaling)
	{
		_iThumbPos = 0;
		_iScaledThumbPos = cFrame.fScaleY * _iThumbPos;
		_iScaledThumbSize = cFrame.fScaleY * _iThumbSize;
		_iScaledTrackSizeX = cFrame.fScaleX * _iTrackSizeX;
		_iScaledTrackSizeY = cFrame.fScaleY * _iTrackSizeY;
	}
	else
	{
		_iThumbPos = 0;
		_iScaledThumbPos = _iThumbPos;
		_iScaledThumbSize = _iThumbSize;
		_iScaledTrackSizeX = _iTrackSizeX;
		_iScaledTrackSizeY = _iTrackSizeY;
	}
	*/
}
void UUIScrollbarV::MouseMove(int32 mX, int32 mY)
{
	/*
	if (!_bEnabled)
	{
		Return;
	}
	if (_bButtonDown == True)
	{
		if (cFrame.cMouse.iMouseX >= _ScaledPos.X - _iScaledTrackSizeX && cFrame.cMouse.iMouseX <= _ScaledPos.X + _ScaledPos.W - 1 + _iScaledTrackSizeX && cFrame.cMouse.iMouseY >= _ScaledPos.Y - _iScaledTrackSizeY && cFrame.cMouse.iMouseY <= _ScaledPos.Y + _ScaledPos.H - 1 + _iScaledTrackSizeY)
		{
			if (cFrame.cMouse.iMouseY < _ScaledPos.Y || cFrame.cMouse.iMouseY > _ScaledPos.Y + _ScaledPos.H - 1)
			{
				_iScaledThumbPos = _iSavedPos;
				if (_bAllowScaling)
				{
					_iThumbPos = _iScaledThumbPos / cFrame.fScaleY;
				}
				else
				{
					_iThumbPos = _iScaledThumbPos;
				}
				Return;
			}
			_iScaledThumbPos = cFrame.cMouse.iMouseY - _ScaledPos.Y - _iMouseDragOffset;
			if (_iScaledThumbPos > _ScaledPos.H - _iScaledThumbSize)
			{
				_iScaledThumbPos = _ScaledPos.H - _iScaledThumbSize;
				_iMouseDragOffset = cFrame.cMouse.iMouseY - _ScaledPos.Y + _iScaledThumbPos;
			}
			if (_iScaledThumbPos <= 0)
			{
				_iScaledThumbPos = 0;
				_iMouseDragOffset = cFrame.cMouse.iMouseY - _ScaledPos.Y;
			}
			if (_bAllowScaling)
			{
				_iThumbPos = _iScaledThumbPos / cFrame.fScaleY;
			}
			else
			{
				_iThumbPos = _iScaledThumbPos;
			}
			_iSavedPos = _iScaledThumbPos;
			if (cParentControl != None)
			{
				NotifyParent(_iThumbPos / _Pos.H);
			}
		}
		else
		{
			_iScaledThumbPos = _iScaledStartDragThumbPos;
			if (_bAllowScaling)
			{
				_iThumbPos = _iScaledThumbPos / cFrame.fScaleY;
			}
			else
			{
				_iThumbPos = _iScaledThumbPos;
			}
			if (cParentControl != None)
			{
				NotifyParent(_iThumbPos / _Pos.H);
			}
		}
	}
	*/
}
bool UUIScrollbarV::ProcessKeyEvent(int32 Key, int32 Action, float Delta)
{
	/*
	if (!_bEnabled)
	{
		Return False;
	}
	if (Key == 1)
	{
		if (cFrame.cMouse.iMouseX >= _ScaledPos.X && cFrame.cMouse.iMouseX <= _ScaledPos.X + _ScaledPos.W - 1 && cFrame.cMouse.iMouseY >= _ScaledPos.Y && cFrame.cMouse.iMouseY <= _ScaledPos.Y + _ScaledPos.H - 1)
		{
			if (Action == 1)
			{
				if (cFrame.cMouse.iMouseY >= _ScaledPos.Y + _iScaledThumbPos && cFrame.cMouse.iMouseY <= _ScaledPos.Y + _iScaledThumbPos + _iScaledThumbSize)
				{
					_iMouseDragOffset = cFrame.cMouse.iMouseY - _ScaledPos.Y + _iScaledThumbPos;
					_iScaledStartDragThumbPos = _iScaledThumbPos;
				}
				else
				{
					_iScaledThumbPos = cFrame.cMouse.iMouseY - _ScaledPos.Y;
					if (_iScaledThumbPos > _ScaledPos.H - _iScaledThumbSize - 1)
					{
						_iScaledThumbPos = _ScaledPos.H - _iScaledThumbSize - 1;
					}
					if (_bAllowScaling)
					{
						_iThumbPos = _iScaledThumbPos / cFrame.fScaleY;
					}
					else
					{
						_iThumbPos = _iScaledThumbPos;
					}
					_iMouseDragOffset = 0;
					_iScaledStartDragThumbPos = _iScaledThumbPos;
				}
			}
			if (Action == 1)
			{
				_bButtonDown = true;
				cFrame.SetFocus(Self);
			}
			if (Action == 3)
			{
				_bButtonDown = False;
				_iMouseDragOffset = 0;
			}
			Return True;
		}
		if (_bButtonDown == True && Action == 3 && cFrame.cFocus == Self)
		{
			_bButtonDown = False;
			_iMouseDragOffset = 0;
			cFrame.SetFocus(None);
			Return True;
		}
	}
	*/
	return false;
}
void UUIScrollbarV::Draw(UCanvas* Canvas)
{
	/*
	if (!_bEnabled)
	{
		Return;
	}
	if (_bDebug)
	{
		Canvas.DrawText("_BackTex = " $ _BackTex);
	}
	if (_BackTex != None)
	{
		Canvas.SetPos(_ScaledPos.X, _ScaledPos.Y);
		Canvas.DrawTile(_BackTex, _ScaledPos.W, _ScaledPos.H, 0, 0, _iImageWidth, _iImageHeight);
	}
	if (_ThumbTex != None)
	{
		Canvas.SetPos(_ScaledPos.X, _ScaledPos.Y + _iScaledThumbPos);
		Canvas.DrawTile(_ThumbTex, _ScaledPos.W, _iScaledThumbSize, 0, 0, _iImageWidth, _iImageHeight);
		if (_bDebug)
		{
			Canvas.SetPos(_ScaledPos.X, _iScaledThumbPos);
			Canvas.DrawText("Pos: " $ _iScaledThumbPos $ " Size: " $ _iScaledThumbSize $ "Y:" $ _ScaledPos.Y $ " H:" $ _ScaledPos.H);
		}
	}
	*/
}

