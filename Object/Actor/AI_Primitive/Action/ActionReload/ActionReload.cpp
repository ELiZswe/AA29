// All the original content belonged to the US Army

#include "AA29/Object/Actor/AI_Primitive/Action/ActionReload/ActionReload.h"

AActionReload::AActionReload()
{

}

float AActionReload::evaluateAction()
{
	//if (Controller.Pawn.Weapon.GetCurrentAmmoType().AmmoAmount == 0)
	//{
	//	return 0.25;
	//}
	return 0;
}
void AActionReload::executeAction()
{
	//Controller.registerNotification(Self);
	//Controller.Reload();
}
