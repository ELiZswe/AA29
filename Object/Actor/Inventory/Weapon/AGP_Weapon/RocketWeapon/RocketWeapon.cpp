// All the original content belonged to the US Army

#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/RocketWeapon/RocketWeapon.h"

ARocketWeapon::ARocketWeapon()
{
	bAllowsPlusOneLoading  = false;
	fpWeaponThreatLevel    = 8.5;
}

/*
simulated State BusyToggleSafety extends busy
{
	simulated Function BeginState()
	{
		Super::BeginState();
		PlayToggleSafety();
	}
}
*/

/*
simulated State BusyRaisingWeapon
{
	simulated Function EndState()
	{
		Super::EndState();
		bSafe=true;
	}
}
*/

/*
simulated State InCrawling
{
	simulated Function SetFastMove(bool bFast)
	{
	}
	simulated Function TestWeaponProne()
	{
		if ((Instigator != None) && (! Instigator.bIsProne))
		{
			GotoState("OutCrawling");
		}
	}
	simulated Function StopCrawling()
	{
		TestWeaponProne();
	}
}
*/

/*
simulated State OutCrawling
{
	simulated Function StopCrawling()
	{
	}
	simulated Function bool IsCrawling()
	{
		return true;
	}
	simulated Function AnimEnd(int32 Channel)
	{
		if (bChangeWeapon)
		{
			GotoState("BusyLoweringWeapon");
		}
		else
		{
			Super::AnimEnd(Channel);
		}
	}
	simulated Function BeginState()
	{
		if (Level.debugWeaponState)
		{
			Log(string(Self) @ "AGP_Weapon::BeginState() - in state" @ string(GetStateName()));
		}
		Super::BeginState();
		PlayHighCrawlOut();
	}
}
*/

/*
simulated State Crawling
{
	simulated Function SetFastMove(bool bFast)
	{
	}
	simulated Function ClientPutDown()
	{
		bChangeWeapon=true;
		GotoState("OutCrawling");
	}
	simulated Function bool IsTempBusy()
	{
		return IsZero(Instigator.Velocity);
	}
	simulated Function bool CanUseWeapon(int32 DesiredAction)
	{
		FName SeqName = "";
		float AnimFrame = 0;
		float AnimRate = 0;
		if (DesiredAction == 7)
		{
			if (Level.IsServer())
			{
				return (VSizeSquared(Instigator.Velocity) < 1);
			}
			else
			{
				GetAnimParams(0,SeqName,AnimFrame,AnimRate);
				return (SeqName == "HighCrawlStill");
			}
		}
		if (DesiredAction == 6)
		{
			if (Self.IsA("WEAPON_Javelin"))
			{
				return Global.dim(DesiredAction);
			}
		}
		else
		{
			return false;
		}
	}
	simulated Function bool CanZoom()
	{
		if (! Self.IsA("WEAPON_Javelin"))
		{
			return Global.p();
		}
		else
		{
			return ((_Scope != None) && (eROF != AuxROF));
		}
	}
	simulated Function AnimEnd(int32 Channel)
	{
		PlayCrawl();
	}
	simulated Function TestWeaponProne()
	{
		if ((Instigator != None) && (! Instigator.bIsProne))
		{
			GotoState("OutCrawling");
		}
	}
	simulated Function StopCrawling()
	{
		RunAnimation("HighCrawlStill",1,0.05,true);
	}
}
*/

/*
simulated State BusyZooming
{
	simulated Function AnimEnd(int32 Channel)
	{
	}
	simulated Function BeginState()
	{
		if (Level.debugWeaponState)
		{
			Log(string(Self) @ "AGP_Weapon::BeginState() - in state" @ string(GetStateName()));
		}
		bUnZoomASAP=false;
	}
	simulated Function bool CanSprint()
	{
		return false;
	}
	simulated Function bool CanCombatRoll(bool bActual)
	{
		return (! bActual);
	}
	simulated Function EndState()
	{
		if (Level.debugWeaponState)
		{
			Log(string(Self) @ "AGP_Weapon::EndState() - in state" @ string(GetStateName()));
		}
		Super::EndState();
		Instigator.ChangeAnimation();
	}
Begin:
	if (bZoomDir)
	{
		bInZoom=true;
		if (bSafe && HasAnim("ZoomInSafe"))
		{
			RunAnimation("ZoomInSafe",1,0.05);
		}
		else
		{
			RunAnimation("ZoomIn",1,0.05);
		}
		InterpolateZoomView(true);
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
		if (bSafe && HasAnim("ZoomOutSafe"))
		{
			RunAnimation("ZoomOutSafe",1,0.05);
		}
		else
		{
			RunAnimation("ZoomOut",1,0.05);
		}
		InterpolateZoomView(false);
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
		RunAnimation("ZoomOut",1,0.05);
		InterpolateZoomView(false);
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
	if (Instigator == nullptr)
	{
		return true;
	}
	if (Instigator.IsBusy() || Instigator.bIsProne)
	{
		return true;
	}
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsServer())
	{
		if (VSizeSquared(Instigator.Velocity) > 100)
		{
			return true;
		}
	}
	else
	{
		if (! IsZero(Instigator.Velocity))
		{
			return true;
		}
	}
	if (OutOfAmmo())
	{
		return true;
	}
	else
	{
		return false;
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
