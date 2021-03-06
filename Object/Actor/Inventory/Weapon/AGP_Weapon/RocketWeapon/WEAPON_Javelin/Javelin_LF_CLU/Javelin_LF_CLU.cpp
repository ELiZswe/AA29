// All the original content belonged to the US Army

#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/RocketWeapon/WEAPON_Javelin/Javelin_LF_CLU/Javelin_LF_CLU.h"
#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/AGP_Vehicle/AGP_WheeledCraft/AGP_TreadCraft/T62A/T62A.h"

AJavelin_LF_CLU::AJavelin_LF_CLU()
{
	bCanFire     = true;
	bCanZoom     = true;
	bCanReload   = true;
	bCanSupport  = true;
}

bool AJavelin_LF_CLU::CanUseWeapon(int32 DesiredAction)
{
	if (bTotalLock)
	{
		return false;
	}
	switch(DesiredAction)
	{
		case 7:
		return bCanDrop;
		case 0:
		return ! bSafe && bCanFire;
		case 3:
		return ! CheckForNoReload() && bCanReload;
		case 6:
		//return CanZoom() && ! Instigator.IsBusy() && bCanZoom;
		case 5:
		return IsZoomed() && bCanSupport;
		case 2:
		return true;
		default:
		return false;
	}
}
void AJavelin_LF_CLU::Fire(float Value)
{
	/*
		if (! bCanFire)
		{
			return;
		}
		if (bLockedOn == false)
		{
			return;
		}
		Fire(Value);
		if (EventLab != nullptr)
		{
			EventLab.ActorNotify(this,31,Instigator,"LFFired");
		}
	*/
}
void AJavelin_LF_CLU::Spawn_J_Target()
{
	/*
		Spawn_J_Target();
		if (Cast<AT62A>(HomingTarget) != nullptr && J_Target != nullptr && ! HomingTarget.IsInState('VehicleDestroyed'))
		{
			AGP_Vehicle(HomingTarget).fJavelinAccuracy=VSizeSquared(HomingTarget.Location - J_Target.Location);
		}
		else
		{
			AGP_Vehicle(HomingTarget).fJavelinAccuracy=0;
		}
	*/
}

bool AJavelin_LF_CLU::IsJavelin()
{
	return false;
}
