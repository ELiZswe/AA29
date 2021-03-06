// All the original content belonged to the US Army

#include "AA29/Object/UIBase/UIControl/UIHUDBaseDisplay/HUDPlayerID/HUDPlayerID.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/Object/UIBase/UIFrame/UIFrame.h"
#include "Engine/Canvas.h"

UHUDPlayerID::UHUDPlayerID()
{
	FTName.SetNum(5);
	FTLetter.SetNum(5);
	tFT.SetNum(5);
	//tSquadLeader = Texture'T_AA2_UI.HUD.hud_rank_ssg'
	//tTeamLeader = Texture'T_AA2_UI.HUD.hud_rank_sgt'
	//tTeamMember = Texture'T_AA2_UI.HUD.hud_rank_pvt'
	//tIndigenous = Texture'T_AA2_UI.HUD.hud_rank_indigenous'
	//tSFCaptain = Texture'T_AA2_UI.HUD.hud_rank_captain'
	//tVIP = Texture'T_AA2_UI.HUD.hud_rank_VIP'
	//tSFTeamLeader = Texture'T_AA2_UI.HUD.hud_rank_staffsgt_1st'
	//tFT(1) = Texture'T_AA2_UI.HUD.hud_fireteam_a'
	//tFT(2) = Texture'T_AA2_UI.HUD.hud_fireteam_b'
	//tFT(3) = Texture'T_AA2_UI.HUD.hud_fireteam_c'
	//tFT(4) = Texture'T_AA2_UI.HUD.hud_fireteam_d'
	FTLetter = { "SSG","A","B","C","D" };
	FTName = { "Squad Leader","Alpha", "Bravo", "Charlie", "Delta" };
	//_tBleeding = FinalBlend'T_AA2_UI.HUD.ui_hud_bleeding_fb'
	//_tHealed = Texture'T_AA2_UI.HUD.ui_hud_medpack'
	//_tHealing = Texture'T_AA2_UI.HUD.ui_hud_healing'
}

//const kFadeTime = 0.6;
//const kHealthIconSizeX = 32;
//const kHealthIconSizeY = 32;
//const kHealthIconOffsetY = 60;

void UHUDPlayerID::Destroyed()
{
	_tBleeding = nullptr;
	_tHealed = nullptr;
	_tHealing = nullptr;
	_TargetPRI = nullptr;
}

void UHUDPlayerID::SetTarget(AAA2_PlayerState* new_target, int32 new_color_id, bool new_deep_trace)
{
	//DisplayType = 1;
	_TargetPRI = new_target;
	bDeepTrace = new_deep_trace;
	if (new_color_id != 0)
	{
		ColorId = new_color_id;
	}
}

void UHUDPlayerID::NoTarget()
{
	/*
	if (DisplayType == 1)
	{
		DisplayType = 2;
		if (_TargetPRI != nullptr && _TargetPRI.Level != nullptr)
		{
			LostTargetTime = _TargetPRI.GetWorld()->GetTimeSeconds();
		}
		else
		{
			LostTargetTime = 0;
		}
	}
	*/
}
void UHUDPlayerID::ClearTarget()
{
	/*
	DisplayType = 0;
	_TargetPRI = nullptr;
	LostTargetTime = 0;
	*/
}

void UHUDPlayerID::Draw(UCanvas* Canvas)
{
	int32 oldstyle = 0;
	FColor OldColor = FColor(0,0,0);
	bool OldCenter = false;
	/*
	if (Canvas == nullptr || cFrame == nullptr || cFrame->cActor == nullptr || cFrame->cActor.Level == nullptr || cFrame->cActor.bDeleteMe || cFrame->cActor.Level.bDeleteMe)
	{
		return;
	}
	if (Cast<AAGP_Pawn>(cFrame->cActor) != nullptr && Cast<AAGP_Pawn>(cFrame->cActor).bHealingInProgress)
	{
		DisplayType = 1;
		_TargetPRI = Cast<APawn>(cFrame->cActor).PlayerReplicationInfo;
		ColorId = 1;
		bDeepTrace = false;
	}
	else
	{
		if (_TargetPRI == nullptr)
		{
			DisplayType = 0;
		}
		else
		{
			if (DisplayType == 2)
			{
				if (cFrame->cActor.GetWorld()->GetTimeSeconds() > LostTargetTime + 0.6)
				{
					DisplayType = 0;
					_TargetPRI = nullptr;
				}
			}
		}
	}
	if (DisplayType != 0)
	{
		OldCenter = Canvas.bCenter;
		OldColor = Canvas.DrawColor;
		oldstyle = Canvas.Style;
		DrawPlayerID(Canvas);
		DrawPlayerRank(Canvas);
		DrawMedicalID(Canvas);
		Canvas.bCenter = OldCenter;
		Canvas.DrawColor = OldColor;
		Canvas.Style = oldstyle;
	}
	*/
}
uint8 UHUDPlayerID::GetFadeValue()
{
	/*
	int32 rvalue;
	rvalue = LostTargetTime + 0.6 - cFrame->cActor.GetWorld()->GetTimeSeconds() * 255 / 0.6;
	return FMath::Max(rvalue, 1);
	*/
	return 0;    //FAKE   /EliZ
}
void UHUDPlayerID::DrawPlayerID(UCanvas* Canvas)
{
	FColor C = FColor(0,0,0);
	AAA2_PlayerState* myPRI = nullptr;
	FString PlayerIDText = "";
	/*
	switch(ColorId)
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
	if (DisplayType == 2)
	{
		C.A = GetFadeValue();
	}
	else
	{
		C.A = 255;
	}
	Canvas.bCenter = true;
	Canvas.Style = 6;
	Canvas.DrawColor = C;
	if (_TargetPRI != nullptr && _TargetPRI.myPawn != cFrame->cActor)
	{
		Canvas.SetPos(0, _ScaledPos.Y);
		PlayerIDText = "Target:" @ _TargetPRI.PlayerName;
		if (Cast<APawn>(cFrame->cActor) != nullptr && Pawn(cFrame->cActor).PlayerReplicationInfo != nullptr)
		{
			myPRI = Cast<APawn>(cFrame->cActor).PlayerReplicationInfo;
		}
		if (myPRI != nullptr && myPRI.IsFriend(_TargetPRI))
		{
			if (_TargetPRI.FT != 255)
			{
				PlayerIDText = PlayerIDText @ "(" + FTLetter[_TargetPRI.FT] + ")";
			}
		}
		Canvas.DrawText(PlayerIDText);
	}
	*/
}

void UHUDPlayerID::DrawPlayerRank(UCanvas* Canvas)
{
	FColor C = FColor(0,0,0);
	AAA2_PlayerState* myPRI = nullptr;
	UMaterialInstance* Icon = nullptr;
	/*
	myPRI = Cast<APawn>(cFrame->cActor).PlayerReplicationInfo;
	if (myPRI == nullptr || !myPRI.IsFriend(_TargetPRI))
	{
		return;
	}
	switch(ColorId)
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
	if (myPRI.IsSquadLeader())
	{
		if (myPRI.bSpecialForcesPS && myPRI.bQualifiedSF)
		{
			Icon = tSFCaptain;
		}
		else
		{
			if (myPRI.bSpecialForcesPS && !myPRI.bQualifiedSF)
			{
				Icon = tIndigenous;
			}
			else
			{
				Icon = tSquadLeader;
			}
		}
	}
	else
	{
		if (myPRI.isTeamLeader())
		{
			if (myPRI.bSpecialForcesPS && myPRI.bQualifiedSF)
			{
				Icon = tSFTeamLeader;
			}
			else
			{
				if (myPRI.bSpecialForcesPS && !myPRI.bQualifiedSF)
				{
					Icon = tIndigenous;
				}
				else
				{
					Icon = tTeamLeader;
				}
			}
		}
		else
		{
			if (myPRI.bSpecialForcesPS && myPRI.bQualifiedSF)
			{
				Icon = tSquadLeader;
			}
			else
			{
				if (myPRI.bSpecialForcesPS && !myPRI.bQualifiedSF)
				{
					Icon = tIndigenous;
				}
				else
				{
					Icon = tTeamMember;
				}
			}
		}
	}
	if (myPRI.bGuerrillaPS)
	{
		Icon = tIndigenous;
	}
	if (myPRI.bVIPPS)
	{
		Icon = tVIP;
	}
	if (_TargetPRI.myPawn != cFrame->cActor)
	{
		Canvas.DrawColor = C;
		Canvas.SetPos(0, _ScaledPos.Y);
		Canvas.DrawTile(Icon, 32 * cFrame->fScaleX, 32 * cFrame->fScaleY, 0, 0, Icon.MaterialUSize(), Icon.MaterialVSize());
	}
	*/
}

void UHUDPlayerID::DrawMedicalID(UCanvas* Canvas)
{
	AAA2_PlayerState* myPRI = nullptr;
	AAGP_Pawn* p = nullptr;
	UMaterialInstance* Icon = nullptr;
	float XL = 0;
	float YL = 0;
	FString Text = "";
	if (bDeepTrace)
	{
		return;
	}
	/*
	if (Cast<APawn>(cFrame->cActor) != nullptr && Pawn(cFrame->cActor).PlayerReplicationInfo != nullptr)
	{
		myPRI = Cast<APawn>(cFrame->cActor).PlayerReplicationInfo;
	}
	if (myPRI == nullptr)
	{
		return;
	}
	if (_TargetPRI != nullptr && _TargetPRI == myPRI)
	{
		Icon = _tHealing;
	}
	else
	{
		if (myPRI.bIsMedic && myPRI.IsFriend(_TargetPRI))
		{
			p = Cast<AAGP_Pawn>(_TargetPRI.myPawn);
			if (p != nullptr)
			{
				if (p.bHealingInProgress)
				{
					Icon = _tHealing;
				}
				else
				{
					if (p.IsBleeding())
					{
						Icon = _tBleeding;
						Canvas.SetDrawColor(255, 0, 0, Canvas.DrawColor.A);
					}
					else
					{
						if (p.Health < 100 && !p.IsWounded())
						{
							Icon = _tHealed;
						}
					}
				}
			}
		}
	}
	if (Icon != nullptr)
	{
		Canvas.SetPos(_ScaledPos.X - 32 * 0.5 * cFrame->fScaleX, _ScaledPos.Y - 60 * cFrame->fScaleY);
		Canvas.DrawTile(Icon, 32 * cFrame->fScaleX, 32 * cFrame->fScaleY, 0, 0, Icon.MaterialUSize(), Icon.MaterialVSize());
	}
	if (p != nullptr)
	{
		Canvas.bCenter = true;
		Canvas.StrLen("X", XL, YL);
		Text = "Condition: ";
		switch(p.GetHealthCondition())
		{
			case 0:
				Canvas.SetDrawColor(0, 255, 0, Canvas.DrawColor.A);
				Text = Text @ "Green";
				break;
			case 1:
				Canvas.SetDrawColor(255, 255, 0, Canvas.DrawColor.A);
				Text = Text @ "Yellow";
				break;
			case 2:
				Canvas.SetDrawColor(255, 0, 0, Canvas.DrawColor.A);
				Text = Text @ "Red";
				break;
			default:
		}
		Canvas.SetPos(0, _ScaledPos.Y + YL);
		Canvas.DrawText(Text);
		Text = "Severity: ";
		switch(p.GetWoundSeverity())
		{
			case 0:
				Text = "";
				break;
			case 1:
				Canvas.SetDrawColor(0, 255, 0, Canvas.DrawColor.A);
				Text = Text @ "Treated";
				break;
			case 2:
				Canvas.SetDrawColor(0, 255, 0, Canvas.DrawColor.A);
				Text = Text @ "Minor";
				break;
			case 3:
				Canvas.SetDrawColor(255, 255, 0, Canvas.DrawColor.A);
				Text = Text @ "Moderate";
				break;
			case 4:
				Canvas.SetDrawColor(255, 0, 0, Canvas.DrawColor.A);
				Text = Text @ "Urgent";
				break;
			default:
		}
		if (Text != "")
		{
			Canvas.SetPos(0, _ScaledPos.Y + 2 * YL);
			Canvas.DrawText(Text);
		}
	}
	*/
}
