// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pawn/Vehicle/VehiclePosition/HMMWV_Passenger/CROWS_Gunner/CROWS_Gunner50Cal/FSTS_CROWS_Gunner50cal/FSTS_CROWS_Gunner50cal.h"
#include "AA29/Object/Actor/HUD/AGP_HUD/CROWS_Hud/FSTS_CROWS_HUD/FSTS_CROWS_HUD.h"

AFSTS_CROWS_Gunner50cal::AFSTS_CROWS_Gunner50cal()
{
	bSafety = true;
	//HudClass = AFSTS_CROWS_HUD::StaticClass();
}

void AFSTS_CROWS_Gunner50cal::DoLase()
{
	Super::DoLase();
	bHasLased = true;
}

void AFSTS_CROWS_Gunner50cal::ZoomIn()
{
	Super::ZoomIn();
	bHasZoomed = true;
}

void AFSTS_CROWS_Gunner50cal::ZoomOut()
{
	Super::ZoomOut();
	bHasZoomed = true;
}

void AFSTS_CROWS_Gunner50cal::ServerActivateCrows()
{
	if (!bInCROWS)
	{
		bInCROWS = true;
		//CROWS_Base(Gun).bActive = true;
		//BeginCrows();
	}
}

void AFSTS_CROWS_Gunner50cal::Fire(float F)
{
	if (!bSafety)
	{
		Super::Fire(F);
	}
}

void AFSTS_CROWS_Gunner50cal::AltFire(float F)
{
	if (!bSafety)
	{
		Super::AltFire(F);
	}
}
