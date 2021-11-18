// All the original content belonged to the US Army


#include "AA29/Object/UIBase/UIControl/UISoundControl/UIWebLinkButton/UIWebLinkButton.h"

UUIWebLinkButton::UUIWebLinkButton()
{
	_sOverSound = "S_AA2_UI.Generic.click2";
	_sClickSound = "S_AA2_Foley.Nightvision.NOD_off";
}


void UUIWebLinkButton::Destroyed()
{
	Super::Destroyed();
	_Texture = nullptr;
}

void UUIWebLinkButton::MouseMove(int32 mX, int32 mY)
{
	/*
	if (mX >= _ScaledPos.X && mX <= _ScaledPos.X + _ScaledPos.W - 1 && mY >= _ScaledPos.Y && mY <= _ScaledPos.Y + _ScaledPos.H - 1)
	{
		cFrame.SetMouseOver(Self);
		if (_bButtonDown)
		{
			iState = 1;
		}
		else
		{
			iState = 1;
			if (!_bFirstOver)
			{
				_bFirstOver = true;
				cFrame.PlayMenuSoundSpecific(_sMouseOver);
			}
		}
	}
	else
	{
		iState = 0;
		_bButtonDown = False;
		_bFirstOver = False;
	}
	*/
}
bool UUIWebLinkButton::ProcessKeyEvent(int32 Key, int32 Action, float Delta)
{
	/*
	if (Key == 1)
	{
		if (cFrame.cMouse.iMouseX >= _ScaledPos.X && cFrame.cMouse.iMouseX <= _ScaledPos.X + _ScaledPos.W - 1 && cFrame.cMouse.iMouseY >= _ScaledPos.Y && cFrame.cMouse.iMouseY <= _ScaledPos.Y + _ScaledPos.H - 1)
		{
			if (Action == 1)
			{
				_bButtonDown = true;
				iState = 1;
				cFrame.PlayMenuSoundSpecific(_sMouseClick);
			}
			if (Action == 3)
			{
				if (_bButtonDown == True)
				{
					_bButtonDown = False;
					iState = 1;
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

void UUIWebLinkButton::Draw(UCanvas* Canvas)
{
	/*
	local int oldstyle;
	if (_bDebug)
	{
		Canvas.SetPos(0, 0);
		Canvas.DrawText("_Texture = " $ _Texture);
	}
	oldstyle = Canvas.Style;
	if (_Texture != None)
	{
		Canvas.Style = 1;
		Canvas.SetPos(_ScaledPos.X, _ScaledPos.Y);
		Canvas.DrawTile(_Texture, _ScaledPos.W, _ScaledPos.H, _iTexDim.X, _iTexDim.Y + iState * _iTexDim.H, _iTexDim.W, _iTexDim.H);
		if (_bDebug)
		{
			Canvas.SetPos(_ScaledPos.X, _ScaledPos.Y);
			Canvas.DrawText("X: " $ _ScaledPos.X $ " Y: " $ _ScaledPos.Y $ " W: " $ _ScaledPos.W $ " H: " $ _ScaledPos.H);
		}
	}
	Canvas.Style = oldstyle;
	*/
}
void UUIWebLinkButton::SetTextureDimensions(FPosition dim)
{
	_iTexDim.X = dim.X;
	_iTexDim.Y = dim.Y;
	_iTexDim.W = dim.W;
	_iTexDim.H = dim.H;
}
void UUIWebLinkButton::SetTexture(FString Tex)
{
	if (_Texture == nullptr)
	{
		//_Texture = Texture(DynamicLoadObject(Tex, Class'Texture'));
		//Log("UIWebLinkButton::SetTexture(" $ Tex $ ") failed!");
	}
}