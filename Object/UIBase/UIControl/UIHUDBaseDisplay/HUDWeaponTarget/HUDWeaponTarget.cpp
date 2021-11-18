// All the original content belonged to the US Army


#include "AA29/Object/UIBase/UIControl/UIHUDBaseDisplay/HUDWeaponTarget/HUDWeaponTarget.h"


UHUDWeaponTarget::UHUDWeaponTarget()
{
	//_tBreacherTarget = Texture'T_AA2_UI.HUD.ui_hud_breachdoor'
	//_tJavelinTarget = Texture'T_AA2_UI.HUD.hud_ammo_javelin'
	//_tDemolitionTarget = Texture'T_AA2_UI.HUD.ui_hud_destructable'
	//_tObjectiveActiveTarget = Texture'T_AA2_UI.HUD.ui_hud_carriable'
	//_tObjectiveInactiveTarget = Texture'T_AA2_UI.HUD.ui_hud_noncarriable'
	//_tObjectiveTarget = Texture'T_AAO_UI.HUD.ui_hud_objective'
	//_tESSObjective = Texture'T_AA2_ES2.ES2_Objects.ES2_HUD_NotePad'
}


//const kFadeTime = 0.2;
//const kTargetIconSizeX = 32;
//const kTargetIconSizeY = 32;
//const kTextOffsetY = 6;

void UHUDWeaponTarget::Destroyed()
{
	_tBreacherTarget = nullptr;
	_tDemolitionTarget = nullptr;
}
void UHUDWeaponTarget::SetTarget()
{
	DisplayType = EDisplayType::DTYPE_Active;
}
void UHUDWeaponTarget::NoTarget()
{
	if (DisplayType == EDisplayType::DTYPE_Active)
	{
		DisplayType = EDisplayType::DTYPE_Fading;
		//LostTargetTime = cFrame.cActor.Level.TimeSeconds;
	}
}
void UHUDWeaponTarget::Draw(UCanvas* Canvas)
{
	/*
	local int oldstyle;
	local Object.Color OldColor;
	if (Canvas == None || cFrame == None || cFrame.cActor == None || cFrame.cActor.Level == None || cFrame.cActor.bDeleteMe || cFrame.cActor.Level.bDeleteMe)
	{
		Return;
	}
	if (DisplayType == 2)
	{
		if (cFrame.cActor.Level.TimeSeconds > LostTargetTime + 0.2)
		{
			DisplayType = 0;
			bRecentTarget = False;
		}
	}
	if (DisplayType != 0)
	{
		OldColor = Canvas.DrawColor;
		oldstyle = Canvas.Style;
		DrawTargetIcons(Canvas);
		Canvas.DrawColor = OldColor;
		Canvas.Style = oldstyle;
	}
	*/
}
void UHUDWeaponTarget::GetFadeValue()
{
	/*
	local int rvalue;
	rvalue = LostTargetTime + 0.2 - cFrame.cActor.Level.TimeSeconds * cFrame.cHUD.HUDColor.A / 0.2;
	Return Max(rvalue, 1);
	*/
}
void UHUDWeaponTarget::DrawTargetIcons(UCanvas* Canvas)
{
	/*
	local float XL;
	local float YL;
	if (AGP_Pawn(cFrame.cActor).bActiveObjectiveTarget)
	{
		CaptionText = "OBJECTIVE";
		Switch(AGP_Pawn(cFrame.cActor).TargetObjLetter)
		{
				case 0:
					CaptionText @ = "A";
					break;
				case 1:
					CaptionText @ = "B";
					break;
				case 2:
					CaptionText @ = "C";
					break;
				case 3:
					CaptionText @ = "D";
					break;
				case 4:
					CaptionText @ = "E";
					break;
				case 5:
					CaptionText @ = "F";
					break;
				case 6:
					CaptionText @ = "G";
					break;
				case 7:
					CaptionText @ = "H";
					break;
				default:
		}
		IconImage = _tObjectiveTarget;
		bRecentTarget = true;
		AGP_Pawn(cFrame.cActor).bActiveObjectiveTarget = False;
	}
	else
	{
		if (AGP_Pawn(cFrame.cActor).bActiveDemolitionTarget)
		{
			CaptionText = "DESTRUCTABLE";
			IconImage = _tDemolitionTarget;
			bRecentTarget = true;
			AGP_Pawn(cFrame.cActor).bActiveDemolitionTarget = False;
		}
		else
		{
			if (AGP_Pawn(cFrame.cActor).bActiveJavelinTarget)
			{
				CaptionText = "TARGETABLE";
				IconImage = _tJavelinTarget;
				bRecentTarget = true;
				AGP_Pawn(cFrame.cActor).bActiveJavelinTarget = False;
			}
			else
			{
				if (AGP_Pawn(cFrame.cActor).bActiveBreacherTarget)
				{
					CaptionText = "BREACHABLE";
					IconImage = _tBreacherTarget;
					bRecentTarget = true;
					AGP_Pawn(cFrame.cActor).bActiveBreacherTarget = False;
				}
				else
				{
					if (AGP_Pawn(cFrame.cActor).bActiveObjPickupTarget)
					{
						CaptionText = "CARRIABLE";
						IconImage = _tObjectiveActiveTarget;
						bRecentTarget = true;
						AGP_Pawn(cFrame.cActor).bActiveObjPickupTarget = False;
					}
					else
					{
						if (AGP_Pawn(cFrame.cActor).bInactiveObjPickupTarget)
						{
							CaptionText = "NONCARRIABLE";
							IconImage = _tObjectiveInactiveTarget;
							bRecentTarget = true;
							AGP_Pawn(cFrame.cActor).bInactiveObjPickupTarget = False;
						}
						else
						{
							if (AGP_Pawn(cFrame.cActor).bActiveCoopESSTarget)
							{
								CaptionText = AGP_Pawn(cFrame.cActor).stTargetDescription;
								IconImage = _tESSObjective;
								bRecentTarget = true;
								AGP_Pawn(cFrame.cActor).bActiveCoopESSTarget = False;
							}
						}
					}
				}
			}
		}
	}
	if (bRecentTarget)
	{
		Canvas.DrawColor = cFrame.cHUD.HUDColor;
		if (DisplayType == 2)
		{
			Canvas.DrawColor.A = GetFadeValue();
		}
		else
		{
			Canvas.DrawColor.A = cFrame.cHUD.HUDColor.A;
		}
		Canvas.Style = 6;
		Canvas.SetPos(_ScaledPos.X - 32 * cFrame.fScaleX / 2, _ScaledPos.Y);
		Canvas.DrawTile(IconImage, 32 * cFrame.fScaleX, 32 * cFrame.fScaleY, 0, 0, IconImage.MaterialUSize(), IconImage.MaterialVSize());
		Canvas.TextSize(CaptionText, XL, YL);
		Canvas.SetPos(_ScaledPos.X - XL / 2, _ScaledPos.Y + cFrame.fScaleY * 32 + 6);
		Canvas.DrawText(CaptionText, True);
	}
	*/	
}