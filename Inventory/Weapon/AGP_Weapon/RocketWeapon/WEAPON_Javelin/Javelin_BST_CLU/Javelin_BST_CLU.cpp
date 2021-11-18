// All the original content belonged to the US Army


#include "Javelin_BST_CLU.h"
#include "AA29/Pickup/AGP_WeaponPickup/Pickup_Javelin_BST_CLU/Pickup_Javelin_BST_CLU.h"
#include "AA29/BaseScope/ScopeW_BST.h"

AJavelin_BST_CLU::AJavelin_BST_CLU()
{
	bCanZoom       = true;
	bCanReload     = true;
	bCanSeek       = true;
	bCanFire       = true;
	bForceMisfire  = true;
	MisFireChance  = 0;
	_cScopeClass   = AScopeW_BST::StaticClass();
	bCanSupport    = true;
	PickupClass    = APickup_Javelin_BST_CLU::StaticClass();
}

bool AJavelin_BST_CLU::CanUseWeapon(int32 DesiredAction)
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
		return bCanFixJam;
		default:
		return false;
	}
}
void AJavelin_BST_CLU::FixJam()
{
	/*
		if (CanUseWeapon(2))
		{
			if (IsZoomed())
			{
				ToggleZoom();
			}
			Log("AAGA Fixing Jam");
			if (EventLab != None)
			{
				EventLab.ActorNotify(Self,31,Instigator,"CLUJamFixed");
			}
			FixJam();
		}
	*/
}
void AJavelin_BST_CLU::NV()
{
	/*
		if (! bCanCycle)
		{
			Return;
		}
		if (myscope.fZoomMultiplier == 9)
		{
			if (EventLab != None)
			{
				EventLab.ActorNotify(Self,31,Instigator,"CLUCycled");
			}
		}
		NV();
	*/
}
void AJavelin_BST_CLU::ToggleZoom()
{
	/*
		if (IsZoomed())
		{
			Log("AAGA is zoomed, being unzoomed");
			if (EventLab != None)
			{
				EventLab.ActorNotify(Self,31,Instigator,"CLUUnZooming");
			}
		}
		else
		{
			Log("AAGA is unzoomed, being zoomed");
			bToggled=True;
			if (EventLab != None)
			{
				EventLab.ActorNotify(Self,31,Instigator,"CLUZooming");
			}
		}
		ToggleZoom();
	*/
}
void AJavelin_BST_CLU::CancelLock (bool KeepSeekOn)
{
	/*
		if (bLockedOn)
		{
			if (EventLab != None)
			{
				EventLab.ActorNotify(Self,31,Instigator,"LostLock");
			}
		}
		CancelLock(KeepSeekOn);
	*/
}
void AJavelin_BST_CLU::FireMode()
{
	/*
		Instigator.LimitRotation(True);
		FireMode();
	*/
}
void AJavelin_BST_CLU::DropFrom(FVector StartLocation, bool bAttach)
{
	/*
		local Pickup p;
		p=DropFrom(StartLocation,bAttach);
		if (EventLab != None)
		{
			EventLab.ActorNotify(Self,31,Instigator,"BSTThrown");
		}
		Return p;
	*/
}
void AJavelin_BST_CLU::Fire(float Value)
{
	/*
		if (! CanUseWeapon(0))
		{
			Return;
		}
		if (bLockedOn == false)
		{
			Return;
		}
		Fire(Value);
	*/
}
void AJavelin_BST_CLU::AltFire(float Value)
{
	/*
		if (bCanSeek && ! bTotalLock)
		{
			if (bDirectOnly)
			{
				if (GetbDirectFire())
				{
					AltFire(Value);
				}
			}
			else
			{
				AltFire(Value);
			}
		}
	*/
}
void AJavelin_BST_CLU::IsJavelin()
{
	//Return False;
}
