// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pickup/Ammo/AGP_AmmoPickup/AGP_AmmoPickup.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/Object/Actor/Inventory/Weapon/Weapon.h"

AAGP_AmmoPickup::AAGP_AmmoPickup()
{
	AmmoAmount        = 10;
	MaxDesireability  = 0.24;
	PickupMessage     = FString("AGP_AmmoPickup Generic Pickup Message");
	//Physics = 2;
	CollisionRadius   = 5;
	CollisionHeight   = 5;
}

float AAGP_AmmoPickup::BotDesireability(APawn* Bot)
{
	AAGP_Pawn* agpbot = nullptr;
	AWeapon* weapons = nullptr;
	int32 bulletcount = 0;
	int32 i = 0;
	float Desireability = 0;
	if (AmmoAmount == 0)
	{
		return 0;
	}
	agpbot = Cast<AAGP_Pawn>(Bot);
	/*
	if (agpbot == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("AGP_AmmoPickup::BotDesireability()	Could not find AGP_Pawn Bot"));
		return 0;
	}
	weapons[0] = agpbot.Weapon;
	weapons[1] = Cast<AWeapon>(agpbot.getShoulderInventory());
	for (i = 0; i < 2; i++)
	{
		if (weapons[i] != nullptr)
		{
			if (weapons[i].AmmoName == InventoryType)
			{
				bulletcount = 0;
				bulletcount += agpbot.getBestAmmoFromWeapon(weapons[i]);
				bulletcount += weapons[i].GetCurrentAmmoType().AmmoAmount;
				Desireability = 1 - bulletcount / 2 * AmmoAmount;
				UE_LOG(LogTemp, Warning, TEXT("AGP_AmmoPickup::BotDesireability()	" + bulletcount @ weapons[i].GetCurrentAmmoType().MaxAmmo @ Desireability));
				if (i > 0)
				{
					return MaxDesireability * Desireability;
				}
				else
				{
					return 0.75 * MaxDesireability * Desireability;
				}
			}
		}
	}
	*/
	return 0;
}
