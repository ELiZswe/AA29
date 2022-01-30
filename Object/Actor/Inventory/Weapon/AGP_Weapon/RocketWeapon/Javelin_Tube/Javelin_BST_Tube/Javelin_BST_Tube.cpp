// All the original content belonged to the US Army

#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/RocketWeapon/Javelin_Tube/Javelin_BST_Tube/Javelin_BST_Tube.h"
#include "AA29/Object/Actor/Inventory/InvContainer/InvContainer.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"

AJavelin_BST_Tube::AJavelin_BST_Tube()
{

}

bool AJavelin_BST_Tube::CanUseWeapon(int32 DesiredAction)
{
	switch(DesiredAction)
	{
		case 7:
			return bCanDrop;
		default:
			return false;
	}
}
AInvContainer* AJavelin_BST_Tube::GetSwapContainer()
{
	/*
	if (EventLab != nullptr)
	{
		EventLab.ActorNotify(this, 31, Instigator, "ShoulderedJT");
	}
	return Cast<AAGP_Pawn>(Instigator).getInvContainerAltShoulder();
	*/
	return nullptr;
}
