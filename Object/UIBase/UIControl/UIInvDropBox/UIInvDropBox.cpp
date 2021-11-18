// All the original content belonged to the US Army


#include "AA29/Object/UIBase/UIControl/UIInvDropBox/UIInvDropBox.h"

UUIInvDropBox::UUIInvDropBox()
{

}

void UUIInvDropBox::Destroyed()
{
	Super::Destroyed();
	_Texture = nullptr;
	_TexSel = nullptr;
	_BorderTexture = nullptr;
}
void UUIInvDropBox::MouseMove(int32 mX, int32 mY)
{
	/*
	if (mX >= _ScaledPos.X && mX <= _ScaledPos.X + _ScaledPos.W - 1 && mY >= _ScaledPos.Y && mY <= _ScaledPos.Y + _ScaledPos.H - 1)
	{
		cFrame.SetMouseOver(Self);
	}
	*/
}
void UUIInvDropBox::ProcessKeyEvent(int32 Key, int32 Action, float Delta)
{
	/*
	local Inventory Item;
	local Inventory held_item;
	if (Key == 1)
	{
		if (cFrame.cMouse.iMouseX >= _ScaledPos.X && cFrame.cMouse.iMouseX <= _ScaledPos.X + _ScaledPos.W - 1 && cFrame.cMouse.iMouseY >= _ScaledPos.Y && cFrame.cMouse.iMouseY <= _ScaledPos.Y + _ScaledPos.H - 1)
		{
			if (Action == 1)
			{
				bButtonDown = true;
			}
			if (Action == 3)
			{
				if (bButtonDown == True)
				{
					bButtonDown = False;
					Item = None;
					held_item = cFrame.GetHeldItem();
					cFrame.GetHeldContainer().DeleteItem(held_item);
					cFrame.DropHeldItem();
				}
			}
			Return True;
		}
		if (bButtonDown == True && Action == 3)
		{
			bButtonDown = False;
			Return True;
		}
	}
	Return False;
	*/
}
void UUIInvDropBox::Draw(UCanvas* Canvas)
{
	/*
	if (_bDebug)
	{
		Canvas.DrawText("_Texture = " $ _Texture);
	}
	if (_Texture != None)
	{
		Canvas.SetPos(_ScaledPos.X, _ScaledPos.Y);
		Canvas.DrawTile(_Texture, _ScaledPos.W, _ScaledPos.H, 0, 0, _Pos.W, _Pos.H);
	}
	if (_BorderTexture != None)
	{
		Canvas.SetPos(_BorderLeft.X, _BorderLeft.Y);
		Canvas.DrawTile(_BorderTexture, _BorderLeft.W, _BorderLeft.H, _iTexDim.X, _iTexDim.Y, _iTexDim.W, _iTexDim.H);
		Canvas.SetPos(_BorderRight.X, _BorderRight.Y);
		Canvas.DrawTile(_BorderTexture, _BorderRight.W, _BorderRight.H, _iTexDim.X, _iTexDim.Y, _iTexDim.W, _iTexDim.H);
		Canvas.SetPos(_BorderTop.X, _BorderTop.Y);
		Canvas.DrawTile(_BorderTexture, _BorderTop.W, _BorderTop.H, _iTexDim.X, _iTexDim.Y, _iTexDim.W, _iTexDim.H);
		Canvas.SetPos(_BorderBottom.X, _BorderBottom.Y);
		Canvas.DrawTile(_BorderTexture, _BorderBottom.W, _BorderBottom.H, _iTexDim.X, _iTexDim.Y, _iTexDim.W, _iTexDim.H);
	}
	*/
}
void UUIInvDropBox::SetTexture(UMaterialInstance* Tex)
{
	_Texture = Tex;
}
void UUIInvDropBox::SetTexture2(UMaterialInstance* Tex)
{
	_TexSel = Tex;
}
void UUIInvDropBox::SetBorderTexture(UMaterialInstance* Tex)
{
	_BorderTexture = Tex;
}
void UUIInvDropBox::SetTextureDimensions(FPosition dim)
{
	_iTexDim.X = dim.X;
	_iTexDim.Y = dim.Y;
	_iTexDim.W = dim.W;
	_iTexDim.H = dim.H;
}
void UUIInvDropBox::ScaleControl(UCanvas* Canvas)
{
	/*
	Super::ScaleControl(Canvas);
	_BorderLeft.X = _ScaledPos.X;
	_BorderLeft.Y = _ScaledPos.Y;
	_BorderLeft.W = 1;
	_BorderLeft.H = _ScaledPos.H;
	_BorderRight.X = _ScaledPos.X + _ScaledPos.W - 1;
	_BorderRight.Y = _ScaledPos.Y;
	_BorderRight.W = 1;
	_BorderRight.H = _ScaledPos.H;
	_BorderTop.X = _ScaledPos.X;
	_BorderTop.Y = _ScaledPos.Y;
	_BorderTop.W = _ScaledPos.W;
	_BorderTop.H = 1;
	_BorderBottom.X = _ScaledPos.X;
	_BorderBottom.Y = _ScaledPos.Y + _ScaledPos.H - 1;
	_BorderBottom.W = _ScaledPos.W;
	_BorderBottom.H = 1;
	_BorderLeft.X--;
	_BorderLeft.Y--;
	_BorderLeft.H += 2;
	_BorderRight.X++;
	_BorderRight.Y--;
	_BorderRight.H += 2;
	_BorderTop.X--;
	_BorderTop.Y--;
	_BorderTop.W += 2;
	_BorderBottom.X--;
	_BorderBottom.Y++;
	_BorderBottom.W += 2;
	*/
}