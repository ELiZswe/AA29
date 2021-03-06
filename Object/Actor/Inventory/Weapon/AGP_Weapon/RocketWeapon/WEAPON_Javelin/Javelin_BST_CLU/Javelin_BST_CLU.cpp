// All the original content belonged to the US Army

#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/RocketWeapon/WEAPON_Javelin/Javelin_BST_CLU/Javelin_BST_CLU.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/Pickup_Javelin_BST_CLU/Pickup_Javelin_BST_CLU.h"
#include "AA29/Object/Actor/BaseScope/ScopeW_Javelin/ScopeW_BST/ScopeW_BST.h"
#include "AA29/Object/Actor/Pickup/Pickup.h"

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

/*
simulated State BusyReloading
{
	simulated Function BeginState()
	{
		if (IsZoomed())
		{
			ToggleZoom();
		}
		Super::BeginState();
	}
	simulated Function EndState()
	{
		Super::EndState();
		if (EventLab != nullptr)
		{
			EventLab.ActorNotify(this,31,Instigator,"RELOAD," + FString::FromInt(bAttachingTube));
		}
	}
}
*/

/*
simulated State Targeting
{
	simulated Function Tick(float DeltaTime)
	{
		if (((! Instigator.PressingAltFire()) && (! Level.IsServer())) && (! bTotalLock))
		{
			if (EventLab != nullptr)
			{
				EventLab.ActorNotify(this,31,Instigator,"NoLock");
			}
		}
		Super::Tick(DeltaTime);
	}
	simulated Function Timer()
	{
		if (((HomingTarget == nullptr) || (! IsZoomed())) || ((accuracy_count / total_count) < acc_check))
		{
			if (EventLab != nullptr)
			{
				EventLab.ActorNotify(this,31,Instigator,"NoLock");
			}
		}
		else
		{
			if (CheckTarget())
			{
				if (EventLab != nullptr)
				{
					EventLab.ActorNotify(this,31,Instigator,"HasLock");
				}
			}
		}
		Super::Timer();
	}
}
*/

/*
simulated State Jammed
{
	simulated Function AltFire(float Value)
	{
	}
	Function BeginState()
	{
		if (EventLab != nullptr)
		{
			EventLab.ActorNotify(this,31,Instigator,"ForceMisFire");
		}
	}
Begin:
	PlayWeaponSound(MissileBitError,MissileBitError);
	bNotifiedJam=true;
}
*/

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
			if (EventLab != nullptr)
			{
				EventLab.ActorNotify(this,31,Instigator,"CLUJamFixed");
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
			return;
		}
		if (myscope.fZoomMultiplier == 9)
		{
			if (EventLab != nullptr)
			{
				EventLab.ActorNotify(this,31,Instigator,"CLUCycled");
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
			if (EventLab != nullptr)
			{
				EventLab.ActorNotify(this,31,Instigator,"CLUUnZooming");
			}
		}
		else
		{
			Log("AAGA is unzoomed, being zoomed");
			bToggled=true;
			if (EventLab != nullptr)
			{
				EventLab.ActorNotify(this,31,Instigator,"CLUZooming");
			}
		}
		ToggleZoom();
	*/
}
void AJavelin_BST_CLU::CancelLock(bool KeepSeekOn)
{
	/*
		if (bLockedOn)
		{
			if (EventLab != nullptr)
			{
				EventLab.ActorNotify(this,31,Instigator,"LostLock");
			}
		}
		CancelLock(KeepSeekOn);
	*/
}
void AJavelin_BST_CLU::FireMode()
{
	/*
		Instigator.LimitRotation(true);
		FireMode();
	*/
}

APickup* AJavelin_BST_CLU::DropFrom(FVector StartLocation, bool bAttach)
{
	APickup* p = nullptr;
	/*
	p=DropFrom(StartLocation,bAttach);
	if (EventLab != nullptr)
	{
		EventLab.ActorNotify(this,31,Instigator,"BSTThrown");
	}
	*/
	return p;
}
void AJavelin_BST_CLU::Fire(float Value)
{
	/*
		if (! CanUseWeapon(0))
		{
			return;
		}
		if (bLockedOn == false)
		{
			return;
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

bool AJavelin_BST_CLU::IsJavelin()
{
	return false;
}
