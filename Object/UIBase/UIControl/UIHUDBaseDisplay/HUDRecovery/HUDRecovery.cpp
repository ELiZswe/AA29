// All the original content belonged to the US Army


#include "AA29/Object/UIBase/UIControl/UIHUDBaseDisplay/HUDRecovery/HUDRecovery.h"

UHUDRecovery::UHUDRecovery()
{
	//_tMeter = Texture'T_AA2_UI.HUD.ui_hud_cem_stamina_meter'
}

void UHUDRecovery::Destroyed()
{
	Super::Destroyed();
	_tMeter = nullptr;
}
void UHUDRecovery::Draw(UCanvas* Canvas)
{
	/*
	local Object.Color OldColor;
	local int oldstyle;
	local float fCE;
	local AGP_Pawn p;
	local GameReplicationInfo GRI;
	local PlayerController PC;
	p = AGP_Pawn(cFrame.cActor);
	if (p != None && !p.bDeleteMe)
	{
		PC = cFrame.cHUD.PlayerOwner;
		GRI = PC.GameReplicationInfo;
		if (!GRI.bHUDHideCombatEffect && !PC.bHUDHideCombatEffect)
		{
			OldColor = Canvas.DrawColor;
			oldstyle = Canvas.Style;
			Canvas.Style = 6;
			Canvas.SetDrawColor(255, 255, 255);
			fCE = p.CE_RecoveryPenalty;
			Canvas.SetPos(_ScaledPos.X, _ScaledPos.Y);
			Canvas.DrawTile(_tMeter, _ScaledPos.W, _ScaledPos.H, 0, 0, 5, 64);
			Canvas.SetPos(_ScaledPos.X, _ScaledPos.Y + _ScaledPos.H - _ScaledPos.H * fCE);
			Canvas.DrawTile(_tMeter, _ScaledPos.W, _ScaledPos.H * fCE, 8, 64 - 64 * fCE, 5, 64 * fCE);
			Canvas.DrawColor = OldColor;
			Canvas.DrawColor = OldColor;
			Canvas.Style = oldstyle;
		}
	}
	*/
}