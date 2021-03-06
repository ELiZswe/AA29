// All the original content belonged to the US Army

#include "AA29/Object/UIBase/UIControl/UIHUDCompass/UIHUDCompass.h"
#include "AA29/AA2_PlayerState.h"
#include "AA29/Object/UIBase/UIControl/UIControl.h"
#include "AA29/Object/UIBase/UIFrame/UIFrame.h"
#include "AA29/Object/UIBase/UIScreen/UIScreen.h"
#include "AA29/Object/UIBase/UIControl/UIHUDCompassPoint/UIHUDCompassPoint.h"
#include "AA29/Object/UIBase/UIControl/UIHUDCompassPoint/UIHUDCompassPointObj/UIHUDCompassPointObj.h"
#include "AA29/Object/UIBase/UIControl/UIHUDCompassPoint/UIHUDCompassPointV/UIHUDCompassPointV.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/GameReplicationInfo/GameReplicationInfo.h"
#include "AA29/Object/Actor/Keypoint/BaseObjective/BaseObjective.h"
#include "AA29/Object/Actor/Inventory/Weapon/Weapon.h"
#include "Engine/Canvas.h"
#include "AA29/Object/Actor/Keypoint/BaseObjective/AGP_Objective/AGP_Objective.h"

UUIHUDCompass::UUIHUDCompass()
{
	_tFT.SetNum(4);
	_Objectives.SetNum(8);
	_sObjectiveSymbols.SetNum(8);
	_tObjectiveSymbols.SetNum(8);
	_tLeft = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_nav_compass_01_Mat.hud_nav_compass_01_Mat'"), NULL, LOAD_None, NULL);
	_tRight = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_nav_compass_02_Mat.hud_nav_compass_02_Mat'"), NULL, LOAD_None, NULL);
	_tObjectiveSymbols = {
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/ui_hud_obj_A_Mat.ui_hud_obj_A_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/ui_hud_obj_B_Mat.ui_hud_obj_B_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/ui_hud_obj_C_Mat.ui_hud_obj_C_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/ui_hud_obj_D_Mat.ui_hud_obj_D_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/ui_hud_obj_E_Mat.ui_hud_obj_E_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/ui_hud_obj_F_Mat.ui_hud_obj_F_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/ui_hud_obj_G_Mat.ui_hud_obj_G_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/ui_hud_obj_H_Mat.ui_hud_obj_H_Mat'"), NULL, LOAD_None, NULL)
	};
	_sObjectiveSymbols = {
		"A",
		"B",
		"C",
		"D",
		"E",
		"F",
		"G",
		"H"
	};
	_tObjectiveUp = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/ui_hud_obj_up_Mat.ui_hud_obj_up_Mat'"), NULL, LOAD_None, NULL);
	_tObjectiveDown = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/ui_hud_obj_down_Mat.ui_hud_obj_down_Mat'"), NULL, LOAD_None, NULL);
	_tObjectiveLevel = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/ui_hud_obj_level_Mat.ui_hud_obj_level_Mat'"), NULL, LOAD_None, NULL);
	_tTeamSSG = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_rank_ssg_Mat.hud_rank_ssg_Mat'"), NULL, LOAD_None, NULL);
	_tTeamSGT = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_rank_sgt_Mat.hud_rank_sgt_Mat'"), NULL, LOAD_None, NULL);
	_tTeamPVT = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_rank_pvt_Mat.hud_rank_pvt_Mat'"), NULL, LOAD_None, NULL);
	_tTeamMedic = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/ui_hud_medic_Mat.ui_hud_medic_Mat'"), NULL, LOAD_None, NULL);
	//_tTeamBleed = FinalBlend'T_AA2_UI.HUD.ui_hud_bleeding_fb';
	_tFT = {
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_fireteam_a_Mat.hud_fireteam_a_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_fireteam_b_Mat.hud_fireteam_b_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_fireteam_c_Mat.hud_fireteam_c_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_fireteam_d_Mat.hud_fireteam_d_Mat'"), NULL, LOAD_None, NULL)
	};
	_tTeamIFVIP = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_rank_VIP_Mat.hud_rank_VIP_Mat'"), NULL, LOAD_None, NULL);
	_tTeamSFCapt = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_rank_captain_Mat.hud_rank_captain_Mat'"), NULL, LOAD_None, NULL);
	_tTeamSSG1st = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_rank_staffsgt_1st_Mat.hud_rank_staffsgt_1st_Mat'"), NULL, LOAD_None, NULL);
	_tTeamIF = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_rank_indigenous_Mat.hud_rank_indigenous_Mat'"), NULL, LOAD_None, NULL);
}

static const float kMaxObjectives = 8;
static const float kArrowDeadRange = 132;
static const float kObjectiveArrowScaleX = 0.5;
static const float kObjectiveSize = 16;
static const float kObjectiveTextY = 112;
static const float kObjectiveTextX = 786;
static const float kLocationTextY = 82;
static const float kLocationTextX = 786;
static const float kCompassTextureWidth = 1024;
static const float kCompassY = 16;
static const float kCompassHeight = 32;
static const float kCompassWidth = 512;

void UUIHUDCompass::Destroyed()
{
	int32 i = 0;
	UUIControl* Control = nullptr;
	UUIControl* NextControl = nullptr;
	Super::Destroyed();
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
		if (_Objectives[i] != nullptr)
		{
			_Objectives[i]->Destroyed();
			_Objectives[i] = nullptr;
		}
	}
	Control = _ElementList;
	if (Control != nullptr)
	{
		NextControl = Control->cNextControl;
		Control->Destroyed();
		Control = NextControl;
	}
	_ElementList = nullptr;
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
	int32 oldstyle = 0;
	AGameReplicationInfo* GRI = nullptr;
	APlayerController* PC = nullptr;
	if (cFrame->cActor == nullptr)
	{
		return;
	}
	if (Cast<APawn>(cFrame->cActor) == nullptr)
	{
		return;
	}
	/*
	oldstyle = Canvas.Style;
	if (!_InitializedObjectives)
	{
		InitializeObjectives();
	}
	PC = cFrame->cHUD.PlayerOwner;
	GRI = PC.GameReplicationInfo;
	if (ShouldDrawCompass())
	{
		if (GRI != nullptr && !GRI.bHUDHideCompass && PC != nullptr && !PC.bHUDHideCompass)
		{
			DrawLocation(Canvas);
		}
	}
	if (ShouldDrawObjectiveList())
	{
		if (GRI != nullptr && !GRI.bHUDHideCompass && PC != nullptr && !PC.bHUDHideCompass)
		{
			DrawObjectiveList(Canvas);
		}
	}
	Canvas.Style = oldstyle;
	*/
}

void UUIHUDCompass::InitializeObjectives()
{
	ABaseObjective* obj = nullptr;
	UUIHUDCompassPointObj* objcompass = nullptr;
	int32 objnum;
	objnum = 0;
	/*
	ForEach cFrame->cActor.DynamicActors(ABaseObjective::StaticClass(), obj)
	{
		if (obj->IsA(AAGP_Objective::StaticClass()))
		{
			objcompass = new (None) UUIHUDCompassPointObj::StaticClass();
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
	float X = 0;
	float Y = 0;
	float fFOV = 0;
	int32 iCompassSrc = 0;
	int32 iCompassStart = 0;
	float fDegrees = 0;
	float Width = 0;
	if (!ShouldDrawCompass())
	{
		return;
	}
	/*
	if (_tLeft == nullptr)
	{
		Canvas.SetPos(100, 100);
		Canvas.DrawText("UIHUDCompass::Draw NO TEXTURE");
		return;
	}
	Canvas.Style = 6;
	if (cFrame != nullptr)
	{
		Canvas.DrawColor = cFrame->cHUD.HUDColor;
	}
	X = Canvas.ClipX / 2 - 512 * cFrame->fScaleX / 2;
	Y = 16;
	Canvas.SetPos(X, Y);
	fFOV = Cast<APawn>(cFrame->cActor).Controller.FovAngle;
	iCompassSrc = fFOV * 1024 * 2 / 360;
	fDegrees = cFrame->cActor.Rotation.Yaw * 360 / 65535;
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
			Canvas.DrawTile(_tLeft, 512 * cFrame->fScaleX, 32 * cFrame->fScaleY, iCompassStart, 0, iCompassSrc, _tLeft.VSize);
		}
		else
		{
			Width = 1024 - iCompassStart / iCompassSrc;
			Canvas.DrawTile(_tLeft, Width * 512 * cFrame->fScaleX, 32 * cFrame->fScaleY, iCompassStart, 0, _tLeft.USize - iCompassStart, _tLeft.VSize);
			Canvas.SetPos(X + Width * 512 * cFrame->fScaleX, Y);
			Width = 1 - Width;
			Canvas.DrawTile(_tRight, Width * 512 * cFrame->fScaleX, 32 * cFrame->fScaleY, 0, 0, iCompassSrc - _tRight.USize - iCompassStart, _tRight.VSize);
		}
	}
	else
	{
		if (1024 * 2 > iCompassSrc + iCompassStart)
		{
			Canvas.DrawTile(_tRight, 512 * cFrame->fScaleX, 32 * cFrame->fScaleY, iCompassStart - 1024, 0, iCompassSrc, _tRight.VSize);
		}
		else
		{
			Width = 2 * 1024 - iCompassStart / iCompassSrc;
			Canvas.DrawTile(_tRight, Width * 512 * cFrame->fScaleX, 32 * cFrame->fScaleY, iCompassStart - 1024, 0, _tRight.USize - iCompassStart - 1024, _tRight.VSize);
			Canvas.SetPos(X + Width * 512 * cFrame->fScaleX, Y);
			Width = 1 - Width;
			Canvas.DrawTile(_tLeft, Width * 512 * cFrame->fScaleX, 32 * cFrame->fScaleY, 0, 0, iCompassSrc - 2 * 1024 - iCompassStart, _tRight.VSize);
		}
	}
	X = Canvas.ClipX / 2 - 512 * cFrame->fScaleX / 2;
	Y = 16;
	Canvas.SetPos(X, Y);
	Canvas.DrawTile(_BracketTexture, 512 * cFrame->fScaleX, 32 * cFrame->fScaleY, 0, 0, _BracketTexture.USize, _BracketTexture.VSize);
	*/
}

void UUIHUDCompass::DrawLocation(UCanvas* Canvas)
{
	UMaterialInstance* tobj = nullptr;
	float X = 0;
	float Y = 0;
	float XL = 0;
	float YL = 0;
	float Xi = 0;
	float Yi = 0;
	AAA2_PlayerState* myPRI = nullptr;
	FString LocString = "";
	AVolume* C = nullptr;
	ABaseObjective* obj = nullptr;
	/*
	if (Cast<APawn>(cFrame->cActor) != nullptr && Pawn(cFrame->cActor).PlayerReplicationInfo != nullptr)
	{
		myPRI = Cast<APawn>(cFrame->cActor).PlayerReplicationInfo;
	}
	if (myPRI == nullptr || myPRI->isDead())
	{
		return;
	}
	X = 786 * cFrame->fScaleX;
	Y = 82 * cFrame->fScaleY;
	C = myPRI->GetCommVolume();
	if (C != nullptr)
	{
		obj = BaseObjective(myPRI->GetNearbyObjective(C));
	}
	if (obj != nullptr)
	{
		tobj = _tObjectiveSymbols[obj.GetHUDPosition()];
		Xi = 16 * cFrame->fScaleX;
		Yi = 16 * cFrame->fScaleY;
		Canvas.SetPos(X - Xi, Y);
		Canvas.DrawTile(tobj, Xi, Yi, 0, 0, tobj.USize, tobj.VSize);
		Xi *= 1.5;
	}
	LocString = myPRI->GetLocationName(C);
	Canvas.TextSize(LocString, XL, YL);
	Canvas.SetPos(X - XL - Xi, Y);
	Canvas.DrawTextClipped(LocString);
	*/
}

bool UUIHUDCompass::DrawObjectives(UCanvas* Canvas)
{
	int32 ctr = 0;
	UUIControl* Current = nullptr;
	UUIHUDCompassPoint* currentpoint = nullptr;
	bool retval = false;
	retval = false;
	for (ctr = 0; ctr < 8; ctr++)
	{
		for (Current = _Objectives[ctr]; Current != nullptr; Current = Current->cNextControl)
		{
			currentpoint = Cast<UUIHUDCompassPoint>(Current);
			if (currentpoint->IsA(UUIHUDCompassPointObj::StaticClass()))
			{
				DrawCompassPoint(currentpoint, Canvas);
				retval = true;
			}
			else
			{
				if ((currentpoint != nullptr) && currentpoint->IsOnCompass(Cast<APawn>(cFrame->cActor)->Controller))
				{
					DrawCompassPoint(currentpoint, Canvas);
				}
			}
		}
	}
	return retval;
}

void UUIHUDCompass::ScaleControl(UCanvas* Canvas)
{
	Super::ScaleControl(Canvas);
	ScaledObjectiveTextX = 786 * cFrame->fScaleX;
	ScaledObjectiveTextY = 112 * cFrame->fScaleY;
}

void UUIHUDCompass::DrawObjectiveList(UCanvas* Canvas)
{
	float X = 0;
	float Y = 0;
	float XL = 0;
	float YL = 0;
	int32 ctr = 0;
	UUIControl* Current = nullptr; 
	UUIHUDCompassPointObj* currentobj = nullptr;
	FString ObjString = "";
	X = ScaledObjectiveTextX;
	Y = ScaledObjectiveTextY;
	/*
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
		if (Current != nullptr)
		{
			currentobj = UIHUDCompassPointObj(Current);
			if (currentobj != nullptr)
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
	float ptdegrees = 0;
	float fDegrees = 0;
	UMaterialInstance* ptTexture = nullptr;
	float X = 0;
	float Y = 0;
	float XL = 0;
	float YL = 0;
	uint8 FT = 0;
	AAA2_PlayerState* myPRI = nullptr;
	if (!_InitializedObjectives)
	{
		InitializeObjectives();
	}
	/*
	fDegrees = cFrame->cActor->Rotation->Yaw * 360 / 65535;
	if (currentpoint == nullptr || !currentpoint.IsOnCompass(Cast<APawn>(cFrame->cActor).Controller))
	{
		return;
	}
	if (currentpoint->IsA(UUIHUDCompassPointObj::StaticClass()) && cFrame->cHUD.bHideCompassObjPoints)
	{
		return;
	}
	ptTexture = currentpoint.GetTexture();
	ptdegrees = currentpoint.GetRotation(cFrame->cActor);
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
	X = ptdegrees / Pawn(cFrame->cActor).Controller.FovAngle / 2 * 512 * cFrame->fScaleX / 2;
	if (X < -512 * cFrame->fScaleX / 2)
	{
		X = -512 * cFrame->fScaleX / 2;
	}
	if (X > 512 * cFrame->fScaleX / 2)
	{
		X = 512 * cFrame->fScaleX / 2;
	}
	X += Canvas.ClipX / 2;
	XL = 16 * cFrame->fScaleX;
	X -= XL / 2;
	X -= XL * 0.5 / 2;
	Y = 16 + 32 * cFrame->fScaleY + 5;
	Canvas.SetPos(X, Y);
	Canvas.DrawTile(ptTexture, XL, 16 * cFrame->fScaleY, 0, 0, ptTexture.MaterialUSize(), ptTexture.MaterialVSize());
	FT = currentpoint.getFT();
	if (FT != 255)
	{
		Canvas.SetPos(X + 16 * cFrame->fScaleX / 4, Y + 16 + 2 * cFrame->fScaleY);
		Canvas.DrawTile(_tFT[FT], XL / 2, 16 * cFrame->fScaleY / 2, 0, 0, _tFT[FT].USize, _tFT[FT].VSize);
	}
	Canvas.SetPos(X + XL, Y);
	YL = currentpoint.CompareHeight(cFrame->cActor);
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
	Canvas.DrawTile(ptTexture, XL * 0.5, 16 * cFrame->fScaleY, 0, 0, ptTexture.MaterialUSize(), ptTexture.MaterialVSize());
	if (Cast<APawn>(cFrame->cActor) != nullptr && Pawn(cFrame->cActor).PlayerReplicationInfo != nullptr)
	{
		myPRI = Cast<APawn>(cFrame->cActor).PlayerReplicationInfo;
		if (myPRI->Team != nullptr && currentpoint->IsA(UUIHUDCompassPointObj::StaticClass()) && UIHUDCompassPointObj(currentpoint).IsSquadTarget(myPRI->Team.TeamIndex))
		{
			Canvas.SetPos(X, Y + 16 + 2 * cFrame->fScaleY);
			ptTexture = currentpoint.GetTexture();
			Canvas.DrawTile(ptTexture, XL, 2, 2, 2, 4, 4);
		}
	}
	*/
}

void UUIHUDCompass::DrawPlayer(UCanvas* Canvas, AAA2_PlayerState* Player, UMaterialInstance* Icon)
{
	if (Icon == nullptr)
	{
		return;
	}
	else
	{
		if (Icon == _tTeamBleed)
		{
			//Canvas.SetDrawColor(255, 0, 0, Canvas.DrawColor.A);
		}
	}
	_TeamPoint->setVector(Player->GetPawnLocation());
	_TeamPoint->SetTexture(Icon);
	_TeamPoint->setFT(Player->FT);
	DrawCompassPoint(_TeamPoint, Canvas);
	//Canvas->DrawColor = cFrame->cHUD->HUDColor;
}

UMaterialInstance* UUIHUDCompass::GetPlayerIcon(AAA2_PlayerState* myPRI, AAA2_PlayerState* otherPRI)
{
	if (((otherPRI == nullptr) || otherPRI->isDead()) || (myPRI == otherPRI))
	{
		return nullptr;
	}
	if (myPRI->bIsMedic)
	{
		if (otherPRI->bCallForMedic)
		{
			return _tTeamBleed;
		}
	}
	if (otherPRI->bIsMedic)
	{
		if (myPRI->bCallForMedic || (myPRI->FT == otherPRI->FT))
		{
			return _tTeamMedic;
		}
	}
	if ((otherPRI->IsSquadLeader() && (!otherPRI->bGuerrillaPS)) && (!otherPRI->bSpecialForcesPS))
	{
		return _tTeamSSG;
	}
	else
	{
		if ((otherPRI->IsSquadLeader() && otherPRI->bSpecialForcesPS) && otherPRI->bQualifiedSF)
		{
			return _tTeamSFCapt;
		}
		else
		{
			if (otherPRI->IsSquadLeader() && otherPRI->bVIPPS)
			{
				return _tTeamIFVIP;
			}
			else
			{
				return nullptr;
			}
		}
	}
	if (myPRI->IsSquadLeader())
	{
		if ((otherPRI->isTeamLeader() && (!otherPRI->bSpecialForcesPS)) && (!otherPRI->bGuerrillaPS))
		{
			return _tTeamSGT;
		}
		else
		{
			if ((otherPRI->isTeamLeader() && otherPRI->bSpecialForcesPS) && otherPRI->bQualifiedSF)
			{
				return _tTeamSSG1st;
			}
			else
			{
				return nullptr;
			}
		}
	}
	else
	{
		if (myPRI->isTeamLeader())
		{
			if (((otherPRI->FT == myPRI->FT) && (!otherPRI->bSpecialForcesPS)) && (!otherPRI->bGuerrillaPS))
			{
				return _tTeamPVT;
			}
			else
			{
				if (((otherPRI->FT == myPRI->FT) && otherPRI->bSpecialForcesPS) && otherPRI->bQualifiedSF)
				{
					return _tTeamSSG;
				}
				else
				{
					if ((otherPRI->FT == myPRI->FT) && otherPRI->bGuerrillaPS)
					{
						return _tTeamIF;
					}
				}
			}
		}
		else
		{
			if ((otherPRI->FT == myPRI->FT) && otherPRI->isTeamLeader())
			{
				return _tTeamSGT;
			}
		}
	}
	return nullptr;

}

void UUIHUDCompass::DrawTeam(UCanvas* Canvas)
{
	AAA2_PlayerState* myPRI = nullptr;
	AAA2_PlayerState* otherPRI = nullptr;
	int32 i = 0;
	/*
	if (_TeamPoint == nullptr)
	{
		_TeamPoint = new (nullptr) UUIHUDCompassPointV::StaticClass();
	}
	if ((Cast<APawn>(cFrame->cActor) != nullptr) && (Cast<APawn>(cFrame->cActor).PlayerReplicationInfo != nullptr))
	{
		myPRI = Cast<APawn>(cFrame->cActor).PlayerReplicationInfo;
	}
	if ((myPRI == nullptr) || (myPRI->Team == nullptr))
	{
		return;
	}
	for (i = 0; i < myPRI->Team.Size; i++)
	{
		otherPRI = myPRI->Team.GetFromList(i);
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
	AWeapon* wpn = nullptr;
	/*
	if (cFrame->cHUD.PlayerOwner.IsInState('MedicTraining_SittingAtDesk') || cFrame->cHUD.PlayerOwner.IsInState('MedicTraining_SittingAtDesk2') || cFrame->cHUD.PlayerOwner.IsInState('MedicTraining_TakingExam') || cFrame->cHUD.PlayerOwner.IsInState('MedicTraining_TakingExam2'))
	{
		return false;
	}
	if (Cast<APawn>(cFrame->cActor) == nullptr)
	{
		return false;
	}
	wpn = Cast<APawn>(cFrame->cActor).Weapon;
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

bool UUIHUDCompass::ShouldDrawObjectiveList()
{
	//return (cFrame->cHUD->bShowObjectives && (!cFrame->cHUD->bShowScores));
	return true;     //FAKE   /ELiZ
}

UUIControl* UUIHUDCompass::GetLastControl()
{
	UUIControl* Control= nullptr;
	/*
	for (Control = _ElementList; Control != nullptr; Control = Control.cNextControl)
	{
		if (Control.cNextControl == nullptr)
		{
			return Control;
		}
	}
	*/
	return Control;
}

void UUIHUDCompass::AddControlToTail(UUIControl* Control)
{
	UUIControl* lastcontrol = nullptr;
	lastcontrol = GetLastControl();
	if (lastcontrol == nullptr)
	{
		_ElementList = Control;
	}
	else
	{
		lastcontrol->cNextControl = Control;
	}
}

UUIControl* UUIHUDCompass::GetControl(int32 Id)
{
	UUIControl* Control = nullptr;
	for (Control = _ElementList; Control != nullptr; Control = Control->cNextControl)
	{
		if (Control->GetID() == Id)
		{
			return Control;
		}
	}
	return nullptr;
}

bool UUIHUDCompass::EnableControl(int32 Id, bool State)
{
	UUIControl* Control = nullptr;
	Control = GetControl(Id);
	if (Control == nullptr)
	{
		return false;
	}
	else
	{
		Control->SetEnabled(State);
		return true;
	}
}
