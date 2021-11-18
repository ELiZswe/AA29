// All the original content belonged to the US Army


#include "ArmorPickup.h"



AArmorPickup::AArmorPickup()
{

}

void AArmorPickup::BotDesireability(APawn* Bot)
{
	/*
	local Inventory AlreadyHas;
	local Armor AlreadyHasArmor;
	local float desire;
	local bool bChecked;
	desire = MaxDesireability;
	if (RespawnTime < 10)
	{
		bChecked = true;
		AlreadyHas = Bot.FindInventoryType(InventoryType);
		if (AlreadyHas != None)
		{
			if (Inventory != None)
			{
				if (Inventory.Charge <= AlreadyHas.Charge)
				{
					Return - 1;
				}
			}
			else
			{
				if (InventoryType.Default.Charge <= AlreadyHas.Charge)
				{
					Return - 1;
				}
			}
		}
	}
	if (!bChecked)
	{
		AlreadyHasArmor = Armor(Bot.FindInventoryType(InventoryType));
	}
	if (AlreadyHasArmor != None)
	{
		desire *= 1 - AlreadyHasArmor.Charge * AlreadyHasArmor.ArmorAbsorption * 3E-05;
	}
	if (Armor(Inventory) != None)
	{
		desire *= Inventory.Charge * 0.005;
		desire *= Armor(Inventory).ArmorAbsorption * 0.01;
	}
	else
	{
		desire *= InventoryType.Default.Charge * 0.005;
		desire *= class<Armor>(InventoryType).Default.ArmorAbsorption * 0.01;
	}
	Return desire;
	*/
}