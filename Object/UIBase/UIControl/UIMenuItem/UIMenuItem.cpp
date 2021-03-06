// All the original content belonged to the US Army

#include "AA29/Object/UIBase/UIControl/UIMenuItem/UIMenuItem.h"
#include "AA29/Object/UIBase/UIControl/UIMenu/UIMenu.h"
#include "Engine/Canvas.h"

UUIMenuItem::UUIMenuItem()
{
	_bAllowScaling = false;
}

void UUIMenuItem::Destroyed()
{
	Super::Destroyed();
	cNextItem = nullptr;
	cPrevItem = nullptr;
	cParentMenu = nullptr;
	_Texture = nullptr;
	_sndOver = nullptr;
	_sndClick = nullptr;
}
void UUIMenuItem::CreateTexture()
{
	if (_Texture == nullptr)
	{
		//_Texture = Texture(DynamicLoadObject(sTexture, Class'Texture'));
	}
}
void UUIMenuItem::SetSounds(USoundBase* sOver, USoundBase* sClick)
{
	_sndOver = sOver;
	_sndClick = sClick;
}
void UUIMenuItem::MouseMove(int32 mX, int32 mY)
{

	if (mX >= _ScaledPos.X && mX <= _ScaledPos.X + _ScaledPos.W - 1 && mY >= _ScaledPos.Y && mY <= _ScaledPos.Y + _ScaledPos.H - 1)
	{
		if (bButtonDown)
		{
			iState = 2;
		}
		else
		{
			iState = 1;
			if (!bFirstOver)
			{
				bFirstOver = true;
				if (_sndOver != nullptr)
				{
					PlaySound(_sndOver);
				}
			}
		}
		//cParentMenu->cActiveItem = this;
	}
	else
	{
		iState = 0;
		bButtonDown = false;
		bFirstOver = false;
	}
}
bool UUIMenuItem::ProcessKeyEvent(int32 Key, int32 Action, float Delta)
{
	/*
	if (Key == 1)
	{
		if (cFrame->cMouse->iMouseX >= _ScaledPos.X && cFrame->cMouse->iMouseX <= _ScaledPos.X + _ScaledPos.W - 1 && cFrame->cMouse->iMouseY >= _ScaledPos.Y && cFrame->cMouse->iMouseY <= _ScaledPos.Y + _ScaledPos.H - 1)
		{
			if (Action == 1)
			{
				bButtonDown = true;
				iState = 2;
				if (_sndClick != nullptr)
				{
					PlaySound(_sndClick);
				}
			}
			if (Action == 3)
			{
				if (bButtonDown == true)
				{
					bButtonDown = false;
					iState = 1;
					cFrame->Notify(_iUIEvent);
				}
			}
			return true;
		}
		if (bButtonDown == true && Action == 3 && cFrame->cFocus == this)
		{
			bButtonDown = false;
			cFrame->SetFocus(nullptr);
			return true;
		}
	}
	*/
	return false;
}
void UUIMenuItem::Draw(UCanvas* Canvas)
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
		Canvas.DrawTile(_Texture, _ScaledPos.W, _ScaledPos.H, 0, iState * _ScaledPos.H, _Pos.W, _Pos.H);
		if (_bDebug)
		{
			Canvas.SetPos(_ScaledPos.X, _ScaledPos.Y);
			Canvas.DrawText("X: " + _ScaledPos.X + " Y: " + _ScaledPos.Y + " W: " + _ScaledPos.W + " H: " + _ScaledPos.H);
		}
	}
	else
	{
		if (_bDebug)
		{
			Canvas.SetPos(0, 0);
			Canvas.DrawText("UIBitmap - NO BITMAP " + sTexture);
		}
	}
	*/
}
void UUIMenuItem::SetParentMenu(UUIMenu* Parent)
{
	cParentMenu = Parent;
}
void UUIMenuItem::SetTextureString(FString tString)
{
	sTexture = tString;
}
void UUIMenuItem::SetTooltip(FString sToolTip)
{
	_sToolTip = sToolTip;
}
FString UUIMenuItem::GetToolTip()
{
	return _sToolTip;
}
void UUIMenuItem::PlaySound(USoundBase* pSound)
{
}
