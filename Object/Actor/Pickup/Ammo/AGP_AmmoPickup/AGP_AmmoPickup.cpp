// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pickup/Ammo/AGP_AmmoPickup/AGP_AmmoPickup.h"

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
	/*
	local AGP_Pawn agpbot;
	local Weapon weapons;
	local int bulletcount;
	local int i;
	local float Desireability;
	if (AmmoAmount == 0)
	{
		return 0;
	}
	agpbot = AGP_Pawn(Bot);
	if (agpbot == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("AGP_AmmoPickup::BotDesireability()	Could not find AGP_Pawn Bot"));
		return 0;
	}
	weapons[0] = agpbot.Weapon;
	weapons[1] = Weapon(agpbot.getShoulderInventory());
	for (i = 0; i < 2; i++)
	{
		if (weapons[i] != None)
		{
			if (weapons[i].AmmoName == InventoryType)
			{
				bulletcount = 0;
				bulletcount += agpbot.getBestAmmoFromWeapon(weapons[i]);
				bulletcount += weapons[i].GetCurrentAmmoType().AmmoAmount;
				Desireability = 1 - bulletcount / 2 * AmmoAmount;
				UE_LOG(LogTemp, Warning, TEXT("AGP_AmmoPickup::BotDesireability()	" $ bulletcount @ weapons[i].GetCurrentAmmoType().MaxAmmo @ Desireability));
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
