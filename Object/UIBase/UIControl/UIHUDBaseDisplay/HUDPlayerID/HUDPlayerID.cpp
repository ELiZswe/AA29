// All the original content belonged to the US Army


#include "AA29/Object/UIBase/UIControl/UIHUDBaseDisplay/HUDPlayerID/HUDPlayerID.h"

UHUDPlayerID::UHUDPlayerID()
{
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
		if (_TargetPRI != None && _TargetPRI.Level != None)
		{
			LostTargetTime = _TargetPRI.Level.TimeSeconds;
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
	_TargetPRI = None;
	LostTargetTime = 0;
	*/
}
void UHUDPlayerID::Draw(UCanvas* Canvas)
{
	/*
	local int oldstyle;
	local Object.Color OldColor;
	local bool OldCenter;
	if (Canvas == None || cFrame == None || cFrame.cActor == None || cFrame.cActor.Level == None || cFrame.cActor.bDeleteMe || cFrame.cActor.Level.bDeleteMe)
	{
		Return;
	}
	if (AGP_Pawn(cFrame.cActor) != None && AGP_Pawn(cFrame.cActor).bHealingInProgress)
	{
		DisplayType = 1;
		_TargetPRI = Pawn(cFrame.cActor).PlayerReplicationInfo;
		ColorId = 1;
		bDeepTrace = False;
	}
	else
	{
		if (_TargetPRI == None)
		{
			DisplayType = 0;
		}
		else
		{
			if (DisplayType == 2)
			{
				if (cFrame.cActor.Level.TimeSeconds > LostTargetTime + 0.6)
				{
					DisplayType = 0;
					_TargetPRI = None;
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
void UHUDPlayerID::GetFadeValue()
{
	/*
	local int rvalue;
	rvalue = LostTargetTime + 0.6 - cFrame.cActor.Level.TimeSeconds * 255 / 0.6;
	Return Max(rvalue, 1);
	*/
}
void UHUDPlayerID::DrawPlayerID(UCanvas* Canvas)
{
	/*
	local Object.Color C;
	local PlayerReplicationInfo myPRI;
	local string PlayerIDText;
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
	if (_TargetPRI != None && _TargetPRI.myPawn != cFrame.cActor)
	{
		Canvas.SetPos(0, _ScaledPos.Y);
		PlayerIDText = "Target:" @ _TargetPRI.PlayerName;
		if (Pawn(cFrame.cActor) != None && Pawn(cFrame.cActor).PlayerReplicationInfo != None)
		{
			myPRI = Pawn(cFrame.cActor).PlayerReplicationInfo;
		}
		if (myPRI != None && myPRI.IsFriend(_TargetPRI))
		{
			if (_TargetPRI.FT != 255)
			{
				PlayerIDText = PlayerIDText @ "(" $ FTLetter[_TargetPRI.FT] $ ")";
			}
		}
		Canvas.DrawText(PlayerIDText);
	}
	*/
}
void UHUDPlayerID::DrawPlayerRank(UCanvas* Canvas)
{
	/*
	local Object.Color C;
	local PlayerReplicationInfo myPRI;
	local Material Icon;
	myPRI = Pawn(cFrame.cActor).PlayerReplicationInfo;
	if (myPRI == None || !myPRI.IsFriend(_TargetPRI))
	{
		Return;
	}
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
	if (_TargetPRI.myPawn != cFrame.cActor)
	{
		Canvas.DrawColor = C;
		Canvas.SetPos(0, _ScaledPos.Y);
		Canvas.DrawTile(Icon, 32 * cFrame.fScaleX, 32 * cFrame.fScaleY, 0, 0, Icon.MaterialUSize(), Icon.MaterialVSize());
	}
	*/
}
void UHUDPlayerID::DrawMedicalID(UCanvas* Canvas)
{
	/*
	local PlayerReplicationInfo myPRI;
	local AGP_Pawn p;
	local Material Icon;
	local float XL;
	local float YL;
	local string Text;
	if (bDeepTrace)
	{
		Return;
	}
	if (Pawn(cFrame.cActor) != None && Pawn(cFrame.cActor).PlayerReplicationInfo != None)
	{
		myPRI = Pawn(cFrame.cActor).PlayerReplicationInfo;
	}
	if (myPRI == None)
	{
		Return;
	}
	if (_TargetPRI != None && _TargetPRI == myPRI)
	{
		Icon = _tHealing;
	}
	else
	{
		if (myPRI.bIsMedic && myPRI.IsFriend(_TargetPRI))
		{
			p = AGP_Pawn(_TargetPRI.myPawn);
			if (p != None)
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
	if (Icon != None)
	{
		Canvas.SetPos(_ScaledPos.X - 32 * 0.5 * cFrame.fScaleX, _ScaledPos.Y - 60 * cFrame.fScaleY);
		Canvas.DrawTile(Icon, 32 * cFrame.fScaleX, 32 * cFrame.fScaleY, 0, 0, Icon.MaterialUSize(), Icon.MaterialVSize());
	}
	if (p != None)
	{
		Canvas.bCenter = true;
		Canvas.StrLen("X", XL, YL);
		Text = "Condition: ";
		Switch(p.GetHealthCondition())
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
		Switch(p.GetWoundSeverity())
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