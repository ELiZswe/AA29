// All the original content belonged to the US Army


#include "RocketWeapon.h"

ARocketWeapon::ARocketWeapon()
{
	bAllowsPlusOneLoading  = false;
	fpWeaponThreatLevel    = 8.5;
}

void ARocketWeapon::GetSpecialFireAnim(FName SpecialAnimName)
{
	/*
		if (ShouldUse3dSights() && IsZoomed())
		{
			if (HasAnim(ZoomFireAnims[ElevationIndex]))
			{
				SpecialAnimName=ZoomFireAnims[ElevationIndex];
				return true;
			}
		}
		else
		{
			return false;
		}
	*/
}
void ARocketWeapon::Fire(float Value)
{
/*
	if (IsSafe())
	{
		return;
	}
	Fire(Value);
*/
}
void ARocketWeapon::IsSafe()
{
/*
	if (Instigator == None)
	{
		Return True;
	}
	if (Instigator.IsBusy() || Instigator.bIsProne)
	{
		Return True;
	}
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsServer())
	{
		if (VSizeSquared(Instigator.Velocity) > 100)
		{
			Return True;
		}
	}
	else
	{
		if (! IsZero(Instigator.Velocity))
		{
			Return True;
		}
	}
	if (OutOfAmmo())
	{
		Return True;
	}
	else
	{
		Return False;
	}
*/
}
void ARocketWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	/*
		if (! Cast<AAA2_WorldSettings>(GetWorldSettings())->IsServer())
		{
			SetSafety(IsSafe());
		}
		TestWeaponProne();
	*/
}
void ARocketWeapon::SetSafety(bool new_safety)
{
	/*
		if (IsZoomed())
		{
			bSafe=false;
			return;
		}
		else
		{
			if (new_safety != bSafe && ! IsBusy())
			{
				bSafe=new_safety;
				GotoState('BusyToggleSafety');
			}
		}
	*/
}
void ARocketWeapon::PlayIdleAnim()
{
	/*
		if (bSafe && HasAnim('IdleSafe') && ! IsZoomed())
		{
			RunAnimation('IdleSafe',1,0.05,True);
		}
		else
		{
			PlayIdleAnim();
		}
	*/
}
void ARocketWeapon::PlayToggleSafety()
{
	/*
		if (bSafe && HasAnim('SafetyUp'))
		{
			RunAnimation('SafetyUp',1);
		}
		else
		{
			if (HasAnim('SafetyDn'))
			{
				RunAnimation('SafetyDn',1);
			}
			else
			{
				AnimEnd(0);
			}
		}
	*/
}
void ARocketWeapon::StartCrawling()
{
	//GotoState('InCrawling');
}
bool ARocketWeapon::CanCombatRoll(bool bActual)
{
	return false;
}
void ARocketWeapon::TestWeaponProne()
{
	/*
		if (! IsBusy() && Instigator != None && Instigator.bIsProne)
		{
			if (bChangeWeapon)
			{
				GotoState('BusyLoweringWeapon');
			}
			else
			{
				StartCrawling();
			}
		}
	*/
}
void ARocketWeapon::PlayCrawl()
{
	/*
		local FVector X;
		local FVector Y;
		local FVector Z;
		if (IsZero(Instigator.Velocity))
		{
			RunAnimation('HighCrawlStill',1);
		}
		else
		{
			GetAxes(Instigator.Rotation,X,Y,Z);
			if (Instigator.Velocity Dot X > 0)
			{
				RunAnimation('HighCrawl',1);
			}
			else
			{
				RunAnimation('HighCrawlBack',1);
			}
		}
	*/
}
bool ARocketWeapon::PutDown()
{
	if (SingleShotWeapon() && OutOfAmmo())
	{
		/*
		if (Role == 4)
		{
			if (Instigator != NULL)
			{
				AGP_Pawn(Instigator).DropAndSwap();
			}
		}
		*/
		return true;
	}
	else
	{
		return Super::PutDown();
	}
	
}
void ARocketWeapon::UpdateCurrentAmmoRounds(bool bRoundInBreech)
{
	/*
	UpdateCurrentAmmoRounds();
	if (ThirdPersonActor != None && RocketWeaponAttachment(ThirdPersonActor) != None)
	{
		RocketWeaponAttachment(ThirdPersonActor).AdjustAttachmentFor(Self);
	}
	*/
}
void ARocketWeapon::GiveTo(APawn* Other, APickup* Pickup)
{
	/*
	GiveTo(Other);
	if (ThirdPersonActor != None && RocketWeaponAttachment(ThirdPersonActor) != None)
	{
		RocketWeaponAttachment(ThirdPersonActor).AdjustAttachmentFor(Self);
	}
	*/
}
bool ARocketWeapon::CanUseWeapon(int32 DesiredAction)
{
	switch(DesiredAction)
	{
		case 7:
			return true;
		case 6:
			//return ! GetInstigator()->bIsProne;
		case 0:
			return ! bSafe;
		case 3:
			return ! CheckForNoReload();
		default:
			return false;
	}
}
bool ARocketWeapon::CheckForNoReload()
{
	if (! OutOfAmmo())
	{
		return true;
	}
	else
	{
		return Super::CheckForNoReload();
	}
}
bool ARocketWeapon::SingleShotWeapon()
{
	return bSingleShot;
}
bool ARocketWeapon::CanSprint()
{
	return false;
}
bool ARocketWeapon::ShouldDrawCrosshair()
{
	if (IsZoomed() && ! bDebugSights)
	{
		return false;
	}
	else
	{
		return ! bSafe && ! IsBusy();
	}
}
void ARocketWeapon::DoChangeFireMode()
{
}
void ARocketWeapon::ChangeFireMode()
{
}