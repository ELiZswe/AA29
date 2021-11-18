// All the original content belonged to the US Army


#include "AA29/Object/UIBase/UIControl/UIHUDBaseDisplay/HUDSupportBox/HUDSupportBox.h"

UHUDSupportBox::UHUDSupportBox()
{

}

void UHUDSupportBox::Destroyed()
{
	Super::Destroyed();
	_Texture = nullptr;
	_Texture2 = nullptr;
}
void UHUDSupportBox::Draw(UCanvas* Canvas)
{
	/*
	local int oldstyle;
	if (Canvas == None || cFrame == None || cFrame.cActor == None || cFrame.cActor.Level == None || cFrame.cActor.bDeleteMe || cFrame.cActor.Level.bDeleteMe)
	{
		Return;
	}
	if (cFrame.cActor != None)
	{
		if (AGP_Pawn(cFrame.cActor).IsSupported() && !AGP_Pawn(cFrame.cActor).Weapon.IsZoomed())
		{
			if (!_bSetSupported)
			{
				if (AGP_Pawn(cFrame.cActor).Weapon != None)
				{
					_Pos.W = AGP_Weapon(AGP_Pawn(cFrame.cActor).Weapon).rSupportedLimit.Yaw / 7;
					_Pos.H = AGP_Weapon(AGP_Pawn(cFrame.cActor).Weapon).rSupportedLimit.Pitch / 7;
					_Pos.X = Canvas.ClipX - _Pos.W / 2;
					_Pos.Y = Canvas.ClipY - _Pos.H / 2;
					ScaleControl(Canvas);
					_bSetSupported = true;
				}
			}
			_iXOffset = AGP_Pawn(cFrame.cActor).rBaseRotation.Yaw - AGP_Pawn(cFrame.cActor).Controller.Rotation.Yaw / 7 * 2 * cFrame.fScaleX;
			_iYOffset = AGP_Pawn(cFrame.cActor).Controller.Rotation.Pitch - AGP_Pawn(cFrame.cActor).rBaseRotation.Pitch / 7 * 2 * cFrame.fScaleY;
			if (_Texture != None)
			{
				oldstyle = Canvas.Style;
				Canvas.Style = 3;
				Canvas.SetPos(_BorderLeft.X + _iXOffset, _BorderLeft.Y + _iYOffset);
				Canvas.DrawTile(_Texture2, _BorderLeft.W, _BorderLeft.H, _iTexDim.X, _iTexDim.Y, _iTexDim.W, _iTexDim.H);
				Canvas.SetPos(_BorderRight.X + _iXOffset, _BorderRight.Y + _iYOffset);
				Canvas.DrawTile(_Texture2, _BorderRight.W, _BorderRight.H, _iTexDim.X, _iTexDim.Y, _iTexDim.W, _iTexDim.H);
				Canvas.SetPos(_BorderTop.X + _iXOffset, _BorderTop.Y + _iYOffset);
				Canvas.DrawTile(_Texture, _BorderTop.W, _BorderTop.H, _iTexDim.X, _iTexDim.Y, _iTexDim.W, _iTexDim.H);
				Canvas.SetPos(_BorderBottom.X + _iXOffset, _BorderBottom.Y + _iYOffset);
				Canvas.DrawTile(_Texture, _BorderBottom.W, _BorderBottom.H, _iTexDim.X, _iTexDim.Y, _iTexDim.W, _iTexDim.H);
				Canvas.Style = oldstyle;
			}
		}
		else
		{
			_bSetSupported = False;
		}
	}
	*/
}
void UHUDSupportBox::SetTextureDimensions(FPosition dim)
{
	_iTexDim.X = dim.X;
	_iTexDim.Y = dim.Y;
	_iTexDim.W = dim.W;
	_iTexDim.H = dim.H;
}
void UHUDSupportBox::ScaleControl(UCanvas* Canvas)
{
	/*
	ScaleControl(Canvas);
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
	*/
}
void UHUDSupportBox::SetTexture(UMaterialInstance* Tex)
{
	_Texture = Tex;
}
void UHUDSupportBox::SetTexture2(UMaterialInstance* Tex)
{
	_Texture2 = Tex;
}