// All the original content belonged to the US Army

#include "AA29/Object/UIBase/UIControl/UIHUDBaseDisplay/HUDWeaponTarget/HUDWeaponTarget.h"
#include "AA29/Object/UIBase/UIFrame/UIFrame.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "Engine/Canvas.h"

UHUDWeaponTarget::UHUDWeaponTarget()
{
	_tBreacherTarget = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/ui_hud_breachdoor_Mat.ui_hud_breachdoor_Mat'"), NULL, LOAD_None, NULL);
	_tJavelinTarget = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_ammo_javelin_Mat.hud_ammo_javelin_Mat'"), NULL, LOAD_None, NULL);
	_tDemolitionTarget = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/ui_hud_destructable_Mat.ui_hud_destructable_Mat'"), NULL, LOAD_None, NULL);
	_tObjectiveActiveTarget = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/ui_hud_carriable_Mat.ui_hud_carriable_Mat'"), NULL, LOAD_None, NULL);
	_tObjectiveInactiveTarget = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/ui_hud_noncarriable_Mat.ui_hud_noncarriable_Mat'"), NULL, LOAD_None, NULL);
	_tObjectiveTarget = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/HUD/ui_hud_objective_Mat.ui_hud_objective_Mat'"), NULL, LOAD_None, NULL);
	_tESSObjective = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_ES2/ES2_Objects/ES2_HUD_NotePad_Mat.ES2_HUD_NotePad_Mat'"), NULL, LOAD_None, NULL);
}


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
		//LostTargetTime = cFrame->cActor.GetWorld()->GetTimeSeconds();
	}
}
void UHUDWeaponTarget::Draw(UCanvas* Canvas)
{
	int32 oldstyle = 0;
	FColor OldColor = FColor(0,0,0);
	/*
	if (Canvas == nullptr || cFrame == nullptr || cFrame->cActor == nullptr || cFrame->cActor.Level == nullptr || cFrame->cActor.bDeleteMe || cFrame->cActor.Level.bDeleteMe)
	{
		return;
	}
	if (DisplayType == 2)
	{
		if (cFrame->cActor.GetWorld()->GetTimeSeconds() > LostTargetTime + 0.2)
		{
			DisplayType = 0;
			bRecentTarget = false;
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

uint8 UHUDWeaponTarget::GetFadeValue()
{
	int32 rvalue = 0;
	/*
	rvalue = LostTargetTime + 0.2 - cFrame->cActor.GetWorld()->GetTimeSeconds() * cFrame->cHUD.HUDColor.A / 0.2;
	return FMath::Max(rvalue, 1);
	*/
	return 0;    //FAKE   /ELiZ
}
void UHUDWeaponTarget::DrawTargetIcons(UCanvas* Canvas)
{
	float XL = 0;
	float YL = 0;
	if (Cast<AAGP_Pawn>(cFrame->cActor)->bActiveObjectiveTarget)
	{
		CaptionText = "OBJECTIVE";
		switch(Cast<AAGP_Pawn>(cFrame->cActor)->TargetObjLetter)
		{
			case 0:
				CaptionText += "A";
				break;
			case 1:
				CaptionText += "B";
				break;
			case 2:
				CaptionText += "C";
				break;
			case 3:
				CaptionText += "D";
				break;
			case 4:
				CaptionText += "E";
				break;
			case 5:
				CaptionText += "F";
				break;
			case 6:
				CaptionText += "G";
				break;
			case 7:
				CaptionText += "H";
				break;
			default:
				break;
		}
		IconImage = _tObjectiveTarget;
		bRecentTarget = true;
		Cast<AAGP_Pawn>(cFrame->cActor)->bActiveObjectiveTarget = false;
	}
	else
	{
		if (Cast<AAGP_Pawn>(cFrame->cActor)->bActiveDemolitionTarget)
		{
			CaptionText = "DESTRUCTABLE";
			IconImage = _tDemolitionTarget;
			bRecentTarget = true;
			Cast<AAGP_Pawn>(cFrame->cActor)->bActiveDemolitionTarget = false;
		}
		else
		{
			if (Cast<AAGP_Pawn>(cFrame->cActor)->bActiveJavelinTarget)
			{
				CaptionText = "TARGETABLE";
				IconImage = _tJavelinTarget;
				bRecentTarget = true;
				Cast<AAGP_Pawn>(cFrame->cActor)->bActiveJavelinTarget = false;
			}
			else
			{
				if (Cast<AAGP_Pawn>(cFrame->cActor)->bActiveBreacherTarget)
				{
					CaptionText = "BREACHABLE";
					IconImage = _tBreacherTarget;
					bRecentTarget = true;
					Cast<AAGP_Pawn>(cFrame->cActor)->bActiveBreacherTarget = false;
				}
				else
				{
					if (Cast<AAGP_Pawn>(cFrame->cActor)->bActiveObjPickupTarget)
					{
						CaptionText = "CARRIABLE";
						IconImage = _tObjectiveActiveTarget;
						bRecentTarget = true;
						Cast<AAGP_Pawn>(cFrame->cActor)->bActiveObjPickupTarget = false;
					}
					else
					{
						if (Cast<AAGP_Pawn>(cFrame->cActor)->bInactiveObjPickupTarget)
						{
							CaptionText = "NONCARRIABLE";
							IconImage = _tObjectiveInactiveTarget;
							bRecentTarget = true;
							Cast<AAGP_Pawn>(cFrame->cActor)->bInactiveObjPickupTarget = false;
						}
						else
						{
							if (Cast<AAGP_Pawn>(cFrame->cActor)->bActiveCoopESSTarget)
							{
								CaptionText = Cast<AAGP_Pawn>(cFrame->cActor)->stTargetDescription;
								IconImage = _tESSObjective;
								bRecentTarget = true;
								Cast<AAGP_Pawn>(cFrame->cActor)->bActiveCoopESSTarget = false;
							}
						}
					}
				}
			}
		}
	}
	if (bRecentTarget)
	{
		/*
		Canvas.DrawColor = cFrame->cHUD.HUDColor;
		if (DisplayType == 2)
		{
			Canvas.DrawColor.A = GetFadeValue();
		}
		else
		{
			Canvas.DrawColor.A = cFrame->cHUD.HUDColor.A;
		}
		Canvas.Style = 6;
		Canvas.SetPos(_ScaledPos.X - 32 * cFrame->fScaleX / 2, _ScaledPos.Y);
		Canvas.DrawTile(IconImage, 32 * cFrame->fScaleX, 32 * cFrame->fScaleY, 0, 0, IconImage.MaterialUSize(), IconImage.MaterialVSize());
		Canvas.TextSize(CaptionText, XL, YL);
		Canvas.SetPos(_ScaledPos.X - XL / 2, _ScaledPos.Y + cFrame->fScaleY * 32 + 6);
		Canvas.DrawText(CaptionText, true);
		*/
	}
}
