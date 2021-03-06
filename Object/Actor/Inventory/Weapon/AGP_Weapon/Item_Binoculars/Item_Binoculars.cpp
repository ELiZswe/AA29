// All the original content belonged to the US Army

#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/Item_Binoculars/Item_Binoculars.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"

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
	Cast<AAGP_Pawn>(Instigator).NotifyBinocularsStatusChangingTo(bZoomDir);
	if (bZoomDir)
	{
		bInZoom=true;
		Instigator.WeaponAdjust3p(Instigator.18);
		RunAnimation("Zoom",1);
		if (GetWorld()->GetNetMode() == NM_DedicatedServer)
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
		if (GetWorld()->GetNetMode() == NM_DedicatedServer)
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
		if (GetWorld()->GetNetMode() == NM_DedicatedServer)
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
	if (GetWorld()->GetNetMode() == NM_DedicatedServer)
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

UStaticMesh* AItem_Binoculars::GetStaticMesh(bool bFriendly)
{
	return nullptr;     //FAKE   /EliZ
}

bool AItem_Binoculars::ShouldDrawCrosshair()
{
	return false;
}
bool AItem_Binoculars::ShouldBreatheCycle()
{
	return false;
}

void AItem_Binoculars::AltFire(float Value)
{
	/*
	if (Cast<APlayerController>(Cast<APawn>(GetOwner())->Controller) != nullptr)
	{
		Cast<APlayerController>(Cast<APawn>(GetOwner())->Controller).Zoom();
	}
	*/
}

EUpperBodyAnim AItem_Binoculars::GetUpperBodyLowerAnim()
{
	//return Instigator.20;
	return EUpperBodyAnim::UBANIM_NONE;     //FAKE   /EliZ
}
EUpperBodyAnim AItem_Binoculars::GetUpperBodyRaiseAnim()
{
	//return Instigator.17;
	return EUpperBodyAnim::UBANIM_NONE;     //FAKE   /EliZ
}
EUpperBodyAnim AItem_Binoculars::GetUpperBodyReadyAnim()
{
	/*
	if (IsZoomed())
	{
		return Instigator.22;
	}
	else
	{
		return Instigator.21;
	}
	*/
	return EUpperBodyAnim::UBANIM_NONE;     //FAKE   /EliZ
}

