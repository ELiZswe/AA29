// All the original content belonged to the US Army

#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/FixedWeapon/FixedWeapon.h"
#include "AA29/Object/Actor/Inventory/Inventory.h"
#include "Engine/Canvas.h"

AFixedWeapon::AFixedWeapon()
{
	//	DryFireSound = nullptr
	bMisFire           = false;
	bVirtualInventory  = true;
	DrawType           = EDrawType::DT_None;
}

/*
simulated State BusyRaisingWeapon
{
	simulated Function BeginState()
	{
		if (Level.debugWeaponState)
		{
			Log(string(this) @ "FixedWeapon::BeginState() - in state" @ FString::FromInt(GetStateName()));
		}
		GotoState("Idle");
	}
}
*/

void AFixedWeapon::DetachFromPawn(APawn* p, bool bPreserveWeapon)
{
}
void AFixedWeapon::AttachToPawn(APawn* p)
{
}
void AFixedWeapon::MatchStarting()
{
	/*
	MatchStarting();
	FixedWeaponReload();
	*/
}
void AFixedWeapon::Destroyed()
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
void AFixedWeapon::RemoveTurret()
{
	/*
	FixedWeaponAttachment(ThirdPersonActor).AbandonWeapon();
	ThirdPersonActor=nullptr;
	*/
}
void AFixedWeapon::SetTurret(AActor* A)
{
	//ThirdPersonActor=A;
}
void AFixedWeapon::MatchEnding()
{
}

FVector AFixedWeapon::GetFireStart(FVector X, FVector Y, FVector Z)
{
	/*
	switch(ThirdPersonActor.DrawType)
	{
		case 2:
			return ThirdPersonActor.GetBoneCoords('Muzzle').Origin;
		default:
			return ThirdPersonActor.Location;
	}
	*/

	return FVector(0, 0, 0);    //FAKE   /ELiZ
}
FRotator AFixedWeapon::GetFireRot()
{
	/*
	switch(ThirdPersonActor.DrawType)
	{
		case 2:
			return ThirdPersonActor.GetBoneRotation('Muzzle');
		default:
			return ThirdPersonActor.Rotation;
	}
	*/
	return FRotator(0, 0, 0);    //FAKE   /ELiZ
}
AActor* AFixedWeapon::GetAnimActor()
{
	//return ThirdPersonActor;
	return nullptr;   //FAKE   /EliZ
}
AActor* AFixedWeapon::GetSoundActor()
{
	//return ThirdPersonActor;
	return nullptr;   //FAKE   /EliZ
}
void AFixedWeapon::TweenDown()
{
}
void AFixedWeapon::PlayIdleAnim()
{
}
void AFixedWeapon::Fire(float Value)
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
void AFixedWeapon::ServerFire(bool bNoAdjustAim, bool bRapid, bool bBreatheBonus)
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

void AFixedWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	float fPercent = 0;
	int32 iPercent = 0;
	APlayerController* PC = nullptr;
	/*
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
		if (iLastPercent != iPercent && Instigator != nullptr)
		{
			PC=Cast<APlayerController>(Instigator.Controller);
			Level.Game.BroadcastHandler.BroadcastLocalized(Level.Game,PC,'TurretLocalMessage',iPercent);
			iLastPercent=iPercent;
		}
	}
	*/
}
void AFixedWeapon::FixedWeaponReload()
{
	/*
	fReloadTime=0;
	GetCurrentAmmoType().AmmoAmount=GetCurrentAmmoType().Default.AmmoAmount;
	*/
}
void AFixedWeapon::InitFor(AInventory* Inv)
{
	/*
	InitFor(Inv);
	fReloadTime=Cast<AFixedWeapon>(Inv).fReloadTime;
	*/
}
void AFixedWeapon::RenderOverlays(UCanvas* Canvas, bool bWeaponAndAttachmentsOnly)
{
	/*
	RenderOverlays(Canvas,bWeaponAndAttachmentsOnly);
	if (tTurretOverlay != nullptr && bWeaponAndAttachmentsOnly == false)
	{
		Canvas.SetPos(0,0);
		Canvas.Style=6;
		Canvas.DrawTile(tTurretOverlay,Canvas.SizeX,Canvas.SizeY,0,0,800,600);
	}
	*/
}
