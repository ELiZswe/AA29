// All the original content belonged to the US Army

#include "AA29/Object/UIBase/UIControl/UIHUDBaseDisplay/HUDTaskDisplay/HUDTaskDisplay.h"
#include "AA29/Object/Actor/CallForSupport/CallForSupport.h"
#include "AA29/Object/Actor/Inventory/Inventory.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/GameReplicationInfo/GameReplicationInfo.h"
#include "AA29/Object/UIBase/UIFrame/UIFrame.h"
#include "AA29/Object/Actor/Inventory/AGP_ObjectiveInventory/AGP_ObjectiveInventory.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/AGP_Weapon.h"
#include "AA29/Object/Actor/InventoryAttachment/BaseOptics/BaseOptics.h"
#include "AA29/Object/Actor/HUD/AGP_HUD/AGP_HUD.h"
#include "Engine/Canvas.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/RocketWeapon/WEAPON_Javelin/WEAPON_Javelin.h"
#include "AA29/Object/Actor/CallForSupport/FireSupport/AirStrike/AirStrike.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/Item_Binoculars/Item_Binoculars.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/item_headphones/item_headphones.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/Item_Binoculars/Item_VIPER/Item_VIPER.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/RocketWeapon/Javelin_Tube/Javelin_Tube.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/TraceWeapon/PistolWeapon/PistolWeapon.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/ThrowWeapon/ThrowWeapon.h"
#include "AA29/Object/Actor/Pawn/Vehicle/Vehicle.h"

UHUDTaskDisplay::UHUDTaskDisplay()
{
	tSupport.SetNum(4);
	tBinoc.SetNum(5);
	tFT.SetNum(4);
	GrenadeClassName.SetNum(4);
	GrenadeClass.SetNum(4);
	Breachername = "AGP_Inventory.Demo_DoorBreacher";
	GrenadeClassName = {
		"AGP_Inventory.Throw_M67_Frag",
		"AGP_Inventory.Throw_M83_Smoke",
		"AGP_Inventory.Throw_M84_Stun",
		"AGP_Inventory.Throw_M14_Incendiary"
	};
	textSpotterOverlayMenu = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_SpotterTools/MenuOverlays/BinocularOverlayNumpad_Mat.BinocularOverlayNumpad_Mat'"), NULL, LOAD_None, NULL);
	tDiscard = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_mode_discard_Mat.hud_mode_discard_Mat'"), NULL, LOAD_None, NULL);
	tReload = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_mode_reload_Mat.hud_mode_reload_Mat'"), NULL, LOAD_None, NULL);
	tRecharge = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_mode_recharge_Mat.hud_mode_recharge_Mat'"), NULL, LOAD_None, NULL);
	tRoll = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_mode_roll_Mat.hud_mode_roll_Mat'"), NULL, LOAD_None, NULL);
	tJammed = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_mode_fixjam_Mat.hud_mode_fixjam_Mat'"), NULL, LOAD_None, NULL);
	tLiveGrenade = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_mode_livegrenade_Mat.hud_mode_livegrenade_Mat'"), NULL, LOAD_None, NULL);
	tSupported = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_mode_supported_Mat.hud_mode_supported_Mat'"), NULL, LOAD_None, NULL);
	tROF_Single = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_mode_single_Mat.hud_mode_single_Mat'"), NULL, LOAD_None, NULL);
	tROF_Burst = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_mode_burst_Mat.hud_mode_burst_Mat'"), NULL, LOAD_None, NULL);
	tROF_Auto = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_mode_auto_Mat.hud_mode_auto_Mat'"), NULL, LOAD_None, NULL);
	tROF_Grenade = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_mode_grenade_Mat.hud_mode_grenade_Mat'"), NULL, LOAD_None, NULL);
	tJav_Targeting = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_mode_targeting_Mat.hud_mode_targeting_Mat'"), NULL, LOAD_None, NULL);
	tJav_LockedOn = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_mode_lockedon_Mat.hud_mode_lockedon_Mat'"), NULL, LOAD_None, NULL);
	tJav_TooClose = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_mode_tooclose_Mat.hud_mode_tooclose_Mat'"), NULL, LOAD_None, NULL);
	tJav_Tube = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_mode_javelintube_Mat.hud_mode_javelintube_Mat'"), NULL, LOAD_None, NULL);
	tSquadLeader = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_rank_ssg_Mat.hud_rank_ssg_Mat'"), NULL, LOAD_None, NULL);
	tTeamLeader = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_rank_sgt_Mat.hud_rank_sgt_Mat'"), NULL, LOAD_None, NULL);
	tTeamMember = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_rank_pvt_Mat.hud_rank_pvt_Mat'"), NULL, LOAD_None, NULL);
	tIndigenous = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_rank_indigenous_Mat.hud_rank_indigenous_Mat'"), NULL, LOAD_None, NULL);
	tSFCaptain = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_rank_captain_Mat.hud_rank_captain_Mat'"), NULL, LOAD_None, NULL);
	tVIP = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_rank_VIP_Mat.hud_rank_VIP_Mat'"), NULL, LOAD_None, NULL);
	tSFTeamLeader = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_rank_staffsgt_1st_Mat.hud_rank_staffsgt_1st_Mat'"), NULL, LOAD_None, NULL);
	tFT = {
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_fireteam_a_Mat.hud_fireteam_a_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_fireteam_b_Mat.hud_fireteam_b_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_fireteam_c_Mat.hud_fireteam_c_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_fireteam_d_Mat.hud_fireteam_d_Mat'"), NULL, LOAD_None, NULL)
	};
	tBinoc = {
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_optics_BINOCS_m22_Mat.hud_optics_BINOCS_m22_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_optics_BINOCS_m24_Mat.hud_optics_BINOCS_m24_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_optics_BINOCS_tank_Mat.hud_optics_BINOCS_tank_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_optics_BINOCS_newt_Mat.hud_optics_BINOCS_newt_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_optics_binocs_VIPIR_Mat.hud_optics_binocs_VIPIR_Mat'"), NULL, LOAD_None, NULL)
	};
	tSupport = {
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/Air_Strike_Not_Available_Mat.Air_Strike_Not_Available_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/Air_Strike_Available_Mat.Air_Strike_Available_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/Air_Strike_Ready_Mat.Air_Strike_Ready_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/Air_Strike_Firing_Mat.Air_Strike_Firing_Mat'"), NULL, LOAD_None, NULL)
	};
	tCLU = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_optics_CLU_Mat.hud_optics_CLU_Mat'"), NULL, LOAD_None, NULL);
	tMedPack = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/ui_hud_medpack_Mat.ui_hud_medpack_Mat'"), NULL, LOAD_None, NULL);
	tFirstAidKit = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/ui_hud_healing_Mat.ui_hud_healing_Mat'"), NULL, LOAD_None, NULL);
	tBreacher = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_wpn_db_Mat.hud_wpn_db_Mat'"), NULL, LOAD_None, NULL);
	tInvObjective = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/ui_hud_carriable_Mat.ui_hud_carriable_Mat'"), NULL, LOAD_None, NULL);
}

void UHUDTaskDisplay::Destroyed()
{
	Super::Destroyed();
	tDiscard = nullptr;
	tReload = nullptr;
	tRecharge = nullptr;
	tRoll = nullptr;
	tJammed = nullptr;
	tLiveGrenade = nullptr;
	tSupported = nullptr;
	tROF_Single = nullptr;
	tROF_Burst = nullptr;
	tROF_Auto = nullptr;
	tROF_Grenade = nullptr;
	tSquadLeader = nullptr;
	tTeamLeader = nullptr;
	tTeamMember = nullptr;
	tIndigenous = nullptr;
	tSFCaptain = nullptr;
	tVIP = nullptr;
	tSFTeamLeader = nullptr;
	tJav_Targeting = nullptr;
	tJav_LockedOn = nullptr;
	tJav_TooClose = nullptr;
	tCLU = nullptr;
	tJav_Tube = nullptr;
}
void UHUDTaskDisplay::ProcessParams()
{
	int32 i = 0;
	if (_iParams == 1)
	{
		_bAlpha = true;
	}
	/*
	for (i = 0; i < 4; i++)
	{
		GrenadeClass[i] = class<Inventory>(DynamicLoadObject(GrenadeClassName[i], Class'Class'));
	}
	GrenadeClassGreenSmoke = class<Inventory>(DynamicLoadObject("AGP_Inventory.Throw_M83_GreenSmoke", Class'Class'));
	*/
}
void UHUDTaskDisplay::ScaleControl(UCanvas* Canvas)
{
	Super::ScaleControl(Canvas);
	Grenades_xsize = 32 * 0.75 * cFrame->fScaleX;
	Grenades_ysize = 32 * 0.75 * cFrame->fScaleY;
	Grenades_xspace = 11 * cFrame->fScaleX;
	Grenades_xposn = 450 * cFrame->fScaleX;
	Grenades_yposn = 560 * cFrame->fScaleY;
}

void UHUDTaskDisplay::Draw(UCanvas* Canvas)
{
	int32 oldstyle = 0;
	AGameReplicationInfo* GRI = nullptr;
	APlayerController* PC = nullptr;
	bool bIsVehicle = false;
	/*
	if (Canvas == nullptr || cFrame == nullptr || cFrame->cActor == nullptr || cFrame->cActor.Level == nullptr || cFrame->cActor.bDeleteMe || cFrame->cActor.Level.bDeleteMe)
	{
		return;
	}
	PC = cFrame->cHUD.PlayerOwner;
	GRI = PC.GameReplicationInfo;
	if (PC.bRadarIsVisible != bRadarIsVisibleLastFrame)
	{
		if (PC.bRadarIsVisible)
		{
			_Pos.X = 218;
			_Pos.Y = 558;
			ScaleControl(Canvas);
		}
		else
		{
			_Pos.X = 37;
			_Pos.Y = 558;
			ScaleControl(Canvas);
		}
	}
	bRadarIsVisibleLastFrame = PC.bRadarIsVisible;
	bIsVehicle = cFrame->cActor->IsA(AVehicle::StaticClass());
	oldstyle = Canvas.Style;
	Canvas.Style = 6;
	if (cFrame->cActor.GetWorld()->GetNetMode() != 0)
	{
		if (!GRI.bHUDHideObjectives && !PC.bHUDHideObjectives)
		{
			DrawRank(Canvas);
		}
	}
	if (!GRI.bHUDHideWeapon && !PC.bHUDHideWeapon && !bIsVehicle)
	{
		DrawAmmo(Canvas);
		DrawHolster(Canvas);
	}
	if (!GRI.bHUDHideGrenades && !PC.bHUDHideGrenades && !bIsVehicle)
	{
		DrawGrenades(Canvas);
		DrawBreacher(Canvas);
	}
	if (!GRI.bHUDHideOptics && !PC.bHUDHideOptics && !bIsVehicle)
	{
		DrawOptics(Canvas);
	}
	if (!GRI.bHUDHideMedical && !PC.bHUDHideMedical && !bIsVehicle)
	{
		DrawMedical(Canvas);
	}
	if (!GRI.bHUDHideTimer && !PC.bHUDHideTimer)
	{
		DrawTime(Canvas);
	}
	if (!HumanController(PC).bCFFShowSpotterToolMenu)
	{
		DrawObjectives(Canvas);
	}
	else
	{
		cFrame->cHUD.bShowObjectives = false;
	}
	DrawCompass(Canvas);
	if (!GRI.bHUDHideSupport && !PC.bHUDHideSupport)
	{
		DrawSupport(Canvas);
	}
	DrawInventoryObjectives(Canvas);
	Canvas.Style = oldstyle;
	*/
}
void UHUDTaskDisplay::DrawInventoryObjectives(UCanvas* Canvas)
{
	AAGP_Pawn* aPawn = nullptr;
	AAGP_ObjectiveInventory* OInv = nullptr;
	int32 PosX = 0;
	int32 PosY = 0;
	int32 sizeW = 0;
	int32 sizeH = 0;
	aPawn = Cast<AAGP_Pawn>(cFrame->cActor);
	if (aPawn == nullptr)
	{
		return;
	}
	/*
	OInv = aPawn.GetFirstObjectiveInventory();
	if (OInv != nullptr)
	{
		if (OInv.Objective != nullptr)
		{
			if (aPawn._InvMedPacks > 0)
			{
				PosX = 660 * cFrame->fScaleX;
				PosY = 530 * cFrame->fScaleY;
			}
			else
			{
				PosX = 660 * cFrame->fScaleX;
				PosY = 560 * cFrame->fScaleY;
			}
			sizeW = 24 * cFrame->fScaleX;
			sizeH = 24 * cFrame->fScaleY;
			Canvas.SetPos(PosX, PosY);
			Canvas.DrawTile(tInvObjective, sizeW, sizeH, 0, 0, tInvObjective.USize, tInvObjective.VSize);
		}
	}
	*/
}

void UHUDTaskDisplay::DrawOptics(UCanvas* Canvas)
{
	AAGP_Pawn* aPawn = nullptr;
	ABaseOptics* Optics = nullptr;
	UMaterialInstance* tOptics = nullptr;
	UMaterialInstance* tTemp = nullptr;
	AInventory* Inv = nullptr;
	aPawn = Cast<AAGP_Pawn>(cFrame->cActor);
	if (aPawn == nullptr)
	{
		return;
	}
	/*
	Optics = aPawn.GetOpticsDevice();
	if (Optics != nullptr)
	{
		tOptics = Texture(Optics.Icon);
		if (tOptics != nullptr)
		{
			Canvas.SetPos(592 * cFrame->fScaleX, 560 * cFrame->fScaleY);
			Canvas.DrawTile(tOptics, 24 * cFrame->fScaleX, 24 * cFrame->fScaleY, 0, 0, tOptics.USize, tOptics.VSize);
		}
	}
	Inv = aPawn.getHipInventory();
	if (Inv != nullptr && Inv->IsA(AWEAPON_Javelin::StaticClass()))
	{
		tTemp = tCLU;
		if (tTemp != nullptr)
		{
			if (Optics == nullptr)
			{
				Canvas.SetPos(592 * cFrame->fScaleX, 560 * cFrame->fScaleY);
			}
			else
			{
				Canvas.SetPos(592 * cFrame->fScaleX, 530 * cFrame->fScaleY);
			}
			Canvas.DrawTile(tTemp, 24 * cFrame->fScaleX, 24 * cFrame->fScaleY, 0, 0, tTemp.USize, tTemp.VSize);
		}
	}
	else
	{
		if (aPawn._InvBinoculars != 0 && aPawn.Weapon == nullptr || !aPawn.Weapon->IsA(AItem_Binoculars::StaticClass()) && aPawn.Weapon == nullptr || !aPawn.Weapon->IsA(AWEAPON_Javelin::StaticClass()))
		{
			tTemp = tBinoc[aPawn._InvBinoculars - 1];
			if (tTemp != nullptr && !aPawn.bHasCLU)
			{
				if (Optics == nullptr)
				{
					Canvas.SetPos(592 * cFrame->fScaleX, 560 * cFrame->fScaleY);
				}
				else
				{
					Canvas.SetPos(592 * cFrame->fScaleX, 530 * cFrame->fScaleY);
				}
				Canvas.DrawTile(tTemp, 24 * cFrame->fScaleX, 24 * cFrame->fScaleY, 0, 0, tTemp.USize, tTemp.VSize);
			}
		}
	}
	*/
}

void UHUDTaskDisplay::DrawHolster(UCanvas* Canvas)
{
	AAGP_Pawn* aPawn = nullptr;
	AAGP_Weapon* holsterweapon = nullptr;
	UMaterialInstance* wIcon = nullptr;
	aPawn = Cast<AAGP_Pawn>(cFrame->cActor);
	if (aPawn == nullptr)
	{
		return;
	}
	/*
	holsterweapon = Cast<AAGP_Weapon>(aPawn.getHolsterInventory());
	if (holsterweapon != nullptr && !holsterweapon->IsA(Aitem_headphones::StaticClass()))
	{
		wIcon = Texture(holsterweapon.IconMaterial);
		Canvas.SetPos(409 * cFrame->fScaleX, 557 * cFrame->fScaleY);
		Canvas.DrawTile(wIcon, 32 * cFrame->fScaleX, 32 * cFrame->fScaleY, 0, 0, wIcon.USize, wIcon.VSize);
	}
	*/
}

void UHUDTaskDisplay::DrawTime(UCanvas* Canvas)
{
	APawn* aPawn = nullptr;
	APlayerController* PC = nullptr;
	AGameReplicationInfo* GRI = nullptr;
	int32 minutes = 0;
	int32 Seconds = 0;
	float XL = 0;
	float YL = 0;
	aPawn = Cast<APawn>(cFrame->cActor);
	if (aPawn == nullptr)
	{
		return;
	}
	/*
	PC = Cast<APlayerController>(aPawn.Controller);
	if (PC == nullptr)
	{
		return;
	}
	GRI = PC.GameReplicationInfo;
	if (GRI == nullptr)
	{
		return;
	}
	if (GRI.TimeLimit < 0)
	{
		return;
	}
	Canvas.TextSize("0000:00", XL, YL);
	if (Cast<AAGP_HUD>(cFrame->cHUD).fSpectateTextOffset > 0)
	{
		Canvas.SetPos(777 * cFrame->fScaleX - XL / 2, Cast<AAGP_HUD>(cFrame->cHUD).fSpectateTextOffset + 5 * cFrame->fScaleY);
	}
	else
	{
		Canvas.SetPos(777 * cFrame->fScaleX - XL / 2, 64 * cFrame->fScaleY);
	}
	if (GRI.RemainingTime >= 0)
	{
		if (GRI.RemainingTime < 45 && GRI.RemainingTime > 0 || GRI.bRoundIsSuspended)
		{
			if (CheckFlashTime())
			{
				return;
			}
		}
		minutes = GRI.RemainingTime / 60;
		Seconds = GRI.RemainingTime % 60;
		Canvas.DrawText(TwoDigitString(minutes) + ":" + TwoDigitString(Seconds));
	}
	else
	{
		minutes = GRI.ElapsedTime / 60;
		Seconds = GRI.ElapsedTime % 60;
		Canvas.DrawText(TwoDigitString(minutes) + ":" + TwoDigitString(Seconds));
	}
	*/
}

FString UHUDTaskDisplay::TwoDigitString(int32 Num)
{
	if (Num < 10 && Num >= 0)
	{
		return "0" + Num;
	}
	else
	{
		return FString::FromInt(Num);
	}
	return "00";     //FAKE  /ELiZ
}
void UHUDTaskDisplay::DrawRank(UCanvas* Canvas)
{
	AAA2_PlayerState* PRI = nullptr;
	UMaterialInstance* tSquad = nullptr;
	/*
	if (cFrame->cActor == nullptr || !cFrame->cActor->IsA(APawn::StaticClass()))
	{
		return;
	}
	PRI = cFrame->cHUD.PlayerOwner.PlayerReplicationInfo;
	if (PRI.IsSquadLeader())
	{
		if (PRI.bSpecialForcesPS && PRI.bQualifiedSF)
		{
			tSquad = tSFCaptain;
		}
		else
		{
			if (PRI.bSpecialForcesPS && !PRI.bQualifiedSF)
			{
				tSquad = tIndigenous;
			}
			else
			{
				tSquad = tSquadLeader;
			}
		}
	}
	else
	{
		if (PRI.isTeamLeader())
		{
			if (PRI.bSpecialForcesPS && PRI.bQualifiedSF)
			{
				tSquad = tSFTeamLeader;
			}
			else
			{
				if (PRI.bSpecialForcesPS && !PRI.bQualifiedSF)
				{
					tSquad = tIndigenous;
				}
				else
				{
					tSquad = tTeamLeader;
				}
			}
		}
		else
		{
			if (PRI.bSpecialForcesPS && PRI.bQualifiedSF)
			{
				tSquad = tSquadLeader;
			}
			else
			{
				if (PRI.bSpecialForcesPS && !PRI.bQualifiedSF)
				{
					tSquad = tIndigenous;
				}
				else
				{
					tSquad = tTeamMember;
				}
			}
		}
	}
	if (PRI.bGuerrillaPS)
	{
		tSquad = tIndigenous;
	}
	if (PRI.bVIPPS)
	{
		tSquad = tVIP;
	}
	Canvas.SetPos(760 * cFrame->fScaleX, 26 * cFrame->fScaleY);
	Canvas.DrawTile(tSquad, 32 * cFrame->fScaleX, 32 * cFrame->fScaleY, 0, 0, tSquad.USize, tSquad.VSize);
	if (PRI.FT != 255)
	{
		Canvas.SetPos(760 - 16 * cFrame->fScaleX, 26 + 8 * cFrame->fScaleY);
		Canvas.DrawTile(tFT[PRI.FT], 32 / 2 * cFrame->fScaleX, 32 / 2 * cFrame->fScaleY, 0, 0, tFT[PRI.FT].USize, tFT[PRI.FT].VSize);
	}
	*/
}

void UHUDTaskDisplay::DrawMedical(UCanvas* Canvas)
{
	AAGP_Pawn* p = nullptr;
	FString Num = "";
	int32 PosX = 0;
	int32 PosY = 0;
	int32 sizeW = 0;
	int32 sizeH = 0;
	float XL = 0;
	float YL = 0;
	p = Cast<AAGP_Pawn>(cFrame->cActor);
	/*
	if (p != nullptr && p._InvMedPacks > 0)
	{
		PosX = 660 * cFrame->fScaleX;
		PosY = 560 * cFrame->fScaleY;
		sizeW = 24 * cFrame->fScaleX;
		sizeH = 24 * cFrame->fScaleY;
		Canvas.SetPos(PosX, PosY);
		Canvas.DrawTile(tMedPack, sizeW, sizeH, 0, 0, tMedPack.USize, tMedPack.VSize);
		Num = " " + p._InvMedPacks;
		Canvas.TextSize(Num, XL, YL);
		PosX += sizeW - XL + 14;
		Canvas.SetPos(PosX, PosY);
		Canvas.DrawText(Num);
	}
	if (p != nullptr && p._InvSelfHealMedPacks > 0)
	{
		PosX = 766 * cFrame->fScaleX;
		PosY = 526 * cFrame->fScaleY;
		sizeW = 16 * cFrame->fScaleX;
		sizeH = 16 * cFrame->fScaleY;
		Canvas.SetPos(PosX, PosY);
		Canvas.DrawTile(tFirstAidKit, sizeW, sizeH, 0, 0, tFirstAidKit.USize, tFirstAidKit.VSize);
	}
	*/
}

void UHUDTaskDisplay::DrawBreacher(UCanvas* Canvas)
{
	AAGP_Pawn* p = nullptr;
	int32 PosX = 0;
	int32 PosY = 0;
	int32 sizeW = 0;
	int32 sizeH = 0;
	float XL = 0;
	float YL = 0;
	FString AmmoCount = "";
	int32 Num  = 0;
	p = Cast<AAGP_Pawn>(cFrame->cActor);
	/*
	if (DoorBreacher == nullptr)
	{
		DoorBreacher = class<Inventory>(DynamicLoadObject(Breachername, Class'Class'));
	}
	AmmoCount = " " + Cast<AAGP_Pawn>(cFrame->cActor).CountInventoryType(DoorBreacher);
	Num = AmmoCount;
	if (p != nullptr && Num > 0)
	{
		PosX = 623 * cFrame->fScaleX;
		PosY = 558 * cFrame->fScaleY;
		sizeW = 28 * cFrame->fScaleX;
		sizeH = 28 * cFrame->fScaleY;
		Canvas.SetPos(PosX, PosY);
		Canvas.DrawTile(tBreacher, sizeW, sizeH, 0, 0, tBreacher.USize, tBreacher.VSize);
		Canvas.TextSize(AmmoCount, XL, YL);
		PosX += sizeW - XL + 8;
		Canvas.SetPos(PosX, PosY);
		Canvas.DrawText(AmmoCount);
	}
	*/
}

void UHUDTaskDisplay::DrawGrenades(UCanvas* Canvas)
{
	int32 i = 0;
	int32 PosX = 0;
	int32 PosY = 0;
	float XL = 0;
	float YL = 0;
	FString AmmoCount = "";
	UMaterialInstance* grenTex = nullptr;
	/*
	Canvas.Font = cFrame->GetProperSizeFont(Canvas);
	for (i = 0; i < 4; i++)
	{
		PosX = Grenades_xposn + i * Grenades_xsize + Grenades_xspace;
		PosY = Grenades_yposn;
		Canvas.SetPos(PosX, PosY);
		grenTex = Texture(GrenadeClass[i].Default.IconMaterial);
		Canvas.DrawTile(grenTex, Grenades_xsize, Grenades_ysize, 0, 0, grenTex.USize, grenTex.VSize);
		AmmoCount = " " + Cast<AAGP_Pawn>(cFrame->cActor).CountInventoryType(GrenadeClass[i]);
		if (i == 1 && GrenadeClassGreenSmoke != nullptr && Cast<AAGP_Pawn>(cFrame->cActor).CountInventoryType(GrenadeClassGreenSmoke) > 0)
		{
			AmmoCount = AmmoCount + "/" + Cast<AAGP_Pawn>(cFrame->cActor).CountInventoryType(GrenadeClassGreenSmoke);
			PosX += 8;
		}
		Canvas.TextSize(AmmoCount, XL, YL);
		PosX += Grenades_xsize - XL + 8;
		Canvas.SetPos(PosX, PosY);
		Canvas.DrawText(AmmoCount);
	}
	*/
}

UFont* UHUDTaskDisplay::GetStatusFont(UCanvas* Canvas)
{
	/*
	if (_bAllowScaling)
	{
		if (Canvas.SizeX <= 640)
		{
			return cFrame->Fonts[0];
		}
		else
		{
			if (Canvas.SizeX <= 800)
			{
				return cFrame->Fonts[1];
			}
			else
			{
				if (Canvas.SizeX <= 1024)
				{
					return cFrame->Fonts[3];
				}
				else
				{
					if (Canvas.SizeX <= 1280)
					{
						return cFrame->Fonts[4];
					}
					else
					{
						if (Canvas.SizeX <= 1600)
						{
							return cFrame->Fonts[5];
						}
						else
						{
							return cFrame->Fonts[5];
						}
					}
				}
			}
		}
	}
	else
	{
		return cFrame->Fonts[3];
	}
	*/
	return nullptr;   //FAKE   /ELiZ
}

void UHUDTaskDisplay::DrawAmmo(UCanvas* Canvas)
{
	AAGP_Weapon* Weapon = nullptr;
	float XL = 0;
	float YL = 0;
	UMaterialInstance* tStatus = nullptr;
	UMaterialInstance* tAmmo = nullptr;
	UMaterialInstance* wIcon = nullptr;
	UMaterialInstance* tElevation = nullptr;
	FString sStatus = "";
	int32 PosX = 0;
	int32 PosY = 0;
	FString AmmoCount = "";
	bool bFlash = false;
	AGameReplicationInfo* GRI = nullptr;
	APlayerController* PC = nullptr;
	FString sShift = "";
	/*
	PC = cFrame->cHUD.PlayerOwner;
	if (cFrame->cActor != nullptr)
	{
		Weapon = Cast<AAGP_Weapon>(Cast<AAGP_Pawn>(cFrame->cActor).Weapon);
		if (Weapon != nullptr && !Weapon->IsA(Aitem_headphones::StaticClass()))
		{
			if (Weapon.IconMaterial != nullptr)
			{
				Canvas.SetPos(_ScaledPos.X, _ScaledPos.Y);
				if (Weapon.IsSupported())
				{
					wIcon = Texture(Weapon.IconMaterial);
				}
				else
				{
					wIcon = Weapon.GetSupportIcon();
				}
				if (Weapon->IsA(AThrowWeapon::StaticClass()))
				{
					Canvas.DrawTile(wIcon, 32 * cFrame->fScaleX, 32 * cFrame->fScaleY, 0, 0, wIcon.USize, wIcon.VSize);
				}
				else
				{
					if (Weapon->IsA(APistolWeapon::StaticClass()))
					{
						if (PC.bRadarIsVisible)
						{
							Canvas.SetPos(222 * cFrame->fScaleX, 553 * cFrame->fScaleY);
						}
						else
						{
							Canvas.SetPos(41 * cFrame->fScaleX, 553 * cFrame->fScaleY);
						}
						Canvas.DrawTile(wIcon, 32 * cFrame->fScaleX * 1.5, 32 * cFrame->fScaleY * 1.5, 0, 0, wIcon.USize, wIcon.VSize);
					}
					else
					{
						Canvas.DrawTile(wIcon, _ScaledPos.W, _ScaledPos.H, 0, 0, wIcon.USize, wIcon.VSize);
					}
				}
			}
			if (Weapon.bDrawOnHUD)
			{
				GRI = PC.GameReplicationInfo;
				if (Weapon.AmmoType != nullptr)
				{
					PosX = _ScaledPos.X + _ScaledPos.W + 0 * cFrame->fScaleX;
					PosY = _ScaledPos.Y + 0 * cFrame->fScaleY;
					Canvas.SetPos(PosX, PosY);
					tAmmo = Texture(Weapon.AmmoType.IconMaterial);
					Canvas.DrawTile(tAmmo, 32 * cFrame->fScaleX, 32 * cFrame->fScaleY, 0, 0, tAmmo.USize, tAmmo.VSize);
					if (!GRI.bHUDHideAmmoCount && !PC.bHUDHideAmmoCount)
					{
						AmmoCount = "" + Weapon.AmmoType.AmmoAmount;
						if (!Weapon.SingleShotWeapon())
						{
							AmmoCount = AmmoCount + "/" + Weapon.AmmoMagCount;
						}
					}
					else
					{
						if (Weapon.SingleShotWeapon())
						{
							AmmoCount = "" + Weapon.AmmoType.AmmoAmount;
						}
						else
						{
							AmmoCount = "" + Weapon.AmmoMagCount;
						}
					}
					Canvas.TextSize(AmmoCount, XL, YL);
					PosX += 32 * cFrame->fScaleX - XL / 2;
					PosY -= YL;
					Canvas.SetPos(PosX, PosY);
					Canvas.DrawText(AmmoCount);
				}
				if (Weapon.AuxAmmoType != nullptr)
				{
					if (!GRI.bHUDHideGrenades && !PC.bHUDHideGrenades)
					{
						PosX = _ScaledPos.X + _ScaledPos.W + 32 * cFrame->fScaleX + 0 * cFrame->fScaleX + 0 * cFrame->fScaleX;
						PosY = _ScaledPos.Y + 0 * cFrame->fScaleY;
						Canvas.SetPos(PosX, PosY);
						tAmmo = Texture(Weapon.AuxAmmoType.IconMaterial);
						Canvas.DrawTile(tAmmo, 32 * cFrame->fScaleX, 32 * cFrame->fScaleY, 0, 0, tAmmo.USize, tAmmo.VSize);
						AmmoCount = "" + Weapon.AuxAmmoType.AmmoAmount + "/" + Weapon.AuxAmmoMagCount;
						Canvas.TextSize(AmmoCount, XL, YL);
						PosX += 32 * cFrame->fScaleX - XL / 2;
						PosY -= YL;
						Canvas.SetPos(PosX, PosY);
						Canvas.DrawText(AmmoCount);
					}
				}
				if (Weapon.GetCurrentAmmoType() != nullptr && Weapon.ElevationIcon.Num() != 0 && !GRI.bHUDHideWeaponStatus && !PC.bHUDHideWeaponStatus && Weapon.IsZoomed())
				{
					PosX = 200 * cFrame->fScaleX;
					PosY = 560 * cFrame->fScaleY;
					Canvas.SetPos(PosX, PosY);
					tElevation = Weapon.ElevationIcon[Weapon.ElevationIndex];
					if (tElevation != nullptr)
					{
						Canvas.DrawTile(tElevation, 32 * cFrame->fScaleX, 32 * cFrame->fScaleY, 0, 0, tElevation.USize, tElevation.VSize);
					}
				}
				if (!GRI.bHUDHideWeaponStatus && !PC.bHUDHideWeaponStatus)
				{
					tStatus = nullptr;
					sStatus = "";
					bFlash = false;
					if (Weapon->IsA(AJavelin_Tube::StaticClass()))
					{
						tStatus = tJav_Tube;
						sStatus = "Jav Tube";
						bFlash = false;
					}
					else
					{
						if (Weapon->IsA(AThrowWeapon::StaticClass()))
						{
							if (Cast<AThrowWeapon>(Weapon).IsLostSpoon())
							{
								tStatus = tLiveGrenade;
								sStatus = "Live Grenade";
								bFlash = true;
							}
							else
							{
								if (Cast<AThrowWeapon>(Weapon).IsTossNotThrow())
								{
									tStatus = tRoll;
									sStatus = "Roll";
								}
							}
						}
						else
						{
							if (Weapon->IsA(AItem_Binoculars::StaticClass()))
							{
								if (Weapon->IsA(AItem_VIPER::StaticClass()))
								{
									switch(Weapon.GetStateName())
									{
											case 'LockedOn':
												tStatus = tJav_LockedOn;
												sStatus = "Locked On";
												bFlash = false;
												break;
											case 'Targeting':
											case 'Paint':
												if (Weapon.IsZoomed())
												{
													tStatus = tJav_Targeting;
													sStatus = "Targeting";
													bFlash = true;
												}
												else
												{
													tStatus = tROF_Single;
													sStatus = "Single";
													bFlash = false;
												}
											default:
												tStatus = tROF_Single;
												sStatus = "Single";
												bFlash = false;
									}
								}
								else
								{
									if (Cast<AHumanController>(PC) != nullptr && Cast<AHumanController>(PC).bMortarSpotter && Weapon.IsZoomed())
									{
										Canvas.SetPos(544 * cFrame->fScaleX, 56 + 260 * cFrame->fScaleY);
										Canvas.DrawText("CFF RNG: " + Cast<AHumanController>(PC).iSpotterPolarRangeSetting + "m");
										sShift = "";
										if (Cast<AHumanController>(PC).bCFFShowSpotterToolMenu)
										{
											Canvas.SetPos(544 * cFrame->fScaleX, 56 * cFrame->fScaleY);
											Canvas.DrawTile(textSpotterOverlayMenu, 256, 256, 0, 0, textSpotterOverlayMenu.USize, textSpotterOverlayMenu.VSize);
											if (PC.bFire == 1)
											{
												if (cFrame->cActor.GetWorld()->GetTimeSeconds() - fpTimeSinceLastMenuIconClicked > 0.1)
												{
													if (ProcessSpotterMenuNumpad(PC, PC.Player.WindowsMouseX - 544 * cFrame->fScaleX, PC.Player.WindowsMouseY - 56 * cFrame->fScaleY))
													{
														Cast<AHumanController>(PC).Player.bShowWindowsMouse = false;
														Cast<AHumanController>(PC).bCFFShowSpotterToolMenu = false;
														Cast<AHumanController>(PC).LockPlayer(false, false);
													}
												}
												fpTimeSinceLastMenuIconClicked = cFrame->cActor.GetWorld()->GetTimeSeconds();
											}
										}
										else
										{
											if (PC.bFire == 1 && cFrame->cActor.GetWorld()->GetTimeSeconds() - fpTimeSinceLastMenuIconClicked > 0.1)
											{
												LaserSpotterRange(PC);
											}
										}
										if (Len(sAdjustFireDirection) > 0)
										{
											sShift = sAdjustFireDirection + " " + iAdjustFireAdjustment + "m";
										}
										else
										{
											if (iAdjustFireAdjustment > 0)
											{
												sShift = "(INVADJ) " + iAdjustFireAdjustment + "m";
											}
										}
										if (Len(sShift) > 0)
										{
											Canvas.SetPos(544 * cFrame->fScaleX, 56 + 290 * cFrame->fScaleY);
											Canvas.DrawText("CFF Shift " + sShift);
										}
										if (iLaserRange > 0)
										{
											sShift = "LSR RNG: " + iLaserRange + "m";
											if (cFrame->cActor.GetWorld()->GetTimeSeconds() - fpTimeLastLaserUse < 2)
											{
												sShift = sShift + " (CHG: " + cFrame->cActor.GetWorld()->GetTimeSeconds() - fpTimeLastLaserUse / 2 * 100 + "%)";
											}
											Canvas.SetPos(544 * cFrame->fScaleX, 56 + 275 * cFrame->fScaleY);
											Canvas.DrawText(sShift);
										}
									}
									else
									{
										if (Cast<AHumanController>(PC).bCFFShowSpotterToolMenu)
										{
											Cast<AHumanController>(PC).bCFFShowSpotterToolMenu = false;
											Cast<AHumanController>(PC).Player.bShowWindowsMouse = false;
											Cast<AHumanController>(PC).LockPlayer(false, false);
										}
										iLaserRange = 0;
									}
								}
							}
							else
							{
								if (Weapon.IsJammed())
								{
									tStatus = tJammed;
									sStatus = "Fix Jam";
									bFlash = true;
								}
								else
								{
									if (Weapon.OutOfAmmo())
									{
										if (Weapon.SingleShotWeapon())
										{
											tStatus = tDiscard;
											sStatus = "Discard";
										}
										else
										{
											tStatus = tReload;
											sStatus = "Reload";
										}
										bFlash = true;
									}
									else
									{
										if (!Weapon.IsCharged())
										{
											tStatus = tRecharge;
											sStatus = "Recharge";
											bFlash = true;
										}
										else
										{
											if (Weapon.IsSupported())
											{
												tStatus = tSupported;
												sStatus = "Supported";
											}
											else
											{
												if (Weapon->IsA(AWEAPON_Javelin::StaticClass()))
												{
													switch(Weapon.GetStateName())
													{
											case 'LockedOn':
												tStatus = tJav_LockedOn;
												sStatus = "Locked On";
												bFlash = false;
												break;
											case 'Targeting':
												tStatus = tJav_Targeting;
												sStatus = "Targeting";
												bFlash = true;
												break;
											case 'TooClose':
												tStatus = tJav_TooClose;
												sStatus = "Too Close";
												bFlash = true;
												break;
											default:
												tStatus = tROF_Single;
												sStatus = "Single";
												bFlash = false;
												break;
													}
												}
												else
												{
													switch(Weapon.eROF)
													{
											case 2:
												tStatus = tROF_Burst;
												sStatus = "Burst";
												break;
											case 3:
												tStatus = tROF_Auto;
												sStatus = "Auto";
												break;
											case 4:
												tStatus = tROF_Grenade;
												sStatus = "Grenade";
												break;
											case 1:
											default:
												tStatus = tROF_Single;
												sStatus = "Single";
												break;
													}
												}
											}
										}
									}
								}
							}
						}
					}
					if (tStatus != nullptr)
					{
						Canvas.SetPos(_ScaledPos.X + _ScaledPos.W / 2 - 29, _ScaledPos.Y - _ScaledPos.H / 2);
						if (bFlash)
						{
							bWeaponMsgFlashing = CheckFlashTime();
						}
						else
						{
							bWeaponMsgFlashing = false;
						}
						if (!bWeaponMsgFlashing)
						{
							Canvas.Font = GetStatusFont(Canvas);
							Canvas.DrawText(sStatus);
						}
					}
				}
			}
		}
		if (Cast<AAGP_Pawn>(cFrame->cActor).getInvContainerShoulder() != nullptr)
		{
			Weapon = Cast<AAGP_Weapon>(Cast<AAGP_Pawn>(cFrame->cActor).getInvContainerShoulder().getFirstItem());
			if (Weapon != nullptr && !Weapon->IsA(Aitem_headphones::StaticClass()))
			{
				if (Weapon.IsSupported())
				{
					wIcon = Texture(Weapon.IconMaterial);
				}
				else
				{
					wIcon = Weapon.GetSupportIcon();
				}
				if (wIcon != nullptr)
				{
					Canvas.SetPos(_ScaledPos.X - 29, _ScaledPos.Y - _ScaledPos.H / 2);
					wIcon = Texture(Weapon.IconMaterial);
					Canvas.DrawTile(wIcon, _ScaledPos.W / 2, _ScaledPos.H / 2, 0, 0, wIcon.USize, wIcon.VSize);
				}
			}
		}
		if (Cast<AAGP_Pawn>(cFrame->cActor).getInvContainerAltShoulder() != nullptr)
		{
			Weapon = Cast<AAGP_Weapon>(Cast<AAGP_Pawn>(cFrame->cActor).getInvContainerAltShoulder().getFirstItem());
			if (Weapon != nullptr && !Weapon->IsA(Aitem_headphones::StaticClass()))
			{
				if (Weapon.IsSupported())
				{
					wIcon = Texture(Weapon.IconMaterial);
				}
				else
				{
					wIcon = Weapon.GetSupportIcon();
				}
				if (wIcon != nullptr)
				{
					Canvas.SetPos(_ScaledPos.X, _ScaledPos.Y - _ScaledPos.H / 2 * 0.975);
					wIcon = Texture(Weapon.IconMaterial);
					Canvas.DrawTile(wIcon, _ScaledPos.W / 2, _ScaledPos.H / 2, 0, 0, wIcon.USize, wIcon.VSize);
				}
			}
		}
	}
	*/
}
void UHUDTaskDisplay::DrawObjectives(UCanvas* Canvas)
{
	/*
	AGameReplicationInfo* GRI = nullptr;
	APlayerController* PC = nullptr;
	PC = cFrame->cHUD.PlayerOwner;
	GRI = PC.GameReplicationInfo;
	cFrame->cHUD.bShowObjectives = !GRI.bHUDHideObjectives && !PC.bHUDHideObjectives;
	*/
}
void UHUDTaskDisplay::DrawCompass(UCanvas* Canvas)
{
	/*
	AGameReplicationInfo* GRI = nullptr;
	APlayerController* PC = nullptr;
	PC = cFrame->cHUD.PlayerOwner;
	GRI = PC.GameReplicationInfo;
	*/
}
void UHUDTaskDisplay::DrawRadar(UCanvas* Canvas)
{
}
void UHUDTaskDisplay::InitializeSupport()
{
	ACallForSupport* S = nullptr;
	/*
	return;
	if (bInitializedSupport)
	{
		return;
	}
	ForEach cFrame->cActor.DynamicActors('CallForSupport', S)
	{
		if (S->IsA(AAirStrike::StaticClass()))
		{
			if (S.TeamNumber == Cast<APawn>(cFrame->cActor).PlayerReplicationInfo.Team.TeamIndex)
			{
				bInitializedSupport = true;
				Support = S;
			}
		}
	}
	*/
}
void UHUDTaskDisplay::DrawSupport(UCanvas* Canvas)
{
	int32 PosX = 0;
	int32 PosY = 0;
	int32 sizeW = 0;
	int32 sizeH = 0;
	float XL = 0;
	float YL = 0;
	AAGP_Pawn* aPawn = nullptr;
	AHumanController* HC = nullptr;
	APlayerController* PC = nullptr;
	AGameReplicationInfo* GRI = nullptr;
	ACallForSupport* S = nullptr;
	int32 Num = 0;
	UMaterialInstance* tTemp = nullptr;
	aPawn = Cast<AAGP_Pawn>(cFrame->cActor);
	if (aPawn == nullptr)
	{
		return;
	}
	/*
	PC = Cast<APlayerController>(aPawn.Controller);
	if (PC == nullptr)
	{
		return;
	}
	GRI = PC.GameReplicationInfo;
	if (GRI == nullptr)
	{
		return;
	}
	HC = Cast<AHumanController>(PC);
	if (HC == nullptr)
	{
		return;
	}
	InitializeSupport();
	if (Support != nullptr)
	{
		S = Support;
		Num = S.StrikesAvailable;
		if (Num > 0)
		{
			PosX = 8 * cFrame->fScaleX;
			PosY = 410 * cFrame->fScaleY;
			sizeW = 32 * cFrame->fScaleX;
			sizeH = 32 * cFrame->fScaleY;
			tTemp = tSupport[0];
			if (S.bAvailable)
			{
				tTemp = tSupport[1];
				if (S.bReady)
				{
					tTemp = tSupport[2];
					if (S.bFiring)
					{
						tTemp = tSupport[3];
					}
				}
			}
			if (tTemp != nullptr)
			{
				Canvas.SetPos(PosX, PosY);
				Canvas.DrawTile(tTemp, sizeW, sizeH, 0, 0, tTemp.USize, tTemp.VSize);
			}
			Canvas.TextSize(Num, XL, YL);
			PosX += sizeW - XL;
			PosY += sizeH;
			Canvas.SetPos(PosX, PosY);
			Canvas.DrawText(Num);
		}
	}
	*/
}

bool UHUDTaskDisplay::CheckFlashTime()
{
	float deltaT = 0;
	float deltaF = 0;
	/*
	deltaT = cFrame->cActor.GetWorld()->GetTimeSeconds() - fLastFlashTime;
	deltaF = 1 / 2 * 2;
	if (deltaT > deltaF * 2)
	{
		fLastFlashTime = cFrame->cActor.GetWorld()->GetTimeSeconds();
		return false;
	}
	else
	{
		if (deltaT > deltaF)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	*/
	return false;   //FAKE   /EliZ
}
void UHUDTaskDisplay::SetCurrentTask(int32 task)
{
	_iCurrentTask = task;
}
int32 UHUDTaskDisplay::GetCurrentTask()
{
	return _iCurrentTask;
}
bool UHUDTaskDisplay::ProcessSpotterMenu(APlayerController* PC, int32 iMenuX, int32 iMenuY)
{
	/*
	if (iMenuX < 0 || iMenuY < 0 || iMenuX > 256 || iMenuY > 256)
	{
		return false;
	}
	if (iMenuY >= 7 && iMenuY < 49)
	{
		if (iMenuX >= 7 && iMenuX < 79)
		{
			Cast<AHumanController>(PC).CFFPolarSuppressInfantry();
			return true;
		}
		if (iMenuX >= 89 && iMenuX < 158)
		{
			Cast<AHumanController>(PC).CFFPolarSuppressVehicle();
			return true;
		}
		if (iMenuX >= 174 && iMenuX < 240)
		{
			Cast<AHumanController>(PC).CFFPolarSmoke();
			return true;
		}
		return false;
	}
	if (iMenuY >= 59 && iMenuY < 102 && iMenuX >= 31 && iMenuX <= 77)
	{
		Cast<AHumanController>(PC).CFFCancel();
		return true;
	}
	if (iMenuY >= 59 && iMenuY < 102 && iMenuX >= 103 && iMenuX <= 146)
	{
		Cast<AHumanController>(PC).CFFFire();
		return true;
	}
	if (iMenuY >= 59 && iMenuY < 102 && iMenuX >= 170 && iMenuX <= 218)
	{
		Cast<AHumanController>(PC).CFFCheckFire();
		return true;
	}
	if (iMenuY >= 87 && iMenuY < 157 && iMenuX >= 197 && iMenuX <= 237)
	{
		Cast<AHumanController>(PC).iSpotterShiftLeftRight = 0;
		Cast<AHumanController>(PC).iSpotterShiftAddDrop = 0;
		return false;
	}
	if (iMenuY >= 87 && iMenuY < 157 && iMenuX >= 19 && iMenuX <= 67)
	{
		Cast<AHumanController>(PC).CFFRepeat();
		return true;
	}
	if (iMenuY >= 87 && iMenuY < 157 && iMenuX >= 116 && iMenuX <= 168)
	{
		Cast<AHumanController>(PC).iSpotterShiftAddDrop++;
		return false;
	}
	if (iMenuY >= 203 && iMenuY < 245 && iMenuX >= 116 && iMenuX <= 168)
	{
		Cast<AHumanController>(PC).iSpotterShiftAddDrop--;
		return false;
	}
	if (iMenuY >= 160 && iMenuY < 202 && iMenuX >= 2 && iMenuX <= 84)
	{
		Cast<AHumanController>(PC).iSpotterShiftLeftRight--;
		return false;
	}
	if (iMenuY >= 160 && iMenuY < 202 && iMenuX >= 171 && iMenuX <= 254)
	{
		Cast<AHumanController>(PC).iSpotterShiftLeftRight++;
		return false;
	}
	if (iMenuY >= 160 && iMenuY < 202 && iMenuX >= 90 && iMenuX <= 165)
	{
		if (Cast<AHumanController>(PC).iSpotterShiftLeftRight > 0)
		{
			Cast<AHumanController>(PC).CFFAdjustFire("RIGHT", Abs(Cast<AHumanController>(PC).iSpotterShiftLeftRight));
			Cast<AHumanController>(PC).iSpotterShiftLeftRight = 0;
			return true;
		}
		else
		{
			if (Cast<AHumanController>(PC).iSpotterShiftLeftRight < 0)
			{
				Cast<AHumanController>(PC).CFFAdjustFire("LEFT", Abs(Cast<AHumanController>(PC).iSpotterShiftLeftRight));
				Cast<AHumanController>(PC).iSpotterShiftLeftRight = 0;
				return true;
			}
		}
		if (Cast<AHumanController>(PC).iSpotterShiftAddDrop > 0)
		{
			Cast<AHumanController>(PC).CFFAdjustFire("ADD", Abs(Cast<AHumanController>(PC).iSpotterShiftAddDrop));
			Cast<AHumanController>(PC).iSpotterShiftAddDrop = 0;
			return true;
		}
		else
		{
			if (Cast<AHumanController>(PC).iSpotterShiftAddDrop < 0)
			{
				Cast<AHumanController>(PC).CFFAdjustFire("DROP", Abs(Cast<AHumanController>(PC).iSpotterShiftAddDrop));
				Cast<AHumanController>(PC).iSpotterShiftAddDrop = 0;
				return true;
			}
		}
		return true;
	}
	*/
	return false;
}
void UHUDTaskDisplay::LaserSpotterRange(APlayerController* PC)
{
	AActor* actHit = nullptr;
	FVector StartTrace = FVector(0,0,0);
	FVector EndTrace = FVector(0, 0, 0);
	FVector HitLocation = FVector(0, 0, 0);
	FVector HitNormal = FVector(0, 0, 0);
	FRotator CameraRotation = FRotator(0, 0, 0);
	/*
	if (Cast<AHumanController>(PC).bCFFDisableLaser)
	{
		iLaserRange = 0;
		return;
	}
	if (cFrame->cActor.GetWorld()->GetTimeSeconds() - fpTimeLastLaserUse > 2)
	{
		Cast<AHumanController>(PC).PlayerCalcView(actHit, StartTrace, CameraRotation);
		EndTrace = StartTrace + 100000 * Vector(CameraRotation);
		actHit = Cast<AHumanController>(PC).Trace(HitLocation, HitNormal, EndTrace, StartTrace, true);
		fpTimeLastLaserUse = cFrame->cActor.GetWorld()->GetTimeSeconds();
		iLaserRange = VSize(StartTrace - HitLocation) / 55;
	}
	*/
}
bool UHUDTaskDisplay::ProcessSpotterMenuNumpad(APlayerController* PC, int32 iMenuX, int32 iMenuY)
{
	/*
	if (iMenuX < 0 || iMenuY < 0 || iMenuX > 256 || iMenuY > 256)
	{
		return false;
	}
	Log("Player clicked on spotter menu at " + iMenuX + ", " + iMenuY);
	if (iMenuY >= 8 && iMenuY < 56)
	{
		if (iMenuX >= 8 && iMenuX < 76)
		{
			Cast<AHumanController>(PC).CFFPolarSuppressInfantry();
			return true;
		}
		if (iMenuX >= 89 && iMenuX < 158)
		{
			Cast<AHumanController>(PC).CFFPolarSuppressVehicle();
			return true;
		}
		if (iMenuX >= 174 && iMenuX < 240)
		{
			Cast<AHumanController>(PC).CFFPolarSmoke();
			return true;
		}
		return false;
	}
	if (iMenuY >= 59 && iMenuY < 102)
	{
		if (iMenuX >= 8 && iMenuX <= 56)
		{
			Cast<AHumanController>(PC).CFFCancel();
			return true;
		}
		if (iMenuX >= 71 && iMenuX <= 118)
		{
			Cast<AHumanController>(PC).CFFFire();
			return true;
		}
		if (iMenuX >= 132 && iMenuX <= 180)
		{
			Cast<AHumanController>(PC).CFFCheckFire();
			return true;
		}
		if (iMenuX >= 193 && iMenuX <= 240)
		{
			Cast<AHumanController>(PC).CFFRepeat();
			return true;
		}
		return false;
	}
	if (iMenuY >= 122 && iMenuY < 152)
	{
		if (iMenuX >= 8 && iMenuX <= 40)
		{
			if (iAdjustFireAdjustment > 0)
			{
				iAdjustFireAdjustment = iAdjustFireAdjustment * 10 + 1;
			}
			else
			{
				iAdjustFireAdjustment = 1;
			}
			return false;
		}
		if (iMenuX >= 46 && iMenuX <= 75)
		{
			if (iAdjustFireAdjustment > 0)
			{
				iAdjustFireAdjustment = iAdjustFireAdjustment * 10 + 2;
			}
			else
			{
				iAdjustFireAdjustment = 2;
			}
			return false;
		}
		if (iMenuX >= 80 && iMenuX <= 110)
		{
			if (iAdjustFireAdjustment > 0)
			{
				iAdjustFireAdjustment = iAdjustFireAdjustment * 10 + 3;
			}
			else
			{
				iAdjustFireAdjustment = 3;
			}
			return false;
		}
		if (iMenuX >= 157 && iMenuX <= 186)
		{
			sAdjustFireDirection = "ADD";
			return false;
		}
	}
	if (iMenuY >= 157 && iMenuY < 184)
	{
		if (iMenuX >= 8 && iMenuX <= 40)
		{
			if (iAdjustFireAdjustment > 0)
			{
				iAdjustFireAdjustment = iAdjustFireAdjustment * 10 + 4;
			}
			else
			{
				iAdjustFireAdjustment = 4;
			}
			return false;
		}
		if (iMenuX >= 46 && iMenuX <= 75)
		{
			if (iAdjustFireAdjustment > 0)
			{
				iAdjustFireAdjustment = iAdjustFireAdjustment * 10 + 5;
			}
			else
			{
				iAdjustFireAdjustment = 5;
			}
			return false;
		}
		if (iMenuX >= 80 && iMenuX <= 110)
		{
			if (iAdjustFireAdjustment > 0)
			{
				iAdjustFireAdjustment = iAdjustFireAdjustment * 10 + 6;
			}
			else
			{
				iAdjustFireAdjustment = 6;
			}
			return false;
		}
		if (iMenuX >= 123 && iMenuX <= 153)
		{
			sAdjustFireDirection = "LEFT";
			return false;
		}
		if (iMenuX >= 157 && iMenuX <= 186)
		{
			if (Len(sAdjustFireDirection) > 0)
			{
				Cast<AHumanController>(PC).CFFAdjustFire(sAdjustFireDirection, iAdjustFireAdjustment);
				return true;
			}
			return false;
		}
		if (iMenuX >= 192 && iMenuX <= 223)
		{
			sAdjustFireDirection = "RIGHT";
			return false;
		}
	}
	if (iMenuY >= 188 && iMenuY < 216)
	{
		if (iMenuX >= 8 && iMenuX <= 40)
		{
			if (iAdjustFireAdjustment > 0)
			{
				iAdjustFireAdjustment = iAdjustFireAdjustment * 10 + 7;
			}
			else
			{
				iAdjustFireAdjustment = 7;
			}
			return false;
		}
		if (iMenuX >= 46 && iMenuX <= 75)
		{
			if (iAdjustFireAdjustment > 0)
			{
				iAdjustFireAdjustment = iAdjustFireAdjustment * 10 + 8;
			}
			else
			{
				iAdjustFireAdjustment = 8;
			}
			return false;
		}
		if (iMenuX >= 80 && iMenuX <= 110)
		{
			if (iAdjustFireAdjustment > 0)
			{
				iAdjustFireAdjustment = iAdjustFireAdjustment * 10 + 9;
			}
			else
			{
				iAdjustFireAdjustment = 9;
			}
			return false;
		}
		if (iMenuX >= 157 && iMenuX <= 186)
		{
			sAdjustFireDirection = "DROP";
			return false;
		}
	}
	if (iMenuY >= 219 && iMenuY < 247)
	{
		if (iMenuX >= 8 && iMenuX <= 40)
		{
			if (iAdjustFireAdjustment > 0)
			{
				iAdjustFireAdjustment *= 10;
			}
			return false;
		}
		if (iMenuX >= 46 && iMenuX <= 75)
		{
			sAdjustFireDirection = "";
			iAdjustFireAdjustment = 0;
			Cast<AHumanController>(PC).iSpotterShiftLeftRight = 0;
			Cast<AHumanController>(PC).iSpotterShiftAddDrop = 0;
			return false;
		}
	}
	*/
	return false;
}
