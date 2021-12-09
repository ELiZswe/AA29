// All the original content belonged to the US Army


#include "FixedWeapon.h"


AFixedWeapon::AFixedWeapon()
{
	//	DryFireSound = class'None'
	bMisFire           = false;
	bVirtualInventory  = true;
	DrawType           = EDrawType::DT_None;
}



void AFixedWeapon::DetachFromPawn (APawn* p, bool bPreserveWeapon)
{
}
void AFixedWeapon::AttachToPawn (APawn* p)
{
}
void AFixedWeapon::MatchStarting ()
{
	/*
	MatchStarting();
	FixedWeaponReload();
	*/
}
void AFixedWeapon::Destroyed ()
{
	/*
	if (iLastPercent != -1)
	{
		iLastPercent=-1;
		Level.Game.BroadcastHandler.BroadcastLocalized(Level.Game,PlayerController(Instigator.Controller),'TurretLocalMessage',iLastPercent);
	}
	RemoveTurret();
	Destroyed();
	*/
}
void AFixedWeapon::RemoveTurret ()
{
	/*
	FixedWeaponAttachment(ThirdPersonActor).AbandonWeapon();
	ThirdPersonActor=None;
	*/
}
void AFixedWeapon::SetTurret (AActor* A)
{
	//ThirdPersonActor=A;
}
void AFixedWeapon::MatchEnding ()
{
}
void AFixedWeapon::GetFireStart(FVector X, FVector Y, FVector Z)
{
	/*
	Switch(ThirdPersonActor.DrawType)
	{
		case 2:
			Return ThirdPersonActor.GetBoneCoords('Muzzle').Origin;
		default:
			Return ThirdPersonActor.Location;
	}
	*/
}
void AFixedWeapon::GetFireRot ()
{
	/*
	Switch(ThirdPersonActor.DrawType)
	{
		case 2:
			Return ThirdPersonActor.GetBoneRotation('Muzzle');
		default:
			Return ThirdPersonActor.Rotation;
	}
	*/
}
void AFixedWeapon::GetAnimActor ()
{
	//Return ThirdPersonActor;
}
void AFixedWeapon::GetSoundActor ()
{
	//Return ThirdPersonActor;
}
void AFixedWeapon::TweenDown ()
{
}
void AFixedWeapon::PlayIdleAnim ()
{
}
void AFixedWeapon::Fire (float Value)
{
	/*
	Fire(Value);
	if (GetNetMode() == ENetMode::NM_Client)
	{
		if (! GetCurrentAmmoType().HasAmmo())
		{
			PlayReloading();
		}
	}
	*/
}
void AFixedWeapon::ServerFire (bool bNoAdjustAim, bool bRapid, bool bBreatheBonus)
{
	/*
	ServerFire(bNoAdjustAim,bRapid,bBreatheBonus);
	if (! GetCurrentAmmoType().HasAmmo())
	{
		PlayReloading();
		fReloadTime=GetSoundDuration(ReloadSound);
	}
	*/
}
void AFixedWeapon::Tick (float DeltaTime)
{
	Super::Tick(DeltaTime);
	/*
	local float fPercent;
	local int iPercent;
	local PlayerController PC;
	Tick(DeltaTime);
	if (Role == 4 && fReloadTime > 0)
	{
		fReloadTime -= DeltaTime;
		if (fReloadTime <= 0)
		{
			FixedWeaponReload();
			iPercent=-1;
		}
		else
		{
			fPercent=1 - fReloadTime / GetSoundDuration(ReloadSound);
			iPercent=100 * fPercent;
		}
		if (iLastPercent != iPercent && Instigator != None)
		{
			PC=PlayerController(Instigator.Controller);
			Level.Game.BroadcastHandler.BroadcastLocalized(Level.Game,PC,'TurretLocalMessage',iPercent);
			iLastPercent=iPercent;
		}
	}
	*/
}
void AFixedWeapon::FixedWeaponReload ()
{
	/*
	fReloadTime=0;
	GetCurrentAmmoType().AmmoAmount=GetCurrentAmmoType().Default.AmmoAmount;
	*/
}
void AFixedWeapon::InitFor (AInventory* Inv)
{
	/*
	InitFor(Inv);
	fReloadTime=FixedWeapon(Inv).fReloadTime;
	*/
}
void AFixedWeapon::RenderOverlays (UCanvas* Canvas, bool bWeaponAndAttachmentsOnly)
{
	/*
	RenderOverlays(Canvas,bWeaponAndAttachmentsOnly);
	if (tTurretOverlay != None && bWeaponAndAttachmentsOnly == false)
	{
		Canvas.SetPos(0,0);
		Canvas.Style=6;
		Canvas.DrawTile(tTurretOverlay,Canvas.SizeX,Canvas.SizeY,0,0,800,600);
	}
	*/
}