// All the original content belonged to the US Army


#include "AA29/Object/UIBase/UIControl/UIHUDBaseDisplay/HUDCrosshair/HUDCrosshair.h"

UHUDCrosshair::UHUDCrosshair()
{
	iCrosshairIndex = 1;
	//_tCrosshair(0) = Texture'T_AA2_UI.HUD.hud_crosshair_01'
	//_tCrosshair(1) = Texture'T_AA2_UI.HUD.hud_crosshair_02'
	//_tCrosshair(2) = Texture'T_AA2_UI.HUD.hud_crosshair_03'
	//_tCrosshair(3) = Texture'T_AA2_UI.HUD.hud_crosshair_04'
	//_tCrosshair(4) = Texture'T_AA2_UI.HUD.hud_crosshair_05'
	//_tCrosshair(5) = Texture'T_AA2_UI.HUD.hud_crosshair_06'
	//_tCrosshair(6) = Texture'T_AA2_UI.HUD.hud_crosshair_07'
}

//const kMaxCrosshairIndex = 6;
//const kFadeTime = 0.6;
//const kTargetPosnY = 560;
//const kHealthIconX = 400;
//const kHealthIconY = 520;
//const ACTIONTEXT_POSX = 0.50;
//const ACTIONTEXT_POSY = 0.85;
//const ACTIONTEXT_POSX_DRIVING = 0.68;
//const ACTIONTEXT_POSY_DRIVING = 0.835;
//const ACTIONICON_POSX = 0.50;
//const ACTIONICON_POSY = 0.80;
//const ACTIONICON_SIZE = 32;
//const ACTIONICON_HALFSIZE = 16;

void UHUDCrosshair::SetCrossHairColor(int32 NewColorID)
{
	ColorId = NewColorID;
}
void UHUDCrosshair::Destroyed()
{
	int32 i=0;
	Super::Destroyed();
	/*
	for (i = 0; i < 6; i++)
	{
		_tCrosshair[i] = nullptr;
	}
	*/
}
void UHUDCrosshair::Draw(UCanvas* Canvas)
{
	/*
	local int oldstyle;
	local Object.Color OldColor;
	local Object.Color C;
	local float ScaleX;
	local float ScaleY;
	local float _TextSizeX;
	local float _TextSizeY;
	if (Canvas == None || cFrame == None || cFrame.cActor == None || cFrame.cActor.Level == None || cFrame.cActor.bDeleteMe || cFrame.cActor.Level.bDeleteMe)
	{
		Return;
	}
	if (cFrame.cActor != None)
	{
		if (ActionText != "")
		{
			if (cFrame.cActor.IsA('CROWS_HMMWV'))
			{
				Canvas.TextSize(ActionText, _TextSizeX, _TextSizeY);
				Canvas.SetPos(Canvas.SizeX * 0.68 - _TextSizeX / 2, Canvas.SizeY * 0.835);
				Canvas.DrawText(ActionText);
			}
			else
			{
				Canvas.TextSize(ActionText, _TextSizeX, _TextSizeY);
				Canvas.SetPos(Canvas.SizeX * 0.5 - _TextSizeX / 2, Canvas.SizeY * 0.85);
				Canvas.DrawText(ActionText);
			}
		}
		if (ActionIcon != None)
		{
			ScaleX = 32 * cFrame.fScaleX;
			ScaleY = 32 * cFrame.fScaleY;
			Canvas.SetPos(Canvas.SizeX * 0.5 - ScaleX / 2, Canvas.SizeY * 0.8 - ScaleY / 2);
			Canvas.DrawTile(ActionIcon, ScaleX, ScaleY, 0, 0, ActionIcon.USize, ActionIcon.VSize);
		}
		if (AGP_Pawn(cFrame.cActor) != None)
		{
			OldColor = Canvas.DrawColor;
			oldstyle = Canvas.Style;
			Switch(ColorId)
			{
					case 1:
						C.G = 255;
						break;
					case 2:
						C.R = 255;
						break;
					default:
						C.G = 255;
						C.R = 255;
						break;
			}
			Canvas.Style = 6;
			Canvas.DrawColor = C;
			Canvas.DrawColor.A = AGP_HUD(cFrame.cHUD).HUDColor.A;
			if (AGP_Pawn(cFrame.cActor).ShouldDrawCrosshair())
			{
				if (_tCrosshair[iCrosshairIndex] != None)
				{
					Canvas.SetPos(_ScaledPos.X, _ScaledPos.Y);
					Canvas.DrawTile(_tCrosshair[iCrosshairIndex], _ScaledPos.W, _ScaledPos.H, 0, 0, _Pos.W, _Pos.H);
				}
			}
			Canvas.Style = oldstyle;
			Canvas.DrawColor = OldColor;
		}
	}
	*/
}
void UHUDCrosshair::SetColorID(int32 i)
{
	ColorId = i;
}
void UHUDCrosshair::SetCrosshair(int32 C)
{
	/*
	if (C < 0 || C > 6)
	{
		Return;
	}
	iCrosshairIndex = C;
	PrivateSet("humancontroller hudcrosshair " $ iCrosshairIndex);
	*/
}
void UHUDCrosshair::NextCrosshair()
{
	/*
	iCrosshairIndex++;
	if (iCrosshairIndex > 6)
	{
		iCrosshairIndex = 0;
	}
	PrivateSet("humancontroller hudcrosshair " $ iCrosshairIndex);
	*/
}

