// All the original content belonged to the US Army


#include "AA29/Object/UIBase/UIControl/UIBorder/UIBorderButton/UIBorderButtonB/UIBorderButtonB.h"

UUIBorderButtonB::UUIBorderButtonB()
{

}

bool UUIBorderButtonB::ProcessKeyEvent(int32 Key, int32 Action, float Delta)
{
	/*
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
					if (_iLabelState == 0)
					{
						_iLabelState = 1;
						cFrame.Notify(_iUIEvent2);
					}
					else
					{
						_iLabelState = 0;
						cFrame.Notify(_iUIEvent);
					}
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

void UUIBorderButtonB::Draw(UCanvas* Canvas)
{
	/*
	local Font temp_font;
	int32 old_style = 0;
	if (_bDebug)
	{
		Canvas.DrawText("_Texture = " $ string(_Texture));
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
	if (_iState == 1)
	{
		old_style = Canvas.Style;
		Canvas.Style = ERenderStyle.STY_Translucent;
		Canvas.SetPos(float(_ScaledPos.X), float(_ScaledPos.Y));
		if (_Texture2 != None)
		{
			Canvas.DrawTile(_Texture2, float(_ScaledPos.W), float(_ScaledPos.H), float(_iTexDim.X), float(_iTexDim.Y), float(_iTexDim.W), float(_iTexDim.H));
		}
		Canvas.Style = byte(old_style);
	}
	temp_font = Canvas.Font;
	Canvas.Font = cFrame.GetProperSizeFont(Canvas);
	if (_iLabelState == 0)
	{
		Canvas.SetPos(float(_iLabelX), float(_iLabelY));
		Canvas.DrawText(_sLabel);
	}
	else
	{
		Canvas.SetPos(float(_iLabel2X), float(_iLabel2Y));
		Canvas.DrawText(_sLabel2);
	}
	Canvas.Font = temp_font;
	*/
}

void UUIBorderButtonB::ScaleControl(UCanvas* Canvas)
{
	/*
	local Font temp_font;
	float Xsize = 0;
	float Ysize = 0;
	Super::ScaleControl(Canvas);
	temp_font = Canvas.Font;
	Canvas.Font = cFrame.GetProperSizeFont(Canvas);
	Canvas.TextSize(_sLabel2, Xsize, Ysize);
	_iLabel2X = int((float(_ScaledPos.X) + ((float(_ScaledPos.W) - Xsize) / 2)));
	_iLabel2Y = int((float(_ScaledPos.Y) + ((float(_ScaledPos.H) - Ysize) / 2)));
	Canvas.Font = temp_font;
	*/
}

void UUIBorderButtonB::SetLabel2(FString Label)
{
	//_sLabel2 = Label;
}

void UUIBorderButtonB::SetEvent2(int32 event2)
{
	//_iUIEvent2 = event2;
}
