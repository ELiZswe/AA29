// All the original content belonged to the US Army


#include "AA29/Object/UIBase/UIControl/UIBorder/UIBorderButton/UIBorderButton.h"

UUIBorderButton::UUIBorderButton()
{

}
void UUIBorderButton::Destroyed()
{
	Super::Destroyed();
	_Texture3 = nullptr;
}

void UUIBorderButton::MouseMove(int32 mX, int32 mY)
{
	/*
	if (!_bEnabled)
	{
		return;
	}
	if (((mX >= _ScaledPos.X) && (mX <= ((_ScaledPos.X + _ScaledPos.W) - 1))) && ((mY >= _ScaledPos.Y) && (mY <= ((_ScaledPos.Y + _ScaledPos.H) - 1))))
	{
		if (_bButtonDown)
		{
			_iState = 2;
		}
		else
		{
			_iState = 1;
		}
		if (!cFrame.SetMouseOver(Self))
		{
			_iState = 0;
		}
	}
	else
	{
		_iState = 0;
		_bButtonDown = false;
	}
	*/
}

bool UUIBorderButton::ProcessKeyEvent(int32 Key, int32 Action, float Delta)
{
	/*
	if (!_bEnabled)
	{
		return false;
	}
	if (Key == 13)
	{
		if (cFrame._cMouseOver == Self)
		{
			cFrame.Notify(_iUIEvent);
			return true;
		}
	}
	if (Key == 1)
	{
		if (((cFrame.cMouse.iMouseX >= _ScaledPos.X) && (cFrame.cMouse.iMouseX <= ((_ScaledPos.X + _ScaledPos.W) - 1))) && ((cFrame.cMouse.iMouseY >= _ScaledPos.Y) && (cFrame.cMouse.iMouseY <= ((_ScaledPos.Y + _ScaledPos.H) - 1))))
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
					cFrame.Notify(_iUIEvent);
				}
			}
			return true;
		}
		if (((_bButtonDown == true) && (Action == 3)) && (cFrame.cFocus == Self))
		{
			_bButtonDown = false;
			cFrame.SetFocus(None);
			return true;
		}
	}
	*/
	return false;
}

void UUIBorderButton::Draw(UCanvas* Canvas)
{
	/*
	local Font temp_font;
	int32 old_style = 0;
	FColor OldColor = FColor(0, 0, 0, 0);
	if (!_bEnabled)
	{
		return;
	}
	if (_bDebug)
	{
		Canvas.DrawText("_Texture = " $ string(_Texture));
	}
	old_style = Canvas.Style;
	if (_iParams == 0)
	{
		Canvas.Style = ERenderStyle.STY_Normal;
	}
	else
	{
		Canvas.Style = ERenderStyle.STY_Alpha;
	}
	if (cFrame._cMouseOver == Self)
	{
		_iState = 1;
	}
	if (_iState != 1)
	{
		Canvas.SetPos(float(_ScaledPos.X), float(_ScaledPos.Y));
		if (_Texture3 != None)
		{
			Canvas.DrawTile(_Texture3, float(_ScaledPos.W), float(_ScaledPos.H), float(_iTexDim.X), float(_iTexDim.Y), float(_iTexDim.W), float(_iTexDim.H));
		}
	}
	if (_Texture != None)
	{
		Canvas.SetPos(float(_BorderLeft.X), float(_BorderLeft.Y));
		Canvas.DrawTile(_Texture, float(_BorderLeft.W), float(_BorderLeft.H), float(_iTexDim.X), float(_iTexDim.Y), float(_iTexDim.W), float(_iTexDim.H));
		Canvas.SetPos(float(_BorderRight.X), float(_BorderRight.Y));
		Canvas.DrawTile(_Texture, float(_BorderRight.W), float(_BorderRight.H), float(_iTexDim.X), float(_iTexDim.Y), float(_iTexDim.W), float(_iTexDim.H));
		Canvas.SetPos(float(_BorderTop.X), float(_BorderTop.Y));
		Canvas.DrawTile(_Texture, float(_BorderTop.W), float(_BorderTop.H), float(_iTexDim.X), float(_iTexDim.Y), float(_iTexDim.W), float(_iTexDim.H));
		Canvas.SetPos(float(_BorderBottom.X), float(_BorderBottom.Y));
		Canvas.DrawTile(_Texture, float(_BorderBottom.W), float(_BorderBottom.H), float(_iTexDim.X), float(_iTexDim.Y), float(_iTexDim.W), float(_iTexDim.H));
	}
	OldColor.R = Canvas.DrawColor.R;
	OldColor.G = Canvas.DrawColor.G;
	OldColor.B = Canvas.DrawColor.B;
	if (_iState == 1)
	{
		old_style = Canvas.Style;
		Canvas.Style = ERenderStyle.STY_Normal;
		Canvas.SetPos(float(_ScaledPos.X), float(_ScaledPos.Y));
		if (_Texture2 != None)
		{
			Canvas.DrawTile(_Texture2, float(_ScaledPos.W), float(_ScaledPos.H), float(_iTexDim.X), float(_iTexDim.Y), float(_iTexDim.W), float(_iTexDim.H));
		}
		Canvas.Style = byte(old_style);
		Canvas.SetDrawColor(0, 0, 0);
	}
	else
	{
		Canvas.SetDrawColor(255, 255, 0);
	}
	temp_font = Canvas.Font;
	Canvas.Font = cFrame.GetProperSizeFont(Canvas);
	Canvas.SetPos(float(_iLabelX), float(_iLabelY));
	Canvas.DrawText(_sLabel);
	Canvas.Font = temp_font;
	Canvas.SetDrawColor(OldColor.R, OldColor.G, OldColor.B);
	Canvas.Style = byte(old_style);
	*/
}

void UUIBorderButton::SetTextureDimensions(FPosition dim)
{
	/*
	_iTexDim.X = dim.X;
	_iTexDim.Y = dim.Y;
	_iTexDim.W = dim.W;
	_iTexDim.H = dim.H;
	*/
}

void UUIBorderButton::ScaleControl(UCanvas* Canvas)
{
	/*
	local Font temp_font;
	float Xsize = 0;
	float Ysize = 0;
	Super::ScaleControl(Canvas);
	temp_font = Canvas.Font;
	Canvas.Font = cFrame.GetProperSizeFont(Canvas);
	Canvas.TextSize(_sLabel, Xsize, Ysize);
	_iLabelX = int((float(_ScaledPos.X) + ((float(_ScaledPos.W) - Xsize) / 2)));
	_iLabelY = int((float(_ScaledPos.Y) + ((float(_ScaledPos.H) - Ysize) / 2)));
	Canvas.Font = temp_font;
	*/
}

void UUIBorderButton::SetLabel(FString Label)
{
	_sLabel = Label;
}

void UUIBorderButton::SetTexture3(UMaterialInstance* Tex)
{
	_Texture3 = Tex;
}