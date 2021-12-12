// All the original content belonged to the US Army

#include "Item_Binoculars.h"

AItem_Binoculars::AItem_Binoculars()
{
	InvBinocularsIndex  = 255;
	DisplayFOV          = 50;
	bVirtualInventory   = true;
	PlayerViewOffset    = FVector(8, 0, -6);
	DrawScale           = 1;
}

/*
simulated State BusyZooming
{
Begin:
	AGP_Pawn(Instigator).NotifyBinocularsStatusChangingTo(bZoomDir);
	if (bZoomDir)
	{
		bInZoom=true;
		Instigator.WeaponAdjust3p(Instigator.18);
		RunAnimation("Zoom",1);
		if (Level.NetMode == NM_DedicatedServer)
		{
			Sleep(AnimTimerDuration);
			AnimEnd(0);
		}
		else
		{
			FinishAnim();
		}
		Zoom();
	}
	else
	{
		UnZoom();
		Instigator.WeaponAdjust3p(Instigator.19);
		RunAnimation("UnZoom",1);
		if (Level.NetMode == NM_DedicatedServer)
		{
			Sleep(AnimTimerDuration);
			AnimEnd(0);
		}
		else
		{
			FinishAnim();
		}
		bInZoom=false;
	}
	GotoState("Idle");
}
*/

/*
simulated State BusyLoweringWeapon
{
	simulated Function bool TweenDownImmediately()
	{
		return false;
	}
Begin:
	if (IsZoomed())
	{
		UnZoom();
		RunAnimation("UnZoom",1);
		if (Level.NetMode == NM_DedicatedServer)
		{
			Sleep(AnimTimerDuration);
			AnimEnd(0);
		}
		else
		{
			FinishAnim();
		}
		bInZoom=false;
	}
	TweenDown();
	if (Level.NetMode == NM_DedicatedServer)
	{
		Sleep(AnimTimerDuration);
		AnimEnd(0);
	}
	else
	{
		FinishAnim();
	}
}
*/

void AItem_Binoculars::Fire(float Value)
{
}
void AItem_Binoculars::Reload()
{
}
void AItem_Binoculars::FixJam()
{
}
void AItem_Binoculars::ChangeFireMode()
{
}
void AItem_Binoculars::SpawnAndAttachMILESGear()
{
}
void AItem_Binoculars::NotifyBaseChange()
{
}
void AItem_Binoculars::SetMesh()
{
}
void AItem_Binoculars::GetStaticMesh(bool bFriendly)
{
}
void AItem_Binoculars::ShouldDrawCrosshair()
{
	//Return False;
}
bool AItem_Binoculars::ShouldBreatheCycle()
{
	return false;
}

void AItem_Binoculars::AltFire(float Value)
{
	/*
	if (PlayerController(Pawn(Owner).Controller) != None)
	{
		PlayerController(Pawn(Owner).Controller).Zoom();
	}
	*/
}
void AItem_Binoculars::GetUpperBodyLowerAnim()
{
	//Return Instigator.20;
}
void AItem_Binoculars::GetUpperBodyRaiseAnim()
{
	//Return Instigator.17;
}
void AItem_Binoculars::GetUpperBodyReadyAnim()
{
	/*
	if (IsZoomed())
	{
		Return Instigator.22;
	}
	else
	{
		Return Instigator.21;
	}
	*/
}

