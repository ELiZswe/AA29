// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pickup/ArmorPickup/ArmorPickup.h"
#include "AA29/Object/Actor/Inventory/Powerups/Armor/Armor.h"
#include "AA29/Object/Actor/Inventory/Inventory.h"

AArmorPickup::AArmorPickup()
{

}

float AArmorPickup::BotDesireability(APawn* Bot)
{
	AInventory* AlreadyHas = nullptr;
	AArmor* AlreadyHasArmor = nullptr;
	float desire = 0;
	bool bChecked = false;
	desire = MaxDesireability;
	if (RespawnTime < 10)
	{
		bChecked = true;
		/*
		AlreadyHas = Bot->FindInventoryType(InventoryType);
		if (AlreadyHas != nullptr)
		{
			if (Inventory != nullptr)
			{
				if (Inventory.Charge <= AlreadyHas.Charge)
				{
					return - 1;
				}
			}
			else
			{
				if (InventoryType.Default.Charge <= AlreadyHas.Charge)
				{
					return - 1;
				}
			}
		}
		*/
	}
	if (!bChecked)
	{
		//AlreadyHasArmor = Armor(Bot.FindInventoryType(InventoryType));
	}
	if (AlreadyHasArmor != nullptr)
	{
		//desire *= 1 - AlreadyHasArmor.Charge * AlreadyHasArmor.ArmorAbsorption * 3E-05;
	}
	/*
	if (Cast<AArmor>(Inventory) != nullptr)
	{
		desire *= Inventory.Charge * 0.005;
		desire *= Armor(Inventory).ArmorAbsorption * 0.01;
	}
	else
	{
		desire *= InventoryType.Default.Charge * 0.005;
		desire *= class<Armor>(InventoryType).Default.ArmorAbsorption * 0.01;
	}
	*/
	return desire;
}
