// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/RocketWeaponPickup/RocketWeaponPickup.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/AGP_Weapon.h"
#include "AA29/Object/Actor/Inventory/Inventory.h"

ARocketWeaponPickup::ARocketWeaponPickup()
{
	AmmoState = EAmmoState::AMMSTATE_None;
}

void ARocketWeaponPickup::InitDroppedPickupFor(AInventory* Inv, bool bFreeze)
{
	Super::InitDroppedPickupFor(Inv,bFreeze);
	if (Cast<AAGP_Weapon>(Inv)->OutOfAmmo())
	{
		AmmoState = EAmmoState::AMMSTATE_Off;
	}
	else
	{
		AmmoState = EAmmoState::AMMSTATE_On;
	}
	if (GetNetMode() == ENetMode::NM_Standalone)
	{
		SwapAmmoRound();
	}
}

bool ARocketWeaponPickup::IsReplicationComplete()
{
	return AmmoState != EAmmoState::AMMSTATE_None;
}

void ARocketWeaponPickup::NotifyReplicationComplete()
{
	SwapAmmoRound();
}

void ARocketWeaponPickup::SwapAmmoRound()
{
	if (! MaybeSetStaticMesh())
	{
		if (AmmoState == EAmmoState::AMMSTATE_On)
		{
			//SetStaticMesh(StaticMeshFull);
		}
		else
		{
			//SetStaticMesh(StaticMeshEmpty);
		}
	}
}

bool ARocketWeaponPickup::MaybeSetStaticMesh()
{
	if (UseEnemyClass(nullptr))
	{
		/*
		switch(DrawType)
		{
			case 8:
			if (AmmoState == 2)
			{
				SetStaticMesh(EnemyPickupClass.Default.StaticMeshEmpty);
				break;
			}
			SetStaticMesh(EnemyPickupClass.Default.StaticMeshFull);
		}
		case 2:
		LinkMesh(EnemyPickupClass.Default.Mesh);
		default:
		Level.SetActorLevelSkin(this,false);
		*/
		return true;
	}
	//Level.SetActorLevelSkin(this,true);
	return false;
}
