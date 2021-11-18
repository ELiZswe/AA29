// All the original content belonged to the US Army


#include "AA29/Object/UIBase/UIControl/UITextDisplay/UITextDisplay.h"

UUITextDisplay::UUITextDisplay()
{

}


void UUITextDisplay::MouseMove(int32 mX, int32 mY)
{
	return;
}
bool UUITextDisplay::ProcessKeyEvent(int32 Key, int32 Action, float Delta)
{
	return false;
}
void UUITextDisplay::Draw(UCanvas* Canvas)
{
	/*
	local Font temp_font;
	local Object.Color OldColor;
	if (_bLabelChanged)
	{
		ScaleControl(Canvas);
	}
	if (!_bEnabled)
	{
		Return;
	}
	temp_font = Canvas.Font;
	Canvas.Font = cFrame.Fonts[_iFontIndex];
	OldColor = Canvas.DrawColor;
	if (_iColorIndex == 0)
	{
		Canvas.SetDrawColor(196, 190, 141);
	}
	else
	{
		Canvas.SetDrawColor(168, 201, 156);
	}
	Canvas.SetPos(_iLabelX, _iLabelY);
	Canvas.DrawText(_sLabel);
	Canvas.DrawColor = OldColor;
	Canvas.Font = temp_font;
	*/
}
void UUITextDisplay::ScaleControl(UCanvas* Canvas)
{
	/*
	local Font temp_font;
	local float Xsize;
	local float Ysize;
	ScaleControl(Canvas);
	temp_font = Canvas.Font;
	Canvas.Font = cFrame.GetLargeFont();
	Canvas.TextSize(_sLabel, Xsize, Ysize);
	if (_iParams == 0)
	{
		_iLabelX = _ScaledPos.X + _ScaledPos.W - Xsize / 2;
		_iLabelY = _ScaledPos.Y + _ScaledPos.H - Ysize / 2;
		if (_iLabelX < _ScaledPos.X)
		{
			_iLabelX = _ScaledPos.X;
		}
		if (_iLabelY < _ScaledPos.Y)
		{
			_iLabelY = _ScaledPos.Y;
		}
	}
	else
	{
		_iLabelX = _ScaledPos.X;
		_iLabelY = _ScaledPos.Y;
	}
	Canvas.Font = temp_font;
	_bLabelChanged = False;
	*/
}
void UUITextDisplay::SetLabel(FString Label)
{
	_sLabel = Label;
	_bLabelChanged = true;
}
FString UUITextDisplay::GetLabel()
{
	return _sLabel;
}
void UUITextDisplay::SetColorIndex(int32 cindex)
{
	_iColorIndex = cindex;
}
void UUITextDisplay::SetFontIndex(int32 findex)
{
	_iFontIndex = findex;
}