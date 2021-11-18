// All the original content belonged to the US Army


#include "RocketWeaponPickup.h"

ARocketWeaponPickup::ARocketWeaponPickup()
{
	AmmoState = EAmmoState::AMMSTATE_None;
}


void ARocketWeaponPickup::InitDroppedPickupFor(AInventory* Inv, bool bFreeze)
{
	/*
		InitDroppedPickupFor(Inv,bFreeze);
		if (AGP_Weapon(Inv).OutOfAmmo())
		{
			AmmoState=2;
		}
		else
		{
			AmmoState=1;
		}
		if (GetNetMode() == ENetMode::NM_Standalone)
		{
			SwapAmmoRound();
		}
	*/
}
void ARocketWeaponPickup::IsReplicationComplete()
{
	/*
		Return AmmoState != 0;
	*/
}
void ARocketWeaponPickup::NotifyReplicationComplete()
{
	/*
		SwapAmmoRound();
	*/
}
void ARocketWeaponPickup::SwapAmmoRound()
{
	/*
		if (! MaybeSetStaticMesh())
		{
			if (AmmoState == 1)
			{
				SetStaticMesh(StaticMeshFull);
			}
			else
			{
				SetStaticMesh(StaticMeshEmpty);
			}
		}
	*/
}
void ARocketWeaponPickup::MaybeSetStaticMesh()
{
	/*
		if (UseEnemyClass())
		{
			Switch(DrawType)
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
			Level.SetActorLevelSkin(Self,False);
			Return True;
		}
		Level.SetActorLevelSkin(Self,True);
		Return False;
	*/
}
