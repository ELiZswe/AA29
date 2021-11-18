// All the original content belonged to the US Army


#include "AA29/Object/UIBase/UIControl/UIHUDBaseDisplay/HUDCombatEff/HUDCombatEff.h"

UHUDCombatEff::UHUDCombatEff()
{
	//_tMeter = Texture'T_AA2_UI.HUD.ui_hud_combateffect_meter';
	//_tMaxBar = Texture'T_AA2_UI.HUD.hud_group_dev';
}


void UHUDCombatEff::Destroyed()
{
	Super::Destroyed();
	_tMeter = nullptr;
}
void UHUDCombatEff::Draw(UCanvas* Canvas)
{
	/*
	local Object.Color OldColor;
	local int oldstyle;
	local float fCE;
	local float FMax;
	local GameReplicationInfo GRI;
	local PlayerController PC;
	local AGP_Pawn p;
	local Vehicle V;
	if (Canvas == None || cFrame == None || cFrame.cActor == None || cFrame.cActor.Level == None || cFrame.cActor.bDeleteMe || cFrame.cActor.Level.bDeleteMe)
	{
		Return;
	}
	V = Vehicle(cFrame.cActor);
	if (V != None)
	{
		p = AGP_Pawn(V.Driver);
	}
	else
	{
		p = AGP_Pawn(cFrame.cActor);
	}
	if (p != None && p.Health > 0)
	{
		PC = cFrame.cHUD.PlayerOwner;
		GRI = PC.GameReplicationInfo;
		if (!GRI.bHUDHideCombatEffect && !PC.bHUDHideCombatEffect)
		{
			OldColor = Canvas.DrawColor;
			oldstyle = Canvas.Style;
			Canvas.Style = 6;
			Canvas.SetDrawColor(255, 255, 255);
			FMax = p.CE_MaxMeterValue;
			fCE = p.CE_MeterValue;
			Canvas.SetPos(_ScaledPos.X, _ScaledPos.Y);
			Canvas.DrawTile(_tMeter, _ScaledPos.W, _ScaledPos.H, 0, 0, 5, 64);
			Canvas.SetPos(_ScaledPos.X, _ScaledPos.Y + _ScaledPos.H - _ScaledPos.H * FMax - _ScaledPos.H / 32);
			Canvas.DrawTile(_tMaxBar, _ScaledPos.W, _ScaledPos.H / 32, 5, 5, 6, 6);
			Canvas.SetPos(_ScaledPos.X, _ScaledPos.Y + _ScaledPos.H - _ScaledPos.H * fCE);
			Canvas.DrawTile(_tMeter, _ScaledPos.W, _ScaledPos.H * fCE, 8, 64 - 64 * fCE, 5, 64 * fCE);
			Canvas.DrawColor = OldColor;
			Canvas.DrawColor = OldColor;
			Canvas.Style = oldstyle;
		}
	}
	*/
}