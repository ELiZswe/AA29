// All the original content belonged to the US Army

#include "AA29/Object/Actor/HUD/AGP_HUD/CROWS_Hud/CROWS_Hud.h"
#include "AA29/Object/Actor/VehicleWeapon/CROWS_Base/CROWS_Base.h"
#include "AA29/Object/Actor/Pawn/Vehicle/VehiclePosition/VehiclePosition.h"
#include "Engine/Canvas.h"

ACROWS_Hud::ACROWS_Hud(const FObjectInitializer& ObjectInitializer) :Super(ObjectInitializer)
{
	/*
	UTexRotator* CompRotator = NewObject<UTexRotator>(UTexRotator::StaticClass());
	CompRotator->UOffset = 64;
	CompRotator->VOffset = 64;
	CompRotator->Material = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/HUD/t_ui_hud_crows_compass_Mat.t_ui_hud_crows_compass_Mat'"), NULL, LOAD_None, NULL);
	
	UTexRotator* VehicleCompRotator = NewObject<UTexRotator>(UTexRotator::StaticClass());
	VehicleCompRotator->UOffset = 32;
	VehicleCompRotator->VOffset = 32;
	VehicleCompRotator->Material = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/HUD/t_ui_hud_crows_compass_vehicle_Mat.t_ui_hud_crows_compass_vehicle_Mat'"), NULL, LOAD_None, NULL);
	
	UTexRotator* CompassArrowRotator = NewObject<UTexRotator>(UTexRotator::StaticClass());
	CompassArrowRotator->UOffset = 32;
	CompassArrowRotator->VOffset = 32;
	CompassArrowRotator->Material = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/HUD/t_ui_hud_crows_compass_arrow_Mat.t_ui_hud_crows_compass_arrow_Mat'"), NULL, LOAD_None, NULL);
	*/

	CROWS_HUDColor = FColor(255, 255, 255, 255);
	CROWS_HUDRedColor = FColor(48, 83, 230, 255);
	CrosshairX = 128;
	CrosshairY = 128;
	CrosshairOffX = 63;
	CrosshairOffY = 63;
	CrosshairTexture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/HUD/t_ui_hud_crows_crosshair_Mat.t_ui_hud_crows_crosshair_Mat'"), NULL, LOAD_None, NULL);
	CrosshairDeadTexture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/HUD/t_ui_hud_crows_cross_Mat.t_ui_hud_crows_cross_Mat'"), NULL, LOAD_None, NULL);
	SideMeterX = 16;
	SideMeterY = 256;
	SideMeterOffX = 9;
	SideMeterOffY = 145;
	SideMeterTexture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/HUD/t_ui_hud_crows_elevation_hashmarks_Mat.t_ui_hud_crows_elevation_hashmarks_Mat'"), NULL, LOAD_None, NULL);
	AmmoIconX = 64;
	AmmoIconY = 32;
	AmmoIconOffY = 559;
	AmmoIconTexture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/HUD/t_ui_hud_crows_50cal_icon_Mat.t_ui_hud_crows_50cal_icon_Mat'"), NULL, LOAD_None, NULL);
	ArrowX = 16;
	ArrowY = 16;
	ArrowOffX = 31;
	ArrowOffY = 300;
	ArrowLeftTexture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/HUD/t_ui_hud_crows_elevation_arrow_l_Mat.t_ui_hud_crows_elevation_arrow_l_Mat'"), NULL, LOAD_None, NULL);
	ArrowRightTexture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/HUD/t_ui_hud_crows_elevation_arrow_r_Mat.t_ui_hud_crows_elevation_arrow_r_Mat'"), NULL, LOAD_None, NULL);
	CompassOffX = 80;
	CompassOffY = 523;
	//Compass = CompRotator;
	VehicleCompassOffX = 80;
	VehicleCompassOffY = 523;
	//VehicleCompass = VehicleCompRotator;
	CompassArrowOffX = 80;
	CompassArrowOffY = 523;
	//CompassArrow = CompassArrowRotator;
	ProgBarX = 120;
	ProgBarY = 18;
	ProgBarOffX = 640;
	ProgBarOffY = 6;
	ProgBarTexture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_goal_edge_Mat.hud_goal_edge_Mat'"), NULL, LOAD_None, NULL);
	ProgIndicatorX = 0.97;
	ProgIndicatorY = 0.825;
	ProgIndicatorTexture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/Engine/WhiteSquareTexture_Mat.WhiteSquareTexture_Mat'"), NULL, LOAD_None, NULL);
	TiltWarnOffY = -72;
	TiltWarnThreshold = 2048;
	LasingOffY = 72;
	LasingDrawX = 32;
	LasingDrawY = 32;
	LasingCrosshairTexture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/HUD/t_ui_hud_crows_lasing_crosshair_Mat.t_ui_hud_crows_lasing_crosshair_Mat'"), NULL, LOAD_None, NULL);
	Ammo = 500;
	MaxAmmo = 500;
	FOVReadout = 26.200001;
	LaseRechargeTime = 2;
	FontArrayNames = {
		"T_AA2_Fonts.Arial18",
		"T_AA2_Fonts.Arial22",
		"T_AA2_Fonts.Arial22",
		"T_AA2_Fonts.Arial22"
	};
}

static const float DegreeToURot = 182.044444445;
static const float RadianToURot = 10430.3783505;

FColor ACROWS_Hud::MakeCanvasColor(uint8 R, uint8 G, uint8 B, uint8 A)
{
	FColor C = FColor(0, 0, 0, 0);
	C.R = R;
	C.G = G;
	C.B = B;
	if (A == 0)
	{
		A = 255;
	}
	C.A = A;
	return C;
}

void ACROWS_Hud::CenterDraw(UCanvas* aCanvas, UMaterialInstance* mat, float X, float Y, float UScale, float VScale, bool bStretched)
{
	float U = 0;
	float V = 0;
	float W = 0;
	float H = 0;
	/*
	U = float(mat.MaterialUSize());
	W = (U * UScale);
	V = float(mat.MaterialVSize());
	H = (V * VScale);
	W *= xRatio;
	H *= yRatio;
	aCanvas.SetPos((X - (W / 2)), (Y - (H / 2)));
	if (!bStretched)
	{
		aCanvas.DrawTile(mat, W, H, 0, 0, U, V);
	}
	else
	{
		aCanvas.DrawTileStretched(mat, W, H);
	}
	*/
}

void ACROWS_Hud::ScaleTextureValues()
{
	CrosshairDrawX = (CrosshairX * xRatio);
	CrosshairDrawY = (CrosshairY * yRatio);
	CrosshairDrawOffX = (CrosshairOffX * xRatio);
	CrosshairDrawOffY = (CrosshairOffY * yRatio);
	SideMeterDrawX = (SideMeterX * xRatio);
	SideMeterDrawY = (SideMeterY * yRatio);
	SideMeterDrawOffX = (SideMeterOffX * xRatio);
	SideMeterDrawOffY = (SideMeterOffY * yRatio);
	ArrowDrawX = (ArrowX * xRatio);
	ArrowDrawY = (ArrowY * yRatio);
	ArrowDrawOffX = (ArrowOffX * xRatio);
	ArrowDrawOffY = (ArrowOffY * yRatio);
	AmmoIconDrawX = (AmmoIconX * xRatio);
	AmmoIconDrawY = (AmmoIconY * yRatio);
	AmmoIconDrawOffX = (AmmoIconOffX * xRatio);
	AmmoIconDrawOffY = (AmmoIconOffY * yRatio);
	CompassDrawOffX = (CompassOffX * xRatio);
	CompassDrawOffY = (CompassOffY * yRatio);
	VehicleCompassDrawOffX = (VehicleCompassOffX * xRatio);
	VehicleCompassDrawOffY = (VehicleCompassOffY * yRatio);
	CompassArrowDrawOffX = (CompassArrowOffX * xRatio);
	CompassArrowDrawOffY = (CompassArrowOffY * yRatio);
	ProgBarDrawX = int((float(ProgBarX) * xRatio));
	ProgBarDrawY = int((float(ProgBarY) * yRatio));
	ProgBarDrawOffX = int((float(ProgBarOffX) * xRatio));
	ProgBarDrawOffY = int((float(ProgBarOffY) * yRatio));
	ProgIndicatorDrawX = int((ProgIndicatorX * xRatio));
	ProgIndicatorDrawY = int((ProgIndicatorY * yRatio));
}

void ACROWS_Hud::DrawString(int32 XPos, int32 YPos, FString Text)
{
	//parentCanvas.SetPos((float(XPos) * xRatio), (float(YPos) * yRatio));
	//parentCanvas.DrawText(Text);
}

void ACROWS_Hud::SetupFonts(UCanvas* C)
{
	//C.Font = _cHUDFrame.GetProperSizeFont(C);
}

void ACROWS_Hud::CalculateAzimuth()
{
	int32 Yaw = 0;
	int32 VYaw = 0;
	/*
	VYaw = Cast<AVehiclePosition>(PlayerOwner.Pawn).VehicleBase.Rotation.Yaw;
	Yaw = PlayerOwner.GetViewRotation().Yaw;
	VehicleCompass.Rotation.Yaw = ((-VYaw) + Yaw);
	CompassArrow.Rotation.Yaw = 0;
	Compass.Rotation.Yaw = Yaw;
	*/
}

void ACROWS_Hud::CalculateElevation()
{
	/*
	Elevation = (Cast<AVehiclePosition>(PlayerOwner.Pawn).Rotation.Pitch - Cast<AVehiclePosition>(PlayerOwner.Pawn).VehicleBase.Rotation.Pitch);
	if (Elevation > 32768)
	{
		(Elevation -= 65536);
	}
	Elevation = int((float(Elevation) / 43.333));
	*/
}

bool ACROWS_Hud::ShouldDisplayMOTD()
{
	return false;
}

void ACROWS_Hud::DrawHUD()
{
	FString tempString = "";
	float tempXRatio = 0;
	float tempYRatio = 0;
	float textheight = 0;
	int32 Yaw = 0;
	int32 VYaw = 0;
	float XL = 0;
	float YL = 0;
	textheight = 35;
	parentCanvas = Canvas;
	/*
	if ((PlayerOwner.Pawn == nullptr) || (Cast<AVehiclePosition>(PlayerOwner.Pawn) == nullptr))
	{
		return;
	}
	SetupFonts(Canvas);
	CalculateAzimuth();
	CalculateElevation();
	if ((Cast<AVehiclePosition>(PlayerOwner.Pawn) != nullptr) && (Cast<AVehiclePosition>(PlayerOwner.Pawn).Gun != nullptr))
	{
		Ammo = Cast<ACROWS_Base>(Cast<AVehiclePosition>(PlayerOwner.Pawn).Gun).Ammo;
	}
	Canvas.DrawColor = CROWS_HUDColor;
	Canvas.DrawColor.A = 255;
	Canvas.Style = ERenderStyle.STY_Alpha;
	if ((Cast<ACROWS_Base>(Cast<AVehiclePosition>(PlayerOwner.Pawn).Gun).iSystemStatus & 2) == 0)
	{
		Canvas.DrawTile(Texture'AGP.Icons.Fade', float(Canvas.SizeX), float(Canvas.SizeY), 1, 0, 1, 1);
	}
	tempXRatio = (float(Canvas.SizeX) / 800);
	tempYRatio = (float(Canvas.SizeY) / 600);
	if ((tempXRatio != xRatio) || (tempYRatio != yRatio))
	{
		xRatio = tempXRatio;
		yRatio = tempYRatio;
		ScaleTextureValues();
	}
	if (bPlayProgressBar)
	{
		Canvas.SetPos((xRatio * float(ProgBarOffX)), (yRatio * float(ProgBarOffY)));
		Canvas.DrawTile(ProgBarTexture, float(ProgBarDrawX), float(ProgBarDrawY), 0, 0, float(ProgBarTexture.USize), float(ProgBarTexture.VSize));
		Canvas.SetPos(((xRatio * float(ProgBarOffX)) + (((1 - ProgIndicatorX) / 2) * float(ProgBarDrawX))), ((yRatio * float(ProgBarOffY)) + (((1 - ProgIndicatorY) / 2) * float(ProgBarDrawY))));
		Canvas.DrawTile(ProgIndicatorTexture, ((ProgBarCounter / float(LaseRechargeTime)) * (float(ProgBarDrawX) * ProgIndicatorX)), (float(ProgBarDrawY) * ProgIndicatorY), 0, 0, float(ProgIndicatorTexture.USize), float(ProgIndicatorTexture.VSize));
		Canvas.TextSize("LASER CHARGING", XL, YL);
		Canvas.SetPos(((xRatio * float(ProgBarOffX)) + ((float(ProgBarDrawX) - XL) / 2)), (((yRatio * float(ProgBarOffY)) + float(ProgBarDrawY)) + 4));
		Canvas.DrawText("LASER CHARGING");
	}
	else
	{
		Canvas.SetPos((xRatio * float(ProgBarOffX)), (yRatio * float(ProgBarOffY)));
		Canvas.DrawTile(ProgBarTexture, float(ProgBarDrawX), float(ProgBarDrawY), 0, 0, float(ProgBarTexture.USize), float(ProgBarTexture.VSize));
		Canvas.TextSize("LASER READY", XL, YL);
		Canvas.SetPos(((xRatio * float(ProgBarOffX)) + ((float(ProgBarDrawX) - XL) / 2)), ((yRatio * float(ProgBarOffY)) + ((float(ProgBarDrawY) - YL) / 2)));
		Canvas.DrawText("LASER READY");
	}
	if (bIsLasing)
	{
		Canvas.TextSize("LASING TARGET...", XL, YL);
		Canvas.SetPos(((float((Canvas.SizeX / 2)) - (XL / 2)) + (xRatio * float(LasingOffX))), (float((Canvas.SizeY / 2)) + (yRatio * float(LasingOffY))));
		Canvas.DrawText("LASING TARGET...");
		Canvas.SetPos((float((Canvas.SizeX / 2)) - ((xRatio * float(LasingDrawX)) / 2)), (float((Canvas.SizeY / 2)) - ((yRatio * float(LasingDrawY)) / 2)));
		Canvas.DrawTile(LasingCrosshairTexture, (xRatio * float(LasingDrawX)), (xRatio * float(LasingDrawY)), 0, 0, float(LasingCrosshairTexture.USize), float(LasingCrosshairTexture.VSize));
	}
	if (bDrawLased && (!bIsLasing))
	{
		Canvas.DrawColor = CROWS_HUDRedColor;
		Canvas.TextSize("LASED", XL, YL);
		Canvas.SetPos(((float((Canvas.SizeX / 2)) - (XL / 2)) + (xRatio * float(LasingOffX))), (float((Canvas.SizeY / 2)) + (yRatio * float(LasingOffY))));
		Canvas.DrawText("LASED");
		Canvas.DrawColor = CROWS_HUDColor;
	}
	if (FMath::Abs(float(Cast<AVehiclePosition>(PlayerOwner.Pawn).VehicleBase.Rotation.Roll)) > float(TiltWarnThreshold))
	{
		Canvas.TextSize("ADJUST FOR TILT", XL, YL);
		Canvas.SetPos(((float((Canvas.SizeX / 2)) - (XL / 2)) + (xRatio * float(TiltWarnOffX))), (float((Canvas.SizeY / 2)) + (yRatio * float(TiltWarnOffY))));
		Canvas.DrawText("ADJUST FOR TILT");
	}
	Canvas.SetPos(((float(Canvas.SizeX) - SideMeterDrawX) - SideMeterDrawOffX), SideMeterDrawOffY);
	Canvas.DrawTile(SideMeterTexture, SideMeterDrawX, SideMeterDrawY, 0.5, 0.5, (float(SideMeterTexture.USize) - 1), (float(SideMeterTexture.VSize) - 1));
	Canvas.SetPos(((float(Canvas.SizeX) - ArrowDrawX) - ArrowDrawOffX), (ArrowDrawOffY - (float(Elevation) * yRatio)));
	Canvas.DrawTile(ArrowRightTexture, ArrowDrawX, ArrowDrawY, 0, 0, (float(ArrowRightTexture.USize) - 1), (float(ArrowRightTexture.VSize) - 1));
	Canvas.SetPos(SideMeterDrawOffX, SideMeterDrawOffY);
	Canvas.DrawTile(SideMeterTexture, SideMeterDrawX, SideMeterDrawY, 0.5, 0.5, (float(SideMeterTexture.USize) - 1), (float(SideMeterTexture.VSize) - 1));
	Canvas.SetPos(ArrowDrawOffX, (ArrowDrawOffY - (float(Elevation) * yRatio)));
	Canvas.DrawTile(ArrowLeftTexture, (ArrowX * xRatio), (ArrowY * yRatio), 0.5, 0.5, (float(ArrowLeftTexture.USize) - 0.5), (float(ArrowLeftTexture.VSize) - 0.5));
	CenterDraw(Canvas, Compass, CompassDrawOffX, CompassDrawOffY, 1, 1);
	CenterDraw(Canvas, VehicleCompass, VehicleCompassDrawOffX, VehicleCompassDrawOffY, 1, 1);
	CenterDraw(Canvas, CompassArrow, CompassArrowDrawOffX, CompassArrowDrawOffY, 1, 1);
	if ((Cast<ACROWS_Base>(Cast<AVehiclePosition>(PlayerOwner.Pawn).Gun).iSystemStatus & 2) == 0)
	{
		Canvas.TextSize("OPTICS DAMAGED", XL, YL);
		Canvas.SetPos((float((Canvas.SizeX / 2)) - (XL / 2)), (10 * yRatio));
		Canvas.DrawText("OPTICS DAMAGED");
	}
	if ((Cast<ACROWS_Base>(Cast<AVehiclePosition>(PlayerOwner.Pawn).Gun).iSystemStatus & 4) == 0)
	{
		Canvas.TextSize("LASER DAMAGED", XL, YL);
		Canvas.SetPos((XL - float(Canvas.SizeX)), (10 * yRatio));
		Canvas.DrawText("LASER DAMAGED");
	}
	else
	{
		if (ProgBarCounter != 0)
		{
			Canvas.DrawColor = CROWS_HUDRedColor;
		}
		tempString = FString::FromInt(LaseDistance) + "m";
		DrawString(480, 203, tempString);
		if (ProgBarCounter != 0)
		{
			Canvas.DrawColor = CROWS_HUDColor;
		}
	}
	if (((Cast<ACROWS_Base>(Cast<AVehiclePosition>(PlayerOwner.Pawn).Gun).iSystemStatus & 8) == 0) || ((Cast<ACROWS_Base>(Cast<AVehiclePosition>(PlayerOwner.Pawn).Gun).iSystemStatus & 16) == 0))
	{
		Canvas.TextSize("MOTOR DAMAGED", XL, YL);
		Canvas.SetPos((float((Canvas.SizeX / 2)) - (XL / 2)), (30 * yRatio));
		Canvas.DrawText("MOTOR DAMAGED");
	}
	if ((Cast<ACROWS_Base>(Cast<AVehiclePosition>(PlayerOwner.Pawn).Gun).iSystemStatus & 2) > 0)
	{
		if ((Cast<ACROWS_Base>(Cast<AVehiclePosition>(PlayerOwner.Pawn).Gun).iSystemStatus & 32) == 0)
		{
			Canvas.TextSize("WEAPON DAMAGED", XL, YL);
			Canvas.SetPos((float((Canvas.SizeX / 2)) - (XL / 2)), (569 * yRatio));
			Canvas.DrawText("WEAPON DAMAGED");
		}
		else
		{
			Canvas.SetPos(((float((Canvas.SizeX / 2)) - AmmoIconDrawOffX) - ((AmmoIconX * xRatio) / 2)), AmmoIconDrawOffY);
			Canvas.DrawTile(AmmoIconTexture, AmmoIconDrawX, AmmoIconDrawY, 0.5, 0.5, (float(AmmoIconTexture.USize) - 1), (float(AmmoIconTexture.VSize) - 1));
			tempString = FString::FromInt(Ammo) + "/" + FString::FromInt(MaxAmmo);
			DrawString(460, 569, tempString);
			Canvas.TextSize(AmmoType, XL, YL);
			Canvas.SetPos(((float((Canvas.SizeX / 2)) - XL) - (float(61) * xRatio)), (569 * yRatio));
			Canvas.DrawText(AmmoType);
			if (Cast<ACROWS_Base>(Cast<AVehiclePosition>(PlayerOwner.Pawn).Gun).bCharged && (Ammo > 0))
			{
				Canvas.TextSize("Weapon Charged", XL, YL);
				Canvas.SetPos((float((Canvas.SizeX / 2)) - (XL / 2)), (537 * yRatio));
				Canvas.DrawText("Weapon Charged");
			}
			if (Ammo <= 0)
			{
				Canvas.TextSize("WEAPON EMPTY", XL, YL);
				Canvas.SetPos((float((Canvas.SizeX / 2)) - (XL / 2)), (537 * yRatio));
				Canvas.DrawText("WEAPON EMPTY");
			}
		}
		Canvas.SetPos((float((Canvas.SizeX / 2)) - CrosshairDrawOffX), (float((Canvas.SizeY / 2)) - CrosshairDrawOffY));
		if (Cast<ACROWS_Base>(Cast<AVehiclePosition>(PlayerOwner.Pawn).Gun).bCharged && (Ammo > 0))
		{
			Canvas.DrawTile(CrosshairTexture, CrosshairDrawX, CrosshairDrawY, 1, 1, (float(CrosshairTexture.USize) - 0.5), (float(CrosshairTexture.VSize) - 0.5));
		}
		else
		{
			Canvas.DrawTile(CrosshairDeadTexture, CrosshairDrawX, CrosshairDrawY, 1, 1, (float(CrosshairDeadTexture.USize) - 0.5), (float(CrosshairDeadTexture.VSize) - 0.5));
		}
		VYaw = Cast<AVehiclePosition>(PlayerOwner.Pawn).VehicleBase.Rotation.Yaw;
		Yaw = (PlayerOwner.GetViewRotation().Yaw - VYaw);
		tempString = FString::FromInt(FOVToZoom(FOVReadout)) + "x";
		DrawString(307, 203, tempString);
	}
	if (GetWorld()->GetTimeSeconds() < (_fCMessageTimeout + 2))
	{
		DrawCenteredMessages(Canvas);
	}
	else
	{
		if (GetWorld()->GetTimeSeconds() < (LongMessageTimeout + 2))
		{
			DrawCenteredLongMessage(Canvas);
		}
	}
	*/
}

void ACROWS_Hud::DrawLased()
{
	//SetCustomTimer(1.5, false, "FinishDrawingLase");
	bDrawLased = true;
}

void ACROWS_Hud::FinishDrawingLase()
{
	bDrawLased = false;
}

void ACROWS_Hud::SetAmmo(int32 aAmmo)
{
	Ammo = aAmmo;
}

void ACROWS_Hud::SetFOV(float aFOV)
{
	FOVReadout = aFOV;
}

int32 ACROWS_Hud::FOVToZoom(float FOV)
{
	/*
	switch (FOV)
	{
	case 45:
		return 1;
	case 22.5:
		return 2;
	case 11.25:
		return 4;
	case 5.625:
		return 8;
	case 3.75:
		return 12;
	default:
	}
	*/
	return 1;    //FAKE   /ELiZ
}

void ACROWS_Hud::SetStabilization(bool flag)
{
	Stabilized = flag;
}

void ACROWS_Hud::SetLaseDistance(float aLaseDistance)
{
	LaseDistance = int(aLaseDistance);
}

void ACROWS_Hud::Tick(float DeltaTime)
{
	if (bPlayProgressBar)
	{
		(ProgBarCounter += DeltaTime);
		if (ProgBarCounter > float(LaseRechargeTime))
		{
			bPlayProgressBar = false;
			ProgBarCounter = 0;
		}
	}
}
