// All the original content belonged to the US Army


#include "AA29/Object/UIBase/UIControl/UIHUDBaseDisplay/HUDTaskDisplay/HUDTaskDisplay.h"
UHUDTaskDisplay::UHUDTaskDisplay()
{
	//Breachername = "AGP_Inventory.Demo_DoorBreacher"
	//GrenadeClassName(0) = "AGP_Inventory.Throw_M67_Frag"
	//GrenadeClassName(1) = "AGP_Inventory.Throw_M83_Smoke"
	//GrenadeClassName(2) = "AGP_Inventory.Throw_M84_Stun"
	//GrenadeClassName(3) = "AGP_Inventory.Throw_M14_Incendiary"
	//textSpotterOverlayMenu = Texture'T_AA2_SpotterTools.MenuOverlays.BinocularOverlayNumpad'
	//tDiscard = Texture'T_AA2_UI.HUD.hud_mode_discard'
	//tReload = Texture'T_AA2_UI.HUD.hud_mode_reload'
	//tRecharge = Texture'T_AA2_UI.HUD.hud_mode_recharge'
	//tRoll = Texture'T_AA2_UI.HUD.hud_mode_roll'
	//tJammed = Texture'T_AA2_UI.HUD.hud_mode_fixjam'
	//tLiveGrenade = Texture'T_AA2_UI.HUD.hud_mode_livegrenade'
	//tSupported = Texture'T_AA2_UI.HUD.hud_mode_supported'
	//tROF_Single = Texture'T_AA2_UI.HUD.hud_mode_single'
	//tROF_Burst = Texture'T_AA2_UI.HUD.hud_mode_burst'
	//tROF_Auto = Texture'T_AA2_UI.HUD.hud_mode_auto'
	//tROF_Grenade = Texture'T_AA2_UI.HUD.hud_mode_grenade'
	//tJav_Targeting = Texture'T_AA2_UI.HUD.hud_mode_targeting'
	//tJav_LockedOn = Texture'T_AA2_UI.HUD.hud_mode_lockedon'
	//tJav_TooClose = Texture'T_AA2_UI.HUD.hud_mode_tooclose'
	//tJav_Tube = Texture'T_AA2_UI.HUD.hud_mode_javelintube'
	//tSquadLeader = Texture'T_AA2_UI.HUD.hud_rank_ssg'
	//tTeamLeader = Texture'T_AA2_UI.HUD.hud_rank_sgt'
	//tTeamMember = Texture'T_AA2_UI.HUD.hud_rank_pvt'
	//tIndigenous = Texture'T_AA2_UI.HUD.hud_rank_indigenous'
	//tSFCaptain = Texture'T_AA2_UI.HUD.hud_rank_captain'
	//tVIP = Texture'T_AA2_UI.HUD.hud_rank_VIP'
	//tSFTeamLeader = Texture'T_AA2_UI.HUD.hud_rank_staffsgt_1st'
		
	//tFT(0) = Texture'T_AA2_UI.HUD.hud_fireteam_a'
	//tFT(1) = Texture'T_AA2_UI.HUD.hud_fireteam_b'
	//tFT(2) = Texture'T_AA2_UI.HUD.hud_fireteam_c'
	//tFT(3) = Texture'T_AA2_UI.HUD.hud_fireteam_d'
		
	//tBinoc(0) = Texture'T_AA2_UI.HUD.hud_optics_BINOCS_m22'
	//tBinoc(1) = Texture'T_AA2_UI.HUD.hud_optics_BINOCS_m24'
	//tBinoc(2) = Texture'T_AA2_UI.HUD.hud_optics_BINOCS_tank'
	//tBinoc(3) = Texture'T_AA2_UI.HUD.hud_optics_BINOCS_newt'
	//tBinoc(4) = Texture'T_AA2_UI.HUD.hud_optics_binocs_VIPIR'
		
	//tSupport(0) = Texture'T_AA2_UI.HUD.Air_Strike_Not_Available'
	//tSupport(1) = Texture'T_AA2_UI.HUD.Air_Strike_Available'
	//tSupport(2) = Texture'T_AA2_UI.HUD.Air_Strike_Ready'
	//tSupport(3) = Texture'T_AA2_UI.HUD.Air_Strike_Firing'
		
	//tCLU = Texture'T_AA2_UI.HUD.hud_optics_CLU'
	//tMedPack = Texture'T_AA2_UI.HUD.ui_hud_medpack'
	//tFirstAidKit = Texture'T_AA2_UI.HUD.ui_hud_healing'
	//tBreacher = Texture'T_AA2_UI.HUD.hud_wpn_db'
	//tInvObjective = Texture'T_AA2_UI.HUD.ui_hud_carriable'
}

/*
static const kTaskNone = 0;
static const kTaskM16 = 1;
static const kTaskM249 = 2;
static const kTaskHelicopter = 3;
static const kNumTasks = 4;
static const kBasePosX = 218;
static const kBasePosY = 558;
static const kNoRadarPosX = 37;
static const kNoRadarPosY = 558;
static const kStatusOffsetX = 29;
static const kWeaponMsgPosW = 64;
static const kWeaponMsgPosH = 16;
static const kWeaponMsgFlashPS = 2.0;
static const kAmmoOffsetX = 0;
static const kAmmoOffsetY = 0;
static const kAmmoSpacingX = 0;
static const kAmmoW = 32;
static const kAmmoH = 32;
static const kSquadX = 760;
static const kSquadY = 26;
static const kSquadW = 32;
static const kSquadH = 32;
static const kHolsterX = 409;
static const kHolsterY = 557;
static const kPistolX = 222;
static const kPistolY = 553;
static const kNoRadarPistolX = 41;
static const kNoRadarPistolY = 553;
static const kOpticsX = 592;
static const kOpticsY = 560;
static const kOpticsW = 24;
static const kOpticsH = 24;
static const kSecondaryOpticsX = 592;
static const kSecondaryOpticsY = 530;
static const kMedPackX = 660;
static const kMedPackY = 560;
static const kMedPackW = 24;
static const kMedPackH = 24;
static const kFirstAidKitX = 766;
static const kFirstAidKitY = 526;
static const kFirstAidKitW = 16;
static const kFirstAidKitH = 16;
static const kTimePosX = 777;
static const kTimePosY = 64;
static const kGrenadeSpacingX = 11;
static const kGrenadePosX = 450;
static const kGrenadePosY = 560;
static const kGrenadeScale = 0.75;
static const kBreacherX = 623;
static const kBreacherY = 558;
static const kBreacherW = 28;
static const kBreacherH = 28;
static const kInvObjectiveX = 660;
static const kInvObjectiveY = 560;
static const kInvObjectiveW = 24;
static const kInvObjectiveH = 24;
static const kSecInvObjectiveX = 660;
static const kSecInvObjectiveY = 530;
static const kElevationX = 200;
static const kElevationY = 560;
static const kElevationW = 32;
static const kElevationH = 32;
static const kSupportX = 8;
static const kSupportY = 410;
static const kSupportW = 32;
static const kSupportH = 32;
static const kSpotterToolsMenuX = 544;
static const kSpotterToolsMenuY = 56;
static const NUM_GREN_TYPES = 4;
*/


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
	/*
	local int i;
	if (_iParams == 1)
	{
		_bAlpha = true;
	}
	for (i = 0; i < 4; i++)
	{
		GrenadeClass[i] = class<Inventory>(DynamicLoadObject(GrenadeClassName[i], Class'Class'));
	}
	GrenadeClassGreenSmoke = class<Inventory>(DynamicLoadObject("AGP_Inventory.Throw_M83_GreenSmoke", Class'Class'));
	*/
}
void UHUDTaskDisplay::ScaleControl(UCanvas* Canvas)
{
	//Super::ScaleControl(Canvas);
	/*
	Grenades_xsize = 32 * 0.75 * cFrame.fScaleX;
	Grenades_ysize = 32 * 0.75 * cFrame.fScaleY;
	Grenades_xspace = 11 * cFrame.fScaleX;
	Grenades_xposn = 450 * cFrame.fScaleX;
	Grenades_yposn = 560 * cFrame.fScaleY;
	*/
}
void UHUDTaskDisplay::Draw(UCanvas* Canvas)
{
	/*
	local int oldstyle;
	local GameReplicationInfo GRI;
	local PlayerController PC;
	local bool bIsVehicle;
	if (Canvas == None || cFrame == None || cFrame.cActor == None || cFrame.cActor.Level == None || cFrame.cActor.bDeleteMe || cFrame.cActor.Level.bDeleteMe)
	{
		Return;
	}
	PC = cFrame.cHUD.PlayerOwner;
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
	bIsVehicle = cFrame.cActor.IsA('Vehicle');
	oldstyle = Canvas.Style;
	Canvas.Style = 6;
	if (cFrame.cActor.Level.NetMode != 0)
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
		cFrame.cHUD.bShowObjectives = False;
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
	/*
	local AGP_Pawn aPawn;
	local AGP_ObjectiveInventory OInv;
	local int PosX;
	local int PosY;
	local int sizeW;
	local int sizeH;
	aPawn = AGP_Pawn(cFrame.cActor);
	if (aPawn == None)
	{
		Return;
	}
	OInv = aPawn.GetFirstObjectiveInventory();
	if (OInv != None)
	{
		if (OInv.Objective != None)
		{
			if (aPawn._InvMedPacks > 0)
			{
				PosX = 660 * cFrame.fScaleX;
				PosY = 530 * cFrame.fScaleY;
			}
			else
			{
				PosX = 660 * cFrame.fScaleX;
				PosY = 560 * cFrame.fScaleY;
			}
			sizeW = 24 * cFrame.fScaleX;
			sizeH = 24 * cFrame.fScaleY;
			Canvas.SetPos(PosX, PosY);
			Canvas.DrawTile(tInvObjective, sizeW, sizeH, 0, 0, tInvObjective.USize, tInvObjective.VSize);
		}
	}
	*/
}
void UHUDTaskDisplay::DrawOptics(UCanvas* Canvas)
{
	/*
	local AGP_Pawn aPawn;
	local BaseOptics Optics;
	local Texture tOptics;
	local Texture tTemp;
	local Inventory Inv;
	aPawn = AGP_Pawn(cFrame.cActor);
	if (aPawn == None)
	{
		Return;
	}
	Optics = aPawn.GetOpticsDevice();
	if (Optics != None)
	{
		tOptics = Texture(Optics.Icon);
		if (tOptics != None)
		{
			Canvas.SetPos(592 * cFrame.fScaleX, 560 * cFrame.fScaleY);
			Canvas.DrawTile(tOptics, 24 * cFrame.fScaleX, 24 * cFrame.fScaleY, 0, 0, tOptics.USize, tOptics.VSize);
		}
	}
	Inv = aPawn.getHipInventory();
	if (Inv != None && Inv.IsA('WEAPON_Javelin'))
	{
		tTemp = tCLU;
		if (tTemp != None)
		{
			if (Optics == None)
			{
				Canvas.SetPos(592 * cFrame.fScaleX, 560 * cFrame.fScaleY);
			}
			else
			{
				Canvas.SetPos(592 * cFrame.fScaleX, 530 * cFrame.fScaleY);
			}
			Canvas.DrawTile(tTemp, 24 * cFrame.fScaleX, 24 * cFrame.fScaleY, 0, 0, tTemp.USize, tTemp.VSize);
		}
	}
	else
	{
		if (aPawn._InvBinoculars != 0 && aPawn.Weapon == None || !aPawn.Weapon.IsA('Item_Binoculars') && aPawn.Weapon == None || !aPawn.Weapon.IsA('WEAPON_Javelin'))
		{
			tTemp = tBinoc[aPawn._InvBinoculars - 1];
			if (tTemp != None && !aPawn.bHasCLU)
			{
				if (Optics == None)
				{
					Canvas.SetPos(592 * cFrame.fScaleX, 560 * cFrame.fScaleY);
				}
				else
				{
					Canvas.SetPos(592 * cFrame.fScaleX, 530 * cFrame.fScaleY);
				}
				Canvas.DrawTile(tTemp, 24 * cFrame.fScaleX, 24 * cFrame.fScaleY, 0, 0, tTemp.USize, tTemp.VSize);
			}
		}
	}
	*/
}
void UHUDTaskDisplay::DrawHolster(UCanvas* Canvas)
{
	/*
	local AGP_Pawn aPawn;
	local AGP_Weapon holsterweapon;
	local Texture wIcon;
	aPawn = AGP_Pawn(cFrame.cActor);
	if (aPawn == None)
	{
		Return;
	}
	holsterweapon = AGP_Weapon(aPawn.getHolsterInventory());
	if (holsterweapon != None && !holsterweapon.IsA('item_headphones'))
	{
		wIcon = Texture(holsterweapon.IconMaterial);
		Canvas.SetPos(409 * cFrame.fScaleX, 557 * cFrame.fScaleY);
		Canvas.DrawTile(wIcon, 32 * cFrame.fScaleX, 32 * cFrame.fScaleY, 0, 0, wIcon.USize, wIcon.VSize);
	}
	*/
}
void UHUDTaskDisplay::DrawTime(UCanvas* Canvas)
{
	/*
	local Pawn aPawn;
	local PlayerController PC;
	local GameReplicationInfo GRI;
	local int minutes;
	local int Seconds;
	local float XL;
	local float YL;
	aPawn = Pawn(cFrame.cActor);
	if (aPawn == None)
	{
		Return;
	}
	PC = PlayerController(aPawn.Controller);
	if (PC == None)
	{
		Return;
	}
	GRI = PC.GameReplicationInfo;
	if (GRI == None)
	{
		Return;
	}
	if (GRI.TimeLimit < 0)
	{
		Return;
	}
	Canvas.TextSize("0000:00", XL, YL);
	if (AGP_HUD(cFrame.cHUD).fSpectateTextOffset > 0)
	{
		Canvas.SetPos(777 * cFrame.fScaleX - XL / 2, AGP_HUD(cFrame.cHUD).fSpectateTextOffset + 5 * cFrame.fScaleY);
	}
	else
	{
		Canvas.SetPos(777 * cFrame.fScaleX - XL / 2, 64 * cFrame.fScaleY);
	}
	if (GRI.RemainingTime >= 0)
	{
		if (GRI.RemainingTime < 45 && GRI.RemainingTime > 0 || GRI.bRoundIsSuspended)
		{
			if (CheckFlashTime())
			{
				Return;
			}
		}
		minutes = GRI.RemainingTime / 60;
		Seconds = GRI.RemainingTime % 60;
		Canvas.DrawText(TwoDigitString(minutes) $ ":" $ TwoDigitString(Seconds));
	}
	else
	{
		minutes = GRI.ElapsedTime / 60;
		Seconds = GRI.ElapsedTime % 60;
		Canvas.DrawText(TwoDigitString(minutes) $ ":" $ TwoDigitString(Seconds));
	}
	*/
}
void UHUDTaskDisplay::TwoDigitString(int32 Num)
{
	/*
	if (Num < 10 && Num >= 0)
	{
		return "0" $ Num;
	}
	else
	{
		return Num;
	}
	*/
}
void UHUDTaskDisplay::DrawRank(UCanvas* Canvas)
{
	/*
	local PlayerReplicationInfo PRI;
	local Texture tSquad;
	if (cFrame.cActor == None || !cFrame.cActor.IsA('Pawn'))
	{
		Return;
	}
	PRI = cFrame.cHUD.PlayerOwner.PlayerReplicationInfo;
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
	Canvas.SetPos(760 * cFrame.fScaleX, 26 * cFrame.fScaleY);
	Canvas.DrawTile(tSquad, 32 * cFrame.fScaleX, 32 * cFrame.fScaleY, 0, 0, tSquad.USize, tSquad.VSize);
	if (PRI.FT != 255)
	{
		Canvas.SetPos(760 - 16 * cFrame.fScaleX, 26 + 8 * cFrame.fScaleY);
		Canvas.DrawTile(tFT[PRI.FT], 32 / 2 * cFrame.fScaleX, 32 / 2 * cFrame.fScaleY, 0, 0, tFT[PRI.FT].USize, tFT[PRI.FT].VSize);
	}
	*/
}
void UHUDTaskDisplay::DrawMedical(UCanvas* Canvas)
{
	/*
	local AGP_Pawn p;
	local string Num;
	local int PosX;
	local int PosY;
	local int sizeW;
	local int sizeH;
	local float XL;
	local float YL;
	p = AGP_Pawn(cFrame.cActor);
	if (p != None && p._InvMedPacks > 0)
	{
		PosX = 660 * cFrame.fScaleX;
		PosY = 560 * cFrame.fScaleY;
		sizeW = 24 * cFrame.fScaleX;
		sizeH = 24 * cFrame.fScaleY;
		Canvas.SetPos(PosX, PosY);
		Canvas.DrawTile(tMedPack, sizeW, sizeH, 0, 0, tMedPack.USize, tMedPack.VSize);
		Num = " " $ p._InvMedPacks;
		Canvas.TextSize(Num, XL, YL);
		PosX += sizeW - XL + 14;
		Canvas.SetPos(PosX, PosY);
		Canvas.DrawText(Num);
	}
	if (p != None && p._InvSelfHealMedPacks > 0)
	{
		PosX = 766 * cFrame.fScaleX;
		PosY = 526 * cFrame.fScaleY;
		sizeW = 16 * cFrame.fScaleX;
		sizeH = 16 * cFrame.fScaleY;
		Canvas.SetPos(PosX, PosY);
		Canvas.DrawTile(tFirstAidKit, sizeW, sizeH, 0, 0, tFirstAidKit.USize, tFirstAidKit.VSize);
	}
	*/
}
void UHUDTaskDisplay::DrawBreacher(UCanvas* Canvas)
{
	/*
	local AGP_Pawn p;
	local int PosX;
	local int PosY;
	local int sizeW;
	local int sizeH;
	local float XL;
	local float YL;
	local string AmmoCount;
	local int Num;
	p = AGP_Pawn(cFrame.cActor);
	if (DoorBreacher == None)
	{
		DoorBreacher = class<Inventory>(DynamicLoadObject(Breachername, Class'Class'));
	}
	AmmoCount = " " $ AGP_Pawn(cFrame.cActor).CountInventoryType(DoorBreacher);
	Num = AmmoCount;
	if (p != None && Num > 0)
	{
		PosX = 623 * cFrame.fScaleX;
		PosY = 558 * cFrame.fScaleY;
		sizeW = 28 * cFrame.fScaleX;
		sizeH = 28 * cFrame.fScaleY;
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
	/*
	local int i;
	local int PosX;
	local int PosY;
	local float XL;
	local float YL;
	local string AmmoCount;
	local Texture grenTex;
	Canvas.Font = cFrame.GetProperSizeFont(Canvas);
	for (i = 0; i < 4; i++)
	{
		PosX = Grenades_xposn + i * Grenades_xsize + Grenades_xspace;
		PosY = Grenades_yposn;
		Canvas.SetPos(PosX, PosY);
		grenTex = Texture(GrenadeClass[i].Default.IconMaterial);
		Canvas.DrawTile(grenTex, Grenades_xsize, Grenades_ysize, 0, 0, grenTex.USize, grenTex.VSize);
		AmmoCount = " " $ AGP_Pawn(cFrame.cActor).CountInventoryType(GrenadeClass[i]);
		if (i == 1 && GrenadeClassGreenSmoke != None && AGP_Pawn(cFrame.cActor).CountInventoryType(GrenadeClassGreenSmoke) > 0)
		{
			AmmoCount = AmmoCount $ "/" $ AGP_Pawn(cFrame.cActor).CountInventoryType(GrenadeClassGreenSmoke);
			PosX += 8;
		}
		Canvas.TextSize(AmmoCount, XL, YL);
		PosX += Grenades_xsize - XL + 8;
		Canvas.SetPos(PosX, PosY);
		Canvas.DrawText(AmmoCount);
	}
	*/
}
void UHUDTaskDisplay::GetStatusFont(UCanvas* Canvas)
{
	/*
	if (_bAllowScaling)
	{
		if (Canvas.SizeX <= 640)
		{
			Return cFrame.Fonts[0];
		}
		else
		{
			if (Canvas.SizeX <= 800)
			{
				Return cFrame.Fonts[1];
			}
			else
			{
				if (Canvas.SizeX <= 1024)
				{
					Return cFrame.Fonts[3];
				}
				else
				{
					if (Canvas.SizeX <= 1280)
					{
						Return cFrame.Fonts[4];
					}
					else
					{
						if (Canvas.SizeX <= 1600)
						{
							Return cFrame.Fonts[5];
						}
						else
						{
							Return cFrame.Fonts[5];
						}
					}
				}
			}
		}
	}
	else
	{
		Return cFrame.Fonts[3];
	}
	*/
}
void UHUDTaskDisplay::DrawAmmo(UCanvas* Canvas)
{
	/*
	local AGP_Weapon Weapon;
	local float XL;
	local float YL;
	local Texture tStatus;
	local Texture tAmmo;
	local Texture wIcon;
	local Texture tElevation;
	local string sStatus;
	local int PosX;
	local int PosY;
	local string AmmoCount;
	local bool bFlash;
	local GameReplicationInfo GRI;
	local PlayerController PC;
	local string sShift;
	PC = cFrame.cHUD.PlayerOwner;
	if (cFrame.cActor != None)
	{
		Weapon = AGP_Weapon(AGP_Pawn(cFrame.cActor).Weapon);
		if (Weapon != None && !Weapon.IsA('item_headphones'))
		{
			if (Weapon.IconMaterial != None)
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
				if (Weapon.IsA('ThrowWeapon'))
				{
					Canvas.DrawTile(wIcon, 32 * cFrame.fScaleX, 32 * cFrame.fScaleY, 0, 0, wIcon.USize, wIcon.VSize);
				}
				else
				{
					if (Weapon.IsA('PistolWeapon'))
					{
						if (PC.bRadarIsVisible)
						{
							Canvas.SetPos(222 * cFrame.fScaleX, 553 * cFrame.fScaleY);
						}
						else
						{
							Canvas.SetPos(41 * cFrame.fScaleX, 553 * cFrame.fScaleY);
						}
						Canvas.DrawTile(wIcon, 32 * cFrame.fScaleX * 1.5, 32 * cFrame.fScaleY * 1.5, 0, 0, wIcon.USize, wIcon.VSize);
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
				if (Weapon.AmmoType != None)
				{
					PosX = _ScaledPos.X + _ScaledPos.W + 0 * cFrame.fScaleX;
					PosY = _ScaledPos.Y + 0 * cFrame.fScaleY;
					Canvas.SetPos(PosX, PosY);
					tAmmo = Texture(Weapon.AmmoType.IconMaterial);
					Canvas.DrawTile(tAmmo, 32 * cFrame.fScaleX, 32 * cFrame.fScaleY, 0, 0, tAmmo.USize, tAmmo.VSize);
					if (!GRI.bHUDHideAmmoCount && !PC.bHUDHideAmmoCount)
					{
						AmmoCount = "" $ Weapon.AmmoType.AmmoAmount;
						if (!Weapon.SingleShotWeapon())
						{
							AmmoCount = AmmoCount $ "/" $ Weapon.AmmoMagCount;
						}
					}
					else
					{
						if (Weapon.SingleShotWeapon())
						{
							AmmoCount = "" $ Weapon.AmmoType.AmmoAmount;
						}
						else
						{
							AmmoCount = "" $ Weapon.AmmoMagCount;
						}
					}
					Canvas.TextSize(AmmoCount, XL, YL);
					PosX += 32 * cFrame.fScaleX - XL / 2;
					PosY -= YL;
					Canvas.SetPos(PosX, PosY);
					Canvas.DrawText(AmmoCount);
				}
				if (Weapon.AuxAmmoType != None)
				{
					if (!GRI.bHUDHideGrenades && !PC.bHUDHideGrenades)
					{
						PosX = _ScaledPos.X + _ScaledPos.W + 32 * cFrame.fScaleX + 0 * cFrame.fScaleX + 0 * cFrame.fScaleX;
						PosY = _ScaledPos.Y + 0 * cFrame.fScaleY;
						Canvas.SetPos(PosX, PosY);
						tAmmo = Texture(Weapon.AuxAmmoType.IconMaterial);
						Canvas.DrawTile(tAmmo, 32 * cFrame.fScaleX, 32 * cFrame.fScaleY, 0, 0, tAmmo.USize, tAmmo.VSize);
						AmmoCount = "" $ Weapon.AuxAmmoType.AmmoAmount $ "/" $ Weapon.AuxAmmoMagCount;
						Canvas.TextSize(AmmoCount, XL, YL);
						PosX += 32 * cFrame.fScaleX - XL / 2;
						PosY -= YL;
						Canvas.SetPos(PosX, PosY);
						Canvas.DrawText(AmmoCount);
					}
				}
				if (Weapon.GetCurrentAmmoType() != None && Weapon.ElevationIcon.Length != 0 && !GRI.bHUDHideWeaponStatus && !PC.bHUDHideWeaponStatus && Weapon.IsZoomed())
				{
					PosX = 200 * cFrame.fScaleX;
					PosY = 560 * cFrame.fScaleY;
					Canvas.SetPos(PosX, PosY);
					tElevation = Weapon.ElevationIcon[Weapon.ElevationIndex];
					if (tElevation != None)
					{
						Canvas.DrawTile(tElevation, 32 * cFrame.fScaleX, 32 * cFrame.fScaleY, 0, 0, tElevation.USize, tElevation.VSize);
					}
				}
				if (!GRI.bHUDHideWeaponStatus && !PC.bHUDHideWeaponStatus)
				{
					tStatus = None;
					sStatus = "";
					bFlash = False;
					if (Weapon.IsA('Javelin_Tube'))
					{
						tStatus = tJav_Tube;
						sStatus = "Jav Tube";
						bFlash = False;
					}
					else
					{
						if (Weapon.IsA('ThrowWeapon'))
						{
							if (ThrowWeapon(Weapon).IsLostSpoon())
							{
								tStatus = tLiveGrenade;
								sStatus = "Live Grenade";
								bFlash = true;
							}
							else
							{
								if (ThrowWeapon(Weapon).IsTossNotThrow())
								{
									tStatus = tRoll;
									sStatus = "Roll";
								}
							}
						}
						else
						{
							if (Weapon.IsA('Item_Binoculars'))
							{
								if (Weapon.IsA('Item_VIPER'))
								{
									Switch(Weapon.GetStateName())
									{
											case 'LockedOn':
												tStatus = tJav_LockedOn;
												sStatus = "Locked On";
												bFlash = False;
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
													bFlash = False;
												}
											default:
												tStatus = tROF_Single;
												sStatus = "Single";
												bFlash = False;
									}
								}
								else
								{
									if (HumanController(PC) != None && HumanController(PC).bMortarSpotter && Weapon.IsZoomed())
									{
										Canvas.SetPos(544 * cFrame.fScaleX, 56 + 260 * cFrame.fScaleY);
										Canvas.DrawText("CFF RNG: " $ HumanController(PC).iSpotterPolarRangeSetting $ "m");
										sShift = "";
										if (HumanController(PC).bCFFShowSpotterToolMenu)
										{
											Canvas.SetPos(544 * cFrame.fScaleX, 56 * cFrame.fScaleY);
											Canvas.DrawTile(textSpotterOverlayMenu, 256, 256, 0, 0, textSpotterOverlayMenu.USize, textSpotterOverlayMenu.VSize);
											if (PC.bFire == 1)
											{
												if (cFrame.cActor.Level.TimeSeconds - fpTimeSinceLastMenuIconClicked > 0.1)
												{
													if (ProcessSpotterMenuNumpad(PC, PC.Player.WindowsMouseX - 544 * cFrame.fScaleX, PC.Player.WindowsMouseY - 56 * cFrame.fScaleY))
													{
														HumanController(PC).Player.bShowWindowsMouse = False;
														HumanController(PC).bCFFShowSpotterToolMenu = False;
														HumanController(PC).LockPlayer(False, False);
													}
												}
												fpTimeSinceLastMenuIconClicked = cFrame.cActor.Level.TimeSeconds;
											}
										}
										else
										{
											if (PC.bFire == 1 && cFrame.cActor.Level.TimeSeconds - fpTimeSinceLastMenuIconClicked > 0.1)
											{
												LaserSpotterRange(PC);
											}
										}
										if (Len(sAdjustFireDirection) > 0)
										{
											sShift = sAdjustFireDirection $ " " $ iAdjustFireAdjustment $ "m";
										}
										else
										{
											if (iAdjustFireAdjustment > 0)
											{
												sShift = "(INVADJ) " $ iAdjustFireAdjustment $ "m";
											}
										}
										if (Len(sShift) > 0)
										{
											Canvas.SetPos(544 * cFrame.fScaleX, 56 + 290 * cFrame.fScaleY);
											Canvas.DrawText("CFF Shift " $ sShift);
										}
										if (iLaserRange > 0)
										{
											sShift = "LSR RNG: " $ iLaserRange $ "m";
											if (cFrame.cActor.Level.TimeSeconds - fpTimeLastLaserUse < 2)
											{
												sShift = sShift $ " (CHG: " $ cFrame.cActor.Level.TimeSeconds - fpTimeLastLaserUse / 2 * 100 $ "%)";
											}
											Canvas.SetPos(544 * cFrame.fScaleX, 56 + 275 * cFrame.fScaleY);
											Canvas.DrawText(sShift);
										}
									}
									else
									{
										if (HumanController(PC).bCFFShowSpotterToolMenu)
										{
											HumanController(PC).bCFFShowSpotterToolMenu = False;
											HumanController(PC).Player.bShowWindowsMouse = False;
											HumanController(PC).LockPlayer(False, False);
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
												if (Weapon.IsA('WEAPON_Javelin'))
												{
													Switch(Weapon.GetStateName())
													{
											case 'LockedOn':
												tStatus = tJav_LockedOn;
												sStatus = "Locked On";
												bFlash = False;
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
												bFlash = False;
												break;
													}
												}
												else
												{
													Switch(Weapon.eROF)
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
					if (tStatus != None)
					{
						Canvas.SetPos(_ScaledPos.X + _ScaledPos.W / 2 - 29, _ScaledPos.Y - _ScaledPos.H / 2);
						if (bFlash)
						{
							bWeaponMsgFlashing = CheckFlashTime();
						}
						else
						{
							bWeaponMsgFlashing = False;
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
		if (AGP_Pawn(cFrame.cActor).getInvContainerShoulder() != None)
		{
			Weapon = AGP_Weapon(AGP_Pawn(cFrame.cActor).getInvContainerShoulder().getFirstItem());
			if (Weapon != None && !Weapon.IsA('item_headphones'))
			{
				if (Weapon.IsSupported())
				{
					wIcon = Texture(Weapon.IconMaterial);
				}
				else
				{
					wIcon = Weapon.GetSupportIcon();
				}
				if (wIcon != None)
				{
					Canvas.SetPos(_ScaledPos.X - 29, _ScaledPos.Y - _ScaledPos.H / 2);
					wIcon = Texture(Weapon.IconMaterial);
					Canvas.DrawTile(wIcon, _ScaledPos.W / 2, _ScaledPos.H / 2, 0, 0, wIcon.USize, wIcon.VSize);
				}
			}
		}
		if (AGP_Pawn(cFrame.cActor).getInvContainerAltShoulder() != None)
		{
			Weapon = AGP_Weapon(AGP_Pawn(cFrame.cActor).getInvContainerAltShoulder().getFirstItem());
			if (Weapon != None && !Weapon.IsA('item_headphones'))
			{
				if (Weapon.IsSupported())
				{
					wIcon = Texture(Weapon.IconMaterial);
				}
				else
				{
					wIcon = Weapon.GetSupportIcon();
				}
				if (wIcon != None)
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
	local GameReplicationInfo GRI;
	local PlayerController PC;
	PC = cFrame.cHUD.PlayerOwner;
	GRI = PC.GameReplicationInfo;
	cFrame.cHUD.bShowObjectives = !GRI.bHUDHideObjectives && !PC.bHUDHideObjectives;
	*/
}
void UHUDTaskDisplay::DrawCompass(UCanvas* Canvas)
{
	/*
	local GameReplicationInfo GRI;
	local PlayerController PC;
	PC = cFrame.cHUD.PlayerOwner;
	GRI = PC.GameReplicationInfo;
	*/
}
void UHUDTaskDisplay::DrawRadar(UCanvas* Canvas)
{
}
void UHUDTaskDisplay::InitializeSupport()
{
	/*
	local CallForSupport S;
	Return;
	if (bInitializedSupport)
	{
		Return;
	}
	ForEach cFrame.cActor.DynamicActors('CallForSupport', S)
	{
		if (S.IsA('AirStrike'))
		{
			if (S.TeamNumber == Pawn(cFrame.cActor).PlayerReplicationInfo.Team.TeamIndex)
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
	/*
	local int PosX;
	local int PosY;
	local int sizeW;
	local int sizeH;
	local float XL;
	local float YL;
	local AGP_Pawn aPawn;
	local HumanController HC;
	local PlayerController PC;
	local GameReplicationInfo GRI;
	local CallForSupport S;
	local int Num;
	local Texture tTemp;
	aPawn = AGP_Pawn(cFrame.cActor);
	if (aPawn == None)
	{
		Return;
	}
	PC = PlayerController(aPawn.Controller);
	if (PC == None)
	{
		Return;
	}
	GRI = PC.GameReplicationInfo;
	if (GRI == None)
	{
		Return;
	}
	HC = HumanController(PC);
	if (HC == None)
	{
		Return;
	}
	InitializeSupport();
	if (Support != None)
	{
		S = Support;
		Num = S.StrikesAvailable;
		if (Num > 0)
		{
			PosX = 8 * cFrame.fScaleX;
			PosY = 410 * cFrame.fScaleY;
			sizeW = 32 * cFrame.fScaleX;
			sizeH = 32 * cFrame.fScaleY;
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
			if (tTemp != None)
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
void UHUDTaskDisplay::CheckFlashTime()
{
	/*
	local float deltaT;
	local float deltaF;
	deltaT = cFrame.cActor.Level.TimeSeconds - fLastFlashTime;
	deltaF = 1 / 2 * 2;
	if (deltaT > deltaF * 2)
	{
		fLastFlashTime = cFrame.cActor.Level.TimeSeconds;
		Return False;
	}
	else
	{
		if (deltaT > deltaF)
		{
			Return True;
		}
		else
		{
			Return False;
		}
	}
	*/
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
		Return False;
	}
	if (iMenuY >= 7 && iMenuY < 49)
	{
		if (iMenuX >= 7 && iMenuX < 79)
		{
			HumanController(PC).CFFPolarSuppressInfantry();
			Return True;
		}
		if (iMenuX >= 89 && iMenuX < 158)
		{
			HumanController(PC).CFFPolarSuppressVehicle();
			Return True;
		}
		if (iMenuX >= 174 && iMenuX < 240)
		{
			HumanController(PC).CFFPolarSmoke();
			Return True;
		}
		Return False;
	}
	if (iMenuY >= 59 && iMenuY < 102 && iMenuX >= 31 && iMenuX <= 77)
	{
		HumanController(PC).CFFCancel();
		Return True;
	}
	if (iMenuY >= 59 && iMenuY < 102 && iMenuX >= 103 && iMenuX <= 146)
	{
		HumanController(PC).CFFFire();
		Return True;
	}
	if (iMenuY >= 59 && iMenuY < 102 && iMenuX >= 170 && iMenuX <= 218)
	{
		HumanController(PC).CFFCheckFire();
		Return True;
	}
	if (iMenuY >= 87 && iMenuY < 157 && iMenuX >= 197 && iMenuX <= 237)
	{
		HumanController(PC).iSpotterShiftLeftRight = 0;
		HumanController(PC).iSpotterShiftAddDrop = 0;
		Return False;
	}
	if (iMenuY >= 87 && iMenuY < 157 && iMenuX >= 19 && iMenuX <= 67)
	{
		HumanController(PC).CFFRepeat();
		Return True;
	}
	if (iMenuY >= 87 && iMenuY < 157 && iMenuX >= 116 && iMenuX <= 168)
	{
		HumanController(PC).iSpotterShiftAddDrop++;
		Return False;
	}
	if (iMenuY >= 203 && iMenuY < 245 && iMenuX >= 116 && iMenuX <= 168)
	{
		HumanController(PC).iSpotterShiftAddDrop--;
		Return False;
	}
	if (iMenuY >= 160 && iMenuY < 202 && iMenuX >= 2 && iMenuX <= 84)
	{
		HumanController(PC).iSpotterShiftLeftRight--;
		Return False;
	}
	if (iMenuY >= 160 && iMenuY < 202 && iMenuX >= 171 && iMenuX <= 254)
	{
		HumanController(PC).iSpotterShiftLeftRight++;
		Return False;
	}
	if (iMenuY >= 160 && iMenuY < 202 && iMenuX >= 90 && iMenuX <= 165)
	{
		if (HumanController(PC).iSpotterShiftLeftRight > 0)
		{
			HumanController(PC).CFFAdjustFire("RIGHT", Abs(HumanController(PC).iSpotterShiftLeftRight));
			HumanController(PC).iSpotterShiftLeftRight = 0;
			Return True;
		}
		else
		{
			if (HumanController(PC).iSpotterShiftLeftRight < 0)
			{
				HumanController(PC).CFFAdjustFire("LEFT", Abs(HumanController(PC).iSpotterShiftLeftRight));
				HumanController(PC).iSpotterShiftLeftRight = 0;
				Return True;
			}
		}
		if (HumanController(PC).iSpotterShiftAddDrop > 0)
		{
			HumanController(PC).CFFAdjustFire("ADD", Abs(HumanController(PC).iSpotterShiftAddDrop));
			HumanController(PC).iSpotterShiftAddDrop = 0;
			Return True;
		}
		else
		{
			if (HumanController(PC).iSpotterShiftAddDrop < 0)
			{
				HumanController(PC).CFFAdjustFire("DROP", Abs(HumanController(PC).iSpotterShiftAddDrop));
				HumanController(PC).iSpotterShiftAddDrop = 0;
				Return True;
			}
		}
		Return True;
	}
	*/
	return false;
}
void UHUDTaskDisplay::LaserSpotterRange(APlayerController* PC)
{
	/*
	local Actor actHit;
	local Object.Vector StartTrace;
	local Object.Vector EndTrace;
	local Object.Vector HitLocation;
	local Object.Vector HitNormal;
	local Object.Rotator CameraRotation;
	if (HumanController(PC).bCFFDisableLaser)
	{
		iLaserRange = 0;
		Return;
	}
	if (cFrame.cActor.Level.TimeSeconds - fpTimeLastLaserUse > 2)
	{
		HumanController(PC).PlayerCalcView(actHit, StartTrace, CameraRotation);
		EndTrace = StartTrace + 100000 * Vector(CameraRotation);
		actHit = HumanController(PC).Trace(HitLocation, HitNormal, EndTrace, StartTrace, True);
		fpTimeLastLaserUse = cFrame.cActor.Level.TimeSeconds;
		iLaserRange = VSize(StartTrace - HitLocation) / 55;
	}
	*/
}
bool UHUDTaskDisplay::ProcessSpotterMenuNumpad(APlayerController* PC, int32 iMenuX, int32 iMenuY)
{
	/*
	if (iMenuX < 0 || iMenuY < 0 || iMenuX > 256 || iMenuY > 256)
	{
		Return False;
	}
	Log("Player clicked on spotter menu at " $ iMenuX $ ", " $ iMenuY);
	if (iMenuY >= 8 && iMenuY < 56)
	{
		if (iMenuX >= 8 && iMenuX < 76)
		{
			HumanController(PC).CFFPolarSuppressInfantry();
			Return True;
		}
		if (iMenuX >= 89 && iMenuX < 158)
		{
			HumanController(PC).CFFPolarSuppressVehicle();
			Return True;
		}
		if (iMenuX >= 174 && iMenuX < 240)
		{
			HumanController(PC).CFFPolarSmoke();
			Return True;
		}
		Return False;
	}
	if (iMenuY >= 59 && iMenuY < 102)
	{
		if (iMenuX >= 8 && iMenuX <= 56)
		{
			HumanController(PC).CFFCancel();
			Return True;
		}
		if (iMenuX >= 71 && iMenuX <= 118)
		{
			HumanController(PC).CFFFire();
			Return True;
		}
		if (iMenuX >= 132 && iMenuX <= 180)
		{
			HumanController(PC).CFFCheckFire();
			Return True;
		}
		if (iMenuX >= 193 && iMenuX <= 240)
		{
			HumanController(PC).CFFRepeat();
			Return True;
		}
		Return False;
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
			Return False;
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
			Return False;
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
			Return False;
		}
		if (iMenuX >= 157 && iMenuX <= 186)
		{
			sAdjustFireDirection = "ADD";
			Return False;
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
			Return False;
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
			Return False;
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
			Return False;
		}
		if (iMenuX >= 123 && iMenuX <= 153)
		{
			sAdjustFireDirection = "LEFT";
			Return False;
		}
		if (iMenuX >= 157 && iMenuX <= 186)
		{
			if (Len(sAdjustFireDirection) > 0)
			{
				HumanController(PC).CFFAdjustFire(sAdjustFireDirection, iAdjustFireAdjustment);
				Return True;
			}
			Return False;
		}
		if (iMenuX >= 192 && iMenuX <= 223)
		{
			sAdjustFireDirection = "RIGHT";
			Return False;
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
			Return False;
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
			Return False;
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
			Return False;
		}
		if (iMenuX >= 157 && iMenuX <= 186)
		{
			sAdjustFireDirection = "DROP";
			Return False;
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
			Return False;
		}
		if (iMenuX >= 46 && iMenuX <= 75)
		{
			sAdjustFireDirection = "";
			iAdjustFireAdjustment = 0;
			HumanController(PC).iSpotterShiftLeftRight = 0;
			HumanController(PC).iSpotterShiftAddDrop = 0;
			Return False;
		}
	}
	*/
	return false;
}
