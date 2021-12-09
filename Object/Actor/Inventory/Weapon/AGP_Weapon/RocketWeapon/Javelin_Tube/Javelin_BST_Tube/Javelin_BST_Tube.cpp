// All the original content belonged to the US Army


#include "Javelin_BST_Tube.h"

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
void AJavelin_BST_Tube::GetSwapContainer()
{
	/*
	if (EventLab != None)
	{
		EventLab.ActorNotify(Self, 31, Instigator, "ShoulderedJT");
	}
	Return AGP_Pawn(Instigator).getInvContainerAltShoulder();
	*/
}