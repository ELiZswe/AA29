// All the original content belonged to the US Army


#include "AA29/AI_Primitive/Action/ActionAdjustInv/ActionAdjustInv.h"

AActionAdjustInv::AActionAdjustInv()
{

}

float AActionAdjustInv::evaluateAction()
{
	/*
	local AGP.AGP_Pawn Bot;
	local AGP.AGP_Weapon weapons;
	Bot = getPawn();
	weapons[0] = AGP_Weapon(Bot.Weapon);
	weapons[1] = AGP_Weapon(Bot.getShoulderInventory());
	if (weapons[1] == None)
	{
		Return 0;
	}
	DebugLog(DEBUG_InvAI, "ActionAdjustInv::evaluateAction()	Got weapons of type " $ weapons[0].weaponType @ weapons[1].weaponType);
	if (weapons[0].weaponType < weapons[1].weaponType)
	{
		DebugLog(DEBUG_InvAI, "ActionAdjustInv::evaluateAction()	Active weapon " $ weapons[0] $ " is less than shoulder " $ weapons[1]);
		Return 0.1;
	}
	*/
	return 0;
}
void AActionAdjustInv::executeAction()
{
	//AGP_Pawn(Controller.Pawn).SwapHands();
	//NotifyComplete();
}