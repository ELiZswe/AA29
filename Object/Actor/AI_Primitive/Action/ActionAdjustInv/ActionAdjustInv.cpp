// All the original content belonged to the US Army

#include "AA29/Object/Actor/AI_Primitive/Action/ActionAdjustInv/ActionAdjustInv.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/AGP_Weapon.h"

AActionAdjustInv::AActionAdjustInv()
{

}

float AActionAdjustInv::evaluateAction()
{
	AAGP_Pawn* Bot = nullptr;
	AAGP_Weapon* weapons = nullptr;
	/*
	Bot = getPawn();
	weapons[0] = Cast<AAGP_Weapon>(Bot.Weapon);
	weapons[1] = Cast<AAGP_Weapon>(Bot.getShoulderInventory());
	if (weapons[1] == nullptr)
	{
		return 0;
	}
	DebugLog(DEBUG_InvAI, "ActionAdjustInv::evaluateAction()	Got weapons of type " + weapons[0].weaponType @ weapons[1].weaponType);
	if (weapons[0].weaponType < weapons[1].weaponType)
	{
		DebugLog(DEBUG_InvAI, "ActionAdjustInv::evaluateAction()	Active weapon " + weapons[0] + " is less than shoulder " + weapons[1]);
		return 0.1;
	}
	*/
	return 0;
}
void AActionAdjustInv::executeAction()
{
	//AGP_Pawn(Controller.Pawn).SwapHands();
	//NotifyComplete();
}
