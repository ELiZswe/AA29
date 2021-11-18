// All the original content belonged to the US Army


#include "AA29/Object/UIBase/UIControl/UISoundControl/UINavControl/UITextButton/UITextButtonSize/UITextButtonSize.h"

UUITextButtonSize::UUITextButtonSize()
{

}


void UUITextButtonSize::Draw(UCanvas* Canvas)
{
	/*
	local Font temp_font;
	local int old_style;
	local Object.Color OldColor;
	if (_bLabelChanged)
	{
		ScaleControl(Canvas);
	}
	if (!_bEnabled)
	{
		Return;
	}
	old_style = Canvas.Style;
	Canvas.Style = 1;
	if (cFrame._cMouseOver == Self)
	{
		_iState = 1;
	}
	OldColor.R = Canvas.DrawColor.R;
	OldColor.G = Canvas.DrawColor.G;
	OldColor.B = Canvas.DrawColor.B;
	if (_iParams == 0)
	{
		Canvas.SetDrawColor(196, 190, 141);
	}
	else
	{
		if (_iState == 1)
		{
			Canvas.SetDrawColor(255, 255, 255);
		}
		else
		{
			Canvas.SetDrawColor(196, 190, 141);
		}
	}
	temp_font = Canvas.Font;
	Canvas.Font = cFrame.Fonts[_iSize];
	Canvas.SetPos(_iLabelX, _iLabelY);
	Canvas.DrawText(_sLabel);
	Canvas.Font = temp_font;
	Canvas.SetDrawColor(OldColor.R, OldColor.G, OldColor.B);
	Canvas.Style = old_style;
	*/
}
void UUITextButtonSize::CreateTexture()
{
	//_tSelected = Texture(DynamicLoadObject("T_AA2_UI.menu.hud_menu_greenlight", Class'Texture'));
}
void UUITextButtonSize::ScaleControl(UCanvas* Canvas)
{
	/*
	local Font temp_font;
	local float Xsize;
	local float Ysize;
	ScaleControl(Canvas);
	temp_font = Canvas.Font;
	Canvas.Font = cFrame.Fonts[_iSize];
	Canvas.TextSize(_sLabel, Xsize, Ysize);
	_Pos.W = Xsize;
	_Pos.H = Ysize;
	if (_bAllowScaling)
	{
		_ScaledPos.X = _Pos.X * cFrame.fScaleX + cFrame.offset.X;
		_ScaledPos.Y = _Pos.Y * cFrame.fScaleY + cFrame.offset.Y;
		_ScaledPos.W = _Pos.W * cFrame.fScaleX;
		_ScaledPos.H = _Pos.H * cFrame.fScaleY;
	}
	else
	{
		_ScaledPos.X = _Pos.X + cFrame.offset.X;
		_ScaledPos.Y = _Pos.Y + cFrame.offset.Y;
		_ScaledPos.W = _Pos.W;
		_ScaledPos.H = _Pos.H;
	}
	_iLabelX = _ScaledPos.X;
	_iLabelY = _ScaledPos.Y;
	Canvas.Font = temp_font;
	_bLabelChanged = False;
	*/
}
void UUITextButtonSize::SetSize(int32 Size)
{
	_bLabelChanged = true;
	_iSize = Size;
}
