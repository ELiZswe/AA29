// All the original content belonged to the US Army


#include "Javelin_LF_CLU.h"

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
			Return;
		}
		if (bLockedOn == false)
		{
			Return;
		}
		Fire(Value);
		if (EventLab != None)
		{
			EventLab.ActorNotify(Self,31,Instigator,"LFFired");
		}
	*/
}
void AJavelin_LF_CLU::Spawn_J_Target()
{
	/*
		Spawn_J_Target();
		if (T62A(HomingTarget) != None && J_Target != None && ! HomingTarget.IsInState('VehicleDestroyed'))
		{
			AGP_Vehicle(HomingTarget).fJavelinAccuracy=VSizeSquared(HomingTarget.Location - J_Target.Location);
		}
		else
		{
			AGP_Vehicle(HomingTarget).fJavelinAccuracy=0;
		}
	*/
}
void AJavelin_LF_CLU::IsJavelin()
{
	//Return False;
}
