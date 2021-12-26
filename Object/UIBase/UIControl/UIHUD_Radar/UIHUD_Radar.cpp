// All the original content belonged to the US Army

#include "AA29/Object/UIBase/UIControl/UIHUD_Radar/UIHUD_Radar.h"
#include "AA29/AA2_PlayerState.h"

UUIHUD_Radar::UUIHUD_Radar()
{
	//GridRange = FRange(4096, 8192);
	bMap = true;
	MapSize = -32768;
}

void UUIHUD_Radar::Initialize()
{
	/*
	local string map_name;
	local Material NewMap;
	map_name = "T_AA2_UI.Map.Map_" $ cFrame.cActor.Level.sLevelName;
	NewMap = Material(DynamicLoadObject(map_name, Class'Texture'));
	if (NewMap != None)
	{
		_tGrid = NewMap;
	}
	bInitialized = true;
	*/
}
bool UUIHUD_Radar::ShouldDrawRadar()
{
	/*
	local Weapon wpn;
	if (Pawn(cFrame.cActor).Controller.IsInState('MedicTraining_SittingAtDesk') || Pawn(cFrame.cActor).Controller.IsInState('MedicTraining_SittingAtDesk2') || Pawn(cFrame.cActor).Controller.IsInState('MedicTraining_TakingExam') || Pawn(cFrame.cActor).Controller.IsInState('MedicTraining_TakingExam2'))
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
	return true;     //FAKE    /ELiZ
}
void UUIHUD_Radar::Draw(UCanvas* C)
{
	/*
	local GameReplicationInfo GRI;
	local PlayerController PC;
	if (!bInitialized)
	{
		Initialize();
	}
	PC = cFrame.cHUD.PlayerOwner;
	GRI = PC.GameReplicationInfo;
	if (ShouldDrawRadar())
	{
		if (!GRI.bHUDHideRadar && !PC.bHUDHideRadar)
		{
			UpdateRadarDots();
			DrawRadarGrid(C);
		}
	}
	*/
}
void UUIHUD_Radar::DrawRadarGrid(UCanvas* C)
{
	/*
	C.SetPos(_ScaledPos.X, _ScaledPos.Y);
	C.SetDrawColor(255, 255, 255, C.DrawColor.A);
	C.DrawTile(_tGrid, _ScaledPos.W, _ScaledPos.H, GridUV.X, GridUV.Y, GridUV.W, GridUV.H);
	C.DrawColor = cFrame.cHUD.HUDColor;
	*/
}
void UUIHUD_Radar::UpdateRadarDots()
{
	/*
	local TeamInfo MyTeam;
	local int i;
	local int draw_num;
	local float max_distance_s;
	myPRI = Pawn(cFrame.cActor).PlayerReplicationInfo;
	MyTeam = myPRI.Team;
	if (MyTeam != None)
	{
		for (i = 0; i < MyTeam.Size; i++)
		{
			if (ShouldDraw(MyTeam.TeamList[i]))
			{
				UpdateRadarDot(MyTeam.TeamList[i], draw_num);
				max_distance_s = FMax(max_distance_s, RadarDotPool[draw_num].GetDistanceSquared());
				draw_num++;
			}
		}
	}
	else
	{
		UpdateRadarDot(myPRI, draw_num);
		draw_num++;
	}
	UpdateCurrentRange(Sqrt(max_distance_s));
	for (i = draw_num; i < RadarDotPool.Length; i++)
	{
		RadarDotPool[i].bVisible = False;
	}
	*/
}
void UUIHUD_Radar::CreateNewRadarDot()
{
	/*
	local UIHUD_RadarDot NewRadarDot;
	cScreen.AddHUDBaseDisplay("AGP_UI.UIHUD_RadarDot", -1, _Pos, 1);
	NewRadarDot = UIHUD_RadarDot(cScreen.GetLastControl());
	NewRadarDot.SetMyRadar(Self);
	NewRadarDot.ScaleControl(None);
	RadarDotPool[RadarDotPool.Length] = NewRadarDot;
	*/
}
void UUIHUD_Radar::UpdateRadarDot(AAA2_PlayerState* PRI, int32 draw_number)
{
	/*
	local UIHUD_RadarDot RadarDot;
	local Object.Vector MyLoc;
	local Object.Vector DotLoc;
	local Object.Vector RelLoc;
	local Object.Rotator R;
	if (RadarDotPool.Length <= draw_number)
	{
		CreateNewRadarDot();
	}
	RadarDot = RadarDotPool[draw_number];
	RadarDot.bVisible = true;
	MyLoc = myPRI.GetPawnLocation();
	DotLoc = PRI.GetPawnLocation();
	RelLoc = MyLoc - DotLoc;
	if (bFrontUp)
	{
		R.Yaw = myPRI.GetMyPawn().Rotation.Yaw;
		RelLoc = RelLoc << R;
	}
	RadarDot.SetRadarDotXY(RelLoc.X, RelLoc.Y);
	*/
}
bool UUIHUD_Radar::ShouldDraw(AAA2_PlayerState* PRI)
{
	if (PRI->isDead())
	{
		return false;
	}
	else
	{
		return true;
	}
}
void UUIHUD_Radar::UpdateCurrentRange(float max_distance)
{
	/*
	local float NewRange;
	NewRange = FClamp(max_distance * 1.5, GridRange.Min, GridRange.Max);
	if (NewRange != CurrentRange || bMap)
	{
		SetCurrentRange(NewRange);
	}
	*/
}
void UUIHUD_Radar::SetCurrentRange(float NewRange)
{
	/*
	local float ratio;
	local float u_max;
	local float v_max;
	local Object.Vector CenterLoc;
	local float U;
	local float V;
	local float X;
	local float Y;
	local float X1;
	local float X2;
	local float Y1;
	local float Y2;
	CurrentRange = NewRange;
	u_max = _tGrid.MaterialUSize();
	v_max = _tGrid.MaterialVSize();
	if (bMap)
	{
		CenterLoc = myPRI.GetMyPawn().Location;
		X = CenterLoc.Y;
		Y = -CenterLoc.X;
		X += MapSize / 2;
		Y += MapSize / 2;
		X1 = X - CurrentRange;
		Y1 = Y - CurrentRange;
		X2 = X + CurrentRange;
		Y2 = Y + CurrentRange;
		GridUV.X = u_max * X1 / MapSize;
		GridUV.Y = v_max * Y1 / MapSize;
		GridUV.W = u_max * X2 - X1 / MapSize;
		GridUV.H = v_max * Y2 - Y1 / MapSize;
	}
	else
	{
		ratio = 1 - CurrentRange / GridRange.Max;
		U = ratio * u_max / 2;
		V = ratio * v_max / 2;
		GridUV.X = U;
		GridUV.Y = V;
		GridUV.W = u_max - U - U;
		GridUV.H = v_max - V - V;
	}
	*/
}