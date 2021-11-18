// All the original content belonged to the US Army


#include "AA29/Object/UIBase/UIControl/UIHUDBaseDisplay/HUDBodyInfo/HUDBodyInfo.h"

UHUDBodyInfo::UHUDBodyInfo()
{
	//_FastTextures(0) = Texture'T_AA2_UI.HUD.hud_health_walk_fast'
		//_FastTextures(1) = Texture'T_AA2_UI.HUD.hud_health_crouch_fast'
		//_FastTextures(2) = Texture'T_AA2_UI.HUD.hud_health_prone_fast'
		//_SlowTextures(0) = Texture'T_AA2_UI.HUD.hud_health_walk'
		//_SlowTextures(1) = Texture'T_AA2_UI.HUD.hud_health_crouch'
		//_SlowTextures(2) = Texture'T_AA2_UI.HUD.hud_health_prone'
		//_FastFillTextures(0) = Texture'T_AA2_UI.HUD.hud_health_walk_fill'
		//_FastFillTextures(1) = Texture'T_AA2_UI.HUD.hud_health_crouch_fill'
		//_FastFillTextures(2) = Texture'T_AA2_UI.HUD.hud_health_prone_fill'
		//_SlowFillTextures(0) = Texture'T_AA2_UI.HUD.hud_health_walk_fill'
		//_SlowFillTextures(1) = Texture'T_AA2_UI.HUD.hud_health_crouch_fill'
		//_SlowFillTextures(2) = Texture'T_AA2_UI.HUD.hud_health_prone_fill'
		//_DriverTexture = Texture'T_AAO_UI.HUD.T_UI_Hud_Vehicle_Driver'
		//_CROWSTexture = Texture'T_AAO_UI.HUD.T_UI_Hud_Vehicle_CROWS'
		//_PassengerTexture = Texture'T_AAO_UI.HUD.T_UI_Hud_Vehicle_Passenger'
		//_DriverFillTexture = Texture'T_AAO_UI.HUD.T_UI_Hud_Vehicle_Driver_fill'
		//_CROWSFillTexture = Texture'T_AAO_UI.HUD.T_UI_Hud_Vehicle_CROWS_fill'
		//_PassengerFillTexture = Texture'T_AAO_UI.HUD.T_UI_Hud_Vehicle_Passenger_fill'
		//_SprintTexture = Texture'T_AA2_UI.HUD.hud_health_sprint'
		//_SprintFillTexture = Texture'T_AA2_UI.HUD.hud_health_sprint_fill'
		//_BleedingTexture = FinalBlend'T_AA2_UI.HUD.ui_hud_bleeding_fb'
		//_BleedingSlowTexture = FinalBlend'T_AA2_UI.HUD.UI_HUD_Bleeding_Slow_FB'
	ProneX = 104;
	ProneY = 26;

}

void UHUDBodyInfo::Destroyed()
{
	int i = 0;
	Super::Destroyed();
	/*
	for (i = 0; i < 3; i++)
	{
		_FastTextures[i] = None;
		_SlowTextures[i] = None;
		_FastFillTextures[i] = None;
		_SlowFillTextures[i] = None;
	}
	*/
	_DriverTexture = nullptr;
	_CROWSTexture = nullptr;
	_PassengerTexture = nullptr;
	_DriverFillTexture = nullptr;
	_CROWSFillTexture = nullptr;
	_PassengerFillTexture = nullptr;
	_SprintTexture = nullptr;
	_SprintFillTexture = nullptr;
	_BleedingTexture = nullptr;
	_BleedingSlowTexture = nullptr;
}
void UHUDBodyInfo::Draw(UCanvas* Canvas)
{
	/*
	local Object.Color OldColor;
	local Object.Color C;
	local int Index;
	local Pawn.EHealthCondition HC;
	local int oldstyle;
	local GameReplicationInfo GRI;
	local PlayerController PC;
	local float BleedX;
	local float BleedY;
	local AGP_Pawn p;
	local Vehicle VP;
	p = AGP_Pawn(cFrame.cActor);
	VP = Vehicle(cFrame.cActor);
	if (p == None && VP != None && !VP.bDeleteMe)
	{
		p = AGP_Pawn(VP.Driver);
	}
	if (p != None && !p.bDeleteMe)
	{
		PC = cFrame.cHUD.PlayerOwner;
		GRI = PC.GameReplicationInfo;
		if (!GRI.bHUDHideHealth && !PC.bHUDHideHealth)
		{
			ProneX = Default.ProneX * cFrame.fScaleX;
			ProneY = Default.ProneY * cFrame.fScaleY;
			OldColor = Canvas.DrawColor;
			oldstyle = Canvas.Style;
			Canvas.Style = 6;
			HC = p.GetHealthCondition();
			if (HC == 0)
			{
				C.G = 255;
			}
			else
			{
				if (HC == 1)
				{
					C.G = 255;
					C.R = 255;
				}
				else
				{
					if (HC == 2)
					{
						C.R = 255;
					}
				}
			}
			C.A = Canvas.DrawColor.A;
			Canvas.DrawColor = C;
			if (p.bIsProne)
			{
				Index = 2;
			}
			else
			{
				if (p.bIsCrouched)
				{
					Index = 1;
				}
				else
				{
					Index = 0;
				}
			}
			if (VP != None && !VP.IsA('HMMWV_RunningBoardPassenger'))
			{
				Canvas.SetPos(_ScaledPos.X, _ScaledPos.Y);
				if (VP.Driver != None && VP.Driver.Health <= 0)
				{
				}
				if (VP.IsA('CROWS_HMMWV'))
				{
					Canvas.DrawTile(_DriverFillTexture, _ScaledPos.W, _ScaledPos.H, 0, 0, _DriverFillTexture.USize, _DriverFillTexture.VSize);
				}
				else
				{
					if (VP.IsA('CROWS_Gunner'))
					{
						Canvas.DrawTile(_CROWSFillTexture, _ScaledPos.W, _ScaledPos.H, 0, 0, _CROWSFillTexture.USize, _CROWSFillTexture.VSize);
					}
					else
					{
						Canvas.DrawTile(_PassengerFillTexture, _ScaledPos.W, _ScaledPos.H, 0, 0, _PassengerFillTexture.USize, _PassengerFillTexture.VSize);
					}
				}
			}
			else
			{
				if (p.bIsSprinting)
				{
					Canvas.SetPos(_ScaledPos.X, _ScaledPos.Y);
					Canvas.DrawTile(_SprintFillTexture, _ScaledPos.W, _ScaledPos.H, 0, 0, _SprintFillTexture.USize, _SprintFillTexture.VSize);
				}
				else
				{
					if (Index == 2)
					{
						Canvas.SetPos(_ScaledPos.X - ProneX / 2 + 20, _ScaledPos.Y + ProneY + 13);
						if (Pawn(cFrame.cActor).bIsWalking)
						{
							Canvas.DrawTile(_SlowFillTextures[Index], ProneX, ProneY, 0, 0, _SlowFillTextures[Index].USize, _SlowFillTextures[Index].VSize);
						}
						else
						{
							Canvas.DrawTile(_FastFillTextures[Index], ProneX, ProneY, 0, 0, _FastFillTextures[Index].USize, _FastFillTextures[Index].VSize);
						}
					}
					else
					{
						Canvas.SetPos(_ScaledPos.X, _ScaledPos.Y);
						if (Pawn(cFrame.cActor).bIsWalking)
						{
							Canvas.DrawTile(_SlowFillTextures[Index], _ScaledPos.W, _ScaledPos.H, 0, 0, _SlowFillTextures[Index].USize, _SlowFillTextures[Index].VSize);
						}
						else
						{
							Canvas.DrawTile(_FastFillTextures[Index], _ScaledPos.W, _ScaledPos.H, 0, 0, _FastFillTextures[Index].USize, _FastFillTextures[Index].VSize);
						}
					}
				}
			}
			if (p.IsBleeding())
			{
				BleedX = _ScaledPos.X + _ScaledPos.W * 2 / 4;
				BleedY = _ScaledPos.Y - _ScaledPos.H * 1 / 4;
				Canvas.SetPos(BleedX, BleedY);
				Canvas.SetDrawColor(255, 0, 0, Canvas.DrawColor.A);
				if (p.fpBleedRate <= 5)
				{
					Canvas.DrawTile(_BleedingTexture, _ScaledPos.W / 3, _ScaledPos.H / 3, 0, 0, _BleedingTexture.MaterialUSize(), _BleedingTexture.MaterialVSize());
				}
				else
				{
					Canvas.DrawTile(_BleedingSlowTexture, _ScaledPos.W / 3, _ScaledPos.H / 3, 0, 0, _BleedingSlowTexture.MaterialUSize(), _BleedingSlowTexture.MaterialVSize());
				}
			}
			Canvas.DrawColor = OldColor;
			if (VP != None && !VP.IsA('HMMWV_RunningBoardPassenger'))
			{
				Canvas.SetPos(_ScaledPos.X, _ScaledPos.Y);
				if (VP.Driver != None && VP.Driver.Health <= 0)
				{
				}
				if (VP.IsA('CROWS_HMMWV'))
				{
					Canvas.DrawTile(_DriverTexture, _ScaledPos.W, _ScaledPos.H, 0, 0, _DriverTexture.USize, _DriverTexture.VSize);
				}
				else
				{
					if (VP.IsA('CROWS_Gunner'))
					{
						Canvas.DrawTile(_CROWSTexture, _ScaledPos.W, _ScaledPos.H, 0, 0, _CROWSTexture.USize, _CROWSTexture.VSize);
					}
					else
					{
						Canvas.DrawTile(_PassengerTexture, _ScaledPos.W, _ScaledPos.H, 0, 0, _PassengerTexture.USize, _PassengerTexture.VSize);
					}
				}
			}
			else
			{
				if (p.bIsSprinting)
				{
					Canvas.SetPos(_ScaledPos.X, _ScaledPos.Y);
					Canvas.DrawTile(_SprintTexture, _ScaledPos.W, _ScaledPos.H, 0, 0, _SprintTexture.USize, _SprintTexture.VSize);
				}
				else
				{
					if (Index == 2)
					{
						Canvas.SetPos(_ScaledPos.X - ProneX / 2 + 20, _ScaledPos.Y + ProneY + 13);
						if (Pawn(cFrame.cActor).bIsWalking)
						{
							Canvas.DrawTile(_SlowTextures[Index], ProneX, ProneY, 0, 0, _SlowTextures[Index].USize, _SlowTextures[Index].VSize);
						}
						else
						{
							Canvas.DrawTile(_FastTextures[Index], ProneX, ProneY, 0, 0, _FastTextures[Index].USize, _FastTextures[Index].VSize);
						}
					}
					else
					{
						Canvas.SetPos(_ScaledPos.X, _ScaledPos.Y);
						if (Pawn(cFrame.cActor).bIsWalking)
						{
							Canvas.DrawTile(_SlowTextures[Index], _ScaledPos.W, _ScaledPos.H, 0, 0, _SlowTextures[Index].USize, _SlowTextures[Index].VSize);
						}
						else
						{
							Canvas.DrawTile(_FastTextures[Index], _ScaledPos.W, _ScaledPos.H, 0, 0, _FastTextures[Index].USize, _FastTextures[Index].VSize);
						}
					}
				}
			}
			Canvas.DrawColor = OldColor;
			Canvas.Style = oldstyle;
		}
	}
	*/
}
