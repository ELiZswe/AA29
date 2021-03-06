// All the original content belonged to the US Army

#include "AA29/Object/UIBase/UIControl/UIHUDBaseDisplay/HUDBodyInfo/HUDBodyInfo.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/GameReplicationInfo/GameReplicationInfo.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/Object/UIBase/UIFrame/UIFrame.h"
#include "AA29/Object/Actor/Pawn/Vehicle/Vehicle.h"
#include "Engine/Canvas.h"
#include "AA29/Object/Actor/Pawn/Vehicle/VehiclePosition/HMMWV_Passenger/CROWS_Gunner/CROWS_Gunner.h"
#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/AGP_Vehicle/AGP_WheeledCraft/CROWS_HMMWV/CROWS_HMMWV.h"
#include "AA29/Object/Actor/Pawn/Vehicle/VehiclePosition/HMMWV_Passenger/HMMWV_RunningBoardPassenger/HMMWV_RunningBoardPassenger.h"

UHUDBodyInfo::UHUDBodyInfo()
{
	_SlowFillTextures.SetNum(3);
	_FastFillTextures.SetNum(3);
	_SlowTextures.SetNum(3);
	_FastTextures.SetNum(3);
	_FastTextures = {
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_health_walk_fast_Mat.hud_health_walk_fast_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_health_crouch_fast_Mat.hud_health_crouch_fast_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_health_prone_fast_Mat.hud_health_prone_fast_Mat'"), NULL, LOAD_None, NULL)
	};
	_SlowTextures = {
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_health_walk_Mat.hud_health_walk_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_health_crouch_Mat.hud_health_crouch_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_health_prone_Mat.hud_health_prone_Mat'"), NULL, LOAD_None, NULL)
	};
	_FastFillTextures = {
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_health_walk_fill_Mat.hud_health_walk_fill_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_health_crouch_fill_Mat.hud_health_crouch_fill_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_health_prone_fill_Mat.hud_health_prone_fill_Mat'"), NULL, LOAD_None, NULL)
	};
	_SlowFillTextures = {
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_health_walk_fill_Mat.hud_health_walk_fill_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_health_crouch_fill_Mat.hud_health_crouch_fill_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_health_prone_fill_Mat.hud_health_prone_fill_Mat'"), NULL, LOAD_None, NULL)
	};
	_DriverTexture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/HUD/T_UI_Hud_Vehicle_Driver_Mat.T_UI_Hud_Vehicle_Driver_Mat'"), NULL, LOAD_None, NULL);
	_CROWSTexture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/HUD/T_UI_Hud_Vehicle_CROWS_Mat.T_UI_Hud_Vehicle_CROWS_Mat'"), NULL, LOAD_None, NULL);
	_PassengerTexture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/HUD/T_UI_Hud_Vehicle_Passenger_Mat.T_UI_Hud_Vehicle_Passenger_Mat'"), NULL, LOAD_None, NULL);
	_DriverFillTexture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/HUD/T_UI_Hud_Vehicle_Driver_fill_Mat.T_UI_Hud_Vehicle_Driver_fill_Mat'"), NULL, LOAD_None, NULL);
	_CROWSFillTexture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/HUD/T_UI_Hud_Vehicle_CROWS_fill_Mat.T_UI_Hud_Vehicle_CROWS_fill_Mat'"), NULL, LOAD_None, NULL);
	_PassengerFillTexture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/HUD/T_UI_Hud_Vehicle_Passenger_fill_Mat.T_UI_Hud_Vehicle_Passenger_fill_Mat'"), NULL, LOAD_None, NULL);
	_SprintTexture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_health_sprint_Mat.hud_health_sprint_Mat'"), NULL, LOAD_None, NULL);
	_SprintFillTexture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_health_sprint_fill_Mat.hud_health_sprint_fill_Mat'"), NULL, LOAD_None, NULL);

	//_BleedingTexture = FinalBlend'T_AA2_UI.HUD.ui_hud_bleeding_fb'
	//_BleedingSlowTexture = FinalBlend'T_AA2_UI.HUD.UI_HUD_Bleeding_Slow_FB'
	ProneX = 104;
	ProneY = 26;

}

void UHUDBodyInfo::Destroyed()
{
	int i = 0;
	Super::Destroyed();
	for (i = 0; i < 3; i++)
	{
		_FastTextures[i] = nullptr;
		_SlowTextures[i] = nullptr;
		_FastFillTextures[i] = nullptr;
		_SlowFillTextures[i] = nullptr;
	}
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
	FColor OldColor = FColor(0,0,0,0);
	FColor C = FColor(0,0,0,0);
	int32 Index = 0;
	EHealthCondition HC = EHealthCondition::HC_GREEN;
	int32 oldstyle = 0;
	AGameReplicationInfo* GRI = nullptr;
	APlayerController* PC = nullptr;
	float BleedX = 0;
	float BleedY = 0;
	AAGP_Pawn* p = nullptr;
	AVehicle* VP = nullptr;
	p = Cast<AAGP_Pawn>(cFrame->cActor);
	VP = Cast<AVehicle>(cFrame->cActor);
	/*
	if (p == nullptr && VP != nullptr && !VP.bDeleteMe)
	{
		p = Cast<AAGP_Pawn>(VP.Driver);
	}
	if (p != nullptr && !p.bDeleteMe)
	{
		PC = cFrame->cHUD.PlayerOwner;
		GRI = PC.GameReplicationInfo;
		if (!GRI.bHUDHideHealth && !PC.bHUDHideHealth)
		{
			ProneX = Default.ProneX * cFrame->fScaleX;
			ProneY = Default.ProneY * cFrame->fScaleY;
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
			if (VP != nullptr && !VP->IsA(AHMMWV_RunningBoardPassenger::StaticClass()))
			{
				Canvas.SetPos(_ScaledPos.X, _ScaledPos.Y);
				if (VP.Driver != nullptr && VP.Driver.Health <= 0)
				{
				}
				if (VP->IsA(ACROWS_HMMWV::StaticClass()))
				{
					Canvas.DrawTile(_DriverFillTexture, _ScaledPos.W, _ScaledPos.H, 0, 0, _DriverFillTexture.USize, _DriverFillTexture.VSize);
				}
				else
				{
					if (VP->IsA(ACROWS_Gunner::StaticClass()))
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
						if (Cast<APawn>(cFrame->cActor).bIsWalking)
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
						if (Cast<APawn>(cFrame->cActor).bIsWalking)
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
			if (VP != nullptr && !VP->IsA(AHMMWV_RunningBoardPassenger::StaticClass()))
			{
				Canvas.SetPos(_ScaledPos.X, _ScaledPos.Y);
				if (VP.Driver != nullptr && VP.Driver.Health <= 0)
				{
				}
				if (VP->IsA(ACROWS_HMMWV::StaticClass()))
				{
					Canvas.DrawTile(_DriverTexture, _ScaledPos.W, _ScaledPos.H, 0, 0, _DriverTexture.USize, _DriverTexture.VSize);
				}
				else
				{
					if (VP->IsA(ACROWS_Gunner::StaticClass()))
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
						if (Cast<APawn>(cFrame->cActor).bIsWalking)
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
						if (Cast<APawn>(cFrame->cActor).bIsWalking)
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
