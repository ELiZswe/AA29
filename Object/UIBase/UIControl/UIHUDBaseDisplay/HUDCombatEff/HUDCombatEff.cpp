// All the original content belonged to the US Army

#include "AA29/Object/UIBase/UIControl/UIHUDBaseDisplay/HUDCombatEff/HUDCombatEff.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/GameReplicationInfo/GameReplicationInfo.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/Object/Actor/Pawn/Vehicle/Vehicle.h"
#include "Engine/Canvas.h"

UHUDCombatEff::UHUDCombatEff()
{
	_tMeter = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/ui_hud_combateffect_meter_Mat.ui_hud_combateffect_meter_Mat'"), NULL, LOAD_None, NULL);
	_tMaxBar = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_group_dev_Mat.hud_group_dev_Mat'"), NULL, LOAD_None, NULL);
}

void UHUDCombatEff::Destroyed()
{
	Super::Destroyed();
	_tMeter = nullptr;
}
void UHUDCombatEff::Draw(UCanvas* Canvas)
{
	FColor OldColor = FColor(0,0,0,0);
	int32 oldstyle = 0;
	float fCE = 0;
	float FMax = 0;
	AGameReplicationInfo* GRI = nullptr;
	APlayerController* PC = nullptr;
	AAGP_Pawn* p = nullptr;
	AVehicle* V = nullptr;
	/*
	if (Canvas == nullptr || cFrame == nullptr || cFrame->cActor == nullptr || cFrame->cActor.Level == nullptr || cFrame->cActor.bDeleteMe || cFrame->cActor.Level.bDeleteMe)
	{
		return;
	}
	V = Vehicle(cFrame->cActor);
	if (V != nullptr)
	{
		p = Cast<AAGP_Pawn>(V.Driver);
	}
	else
	{
		p = Cast<AAGP_Pawn>(cFrame->cActor);
	}
	if (p != nullptr && p.Health > 0)
	{
		PC = cFrame->cHUD.PlayerOwner;
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
