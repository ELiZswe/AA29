// All the original content belonged to the US Army


#include "WeaponPickup.h"

AWeaponPickup::AWeaponPickup()
{
	bWeaponStay       = true;
	MaxDesireability  = 0.5;
	bAmbientGlow      = true;
	bPredictRespawns  = true;
	RespawnTime       = 30;
	PickupMessage     = "You got a weapon";
	CullDistance      = 6500;
	//Physics = 5;
	Texture           = LoadObject<class UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/Engine/S_Weapon.S_Weapon"), NULL, LOAD_None, NULL);
	AmbientGlow       = 128;
	CollisionRadius   = 36;
	CollisionHeight   = 30;
	RotationRate      = FRotator(0, 180, 0);
}



void AWeaponPickup::PostBeginPlay()
{
	/*
	PostBeginPlay();
	SetWeaponStay();
	MaxDesireability = 1.2 * class<Weapon>(InventoryType).Default.AIRating;
	*/
}
void AWeaponPickup::SetWeaponStay()
{
	/*
	bWeaponStay = bWeaponStay && Level.Game.bWeaponStay;
	*/
}
/*
void AWeaponPickup::UpdateHUD(AHUD* H)
{
	H.LastPickupTime = H.GetWorld()->GetTimeSeconds();
	H.LastWeaponPickupTime = H.LastPickupTime;
}
*/
void AWeaponPickup::StartSleeping()
{
	/*
	if (bDropped)
	{
		Destroy();
	}
	else
	{
		if (!bWeaponStay)
		{
			GotoState('Sleeping');
		}
	}
	*/
}
bool AWeaponPickup::AllowRepeatPickup()
{
	return !bWeaponStay || bDropped && !bThrown;
}
void AWeaponPickup::GetRespawnTime()
{
	/*
	if (GetNetMode() != ENetMode::NM_Standalone || Level.Game.GameDifficulty > 3)
	{
		Return RespawnTime;
	}
	Return RespawnTime * 0.33 + 0.22 * Level.Game.GameDifficulty;
	*/
}
