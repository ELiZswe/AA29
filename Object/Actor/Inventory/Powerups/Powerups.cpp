// All the original content belonged to the US Army

#include "Powerups.h"

APowerups::APowerups()
{

}

/*
State Activated
{
	Function BeginState()
	{
		bActive=true;
	}
	Function EndState()
	{
		bActive=false;
	}
	Function Activate()
	{
		if ((((Pawn(Owner) != None) && Pawn(Owner).bAutoActivate) && bAutoActivate) && (Charge > 0))
		{
			return;
		}
		Global.BaseProjectile();
	}
}
*/

void APowerups::TravelPreAccept()
{
	Super::TravelPreAccept();
	if (bActive)
	{
		Activate();
	}
}

void APowerups::PickupFunction(APawn* Other)
{
	/*
		PickupFunction(Other);
		if (bActivatable && Other.SelectedItem == None)
		{
			Other.SelectedItem=Self;
		}
		if (bActivatable && bAutoActivate && Other.bAutoActivate)
		{
			Activate();
		}
	*/
}
APowerups* APowerups::SelectNext()
{
	if (bActivatable)
	{
		return this;
	}
	if (Inventory != nullptr)
	{
		//return Inventory.SelectNext();
	}
	else
	{
		return nullptr;
	}
	return nullptr;    //FAKE   /EliZ
}
void APowerups::Activate()
{
	if (bActivatable)
	{
		//GotoState('Activated');
	}
}
void APowerups::HandlePickupQuery(APickup* Item)
{
	/*
		if (Item.InventoryType == Class)
		{
			if (bCanHaveMultipleCopies)
			{
				NumCopies ++;
			}
			else
			{
				if (bDisplayableInv)
				{
					if (Item.Inventory != None)
					{
						Charge=Max(Charge,Item.Inventory.Charge);
					}
					else
					{
						Charge=Max(Charge,Item.InventoryType.Default.Charge);
					}
				}
				else
				{
					return false;
				}
			}
			Item.AnnouncePickup(Pawn(Owner));
			Item.SetRespawn();
			return true;
		}
		if (Inventory == None)
		{
			return false;
		}
		return Inventory.HandlePickupQuery(Item);
	*/
}
void APowerups::UseCharge(float Amount)
{
}
void APowerups::FireEffect()
{
}
void APowerups::UsedUp()
{
	/*
		if (Pawn(Owner) != None)
		{
			bActivatable=False;
			Pawn(Owner).NextItem();
			if (Pawn(Owner).SelectedItem == Self)
			{
				Pawn(Owner).NextItem();
				if (Pawn(Owner).SelectedItem == Self)
				{
					Pawn(Owner).SelectedItem=None;
				}
			}
			Instigator.ReceiveLocalizedMessage(MessageClass,0,None,None,Self.Class);
		}
		Owner.PlaySound(DeActivateSound,6);
		Destroy();
	*/
}

FString APowerups::GetLocalString(int32 Switch, AAA2_PlayerState*  RelatedPRI_1, AAA2_PlayerState*  RelatedPRI_2)
{
	//return Default.ExpireMessage;
	return "FAKE";    //FAKE   /ELiZ
}
