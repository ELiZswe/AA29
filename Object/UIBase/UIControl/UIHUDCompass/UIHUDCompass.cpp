// All the original content belonged to the US Army

#include "AA29/Object/UIBase/UIControl/UIHUDCompass/UIHUDCompass.h"

UUIHUDCompass::UUIHUDCompass()
{
	//_tLeft = Texture'T_AA2_UI.HUD.hud_nav_compass_01'
	//_tRight = Texture'T_AA2_UI.HUD.hud_nav_compass_02'
	
	//_tObjectiveSymbols(0) = Texture'T_AA2_UI.HUD.ui_hud_obj_A'
	//_tObjectiveSymbols(1) = Texture'T_AA2_UI.HUD.ui_hud_obj_B'
	//_tObjectiveSymbols(2) = Texture'T_AA2_UI.HUD.ui_hud_obj_C'
	//_tObjectiveSymbols(3) = Texture'T_AA2_UI.HUD.ui_hud_obj_D'
	//_tObjectiveSymbols(4) = Texture'T_AA2_UI.HUD.ui_hud_obj_E'
	//_tObjectiveSymbols(5) = Texture'T_AA2_UI.HUD.ui_hud_obj_F'
	//_tObjectiveSymbols(6) = Texture'T_AA2_UI.HUD.ui_hud_obj_G'
	//_tObjectiveSymbols(7) = Texture'T_AA2_UI.HUD.ui_hud_obj_H'

	_sObjectiveSymbols = { "A","B","C","D","E","F","G","H" };

	//_tObjectiveUp = Texture'T_AA2_UI.HUD.ui_hud_obj_up'
	//_tObjectiveDown = Texture'T_AA2_UI.HUD.ui_hud_obj_down'
	//_tObjectiveLevel = Texture'T_AA2_UI.HUD.ui_hud_obj_level'
	//_tTeamSSG = Texture'T_AA2_UI.HUD.hud_rank_ssg'
	//_tTeamSGT = Texture'T_AA2_UI.HUD.hud_rank_sgt'
	//_tTeamPVT = Texture'T_AA2_UI.HUD.hud_rank_pvt'
	//_tTeamMedic = Texture'T_AA2_UI.HUD.ui_hud_medic'
	//_tTeamBleed = FinalBlend'T_AA2_UI.HUD.ui_hud_bleeding_fb'

	//_tFT(0) = Texture'T_AA2_UI.HUD.hud_fireteam_a'
	//_tFT(1) = Texture'T_AA2_UI.HUD.hud_fireteam_b'
	//_tFT(2) = Texture'T_AA2_UI.HUD.hud_fireteam_c'
	//_tFT(3) = Texture'T_AA2_UI.HUD.hud_fireteam_d'

	//_tTeamIFVIP = Texture'T_AA2_UI.HUD.hud_rank_VIP'
	//_tTeamSFCapt = Texture'T_AA2_UI.HUD.hud_rank_captain'
	//_tTeamSSG1st = Texture'T_AA2_UI.HUD.hud_rank_staffsgt_1st'
	//_tTeamIF = Texture'T_AA2_UI.HUD.hud_rank_indigenous'
}

//const kMaxObjectives = 8;
//const kArrowDeadRange = 132;
//const kObjectiveArrowScaleX = 0.5;
//const kObjectiveSize = 16;
//const kObjectiveTextY = 112;
//const kObjectiveTextX = 786;
//const kLocationTextY = 82;
//const kLocationTextX = 786;
//const kCompassTextureWidth = 1024;
//const kCompassY = 16;
//const kCompassHeight = 32;
//const kCompassWidth = 512;

void UUIHUDCompass::Destroyed()
{
	/*
	local int i;
	local UIControl Control;
	local UIControl NextControl;
	Destroyed();
	_tLeft = nullptr;
	_tRight = nullptr;
	_BracketTexture = nullptr;
	_TeamPoint = nullptr;
	_tTeamSSG = nullptr;
	_tTeamSGT = nullptr;
	_tTeamPVT = nullptr;
	_tTeamMedic = nullptr;
	_tTeamBleed = nullptr;
	_tTeamIFVIP = nullptr;
	_tTeamSFCapt = nullptr;
	_tTeamSSG1st = nullptr;
	_tTeamIF = nullptr;
	for (i = 0; i < 8; i++)
	{
		_tObjectiveSymbols[i] = nullptr;
		if (_Objectives[i] != None)
		{
			_Objectives[i].Destroyed();
			_Objectives[i] = nullptr;
		}
	}
	Control = _ElementList;
	if (Control != None)
	{
		NextControl = Control.cNextControl;
		Control.Destroyed();
		Control = NextControl;
	}
	_ElementList = nullptr;
	*/
}
bool UUIHUDCompass::IsSettingTarget()
{
	return _bIsSettingTarget;
}
void UUIHUDCompass::SetTarget(bool E)
{
	_bIsSettingTarget = E;
}
void UUIHUDCompass::Draw(UCanvas* Canvas)
{
	/*
	local int oldstyle;
	local GameReplicationInfo GRI;
	local PlayerController PC;
	if (cFrame.cActor == nullptr)
	{
		Return;
	}
	if (Pawn(cFrame.cActor) == nullptr)
	{
		Return;
	}
	oldstyle = Canvas.Style;
	if (!_InitializedObjectives)
	{
		InitializeObjectives();
	}
	PC = cFrame.cHUD.PlayerOwner;
	GRI = PC.GameReplicationInfo;
	if (ShouldDrawCompass())
	{
		if (GRI != None && !GRI.bHUDHideCompass && PC != None && !PC.bHUDHideCompass)
		{
			DrawLocation(Canvas);
		}
	}
	if (ShouldDrawObjectiveList())
	{
		if (GRI != None && !GRI.bHUDHideCompass && PC != None && !PC.bHUDHideCompass)
		{
			DrawObjectiveList(Canvas);
		}
	}
	Canvas.Style = oldstyle;
	*/
}
void UUIHUDCompass::InitializeObjectives()
{
	/*
	local BaseObjective obj;
	local UIHUDCompassPointObj objcompass;
	local int objnum;
	objnum = 0;
	ForEach cFrame.cActor.DynamicActors(Class'BaseObjective', obj)
	{
		if (obj.IsA('AGP_Objective'))
		{
			objcompass = new (None) class'UIHUDCompassPointObj';
			objcompass.setObjective(obj);
			objnum = obj.GetHUDPosition();
			if (objnum > 8)
			{
				objnum = 8 - 1;
			}
			objcompass.SetTexture(_tObjectiveSymbols[objnum]);
			objcompass.SetText(_sObjectiveSymbols[objnum]);
			objcompass.setOrder(objnum);
			objcompass.Create(cFrame, cScreen, 0, -1, 0);
			if (_Objectives[objnum] == nullptr)
			{
				_Objectives[objnum] = objcompass;
			}
			else
			{
				objcompass.cNextControl = _Objectives[objnum];
				_Objectives[objnum] = objcompass;
			}
		}
	}
	_InitializedObjectives = true;
	*/
}
void UUIHUDCompass::DrawCompass(UCanvas* Canvas)
{
	/*
	local float X;
	local float Y;
	local float fFOV;
	local int iCompassSrc;
	local int iCompassStart;
	local float fDegrees;
	local float Width;
	if (!ShouldDrawCompass())
	{
		Return;
	}
	if (_tLeft == nullptr)
	{
		Canvas.SetPos(100, 100);
		Canvas.DrawText("UIHUDCompass::Draw NO TEXTURE");
		Return;
	}
	Canvas.Style = 6;
	if (cFrame != None)
	{
		Canvas.DrawColor = cFrame.cHUD.HUDColor;
	}
	X = Canvas.ClipX / 2 - 512 * cFrame.fScaleX / 2;
	Y = 16;
	Canvas.SetPos(X, Y);
	fFOV = Pawn(cFrame.cActor).Controller.FovAngle;
	iCompassSrc = fFOV * 1024 * 2 / 360;
	fDegrees = cFrame.cActor.Rotation.Yaw * 360 / 65535;
	iCompassStart = fDegrees * 1024 * 2 / 360;
	iCompassStart -= iCompassSrc / 2;
	iCompassStart = iCompassStart % 2 * 1024;
	if (iCompassStart < 0)
	{
		iCompassStart += 2 * 1024;
	}
	if (iCompassStart <= 1024)
	{
		if (1024 > iCompassSrc + iCompassStart)
		{
			Canvas.DrawTile(_tLeft, 512 * cFrame.fScaleX, 32 * cFrame.fScaleY, iCompassStart, 0, iCompassSrc, _tLeft.VSize);
		}
		else
		{
			Width = 1024 - iCompassStart / iCompassSrc;
			Canvas.DrawTile(_tLeft, Width * 512 * cFrame.fScaleX, 32 * cFrame.fScaleY, iCompassStart, 0, _tLeft.USize - iCompassStart, _tLeft.VSize);
			Canvas.SetPos(X + Width * 512 * cFrame.fScaleX, Y);
			Width = 1 - Width;
			Canvas.DrawTile(_tRight, Width * 512 * cFrame.fScaleX, 32 * cFrame.fScaleY, 0, 0, iCompassSrc - _tRight.USize - iCompassStart, _tRight.VSize);
		}
	}
	else
	{
		if (1024 * 2 > iCompassSrc + iCompassStart)
		{
			Canvas.DrawTile(_tRight, 512 * cFrame.fScaleX, 32 * cFrame.fScaleY, iCompassStart - 1024, 0, iCompassSrc, _tRight.VSize);
		}
		else
		{
			Width = 2 * 1024 - iCompassStart / iCompassSrc;
			Canvas.DrawTile(_tRight, Width * 512 * cFrame.fScaleX, 32 * cFrame.fScaleY, iCompassStart - 1024, 0, _tRight.USize - iCompassStart - 1024, _tRight.VSize);
			Canvas.SetPos(X + Width * 512 * cFrame.fScaleX, Y);
			Width = 1 - Width;
			Canvas.DrawTile(_tLeft, Width * 512 * cFrame.fScaleX, 32 * cFrame.fScaleY, 0, 0, iCompassSrc - 2 * 1024 - iCompassStart, _tRight.VSize);
		}
	}
	X = Canvas.ClipX / 2 - 512 * cFrame.fScaleX / 2;
	Y = 16;
	Canvas.SetPos(X, Y);
	Canvas.DrawTile(_BracketTexture, 512 * cFrame.fScaleX, 32 * cFrame.fScaleY, 0, 0, _BracketTexture.USize, _BracketTexture.VSize);
	*/
}
void UUIHUDCompass::DrawLocation(UCanvas* Canvas)
{
	/*
	local Texture tobj;
	local float X;
	local float Y;
	local float XL;
	local float YL;
	local float Xi;
	local float Yi;
	local PlayerReplicationInfo myPRI;
	local string LocString;
	local Volume C;
	local BaseObjective obj;
	if (Pawn(cFrame.cActor) != None && Pawn(cFrame.cActor).PlayerReplicationInfo != None)
	{
		myPRI = Pawn(cFrame.cActor).PlayerReplicationInfo;
	}
	if (myPRI == nullptr || myPRI.isDead())
	{
		Return;
	}
	X = 786 * cFrame.fScaleX;
	Y = 82 * cFrame.fScaleY;
	C = myPRI.GetCommVolume();
	if (C != None)
	{
		obj = BaseObjective(myPRI.GetNearbyObjective(C));
	}
	if (obj != None)
	{
		tobj = _tObjectiveSymbols[obj.GetHUDPosition()];
		Xi = 16 * cFrame.fScaleX;
		Yi = 16 * cFrame.fScaleY;
		Canvas.SetPos(X - Xi, Y);
		Canvas.DrawTile(tobj, Xi, Yi, 0, 0, tobj.USize, tobj.VSize);
		Xi *= 1.5;
	}
	LocString = myPRI.GetLocationName(C);
	Canvas.TextSize(LocString, XL, YL);
	Canvas.SetPos(X - XL - Xi, Y);
	Canvas.DrawTextClipped(LocString);
	*/
}
void UUIHUDCompass::DrawObjectives(UCanvas* Canvas)
{
	/*
	local int ctr;
	local UIControl Current;
	local UIHUDCompassPoint currentpoint;
	local bool retval;
	retval = False;
	for (ctr = 0; ctr < 8; ctr++)
	{
		Current = _Objectives[ctr];
		if (Current != None)
		{
			currentpoint = UIHUDCompassPoint(Current);
			if (currentpoint.IsA('UIHUDCompassPointObj'))
			{
				DrawCompassPoint(currentpoint, Canvas);
				retval = true;
			}
			else
			{
				if (currentpoint != None && currentpoint.IsOnCompass(Pawn(cFrame.cActor).Controller))
				{
					DrawCompassPoint(currentpoint, Canvas);
				}
			}
			Current = Current.cNextControl;
		}
	}
	return retval;
	*/
}
void UUIHUDCompass::ScaleControl(UCanvas* Canvas)
{
	/*
	Super::ScaleControl(Canvas);
	ScaledObjectiveTextX = 786 * cFrame.fScaleX;
	ScaledObjectiveTextY = 112 * cFrame.fScaleY;
	*/
}
void UUIHUDCompass::DrawObjectiveList(UCanvas* Canvas)
{
	/*
	local float X;
	local float Y;
	local float XL;
	local float YL;
	local int ctr;
	local UIControl Current;
	local UIHUDCompassPointObj currentobj;
	local string ObjString;
	X = ScaledObjectiveTextX;
	Y = ScaledObjectiveTextY;
	Canvas.SetPos(X, Y);
	if (_bIsSettingTarget)
	{
		Canvas.TextSize("SET SQUAD TARGET:", XL, YL);
		Canvas.SetPos(X - XL, Y);
		Canvas.DrawTextClipped("SET SQUAD TARGET:");
	}
	else
	{
		Canvas.TextSize("OBJECTIVES", XL, YL);
		Canvas.SetPos(X - XL, Y);
		Canvas.DrawTextClipped("OBJECTIVES");
	}
	Y += YL * 0.5;
	for (ctr = 0; ctr < 8; ctr++)
	{
		Current = _Objectives[ctr];
		if (Current != None)
		{
			currentobj = UIHUDCompassPointObj(Current);
			if (currentobj != None)
			{
				ObjString = currentobj.GetString();
			}
			if (currentobj == nullptr || !currentobj.IsEnabled() || ObjString == "")
			{
				Current = Current.cNextControl;
			}
			else
			{
				Canvas.TextSize(ObjString, XL, YL);
				Y += YL;
				Canvas.SetPos(X - XL, Y);
				Canvas.DrawTextClipped(ObjString);
				Current = Current.cNextControl;
			}
		}
	}
	*/
}
void UUIHUDCompass::DrawCompassPoint(UUIHUDCompassPoint* currentpoint, UCanvas* Canvas)
{
	/*
	local float ptdegrees;
	local float fDegrees;
	local Material ptTexture;
	local float X;
	local float Y;
	local float XL;
	local float YL;
	local byte FT;
	local PlayerReplicationInfo myPRI;
	if (!_InitializedObjectives)
	{
		InitializeObjectives();
	}
	fDegrees = cFrame.cActor.Rotation.Yaw * 360 / 65535;
	if (currentpoint == nullptr || !currentpoint.IsOnCompass(Pawn(cFrame.cActor).Controller))
	{
		Return;
	}
	if (currentpoint.IsA('UIHUDCompassPointObj') && cFrame.cHUD.bHideCompassObjPoints)
	{
		Return;
	}
	ptTexture = currentpoint.GetTexture();
	ptdegrees = currentpoint.GetRotation(cFrame.cActor);
	ptdegrees = ptdegrees - fDegrees;
	if (ptdegrees > 180)
	{
		ptdegrees = ptdegrees - 360;
	}
	else
	{
		if (ptdegrees < -180)
		{
			ptdegrees = ptdegrees + 360;
		}
	}
	X = ptdegrees / Pawn(cFrame.cActor).Controller.FovAngle / 2 * 512 * cFrame.fScaleX / 2;
	if (X < -512 * cFrame.fScaleX / 2)
	{
		X = -512 * cFrame.fScaleX / 2;
	}
	if (X > 512 * cFrame.fScaleX / 2)
	{
		X = 512 * cFrame.fScaleX / 2;
	}
	X += Canvas.ClipX / 2;
	XL = 16 * cFrame.fScaleX;
	X -= XL / 2;
	X -= XL * 0.5 / 2;
	Y = 16 + 32 * cFrame.fScaleY + 5;
	Canvas.SetPos(X, Y);
	Canvas.DrawTile(ptTexture, XL, 16 * cFrame.fScaleY, 0, 0, ptTexture.MaterialUSize(), ptTexture.MaterialVSize());
	FT = currentpoint.getFT();
	if (FT != 255)
	{
		Canvas.SetPos(X + 16 * cFrame.fScaleX / 4, Y + 16 + 2 * cFrame.fScaleY);
		Canvas.DrawTile(_tFT[FT], XL / 2, 16 * cFrame.fScaleY / 2, 0, 0, _tFT[FT].USize, _tFT[FT].VSize);
	}
	Canvas.SetPos(X + XL, Y);
	YL = currentpoint.CompareHeight(cFrame.cActor);
	if (YL < -132)
	{
		ptTexture = _tObjectiveDown;
	}
	else
	{
		if (YL > 132)
		{
			ptTexture = _tObjectiveUp;
		}
		else
		{
			ptTexture = _tObjectiveLevel;
		}
	}
	Canvas.DrawTile(ptTexture, XL * 0.5, 16 * cFrame.fScaleY, 0, 0, ptTexture.MaterialUSize(), ptTexture.MaterialVSize());
	if (Pawn(cFrame.cActor) != None && Pawn(cFrame.cActor).PlayerReplicationInfo != None)
	{
		myPRI = Pawn(cFrame.cActor).PlayerReplicationInfo;
		if (myPRI.Team != None && currentpoint.IsA('UIHUDCompassPointObj') && UIHUDCompassPointObj(currentpoint).IsSquadTarget(myPRI.Team.TeamIndex))
		{
			Canvas.SetPos(X, Y + 16 + 2 * cFrame.fScaleY);
			ptTexture = currentpoint.GetTexture();
			Canvas.DrawTile(ptTexture, XL, 2, 2, 2, 4, 4);
		}
	}
	*/
}
void UUIHUDCompass::DrawPlayer(UCanvas* Canvas, AAA2_PlayerState* Player, UMaterialInstance* Icon)
{
	/*
	if (Icon == nullptr)
	{
		Return;
	}
	else
	{
		if (Icon == _tTeamBleed)
		{
			Canvas.SetDrawColor(255, 0, 0, Canvas.DrawColor.A);
		}
	}
	_TeamPoint.setVector(Player.GetPawnLocation());
	_TeamPoint.SetTexture(Icon);
	_TeamPoint.setFT(Player.FT);
	DrawCompassPoint(_TeamPoint, Canvas);
	Canvas.DrawColor = cFrame.cHUD.HUDColor;
	*/
}
void UUIHUDCompass::GetPlayerIcon(AAA2_PlayerState* myPRI, AAA2_PlayerState* otherPRI)
{
	/*
	if (otherPRI == nullptr || otherPRI.isDead() || myPRI == otherPRI)
	{
		return None;
	}
	if (myPRI.bIsMedic)
	{
		if (otherPRI.bCallForMedic)
		{
			return _tTeamBleed;
		}
	}
	if (otherPRI.bIsMedic)
	{
		if (myPRI.bCallForMedic || myPRI.FT == otherPRI.FT)
		{
			return _tTeamMedic;
		}
	}
	if (otherPRI.IsSquadLeader() && !otherPRI.bGuerrillaPS && !otherPRI.bSpecialForcesPS)
	{
		return _tTeamSSG;
	}
	else
	{
		if (otherPRI.IsSquadLeader() && otherPRI.bSpecialForcesPS && otherPRI.bQualifiedSF)
		{
			return _tTeamSFCapt;
		}
		else
		{
			if (otherPRI.IsSquadLeader() && otherPRI.bVIPPS)
			{
				return _tTeamIFVIP;
			}
			else
			{
				return None;
			}
		}
	}
	if (myPRI.IsSquadLeader())
	{
		if (otherPRI.isTeamLeader() && !otherPRI.bSpecialForcesPS && !otherPRI.bGuerrillaPS)
		{
			return _tTeamSGT;
		}
		else
		{
			if (otherPRI.isTeamLeader() && otherPRI.bSpecialForcesPS && otherPRI.bQualifiedSF)
			{
				return _tTeamSSG1st;
			}
			else
			{
				return None;
			}
		}
	}
	else
	{
		if (myPRI.isTeamLeader())
		{
			if (otherPRI.FT == myPRI.FT && !otherPRI.bSpecialForcesPS && !otherPRI.bGuerrillaPS)
			{
				return _tTeamPVT;
			}
			else
			{
				if (otherPRI.FT == myPRI.FT && otherPRI.bSpecialForcesPS && otherPRI.bQualifiedSF)
				{
					return _tTeamSSG;
				}
				else
				{
					if (otherPRI.FT == myPRI.FT && otherPRI.bGuerrillaPS)
					{
						return _tTeamIF;
					}
				}
			}
		}
		else
		{
			if (otherPRI.FT == myPRI.FT && otherPRI.isTeamLeader())
			{
				return _tTeamSGT;
			}
		}
	}
	return None;
	*/
}

void UUIHUDCompass::DrawTeam(UCanvas* Canvas)
{
	/*
	local PlayerReplicationInfo myPRI;
	local PlayerReplicationInfo otherPRI;
	local int i;
	if (_TeamPoint == nullptr)
	{
		_TeamPoint = new (None) class'UIHUDCompassPointV';
	}
	if (Pawn(cFrame.cActor) != None && Pawn(cFrame.cActor).PlayerReplicationInfo != None)
	{
		myPRI = Pawn(cFrame.cActor).PlayerReplicationInfo;
	}
	if (myPRI == nullptr || myPRI.Team == nullptr)
	{
		Return;
	}
	for (i = 0; i < myPRI.Team.Size; i++)
	{
		otherPRI = myPRI.Team.GetFromList(i);
		DrawPlayer(Canvas, otherPRI, GetPlayerIcon(myPRI, otherPRI));
	}
	*/
}
void UUIHUDCompass::SetTexture(UMaterialInstance* pleft)
{
}
void UUIHUDCompass::SetBracketTexture(UMaterialInstance* Tex)
{
	_BracketTexture = Tex;
}
bool UUIHUDCompass::ShouldDrawCompass()
{
	/*
	local Weapon wpn;
	if (cFrame.cHUD.PlayerOwner.IsInState('MedicTraining_SittingAtDesk') || cFrame.cHUD.PlayerOwner.IsInState('MedicTraining_SittingAtDesk2') || cFrame.cHUD.PlayerOwner.IsInState('MedicTraining_TakingExam') || cFrame.cHUD.PlayerOwner.IsInState('MedicTraining_TakingExam2'))
	{
		return false;
	}
	if (Pawn(cFrame.cActor) == nullptr)
	{
		return false;
	}
	wpn = Pawn(cFrame.cActor).Weapon;
	if (wpn == nullptr)
	{
		return true;
	}
	return !wpn.IsZoomed();
	*/
	return true;    //FAKE    /ELiZ
}
bool UUIHUDCompass::ShouldDrawLocation()
{
	return false;
}
void UUIHUDCompass::ShouldDrawObjectiveList()
{
	//Return cFrame.cHUD.bShowObjectives && !cFrame.cHUD.bShowScores;
}
UUIControl* UUIHUDCompass::GetLastControl()
{
	UUIControl* Control= nullptr;
	/*
	Control = _ElementList;
	if (Control != None)
	{
		if (Control.cNextControl == nullptr)
		{
			return Control;
		}
		Control = Control.cNextControl;
	}
	*/
	return Control;
}
void UUIHUDCompass::AddControlToTail(UUIControl* Control)
{
	/*
	local UIControl lastcontrol;
	lastcontrol = GetLastControl();
	if (lastcontrol == nullptr)
	{
		_ElementList = Control;
	}
	else
	{
		lastcontrol.cNextControl = Control;
	}
	*/
}
UUIControl* UUIHUDCompass::GetControl(int32 Id)
{
	/*
	local UIControl Control;
	Control = _ElementList;
	if (Control != None)
	{
		if (Control.GetID() == Id)
		{
			return Control;
		}
		Control = Control.cNextControl;
	}
	return None;
	*/
	return nullptr;    //FAKE   /ELiZ
}
bool UUIHUDCompass::EnableControl(int32 Id, bool State)
{
	/*
	local UIControl Control;
	Control = GetControl(Id);
	if (Control == nullptr)
	{
		return false;
	}
	else
	{
		Control.SetEnabled(State);
		return true;
	}
	*/
	return false;    //FAKE  /ELiZ
}
