// All the original content belonged to the US Army


#include "Powerups.h"

APowerups::APowerups()
{

}



void APowerups::TravelPreAccept()
{
	/*
		TravelPreAccept();
		if (bActive)
		{
			Activate();
		}
	*/
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
void APowerups::SelectNext()
{
	/*
		if (bActivatable)
		{
			Return Self;
		}
		if (Inventory != None)
		{
			Return Inventory.SelectNext();
		}
		else
		{
			Return None;
		}
	*/
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
					Return False;
				}
			}
			Item.AnnouncePickup(Pawn(Owner));
			Item.SetRespawn();
			Return True;
		}
		if (Inventory == None)
		{
			Return False;
		}
		Return Inventory.HandlePickupQuery(Item);
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
/*
void APowerups::GetLocalString(int32 Switch, AAA2_PlayerState*  RelatedPRI_1, AAA2_PlayerState*  RelatedPRI_2)
{
		Return Default.ExpireMessage;
}

*/